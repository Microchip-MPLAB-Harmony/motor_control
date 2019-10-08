/*******************************************************************************
 Reduced Order Luenberger Observer Motor Control Library 

  Company:
    Microchip Technology Inc.

  File Name:
    q14_rolo_wm_mcLib.c

  Summary:
    Reduced Order Luenberger Observer and windmilling related functions and variables
 *  implemented in Q14 fixed point arithmetic.

  Description:
    This file implements reduced order luenberger observer related functions
 
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
#include "q14_rolo_wm_mcLib.h"
#include "userparams.h"


/*******************************************************************************
MISRA violations
*******************************************************************************/
/* 10.1:
shift operations on signed numbers is used to benefit optimization.
arithmetic shift is used by the compiler in those cases
*/

/*******************************************************************************
Private global variables
*******************************************************************************/

/* Base parameters set only once, not used within control loop */
static float32_t
 f32_sam_fre, /* sampling frequency [Hz] */
 f32_bas_spe, /* base speed [rad/sec] */
 f32_k_volam, /* internal conversion constant */ 
 f32_sta_res, /* stator resistance [Ohm] */
 f32_syn_ind, /* synchronous inductance [Hen] */
 f32_k_gain,  /* constant in observer coefficient calculation */
 f32_c1_coe;  /* constant in observer coefficient calculation */


#ifdef  CROSS_COUPLING_ENABLED
static float32_t  f32_k_speed; /* internal conversion constant */
/* debug variables */
static uint32_t
 debug_cnt1,
 debug_cnt2;
#endif
/******************************************************************************
Safety variables
******************************************************************************/
static vec2_t
 obs_z,   /* observer estimated status vector */
 obs_e;   /* observer estimated bemf vector */

static vecp_t
 bemf;   /* observer estimated bemf vector (polar coordinates) */

static coef_t
 l11,   /* constant observer coefficient */
 m11,   /* constant observer coefficient */
 n11,   /* constant observer coefficient */
 k11;   /* constant observer coefficient */

#ifdef  CROSS_COUPLING_ENABLED
coef_t
 hhh,   /* intermediate result in observer variable coefficient calculation */
 lll,   /* intermediate result in observer variable coefficient calculation */
 xxx,   /* intermediate result in observer variable coefficient calculation */
 m21,   /* observer variable coefficient */
 n21,   /* observer variable coefficient */
 k21;   /* observer variable coefficient */
#endif  // ifdef CROSS_COUPLING_ENABLED

/* unused observer coefficients
 l12 = 0;
 l21 = 0;
 l22 = l11;
 m12 = -m21;
 m22 = m11;
 n12 = -n21;
 n22 = n11;
 k12 = -k21;
 k22 = k11;
*/



static int32_t
 sp_fir_acc,  /* speed fir filter accumulator */
 sp_iir1_mem, /* speed iir filter memory (first iir) */
 sp_iir2_mem, /* speed iir filter memory (second iir) */
 sp_iir3_mem, /* speed iir filter memory (third iir) */
 sp_iir3_mem_abs; /*speed iir filter memory absolute (third iir)*/

 uint16_t
 dph_min,     /* minimum delta phase */
         
#ifdef PH_CLAMP
 max_dspeed,  /* maximum speed variation in one sampling period */
#endif // ifdef PH_CLAMP
 flx_arg,  /* estimated permanent magnets flux position */

 dph_abs_fil; /* filtered one-step phase difference */

uint16_t  flx_arg_mem, /* estimated permanent magnets flux position memory */
          bemf_arg,
         bemf_arg_mem;
int16_t dph_global;
static int16_t
 k_spe12,  /* internal conversion constant */
 speed_min,  /* minimum speed [internal units] */
 speed_est,  /* estimated speed [internal units] */
 speed_sgn,  /* speed sign */
 speed_abs,  /* speed absolute value */
 sp_fir_ind,  /* index in fir speed filter memories vector */
 sp_fir_vec[8]; /* speed fir filter memories vector */


int16_t dph_mem;
int32_t delta_u16a;
uint32_t blanking_count = 0;
uint16_t angle_rollover_count = 0;

/*******************************************************************************
Functions (private and public)
*******************************************************************************/

