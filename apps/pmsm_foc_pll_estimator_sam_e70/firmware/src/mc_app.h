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
#include "mclib_generic_float.h"


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
/* Motor state enum

  Summary:
    Identifies motor states

  Description:
    Enum for the motor states

  Remarks:
    None.
*/
typedef enum 
{
   /* Application's state machine's initial state. */
	MC_APP_STATE_INIT = 0U,
    MC_APP_STATE_START,
	MC_APP_STATE_RUNNING,
    MC_APP_STATE_STOP,
}MC_APP_STATE;

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

/* Motor control structure

  Summary:
    Motor Control state

  Description:
    Structure contains motor state variable

  Remarks:
    None.
*/
typedef struct 
{
  MC_APP_STATE mcState;
  uint32_t switchCount;
  MC_APP_SWITCH_STATE switchState;
}MC_APP_DATA;

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
typedef struct 
{
    float   angle;
	float   dIqRefdt;
	float   lastIqRef;

	float   lastVd;
    float   fwVd;
  
    float   fwVqRefFiltered;

    float   dcBusVoltage;
    float   dcBusVoltageBySqrt3;
} MCAPP_FOC_PARAM;

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
    float    velRef;        /* Reference velocity from Ramp */
    float    idRef;         /* Vd flux reference value */
	float    idRefFF;       /* Id reference value from feed forward */
    float    iqRef;         /* Vq torque reference value */
	float	 endSpeed;      /* End speed reference value for ramp */
	float    rampIncStep;   /* Speed increment per slow loop execution */
    float    startup_angle_ramp_rads_per_sec;  /* ramp angle variable for initial ramp */
    uint32_t startup_lock_count; /* lock variable for initial ramp */
    uint32_t open_loop_stab_counter;
    uint32_t sync_cnt;   /* counter in main loop (5ms) synchronization function */
	tMotorStatus motorStatus;   /* Motor status, STOPPED - 0, RUNNING -1 */
	bool         openLoop;      /* Indicated motor running in open loop; */
	bool         changeMode;    /* Switch from open loop to close loop */     
	
} MCAPP_CONTROL_PARAM;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
void MCAPP_Tasks(void);
void MCAPP_MotorStart(void);
void MCAPP_MotorStop(void);
void MCAPP_MotorPLLEstimInit(void);
void MCAPP_MotorPIParamInit(void);


    
// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MC_APP_H

/**
 End of File
*/