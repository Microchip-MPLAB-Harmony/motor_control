/*******************************************************************************
  Motor Control PWM (MCPWM) Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_mcpwm_common.h

  Summary
    Data Type definition of the MCPWM Peripheral Interface Plib.

  Description
    This file defines the Data Types for the MCPWM Plib.

  Remarks:
    None.

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

#ifndef PLIB_MCPWM_COMMON_H    // Guards against multiple inclusion
#define PLIB_MCPWM_COMMON_H

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
    interface.
*/

// *****************************************************************************


typedef enum
{
    MCPWM_CH_1 ,
    MCPWM_CH_2 ,
    MCPWM_CH_3 ,
    MCPWM_CH_4 ,
    MCPWM_CH_5 ,
    MCPWM_CH_6 ,
    MCPWM_CH_7 ,
    MCPWM_CH_8 ,
    MCPWM_CH_9 ,
    MCPWM_CH_10 ,
    MCPWM_CH_11 ,
    MCPWM_CH_12 ,
} MCPWM_CH_NUM;

typedef enum
{
    MCPWM_NONE = 0,
    MCPWM_PWMH = _PWMCON1_PWMHIF_MASK,
    MCPWM_PWML = _PWMCON1_PWMLIF_MASK,
    MCPWM_TRG = _PWMCON1_TRGIF_MASK,
    MCPWM_CL = _PWMCON1_CLIF_MASK,
    MCPWM_FLT = _PWMCON1_FLTIF_MASK,
    MCPWM_STATUS_MASK = _PWMCON1_PWMHIF_MASK | _PWMCON1_PWMLIF_MASK | _PWMCON1_TRGIF_MASK | _PWMCON1_CLIF_MASK | _PWMCON1_FLTIF_MASK
}MCPWM_CH_STATUS;

typedef void (*MCPWM_CH_CALLBACK) (MCPWM_CH_STATUS status, uintptr_t context);

typedef void (*MCPWM_CALLBACK) (uintptr_t context);

// *****************************************************************************
// *****************************************************************************
// Section: Local: **** Do Not Use ****
// *****************************************************************************
// *****************************************************************************

typedef struct
{
    MCPWM_CH_CALLBACK callback;
    uintptr_t    context;

} MCPWM_CH_OBJECT ;

typedef struct
{
    MCPWM_CALLBACK callback;
    uintptr_t    context;

} MCPWM_OBJECT ;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif
// DOM-IGNORE-END
#endif // PLIB_ACC_COMMON_H
