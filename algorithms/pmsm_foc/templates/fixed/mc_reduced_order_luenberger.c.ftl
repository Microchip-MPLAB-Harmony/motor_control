/*******************************************************************************
 Reduced Order Luenberger Observer Motor Control Library 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rolo.c

  Summary:
    Reduced Order Luenberger Observer related functions and variables
    implemented in Q14 fixed point arithmetic.

  Description:
    This file implements reduced order luenberger observer related functions
 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
#include "mc_reduced_order_luenberger.h"


/*******************************************************************************
 Private data-types  
 *******************************************************************************/

typedef struct _tmcRpo_Parameters_s
{
   float f32_sam_fre; /* sampling frequency [Hz] */
   float f32_bas_spe;/* base speed [rad/sec] */
   float f32_k_volam; /* internal conversion constant */ 
   float Rs;/* stator resistance [Ohm] */
   float Ls; /* synchronous inductance [Hen] */
   float Kgain;  /* constant in observer coefficient calculation */
   float C1;  /* constant in observer coefficient calculation */
#ifdef  CROSS_COUPLING_ENABLED
   float f32_k_speed; /* internal conversion constant */
#endif
}tmcRpo_Parameters_s;

typedef struct _tmcRpo_ObserverCoefficients_s
{
  IQ l11;   /* constant observer coefficient */
  IQ m11;   /* constant observer coefficient */
  IQ n11;  /* constant observer coefficient */
  IQ k11;   /* constant observer coefficient */
#ifdef  CROSS_COUPLING_ENABLED
  IQ hhh;   /* intermediate result in observer variable coefficient calculation */
  IQ lll;   /* intermediate result in observer variable coefficient calculation */
  IQ xxx;   /* intermediate result in observer variable coefficient calculation */
  IQ m21;   /* observer variable coefficient */
  IQ n21;   /* observer variable coefficient */
  IQ k21;   /* observer variable coefficient */
#endif  // ifdef CROSS_COUPLING_ENABLED
    
}tmcRpo_ObserverCoefficients_s;

typedef struct _tmcRpo_StateVariables_s
{
   tmcLib_Cartesian_s   obs_z;   /* observer estimated status vector */
   tmcLib_Cartesian_s   obs_e;   /* observer estimated  bemf vector */
   tmcLib_Polar_s  bemf;               /* observer estimated  bemf vector (polar coordinates) */
   uint32_t  sp_fir_acc;  /* speed fir filter accumulator */
   uint32_t  sp_iir1_mem; /* speed iir filter memory (first iir) */
   uint32_t  sp_iir2_mem; /* speed iir filter memory (second iir) */
   uint32_t  sp_iir3_mem; /* speed iir filter memory (third iir) */
   uint16_t  dph_min;     /* minimum delta phase */
         
#ifdef PH_CLAMP
  uint16_t  max_dspeed;  /* maximum speed variation in one sampling period */
#endif 
   uint16_t  flx_arg;  /* estimated permanent magnets flux position */
   uint16_t  flx_arg_mem; /* estimated permanent magnets flux position memory */
   uint16_t  dph_abs_fil; /* filtered one-step phase difference */

   uint16_t  dph_global;
   uint16_t  k_spe12;  /* internal conversion constant */
   int16_t  speed_min;  /* minimum speed [internal units] */
   int16_t  speed_est;  /* estimated speed [internal units] */   
   uint16_t  speed_abs;  /* speed absolute value */
   uint16_t  sp_fir_ind;  /* index in fir speed filter memories vector */
   uint16_t  sp_fir_vec[8]; /* speed fir filter memories vector */
   
   int16_t  ua;
   int16_t  ub;

}tmcRpo_StateVariables_s;

/*******************************************************************************
Private global variables
*******************************************************************************/
static tmcRpo_InputPorts_s     mcRpo_InputPorts_mas[1u];
static tmcRpo_Parameters_s     mcRpo_Parameters_mas[1u];
static tmcRpo_ObserverCoefficients_s   mcRpo_ObserverCoefficients_mas[1u];
static tmcRpo_StateVariables_s      mcRpo_StateVariables_mas[1u];
static tmcRpo_OutputPorts_s     mcRpo_OutputPorts_mas[1u];


