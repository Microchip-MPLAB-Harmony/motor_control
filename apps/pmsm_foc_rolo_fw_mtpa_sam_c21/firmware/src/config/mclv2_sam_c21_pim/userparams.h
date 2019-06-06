/*******************************************************************************
  System Definitions

  File Name:
    userparams.h

  Summary:
    Header file which defines Motor Specific and Board Specific constants

  Description:
    This file contains the motor and board specific constants. It also defines
 * switches which allows algorithm to be run in debug modes like Open Loop Mode,
 * Torque mode, etc.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef USERPARAMS_H
#define USERPARAMS_H

/*Define the Motor Type*/
#define LONG_HURST

/*Define the Board Type*/
#define MCLV2

/*Defining CTRL_PWM_1_1 sets the Control to PWM Frequency Ratio as 1:1
 Undefining CTRL_PWM_1_1 sets the Control to PWM Frequency Ration as 1:2*/
#define CTRL_PWM_1_1

/* Defining Q_AXIS_STARTUP causes the open loop startup by injecting current in Q axis
 * Undefining Q_AXIS_STARTUP cause the open loop startup by injecting current in D axis */
#define Q_AXIS_STARTUP

/*Debug Feature: Defining OPEN_LOOP_FUNCTIONING forces the algorithm to operate in Rotor Angle Open Loop mode i.e. angle reference is generated and not estimated*/
#undef OPEN_LOOP_FUNCTIONING

/*Debug Feature: Defining TORQUE_MODE forces the algorithm to operate in Torque Mode i.e. no speed control, the potentiometer input is used as torque reference*/
#undef TORQUE_MODE
    #ifdef TORQUE_MODE
    #define TORQUE_MODE_MIN_CUR_AMP 0.1
    #endif
/* Defining RAM_EXECUTE executes key motor control functions from RAM and thereby allowing faster execution at the expense of data memory.
 Please note, instruction breakpoint will not be asserted if that particular instruction is being executed from RAM
*Undefining RAM_EXECUTE executes key motor control functions from Flash and thereby reducing data memory consumption at the expense of time */
#define RAM_EXECUTE

/*Defining USE_DIVAS uses the DIVAS peripheral for division and square root operatons*/
#define USE_DIVAS

/*******************************************************************************
Macro definitions
*******************************************************************************/
#define FIELD_WEAKENING    1U

#define PWM_HPER_TICKS  ( 2400U )  /* 4000 ticks, total period 8000 ticks @48MHz -> 167us */
/* 2400 ticks , total period 4800 ticks -> 100 micro seconds */

#define HALF_HPER_TICKS  (PWM_HPER_TICKS>>1)

/* motor and application related parameters */
/* Note: only one motor has to be selected! */


#ifdef  SMALL_HURST                             /* Small Hurst motor */
#define ISOTROPIC_MOTOR                               /* Surface mounted PMSM motor */
#define RATED_FRE_HZ        (   250      )      /* maximum frequency [Hz] - 3000RPM                 */
#if(1U == FIELD_WEAKENING)
#define MAX_FRE_HZ          (   300       )     /* maximum frequency [Hz] - 3600RPM                 */
#else
#define MAX_FRE_HZ         RATED_FRE_HZ         /* maximum frequency [Hz] - 3600RPM                 */
#endif
#define MIN_FRE_HZ          (    30       )     /* minimum frequency [Hz] - 360RPM                  */
#define POLAR_COUPLES       (     5       )     /* number of polar couples                          */
#define R_STA               (   2.1       )     /* stator phase resistance [Ohm]                    */
#define L_SYN               (     0.00192 )     /* synchronous inductance 0.00192 [Hen] (note: >0!) */
#define MAX_CUR_AMP         (     2.0     )     /* peak maximum current [A]                         */
#define START_CUR_AMP       (     0.4     )     /* peak startup current [A]                         */
#define KP_V_A_Q            (     5.0     )     /* current loop proportional gain [Volt/Amp]        */
#define KI_V_AS_Q           (   1467.0    )     /* current loop integral gain [Volt/(Amp*sec)]      */
#define KP_V_A_D            (     5.0     )     /* current loop proportional gain [Volt/Amp]        */
#define KI_V_AS_D           (   1467.0    )     /* current loop integral gain [Volt/(Amp*sec)]      */
#define KP_AS_R             (  0.0016     )  	  /* speed loop proportional gain [Amp/(rad/sec)]     */
#define KI_A_R              (  0.002      )    	/* speed loop integral gain [Amp/((rad/sec)*sec)]   */
#define ACC_RPM_S           (  1000.0     )     /* acceleration ramp [rpm/s]                        */
#define DEC_RPM_S           (   500.0     )     /* acceleration ramp [rpm/s]                        */
#define STUP_ACCTIME_S      (     2.0     )     /* startup acceleration time [sec]                  */
#define CUR_RISE_T          (     1       )     /* current rising time [s] during startup alignment */
#define CUR_FALL_T          (     1.0     )     /* direct current falling time [s] after startup    */
#endif  /* ifdef SMALL_HURST */



