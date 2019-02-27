/*******************************************************************************
  System Definitions

  File Name:
    q14_generic_mcLib.h

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

#ifndef Q14_GENERIC_MCLIB_H
#define Q14_GENERIC_MCLIB_H

#include <stdint.h>
#include <sys/attribs.h>
#include "userparams.h"
/******************************************************************************
Macro definitions and typedefs
******************************************************************************/

typedef float   float32_t;

/* pi */
#ifdef FLOAT_PI
#undef FLOAT_PI
#endif	// FLOAT_PI
#define FLOAT_PI		( 3.141592654f )

/* base value for normalization */
#ifdef BASE_VALUE
#undef BASE_VALUE
#endif	// BASE_VALUE
#ifdef SH_BASE_VALUE
#undef SH_BASE_VALUE
#endif	// BASE_VALUE
#define SH_BASE_VALUE	( 14U )			// BASE_VALUE = 2^SHFT_BASE_VALUE
#define BASE_VALUE		((int16_t)( 1 << SH_BASE_VALUE ))
#define BASE_VALUE_INT          (16384U)
#define BASE_VALUE_FL            (16384.0f)

/* numerical constants (referred to BASE VALUE) */
#ifdef ONETHIRD
#undef ONETHIRD
#endif	// ONETHIRD
#define	ONETHIRD		(  5461 )		// BASE_VALUE * (1/3) = 5461.33333
#ifdef TWOTHIRDS
#undef TWOTHIRDS
#endif	// TWOTHIRDS
#define	TWOTHIRDS		( 10923 )		// BASE_VALUE * (2/3) = 10922.66666
#ifdef SQRT2
#undef SQRT2
#endif	// SQRT2
#define	SQRT2			( 23170 )		// BASE_VALUE * SQUAREROOT(2) = 23170.47501
#ifdef ONEBYSQRT2
#undef ONEBYSQRT2
#endif	// ONEBYSQRT2
#define	ONEBYSQRT2		( 11585 )		// BASE_VALUE / SQUAREROOT(2) = 11585.2375
#ifdef SQRT3
#undef SQRT3
#endif	// SQRT3
#define	SQRT3			( 28378 )		// BASE_VALUE * SQUAREROOT(3) = 28377.92043
#ifdef ONEBYSQRT3
#undef ONEBYSQRT3
#endif	// ONEBYSQRT3
#define	ONEBYSQRT3		(  9459 )		// BASE_VALUE / SQUAREROOT(3) = 9459.30681
#ifdef TWOBYSQRT3
#undef TWOBYSQRT3
#endif	// TWOBYSQRT3
#define	TWOBYSQRT3		( 18919 )		// BASE_VALUE / SQUAREROOT(3) = 18918.61362
#ifdef SQRT2BYSQRT3
#undef SQRT2BYSQRT3
#endif	// SQRT2BYSQRT3
#define SQRT2BYSQRT3	( 13377 )		// BASE_VALUE * SQUAREROOT(2/3) = 13377.47998
#ifdef SQRT3BYSQRT2
#undef SQRT3BYSQRT2
#endif	// SQRT3BYSQRT2
#define SQRT3BYSQRT2	( 20066 )		// BASE_VALUE * SQUAREROOT(3/2) = 20066.21997

/* angles definitions */
#ifdef PIFOURTHS
#undef PIFOURTHS
#endif	// PIFOURTHS
#define	PIFOURTHS		(  8192U )		// 0x2000 045
#ifdef PIHALVES
#undef PIHALVES
#endif	// PIHALVES
#define	PIHALVES		( 16384U )		// 0x4000 090
#ifdef THREEPIFOURTHS
#undef THREEPIFOURTHS
#endif	// THREEPIFOURTHS
#define	THREEPIFOURTHS	( 24576U )		// 0x6000 135
#ifdef PI
#undef PI
#endif	// PI
#define	PI				( 32768U )		// 0x8000 180
#ifdef FIVEPIFOURTHS
#undef FIVEPIFOURTHS
#endif	// FIVEPIFOURTHS
#define	FIVEPIFOURTHS	( 40960U )		// 0xA000 225
#ifdef THREEPIHALVES
#undef THREEPIHALVES
#endif	// THREEPIHALVES
#define	THREEPIHALVES	( 49152U )		// 0xC000 270
#ifdef SEVENPIFOURTHS
#undef SEVENPIFOURTHS
#endif	// SEVENPIFOURTHS
#define	SEVENPIFOURTHS	( 57344U )		// 0xE000 315
#ifdef TWOPI
#undef TWOPI
#endif	// TWOPI
#define	TWOPI			( 65536UL )		// 0x00010000 LONG; IF WORD ACCESS GIVES 0

