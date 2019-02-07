/*******************************************************************************
 Generic Motor Control Library 

  Company:
    Microchip Technology Inc.

  File Name:
    q14_generic_mcLib.c

  Summary:
    Generic Motor Control Library implemented in Q14 fixed point arithmetic.

  Description:
    This file implements generic vector motor control related functions
 *  like Trigonometric, Transformations, PI Control
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

#include <math.h>
#include <stdint.h>
#include "q14_generic_mcLib.h"
#include "userparams.h"
#include "definitions.h"


/*******************************************************************************
Macro definitions
*******************************************************************************/

/* trigonometric tables */
#define SH_TRITAB_DIM	( 8U )
#define TRITAB_DIM		( (uint16_t)1U << (uint16_t)SH_TRITAB_DIM )
#define SH_SINTAB		( 14U - SH_TRITAB_DIM )	// PIHALVES=(2^16)/4=2^14
#define SH_SACTAB		( SH_BASE_VALUE - SH_TRITAB_DIM )
#define SH_ACTTAB		( SH_BASE_VALUE - SH_TRITAB_DIM )
#define	SEL1Q			( 0x3FFFU )	/* select first_quarter_value */
#define	ISCOS			( 0x4000U )	/* table(first_quarter_value) gives cos */
#define	ISNEG			( 0x8000U )	/* sin is neg */


/******************************************************************************
Private global variables
******************************************************************************/
int32_t g_s32i, g_s32p, g_s32t;
	int16_t	g_s16e, g_s16t;

/* table y = BASE_VALUE * sin((pi/2) * x / TRITAB_DIM)
 0 <= x <= TRITAB_DIM, 0 <= y <= BASE_VALUE (first quarter) */
static const int16_t sin_table[TRITAB_DIM + 1U] = {
	    0,   101,   201,   302,   402,   503,   603,   704,	//   0, ..,   7
	  804,   904,  1005,  1105,  1205,  1306,  1406,  1506,	//   8, ..,  15
	 1606,  1706,  1806,  1906,  2006,  2105,  2205,  2305,	//  16, ..,  23
	 2404,  2503,  2603,  2702,  2801,  2900,  2999,  3098,	//  24, ..,  31
	 3196,  3295,  3393,  3492,  3590,  3688,  3786,  3883,	//  32, ..,  39
	 3981,  4078,  4176,  4273,  4370,  4467,  4563,  4660,	//  40, ..,  47
	 4756,  4852,  4948,  5044,  5139,  5235,  5330,  5425,	//  48, ..,  55
	 5520,  5614,  5708,  5803,  5897,  5990,  6084,  6177,	//  56, ..,  63
	 6270,  6363,  6455,  6547,  6639,  6731,  6823,  6914,	//  64, ..,  71
	 7005,  7096,  7186,  7276,  7366,  7456,  7545,  7635,	//  72, ..,  79
	 7723,  7812,  7900,  7988,  8076,  8163,  8250,  8337,	//  80, ..,  87
	 8423,  8509,  8595,  8680,  8765,  8850,  8935,  9019,	//  88, ..,  95
	 9102,  9186,  9269,  9352,  9434,  9516,  9598,  9679,	//  96, .., 103
	 9760,  9841,  9921, 10001, 10080, 10159, 10238, 10316,	// 104, .., 111
	10394, 10471, 10549, 10625, 10702, 10778, 10853, 10928,	// 112, .., 119
	11003, 11077, 11151, 11224, 11297, 11370, 11442, 11514,	// 120, .., 127
	11585, 11656, 11727, 11797, 11866, 11935, 12004, 12072,	// 128, .., 135
	12140, 12207, 12274, 12340, 12406, 12472, 12537, 12601,	// 136, .., 143
	12665, 12729, 12792, 12854, 12916, 12978, 13039, 13100,	// 144, .., 151
	13160, 13219, 13279, 13337, 13395, 13453, 13510, 13567,	// 152, .., 159
	13623, 13678, 13733, 13788, 13842, 13896, 13949, 14001,	// 160, .., 167
	14053, 14104, 14155, 14206, 14256, 14305, 14354, 14402,	// 168, .., 175
	14449, 14497, 14543, 14589, 14635, 14680, 14724, 14768,	// 176, .., 183
	14811, 14854, 14896, 14937, 14978, 15019, 15059, 15098,	// 184, .., 191
	15137, 15175, 15213, 15250, 15286, 15322, 15357, 15392,	// 192, .., 199
	15426, 15460, 15493, 15525, 15557, 15588, 15619, 15649,	// 200, .., 207
	15679, 15707, 15736, 15763, 15791, 15817, 15843, 15868,	// 208, .., 215
	15893, 15917, 15941, 15964, 15986, 16008, 16029, 16049,	// 216, .., 223
	16069, 16088, 16107, 16125, 16143, 16160, 16176, 16192,	// 224, .., 231
	16207, 16221, 16235, 16248, 16261, 16273, 16284, 16295,	// 232, .., 239
	16305, 16315, 16324, 16332, 16340, 16347, 16353, 16359,	// 240, .., 247
	16364, 16369, 16373, 16376, 16379, 16381, 16383, 16384,	// 248, .., 255
	16384};													// 256

