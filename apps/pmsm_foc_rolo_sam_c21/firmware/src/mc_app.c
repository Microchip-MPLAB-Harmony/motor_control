/*******************************************************************************
 Motor Control Application Source file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_app.c

  Summary:
    This file contains all the functions related to motor control application

  Description:
    This file contains implementation of the application state machine
 
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


/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "q14_generic_mcLib.h"
#include "q14_rolo_mcLib.h"
#include "device.h"
#include "mc_app.h"
#include "definitions.h"
#include <sys/attribs.h>
#include "userparams.h"

/****************************************************************************/
/************************MISRA Violations    ********************************/
/****************************************************************************/
/* 10.1:
shift operations on signed numbers is used to benefit optimization.
arithmetic shift is used by the compiler in those cases
* 11.4, 11.6*
Register access (absolute address access) - 
required for ADC and TCC access.
*/

/*******************************************************************************
Variables
*******************************************************************************/

/***********Non safety ***********************/

/* motor run variable */
uint8_t  state_run;      
/* speed reference, derived from GUI data */
int16_t  ext_speed_ref_rpm;
/* reference speed [rpm] absolute value */
uint16_t rpm_ref_abs;   
/* alarm code ; only internal reference*/
alrm_t motor_alarm = NO_ALRM;  
/*only display variables - non safety */
/* d current in mA */
int16_t d_cur_a1000;    
/* q current in mA */
int16_t q_cur_a1000;    
/* d voltage in volt tenths */
int16_t d_vol_v10;      
/* q voltage in volt tenths */
int16_t q_vol_v10;      
/* DC link voltage in volt tenths */
uint16_t bus_vol_v10;   
/* end of display variables */
/* measured input speed */
/* measured speed [rpm] absolute value */
uint16_t spe_rpm_abs;   
/* visualization variables and
its dependent filters */
/* counter in main loop (10ms) synchronization function */
uint16_t     syn_cnt;  

uint8_t phaseindex[3] = {0,1,2};
uint8_t vis_cnt = 0;
/* Debug variables */
#ifdef  MACRO_DEBUG
uint16_t     acc_ramp;
uint16_t     dec_ramp;
#endif
#ifdef  CURPI_TUN
uint16_t
    cpt_cnt;    /* counter in tuning PI procedure */
#endif  

/*Debug variables; One time write variables */
#ifdef  MACRO_DEBUG
uint16_t
    sampling_freq, /* sampling frequency [Hz] */
    k_avail_vol,   /* constant in available output voltage vector amplitude calculation */
    max_spe_rs,    /* maximum speed [rad/sec] */
    min_spe_rs,    /* minimum speed [rad/sec] */
    max_spe_rpm,   /* maximum speed [rpm] */
    min_spe_rpm,   /* minimum speed [rpm] */
    k_speed_l,     /* constant in speed conversion */
    k_intspe2rpm,  /* constant in speed conversion */
    stup_ticks,    /* number of interrupt during startup */
    dspeedl_stup,  /* one step speed variation during startup */
    max_cur,       /* maximum current [internal current unit] */
    start_cur,     /* startup current [internal current unit] */
    cur_ramp_al,   /* current ramp during alignment */
    cur_ramp_ru;   /* direct current variation ramp during normal running */


uint32_t state_count = 1;
uint16_t state_windmilling =0;
uint16_t state_decide =0;
uint16_t state_brake =0;
uint16_t state_stopped =0;
uint16_t state_start =0;
uint16_t state_align =0;
uint16_t state_closingloop =0;
uint16_t state_closingloopwindmilling =0;
uint16_t state_closedloop =0;
int16_t min_test=MIN_SPE;
uint16_t start_count = 0;
uint16_t stop_count = 0;
int32_t delta_duty = 0;
#endif



/******************************************************************************
Safety variables
******************************************************************************/

/* measured phase currents (A/D converter values, without offset) */
int16_t cur_mea[3];     

/*PI control variables */
pi_cntrl_t
    id_pi,
    iq_pi,
    sp_pi;

int16_t
    spe_ref_sgn,  /* speed reference sign (speed_ramp routine output) */
    ref_sgn,      /* speed reference sign (speed_ramp routine input, 
                     derived from GUI data) */
    sgn_mem;      /* speed reference sign memory */
uint16_t
    spe_ref_abs ,  /* speed reference absolute value 
                     (speed_ramp routine output) [internal speed unit] */
    ref_abs,      /* speed reference absolute value 
                     (speed_ramp routine input, derived from GUI data) 
                     [internal speed unit] */
    ext_spe_ref_fil,  /*Filtered Speed reference in RPM*/    
    espabs_fil;   /* filtered estimated electrical speed absolute value 
                    [internal speed unit] */
int16_t
    vbfil,      /* filtered bus voltage value [internal voltage unit] */
    vdfil,      /* filtered direct voltage value [internal voltage unit] */
    vqfil,      /* filtered quadrature voltage value [internal voltage unit] */
    idfil,      /* filtered direct current value [internal current unit] */
    iqfil;      /* filtered quadrature current value [internal current unit] */

uint16_t  uall_cnt,  /* u-phase phase lost alarm counter */
  vall_cnt,  /* v-phase phase lost alarm counter */
  wall_cnt;  /* w-phase phase lost alarm counter */

/* status variable in motor management state machine */

run_status_t
    motor_status = STOPPED;  

stop_source_t motor_stop_source = NO_START_CMD;
/* variables used for phase lost check */
static uint32_t
  umem,      /* u-phase absolute value filter memory */
  vmem,      /* v-phase absolute value filter memory */
  wmem;      /* w-phase absolute value filter memory */
uint16_t
  ufil,      /* u-phase absolute value filter output [internal current unit] */
  vfil,      /* v-phase absolute value filter output [internal current unit] */
  wfil;      /* w-phase absolute value filter output [internal current unit] */

/* system phase [(d, q) reference system angular 
                position referred to alpha (u) axis] [internal angle unit] */
static ang_sincos_t
    sysph;      
/* vector containing the PWM timer compare values */
static int32_t dutycycle[3];  

static vec3_t
    cur3m,      /* three-phases vector of current measurement [internal current unit] */
    outv3;      /* three-phases vector of output voltage reference [internal voltage unit] */

static vec2_t
    curabm,      /* two-phases (a, b) vector of current measurement [internal current unit] */
    curabr,      /* two-phases (a, b) vector of current reference [internal current unit] */
    curdqm,      /* two-phases (d, q) vector of current measurement [internal current unit] */
    curdqr,      /* two-phases (d, q) vector of current reference [internal voltage unit] */
    outvab,      /* two-phases (a, b) vector of output voltage reference [internal voltage unit] */
    prev_outvab, /* two-phases (a, b) vector of output voltage reference of previous cycle [internal voltage unit] */
    outvdq;      /* two-phases (d, q) vector of output voltage reference [internal voltage unit] */