#ifdef  LONG_HURST                         /* Long Hurst motor */
#define ISOTROPIC_MOTOR                          /* Surface mounted PMSM motor */
#define RATED_FRE_HZ    (   234    )       /* rated frequency [Hz] - 2804 RPM                       */
#if(1U == FIELD_WEAKENING)
#define MAX_FRE_HZ      (   295    )       /* maximum frequency [Hz] - 3540 RPM                     */
#else
#define MAX_FRE_HZ      RATED_FRE_HZ       /* rated frequency as maximum frequency [Hz] - 2804 RPM  */
#endif
#define MIN_FRE_HZ      (   30      )      /* minimum frequency [Hz] - 360RPM                       */
#define POLAR_COUPLES   (   5       )      /* number of polar couples                               */
#define R_STA           (   0.285   )      /* stator phase resistance [Ohm]                         */
#define L_SYN           (   0.00032 )      /* synchronous inductance 0.00192 [Hen] (note: >0!)      */
#define MAX_CUR_AMP     (   2.0     )      /* peak maximum current [A]                              */
#define START_CUR_AMP   (   0.2     )      /* peak startup current [A]                              */
#define KP_V_A_D        (   0.71    )      /* current loop proportional gain [Volt/Amp] 0.71        */
#define KI_V_AS_D       (   917.0   )      /* current loop integral gain [Volt/(Amp*sec)]917        */
#define KP_V_A_Q        (   0.71    )      /* current loop proportional gain [Volt/Amp] 0.71        */
#define KI_V_AS_Q       (   917.0   )      /* current loop integral gain [Volt/(Amp*sec)]917        */
#define KP_AS_R         (   0.003   )      /* speed loop proportional gain [Amp/(rad/sec)]          */
#define KI_A_R          (   0.004   )      /* speed loop integral gain [Amp/((rad/sec)*sec)]        */
#define ACC_RPM_S       (   1000.0  )      /* acceleration ramp [rpm/s]                             */
#define DEC_RPM_S       (   500.0   )      /* acceleration ramp [rpm/s]                             */
#define STUP_ACCTIME_S  (   2.0     )      /* startup acceleration time [sec]                       */
#define CUR_RISE_T      (   1.5     )      /* current rising time [s] during startup alignment      */
#define CUR_FALL_T      (   1.0     )      /* direct current falling time [s] after startup         */
#endif  /* ifdef LONG_HURST */