/* table y = BASE_VALUE * sin(acos(x / TRITAB_DIM))
 0 <= x <= TRITAB_DIM, 0 <= y <= BASE_VALUE (first quarter) */
static const uint16_t library_tbsac[TRITAB_DIM + 1U] = {
	16384, 16384, 16383, 16383, 16382, 16381, 16379, 16378, //   0, ..,   7
	16376, 16374, 16371, 16369, 16366, 16363, 16359, 16356, //   8, ..,  15
	16352, 16348, 16343, 16339, 16334, 16329, 16323, 16318, //  16, ..,  23
	16312, 16306, 16299, 16293, 16286, 16279, 16271, 16263, //  24, ..,  31
	16255, 16247, 16239, 16230, 16221, 16212, 16202, 16193, //  32, ..,  39
	16183, 16173, 16162, 16151, 16140, 16129, 16117, 16106, //  40, ..,  47
	16093, 16081, 16068, 16056, 16042, 16029, 16015, 16001, //  48, ..,  55
	15987, 15973, 15958, 15943, 15928, 15912, 15896, 15880, //  56, ..,  63
	15864, 15847, 15830, 15813, 15795, 15778, 15760, 15741, //  64, ..,  71
	15723, 15704, 15685, 15665, 15645, 15625, 15605, 15584, //  72, ..,  79
	15563, 15542, 15521, 15499, 15477, 15455, 15432, 15409, //  80, ..,  87
	15386, 15362, 15338, 15314, 15289, 15265, 15240, 15214, //  88, ..,  95
	15188, 15162, 15136, 15109, 15082, 15055, 15027, 14999, //  96, .., 103
	14971, 14942, 14914, 14884, 14855, 14825, 14794, 14764, // 104, .., 111
	14733, 14701, 14670, 14638, 14605, 14573, 14540, 14506, // 112, .., 119
	14472, 14438, 14404, 14369, 14334, 14298, 14262, 14226, // 120, .., 127
	14189, 14152, 14114, 14076, 14038, 13999, 13960, 13921, // 128, .., 135
	13881, 13840, 13800, 13759, 13717, 13675, 13632, 13590, // 136, .., 143
	13546, 13502, 13458, 13414, 13368, 13323, 13277, 13230, // 144, .., 151
	13183, 13136, 13088, 13040, 12991, 12941, 12891, 12841, // 152, .., 159
	12790, 12738, 12686, 12634, 12581, 12527, 12473, 12418, // 160, .., 167
	12362, 12306, 12250, 12193, 12135, 12077, 12018, 11958, // 168, .., 175
	11898, 11837, 11775, 11713, 11650, 11586, 11522, 11457, // 176, .., 183
	11391, 11325, 11257, 11189, 11121, 11051, 10980, 10909, // 184, .., 191
	10837, 10764, 10690, 10615, 10540, 10463, 10385, 10307, // 192, .., 199
	10227, 10147, 10065,  9982,  9898,  9813,  9727,  9640, // 200, .., 207
	 9551,  9461,  9370,  9278,  9184,  9089,  8992,  8894, // 208, .., 215
	 8794,  8692,  8589,  8485,  8378,  8269,  8159,  8046, // 216, .., 223
	 7932,  7815,  7696,  7574,  7450,  7324,  7194,  7062, // 224, .., 231
	 6926,  6787,  6645,  6499,  6349,  6194,  6035,  5871, // 232, .., 239
	 5701,  5526,  5344,  5155,  4957,  4751,  4535,  4306, // 240, .., 247
	 4064,  3805,  3526,  3222,  2885,  2501,  2044,  1447, // 248, .., 255
	    0};							// 256

