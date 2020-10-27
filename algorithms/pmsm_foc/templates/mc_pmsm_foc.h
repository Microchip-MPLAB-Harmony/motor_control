/*******************************************************************************
 PMSM_FOC App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pmsm_foc.h

  Summary:
    Header file for PMSM_FOC APP

  Description:
    This file contains the data structures and function prototypes used by
    PMSM FOC module.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#ifndef MCINF_H    // Guards against multiple inclusion
#define MCINF_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "mc_lib.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
#define     DELAY_MS                               (float)5  // Delay in milliseconds after which Speed Ramp loop is executed
#define     DELAY_10MS_COUNT                       (uint32_t)(PWM_FREQUENCY*DELAY_MS*(float)0.001)
#define     SW_DEBOUNCE_DLY_MS                     (float)500  // Switch debounce delay in mS
#define     SW_DEBOUNCE_DLY_500MS                  (uint32_t)(SW_DEBOUNCE_DLY_MS/DELAY_MS)

typedef enum
{
    PMSM_FOC_SWITCH_RELEASED,
    PMSM_FOC_SWITCH_PRESSED
}tPMSM_FOC_SWITCH_STATE_E;

typedef enum
{
    PMSM_FOC_BUTTON_READY,
    PMSM_FOC_BUTTON_WAIT
}tPMSM_FOC_BUTTON_STATE_E;

typedef struct
{
    tPMSM_FOC_BUTTON_STATE_E state;
    uint32_t debounceCounter;
}tPMSM_FOC_BUTTON_STATE_S;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void PMSM_FOC_Tasks();

void PMSM_FOC_Initialize(void);
void PMSM_FOC_ResetParameters(void);

void PMSM_FOC_MotorStart( void );
void PMSM_FOC_MotorStop( void );

void PMSM_FOC_SpeedLoopTasks( void );

void PMSM_FOC_ButtonResponse( const tPMSM_FOC_SWITCH_STATE_E  buttonState,  void (*buttonFunction)(void) );

<#if MCPMSMFOC_BOARD_SEL != "MCHV3">
void PMSM_FOC_DirectionToggle(void);
</#if>




// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCINF_H

/**
 End of File
*/