#ifdef  SAMPLE_INSET_MOTOR                         /* Inset type motor                                       */
#define NON_ISOTROPIC_MOTOR                        /* Interior burried type PMSM motor                       */
#define RATED_FRE_HZ           (   250       )     /* maximum frequency [Hz] - 3000 RPM                      */
#if(1U == FIELD_WEAKENING)
#define MAX_FRE_HZ             (   300       )     /* maximum frequency [Hz] - 3600RPM                       */
#else
#define MAX_FRE_HZ             RATED_FRE_HZ        /* maximum frequency [Hz] - 3600RPM                       */
#endif
#define MIN_FRE_HZ             (    30       )     /* minimum frequency [Hz] - 360 RPM                       */
#define POLAR_COUPLES          (     5       )     /* number of polar couples                                */
#define R_STA                  (     0.285   )     /* stator phase resistance [Ohm]                          */
#define LD_SYN                 (     0.00032 )     /* synchronous inductance 0.00192 [Hen]                   */
#define LQ_SYN                 (     0.00000 )     /* synchronous inductance 0.00192 [Hen]                   */
#define L_SYN                  (     0.00032 )     /* synchronous inductance 0.00192 [Hen]                   */
#define AIR_GAP_FLUX           (     0.8     )     /* Air gap flux in weber                                  */
#define MAX_CUR_AMP            (     2.0     )      /* peak maximum current [A]                              */
#define START_CUR_AMP          (     0.2     )      /* peak startup current [A]                              */
#define KP_V_A_D               (     0.71    )      /* current loop proportional gain [Volt/Amp] 0.71        */
#define KI_V_AS_D              (   917.0     )      /* current loop integral gain [Volt/(Amp*sec)]917        */
#define KP_V_A_Q               (     0.71    )      /* current loop proportional gain [Volt/Amp] 0.71        */
#define KI_V_AS_Q              (   917.0     )      /* current loop integral gain [Volt/(Amp*sec)]917        */
#define KP_AS_R                (     0.003   )      /* speed loop proportional gain [Amp/(rad/sec)]          */
#define KI_A_R                 (     0.004   )      /* speed loop integral gain [Amp/((rad/sec)*sec)]        */
#define ACC_RPM_S              (  1000.0     )      /* acceleration ramp [rpm/s]                             */
#define DEC_RPM_S              (   500.0     )      /* acceleration ramp [rpm/s]                             */
#define STUP_ACCTIME_S         (     2.0     )      /* startup acceleration time [sec]                       */
#define CUR_RISE_T             (     1.5     )      /* current rising time [s] during startup alignment      */
#define CUR_FALL_T             (     1       )      /* direct current falling time [s] after startup         */
#endif  /* SAMPLE_INSET_MOTOR */

#ifdef NON_ISOTROPIC_MOTOR
#define ENABLE_MTPA     1
#else 
#define ENABLE_MTPA     0
#endif

/* board related parameters */
/* Note: only one board type has to be selected! */

/* dsPICDEM MCLV-2 Board related parameters */
#ifdef MCLV2
#define CUR_SGN_REV     /* current sign is reversed!!! */
#define AD_RBA          (  465.4545 )  /*8.8A, 1A <-> 465.45 bit */
#define AD_RBV          (   77.57 )  /* 52.8V, 1V <->  77.57 bit */
#endif /* ifdef MCLV2 */

#define AD_FULLRANGE    ( 4096 )

#define MC_FREQ_HZ      ( 48000000.0f ) /* PWM peripheral frequency */

/* set the default start speed  in rpm */
#define START_SPEED_DEFAULT    (600U)

/* slower sampling frequency [Hz] (speed ramps and slower functions) */
#define SAMF_SLOW       (  100 )

#define DEADT_TICKS     (   48U )		/* 48 ticks @48MHz -> 1us */



/* phase lost alarm counters limit, filters time constant */
/* time constant is (1<<11)/Fs (=682ms @3kHz) */
#define SH_PHL_FIL                     ( 11 )
/* half second counter time */
#define PHLOST_CNT_MAX                 ( (uint16_t)SAMF_SLOW >> 1U )
#define SH_THR_PHLOST                  ( 11 )          /* threshold amplification */
#define K_THR_PHLOST   ( 1365 )        /* (1<<11)*(4/3)*(1/2), threshold is 0.5 */


