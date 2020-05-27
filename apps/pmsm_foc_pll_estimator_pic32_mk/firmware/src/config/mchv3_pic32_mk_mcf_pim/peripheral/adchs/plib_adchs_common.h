/*******************************************************************************
  ADCHS Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_adchs_common.h

  Summary
    Commonly needed stuff for the ADCHS peripheral libraries interfaces.

  Description
    This file defines several items commonly needed by the interfaces to
    the ADCHS peripheral libraries.

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

#ifndef PLIB_ADCHS_COMMON_H    // Guards against multiple inclusion
#define PLIB_ADCHS_COMMON_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

/*  This section lists the other files that are included in this file.
*/

#include <stddef.h>
#include <stdbool.h>


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

// *****************************************************************************

typedef enum
{
    ADCHS_MODULE0_MASK = (1U << 0U),
    ADCHS_MODULE1_MASK = (1U << 1U),
    ADCHS_MODULE2_MASK = (1U << 2U),
    ADCHS_MODULE3_MASK = (1U << 3U),
    ADCHS_MODULE4_MASK = (1U << 4U),
    ADCHS_MODULE5_MASK = (1U << 5U),
    ADCHS_MODULE7_MASK = (1U << 7U)
}ADCHS_MODULE_MASK;


typedef enum
{
    ADCHS_CH0 = 0U,
    ADCHS_CH1 = 1U,
    ADCHS_CH2 = 2U,
    ADCHS_CH3 = 3U,
    ADCHS_CH4 = 4U,
    ADCHS_CH5 = 5U,
    ADCHS_CH6 = 6U,
    ADCHS_CH7 = 7U,
    ADCHS_CH8 = 8U,
    ADCHS_CH9 = 9U,
    ADCHS_CH10 = 10U,
    ADCHS_CH11 = 11U,
    ADCHS_CH12 = 12U,
    ADCHS_CH13 = 13U,
    ADCHS_CH14 = 14U,
    ADCHS_CH15 = 15U,
    ADCHS_CH16 = 16U,
    ADCHS_CH17 = 17U,
    ADCHS_CH18 = 18U,
    ADCHS_CH19 = 19U,
    ADCHS_CH20 = 20U,
    ADCHS_CH21 = 21U,
    ADCHS_CH22 = 22U,
    ADCHS_CH23 = 23U,
    ADCHS_CH24 = 24U,
    ADCHS_CH25 = 25U,
    ADCHS_CH26 = 26U,
    ADCHS_CH27 = 27U,
    ADCHS_CH33 = 33U,
    ADCHS_CH34 = 34U,
    ADCHS_CH35 = 35U,
    ADCHS_CH36 = 36U,
    ADCHS_CH37 = 37U,
    ADCHS_CH38 = 38U,
    ADCHS_CH39 = 39U,
    ADCHS_CH40 = 40U,
    ADCHS_CH41 = 41U,
    ADCHS_CH45 = 45U,
    ADCHS_CH46 = 46U,
    ADCHS_CH47 = 47U,
    ADCHS_CH48 = 48U,
    ADCHS_CH49 = 49U,
    ADCHS_CH50 = 50U,
    ADCHS_CH52 = 52U,
    ADCHS_CH53 = 53U,
}ADCHS_CHANNEL_NUM;


// *****************************************************************************

typedef void (*ADCHS_CALLBACK)(ADCHS_CHANNEL_NUM channel, uintptr_t context);

typedef void (*ADCHS_EOS_CALLBACK)(uintptr_t context);
// *****************************************************************************

typedef struct
{
    ADCHS_CALLBACK callback_fn;
    uintptr_t context;
}ADCHS_CALLBACK_OBJECT;

typedef struct
{
    ADCHS_EOS_CALLBACK callback_fn;
    uintptr_t context;
}ADCHS_EOS_CALLBACK_OBJECT;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //PLIB_ADCHS_COMMMON_H

/**
 End of File
*/
