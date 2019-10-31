 /*******************************************************************************
 User Parameters interface file

  Company:
    Microchip Technology Inc.

  File Name:
    userparams.h

  Summary:
    Motor control parameters interface

  Description:
    This file contains the motor parameters and hardware board parameters
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

#ifndef _USER_HEADER
#define _USER_HEADER

/***********************************************************************************************/
/*                    include files                                                            */
/***********************************************************************************************/

/***********************************************************************************************/
/*                    DEFINATIONS                                                              */
/***********************************************************************************************/
#define MOTOR_1_EL5_M0400_1_24                           (1U)    /* AC Servo Motor EL5-M0400-1-24 */

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - START                                                        */
/***********************************************************************************************/

/***********************************************************************************************/
/* Algorithm Configuration parameters                                                          */
/***********************************************************************************************/
#define TORQUE_MODE                                      (0U)  /* If enabled - torque control */

/***********************************************************************************************/
/* Motor Configuration Parameters */
/***********************************************************************************************/

/* Motor selection from above mentioned predefined motors */
#define MOTOR                                               (MOTOR_1_EL5_M0400_1_24)

#if(MOTOR == MOTOR_1_EL5_M0400_1_24)
/* AC Servo Motor EL5-M0400-1-24  */
#define MOTOR_PER_PHASE_RESISTANCE                          ((float)1.39)
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)0.00253)
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH                ((float)44.38)
#define NUM_POLE_PAIRS                                      ((float)5)
#define RATED_SPEED_RPM                                     ((float)3000)
#define MAX_SPEED_RPM                                       ((float)5000)
#define MAX_MOTOR_CURRENT                                   ((float)(5))
#define ENCODER_PULSES_PER_REV                              ((float)10000)
#endif
/*****************************************************************************/
/* Control Parameters                                                        */
/*****************************************************************************/

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                (2)   /* Startup - Rotor alignment time */
#define OPEN_LOOP_END_SPEED_RPM         (RATED_SPEED_RPM*0.20) /* Startup - Control loop switches to close loop at this speed */
#define OPEN_LOOP_RAMP_TIME_IN_SEC      (2)   /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds */
#define Q_CURRENT_REF_OPENLOOP          ((float)0.2) /* Startup - Motor start to ramp up in current control mode */

/******************************************************************************/
/* PI controllers tuning values - */
#if(MOTOR == MOTOR_1_EL5_M0400_1_24)
/********* D Control Loop Coefficients ****************************************/
#define     D_CURRCNTR_PTERM           ((float)(0.04)/MAX_MOTOR_CURRENT)
#define     D_CURRCNTR_ITERM           ((float)(0.02) /MAX_MOTOR_CURRENT)
#define     D_CURRCNTR_CTERM           ((float)(0.999)/MAX_MOTOR_CURRENT)
#define     D_CURRCNTR_OUTMAX          ((float)(0.98))

/******** Q Control Loop Coefficients ****************************************/
#define     Q_CURRCNTR_PTERM           ((float)(0.04)/MAX_MOTOR_CURRENT)
#define     Q_CURRCNTR_ITERM           ((float)(0.02) /MAX_MOTOR_CURRENT)
#define     Q_CURRCNTR_CTERM           ((float)(0.999)/MAX_MOTOR_CURRENT)
#define     Q_CURRCNTR_OUTMAX          ((float)(0.98))

/******* Velocity Control Loop Coefficients **********************************/
#define     SPEEDCNTR_PTERM            ((float)0.004)
#define     SPEEDCNTR_ITERM            ((float)0.0004)
#define     SPEEDCNTR_CTERM            ((float)(0.999))
#define     SPEEDCNTR_OUTMAX           ((float)MAX_MOTOR_CURRENT)
#endif

/* First order low pass Filter constants used inside the project             */
#define KFILTER_ESDQ                   (float)((float)200/(float)32767)
#define KFILTER_BEMF_AMPLITUDE         (float)((float)100/(float)32767)
#define KFILTER_VELESTIM               (float)((float)174/(float)32767)
#define KFILTER_POT                    (float)((float)50/(float)32767)

/***********************************************************************************************/
/* Driver board configuration Parameters */
/***********************************************************************************************/
/* MCHV-3 motor control driver board 
 * Gain of opamp = 10.06
 * shunt resistor = 0.01 ohms
 * DC offset = 1.65V
 * max current = x
 * (x * 0.01 * 10.06) + 1.65V = 3.3V
 * x = 16.4 Amps */
#define MAX_CURRENT                                         ((float)(16.4)) /* Max Board Current in A */
#define MAX_ADC_COUNT                                       (float)4095     /* 12-bit ADC */
#define MAX_ADC_INPUT_VOLTAGE                               (float)3.3      /* volts */

/** Dead time in micro seconds */
#define DEAD_TIME_uS                                        (1U)                /* Dead time in uS. */

#define DCBUS_SENSE_TOP_RESISTOR                            (float)285     /* 300K Ohm but due to temperature it is considered as 276K*/
#define DCBUS_SENSE_BOTTOM_RESISTOR                         (float)2.2     /* 2.2K Ohm */
#define STATOR_VOLTAGE_LIMIT                                (float)(0.98)  /* In percentage */


#define ACBUS_SENSE_TOP_RESISTOR                            (float)300     /* 300K Ohm */
#define ACBUS_SENSE_BOTTOM_RESISTOR                         (float)1.1     /* 1.1K Ohm */

