/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_infrastructure.c

  Summary:
    This file contains functions to functions to initialize the motor control
    peripherals.

  Description:
    This file contains functions to functions to initialize the motor control
    peripherals.

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
#if  ( defined ( USE_FILE_INLINING )  && defined  (  MCAPP_C  ) )  ||   ( !defined ( USE_FILE_INLINING )  )
#ifndef MCINF_C
#define MCINF_C
#include "mc_rotorPosition.h"
#include "mc_infrastructure.h"
#include "mc_currMeasurement.h"
#include "mc_voltageMeasurement.h"
#include "mc_speed.h"
#include "mc_pwm.h"
#include "mc_lib.h"
#include "mc_picontrol.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Motor phase current offset calibration limits. */

/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

extern void MCERR_FaultControlISR(uint32_t status, uintptr_t context);
static void MCINF_ButtonPolling( void );
void MCINF_SpeedLoopTasks( void );
void MCINF_CurrentLoopTasks( uint32_t status, uintptr_t context );



/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
          
tMCINF_PARAM_S gMCINF_Parameters = {
                                        SPEED_LOOP_PWM_COUNT,
                                        POSITION_LOOP_PWM_COUNT
                                   };

tMCINF_STATE_S gMCINF_StateSignals = { LOOP_INACTIVE, LOOP_INACTIVE };


/******************************************************************************/
/* Function name: MCINF_InitiaizeInfrastructure                               */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialize  infrastructure                                    */
/******************************************************************************/
void MCINF_InitiaizeInfrastructure( void )
{
    /* Initialize  infrastructure state variables */
    gMCINF_StateSignals.PositionLoopActive = LOOP_INACTIVE;
    gMCINF_StateSignals.SpeedLoopActive = LOOP_INACTIVE;      
         
    /* Initialize infrastructure parameters */     
    gMCINF_Parameters.PositionLoopCount = POSITION_LOOP_PWM_COUNT;
    gMCINF_Parameters.SpeedLoopCount = SPEED_LOOP_PWM_COUNT;
}



/*******************************************************************************/
/* Function name: MCINF_LoopSynchronization                                    */
/* Function parameters: None                                                   */
/* Function return: Bool( True - executes slow control loop )                  */
/* Description: To be used in a state machine to decide whether                */
/* to execute slow control loop                                                */
/*******************************************************************************/
__STATIC_INLINE void  MCINF_LoopSynchronization(void)
{
	static uint32_t speedLoopCounter = 0U;
    static uint32_t positionLoopCounter = 0U;
    speedLoopCounter++;
    positionLoopCounter++;
	if( gMCINF_Parameters.SpeedLoopCount <= speedLoopCounter)
	{
	    speedLoopCounter = 0;
	    gMCINF_StateSignals.SpeedLoopActive = LOOP_ACTIVE;
	}
         
    if( gMCINF_Parameters.PositionLoopCount <= positionLoopCounter )
    {
        positionLoopCounter = 0;
        gMCINF_StateSignals.PositionLoopActive = LOOP_ACTIVE;
    }
}
/******************************************************************************/
/* Function name: MCINF_InitializeControl                                     */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* initializes parameters and state variables for motor  control function     */
/******************************************************************************/
void MCINF_InitializeControl( void )
{
    gCtrlParam.rotationSign = 1U;

    /* Disable PWM output */
    MCPWM_Stop();

    /* Disable interrupt, and clear pending interrupts */
    EVIC_SourceDisable( INTERRUPT_SOURCE);
    EVIC_SourceStatusClear( INTERRUPT_SOURCE);

    /* Current sense amplifiers offset calculation */
    if(gMCCUR_OutputSignals.calibDone == 0U)
    {
        MCCUR_OffsetCalibration();
    }
    else
    {
        asm("NOP");
    }

    /* Initialize speed command function */
    MCSPE_InitializeSpeedControl();
    
    /* Initialize current measurement module */
    MCCUR_InitializeCurrentMeasurement();   
    
    /* Motor Controller parameter initialization */
    MCAPP_InitializeMotorControl();

    /* Rotor position algorithm state initialization */
    MCRPOS_InitializeRotorPositionSensing();
         
    /* Start ADC Interrupt for current control */
    MCINF_StartAdcInterrupt();
}   