/******************************************************************************
Safety variables
******************************************************************************/
tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gds = ROLO_MODULE_CONFIG;

/*******************************************************************************
Functions (private and public)
*******************************************************************************/

/* !\brief Set observer coefficients 
 * 
 * Details.
 * Set Observer coefficients
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: Angular position 
 */
void mcRpo_SetObserverCoefficients( uint8_t Id, float rsta, float lsyn)
{
    float  f32a;

    /* preliminary floating point calculations */
    mcRpo_Parameters_mas[Id].Rs = rsta;
    mcRpo_Parameters_mas[Id].Ls = lsyn;
    mcRpo_Parameters_mas[Id].Kgain = OBS_H_GAIN * mcRpo_Parameters_mas[Id].Ls * mcRpo_Parameters_mas[Id].f32_sam_fre; /* always positive */
    mcRpo_Parameters_mas[Id].C1 = mcRpo_Parameters_mas[Id].Kgain - rsta;     /* can be negative */

    /* l11 calculation  */
    f32a = OBS_C0_GAIN;
    mcLib_FloatToIQ( f32a, &mcRpo_ObserverCoefficients_mas[Id].l11 );

    /* m11 calculation  */
    f32a = mcRpo_Parameters_mas[Id].C1 * mcRpo_Parameters_mas[Id].f32_k_volam * OBS_H_GAIN;
    mcLib_FloatToIQ( f32a, &mcRpo_ObserverCoefficients_mas[Id].m11 );

    /* n11 calculation  */
    f32a = OBS_H_GAIN;
   mcLib_FloatToIQ( f32a,  &mcRpo_ObserverCoefficients_mas[Id].n11 );

    /* k11 calculation  */
    f32a = mcRpo_Parameters_mas[Id].Kgain * mcRpo_Parameters_mas[Id].f32_k_volam;
    mcLib_FloatToIQ( f32a, &mcRpo_ObserverCoefficients_mas[Id].k11 );

 #ifdef  CROSS_COUPLING_ENABLED

    /* hhh calculation */
    f32a = mcRpo_Parameters_mas[Id].C1 * mcRpo_Parameters_mas[Id].f32_k_volam;
    mcLib_FloatToIQ( f32a, &mcRpo_ObserverCoefficients_mas[Id].hhh );

    /* .lll calculation  */
    f32a = mcRpo_Parameters_mas[Id].Ls * mcRpo_Parameters_mas[Id].f32_k_volam / mcRpo_Parameters_mas[Id].f32_k_speed;
    mcLib_FloatToIQ( f32a, &mcRpo_ObserverCoefficients_mas[Id].lll );

    /* xxx calculation  */
    f32a = (1.0f / (mcRpo_Parameters_mas[Id].f32_sam_fre * mcRpo_Parameters_mas[Id].f32_k_speed));
    mcLib_FloatToIQ( f32a, &mcRpo_ObserverCoefficients_mas[Id].xxx );

 #endif  // ifdef CROSS_COUPLING_ENABLED

 /* speed estimation init */
 #ifdef PH_CLAMP
    mcRpo_StateVariables_mas[Id].max_dspeed = mcRpo_StateVariables_mas[Id].max_dspeed;
 #endif 
 
}