/* angle structure */
typedef struct
{
	uint16_t		ang;	/* angle */
	int16_t			sin;	/* sin(angle) */
	int16_t			cos;	/* cos(angle) */
}	ang_sincos_t;

/* vector types definition */
typedef struct
{
	int16_t			u;		// first component
	int16_t			v;		// second component
	int16_t			w;		// third component
}	vec3_t;
typedef struct
{
	int16_t			x;		// first component
	int16_t			y;		// second component
}	vec2_t;
typedef struct
{
	uint16_t		r;		// amplitude
	ang_sincos_t	t;		// argument
}	vecp_t;

/* PI control structure */
typedef struct
{
	int16_t			kp;		// proportional gain
	uint16_t		shp;	// proportional gain shifts down
	int16_t			ki;		// integral gain
	uint16_t		shi;	// integral gain shifts down
	int16_t			hlim;	// upper clamp value
	int16_t			llim;	// lower clamp value
	int32_t			imem;	// integral term memory
}	pi_cntrl_t;

/* measurement units conversion constants (referred to internal representation
	of physical quantities) */
#define K_ANGLE		((float32_t)(TWOPI / (2.0 * FLOAT_PI)))


/******************************************************************************
Functions prototypes
******************************************************************************/

/* TRIGONOMETRIC FUNCTIONS ***************************************************/

/******************************************************************************
Function:		library_sin
Description:	y = BASE_VALUE * sin(ang)
Input:			ang = (PI / FLOAT_PI) * angle[rad], 0 <= ang < TWOPI
Output:			normalized sin value y, |y| <= BASE_VALUE
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ library_sin(uint16_t ang);
#else
int16_t library_sin(uint16_t ang);
#endif
/******************************************************************************
Function:		library_cos
Description:	y = BASE_VALUE * cos(ang)
Input:			ang = (PI / FLOAT_PI) * angle[rad], 0 <= ang < TWOPI
Output:			normalized cos value y, |y| <= BASE_VALUE
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ library_cos(uint16_t ang);
#else
int16_t library_cos(uint16_t ang);
#endif

/******************************************************************************
Function:		library_sincos
Description:	sin and cos calculation
Input:			t, angle structure address
Output:			nothing
Modifies:		angle structure fields t->sin and t->cos, using field t->ang
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void  __ramfunc__ library_sincos(ang_sincos_t *t);
#else
void library_sincos(ang_sincos_t *t);
#endif
/******************************************************************************
Function:		library_sinarcos
Description:	y = BASE_VALUE * sin(arcos(x / BASE_VALUE))
Input:			normalized cos(angle) value x, 0 <= x <= BASE_VALUE
Output:			normalized sin(angle) value y, 0 <= y <= BASE_VALUE
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t  __ramfunc__ library_sinarcos(int16_t x);
#else
int16_t library_sinarcos(int16_t x);
#endif 

/******************************************************************************
Function:		library_atan2
Description:	ang = (PI / FLOAT_PI) * arctan(y / x)
Input:			amplified value x = A * cos(angle),
				amplified value y = A * sin(angle),
					0 < A < 2^15
Output:			internal representation of angle: ang = (PI / FLOAT_PI) * angle
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
uint16_t __ramfunc__ library_atan2(int16_t x, int16_t y);
#else
uint16_t library_atan2(int16_t x, int16_t y);
#endif
/* END OF TRIGONOMETRIC FUNCTIONS ********************************************/


/* OTHER MATH FUNCTIONS ******************************************************/

/******************************************************************************
Function:		library_scat
Description:	calculation of the second cathetus of a right angled triangle
				(Pitagora theorem)
Input:			hypotenuse hypo
				first cathetus fcat
Output:			second cathetus
Notes:			if the first cathetus is negative, its absolute value is
				considered;
				if the first cathetus absolute value is greater or equal than
				the hypotenuse, the result will be zero (as a consequence, if
				the hypothenuse is zero or negative, the result will be zero)
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ library_scat(int16_t hypo, int16_t fcat);
#else
int16_t library_scat(int16_t hypo, int16_t fcat);
#endif 
/* END OF OTHER MATH FUNCTIONS ***********************************************/


