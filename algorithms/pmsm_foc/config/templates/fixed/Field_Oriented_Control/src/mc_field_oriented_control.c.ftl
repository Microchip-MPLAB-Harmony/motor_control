/**
 * @brief 
 *    Field Oriented Control (FOC) source file
 *
 * @File Name 
 *    mc_field_oriented_control.c
 *
 * @Company 
 *   Microchip Technology Inc.
 *
 * @Summary
 *    This file implements functions for Field Oriented Control (FOC).
 *
 * @Description
 *   This file contains the implementation of functions necessary for Field Oriented
 *    Control (FOC), which is used to control motor currents based on given inputs.
 *    Functions include initialization, execution, resetting, current updating,
 *    torque calculation, and field weakening control.
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
#include "mc_field_oriented_control.h"

/*******************************************************************************
 * Local Configuration Options
 *******************************************************************************/
/** 
 * @brief Step size for open to close angle transition
 * 
 * This constant defines the step size for transitioning from an open loop to a closed 
 * loop control in the angle calculation.
 */
#define OPEN_TO_CLOSE_ANGLE_STEP_SIZE   (uint16_t)(4)

/** 
 * @brief DC bus voltage limit
 * 
 * This constant defines  DC bus voltage limit.
 */
#define  DC_BUS_VOLTAGE_LIMIT     Q_SCALE( 0.5658032638 )

/*******************************************************************************
 * Private Data Types
 *******************************************************************************/
/**
 * @brief Enumeration for FOC states
 */
typedef enum
{
    FocState_FlyingStart, /**< State for flying start */
    FocState_Startup,     /**< State for startup */
    FocState_ClosingLoop, /**< State for closing the loop */
    FocState_CloseLoop    /**< State for closed loop control */
} tmcFoc_FocState_e;

/**
 * @brief Data structure for FOC state
 */
typedef struct
{
    bool enable;                        /**< Enable flag */
    bool initDone;                      /**< Initialization done flag */
    tmcFoc_FocState_e FocState;         /**< Current FOC state */
    tmcTypes_DQ_s uDQ;                  /**< DQ axis voltage components */
    tmcTypes_AlphaBeta_s eAlphaBeta;    /**< Alpha-beta bemf components */
    uint16_t openLoopAngle;             /**< Open loop angle */
    int16_t openLoopSpeed;              /**< Open loop speed */
    int16_t iQref;                      /**< Q-axis current reference */
    int16_t iDref;                      /**< D-axis current reference */
    int16_t nRef;                       /**< Speed reference */
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER'>
    int16_t angleDifference;            /**< Angle difference for position calculation */
</#if>
    int16_t commandDirection;           /**< Commanded direction */
    int16_t ratedSpeedInRpm;            /**< Rated speed in RPM */

    tmcSup_Parameters_s bOpenLoopStartup; /**< Open loop startup parameters */
    tmcPwm_Parameters_s bPwmModulator;    /**< PWM modulator parameters */
    tmcFlx_Parameters_s bFluxController;  /**< Flux controller parameters */
    tmcTor_Parameters_s bTorqueController; /**< Torque controller parameters */
    tmcSpe_Parameters_s bSpeedController; /**< Speed controller parameters */
    tmcRef_Parameters_s bReferenceController; /**< Reference controller parameters */

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
    tmcRpc_Parameters_s bPositionCalculation; /**< Position calculation parameters */
<#else>
    tmcRpe_Parameters_s bPositionEstimation; /**< Position estimation parameters */
</#if>

    uint16_t duty[3u]; /**< PWM duty cycles for three phases */
} tmcFoc_State_s;

/*******************************************************************************
 * Private Variables
 *******************************************************************************/
static tmcFoc_State_s mcFoc_State_mds;

/*******************************************************************************
 * Interface Variables
 *******************************************************************************/
tmcFocI_ModuleData_s mcFocI_ModuleData_gds;

<#if ( MCPMSMFOC_CONTROL_TYPE == 'TORQUE_LOOP' ) >
int16_t mcFoc_FocOverrideCurrent_gds16 = 0;
</#if>

/*******************************************************************************
 * Macro Functions
 *******************************************************************************/
#define MULT_SHIFT     mcUtils_MultAndRightShiftS16

/*******************************************************************************
 * Private Functions
 *******************************************************************************/
/**
 * @brief Clarke Transformation
 *
 * @details
 * This function performs the Clarke transformation to convert three-phase
 * currents into two-phase alpha-beta currents.
 *
 * @param[in] pABC Pointer to the structure holding three-phase currents
 * @param[out] pAlphaBeta Pointer to the structure holding alpha-beta currents
 */
