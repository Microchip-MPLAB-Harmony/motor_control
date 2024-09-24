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

/*******************************************************************************
Local configuration options
*******************************************************************************/
#define SRF_PLL
#define ENABLE_PHI_OFFSET_COMPENSATION
#define CROSS_COUPLING_ENABLED
#define AMP_CLAMP
#define OBS_MAXSHIFTS 32

/*******************************************************************************
 Private data types
*******************************************************************************/

/**
 * @brief tRpc_Qnum_s        structure representing a value and shift factor.
 */
typedef struct
{
    int16_t  val;  /**< Integer value. */
    uint16_t shr;  /**< Shift right factor. */
} tRpc_Qnum_s    ;

/**
 * @brief Structure representing observer coefficients for the motor control system.
 */
typedef struct
{
    tRpc_Qnum_s        l11;   /**< Constant observer coefficient l11. */
    tRpc_Qnum_s        m11;   /**< Constant observer coefficient m11. */
    tRpc_Qnum_s        n11;   /**< Constant observer coefficient n11. */
    tRpc_Qnum_s        k11;   /**< Constant observer coefficient k11. */
    
#ifdef CROSS_COUPLING_ENABLED
    tRpc_Qnum_s        hhh;   /**< Intermediate result in observer variable coefficient calculation (hhh). */
    tRpc_Qnum_s        lll;   /**< Intermediate result in observer variable coefficient calculation (lll). */
    tRpc_Qnum_s        xxx;   /**< Intermediate result in observer variable coefficient calculation (xxx). */
    tRpc_Qnum_s        m21;   /**< Observer variable coefficient m21. */
    tRpc_Qnum_s        n21;   /**< Observer variable coefficient n21. */
    tRpc_Qnum_s        k21;   /**< Observer variable coefficient k21. */
#endif  // ifdef CROSS_COUPLING_ENABLED
    
} tmcRpe_ROLOCoefficients_s;