/* TRANSFORMATION FUNCTIONS **************************************************/

/******************************************************************************
Function:		library_uvw_ab
Description:	unitary gain transformation (u, v, w)->(alpha, beta):
					alpha=(2u-v-w)/3, beta=(v-w)/sqrt(3)
Input:			uvw, input vector structure address
				ab, output vector structure address
Output:			nothing
Modifies:		x (a), y (b) components of ab vector
Note:			no limitation (omopolar component kept into account)
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ library_uvw_ab(const vec3_t *uvw, vec2_t *ab);
#else
void library_uvw_ab(const vec3_t *uvw, vec2_t *ab);
#endif
/******************************************************************************
Function:		library_ab_uvw
Description:	unitary gain transformation (alpha, beta)->(u, v, w):
					u=alpha, v=((sqrt(3)*beta-alpha)/2, w=-u-v
Input:			ab, input vector structure address
				uvw, output vector structure address
Modifies:		u, v, w components of uvw vector
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ library_ab_uvw(const vec2_t *ab, vec3_t *uvw);
#else
void library_ab_uvw(const vec2_t *ab, vec3_t *uvw);
#endif

/******************************************************************************
Function:		library_ab_dq
Description:	unitary gain transformation (alpha, beta)->(d, q):
					d=alpha*cos(internal_angle)+beta*sin(internal_angle)
					q=alpha*cos(internal_angle)-beta*sin(internal_angle)
Input:			t, angle structure address, where t->ang is the angular
					position of (d, q) reference system
				ab, input vector structure address
				dq, output vector structure address
Output:			nothing
Modifies:		x (d), y (q) components of dq vector
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ library_ab_dq(const ang_sincos_t *t, const vec2_t *ab, vec2_t *dq);
#else
void library_ab_dq(const ang_sincos_t *t, const vec2_t *ab, vec2_t *dq);
#endif
/******************************************************************************
Function:		library_dq_ab
Description:	unitary gain transformation (d, q)->(alpha, beta):
					alpha=d*cos(internal_angle)-q*sin(internal_angle)
					beta=d*sin(internal_angle)+q*cos(internal_angle)
Input:			t, angle structure address, where t->ang is the angular
					position of (d, q) reference system
				dq, input vector structure address
				ab, output vector structure address
Output:			nothing
Modifies:		x (a), y (b) components of ab vector
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void  __ramfunc__ library_dq_ab(const ang_sincos_t *t, const vec2_t *dq, vec2_t *ab);
#else
void library_dq_ab(const ang_sincos_t *t, const vec2_t *dq, vec2_t *ab);
#endif
/******************************************************************************
Function:		library_xy_rt
Description:	transformation (x, y)->(ro, theta)
Input:			xy, input vector structure address
				rt, output vector structure address
Output:			nothing
Modifies:		r (amplitude), t (argument) components of rt vector
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ library_xy_rt(const vec2_t *xy, vecp_t *rt);
#else
void library_xy_rt(const vec2_t *xy, vecp_t *rt);
#endif
/******************************************************************************
Function:		library_rt_xy
Description:	transformation (ro, theta)->(alpha, beta)
Input:			rt, input vector structure address
				xy, output vector structure address
Output:			nothing
Modifies:		x, y components of xy vector
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ library_rt_xy(const vecp_t *rt, vec2_t *xy);
#else
void library_rt_xy(const vecp_t *rt, vec2_t *xy);
#endif 
/* END OF TRANSFORMATION FUNCTIONS *******************************************/


/* CONTROL FUNCTIONS ********************************************************/

/******************************************************************************
Function:		library_pi_control
Description:	PI control with anti-windup
Input:			error erl
				pointer to the pi control structure pi
Output:			control output
Modifies:		integral memory im of the control
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ library_pi_control(int32_t erl, pi_cntrl_t *pi);
#else
int16_t library_pi_control(int32_t erl, pi_cntrl_t *pi);
#endif

/* END OF CONTROL FUNCTIONS *************************************************/


#endif // Q14_GENERIC_MCLIB_H
