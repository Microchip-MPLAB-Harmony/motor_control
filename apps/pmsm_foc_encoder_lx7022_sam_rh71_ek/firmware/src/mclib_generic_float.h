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

#define M_PI		3.14159265358979323846
#define M_PI_2		1.57079632679489661923
#define PI					3.14159265358979f

#define SQRT3_BY2     ((float)(0.866025403788))

#define ONE_BY_SQRT3    ((float)(0.5773502691))
#define TWO_BY_SQRT3    ((float)(1.1547005384))

/* Rated Electric speed(rad/s) = (2 * pi * RATED_SPEED_RPM / 60) * (Pole Pairs) */
#define SQRT3                     ((float)1.732)
#define ANGLE_OFFSET_MIN          ((float)(M_PI_2)/(float)(32767))

#define TOTAL_SINE_TABLE_ANGLE      (2*(float)M_PI)
#define ANGLE_STEP                  (TOTAL_SINE_TABLE_ANGLE/(float)TABLE_SIZE)
#define TABLE_SIZE  256



typedef enum
{
	MOTOR_STATUS_STOPPED,
	MOTOR_STATUS_RUNNING

}tMotorStatus;

typedef struct
{
    float ia;
    float ib;
    float ic;
}MCLIB_I_ABC;

typedef struct
{
    float iAlpha;
    float iBeta;
}MCLIB_I_ALPHA_BETA;

typedef struct
{
    float id;
    float iq;
}MCLIB_I_DQ;

typedef struct
{
    float vAlpha;
    float vBeta;
}MCLIB_V_ALPHA_BETA;

typedef struct
{
    float vd;
    float vq;
}MCLIB_V_DQ;

typedef struct
{
    float angle;
    float sineAngle;
    float cosAngle;
}MCLIB_POSITION;

typedef struct
{
    float   dSum;
    float   kp;
    float   ki;
    float   kc;
    float   outMax;
    float   outMin;
    float   inRef;
    float   inMeas;
    float   out;

} MCLIB_PI;

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
    uint32_t dPWM1;
    uint32_t dPWM2;
    uint32_t dPWM3;
} MCLIB_SVPWM;

extern MCLIB_PI     gPIParmQ;        /* Iq PI controllers */
extern MCLIB_PI     gPIParmD;        /* Id PI controllers */
extern MCLIB_PI     gPIParmQref;     /* Speed PI controllers */

extern MCLIB_I_ABC gMCLIBCurrentABC;
extern MCLIB_I_ALPHA_BETA  gMCLIBCurrentAlphaBeta;
extern MCLIB_I_DQ gMCLIBCurrentDQ;
extern MCLIB_POSITION gMCLIBPosition;
extern MCLIB_V_DQ gMCLIBVoltageDQ;
extern MCLIB_V_ALPHA_BETA gMCLIBVoltageAlphaBeta;
extern MCLIB_SVPWM gMCLIBSVPWM;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
 void MCLIB_ClarkeTransform(MCLIB_I_ABC* input, MCLIB_I_ALPHA_BETA* output);
 void MCLIB_ParkTransform(MCLIB_I_ALPHA_BETA* input, MCLIB_POSITION* position, MCLIB_I_DQ* output);
 void MCLIB_InvParkTransform(MCLIB_V_DQ* input, MCLIB_POSITION* position, MCLIB_V_ALPHA_BETA* output);
 void MCLIB_SinCosCalc(MCLIB_POSITION* position );
 void MCLIB_PIControl( MCLIB_PI *pParm);
 void MCLIB_SVPWMGen( MCLIB_V_ALPHA_BETA* vAlphaBeta, MCLIB_SVPWM* svm );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCLIB_GENERIC_FLOAT_H

/**
 End of File
*/
