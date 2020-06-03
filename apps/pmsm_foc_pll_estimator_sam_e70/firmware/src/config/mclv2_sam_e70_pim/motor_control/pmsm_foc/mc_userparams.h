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

/***********************************************************************************************/
/* Algorithm Configuration parameters                                                          */
/***********************************************************************************************/
#define POSITION_FEEDBACK                (SENSORLESS_PLL)

#define OPEN_LOOP_FUNCTIONING            (DISABLED)  /* If enabled - Keep running in open loop */
#define TORQUE_MODE                      (DISABLED)  /* If enabled - torque control */
#define FIELD_WEAKENING                  (DISABLED)  /* If enabled - Field weakening */
#define ALIGNMENT_METHOD                 (FORCED_ALIGNMENT)  /* alignment method  */

#define Q_AXIS_ALIGNMENT                 (ENABLED)
#define ANGLE_OFFSET_DEG                 (float)45.0    /* Angle offset while switching to closed loop */

#define CURRENT_MEASUREMENT              (DUAL_SHUNT)  /* Current measurement shunts */

#define POTENTIOMETER_INPUT_ENABLED       ENABLED
/***********************************************************************************************/
/* Motor Configuration Parameters */
/***********************************************************************************************/
#define MOTOR_PER_PHASE_RESISTANCE                          ((float)0.285)
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)0.00032)
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH                ((float)7.24)
#define NUM_POLE_PAIRS                                      ((float)5)
#define RATED_SPEED_RPM                                     ((float)2804)
#define MAX_SPEED_RPM                                       ((float)3500)
#define MAX_MOTOR_CURRENT                                   ((float)4)
#define MOTOR_CONNECTION                                    (STAR)

/*****************************************************************************/
/* Control Parameters                                                        */
/*****************************************************************************/

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                (2)   /* Startup - Rotor alignment time */
#define OPEN_LOOP_END_SPEED_RPM         (500) /* Startup - Control loop switches to close loop at this speed */
#define OPEN_LOOP_RAMP_TIME_IN_SEC      (5)   /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds */
#define Q_CURRENT_REF_OPENLOOP          (0.4) /* Startup - Motor start to ramp up in current control mode */
#if (TORQUE_MODE == ENABLED)
#define Q_CURRENT_REF_TORQUE            (0.2)   /* Iq ref for torque mode */
#endif

/* Current ramp parameters for open loop to close loop transition  */
#define Q_CURRENT_OPENLOOP_STEP                    ((float)0.001)
#define CLOSING_LOOP_TIME_COUNTS                   (uint32_t)( Q_CURRENT_REF_OPENLOOP / Q_CURRENT_OPENLOOP_STEP)

/* Field weakening - Limit for -ve Idref */
#if(FIELD_WEAKENING == ENABLED)
#define MAX_FW_NEGATIVE_ID_REF              (float)(-2)
#endif

/******************************************************************************/
/* PI controllers tuning values - */

/********* D Control Loop Coefficients ****************************************/
#define     D_CURRCNTR_PTERM           (float)(0.02)
#define     D_CURRCNTR_ITERM           (float)(0.00005)
#define     D_CURRCNTR_CTERM           (float)(0.5)
#define     D_CURRCNTR_OUTMAX          (float)(0.98)

/******** Q Control Loop Coefficients ****************************************/
#define     Q_CURRCNTR_PTERM           (float)(0.02)
#define     Q_CURRCNTR_ITERM           (float)(0.00005)
#define     Q_CURRCNTR_CTERM           (float)(0.5)
#define     Q_CURRCNTR_OUTMAX          (float)(0.98)

/******* Velocity Control Loop Coefficients **********************************/
#define     SPEEDCNTR_PTERM            (float)(0.005)
#define     SPEEDCNTR_ITERM            (float)(0.00002)
#define     SPEEDCNTR_CTERM            (float)(0.5)
#define     SPEEDCNTR_OUTMAX           (float)(4.4)


/* First order low pass Filter constants used inside the project             */
#define KFILTER_ESDQ                   (float)((float)200/(float)32767)
#define KFILTER_BEMF_AMPLITUDE         (float)((float)100/(float)32767)
#define KFILTER_VELESTIM               (float)((float)174/(float)32767)
#define KFILTER_POT                    (float)((float)250/(float)32767)

/***********************************************************************************************/
/* Driver board configuration Parameters */
/***********************************************************************************************/

#define MAX_CURRENT                                         ((float)(4.4)) /* Max current as per above calculations */
#define MAX_ADC_COUNT                                       (float)4095     /*  ADC Resolution*/
#define MAX_ADC_INPUT_VOLTAGE                               (float)3.3      /* volts */

#define DC_BUS_VOLTAGE                                      (float)24     /* Volts */
#define DCBUS_SENSE_RATIO                                   (float)0.0625    /* Voltage divider ratio R2/(R2 + R1) */

#define STATOR_VOLTAGE_LIMIT                                (float)(0.98)   /* In percentage */

/***********************************************************************************************/
/* Peripheral Configuration parameters */
/***********************************************************************************************/

/** PWM frequency in Hz */
#define PWM_FREQUENCY                     (20000U)

/**********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - END                                                          */
/***********************************************************************************************/

#endif