/******************************************************************************
Function:  estimation_set_base_values
Description: base values setting for the observer library
Input:   sampling frequency [Hz]
    base speed [rad/sec]
    base voltage [V]
    base current [A]
Output:   nothing
Modifies:  observer internal constants
******************************************************************************/
void estimation_set_base_values(float32_t samfreq, float32_t basespe,
    float32_t basevol, float32_t basecur)
{
 float32_t f32a;

 /* base values setting */
 f32_sam_fre = samfreq;
 f32_bas_spe = basespe;

 /* internal useful conversion constants calculation */
 f32_k_volam = 1.0f / (basevol * basecur);
 #ifdef  CROSS_COUPLING_ENABLED
 f32_k_speed = (BASE_VALUE_FL) / basespe;
 #endif

 /* minimum speed in internal units */
 f32a = (OBS_MINSPEED_R_S * (BASE_VALUE_FL)) / basespe;
 speed_min = (int16_t)f32a;
 /* minimum phase difference */
 f32a = OBS_MINFREQ_HZ * 65536.0 / f32_sam_fre;
 dph_min = (uint16_t)f32a;

 /* conversion constants between speed in internal units and speed as
    filtered phase difference */
 f32a = ((32768.0f / FLOAT_PI)) * (f32_bas_spe / f32_sam_fre);
 k_spe12 = (int16_t)f32a;
}

/******************************************************************************
Function:  estimation_set_parameters
Description: Luenberger observer coefficients calculation
Input:   stator resistance [Ohm]
    synchronous inductance [Hen]
Output:   nothing
Modifies:  observer coefficients
******************************************************************************/
void estimation_set_parameters(float32_t rsta, float32_t lsyn)
{
 float32_t  f32a;

 /* preliminary floating point calculations */
 f32_sta_res = rsta;
 f32_syn_ind = lsyn;
 f32_k_gain = OBS_H_GAIN * f32_syn_ind * f32_sam_fre; /* always positive */
 f32_c1_coe = f32_k_gain - f32_sta_res;     /* can be negative */

 /* constant coefficients calc (l11) */
 f32a = OBS_C0_GAIN;
 l11.shr = 0;
 while((16383.0f > f32a) && ((uint16_t)OBS_MAXSHIFTS > l11.shr))
 {
  f32a *= 2.0f;
  l11.shr++;
 }
 l11.val = (int16_t)f32a;        /* always positive */
 while((0 == (l11.val & 0x0001)) && (0U < l11.shr))
 {
  l11.val >>= 1;
  l11.shr--;
 }

 /* constant coefficients calc (m11) */
 f32a = f32_c1_coe * f32_k_volam * OBS_H_GAIN;
 m11.shr = 0;
 if(f32a >= 0.0f)
 {
  while((16383.0f > f32a) && ((uint16_t)OBS_MAXSHIFTS > m11.shr))
  {
   f32a *= 2.0f;
   m11.shr++;
  }
 }
 else
 {
  while((-16383.0f < f32a) && ((uint16_t)OBS_MAXSHIFTS > m11.shr))
  {
   f32a *= 2.0f;
   m11.shr++;
  }
 }
 m11.val = (int16_t)f32a;        /* can be negative */
 while((0 == (m11.val & 0x0001)) && (0U < m11.shr))
 {
  m11.val >>= 1;
  m11.shr--;
 }

 /* constant coefficients calc (n11) */
 f32a = OBS_H_GAIN;
 n11.shr = 0;
 while((16383.0f > f32a) && ((uint16_t)OBS_MAXSHIFTS > n11.shr))
 {
  f32a *= 2.0f;
  n11.shr++;
 }
 n11.val = (int16_t)f32a;        /* always positive */
 while((0 == (n11.val & 0x0001)) && (0U < n11.shr))
 {
  n11.val >>= 1;
  n11.shr--;
 }

 /* constant coefficients calc (k11) */
 f32a = f32_k_gain * f32_k_volam;
 k11.shr = 0;
 while((16383.0f > f32a) && ((uint16_t)OBS_MAXSHIFTS > k11.shr))
 {
  f32a *= 2.0f;
  k11.shr++;
 }
 k11.val = (int16_t)f32a;        /* always positive */
 while((0 == (k11.val & 0x0001)) && (0U < k11.shr))
 {
  k11.val >>= 1;
  k11.shr--;
 }

 #ifdef  CROSS_COUPLING_ENABLED

 /* intermediate constant (useful in variable coefficients calc) (hhh) */
 f32a = f32_c1_coe * f32_k_volam;
 hhh.shr = 0;
 if(f32a >= 0.0f)
 {
  while((16383.0f > f32a) && ((uint16_t)OBS_MAXSHIFTS > hhh.shr))
  {
   f32a *= 2.0f;
   hhh.shr++;
  }
 }
 else
 {
  while((-16383.0f < f32a) && ((uint16_t)OBS_MAXSHIFTS > hhh.shr))
  {
   f32a *= 2.0f;
   hhh.shr++;
  }
 }
 hhh.val = (int16_t)f32a;        /* can be negative */
 while((0 == (hhh.val & 0x0001)) && (0 < hhh.shr))
 {
  hhh.val >>= 1;
  hhh.shr--;
 }

 /* intermediate constant (useful in variable coefficients calc) (lll) */
 f32a = f32_syn_ind * f32_k_volam / f32_k_speed;
 lll.shr = 0;
 while((16383.0f > f32a) && ((uint16_t)OBS_MAXSHIFTS > lll.shr))
 {
  f32a *= 2.0f;
  lll.shr++;
 }
 lll.val = (int16_t)f32a; /* always positive */
 while((0 == (lll.val & 0x0001)) && (0 < lll.shr))
 {
  lll.val >>= 1;
  lll.shr--;
 }

 /* intermediate constant (useful in variable coefficients calc) (xxx) */
 f32a = (1.0f / (f32_sam_fre * f32_k_speed));
 xxx.shr = 0;
 while((16383.0f > f32a) && ((uint16_t)OBS_MAXSHIFTS > xxx.shr))
 {
  f32a *= 2.0f;
  xxx.shr++;
 }
 xxx.val = (int16_t)f32a; /* always positive */
 while((0 == (xxx.val & 0x0001)) && (0 < xxx.shr))
 {
  xxx.val >>= 1;
  xxx.shr--;
 }

 /* variable coefficients init (NOT NEEDED)
 obs_coef_calc(speed_min); */

 #endif  // ifdef CROSS_COUPLING_ENABLED

 /* observer status init */
 obs_z.x = 0;
 obs_z.y = 0;

 /* speed estimation init */
 #ifdef PH_CLAMP
 max_dspeed = MAX_DSPEED;
 #endif 
 speed_filter_init(speed_min);

 /* other internal variables init */
 flx_arg_mem = 0;
 flx_arg = 0;
 obs_e.x = 0;
 obs_e.y = 0;
 bemf.r = 0;
 bemf.t.ang = 0;
 bemf.t.sin = 0;
 bemf.t.cos = (int16_t)BASE_VALUE_INT;
 #ifdef  CROSS_COUPLING_ENABLED
 debug_cnt1 = 0;
 debug_cnt2 = 0;
 #endif
}

