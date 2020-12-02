 /*******************************************************************************
 User Parameters interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_userparams.h

  Summary:
    Motor control parameters interface

  Description:
    This file contains the motor parameters and hardware board parameters
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

#ifndef _USER_HEADER
#define _USER_HEADER

#include "mc_pmsm_foc_common.h"
/***********************************************************************************************/
/*                    include files                                                            */
/***********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - START                                                        */
/***********************************************************************************************/

/***********************************************************************************************/
/* Algorithm Configuration parameters                                                          */
/***********************************************************************************************/
#define BOARD                            (${MCPMSMFOC_BOARD_SEL})                            
#define POSITION_FEEDBACK                (${MCPMSMFOC_POSITION_FB})

<#if MCPMSMFOC_POSITION_FB != "SENSORED_ENCODER">
#define OPEN_LOOP_FUNCTIONING            (${MCPMSMFOC_OPEN_LOOP?then('ENABLED','DISABLED')})  /* If enabled - Keep running in open loop */
</#if>
#define TORQUE_MODE                      (${MCPMSMFOC_TORQUE_MODE?then('ENABLED','DISABLED')})  /* If enabled - torque control */
#define FIELD_WEAKENING                  (${MCPMSMFOC_FIELD_WEAKENING?then('ENABLED','DISABLED')})  /* If enabled - Field weakening */
#define ALIGNMENT_METHOD                 (${MCPMSMFOC_ALIGNMENT_METHOD})  /* alignment method  */

<#if MCPMSMFOC_ALIGNMENT == "0">
#define Q_AXIS_ALIGNMENT                 (ENABLED)
<#else>
#define D_AXIS_ALIGNMENT                 (ENABLED)
</#if>
<#if MCPMSMFOC_POSITION_FB != "SENSORED_ENCODER">
#define ANGLE_OFFSET_DEG                 (float)45.0    /* Angle offset while switching to closed loop */
</#if>

#define CURRENT_MEASUREMENT              (${MCPMSMFOC_CURRENT_MEAS})  /* Current measurement shunts */

<#if MCPMSMFOC_SPEED_REF_INPUT == "Potentiometer Analog Input">
#define POTENTIOMETER_INPUT_ENABLED       ENABLED
<#else>
#define POTENTIOMETER_INPUT_ENABLED       DISABLED
#define SPEED_REF_RPM                     (float)${MCPMSMFOC_SPEED_REF}
</#if>
/***********************************************************************************************/
/* Motor Configuration Parameters */
/***********************************************************************************************/
#define MOTOR_PER_PHASE_RESISTANCE                          ((float)${MCPMSMFOC_R})
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)${MCPMSMFOC_LD})
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH                ((float)${MCPMSMFOC_BEMF_CONST})
#define NUM_POLE_PAIRS                                      ((float)${MCPMSMFOC_POLE_PAIRS})
#define RATED_SPEED_RPM                                     ((float)${MCPMSMFOC_RATED_SPEED})
#define MAX_SPEED_RPM                                       ((float)${MCPMSMFOC_MAX_SPEED})
#define MAX_MOTOR_CURRENT                                   ((float)${MCPMSMFOC_MAX_MOTOR_CURRENT})
#define MOTOR_CONNECTION                                    (${MCPMSMFOC_MOTOR_CONNECTION})
<#if MCPMSMFOC_POSITION_FB == "SENSORED_ENCODER">
#define ENCODER_PULSES_PER_REV                              ((float)${MCPMSMFOC_QE_PULSES_PER_REV})
</#if>

/*****************************************************************************/
/* Control Parameters                                                        */
/*****************************************************************************/

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                (${MCPMSMFOC_LOCK_TIME})   /* Startup - Rotor alignment time */
<#if MCPMSMFOC_POSITION_FB != "SENSORED_ENCODER">
#define OPEN_LOOP_END_SPEED_RPM         (${MCPMSMFOC_OL_END_SPEED}) /* Startup - Control loop switches to close loop at this speed */
#define OPEN_LOOP_RAMP_TIME_IN_SEC      (${MCPMSMFOC_OL_RAMP_TIME})   /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds */
</#if>
#define Q_CURRENT_REF_OPENLOOP          (${MCPMSMFOC_OL_IQ_REF}) /* Startup - Motor start to ramp up in current control mode */
#if (TORQUE_MODE == ENABLED)
#define Q_CURRENT_REF_TORQUE            (${MCPMSMFOC_END_TORQUE})   /* Iq ref for torque mode */
#endif