static uint16_t
    newsysph,    /* next cycle system phase [(d, q) reference system 
                    angular position referred to alpha (u) axis] [internal angle unit] */
    position_offset,/* angular offset to be added to system phase [internal angle unit] */
    spe_ref_fil,  /* filtered speed reference absolute value [internal speed unit] */
    elespeed_abs;  /* estimated speed absolute value [internal speed unit] */

static int16_t
    du,        /* u-phase duty cycle */
    dv,        /* v-phase duty cycle */
    dw;        /* w-phase duty cycle */

static int16_t
    elespeed,    /* (estimated or imposed) electrical speed [internal speed unit] */
    plost_cnt,   /* counter in position lost alarm management */
    vbus,        /* bus voltage value [internal voltage unit] */
    vbmin,       /* minimum bus voltage value [internal voltage unit] */
    outvmax;     /* maximum available output voltage vector 
                    amplitude value [internal voltage unit] */

static int32_t
    dcurref_l,    /* amplified direct current reference */
    vbmin_mem,    /* filter memory in vbmin lp filter */
    vbfil_mem,    /* filter memory in vbus lp filter */
    vdfil_mem,    /* filter memory in vd lp filter */
    vqfil_mem,    /* filter memory in vq lp filter */
    idfil_mem,    /* filter memory in id lp filter */
    iqfil_mem;    /* filter memory in iq lp filter */

static uint32_t
    espabs_mem,  /* filter memory in electrical speed lp filter */
    ext_spe_ref_mem,/* filter memory for mechanical speed ref LP filter */
    ampsysph,    /* system phase amplified value */
    elespeed_l,  /* electrical speed amplified value */
    spe_ref_mem; /* filter memory in reference speed lp filter */

int32_t  spe_adc_rpm_var; // Intermediate variable to convert POT  - ADC value to RPM
uint16_t spe_adc_rpm; // This register holds the Potentiometer value scaled to MAX_SPE_RPM

uint32_t  torque_adc_ref_var; // Intermediate variable to convert POT  - ADC value to Torque Ref
uint16_t  torque_adc_ref_abs; // This register holds the absolute torque ref scaled to MAX_CUR
int16_t  torque_adc_ref; // This register holds the signed torque ref scaled to MAX_CUR
/*******************************************************************************
Functions
*******************************************************************************/

#ifdef  MACRO_DEBUG
/******************************************************************************
Function:    macro_debug
Description:  debug function
Input:      nothing
Output:      nothing
Note:      only used to make it possible to visualize the values of some
        macro definitions with the debugger;
        to be removed in final release
******************************************************************************/
void macro_debug(void)
{
    k_avail_vol = K_AVAIL_VOL;
    sampling_freq = (uint16_t)SAMPLING_FREQ;
    max_spe_rs = (uint16_t)MAX_SPE_RS;
    min_spe_rs = (uint16_t)MIN_SPE_RS;
    max_spe_rpm = MAX_SPE_RPM;
    min_spe_rpm = MIN_SPE_RPM;
    k_speed_l = K_SPEED_L;
    k_intspe2rpm = K_INTSPE2RPM;
    stup_ticks = STUP_TICKS;
    dspeedl_stup = (uint16_t)DSPEEDL_STUP;
    acc_ramp = ACC_RAMP;
    dec_ramp = DEC_RAMP;
    max_cur = MAX_CUR;
    start_cur = START_CUR;
    cur_ramp_al = CUR_RAMP_AL;
    cur_ramp_ru = CUR_RAMP_RU;
    spe_ref_abs = (uint16_t)MIN_SPE;

}
#endif


/******************************************************************************
Function:       syn10ms
Description:    main loop (10ms) synchronization function
Input:          nothing (uses global variable syn_cnt)
Output:         nothing (modifies global variable syn_cnt)
Note:           to be used in a while loop; it becomes false only every 10ms,
                and in this case it resets the counter;
                the counter itself is managed by the main interrupt
******************************************************************************/
uint8_t syn10ms(void)
{
    uint8_t retval = 0;
    if(0U < syn_cnt)
    {
        retval = 1U;
    }
    else
    {
        syn_cnt = SYN_VAL10MS;
    }
    return( retval );
}

/******************************************************************************
Function:    syn1000ms
Description:  (10000ms) synchronization function
Input:      nothing (uses global variable syn1000ms_cnt)
Output:      nothing (modifies global variable syn1000ms_cnt)
Note:      to be used in a while loop; it becomes false only every 1000ms,
        and in this case it resets the counter;
        the counter itself is managed by the main interrupt
******************************************************************************/
uint8_t syn1000ms(void)
{
    uint8_t retval = 0;
    if(0U < syn1000ms_cnt)
    {
        retval = 1U;
    }
    else
    {
        syn1000ms_cnt = SYN_VAL1000MS;
    }
    return( retval );
}


/******************************************************************************
Function:    motorcontrol_vars_init
Description:  motor control variable initialization
Input:      nothing (uses some global variables)
Output:      nothing (modifies some global variables)
Note:      to be called once before starting the interrupts;
        sets some constants used by the control algo, and calls init
        functions for the observer
******************************************************************************/
void motorcontrol_vars_init(void)
{
  uint32_t u32a;

#ifdef MACRO_DEBUG
    macro_debug();
#endif  /* ifdef MACRO_DEBUG */

    /* current PI gains */
  u32a = (uint32_t)KP_CUR;
  if(32767U < u32a)
  {
    u32a = 32767;
  }
  iq_pi.kp = (int16_t)u32a;
  id_pi.kp = (int16_t)u32a;
  iq_pi.shp = (uint16_t)SH_PROC;
  id_pi.shp = (uint16_t)SH_PROC;
  u32a = KI_CUR;
  if(32767U < u32a)
  {
    u32a = 32767;
  }
  iq_pi.ki = (int16_t)u32a;
  id_pi.ki = (int16_t)u32a;
  iq_pi.shi = (uint16_t)SH_INTC;
  id_pi.shi = (uint16_t)SH_INTC;
  iq_pi.imem = 0;
  id_pi.imem = 0;
  iq_pi.hlim = 0;
  id_pi.hlim = 0;
  iq_pi.llim = 0;
  id_pi.llim = 0;

    /* speed PI gains */
  u32a = KP_SPE;
  if(32767U < u32a)
  {
    u32a = 32767;
  }
  sp_pi.kp = (int16_t)u32a;
  sp_pi.shp = (uint16_t)SH_PROS;
  u32a = KI_SPE;
  if(32767U < u32a)
  {
    u32a = 32767;
  }
  sp_pi.ki = (int16_t)u32a;
  sp_pi.shi = (uint16_t)SH_INTS;
  sp_pi.imem = 0;
  sp_pi.hlim = 0;
  sp_pi.llim = 0;

  /* */
  state_run = 0;
  ext_speed_ref_rpm = 0;

  /* observer init */
  estimation_set_base_values(SAMPLING_FREQ, BASE_SPEED, 
                             BASE_VOLTAGE, BASE_CURRENT);
  estimation_set_parameters((float32_t)R_STA, (float32_t)L_SYN);

  /* phase offset */
  position_offset = 0;
  /* safe initialzation for variables to avoid
     block level static definition  MISRA 8.9 */
  sysph.ang = 0;
  curdqm.x = 0;
  newsysph = 0;
  outvmax = 0;
  elespeed = 0;

}

