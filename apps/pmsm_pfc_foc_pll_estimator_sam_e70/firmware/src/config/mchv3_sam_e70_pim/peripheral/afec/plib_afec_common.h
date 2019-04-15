/*******************************************************************************
  AFEC Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_afec_common.h

  Summary
    AFEC peripheral library interface.

  Description
    This file defines the interface to the AFEC peripheral library.  This
    library provides access to and control of the associated peripheral
    instance.

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

#ifndef PLIB_AFEC_COMMON_H    // Guards against multiple inclusion
#define PLIB_AFEC_COMMON_H


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

typedef enum
{
    AFEC_CH0_MASK = (1U << 0U),
    AFEC_CH1_MASK = (1U << 1U),
    AFEC_CH2_MASK = (1U << 2U),
    AFEC_CH3_MASK = (1U << 3U),
    AFEC_CH4_MASK = (1U << 4U),
    AFEC_CH5_MASK = (1U << 5U),
    AFEC_CH6_MASK = (1U << 6U),
    AFEC_CH7_MASK = (1U << 7U),
    AFEC_CH8_MASK = (1U << 8U),
    AFEC_CH9_MASK = (1U << 9U),
    AFEC_CH10_MASK = (1U << 10U),
    AFEC_CH11_MASK = (1U << 11U)
}AFEC_CHANNEL_MASK;
// *****************************************************************************

typedef enum
{
    AFEC_CH0 = 0U,
    AFEC_CH1,
    AFEC_CH2,
    AFEC_CH3,
    AFEC_CH4,
    AFEC_CH5,
    AFEC_CH6,
    AFEC_CH7,
    AFEC_CH8,
    AFEC_CH9,
    AFEC_CH10,
    AFEC_CH11
}AFEC_CHANNEL_NUM;
// *****************************************************************************

typedef enum
{
    AFEC_CHANNEL_GAIN_X1,
    AFEC_CHANNEL_GAIN_X2,
    AFEC_CHANNEL_GAIN_X4
}AFEC_CHANNEL_GAIN;
// *****************************************************************************

typedef enum
{
    AFEC_INTERRUPT_EOC_0_MASK = (1U << 0U),
    AFEC_INTERRUPT_EOC_1_MASK = (1U << 1U),
    AFEC_INTERRUPT_EOC_2_MASK = (1U << 2U),
    AFEC_INTERRUPT_EOC_3_MASK = (1U << 3U),
    AFEC_INTERRUPT_EOC_4_MASK = (1U << 4U),
    AFEC_INTERRUPT_EOC_5_MASK = (1U << 5U),
    AFEC_INTERRUPT_EOC_6_MASK = (1U << 6U),
    AFEC_INTERRUPT_EOC_7_MASK = (1U << 7U),
    AFEC_INTERRUPT_EOC_8_MASK = (1U << 8U),
    AFEC_INTERRUPT_EOC_9_MASK = (1U << 9U),
    AFEC_INTERRUPT_EOC_10_MASK = (1U << 10U),
    AFEC_INTERRUPT_EOC_11_MASK = (1U << 11U)
}AFEC_INTERRUPT_MASK;

// *****************************************************************************

typedef void (*AFEC_CALLBACK)(uint32_t status, uintptr_t context);
// *****************************************************************************

typedef struct
{
    AFEC_CALLBACK callback_fn;
    uintptr_t context;
}AFEC_CALLBACK_OBJECT;




// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //PLIB_AFEC_COMMMON_H

/**
 End of File
*/
