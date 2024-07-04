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

#ifndef MC_IIR_FILTER
#define MC_IIR_FILTER

#include "mc_types.h"

/******************************************************************************
 * Constants
******************************************************************************/

/******************************************************************************
 * User-defined data structure
******************************************************************************/
/**
 * @brief Structure to hold the state and coefficients for each stage of the IIR filter.
 */
typedef struct {
    int16_t a;            /**< Coefficient a in Q15 format */
    int16_t b;            /**< Coefficient b in Q15 format */
    int16_t prev_input;   /**< Previous input (x[n-1]) in Q15 format */
    int16_t prev_output;  /**< Previous output (y[n-1]) in Q15 format */
} IIRStage;

/**
 * @brief Structure to hold multiple stages of the IIR filter.
 */
typedef struct {
    IIRStage *stages;   /**< Array of IIR filter stages */
    int num_stages;     /**< Number of stages in the IIR filter */
} IIRFilter;


/******************************************************************************
 * Interface variables
******************************************************************************/

/******************************************************************************
 * Interface functions
******************************************************************************/
/**
 * @brief Initializes the IIR filter with the given coefficients and number of stages.
 * 
 * @param filter Pointer to the IIR filter structure.
 * @param a Array of coefficients a for each stage in Q15 format.
 * @param b Array of coefficients b for each stage in Q15 format.
 * @param num_stages Number of stages in the IIR filter.
 */
void IIRFilter_FilterInitialize(IIRFilter *filter, int16_t a[], int16_t b[], int num_stages);

/**
 * @brief Applies the IIR filter to an input sample.
 * 
 * @param filter Pointer to the IIR filter structure.
 * @param input Input sample to filter.
 * @return Filtered output sample.
 */
int16_t IIRFilter_FilterApply(IIRFilter *filter, int16_t input);

/**
 * @brief Frees the memory allocated for the IIR filter stages.
 * 
 * @param filter Pointer to the IIR filter structure.
 */
void IIRFilter_FilterFree(IIRFilter *filter);

#endif // MC_IIR_FILTER
