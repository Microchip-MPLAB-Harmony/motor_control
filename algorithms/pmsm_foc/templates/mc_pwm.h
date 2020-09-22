/*******************************************************************************
 Space Vector PWM interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pwm.h

  Summary:
    Header file for mc_pwm.c

  Description:
    This file contains the data structures and function prototypes used by
    PWM module
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

#ifndef MCPWM_H    // Guards against multiple inclusion
#define MCPWM_H


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
typedef struct
{
    float    period;
    float    vr1;
    float    vr2;
    float    vr3;
    float    t1;
    float    t2;
    float    ta;
    float    tb;
    float    tc;
    uint32_t neutralPWM;
    uint32_t dPwm1;
    uint32_t dPwm2;
    uint32_t dPwm3;
    bool     enableSVPWM;
} tMCPWM_SVPWM_S;

extern tMCPWM_SVPWM_S gMCPWM_SVPWM;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
void MCPWM_PWMModulator( void );
void MCPWM_PWMOutputDisable(void);
void MCPWM_PWMOutputEnable(void);

void MCPWM_SVPWMGen( const tMCLIB_CLARK_TRANSFORM_S * const vAlphaBeta, tMCPWM_SVPWM_S * const svm );
void MCPWM_PWMDutyUpdate(tMCPWM_SVPWM_S * const svm);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCINF_H

/**
 End of File
*/
