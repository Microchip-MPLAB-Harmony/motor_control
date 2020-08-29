/******************************************************************************
* © 2017 Microchip Technology Inc.
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and
* intellectual property rights in the code accompanying this message and in all
* derivatives hereto.  You may use this code, and any derivatives created by
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY),
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL,
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and
* determining its suitability.  Microchip has no obligation to modify, test,
* certify, or support the code.
*
***********************************************************************************************/

#ifndef _USER_HEADER
#define _USER_HEADER

/***********************************************************************************************/
/*                    INCLUDE FILES                                                            */
/***********************************************************************************************/

/***********************************************************************************************/
/*                    DEFINITIONS                                                              */
/***********************************************************************************************/
#define MOTOR_1_CUSTOM_MOTOR                             (1U)    /* Custom Motor 1 */
#define MOTOR_2_CUSTOM_MOTOR                             (2U)    /* Custom Motor 2 */
#define MOTOR_3_HURST_DMA0204024B101                     (3U)    /* Long Hurst Motor */

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - START                                                        */
/***********************************************************************************************/

/***********************************************************************************************/
/* Algorithm Configuration parameters                                                          */
/***********************************************************************************************/

#define TORQUE_MODE                                      (0U)  /* If enabled - torque control */
                                                               /* If disabled (default) - speed control*/
/***********************************************************************************************/
/* Motor Configuration Parameters */
/***********************************************************************************************/

/* Motor selection from above mentioned predefined motors */
#define MOTOR                                               (MOTOR_3_HURST_DMA0204024B101)

#if(MOTOR == MOTOR_1_CUSTOM_MOTOR)

#define MOTOR_PER_PHASE_RESISTANCE                          ((float)0.9)
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)0.0012)
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH                ((float)3.6)
#define NUM_POLE_PAIRS                                      ((float)4)
#define RATED_SPEED_RPM                                     ((float)4000)
#define MAX_SPEED_RPM                                       ((float)4000)
#define ENCODER_PULSES_PER_REV                              ((float)1024)

#elif(MOTOR == MOTOR_2_CUSTOM_MOTOR)

#define MOTOR_PER_PHASE_RESISTANCE                          ((float)2.10)
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)0.00192)
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH                ((float)7.24)
#define NUM_POLE_PAIRS                                      ((float)5)
#define RATED_SPEED_RPM                                     ((float)2054)
#define MAX_SPEED_RPM                                       ((float)4000)

#elif(MOTOR == MOTOR_3_HURST_DMA0204024B101)
/* Hurst motor part number - DMB0224C10002 */
#define MOTOR_PER_PHASE_RESISTANCE                          ((float)0.285)
#define MOTOR_PER_PHASE_INDUCTANCE                          ((float)0.00032)
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH                ((float)13.57)
#define NUM_POLE_PAIRS                                      ((float)5)
#define RATED_SPEED_RPM                                     ((float)2804)
#define MAX_SPEED_RPM                                       ((float)3644)
#define ENCODER_PULSES_PER_REV                              ((float)1000)

#endif 

/******************************************************************************/
/* PI controllers tuning values - */
#if(MOTOR == MOTOR_1_CUSTOM_MOTOR)
/********* D Control Loop Coefficients ****************************************/
#define     D_CURRCNTR_PTERM           ((float)(0.5)/MAX_CURRENT)
#define     D_CURRCNTR_ITERM           ((float)(0.0005) /MAX_CURRENT)
#define     D_CURRCNTR_CTERM           ((float)(0.999)/MAX_CURRENT)
#define     D_CURRCNTR_OUTMAX          ((float)(0.999))

/******** Q Control Loop Coefficients ****************************************/
#define     Q_CURRCNTR_PTERM           ((float)(0.5)/MAX_CURRENT)
#define     Q_CURRCNTR_ITERM           ((float)(0.0005) /MAX_CURRENT)
#define     Q_CURRCNTR_CTERM           ((float)(0.999)/MAX_CURRENT)
#define     Q_CURRCNTR_OUTMAX          ((float)(0.999))

/******* Velocity Control Loop Coefficients **********************************/
#define     SPEEDCNTR_PTERM            ((float)0.02)
#define     SPEEDCNTR_ITERM            ((float)0.0005)
#define     SPEEDCNTR_CTERM            ((float)(0.1))
#define     SPEEDCNTR_OUTMAX           ((float)MAX_CURRENT)

#elif(MOTOR == MOTOR_2_CUSTOM_MOTOR)
///* PI controllers tuning values - */
/********* D Control Loop Coefficients ****************************************/
#define     D_CURRCNTR_PTERM           (float)(0.035798/MAX_CURRENT)
#define     D_CURRCNTR_ITERM           (float)(0.00022 /MAX_CURRENT)
#define     D_CURRCNTR_CTERM           (float)(0.999/MAX_CURRENT)
#define     D_CURRCNTR_OUTMAX          (float)(0.999)

/******** Q Control Loop Coefficients ****************************************/
#define     Q_CURRCNTR_PTERM           (float)(0.035798/MAX_CURRENT)
#define     Q_CURRCNTR_ITERM           (float)(0.00022 /MAX_CURRENT)
#define     Q_CURRCNTR_CTERM           (float)(0.999/MAX_CURRENT)
#define     Q_CURRCNTR_OUTMAX          (float)(0.999)

/******* Velocity Control Loop Coefficients **********************************/
#define     SPEEDCNTR_PTERM            (float) (0.05)
#define     SPEEDCNTR_ITERM            (float)(0.0005)
#define     SPEEDCNTR_CTERM            (float)(0.1)
#define     SPEEDCNTR_OUTMAX           (float)(MAX_CURRENT)

