/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef _MC_APP_H
#define _MC_APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

typedef struct 
{
    float   PWMPeriod;

    float   Vr1;
    float   Vr2;
    float   Vr3;
    float   Vr4;
    float   Vr5;
    float   Vr6;
} tSVGenParm;

typedef struct 
{
    float   VelRef;    						// Reference velocity
    float   IdRef;     						// Vd flux reference value
    float   IqRef;     						// Vq torque reference value
	float	qRefRamp;						// Ramp for speed reference value
	float   qDiff;							// Speed of the ramp
	float	IdRefFF;						// Feed forward Idref during Field Weakening
	float	IdRefPI;						// Field Weakening Idref PI output
	float 	IqRefmax;						// Maximum Q axis current	
} tCtrlParm;

typedef struct 
{
    float   RevAngle;
    float   Angle;
    float   Sin;
    float   Cos;
    float   Ia;
    float   Ib;
    float   Ialpha;
    float   Ibeta;
    float   Id;
    float   Iq;
    float   Vd;
    float   FW_Vd;
    float   Vq;
    float   FW_Vq;
    float   Valpha;
    float   Vbeta;
    float   V1;
    float   V2;
    float   V3;
    float   DCBusVoltage;
    float   MaxPhaseVoltage;
	float	VdqNorm;
	float	MaxVoltageCircleSquared;
	float   VdSquaredDenorm;
	float	VqSquaredDenorm;
	float	VqRefVoltage;

} tParkParm;

typedef struct 
{
    float   RevAngle;
    float   Angle;
    float   Sin;
    float   Cos;
} tSincosParm;

union  SYSTEM_STATUS_UNION 
{
    struct
    {
        unsigned RunMotor:1;  					/* run motor indication */
        unsigned OpenLoop:1;  					/* open loop/clsd loop indication */
        unsigned Btn1Pressed:1; 				/* btn 1 pressed indication */
        unsigned Btn2Pressed:1; 				/* btn 2 pressed indication */
        unsigned ChangeMode:1; 					/* mode changed indication - from open to clsd loop */
        unsigned ChangeSpeed:1; 				/* speed doubled indication */
        unsigned Btn2Debounce:1;
        unsigned ClassBPass:1;
        unsigned    :8;
    }bit;
    
	unsigned short Word;
}MC_APP_MC_CONTROL ;        						// general flags

typedef struct 
{
    float   qdSum;          
    float   qKp;
    float   qKi;
    float   qKc;
    float   qOutMax;
    float   qOutMin;
    float   qInRef; 
    float   qInMeas;
    float   qOut;
    float   qErr;
} tPIParm;

typedef struct 
{
	float	qRs;								// Rs value - stator resistance
	float	qLsDt;								// Ls/dt value - stator inductand / dt - variable with speed
   	float	qInvKFi;	    					// InvKfi constant value ( InvKfi = Omega/BEMF )
} tMotorEstimParm;

//extern  	tPIParm     										PIParmQ;        /* parms for PI controlers */
//extern  	tPIParm     										PIParmD;        /* parms for PI controlers */
//extern 		tParkParm											ParkParm;
//extern 		tSincosParm											SincosParm;
//extern 		tSVGenParm 											SVGenParm;    
//extern 		float 												dPWM1, dPWM2, dPWM3;
//extern 		tCtrlParm 											CtrlParm;

//typedef 	signed int 											int32_t;
#define 	TOTAL_SINE_TABLE_ANGLE      						(2*M_PI)
#define 	TABLE_SIZE      									256
#define 	ANGLE_STEP      									(float)((float)TOTAL_SINE_TABLE_ANGLE/(float)TABLE_SIZE)
#define     ONE_OVER_ANGLE_STEP                                 (float)((float)TABLE_SIZE / TOTAL_SINE_TABLE_ANGLE)

//extern 		const float 										sineTable[TABLE_SIZE];
//extern 		const float 										cosineTable[TABLE_SIZE];

//extern 		tMotorEstimParm 									MotorEstimParm;
//
//extern      short                                               phaseCurrentA;
//extern      short                                               phaseCurrentB;
//extern      short                                               potReading;
//extern      float                                                Startup_Ramp_Angle_Rads_Per_Sec;
//extern      unsigned int                                    Speed_Maintain_Cnt1;

typedef enum
{
	/* Application's state machine's initial state. */
	MC_APP_MC_STATE_INIT = 0,
	MC_APP_MC_STATE_START,
    MC_APP_MC_STATE_RUNNING,
    MC_APP_MC_STATE_STOP,
} MC_APP_MC_STATES;

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


// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
	/* Application's state machine's initial state. */
	MC_APP_STATE_INIT=0,
	MC_APP_STATE_SERVICE_TASKS,

	/* TODO: Define states used by the application state machine. */


} MC_APP_STATES;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    MC_APP_STATES state;
	MC_APP_MC_STATES mcState;
    uint16_t switchCount;
    MC_APP_SWITCH_STATE switchState;
    int16_t direction;
} MC_APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/
	
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void MC_APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the 
    application in its initial state and prepares it to run so that its 
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    MC_APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void MC_APP_Initialize ( void );


/*******************************************************************************
  Function:
    void MC_APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    MC_APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void MC_APP_MC_Tasks( void );

/* MC Core Routines */
void MC_APP_MC_InvPark(void);
void MC_APP_MC_CalcRefVec(void);
void MC_APP_MC_Clarke(void);
void MC_APP_MC_Park(void);
void MC_APP_MC_CalcSVGen( void );
void MC_APP_MC_CalcTimes( void );
void MC_APP_MC_InitControlParameters(void);
void MC_APP_MC_InitPI( tPIParm *pParm);
void MC_APP_MC_CalcPI( tPIParm *pParm);
void MC_APP_MC_SinCos(void);
void MC_APP_MC_CalculateParkAngle(void);
void MC_APP_MC_DoControl( void );




#endif /* _MC_APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

