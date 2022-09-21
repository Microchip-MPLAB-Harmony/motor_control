/*******************************************************************************
 Function Coordinator

  Company:
    Microchip Technology Inc.

  File Name:
    mc_function_coordinator.c

  Summary:
  Function coordination functions 

  Description:
  Function coordination functions 
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
#include <stdint.h>
#include "mc_function_coordinator.h"

/*******************************************************************************
 * Constants 
 *******************************************************************************/
#define INTERRUPT_COUNTS_IN_1MS        ( uint32_t )( 0.001f * PWM_FREQUENCY + 0.5f )
#define INTERRUPT_COUNTS_IN_10MS      ( uint32_t )( 0.010f * PWM_FREQUENCY + 0.5f )
#define INTERRUPT_COUNTS_IN_100MS    ( uint32_t )( 0.100f * PWM_FREQUENCY + 0.5f )
#define INTERRUPT_COUNTS_IN_1000MS  ( uint32_t )( 1.000f * PWM_FREQUENCY + 0.5f )

/*******************************************************************************
 Private data-types 
 *******************************************************************************/

   
/*******************************************************************************
 Private variables 
 *******************************************************************************/

static uint32_t mcFco_1msInterruptSyncPulseCounter_mdu32 = 0u;
static uint32_t mcFco_10msInterruptSyncPulseCounter_mdu32 = 0u;
static uint32_t mcFco_100msInterruptSyncPulseCounter_mdu32 = 0u;
static uint32_t mcFco_1000msInterruptSyncPulseCounter_mdu32 = 0u;

static uint8_t mcFco_1msInterruptSyncPulse_mdu8 = 0u;
static uint8_t mcFco_10msInterruptSyncPulse_mdu8 = 0u;
static uint8_t mcFco_100msInterruptSyncPulse_mdu8 = 0u;
static uint8_t mcFco_1000msInterruptSyncPulse_mdu8 = 0u;


/*******************************************************************************
 Interface variables 
 *******************************************************************************/

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

/*! \brief 
 * 
 * Details.
 * 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcFco_InterruptAndThreadSync( void )
{
    /* 1 ms thread task synchronization */    
    if(  INTERRUPT_COUNTS_IN_1MS <=  mcFco_1msInterruptSyncPulseCounter_mdu32 )
    {
        mcFco_1msInterruptSyncPulseCounter_mdu32 = 0u;
        if( 0u == mcFco_1msInterruptSyncPulse_mdu8 )
        {
            mcFco_1msInterruptSyncPulse_mdu8 = 1u;
        }
        else
        {
            /* Last 1ms task has not been executed properly */
        }
    }
    else
    {
        mcFco_1msInterruptSyncPulseCounter_mdu32++;
    }
    
     /* 10 ms thread task synchronization */    
    if(  INTERRUPT_COUNTS_IN_10MS <=  mcFco_10msInterruptSyncPulseCounter_mdu32 )
    {
        mcFco_10msInterruptSyncPulseCounter_mdu32 = 0u;
        if( 0u == mcFco_10msInterruptSyncPulse_mdu8 )
        {
            mcFco_10msInterruptSyncPulse_mdu8 = 1u;
        }
        else
        {
            /* Last 10ms task has not been executed properly */
        }
    }
    else
    {
        mcFco_10msInterruptSyncPulseCounter_mdu32++;
    }
    
    /* 100 ms thread task synchronization */    
    if(  INTERRUPT_COUNTS_IN_100MS <=  mcFco_100msInterruptSyncPulseCounter_mdu32 )
    {
        mcFco_100msInterruptSyncPulseCounter_mdu32 = 0u;
        if( 0u == mcFco_100msInterruptSyncPulse_mdu8 )
        {
            mcFco_100msInterruptSyncPulse_mdu8 = 1u;
        }
        else
        {
            /* Last 100ms task has not been executed properly */
        }
    }
    else
    {
        mcFco_100msInterruptSyncPulseCounter_mdu32++;
    }
    
    /* 1000 ms thread task synchronization */    
    if(  INTERRUPT_COUNTS_IN_1000MS <=  mcFco_1000msInterruptSyncPulseCounter_mdu32 )
    {
        mcFco_1000msInterruptSyncPulseCounter_mdu32 = 0u;
        if( 0u == mcFco_1000msInterruptSyncPulse_mdu8 )
        {
            mcFco_1000msInterruptSyncPulse_mdu8 = 1u;
        }
        else
        {
            /* Last 10ms task has not been executed properly */
        }
    }
    else
    {
        mcFco_1000msInterruptSyncPulseCounter_mdu32++;
    }
}


 /*! \brief Motor control application calibration
 * 
 * Details.
 *  Motor Control application calibration 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_M1PhaseCurrentSensorCalib( uint32_t status, uintptr_t context )
{
    /* Current sense amplifiers offset calculation */
    if( 0u == mcCurI_CurrentOffsetCalibDone_gau8[0u] )
    {
        mcCurI_CurrentSensorOffsetCalculate( 0u );
    }
    else
    {
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcFcoI_MotorAInterruptTasksRun, (uintptr_t)NULL );
    }
}