/***********************************************************************************************/
/* Peripheral Configuration parameters */
/***********************************************************************************************/
/** PWM frequency in Hz */
#define PWM_FREQUENCY                                       (20000U)

#define CPU_FREQUENCY                                       (300000000U)
/** Master clock frequency in Hz */
#define MASTER_CLK_FREQUENCY                                (75000000U)

/** Phase Current Offset calibration samples */
#define CURRENTS_OFFSET_SAMPLES                             (100U)


#define PWM_PERIOD_COUNT       (MASTER_CLK_FREQUENCY/PWM_FREQUENCY/2U)
/** Initial duty cycle value */
#define INIT_DUTY_VALUE        (PWM_PERIOD_COUNT * 0.0)

#define MAX_DUTY                        (PWM_PERIOD_COUNT)

/**********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - END                                                          */
/***********************************************************************************************/

/*******************************************************************************/
/* Configuration Parameters Calculations*/
/*******************************************************************************/
#define One_MHz                       (1000000U)

#define FAST_LOOP_TIME_SEC              (float)(1/(float)PWM_FREQUENCY) /* Always runs in sync with PWM */
#define SLOW_LOOP_TIME_SEC              (float)(FAST_LOOP_TIME_SEC * 100) /* 100 times slower than Fast Loop */


/***********************************************************************************************/
/* Derived Parameters - Don't Change                                                           */
/***********************************************************************************************/
#define ADC_CURRENT_SCALE             ((float)(MAX_CURRENT/(float)(2048)))
#define DCBUS_SENSE_RATIO             (float)(DCBUS_SENSE_BOTTOM_RESISTOR/(DCBUS_SENSE_BOTTOM_RESISTOR + DCBUS_SENSE_TOP_RESISTOR))
#define VOLTAGE_ADC_TO_PHY_RATIO      (float)(MAX_ADC_INPUT_VOLTAGE/(MAX_ADC_COUNT * DCBUS_SENSE_RATIO))
#define SLOW_LOOP_TIME_PWM_COUNT      (int32_t)(SLOW_LOOP_TIME_SEC / FAST_LOOP_TIME_SEC) /* 100 times slower than Fast Loop */
#define LOCK_COUNT_FOR_LOCK_TIME      (uint32_t)((float)LOCK_TIME_IN_SEC/(float)FAST_LOOP_TIME_SEC)
#define OPEN_LOOP_END_SPEED_RPS       ((float)OPEN_LOOP_END_SPEED_RPM/60)

/* Rated speed of the motor in RPM */
#define RATED_SPEED_RAD_PER_SEC_ELEC                     (float)(RATED_SPEED_RPM *(2*(float)M_PI/60) * NUM_POLE_PAIRS)
#define CLOSE_LOOP_RAMP_RATE                              (600) /* RPM per sec */
#define RAMP_RAD_PER_SEC_ELEC                             (float)(CLOSE_LOOP_RAMP_RATE * NUM_POLE_PAIRS * PI/30.0)
#define SPEED_RAMP_INC_SLOW_LOOP                          (float)(RAMP_RAD_PER_SEC_ELEC*SLOW_LOOP_TIME_SEC)

/* Open loop end speed conversions */
#define SINGLE_ELEC_ROT_RADS_PER_SEC                      ((float)((float)(2.0) * (float)M_PI))
#define END_SPEED_RADS_PER_SEC_MECH                       (float)(OPEN_LOOP_END_SPEED_RPS * SINGLE_ELEC_ROT_RADS_PER_SEC)
#define OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC             (float)(END_SPEED_RADS_PER_SEC_MECH * NUM_POLE_PAIRS)
#define OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME (float)(OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC * FAST_LOOP_TIME_SEC)
#define OPEN_LOOP_RAMPSPEED_INCREASERATE                  (float)(OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME/(OPEN_LOOP_RAMP_TIME_IN_SEC/FAST_LOOP_TIME_SEC))

/* BEMF constant */
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH       (float)((MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH/SQRT3)/1000.0)
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH   (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH / (float)(2.0 * M_PI/60.0))
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_ELEC   (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH / NUM_POLE_PAIRS)

#define ENCODER_PULSES_PER_EREV                          (uint16_t)(ENCODER_PULSES_PER_REV/NUM_POLE_PAIRS)

#define MAX_STATOR_VOLT_SQUARE              (float)(0.98 * 0.98)
#if(1U == ENABLE_FLUX_WEAKENING )
    #define MAX_SPEED_RAD_PER_SEC_ELEC              (float)(((MAX_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
#else 
    #define MAX_SPEED_RAD_PER_SEC_ELEC          (float)(((RATED_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
 #endif 
 #define POT_ADC_COUNT_FW_SPEED_RATIO        (float)(MAX_SPEED_RAD_PER_SEC_ELEC/MAX_ADC_COUNT)
#define QDEC_RC 65536u              
#define QDEC_UPPER_THRESHOLD 49151u   
#define QDEC_LOWER_THRESHOLD 16384u  
#define QDEC_OVERFLOW  (uint16_t)((QDEC_RC % ENCODER_PULSES_PER_EREV))
#define QDEC_UNDERFLOW  (uint16_t)(ENCODER_PULSES_PER_EREV - QDEC_OVERFLOW)
#endif
