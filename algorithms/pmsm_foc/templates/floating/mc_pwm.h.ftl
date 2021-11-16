/*******************************************************************************
 Space Vector PWM interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pwm.h

  Summary:
    Header file for mc_pwm.c

  Description:
    This file contains the data structures and function prototypes used by
    PWM module
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

#ifndef MCPWM_H    // Guards against multiple inclusion
#define MCPWM_H


/*******************************************************************************
 Header Inclusions
 *******************************************************************************/

#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_generic_library.h"
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 Parameters 
 *******************************************************************************/
#define PWM_INSTANCES 1u
/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define PWM_MODULE_A_CONFIG   { \
        0u, \
        { \
            &mcMocI_AlphaBetaVoltage_gas[0u].alpha, &mcMocI_AlphaBetaVoltage_gas[0u].beta \
        }, \
        { \
            PWM_FREQUENCY, \
        } \
    }

#define PWM_MODULE_B_CONFIG { \
        1u, \
        { \
            &mcMocI_AlphaBetaVoltage_gas[0u].alpha, &mcMocI_AlphaBetaVoltage_gas[0u].beta \
        }, \
        { \
            PWM_FREQUENCY, \
        } \
    }

/*******************************************************************************
 Private data-types
 *******************************************************************************/
typedef enum _tmcPwm_InstanceId_e
{
    pwmModuleInstance_01,
    pwmModuleInstance_02,
    pwmModuleInstance_max 
}tmcPwm_InstanceId_e;

typedef struct _tmcPwm_InputPorts_s 
{
    volatile float * ualpha_pf32;
    volatile float * ubeta_pf32;
}tmcPwm_InputPorts_s;


typedef struct _tmcPwm_OutputPorts_s 
{

}tmcPwm_OutputPorts_s;

typedef struct _tmcPwm_UserParameters_s 
{
    uint32_t frequencyInHz;
}tmcPwm_UserParameters_s;

typedef struct _tmcPwm_Dependencies_d
{
    
}tmcPwm_Dependencies_s;

typedef struct _tmcPwm_Parameters_s 
{
    uint32_t frequencyInHz;
    uint32_t  period;
}tmcPwm_Parameters_s;

typedef struct _tmcPwm_ConfigParameters_s 
{
    /* Instance Id */
    tmcPwm_InstanceId_e Id; 
    
    /* Input port */
    tmcPwm_InputPorts_s     inPort;
    
    /* User Parameter */
    tmcPwm_UserParameters_s   userParam;
    
//     /* Dependencies  */
//    tmcPwm_Dependencies_s   dependency;
//    
//    /* Output Port */
//    tmcPwm_OutputPorts_s    outPort;
    
}tmcPwm_ConfigParameters_s;


/*******************************************************************************
 Interface variables 
 *******************************************************************************/
extern tmcPwm_ConfigParameters_s mcPwmI_ConfigParameters_gas[PWM_INSTANCES];


/*! \brief PWM Module instance initialization 
 * 
 * Details.
 *  PWM Module instance initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

tStd_ReturnType_e mcPwmI_PulseWidthModulationInit( const tmcPwm_ConfigParameters_s * const pwmConfigParam );



/*! \brief Execute PWM Module instance
 * 
 * Details.
 *  Execute PWM Module instance   
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcPwmI_PulseWidthModulationRun( const tmcPwm_InstanceId_e Id  );


/*! \brief Reset PWM Module instance
 * 
 * Details.
 *  Reset PWM Module instance   
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcPwmI_PulseWidthModulationReset( const tmcPwm_InstanceId_e Id  );


#endif //MCPWM_H

/**
 End of File
*/