/* table y = ((PI / FLOAT_PI) * atan(x / TRITAB_DIM))
 0 <= x <= TRITAB_DIM, 0 <= y <= PIFOURTHS (first half quarter) */
static const int16_t library_tbact[TRITAB_DIM + 1U] = {
	    0,    41,    81,   122,   163,   204,   244,   285, //   0, ..,   7
	  326,   367,   407,   448,   489,   529,   570,   610, //   8, ..,  15
	  651,   692,   732,   773,   813,   854,   894,   935, //  16, ..,  23
	  975,  1015,  1056,  1096,  1136,  1177,  1217,  1257, //  24, ..,  31
	 1297,  1337,  1377,  1417,  1457,  1497,  1537,  1577, //  32, ..,  39
	 1617,  1656,  1696,  1736,  1775,  1815,  1854,  1894, //  40, ..,  47
	 1933,  1973,  2012,  2051,  2090,  2129,  2168,  2207, //  48, ..,  55
	 2246,  2285,  2324,  2363,  2401,  2440,  2478,  2517, //  56, ..,  63
	 2555,  2594,  2632,  2670,  2708,  2746,  2784,  2822, //  64, ..,  71
	 2860,  2897,  2935,  2973,  3010,  3047,  3085,  3122, //  72, ..,  79
	 3159,  3196,  3233,  3270,  3307,  3344,  3380,  3417, //  80, ..,  87
	 3453,  3490,  3526,  3562,  3599,  3635,  3670,  3706, //  88, ..,  95
	 3742,  3778,  3813,  3849,  3884,  3920,  3955,  3990, //  96, .., 103
	 4025,  4060,  4095,  4129,  4164,  4199,  4233,  4267, // 104, .., 111
	 4302,  4336,  4370,  4404,  4438,  4471,  4505,  4539, // 112, .., 119
	 4572,  4605,  4639,  4672,  4705,  4738,  4771,  4803, // 120, .., 127
	 4836,  4869,  4901,  4933,  4966,  4998,  5030,  5062, // 128, .., 135
	 5094,  5125,  5157,  5188,  5220,  5251,  5282,  5313, // 136, .., 143
	 5344,  5375,  5406,  5437,  5467,  5498,  5528,  5559, // 144, .., 151
	 5589,  5619,  5649,  5679,  5708,  5738,  5768,  5797, // 152, .., 159
	 5826,  5856,  5885,  5914,  5943,  5972,  6000,  6029, // 160, .., 167
	 6058,  6086,  6114,  6142,  6171,  6199,  6227,  6254, // 168, .., 175
	 6282,  6310,  6337,  6365,  6392,  6419,  6446,  6473, // 176, .., 183
	 6500,  6527,  6554,  6580,  6607,  6633,  6660,  6686, // 184, .., 191
	 6712,  6738,  6764,  6790,  6815,  6841,  6867,  6892, // 192, .., 199
	 6917,  6943,  6968,  6993,  7018,  7043,  7068,  7092, // 200, .., 207
	 7117,  7141,  7166,  7190,  7214,  7238,  7262,  7286, // 208, .., 215
	 7310,  7334,  7358,  7381,  7405,  7428,  7451,  7475, // 216, .., 223
	 7498,  7521,  7544,  7566,  7589,  7612,  7635,  7657, // 224, .., 231
	 7679,  7702,  7724,  7746,  7768,  7790,  7812,  7834, // 232, .., 239
	 7856,  7877,  7899,  7920,  7942,  7963,  7984,  8005, // 240, .., 247
	 8026,  8047,  8068,  8089,  8110,  8131,  8151,  8172, // 248, .., 255
	 8192};							// 256