/* !\brief Estimate observer coefficients 
 * 
 * Details.
 * Estimate Observer coefficients 
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: Angular position 
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcRpo_EstimateObserverCoefficients( uint8_t Id )
#else
void mcRpo_EstimateObserverCoefficients(  uint8_t Id )
#endif
{
 #ifdef  CROSS_COUPLING_ENABLED
    int32_t s32a;
    int16_t spabs;

    /* speed clamp */
    /* 10.1 violation */
    if(mcRpo_StateVariables_mas[Id].speed_min > (int16_t)mcRpo_StateVariables_mas[Id].speed_abs)
    {
        spabs = mcRpo_StateVariables_mas[Id].speed_min;
    }
    else
    {
        spabs = mcRpo_StateVariables_mas[Id].speed_abs;
    }

    /* variable coefficient (mcRpo_ObserverCoefficients_mds.n21) (mcRpo_ObserverCoefficients_mds.xxx.val is positive) */
    s32a = ((int32_t)(mcRpo_ObserverCoefficients_mas[Id].xxx.val)) * ((int32_t)spabs);
    mcRpo_ObserverCoefficients_mas[Id].n21.shr = mcRpo_ObserverCoefficients_mas[Id].xxx.shr;
    while((32767 < s32a) || (OBS_MAXSHIFTS < mcRpo_ObserverCoefficients_mas[Id].n21.shr))
    {
        s32a >>= 1;
        mcRpo_ObserverCoefficients_mas[Id].n21.shr--;   // if negative algo. will fail
    }
    mcRpo_ObserverCoefficients_mas[Id].n21.val = (int16_t)s32a;
    while((0 == (mcRpo_ObserverCoefficients_mas[Id].n21.val & 0x0001)) && (0u < mcRpo_ObserverCoefficients_mas[Id].n21.shr))
    {
        mcRpo_ObserverCoefficients_mas[Id].n21.val >>= 1;
        mcRpo_ObserverCoefficients_mas[Id].n21.shr--;
    }

    /* variable coefficient (mcRpo_ObserverCoefficients_mds.m21) (mcRpo_ObserverCoefficients_mds.hhh.val can be negative) */
    s32a = ((int32_t)(mcRpo_ObserverCoefficients_mas[Id].hhh.val)) * ((int32_t)(mcRpo_ObserverCoefficients_mas[Id].n21.val));
    mcRpo_ObserverCoefficients_mas[Id].m21.shr = mcRpo_ObserverCoefficients_mas[Id].n21.shr + mcRpo_ObserverCoefficients_mas[Id].hhh.shr;
    while(((32767 < s32a) || (-32767 > s32a)) || (OBS_MAXSHIFTS < mcRpo_ObserverCoefficients_mas[Id].m21.shr))
    {
        s32a >>= 1;
        mcRpo_ObserverCoefficients_mas[Id].m21.shr--;   // if negative algo. will fail
    }
    mcRpo_ObserverCoefficients_mas[Id].m21.val = (int16_t)s32a;
    while((0 == (mcRpo_ObserverCoefficients_mas[Id].m21.val & 0x0001)) && (0u < mcRpo_ObserverCoefficients_mas[Id].m21.shr))
    {
        mcRpo_ObserverCoefficients_mas[Id].m21.val >>= 1;
        mcRpo_ObserverCoefficients_mas[Id].m21.shr--;
    }

    /* variable coefficient (mcRpo_ObserverCoefficients_mds.k21) (mcRpo_ObserverCoefficients_mds.lll.val is positive) */
    s32a = ((int32_t)(mcRpo_ObserverCoefficients_mas[Id].lll.val)) * ((int32_t)spabs);
    mcRpo_ObserverCoefficients_mas[Id].k21.shr = mcRpo_ObserverCoefficients_mas[Id].lll.shr;
    while((32767 < s32a) || (OBS_MAXSHIFTS < mcRpo_ObserverCoefficients_mas[Id].k21.shr))
    {
        s32a >>= 1;
        mcRpo_ObserverCoefficients_mas[Id].k21.shr--;   /* if negative algo. will fail */
    }
    mcRpo_ObserverCoefficients_mas[Id].k21.val = (int16_t)s32a;
    while((0 == (mcRpo_ObserverCoefficients_mas[Id].k21.val & 0x0001)) && (0u < mcRpo_ObserverCoefficients_mas[Id].k21.shr))
    {
        mcRpo_ObserverCoefficients_mas[Id].k21.val >>= 1;
        mcRpo_ObserverCoefficients_mas[Id].k21.shr--;
    }

    /* coefficients sign management */
    if(0 > ( *mcRpo_InputPorts_mas[Id].rotSign ))
    {
        mcRpo_ObserverCoefficients_mas[Id].n21.val = -mcRpo_ObserverCoefficients_mas[Id].n21.val;
        mcRpo_ObserverCoefficients_mas[Id].m21.val = -mcRpo_ObserverCoefficients_mas[Id].m21.val;
        mcRpo_ObserverCoefficients_mas[Id].k21.val = -mcRpo_ObserverCoefficients_mas[Id].k21.val;
    }

 #endif  /* ifdef CROSS_COUPLING_ENABLED */
}

