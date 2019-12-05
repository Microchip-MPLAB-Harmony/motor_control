/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_app.c

  Summary:
    This file contains the state machine and control loop of the motor control
   algorithm.

  Description:
    This file contains the control loop of the pmsm_foc_pll_estimator.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"                // SYS function prototypes
#include "device.h"
#include "userparams.h"
#include "mc_app.h"
#if defined (USE_FILE_INLINING )    &&    !defined ( MCAPP_C  ) 
#define   MCAPP_C
        #include "mc_infrastructure.c"
        #include "mc_currMeasurement.c"
        #include "mc_rotorPosition.c"
        #include "mc_voltageMeasurement.c"
        #include "mc_pwm.c"
        #include "mc_speed.c"
        #include "mc_errorHandler.c"
        #include "mc_picontrol.c"
#else
        #include "mc_infrastructure.h"
        #include "mc_currMeasurement.h"
        #include "mc_rotorPosition.h"
        #include "mc_voltageMeasurement.h"
        #include "mc_pwm.h"
        #include "mc_speed.h"
        #include "mc_errorHandler.h"
        #include "mc_picontrol.h"
#endif

#include "X2CScope.h"
#include "X2CScopeCommunication.h"
#include "math.h"


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/
__STATIC_INLINE float MCAPP_IdrefCalculation( void );
__STATIC_INLINE float MCAPP_IqrefCalculation( void );

void MCAPP_SignalTransformation(void);
void MCAPP_StateMachine( void );
void MCAPP_CurrentControl(void);


#if (1U == FIELD_WEAKENING )
static void MCAPP_InitializeFieldWeakening( void );
__STATIC_INLINE void MCAPP_FieldWeakening(const tMCAPP_FIELD_WEAKENING_INPUT_S  * const fieldWeakeningInput,
                                   tMCAPP_FIELD_WEAKENING_OUTPUT_S * const fieldWeakeningOutput );
static void MCAPP_ResetFieldWeakening( void );
#endif


/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
MCAPP_CONTROL_PARAM gCtrlParam;
tMCAPP_FIELD_WEAKENING_INPUT_S        gFieldWeakeningInput;
tMCAPP_FIELD_WEAKENING_OUTPUT_S       gFieldWeakeningOutput;
tMCAPP_FIELD_WEAKENING_STATE_S        gFieldWeakeningState;
tMCAPP_FIELD_WEAKENING_PARAM_S        gFieldWeakeningParam;
tMCAPP_CLOSING_LOOP_STATE_S           gMCAPP_ClosingLoopState;
tMCAPP_CLOSING_LOOP_PARAM_S           gMCAPP_ClosingLoopParam;
tMCAPP_OPEN_LOOP_STATE_S             gMCAPP_OpenLoopState = { 0.0f };
tMCAPP_OPEN_LOOP_PARAM_S             gMCAPP_OpenLoopParam = { 
                                                                  OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME,
                                                                  OPEN_LOOP_RAMPSPEED_INCREASERATE,
                                                                  Q_CURRENT_REF_OPENLOOP
                                                              };


/*****************************************************************************/
/*                   LOCAL FUNCTIONS                                         */
/*****************************************************************************/

/*****************************************************************************/
/* Function name: MCAPP_InitilaizeOpenLoopControl                            */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Initialize open loop parameters and state                    */
/*****************************************************************************/
static void MCAPP_InitilaizeOpenLoopControl( void )
{
    /* Initilaize open loop parameters */
    gMCAPP_OpenLoopParam.maxOpenLoopSpeed  = OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME;
    gMCAPP_OpenLoopParam.openLoopSpeedRate = OPEN_LOOP_RAMPSPEED_INCREASERATE;
    gMCAPP_OpenLoopParam.openLoopCurrent   = Q_CURRENT_REF_OPENLOOP;

    /* Initialize open loop state */
    gMCAPP_OpenLoopState.startup_angle_ramp_rads_per_sec = 0.0f;
}