void MCINF_StartAdcInterrupt( void )
{
    /* ADC end of conversion interrupt generation for FOC control */
	EVIC_SourceDisable(INTERRUPT_SOURCE);
	EVIC_SourceStatusClear(INTERRUPT_SOURCE);
 
    /* Enable ADC interrupt for field oriented control */
    ADCHS_CallbackRegister( PHASE_CURRENT_U, MCINF_CurrentLoopTasks, (uintptr_t)NULL );
	EVIC_SourceEnable(INTERRUPT_SOURCE);

    /* Enable interrupt for fault detection */
    MCPWM_CallbackRegister(MCPWM_CH_1, MCERR_FaultControlISR, (uintptr_t)NULL);
    EVIC_SourceEnable(INT_SOURCE_PWM1);
         
    /* Enables PWM channels. */
    MCPWM_Start();
         
    /* Disable PWM output when the interface is available */
    IOCON1bits.PENL = 0;    IOCON1bits.PENH = 0;
    IOCON2bits.PENL = 0;    IOCON2bits.PENH = 0;
    IOCON3bits.PENL = 0;    IOCON3bits.PENH = 0;
}


/******************************************************************************/
/* Function name: MCINF_Tasks                                                 */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Motor start stop and direction switch polling                 */
/******************************************************************************/
void MCINF_Tasks()
{
    /* Position Loop control tasks */
    
    /* Speed Loop Control tasks  */
    MCINF_SpeedLoopTasks();
    
    /* Current control Loop Tasks */

 }

 
/******************************************************************************/
/* Function name: MCINF_CurrentLoopTasks                                      */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:Current loop tasks                                             */
/******************************************************************************/
void MCINF_CurrentLoopTasks( uint32_t status, uintptr_t context )
{       
    /* Current Measurement */
    MCCUR_CurrentMeasurement( );

    /* Voltage measurement */
    MCVOL_VoltageMeasurement( );
         
    /* Rotor position estimation */
    MCRPOS_PositionMeasurement( );

    /* Motor control */
    MCAPP_MotorControl( );
    
     /* sync count for slow control loop execution */
    MCINF_LoopSynchronization();

}

/******************************************************************************/
/* Function name: MCAPP_SpeedLoopTasks                                        */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Motor start stop and direction switch polling                 */
/******************************************************************************/
void MCINF_SpeedLoopTasks()
{       
    if( LOOP_ACTIVE == MCINF_IsSpeedLoopActive())
    {
        /* Motor start stop task */
        MCINF_ButtonPolling();

        /* Reference speed calculation */
        MCSPE_SpeedCommand();

        /* Reset Speed Loop counter */
        gMCINF_StateSignals.SpeedLoopActive = LOOP_INACTIVE;
    }
 }


/******************************************************************************/
/* Function name: MCINF_IsSpeedLoopActive                                     */
/* Function parameters: None                                                  */
/* Function return: tMCINF_LOOP_STATE_E                                       */
/* Description: To be used in a state machine to decide whether               */
/* to execute slow control loop                                               */
/******************************************************************************/
tMCINF_LOOP_STATE_E  MCINF_IsSpeedLoopActive(void)
{
	  return gMCINF_StateSignals.SpeedLoopActive;
}

/*****************************************************************************/
/* Function name: MCAPP_SpeedLoopTasks                                       */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Motor start stop and direction switch polling                */
/*****************************************************************************/
void MCINF_PositionLoopTasks()
{       
    if( LOOP_ACTIVE == MCINF_IsPositionLoopActive())
    {
        /* Performs tasks for position loop  */
           
        /* Reset Speed Loop counter */
        gMCINF_StateSignals.PositionLoopActive = LOOP_INACTIVE;
                  
    }
 }


/*******************************************************************************/
/* Function name: MCINF_IsPositionLoopActive                                   */
/* Function parameters: None                                                   */
/* Function return: tMCINF_LOOP_STATE_E                                        */
/* Description: To be used in a state machine to decide whether                */
/* to execute slow control loop                                                */
/*******************************************************************************/
tMCINF_LOOP_STATE_E  MCINF_IsPositionLoopActive(void)
{
	return gMCINF_StateSignals.PositionLoopActive;
}

