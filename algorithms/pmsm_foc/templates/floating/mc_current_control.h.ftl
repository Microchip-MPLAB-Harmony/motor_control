/*******************************************************************************
 Current Regulation 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_current_regulaton.h

  Summary:
   Current regulation header file 

  Description:
  Current regulation header file 
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

#ifndef MCREG_H_    // Guards against multiple inclusion
#define MCREG_H_

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include <stddef.h>
#include "mc_interface_handling.h"
#include "mc_userparams.h"
#include "mc_generic_library.h"

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define CURRENT_CONTROL_INSTANCES 1u
#define CURRENT_CONTROL_MODULE_A_CONFIG  {\
        0u, \
        /* Input Ports */ \
        { \
            &mcSpeI_ReferenceIdCurrent_gaf32[0u], \
            &mcSpeI_ReferenceIqCurrent_gaf32[0u], \
            &mcMocI_FeedbackDQCurrent_gas[0u].direct, \
            &mcMocI_FeedbackDQCurrent_gas[0u].quadrature, \
            NULL \
        },\
        /* Output Ports */ \
        { \
            &mcMocI_DQVoltage_gas[0u].direct , \
            &mcMocI_DQVoltage_gas[0u].quadrature \
        }, \
        /* User Parameters */ \
        {\
            /* Q axis current controller parameters */ \
            { \
                /* Reference Signal */ \
                0.0f,\
\
                /* Feedback signal */ \
                0.0f, \
\
                /* Proportional gain */ \
                Q_CURRENT_KP, \
\
                /* Integral gain */ \
                Q_CURRENT_KI, \
\
                /* Anti-windup back calculation gain */ \
                Q_CURRENT_KC, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */\
                Q_CURRENT_YMAX, \
\
               /* Negative saturation limit */ \
                -Q_CURRENT_YMAX, \
\
                /* Control output */\
                0.0f \
            }, \
            /*D axis current controller parameters */ \
            { \
                /* Reference Signal */\
                0.0f,\
\
                /* Feedback signal */\
                0.0f,\
 \
                /* Proportional gain */ \
                D_CURRENT_KP, \
\
                /* Integral gain */ \
                D_CURRENT_KI, \
\
                /* Anti-windup back calculation gain */ \
                D_CURRENT_KC, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */ \
                D_CURRENT_YMAX, \
\
                /* Negative saturation limit */ \
                -D_CURRENT_YMAX, \
\
                /* Control output */ \
                0.0f       \
            }\
        }  \
    }
            
  #define CURRENT_CONTROL_MODULE_B_CONFIG  {\
        1u, \
        /* Input Ports */ \
        { \
            &mcSpeI_ReferenceIdCurrent_gaf32[1u], \
            &mcSpeI_ReferenceIqCurrent_gaf32[1u], \
            &mcMocI_FeedbackDQCurrent_gas[1u].direct, \
            &mcMocI_FeedbackDQCurrent_gas[1u].quadrature, \
            NULL \
        },\
        /* Output Ports */ \
        { \
            &mcMocI_DQVoltage_gas[1u].direct , \
            &mcMocI_DQVoltage_gas[1u].quadrature \
        }, \
        /* User Parameters */ \
        {\
            /* Q axis current controller parameters */ \
            { \
                /* Reference Signal */ \
                0.0f,\
\
                /* Feedback signal */ \
                0.0f, \
\
                /* Proportional gain */ \
                Q_CURRENT_KP, \
\
                /* Integral gain */ \
                Q_CURRENT_KI, \
\
                /* Anti-windup back calculation gain */ \
                Q_CURRENT_KC, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */\
                Q_CURRENT_YMAX, \
\
               /* Negative saturation limit */ \
                -Q_CURRENT_YMAX, \
\
                /* Control output */\
                0.0f \
            }, \
            /*D axis current controller parameters */ \
            { \
                /* Reference Signal */\
                0.0f,\
\
                /* Feedback signal */\
                0.0f,\
 \
                /* Proportional gain */ \
                D_CURRENT_KP, \
\
                /* Integral gain */ \
                D_CURRENT_KI, \
\
                /* Anti-windup back calculation gain */ \
                D_CURRENT_KC, \
\
                /* Last integral */ \
                0.0f, \
\
                /* Positive saturation limit */ \
                D_CURRENT_YMAX, \
\
                /* Negative saturation limit */ \
                -D_CURRENT_YMAX, \
\
                /* Control output */ \
                0.0f       \
            }\
        }  \
}
    
/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef enum _tmcReg_InstanceId_e
{
    regModuleInstance_01,
    regModuleInstance_02,
    regModuleInstance_max
}tmcReg_InstanceId_e;

typedef struct _tmcReg_InputPorts_s
{
    volatile float * Idref;
    volatile float * Iqref;
    volatile float * Idact;
    volatile float * Iqact;
    volatile float * UacPeak;
}tmcReg_InputPorts_s;


typedef struct _tmcReg_OutputPorts_s
{
    float * Ud;
    float * Uq;
}tmcReg_OutputPorts_s;


typedef struct _tmcReg_UserParameters_s
{
    tmcLib_PiController_s IdController;
    tmcLib_PiController_s IqController;
}tmcReg_UserParameters_s;

typedef struct _tmcReg_Dependencies_s
{
    
}tmcReg_Dependencies_s;


typedef struct _tmcReg_ConfigParameters_s
{
    /* Instance Identifier */
    uint8_t Id;
    
    /* Input ports */
    tmcReg_InputPorts_s inPort;
    
    /* Output ports */
    tmcReg_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcReg_UserParameters_s userParam;
       
}tmcReg_ConfigParameters_s;

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
extern tmcReg_ConfigParameters_s mcRegI_ConfigurationParameters_gas[CURRENT_CONTROL_INSTANCES];

/*******************************************************************************
 Interface Functions 
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
tStd_ReturnType_e mcRegI_CurrentRegulationInit( tmcReg_ConfigParameters_s * regParam );


/*! \brief Current control PI parameter set  
 * 
 * Details.
 *  Current control PI parameter set
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRegI_CurrentControllerParameterSet( const tmcReg_InstanceId_e Id,  tmcLib_PiControllerParameter_s * piParam );

/*! \brief Current control execution function 
 * 
 * Details.
 *  Current control execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRegI_CurrentRegulationRun( const tmcReg_InstanceId_e Id );


/*! \brief Set Id current control output directly 
 * 
 * Details.
 *  Set Id current control output directly 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRegI_IdCurrentControlOutputSet( uint8_t Id, float value );

/*! \brief Set Id current control integrator directly 
 * 
 * Details.
 *  Set Id current control integrator directly
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRegI_IdCurrentControlIntegralSet( uint8_t Id, float value );


/*! \brief Set Iq current control output directly 
 * 
 * Details.
 *  Set Iq current control output directly 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRegI_IqCurrentControlOutputSet( uint8_t Id, float value );

/*! \brief Set Iq current control integrator directly 
 * 
 * Details.
 *  Set Iq current control integrator directly
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRegI_IqCurrentControlIntegralSet( uint8_t Id, float value );

/*! \brief Current control reset function 
 * 
 * Details.
 *  Current control reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRegI_CurrentRegulationReset( const tmcReg_InstanceId_e Id );

#endif //MCREG_H

/**
 End of File
*/
