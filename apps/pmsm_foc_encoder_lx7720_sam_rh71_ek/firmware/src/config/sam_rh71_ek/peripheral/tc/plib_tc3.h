/*******************************************************************************
  TC Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_tc3.h

  Summary
    TC peripheral library interface.

  Description
    This file defines the interface to the TC peripheral library.  This
    library provides access to and control of the associated peripheral
    instance.

******************************************************************************/

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

#ifndef PLIB_TC3_H    // Guards against multiple inclusion
#define PLIB_TC3_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/


#include "plib_tc_common.h"

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

// *****************************************************************************

  


 




void TC3_CH0_CaptureInitialize (void);

void TC3_CH0_CaptureStart (void);

void TC3_CH0_CaptureStop (void);

uint32_t TC3_CH0_CaptureFrequencyGet (void);

uint32_t TC3_CH0_CaptureAGet (void);

uint32_t TC3_CH0_CaptureBGet (void);

TC_CAPTURE_STATUS TC3_CH0_CaptureStatusGet(void);



 




void TC3_CH1_CaptureInitialize (void);

void TC3_CH1_CaptureStart (void);

void TC3_CH1_CaptureStop (void);

uint32_t TC3_CH1_CaptureFrequencyGet (void);

uint32_t TC3_CH1_CaptureAGet (void);

uint32_t TC3_CH1_CaptureBGet (void);

TC_CAPTURE_STATUS TC3_CH1_CaptureStatusGet(void);



 




void TC3_CH2_CaptureInitialize (void);

void TC3_CH2_CaptureStart (void);

void TC3_CH2_CaptureStop (void);

uint32_t TC3_CH2_CaptureFrequencyGet (void);

uint32_t TC3_CH2_CaptureAGet (void);

uint32_t TC3_CH2_CaptureBGet (void);

TC_CAPTURE_STATUS TC3_CH2_CaptureStatusGet(void);




#ifdef __cplusplus // Provide C++ Compatibility
}
#endif

#endif //PLIB_TC3_H

/* End of File */