/*****************************************************************************/
/* Function name: MCAPP_OpenLoopControl                                      */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Open Loop Current                                            */
/*****************************************************************************/
__STATIC_INLINE tMCRPOS_STATUS_E MCAPP_OpenLoopControl( const int16_t rotationSign )
{
    tMCRPOS_STATUS_E status = RUNNING;
    if (gMCAPP_OpenLoopState.startup_angle_ramp_rads_per_sec  < gMCAPP_OpenLoopParam.maxOpenLoopSpeed )
    {
        gMCAPP_OpenLoopState.startup_angle_ramp_rads_per_sec += gMCAPP_OpenLoopParam.openLoopSpeedRate;
    }
    else
    {
        status = COMPLETE;
    }

    /* Set open loop reference current */
    gCtrlParam.iqRef = rotationSign * gMCAPP_OpenLoopParam.openLoopCurrent;
    gCtrlParam.idRef = 0.0f;
    
    gCtrlParam.velRef = gMCAPP_OpenLoopState.startup_angle_ramp_rads_per_sec / FAST_LOOP_TIME_SEC;
    gMCLIB_Position.angle +=  ( (float)rotationSign * gMCAPP_OpenLoopState.startup_angle_ramp_rads_per_sec );
    MCLIB_WrapAngle(&gMCLIB_Position.angle);
    return status;
}

/*****************************************************************************/
/* Function name: MCAPP_ResetOpenLoopControl                                 */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Reset open loop parameters and state                         */
/*****************************************************************************/
static void MCAPP_ResetOpenLoopControl( void )
{
    /* Reset open loop state */
    gMCAPP_OpenLoopState.startup_angle_ramp_rads_per_sec = 0.0f;
}


#if(1U == FIELD_WEAKENING )
/*****************************************************************************/
/* Function name: MCAPP_InitializeFieldWeakening                             */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Initialize field weakening parameters and state              */
/*****************************************************************************/
static void MCAPP_InitializeFieldWeakening( void )
{
         /* Initialize field weakening state variables and parameters */
    gFieldWeakeningParam.Wbase           =     RATED_SPEED_RAD_PER_SEC_ELEC;
    gFieldWeakeningParam.UmaxSqr         =     MAX_STATOR_VOLT_SQUARE;                 
    gFieldWeakeningParam. EsFiltCoeff    =     KFILTER_ESDQ;           
    gFieldWeakeningParam.Ls              =     MOTOR_PER_PHASE_INDUCTANCE ;             
    gFieldWeakeningParam.Rs              =     MOTOR_PER_PHASE_RESISTANCE ;              
    gFieldWeakeningParam.fs              =     PWM_FREQUENCY;                           
    gFieldWeakeningParam.idmax           =     MAX_FW_NEGATIVE_ID_REF;          
         
    /* Reset the state variables of field weakening */
    gFieldWeakeningState.UqrefFilt       =     0.0f;
    gFieldWeakeningState.iqrefFilt       =     0.0f;
    gFieldWeakeningState.iqref_1         =     0.0f;
         
}


/******************************************************************************/
/* Function name: MCAPP_FieldWeakening                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Field weakening                                               */
/******************************************************************************/
__STATIC_INLINE void MCAPP_FieldWeakening( const tMCAPP_FIELD_WEAKENING_INPUT_S * const fieldWeakeningInput,
                                   tMCAPP_FIELD_WEAKENING_OUTPUT_S * const fieldWeakeningOutput )
{
    float UqRef, UdSquare,OmegaLs, idref;

    UdSquare = fieldWeakeningInput->Ud * fieldWeakeningInput->Ud;

    if( fieldWeakeningInput->Ws > gFieldWeakeningParam.Wbase )
    {
        if(UdSquare >= gFieldWeakeningParam.UmaxSqr)
        {
            UdSquare = gFieldWeakeningParam.UmaxSqr;
        }

        UqRef = sqrtf((float)(  gFieldWeakeningParam.UmaxSqr - UdSquare));

        gFieldWeakeningState.UqrefFilt =     gFieldWeakeningState.UqrefFilt
                                        + ( ( UqRef - gFieldWeakeningState.UqrefFilt) *  gFieldWeakeningParam.EsFiltCoeff );

        OmegaLs = ( fieldWeakeningInput->Ws *  gFieldWeakeningParam.Ls);

        /* Id reference for feed forward control */
        idref = (( gFieldWeakeningState.UqrefFilt * fieldWeakeningInput->Umax )
              - (  gFieldWeakeningParam.Rs * fieldWeakeningInput->iqref )
              - (  gFieldWeakeningParam.Ls * (( fieldWeakeningInput->iqref - gFieldWeakeningState.iqref_1) *  gFieldWeakeningParam.fs) )
              - ( fieldWeakeningInput->Esfilt )) / OmegaLs;

        gFieldWeakeningState.iqref_1 = fieldWeakeningInput->iqref;
     
        /* d-axis current saturation  */
        if(idref > 0)
        {
            fieldWeakeningOutput->idref = 0;
        }
        else if( idref <  gFieldWeakeningParam.idmax)
        {
            fieldWeakeningOutput->idref =  gFieldWeakeningParam.idmax;
        }
        else
        {
            fieldWeakeningOutput->idref = idref;
        }
    }
    else
    {
        /* Field weakening is disabled below rated speed. */
        fieldWeakeningOutput->idref = 0;
    }
}