/* !\brief Arithmetic shift 
 * 
 * Details.
 * Arithmetic shift down, which goes to zero also with negative
 * numbers, but keeps output >=1 (<=-1) if the input is >1 (<-1)
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: Angular position 
 */
#ifdef RAM_EXECUTE
int32_t __ramfunc__ shfdw2(int32_t a, uint16_t s)
#else
int32_t shfdw2(int32_t a, uint16_t s)
#endif
{
    int32_t r;

    if((-2 < a) && (2 > a))
    {
         r = 0;
    }
    else
    {
        r = a >> s;
        if(0 == r)
        {
            r = 1;
        }
    }
    return (r);
}


/* !\brief Multiply and  shift 
 * 
 * Details.
 * Multiply and shift
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: Angular position 
 */
static inline int32_t mulshr(int16_t a, const IQ *c)
{
    int32_t r;

    r = ((int32_t)a) * ((int32_t)(c->val));
    r >>= (c->shr);

    return (r);
}



/* !\brief Execute Luenberger Observer
 * 
 * Details.
 * Execute Luenberger Observer
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: Angular position 
 */

#ifdef RAM_EXECUTE
void __ramfunc__ mcRpo_LuenbergerObserver( uint8_t Id )
#else
void mcRpo_LuenbergerObserver(  uint8_t Id )
#endif
{
    int32_t s32x; 
    int32_t s32y;
 #ifdef AMP_CLAMP
    int32_t luzx; 
    int32_t luzy;
 #endif 

    tmcLib_Cartesian_s * Z;
    tmcLib_Cartesian_s * E;

    Z = &mcRpo_StateVariables_mas[Id].obs_z;
    E = &mcRpo_StateVariables_mas[Id].obs_e;

    s32x =  mulshr( Z->x, &mcRpo_ObserverCoefficients_mas[Id].l11);
    s32x +=  mulshr(( *mcRpo_InputPorts_mas[Id].ia ), &mcRpo_ObserverCoefficients_mas[Id].m11);
 #ifdef  CROSS_COUPLING_ENABLED
    s32x -= mulshr(( *mcRpo_InputPorts_mas[Id].ib ), &mcRpo_ObserverCoefficients_mas[Id].m21); 
 #endif  // ifdef CROSS_COUPLING_ENABLED
    s32x +=  mulshr((mcRpo_StateVariables_mas[Id].ua), &mcRpo_ObserverCoefficients_mas[Id].n11);
 #ifdef  CROSS_COUPLING_ENABLED
    s32x -= mulshr((mcRpo_StateVariables_mas[Id].ub), &mcRpo_ObserverCoefficients_mas[Id].n21); 
 #endif  // ifdef CROSS_COUPLING_ENABLED

    s32y = mulshr(Z->y, &mcRpo_ObserverCoefficients_mas[Id].l11); 
 #ifdef  CROSS_COUPLING_ENABLED
    s32y += mulshr(( *mcRpo_InputPorts_mas[Id].ia ), &mcRpo_ObserverCoefficients_mas[Id].m21);
 #endif  // ifdef CROSS_COUPLING_ENABLED
    s32y += mulshr(( *mcRpo_InputPorts_mas[Id].ib ), &mcRpo_ObserverCoefficients_mas[Id].m11);
 #ifdef  CROSS_COUPLING_ENABLED
    s32y += mulshr((mcRpo_StateVariables_mas[Id].ua), &mcRpo_ObserverCoefficients_mas[Id].n21);
 #endif  // ifdef CROSS_COUPLING_ENABLED
    s32y += mulshr((mcRpo_StateVariables_mas[Id].ub), &mcRpo_ObserverCoefficients_mas[Id].n11); 

 #ifdef AMP_CLAMP
    /* during startup transitory from zero speed, observer status could diverge;
       this clamping keeps the vector amplitude clamped, without changing its argument */
    luzx = s32x;
    luzy = s32y;
    while((-32767 > luzx) || (32767 < luzx) || (-32767 > luzy) || (32767 < luzy))
    {
     luzx = mcLib_RightShift(luzx, 1);
     luzy = mcLib_RightShift(luzy, 1);
     debug_cnt1++;
    }
    Z->x = (int16_t)luzx;
    Z->y = (int16_t)luzy;
 #else /* ifdef AMP_CLAMP */
    Z->x = (int16_t)s32x;
    Z->y = (int16_t)s32y;
 #endif /* ifdef AMP_CLAMP */

    s32x -= mulshr(( *mcRpo_InputPorts_mas[Id].ia ), &mcRpo_ObserverCoefficients_mas[Id].k11);
 #ifdef  CROSS_COUPLING_ENABLED
    s32x += mulshr(( *mcRpo_InputPorts_mas[Id].ib ), &mcRpo_ObserverCoefficients_mas[Id].k21); 
 #endif  // ifdef CROSS_COUPLING_ENABLED

 #ifdef  CROSS_COUPLING_ENABLED
    s32y -= mulshr(( *mcRpo_InputPorts_mas[Id].ia ), &mcRpo_ObserverCoefficients_mas[Id].k21);
 #endif  // ifdef CROSS_COUPLING_ENABLED
    s32y -=  mulshr(( *mcRpo_InputPorts_mas[Id].ib ), &mcRpo_ObserverCoefficients_mas[Id].k11); 

 #ifdef AMP_CLAMP
    while((-32767 > s32x) || (32767 < s32x) || (-32767 > s32y) || (32767 < s32y))
    {
     s32x = mcLib_RightShift(s32x, 1);
     s32y = mcLib_RightShift(s32y, 1);
     debug_cnt2++;
    }
 #endif // ifdef AMP_CLAMP

    E->x = (int16_t)s32x;
    E->y = (int16_t)s32y;

    mcRpo_StateVariables_mas[Id].ua = *mcRpo_InputPorts_mas[Id].ua;
    mcRpo_StateVariables_mas[Id].ub = *mcRpo_InputPorts_mas[Id].ub;
  
}


