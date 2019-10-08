/*******************************************************************************
  System Definitions

  File Name:
    q14_rolo_wm_mcLib.h

  Summary:
    Header file which contains variables and function prototypes for Motor Control.
 
  Description:
    This file contains variables and function prototypes which are generally used in Motor Control.
    Implemented in Q2.14 Fixed Point Arithmetic.
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

#ifndef Q14_ROLO_WM_MCLIB_H
#define Q14_ROLO_WM_MCLIB_H

#include "userparams.h"
/*******************************************************************************
Macro definitions
*******************************************************************************/
#define	OBS_H_GAIN			( 0.2f )				/* RANGE: 0.2 - 0.5 */
#define	OBS_C0_GAIN			( 1.0f - OBS_H_GAIN )	/* > 0 */
#define	OBS_MINFREQ_HZ		( 3.0f )
#define	OBS_MINSPEED_R_S	((float32_t)(2.0f * FLOAT_PI * OBS_MINFREQ_HZ))
#define OBS_MAXSHIFTS		( 32 )



/* uncomment the following macro to enable phase clamping to enhance waveform */
/* #define PH_CLAMP */
#define MAX_DSPEED			( 300 )

/*	only the cross-coupling coefficients are speed dependent, and their value is usually
	much lesser than the others; so in first approximation they could be neglected, saving
	a lot of computation time; furthermore, neglecting them could lead to a higher noise immunity */
/* uncomment the following macro to enable the cross-coupling observer terms */
 #define CROSS_COUPLING_ENABLED 

/* uncomment the following macro to enable amplification clamping */
/* #define AMP_CLAMP */


extern uint16_t flx_arg_mem;
extern uint16_t bemf_arg_mem;
extern uint16_t flx_arg;
extern uint16_t bemf_arg;
/*******************************************************************************
Type definitions
*******************************************************************************/

/*	to make the calculations with enough resolution, the coefficients are represented
	with an amplified value and the number of amplification shifts */
typedef struct
{
	int16_t		val;
	uint16_t	shr;
}	coef_t;


/******************************************************************************
Function:		estimation_set_base_values
Description:	base values setting for the observer library
Input:			sampling frequency [Hz]
				base speed [rad/sec]
				base voltage [V]
				base current [A]
Output:			nothing
Modifies:		observer internal constants
******************************************************************************/
void estimation_set_base_values(float32_t samfreq, float32_t basespe,
								float32_t basevol, float32_t basecur);

/******************************************************************************
Function:		estimation_set_parameters
Description:	Luenberger observer coefficients calculation
Input:			stator resistance [Ohm]
				synchronous inductance [Hen]
Output:			nothing
Modifies:		observer coefficients
******************************************************************************/
void estimation_set_parameters(float32_t rsta, float32_t lsyn);

/******************************************************************************
Function:		position_and_speed_estimation
Description:	performs the position and speed estimation
Input:			reference speed [internal_speed_unit] rs
				applied voltage vector (in stationary reference frame)
				measured current vector (in stationary reference frame)
Output:			nothing (updates internal variables)
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i);
#else
void position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i);
#endif

/******************************************************************************
Function:		bemf_position_and_speed_estimation
Description:	performs the position and speed estimation of bemf vector
Input:			reference speed [internal_speed_unit] rs
				applied voltage vector (in stationary reference frame)
				measured current vector (in stationary reference frame)
Output:			nothing (updates internal variables)
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ bemf_position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i);
#else
void bemf_position_and_speed_estimation(int16_t rs, const vec2_t *v, const vec2_t *i);
#endif


/******************************************************************************
Function:		estimation_alignment
Description:	aligns the observer
Input:			reference speed [internal_speed_unit] rs
				applied voltage vector (in stationary reference frame)
				measured current vector (in stationary reference frame)
Output:			nothing (updates internal variables)
******************************************************************************/
void estimation_alignment(int16_t rs, const vec2_t *v, const vec2_t *i);

/******************************************************************************
Function:		bemf_estimation_alignment
Description:	aligns the observer
Input:			reference speed [internal_speed_unit] rs
				applied voltage vector (in stationary reference frame)
				measured current vector (in stationary reference frame)
Output:			nothing (updates internal variables)
******************************************************************************/
void bemf_estimation_alignment(int16_t rs, const vec2_t *v, const vec2_t *i);
/******************************************************************************
Function:		get_angular_position
Description:	returns the estimated position [internal_angle_unit]
Input:			nothing
Output:			compensated estimated position
******************************************************************************/
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ get_angular_position(void);
#else
uint16_t get_angular_position(void);
#endif

