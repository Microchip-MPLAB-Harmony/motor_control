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

uint8_t acceleration_count = 0;
uint8_t deceleration_count = 0;
int16_t    ram_abs;  
uint8_t      state_halt; 
uint16_t	 angle_incr;
uint16_t     acc_ramp;
uint16_t     dec_ramp;
uint8_t      direction_changed;
uint8_t      demand_dir;
uint16_t     speed_ref_filter;



/******************************************************************************
Safety variables
******************************************************************************/

uint16_t ref_abs;      /* speed reference absolute value 
                     (speed_ramp routine input, derived from POT input) 
                     [internal speed unit] */

stop_source_t motor_stop_source = NO_START_CMD;
/* variables used for phase lost check */


/* system phase [(d, q) reference system angular 
                position referred to alpha (u) axis] [internal angle unit] */
static ang_sincos_t  sysph;    

/* vector containing the PWM timer compare values */
static int32_t dutycycle[3];  

static vec3_t  outv3;      /* three-phases vector of output voltage reference [internal voltage unit] */

static vec2_t   
    outvab,      /* two-phases (a, b) vector of output voltage reference [internal voltage unit] */
    outvdq;      /* two-phases (d, q) vector of output voltage reference [internal voltage unit] */


/*******************************************************************************
Functions
*******************************************************************************/

/******************************************************************************
Function:     motorcontrol_vars_init
Description:  motor control variable initialization
Input:        nothing (uses some global variables)
Output:       nothing (modifies some global variables)
Note:         to be called once before starting the control functions              
******************************************************************************/
void motorcontrol_vars_init(void)
{
  state_run = 0;
  state_halt = 1;
  ext_speed_ref_rpm = 0;
  set_speed = START_SPEED_DEFAULT;
  direction_changed = 0;
  direction = 0;
  ref_abs = 0;  
  sysph.ang = 0; 
  switch_state = 0;
  acc_ramp = ACC_RAMP;
  dec_ramp = DEC_RAMP;
    
}


/******************************************************************************
Function:     pwm_modulation_reset
Description:  resets internal variables used in pwm modulation, and sets
              the inactive value into the pwm registers
Input:        nothing
Output:       nothing
******************************************************************************/
static inline void pwm_modulation_reset(void)
{
    outv3.u = 0;
    outv3.v = 0;
    outv3.w = 0;
    dutycycle[0] = (int32_t)PWM_HPER_TICKS;
    dutycycle[1] = (int32_t)PWM_HPER_TICKS;
    dutycycle[2] = (int32_t)PWM_HPER_TICKS;
    /*Using register address of TCC0 */
     
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)dutycycle[0]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)dutycycle[1]);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)dutycycle[2]);        

}

/******************************************************************************
Function:     pwm_modulation
Description:  output duties calc for SVPWM (3rd harmonic injected voltages)
Input:        nothing (uses global variables outv3)
Output:       nothing (directly calculate the duty cycles)
Note:         implements a SVPWM modulation (min-max);
 
******************************************************************************/

