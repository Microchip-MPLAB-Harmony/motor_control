/**
 * @brief 
  *  Motor Control current measurement interface file
 *
 * @Company 
 *   Microchip Technology Inc.
 *
 * @File name
 *   mc_current_calculation.h
 *
 * @Summary 
 *    Header file for current measurement
 *
 * @Description
 *   This file contains the data structures and function prototypes  necessary for the current
 *    measurement functionality in motor control applications.
 *
 *   It includes definitions for initializing the current measurement module,  calculating current
 *   sensor offsets, computing phase currents, and resetting  the current calculations.
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

#ifndef MCCUR_H_    // Guards against multiple inclusion
#define MCCUR_H_

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_utilities.h"
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

/**
 * @brief Structure for current inputs.
 */
typedef struct
{
    int16_t iaAdcInput;  /**< ADC input for phase A current */
    int16_t ibAdcInput;  /**< ADC input for phase B current */
} tmcCur_Input_s;

/**
 * @brief Structure for current outputs.
 */
typedef struct
{
    tmcTypes_ABC_s iABC;  /**< Structure holding phase currents */
    uint8_t calibDone;    /**< Calibration status flag */
} tmcCur_Output_s;

/**
 * @brief Structure for current parameters.
 */
typedef struct
{
    float32_t adcToCurrentFactor;   /**< adcToCurrentFactor */
<#if MCPMSMFOC_OFFSET_OOR == true >
    int16_t minOffset;  /**< Minimum offset value */
    int16_t maxOffset;  /**< Maximum offset value */
</#if>
} tmcCur_Parameters_s;

/**
 * @brief Structure for module data.
 */
typedef struct
{
    tmcCur_Input_s dInput;         /**< Input ports */
    tmcCur_Output_s dOutput;       /**< Output ports */
    tmcCur_Parameters_s dParameters; /**< User Parameters */
} tmcCur_ModuleData_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
extern tmcCur_ModuleData_s mcCurI_ModuleData_gds;

/*******************************************************************************
 Static Functions
 *******************************************************************************/
 /**
 * @brief Reads the current input ports.
 * 
 * This function reads the ADC input values for phase currents
 * and assigns them to the respective fields in the input structure.
 * 
 * @param[in,out] pInput Pointer to the input structure where ADC values are stored.
 */
__STATIC_INLINE void mcCur_InputsRead( tmcCur_Input_s * const pInput )
{
    pInput->iaAdcInput = (int16_t)mcHalI_IaAdcInput_gdu16;
    pInput->ibAdcInput = (int16_t)mcHalI_IbAdcInput_gdu16;
}

/**
 * @brief Writes to the current output ports.
 * 
 * This function is a placeholder for writing the output values.
 * 
 * @param[in] pOutput Pointer to the output structure to be written.
 * @note ToDO: Remove for optimization.
 */
__STATIC_INLINE void mcCur_ParametersSet( tmcCur_Parameters_s * const pParameters )
{
    pParameters->adcToCurrentFactor = (float32_t)(${MCPMSMFOC_CURRENT_SCALING_FACTORT});

<#if MCPMSMFOC_OFFSET_OOR == true >
    pParameters->minOffset = (float32_t)(${MCPMSMFOC_OFFSET_OOR_MINIMUM});
    pParameters->maxOffset = (float32_t)(${MCPMSMFOC_OFFSET_OOR_MAXIMUM});
</#if>
}

/*******************************************************************************
 Interface functions
 *******************************************************************************/
/**
 * @brief Current control initialization function.
 *
 * Initializes the current control module by setting up the required parameters 
 * and preparing the module for current calculations.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 * 
 * @return None
 */
void mcCurI_CurrentCalculationInit( tmcCur_ModuleData_s * const pModule );

/**
 * @brief Function to calculate the current sensor offset.
 *
 * Calculates the offset for the current sensors to ensure accurate current measurements.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 * 
 * @return None
 */
tmcTypes_StdReturn_e mcCurI_CurrentOffsetCalculation( tmcCur_ModuleData_s * const pModule );

/**
 * @brief Function to calculate the phase currents.
 *
 * Computes the phase currents based on the ADC input values and stores the results 
 * in the module's output structure.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 * 
 * @return None
 */
void mcCurI_CurrentCalculation( tmcCur_ModuleData_s * const pModule );


/**
 * @brief Function to reset phase current calculation.
 *
 * Resets the state of the current calculation module, clearing any stored values 
 * and preparing it for a fresh set of calculations.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 * 
 * @return None
 */
void mcCurI_CurrentCalculationReset( tmcCur_ModuleData_s * const pModule );

#endif //MCCUR_H_

/**
 End of File
*/
