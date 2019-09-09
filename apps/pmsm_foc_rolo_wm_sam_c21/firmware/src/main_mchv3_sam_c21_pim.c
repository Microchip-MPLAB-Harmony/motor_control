/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "userparams.h"
#include "mc_app.h"
#include "X2CScope.h"
#include "X2CScopeCommunication.h"
#include <sys/attribs.h>

uint16_t adc_result1;   
uint16_t adc_result2;
#ifndef CTRL_PWM_1_1
static uint8_t  adc_interrupt_counter = 0U;
#endif
uint16_t adc_result_data[2];
uint8_t start_toggle = 0;
uint8_t windmilling_start = 0;
uint16_t adc_dc_bus_voltage;
uint16_t pot_input;
uint16_t set_speed = 0;
uint8_t  direction = 0;
uint8_t direction_change_flag = 0;
uint8_t phaseindex[3] = {0,1,2};
extern uint16_t windmilling_count;
extern uint16_t braking_count;
extern uint32_t state_count;
extern uint16_t state_windmilling;
extern uint16_t state_decide;
extern uint16_t state_brake; 
extern uint16_t state_stopped;
extern uint16_t state_start;
extern uint16_t state_align;
extern uint16_t state_closingloop;
extern uint16_t state_closingloopwindmilling;
extern uint16_t state_closedloop;
extern uint32_t trigger;
extern int16_t elespeed;
extern uint16_t flx_arg;
extern uint16_t flx_arg_mem;
extern uint16_t bemf_arg;
extern uint16_t bemf_arg_mem;
extern uint16_t angle_rollover_count;
button_response_t button_S2_data;
button_response_t button_S3_data;

uint16_t calibration_sample_count = 0x0000U;
uint16_t adc_0_offset = 0;
uint16_t adc_1_offset = 0;

uint32_t adc_0_sum = 0;
uint32_t adc_1_sum = 0;

button_response_t button_S2_data;
button_response_t button_S3_data;
void ADC_ISR(uintptr_t context);
void ADC_CALIB_ISR (uintptr_t context);
void OC_FAULT_ISR(uintptr_t context);
void motor_start_stop(void);
void motor_direction_toggle(void);
void buttonRespond(button_response_t * buttonResData, void (* buttonJob)(void));

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{

/* Initialize all modules */
    SYS_Initialize ( NULL );
    motor_stop();
    ADC0_CallbackRegister((ADC_CALLBACK) ADC_CALIB_ISR, (uintptr_t)NULL);
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_2, (EIC_CALLBACK) OC_FAULT_ISR,(uintptr_t)NULL);
    motorcontrol_vars_init();
    ADC0_Enable();
    state_run = 0;
    X2CScope_Init();
    TCC0_PWMStart();

    while ( true )
    {
        
        
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        X2CScope_Communicate();
        if(0U == syn10ms())
        {
            /* This if loop ensures that when the motor direction is changed, 
             * the PWM is disabled for 10mS before re-starting the windmilling 
             * state to avoid current spike*/
            if(direction_change_flag == 1) 
            {
                motor_start();
                direction_change_flag = 0;
            }
            speed_ramp(); 
       
            button_S2_data.inputVal = BTN_START_STOP_Get();
            buttonRespond(&button_S2_data, &motor_start_stop);
           
     
        }

        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}
void OC_FAULT_ISR(uintptr_t context)
{
    motor_stop();
    start_toggle=0;
    LED1_OC_FAULT_Set();
    while(1);
    
}
/* This ISR calibrates zero crossing point for Phase U and Phase V currents*/
void ADC_CALIB_ISR (uintptr_t context)
{
    
    X2CScope_Update();
    calibration_sample_count++;
    if(calibration_sample_count <= 4096)
    {
        adc_0_sum += ADC0_ConversionResultGet();    
        adc_1_sum += ADC1_ConversionResultGet();
    }
    else
    {
        adc_0_offset = adc_0_sum>>12;
        adc_1_offset = adc_1_sum>>12;
        ADC0_Disable();
        ADC0_CallbackRegister((ADC_CALLBACK) ADC_ISR, (uintptr_t)NULL);
        ADC0_Enable();

    }
    
    ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;
    
    
}