/* Current ramp parameters for open loop to close loop transition  */
#define Q_CURRENT_OPENLOOP_STEP                    ((float)0.001)
#define CLOSING_LOOP_TIME_COUNTS                   (uint32_t)( Q_CURRENT_REF_OPENLOOP / Q_CURRENT_OPENLOOP_STEP)

/* Field weakening - Limit for -ve Idref */
#if(FIELD_WEAKENING == ENABLED)
#define MAX_FW_NEGATIVE_ID_REF              (float)(${MCPMSMFOC_MAX_FW_CURRENT})
#endif

/******************************************************************************/
/* PI controllers tuning values - */

/********* D Control Loop Coefficients ****************************************/
#define     D_CURRCNTR_PTERM           (float)(${MCPMSMFOC_ID_KP})
#define     D_CURRCNTR_ITERM           (float)(${MCPMSMFOC_ID_KI})
#define     D_CURRCNTR_CTERM           (float)(${MCPMSMFOC_ID_KC})
#define     D_CURRCNTR_OUTMAX          (float)(${MCPMSMFOC_ID_OUT_MAX})

/******** Q Control Loop Coefficients ****************************************/
#define     Q_CURRCNTR_PTERM           (float)(${MCPMSMFOC_IQ_KP})
#define     Q_CURRCNTR_ITERM           (float)(${MCPMSMFOC_IQ_KI})
#define     Q_CURRCNTR_CTERM           (float)(${MCPMSMFOC_IQ_KC})
#define     Q_CURRCNTR_OUTMAX          (float)(${MCPMSMFOC_IQ_OUT_MAX})

/******* Velocity Control Loop Coefficients **********************************/
#define     SPEEDCNTR_PTERM            (float)(${MCPMSMFOC_SPEED_KP})
<#if MCPMSMFOC_BOARD_SEL == "MCHV3">
#define     SPEEDCNTR_ITERM            (float)(${MCPMSMFOC_SPEED_KI} * 0.01f)
<#else>
#define     SPEEDCNTR_ITERM            (float)(${MCPMSMFOC_SPEED_KI})
</#if>
#define     SPEEDCNTR_CTERM            (float)(${MCPMSMFOC_SPEED_KC})
#define     SPEEDCNTR_OUTMAX           (float)(${MCPMSMFOC_SPEED_OUT_MAX})


/* First order low pass Filter constants used inside the project             */
<#if MCPMSMFOC_BOARD_SEL == "MCHV3">
#define KFILTER_ESDQ                   (float)((float)4000/(float)32767)
#define KFILTER_BEMF_AMPLITUDE         (float)((float)4000/(float)32767)
#define KFILTER_VELESTIM               (float)((float)4000/(float)32767)
#define KFILTER_POT                    (float)((float)250/(float)32767)
<#else>
#define KFILTER_ESDQ                   (float)((float)200/(float)32767)
#define KFILTER_BEMF_AMPLITUDE         (float)((float)100/(float)32767)
#define KFILTER_VELESTIM               (float)((float)174/(float)32767)
#define KFILTER_POT                    (float)((float)250/(float)32767)
</#if>

/***********************************************************************************************/
/* Driver board configuration Parameters */
/***********************************************************************************************/

#define MAX_CURRENT                                         ((float)(${MCPMSMFOC_MAX_CURRENT})) /* Max current as per above calculations */
#define MAX_ADC_COUNT                                       (float)${MCPMSMFOC_ADC_MAX}     /*  ADC Resolution*/
#define MAX_ADC_INPUT_VOLTAGE                               (float)3.3      /* volts */

#define DC_BUS_VOLTAGE                                      (float)${MCPMSMFOC_DC_BUS_VOLT}     /* Volts */
#define DCBUS_SENSE_RATIO                                   (float)${MCPMSMFOC_DC_BUS_RATIO}    /* Voltage divider ratio R2/(R2 + R1) */

#define STATOR_VOLTAGE_LIMIT                                (float)(0.98)   /* In percentage */

/***********************************************************************************************/
/* Peripheral Configuration parameters */
/***********************************************************************************************/

/** PWM frequency in Hz */
#define PWM_FREQUENCY                     (${MCPMSMFOC_PWM_FREQ}U)

/**********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - END                                                          */
/***********************************************************************************************/

#endif
