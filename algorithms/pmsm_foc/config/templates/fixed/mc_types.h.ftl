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
 Defines
 *******************************************************************************/
 #define RAM_EXECUTE
 
/*******************************************************************************
 User defined data-types
 *******************************************************************************/

/*! \brief 32-bit floating point data type */
typedef float float32_t;

/*! \brief 64-bit floating point data type */
typedef double float64_t;

/*! \brief Structure representing ABC phase quantities */
typedef struct
{
    int16_t a; /*!< Phase A quantity */
    int16_t b; /*!< Phase B quantity */
    int16_t c; /*!< Phase C quantity */
} tmcTypes_ABC_s;

/*! \brief Structure representing Alpha-Beta stationary frame quantities */
typedef struct
{
    int16_t alpha; /*!< Alpha axis quantity */
    int16_t beta;  /*!< Beta axis quantity */
} tmcTypes_AlphaBeta_s;

/*! \brief Structure representing DQ rotating frame quantities */
typedef struct
{
    int16_t d; /*!< D axis quantity */
    int16_t q; /*!< Q axis quantity */
} tmcTypes_DQ_s;

/*! \brief Enumeration for standard return status codes */
typedef enum
{
    StdReturn_Progress,  /*!< Operation in progress */
    StdReturn_Success,   /*!< Operation successful */
    StdReturn_Fail,      /*!< Operation failed */
    StdReturn_Complete   /*!< Operation completed */
} tmcTypes_StdReturn_e;


/*******************************************************************************
 Interface variables
 *******************************************************************************/

#endif //MC_TYPES_H

/**
 End of File
*/
