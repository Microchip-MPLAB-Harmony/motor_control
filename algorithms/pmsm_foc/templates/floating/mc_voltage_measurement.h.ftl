/*******************************************************************************
 Voltage measurement 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_voltage_measurement.h

  Summary:
   Voltage measurement 

  Description:
  Voltage measurement 
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

#ifndef MCVOL_H   // Guards against multiple inclusion
#define MCVOL_H

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_generic_library.h"
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
/**
 * Number of module instances 
 */
#define VOLTAGE_MEASUREMENT_INSTANCES 1u 

/**
 * Voltage divider top resistance in ohms
 */
#define VOLTAGE_DIVIDER_TOP_RESISTANCE_IN_KOHM (float)30.0f

/**
 * Voltage divider bottom resistance in ohms
 */
#define VOLTAGE_DIVIDER_BOTTOM_RESISTANCE_IN_KOHM (float)2.0f

/**
 * ADC count to volts 
 */
#define VOLTAGE_DIVIDER_RATIO  (float)((    VOLTAGE_DIVIDER_BOTTOM_RESISTANCE_IN_KOHM )               \
                                                                        /(  VOLTAGE_DIVIDER_TOP_RESISTANCE_IN_KOHM              \
                                                                          +  VOLTAGE_DIVIDER_BOTTOM_RESISTANCE_IN_KOHM ))

/**
 * ADC reference voltage 
 */
#define VOLTAGE_ADC_REFERENCE_IN_VOLTS    (float)3.3f

/**
 * ADC Resolution
 */
#define VOLTAGE_ADC_RESOLUTION  12u

/**
 * Maximum measurable voltage 
 */
#define MAXIMUM_MEASURABLE_VOLTAGE_IN_VOLTS  (float)( VOLTAGE_ADC_REFERENCE_IN_VOLTS / VOLTAGE_DIVIDER_RATIO )

                                                                          
#define ADC_VOLTAGE_SCALE (float)( MAXIMUM_MEASURABLE_VOLTAGE_IN_VOLTS / (float)( 1 << VOLTAGE_ADC_RESOLUTION ) )

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define VOLTAGE_MEASUREMENT_MODULE_A_CONFIG { \
        0u, \
        /* Input Ports */ \
        { \
            &mcHalI_DcBusVoltage_gdu16 \
        }, \
\
        /* Output Ports */ \
        { \
            &mcVolI_DcBusVoltage_gaf32[0u], \
            &mcVolI_DcBusVoltageFilt_gaf32[0u], \
            &mcVolI_UacPeakVoltage_gaf32[0u], \
        }, \
\
        /* User Parameters */ \
        { \
            ADC_VOLTAGE_SCALE, \
            1.0f \
        } \
    }
            
#define VOLTAGE_MEASUREMENT_MODULE_B_CONFIG { \
        1u, \
        /* Input Ports */ \
        { \
            &mcHalI_DcBusVoltage_gdu16 \
        }, \
\
        /* Output Ports */ \
        { \
            &mcVolI_DcBusVoltage_gaf32[1u], \
            &mcVolI_DcBusVoltageFilt_gaf32[1u], \
            &mcVolI_UacPeakVoltage_gaf32[1u], \
        }, \
\
        /* User Parameters */ \
        { \
            ADC_VOLTAGE_SCALE, \
            1.0f \
        } \
    }
/*******************************************************************************
 User defined data-types
 *******************************************************************************/

typedef enum _tmcVol_InstanceId_e
{
    volModuleInstance_01,
    volModuleInstance_02,
    volModuleInstance_max 
}tmcVol_InstanceId_e;


typedef struct _tmcVol_InputPorts_s
{
    volatile uint16_t * sensorInput;
}tmcVol_InputPorts_s;


typedef struct _tmcVol_OutputPorts_s
{
    float * busVoltage;
    float * filteredBusVoltage;
    float * maximumUacPeak;
}tmcVol_OutputPorts_s;

typedef struct _tmcVol_UserParameters_s
{
    
    float adcToVoltage;
    float busVoltageFiltParam;
}tmcVol_UserParameters_s;

typedef struct _tmcVol_Dependencies_s
{
    
}tmcVol_Dependencies_s;


typedef struct _tmcVol_ConfigParameters_s
{
    /* Instance Identifier */
    uint8_t Id;
    
    /* Input ports */
    tmcVol_InputPorts_s inPort;
    
    /* Output ports */
    tmcVol_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcVol_UserParameters_s userParam;
       
}tmcVol_ConfigParameters_s;

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
extern tmcVol_ConfigParameters_s mcVolI_ConfigurationParameters_gas[VOLTAGE_MEASUREMENT_INSTANCES];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Voltage calculation initialization function 
 * 
 * Details.
 *  Voltage calculation initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcVolI_VoltageCalculationInit( tmcVol_ConfigParameters_s * volParam );

/*! \brief Voltage calculation function 
 * 
 * Details.
 *  Voltage calculation function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcVolI_VoltageCalculationRun( const tmcVol_InstanceId_e Id );


/*! \brief Voltage calculation reset 
 * 
 * Details.
 *  Voltage calculation reset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcVolI_VoltageCalculationReset( const tmcVol_InstanceId_e Id );

#endif //MCVOL_H_

/**
 End of File
*/
