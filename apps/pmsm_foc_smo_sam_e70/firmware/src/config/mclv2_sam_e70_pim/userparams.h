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
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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
#define MOTOR_1_HURST_DMB0224C10002                      (1U)   /* Small hurst motor */
#define MOTOR_2_HURST_DMA0204024B101                     (2U)  /* Long hurst motor */

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - START                                                        */
/***********************************************************************************************/
#define MCLV2
/***********************************************************************************************/
/* Algorithm Configuration parameters                                                          */
/***********************************************************************************************/
#define OPEN_LOOP_FUNCTIONING                            (0U)  /* If enabled - Keep running in open loop */

/***********************************************************************************************/
/* Motor Configuration Parameters */
/***********************************************************************************************/

/* Motor selection from above mentioned predefined motors */
#define MOTOR                                               (MOTOR_2_HURST_DMA0204024B101)

#if(MOTOR == MOTOR_2_HURST_DMA0204024B101)
/* Hurst motor part number - DMA0204024B101 */
#define     MOTOR_PER_PHASE_RESISTANCE                          ((float)0.285)			// Resistance in Ohms
#define     MOTOR_PER_PHASE_INDUCTANCE                          ((float)0.00032)		// Inductance in Henrys
#define     MOTOR_INERTIA                                       (float)(0.00251 * 0.007)  /* ((float)0.00251*0.007) */
#define     MOTOR_PER_PHASE_INDUCTANCE_DIV_2_PI                 ((float)(MOTOR_PER_PHASE_INDUCTANCE/(2*M_PI)))	
#define     MOTOR_BACK_EMF_CONSTANT_Vpeak_Line_Line_KRPM_MECH   (float)(7.24)				// Back EMF Constant in Vpeak/KRPM
#define     NOPOLESPAIRS                                        5
#define     NOMINAL_SPEED_RPM                                   (float)2804 // Value in RPM
#endif 

/*****************************************************************************/
/* Control Parameters                                                        */
/*****************************************************************************/

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                (2)   /* Startup - Rotor alignment time */
#define END_SPEED_RPM                   (500) /* Startup - Control loop switches to close loop at this speed */
#define RAMP_TIME_IN_SEC                (5)   /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds */
#define Q_CURRENT_REF_OPENLOOP          ((float)0.4) /* Startup - Motor start to ramp up in current control mode */


/******************************************************************************/
/* PI controllers tuning values - */
#if(MOTOR == MOTOR_1_HURST_DMB0224C10002)
/* PI controllers tuning values - */
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

#elif(MOTOR == MOTOR_2_HURST_DMA0204024B101)

/* PI controllers tuning values - */
//******** D Control Loop Coefficients *******
#define     D_CURRCNTR_PTERM                                    0.02
#define     D_CURRCNTR_ITERM                                    (0.00005)
#define     D_CURRCNTR_CTERM                                    0.5
#define     D_CURRCNTR_OUTMAX                                    0.999

//******** Q Control Loop Coefficients *******
#define     Q_CURRCNTR_PTERM                                    0.02
#define     Q_CURRCNTR_ITERM                                    (0.00005)
#define     Q_CURRCNTR_CTERM                                    0.5
#define     Q_CURRCNTR_OUTMAX                                   0.999

//*** Velocity Control Loop Coefficients *****
#define     SPEEDCNTR_PTERM                                      (0.005)
#define     SPEEDCNTR_ITERM                                      (0.0000006) 
#define     SPEEDCNTR_CTERM                                      0.5
#define     SPEEDCNTR_OUTMAX                                     MAX_MOTOR_CURRENT

#endif

/* First order low pass Filter constants used inside the project             */
#define     KFILTER_ESDQ                                        (float)((float)400/(float)32767)
#define     KFILTER_VELESTIM                                    (float)((float)(1*374)/(float)32767)
#define     INITOFFSET_TRANS_OPEN_CLSD                          (float)((float)0x2000/(float)32767)

/***********************************************************************************************/
/* Driver board configuration Parameters */
/***********************************************************************************************/
/* MCLV-2 motor control driver board 
 * Gain of opamp = 15
 * shunt resistor = 0.025 ohms
 * DC offset = 1.65V
 * max current = x
 * (x * 0.025 * 15) + 1.65V = 3.3V
 * x = 4.4Amps */