/* !\brief Speed dependent angle compensation
 * 
 * Details.
 * This function performs speed dependent compensation for the time elapsed between
 *  input signals reading and the PWM application
 * 
 * @param[in]: 
 * @param[in/out]: 
 * @param[out]: 
 * @return: None
 */
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ mcRpo_DelayCompensation(uint8_t Id)
#else
uint16_t mcRpo_DelayCompensation( uint8_t Id)
#endif
{
 int32_t s32a;
 int16_t s16a;
 uint16_t retval;

 s32a = mcRpo_StateVariables_mas[Id].sp_iir3_mem; 
 if((int32_t)BASE_VALUE <= s32a)
 {
  if(0 > ( *mcRpo_InputPorts_mas[Id].rotSign ))
  {
     s16a = (int16_t)(-(s32a >> SH_BASE_VALUE));
     retval = ((uint16_t)s16a);
  }
  else
  {
         s16a = (int16_t)((s32a >> SH_BASE_VALUE));
         retval = ((uint16_t)s16a);
  }
 }
 else
 {
          retval = (0U);
 }
 return (retval);
}

/* !\brief Phase Estimation
 * 
 * Details.
 * Phase Estimation
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: Angular position 
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcRpo_PhaseEstimation(uint8_t Id)
#else
void mcRpo_PhaseEstimation( uint8_t Id)
#endif
{
    uint16_t u16a;
 #ifdef PH_CLAMP
    uint16_t u16b;
    uint16_t u16c;
 #endif /* ifdef PH_CLAMP */

 #ifdef PH_CLAMP
    /* phase variation limits calculation */
    u16a = mcRpo_StateVariables_mas[Id].dph_abs_fil >> 1;
    if(mcRpo_StateVariables_mas[Id].max_dspeed < u16a)
    {
        u16b = mcRpo_StateVariables_mas[Id].dph_abs_fil - mcRpo_StateVariables_mas[Id].max_dspeed;
        u16c = mcRpo_StateVariables_mas[Id].dph_abs_fil + mcRpo_StateVariables_mas[Id].max_dspeed;
    }
    else
    {
        u16b = mcRpo_StateVariables_mas[Id].dph_abs_fil - u16a;
        u16c = mcRpo_StateVariables_mas[Id].dph_abs_fil + u16a;
    }
 #endif /* ifdef PH_CLAMP */

    mcLib_Cartesian2Polar(&mcRpo_StateVariables_mas[Id].obs_e, &mcRpo_StateVariables_mas[Id].bemf);  /* extract angular position */
    if(0 >  ( *mcRpo_InputPorts_mas[Id].rotSign ))
    {
        u16a = mcRpo_StateVariables_mas[Id].bemf.t.ang + PIHALVES; /* overflow is OK here */
     #ifndef PH_CLAMP
        if((mcRpo_StateVariables_mas[Id].flx_arg - u16a) > (uint16_t)PI)
        {
            u16a = mcRpo_StateVariables_mas[Id].flx_arg;             /* cannot increase */
        }
     #else   /* ifndef PH_CLAMP */
        u16b = mcRpo_StateVariables_mas[Id].flx_arg - u16b;   /* overflow is OK here */
        u16c = mcRpo_StateVariables_mas[Id].flx_arg - u16c;   /* overflow is OK here */
        if(((uint16_t)(u16b - u16a)) > PI)
        {
            u16a = u16b;
        }
        else if((u16a - u16c) > (uint16_t)PI)
        {
            u16a = u16c;
        }
        else 
        {
            /* Do nothing */
        }
     #endif
    }
    else
    {
        u16a = mcRpo_StateVariables_mas[Id].bemf.t.ang - PIHALVES; /* overflow is OK here */
     #ifndef PH_CLAMP
        if((u16a - mcRpo_StateVariables_mas[Id].flx_arg) > (uint16_t)PI)
        {
           u16a = mcRpo_StateVariables_mas[Id].flx_arg;             /* cannot decrease */
        }
     #else   /* ifndef PH_CLAMP */
        u16b = mcRpo_StateVariables_mas[Id].flx_arg + u16b;   /* overflow is OK here */
        u16c = mcRpo_StateVariables_mas[Id].flx_arg + u16c;   /* overflow is OK here */
        if((u16a - u16b) > (uint16_t)PI)
        {
            u16a = u16b;
        }
        else if((u16c - u16a) > (uint16_t)PI)
        {
            u16a = u16c;
        }
        else 
        {
            /* Do nothing */
        }
     #endif /* ifdef PH_CLAMP */
    }
    mcRpo_StateVariables_mas[Id].flx_arg = u16a;
   *mcRpo_OutputPorts_mas[Id].angle =  u16a + mcRpo_DelayCompensation( Id );
   *mcRpo_OutputPorts_mas[Id].Es =  mcRpo_StateVariables_mas[Id].bemf.r;
}