/* derived and control parameters */
/* useful in duty cycle calculation */
#define HALFPER_NRM     ((uint16_t)((float32_t)PWM_HPER_TICKS * BASE_VALUE_FL / 32768.0f))
/* useful in voltages re-calculation */
#define HALFPER_A15     ((uint32_t)((float32_t)PWM_HPER_TICKS * 32768.0f))
/* 60 ticks @48MHz -> 1.25us (greater than dead times!) */
#define DMIN_TICKS      (DEADT_TICKS + 12U)
/* max delta duty */
#define DELMAX_TICKS    (PWM_HPER_TICKS - DMIN_TICKS)
/* converting DELMAX_TICKS to absolute float calculation */
#define DELMAX_TICKS_FL ((float32_t)DELMAX_TICKS )
/* max ratio of vbus which is possible to obtain with modulation */
#define K_MODLOSSES     ((DELMAX_TICKS_FL) / (float32_t)PWM_HPER_TICKS)
/* linear modulation */
#define K_AVAIL_VOL     ((int16_t)(K_MODLOSSES * (float32_t)ONEBYSQRT3))
/* over modulation */
/*#define K_AVAIL_VOL     ((int16_t)(K_MODLOSSES * TWOTHIRDS))*/
/* maximum voltage readable by the A/D converter */
#define MAX_VOL   ((float32_t)AD_FULLRANGE / (float32_t)AD_RBV)
/* maximum current readable by the A/D converter */
#define MAX_AMP   (0.5f * (float32_t)AD_FULLRANGE / (float32_t)AD_RBA)
/* maximum speed considered */
#define MAX_SPE_RS      (2.0f * FLOAT_PI * (float32_t)MAX_FRE_HZ)
/* minimum speed considered */
#define MIN_SPE_RS      (2.0f * FLOAT_PI * (float32_t)MIN_FRE_HZ)
/* no deep flux weakening: all the voltages considered are lesser than vbus */
/*#define BASE_VOLTAGE    ((float32_t)1* MAX_VOL) */
/*      deep flux weakening: bemf level can be much higher than max vbus */
#define BASE_VOLTAGE    ((float32_t)(1.0 * MAX_VOL))
/* normal condition */
#define BASE_CURRENT    ((float32_t)(0.45 * MAX_AMP))
/*#define BASE_CURRENT    ((float32_t)(0.5 * MAX_AMP))     to increase current resolution */
#define BASE_SPEED      ((float32_t)MAX_SPE_RS)
/* sampling frequency [Hz] */
#ifdef CTRL_PWM_1_1
#define SAMPLING_FREQ   ((0.5f * MC_FREQ_HZ / (float32_t)PWM_HPER_TICKS))  // 0.5f if PWM and control freq same; 0.25 if Control freq is half of PWM
#else
#define SAMPLING_FREQ   ((0.25f * MC_FREQ_HZ / (float32_t)PWM_HPER_TICKS))  // 0.5f if PWM and control freq same; 0.25 if Control freq is half of PWM
#endif
/* K Time */
#define K_TIME          SAMPLING_FREQ
/* conversion constant: voltage[internal voltage unit] = K_VOLTAGE * voltage[volt] */
#define K_VOLTAGE       (BASE_VALUE_FL / BASE_VOLTAGE)
/* conversion constant: current[internal current unit] = K_CURRENT * current[ampere] */
#define K_CURRENT       (BASE_VALUE_FL / BASE_CURRENT)
/* conversion constant: speed[internal speed unit] = K_SPEED * speed[rad/sec] */
#define K_SPEED         (BASE_VALUE_FL / BASE_SPEED)
/* a second internal speed unit is needed, to obtain angles as integral of the speed */
#define K_SPEED_L       ((uint16_t)(BASE_SPEED * (32768.0f / FLOAT_PI) / K_TIME))
/* speed[second internal speed unit] = K_SPEED_L * speed[internal speed unit] */
/* Conversion constant: Impedence[internal impedence units] = K_FLUX * Impedence [Ohm] */
#define K_IMPEDENCE                      (float)(BASE_VALUE_FL * BASE_CURRENT / BASE_VOLTAGE)

/* Conversion constant: Flux[internal flux units] = K_FLUX * Flux [Weber] */
#define K_FLUX                           (float)(BASE_VALUE_FL * BASE_SPEED / BASE_VOLTAGE)



/* due to chosen base values, the conversion constants from the A/D result to the internal
 representation are particularly simple:
    KAD_VOL =K_VOLTAGE/AD_RBV=
            =(BASE_VALUE/BASE_VOLTAGE)/AD_RBV=
            =(BASE_VALUE/(X*MAX_VOL))/AD_RBV=
            =(BASE_VALUE/(X*AD_FULLRANGE/AD_RBV))/AD_RBV=
            =BASE_VALUE/(X*AD_FULLRANGE)
    KAD_CUR =K_CURRENT/AD_RBV=
            =(BASE_VALUE/BASE_CURRENT)/AD_RBA=
            =(BASE_VALUE/(Y*MAX_AMP))/AD_RBA=
            =(BASE_VALUE/(0.5*Y*AD_FULLRANGE/AD_RBA))/AD_RBA=
            =2*BASE_VALUE/(Y*AD_FULLRANGE)
*/
/* (BASE_VALUE / (1 * AD_FULLRANGE / AD_RBV)) / AD_RBV */
#define KAD_VOL         (  4 )
#ifndef  CUR_SGN_REV
/* (2 * BASE_VALUE / (1 * AD_FULLRANGE / AD_RBA)) / AD_RBA */
#define KAD_CUR         (  8 )
#else   /* ifndef CUR_SGN_REV */
/* (2 * BASE_VALUE / (1 * AD_FULLRANGE / AD_RBA)) / AD_RBA */
#define KAD_CUR         ( -8 )
#endif  /* ifndef CUR_SGN_REV */
#define SH_KAD_CUR      (  0 )
#define SH_KAD_VOL      (  0 )

