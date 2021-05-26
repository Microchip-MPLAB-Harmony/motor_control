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
/*___________________________________PLL PARAMETERS  _____________________________________________________ */
#define     ANGLE_OFFSET_MIN                        ((float)(M_PI_2)/(float)(32767))
#define     DECIMATE_RATED_SPEED                     (float)((RATED_SPEED_RPM *((float)M_PI/30)) * NUM_POLE_PAIRS/10)



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

/*--------------------------------------------------------------------------*/
typedef struct
{
    float                           ialpha;
    float                           ibeta;
    float                           ualpha;
    float                           ubeta;
    float                           umax;
}tMCRPOS_INPUT_SIGNAL_S;

typedef struct
{
    float                           lsDt;
    float                           rs;
    float                           invKFi;
    float                           kFilterEsdq;
    float                           kFilterBEMFAmp;
    float                           velEstimFilterK;
    float                           deltaT;
    float                           decimateRotorSpeed;
}tMCRPOS_PARAMETERS_S;

typedef struct
{
    float                            filterInitialized;
    float                            omegaMr;
    float                            rhoOffset;
    float                            bemfFilt;
    float                            velEstim;
    float                            ialphaLast;
    float                            ibetaLast;
    float                            ualphaLast;
    float                            ubetaLast;
    float                            esa;
    float                            esb;
    float                            esd;
    float                            esq;
    float                            esdf;
    float                            esqf;
    float                            rho;
}tMCRPOS_STATE_SIGNAL_S;

typedef struct
{
    float                            angle;
    float                            speed;
    float                            mechSpeedRPM;    
    float                            acceleration;
  #if(ENABLED == FIELD_WEAKENING )
    float                            esfilt;
  #endif
}tMCRPOS_OUTPUT_SIGNALS_S;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
extern tMCRPOS_STATE_SIGNAL_S         gMCRPOS_StateSignals;
extern tMCRPOS_OUTPUT_SIGNALS_S       gMCRPOS_OutputSignals;
extern tMCRPOS_ROTOR_ALIGN_OUTPUT_S  gMCRPOS_RotorAlignOutput;

void MCRPOS_InitializeRotorPositionSensing(void);
tMCAPP_STATUS_E MCRPOS_FieldAlignment( tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput );
tMCAPP_STATUS_E MCRPOS_InitialRotorPositonDetection(tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput );
void MCRPOS_OffsetCalibration(const int16_t direction );
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