/*******************************************************************************/
/* Function name: MCINF_ButtonPolling                                          */
/* Function parameters: None                                                   */
/* Function return: None                                                       */
/* Description: Button Polling                                                 */
/*******************************************************************************/
void MCINF_ButtonPolling()
{
    /* Check whether S2 push button is pressed */
    if( MCAPP_IDLE == gCtrlParam.s_ControlStatus_e )
    {
        MCLIB_ButtonResponse((tMCLIB_SWITCH_STATE_E)(!START_STOP_BUTTON_Get()), &MCINF_MotorStart);
        
      #ifndef MCHV3
        MCLIB_ButtonResponse((tMCLIB_SWITCH_STATE_E)(!DIRECTION_TOGGLE_BUTTON_Get()), &MCINF_DirectionToggle);
      #endif

    }
    else 
    {
        MCLIB_ButtonResponse((tMCLIB_SWITCH_STATE_E)(!START_STOP_BUTTON_Get()), &MCINF_MotorStop);
    }
 }


/*****************************************************************************/
/* Function name: MotorStart                                                 */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description: Enables fast control loop and starts the PWMs.               */
/*****************************************************************************/
extern tMCRPOS_ROTOR_ALIGN_STATE_S       gMCRPOS_RotorAlignState;
void MCINF_MotorStart(void)
{
    /* Change motor status to RUNNING */
        
    /* Reset PI Controller integrator values */
    MCCON_ResetPIParameters();
         
    MCRPOS_ResetPositionSensing();
         
    gMCRPOS_RotorAlignState.rotorAlignState = FORCE_ALIGN;
               
    /* Switch the motor control state to MCAPP_FIELD_ALIGNMENT */
    gCtrlParam.s_ControlStatus_e = MCAPP_FIELD_ALIGNMENT;
         
    /* Enable / Re-enable PWM output */
    MCPWM_PWMDutyUpdate(gMCLIB_SVPWM.neutralPWM, gMCLIB_SVPWM.neutralPWM, gMCLIB_SVPWM.neutralPWM );
    IOCON1bits.PENL = 1; IOCON1bits.PENH = 1; 
    IOCON2bits.PENL = 1; IOCON2bits.PENH = 1; 
    IOCON3bits.PENL = 1; IOCON3bits.PENH = 1; 
       
}

/******************************************************************************/
/* Function name: MotorStop                                                   */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Stops PWM and disables fast control loop.                     */
/******************************************************************************/
void MCINF_MotorStop(void)
{      
    /* Disable PWM output when the interface is available */
    IOCON1bits.PENL = 0;    IOCON1bits.PENH = 0;
    IOCON2bits.PENL = 0;    IOCON2bits.PENH = 0;
    IOCON3bits.PENL = 0;    IOCON3bits.PENH = 0;
         
    /* Switch the motor control state to MCAPP_FIELD_ALIGNMENT */
    gCtrlParam.s_ControlStatus_e = MCAPP_IDLE;
       
    /* Reset global variables for next run */
    MCSPE_ResetSpeedControl();

    /* Motor Controller parameter initialization */
    MCAPP_ResetMotorControl();
}


#ifndef MCHV3
/******************************************************************************/
/* Function name: MCAPP_DirectionToggle                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Updates global variable for motor direction change            */
/******************************************************************************/
void MCINF_DirectionToggle(void)
{
    /* Change rotation sign */
    gCtrlParam.rotationSign = -gCtrlParam.rotationSign;
    
    /* Toggle direction indicator LED */
    DIRECTION_INDICATOR_Toggle();
    
}
#endif

/******************************************************************************/
/* Function name: MCINF_ResetInfrastructure                                   */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Reset infrastructure                                          */
/******************************************************************************/
void MCINF_ResetInfrastructure( void )
{
    /* Reset infrastructure state variables */
    gMCINF_StateSignals.PositionLoopActive = LOOP_INACTIVE;
    gMCINF_StateSignals.SpeedLoopActive = LOOP_INACTIVE;      
}

#endif
#endif