/* !\brief Speed Estimation
 * 
 * Details.
 * Speed Estimation
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: Angular position 
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcRpo_SpeedEstimation( uint8_t Id )
#else
void mcRpo_SpeedEstimation(  uint8_t Id )
#endif
{
    int16_t dph;

    /* sign management and delta ang clamp */
    if(0 >  ( *mcRpo_InputPorts_mas[Id].rotSign ))
    {
        dph = (int16_t)mcRpo_StateVariables_mas[Id].flx_arg_mem - (int16_t)mcRpo_StateVariables_mas[Id].flx_arg;
    }
    else
    {
        dph = (int16_t)mcRpo_StateVariables_mas[Id].flx_arg - (int16_t)mcRpo_StateVariables_mas[Id].flx_arg_mem;
    }
    mcRpo_StateVariables_mas[Id].flx_arg_mem = mcRpo_StateVariables_mas[Id].flx_arg;
    if(1 > dph)
    {
        dph = mcRpo_StateVariables_mas[Id].dph_min;
    }
     mcRpo_StateVariables_mas[Id].dph_global = dph;
    /* first filter (FIR) */
    /* since we use as output the accumulator undivided, the amplification is
     4=2^2 if we calculate the speed over 4 samples; if the speed is
     calculated over a different number of samples, the amplification has
     to be adapted in consequence, since at the end we want a total amp of
     2^14 */
    mcRpo_StateVariables_mas[Id].sp_fir_acc += (uint32_t)dph;
    mcRpo_StateVariables_mas[Id].sp_fir_acc -= (uint32_t)mcRpo_StateVariables_mas[Id].sp_fir_vec[mcRpo_StateVariables_mas[Id].sp_fir_ind];
    mcRpo_StateVariables_mas[Id].sp_fir_vec[mcRpo_StateVariables_mas[Id].sp_fir_ind] = (uint16_t)dph;  /* max speed: pi[rad/s]/Ts[s] */
    mcRpo_StateVariables_mas[Id].sp_fir_ind++;
    /* mcRpo_StateSignal_mds.sp_fir_ind &= 0x07; speed calculated over 8 samples */
    mcRpo_StateVariables_mas[Id].sp_fir_ind &= 0x03; /* speed calculated over 4 samples */

    /* now we will apply three IIR in cascade configuration;
     the IIR time constant is ((2^4)-1)*Ts, so the cut-off frequency is Fs/(30pi)
     (around 85Hz if Fs=8kHz) */

    /* second filter (IIR) */
    /* since we use as output the filter memory, the amplification is 2^4=16 */
    /*mcRpo_StateSignal_mds.sp_iir1_mem -= shfdw2(mcRpo_StateSignal_mds.sp_iir1_mem, 4);*/ /* mcRpo_StateSignal_mds.sp_iir1_mem -= mcRpo_StateSignal_mds.sp_iir1_mem >> 4; */

    mcRpo_StateVariables_mas[Id].sp_iir1_mem -= mcRpo_StateVariables_mas[Id].sp_iir1_mem >> 4u;
    /* mcRpo_StateSignal_mds.sp_iir1_mem += shfdw1(mcRpo_StateSignal_mds.sp_fir_acc, 1); speed calculated over 8 samples */
    mcRpo_StateVariables_mas[Id].sp_iir1_mem += mcRpo_StateVariables_mas[Id].sp_fir_acc; /* speed calculated over 4 samples */

    /* third filter (IIR) */
    /* since we use as output the filter memory, the amplification is 2^4=16 */
    /*mcRpo_StateSignal_mds.sp_iir2_mem -= shfdw2(mcRpo_StateSignal_mds.sp_iir2_mem, 4);*/ /* mcRpo_StateSignal_mds.sp_iir2_mem -= mcRpo_StateSignal_mds.sp_iir2_mem >> 4; */
    mcRpo_StateVariables_mas[Id].sp_iir2_mem -= mcRpo_StateVariables_mas[Id].sp_iir2_mem >> 4u;
    mcRpo_StateVariables_mas[Id].sp_iir2_mem += mcRpo_StateVariables_mas[Id].sp_iir1_mem;

    /* fourth filter (IIR) */
    /* since we use as output the filter memory, the amplification is 2^4=16 */
    /*mcRpo_StateSignal_mds.sp_iir3_mem -= shfdw2(mcRpo_StateSignal_mds.sp_iir3_mem, 4);*/ /* mcRpo_StateSignal_mds.sp_iir3_mem -= mcRpo_StateSignal_mds.sp_iir3_mem >> 4; */
    mcRpo_StateVariables_mas[Id].sp_iir3_mem -= mcRpo_StateVariables_mas[Id].sp_iir3_mem >> 4u;
    mcRpo_StateVariables_mas[Id].sp_iir3_mem += mcRpo_StateVariables_mas[Id].sp_iir2_mem;

    /* the total amplification is 2^(2+3*4=14); now come back to the internal units */
    mcRpo_StateVariables_mas[Id].speed_abs = (int16_t)(mcRpo_StateVariables_mas[Id].sp_iir3_mem / (uint32_t)mcRpo_StateVariables_mas[Id].k_spe12);
    #ifdef PH_CLAMP
    mcRpo_StateVariables_mas[Id].dph_abs_fil = (int16_t)(mcRpo_StateVariables_mas[Id].sp_iir3_mem >> 14);
    #endif 
    if(0 >  ( *mcRpo_InputPorts_mas[Id].rotSign ))
    {
        mcRpo_StateVariables_mas[Id].speed_est = -mcRpo_StateVariables_mas[Id].speed_abs;
    }
    else
    {
        mcRpo_StateVariables_mas[Id].speed_est = mcRpo_StateVariables_mas[Id].speed_abs;
    }

  *mcRpo_OutputPorts_mas[Id].speed =   mcRpo_StateVariables_mas[Id].speed_est;
}

