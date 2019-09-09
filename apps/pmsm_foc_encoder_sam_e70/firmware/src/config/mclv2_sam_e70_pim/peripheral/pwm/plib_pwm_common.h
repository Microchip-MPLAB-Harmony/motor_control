/*******************************************************************************
  PWM Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_pwm_common.h

  Summary
    PWM peripheral library interface.

  Description
    This file defines the interface to the PWM peripheral library.  This
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

#ifndef PLIB_PWM_COMMON_H    // Guards against multiple inclusion
#define PLIB_PWM_COMMON_H


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
/*  The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/


typedef void (*PWM_CALLBACK)(uint32_t status, uintptr_t context );
// *****************************************************************************

typedef enum
{
    PWM_CHANNEL_0,
    PWM_CHANNEL_1,
    PWM_CHANNEL_2,
    PWM_CHANNEL_3
}PWM_CHANNEL_NUM;
// *****************************************************************************

typedef enum
{
    PWM_CHANNEL_0_MASK = (1U << 0U),
    PWM_CHANNEL_1_MASK = (1U << 1U),
    PWM_CHANNEL_2_MASK = (1U << 2U),
    PWM_CHANNEL_3_MASK = (1U << 3U)
}PWM_CHANNEL_MASK;

// *****************************************************************************

typedef enum
{
    PWM_COMPARE_0,
    PWM_COMPARE_1,
    PWM_COMPARE_2,
    PWM_COMPARE_3,
    PWM_COMPARE_4,
    PWM_COMPARE_5,
    PWM_COMPARE_6,
    PWM_COMPARE_7,
}PWM_COMPARE;

// *****************************************************************************

typedef enum
{
    PWM_FAULT_ID_0,
    PWM_FAULT_ID_1,
    PWM_FAULT_ID_2,
    PWM_FAULT_ID_3,
    PWM_FAULT_ID_4,
    PWM_FAULT_ID_5,
    PWM_FAULT_ID_6,
    PWM_FAULT_ID_7,
}PWM_FAULT_ID;

typedef struct
{
    PWM_CALLBACK callback_fn;
    uintptr_t context;
}PWM_CALLBACK_OBJECT;


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //PLIB_PWM_COMMON_H

/**
 End of File
*/
