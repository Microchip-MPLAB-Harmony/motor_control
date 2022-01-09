/*******************************************************************************
 Rotor Position interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotor_position.h

  Summary:
    Header file for rotor position

  Description:
    This file contains the data structures and function prototypes of rotor position.
 *******************************************************************************/

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

#ifndef MCRPO_H    // Guards against multiple inclusion
#define MCRPO_H

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
#include <stddef.h>
#include "mc_generic_library.h"
#include "mc_hardware_abstraction.h"
#include "mc_interface_handling.h"

/*******************************************************************************
 Configuration constants 
 *******************************************************************************/
/**
 * Number of rotor position module instances
 */
#define ROTOR_POSITION_INSTANCES 1u  

/**
 * Quadrature Encoder pulse count per mechanical revolution 
 */
#define CONFIG_EncoderPulsesPerMechRev    (${MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV}u * NUM_POLE_PAIRS )

/**
 * Velocity calculation pre-scale value with respect to the pulse sampling frequency
 */
#define CONFIG_VelcoityCalculationPrescale   (float)100.0f

/**
 * Number of pole pairs 
 */
#define CONFIG_RpoNumberOfPolePairs             NUM_POLE_PAIRS

/**
 * Quadrature pulse sampling frequency 
 */
#define CONFIG_SamplingFrequency              PWM_FREQUENCY

/*******************************************************************************
 Default module parameters
 *******************************************************************************/
#define ROTOR_POSITION_MODULE_A_CONFIG { \
    /* Instance Id */ \
    0u, \
    /* Output ports */ \
    { \
        &mcRpoI_ElectricalRotorPosition_gaf32[0u], \
        &mcRpoI_MechanicalRotorPosition_gaf32[0u], \
        &mcRpoI_ElectricalRotorSpeed_gaf32[0u], \
        &mcRpoI_ElectricalRotorAccel_gaf32[0u] \
    }, \
    /* User Parameters */ \
    { \
         CONFIG_VelcoityCalculationPrescale, \
    } \
}

#define ROTOR_POSITION_MODULE_B_CONFIG { \
    /* Instance Id */ \
    1u, \
    /* Output ports */ \
    { \
        &mcRpoI_ElectricalRotorPosition_gaf32[1u], \
        &mcRpoI_MechanicalRotorPosition_gaf32[1u], \
        &mcRpoI_ElectricalRotorSpeed_gaf32[1u], \
        &mcRpoI_ElectricalRotorAccel_gaf32[1u] \
    }, \
    /* User Parameters */ \
    { \
         CONFIG_VelcoityCalculationPrescale, \
    } \
}

/*******************************************************************************
 User defined data types  
 *******************************************************************************/

typedef enum _tmcRpo_InstanceId_e
{
    encModuleInstance_01,
    encModuleInstance_02,
    encModuleInstance_max 
}tmcRpo_InstanceId_e;

typedef struct _tmcRpo_OutputPorts_s
{
    float  * elecAngle;
    float  * mechAngle;
    float  * elecVelocity;
    float  * accel;
}tmcRpo_OutputPorts_s;

typedef struct _tmcRpo_UserParameters_s
{
    uint16_t velocityCountPrescaler;
}tmcRpo_UserParameters_s;

typedef struct _tmcRpo_ConfigParameters_s
{
    /* Instance identifier */
    uint8_t Id;
       
    /* Output ports */
    tmcRpo_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcRpo_UserParameters_s userParam;
    
}tmcRpo_ConfigParameters_s;


/*******************************************************************************
 Interface variables  
 *******************************************************************************/
extern tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Rotor position calculation initialization function 
 * 
 * Details.
 *  Rotor position calculation initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( const tmcRpo_ConfigParameters_s * const rpoParam );

/*! \brief Rotor position calculation trigger 
 * 
 * Details.
 *  Rotor position calculation trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationStart( const tmcRpo_InstanceId_e Id );

/*! \brief Rotor position calculation execution  function 
 * 
 * Details.
 *  Rotor position calculation execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( const tmcRpo_InstanceId_e Id );

/*! \brief Rotor position calculation reset function 
 * 
 * Details.
 *  Rotor position calculation reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationReset( const tmcRpo_InstanceId_e Id );

#endif //MCRPO_H

/**
 End of File
*/
