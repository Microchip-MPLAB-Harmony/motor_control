/**
 * @file mc_rotor_position_estimation.c
 *
 * @brief 
 *    Source file for rotor position estimation
 *
 * @File Name 
 *    mc_rotor_position_estimation.c
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Source file which contains variables and function implementations for rotor position estimation.
 *
 * @Description
 *    This file contains variables and function implementations which are generally used for rotor
 *    position estimation in pulse width modulation. It is implemented in Q2.14 fixed point arithmetic.
 */

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "mc_rotor_position_estimation.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/
#undef SRF_PLL

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
    bool enable;                /**< Flag indicating if the module is enabled */
    bool initDone;              /**< Flag indicating if initialization is done */
    int16_t RsVal;              /**< Stator resistance value */
    uint16_t RsShift;           /**< Shift amount for stator resistance */
    int16_t LsFsVal;            /**< Filtered inductance value */
    uint16_t LsFsShift;         /**< Shift amount for filtered inductance */
    int16_t OneByKeVal;         /**< Inverse of back EMF constant value */
    uint16_t OneByKeShift;      /**< Shift amount for inverse of back EMF constant */
    int16_t SpeedToAngleVal;    /**< Speed to angle conversion value */
    uint16_t SpeedToAngleShift; /**< Shift amount for speed to angle conversion */
    int16_t eAlpha;             /**< Error in alpha axis */
    int16_t eBeta;              /**< Error in beta axis */
    int16_t eD;                 /**< Error in direct axis */
    int16_t eQ;                 /**< Error in quadrature axis */
    int16_t iAlphaLast;         /**< Last alpha axis current value */
    int16_t iBetaLast;          /**< Last beta axis current value */
    int16_t uAlphaLast;         /**< Last alpha axis voltage value */
    int16_t uBetaLast;          /**< Last beta axis voltage value */
    uint16_t phi;               /**< Rotor electrical angle */
    int16_t speed;              /**< Rotor speed */
    int16_t integOffset;        /**< Integration offset */
#if defined SRF_PLL
    tmcUtils_PiControl_s bPIController; /**< PI controller for PLL */
#endif
} tmcRpe_State_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcRpe_State_s mcRpe_State_mds;

/*******************************************************************************
Interface  variables
*******************************************************************************/

/*******************************************************************************
Macro Functions
*******************************************************************************/
#define RIGHT_SHIFT_S32     mcUtils_RightShiftS32
#define MULT_SHIFT     mcUtils_MultAndRightShiftS16
#define GET_VALUE_SHIFT     mcUtils_FloatToValueShiftPair

/*******************************************************************************
Private Functions
*******************************************************************************/

/*******************************************************************************
 * Interface Functions
*******************************************************************************/
/*! 
 * @brief Initialize rotor position estimation module
 *
 * @details
 * Initialize rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void  mcRpeI_RotorPositionEstimInit( tmcRpe_Parameters_s * const pParameters )
{
    float32_t f32a;

    /** Link state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcRpe_State_mds;
    tmcRpe_State_s * pState = &mcRpe_State_mds;

    /** Set parameters */
    mcRpeI_ParametersSet(pParameters);

    /** Calculate scaled values  */
    f32a = pParameters->pMotorParameters->RsInOhms/ BASE_IMPEDENCE_IN_OHMS;
    pState->RsShift = 0u;

    GET_VALUE_SHIFT( f32a, &pState->RsVal, &pState->RsShift);

    f32a = pParameters->pMotorParameters->LdInHenry / ( BASE_IMPEDENCE_IN_OHMS * pParameters->dt );
    GET_VALUE_SHIFT( f32a, &pState->LsFsVal, &pState->LsFsShift);

    /** ToDO: Remove hard coded numeric value */
    f32a = 1225.0f * (BASE_VOLTAGE_IN_VOLTS/ BASE_SPEED_IN_RPM )/ pParameters->Ke;
    GET_VALUE_SHIFT( f32a, &pState->OneByKeVal, &pState->OneByKeShift);

    /** Speed to angle conversion factor calculation */
    f32a = (float32_t)K_TIME;

    pState->SpeedToAngleShift = 0u;
    GET_VALUE_SHIFT( f32a, &pState->SpeedToAngleVal, &pState->SpeedToAngleShift);

#if defined SRF_PLL
    mcUtils_PiControlInit( 0.1, 2, pParameters->dt, &pState->bPIController );
    mcUtils_PiLimitUpdate( -16384, 16384, &pState->bPIController );
#endif

    /** Set initialization flag to true */
    pState->initDone = true;
}

/*! 
 * @brief Enable rotor position estimation module
 *
 * @details
 * Enable rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void  mcRpeI_RotorPositionEstimEnable( tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
         /** Initialize parameters */
        mcRpeI_RotorPositionEstimInit(pParameters);
    }
    else
    {
         /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = true;
}

/*! 
 * @brief Disable rotor position estimation module
 *
 * @details
 * Disable rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void  mcRpeI_RotorPositionEstimDisable( tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcRpeI_RotorPositionEstimReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Set enable flag as true */
    pState->enable = false;
}