/******************************************************************************
Function:  obs_coef_calc
Description: Luenberger observer coefficients calculation
Input:   reference speed (only to get its sign)
Output:   nothing
Modifies:  observer variable coefficients
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ obs_coef_calc(int16_t spref)
#else
void obs_coef_calc(int16_t spref)
#endif
{
 #ifdef  CROSS_COUPLING_ENABLED
 int32_t s32a;
 int16_t spabs;
 #endif /* ifdef CROSS_COUPLING_ENABLED */

 /* sign management */
 if(0 > spref)
 {
  speed_sgn = -1;
 }
 else
 {
  speed_sgn = 1;
 }

 #ifdef  CROSS_COUPLING_ENABLED

 /* speed clamp */
 /* 10.1 violation */
 if(speed_min > speed_abs)
 {
  spabs = speed_min;
 }
 else
 {
  spabs = speed_abs;
 }

 /* variable coefficient (n21) (xxx.val is positive) */
 s32a = ((int32_t)(xxx.val)) * ((int32_t)spabs);
 n21.shr = xxx.shr;
 while((32767 < s32a) || (OBS_MAXSHIFTS < n21.shr))
 {
  s32a >>= 1;
  n21.shr--;   // if negative algo. will fail
 }
 n21.val = (int16_t)s32a;
 while((0 == (n21.val & 0x0001)) && (0 < n21.shr))
 {
  n21.val >>= 1;
  n21.shr--;
 }

 /* variable coefficient (m21) (hhh.val can be negative) */
 s32a = ((int32_t)(hhh.val)) * ((int32_t)(n21.val));
 m21.shr = n21.shr + hhh.shr;
 while(((32767 < s32a) || (-32767 > s32a)) || (OBS_MAXSHIFTS < m21.shr))
 {
  s32a >>= 1;
  m21.shr--;   // if negative algo. will fail
 }
 m21.val = (int16_t)s32a;
 while((0 == (m21.val & 0x0001)) && (0 < m21.shr))
 {
  m21.val >>= 1;
  m21.shr--;
 }

 /* variable coefficient (k21) (lll.val is positive) */
 s32a = ((int32_t)(lll.val)) * ((int32_t)spabs);
 k21.shr = lll.shr;
 while((32767 < s32a) || (OBS_MAXSHIFTS < k21.shr))
 {
  s32a >>= 1;
  k21.shr--;   /* if negative algo. will fail */
 }
 k21.val = (int16_t)s32a;
 while((0 == (k21.val & 0x0001)) && (0 < k21.shr))
 {
  k21.val >>= 1;
  k21.shr--;
 }

 /* coefficients sign management */
 if(0 > speed_sgn)
 {
  n21.val = -n21.val;
  m21.val = -m21.val;
  k21.val = -k21.val;
 }
 #endif  /* ifdef CROSS_COUPLING_ENABLED */

}

