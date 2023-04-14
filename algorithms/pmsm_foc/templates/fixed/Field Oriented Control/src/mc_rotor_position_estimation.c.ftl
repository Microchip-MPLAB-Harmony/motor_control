/*******************************************************************************
 Rotor position estimation source file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_torque_control.c

  Summary:
    - Rotor position estimation source file

  Description:
    - This file implements functions for rotor position estimation
 
 *******************************************************************************/

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

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
    bool enable;
    bool initDone;
    int16_t RsVal;
    uint16_t RsShift;
    int16_t LsFsVal;
    uint16_t LsFsShift;
    int16_t OneByKeVal;
    uint16_t OneByKeShift;
    int16_t SpeedToAngleVal;
    uint16_t SpeedToAngleShift;
    int16_t eAlpha;
    int16_t eBeta;
    int16_t eD;
    int16_t eQ;
    int16_t iAlphaLast;
    int16_t iBetaLast;
    int16_t uAlphaLast;
    int16_t uBetaLast;
    uint16_t phi;
    int16_t speed;
}tmcRpe_State_s;

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
/*! \brief Initialize rotor position estimation module
 * 
 * Details.
 * Initialize rotor position estimation module
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
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
    f32a = 1.73f * (BASE_VOLTAGE_IN_VOLTS/ BASE_SPEED_IN_RPM )/ pParameters->Ke;
    GET_VALUE_SHIFT( f32a, &pState->OneByKeVal, &pState->OneByKeShift);

    /** Speed to angle conversion factor calculation */
    f32a = (float32_t)K_TIME;

    pState->SpeedToAngleShift = 0u;
    GET_VALUE_SHIFT( f32a, &pState->SpeedToAngleVal, &pState->SpeedToAngleShift);

    /** Set initialization flag to true */
    pState->initDone = true;
}

/*! \brief Enable rotor position estimation module
 *
 * Details.
 * Enable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Disable rotor position estimation module
 *
 * Details.
 * Disable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

/*! \brief Rotor position estimation
 *
 * Details.
 * Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
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

         pState->eAlpha = pUAlphaBeta->alpha - s16a - s16b;

         /** Calculate beta-back EMF  */
         s16a = MULT_SHIFT( pIAlphaBeta->beta, pState->RsVal, pState->RsShift );
         s16b = MULT_SHIFT( ( pIAlphaBeta->beta - pState->iBetaLast ), pState->LsFsVal,  pState->LsFsShift );

         pState->eBeta = pUAlphaBeta->beta - s16a - s16b;

         /** Calculate sine and cosine values */
         mcUtils_SineCosineCalculation( pState->phi, &sine, &cosine );

         /** Calculate d-axis back EMF */
         pState->eD = (int16_t)RIGHT_SHIFT_S32( (int32_t)( ( pState->eAlpha * cosine )  + ( pState->eBeta * sine ) ), 14u );

         /** Calculate q-axis back EMF */
         pState->eQ = (int16_t)RIGHT_SHIFT_S32( (int32_t)( ( pState->eBeta * cosine )  - ( pState->eAlpha * sine) ), 14u );

         /** Calculate speed */
         if( 0 < pState->eQ )   {
             s16a = pState->eQ - pState->eD;
         }else
         {
             s16a = pState->eQ + pState->eD;
         }

         pState->speed = MULT_SHIFT( s16a, pState->OneByKeVal, pState->OneByKeShift );

         /** Calculate angle from speed */
         pState->phi += (uint16_t)MULT_SHIFT( pState->speed, pState->SpeedToAngleVal, pState->SpeedToAngleShift);

         /** Update output */
         *pSpeed = pState->speed;
         *pAngle = pState->phi;

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


/*! \brief Reset Rotor position estimation
 * 
 * Details.
 * Reset Rotor position estimation
 * 
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcRpeI_RotorPositionEstimReset( const tmcRpe_Parameters_s * const pParameters )
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    /** Reset state variables  */
    pState->iAlphaLast = 0;
    pState->iBetaLast = 0;
    pState->uAlphaLast = 0;
    pState->uBetaLast = 0;
}
