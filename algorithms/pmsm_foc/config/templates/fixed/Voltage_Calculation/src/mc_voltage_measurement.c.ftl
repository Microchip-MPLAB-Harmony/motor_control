/**
 * @brief 
 *   Voltage calculation functions
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @File Name 
 *    mc_voltage_measurement.c
 *
 * @Summary 
 *    Implementation file for voltage measurement functions.
 *
 * @Description
 *    This file contains the implementation of functions used for voltage 
 *    measurement in motor control applications.
 */

// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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


/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include "mc_voltage_measurement.h"

/*******************************************************************************
 * Constants
 *******************************************************************************/

/*******************************************************************************
 Private data-types
 *******************************************************************************/

/*******************************************************************************
 Private variables
 *******************************************************************************/

/*******************************************************************************
 Interface Variables
 *******************************************************************************/
tmcVol_ModuleData_s mcVolI_ModuleData_gds;

/*******************************************************************************
 Private Functions
 *******************************************************************************/

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
/**
 * @brief Initialize voltage calculation module.
 *
 * @details
 * Initializes the voltage calculation module.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 */
void  mcVolI_VoltageCalculationInit( tmcVol_ModuleData_s * const pModule )
{
    /** Set parameters */
    mcVol_ParametersSet( &pModule->pParameters);
}

/**
 * @brief Perform voltage calculation.
 *
 * @details
 * Executes the voltage calculation process.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcVolI_VoltageCalculation( tmcVol_ModuleData_s * const pModule )
#else
void mcVolI_VoltageCalculation( tmcVol_ModuleData_s * const pModule )
#endif
{
    tmcVol_Input_s * pInput;

    pInput = &pModule->dInput;

    /** Read input ports */
    mcVol_InputPortsRead(pInput);

    /** Calculate DC bus voltage */
    pModule->pOutput.uBus =   Qx_NORMALIZE( Q12, pInput->sensorInput);

    /** Write output ports */
    mcVol_OutputPortsWrite(&pModule->pOutput);
}

/**
 * @brief Reset voltage calculation.
 *
 * @details
 * Resets the voltage calculation module to initial state.
 *
 * @param[in,out] pModule Pointer to the module data structure.
 */
void mcVolI_VoltageCalculationReset( tmcVol_ModuleData_s * const pModule )
{
    tmcVol_Output_s * pOutput;
    pOutput = &pModule->pOutput;

    /** Reset output ports */
    pOutput->uBus = 0u;
    pOutput->uBusFilt = 0u;

    /** Write output ports */
    mcVol_OutputPortsWrite(&pModule->pOutput);
}
