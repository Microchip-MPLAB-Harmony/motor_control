/*******************************************************************************
  ADCHS Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_adchs.h

  Summary
    ADCHS peripheral library interface.

  Description
    This file defines the interface to the ADCHS peripheral library.  This
    library provides access to and control of the associated peripheral
    instance.

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

#ifndef PLIB_ADCHS_H    // Guards against multiple inclusion
#define PLIB_ADCHS_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include "plib_adchs_common.h"

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
/*  The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions make up the methods (set of possible operations) of
   this interface.
*/

void ADCHS_Initialize (void);

void ADCHS_ModulesEnable (ADCHS_MODULE_MASK modulesMask);
void ADCHS_ModulesDisable (ADCHS_MODULE_MASK modulesMask);

void ADCHS_GlobalEdgeConversionStart(void);
void ADCHS_GlobalLevelConversionStart(void);
void ADCHS_GlobalLevelConversionStop(void);
void ADCHS_ChannelConversionStart(ADCHS_CHANNEL_NUM channel);

void ADCHS_ChannelResultInterruptEnable (ADCHS_CHANNEL_NUM channel);
void ADCHS_ChannelResultInterruptDisable (ADCHS_CHANNEL_NUM channel);
void ADCHS_ChannelEarlyInterruptEnable (ADCHS_CHANNEL_NUM channel);
void ADCHS_ChannelEarlyInterruptDisable (ADCHS_CHANNEL_NUM channel);

bool ADCHS_ChannelResultIsReady(ADCHS_CHANNEL_NUM channel);
uint16_t ADCHS_ChannelResultGet(ADCHS_CHANNEL_NUM channel);

void ADCHS_CallbackRegister(ADCHS_CHANNEL_NUM channel, ADCHS_CALLBACK callback, uintptr_t context);

bool ADCHS_EOSStatusGet(void);

// *****************************************************************************

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}
#endif
// DOM-IGNORE-END

#endif //PLIB_ADCHS_H

/**
 End of File
*/
