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

/* Switch state enum

  Summary:
    Identifies state of the switch

  Description:
    Enum for the switch states

  Remarks:
    None.
*/
typedef enum
{

         MC_APP_SWITCH_RELEASED,
  	MC_APP_SWITCH_PRESSED

}MC_APP_SWITCH_STATE;

/* Motor command

  Summary:
    Identifies motor comands

  Description:
    Enum for the motor commands

  Remarks:
    None.
*/
typedef enum
{
	  MOTOR_CTRL_CMD_STOP,
	  MOTOR_CTRL_CMD_START

}tMotorCtrlCmd;

/* Motor control FOC parameter structure

  Summary:
    Motor Control FOC Parameters

  Description:
    Structure contains run time variables of FOC

  Remarks:
    None.
*/

typedef enum
{
    MCAPP_IDLE,
    MCAPP_FIELD_ALIGNMENT,
            MCAPP_OPEN_LOOP,
	  MCAPP_CLOSED_LOOP
}tCONTROL_STATUS_E;


#if(1U == OPEN_LOOP_FUNCTIONING )
typedef struct
{
    float                           startup_angle_ramp_rads_per_sec;  
}tMCAPP_OPEN_LOOP_STATE_S;

typedef struct
{
    float	                          maxOpenLoopSpeed;   
    float                           openLoopSpeedRate; 
    float                           openLoopCurrent;                
 }tMCAPP_OPEN_LOOP_PARAM_S;

#endif

/* Motor control parameter structure

  Summary:
    Motor Control Parameters

  Description:
    Structure contains run time variables used in control loop

  Remarks:
    None.
*/
typedef struct
{
    float                    velRef;                     /*   Reference velocity from Ramp        */
    float                    idRef;                      /*   Vd flux reference value             */
    float                    iqRef;                      /*   Vq torque reference value           */
    uint32_t                 sync_cnt;                   /*   Sync Counter                        */
	  int16_t                  rotationSign;               /*   Motor direction switch              */
	  tCONTROL_STATUS_E        s_ControlStatus_e;          /*   Controller status                   */
	  tCONTROL_STATUS_E        s_ControlStatus_Old_e;      /*   Controller status of previous cycle */
} MCAPP_CONTROL_PARAM;

typedef struct
{
    float             yd;                                /*   D- axis controller output                 */
    float             Ud;                                /*   D- axis voltage                           */
    float             Ws;                                /*   mechanical speed of motor in RPM          */
    float             iqref;                             /*   Q-axis reference current                  */
    float             Esfilt;                            /*   Filtered back emf magnitude               */
    float             Umax;                              /*   Maximum voltage  (Udc / VdSquareroot(3))  */
}tMCAPP_FIELD_WEAKENING_INPUT_S;

typedef struct  
{
    float              Wbase;                           /*      Base motor speed                        */ 
    float              UmaxSqr;                         /*       Maximum stator voltage squared         */
    float              EsFiltCoeff;                     /*        Back emf filter coefficient           */
    float              Ls;                              /*        Per phase inductance                  */
    float              Rs;                              /*        Per phase resistance                  */
    float              fs;                              /*         PWM frequency                        */
    float              idmax;                           /*          maximum d- axis current             */
}tMCAPP_FIELD_WEAKENING_PARAM_S;

typedef struct
{
    float            UqrefFilt;                         /*   Filtered q-axis voltage squared           */
    float            iqrefFilt;                         /*   Filtered q-axis reference current         */
    float            iqref_1;                           /*   Last q-axis reference current             */
}tMCAPP_FIELD_WEAKENING_STATE_S;

typedef struct
{
    float           idref;                              /*   D-axis reference current                  */

}tMCAPP_FIELD_WEAKENING_OUTPUT_S;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
extern MCAPP_CONTROL_PARAM gCtrlParam;
void MCAPP_InitializeMotorControl(void);
void MCAPP_ControlLoopISR(uint32_t status, uintptr_t context);
void MCAPP_ResetMotorControl(void);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MC_APP_H

/**
 End of File
*/