/******************************************************************************
Public functions
******************************************************************************/

/******************************************************************************
Function:		library_sin
Description:	y = BASE_VALUE * sin(ang)
Input:			ang = (PI / FLOAT_PI) * angle[rad], 0 <= ang < TWOPI
Output:			normalized sin value y, |y| <= BASE_VALUE
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ library_sin(uint16_t ang)
#else
int16_t library_sin(uint16_t ang)
#endif
{
	uint16_t	a;
	int16_t		y;

	a = ang & SEL1Q; /* select angle in the first quarter (<= PIHALVES) */
	if((ISCOS & ang) != 0U)
	{
	  a = PIHALVES - a;
	}
	y = sin_table[a >> SH_SINTAB];
	return (((ISNEG & ang) != 0U)? -y: y);
}

/******************************************************************************
Function:		library_cos
Description:	y = BASE_VALUE * cos(ang)
Input:			ang = (PI / FLOAT_PI) * angle[rad], 0 <= ang < TWOPI
Output:			normalized cos value y, |y| <= BASE_VALUE
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ library_cos(uint16_t ang)
#else
int16_t library_cos(uint16_t ang)
#endif
{
	uint16_t	a;
	int16_t		y;
        uint16_t  ang_temp;

	/* overflow is OK here due to angle periodicity */
	ang_temp = ang + PIHALVES;
        a = ang_temp  & SEL1Q;  /* select angle in the first quarter (<= PIHALVES) */
	if((ISCOS & ang_temp) != 0U)
	{
		a = PIHALVES - a;
	}
	y = sin_table[a >> SH_SINTAB];
	return (((ISNEG & ang_temp) != 0U )? -y: y);
}

/******************************************************************************
Function:		library_sincos
Description:	sin and cos calculation
Input:			t, angle structure address
Output:			nothing
Modifies:		angle structure fields t->sin and t->cos, using field t->ang
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void  __ramfunc__ library_sincos(ang_sincos_t *t)
#else
void library_sincos(ang_sincos_t *t)
#endif
{
	(t->sin) = library_sin(t->ang);
	(t->cos) = library_cos(t->ang);
}

/******************************************************************************
Function:		library_sinarcos
Description:	y = BASE_VALUE * sin(arcos(x / BASE_VALUE))
Input:			normalized cos(angle) value x, 0 <= x <= BASE_VALUE
Output:			normalized sin(angle) value y, 0 <= y <= BASE_VALUE
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t  __ramfunc__ library_sinarcos(int16_t x)
#else
int16_t library_sinarcos(int16_t x)
#endif
{
	int16_t		y;
        int16_t         x_temp;
	x_temp = x;
        if((-(int16_t)BASE_VALUE_INT >= x) || ((int16_t)BASE_VALUE_INT <= x))
	{
		y = 0;
	}
	else
	{
		if(0 > x)
		{
			x_temp = -x;
		}
		y = (int16_t)library_tbsac[((uint16_t)x_temp) >> (uint16_t)SH_SACTAB];
	}
	return (y);
}

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
uint16_t  __ramfunc__ library_atan2(int16_t x, int16_t y)
#else
uint16_t library_atan2(int16_t x, int16_t y)
#endif
{
	uint32_t u32a;
 	uint16_t u16a, off, sgn, a, b;

	if(0 == y)
	{
		if(0 > x)
		{
			u16a = PI;
		}
		else
		{
			u16a = 0;
		}
	}
	else if(0 == x)
	{
		if(0 > y)
		{
			u16a = THREEPIHALVES;
		}
		else
		{
			u16a = PIHALVES;
		}
	}
	else
	{
		if(0 > y)
		{
			if(-32768 == y)
			{
				b = 32767;
			}
			else
			{
				b = (uint16_t)-y;
			}
			if(0 > x)	// x < 0, y < 0
			{
				if(-32768 == x)
				{
					a = 32767;
				}
				else
				{
					a = (uint16_t)-x;
				}
				off = PI;
				sgn = 0;
			}
			else		// x > 0, y < 0
			{
				a = (uint16_t)x;
				off = 0;
				sgn = 1;
			}
		}
		else
		{
			b = (uint16_t)y;
			if(0 > x)	// x < 0, y > 0
			{
				if(-32768 == x)
				{
					a = 32767;
				}
				else
				{
					a = (uint16_t)-x;
				}
				off = PI;
				sgn = 1;
			}
			else		// x > 0, y > 0
			{
				a = (uint16_t)x;
				off = 0;
				sgn = 0;
			}
		}
		if(b == a)
		{
			u16a = PIFOURTHS;
		}
		else if(b < a)
		{
			u32a = (uint32_t)b * (uint32_t)BASE_VALUE_INT;
			u16a = (uint16_t)(u32a / a);
			u16a = (uint16_t)library_tbact[u16a >> (uint16_t)SH_ACTTAB];
		}
		else
		{
			u32a = (uint32_t)a * (uint32_t)BASE_VALUE_INT;
			u16a = (uint16_t)(u32a / b);
			u16a = (uint16_t)library_tbact[u16a >> (uint16_t)SH_ACTTAB];
			u16a = PIHALVES - u16a;	
                        /* overflow is OK here! */
		}
		if(0U != sgn)
		{
			u16a = off - u16a;		// overflow is OK here!
		}
		else
		{
			u16a = off + u16a;		// overflow is OK here!
		}
	}
	return(u16a);

}	/* end of function library_atan2(...) */

