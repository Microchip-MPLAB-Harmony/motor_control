/*******************************************************************************
  Analog-to-Digital Converter(ADC) Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_adc_common.h

  Summary
    ADC Peripheral Library Interface Header File.

  Description
    This file defines the common types for the ADC peripheral library. This
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

#ifndef PLIB_ADC_COMMON_H    // Guards against multiple inclusion
#define PLIB_ADC_COMMON_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/

typedef enum
{
    ADC_POSINPUT_AIN0 = ADC_INPUTCTRL_MUXPOS_AIN0,
    ADC_POSINPUT_AIN1 = ADC_INPUTCTRL_MUXPOS_AIN1,
    ADC_POSINPUT_AIN2 = ADC_INPUTCTRL_MUXPOS_AIN2,
    ADC_POSINPUT_AIN3 = ADC_INPUTCTRL_MUXPOS_AIN3,
    ADC_POSINPUT_AIN4 = ADC_INPUTCTRL_MUXPOS_AIN4,
    ADC_POSINPUT_AIN5 = ADC_INPUTCTRL_MUXPOS_AIN5,
    ADC_POSINPUT_AIN6 = ADC_INPUTCTRL_MUXPOS_AIN6,
    ADC_POSINPUT_AIN7 = ADC_INPUTCTRL_MUXPOS_AIN7,
    ADC_POSINPUT_AIN8 = ADC_INPUTCTRL_MUXPOS_AIN8,
    ADC_POSINPUT_AIN9 = ADC_INPUTCTRL_MUXPOS_AIN9,
    ADC_POSINPUT_AIN10 = ADC_INPUTCTRL_MUXPOS_AIN10,
    ADC_POSINPUT_AIN11 = ADC_INPUTCTRL_MUXPOS_AIN11,
    ADC_POSINPUT_AIN12 = ADC_INPUTCTRL_MUXPOS_AIN12,
    ADC_POSINPUT_AIN13 = ADC_INPUTCTRL_MUXPOS_AIN13,
    ADC_POSINPUT_AIN14 = ADC_INPUTCTRL_MUXPOS_AIN14,
    ADC_POSINPUT_AIN15 = ADC_INPUTCTRL_MUXPOS_AIN15,
    ADC_POSINPUT_SCALEDCOREVCC = ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC,
    ADC_POSINPUT_SCALEDVBAT = ADC_INPUTCTRL_MUXPOS_SCALEDVBAT,
    ADC_POSINPUT_SCALEDIOVCC = ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC,
    ADC_POSINPUT_BANDGAP = ADC_INPUTCTRL_MUXPOS_BANDGAP,
    ADC_POSINPUT_PTAT = ADC_INPUTCTRL_MUXPOS_PTAT,
    ADC_POSINPUT_CTAT = ADC_INPUTCTRL_MUXPOS_CTAT,
    ADC_POSINPUT_DAC = ADC_INPUTCTRL_MUXPOS_DAC,
    ADC_POSINPUT_PTC = ADC_INPUTCTRL_MUXPOS_PTC,
}ADC_POSINPUT;

// *****************************************************************************

typedef enum
{
    ADC_NEGINPUT_AIN0 = ADC_INPUTCTRL_MUXNEG_AIN0,
    ADC_NEGINPUT_AIN1 = ADC_INPUTCTRL_MUXNEG_AIN1,
    ADC_NEGINPUT_AIN2 = ADC_INPUTCTRL_MUXNEG_AIN2,
    ADC_NEGINPUT_AIN3 = ADC_INPUTCTRL_MUXNEG_AIN3,
    ADC_NEGINPUT_AIN4 = ADC_INPUTCTRL_MUXNEG_AIN4,
    ADC_NEGINPUT_AIN5 = ADC_INPUTCTRL_MUXNEG_AIN5,
    ADC_NEGINPUT_AIN6 = ADC_INPUTCTRL_MUXNEG_AIN6,
    ADC_NEGINPUT_AIN7 = ADC_INPUTCTRL_MUXNEG_AIN7,
    ADC_NEGINPUT_GND = ADC_INPUTCTRL_MUXNEG_GND,
}ADC_NEGINPUT;


typedef enum
{
    ADC_STATUS_NONE = 0,
    ADC_STATUS_RESRDY = ADC_INTFLAG_RESRDY_Msk,
    ADC_STATUS_OVERRUN = ADC_INTFLAG_OVERRUN_Msk,
    ADC_STATUS_WINMON = ADC_INTFLAG_WINMON_Msk,
    ADC_STATUS_MASK = ADC_STATUS_RESRDY | ADC_STATUS_OVERRUN | ADC_STATUS_WINMON,
    /* Force compiler to reserve 32-bit for this enum */
    ADC_STATUS_INVALID = 0xFFFFFFFF
}ADC_STATUS;

typedef enum
{
    ADC_WINMODE_DISABLED = ADC_CTRLB_WINMODE_DISABLE_Val,
    ADC_WINMODE_GREATER_THAN_WINLT = ADC_CTRLB_WINMODE_MODE1_Val,
    ADC_WINMODE_LESS_THAN_WINUT = ADC_CTRLB_WINMODE_MODE2_Val,
    ADC_WINMODE_BETWEEN_WINLT_AND_WINUT = ADC_CTRLB_WINMODE_MODE3_Val,
    ADC_WINMODE_OUTSIDE_WINLT_AND_WINUT = ADC_CTRLB_WINMODE_MODE4_Val
}ADC_WINMODE;
// *****************************************************************************


typedef void (*ADC_CALLBACK)(ADC_STATUS status, uintptr_t context);


typedef struct
{
    ADC_CALLBACK callback;

    uintptr_t context;

} ADC_CALLBACK_OBJ;



// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif /* PLIB_ADC_COMMON_H*/
