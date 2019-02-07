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
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "X2CScope.h"
#include "mc_app.h"
#include "X2CScopeCommunication.h"



#ifndef CTRL_PWM_1_1
static uint8_t  adc_interrupt_counter = 0U;
#endif
uint16_t adc_result_data[2];
uint8_t start_toggle = 0;
uint16_t adc_dc_bus_voltage;
uint16_t pot_input;
uint8_t  direction = 0x0U;
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
    X2CScope_Init();
    TCC0_PWMStart();
     

    while ( true )
    {
        
        
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        X2CScope_Communicate();
        if(0U == syn10ms())
        {
          
            
            button_S2_data.inputVal = BTN_START_STOP_Get();
            buttonRespond(&button_S2_data, &motor_start_stop);

           
            speed_ramp(); 
          
        }

        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

void OC_FAULT_ISR(uintptr_t context)
{
    motor_stop();
    motor_stop_source = OC_FAULT_STOP;
    start_toggle=0;
    LED1_OC_FAULT_Set();
    while(1);
    
}

void ADC_CALIB_ISR (uintptr_t context)
{
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
    start_toggle = !start_toggle; // Calling this function starts/stops motor

}

void motor_direction_toggle(void) // Calling this function toggles direction of the motor (only if motor is stationary).
{
    if(!start_toggle)
    {
        direction = !direction; 
        LED2_DIRECTION_Toggle(); 
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