/******************************************************************************
Function:    motor_stop
Description:  pwm output pins disable function
Input:      nothing
Output:      nothing (modifies some global variables)
Note:      to be called to disable pwm outputs
******************************************************************************/
void motor_stop(void)
{
    /* Rules 11.4, 11.6 violated access to register */
    int32_t dc[3];
    dc[0] =  (int32_t)HALF_HPER_TICKS;
    dc[1] =  (int32_t)HALF_HPER_TICKS;
    dc[2] =  (int32_t)HALF_HPER_TICKS;
    
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)dc[0]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)dc[1]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)dc[2]);
    
    /*Override all PWM outputs to low*/
    TCC0_PWMPatternSet((TCC_PATT_PGE0_Msk|TCC_PATT_PGE1_Msk|TCC_PATT_PGE2_Msk
            |TCC_PATT_PGE4_Msk|TCC_PATT_PGE5_Msk|TCC_PATT_PGE6_Msk),
            (TCC_PATT_PGE0(0)|TCC_PATT_PGE1(0)|TCC_PATT_PGE2(0)|TCC_PATT_PGE4(0)
            |TCC_PATT_PGE5(0)|TCC_PATT_PGE6(0)));

    
    state_run = 0;
    stop_count++;

    
}

/******************************************************************************
Function:    motor_start
Description:  pwm output pins enable function
Input:      nothing
Output:      nothing (modifies some global variables)
Note:      to be called to enable pwm outputs
******************************************************************************/
void motor_start(void)
{

    TCC0_PWMPatternSet(0x00,0x00);/*Disable PWM override*/
    state_run = 1;
    start_count++;
}

/******************************************************************************
Function:    phase_lost_filters
Description:  low-pass filtering of the absolute values of the current readings
Input:      nothing (uses as input the global variable cur3m, the current
        readings)
Output:      nothing (only modifies some global variables)
Note:      to be called in the main interrupt; the results will be evaluated
        at a slower rate.
******************************************************************************/
static inline void phase_lost_filters(void)
{

  /* lowpass filter of absolute value of u-phase current */
  uint16_t phase_a;
  uint16_t phase_b;
  uint16_t phase_c;
  if (0 >  cur3m.u)
  {
    phase_a = (uint16_t)-cur3m.u;
  }
  else
  {
    phase_a =  (uint16_t)cur3m.u;  
  }
  umem = (umem + phase_a) -ufil;
   
  ufil = (uint16_t)(umem >> (uint32_t)SH_PHL_FIL);

  /* lowpass filter of absolute value of v-phase current */
  if (0 >  cur3m.v)
  {
    phase_b = (uint16_t)-cur3m.v;
  }
  else
  {
    phase_b =  (uint16_t)cur3m.v;  
  }

  vmem = (vmem + phase_b) -vfil;
  vfil = (uint16_t) (vmem >> (uint32_t)SH_PHL_FIL);

  /* lowpass filter of absolute value of w-phase current */
  if (0 >  cur3m.w)
  {
    phase_c = (uint16_t)-cur3m.w;
  }
  else
  {
    phase_c =  (uint16_t)cur3m.w;  
  }

  wmem = (wmem + phase_c) -wfil;
  wfil = (uint16_t)(wmem >> (uint32_t)SH_PHL_FIL);

}

/******************************************************************************
Function:       phase_lost_filters_reset
Description:    reset of the filters used for the phase lost check and also
                of the related alarm counters
Input:          nothing (uses global variables)
Output:         nothing (modifies global variables)
Note:           to be called in the main interrupt, when the output frequency
                is lesser than the minimum required for the routine (ex. when
                aligning)
******************************************************************************/
static inline void phase_lost_filters_reset(void)
{
  umem = 0UL;
  ufil = 0U;
  uall_cnt = 0U;
  vmem = 0UL;
  vfil = 0U;
  vall_cnt = 0U;
  wmem = 0UL;
  wfil = 0U;
  wall_cnt = 0U;
}