/******************************************************************************
Function:		library_scat
Description:	calculation of the second cathetus of a right angled triangle
				(pythagoras theorem)
Input:			hypotenuse hypo
				first cathetus fcat
Output:			second cathetus
Notes:			if the first cathetus is negative, its absolute value is
				considered;
				if the first cathetus absolute value is greater or equal than
				the hypotenuse, the result will be zero (as a consequence, if
				the hypotenuse is zero or negative, the result will be zero)
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t  __ramfunc__ library_scat(int16_t hypo, int16_t fcat)
#else
int16_t library_scat(int16_t hypo, int16_t fcat)
#endif 
{
	int32_t s32a;
	int16_t	s16a;
        int16_t fcat_temp;
        fcat_temp = fcat;
	if(0 > fcat_temp)
	{
		if(-32768 == fcat_temp)
		{
			fcat_temp = 32767;
		}
		else
		{
			fcat_temp = -fcat_temp;
		}
	}
	if(fcat_temp < hypo)
	{
		s32a = ((int32_t)fcat_temp) * (int32_t)BASE_VALUE_INT;
		s16a = (int16_t)(s32a / hypo);
		s16a = library_sinarcos(s16a);
		s32a = ((int32_t)s16a) * ((int32_t)hypo);
        s16a = (int16_t)(s32a >> SH_BASE_VALUE);
	}
	else
	{
		s16a = 0;
	}
	return(s16a);
}

/******************************************************************************
Function:		library_uvw_ab
Description:	unitary gain transformation (u, v, w)->(alpha, beta):
					alpha=(2u-v-w)/3, beta=(v-w)/sqrt(3)
Input:			uvw, input vector structure address
				ab, output vector structure address
Output:			nothing
Modifies:		x (a), y (b) components of ab vector
Note:			no limitation (homopolar component kept into account)
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void  __ramfunc__ library_uvw_ab(const vec3_t *uvw, vec2_t *ab)
#else
void library_uvw_ab(const vec3_t *uvw, vec2_t *ab)
#endif
{
	int32_t	s32a;

	/* alpha, direct component in the static reference frame */
	s32a = ((int32_t)(uvw->u)) * TWOTHIRDS;
	s32a -= (((int32_t)(uvw->v)) * ONETHIRD);
	s32a -= (((int32_t)(uvw->w)) * ONETHIRD);
    (ab->x) = (int16_t)(s32a >> SH_BASE_VALUE);

	/* beta, quadrature component in the static reference frame */
	s32a = (((int32_t)(uvw->v)) * ONEBYSQRT3);
	s32a -= (((int32_t)(uvw->w)) * ONEBYSQRT3);
	(ab->y) = (int16_t)(s32a >> SH_BASE_VALUE);
}

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
void __ramfunc__ library_ab_uvw(const vec2_t *ab, vec3_t *uvw)
#else
void library_ab_uvw(const vec2_t *ab, vec3_t *uvw)
#endif
{
	int32_t s32a;

	/* u */
	(uvw->u) = (ab->x);

	/* v */
	s32a = ((int32_t)(ab->y)) * SQRT3;
    s32a >>= SH_BASE_VALUE;
	s32a -= (ab->x);
    (uvw->v) = (int16_t)(s32a >> 1);

	/* w */
	(uvw->w) = -(uvw->u) - (uvw->v);
}

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
void __ramfunc__ library_ab_dq(const ang_sincos_t *t, const vec2_t *ab, vec2_t *dq)
#else
void library_ab_dq(const ang_sincos_t *t, const vec2_t *ab, vec2_t *dq)
#endif
{
	int32_t s32a;
	/* d, direct component in the rotating reference frame */
	s32a = ((int32_t)(ab->x)) * ((int32_t)(t->cos));
	s32a += (((int32_t)(ab->y)) * ((int32_t)(t->sin)));
	(dq->x) = (int16_t)(s32a >> SH_BASE_VALUE);

	/* q, quadrature current component in the rotating reference frame */
	s32a = ((int32_t)(ab->y)) * ((int32_t)(t->cos));
	s32a -= (((int32_t)(ab->x)) * ((int32_t)(t->sin)));
	(dq->y) = (int16_t)(s32a >> SH_BASE_VALUE);
}

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
void  __ramfunc__ library_dq_ab(const ang_sincos_t *t, const vec2_t *dq, vec2_t *ab)
#else
void library_dq_ab(const ang_sincos_t *t, const vec2_t *dq, vec2_t *ab)
#endif
{
	int32_t s32a;
	/* alpha, direct component in the static reference frame */
	s32a = ((int32_t)(dq->x)) * ((int32_t)(t->cos));
	s32a -= (((int32_t)(dq->y)) * ((int32_t)(t->sin)));
	(ab->x) = (int16_t)(s32a >> SH_BASE_VALUE);

	/* beta, quadrature component in the static reference frame */
	s32a = ((int32_t)(dq->x)) * ((int32_t)(t->sin));
	s32a += (((int32_t)(dq->y)) * ((int32_t)(t->cos)));
	(ab->y) = (int16_t)(s32a >> SH_BASE_VALUE);
}

