/*******************************************************************************
  EVSYS Peripheral Library

  Company:
    Microchip Technology Inc.

  File Name:
    plib_evsys.c

  Summary:
    EVSYS Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_evsys.h"


void EVSYS_Initialize( void )
{	/*Event Channel User Configuration*/
	EVSYS_REGS->EVSYS_USER[9] = EVSYS_USER_CHANNEL(0x4);
	EVSYS_REGS->EVSYS_USER[10] = EVSYS_USER_CHANNEL(0x2);
	EVSYS_REGS->EVSYS_USER[15] = EVSYS_USER_CHANNEL(0x5);
	EVSYS_REGS->EVSYS_USER[28] = EVSYS_USER_CHANNEL(0x1);
	EVSYS_REGS->EVSYS_USER[30] = EVSYS_USER_CHANNEL(0x3);

	/* Event Channel 0 Configuration */
	EVSYS_REGS->EVSYS_CHANNEL[0] = EVSYS_CHANNEL_EVGEN(45) | EVSYS_CHANNEL_PATH(2) | EVSYS_CHANNEL_EDGSEL(1) \
									 ;
	/* Event Channel 1 Configuration */
	EVSYS_REGS->EVSYS_CHANNEL[1] = EVSYS_CHANNEL_EVGEN(16) | EVSYS_CHANNEL_PATH(2) | EVSYS_CHANNEL_EDGSEL(1) \
									 ;
	/* Event Channel 2 Configuration */
	EVSYS_REGS->EVSYS_CHANNEL[2] = EVSYS_CHANNEL_EVGEN(46) | EVSYS_CHANNEL_PATH(2) | EVSYS_CHANNEL_EDGSEL(1) \
									 ;
	/* Event Channel 3 Configuration */
	EVSYS_REGS->EVSYS_CHANNEL[3] = EVSYS_CHANNEL_EVGEN(52) | EVSYS_CHANNEL_PATH(2) | EVSYS_CHANNEL_EDGSEL(0) \
									 ;
	/* Event Channel 4 Configuration */
	EVSYS_REGS->EVSYS_CHANNEL[4] = EVSYS_CHANNEL_EVGEN(52) | EVSYS_CHANNEL_PATH(2) | EVSYS_CHANNEL_EDGSEL(0) \
									 ;

}


