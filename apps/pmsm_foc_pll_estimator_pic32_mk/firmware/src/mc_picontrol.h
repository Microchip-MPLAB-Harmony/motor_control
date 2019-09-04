/*******************************************************************************
 * PI Controller interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_picontrol.h

  Summary:
    Header file for PI controller functions

  Description:
    This file contains the data structures and function prototypes used by
   PI controller module.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#ifndef MC_CONTROL_H
#define	MC_CONTROL_H

typedef struct
{
    float   dSum;
    float   kp;
    float   ki;
    float   kc;
    float   outMax;
    float   outMin;
    float   inRef;
    float   inMeas;
    float   out;

} MCCON_PI;


extern MCCON_PI     gPIParmQ;        /* Iq PI controllers */
extern MCCON_PI     gPIParmD;        /* Id PI controllers */
extern MCCON_PI     gPIParmQref;     /* Speed PI controllers */

void MCCON_PIControl( MCCON_PI * const pParm);
void MCCON_InitializePIParameters(void);
void MCCON_ResetPIParameters(void);

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* MC_CONTROL_H */