#ifdef RAM_EXECUTE
void  __ramfunc__ pwm_modulation(void)
#else
void pwm_modulation(void)
#endif
{
    int32_t voltage_offset;
	int32_t min_val;
	int32_t max_val;
	int32_t voltage_va3h,voltage_vb3h,voltage_vc3h;

	/*Find the minimum value among the three voltages 	 */

	/*Finding the minimum value between va and vb      	 */
	if(outv3.u <= outv3.v)
	{
		min_val = outv3.u;
	}
	else
	{
		min_val = outv3.v;
	}

	/*Finding the minimum value between vc and min_val  	 */
	if(outv3.w <= min_val)
	{
		min_val = outv3.w;
	}
	else
	{
		/* Do nothing */
	}

	/*Find the maximum value among the three voltages 	 */

	/*Finding the maximum value between va and vb      	 */
	if(outv3.u >= outv3.v)
	{
		max_val = outv3.u;
	}
	else
	{
		max_val = outv3.v;
	}

	/*	Finding the maximum value between vc and max_val  	 */
	if(outv3.w >= max_val)
	{
		max_val = outv3.w;
	}
	else
	{
		/*	Do nothing	*/
	}

	/*	Find the offset voltage from the minimum and maximum values	 */
	voltage_offset = (min_val + max_val)>>1;

	voltage_va3h = (outv3.u - voltage_offset);  
	voltage_vb3h = (outv3.v - voltage_offset);
	voltage_vc3h = (outv3.w - voltage_offset);

	dutycycle[0] = (uint16_t)((voltage_va3h>>1) + (PWM_HPER_TICKS>>1));	  
	dutycycle[1] = (uint16_t)((voltage_vb3h>>1) + (PWM_HPER_TICKS>>1));
	dutycycle[2] = (uint16_t)((voltage_vc3h>>1) + (PWM_HPER_TICKS>>1));	

}  /* end of function pwm_modulation()*/