/*******************************************************************************
Function:  shfdw1
Description: arithmetic shift down, which goes to zero also with negative
    numbers
Input:   number to be shifted (a), number of shifts (s)
Output:   a >> s
Note:   symmetric behaviour, unlike the assembly instruction
*******************************************************************************/
#ifdef RAM_EXECUTE
int32_t __ramfunc__ shfdw1(int32_t a, uint16_t s)
#else
int32_t shfdw1(int32_t a, uint16_t s)
#endif
{
 /* shift operation on signed numbers is required.
    optimization is higher in this case.
    compiler ensures it places with an arithmetic shift */

 int32_t r;

 if(0 > a)
 {
  r = -((-a) >> s);
 }
 else
 {
  r = a >> s;
 }
 return (r);
}

/*******************************************************************************
Function:  shfdw2
Description: arithmetic shift down, which goes to zero also with negative
    numbers, but keeps output >=1 (<=-1) if the input is >1 (<-1)
Input:   number to be shifted (a), number of shifts (s)
Output:   a >> s
Note:   useful to reset the filters memories
*******************************************************************************/
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

/*******************************************************************************
Function:  mulshr
Description: multiplication and shift down of a number by a coef_t
Input:   number to be multiplied and shifted (a), coefficient address (c)
Output:   result of multiply and shift operation
*******************************************************************************/
static inline int32_t mulshr(int16_t a, const coef_t *c)
{
 int32_t r;

 r = ((int32_t)a) * ((int32_t)(c->val));
 r >>= (c->shr);

 return (r);
}

/******************************************************************************
Function:  lunberger_observer
Description: bemf reduced order observer implementation
Input:   voltage and current vectors in the static reference frame
Output:   nothing
Modifies:  observer status and estimated bemf vectors
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ lunberger_observer(const vec2_t *v, const vec2_t *i)
#else
void lunberger_observer(const vec2_t *v, const vec2_t *i)
#endif
{
 int32_t s32x, s32y;
 #ifdef AMP_CLAMP
 int32_t luzx, luzy;
 #endif 

 s32x = mulshr(obs_z.x, &l11);
 s32x += mulshr((i->x), &m11);
 #ifdef  CROSS_COUPLING_ENABLED
 s32x -= mulshr((i->y), &m21); /* m12 = -m21 */
 #endif  // ifdef CROSS_COUPLING_ENABLED
 s32x += mulshr((v->x), &n11);
 #ifdef  CROSS_COUPLING_ENABLED
 s32x -= mulshr((v->y), &n21); /* n12 = -n21 */
 #endif  // ifdef CROSS_COUPLING_ENABLED

 s32y =  mulshr(obs_z.y, &l11); /* l22 = l11 */
 #ifdef  CROSS_COUPLING_ENABLED
 s32y += mulshr((i->x), &m21);
 #endif  // ifdef CROSS_COUPLING_ENABLED
 s32y += mulshr((i->y), &m11); /* m22 = m11 */
 #ifdef  CROSS_COUPLING_ENABLED
 s32y += mulshr((v->x), &n21);
 #endif  // ifdef CROSS_COUPLING_ENABLED
 s32y += mulshr((v->y), &n11); /* n22 = n11 */

 #ifdef AMP_CLAMP
 /* during startup transitory from zero speed, observer status could diverge;
    this clamping keeps the vector amplitude clamped, without changing its argument */
 luzx = s32x;
 luzy = s32y;
 while((-32767 > luzx) || (32767 < luzx) || (-32767 > luzy) || (32767 < luzy))
 {
  luzx = shfdw1(luzx, 1);
  luzy = shfdw1(luzy, 1);
  debug_cnt1++;
 }
 obs_z.x = (int16_t)luzx;
 obs_z.y = (int16_t)luzy;
 #else /* ifdef AMP_CLAMP */
 obs_z.x = (int16_t)s32x;
 obs_z.y = (int16_t)s32y;
 #endif /* ifdef AMP_CLAMP */

 s32x -= mulshr((i->x), &k11);
 #ifdef  CROSS_COUPLING_ENABLED
 s32x += mulshr((i->y), &k21); /* k12 = -k21 */
 #endif  // ifdef CROSS_COUPLING_ENABLED

 #ifdef  CROSS_COUPLING_ENABLED
 s32y -= mulshr((i->x), &k21);
 #endif  // ifdef CROSS_COUPLING_ENABLED
 s32y -=  mulshr((i->y), &k11); /* k22 = k11 */

 #ifdef AMP_CLAMP
 while((-32767 > s32x) || (32767 < s32x) || (-32767 > s32y) || (32767 < s32y))
 {
  s32x = shfdw1(s32x, 1);
  s32y = shfdw1(s32y, 1);
  debug_cnt2++;
 }
 #endif // ifdef AMP_CLAMP

 obs_e.x = (int16_t)s32x;
 obs_e.y = (int16_t)s32y;

}

