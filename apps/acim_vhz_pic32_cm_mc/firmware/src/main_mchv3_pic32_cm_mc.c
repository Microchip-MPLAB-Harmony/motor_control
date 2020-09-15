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
#include "mc_app.h"



uint8_t  switch_state = 0;
uint8_t  state_halt; 
uint8_t  direction = 0x0U;
uint16_t set_speed = 0;
uint16_t speed_ref_pot;

void ADC_ISR(uintptr_t context);
void OC_FAULT_ISR(uintptr_t context);
void motor_start_stop(void);


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    ADC1_CallbackRegister((ADC_CALLBACK) ADC_ISR, (uintptr_t)NULL);
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_8, (EIC_CALLBACK) OC_FAULT_ISR,(uintptr_t)NULL);
    EIC_CallbackRegister ((EIC_PIN)EIC_PIN_11, (EIC_CALLBACK) motor_start_stop,(uintptr_t)NULL);
    motorcontrol_vars_init();
    ADC1_Enable();
    X2CScope_Init();
    TCC0_PWMStart(); 
    PWM_Output_Disable();    

    while ( true )
    {
        
        
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        X2CScope_Communicate();
       
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

void OC_FAULT_ISR(uintptr_t context)
{
   
    motor_stop_source = OC_FAULT_STOP;
    state_run=0;
    LED1_OC_FAULT_Set();
    while(1);
    
}


void ADC_ISR(uintptr_t context)
{
   
    /* Read the ADC result value */
 	speed_ref_pot = ADC1_ConversionResultGet();
      
    X2CScope_Update();
  
    /* Clear all interrupt flags */
    ADC1_REGS->ADC_INTFLAG = ADC_INTFLAG_Msk;
       
    /* motor control */
	motorcontrol();     
	
    return;
}

void motor_start_stop(void)
{
    switch_state ^= 1;         // Calling this function starts/stops motor
		
	if(1U == switch_state)
	{
		PWM_Output_Enable();
        state_run = 1;
		state_halt = 0;	
		ref_abs = 0;
		direction = 0;
        speed_ref_filter = speed_ref_pot;
	}
	else
	{
		PWM_Output_Disable();
        state_run = 0;
		ref_abs = 0;
		ext_speed_ref_rpm = 0;
	}	

}

/*******************************************************************************
 End of File
*/