__STATIC_FORCEINLINE void mcFoc_ClarkeTransformation(const tmcTypes_ABC_s * pABC,
                                                     tmcTypes_AlphaBeta_s * const pAlphaBeta)
{
    /** Temporary variables used to store intermediate results */
    int16_t  s16a, s16b;

    /** Calculating alpha-axis component  */
    pAlphaBeta->alpha = pABC->a;

    /** Intermediate product is calculated by (1/(sqrt(3)) * a) */
    s16a = (int16_t)Q_MULTIPLY(pABC->a, Q_SCALE(ONE_OVER_SQRT_3) );

    /** Intermediate product is calculated by (2/sqrt(3) * b) */
    s16b = (int16_t)Q_MULTIPLY( pABC->b, Q_SCALE(TWO_OVER_SQRT_3 ));

    /** Calculate beta-axis component by adding the intermediate products */
    pAlphaBeta->beta = (int16_t)(s16a + s16b);
}

/**
 * @brief Park Transformation
 *
 * @details
 * This function performs the Park transformation to convert alpha-beta currents
 * into DQ currents using the provided sine and cosine values.
 *
 * @param[in] pAlphaBeta Pointer to the structure holding alpha-beta currents
 * @param[in] sine Sine value of the electrical angle
 * @param[in] cosine Cosine value of the electrical angle
 * @param[out] pDQ Pointer to the structure holding DQ currents
 */
__STATIC_FORCEINLINE void mcFoc_ParkTransformation(const tmcTypes_AlphaBeta_s * const pAlphaBeta,
                                                   const int16_t sine, const int16_t cosine,
                                                   tmcTypes_DQ_s * const pDQ)
{
    /** Temporary variables used to store intermediate results */
    int16_t s16a, s16b;

    /** Intermediate product is calculated by (pAlphaBeta->alpha * cosVal) */
    s16a = (int16_t)Q_MULTIPLY( pAlphaBeta->alpha, cosine);

    /** Intermediate product is calculated by (pAlphaBeta->beta * sinVal) */
    s16b = (int16_t)Q_MULTIPLY( pAlphaBeta->beta, sine);

    /** Calculate pId by adding the two intermediate s16a and s16b */
    pDQ->d = s16a + s16b;

    /** Intermediate product is calculated by (pAlphaBeta->alpha * sinVal) */
    s16a = (int16_t)Q_MULTIPLY( pAlphaBeta->alpha, sine);

    /** Intermediate product is calculated by (pAlphaBeta->beta * cosVal) */
    s16b = (int16_t)Q_MULTIPLY( pAlphaBeta->beta, cosine);

    /** Calculate pIq by subtracting the two intermediate s16a from s16b */
    pDQ->q = s16b - s16a;
}

/**
 * @brief Inverse Park Transformation
 *
 * @details
 * This function performs the inverse Park transformation to convert DQ currents
 * back into alpha-beta currents using the provided sine and cosine values.
 *
 * @param[in] pDQ Pointer to the structure holding DQ currents
 * @param[in] sine Sine value of the electrical angle
 * @param[in] cosine Cosine value of the electrical angle
 * @param[out] pAlphaBeta Pointer to the structure holding alpha-beta currents
 */
__STATIC_FORCEINLINE void mcFoc_InverseParkTransformation(const tmcTypes_DQ_s * const pDQ,
                                                          const int16_t sine, const int16_t cosine,
                                                          tmcTypes_AlphaBeta_s * const pAlphaBeta)
{
    /** Temporary variables used to store intermediate results */
    int16_t s16a, s16b;

    /** Intermediate product is calculated by (pAlphaBeta->alpha * cosVal) */
    s16a = (int16_t)Q_MULTIPLY( pDQ->d, cosine);

    /** Intermediate product is calculated by (pAlphaBeta->beta * sinVal) */
    s16b =(int16_t)Q_MULTIPLY( pDQ->q, sine);

    /** Calculate pId by adding the two intermediate s16a and s16b */
    pAlphaBeta->alpha = s16a - s16b;

    /** Intermediate product is calculated by (pAlphaBeta->alpha * sinVal) */
    s16a = (int16_t)Q_MULTIPLY( pDQ->d, sine );

    /** Intermediate product is calculated by (pAlphaBeta->beta * cosVal) */
    s16b = (int16_t)Q_MULTIPLY( pDQ->q, cosine );

    /** Calculate pIq by subtracting the two intermediate s16a from s16b */
    pAlphaBeta->beta = s16a + s16b;
}

