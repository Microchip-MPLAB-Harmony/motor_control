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
        #include "mc_control.h"
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

void MCAPP_SignalMeasurement( void );
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
#if(1U == OPEN_LOOP_FUNCTIONING)
tMCAPP_OPEN_LOOP_STATE_S             gMCAPP_OpenLoopState = { 0.0f };
tMCAPP_OPEN_LOOP_PARAM_S             gMCAPP_OpenLoopParam = { 
                                                                  OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME,
                                                                  OPEN_LOOP_RAMPSPEED_INCREASERATE,
                                                                  Q_CURRENT_REF_OPENLOOP
                                                            };
#endif


/******************************************************************************/
/*                   LOCAL FUNCTIONS                                          */
/******************************************************************************/

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


/******************************************************************************/
/* Function name: MCAPP_SignalProcessing                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Read and process inputs for field oriented Control            */
/******************************************************************************/
void MCAPP_SignalMeasurement( void )
{
    /* Current Measurement */
    MCCUR_CurrentMeasurement(&gMCCUR_PhaseCurrent);

    /* Voltage measurement */
    MCVOL_voltageMeasurement(&gMCVOL_Voltage);
         
    /* Estimates the rotor angle and speed. */
    MCRPOS_PositionMeasurement(&gMCRPOS_InputSignals, &gMCRPOS_OutputSignals);
}


/******************************************************************************/
/* Function name: MCAPP_SignalTransformation                                  */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Signal Transformation for FOC                                 */
/******************************************************************************/
void MCAPP_SignalTransformation(void )
{
    /* Clarke transform */
    MCLIB_ClarkeTransform(&gMCCUR_PhaseCurrent, &gMCLIB_CurrentAlphaBeta);

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
    if( gPIParmD.inRef < 0.0f )
    {
        gPIParmQref.outMax = sqrtf((float)(MAX_CURRENT_SQUARED - (float)( gPIParmD.inRef * gPIParmD.inRef )));
        gPIParmQref.outMin = -gPIParmQref.outMax;
    }
    /* Execute the velocity control loop */
    gPIParmQref.inMeas = gMCRPOS_OutputSignals.Speed;
    gPIParmQref.inRef  = ( gCtrlParam.rotationSign * gCtrlParam.velRef );
    MCCON_PIControl(&gPIParmQref);
    iqRef = gPIParmQref.out;
    
  #else
    iqRef = gCtrlParam.rotationSign * Q_CURRENT_REF_OPENLOOP;
  #endif	
   return iqRef;
}

/*******************************************************************************/
/* Function name: MCAPP_iqrefCalculation                                       */
/* Function parameters: None                                                   */
/* Function return: None                                                       */
/* Description: D-axis reference current calculation in close loop             */
/*                        control                                              */
/*******************************************************************************/
float MCAPP_IdrefCalculation( void )
{
    static float idRef = 0;
#if(FIELD_WEAKENING == 1)
    float VqRefSquare;

    /* Dynamic d-q adjustment with d component priority */
    VqRefSquare = MAX_STATOR_VOLT_SQUARE - gPIParmD.out * gPIParmD.out;

    gPIParmQ.outMax = sqrtf((float)(VqRefSquare));

    /* Read inputs for field weakening  */
    gFieldWeakeningInput.yd = gPIParmD.out;
    gFieldWeakeningInput.Ws = gCtrlParam.velRef;
    gFieldWeakeningInput.iqref = ( gCtrlParam.iqRef >= 0.0f )?(gCtrlParam.iqRef): (-gCtrlParam.iqRef);
    gFieldWeakeningInput.Ud =  gMCLIB_VoltageDQ.directAxis;
    gFieldWeakeningInput.Umax = gMCVOL_Voltage.Umax;
    gFieldWeakeningInput.Esfilt = gFieldWeakeningInput.Esfilt +
                                (((MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_ELEC * gCtrlParam.velRef)
                                 - gFieldWeakeningInput.Esfilt) * KFILTER_BEMF_AMPLITUDE) ;	

    /* Field weakening */
    MCAPP_FieldWeakening(&gFieldWeakeningInput, &gFieldWeakeningOutput);
    
    /* Write field weakening output */
    idRef = idRef + KFILTER_POT * ( gFieldWeakeningOutput.idref - idRef );

#else
    idRef = 0;
#endif 
    

    return idRef;
}

