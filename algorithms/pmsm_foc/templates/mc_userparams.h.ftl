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

/***********************************************************************************************/
/*                    include files                                                            */
/***********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - START                                                        */
/***********************************************************************************************/

#define POTENTIOMETER_INPUT_ENABLED 1U

#define NO_ALIGNMENT                    (0U)
#define FORCED_ALIGNMENT                (1U)
#define IPD                             (2U)

#define SENSORLESS_PLL                  (0U)
#define SENSORED_ENCODER                (1U)
#define SENSORLESS_ROLO                 (2U)
#define SENSORLESS_SMO                  (3U)

#define DUAL_SHUNT                        0U
#define SINGLE_SHUNT                      1U


/***********************************************************************************************/
/* Algorithm Configuration parameters                                                          */
/***********************************************************************************************/
#define POSITION_FEEDBACK                (${MCPMSMFOC_POSITION_FB})

#define OPEN_LOOP_FUNCTIONING            (${MCPMSMFOC_OPEN_LOOP?then('1','0')}U)  /* If enabled - Keep running in open loop */
#define TORQUE_MODE                      (${MCPMSMFOC_TORQUE_MODE?then('1','0')}U)  /* If enabled - torque control */
#define FIELD_WEAKENING                  (${MCPMSMFOC_FIELD_WEAKENING?then('1','0')}U)  /* If enabled - Field weakening */
#define ALIGNMENT_METHOD                 (${MCPMSMFOC_ALIGNMENT_METHOD}U)  /* alignment method  */

<#if MCPMSMFOC_ALIGNMENT == "0">
#define Q_AXIS_ALIGNMENT                 (1U)
#define ANGLE_OFFSET_DEG                 (float)45.0    /* Angle offset while switching to closed loop */
<#else>
#define D_AXIS_ALIGNMENT                 (1U)
#define ANGLE_OFFSET_DEG                 (float)0       /* Angle offset while switching to closed loop */
</#if>

#define CURRENT_MEASUREMENT              (${MCPMSMFOC_CURRENT_MEAS})  /* Current measurement shunts */

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
<#if MCPMSMFOC_POSITION_FB == "1">
#define ENCODER_PULSES_PER_REV                              ((float)${MCPMSMFOC_QE_PULSES_PER_REV})
</#if>

/*****************************************************************************/
/* Control Parameters                                                        */
/*****************************************************************************/

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                (${MCPMSMFOC_LOCK_TIME})   /* Startup - Rotor alignment time */
#define OPEN_LOOP_END_SPEED_RPM         (${MCPMSMFOC_OL_END_SPEED}) /* Startup - Control loop switches to close loop at this speed */
#define OPEN_LOOP_RAMP_TIME_IN_SEC      (${MCPMSMFOC_OL_RAMP_TIME})   /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds */
#define Q_CURRENT_REF_OPENLOOP          (${MCPMSMFOC_OL_IQ_REF}) /* Startup - Motor start to ramp up in current control mode */

/* Current ramp parameters for open loop to close loop transition  */
#define Q_CURRENT_OPENLOOP_STEP                    ((float)0.001)
#define CLOSING_LOOP_TIME_COUNTS                   (uint32_t)( Q_CURRENT_REF_OPENLOOP / Q_CURRENT_OPENLOOP_STEP)

/* Field weakening - Limit for -ve Idref */
#if(FIELD_WEAKENING == 1U)
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
#define     SPEEDCNTR_ITERM            (float)(${MCPMSMFOC_SPEED_KI})
#define     SPEEDCNTR_CTERM            (float)(${MCPMSMFOC_SPEED_KC})
#define     SPEEDCNTR_OUTMAX           (float)(${MCPMSMFOC_SPEED_OUT_MAX})


/* First order low pass Filter constants used inside the project             */
#define KFILTER_ESDQ                   (float)((float)200/(float)32767)
#define KFILTER_BEMF_AMPLITUDE         (float)((float)100/(float)32767)
#define KFILTER_VELESTIM               (float)((float)174/(float)32767)
#define KFILTER_POT                    (float)((float)50/(float)32767)

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
/* Current measurement algorithms */

/** PWM frequency in Hz */
#define PWM_FREQUENCY                     (${MCPMSMFOC_PWM_FREQ}U)

/**********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - END                                                          */
/***********************************************************************************************/

#endif