/*****************************************************************************/
/* Function name: MCAPP_ResetFieldWeakening                                  */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Reset field weakening state                                  */
/*****************************************************************************/
static void MCAPP_ResetFieldWeakening( void )
{     
    /* Reset the state variables of field weakening */
    gFieldWeakeningState.UqrefFilt     =        0.0f;
    gFieldWeakeningState.iqrefFilt       =       0.0f;
    gFieldWeakeningState.iqref_1         =       0.0f;
         
}
#endif


void MCAPP_SignalTransformation(void )
{
    /* Clarke transform */
    MCLIB_ClarkeTransform(&gMCCUR_OutputSignals.phaseCurrents, &gMCLIB_CurrentAlphaBeta);

    /* Park transform */
    MCLIB_ParkTransform(&gMCLIB_CurrentAlphaBeta, &gMCLIB_Position, &gMCLIB_CurrentDQ);
}

/*******************************************************************************/
/* Function name: MCAPP_iqrefCalculation                                       */
/* Function parameters: None                                                   */
/* Function return: None                                                       */
/* Description: Q-axis reference current calculation in close loop             */
/*                       control                                               */
/*******************************************************************************/
float MCAPP_IqrefCalculation( void )
{
    float iqRef = 0.0f;
  #if( 0U == TORQUE_MODE )

    /* Quadrature axis reference current limitation */
    if( gMCCON_IdController.inRef < MAX_MOTOR_CURRENT )
    {
        gMCCON_SpeedController.outMax = sqrtf((float)(MAX_CURRENT_SQUARED - (float)( gMCCON_IdController.inRef * gMCCON_IdController.inRef )));
        gMCCON_SpeedController.outMin = -gMCCON_SpeedController.outMax;
    }
    else 
    {
        gMCCON_SpeedController.outMax = 0.0f;
        gMCCON_SpeedController.outMin = 0.0f;
    }
    
    /* Execute the velocity control loop */
    gMCCON_SpeedController.inMeas = gMCRPOS_OutputSignals.Speed;
    gMCCON_SpeedController.inRef  = ( gCtrlParam.rotationSign * gMCSPE_OutputSignals.commandSpeed );
    MCCON_PIControl(&gMCCON_SpeedController);
    iqRef = gMCCON_SpeedController.out;

    
  #else
    iqRef = gCtrlParam.rotationSign * Q_CURRENT_REF_OPENLOOP;
  #endif	
   return iqRef;
}

/******************************************************************************/
/* Function name: MCAPP_iqrefCalculation                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: D-axis reference current calculation in close loop            */
/*                        control                                             */
/******************************************************************************/
float MCAPP_IdrefCalculation( void )
{
    static float idRef;
#if(FIELD_WEAKENING == 1U)
    float VqRefSquare;

    /* Dynamic d-q adjustment with d component priority */
    VqRefSquare = MAX_STATOR_VOLT_SQUARE - gMCCON_IdController.out * gMCCON_IdController.out;

    gMCCON_IqController.outMax = sqrtf((float)(VqRefSquare));

    /* Read inputs for field weakening  */
    gFieldWeakeningInput.yd = gMCCON_IdController.out;
    gFieldWeakeningInput.Ws = gMCSPE_OutputSignals.commandSpeed;
    gFieldWeakeningInput.iqref =  ( gCtrlParam.iqRef >= 0.0f )? (gCtrlParam.iqRef):(-gCtrlParam.iqRef);
    gFieldWeakeningInput.Ud =  gMCLIB_VoltageDQ.directAxis;
    gFieldWeakeningInput.Umax = gMCVOL_OutputSignals.Umax;
    gFieldWeakeningInput.Esfilt = gMCRPOS_OutputSignals.Esfilt;

    MCAPP_FieldWeakening(&gFieldWeakeningInput, &gFieldWeakeningOutput);

    /* Write field weakening output */
    idRef = idRef + KFILTER_POT * ( gFieldWeakeningOutput.idref -  idRef);
    
#else
    idRef = 0;
#endif 

    return idRef;
}