/* remeber to update the filters time constants when changing Fs */
/* rising time constant is (1<<10)/Fs (=128ms @6kHz) */
#define SH_VBMIN_INC    ( 10 )
/* falling time is (1<<(10-5))/Fs (=2ms @6kHz) */
#define SH_VBMIN_DEC    (  4 )
/* time constant is (1<<10)/Fs (=128ms @6kHz) */
#define SH_REFSPEED_FIL ( 10 )
/* time constant is (1<<10)/Fs (=128ms @6kHz) */
#define SH_MEAS_FIL     ( 10 )
/* minimum bus voltage in internal units */
#define VBUSMIN         ((int16_t)(0.2f * BASE_VALUE_FL))
/* ratio of total available voltage reserved for d axis */
#define DVOL_MARG       ((int16_t)(0.9f * BASE_VALUE_FL))
 /* max speed [rpm] */
#define MAX_SPE_RPM     ((uint16_t)(60.0f * (float32_t)MAX_FRE_HZ / (float32_t)POLAR_COUPLES))
/* min speed [rpm] */
#define MIN_SPE_RPM     ((uint16_t)(60 * MIN_FRE_HZ / POLAR_COUPLES))
/* speed[rpm] = (K_INTSPE2RPM * speed[int]) / BASE_VALUE */
#define K_INTSPE2RPM    MAX_SPE_RPM
/* speed[int] = (speed[rpm] * BASE_VALUE) / K_INTSPE2RPM */

/* floating equivalent of MAX_SPE_RPM to avoid MISRA errors */
/* max speed [rpm] */
#define MAX_SPE_RPM_FL     ((60.0f * (float32_t)MAX_FRE_HZ / (float32_t)POLAR_COUPLES))

#define MAX_SPE          BASE_VALUE_INT
#define MAX_SPE_FL       BASE_VALUE_FL
/* used in position lost alarm management */
#define MAX_SPE_PLOST   ((uint16_t)(1.25f * BASE_VALUE_FL))
#define MIN_SPE         ((uint16_t)(BASE_VALUE_FL * MIN_SPE_RS / BASE_SPEED))
/* used in position lost alarm management */
#define MIN_SPE_PLOST   ((uint16_t)(0.3f * (BASE_VALUE_FL * MIN_SPE_RS / BASE_SPEED)))
/* position lost alarm counter limit */
#define POS_LOST_CNTMX  ( 300 )
/* number of sampling periods for startup acceleration */
#define STUP_TICKS      ((int16_t)(SAMPLING_FREQ * (float32_t)STUP_ACCTIME_S))
/* delta speed for each sampling period during startup */
#define DSPEEDL_STUP    ((uint32_t)(MIN_SPE * K_SPEED_L / STUP_TICKS))
/* 333.32 micro second = 1, hence 3 for 1ms */
#define SYN_VAL1MS       ((uint16_t)3U)
/* timer for 10ms routines calling */
#define SYN_VAL10MS      ((uint16_t)(SAMPLING_FREQ / (float32_t)SAMF_SLOW))
/* 333.32 micro second = 1, hence 300 for 100ms */
#define SYN_VAL100MS     ((uint16_t)300U)
/* 333.32 micro second = 1, hence 3000 for 1s */
#define SYN_VAL1000MS    ((uint16_t)3000U)


/* from the required acceleration ramps in rpm we derive the quantities
   to add to the reference each main loop (10ms) cycle */
#define ACC_RAMP        ((int16_t)(((float32_t)ACC_RPM_S * BASE_VALUE_FL / MAX_SPE_RPM_FL) / (float32_t)SAMF_SLOW))
#define DEC_RAMP        ((int16_t)(((float32_t)DEC_RPM_S * BASE_VALUE_FL / MAX_SPE_RPM_FL) / (float32_t)SAMF_SLOW))
/* maximum current in internal current units */
#define MAX_CUR         ((int16_t)((float32_t)MAX_CUR_AMP * BASE_VALUE_FL / BASE_CURRENT))
#define MAX_CUR_SQUARED (uint32_t)(MAX_CUR*MAX_CUR)
/* startup current in internal current units */
#define START_CUR       ((int16_t)((float32_t)START_CUR_AMP * BASE_VALUE_FL / BASE_CURRENT))