/*******************************************************************************
Function:  bemf_phase_estimation
Description: estimation of bemf angle 
Input:   nothing (uses global variable bemf vector)
Output:   nothing (modifies global variable flx_arg)
*******************************************************************************/

#ifdef RAM_EXECUTE
void __ramfunc__ bemf_phase_estimation(void)
#else
void bemf_phase_estimation(void)
#endif
{
 uint16_t u16a;

 #ifdef PH_CLAMP
 uint16_t u16b;
 uint16_t u16c;
 #endif /* ifdef PH_CLAMP */

 #ifdef PH_CLAMP
 /* phase variation limits calculation */
 u16a = dph_abs_fil >> 1;
 if(max_dspeed < u16a)
 {
  u16b = dph_abs_fil - max_dspeed;
  u16c = dph_abs_fil + max_dspeed;
 }
 else
 {
  u16b = dph_abs_fil - u16a;
  u16c = dph_abs_fil + u16a;
 }
 #endif /* ifdef PH_CLAMP */

 library_xy_rt(&obs_e, &bemf);  /* extract angular position */
 u16a = bemf.t.ang;
 delta_u16a = ((int32_t)u16a) - ((int32_t)bemf_arg);

  
    if((delta_u16a>((int32_t)PI))||(delta_u16a<((int32_t)-PI)))
    {
 /* Blanking for 'BEMF_ANGLE_BLANK_COUNT' samples is started "after" the angle roll over from 2*PI to 0 or 0 to 2*PI
  * This blanking helps in removing an possible noise which would masquerade as angle roll over 
  * The reason blanking is trigger "after" the roll over because it was observed that an erroneous glitch 
  * appeared immediately after a valid angle roll over */       
        if(blanking_count>0) 
        {
            u16a = bemf_arg; // CPU comes here if there is a glitch during the blanking. Ignore the erroneous value and use the previous value 
        }
        else
        {
            blanking_count = BEMF_ANGLE_BLANK_COUNT;  //when blanking_count == 0, CPU enters here and the high delta in angle is assumed to be caused due to angle roll over. Hence, bemf.t.ang is accepted as valid angle
            angle_rollover_count++; // counts the angle rollovers during windmilling
        }
    }

  if(blanking_count!=0)
  {
    blanking_count--; 
  }
  
   bemf_arg = u16a;
}


/*******************************************************************************
Function:  phase_estimation
Description: estimation of rotor position using bemf vector
Input:   nothing (uses global variable bemf vector)
Output:   nothing (modifies global variable flx_arg)
*******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ phase_estimation(void)
#else
void phase_estimation(void)
#endif
{
 uint16_t u16a;
 #ifdef PH_CLAMP
 uint16_t u16b;
 uint16_t u16c;
 #endif /* ifdef PH_CLAMP */

 #ifdef PH_CLAMP
 /* phase variation limits calculation */
 u16a = dph_abs_fil >> 1;
 if(max_dspeed < u16a)
 {
  u16b = dph_abs_fil - max_dspeed;
  u16c = dph_abs_fil + max_dspeed;
 }
 else
 {
  u16b = dph_abs_fil - u16a;
  u16c = dph_abs_fil + u16a;
 }
 #endif /* ifdef PH_CLAMP */

 library_xy_rt(&obs_e, &bemf);  /* extract angular position */
 if(0 > speed_sgn)
 {
  u16a = bemf.t.ang + PIHALVES; /* overflow is OK here */
  #ifndef PH_CLAMP
  if((flx_arg - u16a) > (uint16_t)PI)
  {
   u16a = flx_arg;             /* cannot increase */
  }
  #else   /* ifndef PH_CLAMP */
  u16b = flx_arg - u16b;   /* overflow is OK here */
  u16c = flx_arg - u16c;   /* overflow is OK here */
  if(((uint16_t)(u16b - u16a)) > PI)
  {
   u16a = u16b;
  }
  else if((u16a - u16c) > (uint16_t)PI)
  {
   u16a = u16c;
  }
  #endif
 }
 else
 {
  u16a = bemf.t.ang - PIHALVES; /* overflow is OK here */
  #ifndef PH_CLAMP
  if((u16a - flx_arg) > (uint16_t)PI)
  {
   u16a = flx_arg;             /* cannot decrease */
  }
  #else   /* ifndef PH_CLAMP */
  u16b = flx_arg + u16b;   /* overflow is OK here */
  u16c = flx_arg + u16c;   /* overflow is OK here */
  if((u16a - u16b) > (uint16_t)PI)
  {
   u16a = u16b;
  }
  else if((u16c - u16a) > (uint16_t)PI)
  {
   u16a = u16c;
  }
  #endif /* ifdef PH_CLAMP */
 }
 flx_arg = u16a;
}