/*******************************************************************************
 * Interface Functions
*******************************************************************************/
/**
 * @brief Initialize Field Oriented Control (FOC) module
 *
 * @details Initializes the FOC module.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void  mcFocI_FieldOrientedControlInit( tmcFocI_ModuleData_s * const pModule )
{
    /** Link state variable structure to the module */
    pModule->pStatePointer = (void *)&mcFoc_State_mds;

    /** Set parameters */
    mcFocI_ParametersSet(&pModule->dParameters);

    /** Update state variables */
    mcFoc_State_mds.commandDirection = 1;

    /** Update state variables */

    /** Initialize open loop start-up module */
    mcSupI_OpenLoopStartupInit( &mcFoc_State_mds.bOpenLoopStartup );

    /** Initialize reference control module */
    mcRefI_ReferenceControlInit( &mcFoc_State_mds.bReferenceController);

    /** Initialize speed control module */
    mcSpeI_SpeedControlInit( &mcFoc_State_mds.bSpeedController);

    /** Initialize torque control module */
    mcTorI_TorqueControlInit( &mcFoc_State_mds.bTorqueController);

    /** Initialize flux control module */
    mcFlxI_FluxControlInit( &mcFoc_State_mds.bFluxController);

    /** Initialize rotor position estimation  */
    mcRpeI_RotorPositionEstimInit( &mcFoc_State_mds.bPositionEstimation);

    /** Initialize PWM  module */
    mcPwmI_PulseWidthModulationInit( &mcFoc_State_mds.bPwmModulator );

    /** Set initialization flag */
    mcFoc_State_mds.initDone = true;
}

/**
 * @brief Enable Field Oriented Control (FOC) module
 *
 * @details Enables the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void  mcFocI_FieldOrientedControlEnable( tmcFocI_ModuleData_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFoc_State_s * pState;
    pState = (tmcFoc_State_s *)pParameters->pStatePointer;

    if( ( NULL == pState ) || ( !pState->initDone ))
    {
        /** Initialize parameters */
        mcFocI_FieldOrientedControlInit(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Enable open loop start-up module */
    mcSupI_OpenLoopStartupEnable( &mcFoc_State_mds.bOpenLoopStartup );

    /** Enable reference control module */
    mcRefI_ReferenceControlEnable( &mcFoc_State_mds.bReferenceController);

    /** Enable speed control module */
    mcSpeI_SpeedControlEnable( &mcFoc_State_mds.bSpeedController);

    /** Enable torque control module */
    mcTorI_TorqueControlEnable( &mcFoc_State_mds.bTorqueController);

    /** Enable flux control module */
    mcFlxI_FluxControlEnable( &mcFoc_State_mds.bFluxController);

    /** Enable rotor position estimation  */
    mcRpeI_RotorPositionEstimEnable( &mcFoc_State_mds.bPositionEstimation);

    /** Enable PWM  module */
    mcPwmI_PulseWidthModulationEnable( &mcFoc_State_mds.bPwmModulator );

    /** Set FOC state machine */
<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER' ) && ( MCPMSMFOC_ENABLE_FLYING_START == true ) >
    mcFoc_State_mds.FocState = FocState_FlyingStart;
<#else>
    mcFoc_State_mds.FocState = FocState_Startup;
</#if>

    /** Set enable flag as true */
    pState->enable = true;
}

/**
 * @brief Disable Field Oriented Control (FOC) module
 *
 * @details Disables the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void  mcFocI_FieldOrientedControlDisable( tmcFocI_ModuleData_s * const pParameters )
{
    /** Get the linked state variable */
    tmcFoc_State_s * pState;
    pState = (tmcFoc_State_s *)pParameters->pStatePointer;

    if( NULL != pState)
    {
        /** Reset state variables  */
        mcFocI_FieldOrientedControlReset(pParameters);
    }
    else
    {
        /** For MISRA Compliance */
    }

    /** Disable open loop start-up module */
    mcSupI_OpenLoopStartupDisable( &mcFoc_State_mds.bOpenLoopStartup );

    /** Disable reference control module */
    mcRefI_ReferenceControlDisable( &mcFoc_State_mds.bReferenceController);

    /** Disable speed control module */
    mcSpeI_SpeedControlDisable( &mcFoc_State_mds.bSpeedController);

    /** Disable torque control module */
    mcTorI_TorqueControlDisable( &mcFoc_State_mds.bTorqueController);

    /** Disable flux control module */
    mcFlxI_FluxControlDisable( &mcFoc_State_mds.bFluxController);

    /** Disable rotor position estimation  */
    mcRpeI_RotorPositionEstimDisable( &mcFoc_State_mds.bPositionEstimation);

    /** Disable PWM  module */
    mcPwmI_PulseWidthModulationDisable( &mcFoc_State_mds.bPwmModulator );

    /** Set enable flag as true */
    pState->enable = false;

}

