/*******************************************************************************
  System Definitions

  File Name:
    mc_rolo.h

  Summary:
    Header file which contains variables and function prototypes for angle and speed estimation
    with reduced order Luenberger observer 
 
  Description:
    This file contains variables and function prototypes which are generally used for angle and 
    speed estimation with reduced order Luenberger observer .  Implemented in Q2.14 Fixed
     Point Arithmetic.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef MCRPO_H
#define MCRPO_H

#include <stdint.h>
#include <sys/attribs.h>
#include "mc_generic_library.h"
#include "mc_interface_handling.h"

/*******************************************************************************
Macro definitions
*******************************************************************************/
#define OBS_H_GAIN			( 0.2f )				/* RANGE: 0.2 - 0.5 */
#define OBS_C0_GAIN			( 1.0f - OBS_H_GAIN )	/* > 0 */
#define OBS_MINFREQ_HZ		( 3.0f )
#define OBS_MINSPEED_R_S	         ((float)(2.0f * FLOAT_PI * OBS_MINFREQ_HZ))
#define OBS_MAXSHIFTS		(uint16_t)( 32u )



/* uncomment the following macro to enable phase clamping to enhance waveform */
/* #define PH_CLAMP */
#define MAX_DSPEED			( 300 )

/*	only the cross-coupling coefficients are speed dependent, and their value is usually
	much lesser than the others; so in first approximation they could be neglected, saving
	a lot of computation time; furthermore, neglecting them could lead to a higher noise immunity */
#define CROSS_COUPLING_ENABLED 

/* uncomment the following macro to enable amplification clamping */
/* #define AMP_CLAMP */

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define ROLO_MODULE_CONFIG    {\
     /* Instance Id */\
    0u,\
    \
    /* Input ports */ \
    { \
        &mcMocI_FeedbackAlphaBetaCurrent_gds.alpha,\
        &mcMocI_FeedbackAlphaBetaCurrent_gds.beta, \
        &mcMocI_AlphaBetaVoltage_gds.alpha, \
        &mcMocI_AlphaBetaVoltage_gds.beta, \
        &mcVolI_UacPeakVoltage_gds16, \
        &mcMocI_RotationSign_gds8 \
    }, \
    \
    /* Output ports */ \
    {\
        &mcRpoI_ElectricalRotorPosition_gdu16, \
        &mcRpoI_ElectricalRotorSpeed_gds16, \
        &mcRpoI_ElectricalRotorAccel_gds16,  \
        &mcRpoI_BackEmfMagnitude_gds16 \
    }, \
    \
    /* User Parameters */ \
    { \
        CURRENT_CONTROL_FREQUENCY, \
        BASE_SPEED,   \
        BASE_VOLTAGE, \
        BASE_CURRENT, \
        MOTOR_PER_PHASE_RESISTANCE_IN_OHM, \
        QUADRATURE_AXIS_INDUCTANCE_IN_HENRY, \
        OBS_H_GAIN, \
        CURRENT_CONTROL_SAMPLING_TIME,   \
    }\
}

/*******************************************************************************
Type definitions
*******************************************************************************/
typedef struct _tmcRpo_InputPorts_s
{
    int16_t  * ia;		// measured alpha current 
    int16_t  * ib;		// measured beta current
    int16_t  * ua;		// applied alpha voltage
    int16_t  * ub;		// applied beta voltage   
    int16_t  * um;
    int8_t  * rotSign;
}tmcRpo_InputPorts_s;

typedef struct _tmcRpo_UserParameters_s
{
    float samfreq;
    float basespe;
    float basevol;
    float basecur;
    float Rs;
    float Ls;
    float H;
    float Ts;      
}tmcRpo_UserParameters_s;

typedef struct _tmcRpo_OutputPorts_s
{
    uint16_t * angle;
    int16_t * speed;
    int16_t * accel;
    int16_t * Es;
}tmcRpo_OutputPorts_s;


typedef struct _tmcRpo_ConfigParameters_s
{
    /* Instance Id */
    uint8_t Id;
    
    /* Input ports */
    tmcRpo_InputPorts_s inPort;
    
    /* Output ports */
    tmcRpo_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcRpo_UserParameters_s userParam;
    
}tmcRpo_ConfigParameters_s;

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
extern tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gds;


/*******************************************************************************
 * Interface functions
*******************************************************************************/

/* !\brief Initialize Observer  
 * 
 * Details.
 * This interface functions initializes the observer
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
void mcRpoI_RotorPositionCalculationInit( tmcRpo_ConfigParameters_s * const rolParam );

/* !\brief Execute Luenberger Observer 
 * 
 * Details.
 * This interface functions reads phase current and voltage space vector inputs ( alpha -beta ),
 *  and estimates the rotor phase angle and speed
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcRpoI_RotorPositionCalculationRun( uint8_t Id );
#else
void mcRpoI_RotorPositionCalculationRun(  uint8_t Id  );
#endif

/* !\brief Reset Observer  
 * 
 * Details.
 * This interface functions reset the observer
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
void mcRpoI_RotorPositionCalculationReset( uint8_t Id );

#endif // _MCRPO_H