/*Minimum Torque mode reference current*/
#ifdef TORQUE_MODE
#define TORQUE_MODE_MIN_CUR       ((int16_t)((float32_t)TORQUE_MODE_MIN_CUR_AMP * BASE_VALUE_FL / BASE_CURRENT))
#endif
/* amplified (to increase resolution) startup current */
#define START_CURL      ((int32_t)(START_CUR * (int32_t)BASE_VALUE_INT))
/* startup current rising ramp (amplified) */
#define CUR_RAMP_AL     ((int32_t)(START_CURL / (int32_t)((SAMPLING_FREQ * (float32_t)CUR_RISE_T))))
/* direct current falling ramp (amplified) */
#define CUR_RAMP_RU     ((int32_t)(START_CURL / (int32_t)((SAMPLING_FREQ * (float32_t)CUR_FALL_T))))
/* Q axis current loop proportional gain [int] */
#define KP_CURPIQ       ((K_VOLTAGE * (float32_t)KP_V_A_Q / K_CURRENT))
/* Q axis current loop integral gain [int] */
#define KI_CURPIQ       ((K_VOLTAGE * (float32_t)KI_V_AS_Q / (K_CURRENT * K_TIME)))

/* D axis current loop proportional gain [int] */
#define KP_CURPID       ((K_VOLTAGE * (float32_t)KP_V_A_D / K_CURRENT))
/* D axis current loop integral gain [int] */
#define KI_CURPID       ((K_VOLTAGE * (float32_t)KI_V_AS_D / (K_CURRENT * K_TIME)))

/* amplification shifts in current PI calculation */
#define SH_PROC         ( 10U )
/* amplification shifts in current PI calculation */
#define SH_INTC         (  6U )
#define KP_CUR_Q          ((int32_t)(KP_CURPIQ * (float32_t)(((uint16_t)1 << (uint16_t)SH_PROC))))
#define KI_CUR_Q          ((int32_t)(KI_CURPIQ * (float32_t)(((uint32_t)1 << (uint32_t)(SH_INTC + SH_PROC)))))
#define KP_CUR_D          ((int32_t)(KP_CURPID * (float32_t)(((uint16_t)1 << (uint16_t)SH_PROC))))
#define KI_CUR_D          ((int32_t)(KI_CURPID * (float32_t)(((uint32_t)1 << (uint32_t)(SH_INTC + SH_PROC)))))

/* speed loop proportional gain [int] */
#define KP_SPEPIF       ((K_CURRENT * (float32_t)KP_AS_R / K_SPEED))
/* speed loop integral gain [int] */
#define KI_SPEPIF       ((K_CURRENT * (float32_t)KI_A_R / (K_SPEED * K_TIME)))
/* amplification shifts in speed PI calculation */
#define SH_PROS         ( 10U )
/* amplification shifts in speed PI calculation */
#define SH_INTS         (  6U )
#define KP_SPE          ((int16_t)(KP_SPEPIF * (float32_t)(((uint16_t)1 << (uint16_t)SH_PROS))))
#define KI_SPE          ((int16_t)(KI_SPEPIF * (float32_t)(((uint32_t)1 << (uint32_t)(SH_INTS + SH_PROS)))))
/* conversion constant current[mA] = K_INTCUR2MA * current[internal current unit] */
#define K_INTCUR2MA     ((uint16_t)(BASE_VALUE_FL * 1000.0f / K_CURRENT))
/* conversion constant voltage[V/10] = K_INTVOL2DV * voltage[internal voltage unit] */
#define K_INTVOL2DV     ((uint16_t)(BASE_VALUE_FL * 10.0f / K_VOLTAGE))

/* uncomment the following macro to align speed reference filter before change */
#define SPREF_FIL_ALIGN
#define RL_500MS_10MS 50u

/*Debug Feature: Defining CURPI_TUN enables current PI tuning mode in which a step current reference is generated to observe step response of the current controller*/
#undef CURPI_TUN
/* step amplitude [A] */
#define CUR_STEP_AMP    ( 1.0 )
#define CUR_STEP_VAL    ((int16_t)(CUR_STEP_AMP * BASE_VALUE / BASE_CURRENT))
/* step duration [sec] */
#define CUR_STEP_TIM    ( 0.5 )
#define CPT_CNT_VAL     ((uint16_t)(CUR_STEP_TIM * SAMF_SLOW))

