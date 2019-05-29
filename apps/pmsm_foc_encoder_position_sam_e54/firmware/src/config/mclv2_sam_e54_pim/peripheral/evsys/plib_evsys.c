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
{
	/*Event Channel User Configuration*/
	EVSYS_REGS->EVSYS_USER[17] = EVSYS_USER_CHANNEL(0x2);
	EVSYS_REGS->EVSYS_USER[55] = EVSYS_USER_CHANNEL(0x1);

	/* Event Channel 0 Configuration */
	EVSYS_REGS->CHANNEL[0].EVSYS_CHANNEL = EVSYS_CHANNEL_EVGEN(41) | EVSYS_CHANNEL_PATH(2) | EVSYS_CHANNEL_EDGSEL(1) \
									 ;
	/* Event Channel 1 Configuration */
	EVSYS_REGS->CHANNEL[1].EVSYS_CHANNEL = EVSYS_CHANNEL_EVGEN(20) | EVSYS_CHANNEL_PATH(2) | EVSYS_CHANNEL_EDGSEL(1) \
									 ;
}


