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


extern motor_state_params_t    Motor_StateParams;

typedef struct
{
    uint32_t inputVal;  /* read value of button input pin */
    uint16_t state;
    uint16_t cnt;
} button_response_t;

button_response_t button_S2_data;
button_response_t button_S3_data;



void buttonStartStopToggle(void);
void buttonDirectionToggle(void);

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
    X2CScope_Init();
    
    LED1_OC_FAULT_Clear();
    
    MCAPP_Start();

    while ( true )
    {
    
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        X2CScope_Communicate();
        
        
        if(1U == Motor_StateParams.var_time_10ms)
        {          
            button_S2_data.inputVal = BTN_START_STOP_Get();
            buttonRespond(&button_S2_data, &buttonStartStopToggle);

            button_S3_data.inputVal = BTN_DIR_TGL_Get();
            buttonRespond(&button_S3_data, &buttonDirectionToggle);                      
           
            Motor_StateParams.var_time_10ms = 0;
        }   
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
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
            if(buttonResData->cnt >= 50){
                buttonResData->cnt = 0u;
                buttonResData->state = 0u;
            }
            break;
        default:
            break;
    }
}


void buttonStartStopToggle(void)
{
    Motor_StateParams.switch_state ^= 1;         
		
	if(1U == Motor_StateParams.switch_state)
	{
		Motor_StateParams.state_run = 1;
		Motor_Start();
	}
	else
	{
		Motor_StateParams.state_run = 0;
		Motor_Stop();
	}	

}


void buttonDirectionToggle(void)
{
    // Direction can be changed only when motor is stopped
    if(!Motor_StateParams.state_run)
    {
        Motor_StateParams.direction ^= 1;
        LED2_DIRECTION_Toggle();        
        
        if(!Motor_StateParams.direction)
        {
            Motor_StateParams.direction_offset = 0;
        }
        else
        {
            Motor_StateParams.direction_offset = 8;
        }
    }   
}


/*******************************************************************************
 End of File
*/

