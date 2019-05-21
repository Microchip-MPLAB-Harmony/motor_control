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
#include "definitions.h"
#include "userparams.h"

#ifdef RAM_EXECUTE
uint16_t __ramfunc__ pi_lib_calculate(picontrol_type* piPtr)
#else
uint16_t pi_lib_calculate(picontrol_type* piPtr)
#endif
{

	int32_t y_kplus;
	int32_t yn_kplus;
	int32_t y_kp;
	int32_t y_ki;

	/* Calculation Proportional term   y_kp = Prop Gain * Error	*/
	y_kp =	((piPtr->error *(int32_t)piPtr->kp * 64));
	
	/* Calculation Integral term   y_ki = Integral Gain * Error	*/
	y_ki = 	((piPtr->error *(int32_t)piPtr->ki));

	/* Integral term summation	*/
	y_kplus 	= ((int32_t)piPtr->integratorBuf + y_ki);
	
	/*	Load buffer with the accumulated error	*/
	piPtr->integratorBuf = y_kplus;
	
	y_kplus = y_kplus >> 15;
	
	/* Integral term Anti Windup Saturation Limit Check	*/
	if(y_kplus >= SPEED_MAX_LIMIT)
	{
		y_kplus = SPEED_MAX_LIMIT;
		piPtr->integratorBuf = (uint32_t) y_kplus*32768;
	}
	else if (y_kplus < SPEED_MIN_LIMIT)
	{
		y_kplus = SPEED_MIN_LIMIT;
		piPtr->integratorBuf = (uint32_t) y_kplus*32768;
	}
	else
	{
		/*Do nothing */
	}

	/*	Summation of Prop term and Integral term	*/
	yn_kplus	=	(y_kp + piPtr->integratorBuf)>>15;
	
	/*	Saturation Limit Check on final output	*/
	if(yn_kplus >= SPEED_MAX_LIMIT)
	{
		yn_kplus = SPEED_MAX_LIMIT;
	}
	else if(yn_kplus < SPEED_MIN_LIMIT)
	{
		yn_kplus = SPEED_MIN_LIMIT;
	}
	else
	{
		/*Do nothing */
	}
    piPtr->outputvalue = yn_kplus;
    
	/*	PI Controller output assignment	*/
	return((uint16_t)yn_kplus);

}