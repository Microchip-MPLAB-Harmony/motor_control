/*******************************************************************************
  Utility Functions

  Company:
    - Microchip Technology Inc

  File Name:
    - mc_utilitiesc

  Summary:
    - Utility Functions

  Description:
    - Utility Functions

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2022 Microchip Technology Inc and its subsidiaries
 *
 * Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS" NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END


/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include "mc_fir_filter.h"

/*******************************************************************************
Macro definitions
 *******************************************************************************/

/******************************************************************************
Private global variables
******************************************************************************/


/*******************************************************************************
 *  Functions
 *******************************************************************************/
 /**
 * @brief Fixed-point multiplication of two Q15 numbers.
 * 
 * @param a First Q15 number.
 * @param b Second Q15 number.
 * @return Result of the multiplication.
 */
int16_t q15_mult(int16_t a, int16_t b) {
    int32_t temp = (int32_t)a * (int32_t)b;
    temp += (1 << 14); // Rounding
    return (int16_t)(temp >> 15);
}

/**
 * @brief Initializes the FIR filter with the given coefficients and number of taps.
 * 
 * @param filter Pointer to the FIR filter structure.
 * @param coefficients Array of FIR filter coefficients in Q15 format.
 * @param num_taps Number of taps in the FIR filter.
 */
void FIRFilter_FilterInitialize( FIRFilter *filter, int16_t *coefficients, int num_taps) {
    filter->num_taps = num_taps;
    filter->coefficients = (int16_t *)malloc(num_taps * sizeof(int16_t));
    filter->history = (int16_t *)malloc(num_taps * sizeof(int16_t));

    for (int i = 0; i < num_taps; i++) {
        filter->coefficients[i] = coefficients[i];
        filter->history[i] = 0; // Initialize history buffer to 0
    }
}

/**
 * @brief Applies the FIR filter to an input sample.
 * 
 * @param filter Pointer to the FIR filter structure.
 * @param input Input sample to filter.
 * @return Filtered output sample.
 */
int16_t FIRFilter_FilterApply(FIRFilter *filter, int16_t input) {
    // Shift history
    for (int i = filter->num_taps - 1; i > 0; i--) {
        filter->history[i] = filter->history[i - 1];
    }
    filter->history[0] = input;

    // Apply the filter
    int32_t output = 0;
    for (int i = 0; i < filter->num_taps; i++) {
        output += q15_mult(filter->coefficients[i], filter->history[i]);
    }

    // Saturate the output to the Q15 range
    if (output > INT16_MAX) {
        output = INT16_MAX;
    } else if (output < INT16_MIN) {
        output = INT16_MIN;
    }

    return (int16_t)output;
}

/**
 * @brief Frees the memory allocated for the FIR filter.
 * 
 * @param filter Pointer to the FIR filter structure.
 */
void FIRFilter_FilterFree(FIRFilter *filter) {
    free(filter->coefficients);
    free(filter->history);
}