#define     MAX_BOARD_CURRENT                                   (float)(4.4)
#define     MAX_MOTOR_CURRENT                                   (float)(4.4)
#define MAX_ADC_COUNT                                       (float)4095     /* 12-bit ADC */
#define MAX_ADC_INPUT_VOLTAGE                               (float)3.3      /* volts */

#define DC_BUS_VOLTAGE                                      (float)24.0     /* Volts */
#define DCBUS_SENSE_TOP_RESISTOR                            (float)30.00    /* 30K Ohm */
#define DCBUS_SENSE_BOTTOM_RESISTOR                         (float)2.00     /* 2K Ohm */
#define STATOR_VOLTAGE_LIMIT                                (float)(0.98)   /* In percentage */

/***********************************************************************************************/
/* Peripheral Configuration parameters */
/***********************************************************************************************/
/** PWM frequency in Hz */
#define PWM_FREQ                                       (20000U)
#define SYS_CLK_FREQ                                    150000000
/**********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - END                                                          */
/***********************************************************************************************/

/*******************************************************************************/
/* Configuration Parameters Calculations*/
/*******************************************************************************/
#define One_MHz                       (1000000U)
#define     SINGLE_ELEC_ROT_RADS_PER_SEC                        (float)(2*M_PI)

#define     PBCLK_PWM                                           (SYS_CLK_FREQ/1)
#define     PWM_TS                                                 (float)(1.0/PWM_FREQ)
#define     PWM_RELOAD_EDGE                                     ((PBCLK_PWM/PWM_FREQ))
#define     PWM_RELOAD_CENTER                                   (((PBCLK_PWM/PWM_FREQ)/2))


/***********************************************************************************************/
/* Derived Parameters - Don't Change                                                           */
/***********************************************************************************************/
#define     MAX_MOTOR_CURRENT_SQUARED                           (float)((float)MAX_MOTOR_CURRENT*(float)MAX_MOTOR_CURRENT)
#define     ADC_CURRENT_SCALE                                   (float)(MAX_BOARD_CURRENT/(float)2048)
#define     MAX_PHASE_VOLTAGE                                   (float)(DC_BUS_VOLTAGE/1.732)
#define     VREF_DAC_VALUE                                      ((int)2048u)
#define     DCBUS_SENSE_RATIO                                   (float)(DCBUS_SENSE_BOTTOM_RESISTOR/(DCBUS_SENSE_BOTTOM_RESISTOR + DCBUS_SENSE_TOP_RESISTOR))
#define     VOLTAGE_ADC_TO_PHY_RATIO                            (float)(MAX_ADC_INPUT_VOLTAGE/(MAX_ADC_COUNT * DCBUS_SENSE_RATIO))

#define     MAX_DUTY                                            (PWM_RELOAD_CENTER)
#define     LOOPTIME_SEC                                        (float)0.00005           // PWM Period - 50 uSec, 20Khz PWM

#define     LOCK_COUNT_FOR_LOCK_TIME                            (unsigned int)((float)LOCK_TIME_IN_SEC/(float)LOOPTIME_SEC)
#define     RL_CNT_1S                                           0xfff //(unsigned int)(1.0 * PWM_FREQ)
#define     END_SPEED_RPS                                       ((float)END_SPEED_RPM/60)
#define     END_SPEED_RADS_PER_SEC_MECH                         (float)(END_SPEED_RPS * SINGLE_ELEC_ROT_RADS_PER_SEC)
#define     END_SPEED_RADS_PER_SEC_ELEC                         (float)(END_SPEED_RADS_PER_SEC_MECH * NOPOLESPAIRS)
#define     END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME             (float)(END_SPEED_RADS_PER_SEC_ELEC * LOOPTIME_SEC)
#define     OPENLOOP_RAMPSPEED_INCREASERATE                     (float)(END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME/(RAMP_TIME_IN_SEC/LOOPTIME_SEC))


#define     NOMINAL_SPEED_RAD_PER_SEC_ELEC                      (float)(((NOMINAL_SPEED_RPM/60)*2*M_PI)*NOPOLESPAIRS) // Value in RPM