#if(1U == OPEN_LOOP_FUNCTIONING )
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
#endif

/*******************************************************************************/
/* Function name: MCAPP_MotorControl                                           */
/* Function parameters: None                                                   */
/* Function return: None                                                       */
/* Description: Motor Control state                                            */
/******************************************************************************/
void MCAPP_StateMachine( void )
{
    switch(gCtrlParam.s_ControlStatus_e)
    {
        case MCAPP_IDLE:
        {
            /* Do not do anything */
           
        }
        break;
        case MCAPP_FIELD_ALIGNMENT:
        {
            gCtrlParam.iqRef =  gCtrlParam.rotationSign * gMCRPOS_RotorAlignOutput.iqRef;
            gCtrlParam.idRef =  gMCRPOS_RotorAlignOutput.idRef;
            gMCLIB_Position.angle = gCtrlParam.rotationSign * gMCRPOS_RotorAlignOutput.angle;

            MCLIB_WrapAngle( & gMCLIB_Position.angle);

            /* Read inputs for initial rotor position detection */
            if( COMPLETE == MCRPOS_InitialRotorPositonDetection( &gMCRPOS_RotorAlignInput, &gMCRPOS_RotorAlignOutput))
            {
                gCtrlParam.velRef  = gMCSPE_Parameters.minSpeed;
                gCtrlParam.iqRef =  0;
                gCtrlParam.idRef =  0;
                gMCLIB_Position.angle = 0;
              #if( 1U == OPEN_LOOP_FUNCTIONING )
                gCtrlParam.s_ControlStatus_e = MCAPP_OPEN_LOOP;
              #else
                gCtrlParam.s_ControlStatus_e = MCAPP_CLOSED_LOOP;
              #endif 
            }
        }
        break;
      #if( 1U == OPEN_LOOP_FUNCTIONING )
        case MCAPP_OPEN_LOOP:
        {
            if( COMPLETE == MCAPP_OpenLoopControl( gCtrlParam.rotationSign))
            {

            }
        }
        break;
      #endif 
        case MCAPP_CLOSED_LOOP:
        {
            /* Get the angle from PLL Estimator  */
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
    gPIParmQ.inMeas = gMCLIB_CurrentDQ.quadratureAxis;
    gPIParmQ.inRef  = gCtrlParam.iqRef;
    MCCON_PIControl(&gPIParmQ);
    gMCLIB_VoltageDQ.quadratureAxis = gPIParmQ.out;

    /* PI control for Id flux control loop */
    gPIParmD.inMeas = gMCLIB_CurrentDQ.directAxis;
    gPIParmD.inRef  = gCtrlParam.idRef;
    MCCON_PIControl(&gPIParmD);
    gMCLIB_VoltageDQ.directAxis = gPIParmD.out;
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

#if (1U == FIELD_WEAKENING )
    MCAPP_InitializeFieldWeakening();
#endif        
                 
    gMCLIB_SVPWM.period = MCPWM_PrimaryPeriodGet();
    gMCLIB_SVPWM.neutralPWM = (uint32_t)(0.5f * gMCLIB_SVPWM.period );
}


/******************************************************************************/
/* Function name: MCAPP_ControlLoopISR                                      *
 * Function parameters: None                                                  *
 * Function return: None                                                      *
 * Description: ADC end of conversion interrupt is used for executing fast    *
 *              control loop.It estimates speed and rotor angle based upon    *
 *              the phase current measurements and updates duty.              *
 ******************************************************************************/
void MCAPP_ControlLoopISR(uint32_t status, uintptr_t context)
{            
    
    /* Get input signals for motor control */
    MCAPP_SignalMeasurement();

    /* Get input signals for motor control */
    MCAPP_SignalTransformation();

    /* D and Q axis Current control */
    MCAPP_StateMachine();
         
    /* Direct and Quadrature axis current control */
    MCAPP_CurrentControl();
       
    /* PWM modulation */
    MCPWM_PWMModulator();
       
    /* sync count for slow control loop execution */
    MCINF_LoopSynchronization();

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

#if (1U == FIELD_WEAKENING )
    MCAPP_ResetFieldWeakening();
#endif        
                 
    gMCLIB_SVPWM.period = MCPWM_PrimaryPeriodGet();
    gMCLIB_SVPWM.neutralPWM = (uint32_t)(0.5f * gMCLIB_SVPWM.period );
}


/*******************************************************************************
 End of File
*/
