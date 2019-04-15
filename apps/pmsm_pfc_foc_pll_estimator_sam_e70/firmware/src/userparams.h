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
#define OPEN_LOOP_FUNCTIONING                            (0U)  /* If enabled - Keep running in open loop */
#define TORQUE_MODE                                      (0U)  /* If enabled - torque control */
#define FIELD_WEAKENING                                  (1U)  /* If enabled - Field weakening */
#define PFC_ENABLE                                       (1U)  /* If enabled - Power Factor Correction */

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
#endif
/*****************************************************************************/
/* Control Parameters                                                        */
/*****************************************************************************/

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                (2)   /* Startup - Rotor alignment time */
#define OPEN_LOOP_END_SPEED_RPM         (RATED_SPEED_RPM*0.20) /* Startup - Control loop switches to close loop at this speed */
#define OPEN_LOOP_RAMP_TIME_IN_SEC      (2)   /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds */
#define Q_CURRENT_REF_OPENLOOP          ((float)0.2) /* Startup - Motor start to ramp up in current control mode */

/* Field weakening - Limit for -ve Idref */
#if(FIELD_WEAKENING == 1U)
#define MAX_FW_NEGATIVE_ID_REF              (float)(-1.0)
#endif

/******************************************************************************/
/* PI controllers tuning values - */
#if(MOTOR == MOTOR_1_EL5_M0400_1_24)
/********* D Control Loop Coefficients ****************************************/
#define     D_CURRCNTR_PTERM           ((float)(0.05)/MAX_MOTOR_CURRENT)
#define     D_CURRCNTR_ITERM           ((float)(0.001) /MAX_MOTOR_CURRENT)
#define     D_CURRCNTR_CTERM           ((float)(0.999)/MAX_MOTOR_CURRENT)
#define     D_CURRCNTR_OUTMAX          ((float)(0.999))

/******** Q Control Loop Coefficients ****************************************/
#define     Q_CURRCNTR_PTERM           ((float)(0.05)/MAX_MOTOR_CURRENT)
#define     Q_CURRCNTR_ITERM           ((float)(0.001) /MAX_MOTOR_CURRENT)
#define     Q_CURRCNTR_CTERM           ((float)(0.999)/MAX_MOTOR_CURRENT)
#define     Q_CURRCNTR_OUTMAX          ((float)(0.999))

/******* Velocity Control Loop Coefficients **********************************/
#define     SPEEDCNTR_PTERM            ((float)0.004)
#define     SPEEDCNTR_ITERM            ((float)0.0005)
#define     SPEEDCNTR_CTERM            ((float)(0.999))
#define     SPEEDCNTR_OUTMAX           ((float)MAX_MOTOR_CURRENT)
#endif

/******************************************************************************/
/* PI controllers tuning values for PFC  */
#if(PFC_ENABLE == 1U)
/******* PFC Voltage PI Coefficients ******************************************/
#define     PFC_VOLTAGE_PTERM           ((float)(0.8))
#define     PFC_VOLTAGE_ITERM           ((float)(0.03))
#define     PFC_VOLTAGE_CTERM           ((float)(0.1))
#define     PFC_VOLTAGE_OUTMAX          ((float)(0.65))

/******* PFC Current PI Coefficients ****************************************/
#define     PFC_CURRCNTR_PTERM           ((float)(0.08))
#define     PFC_CURRCNTR_ITERM           ((float)(0.0003))
#define     PFC_CURRCNTR_CTERM           ((float)(0.1))
#define     PFC_CURRCNTR_OUTMAX          ((float)(0.999))
#endif  // End of #if(PFC_ENABLE == 1U)

/* First order low pass Filter constants used inside the project             */
#define KFILTER_ESDQ                   (float)((float)200/(float)32767)
#define KFILTER_BEMF_AMPLITUDE         (float)((float)100/(float)32767)
#define KFILTER_VELESTIM               (float)((float)174/(float)32767)
#define KFILTER_POT                    (float)((float)50/(float)32767)

/* IIR Filter coefficient for average filter. Average AC line voltage and inductor current */
#if(PFC_ENABLE == 1U)
#define KFILTER_PFC_BUS_VOLTAGE        (float)((float)400/(float)32767)
#define B0_AVG_FILT                    (float)1.3862780245480766E-6
#define B1_AVG_FILT                    (float)2.772556049096153E-6
#define B2_AVG_FILT                    (float)1.3862780245480766E-6
#define A1_AVG_FILT                    (float)1.9976410362200994
#define A2_AVG_FILT                    (float)-0.9976465813321974
#endif  // End of #if(PFC_ENABLE == 1U)

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
#define MAX_CURRENT                                         ((float)(16.4)) /* Max current as per above calculations */
#define MAX_ADC_COUNT                                       (float)4095     /* 12-bit ADC */
#define MAX_ADC_INPUT_VOLTAGE                               (float)3.3      /* volts */

/** Dead time in micro seconds */
#define DEAD_TIME_uS                                        (1U)                /* Dead time in uS. */

#define DCBUS_SENSE_TOP_RESISTOR                            (float)285     /* 300K Ohm but due to temperature it is considered as 276K*/
#define DCBUS_SENSE_BOTTOM_RESISTOR                         (float)2.2     /* 2.2K Ohm */
#define STATOR_VOLTAGE_LIMIT                                (float)(0.98)  /* In percentage */


#define ACBUS_SENSE_TOP_RESISTOR                            (float)300     /* 300K Ohm */
#define ACBUS_SENSE_BOTTOM_RESISTOR                         (float)1.1     /* 1.1K Ohm */


