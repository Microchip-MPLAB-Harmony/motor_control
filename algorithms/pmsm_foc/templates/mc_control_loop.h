/*******************************************************************************
 Motor Control App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_app.h

  Summary:
    Motor control algorithm interface

  Description:
    This file contains the data structures and function prototypes of motor control loop.
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

#ifndef MC_APP_H    // Guards against multiple inclusion
#define MC_APP_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include "mc_lib.h"
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

typedef struct
{
    float                           openLoopAngle;
}tMCCTRL_OPEN_LOOP_STATE_SIGNALS_S;

typedef struct
{
    float                            maxOpenLoopSpeed;
    float                           openLoopSpeedRate;
    float                           openLoopCurrent;
 }tMCCTRL_OPEN_LOOP_PARAM_S;

/*---------------------------------------------------------------------------*/


typedef struct
{
    float             yd;                                        /*   D- axis controller output                 */
    float             ud;                                        /*   D- axis voltage                           */
    float             ws;                                        /*   mechanical speed of motor in RPM          */
    float             iqref;                                     /*   Q-axis reference current                  */
    float             esFilt;                                    /*   Filtered back emf magnitude               */
    float             umax;                                      /*   Maximum voltage  (Udc / VdSquareroot(3))  */
}tMCCTRL_FW_INPUT_SIGNALS_S;

typedef struct
{
    float              wbase;                                    /*      Base motor speed                       */
    float              umaxSqr;                                  /*      Maximum stator voltage squared         */
    float              esFiltCoeff;                              /*      Back emf filter coefficient            */
    float              ls;                                       /*      Per phase inductance                   */
    float              rs;                                       /*      Per phase resistance                   */
    float              fs;                                       /*      PWM frequency                          */
    float              idmax;                                    /*      maximum d- axis current                */
}tMCCTRL_FW_PARAM_S;

typedef struct
{
    float            uQrefFilt;                                 /*   Filtered q-axis voltage squared           */
    float            iQrefFilt;                                 /*   Filtered q-axis reference current         */
    float            iQrefLast;                                   /*   Last q-axis reference current             */
}tMCCTRL_FW_STATE_SIGNALS_S;

typedef struct
{
    float           idref;                                      /*   D-axis reference current                  */

}tMCCTRL_FW_OUTPUT_SIGNALS_S;

/*----------------------------------------------------------------------------*/

typedef struct
{
    uint32_t         stabilizationCounter;
}tMCCTRL_CLOSING_LOOP_STATE_SIGNALS_S;


typedef struct
{
    uint32_t             stabilizationTime;
}tMCCTRL_CLOSING_LOOP_PARAM_S;

typedef enum
{
    MCCTRL_LOOP_INACTIVE,
    MCCTRL_LOOP_ACTIVE
}tMCCTRL_TASK_STATE_E;

typedef struct
{
    volatile tMCCTRL_TASK_STATE_E  speedLoopActive;
    volatile tMCCTRL_TASK_STATE_E  positionLoopActive;
    volatile tMCCTRL_TASK_STATE_E  userInputLoopActive;
}tMCCTRL_TASK_STATE_SIGNALS_S;

typedef struct
{
    uint32_t  speedLoopCount;
    uint32_t  positionLoopCount;
    uint32_t  userInputLoopCount;
}tMCCTRL_TASK_PARAM_S;

extern tMCCTRL_TASK_STATE_SIGNALS_S gMCCTRL_TaskStateSignals;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void MCCTRL_InitializeMotorControl(void);
void MCCTRL_ResetMotorControl(void);
void MCCTRL_CurrentLoopTasks( uint32_t status, uintptr_t context );
void MCCTRL_CurrentOffsetCalibration( uint32_t status, uintptr_t context );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MC_APP_H

/**
 End of File
*/