/**
 * @brief Execute Field Oriented Control (FOC) fast loop
 *
 * @details Executes the fast loop of the FOC algorithm.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFocI_FieldOrientedControlFast( tmcFocI_ModuleData_s * const pModule )
#else
void mcFocI_FieldOrientedControlFast( tmcFocI_ModuleData_s * const pModule )
#endif
{
    int16_t sine = 0;
    int16_t cosine = 0;

    /** Get the linked state variable */
    tmcFoc_State_s * pState;
    pState = (tmcFoc_State_s *)pModule->pStatePointer;

    /** Get the output structure pointer */
    tmcFoc_Output_s * pOutput;
    pOutput = &pModule->dOutput;

    /** Read FOC inputs  */
    mcFocI_InputsRead( &pModule->dInput );

    /** Clarke transformation  */
    mcFoc_ClarkeTransformation( &pModule->dInput.iABC, &pOutput->iAlphaBeta);

    /** Rotor position estimation   */
    mcRpeI_RotorPositionEstim(&pState->bPositionEstimation,  &pOutput->iAlphaBeta, &pOutput->uAlphaBeta, 
                         &pState->eAlphaBeta, &pOutput->elecAngle, &pOutput->elecSpeed );

    switch(pState->FocState )
    {
<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER' ) && ( MCPMSMFOC_ENABLE_FLYING_START == true ) >
        case FocState_FlyingStart:
        {
            tmcTypes_StdReturn_e flyingStartStatus;
            flyingStartStatus = mcFlyI_FlyingStart( pState->flyingStart );

            if( StdReturn_Success == flyingStartStatus )
            {
                /** Set speed controller state */
                mcSpeI_SpeedControlManual( &pState->bSpeedController );

                /** Set flux controller controller state */
                mcFlxI_FluxControllerManual(&pState->bFluxController);

                /** Set torque controller state */
                mcTorI_TorqueControllerManual(&pState->bTorqueController);

                /** Set FOC state machine to CloseLoop */
                pState->FocState = FocState_CloseLoop;
            }
            else if( StdReturn_Fail == flyingStartStatus )
            {
                /** Set speed controller state */
                mcSpeI_SpeedControlManual( &pState->bSpeedController, 0u );

                /** Set flux controller controller state */
                mcFlxI_FluxControllerManual(&pState->bFluxController, 0u);

                /** Set torque controller state */
                mcTorI_TorqueControllerManual(&pState->bTorqueController, 0u);

                /** Set FOC state machine to CloseLoop */
                pState->FocState = FocState_Startup;
            }
            else
            {
                /** Stay in flying start state */
            }
            break;
        }
</#if>
        case FocState_Startup:
        {
            tmcTypes_StdReturn_e startupStatus;
            startupStatus = mcSupI_OpenLoopStartup( &pState->bOpenLoopStartup, pState->commandDirection,
                                                                &pState->iQref, &pState->iDref, &pState->openLoopAngle, &pState->openLoopSpeed );
            if( StdReturn_Complete == startupStatus )
            {
<#if ( MCPMSMFOC_CONTROL_TYPE != 'TORQUE_LOOP' ) >
                /** Set speed controller state */
                mcSpeI_SpeedControlManual( &pState->bSpeedController, pState->iQref );
</#if>

                /** Calculate open loop and close loop angle difference */
                pState->angleDifference = UTIL_AngleDifferenceGet( pState->openLoopAngle, pOutput->elecAngle );

                /** Set FOC state machine to ClosingLoop */
               pState->FocState = FocState_ClosingLoop;
            }

            pState->nRef = pState->openLoopSpeed;

            /** Sine-cosine calculation */
            mcUtils_SineCosineCalculation( pState->openLoopAngle, &sine, &cosine );
            break;
        }

        case FocState_ClosingLoop:
        {
            pOutput->elecAngle = pOutput->elecAngle + pState->angleDifference;

            /** Sine-cosine calculation */
            mcUtils_SineCosineCalculation( pOutput->elecAngle, &sine, &cosine );

            /** Linear ramp */
            UTILS_LinearRamp(&pState->angleDifference, OPEN_TO_CLOSE_ANGLE_STEP_SIZE, 0u);

            /** Switch the FOC state to close loop if angle difference is zero */
            if( pState->angleDifference == 0u )
            {
                /** Set FOC state machine to CloseLoop */
                pState->FocState = FocState_CloseLoop;
            }

<#if ( MCPMSMFOC_CONTROL_TYPE != 'TORQUE_LOOP' ) >
            /** Execute speed controller */
            mcSpeI_SpeedControlAuto(&pState->bSpeedController, pState->nRef,
                                               pOutput->elecSpeed, &pState->iQref );
<#else>
            pState->iQref = mcFoc_FocOverrideCurrent_gds16;
</#if>
            break;
        }
        case FocState_CloseLoop:
        {
            /** Sine-cosine calculation */
            mcUtils_SineCosineCalculation( pOutput->elecAngle, &sine, &cosine );

            /** Reference Control */
            mcRefI_ReferenceControl( &mcFoc_State_mds.bReferenceController, pModule->dInput.reference, &pState->nRef );

<#if ( MCPMSMFOC_CONTROL_TYPE != 'TORQUE_LOOP' ) >
            /** Execute speed controller */
            pState->nRef *= pState->commandDirection;
            mcSpeI_SpeedControlAuto(&pState->bSpeedController, pState->nRef,
                                                  pOutput->elecSpeed, &pState->iQref );
<#else>
            pState->iQref = mcFoc_FocOverrideCurrent_gds16;
</#if>
            break;
        }
        default:
        {
            /** For MISRA Compliance */
        }
        break;
    }

    /** Park Transformation   */
    mcFoc_ParkTransformation( &pOutput->iAlphaBeta, sine, cosine, &pOutput->iDQ );

    /** Execute flux control. Note. Implied rescale of 0.636619 * Vdc  to 1 */
    int16_t  maxBusVoltage = Q_MULTIPLY( pModule->dInput.uBus, DC_BUS_VOLTAGE_LIMIT );
    mcFlxI_FluxControlAuto( &pState->bFluxController, pState->iDref, pOutput->iDQ.d, maxBusVoltage, &pState->uDQ.d );

    /** Calculate maximum allowed Q-axis voltage   */
    int32_t uqLimitSquare =((int32_t)maxBusVoltage * (int32_t)maxBusVoltage) - ( (int32_t)pState->uDQ.d * (int32_t)pState->uDQ.d );
    int16_t uqLimit = mcUtils_SquareRoot( uqLimitSquare );

    /** Calculate the maximum allowed Q-axis reference current  */
    int32_t iqrefLimitSquare = ((int32_t)Q_SCALE(1.0) * (int32_t)Q_SCALE(1.0)) - ( (int32_t)pState->iDref * (int32_t)pState->iDref );
    int16_t iqrefLimit = mcUtils_SquareRoot( iqrefLimitSquare );

    UTIL_ApplyClampS16( &pState->iQref, iqrefLimit, -iqrefLimit );

    /** Execute torque control  */
    mcTorI_TorqueControlAuto( &pState->bTorqueController, pState->iQref, pOutput->iDQ.q, uqLimit, &pState->uDQ.q );

    /** Inverse Park transformation  */
    mcFoc_InverseParkTransformation( &pState->uDQ, sine, cosine, &pOutput->uAlphaBeta );

    /** Space vector modulation  */
    mcPwmI_PulseWidthModulation(&pState->bPwmModulator, maxBusVoltage, &pOutput->uAlphaBeta, mcPwmI_Duty_gau16 );

