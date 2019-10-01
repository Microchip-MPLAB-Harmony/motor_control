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
#include "X2CScope.h"
#include "X2CScopeCommunication.h"
#include "mc_app.h"
#include "userparams.h"
#include "mc_Lib.h"

button_response_t    button_S2_data;
button_response_t    button_S3_data;


void buttonRespond(button_response_t * buttonResData, void (* buttonJob)(void));
 


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

uint16_t count1;
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    delay_10ms.period = DELAY_10MS_COUNT;
    ADC0_CallbackRegister((ADC_CALLBACK) ADC_CALIB_ISR, (uintptr_t)NULL);
    PWM_Output_Disable();
    TCC0_PWMStart(); 
    ADC0_Enable();
    X2CScope_Init();


    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        X2CScope_Communicate();
        if(delay_10ms.count>delay_10ms.period)
        {

            button_S2_data.inputVal = BTN_START_STOP_Get();
            buttonRespond(&button_S2_data, &mcApp_motorStartToggle);
            button_S3_data.inputVal = BTN_DIR_TGL_Get();
            buttonRespond(&button_S3_data, &mcApp_motorDirectionToggle);
            mcApp_SpeedRamp();
            delay_10ms.count = 0;
            
        }
        else
        {
            
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
            if(buttonResData->cnt >= SW_DEBOUNCE_DLY_500MS){
                buttonResData->cnt = 0u;
                buttonResData->state = 0u;
            }
            break;
        default:
            break;
    }
}

