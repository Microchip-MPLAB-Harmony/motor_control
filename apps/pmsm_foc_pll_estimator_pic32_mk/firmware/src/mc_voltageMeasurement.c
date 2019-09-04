/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    MCAPP_VoltageMeasurement.c

  Summary:
    This file contains functions to measure voltage inputs for motor control

  Description:
    This file contains functions to measure voltage inputs for motor control

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "definitions.h"                // SYS function prototypes
#include "device.h"
#include "userparams.h"
#if  ( defined ( USE_FILE_INLINING )  && defined  (  MCAPP_C  ) )  ||   ( !defined ( USE_FILE_INLINING )  )
#ifndef MCVOL_C
#define MCVOL_C
#include "mc_voltageMeasurement.h"
#include "math.h"
#include "assert.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Motor phase current offset calibration limits. */

/******************************************************************************/
/* Local Function Prototype                                                   */
/******************************************************************************/

/******************************************************************************/
/*                   Global Variables                                         */
/******************************************************************************/
tMCVOL_OUTPUT_S gMCVOL_Voltage = {0.0f, 0.0f };

/******************************************************************************/
/* Function name: MCINF_Initialization                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* initializes parameters and state variables for rotor position sensing      */
/******************************************************************************/
INLINE_FUNCTION void MCVOL_voltageMeasurement( tMCVOL_OUTPUT_S * voltage )
{
         /* Read DC bus voltage */
         voltage->Udc = VOLTAGE_ADC_TO_PHY_RATIO * ADCHS_ChannelResultGet(ADCHS_CH10);
         voltage->Umax = voltage->Udc/SQRT3;
}

#endif

#endif