/******************************************************************************
Function:		library_xy_rt
Description:	transformation (x, y)->(ro, theta) [cartesian to polar coordinates]
Input:			xy, input vector structure address
				rt, output vector structure address
Output:			nothing
Modifies:		r (amplitude), t (argument) components of rt vector
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ library_xy_rt(const vec2_t *xy, vecp_t *rt)
#else
void library_xy_rt(const vec2_t *xy, vecp_t *rt)
#endif
{
	int32_t	s32a;
    int16_t temp;

	((rt->t).ang) = library_atan2(xy->x, xy->y);
	library_sincos(&(rt->t));
	if(	((PIFOURTHS < (rt->t).ang)	&& (THREEPIFOURTHS > (rt->t).ang)) ||
		((FIVEPIFOURTHS < (rt->t).ang)	&& (SEVENPIFOURTHS > (rt->t).ang)) )
	{	/* |sin(ang)|>|cos(ang)| */
		s32a = ((int32_t)(xy->y)) * (int32_t)BASE_VALUE_INT;
		temp =  (int16_t)(s32a / ((rt->t).sin)) ;
        (rt->r) = (uint16_t) temp;
	}
	else
	{	/* |sin(ang)|<=|cos(ang)|*/
		s32a = ((int32_t)(xy->x)) * (int32_t)BASE_VALUE_INT;
		temp =  (int16_t)(s32a / ((rt->t).cos)) ;
        (rt->r) = (uint16_t)temp;
	}
}

