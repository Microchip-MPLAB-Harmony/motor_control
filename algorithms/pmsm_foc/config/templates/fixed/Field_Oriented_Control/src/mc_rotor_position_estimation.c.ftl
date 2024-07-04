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
 *    position estimation in pulse width modulation. 
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
#include "mc_fir_filter.h"
#include "mc_iir_filter.h"

/*******************************************************************************
Local configuration options
*******************************************************************************/
#undef SRF_PLL
#define ENABLE_PHI_OFFSET_COMPENSATION
#undef ENABLE_FIR_FILTER_STAGE
#undef ENABLE_IIR_FILTER_STAGE

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct
{
    bool enable;
    bool initDone;
    int16_t Rs;
    int16_t LsFs;
    int16_t oneByKeVal;
    uint16_t oneByKeShift;
    int16_t speedToAngle;
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

#if defined ENABLE_FIR_FILTER_STAGE
    int16_t firTapNumbers;
    int16_t firCoefficients[4U];
    FIRFilter  firFilter;
#endif

#if defined ENABLE_IIR_FILTER_STAGE
    int16_t  iirStages;
    int16_t  iirACoefficients[3U];
    int16_t  iirBCoefficients[3U];
    IIRFilter  iirFilter;
#endif

#if defined SRF_PLL
    tmcUtils_PiControl_s bPIController;
#else
    int16_t phiOffset;
    uint16_t calibCounter;
    uint16_t calibTimeinCounts;
#endif
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

    pState->Rs = Q_SCALE( f32a );

    f32a = pParameters->pMotorParameters->LdInHenry / ( BASE_IMPEDENCE_IN_OHMS * pParameters->dt );
    pState->LsFs = Q_SCALE( f32a );

    /** ToDO: Remove hard coded numeric value */
    f32a = 1225.0f * (BASE_VOLTAGE_IN_VOLTS/ BASE_SPEED_IN_RPM )/ pParameters->Ke;
    mcUtils_FloatToValueShiftPair( f32a, &pState->oneByKeVal, &pState->oneByKeShift );

    /** Speed to angle conversion factor calculation */
    f32a = (float32_t)K_TIME;

    pState->speedToAngle = Q_SCALE( f32a);

#if defined SRF_PLL
    mcUtils_PiControlInit( 0.5, 100, pParameters->dt, &pState->bPIController );
    mcUtils_PiLimitUpdate( -Q_SCALE(1.0), Q_SCALE(1.0), &pState->bPIController );
#else
    /** Rotor position calibration time */
    pState->calibTimeinCounts = pParameters->calibTimeInSec / pParameters->dt;
#endif

#if defined ENABLE_FIR_FILTER_STAGE
    pState->firTapNumbers = 4U;
    for( int8_t tap = 0; tap < pState->firTapNumbers; tap++ )
    {
        pState->firCoefficients[tap] = Q_SCALE(0.25);
    }

    // Initialize the filter
    FIRFilter_FilterInitialize(&pState->firFilter, pState->firCoefficients, pState->firTapNumbers );
#endif

#if defined ENABLE_IIR_FILTER_STAGE
    // Example coefficients for each stage (a = 0.9, b = 0.1 in Q15 format)
    pState->iirStages = 3;
    for( int8_t stage = 0; stage < pState->iirStages; stage++ )
    {
        pState->iirACoefficients[stage] = Q_SCALE(0.5);
        pState->iirBCoefficients[stage] = Q_SCALE(0.5);
    }

    // Initialize the filter
    IIRFilter_FilterInitialize(&pState->iirFilter, pState->iirACoefficients, pState->iirBCoefficients, pState->iirStages );
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

#if defined  ENABLE_PHI_OFFSET_COMPENSATION  && !defined SRF_PLL
/*! 
 * @brief Disable rotor position estimation module
 *
 * @details
 * Rotor position offset calculation
 *
 * @param[in] pParameters - Pointer to parameters structure
 * @param[in/out] pS16Offset - Pointer to offset values
 *
 * @return None
 */
__STATIC_INLINE  void mcRpe_RotorPostionOffsetCalc( const tmcRpe_Parameters_s * const pParameters, 
                                                    int16_t * const pS16Offset ) 
{
    /** Get the linked state variable */
    tmcRpe_State_s * pState;
    pState = (tmcRpe_State_s *)pParameters->pStatePointer;

    pState->calibCounter++;

    if( pState->calibCounter > pState->calibTimeinCounts ){
        return;
    }

    /** Integrator drift  tracking and compensation based on speed direction */
    if( 0 < pState->speed )     {
        if( UTIL_AbsLessThanEqual( pState->eAlpha,  10 ))
        {
            if( pState->eBeta > 0 )
            {
                *pS16Offset = pState->phi;
            }
        }
    }
    else      {
        if( UTIL_AbsLessThanEqual( pState->eAlpha,  10 ))
        {
            if( pState->eBeta < 0 ) 
            {
                *pS16Offset = pState->phi;
            }
        }
    }
}
#endif

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
                                          tmcTypes_AlphaBeta_s * const pEAlphaBeta,
                                          uint16_t * pAngle, int16_t * pSpeed  )