/******************************************************************************
Function:     speed_ramp
Description:  calculation of internal speed reference (in internal units)
Input:        nothing
Output:       nothing
Note1:        the global variable ext_speed_ref_rpm is used as ramp input
              reference,
              the global variable spe_ref is modified as routine output
Note2:        the routine has to be called every 10ms to assure correct ramps
******************************************************************************/
 void speed_ramp(void)
{
  
     uint32_t    u32a;
    /* speed reference absolute value (actual ramp value) [internal speed unit] */
    uint16_t    ram_abs;    
    /* reference speed sign (actual ramp value) */
    int16_t     ram_sgn;    

    if(0U == start_toggle)
    {
        ext_speed_ref_rpm = 0;
        rpm_ref_abs = 0;
    }
    else
    {

        #ifdef TORQUE_MODE
        //This calculation scales Torque input from 0 - 4095 to 0 to MAX_CUR (maximum motor current)
        torque_adc_ref_var = pot_input*MAX_CUR;
        torque_adc_ref_abs = torque_adc_ref_var>>12;  //Divide by 4095 as ADC is 12 bit. 
        if(torque_adc_ref_abs < TORQUE_MODE_MIN_CUR) // Limiting minimum torque in TORQUE_MODE. 
        {
            torque_adc_ref_abs = TORQUE_MODE_MIN_CUR; 
        }
        #else
               
        //This calculation scales Speed Ref scale from 0 - 4095 to 0 to Max Speed in RPM
        spe_adc_rpm_var = pot_input*MAX_SPE_RPM;
        spe_adc_rpm = spe_adc_rpm_var>>12;  //Divide by 4095 as ADC is 12 bit. 
        rpm_ref_abs =spe_adc_rpm;
        #endif
        if(rpm_ref_abs < MIN_SPE_RPM)
        {
            rpm_ref_abs = MIN_SPE_RPM;
            ext_speed_ref_rpm = MIN_SPE_RPM;
                        
        }
        else
        {
        
        }
    
     
        if(0x0U == direction)
        {
            ext_speed_ref_rpm = ((int16_t)rpm_ref_abs);
            #ifdef TORQUE_MODE
                torque_adc_ref = ((int16_t)torque_adc_ref_abs); 
            #endif
        }
        else
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            ext_speed_ref_rpm = -((int16_t)rpm_ref_abs);
            #ifdef TORQUE_MODE
                torque_adc_ref = -((int16_t)torque_adc_ref_abs); 
            #endif
        }
    }

    if(NO_ALRM != motor_alarm)
    { 
      motor_stop();
      LED1_OC_FAULT_Set();
      motor_stop_source = ALARM_STOP ;
      spe_ref_sgn = 0;
      spe_ref_abs = 0;
    }
    #ifdef  CURPI_TUN
    else if(0 == start_toggle)
    {
        motor_stop_source = CUR_PI_NO_START_CMD ;
        motor_stop();
        cpt_cnt = 0;
    }
    else if(CPT_CNT_VAL > cpt_cnt)
    {
        
        cpt_cnt++;
        motor_start();
    }
    else
    {
        motor_stop_source = CUR_PI_END ;
        motor_stop();
    }
    return;
    #endif  /* ifdef CURPI_TUN */

    if(-((int16_t)(MIN_SPE_RPM)) >= ext_speed_ref_rpm)
    {
        u32a = (uint32_t)((uint16_t)(-ext_speed_ref_rpm) * (uint32_t)BASE_VALUE_INT);
        ref_abs = (uint16_t)(u32a / ((uint16_t)K_INTSPE2RPM));
        ref_sgn = -1;
    }
    else if(((int16_t)(MIN_SPE_RPM)) <= ext_speed_ref_rpm)
    {
        u32a = (uint32_t)((uint16_t)ext_speed_ref_rpm * (uint32_t)BASE_VALUE_INT);
        ref_abs = (uint16_t)(u32a / ((uint16_t)K_INTSPE2RPM));
        ref_sgn = 1;
    }
    else
    {
        ref_abs = 0;
        ref_sgn = 0;
    }

    if((0 == ref_sgn) || (sgn_mem != ref_sgn))
    {
        /* reset reference */
         ref_abs = 0;
        /* reset position_lost_alarm if needed */
        if(POS_LOST_ALL == motor_alarm)
        {
          motor_alarm = NO_ALRM;
        }

        /* only if motor stopped updates the sign */
        if((uint16_t)MIN_SPE > spe_ref_abs)
        {
            sgn_mem = ref_sgn;
        }
    }

    if(NO_ALRM == motor_alarm)
    {

        /* actual ramp values sampling */
        ram_sgn = spe_ref_sgn;
        ram_abs = spe_ref_abs;

        if(ref_sgn != ram_sgn)
        {
            ref_abs = 0;
        }
        else if(MAX_SPE < ref_abs)
        {
            ref_abs = MAX_SPE;
        }
        else
        {
          /* dummy else for MISRA */
        }

        /* ramp management */
        if((0U == ram_abs) && (0U == ref_abs))
        {
            motor_stop();
            motor_stop_source = NO_START_CMD;
            ram_sgn = ref_sgn;
        }
        else
        {
            if (start_toggle == 1U && !state_run)
            {
              /* if motor is not already started */
              motor_start();
              LED1_OC_FAULT_Clear();
            }
            if(STOPPED == motor_status)
            {
                ram_abs = 0;
            }
            else if((ALIGNING == motor_status) || (STARTING == motor_status))
            {
               if((uint16_t)MIN_SPE <= ref_abs)
               {
                  ram_abs = MIN_SPE;
               }
               else
               {
                  ram_abs = 0;
               }
            }
            else
            {
                if(ref_abs > ram_abs)
                {
                    ram_abs += (uint16_t)acc_ramp;
                    if(ref_abs < ram_abs)
                    {
                        ram_abs = ref_abs;
                    }
                }
                else if(ref_abs < ram_abs)
                {
                    ram_abs -= (uint16_t)dec_ramp;
                    if(ref_abs > ram_abs)
                    {
                        ram_abs = ref_abs;
                    }
                    if((uint16_t)MIN_SPE > ram_abs)
                    {
                        ram_abs = 0;
                    }
                }
                else
                {
                  /*empty else for MISRA 15.7 */
                }
            }
        }

        /* reference update */
        spe_ref_abs = ram_abs;
        spe_ref_sgn = ram_sgn;
    }
            u32a = (uint32_t)(elespeed) * K_INTSPE2RPM;
            spe_rpm_abs = (uint16_t)(u32a >> (uint32_t)SH_BASE_VALUE);
    
    /* phase lost check */
    phase_lost_check();

    return;
}

/******************************************************************************
Function:    current_measurement_management
Description:  calculation of internal current measurement values
Input:      nothing (uses A/D converter results, already corrected from the
        offsets, stored in global variables)
Output:      nothing (updates some internal variables)
Note:      calculates the third phase value from the other two samles;
        converts the A/D results in internal current units;
        calculates the two phases (a, b) vector components from the
        three phases (u, v, w) vector ones
******************************************************************************/
 void current_measurement_management(void)
{
    int32_t s32a;
    int16_t cur[3];

    /* currents */
    s32a = ((int32_t)cur_mea[0]) * ((int32_t)KAD_CUR);
    #if (0 != SH_KAD_CUR)
    cur[0] = (int16_t)(s32a >> SH_KAD_CUR);
    #else
    cur[0] = (int16_t)s32a;
    #endif
    s32a = ((int32_t)cur_mea[1]) * ((int32_t)KAD_CUR);
    #if (0 != SH_KAD_CUR)
    cur[1] = (int16_t)(s32a >> SH_KAD_CUR);
    #else
    cur[1] = (int16_t)s32a;
    #endif  /* else if(0 != SH_KAD_CUR) */
    cur[2] = -cur[0] - cur[1];
    cur3m.u = cur[0];
    cur3m.v = cur[1];
    cur3m.w = cur[2];
    library_uvw_ab(&cur3m, &curabm);


}

/******************************************************************************
Function:    pwm_modulation_reset
Description:  resets internal variables used in pwm modulation, and sets
        the unactive value into the pwm registers
Input:      nothing
Output:      nothing
******************************************************************************/
static inline void pwm_modulation_reset(void)
{
    outv3.u = 0;
    outv3.v = 0;
    outv3.w = 0;
    du = (int16_t)PWM_HPER_TICKS;
    dv = (int16_t)PWM_HPER_TICKS;
    dw = (int16_t)PWM_HPER_TICKS;
    dutycycle[0] = (int32_t)PWM_HPER_TICKS;
    dutycycle[1] = (int32_t)PWM_HPER_TICKS;
    dutycycle[2] = (int32_t)PWM_HPER_TICKS;
    /*Using register address of TCC0 */
     
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)dutycycle[0]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)dutycycle[1]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)dutycycle[2]);
        

}

/******************************************************************************
Function:    pwm_modulation
Description:  output duties calc, and three shunts current reading order
        determination
Input:      nothing (uses global variables vbus and outvab)
Output:      nothing (directly updates the duty registers)
Note:      implements a clamped modulation (min-max);
        in case of clamping (hexagonal saturation), it re-calculates
        the output voltage value to keep the saturation into account
******************************************************************************/

