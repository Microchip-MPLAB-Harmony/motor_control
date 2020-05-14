/*******************************************************************************
Derived Parameters interface file

 Company:
   Microchip Technology Inc.

 File Name:
   mc_derivedparams.h

 Summary:
   Motor control parameters interface

 Description:
   This file contains the calculated algorithm parameters
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

#ifndef _DERIVED_PARAMS_HEADER
#define _DERIVED_PARAMS_HEADER

#include "mc_userparams.h"

/***********************************************************************************************/
/* Derived Parameters - Don't Change                                                           */
/***********************************************************************************************/
#define One_MHz                       (1000000U)

#define FAST_LOOP_TIME_SEC              (float)(1/(float)PWM_FREQUENCY) /* Always runs in sync with PWM */
#define SLOW_LOOP_TIME_SEC              (float)(FAST_LOOP_TIME_SEC * 100) /* 100 times slower than Fast Loop */

#define     M_PI                                     (float)3.14159265358979323846
#define     M_PI_2                                     (float)1.57079632679489661923

#define     SQRT3                                   ((float)1.732)
#define     SQRT3_BY2                              (float)(0.866025403788)

#define     ONE_BY_SQRT3                           (float)(0.5773502691)
#define     TWO_BY_SQRT3                           (float)(1.1547005384)

/***********************************************************************************************/
/* Derived Parameters - Don't Change                                                                                 */
/***********************************************************************************************/
#define MAX_CURRENT_SQUARED                               (float)( MAX_MOTOR_CURRENT * MAX_MOTOR_CURRENT )
#define ADC_CURRENT_SCALE                                 (float)(MAX_CURRENT/(float)(((MAX_ADC_COUNT+1)/2)))
#define VOLTAGE_ADC_TO_PHY_RATIO                          (float)(MAX_ADC_INPUT_VOLTAGE/(MAX_ADC_COUNT * DCBUS_SENSE_RATIO))
#define SPEED_LOOP_PWM_COUNT                              (int32_t)(SLOW_LOOP_TIME_SEC / FAST_LOOP_TIME_SEC) /* 100 times slower than Fast Loop */
#define POSITION_LOOP_PWM_COUNT                           (uint32_t)( 100*SPEED_LOOP_PWM_COUNT )
#define LOCK_COUNT_FOR_LOCK_TIME                          (uint32_t)((float)LOCK_TIME_IN_SEC/(float)FAST_LOOP_TIME_SEC)
#define OPEN_LOOP_END_SPEED_RPS                           ((float)OPEN_LOOP_END_SPEED_RPM/60)

#define MAX_STATOR_VOLT_SQUARE                           (float)(0.98 * 0.98)
#define POT_ADC_COUNT_FW_SPEED_RATIO                     (float)(MAX_SPEED_RAD_PER_SEC_ELEC/MAX_ADC_COUNT)

<#if MCPMSMFOC_SPEED_REF_INPUT != "Potentiometer Analog Input">
#define SPEED_REF_RAD_PER_SEC_ELEC                       (float)(((SPEED_REF_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
</#if>

<#if MCPMSMFOC_POSITION_FB == "SENSORED_ENCODER">
#define QEI_VELOCITY_COUNT_PRESCALER             (float)100.0f
#define ENCODER_PULSES_PER_EREV                  ((uint16_t)((ENCODER_PULSES_PER_REV * 4)/NUM_POLE_PAIRS))
#define QEI_COUNT_TO_ELECTRICAL_ANGLE            (float)(2*M_PI/ENCODER_PULSES_PER_EREV)
#define QEI_VELOCITY_SAMPLE_FREQUENCY            (float)((float)PWM_FREQUENCY / (float)QEI_VELOCITY_COUNT_PRESCALER)
#define QEI_VELOCITY_COUNT_TO_RAD_PER_SEC        (float)(((float)QEI_VELOCITY_SAMPLE_FREQUENCY * 2.0f * M_PI )/((float)ENCODER_PULSES_PER_EREV ))

<#if __PROCESSOR?matches("PIC32M.*") == false>
#define QDEC_RC                                   65536u
#define QDEC_UPPER_THRESHOLD                      49151u
#define QDEC_LOWER_THRESHOLD                      16384u
#define QDEC_OVERFLOW                             (uint16_t)(QDEC_RC % ENCODER_PULSES_PER_EREV)
#define QDEC_UNDERFLOW                            (uint16_t)(ENCODER_PULSES_PER_EREV - QDEC_OVERFLOW)
</#if>
</#if>
/*____________________________ Rated speed of the motor in RPM___________________________________________ */
#define RATED_SPEED_RAD_PER_SEC_ELEC                      (float)(RATED_SPEED_RPM *(2*(float)M_PI/60) * NUM_POLE_PAIRS)
#define CLOSE_LOOP_RAMP_RATE                              (600) /* RPM per sec */
#define RAMP_RAD_PER_SEC_ELEC                             (float)(CLOSE_LOOP_RAMP_RATE * NUM_POLE_PAIRS * PI/30.0)
#define SPEED_RAMP_INC_SLOW_LOOP                          (float)(RAMP_RAD_PER_SEC_ELEC*SLOW_LOOP_TIME_SEC)

#define SINGLE_ELEC_ROT_RADS_PER_SEC                      ((float)((float)(2.0) * (float)M_PI))
<#if MCPMSMFOC_POSITION_FB != "SENSORED_ENCODER">
/*_____________________________ Open loop end speed conversions__________________________________________ */
#define END_SPEED_RADS_PER_SEC_MECH                       (float)(OPEN_LOOP_END_SPEED_RPS * SINGLE_ELEC_ROT_RADS_PER_SEC)
#define OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC             (float)(END_SPEED_RADS_PER_SEC_MECH * NUM_POLE_PAIRS)
#define OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME (float)(OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC * FAST_LOOP_TIME_SEC)
#define OPEN_LOOP_RAMPSPEED_INCREASERATE                  (float)(OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME/(OPEN_LOOP_RAMP_TIME_IN_SEC/FAST_LOOP_TIME_SEC))
</#if>

/*________________________________ BEMF constant___________________________________________________ */
<#if MCPMSMFOC_MOTOR_CONNECTION == "STAR">
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH       (float)((MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH/SQRT3)/1000.0)
<#else>
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH       (float)((MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH)/1000.0)
</#if>
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH   (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH / (float)(2.0 * M_PI/60.0))
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_ELEC   (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH / NUM_POLE_PAIRS)

/*_______________________________ Field weakening ___________________________________________________*/
#if(FIELD_WEAKENING == 1U)
#define MAX_SPEED_RAD_PER_SEC_ELEC                       (float)(((MAX_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
#else
#define MAX_SPEED_RAD_PER_SEC_ELEC                       (float)(((RATED_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
#endif



#endif
