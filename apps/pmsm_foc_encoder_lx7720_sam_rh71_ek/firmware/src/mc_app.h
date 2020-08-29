/*******************************************************************************
  Header File

  Company
    Microchip Technology Inc.

  File Name
    mc_app.h

  Summary
    

  Description
    This file defines the interface to the AFEC peripheral library.  This 
    library provides access to and control of the associated peripheral 
    instance.

  Remarks:
    This header is for documentation only.  The actual afec<x> headers will be
    generated as required by the MCC (where <x> is the peripheral instance 
    number).

    Every interface symbol has a lower-case 'x' in it following the "AFEC" 
    abbreviation.  This 'x' will be replaced by the peripheral instance number
    in the generated headers.  These are the actual functions that should be
    used.
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
#include "userparams.h"
#include "mclib_generic_float.h"

/*  This section lists the other files that are included in this file.
*/

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
#define PI			3.14159265358979f
    
#define SQRT3_BY2     ((float)(0.866025403788))
    
#define ONE_BY_SQRT3    ((float)(0.5773502691))
#define TWO_BY_SQRT3    ((float)(1.1547005384))

/* Rated Electric speed(rad/s) = (2 * pi * RATED_SPEED_RPM / 60) * (Pole Pairs) */
#define DECIMATE_RATED_SPEED      ((RATED_SPEED_RPM *((float)M_PI/30)) * NUM_POLE_PAIRS/10)
#define SQRT3                     ((float)1.732)
#define ANGLE_OFFSET_MIN          ((float)(M_PI_2)/(float)(32767))
    
#define TOTAL_SINE_TABLE_ANGLE      (2*(float)M_PI)
#define ANGLE_STEP                  (TOTAL_SINE_TABLE_ANGLE/(float)TABLE_SIZE)
#define TABLE_SIZE  256

/* Motor phase current offset calibration limits. */
#define CURRENT_OFFSET_MAX                (12700) /* current offset max limit in terms of ADC count*/
#define CURRENT_OFFSET_MIN                (12300) /* current offset min limit in terms of ADC count*/


typedef enum 
{
   /* Application's state machine's initial state. */
	MC_APP_STATE_INIT = 0U,
    MC_APP_STATE_WAIT_START,
    MC_APP_STATE_START,
	MC_APP_STATE_RUNNING,
    MC_APP_STATE_STOP,
    MC_APP_STATE_STOP_DECREASE,
    MC_APP_STATE_STOP_WAIT_ACQ,
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

/* Motor direction
  Summary:
    Identifies motor direction
  Description:
    Enum for the  motor direction
  Remarks:
    None.
*/
typedef enum 
{
    MC_APP_DIRECTION_FORWARD,
	MC_APP_DIRECTION_REVERSE,
}MC_APP_DIRECTION;

typedef struct 
{
  MC_APP_STATE mcState;
  uint32_t switchStartCount;
  MC_APP_SWITCH_STATE switchStartState;  
  uint32_t switchIncrCount;
  MC_APP_SWITCH_STATE switchIncrState;
  uint32_t switchDecrCount;
  MC_APP_SWITCH_STATE switchDecrState;
  uint32_t switchResetCount;
  MC_APP_SWITCH_STATE switchResetState;
  uint32_t switchDirectionCount;
  MC_APP_SWITCH_STATE switchDirectionState;
  MC_APP_DIRECTION mcDirection;
}MCAPP_DATA;

typedef enum
{
	MOTOR_CTRL_CMD_STOP,
	MOTOR_CTRL_CMD_START
}tMotorCtrlCmd;

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
    tMotorStatus oldStatus;
	bool         openLoop;      /* Indicated motor running in open loop; */
	bool         changeMode;    /* Switch from open loop to close loop */  
    int16_t   direction;
    uint8_t   fieldAlignmentFlag;   /* Power On Reset Flag*/
	
} MCAPP_CONTROL_PARAM;

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

typedef struct
{
  volatile uint16_t elec_rotation_count;
  float rotor_angle_rad_per_sec;
  int16_t prev_position_count;
  int16_t present_position_count;
  uint16_t QDECcnt;
  uint16_t QDECcntZ;
  uint16_t posCnt;
  uint16_t posCompensation;
  uint32_t posCntTmp;
  
}MCAPP_POSITION_CALC;

typedef struct 
{
    volatile uint32_t sinc1_prevq;
    volatile uint32_t sinc1_out;
    volatile uint32_t s1_out_pp;
    volatile uint32_t s1_out_p;
    volatile uint32_t intg3;
    volatile uint32_t intg2;
    volatile uint32_t intg1;
    volatile uint32_t der3;
    volatile uint32_t der2;
    volatile uint32_t der1;
    volatile uint32_t sinc3_out_ppp;
    volatile uint32_t sinc3_out_pp;
    volatile uint32_t sinc3_out_p;
    volatile uint32_t sinc3_out;
} MCAPP_SINC3;

void MCAPP_Tasks(void);
void MCAPP_MotorStart(void);
void MCAPP_MotorStop(void);
void MCAPP_MotorPIParamInit(void);
void MCAPP_PIOutputInit( MCLIB_PI *pParm);

    
// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MC_APP_H

/**
 End of File
*/