#ifdef RAM_EXECUTE
void  __ramfunc__ pwm_modulation(void)
#else
void pwm_modulation(void)
#endif
{
  int32_t s32a;
  /* addresses of min, med and max duty */
  int16_t *amin, *amed, *amax;  
  int16_t s16a, n_shft;

  /* reverse-Clarke transformation */
  library_ab_uvw(&outvab, &outv3);

  /* duty-cycles calculation
    the formula is duty = halfper * (vbus - vout) / vbus; 
    to avoid repeated divisions, we calculate
    the constant k = halfper * (1 << n_shft) / vbus, 
    where n_shft is found in order to have k inside the range of short integers;
    the condition is k < 32768, and this is true if HALFPER_NRM < vbus, 
    since HALFPER_NRM = PWM_HPER_TICKS * (1 << SH_BASE_VALUE) / 32768.0f */
  s16a = (int16_t)HALFPER_NRM;
  n_shft = (int16_t)SH_BASE_VALUE;
  while(s16a >= vbus)
  {
      /* compiler ensures a arithmetic shift is done in these cases.
      MISRA 10.1 violated for optimziation purpose */
      s16a >>= 1;
     n_shft--;
  }
  s32a = (int32_t)PWM_HPER_TICKS;
  s32a <<= n_shft;
        if(VBUSMIN <= vbus)
        {
          s16a = (int16_t)(s32a / vbus);
        }
        else
        {
          s16a = (int16_t)(s32a / VBUSMIN);
        }
  s32a = ((int32_t)vbus - (int32_t)outv3.u) * (int32_t)s16a;
        du = (int16_t)(s32a >> n_shft);
  s32a = ((int32_t)vbus - (int32_t)outv3.v) * (int32_t)s16a;
  dv = (int16_t)(s32a >> n_shft);
  s32a = ((int32_t)vbus - (int32_t)outv3.w) * (int32_t)s16a;
  dw = (int16_t)(s32a >> n_shft);

  /* finding duties order:
    phaseindex[0] will be the index of minimum duty,
    phaseindex[1] will be the index of intermediate duty,
    phaseindex[2] will be the index of maximum duty */
  if(du >= dv)
  {
    if(dv >= dw)
    {
      amin = &dw;
      phaseindex[0] = 2;
      amed = &dv;
      phaseindex[1] = 1;
      amax = &du;
      phaseindex[2] = 0;
    }
    else
    {
      amin = &dv;
      phaseindex[0] = 1;
      if(du >= dw)
      {
        amed = &dw;
        phaseindex[1] = 2;
        amax = &du;
        phaseindex[2] = 0;
      }
      else
      {
        amed = &du;
        phaseindex[1] = 0;
        amax = &dw;
        phaseindex[2] = 2;
      }
    }
  }
  else
  {
    if(du >= dw)
    {
      amin = &dw;
      phaseindex[0] = 2;
      amed = &du;
      phaseindex[1] = 0;
      amax = &dv;
      phaseindex[2] = 1;
    }
    else
    {
      amin = &du;
      phaseindex[0] = 0;
      if(dv >= dw)
      {
        amed = &dw;
        phaseindex[1] = 2;
        amax = &dv;
        phaseindex[2] = 1;
      }
      else
      {
        amed = &dv;
        phaseindex[1] = 1;
        amax = &dw;
        phaseindex[2] = 2;
      }
    }
  }

  /* duties differences calculation */
  (*amed) -= (*amin);
  (*amax) -= (*amin);

  /* maximum limit control (and saturation) */
  if((int16_t)DELMAX_TICKS < (*amax))
  {
    /* duties clamp */
    s32a = (int32_t)(*amed) * (int32_t)DELMAX_TICKS;

    (*amed) = (int16_t)(s32a / (*amax));

    (*amax) = (int16_t)DELMAX_TICKS;

    /* duties update */
    (*amin) = (int16_t)PWM_HPER_TICKS - (*amax);
    /* surely greater than DMIN, due to previous clamp 
    ((*amax) <= DELMAX_TICKS) */
    (*amed) += (*amin);
    (*amax) = (int16_t)PWM_HPER_TICKS;

    /* set output duties */
    dutycycle[0] = (int32_t)du;
    dutycycle[1] = (int32_t)dv;
    dutycycle[2] = (int32_t)dw;
    /*Using register address of TCC0 */  
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)dutycycle[0]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)dutycycle[1]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)dutycycle[2]);
    
    /* output voltages re-calculation 
      (necessary because a clamp has been executed);
      the formula is vout = vbus * (halfper - duty) / halfper, 
      and to avoid repeated divisions we calculate
      the constant h = vbus * (1 << n_shft) / halfper */
    /* first find the number of shifts which warrants that the 
       result of the division stays in a short integer variable */
    s32a = (int32_t)vbus * (int32_t)BASE_VALUE_INT;
    n_shft = (int16_t)SH_BASE_VALUE;
    /* HALFPER_A15 is defined as PWM_HPER_TICKS * 32768 */
    while((int32_t)HALFPER_A15 <= s32a)  
    {
      s32a >>= 1;
      n_shft--;
    }
    /* this is the division which result must stay in a short int */
    s16a = (int16_t)(s32a / (int32_t)PWM_HPER_TICKS);    
    s32a = ((int32_t)PWM_HPER_TICKS - (int32_t)du) * (int32_t)s16a;
    outv3.u = (int16_t)(s32a >> n_shft);
    s32a = ((int32_t)PWM_HPER_TICKS - (int32_t)dv) * (int32_t)s16a;
    outv3.v = (int16_t)(s32a >> n_shft);
    s32a = ((int32_t)PWM_HPER_TICKS - (int32_t)dw) * (int32_t)s16a;
    outv3.w = (int16_t)(s32a >> n_shft);

    /* update output voltage after modulation
     clamping (Clarke transformation) */
    library_uvw_ab(&outv3, &outvab);

  }
  else
  {
        /* duties update */
#if 0  /* 2-phase modulation */
    /* duties update */
    (*amin) = (int16_t)PWM_HPER_TICKS - (*amax);
    /* surely greater than DMIN, due to previous 
    comparison ((*amax) <= DELMAX_TICKS) */
    (*amed) += (*amin);
    (*amax) = (int16_t)PWM_HPER_TICKS;
#else  /* center-aligned modulation */
    (*amin) = HALF_HPER_TICKS - (*amax>>1);
    (*amax) += (*amin);
    (*amed) += (*amin);
#endif

    
    /* set output duties */
    dutycycle[0] = du;
    dutycycle[1] = dv;
    dutycycle[2] = dw;
    /*Using register address of TCC0 */
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)dutycycle[0]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)dutycycle[1]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)dutycycle[2]);

  }

}  /* end of function pwm_modulation()*/

/******************************************************************************
Function:    pos_lost_control_reset
Description:  reset of internal variables used in "pos_lost_control"
Input:      nothing
Output:      nothing
Modifies:    global variable plost_cnt
******************************************************************************/
static inline void pos_lost_control_reset(void)
{
  plost_cnt = 0;
}

