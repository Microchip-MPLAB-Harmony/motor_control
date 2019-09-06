/*******************************************************************************
 Motor Control App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_currMeasurement.h

  Summary:
    Header file for current measurement

  Description:
    This file contains the data structures and function prototypes of current measurement.
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
#include "mc_lib.h"
#include "mc_app.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END
/*____________________________________ Windmilling Configuration_____________________________________________ */

#define     ENABLE_WINDMILLING                         0U
#define     LOOPTIME_SEC                             (float)(1/((float)PWM_FREQUENCY))
#define     WINDMILL_TIME_SEC                          0.5    
#define     COUNT_FOR_WINDMILLING_TIME               (uint32_t)((float)WINDMILL_TIME_SEC/(float)LOOPTIME_SEC)
#define     MIN_WM_SPEED_IN_RPM                      (float)(200)
#define     MIN_WM_SPEED_SPEED_ELEC_RAD_PER_SEC      (float)(((MIN_WM_SPEED_IN_RPM/60)*2*M_PI) * NUM_POLE_PAIRS)    
#define     REGEN_BRAKE_CURRENT_REF                  (float)0.4
#define     WINDMILL_START_Q_AXIS_REF                (float)0.4
#define     REGEN_BRAKE_CURRENT_RAMP_TIME_SEC        (float)(1.0)
#define     REGEN_BRAKE_CURRENT_STEP                 (float)(REGEN_BRAKE_CURRENT_REF/(REGEN_BRAKE_CURRENT_RAMP_TIME_SEC * PWM_FREQUENCY))
#define     COUNT_FOR_PASSIVE_BRAKE_TIME               100
    
#define     DECIMATE_RATED_SPEED                     (float)((RATED_SPEED_RPM *((float)M_PI/30)) * NUM_POLE_PAIRS/10)
#define     SQRT3                                    (float)1.732
#define     ANGLE_OFFSET_MIN                         (float)(M_PI_2)/(float)(32767)
    
/*____________________________ SELECT ROTOR POSITION MEASUREMENT TECHNIQUE _______________________________________________ */
#define     PLL                                         0U

/*_____________________________________ ENCODER CONFIGURATION _____________________________________________________________*/
#define     QEI_COUNT_TO_ELECTRICAL_ANGLE            (float)(2*M_PI/ENCODER_PULSES_PER_EREV)
#define     QEI_VELOCITY_COUNT_PRESCALER             (float)100.0f
#define     QEI_VELOCITY_SAMPLE_FREQUENCY            (float)((float)PWM_FREQUENCY / (float)QEI_VELOCITY_COUNT_PRESCALER)
#define     QEI_VELOCITY_COUNT_TO_RAD_PER_SEC        (float)(((float)QEI_VELOCITY_SAMPLE_FREQUENCY * 2.0f * M_PI )/((float)ENCODER_PULSES_PER_EREV ))

/*___________________________________SELECT FORCE ALIGNMENT TECHNIQUE _____________________________________________________ */
#define     FORCED_ALIGNMENT                            1U
#if      (1U == FORCED_ALIGNMENT )
#define     D_AXIS_ALIGNMENT                            0U
#define     Q_AXIS_ALIGNMENT                            1U
#endif 

#if      (1U == Q_AXIS_ALIGNMENT )
#define     ANGLE_OFFSET_DEG                         (float)45.0
#elif    ( 1U == D_AXIS_ALIGNMENT)
#define     ANGLE_OFFSET_DEG                         (float)45.0
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* Phase currents

  Summary:
    Indicates motor phase currents

  Description:
    Datastructure for motor phase currents

  Remarks:
    None.
*/

typedef enum
{
    IDLE,
    RUNNING,
    COMPLETE,
    FAILED
}tMCRPOS_STATUS_E;

typedef enum 
{
    WINDMILLING,
    WINDMILLING_DECIDE,
    WINDMILLING_PASSIVE_BRAKE,
    FORCE_ALIGN
}tMCRPOS_ROTOR_ALIGN_STATE_E;

typedef struct 
{
    uint32_t                       wmCount;
    uint32_t                       wmDecideCount;
    uint32_t                       wmPassiveBrakeCount;
}tMCRPOS_WINDMILLING_STATE_S;

typedef struct 
{  
    tCONTROL_STATUS_E              s_ControlStatus_e;   
}tMCRPOS_WINDMILLING_OUTPUT_S;

typedef struct 
{
    float                           estSpeed; 
    int16_t                         rotationSign;
}tMCRPOS_WINDMILLING_INPUT_S;

typedef struct
{
    tMCRPOS_WINDMILLING_INPUT_S     windmillingInput;  
}tMCRPOS_ROTOR_ALIGN_INPUT_S;


typedef struct
{
    tMCRPOS_ROTOR_ALIGN_STATE_E	    rotorAlignState; 
    tMCRPOS_WINDMILLING_STATE_S     windmillingState;  
    uint32_t                        startup_lock_count;  
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
    tMCRPOS_WINDMILLING_OUTPUT_S    windmillingOutput;
}tMCRPOS_ROTOR_ALIGN_OUTPUT_S;

typedef struct
{
    float                         * ialpha;
    float                         * ibeta;
    float                         * Ualpha;
    float                         * Ubeta;
    float                         * Umax;
}tMCRPOS_INPUT_S;

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
}tMCRPOS_PARAMETER_S;

typedef struct
{
    int32_t                         position;
    int32_t                         velocity;
    int32_t                         SynCounter;
}tMCRPOS_STATE_S;

typedef struct
{
    float                            Angle;
    float                            Speed;
    float                            Acceleration;
  #if(1U == FIELD_WEAKENING )
    float                            Esfilt;
  #endif
}tMCRPOS_OUTPUT_S;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
extern tMCRPOS_INPUT_S gMCRPOS_InputSignals;
extern tMCRPOS_STATE_S gMCRPOS_StateSignals;
extern tMCRPOS_OUTPUT_S gMCRPOS_OutputSignals;
extern tMCRPOS_ROTOR_ALIGN_INPUT_S       gMCRPOS_RotorAlignInput;
extern tMCRPOS_ROTOR_ALIGN_OUTPUT_S gMCRPOS_RotorAlignOutput;

INLINE_FUNCTION   void MCRPOS_InitializeRotorPositionSensing(void);
INLINE_FUNCTION tMCRPOS_STATUS_E MCRPOS_InitialRotorPositonDetection(  const  tMCRPOS_ROTOR_ALIGN_INPUT_S * const alignInput,
                                                                                                                                                tMCRPOS_ROTOR_ALIGN_OUTPUT_S * const alignOutput );
INLINE_FUNCTION  void MCRPOS_PositionMeasurement( const tMCRPOS_INPUT_S * const rposInput, tMCRPOS_OUTPUT_S * const rposOutput );
INLINE_FUNCTION  void MCRPOS_ResetPositionSensing( void );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCRPOS_H

/**
 End of File
*/