/******************************************************************************
Function:		get_bemf_angular_position
Description:	returns the estimated position [internal_angle_unit]
Input:			nothing
Output:			compensated estimated position
******************************************************************************/
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ get_bemf_angular_position(void);
#else
uint16_t get_bemf_angular_position(void);
#endif

/******************************************************************************
Function:		get_angular_speed
Description:	returns the estimated speed [internal_speed_unit]
Input:			nothing
Output:			estimated speed
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ get_angular_speed(void);
#else
int16_t get_angular_speed(void);
#endif


/*******************************************************************************
Private functions declaration
*******************************************************************************/


/******************************************************************************
Function:		obs_coef_calc
Description:	Luenberger observer coefficients calculation
Input:			reference speed (only to get its sign)
Output:			nothing
Modifies:		observer variable coefficients
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ obs_coef_calc(int16_t spref);
#else
void obs_coef_calc(int16_t spref);
#endif
/*******************************************************************************
Function:		shfdw1
Description:	arithmetic shift down, which goes to zero also with negative
				numbers
Input:			number to be shifted (a), number of shifts (s)
Output:			a >> s
Note:			symmetric behaviour, unlike the assembly instruction
*******************************************************************************/
#ifdef RAM_EXECUTE
int32_t __ramfunc__ shfdw1(int32_t a, uint16_t s);
#else
int32_t shfdw1(int32_t a, uint16_t s);
#endif
/*******************************************************************************
Function:		shfdw2
Description:	arithmetic shift down, which goes to zero also with negative
				numbers, but keeps output >=1 (<=-1) if the input is >1 (<-1)
Input:			number to be shifted (a), number of shifts (s)
Output:			a >> s
Note:			useful to reset the filters memories
*******************************************************************************/
#ifdef RAM_EXECUTE
int32_t __ramfunc__ shfdw2(int32_t a, uint16_t s);
#else
int32_t shfdw2(int32_t a, uint16_t s);
#endif


/******************************************************************************
Function:		lunberger_observer
Description:	bemf reduced order observer implementation
Input:			voltage and current vectors in the static reference frame
Output:			nothing
Modifies:		observer status and estimated bemf vectors
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ lunberger_observer(const vec2_t *v, const vec2_t *i);
#else
void lunberger_observer(const vec2_t *v, const vec2_t *i);
#endif
/*******************************************************************************
Function:		phase_estimation
Description:	estimation of rotor position using bemf vector
Input:			nothing (uses global variable bemf vector)
Output:			nothing (modifies global variable flx_arg)
*******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ phase_estimation(void);
#else
void phase_estimation(void);
#endif
/*******************************************************************************
Function:		phase_estimation_init
Description:	init routine for use of phase estimation
Input:			nothing (uses global variable bemf vector)
Output:			nothing (modifies global variable flx_arg)
*******************************************************************************/
void phase_estimation_init(void);

/*******************************************************************************
Function:		phase_estimation_init
Description:	init routine for use of phase estimation
Input:			nothing (uses global variable bemf vector)
Output:			nothing (modifies global variable flx_arg)
*******************************************************************************/
void bemf_phase_estimation_init(void);
/*******************************************************************************
Function:		speed_filter
Description:	speed estimation, using a fourth order low-pass filter
Input:			nothing (uses delta position in one step)
Output:			nothing (modifies global variable speed_est)
*******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ speed_filter(void);
#else
void speed_filter(void);
#endif

/*******************************************************************************
Function:		bemf_speed_filter
Description:	bemf speed estimation, using a fourth order low-pass filter
Input:			nothing (uses delta position in one step)
Output:			nothing (modifies global variable speed_est)
*******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ bemf_speed_filter(void);
#else
void bemf_speed_filter(void);
#endif

/******************************************************************************
Function:		speed_filter_init
Description:
Input:			speed [internal_speed_unit]
Output:			nothing
Modifies:		internal speed estimation filter memories
******************************************************************************/
void speed_filter_init(int16_t speed);

/******************************************************************************
Function:		delay_comp
Description:	calculation of the phase error due to algorithm medium delay
Input:			nothing (uses internal speed filter memory)
Output:			phase delay (medium time delay is 1.5 sampling periods)
******************************************************************************/
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ delay_comp(void);
#else
uint16_t delay_comp(void);
#endif

#endif // Q14_GENERIC_MCLIB_H
