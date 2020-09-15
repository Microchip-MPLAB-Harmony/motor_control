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

typedef struct picontrol_type_t {
	/* kp Gain */
	int32_t kp;
	/* ki Gain */
	int32_t ki;
	/* Old error value */
	int32_t error;
	/*old output value */
	int32_t outputvalue;
	/* Max Limit of output */
	int32_t maxlimit;
	/* Min Limit of output value */
	int32_t minlimit;
    /* integrator buffer */
    uint32_t integratorBuf;
} picontrol_type;

/******************************************************************************
Functions prototypes
******************************************************************************/

#ifdef RAM_EXECUTE
uint16_t __ramfunc__ pi_lib_calculate(picontrol_type* piPtr);
#else
uint16_t pi_lib_calculate(picontrol_type* piPtr);
#endif


/* END OF CONTROL FUNCTIONS *************************************************/


#endif // Q14_GENERIC_MCLIB_H
