/*******************************************************************************
Rotor Position interface file

 Company:
   Microchip Technology Inc.

 File Name:
   mc_rotorposition.h

 Summary:
   Header file for rotor position

 Description:
   This file contains the data structures and function prototypes of rotor position.
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

#ifndef MCRPOS_H    // Guards against multiple inclusion
#define MCRPOS_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "mc_pmsm_foc_common.h"


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

typedef enum
{
    MCRPOS_FORCE_ALIGN
}tMCRPOS_ALIGN_STATE_E;

typedef struct
{
    tMCRPOS_ALIGN_STATE_E           rotorAlignState;
    uint32_t                        startupLockCount;
    uint8_t                         status;
}tMCRPOS_ROTOR_ALIGN_STATE_S;

typedef struct
{
    float                           lockCurrent;
    uint32_t                        lockTimeCount;
}tMCRPOS_ROTOR_ALIGN_PARAM_S;

typedef struct
{
    float                           idRef;
    float                           iqRef;
    float                           angle;
}tMCRPOS_ROTOR_ALIGN_OUTPUT_S;

typedef struct
{
<#if __PROCESSOR?matches("PIC32M.*") == true>
    int32_t                         position;
    int32_t                         velocity;
    int32_t                         synCounter;

<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    uint16_t                        position;
    int16_t                         velocity;
    uint16_t                        synCounter;
    int16_t                         positionForSpeed;
    int16_t                         positionLastForSpeed;
    uint16_t                        positionLast;
    uint16_t                        positionCount;
    uint16_t                        positionCompensation;
</#if>
}tMCRPOS_STATE_SIGNAL_S;

typedef struct
{
    float                            angle;
    float                            speed;
    float                            acceleration;
  #if(1U == FIELD_WEAKENING )
    float                            esfilt;
  #endif
}tMCRPOS_OUTPUT_SIGNAL_S;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
extern tMCRPOS_STATE_SIGNAL_S gMCRPOS_StateSignals;
extern tMCRPOS_OUTPUT_SIGNAL_S gMCRPOS_OutputSignals;
extern tMCRPOS_ROTOR_ALIGN_OUTPUT_S gMCRPOS_RotorAlignOutput;

void MCRPOS_InitializeRotorPositionSensing(void);
tMCAPP_STATUS_E MCRPOS_InitialRotorPositonDetection( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput );
tMCAPP_STATUS_E MCRPOS_FieldAlignment( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput );
void MCRPOS_PositionMeasurement( void );
void MCRPOS_ResetPositionSensing( tMCRPOS_ALIGN_STATE_E state );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCRPOS_H

/**
 End of File
*/