#elif(MOTOR == MOTOR_3_HURST_DMA0204024B101)

///* PI controllers tuning values - */

//******** D Control Loop Coefficients *******
#define     D_CURRCNTR_PTERM                         (0.1)
#define     D_CURRCNTR_ITERM                         (0.0005)
#define     D_CURRCNTR_CTERM                         (0.5)
#define     D_CURRCNTR_OUTMAX                        MAX_CURRENT

//******** Q Control Loop Coefficients *******
#define     Q_CURRCNTR_PTERM                         (0.1)
#define     Q_CURRCNTR_ITERM                         (0.0005)
#define     Q_CURRCNTR_CTERM                         (0.5)
#define     Q_CURRCNTR_OUTMAX                        MAX_CURRENT

//*** Velocity Control Loop Coefficients *****
#define     SPEEDCNTR_PTERM                            (0.01)
#define     SPEEDCNTR_ITERM                            (0.00020)
#define     SPEEDCNTR_CTERM                            0.5
#define     SPEEDCNTR_OUTMAX                           MAX_CURRENT

#endif

/* First order low pass Filter constants used inside the project  */

#define KFILTER_ESDQ                   (float)((float)200/(float)32767)
#define KFILTER_BEMF_AMPLITUDE         (float)((float)100/(float)32767)
#define KFILTER_VELESTIM               (float)((float)174/(float)32767)
#define KFILTER_POT                    (float)((float)50/(float)32767)

/***********************************************************************************************/
/* Driver board configuration Parameters */
/***********************************************************************************************/
/* MCLV-2 motor control driver board 
 * Gain of opamp = 10
 * shunt resistor = 0.025 ohms
 * DC offset = 1.65V
 * max current = x
 * (x * 0.025 * 15) + 1.65V = 3.3V
 * x = 4.4Amps */
#define MAX_CURRENT                                         ((float)(0.6)) /* Max current as per above calculations */
#define MAX_ADC_COUNT                                       (float)4095     /* 12-bit ADC */
#define MAX_ADC_INPUT_VOLTAGE                               (float)3.3      /* volts */

#define DC_BUS_VOLTAGE                                      (float)24.0     /* Volts */
#define DCBUS_SENSE_TOP_RESISTOR                            (float)30.00     /* 30K Ohm */
#define DCBUS_SENSE_BOTTOM_RESISTOR                         (float)2.00     /* 2K Ohm */
#define STATOR_VOLTAGE_LIMIT                                (float)(0.98)   /* In percentage */

/***********************************************************************************************/
/* Peripheral Configuration parameters */
/***********************************************************************************************/
/* CPU clock frequency in Hz */
#define CPU_FREQUENCY                                       (100000000U)
/** Master clock frequency in Hz */
#define MASTER_CLK_FREQUENCY                                (50000000U)
/** PWM frequency in Hz */
#define PWM_FREQUENCY                                       (20000U)
/** Phase Current Offset calibration samples */
#define CURRENTS_OFFSET_SAMPLES                             (128U)
/**********************************************************************************************/

/*******************************************************************************/
/* Configuration Parameters Calculations*/
/*******************************************************************************/
/** Period value of PWM output waveform for center aligned */
#define PWM_PERIOD_COUNT       (MASTER_CLK_FREQUENCY/PWM_FREQUENCY/2U)
/** Initial duty cycle value */
#define INIT_DUTY_VALUE        (PWM_PERIOD_COUNT * 0.0)

#define MAX_DUTY                        (PWM_PERIOD_COUNT)
#define FAST_LOOP_TIME_SEC              (float)(1/(float)PWM_FREQUENCY) /* Always runs in sync with PWM */
#define SLOW_LOOP_TIME_SEC              (float)(FAST_LOOP_TIME_SEC * 100) /* 100 times slower than Fast Loop */

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                (2)   /* Startup - Rotor alignment time */
#define OPEN_LOOP_END_SPEED_RPM         (100) /* Startup - Control loop switches to close loop at this speed */
#define OPEN_LOOP_RAMP_TIME_IN_SEC      (5)   /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds */
#define Q_CURRENT_REF_OPENLOOP          ((float)0.2) /* Startup - Motor start to ramp up in current control mode */

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - END                                                          */
/***********************************************************************************************/


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
#define CLOSE_LOOP_RAMP_RATE                              (500) /* RPM per sec */
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
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH   (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH * (float)(2.0 * M_PI/60.0))
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_ELEC   (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH * NUM_POLE_PAIRS)

#define ENCODER_PULSES_PER_EREV                          (uint16_t)(ENCODER_PULSES_PER_REV/NUM_POLE_PAIRS)

#define MAX_SPEED_RAD_PER_SEC_ELEC          (float)(((RATED_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)

#define MAX_STATOR_VOLT_SQUARE              (float)(0.98 * 0.98)
#define POT_ADC_COUNT_FW_SPEED_RATIO        (float)(MAX_SPEED_RAD_PER_SEC_ELEC/MAX_ADC_COUNT)
#define QDEC_RC 65535u              
#define QDEC_UPPER_THRESHOLD 49151u   
#define QDEC_LOWER_THRESHOLD 16384u  
#define QDEC_OVERFLOW  (uint16_t)(QDEC_RC % ENCODER_PULSES_PER_EREV) 
#define QDEC_UNDERFLOW  (uint16_t)(ENCODER_PULSES_PER_EREV - QDEC_OVERFLOW)
#endif