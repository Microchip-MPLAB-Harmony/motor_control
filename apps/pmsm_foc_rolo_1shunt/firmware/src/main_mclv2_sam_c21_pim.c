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

uint16_t adc_result_data[2];
uint8_t start_toggle = 0;
uint16_t adc_dc_bus_voltage;
uint16_t pot_input;
uint8_t  direction = 0x0U;

uint16_t calibration_sample_count = 0x0000U;
uint8_t  post_calib_state = 0;
uint8_t  pwm_cycle = 0;
uint16_t adc_0_offset = 0;
uint16_t adc_1_offset = 0;
volatile uint8_t  overCurrentFaultActive = 0;
volatile uint32_t overCurrentFaultResetDelayCounter = 0;

uint32_t adc_0_sum = 0;
uint32_t adc_1_sum = 0;
uint16_t mytestvar1 = 0;
uint16_t mytestvar2 = 0;

button_response_t button_S2_data;
button_response_t button_S3_data;
void ADC_ISR(uintptr_t context);
void ADC_CALIB_ISR (uintptr_t context);
void TCC0_PR_ISR (uintptr_t context);
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
    
    ADC1_CallbackRegister((ADC_CALLBACK) ADC_CALIB_ISR, (uintptr_t)NULL);
    
    ADC0_Enable();
    ADC1_Enable();
    
    TCC0_REGS->TCC_WAVE |= 0x0700;
    TCC1_PWM24bitDutySet(TCC1_CHANNEL0,1000);
    TCC1_PWM24bitDutySet(TCC1_CHANNEL1,2000);
    TCC0_PWMCallbackRegister((TCC_CALLBACK) TCC0_PR_ISR,(uintptr_t)NULL);
    
     // TCC0 and TCC1 Event 1 is configured to retrigger on event from TC0 Overflow
    TCC0_REGS->TCC_EVCTRL |= TCC_EVCTRL_TCEI0_Msk | TCC_EVCTRL_EVACT0_START;
    TCC1_REGS->TCC_EVCTRL |= TCC_EVCTRL_TCEI0_Msk | TCC_EVCTRL_EVACT0_START;
   
   
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_2, (EIC_CALLBACK) OC_FAULT_ISR,(uintptr_t)NULL);
    motorcontrol_vars_init();

    TCC0_PWMStart();
    TCC1_PWMStart();
    
    TCC0_REGS->TCC_CTRLBSET = TCC_CTRLBSET_CMD_STOP;
    TCC1_REGS->TCC_CTRLBSET = TCC_CTRLBSET_CMD_STOP;
    
    TCC0_PWM24bitCounterSet(0U);
    TCC1_PWM24bitCounterSet(0U);
    

    X2CScope_Init();
    TC0_TimerStart();                     

    while ( true )
    {
        
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        X2CScope_Communicate();
        if(0U == syn10ms())
        {
            if(overCurrentFaultActive == 0)
            {
                speed_ramp(); 

                button_S2_data.inputVal = BTN_START_STOP_Get();
                buttonRespond(&button_S2_data, &motor_start_stop);
                
                button_S3_data.inputVal = BTN_DIR_TGL_Get();
                buttonRespond(&button_S3_data, &motor_direction_toggle);
               
            }
            else
            {
                overCurrentFaultResetDelayCounter++;
                //Clear the Over Current Flag after a delay defined by OVERCURRENT_RESET_DELAY_SEC
                if(overCurrentFaultResetDelayCounter >= OVERCURRENT_RESET_DELAY_COUNT)
                {
                    overCurrentFaultResetDelayCounter = 0;
                    overCurrentFaultActive = 0;
                    
                }
            }
        }

        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

void OC_FAULT_ISR(uintptr_t context)
{
    
    motor_stop(); // Disable TCC output
    start_toggle=0; // Stop the state machine
    overCurrentFaultActive = 1; // Set overCurrentFault Flag
    
    syn_cnt = SYN_VAL10MS; // Reset the 10mS counter
    TCC0_REGS->TCC_STATUS = TCC_STATUS_FAULT1(1); // Clear Non Recoverable Fault
    LED1_OC_FAULT_Set();
    
}


void TCC0_PR_ISR (uintptr_t context)
{

    TCC0_REGS->TCC_INTFLAG = TCC_INTFLAG_Msk; 
    
    if(post_calib_state)
        
    {    
        pwm_cycle++;
    
        if(pwm_cycle >= 4)
            pwm_cycle = 0;

        if(pwm_cycle == CYCLE_1)
        {
           set_pwm_rising_comparevalue();       
        }
        else if(pwm_cycle == CYCLE_2)
        {
            set_pwm_falling_comparevalue();  
        }
        else if(pwm_cycle == CYCLE_3)
        {
            new_duty_update();
            new_adc_trigger_update();
            set_pwm_rising_comparevalue();
        }
        else if(pwm_cycle == CYCLE_0)
        {
            set_pwm_falling_comparevalue();        
        }          
    }
}


/* This ISR calibrates zero crossing point for Phase U and Phase V currents*/

void ADC_CALIB_ISR (uintptr_t context)
{
    
    calibration_sample_count++;
    if(calibration_sample_count <= 1024)   
    {
        adc_0_sum += ADC0_ConversionResultGet();  
        adc_1_sum += ADC1_ConversionResultGet();
    }
    else
    {
        adc_0_offset = adc_0_sum>>10;  
        adc_0_sum = 0;
        adc_1_offset = adc_1_sum>>10;  
        adc_1_sum = 0;
        calibration_sample_count = 0;
        post_calib_state = 1;

        ADC1_Disable();
        ADC1_CallbackRegister((ADC_CALLBACK) ADC_ISR, (uintptr_t)NULL);
        ADC1_Enable(); 

        TCC0_REGS->TCC_CTRLBSET = TCC_CTRLBSET_CMD_STOP;
        TCC1_REGS->TCC_CTRLBSET = TCC_CTRLBSET_CMD_STOP;
    
        TCC0_PWM24bitCounterSet(0U);
        TCC1_PWM24bitCounterSet(0U);
        
        TC0_TimerStart(); 
        
    }
    
    ADC1_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;      
  
}


void ADC_ISR(uintptr_t context)
{
    adc_result_data[0] = ADC0_ConversionResultGet();
    adc_result_data[1] = ADC1_ConversionResultGet();
    
    // mytestvar1 provides at what pwm_cycle the first ADC interrupt comes after calibration.
    // This info to be used in TCC0_PR_ISR for the correct rise and fall slope compare value and when to get the new dutycycle.
    if(!mytestvar1)
    mytestvar1 = pwm_cycle;        
   
 /* Clear all interrupt flags */
    ADC1_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;
    
    ADC1_REGS->ADC_INTENCLR = ADC_INTFLAG_RESRDY_Msk;// Disable ADC interrupt
	        
       
	    cur_t1 = - ((int16_t)adc_result_data[0] - (int16_t)adc_0_offset);               
							
         // store the first ADC result value 
        cur_t2 =  - ((int16_t)adc_result_data[1] - (int16_t)adc_1_offset); 
         
        current_measurement_management();         
                
    // select the next channel 
	// select the next ADC channel for conversion 
        
        ADC0_ChannelSelect(ADC_POSINPUT_AIN9,ADC_NEGINPUT_GND); // DC Bus Voltage to ADC0
        ADC1_ChannelSelect(ADC_POSINPUT_AIN0,ADC_NEGINPUT_GND); // Potentiometer to ADC1
        
        ADC0_REGS->ADC_SWTRIG |= ADC_SWTRIG_START_Msk; 
        ADC1_REGS->ADC_SWTRIG |= ADC_SWTRIG_START_Msk; 
         
//  motor control 
        
		motorcontrol();
        
        adc_dc_bus_voltage =  ADC0_ConversionResultGet();
		pot_input = ADC1_ConversionResultGet();
        
        ADC0_ChannelSelect(ADC_POSINPUT_AIN8,ADC_NEGINPUT_GND); // Phase U to ADC0
        ADC1_ChannelSelect(ADC_POSINPUT_AIN10,ADC_NEGINPUT_GND); // Phase V to ADC1
        
        X2CScope_Update(); 
        
        if(0U < syn_cnt)
        {
            --syn_cnt;
        }

        
        ADC1_REGS->ADC_INTENSET = ADC_INTFLAG_RESRDY_Msk;        
      
   return;
}


void motor_start_stop(void)
{
    start_toggle = !start_toggle; // Calling this function starts/stops motor
}

void motor_direction_toggle(void)
{
    if(!start_toggle) // Calling this function toggles direction of the motor (only if motor is stationary).
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