#else
void mcRpeI_RotorPositionEstim(  const tmcRpe_Parameters_s * const pParameters,
                              const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                              const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                              tmcTypes_AlphaBeta_s * const pEAlphaBeta,
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

        s16a = Q_MULTIPLY( pIAlphaBeta->alpha, pState->Rs );
        s16b = Q_MULTIPLY( ( pIAlphaBeta->alpha - pState->iAlphaLast ), pState->LsFs );
        pState->iAlphaLast = pIAlphaBeta->alpha;

        pState->eAlpha = pState->uAlphaLast - s16a - s16b;
        pState->uAlphaLast = pUAlphaBeta->alpha;

        /** Calculate beta-back EMF  */
        s16a = Q_MULTIPLY( pIAlphaBeta->beta, pState->Rs );
        s16b = Q_MULTIPLY( ( pIAlphaBeta->beta - pState->iBetaLast ), pState->LsFs );
        pState->iBetaLast = pIAlphaBeta->beta;

        pState->eBeta = pState->uBetaLast - s16a - s16b;
        pState->uBetaLast = pUAlphaBeta->beta;

        /** Calculate sine and cosine values */
        mcUtils_SineCosineCalculation( pState->phi, &sine, &cosine );

        /** Calculate q-axis back EMF */
        s16a = Q_MULTIPLY( pState->eBeta, cosine );
        s16b = Q_MULTIPLY( pState->eAlpha, sine );
        pState->eQ = s16a - s16b;

#if defined SRF_PLL
        /** Execute PI controller */
        mcUtils_PiControl( pState->eQ, &pState->bPIController );
        pState->speed = pState->bPIController.Yo;

        int16_t filterOutput = pState->speed;
    #if defined ENABLE_FIR_FILTER_STAGE
        filterOutput  =  FIRFilter_FilterApply(&pState->firFilter, pState->speed );
    #endif
    #if defined ENABLE_IIR_FILTER_STAGE
        filterOutput = IIRFilter_FilterApply(&pState->iirFilter, filterOutput );
    #endif
        /** Update electrical speed  */
        *pSpeed = filterOutput;

        pState->phi += (uint16_t)Q_MULTIPLY( pState->speed, pState->speedToAngle );
        if( 0 < pState->speed )     {
             /** Update electrical angle  */
             *pAngle  = pState->phi - Q15_ANGLE( PI_OVER_TWO );
        }
        else      {
             /** Update electrical angle  */
             *pAngle  = pState->phi + Q15_ANGLE( PI_OVER_TWO );
        }
#else
        /** Calculate d-axis back EMF  */
        s16a = Q_MULTIPLY( pState->eAlpha, cosine );
        s16b = Q_MULTIPLY( pState->eBeta, sine );
        pState->eD = s16a + s16b;

        /** Calculate speed */
        if( 0 < pState->eQ  )      {
            s16a = pState->eQ - pState->eD;
        }
       else      {
           s16a = pState->eQ + pState->eD;
       }

        pState->speed = ( (int32_t)s16a *  (int32_t)pState->oneByKeVal ) >> pState->oneByKeShift;

        /** Calculate angle from speed */
        pState->phi += (uint16_t)Q_MULTIPLY( pState->speed, pState->speedToAngle );

#if defined  ENABLE_PHI_OFFSET_COMPENSATION
        mcRpe_RotorPostionOffsetCalc( pParameters, &pState->phiOffset );
#endif

        int16_t filterOutput = pState->speed;
#if defined ENABLE_FIR_FILTER_STAGE
        filterOutput  =  FIRFilter_FilterApply(&pState->firFilter, pState->speed );
#endif
#if defined ENABLE_IIR_FILTER_STAGE
        filterOutput = IIRFilter_FilterApply(&pState->iirFilter, filterOutput );
#endif

        /** Update back-emf voltage */
        pEAlphaBeta->alpha = pState->eAlpha;
        pEAlphaBeta->beta = pState->eBeta;

        /** Update output */
        *pSpeed = filterOutput;
        *pAngle = pState->phi - pState->phiOffset;
#endif
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

#if defined SRF_PLL
    mcUtils_PiControlReset(0, &pState->bPIController);
#else
    /** Reset state variables  */
    pState->calibCounter = 0u;
    pState->phiOffset = 0;
#endif
    pState->iAlphaLast = 0;
    pState->iBetaLast = 0;
    pState->uAlphaLast = 0;
    pState->uBetaLast = 0;
}
