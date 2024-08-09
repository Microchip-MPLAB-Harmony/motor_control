/**
 * @file mc_types.h
 *
 * @brief 
 *   Motor control types
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *   Header file defining motor control types.
 *
 * @Description
 *   This header file defines various types used in motor control applications,
 *   including data structures and enumerations for representing phase quantities,
 *   coordinate frames, and standard return status codes.
 */


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

#ifndef MC_TYPES_H    // Guards against multiple inclusion
#define MC_TYPES_H


/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/attribs.h>
#include "toolchain_specifics.h"

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef float float32_t;

typedef struct
{
    float32_t a;
    float32_t b;
    float32_t c;
}tmcTypes_ABC_s;

typedef struct
{
    float32_t alpha;
    float32_t beta;
}tmcTypes_AlphaBeta_s;

typedef struct
{
    float32_t d;
    float32_t q;
}tmcTypes_DQ_s;

/*! \brief Enumeration for standard return status codes */
typedef enum {
    StdReturn_Progress, /*!< Operation in progress */
    StdReturn_Failed,   /*!< Operation failed */
    StdReturn_Success,   /*!< Operation successful */
    StdReturn_Complete, /*!< Operation successful */
    StdReturn_Pending,  /*!< Operation pending */
    StdReturn_Error,  /*!< Operation error */
    StdReturn_Timeout,  /*!< Operation timeout */
    StdReturn_Invalid,  /*!< Operation invalid */
} tmcTypes_StdReturn_e;

/*******************************************************************************
 Interface variables
 *******************************************************************************/

#endif //MC_TYPES_H

/**
 End of File
*/