#if(1U == FIELD_WEAKENING)
#define BASE_IMPEDENCE                  (float)(BASE_VOLTAGE/BASE_CURRENT)
#define BASE_INDUCTANCE                 (float)(BASE_IMPEDENCE/BASE_SPEED)

#define PMSM_RATED_SPEED_PHYS           (float)(2.0f * FLOAT_PI * (float)RATED_FRE_HZ)
#define PMSM_RATED_SPEED_SCALED         (int16_t)( 0.5f + K_SPEED * PMSM_RATED_SPEED_PHYS)

#define PMSM_RESISTANCE_PHYS            R_STA
#define PMSM_RESISTANCE_SCALED          (int16_t)(0.5f + (BASE_VALUE_FL * R_STA / BASE_IMPEDENCE))
#define PMSM_INDUCTANCE_PHYS          L_SYN
#define PMSM_INDUCTANCE_SCALED        (int16_t)(0.5f + (BASE_VALUE_FL * L_SYN / BASE_INDUCTANCE))
#ifdef NON_ISOTROPIC_MOTOR
  #define PMSM_INDUCTANCE_D_PHYS          LD_SYN
  #define PMSM_INDUCTANCE_D_SCALED        (int16_t)(0.5f + (BASE_VALUE_FL * PMSM_INDUCTANCE_D_PHYS / BASE_INDUCTANCE))
  #define PMSM_INDUCTANCE_Q_PHYS          LQ_SYN
  #define PMSM_INDUCTANCE_Q_SCALED        (int16_t)(0.5f + (BASE_VALUE_FL * PMSM_INDUCTANCE_Q_PHYS / BASE_INDUCTANCE))
#endif

#define PMSM_MAX_NEGATIVE_IDREF_PHYS    (float)(-2.0f)
#define PMSM_MAX_NEGATIVE_IDREF_SCALED  (int16_t)(K_CURRENT * PMSM_MAX_NEGATIVE_IDREF_PHYS)
#endif
#define DECOUPLING_ENABLE   0U
#if(1U == DECOUPLING_ENABLE )
#define BASE_IMPEDENCE                  (float)(BASE_VOLTAGE/BASE_CURRENT)
#define BASE_INDUCTANCE                 (float)(BASE_IMPEDENCE/BASE_SPEED)

#define PMSM_RATED_SPEED_PHYS           (float)(2.0f * FLOAT_PI * (float)RATED_FRE_HZ)
#define PMSM_RATED_SPEED_SCALED         (int16_t)( 0.5f + K_SPEED * PMSM_RATED_SPEED_PHYS)

#define PMSM_RESISTANCE_PHYS            R_STA
#define PMSM_RESISTANCE_SCALED          (int16_t)(0.5f + (BASE_VALUE_FL * R_STA / BASE_IMPEDENCE))

#define PMSM_INDUCTANCE_PHYS            L_SYN
#define PMSM_INDUCTANCE_SCALED          (int16_t)(0.5f + (BASE_VALUE_FL * L_SYN / BASE_INDUCTANCE))

#define PMSM_MAX_NEGATIVE_IDREF_PHYS    (float)(-2.0f)
#define PMSM_MAX_NEGATIVE_IDREF_SCALED  (int16_t)(K_CURRENT * PMSM_MAX_NEGATIVE_IDREF_PHYS)
#endif
#if(1U == ENABLE_MTPA)
   #define PMSM_MTPA_CONSTANT1_PHYS         (float)(0.5 * AIR_GAP_FLUX / (PMSM_INDUCTANCE_D_PHYS - PMSM_INDUCTANCE_Q_PHYS))
   #define PMSM_MTPA_CONSTANT1_SCALED       (int32_t)(PMSM_MTPA_CONSTANT1_PHYS * K_CURRENT )
   #define PMSM_MTPA_CONSTANT2_PHYS         (float)(PMSM_MTPA_CONSTANT1_PHYS * PMSM_MTPA_CONSTANT1_PHYS )
   #define PMSM_MTPA_CONSTANT2_SCALED       (int32_t)(PMSM_MTPA_CONSTANT2_PHYS * K_CURRENT )
#endif
#endif // USERPARAMS_H