#ifdef CTRL_PWM_1_1
void ADC_ISR(uintptr_t context)
{

        adc_result_data[0] = ADC0_ConversionResultGet();
        adc_result_data[1] = ADC1_ConversionResultGet();
        X2CScope_Update();
  
    /* Clear all interrupt flags */
       ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;

       ADC0_REGS->ADC_INTENCLR = ADC_INTFLAG_RESRDY_Msk;// Disable ADC interrupt
	
    	/* select the next channel */
		/* select the next ADC channel for conversion */
        ADC0_ChannelSelect(ADC_POSINPUT_AIN9,ADC_NEGINPUT_GND); // DC Bus Voltage to ADC0
        ADC1_ChannelSelect(ADC_POSINPUT_AIN0,ADC_NEGINPUT_GND); // Potentiometer to ADC1
		
        ADC0_REGS->ADC_SWTRIG |= ADC_SWTRIG_START_Msk; 
        
        current_measurement_management();
        
        /* store the first ADC result value */
	    cur_mea[0] = ((int16_t)adc_result_data[0] - (int16_t)adc_0_offset);               
							
         /* store the first ADC result value */
        cur_mea[1] =  ((int16_t)adc_result_data[1] - (int16_t)adc_1_offset);   
		 
		/* motor control */
		motorcontrol();
		 
		while(ADC0_REGS->ADC_INTFLAG != ADC_INTFLAG_RESRDY_Msk);
                       
        /* Read the ADC result value */
        adc_dc_bus_voltage =  ADC0_ConversionResultGet();
		pot_input = ADC1_ConversionResultGet();
  
        /* select the next ADC channel for conversion */
        ADC0_ChannelSelect(ADC_POSINPUT_AIN2,ADC_NEGINPUT_GND); // Phase U to ADC0
        ADC1_ChannelSelect(ADC_POSINPUT_AIN5,ADC_NEGINPUT_GND); // Phase V to ADC1
        ADC0_REGS->ADC_INTENSET = ADC_INTFLAG_RESRDY_Msk;// Enable ADC interrupt
        /* Clear all interrupt flags */
        ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;	
    return;
}
#else
void ADC_ISR(uintptr_t context)
{
    adc_result_data[0] = ADC0_ConversionResultGet();
    adc_result_data[1] = ADC1_ConversionResultGet();
    X2CScope_Update();
  
 /* Clear all interrupt flags */
    ADC0_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;
	if (0U == adc_interrupt_counter)
	{
    	
		current_measurement_management();
		 
		/* store the first ADC result value */
	     cur_mea[0] = ((int16_t)adc_result_data[0] - (int16_t)adc_0_offset);               
							
         /* store the first ADC result value */
         cur_mea[1] =  ((int16_t)adc_result_data[1] - (int16_t)adc_1_offset); 
         
         /* motor control */
		motorcontrol();
          adc_interrupt_counter = 1;
	      /* select the next channel */
		/* select the next ADC channel for conversion */
        ADC0_ChannelSelect(ADC_POSINPUT_AIN9,ADC_NEGINPUT_GND); // DC Bus Voltage to ADC0
        ADC1_ChannelSelect(ADC_POSINPUT_AIN0,ADC_NEGINPUT_GND); // Potentiometer to ADC1
	}
	else if (1U == adc_interrupt_counter)
	{
                      
         adc_interrupt_counter = 0;	    
         
         /* Read the ADC result value */
          adc_dc_bus_voltage =  adc_result_data[0];
		  pot_input = adc_result_data[1];
  
          /* select the next ADC channel for conversion */
          ADC0_ChannelSelect(ADC_POSINPUT_AIN2,ADC_NEGINPUT_GND); // Phase U to ADC0
          ADC1_ChannelSelect(ADC_POSINPUT_AIN5,ADC_NEGINPUT_GND); // Phase V to ADC1

	}
	else
	{
		
      

	}
    return;
}

#endif

void motor_start_stop(void)
{

     start_toggle =!start_toggle;
     
     if(!start_toggle)
     {
        motor_stop();
        windmilling_start = 0;
        windmilling_count = 0;
        state_count = 1;
        braking_count = 0;
        state_windmilling = 0;
        state_decide = 0;
        state_brake = 0;
        state_stopped = 0;
        state_align = 0;
        state_start = 0;
        state_closingloop = 0;
        state_closingloopwindmilling = 0;
        state_closedloop = 0;
        angle_rollover_count = 0;
#ifdef WINDMILLING_ENABLE
        motor_status = WINDMILLING;
#else
        motor_status = STOPPED;
#endif 
        elespeed = 0;
        flx_arg = 0;
        bemf_arg = 0;
        flx_arg_mem = 0;
        bemf_arg_mem = 0;

        if(direction ==0)
        {
            spe_ref_sgn = 1;
        }
        else
        {
            spe_ref_sgn = -1;
        }
     }
}

void motor_direction_toggle(void)
{
    motor_stop(); 
    direction = !direction; // toggle direction 
     LED2_DIRECTION_Set(); 
    windmilling_start = 0;
    windmilling_count = 0;
    state_count = 1;
    braking_count = 0;
    state_windmilling = 0;
    state_decide = 0;
    state_brake = 0;
    state_stopped = 0;
    state_align = 0;
    state_start = 0;
    state_closingloop = 0;
    state_closingloopwindmilling = 0;
    state_closedloop = 0;
    angle_rollover_count = 0;
#ifdef WINDMILLING_ENABLE
    motor_status = WINDMILLING;
#else
    motor_status = STOPPED;
#endif 
    direction_change_flag = 1;
    trigger = 0;
    if(direction == 0)
    {
        spe_ref_sgn = 1;
    }
    else
    {
        spe_ref_sgn = -1;
    }
    
}

void buttonRespond(button_response_t * buttonResData, void (* buttonJob)(void))
{
    switch(buttonResData->state){
        case 0u:  /* Detect if button is pressed. */
            if(buttonResData->inputVal == 0u){
                buttonJob();
                buttonResData->cnt = 0u;
                buttonResData->state = 1u;
            }
            break;
        case 1u:  /* Stay idle for 500ms, and then return to detect. */
            buttonResData->cnt++;
            if(buttonResData->cnt >= RL_500MS_10MS){
                buttonResData->cnt = 0u;
                buttonResData->state = 0u;
            }
            break;
        default:
            break;
    }
}
/*******************************************************************************
 End of File
*/

