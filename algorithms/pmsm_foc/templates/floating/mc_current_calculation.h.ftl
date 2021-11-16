/*******************************************************************************
 Motor Control current measurement interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_current_calculation.h

  Summary:
    Header file for current measurement

  Description:
    This file contains the data structures and function prototypes of current measurement.
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

#ifndef MCCUR_H_    // Guards against multiple inclusion
#define MCCUR_H_

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
/**
 * Number of module instances
 */
#define DUAL_SHUNT_MEASUREMENT_INSTANCES 1u
/**
 * Shunt resistance connected to inverter A leg 
 */
#define INVERTER_A_SHUNT_RESISTANCE_IN_OHM    (float)0.025

/**
 * Inverter A current amplifier gain 
 */
#define INVERTER_A_CURRENT_AMPLIFIER_GAIN   (float)15.0f

/**
 * Inverter A current amplifier offset 
 */
#define INVERTER_A_CURRENT_AMPLIFIER_OFFSET   (float)1.65f

/**
 * Inverter A current amplifier offset 
 */
#define ADC_REFERENCE_VOLTAGE_IN_VOLTS  (float)3.3f

/**
 * Maximum measurable current  
 */
#define MAXIMUM_MEASURABLE_CURRENT_IN_AMPS     (    ADC_REFERENCE_VOLTAGE_IN_VOLTS                     \
                                                                                                  - INVERTER_A_CURRENT_AMPLIFIER_OFFSET )         \
                                                                                              / (   INVERTER_A_CURRENT_AMPLIFIER_GAIN              \
                                                                                                  * INVERTER_A_SHUNT_RESISTANCE_IN_OHM )       \

/**
 * ADC Resolution 
 */
#define ADC_RESOLUTION      12u

/**
 * ADC count to amperes  
 */
#define ADC_CURRENT_SCALE  (float)( MAXIMUM_MEASURABLE_CURRENT_IN_AMPS / (float)( 1 << ADC_RESOLUTION ))

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define CURRENT_MEASUREMENT_MODULE_A_CONFIG {\
        /* Instance Id */\
        0u, \
        /* Input ports */\
        {\
            &mcHalI_PhaseACurrent_gdu16, \
            &mcHalI_PhaseBCurrent_gdu16 \
        }, \
        /* Output ports */ \
        { \
            { \
                &mcCurI_PhaseCurrents_gas[0u].a, \
                &mcCurI_PhaseCurrents_gas[0u].b, \
                &mcCurI_PhaseCurrents_gas[0u].c, \
            }, \
            &mcCurI_CurrentOffsetCalibDone_gau8[0u] \
        }, \
        /* User Parameters */ \
        {\
              1900, \
              2200, \
              ADC_CURRENT_SCALE \
        }\
    }\

#define CURRENT_MEASUREMENT_MODULE_B_CONFIG {\
        /* Instance Id */\
        1u, \
        /* Input ports */\
        {\
            &mcHalI_PhaseACurrent_gdu16, \
            &mcHalI_PhaseBCurrent_gdu16 \
        }, \
        /* Output ports */ \
        { \
            { \
                &mcCurI_PhaseCurrents_gas[1u].a, \
                &mcCurI_PhaseCurrents_gas[1u].b, \
                &mcCurI_PhaseCurrents_gas[1u].c, \
            }, \
            &mcCurI_CurrentOffsetCalibDone_gau8[1u] \
        }, \
        /* User Parameters */ \
        {\
              1900, \
              2200, \
              ADC_CURRENT_SCALE \
        }\
    }\


/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef enum _tmcCur_InstanceId_e
{
    curModuleInstance_01,
    curModuleInstance_02,
    CurModuleInstance_max 
}tmcCur_InstanceId_e;

typedef struct _tmcCur_InputPorts_s
{
    uint16_t * iaAdcInput;
    uint16_t * ibAdcInput;
}tmcCur_InputPorts_s;


typedef struct _tmcCur_PhaseCurrents_s
{
    float * ia;
    float * ib;
    float * ic;
}tmcCur_PhaseCurrents_s;

typedef struct _tmcCur_OutputPorts_s
{
    tmcCur_PhaseCurrents_s  phaseCurrents;
    uint8_t * calibDone;
}tmcCur_OutputPorts_s;

typedef struct _tmcCur_UserParameters_s
{
   float minOffset;
   float maxOffset;
   float adcToCurrent;
}tmcCur_UserParameters_s;

typedef struct _tmcCur_ConfigParameters_s
{
   /* Instance Id */
    uint8_t Id;
    
    /* Input ports */
    tmcCur_InputPorts_s inPort;
    
    /* Output ports */
    tmcCur_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcCur_UserParameters_s userParam;
    
}tmcCur_ConfigParameters_s;


/*******************************************************************************
 Interface variables 
 *******************************************************************************/
extern tmcCur_ConfigParameters_s mcCurI_ConfigurationParameters_gas[DUAL_SHUNT_MEASUREMENT_INSTANCES];

/*******************************************************************************
 Interface functions 
 *******************************************************************************/


/*! \brief Current control initialization function 
 * 
 * Details.
 *  Current control initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcCurI_CurrentCalculationInit( tmcCur_ConfigParameters_s * curParam );

/*! \brief Function to calculate the current sensor offset  
 * 
 * Details.
 * Function to calculate current sensor offset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcCurI_CurrentSensorOffsetCalculate( const uint8_t Id );
    
/*! \brief Function to calculate the phase  currents
 * 
 * Details.
 * Function to calculate phase currents 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcCurI_CurrentCalculationRun( const tmcCur_InstanceId_e Id );

   
/*! \brief Function to reset phase current calculation 
 * 
 * Details.
 * Function to reset phase current calculation  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcCurI_CurrentCalculationReset( const tmcCur_InstanceId_e Id );

#endif //MCCUR_H_

/**
 End of File
*/
