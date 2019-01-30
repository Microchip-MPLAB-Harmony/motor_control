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
#define CURRENT_OFFSET_MAX                (2200) /* current offset max limit in terms of ADC count*/
#define CURRENT_OFFSET_MIN                (1900) /* current offset min limit in terms of ADC count*/


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

typedef struct 
{
  MC_APP_STATE mcState;
  uint32_t switchCount;
  MC_APP_SWITCH_STATE switchState;  
}tMC_APP_DATA;


typedef enum
{
	MOTOR_CTRL_CMD_STOP,
	MOTOR_CTRL_CMD_START
	
}tMotorCtrlCmd;

typedef enum
{
	MOTOR_STATUS_STOPPED,
	MOTOR_STATUS_RUNNING
	
}tMotorStatus;


typedef struct 
{
    float    VelRef;        /* Reference velocity from Ramp */
    float    IdRef;         /* Vd flux reference value */
	float    IdRefFF;       /* Id reference value from feed forward */
	float    IdRefPI;       /* Id reference correction value from FW PI controller */
    float    IqRef;         /* Vq torque reference value */
	float	 EndSpeed;      /* End speed reference value for ramp */
	float    RampIncStep;   /* Speed increment per slow loop execution */
	tMotorStatus MotorStatus;   /* Motor status, STOPPED - 0, RUNNING -1 */
	bool         OpenLoop;      /* Indicated motor running in open loop; */
	bool         ChangeMode;    /* Switch from open loop to close loop */     
	
} tCtrlParm;

typedef struct 
{
    float   Angle;
    float   Sin;
    float   Cos;
    float   Iu;
    float   Iv;
    float   Ialpha;
    float   Ibeta;
    float   Id;
    float   Iq;
	float   DIqRefdt;
	float   LastIqRef;
    float   Vd;
	float   LastVd;
    float   FwVd;
    float   Vq;
    float   FwVqRefFiltered;
    float   Valpha;
    float   Vbeta;
    float   V1;
    float   V2;
    float   V3;
    float   DCBusVoltage;
    float   DCBusVoltageBySqrt3;
} tParkParm;
typedef struct 
{
	float				   Rs;			/* Rs value - stator resistance */
	float				   LsDt;		/* Ls/dt value - stator inductance / dt - variable with speed */
	float				   InvKFi;	    /* InvKfi constant value ( InvKfi = Omega/BEMF ) */
	
} tMotorEstimParm;

typedef struct 
{
    float   dSum;          
    float   Kp;
    float   Ki;
    float   Kc;
    float   OutMax;
    float   OutMin;
    float   InRef; 
    float   InMeas;
    float   Out;
	
} tPIParm;

typedef struct
{
	float   Angle;
	float   Sin;
	float   Cos;
} tSincosParm;

typedef struct 
{
    float   PWMPeriod;
    float   Vr1;
    float   Vr2;
    float   Vr3;

} tSVGenParm;



void app_tasks(void);
void motor_start(void);
void motor_stop(void);

void init_pi_ctrl_param(void);
void init_pi( tPIParm *pParm);

    
// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MC_APP_H

/**
 End of File
*/