/*! \brief Motor control application calibration
 * 
 * Details.
 *  Motor Control application calibration 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFocI_M1ControlHardwareInit( void )
 {
    /* ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptDisable();
    mcHalI_AdcInterruptClear();

    /* Enable ADC interrupt for field oriented control */
    mcHalI_AdcCallBackRegister(  (ADC_CALLBACK)mcFcoI_M1PhaseCurrentSensorCalib, (uintptr_t)NULL );
    mcHalI_AdcInterruptEnable( );
    mcHalI_ADCEnable();
    
    /* Enable interrupt for fault detection */
    mcHalI_PwmCallbackRegister( (TCC_CALLBACK)mcErr_FaultControlISR, (uintptr_t)NULL );
    mcHalI_PwmInterruptEnable( );

    /* Enables PWM channels. */
    mcHalI_PwmTimerStart( );
    
    /* Disable PWM output */
    mcHalI_VoltageSourceInverterPwmDisable();
     
 }


 /*! \brief Motor control application calibration
 * 
 * Details.
 *  Motor Control application calibration 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_M2CurrentSensorCalib( uint32_t status, uintptr_t context )
{
    
}

/*! \brief Motor control application calibration
 * 
 * Details.
 *  Motor Control application calibration 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFocI_M2ControlHardwareInit( void )
 {
   
 }


/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
/*! \brief Application initialization 
 * 
 * Details.
 * Application initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_ApplicationInit( void )
{     
    /* Motor Controller parameter initialization */
    mcMocI_M1ControlApplicationInit(  );
    
    /* Allocate and initialize hardware resources for motor A control  */
    mcFocI_M1ControlHardwareInit( ); 
}

/*! \brief Interrupt tasks execution 
 * 
 * Details.
 *  Interrupt tasks execution 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_MotorAInterruptTasksRun( uint32_t status, uintptr_t context )
{
    /* Read phase currents ( Group 01 )*/
    mcHalI_Group01SignalRead( 0u );
    
    /* Re-assign ADC channels and perform trigger  */
    mcHalI_Group02SignalSoftwareTrigger( 0u );
	
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
    /* Rotor position estimation */
    mcRpoI_RotorPositionCalculationRun( 0u );   	
</#if>
    
    /* Voltage measurement */
    mcVolI_VoltageCalculationRun( 0u );
    
    /* Motor A Control tasks  */
    mcMocI_M1ControlTasksRun(  );
        
    /* Synchronize ISR with the thread tasks  */
    mcFco_InterruptAndThreadSync();
    
      /* Read voltage and potentiometer signal ( Group 02 ) */
    mcHalI_Group02SignalRead( 0u );
    
    /* Re-assign and enable hardware trigger for Group 01 signal */
    mcHalI_Group01SignalHardwareTrigger( 0u );
          
    /* Update X2C Scope */
    X2CScope_Update();
}