/******************************************************************************
Function:    pos_lost_control
Description:  loosing of control of the phase estimation algorithm check
Input:      nothing (uses the global variable elespeed_abs)
Output:      nothing (in case produce an alarm)
Note:      compares the estimated speed with opportune limits to decide
        if the estimation algorithm behaviour is consistent
Modifies:    global alarm, if needed
******************************************************************************/
static inline void pos_lost_control(void)
{
    uint16_t u16a;

  if(POS_LOST_CNTMX <= plost_cnt)
  {
    motor_stop();
    motor_stop_source = POS_LOST_STOP;
    motor_alarm = POS_LOST_ALL;
    plost_cnt = 0;
  }
  else if(0 != spe_ref_sgn)
  {
    u16a = spe_ref_fil;
    u16a <<= 1;
    u16a += 1000U;
    if ((MIN_SPE_PLOST > elespeed_abs) ||
        (MAX_SPE_PLOST < elespeed_abs) ||
        (u16a < elespeed_abs)           )
    {
      plost_cnt++;
    }
    else if(1 < plost_cnt)
    {
      plost_cnt -= 2;
    }
    else
    {
        /*no action */
    }
  }
  else
  {
    if(MIN_SPE < elespeed_abs)
    {
      plost_cnt++;
    }
    else if(0 < plost_cnt)
    {
      plost_cnt --;
    }
    else
    {
          /* empty else no action */
    }
  }
}


