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

#ifndef MC_MOC_H    // Guards against multiple inclusion
#define MC_MOC_H


/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
#include "mc_rotor_position_calculation.h"
</#if>
#include "X2C_Model.h"

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
 #define  FIXED_POINT_Q15_MODEL      0U
 #define  FLOATING_POINT_F32_MODEL   1U

 #define  X2CMODEL_TYPE   FIXED_POINT_Q15_MODEL
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
static uint16_t firsttime =0;
</#if>

/*******************************************************************************
 Interface variables
 *******************************************************************************/

/*******************************************************************************
 Static Functions
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
static inline void mcFoc_InputPortsRead( void  )
{
  /** Please note that the ports may vary depending on your specific model. 
      Please adjust as needed. */
#if ( X2CMODEL_TYPE == FLOATING_POINT_F32_MODEL )
    x2cModel.inports.bI_a = (float32_t)mcCurI_ModuleData_gds.dOutput.iABC.a;
    x2cModel.inports.bI_b = (float32_t)mcCurI_ModuleData_gds.dOutput.iABC.b;
    x2cModel.inports.bV_POT = mcHalI_Potentiometer_gdu16 - 2048;
    x2cModel.inports.bV_DCLINK = (float32_t)mcVolI_ModuleData_gds.dOutput.uBus;
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
    x2cModel.inports.bQEI_POS = (float32_t)mcRpcI_ModuleData_gds.dOutput.elecAngle;
    x2cModel.inports.bQEI_VEL = (float32_t)mcRpcI_ModuleData_gds.dOutput.elecSpeed;
</#if>
#endif

#if ( X2CMODEL_TYPE == FIXED_POINT_Q15_MODEL )
   /** Scale phase currents
      * Scaling:
      *         Maximum measurable current -> 32767 units,
      *         Conversion Factor = 32767./ Maximum measurable current
      *
      *         For a MCLV-48V-300W board, maximum measurable current is 22 Amperes
      *         Therefore, conversion factor ~ 1,489.409
      */
    x2cModel.inports.bI_a = -(int16_t)((float32_t)mcCurI_ModuleData_gds.dOutput.iABC.a * (float32_t)1489.409);
    x2cModel.inports.bI_b = -(int16_t)((float32_t)mcCurI_ModuleData_gds.dOutput.iABC.b * (float32_t)1489.409);

    /**
        Potentiometer scaling: [ 0 - 4095 ] -> [ -32768, 32767 ]
     */
    x2cModel.inports.bV_POT = (int16_t)( mcHalI_Potentiometer_gdu16 ) << 3U;

    /** Scale DC link voltage
      * Scaling:
      *         Maximum measurable voltage -> 32767 units,
      *         Conversion Factor = 32767/ Maximum measurable voltage
      *
      *         For a MCLV-48V-300W board, maximum measurable voltage is 72.9 Volts
      *         Therefore, conversion factor ~ 449.478
      */
    x2cModel.inports.bV_DCLINK = (int16_t)((float32_t)mcVolI_ModuleData_gds.dOutput.uBus * (float32_t)449.478);

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
    /**
       *  Angle scaling: [ 0, 2* PI ] -> [ 0, 65535]
       */
    float32_t elecAngleInRad = (float32_t)mcRpcI_ModuleData_gds.dOutput.elecAngle;
    x2cModel.inports.bQEI_POS = elecAngleInRad * 65535.0f / TWO_PI;

   /** Scale speed
      * Scaling:
      *         Maximum speed -> 32767 units,
      *         Conversion Factor = 32767 / Maximum speed
      *
      *         If maximum speed is around 3600 RPM.
      *         Therefore, conversion factor ~ 9.10
      */
    float32_t elecSpeedInRpm =  (float32_t)mcRpcI_ModuleData_gds.dOutput.elecSpeed;
    x2cModel.inports.bQEI_VEL = (int16_t)( elecSpeedInRpm * 9.10 );
</#if>
#endif
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
static inline void mcFoc_OutputPortsWrite( void  )
{
  /** Please note that the ports may vary depending on your specific model. 
      Please adjust as needed. */
  #if ( X2CMODEL_TYPE == FLOATING_POINT_F32_MODEL )
    float32_t dutyCycleFactor;
    int16_t   periodCount;
    int16_t   halfPeriodCount;

    /* Get the period count from mcHalI_PwmPeriodGet() */
    periodCount = mcHalI_PwmPeriodGet();

    /* Calculate half of the period count */
    halfPeriodCount = periodCount >> 1U;

    /* Calculate the duty cycle factor */
    dutyCycleFactor = (float)periodCount / mcVolI_ModuleData_gds.dOutput.uBus;

    /* Update PWM duty cycles for three channels */
    mcPwmI_Duty_gau16[0] = periodCount - (halfPeriodCount + *x2cModel.outports.bPWM1 * dutyCycleFactor);
    mcPwmI_Duty_gau16[1] = periodCount - (halfPeriodCount + *x2cModel.outports.bPWM2 * dutyCycleFactor);
    mcPwmI_Duty_gau16[2] = periodCount - (halfPeriodCount + *x2cModel.outports.bPWM3 * dutyCycleFactor);
  #endif

  #if ( X2CMODEL_TYPE == FIXED_POINT_Q15_MODEL )
    uint16_t duty[3U];
    int16_t   periodCount;

    /* Get the period count from mcHalI_PwmPeriodGet() */
    periodCount = mcHalI_PwmPeriodGet();

  <#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'> 
    if( *x2cModel.outports.bHOME_INIT !=1 )
    {
        if(firsttime==0){
         /** Start encoder */
        mcHalI_EncoderStart();
        /** Enable rotor position estimation */
        mcRpcI_RotorPositionCalcEnable(&mcRpcI_ModuleData_gds);
        firsttime=1;
        }
         
       
    }
    else
    {

    }
  </#if>

    duty[0u] = (uint16_t)(((INT16_MAX - *x2cModel.outports.bPWM1) * periodCount)>>16);
    duty[1u] = (uint16_t)(((INT16_MAX - *x2cModel.outports.bPWM2) * periodCount)>>16);
    duty[2u] = (uint16_t)(((INT16_MAX - *x2cModel.outports.bPWM3) * periodCount)>>16);

    mcHalI_InverterPwmSet(duty);
  #endif
}

/*******************************************************************************
 * Interface Functions
 *******************************************************************************/

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
void mcFocI_FieldOrientedControlEnable( void );

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
void mcFocI_FieldOrientedControlDisable( void );

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
void mcFocI_FieldOrientedControlInit( void  );

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
void mcFocI_FieldOrientedControlFast( void  );

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
void mcFocI_FieldOrientedControlSlow( void  );

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
void mcFocI_MotorDirectionChange( void );

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
void mcFocI_FieldOrientedControlReset( void );

#endif //MC_MOC_H

/**
 End of File
*/
