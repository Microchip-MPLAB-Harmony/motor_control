/*******************************************************************************
 Motor Control App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_currMeasurement.h

  Summary:
    Header file for current measurement

  Description:
    This file contains the data structures and function prototypes of current measurement.
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

#ifndef MCCUR_H    // Guards against multiple inclusion
#define MCCUR_H


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

/* Current measurement algorithms */
#define SINGLE_SHUNT                      0U
#define DUAL_SHUNT                        1U

/* Motor phase current offset calibration limits. */
#define CURRENT_OFFSET_MAX                (2200) /* current offset max limit in terms of ADC count*/
#define CURRENT_OFFSET_MIN                (1900) /* current offset min limit in terms of ADC count*/
/** Phase Current Offset calibration samples */
#define CURRENTS_OFFSET_SAMPLES           (100U)

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* Phase currents

  Summary:
    Indicates motor phase currents

  Description:
    Datastructure for motor phase currents

  Remarks:
    None.
*/
typedef struct
{
         uint8_t Calib_done;
         float iu_offset;
         float iv_offset;
}tPHASE_CURRENTS_OFFSET_S;

typedef struct
{
         float iu;
         float iv;
         float iw;
         float idc;
}tPHASE_CURRENTS_S;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
extern tPHASE_CURRENTS_OFFSET_S gMCCUR_PhaseCurrentOffset;
extern tPHASE_CURRENTS_S gMCCUR_PhaseCurrent;

void MCCUR_initialization(void);
void MCCUR_offsetCalibration(void);
void MCCUR_CurrentMeasurement(tPHASE_CURRENTS_S * const phaseCurrents);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //MCCUR_H

/**
 End of File
*/
