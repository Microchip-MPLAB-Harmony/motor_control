/*******************************************************************************
 Motor Control Coordination Functions 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_function_coordinator.c

  Summary:
    Motor Control coordination functions.

  Description:
    This file implements functions for motor control coordination.
 
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
#include "mc_function_coordinator.h"


/*******************************************************************************
 * Constants 
 *******************************************************************************/
#define INTERRUPT_COUNTS_IN_1MS        ( uint32_t )( 0.001f * CURRENT_CONTROL_FREQUENCY + 0.5f )
#define INTERRUPT_COUNTS_IN_10MS      ( uint32_t )( 0.010f * CURRENT_CONTROL_FREQUENCY + 0.5f )
#define INTERRUPT_COUNTS_IN_100MS    ( uint32_t )( 0.100f * CURRENT_CONTROL_FREQUENCY + 0.5f )
#define INTERRUPT_COUNTS_IN_1000MS  ( uint32_t )( 1.000f * CURRENT_CONTROL_FREQUENCY + 0.5f )

/*******************************************************************************
 Private data-types 
 *******************************************************************************/

   
/*******************************************************************************
 Private variables 
 *******************************************************************************/
void (*InterruptTasks[2])(void)  = { 
    mcFco_1stCycleInterruptTasksRun, 
    mcFco_2ndCycleInterruptTasksRun,
};

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


/*******************************************************************************
Interface Variables
*******************************************************************************/

/*******************************************************************************
Private Functions
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


/*! \brief ADC ISR for sensor hardware calibration
 * 
 * Details.
 * ADC Finish ISR
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */   
void mcFcoI_MotorControlHardwareInit( void )
{
    if( 1u == mcCurI_CurrentOffsetCalibDone_gdu8 )
    {
        mcHalI_AdcCallBackRegister((ADC_CALLBACK) mcFcoI_InterruptTasksRun, (uintptr_t)NULL);
    }
    else
    {
        /* Get phase a current from ADC port*/
        mcHalI_PhaseACurrentGet();
        
        /* Get phase b current from ADC port */
        mcHalI_PhaseBCurrentGet();
        
        mcCurI_CurrentSensorOffsetCalculate( 0u );
    }
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
     /* Configure ADC Finish ISR */
    mcHalI_AdcCallBackRegister((ADC_CALLBACK) mcFcoI_MotorControlHardwareInit, (uintptr_t)NULL);
     
    /* Configure fault ISR */
    mcHalI_PwmCallBackRegister ((TCC_CALLBACK) mcErr_ErrorReaction,(uintptr_t)NULL);
     
    /* Enable ADC */     
    mcHalI_ADCEnable();
            
    mcHalI_AdcInterruptClear();
    mcHalI_AdcInterruptDisable();
    
    /* Initialize Current Measurement*/
    mcCurI_CurrentCalculationInit(&mcCurI_ConfigurationParameters_gds);
    
    /* Initialize Motor control */
    mcMocI_MotorControlInit();
     
    /* Initialize voltage calculation module */
    mcVolI_VoltageCalculationInit( &mcVolI_ConfigurationParameters_gds );
    
    mcHalI_AdcInterruptEnable();
    mcHalI_AdcInterruptClear();
    
    /* Start PWM */
    mcHalI_PwmTimerStart();
      
    /* Power Factor Correction Initialize */
    
}

/*! \brief ADC Finish ISR
 * 
 * Details.
 * ADC Finish ISR
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */   
void mcFcoI_InterruptTasksRun( void )
{   
    /* Interrupt index */
    static uint8_t index = 0u;
    index =  index & (uint8_t)0x1;
   
    
    /* Clear all interrupt flags */
    mcHalI_AdcInterruptClear();

    /* Call corresponding interrupt tasks */
    (void)InterruptTasks[index]();
            
    /* Update X2C Scope */
    X2CScope_Update();
    
    /* Synchronize ISR with the thread tasks  */
    mcFco_InterruptAndThreadSync();

    /* Update ISR index */ 
    index++;
}


/*! \brief First Cycle interrupt task run 
 * 
 * Details.
 * First Cycle interrupt task run 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFco_1stCycleInterruptTasksRun( void )
{
     /* Get phase a current from ADC port*/
     mcHalI_PhaseACurrentGet();
     
     /* Get phase b current from ADC port */
     mcHalI_PhaseBCurrentGet();
     
     /* Current calculation */		
     mcCurI_CurrentCalculationRun(0u);
     
     /* Motor control tasks */
     mcMocI_MotorControlTasksRun( );

     /* Set the ADC channel for DC bus voltage  */
     mcHalI_DcLinkVoltageChannelSet();

     /* Set the ADC channel for potentiometer  */
     mcHalI_PotentiometerChannelSet();
}


/*! \brief Second Cycle interrupt task run 
 * 
 * Details.
 * Second Cycle interrupt task run 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFco_2ndCycleInterruptTasksRun( void )
{
    /* Get  DC link voltage from ADC port */
    mcHalI_DcLinkVoltageGet();
    
    /* Get potentiometer from ADC port */
    mcHalI_PotentiometerInputGet();
    
    /* DC bus voltage measurement */
    mcVolI_VoltageCalculationRun( 0u );
    
    /* Set ADC Channel for Phase A current */
    mcHalI_PhaseACurrentChannelSet();

    /* Set ADC Channel for Phase B current */
     mcHalI_PhaseBCurrentChannelSet();
        
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
        mcMocI_MotorControlCommandGet();
        
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