/*! 
 * @brief Perform rotor position estimation
 *
 * @details
 * Perform rotor position estimation
 *
 * @param[in] pParameters - Pointer to parameters structure
 * @param[in] pIAlphaBeta - Pointer to input alpha-beta voltages
 * @param[in] pUAlphaBeta - Pointer to input alpha-beta currents
 * @param[out] pAngle - Pointer to store estimated rotor angle
 * @param[out] pSpeed - Pointer to store estimated rotor speed
 *
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcRpeI_RotorPositionEstim( const tmcRpe_Parameters_s * const pParameters,
                                                                         const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                                         const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                                         uint16_t * pAngle, int16_t * pSpeed  )
#else
void mcRpeI_RotorPositionEstim(  const tmcRpe_Parameters_s * const pParameters,
                                                     const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                     const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                     uint16_t * pAngle, int16_t * pSpeed )
#endif
{
     /** Get the linked state variable */
     tmcRpe_State_s * pState;
     pState = (tmcRpe_State_s *)pParameters->pStatePointer;

     if( pState->enable )
     {
         /** Calculate alpha-axis back EMF  */
         int16_t s16a = 0;
         int16_t s16b = 0;
         int16_t sine = 0;
         int16_t cosine = 0;

         s16a = MULT_SHIFT( pIAlphaBeta->alpha, pState->RsVal, pState->RsShift );
         s16b = MULT_SHIFT( ( pIAlphaBeta->alpha - pState->iAlphaLast ), pState->LsFsVal, pState->LsFsShift );
         pState->iAlphaLast = pIAlphaBeta->alpha;

         pState->eAlpha = pState->uAlphaLast - s16a - s16b;
         pState->uAlphaLast = pUAlphaBeta->alpha;

         /** Calculate beta-back EMF  */
         s16a = MULT_SHIFT( pIAlphaBeta->beta, pState->RsVal, pState->RsShift );
         s16b = MULT_SHIFT( ( pIAlphaBeta->beta - pState->iBetaLast ), pState->LsFsVal,  pState->LsFsShift );
         pState->iBetaLast = pIAlphaBeta->beta;

         pState->eBeta = pState->uBetaLast - s16a - s16b;
         pState->uBetaLast = pUAlphaBeta->beta;

         /** Calculate sine and cosine values */
         mcUtils_SineCosineCalculation( pState->phi, &sine, &cosine );

         /** Calculate d-axis back EMF */
         s16a = (int16_t)RIGHT_SHIFT_S32( ( ( (int32_t)pState->eAlpha * (int32_t)cosine )  + ( (int32_t)pState->eBeta * (int32_t)sine ) ), 14u );
         pState->eD = s16a;
         
         /** Calculate q-axis back EMF */
         s16a = (int16_t)RIGHT_SHIFT_S32( ( ( (int32_t)pState->eBeta * (int32_t)cosine )  - ( (int32_t)pState->eAlpha * (int32_t)sine) ), 14u );
         pState->eQ = s16a; 

#if defined SRF_PLL         
         
         if( 0 < pState->eQ )  
         {
              /** Execute PI controller */
              mcUtils_PiControl( -pState->eD, &pState->bPIController );

              s16a = pState->bPIController.Yo; 
             s16b =  MULT_SHIFT( pState->eQ, pState->OneByKeVal, pState->OneByKeShift );

             
         }
         else
         {
              /** Execute PI controller */
              mcUtils_PiControl( pState->eD, &pState->bPIController );

              s16a = pState->bPIController.Yo; 
              s16b = MULT_SHIFT( pState->eQ, pState->OneByKeVal, pState->OneByKeShift );
         }
         
         pState->speed = s16a + s16b;
         
         /** Calculate angle from speed */
         pState->phi += (uint16_t)MULT_SHIFT( pState->speed, pState->SpeedToAngleVal, pState->SpeedToAngleShift);
#else
         
         /** Calculate speed */
         if( 0 < pState->eQ )  
         {
             s16a = pState->eQ - pState->eD;
         }
         else
         {
             s16a = pState->eQ + pState->eD;
         }
         
         pState->speed = MULT_SHIFT( s16a, pState->OneByKeVal, pState->OneByKeShift );
         
         /** Integrator drift  tracking and compensation based on speed direction */
         if( 0 < pState->speed )  
         {
             if( UTIL_AbsLessThanEqual( pState->eAlpha,  10 ))
             {
                 if( pState->eBeta > 0 )
                 {
                     pState->integOffset = pState->phi;
                 }
             }
         }
         else
         {
             if( UTIL_AbsLessThanEqual( pState->eAlpha,  10 ))
             {
                 if( pState->eBeta < 0 )
                 {
                     pState->integOffset = pState->phi;
                 }
             }          
         }
         
         /** Calculate angle from speed */
         pState->phi += (uint16_t)MULT_SHIFT( pState->speed, pState->SpeedToAngleVal, pState->SpeedToAngleShift);
   #endif
         
         /** Update output */
         *pSpeed = *pSpeed  + MULT_SHIFT( ( pState->speed - *pSpeed ), 200, 14 );
         *pAngle = pState->phi - pState->integOffset;
     }
     else
     {
         /** Rotor position estimation */
         mcRpeI_RotorPositionEstimReset( pParameters );

         /** Update output */
         *pSpeed = 0;
         *pAngle = 0u;
     }
}

/*! 
 * @brief Reset rotor position estimation module
 *
 * @details
 * Reset rotor position estimation module
 *
 * @param[in] pParameters - Pointer to parameters structure
 *
 * @return None
 */
void mcRpeI_RotorPositionEstimReset( const tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    /** Reset state variables  */
    pState->integOffset = 0;
#if defined SRF_PLL
    mcUtils_PiControlReset( &pState->bPIController );
#endif
    pState->iAlphaLast = 0;
    pState->iBetaLast = 0;
    pState->uAlphaLast = 0;
    pState->uBetaLast = 0;
}
