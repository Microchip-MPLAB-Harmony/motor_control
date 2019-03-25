/*******************************************************************************
  Position Decoder (PDEC) Peripheral Library Interface Header File

  Company
    Microchip Technology Inc.

  File Name
    plib_pdec_common.h

  Summary
    PDEC peripheral library interface.

  Description
    This file defines the interface to the PDEC peripheral library. This
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

#ifndef PLIB_PDEC_COMMON_H    // Guards against multiple inclusion
#define PLIB_PDEC_COMMON_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.
*/

#include <stdbool.h>
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
/*  The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/

// *****************************************************************************

typedef enum
{
    PDEC_QDEC_STATUS_NONE = 0,
    
    /* Capture status overflow */
    PDEC_QDEC_STATUS_OVERFLOW = PDEC_INTFLAG_OVF_Msk,

    /* Capture status error */
    PDEC_QDEC_STATUS_ERROR = PDEC_INTFLAG_ERR_Msk,
    
    /* Direction change */
    PDEC_QDEC_STATUS_DIR = PDEC_INTFLAG_DIR_Msk,
    
    /* Direction change */
    PDEC_QDEC_STATUS_VELOCITY = PDEC_INTFLAG_VLC_Msk,

    /* Capture status ready for channel 0 */
    PDEC_QDEC_STAUTS_COMPARE_MATCH0 = PDEC_INTFLAG_MC0_Msk,

    /* Capture status ready for channel 1 */
    PDEC_QDEC_STATUS_COMPARE_MATCH1 = PDEC_INTFLAG_MC1_Msk,
    
    PDEC_QDEC_STATUS_MSK = PDEC_QDEC_STATUS_OVERFLOW | PDEC_QDEC_STATUS_ERROR | PDEC_QDEC_STATUS_DIR | PDEC_QDEC_STATUS_VELOCITY \
                        | PDEC_QDEC_STAUTS_COMPARE_MATCH0 | PDEC_QDEC_STATUS_COMPARE_MATCH1,
    
    /* Force the compiler to reserve 32-bit memory for enum */
    PDEC_QDEC_STATUS_INVALID = 0xFFFFFFFF

} PDEC_QDEC_STATUS;

// *****************************************************************************

typedef void (*PDEC_QDEC_CALLBACK) (PDEC_QDEC_STATUS status, uintptr_t context);

// *****************************************************************************
typedef struct
{
    PDEC_QDEC_CALLBACK callback;

    uintptr_t context;

} PDEC_QDEC_CALLBACK_OBJ;


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif /* PLIB_PDEC_COMMON_H */