/*******************************************************************************
Function:  phase_estimation_init
Description: init routine for use of phase estimation
Input:   nothing (uses global variable bemf vector)
Output:   nothing (modifies global variable flx_arg)
*******************************************************************************/
void phase_estimation_init(void)
{
 library_xy_rt(&obs_e, &bemf);
 if(0 > speed_sgn)
 {
  flx_arg = bemf.t.ang + PIHALVES; /* overflow is OK here */
 }
 else
 {
  flx_arg = bemf.t.ang - PIHALVES; /* overflow is OK here */
 }
}

/*******************************************************************************
Function:  bemf_phase_estimation_init
Description: init routine for use of phase estimation
Input:   nothing (uses global variable bemf vector)
Output:   nothing (modifies global variable flx_arg)
*******************************************************************************/
void bemf_phase_estimation_init(void)
{
 library_xy_rt(&obs_e, &bemf);
 
  bemf_arg = bemf.t.ang;
 
}

/*******************************************************************************
Function:  speed_filter
Description: speed estimation, using a fourth order low-pass filter
Input:   nothing (uses delta position in one step)
Output:   nothing (modifies global variable speed_est)
*******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ speed_filter(void)
#else
void speed_filter(void)
#endif
{
 int16_t dph;

 dph = (int16_t)flx_arg - (int16_t)flx_arg_mem;

 flx_arg_mem = flx_arg;
 
 // k_spe12 also comes out to be equal to delta_angle max electrical speed(MAX_FREQ_HZ).
 // If the delta_angle is greater than k_spe12 then that is due to noise/ angle roll over. 
 // In such an event, we use the previous dph value which was within the limit of max angle step.
 
 if((dph < (int16_t)-k_spe12)||(dph > (int16_t)k_spe12)) // covering both speed directions
 {
     dph= dph_mem; // if the delta_angle is greater than the limit then use the last valid value
 }
 else
 {
     dph_mem = dph; // if delta_angle is under the limit then save this value for next cycle evaluation
 }
 

 dph_global = dph;
 /* first filter (FIR) */
 /* since we use as output the accumulator undivided, the amplification is
  4=2^2 if we calculate the speed over 4 samples; if the speed is
  calculated over a different number of samples, the amplification has
  to be adapted in consequence, since at the end we want a total amp of
  2^14 */
 sp_fir_acc += dph;
 sp_fir_acc -= sp_fir_vec[sp_fir_ind];
 sp_fir_vec[sp_fir_ind] = dph;  /* max speed: pi[rad/s]/Ts[s] */
    sp_fir_ind++;
 /* sp_fir_ind &= 0x07; speed calculated over 8 samples */
 sp_fir_ind &= 0x03; /* speed calculated over 4 samples */

 /* now we will apply three IIR in cascade configuration;
  the IIR time constant is ((2^4)-1)*Ts, so the cut-off frequency is Fs/(30pi)
  (around 85Hz if Fs=8kHz) */

 /* second filter (IIR) */
 /* since we use as output the filter memory, the amplification is 2^4=16 */
 /*sp_iir1_mem -= shfdw2(sp_iir1_mem, 4);*/ /* sp_iir1_mem -= sp_iir1_mem >> 4; */

    sp_iir1_mem -= sp_iir1_mem >> 4;
 /* sp_iir1_mem += shfdw1(sp_fir_acc, 1); speed calculated over 8 samples */
 sp_iir1_mem += sp_fir_acc; /* speed calculated over 4 samples */

 /* third filter (IIR) */
 /* since we use as output the filter memory, the amplification is 2^4=16 */
 /*sp_iir2_mem -= shfdw2(sp_iir2_mem, 4);*/ /* sp_iir2_mem -= sp_iir2_mem >> 4; */
 sp_iir2_mem -= sp_iir2_mem >> 4;
 sp_iir2_mem += sp_iir1_mem;

 /* fourth filter (IIR) */
 /* since we use as output the filter memory, the amplification is 2^4=16 */
 /*sp_iir3_mem -= shfdw2(sp_iir3_mem, 4);*/ /* sp_iir3_mem -= sp_iir3_mem >> 4; */
 sp_iir3_mem -= sp_iir3_mem >> 4;
 sp_iir3_mem += sp_iir2_mem;

 /* the total amplification is 2^(2+3*4=14); now come back to the internal units */
 speed_est = (int16_t)(sp_iir3_mem / k_spe12);
 
 
 if(speed_sgn < 0)
 {
     speed_abs = -speed_est;
     sp_iir3_mem_abs = -sp_iir3_mem;
 }
 else
 {
     speed_abs = speed_est;
     sp_iir3_mem_abs = sp_iir3_mem;
 }    
 
 #ifdef PH_CLAMP
 dph_abs_fil = (int16_t)(sp_iir3_mem_abs >> 14);
 #endif
}


