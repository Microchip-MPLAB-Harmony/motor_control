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
#include "mc_iir_filter.h"

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
static inline int16_t q15_mult(int16_t a, int16_t b) {
    int32_t temp = (int32_t)a * (int32_t)b;
    temp += (1 << 14); // Rounding
    return (int16_t)(temp >> 15);
}

/**
 * @brief Initializes the IIR filter with the given coefficients and number of stages.
 * 
 * @param filter Pointer to the IIR filter structure.
 * @param a Array of coefficients a for each stage in Q15 format.
 * @param b Array of coefficients b for each stage in Q15 format.
 * @param num_stages Number of stages in the IIR filter.
 */
void IIRFilter_FilterInitialize(IIRFilter *filter, int16_t a[], int16_t b[], int num_stages) {
    filter->num_stages = num_stages;
    filter->stages = (IIRStage *)malloc(num_stages * sizeof(IIRStage));

    for (int i = 0; i < num_stages; i++) {
        filter->stages[i].a = a[i];
        filter->stages[i].b = b[i];
        filter->stages[i].prev_input = 0;
        filter->stages[i].prev_output = 0;
    }
}


/**
 * @brief Applies the IIR filter to an input sample.
 * 
 * @param filter Pointer to the IIR filter structure.
 * @param input Input sample to filter.
 * @return Filtered output sample.
 */
int16_t IIRFilter_FilterApply(IIRFilter *filter, int16_t input) {
    for (int i = 0; i < filter->num_stages; i++) {
        IIRStage *stage = &(filter->stages[i]);
        int32_t output = q15_mult(stage->a, stage->prev_output) + q15_mult(stage->b, input);// - q15_mult(stage->a, stage->prev_input);

        // Saturate the output to the Q15 range
        if (output > INT16_MAX) {
            output = INT16_MAX;
        } else if (output < INT16_MIN) {
            output = INT16_MIN;
        }

        stage->prev_input = input;
        stage->prev_output = (int16_t)output;
        input = (int16_t)output; // Output of previous stage becomes input to the next stage
    }

    return input; // Output of the last stage is the final output
}

/**
 * @brief Frees the memory allocated for the IIR filter stages.
 * 
 * @param filter Pointer to the IIR filter structure.
 */
void IIRFilter_FilterFree(IIRFilter *filter) {
    free(filter->stages);
}