/******************************************************************************
Function:		library_rt_xy
Description:	transformation (ro, theta)->(x, y) [polar to cartesian coordinates]
Input:			rt, input vector structure address
				xy, output vector structure address
Output:			nothing
Modifies:		x, y components of xy vector
Revision:		1.0
******************************************************************************/
#ifdef RAM_EXECUTE
void __ramfunc__ library_rt_xy(const vecp_t *rt, vec2_t *xy)
#else
void library_rt_xy(const vecp_t *rt, vec2_t *xy)
#endif 
{
	int32_t	s32a;
	if(32767U >= (rt->r))
	{
		s32a = ((int32_t)(rt->r)) * ((int32_t)((rt->t).cos));
		(xy->x) = (int16_t)(s32a >> SH_BASE_VALUE);
		s32a = ((int32_t)(rt->r)) * ((int32_t)((rt->t).sin));
		(xy->y) = (int16_t)(s32a >> SH_BASE_VALUE);
	}
	else
	{
		(xy->x) = 0;
		(xy->y) = 0;
	}
}

/******************************************************************************
Function:		library_pi_control
Description:	PI control with anti-windup
Input:			error erl
				pointer to the pi control structure pi
Output:			control output
Modifies:		integral memory im of the control
******************************************************************************/
#ifdef RAM_EXECUTE
int16_t __ramfunc__ library_pi_control(int32_t erl, pi_cntrl_t *pi)
#else
int16_t library_pi_control(int32_t erl, pi_cntrl_t *pi)
#endif
{
	int32_t s32i, s32p, s32t;
	int16_t	s16e, s16t;

    if(0 < erl)
	{
		/* preliminary error clamp */
		if(32767 < erl)
		{
			s16e = 32767;
		}
		else
		{
			s16e = (int16_t)erl;
		}

		/* integral term */
		s32i = (int32_t)s16e * (int32_t)(pi->ki);
		s32i >>= (pi->shi);
		s32i += (pi->imem);

		/* proportional term */
		s32p = (int32_t)s16e * (int32_t)(pi->kp);
        
		/* total control */
		s32t = s32i + s32p;
		s16t = (int16_t)(s32t >> (pi->shp));
       
       		/* result clamp and integral memory update */
		if(s16t > (pi->hlim))
		{
			s16t = (pi->hlim);
			s32t = s16t;
			s32t <<= (pi->shp);
			(pi->imem) = s32t - s32p;
		}
		else if(s16t < (pi->llim))	/* case possible only if limit is changed */
		{
			s16t = (pi->llim);
			s32t = s16t;
			(pi->imem) = s32t << (pi->shp);
		}
		else
		{
			(pi->imem) = s32i;
		}
	}
	else if(0 > erl)
	{
		/* preliminary error clamp */
		if(-32767 > erl)
		{
			s16e = 32767;
		}
		else
		{
			s16e = (int16_t) -erl;
		}

		/* integral term */
		s32i = (int32_t)s16e * (int32_t)(pi->ki);
		s32i >>= (pi->shi);
		s32i -= (pi->imem);

		/* proportional term */
		s32p = (int32_t)s16e * (int32_t)(pi->kp);

		/* total control */
		s32t = s32i + s32p;
		s16t = (int16_t)(-(s32t >> (pi->shp)));

		/* result clamp and integral memory update */
		if(s16t < (pi->llim))
		{
			s16t = (pi->llim);
			s32t = s16t;
			s32t <<= (pi->shp);
			(pi->imem) = s32t + s32p;
		}
		else if(s16t > (pi->hlim))	/* case possible only if limit is changed */
		{
			s16t = (pi->llim);
			s32t = s16t;
			(pi->imem) = s32t << (pi->shp);
		}
		else
		{
			(pi->imem) = -s32i;
		}
	}
	else	/* error is 0 */
	{
		/* total control */
		s16t = (int16_t)((pi->imem) >> (pi->shp));

		/* result clamp and integral memory update */
		if(s16t < (pi->llim))		/* case possible only if limit is changed */
		{
			s16t = (pi->llim);
			s32t = s16t;
			(pi->imem) = s32t << (pi->shp);
		}
		else if(s16t > (pi->hlim))	/* case possible only if limit is changed */
		{
			s16t = (pi->hlim);
			s32t = s16t;
			(pi->imem) = s32t << (pi->shp);
		}
                else
                {
                  /* no action */
                }
	}

        return(s16t);
}

