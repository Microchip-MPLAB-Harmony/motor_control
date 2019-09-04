/*******************************************************************************
 Motor Control Library interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mclib_generic_float.h

  Summary:
    Motor control library interface

  Description:
    This file contains the data structures and function prototypes of
    motor control library.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
#include "mc_currMeasurement.h"

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

#define     M_PI		                               (float)3.14159265358979323846
#define     M_PI_2		                             (float)1.57079632679489661923
 
#define     SQRT3_BY2                              (float)(0.866025403788)

#define     ONE_BY_SQRT3                           (float)(0.5773502691)
#define     TWO_BY_SQRT3                           (float)(1.1547005384)

#define     TOTAL_SINE_TABLE_ANGLE                 (2*(float)M_PI)
#define     TABLE_SIZE                                     256
#define     ANGLE_STEP                             (TOTAL_SINE_TABLE_ANGLE/(float)TABLE_SIZE)
#define     ONE_BY_ANGLE_STEP                      (1/ANGLE_STEP)
    

#define     DELAY_MS                               (float)5  // Delay in milliseconds after which Speed Ramp loop is executed
#define     DELAY_10MS_COUNT                       (uint32_t)(PWM_FREQUENCY*DELAY_MS*(float)0.001)
#define     SW_DEBOUNCE_DLY_MS                     (float)500  // Switch debounce delay in mS
#define     SW_DEBOUNCE_DLY_500MS                  (uint32_t)(SW_DEBOUNCE_DLY_MS/DELAY_MS)

    
typedef enum
{
    SWITCH_RELEASED,
 	  SWITCH_PRESSED
}tMCLIB_SWITCH_STATE_E;

typedef struct
{
    float phaseU;
    float phaseV;
    float phaseW;
}tMCLIB_THREE_PHASE_S;

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

typedef struct
{
    float    period;
    float    vr1;
    float    vr2;
    float    vr3;
    float    t1;
    float    t2;
    float    t_a;
    float    t_b;
    float    t_c;
    uint32_t neutralPWM;
    uint32_t dPWM1;
    uint32_t dPWM2;
    uint32_t dPWM3;
} tMCLIB_SVPWM_S;


typedef enum 
{
    BUTTON_READY,
    BUTTON_WAIT
}tBUTTON_STATE_E;

typedef struct 
{
    tBUTTON_STATE_E State;
    uint32_t DebounceCounter;
}tMCLIB_BUTTON_STATE_S;


extern tMCLIB_CLARK_TRANSFORM_S  gMCLIB_CurrentAlphaBeta;
extern tMCLIB_PARK_TRANSFORM_S gMCLIB_CurrentDQ;
extern tMCLIB_POSITION_S gMCLIB_Position;
extern tMCLIB_PARK_TRANSFORM_S gMCLIB_VoltageDQ;
extern tMCLIB_CLARK_TRANSFORM_S gMCLIB_VoltageAlphaBeta;
extern tMCLIB_SVPWM_S gMCLIB_SVPWM;
extern tMCLIB_BUTTON_STATE_S gMCLIB_StartStopState;
extern tMCLIB_BUTTON_STATE_S gMCLIB_DirectionToggleState;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
void MCLIB_ClarkeTransform( const tPHASE_CURRENTS_S * const input, tMCLIB_CLARK_TRANSFORM_S * const output);
void MCLIB_ParkTransform(const tMCLIB_CLARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_PARK_TRANSFORM_S * const output);
void MCLIB_InvParkTransform(const tMCLIB_PARK_TRANSFORM_S * const input, const tMCLIB_POSITION_S * const position, tMCLIB_CLARK_TRANSFORM_S * const output);
void MCLIB_SinCosCalc(tMCLIB_POSITION_S * const position );
void MCLIB_SVPWMGen( const tMCLIB_CLARK_TRANSFORM_S * const vAlphaBeta, tMCLIB_SVPWM_S * const svm );
void MCLIB_WrapAngle( float * const angle );
void MCLIB_linearRamp(float * const input, const float stepSize, const float finalValue );
void MCLIB_ButtonResponse( const tMCLIB_SWITCH_STATE_E  buttonState,  void (*buttonFunction)(void) );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCLIB_GENERIC_FLOAT_H

/**
 End of File
*/
