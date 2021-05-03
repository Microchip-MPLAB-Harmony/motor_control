/*******************************************************************************
 Motor Control Library interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_lib.h

  Summary:
    Motor control library interface

  Description:
    This file contains the data structures and function prototypes of
    motor control library.
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

#ifndef MCLIB_GENERIC_FLOAT_H    // Guards against multiple inclusion
#define MCLIB_GENERIC_FLOAT_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "mc_currmeasurement.h"

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
    float alphaAxis;
    float betaAxis;
}tMCLIB_CLARK_TRANSFORM_S;

typedef struct
{
    float directAxis;
    float quadratureAxis;
}tMCLIB_PARK_TRANSFORM_S;

typedef struct
{
    float angle;
    float sineAngle;
    float cosAngle;
}tMCLIB_POSITION_S;



extern tMCLIB_CLARK_TRANSFORM_S  gMCLIB_CurrentAlphaBeta;
extern tMCLIB_PARK_TRANSFORM_S gMCLIB_CurrentDQ;
extern tMCLIB_POSITION_S gMCLIB_Position;
extern tMCLIB_PARK_TRANSFORM_S gMCLIB_VoltageDQ;
extern tMCLIB_CLARK_TRANSFORM_S gMCLIB_VoltageAlphaBeta;




// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
void MCLIB_ClarkeTransform( const tMCCUR_PHASE_CURRENTS_S * const input, tMCLIB_CLARK_TRANSFORM_S * const output);
void MCLIB_ParkTransform(const tMCLIB_CLARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_PARK_TRANSFORM_S * const output);
void MCLIB_InvParkTransform(const tMCLIB_PARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_CLARK_TRANSFORM_S * const output);







// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCLIB_GENERIC_FLOAT_H

/**
 End of File
*/
