/*******************************************************************************
 Motor Control Application Header File

  File Name:
    mc_app.h

  Summary:
 Motor Control Application Variable and Function declarations.

  Description:
    This file contains the declarations for Motor Control application specific 
 * variables and functions (excluding variables and functions used by Motor Control
 * Library

 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef _MC_APP_H    /* Guard against multiple inclusion */
#define _MC_APP_H
#include "definitions.h"
#include "X2CScope.h"
#include "X2CScopeCommunication.h"
#include "mc_Lib.h"

/* MC Core Variables */

/*MC State Machine States*/

#define ALIGN           0
#define OPENLOOP_FOC    1
#define CLOSEDLOOP_FOC  2

typedef struct {
    uint32_t inputVal; /* read value of button input pin */
    uint16_t state;
    uint32_t cnt;
} button_response_t;

typedef struct {
    uint16_t count;
    uint16_t period;
} delay_gen_t;

typedef struct {
    uint8_t focStateMachine; // FOC State Machine
    uint8_t focStart;
    uint8_t motorStart;
    uint8_t motorDirection; // Motor Spin Direction : 0 - Positive Direction, 1 - Negative Direction
} motor_status_t;
extern delay_gen_t          delay_10ms;
extern unsigned int         Align_Counter;
extern mcParam_ControlRef   mcApp_ControlParam;
extern motor_status_t       mcApp_motorState;
extern float                OpenLoop_Ramp_Angle_Rads_Per_Sec;
extern mcParam_SinCos		mcApp_SincosParam;
extern mcParam_SVPWM        mcApp_SVGenParam;



extern void mcApp_motorStartToggle();
extern void mcApp_motorDirectionToggle();

extern void ADC_ISR (ADC_STATUS status, uintptr_t context);
extern void OC_FAULT_ISR (uintptr_t context);

extern void mcApp_SpeedRamp();
extern void mcApp_InitControlParameters(void);
extern void mcApp_InitEstimParm(void);
extern void mcApp_ADCISRTasks(ADC_STATUS status, uintptr_t context);
extern void ADC_CALIB_ISR(ADC_STATUS status, uintptr_t context);
extern void PWM_Output_Enable();
extern void PWM_Output_Disable();
extern void mcApp_motorStart();
extern void mcApp_motorStop();

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