/**
 * \brief check for loss of phase
 *
 * This function will check whether a phase loss obtained
 * between 2 phases
 *
 * \param[in] void
 *
 * \return void
 * Function interval: 10 milli seconds (interrupt time domain)
 *
 * checking if one of the three motor connections is broken
   Note:      this function can be called in the main loop every 10ms;
        the time constant of the filters (much higher than 10ms)
        assures than no aliasing is present;
        the working principle is the following: if one of the three
        lowpass-filtered absolute values of the currents is significantly
        lesser than the median of the three, this means that one of the three
        is missing; this is true is the filter time constant is higher
        than the sinusoid period; we retain that one of the three is
        significantly lesser than the median if it is lesser than (3/4)
        of the media (0.75)
******************************************************************************/
#define PHASE_LOSS_ERROR_LIMIT  (PHLOST_CNT_MAX)
void phase_lost_check(void)
{
  uint16_t u16a,u16u, u16v, u16w;
  uint32_t u32a;

  /* sampling of the three filtered values (no problems if an
  interrupt comes in the middle, due to filters) */
  u16u = ufil;
  u16v = vfil;
  u16w = wfil;

  /* medium value */  /* 3 times the median */
  u32a = (uint32_t)u16u + (uint32_t)u16v + (uint32_t)u16w;    
  u16a = (uint16_t)(u32a >> 2U);                   /* 3/4 of the median */
  u32a = (uint32_t)u16a * (uint32_t)K_THR_PHLOST;
  u16a = (uint16_t)(u32a >> SH_THR_PHLOST);


  /* phase u comparison */
  if(u16u < u16a)
  {
    ++uall_cnt;
    if(PHASE_LOSS_ERROR_LIMIT < uall_cnt)
    {
      motor_stop();
      motor_stop_source = PHASE_U_LOSS;
      spe_ref_sgn = 0;
      motor_status = STOPPED;

      motor_alarm = PHASE_U_LOST_ALL;
      uall_cnt = 0;
      vall_cnt = 0;
      wall_cnt = 0;
    }
  }
  else if(1U < uall_cnt)
  {
    uall_cnt -= 2U;
  }
  else
  {
    /* no action */
  }

  /* v comparison */
  if(u16v < u16a)
  {
    ++vall_cnt;
    if(PHASE_LOSS_ERROR_LIMIT < vall_cnt)
    {
      motor_stop();
      motor_stop_source = PHASE_V_LOSS;
      spe_ref_sgn = 0;
      motor_status = STOPPED;

      motor_alarm = PHASE_V_LOST_ALL;
      uall_cnt = 0;
      vall_cnt = 0;
      wall_cnt = 0;
    }
  }
  else if(1U < vall_cnt)
  {
    vall_cnt -= 2U;
  }
  else
  {
    /* no action */
  }

  /* w comparison */
  if(u16w < u16a)
  {
    ++wall_cnt;
    if(PHASE_LOSS_ERROR_LIMIT < wall_cnt)
    {
      motor_stop();
      motor_stop_source = PHASE_W_LOSS;
      spe_ref_sgn = 0;
      motor_status = STOPPED;

      motor_alarm = PHASE_W_LOST_ALL;
      uall_cnt = 0;
      vall_cnt = 0;
      wall_cnt = 0;
    }
  }
  else if(1U < wall_cnt)
  {
    wall_cnt -= 2U;
  }
  else
  {
    /* no action */
  }
}
/******************************************************************************
Function:    motorcontrol
Description:  motor control implementation
Input:      nothing (uses many global variables, mainly the current measurements)
Output:      nothing (modifies many global variables, mainly the pwm timer compare
        values)
Note:      firstly calculates the next duty cycle to be imposed using the current
        PIs with the current references coming from previous cycle;
        then manages the motor control state machine, which takes care of the
        different control phases:
          stop
          open loop startup (position and speed estimation init and adjustment)
          speed loop closing (reference system change)
          speed closed loop operations (with position and speed estimation);
        refer to the documentation for more detailed description
******************************************************************************/
#ifdef RAM_EXECUTE
void  __ramfunc__ motorcontrol(void)
#else
void motorcontrol(void)
#endif
{
  int32_t s32a;

  /* bus voltage in internal units */
  s32a = (int32_t)adc_dc_bus_voltage * KAD_VOL;
  #if(0 != SH_KAD_VOL)
  vbus = (int16_t)(s32a >> SH_KAD_VOL);
  #else   /* if(0 != SH_KAD_CUR) */
  vbus = (int16_t)s32a;
  #endif  /* else if(0 != SH_KAD_CUR) */
  /* performs motor control if needed */
  if (0U != state_run)
  {

        /* current transformations (previous angle) */
        library_ab_dq(&sysph, &curabm, &curdqm);

    
        
        #ifndef  CURPI_TUN
        /* motor control state machine */
        switch(motor_status)
        {

            case STOPPED:
                state_stopped = state_count;
                dcurref_l = 0;
                curdqr.x = 0;
                curdqr.y = 0;
                newsysph = 0;
                ampsysph = 0;
                elespeed = 0;
                elespeed_abs = 0;
                elespeed_l = 0;
                if(0 != spe_ref_sgn)
                {
                    motor_status = ALIGNING;
                    state_count++;
                }
                break;
            case ALIGNING:
                state_align = state_count;
               
                if(0 == ref_sgn)
                {
                    curdqr.x = 0;
                    curdqr.y = 0;
                    elespeed = 0;
                    elespeed_abs = 0;
                    motor_status = STOPPED;
                    

                }
                else
                {
                #ifdef Q_AXIS_STARTUP
                    
                    if(spe_ref_sgn>0)
                    {
                        /* current rising ramp */
                        if(START_CUR > curdqr.y)
                        {
                            dcurref_l += CUR_RAMP_AL;

                            curdqr.y = (int16_t)(dcurref_l >> SH_BASE_VALUE);

                        }
                        else
                        {
                            curdqr.y = START_CUR;
                            motor_status = STARTING;
                            state_count++;
                        }
                    }
                    else
                    {
                         /* current decreasing ramp */
                        if(-START_CUR < curdqr.y)
                        {
                            dcurref_l -= CUR_RAMP_AL;

                            curdqr.y = (int16_t)(dcurref_l >> SH_BASE_VALUE);

                        }
                        else
                        {
                            curdqr.y = -START_CUR;
                            motor_status = STARTING;
                            state_count++;
                        }
                    }
                #else
                    if(spe_ref_sgn>0)
                    {
                        /* current rising ramp */
                        if(START_CUR > curdqr.x)
                        {
                            dcurref_l += CUR_RAMP_AL;
  
                            curdqr.x = (int16_t)(dcurref_l >> SH_BASE_VALUE);

                        }
                        else
                        {
                            curdqr.x = START_CUR;

                            /* status change */
                            motor_status = STARTING;

                        }
                    }
                    else
                    {
                    /* current decreasing ramp */
                        if(-START_CUR < curdqr.x)
                        {
                            dcurref_l -= CUR_RAMP_AL;

                            curdqr.x = (int16_t)(dcurref_l >> SH_BASE_VALUE);

                        }
                        else
                        {
                            curdqr.x = -START_CUR;

                            /* status change */
                            motor_status = STARTING;

                        }
                    }
                #endif     
                }
                break;
            case STARTING:
                state_start = state_count;
                /* observer alignment */
                if((MIN_SPE >> 2) > elespeed_abs)
                {
                  estimation_alignment(elespeed, &outvab, &curabm);
                  

                }
                else
                {
                  position_and_speed_estimation(spe_ref_sgn, &prev_outvab, &curabm);
                }

                /* speed rising ramp */
                if(MIN_SPE > elespeed_abs)
                {
                    /* speed ramp */
                    elespeed_l += DSPEEDL_STUP;
                    elespeed_abs = (uint16_t)(elespeed_l / K_SPEED_L);
                }
                else
                {

                    elespeed_abs = MIN_SPE;
                    elespeed_l = (uint32_t)elespeed_abs * (uint32_t)K_SPEED_L;

                    /* reference speed filter init */
                    spe_ref_mem = elespeed_abs;
                    spe_ref_fil = elespeed_abs;
                    spe_ref_mem <<= SH_REFSPEED_FIL;

                    /* status change */
                #ifdef OPEN_LOOP_FUNCTIONING
                    motor_status = STARTING;
                #else
                    motor_status = CLOSINGLOOP;
                #endif
                    state_count++;
                }
                if(0 > spe_ref_sgn)
                {
                    elespeed = (int16_t)(-(int32_t)elespeed_abs);
                    ampsysph -= elespeed_l;
                }
                else if(0 < spe_ref_sgn)
                {
                    elespeed = (int16_t)elespeed_abs;
                    ampsysph += elespeed_l;
                }
                else    /* (0 == spe_ref_sgn) */
                {
                    curdqr.x =  0;
                    curdqr.y = 0 ;
                    elespeed = 0;
                    elespeed_abs = 0;
                    motor_status = STOPPED;

                }

                /* feed-forward angle management */
                newsysph = (uint16_t)(ampsysph >> (uint32_t)SH_BASE_VALUE);

                break;
            case CLOSINGLOOP:
                state_closingloop = state_count;
                /* position and speed estimation (Luenberger) */
                position_and_speed_estimation(spe_ref_sgn, &prev_outvab, &curabm);
                newsysph = position_offset + get_angular_position();
                #ifdef  SPREF_FIL_ALIGN
                elespeed = get_angular_speed();
                if(0 >= elespeed)
                {
                    spe_ref_fil = (uint16_t)(-elespeed);
                }
                else
                {
                    spe_ref_fil = (uint16_t)elespeed;
                }
                spe_ref_mem = spe_ref_fil;
                spe_ref_mem <<= SH_REFSPEED_FIL;
                #endif  /* ifdef SPREF_FIL_ALIGN */

                /* control memories calc and setting */
                /* compiler ensures a arithmetic shift is done in these cases.
                    MISRA 10.1 violated for optimziation purpose */

                outvdq.x = (int16_t)(id_pi.imem >> id_pi.shp); //Copying the integral output of D axis PI Controller to D axis output voltage
                outvdq.y = (int16_t)(iq_pi.imem >> iq_pi.shp); //Copying the integral output of Q axis PI Controller to Q axis output voltage
                library_dq_ab(&sysph, &outvdq, &outvab);
                library_dq_ab(&sysph, &curdqr, &curabr);

                /* new phase alignment */
                sysph.ang = newsysph;
                library_sincos(&sysph);

                /* control memories setting in the new reference */
                library_ab_dq(&sysph, &outvab, &outvdq);
                library_ab_dq(&sysph, &curabr, &curdqr);
                #ifdef Q_AXIS_STARTUP
                curdqr.x = 0 ; 
                #endif
                id_pi.imem = outvdq.x;
                /* d current PI integral term in new ref. frame */
                id_pi.imem <<= id_pi.shp;  
                iq_pi.imem = outvdq.y;
                /* q current PI integral term in new ref. frame */
                iq_pi.imem <<= iq_pi.shp;  
                dcurref_l = curdqr.x;
                dcurref_l <<= SH_BASE_VALUE;

                /* speed PI control memory setting */
                sp_pi.imem = curdqr.y;
                sp_pi.imem <<= sp_pi.shp;  /* speed PI integral term */
                /* position loss control reset */
                pos_lost_control_reset();

                /* status change */
                if(0 != ref_sgn)
                {
                    motor_status = RUNNING;
                    state_count++;
                }
                else
                {
                    curdqr.x =  0;
                    curdqr.y = 0;
                    elespeed =  0;
                    elespeed_abs = 0;
                    motor_status = STOPPED;

                }

                /* phase lost check filters reset */
                phase_lost_filters_reset();

                break;
                
            
            case RUNNING:
                
                state_closedloop = state_count;
               /* reference speed filter */
                spe_ref_mem += spe_ref_abs;
                spe_ref_mem -= spe_ref_fil;
                spe_ref_fil = (uint16_t)(spe_ref_mem >> SH_REFSPEED_FIL);

                /* position and speed estimation (Luenberger) */
                position_and_speed_estimation(spe_ref_sgn, &prev_outvab, &curabm);
                /* estimated position */
                newsysph = position_offset + get_angular_position();    
                /* estimated speed */
                elespeed = get_angular_speed(); 
                if(0 > elespeed)
                {
                    elespeed_abs = (uint16_t)(-elespeed);
                }
                else
                {
                    elespeed_abs = (uint16_t)elespeed;
                }

                /* speed control */
                sp_pi.hlim = MAX_CUR;
                sp_pi.llim = -MAX_CUR;
                s32a = (int32_t)spe_ref_fil;
                if(0 > spe_ref_sgn)
                {
                    s32a = -s32a;
                }
                s32a -= elespeed;
                #ifdef TORQUE_MODE
                curdqr.y = torque_adc_ref;
                #else // Speed Control
                curdqr.y = library_pi_control(s32a, &sp_pi); 
                #endif
                curdqr.x = 0;
                /* d current reduction */
                if(0 != curdqr.x)
                {
                    /* idmax calc and d reference clamping */
#ifdef USE_DIVAS
                    if(MAX_CUR > curdqr.y) 
                    {
                        s32a = (int32_t)DIVAS_SquareRoot((uint32_t)((uint32_t)(MAX_CUR_SQUARED)- (uint32_t)(curdqr.y*curdqr.y)));
                    }
                    else
                    {
                        s32a = 0;
                    }
#else
                    s32a = library_scat(MAX_CUR, curdqr.y);
#endif 
                    s32a <<= SH_BASE_VALUE;
                    if(s32a < dcurref_l)
                    {
                        dcurref_l = s32a;
                    }
                    else if(-s32a > dcurref_l)
                    {
                        dcurref_l = -s32a;
                    }
                    else
                    {
                      /* no action */
                    }

                    /* d current ramp */
                    if(CUR_RAMP_RU < dcurref_l)
                    {
                        dcurref_l -= CUR_RAMP_RU;
                    }
                    else if(-CUR_RAMP_RU > dcurref_l)
                    {
                        dcurref_l += CUR_RAMP_RU;
                    }
                    else
                    {
                        dcurref_l = 0;
                    }
                    
                    curdqr.x = (int16_t)(dcurref_l >> SH_BASE_VALUE);
                }

                /* phase lost check filters */
                phase_lost_filters();
#ifndef TORQUE_MODE
                /* position loss control */
                pos_lost_control();
#endif
                break;
            default:
              /* empty case: control should not come here */
              break;
        }/* end of switch case */

        #else   /* ifndef CURPI_TUN */
        curdqr.x = CUR_STEP_VAL;
        curdqr.y = 0;
        curabr.x = 0; // This assignment has no impact in CURPI_TUN mode. It is done to avoid build warning of unused variable in CURPI_TUN mode
        curabr.y = 0; // This assignment has no impact in CURPI_TUN mode. It is done to avoid build warning of unused variable in CURPI_TUN mode
        #endif  /* else ifndef CURPI_TUN */
        /* angle update */
        sysph.ang = newsysph;
        library_sincos(&sysph);
         /* direct current control */
        s32a =(int32_t)outvmax * DVOL_MARG;
        id_pi.hlim = (int16_t)(s32a >> SH_BASE_VALUE);      /* vd max */
        id_pi.llim = -id_pi.hlim;
        s32a = curdqr.x;
        s32a -= curdqm.x;
        outvdq.x = library_pi_control(s32a, &id_pi);

        /* quadrature current control */
#ifdef USE_DIVAS
        if(outvmax > outvdq.x)
        {
            iq_pi.hlim = (int16_t)DIVAS_SquareRoot((uint32_t)((uint32_t)(outvmax*outvmax)- (uint32_t)(outvdq.x*outvdq.x))); /* vq max */
        }
        else
        {
            iq_pi.hlim = 0;
        }
#else        
        iq_pi.hlim = library_scat(outvmax, outvdq.x);  /* vq max */
#endif
        iq_pi.llim = -iq_pi.hlim;
        s32a = curdqr.y;
        s32a -= curdqm.y;
        outvdq.y =  library_pi_control(s32a, &iq_pi);
        prev_outvab = outvab; // save the outvab from previous cycle before updating them in the current cycle
        /* voltage reverse-Park transformation */
        library_dq_ab(&sysph, &outvdq, &outvab);
               
        /* modulation (uses vbus and outvab to calculate duties, 
           and sets directly pwm registers) */


            pwm_modulation();
        /* filters */
        idfil_mem += curdqm.x;          /* direct current */
        idfil_mem -= idfil;
        idfil = (int16_t)(idfil_mem >> SH_MEAS_FIL);
        iqfil_mem += curdqm.y;          /* quadrature current */
        iqfil_mem -= iqfil;
        iqfil = (int16_t)(iqfil_mem >> SH_MEAS_FIL);
        vdfil_mem += outvdq.x;          /* direct voltage */
        vdfil_mem -= vdfil;
        vdfil = (int16_t)(vdfil_mem >> SH_MEAS_FIL);
        vqfil_mem += outvdq.y;          /* quadrature voltage */
        vqfil_mem -= vqfil;
        vqfil = (int16_t)(vqfil_mem >> SH_MEAS_FIL);
        espabs_mem += elespeed_abs;    /* estimated abs speed */
        espabs_mem -= espabs_fil;
        espabs_fil = (uint16_t)(espabs_mem >> SH_MEAS_FIL);
        
        ext_spe_ref_mem += rpm_ref_abs;    /* Filtered reference speed speed in RPM */
        ext_spe_ref_mem -= ext_spe_ref_fil;
        ext_spe_ref_fil = (uint16_t)(ext_spe_ref_mem >> SH_MEAS_FIL);

    }/* if state run is not zero */
    else
    {
        pwm_modulation_reset();
        phase_lost_filters_reset();

        sysph.ang = 0;
        sysph.sin = 0;
        sysph.cos = (int16_t)BASE_VALUE_INT;

        curdqr.x = 0;
        curdqr.y = 0;
        curdqm.x = 0;
        curdqm.y = 0;
        id_pi.imem = 0;
        iq_pi.imem = 0;
        sp_pi.imem = 0;

        outvdq.x = 0;
        outvdq.y = 0;
        outvab.x = 0;
        outvab.y = 0;


        motor_status = STOPPED;

        dcurref_l = 0;
        newsysph = 0;
        ampsysph = 0;
        elespeed_abs = 0;
        elespeed = 0;
        spe_ref_mem = 0;
        spe_ref_fil = 0;
        elespeed_l = 0;

        idfil_mem = 0;
        idfil = 0;
        iqfil_mem = 0;
        iqfil = 0;
        vdfil_mem = 0;
        vdfil = 0;
        vqfil_mem = 0;
        vqfil = 0;
        espabs_mem = 0;
        espabs_fil = 0;

    }

    /* minimum bus voltage calculation */
    s32a = vbus;
    s32a -= vbmin;
    if(0 > s32a)
    {
        s32a <<= SH_VBMIN_DEC;  /* faster decrease */
    }
    vbmin_mem += s32a;
    vbmin = (int16_t)(vbmin_mem >> SH_VBMIN_INC);

    /* available voltage calculation */
    s32a = (int32_t)vbmin * K_AVAIL_VOL;
    outvmax = (int16_t)(s32a >> SH_BASE_VALUE);

    /* filters */
    vbfil_mem += vbus;
    vbfil_mem -= vbfil;
    vbfil = (int16_t)(vbfil_mem >> 12);

    /* slower routines synchronization counter management */
    if(0U < syn_cnt)
    {
        --syn_cnt;
    }

  
}

/* EOF motor_control.c */