/******************************************************************************/
/* Function name: MCAPP_MotorControl                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Motor Control state                                           */
/******************************************************************************/
void MCAPP_StateMachine( void )
{
    switch(gCtrlParam.s_ControlStatus_e)
    {
        case MCAPP_IDLE:
        {
            /* Do not do anything */
            gMCRPOS_RotorAlignOutput.iqRef = 0;
           
        }
        break;
        case MCAPP_FIELD_ALIGNMENT:
        {
            /* Read inputs for initial rotor position detection */
            if( COMPLETE == MCRPO_InitialRotorPositonDetection( &gMCRPOS_RotorAlignOutput))
            {
                gCtrlParam.s_ControlStatus_e = MCAPP_CLOSED_LOOP;
            }
            gCtrlParam.iqRef =  gCtrlParam.rotationSign * gMCRPOS_RotorAlignOutput.iqRef;
            gCtrlParam.idRef =  gMCRPOS_RotorAlignOutput.idRef;
            gMCLIB_Position.angle =  gCtrlParam.rotationSign *  gMCRPOS_RotorAlignOutput.angle;
        }
        break;

        case MCAPP_CLOSED_LOOP:
        {
            /* Switched to closed by slowly decreasing the offset which is present in the estimated angle during open loop */
            gMCLIB_Position.angle = gMCRPOS_OutputSignals.Angle;

            /* d- axis reference current calculation */
            gCtrlParam.idRef = MCAPP_IdrefCalculation();

            /* q- axis reference current calculation */
            gCtrlParam.iqRef = MCAPP_IqrefCalculation();
        }
        break;
        default:
        {
            /* Undefined state: Should never come here */
        }
    }             
         
}

/*******************************************************************************/
/* Function name: MCAPP_CurrentControl                                         */
/* Function parameters: None                                                   */
/* Function return: None                                                       */
/* Description: Current control                                                */
/*******************************************************************************/
void MCAPP_CurrentControl( void )
{
    /* PI control for Iq torque control loop */
    gMCCON_IqController.inMeas = gMCLIB_CurrentDQ.quadratureAxis;
    gMCCON_IqController.inRef  = gCtrlParam.iqRef;
    MCCON_PIControl(&gMCCON_IqController);
    gMCLIB_VoltageDQ.quadratureAxis = gMCCON_IqController.out;

    /* PI control for Id flux control loop */
    gMCCON_IdController.inMeas = gMCLIB_CurrentDQ.directAxis;
    gMCCON_IdController.inRef  = gCtrlParam.idRef;
    MCCON_PIControl(&gMCCON_IdController);
    gMCLIB_VoltageDQ.directAxis = gMCCON_IdController.out;
}


/******************************************************************************/
/*                        INTERFACE FUNCTIONS                                 */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCAPP_InitializeMotorControl                                */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialize control loop variables.                            */
/******************************************************************************/
 void MCAPP_InitializeMotorControl(void)
{
    /* Parameter initialization for FOC */
    MCCON_InitializePIParameters();

    /* Initilaize open loop control */
    MCAPP_InitilaizeOpenLoopControl();
#if (1U == FIELD_WEAKENING )
    MCAPP_InitializeFieldWeakening();
#endif        
                 
    gMCLIB_SVPWM.period = MCPWM_PrimaryPeriodGet();
    gMCLIB_SVPWM.neutralPWM = (uint32_t)(0.5f * gMCLIB_SVPWM.period );
}


/******************************************************************************/
/* Function name: MCAPP_MotorControl                                      *
 * Function parameters: None                                                  *
 * Function return: None                                                      *
 * Description: ADC end of conversion interrupt is used for executing fast    *
 *              control loop.It estimates speed and rotor angle based upon    *
 *              the phase current measurements and updates duty.              *
 ******************************************************************************/
void MCAPP_MotorControl( void )
{            
    /* Get input signals for motor control */
    MCAPP_SignalTransformation();

    /* D and Q axis Current control */
    MCAPP_StateMachine();
         
    /* Direct and Quadrature axis current control */
    MCAPP_CurrentControl();
       
    /* PWM modulation */
    MCPWM_PWMModulator();
       
    /* X2C scope update */
    X2CScope_Update();

}


/******************************************************************************/
/* Function name: MCAPP_InitializeMotorControl                                */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialize control loop variables.                            */
/******************************************************************************/
 void MCAPP_ResetMotorControl(void)
{
    /* Parameter initialization for FOC */
    MCCON_ResetPIParameters();

    /* Initilaize open loop control */
    MCAPP_ResetOpenLoopControl();
#if (1U == FIELD_WEAKENING )
    MCAPP_ResetFieldWeakening();
#endif        
                 
    gMCLIB_SVPWM.period = MCPWM_PrimaryPeriodGet();
    gMCLIB_SVPWM.neutralPWM = (uint32_t)(0.5f * gMCLIB_SVPWM.period );
}


/*******************************************************************************
 End of File
*/