/* Base Value of Voltage for the System. This value is calculated as follows:
 * With the resistor divider used to measure DCBUSSENSE signal, 3.3V
 * is generated when an input of 453V is present in DCBUS.
 */
#define PFC_FULLSCALE_VOLT	                                (float)453.0
/* Base Value of Current for the System
 * This is how this value was calculated:Diff Operational amplifier of
 * 3.1kOhm/(560ohm+39ohm) =5.175 So:
 * Vinadc = Ishunt*Rshunt*5.175. Diff opamp output is biased at 1.65V hence maximum
 * ADC input is +/-1.65V (Max ADC Input = 3.3V)
 * and with Rshunt of 0.015 Ohm
 * we have a maximum current = +/-21.3 A
 */
#define PFC_FULLSCALE_CURR	                                (float)21.3
#define PFC_DC_BUS_VOLTAGE_REF                              (float)385
#define PFC_MIN_VOLTREF                                     (float)127  /* 90Vrms = 127Volts max */

#define PFC_AC_MIN_VOLTAGE_RMS                              85
#define PFC_AC_MAX_VOLTAGE_RMS                              265

#define PFC_AC_MIN_VOLTAGE_PEAK                            (float)(PFC_AC_MIN_VOLTAGE_RMS * M_SQRT2)
#define PFC_AC_MAX_VOLTAGE_PEAK                            (float)(PFC_AC_MAX_VOLTAGE_RMS * M_SQRT2)

/* PFC Fault limits */
#define PFC_DC_BUS_OVER_VOLTAGE                             (float)420  /* Output DC Over voltage */
#define PFC_OVER_CURRENT_RMS                                (float)8   /* Average value of input current in RMS */
#define AC_VOLTAGE_OFFSET                                   (2153U)

/***********************************************************************************************/
/* Peripheral Configuration parameters */
/***********************************************************************************************/
/** PWM frequency in Hz */
#define PWM_FREQUENCY                                       (20000U)

/** PFC PWM frequency in Hz */
#if(PFC_ENABLE == 1U)
#define PFC_PWM_FREQUENCY                                   (40000U)
#define PFC_PERIOD_TIMER_TICKS                              (1875U)
#endif // End of #if(PFC_ENABLE == 1U)

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

/* Field weakening */
#if(FIELD_WEAKENING == 1U)
#define MAX_SPEED_RAD_PER_SEC_ELEC          (float)(((MAX_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
#else
#define MAX_SPEED_RAD_PER_SEC_ELEC          (float)(((RATED_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
#endif

#define MAX_STATOR_VOLT_SQUARE              (float)(0.98 * 0.98)
#define POT_ADC_COUNT_FW_SPEED_RATIO        (float)(MAX_SPEED_RAD_PER_SEC_ELEC/MAX_ADC_COUNT)


/* PFC related parameters */
#if(PFC_ENABLE == 1U)
/* Average value of AC rectified voltage */
#define AVG(x)                        ((float)(2.0*x*M_SQRT2/M_PI))
#define PFC_ADC_CURR_SCALE            ((float)(PFC_FULLSCALE_CURR/(float)2048))
#define ACBUS_SENSE_RATIO             (float)(ACBUS_SENSE_BOTTOM_RESISTOR/(ACBUS_SENSE_BOTTOM_RESISTOR + ACBUS_SENSE_TOP_RESISTOR))
#define PFC_AC_VOLTAGE_ADC_TO_PHY_RATIO  (float)(1.65/(2048 * ACBUS_SENSE_RATIO))
#define PFC_OVER_CURRENT_PEAK         (float)(PFC_OVER_CURRENT_RMS*M_SQRT2)
#define PFC_OVER_CURRENT_AVG          (float)(AVG(PFC_OVER_CURRENT_RMS))
#define PFC_AC_UNDER_VOLTAGE          (float)(AVG(85.0))  /* Average Value of input voltage- corresponding to 90Vrms */
#define PFC_AC_OVER_VOLTAGE           (float)(AVG(265.0)) /* Average Value of input voltage- corresponding to 265Vrms */
#define VAC_AVG_88V                   (float)((AVG(88)))  /* Average Value of input voltage- corresponding to 88Vrms */
#define VAC_AVG_200V                  (float)((AVG(200))) /* Average Value of input voltage- corresponding to 200Vrms */

#define MIN_PFC_DC                    (uint16_t)( 0 )
#define MAX_PFC_DC                    (uint16_t)(0.95 * PFC_PERIOD_TIMER_TICKS )

//Soft start ramp rate and ramp count
#define PFC_SOFT_START_STEP_SIZE      (1)
#define PFC_SOFT_START_RAMP_PRESCALER (1000)

/*=====PFC Voltage loop parameters=====*/

/* Voltage Loop Execution Rate = PFC Current Loop Execution Rate/ PFC_VOLTAGE_LOOP_PRESCALER */
/* Voltage Loop Execution Rate = 40000 Hz/ 10 = 4KHz */
#define PFC_VOLTAGE_LOOP_PRESCALER      10

//Current reference Calculation is shown below
// Current reference = (Voltage PI output)*(Vac Measured)*(1/Vavgsquare)*Kmul
// where Kmul is calculated such that the current reference value
// equals it maximum value at minimum line voltage
// therefore Kmul = (Current reference maximum)/((Voltage PI output max)*(Vac minimum)*(1/Vavgsquaremin))
//KMUL is used as scaling constant

#define KMUL (float)((PFC_OVER_CURRENT_PEAK*PFC_AC_UNDER_VOLTAGE*PFC_AC_UNDER_VOLTAGE)/(PFC_AC_MIN_VOLTAGE_PEAK))

#endif  // End of #if(PFC_ENABLE == 1U)


#endif