<#if ( MCPMSMFOC_ENABLE_MTPA == true ) || ( MCPMSMFOC_ENABLE_FW == true ) >
    /** Get Flux reference value  */
    mcFlxI_FluxReferenceGet( &pState->bFluxController, &pState->uDQ, &pOutput->iDQ,
                                   &pState->eAlphaBeta, pOutput->elecSpeed,  maxBusVoltage, &pState->iDref );
</#if>

}

/**
 * @brief Execute Field Oriented Control (FOC) slow loop
 *
 * @details Executes the slow loop of the FOC algorithm.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFocI_FieldOrientedControlSlow( const tmcFocI_ModuleData_s * const pParameters )
#else
void mcFocI_FieldOrientedControlSlow( const tmcFocI_ModuleData_s * const pParameters )
#endif
{

}

/**
 * @brief Change motor direction
 *
 * @details Changes the direction of the motor.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_MotorDirectionChange(const tmcFocI_ModuleData_s * const pModule )
{
    /** Get the linked state variable */
    tmcFoc_State_s * pState;
    pState = (tmcFoc_State_s *)pModule->pStatePointer;

    /** Change motor direction flag  */
    pState->commandDirection *= -1;

}

/**
 * @brief Reset Field Oriented Control (FOC)
 *
 * @details Resets the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlReset( const tmcFocI_ModuleData_s * const pParameters )
{
    /** Reset open loop startup state variables  */
}