/******************************************************************************
Function:     motorcontrol
Description:  motor control implementation
Input:        nothing (uses many global variables)
Output:       nothing (modifies many global variables, mainly the pwm timer compare values)
Note:         Finds the direction based on the Potentiometer reference value;
              Calculate the speed reference value from the Potentiometer ADC reading;
              Finds the direction change based on dynamic potentiometer adjustment;
              Compute the speed reference value in internal units;
              Accelerate or Decelerate the Ramp reference based on the Internal speed reference;
              then manages the V/Hz profile to find duty cycle to generate SVPWM for voltages 
              as follows:
                 Finds the angle to be incremented each time
                 Compute the instantaneous angle
                 Find the voltage magnitude required
                 Execute the Inverse part transform
                 Execute the Inverse Clarke transform
                 Execute the PWM modulation method for SVPWM generation
                 Update the duty cycle values to the TCC compare channels based on the direction
 
******************************************************************************/
#ifdef RAM_EXECUTE
void  __ramfunc__ motorcontrol(void)
#else
void motorcontrol(void)
#endif
{
  uint32_t	s32a;      
  
  speed_ref_filter = (uint16_t)(((SPEED_FILTER_COEFF*speed_ref_pot) + ((16-SPEED_FILTER_COEFF)*speed_ref_filter))>>4);  
  
  set_speed = (speed_ref_filter*MAX_MOTOR_SPEED)>>12;

    
  if(set_speed > MAX_MOTOR_SPEED)
  {
	  set_speed = MAX_MOTOR_SPEED;
  }
  
  if((demand_dir != direction) && (state_halt == 0U))
  {
  	 direction_changed = 1;
  		   	    
  } 
  if(( ram_abs == 0U) && (1U == direction_changed ))
  {
        
		  direction_changed = 0;
		  direction = demand_dir;
		  sysph.ang = 0;
  } 
      
  /* performs motor control if needed */
  if (0U != state_run)
  {
	  	if(direction_changed == 0U)
		{
			  ext_speed_ref_rpm = set_speed;
			  s32a = ext_speed_ref_rpm * MAX_SPEED_SCALED;
			  ref_abs =  (uint32_t) s32a / (uint32_t) MAX_MOTOR_SPEED;			  			  
		}
		else
		{
			  ref_abs = 0;
		}
  }
  else
  {
	 if(ram_abs == 0)
	 {
		 state_halt = 1;
	 }
  }
  
	if(ref_abs > ram_abs)
	{			  
		if(acceleration_count == 1)   // For every 2 times of PWM Period, the ram_abs incremented by 1.  The max speed is mapped to 2^14.
		{							   // For e.g every 1 times is 2*50 us = 0.1 ms, ram_abs incremented by acc_ramp.  So Zero to max speed achieved at 16384 by 1638 ms or 1.638 S.  	
			acceleration_count = 0;
			
				ram_abs += acc_ramp; //acc_ramp;
				if(ref_abs < ram_abs)
				{
					ram_abs = ref_abs;
				}			
		}
		else
		{
			acceleration_count++;
		}
	}
	
	if(ref_abs < ram_abs)
	{
		if(deceleration_count == 1)   // For every 2 times of PWM Period, the ram_abs decremented by 1.  The max speed is mapped to 2^14.
		{							   // For e.g every 1 times is 2*50 us = 0.1 ms, ram_abs decremented by dec_ramp.  So Max speed to Zero speed achieved at 16384 by 1638 ms or 1.638 S.
			deceleration_count = 0;
			
				ram_abs -= dec_ramp; //dec_ramp;
				if(ref_abs > ram_abs)
				{
					ram_abs = ref_abs;
				}
		}
		else
		{
			deceleration_count++;
		}
	}
	
	if(0U == state_halt)
	{	
		/* Computing the angle to be incremented for the current speed level */ 
		angle_incr = (uint32_t) ((uint32_t) (NUMBER_OF_POLES * ram_abs * MAX_MOTOR_SPEED)/(uint32_t)(30000 * PWM_FREQUENCY));
 	
		sysph.ang = sysph.ang + angle_incr;
		
		library_sincos(&sysph);
		
		s32a = (ram_abs * VF_CONSTANT)>>12;
		
		if(s32a < VF_OFFSET)
		{
			outvdq.x = 0;
			outvdq.y = (int32_t) VF_OFFSET;
		}
		else
		{
			outvdq.x = 0;
			outvdq.y = (int32_t) s32a;
		}

         /* voltage Inverse-Park transformation */
        library_dq_ab(&sysph, &outvdq, &outvab);
		
        /* voltage Inverse-Clarke transformation */
		library_ab_uvw(&outvab, &outv3);

        /* SVPWM, 3rd harmonic injection using Min and Max method */
        pwm_modulation();

	   if(direction == 0x08U)
	   {	
			  /*Using register address of TCC0 */
        TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)dutycycle[0]);
        TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)dutycycle[1]);
        TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)dutycycle[2]);
	   }
	   else
	   {           
             /*Using register address of TCC0 */
        TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)dutycycle[0]);
        TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)dutycycle[2]);
        TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)dutycycle[1]);
		
	   }
	   
  }
  else
  {
        pwm_modulation_reset();

        sysph.ang = 0;
        sysph.sin = 0;
        sysph.cos = (int16_t)BASE_VALUE_INT;

        outvdq.x = 0;
        outvdq.y = 0;
        outvab.x = 0;
        outvab.y = 0;    
     
		angle_incr = 0;
		ram_abs = 0;   
		direction = demand_dir;
		direction_changed = 0;
    }
   
}

void PWM_Output_Disable( void )
{
    TCC0_PWM24bitDutySet(TCC0_CHANNEL0,(uint32_t)HALF_PWM_HPER_TICKS);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL1,(uint32_t)HALF_PWM_HPER_TICKS);
    TCC0_PWM24bitDutySet(TCC0_CHANNEL2,(uint32_t)HALF_PWM_HPER_TICKS);
    
    /*Override all PWM outputs to low*/
    TCC0_PWMPatternSet((TCC_PATT_PGE0_Msk|TCC_PATT_PGE1_Msk|TCC_PATT_PGE2_Msk
            |TCC_PATT_PGE4_Msk|TCC_PATT_PGE5_Msk|TCC_PATT_PGE6_Msk),
            (TCC_PATT_PGE0(0)|TCC_PATT_PGE1(0)|TCC_PATT_PGE2(0)|TCC_PATT_PGE4(0)
            |TCC_PATT_PGE5(0)|TCC_PATT_PGE6(0)));
}

void PWM_Output_Enable( void)
{
    TCC0_PWMPatternSet(0x00,0x00);/*Disable PWM override*/
}

/* EOF motor_control.c */

