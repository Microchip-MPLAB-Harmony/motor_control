/**
 * @brief Voltage calculation functions
 *
 * @Company Microchip Technology Inc.
 *
 * @File Name
 *   mc_voltage_measurement.h
 *
 * @Summary
 *   Header file which contains variables and function prototypes of voltage measurement functions.
 *
 * @Description
 *   This file contains variables and function prototypes of voltage measurement functions
 *   which are used in motor control applications.
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

#ifndef MCVOL_H   // Guards against multiple inclusion
#define MCVOL_H

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_hardware_abstraction.h"
#include "mc_userparams.h"

/*******************************************************************************
 Constants
 *******************************************************************************/

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
/**
 * @brief Structure for voltage sensor input.
 */
typedef struct
{
    uint16_t sensorInput; /**< Voltage sensor input value. */
} tmcVol_Input_s;

/**
 * @brief Structure for voltage measurement output.
 */
typedef struct
{
    uint16_t uBus;     /**< Voltage bus value. */
    uint16_t uBusFilt; /**< Filtered voltage bus value. */
} tmcVol_Output_s;

/**
 * @brief Structure for voltage measurement parameters.
 */
typedef struct tmcVol_Parameters_s
{
    /* Currently no parameters defined */
} tmcVol_Parameters_s;

/**
 * @brief Main structure for voltage measurement module data.
 */
typedef struct
{
    tmcVol_Input_s dInput;         /**< Input ports structure. */
    tmcVol_Output_s pOutput;       /**< Output ports structure. */
    tmcVol_Parameters_s pParameters; /**< User parameters structure. */
} tmcVol_ModuleData_s;

/*******************************************************************************
 Interface Variables
 *******************************************************************************/
extern tmcVol_ModuleData_s mcVolI_ModuleData_gds;

/*******************************************************************************
 * Static functions
 ******************************************************************************/

/**
 * @brief Set voltage measurement parameters.
 *
 * @details
 * Sets the parameters for voltage measurement.
 *
 * @param[in] pParameters Pointer to the parameters structure.
 */
__STATIC_INLINE void mcVol_ParametersSet(tmcVol_Parameters_s * const pParameters)
{
    /** @todo Implement setting of voltage measurement parameters. */
}

/**
 * @brief Read voltage sensor input ports.
 *
 * @details
 * Reads the voltage sensor input and updates the structure.
 *
 * @param[in,out] pInput Pointer to the input ports structure.
 */
__STATIC_INLINE void mcVol_InputPortsRead(tmcVol_Input_s * const pInput)
{
    pInput->sensorInput = mcHalI_UbusAdcInput_gdu16; /**< Read voltage sensor input. */
}

/**
 * @brief Write to voltage measurement output ports.
 *
 * @details
 * Writes the calculated output values to the output ports.
 *
 * @param[in] pOutput Pointer to the output ports structure.
 */
__STATIC_INLINE void mcVol_OutputPortsWrite(tmcVol_Output_s * const pOutput)
{
    /** @todo Implement writing to voltage measurement output ports. */
}

/*******************************************************************************
 * Interface Functions
 ******************************************************************************/

/**
 * @brief Initialize voltage calculation module.
 *
 * @details
 * Initializes the voltage calculation module.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 */
void mcVolI_VoltageCalculationInit(tmcVol_ModuleData_s * const pModule);

/**
 * @brief Perform voltage calculation.
 *
 * @details
 * Executes the voltage calculation process.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 */
void mcVolI_VoltageCalculation(tmcVol_ModuleData_s * const pModule);

/**
 * @brief Reset voltage calculation.
 *
 * @details
 * Resets the voltage calculation module to initial state.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 */
void mcVolI_VoltageCalculationReset(tmcVol_ModuleData_s * const pModule);

#endif // MCVOL_H_

/**
 End of File
*/
