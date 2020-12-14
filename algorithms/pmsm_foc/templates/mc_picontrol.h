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
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
#define MC_CONTROL_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>
#include "mc_userparams.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

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
} tMCLIB_PICONTROLLER_S;


/******************************************************************************/
/*                       INTERFACE VARIABLES                                  */
/******************************************************************************/

extern tMCLIB_PICONTROLLER_S    gMCLIB_IdPIController;
extern tMCLIB_PICONTROLLER_S    gMCLIB_IqPIController;
extern tMCLIB_PICONTROLLER_S    gMCLIB_SpeedPIController;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void MCLIB_PIControl( tMCLIB_PICONTROLLER_S * const pParm);

void MCLIB_ResetPIParameters(tMCLIB_PICONTROLLER_S * const pParm);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif    /* MC_CONTROL_H */