/*******************************************************************************
Function:  bemf_speed_filter
Description: speed estimation, using a fourth order low-pass filter
Input:   nothing (uses delta position in one step)
Output:   nothing (modifies global variable speed_est)
*******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ bemf_speed_filter(void)
#else
void bemf_speed_filter(void)
#endif
{
 int16_t dph;


 dph = (int16_t)bemf_arg - (int16_t)bemf_arg_mem;
 
 bemf_arg_mem = bemf_arg;
 
 // k_spe12 also comes out to be equal to delta_angle max electrical speed(MAX_FREQ_HZ).
 // If the delta_angle is greater than k_spe12 then that is due to noise/ angle roll over. 
 // In such an event, we use the previous dph value which was within the limit of max angle step.
 

    if((dph < (int16_t)-k_spe12)||(dph > (int16_t)k_spe12)) // covering both speed directions
    {
        dph= dph_mem; // if the delta_angle is greater than the limit then use the last valid value
    }
    else
    {
        dph_mem = dph; // if delta_angle is under the limit then save this value for next cycle evaluation
    }

 

  dph_global = dph;
 /* first filter (FIR) */
 /* since we use as output the accumulator undivided, the amplification is
  4=2^2 if we calculate the speed over 4 samples; if the speed is
  calculated over a different number of samples, the amplification has
  to be adapted in consequence, since at the end we want a total amp of
  2^14 */
 sp_fir_acc += dph;
 sp_fir_acc -= sp_fir_vec[sp_fir_ind];
 sp_fir_vec[sp_fir_ind] = dph;  /* max speed: pi[rad/s]/Ts[s] */
    sp_fir_ind++;
 /* sp_fir_ind &= 0x07; speed calculated over 8 samples */
 sp_fir_ind &= 0x03; /* speed calculated over 4 samples */

 /* now we will apply three IIR in cascade configuration;
  the IIR time constant is ((2^4)-1)*Ts, so the cut-off frequency is Fs/(30pi)
  (around 85Hz if Fs=8kHz) */

 /* second filter (IIR) */
 /* since we use as output the filter memory, the amplification is 2^4=16 */
 /*sp_iir1_mem -= shfdw2(sp_iir1_mem, 4);*/ /* sp_iir1_mem -= sp_iir1_mem >> 4; */

    sp_iir1_mem -= sp_iir1_mem >> 4;
 /* sp_iir1_mem += shfdw1(sp_fir_acc, 1); speed calculated over 8 samples */
 sp_iir1_mem += sp_fir_acc; /* speed calculated over 4 samples */

 /* third filter (IIR) */
 /* since we use as output the filter memory, the amplification is 2^4=16 */
 /*sp_iir2_mem -= shfdw2(sp_iir2_mem, 4);*/ /* sp_iir2_mem -= sp_iir2_mem >> 4; */
 sp_iir2_mem -= sp_iir2_mem >> 4;
 sp_iir2_mem += sp_iir1_mem;

 /* fourth filter (IIR) */
 /* since we use as output the filter memory, the amplification is 2^4=16 */
 /*sp_iir3_mem -= shfdw2(sp_iir3_mem, 4);*/ /* sp_iir3_mem -= sp_iir3_mem >> 4; */
 sp_iir3_mem -= sp_iir3_mem >> 4;
 sp_iir3_mem += sp_iir2_mem;

 /* the total amplification is 2^(2+3*4=14); now come back to the internal units */

speed_est = (int16_t)(sp_iir3_mem / k_spe12);

 if(speed_est < 0)
 {
     speed_abs = -speed_est;
     sp_iir3_mem_abs = -sp_iir3_mem;
 }
 else
 {
     speed_abs = speed_est;
     sp_iir3_mem_abs = sp_iir3_mem;
 }

#ifdef PH_CLAMP
dph_abs_fil = (int16_t)(sp_iir3_mem_abs >> 14);
#endif 
}


