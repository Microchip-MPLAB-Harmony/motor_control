/*******************************************************************************
    Voltage measurement interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_voltagemeasurement.h

  Summary:
    Header file for voltage measurement

  Description:
    This file contains the data structures and function prototypes used by
    voltage measurement.
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

#ifndef MCVOL_H    // Guards against multiple inclusion
#define MCVOL_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>


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
  float dig2PhyConversion;
}tMCVOL_PARAMETERS_S;

typedef struct
{
    float rawValue;                   /*  Raw ADC value                             */
    float udc;                        /*  DC link voltage                           */
    float umax;                       /*  Maximum achievable voltage by SVPWM       */
}tMCVOL_OUTPUT_SIGNAL_S;

/*****************************************************************************/
/*                       INTERFACE VARIABLES                                 */
/*****************************************************************************/
extern tMCVOL_OUTPUT_SIGNAL_S gMCVOL_OutputSignals;

/*****************************************************************************/
/*                       INTERFACE FUNCTIONS                                 */
/*****************************************************************************/

/*****************************************************************************/
/* Function name: MCVOL_InitializeVoltageMeasurement                         */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* initializes parameters and state variables for voltage measurement        */
/*****************************************************************************/
void MCVOL_InitializeVoltageMeasurement( void );

/******************************************************************************/
/* Function name: MCINF_Initialization                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description:                                                               */
/* initializes parameters and state variables for rotor position sensing      */
/******************************************************************************/
void MCVOL_VoltageMeasurement( void );

/*****************************************************************************/
/* Function name: MCVOL_ResetVoltageMeasurement                              */
/* Function parameters: None                                                 */
/* Function return: None                                                     */
/* Description:                                                              */
/* resets parameters and state variables for voltage measurement             */
/*****************************************************************************/
void MCVOL_ResetVoltageMeasurement( void );

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCVOL_H

/**
 End of File
*/