/*******************************************************************************
 * Interface Functions
*******************************************************************************/

/* !\brief Initialize Observer  
 * 
 * Details.
 * This interface functions initializes the observer
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
void mcRpoI_RotorPositionCalculationInit( tmcRpo_ConfigParameters_s * const rpoParam )
 {
     float f32a;
     tmcRpo_Parameters_s * pParam;
    
      /* Initialize input ports */
      mcRpo_InputPorts_mas[rpoParam->Id] = rpoParam->inPort;
    
      /* Initialize output ports */
      mcRpo_OutputPorts_mas[rpoParam->Id]  = rpoParam->outPort;
      
     /* Update and calculate independent and dependent parameters respectively */
      pParam = &mcRpo_Parameters_mas[rpoParam->Id] ;
      
      /* base values setting */
      pParam->f32_sam_fre = rpoParam->userParam.samfreq;
      pParam->f32_bas_spe = rpoParam->userParam.basespe;

      /* internal useful conversion constants calculation */
       pParam->f32_k_volam = 1.0f / (rpoParam->userParam.basevol * rpoParam->userParam.basecur );
 #ifdef  CROSS_COUPLING_ENABLED
       pParam->f32_k_speed = (BASE_VALUE_FL) / rpoParam->userParam.basespe;
 #endif

      /* minimum speed in internal units */
      f32a = (OBS_MINSPEED_R_S * (BASE_VALUE_FL)) / rpoParam->userParam.basespe;
      mcRpo_StateVariables_mas[rpoParam->Id] .speed_min = (int16_t)f32a;
    
      /* minimum phase difference */
      f32a = OBS_MINFREQ_HZ * 65536.0 /  pParam->f32_sam_fre;
      mcRpo_StateVariables_mas[rpoParam->Id] .dph_min = (uint16_t)f32a;

      /* conversion constants between speed in internal units and speed as
          filtered phase difference */
      f32a = ((32768.0f / FLOAT_PI)) * ( pParam->f32_bas_spe /  pParam->f32_sam_fre);
      mcRpo_StateVariables_mas[rpoParam->Id] .k_spe12 = (int16_t)f32a;
      mcRpo_SetObserverCoefficients( rpoParam->Id, rpoParam->userParam.Rs, rpoParam->userParam.Ls);
      mcRpoI_RotorPositionCalculationReset( 0u );
 }