typedef struct
{
    bool enable;
    bool initDone;
    int16_t speedToAngle;
    int16_t minSpeedInRpm;
    int16_t eAlpha;
    int16_t eBeta;
    int16_t zAlpha;
    int16_t zBeta;
    int16_t eD;
    int16_t eQ;
    int16_t iAlphaLast;
    int16_t iBetaLast;
    int16_t uAlphaLast;
    int16_t uBetaLast;
    uint16_t phi;
    int16_t speed;

    tmcRpe_ROLOCoefficients_s  roloCoeff; 
#if defined SRF_PLL
    tmcUtils_PiControl_s bPIController;
#else
    int16_t oneByKeVal;
    uint16_t oneByKeShift;
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
__STATIC_INLINE void UTILS_QNumberMultiply( tRpc_Qnum_s QNum, int16_t integerNumber, tRpc_Qnum_s * pQNumResult ) {
#if defined USE_WHILE_LOOP  
    pQNumResult->val = ((int32_t)QNum.val * (int32_t)integerNumber );
    pQNumResult->shr = QNum.shr;

    while( ( pQNumResult->val > 32767 )  || ( pQNumResult->val < -32767 ) || ( OBS_MAXSHIFTS < pROLOCoeff->n21.shr )) {
        pQNumResult->val >>= 1u;
        pQNumResult->shr--;
    }
#else
    pQNumResult->val = Q_MULTIPLY((int32_t)QNum.val, (int32_t)integerNumber );
    pQNumResult->shr = QNum.shr;
#endif
}
/*******************************************************************************
 * Interface Functions
*******************************************************************************/
/*!
 * @brief Initializes the rotor position estimation module.
 * 
 * @details
 * This function links the state variable structure to the rotor position estimation module
 * and sets up parameters for rotor position estimation using floating point calculations.
 *
 * @param[in] pParameters - Pointer to the rotor position estimation parameters structure.
 * 
 * @return None
 */
 float32_t KpSpeed, KiSpeed;
void mcRpeI_RotorPositionEstimInit( tmcRpe_Parameters_s * const pParameters )
{
    float32_t f32a;
    float32_t C1;
    float32_t kGain;

    /** Link the state variable structure to the module */
    pParameters->pStatePointer = (void *)&mcRpe_State_mds;
    tmcRpe_State_s *pState = &mcRpe_State_mds;

    tmcRpe_ROLOCoefficients_s * pROLOCoeff = &pState->roloCoeff;

    /** Set up the rotor position estimation parameters */
    mcRpeI_ParametersSet(pParameters);

    /** Determine minimum speed */
    pState->minSpeedInRpm = Q_SCALE( 0.05f * pParameters->pMotorParameters->NratedInRpm / BASE_SPEED_IN_RPM );

    /** Preliminary floating-point calculations */
    float32_t syncInductance = 0.5f * ( pParameters->pMotorParameters->LdInHenry + pParameters->pMotorParameters->LqInHenry );
    kGain = pParameters->hGain * syncInductance * PWM_FREQUENCY; /**< Always positive */
    C1 = kGain - pParameters->pMotorParameters->RsInOhms; /**< Can be negative */

    /** l11 coefficient calculation */
    f32a = 1.0f - pParameters->hGain;
    mcUtils_FloatToValueShiftPair( f32a, &pROLOCoeff->l11.val, &pROLOCoeff->l11.shr );

    /** m11 coefficient calculation */
    float32_t  invBasePower = 1.0f / ( BASE_CURRENT_IN_AMPS * BASE_VOLTAGE_IN_VOLTS );
    f32a = C1 * invBasePower * pParameters->hGain;
    mcUtils_FloatToValueShiftPair( f32a, &pROLOCoeff->m11.val, &pROLOCoeff->m11.shr );

    /** n11 coefficient calculation */
    f32a = pParameters->hGain;
    mcUtils_FloatToValueShiftPair( f32a, &pROLOCoeff->n11.val, &pROLOCoeff->n11.shr );

    /** k11 coefficient calculation */
    f32a = kGain * invBasePower;
    mcUtils_FloatToValueShiftPair( f32a, &pROLOCoeff->k11.val, &pROLOCoeff->k11.shr );

 #ifdef CROSS_COUPLING_ENABLED
    float32_t kSpeed = Q_SCALE( 1.0f / BASE_SPEED_IN_RPM );

    /** hhh coefficient calculation */
    f32a = C1 * invBasePower;
    mcUtils_FloatToValueShiftPair( f32a, &pROLOCoeff->hhh.val, &pROLOCoeff->hhh.shr );

    /** lll coefficient calculation */
    f32a = syncInductance * invBasePower / kSpeed;
    mcUtils_FloatToValueShiftPair( f32a, &pROLOCoeff->lll.val, &pROLOCoeff->lll.shr );

    /** xxx coefficient calculation */
    f32a = ( 1.0f / ( PWM_FREQUENCY * kSpeed ));
    mcUtils_FloatToValueShiftPair( f32a, &pROLOCoeff->xxx.val, &pROLOCoeff->xxx.shr );
 #endif

#if defined SRF_PLL
    float32_t zeta = 0.7f;
    float32_t radPerSecToRpm = 30.0f / ( pParameters->pMotorParameters->PolePairs * ONE_PI );

    KpSpeed = zeta * radPerSecToRpm *  pParameters->foInHertz;
    KiSpeed = radPerSecToRpm *  pParameters->foInHertz *  pParameters->foInHertz /2.0f;

    mcUtils_PiControlInit( KpSpeed, KiSpeed, pParameters->dt, &pState->bPIController );
    mcUtils_PiLimitUpdate( -Q_SCALE(1.0), Q_SCALE(1.0), &pState->bPIController );
#else
    /** ToDO: Remove hard coded numeric value */
    f32a = 1225.0f * (BASE_VOLTAGE_IN_VOLTS/ BASE_SPEED_IN_RPM )/ pParameters->pMotorParameters->KeInVrmsPerKrpm;
    mcUtils_FloatToValueShiftPair( f32a, &pState->oneByKeVal, &pState->oneByKeShift );

    /** Rotor position calibration time */
    pState->calibTimeinCounts = pParameters->calibTimeInSec / pParameters->dt;
#endif

    /** Speed to angle conversion factor calculation */
    f32a = (float32_t)K_TIME;
    pState->speedToAngle = Q_SCALE( f32a);

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


#ifdef CROSS_COUPLING_ENABLED
/**
 * @brief Calculates ROLO (Rotor Observer Linearization) coefficients.
 * 
 * This function computes variable coefficients for the observer using the current state,
 * including cross-coupling calculations if enabled.
 * 
 * @param[in] pState Pointer to the current state structure.
 */
__STATIC_INLINE void mcRpe_ROLOCoefficientsCalc(tmcRpe_State_s * const pState )
{
    int16_t saturatedSpeed;

    tmcRpe_ROLOCoefficients_s * pROLOCoeff = &pState->roloCoeff;

    /** Determine speed absolute value */
    if ( ( pState->speed < pState->minSpeedInRpm ) && ( pState->speed > -pState->minSpeedInRpm ) )
    {
        saturatedSpeed = pState->minSpeedInRpm;
    }
    else if ( pState->speed > 0.0f )
    {
        saturatedSpeed = (int16_t)pState->speed;
    }
    else
    {
        saturatedSpeed = -(int16_t)pState->speed;
    }

    /** Calculate variable coefficient n21 */
    UTILS_QNumberMultiply( pROLOCoeff->xxx, saturatedSpeed, &pROLOCoeff->n21 );

    /** Calculate variable coefficient m21 */
    UTILS_QNumberMultiply( pROLOCoeff->hhh, pROLOCoeff->n21.val, &pROLOCoeff->m21 );

    /** Calculate variable coefficient k21 */
    UTILS_QNumberMultiply( pROLOCoeff->lll,saturatedSpeed, &pROLOCoeff->k21 );

    /** Manage coefficients sign based on rotor sign */
    if ( 0 > pState->speed )
    {
        pROLOCoeff->n21.val = -pROLOCoeff->n21.val;
        pROLOCoeff->m21.val = -pROLOCoeff->m21.val;
        pROLOCoeff->k21.val = -pROLOCoeff->k21.val;
    }
}
#endif

/**
 * @brief Executes the rotor position estimation algorithm based on state and observer parameters.
 * 
 * This function updates the rotor position and speed estimations by calculating the observer's coefficients 
 * and performing back EMF estimation. It uses a Reduced-Order Luenberger Observer (ROLO) to estimate the 
 * rotor position, applying various transformations and clamping techniques when necessary.
 * 
 * @param[in] pParameters Pointer to the parameters structure.
 * @param[out] pSpeed Pointer to store the estimated rotor speed.
 * @param[out] pAngle Pointer to store the estimated rotor angle.
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

    tmcRpe_ROLOCoefficients_s * pROLOCoeff = &pState->roloCoeff;

    /** Check if the observer is enabled */
    if (pState->enable) {

#ifdef CROSS_COUPLING_ENABLED
        /** Calculate speed-dependent observer parameters */
        mcRpe_ROLOCoefficientsCalc(pState);
#endif

        /** Reduced-Order Luenberger Observer (ROLO) calculations */
        int16_t s16a;
        int16_t s16b;
        int16_t sine;
        int16_t cosine;
        int32_t s32a;
        int32_t s32b;

#ifdef AMP_CLAMP
        int32_t luzx;
        int32_t luzy;
#endif

        /** Compute zAlpha with l11 and m11 observer coefficients */
        s32a = mcUtils_MultAndRightShiftS16(pState->zAlpha, pROLOCoeff->l11.val, pROLOCoeff->l11.shr);
        s32a += mcUtils_MultAndRightShiftS16(pIAlphaBeta->alpha, pROLOCoeff->m11.val, pROLOCoeff->m11.shr);

#ifdef CROSS_COUPLING_ENABLED
        /** Cross-coupling compensation for zAlpha */
        s32a -= mcUtils_MultAndRightShiftS16(pIAlphaBeta->beta, pROLOCoeff->m21.val, pROLOCoeff->m21.shr);
#endif
        /** Update zAlpha with uAlphaLast and n11 observer coefficients */
        s32a += mcUtils_MultAndRightShiftS16(pState->uAlphaLast, pROLOCoeff->n11.val, pROLOCoeff->n11.shr);
#ifdef CROSS_COUPLING_ENABLED
        /** Cross-coupling compensation for uBetaLast */
        s32a -= mcUtils_MultAndRightShiftS16(pState->uBetaLast, pROLOCoeff->n21.val, pROLOCoeff->n21.shr);
#endif

        /** Compute zBeta with l11 and m11 observer coefficients */
        s32b = mcUtils_MultAndRightShiftS16(pState->zBeta, pROLOCoeff->l11.val, pROLOCoeff->l11.shr);

#ifdef CROSS_COUPLING_ENABLED
        /** Cross-coupling compensation for zBeta */
        s32b += mcUtils_MultAndRightShiftS16(pIAlphaBeta->alpha, pROLOCoeff->m21.val, pROLOCoeff->m21.shr);
#endif
        /** Update zBeta with uBetaLast and n11 observer coefficients */
        s32b += mcUtils_MultAndRightShiftS16(pIAlphaBeta->beta, pROLOCoeff->m11.val, pROLOCoeff->m11.shr);
#ifdef CROSS_COUPLING_ENABLED
        s32b += mcUtils_MultAndRightShiftS16(pState->uAlphaLast, pROLOCoeff->n21.val, pROLOCoeff->n21.shr);
#endif
        s32b += mcUtils_MultAndRightShiftS16(pState->uBetaLast, pROLOCoeff->n11.val, pROLOCoeff->n11.shr);

#ifdef AMP_CLAMP
        /** Clamp the vector amplitude to avoid divergence during startup */
        luzx = s32a;
        luzy = s32b;
        while ((-32767 > luzx) || (32767 < luzx) || (-32767 > luzy) || (32767 < luzy)) {
            luzx = mcUtils_RightShiftS32(luzx, 1U);
            luzy = mcUtils_RightShiftS32(luzy, 1U);
        }
        pState->zAlpha = (int16_t)luzx;
        pState->zBeta = (int16_t)luzy;
#else
        pState->zAlpha = (int16_t)s32a;
        pState->zBeta = (int16_t)s32b;
#endif

        /** Subtract k11 observer coefficient from alpha component */
        s32a -= mcUtils_MultAndRightShiftS16( pIAlphaBeta->alpha, pROLOCoeff->k11.val, pROLOCoeff->k11.shr );

#ifdef CROSS_COUPLING_ENABLED
        /** Cross-coupling compensation for k21 observer coefficient */
        s32a += mcUtils_MultAndRightShiftS16(pIAlphaBeta->beta, pROLOCoeff->k21.val, pROLOCoeff->k21.shr );

        /** Cross-coupling compensation for k21 observer coefficient */
        s32b -= mcUtils_MultAndRightShiftS16(pIAlphaBeta->alpha, pROLOCoeff->k21.val, pROLOCoeff->k21.shr );
#endif
        /** Subtract k11 observer coefficient from beta component */
        s32b -= mcUtils_MultAndRightShiftS16(pIAlphaBeta->beta, pROLOCoeff->k11.val, pROLOCoeff->k11.shr );

#ifdef AMP_CLAMP
        /** Clamp the calculated observer values */
        while ((-32767 > s32a) || (32767 < s32a) || (-32767 > s32b) || (32767 < s32b)) {
            s32a = mcUtils_RightShiftS32(s32a, 1U);
            s32b = mcUtils_RightShiftS32(s32b, 1U);
        }
#endif

        /** Update observer error terms */
        pState->eAlpha = (int16_t)s32a;
        pState->eBeta = (int16_t)s32b;

        /** Store previous control inputs */
        pState->uAlphaLast = pUAlphaBeta->alpha;
        pState->uBetaLast = pUAlphaBeta->beta;

        /** Calculate sine and cosine values for the estimated rotor angle */
        mcUtils_SineCosineCalculation(pState->phi, &sine, &cosine);

        /** Calculate q-axis back EMF */
        s16a = Q_MULTIPLY(pState->eBeta, cosine);
        s16b = Q_MULTIPLY(pState->eAlpha, sine);
        pState->eQ = s16a - s16b;

#if defined SRF_PLL
        /** Execute PI controller for speed estimation */
        mcUtils_PiControl(pState->eQ, &pState->bPIController);
        pState->speed = pState->bPIController.Yo;

        /** Update estimated electrical speed */
        *pSpeed = pState->speed;

        /** Update rotor electrical angle */
        pState->phi += (uint16_t)Q_MULTIPLY(pState->speed, pState->speedToAngle);
        if (pState->speed > 0) {
            *pAngle = pState->phi - Q15_ANGLE(PI_OVER_TWO);
        } else {
            *pAngle = pState->phi + Q15_ANGLE(PI_OVER_TWO);
        }
#else
        /** Calculate d-axis back EMF */
        s16a = Q_MULTIPLY(pState->eAlpha, cosine);
        s16b = Q_MULTIPLY(pState->eBeta, sine);
        pState->eD = s16a + s16b;

        /** Calculate speed based on back EMF */
        if (pState->eQ > 0) {
            s16a = pState->eQ - pState->eD;
        } else {
            s16a = pState->eQ + pState->eD;
        }

        /** Estimate rotor speed */
        pState->speed = ((int32_t)s16a * (int32_t)pState->oneByKeVal) >> pState->oneByKeShift;

        /** Calculate angle from speed */
        pState->phi += (uint16_t)Q_MULTIPLY(pState->speed, pState->speedToAngle);

#if defined ENABLE_PHI_OFFSET_COMPENSATION
        /** Apply rotor position offset compensation */
        mcRpe_RotorPostionOffsetCalc(pParameters, &pState->phiOffset);
#endif

        /** Update back-EMF voltages */
        pEAlphaBeta->alpha = pState->eAlpha;
        pEAlphaBeta->beta = pState->eBeta;

        /** Update speed and angle output */
        *pSpeed = pState->speed;
        *pAngle = pState->phi - pState->phiOffset;
#endif
    } else {
        /** Reset rotor position estimation */
        mcRpeI_RotorPositionEstimReset(pParameters);

        /** Set output speed and angle to zero */
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

    pState->eAlpha = 0;
    pState->eBeta = 0;
    pState->zAlpha = 0;
    pState->zBeta = 0;
    pState->eD = 0;
    pState->eQ = 0;
    pState->iAlphaLast = 0;
    pState->iBetaLast = 0;
    pState->uAlphaLast = 0;
    pState->uBetaLast = 0;
    pState->phi = 0;
    pState->speed = 0;
}