/*! \brief Interrupt tasks execution 
 * 
 * Details.
 *  Interrupt tasks execution 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_MotorBInterruptTasksRun( uint32_t status, uintptr_t context )
{
    mcMocI_M1ControlTasksRun(  );
        
}


/*! \brief Motor control thread tasks  
 * 
 * Details.
 * Motor control thread tasks
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_ThreadTasksRun( void )
{
    
    /* Run 1 ms thread tasks */
     mcFcoI_1msThreadTasksRun();
     
     /* Run 10 ms thread tasks */
     mcFcoI_10msThreadTasksRun();
     
     /* Run 100 ms thread tasks */
     mcFcoI_100msThreadTasksRun();
     
     /* Run 1000 ms thread tasks */
     mcFcoI_1000msThreadTasksRun();
}


/*! \brief 1 ms thread tasks 
 * 
 * Details.
 * 1 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_1msThreadTasksRun( void )
{
    if( 1u == mcFco_1msInterruptSyncPulse_mdu8 )
    {
        /* Run 1ms task */
        mcFcoI_ButtonPolling();
        
        /* Clear 1 ms task flag */
        mcFco_1msInterruptSyncPulse_mdu8 = 0u;
    }
}


/*! \brief 10 ms thread tasks 
 * 
 * Details.
 * 10 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_10msThreadTasksRun( void )
{
    if( 1u == mcFco_10msInterruptSyncPulse_mdu8 )
    {
        /* Run 10ms task */
        mcFcoI_ButtonPolling();
        
        /* Clear 10 ms task flag */
        mcFco_10msInterruptSyncPulse_mdu8 = 0u;
    }
}


/*! \brief 100 ms thread tasks 
 * 
 * Details.
 * 100 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_100msThreadTasksRun( void )
{
    if( 100u == mcFco_100msInterruptSyncPulse_mdu8 )
    {
        /* Run 100 ms task */
        
        /* Clear 100 ms task flag */
        mcFco_100msInterruptSyncPulse_mdu8 = 0u;
    }
    
}


/*! \brief 1000 ms thread tasks 
 * 
 * Details.
 * 1000 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_1000msThreadTasksRun( void )
{
    if( 1u == mcFco_1000msInterruptSyncPulse_mdu8 )
    {
        /* Run 1000ms task */
             
        /* Clear 1000 ms task flag */
        mcFco_1000msInterruptSyncPulse_mdu8 = 0u;
    }
    
}



/*! \brief Button polling
 * 
 * Details.
 * Button polling
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcFcoI_ButtonPolling(void)
{
<#function buttonName index>
   <#if 0 == index>
    <#return MCPMSMFOC_BUTTON_0_NAME>
  <#elseif 1 == index>
    <#return MCPMSMFOC_BUTTON_1_NAME>
  <#else>
    <#return "You messed up">
  </#if>

</#function>

<#function buttonFunction index>
   <#if 0 == index>
    <#assign symbol = MCPMSMFOC_BUTTON_0_FUNCTION>
  <#elseif 1 == index>
    <#assign symbol = MCPMSMFOC_BUTTON_1_FUNCTION>
  <#else>
    <#return "Error">
  </#if>

  <#if "Start/Stop" == symbol>
    <#return "PMSM_FOC_MotorStartStop">
  <#elseif "Direction Toggle" == symbol>
    <#return "PMSM_FOC_DirectionToggle">
  <#else>
    <#return "Error">
  </#if>
</#function>
<#if MCPMSMFOC_BUTTONS_AVAILABLE != 0 >
    <#list 0..10 as index>
        mcHal_ButtonResponse((tmcHal_ButtonState_e)(!${buttonName(index)}_Get()), &${buttonFunction(index)});

        <#if index == ( MCPMSMFOC_BUTTONS_AVAILABLE -1 )>
            <#break>
        </#if>
    </#list>
</#if>  
}