#define     MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPM_MECH        (float)((MOTOR_BACK_EMF_CONSTANT_Vpeak_Line_Line_KRPM_MECH/1.732)/1000)
#define     MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPS_MECH        (float)(MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPM_MECH * 60)
#define     MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_MECH (float)(MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RPS_MECH/(2*M_PI))
#define     MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_ELEC (float)(MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_MECH/NOPOLESPAIRS)
#define     INVKFi_BELOW_BASE_SPEED                               (float)(1/MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_ELEC)
#define     MOTOR_TORQUE_CONSTANT                               (float)(1.5*NOPOLESPAIRS*MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_ELEC)

/*Moving Average Filter based Current Offset Calculator Parameters */
#define 	MOVING_AVG_WINDOW_SIZE                              18   // moving average window sample size is 2^18
#define     CURRENT_OFFSET_MAX                                  2200 // current offset max limit
#define     CURRENT_OFFSET_MIN                                  1900 // current offset min limit
#define     CURRENT_OFFSET_INIT                                 2048 // // as the OPAMPs are biased at VDD/2, the estimate offset value is 2048 i.e. half of 4095 which is full scale value of a 12 bit ADC. 

#define     SPEED_COMMAND_RAMP_UP_TIME                          (float)25.0 // seconds

#define     POT_ADC_COUNT_FW_SPEED_RATIO                        (float)(NOMINAL_SPEED_RAD_PER_SEC_ELEC/MAX_ADC_COUNT)


#define RL_WC_VELREF_FIL ((float)1.0)  /* cross frequency of velocity reference filter */
#define RL_WCTS_VELREF (float)(RL_WC_VELREF_FIL * PWM_TS)  /* Wc*Ts */
#define RL_1MINUS_WCTS_VELREF (float)(1.0-RL_WCTS_VELREF)  /* 1 - Wc*Ts */
#define RL_WC_CURREF_FIL ((float)1000.0)  /* cross frequency of torque reference filter */
#define RL_WCTS_CURREF (float)(RL_WC_CURREF_FIL * PWM_TS)  /* Wc*Ts */
#define RL_1MINUS_WCTS_CURREF (float)(1.0-RL_WCTS_CURREF)  /* 1 - Wc*Ts */
#define RL_1SCNT (float)(1.0 * PWM_FREQ)
#define RL_1D_1SCNT (float)(1.0 / RL_1SCNT)
#define RL_2SCNT (float)(2.0 * PWM_FREQ)
#define RL_1D_2SCNT (float)(1.0 / RL_2SCNT)
#define RL_4SCNT (float)(4.0 * PWM_FREQ)
#define RL_1D_4SCNT (float)(1.0 / RL_4SCNT)


/********************************************************************************
 ******************* SMO macro definitions ******************************* 
 ********************************************************************************/
/* User input Macro */
#define RL_BOUNDARY_I ((float)0.5)  /* boundary layer of current observer */
#define RL_M ((float)8000.0)   /* gain of current observer */
#define RL_LAMBDA ((float)-1000.0)  /* desired eigenvalue of BEMF observer */
#define RL_WC_SPEED_FIL ((float)200.0)  /* cross frequency of speed filter */
#define RL_PWM_FREQUENCY ((float)PWM_FREQ)
#define RL_RS MOTOR_PER_PHASE_RESISTANCE  /* Resistance in Ohms */
#define RL_LS MOTOR_PER_PHASE_INDUCTANCE  /* Inductance in Henrys */
#define RL_P ((float)NOPOLESPAIRS)  /* # of pole pairs */
/* The time period where BEMF observer uses speed reference;
 * After this period, estimated speed will be used by BEMF observer. */
#define RL_SPEEDREF_TIME (float)0.2  /* unit: second */
/* Constant Macro */
#define RL_2PI (float)(2.0*M_PI) 
/* ZOH discretization of SMO: intermediate macro */
#define RL_RSLST ((double)RL_RS / RL_LS / RL_PWM_FREQUENCY)
#define RL_EXP_MINUS_RSLST (float)(exp(-RL_RSLST))
/********************************************************************************/




#if 0

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

#define MAX_SPEED_RAD_PER_SEC_ELEC          (float)(((RATED_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)

#define MAX_STATOR_VOLT_SQUARE              (float)(0.98 * 0.98)
#define POT_ADC_COUNT_FW_SPEED_RATIO        (float)(MAX_SPEED_RAD_PER_SEC_ELEC/MAX_ADC_COUNT)

#endif

#endif