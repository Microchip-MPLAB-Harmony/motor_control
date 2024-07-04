/*******************************************************************************
  System Definitions

  File Name:
    mc_generic_library.h

  Summary:
    Header file which contains variables and function prototypes of  generic library functions.

  Description:
    This file contains variables and function prototypes of generic library functions
    which are generally used in Motor Control. Implemented in Q2.14 Fixed Point Arithmetic.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MC_FIR_FILTER
#define MC_FIR_FILTER

#include "mc_types.h"

/******************************************************************************
 * Constants
******************************************************************************/

/******************************************************************************
 * User-defined data structure
******************************************************************************/
typedef struct {
    int16_t *coefficients;
    int16_t *history;
    int num_taps;
} FIRFilter;

/******************************************************************************
 * Interface variables
******************************************************************************/

/******************************************************************************
 * Interface functions
******************************************************************************/
/**
 * @brief Initializes the FIR filter with the given coefficients and number of taps.
 * 
 * @param filter Pointer to the FIR filter structure.
 * @param coefficients Array of FIR filter coefficients in Q15 format.
 * @param num_taps Number of taps in the FIR filter.
 */
void FIRFilter_FilterInitialize(FIRFilter *filter, int16_t *coefficients, int num_taps);

/**
 * @brief Applies the FIR filter to an input sample.
 * 
 * @param filter Pointer to the FIR filter structure.
 * @param input Input sample to filter.
 * @return Filtered output sample.
 */
int16_t FIRFilter_FilterApply(FIRFilter *filter, int16_t input);

/**
 * @brief Frees the memory allocated for the FIR filter.
 * 
 * @param filter Pointer to the FIR filter structure.
 */
void FIRFilter_FilterFree(FIRFilter *filter) ;

#endif // MC_FIR_FILTER
