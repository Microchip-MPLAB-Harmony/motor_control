/*******************************************************************************
  Field Oriented Control ( FOC ) header file

  File Name:
    mc_pwm.h

  Summary:
    Header file which contains variables and function prototypes for Field Oriented Control ( FOC )

  Description:
    This file contains variables and function prototypes which are generally used for Field Oriented
    Control ( FOC ).

 *******************************************************************************/

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
typedef struct
{
    tmcTypes_ABC_s  iABC;
    int16_t uBus;
    int16_t reference;
}tmcFoc_Input_s;

typedef struct
{
    tmcTypes_AlphaBeta_s  iAlphaBeta;
    tmcTypes_AlphaBeta_s  uAlphaBeta;
    tmcTypes_DQ_s  iDQ;
    uint16_t elecAngle;
    int16_t elecSpeed;
    int16_t duty[3u];
}tmcFoc_Output_s;

typedef struct
{

}tmcFoc_Parameters_s;

typedef struct
{
  tmcFoc_Input_s dInput;
  tmcFoc_Output_s dOutput;
  tmcFoc_Parameters_s dParameters;
  void * pStatePointer;
}tmcFocI_ModuleData_s;

/*******************************************************************************
 * Interface variables
*******************************************************************************/
extern tmcFocI_ModuleData_s mcFocI_ModuleData_gds;

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/
/*! \brief Read input ports
 *
 * Details.
 * Read input ports
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcFocI_InputsRead( tmcFoc_Input_s * const pInput )
{
    pInput->iABC = mcCurI_ModuleData_gds.dOutput.iABC;

<#if ( MCPMSMFOC_CONTROL_TYPE == 'SPEED_LOOP' ) >
    pInput->reference = mcHalI_Potentiometer_gdu16 << 2u;
<#elseif ( MCPMSMFOC_CONTROL_TYPE == 'TORQUE_LOOP' ) >
    pInput->reference = mcHalI_Potentiometer_gdu16;
</#if>
}


/*! \brief Set module parameters
 *
 * Details.
 * Set module parameters
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcFocI_ParametersSet( tmcFoc_Parameters_s * const pParameters )
{

}

/*! \brief Set module parameters
 *
 * Details.
 * Set module parameters
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcFocI_OutputPortWrite( tmcFoc_Output_s * const pOutput )
{

}

/*! \brief Set module parameters
 *
 * Details.
 * Set module parameters
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcFocI_ParameterSet( tmcFoc_Parameters_s * const pParameters )
{

}

/*******************************************************************************
 Interface Functions
*******************************************************************************/
/*! \brief Initialize Field Oriented Control ( FOC ) module
 *
 * Details.
 * Initialize Field Oriented Control ( FOC ) module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFocI_FieldOrientedControlInit( tmcFocI_ModuleData_s * const pModule );

/*! \brief Enable Field Oriented Control ( FOC ) module
 *
 * Details.
 * Enable Field Oriented Control ( FOC ) module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFocI_FieldOrientedControlEnable( tmcFocI_ModuleData_s * const pParameters );

/*! \brief Disable Field Oriented Control ( FOC ) module
 *
 * Details.
 * Disable Field Oriented Control ( FOC ) module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFocI_FieldOrientedControlDisable( tmcFocI_ModuleData_s * const pParameters );

/*! \brief Field Oriented Control ( FOC )
 *
 * Details.
 * Field Oriented Control ( FOC )
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFocI_FieldOrientedControlFast( tmcFocI_ModuleData_s * const pModule );
#else
void mcFocI_FieldOrientedControlFast(  tmcFocI_ModuleData_s * const pModule );
#endif

/*! \brief Field Oriented Control ( FOC )
 *
 * Details.
 * Field Oriented Control ( FOC )
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFocI_FieldOrientedControlSlow( const tmcFocI_ModuleData_s * const pParameters );
#else
void mcFocI_FieldOrientedControlSlow( const tmcFocI_ModuleData_s * const pParameters );
#endif

/*! \brief Change motor direction
 *
 * Details.
 * Change motor direction
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void mcFocI_MotorDirectionChange(const tmcFocI_ModuleData_s * const pModule );


/*! \brief Reset Field Oriented Control ( FOC )
 *
 * Details.
 * Reset Field Oriented Control ( FOC )
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcFocI_FieldOrientedControlReset( const tmcFocI_ModuleData_s * const pParameters );

#endif // MCFOC_H