/* !\brief Execute Luenberger Observer 
 * 
 * Details.
 * This interface functions reads phase current and voltage space vector inputs ( alpha -beta ),
 *  and estimates the rotor phase angle and speed
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcRpoI_RotorPositionCalculationRun( uint8_t Id )
#else
void mcRpoI_RotorPositionCalculationRun(  uint8_t Id  )
#endif
{    
    /* Calculate speed dependent observer parameters */
    mcRpo_EstimateObserverCoefficients( Id );
    
    /* Execute Luenberger Observer */
     mcRpo_LuenbergerObserver( Id );
    
    /* Phase Estimation */
    mcRpo_PhaseEstimation( Id );
    
    /* Speed Estimation */
    mcRpo_SpeedEstimation( Id );
}

/* !\brief Reset Observer  
 * 
 * Details.
 * This interface functions reset the observer
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */
void mcRpoI_RotorPositionCalculationReset( uint8_t Id )
{
    /* Other variables initialization  */
    mcRpo_StateVariables_mas[Id].flx_arg_mem = 0;
    mcRpo_StateVariables_mas[Id].flx_arg = 0;
    mcRpo_StateVariables_mas[Id].obs_e.x = 0;
    mcRpo_StateVariables_mas[Id].obs_e.y = 0;
    mcRpo_StateVariables_mas[Id].bemf.r = 0;
    mcRpo_StateVariables_mas[Id].bemf.t.ang = 0;
    mcRpo_StateVariables_mas[Id].bemf.t.sin = 0;
    mcRpo_StateVariables_mas[Id].bemf.t.cos = (int16_t)BASE_VALUE;

     /* observer status initialization */
    mcRpo_StateVariables_mas[Id].obs_z.x = 0;
    mcRpo_StateVariables_mas[Id].obs_z.y = 0;
}
