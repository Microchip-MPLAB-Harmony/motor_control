/**
 * @brief 
 *    Field Oriented Control (FOC) header file
 *
 * @File Name 
 *    mc_field_oriented_control.h
 *
 * @Company 
 *   Microchip Technology Inc.
 *
 * @Summary
 *    This file contains declarations for Field Oriented Control (FOC) functions.
 *
 * @Description
 *   This file provides the function prototypes and data structures necessary for Field Oriented
 *    Control (FOC), which is used to control motor currents based on given inputs.
 *    Functions include initialization, execution, resetting, current updating,
 *    torque calculation, and field weakening control.
 */

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCFOC_H
#define MCFOC_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_utilities.h"
#include "mc_open_loop_startup.h"
#include "mc_pwm.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"
#include "mc_flux_control.h"
#include "mc_torque_control.h"
#include "mc_speed_control.h"
#include "mc_reference_control.h"
#include "mc_rotor_position_estimation.h"

/*******************************************************************************
 Default Module configuration parameters
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
/**
 * @brief Data structure for FOC input ports
 */
typedef struct
{
    tmcTypes_ABC_s  iABC;       /**< Motor phase currents */
    int16_t uBus;               /**< Bus voltage */
    int16_t reference;          /**< Reference value for control (e.g., speed or torque) */
} tmcFoc_Input_s;

/**
 * @brief Data structure for FOC output ports
 */
typedef struct
{
    tmcTypes_AlphaBeta_s  iAlphaBeta;  /**< Alpha-beta components of motor currents */
    tmcTypes_AlphaBeta_s  uAlphaBeta;  /**< Alpha-beta components of voltages */
    tmcTypes_DQ_s  iDQ;                /**< DQ components of motor currents */
    uint16_t elecAngle;                /**< Electrical angle */
    int16_t elecSpeed;                 /**< Electrical speed */
    int16_t duty[3u];                  /**< PWM duty cycles for three phases */
} tmcFoc_Output_s;

/**
 * @brief Data structure for FOC parameters
 */
typedef struct
{
    // Add FOC-specific parameters here
} tmcFoc_Parameters_s;

/**
 * @brief Data structure for FOC module data
 */
typedef struct
{
    tmcFoc_Input_s dInput;             /**< Input ports */
    tmcFoc_Output_s dOutput;           /**< Output ports */
    tmcFoc_Parameters_s dParameters;   /**< User parameters */
    void * pStatePointer;              /**< Pointer to state data */
} tmcFocI_ModuleData_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/
extern tmcFocI_ModuleData_s mcFocI_ModuleData_gds;

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/

/**
 * @brief Read input ports
 *
 * @details Reads the input ports for the FOC module.
 *
 * @param[in] None
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
__STATIC_INLINE void mcFocI_InputsRead(tmcFoc_Input_s * const pInput)
{
    pInput->iABC = mcCurI_ModuleData_gds.dOutput.iABC;
    pInput->uBus = mcVolI_ModuleData_gds.dOutput.uBus;
    pInput->reference = Qx_NORMALIZE( Q12, mcHalI_Potentiometer_gdu16 );
}

/**
 * @brief Set module parameters
 *
 * @details Sets the parameters for the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
__STATIC_INLINE void mcFocI_ParametersSet(tmcFoc_Parameters_s * const pParameters)
{
    // ToDo: Implement parameter setting
}

/**
 * @brief Write output ports
 *
 * @details Writes the output ports for the FOC module.
 *
 * @param[in] pOutput Pointer to the FOC output structure
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
__STATIC_INLINE void mcFocI_OutputPortWrite(tmcFoc_Output_s * const pOutput)
{
    // ToDo: Implement output port writing
}

/**
 * @brief Set module parameters
 *
 * @details Sets the parameters for the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
__STATIC_INLINE void mcFocI_ParameterSet(tmcFoc_Parameters_s * const pParameters)
{
    // ToDo: Implement parameter setting
}

/*******************************************************************************
 Interface Functions
*******************************************************************************/

/**
 * @brief Initialize Field Oriented Control (FOC) module
 *
 * @details Initializes the FOC module.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlInit(tmcFocI_ModuleData_s * const pModule);

/**
 * @brief Enable Field Oriented Control (FOC) module
 *
 * @details Enables the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlEnable(tmcFocI_ModuleData_s * const pParameters);

/**
 * @brief Disable Field Oriented Control (FOC) module
 *
 * @details Disables the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlDisable(tmcFocI_ModuleData_s * const pParameters);

/**
 * @brief Execute Field Oriented Control (FOC) fast loop
 *
 * @details Executes the fast loop of the FOC algorithm.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFocI_FieldOrientedControlFast(tmcFocI_ModuleData_s * const pModule);
#else
void mcFocI_FieldOrientedControlFast(tmcFocI_ModuleData_s * const pModule);
#endif

/**
 * @brief Execute Field Oriented Control (FOC) slow loop
 *
 * @details Executes the slow loop of the FOC algorithm.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcFocI_FieldOrientedControlSlow(const tmcFocI_ModuleData_s * const pParameters);
#else
void mcFocI_FieldOrientedControlSlow(const tmcFocI_ModuleData_s * const pParameters);
#endif

/**
 * @brief Change motor direction
 *
 * @details Changes the direction of the motor.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_MotorDirectionChange(const tmcFocI_ModuleData_s * const pModule);

/**
 * @brief Reset Field Oriented Control (FOC)
 *
 * @details Resets the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlReset(const tmcFocI_ModuleData_s * const pParameters);

#endif // MCFOC_H