/******************************************************************************
Function:  speed_filter_init
Description: initial setting of speed filter memories
Input:   speed [internal_speed_unit]
Output:   nothing
Modifies:  internal speed estimation filter memories
******************************************************************************/
void speed_filter_init(int16_t speed)
{
 int16_t temp;

 speed_est = speed;
 if(0 > speed_est)
 {
  speed_abs = -speed_est;
  speed_sgn = -1;
 }
 else
 {
  speed_abs = speed_est;
  speed_sgn = 1;
 }
 sp_iir3_mem = ((int32_t)speed_abs) * ((int32_t)k_spe12);
 sp_iir2_mem = sp_iir3_mem >> 4;
 sp_iir1_mem = sp_iir2_mem >> 4;
 sp_fir_acc = sp_iir1_mem >> 4;

 temp = (int16_t)(sp_fir_acc >> 2);  /*speed calculated over 4 samples */
 /* temp = (int16_t)(sp_fir_acc >> 3); speed calculated over 8 samples */
 dph_abs_fil = (uint16_t)(temp);

 for(sp_fir_ind = 0; sp_fir_ind < 8; sp_fir_ind++)
 {
  sp_fir_vec[sp_fir_ind] = (int16_t)dph_abs_fil;
 }
 sp_fir_ind = 0;
 flx_arg_mem = flx_arg;
}

/******************************************************************************
Function:  delay_comp
Description: calculation of the phase error due to algorithm medium delay
Input:   nothing (uses internal speed filter memory)
Output:   phase delay (medium time delay is 1.5 sampling periods)
******************************************************************************/
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ delay_comp(void)
#else
uint16_t delay_comp(void)
#endif
{
 int32_t s32a;
 int16_t s16a;
        uint16_t retval;

 /*sp_iir3_mem_abs = change in angle per sample*2^14
  *s32a = sp_iir3_mem_abs for  1 sampling period delay.  s32a= 2*sp_iir3_mem_abs for 2 sampling period delay*/
 s32a = sp_iir3_mem_abs;  /* always positive */
 if((int32_t)BASE_VALUE_INT <= s32a)
 {
  if(0 > speed_sgn)
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

/******************************************************************************
Function:  position_and_speed_estimation
Description: performs the position and speed estimation
Input:   reference speed [internal_speed_unit] rs
    applied voltage vector (in stationary reference frame)
    measured current vector (in stationary reference frame)
Output:   nothing (updates internal variables)
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i)
#else
void position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i)
#endif
{
 obs_coef_calc(rs);
 lunberger_observer(v, i);
 phase_estimation();
 speed_filter();
}

/******************************************************************************
Function:  bemf_position_and_speed_estimation
Description: performs the position and speed estimation
Input:   reference speed [internal_speed_unit] rs
    applied voltage vector (in stationary reference frame)
    measured current vector (in stationary reference frame)
Output:   nothing (updates internal variables)
******************************************************************************/


#ifdef RAM_EXECUTE
void __ramfunc__ bemf_position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i)
#else
void bemf_position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i)
#endif
{
 obs_coef_calc(rs);
 lunberger_observer(v, i);
 bemf_phase_estimation();
 bemf_speed_filter();
}

/******************************************************************************
Function:  estimation_alignment
Description: aligns the observer
Input:   reference speed [internal_speed_unit] rs
    applied voltage vector (in stationary reference frame)
    measured current vector (in stationary reference frame)
Output:   nothing (updates internal variables)
******************************************************************************/
void estimation_alignment(int16_t rs, const vec2_t *v, const vec2_t *i)
{
 obs_coef_calc(rs);
 lunberger_observer(v, i);
 phase_estimation_init();
 speed_filter_init(rs);
}

/******************************************************************************
Function:  bemf_estimation_alignment
Description: aligns the observer
Input:   reference speed [internal_speed_unit] rs
    applied voltage vector (in stationary reference frame)
    measured current vector (in stationary reference frame)
Output:   nothing (updates internal variables)
******************************************************************************/
void bemf_estimation_alignment(int16_t rs, const vec2_t *v, const vec2_t *i)
{
 obs_coef_calc(rs);
 lunberger_observer(v, i);
 bemf_phase_estimation_init();
 speed_filter_init(rs);
}

/******************************************************************************
Function:  get_angular_position
Description: returns the estimated position [internal_angle_unit]
Input:   nothing
Output:   compensated estimated position
******************************************************************************/
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ get_angular_position(void)
#else
uint16_t get_angular_position(void)
#endif
{
 return(flx_arg + delay_comp());
}

/******************************************************************************
Function:  get_bemf_angular_position
Description: returns the estimated position [internal_angle_unit]
Input:   nothing
Output:   compensated estimated position
******************************************************************************/
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ get_bemf_angular_position(void)
#else
uint16_t get_bemf_angular_position(void)
#endif
{
 return(bemf_arg);
}

/******************************************************************************
Function:  get_angular_speed
Description: returns the estimated speed [internal_speed_unit]
Input:   nothing
Output:   estimated speed
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ get_angular_speed(void)
#else
int16_t get_angular_speed(void)
#endif
{
 return(speed_est);
}