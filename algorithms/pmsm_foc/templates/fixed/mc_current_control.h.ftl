/*******************************************************************************
  System Definitions

  File Name:
    mc_current_control.h

  Summary:
    Header file which shares global variables and function prototypes.

  Description:
    This file contains the global variables and function prototypes for motor torque control.
    Implemented in Q2.14 format..

 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCREG_H
#define MCREG_H

/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <sys/attribs.h>
#include "mc_interface_handling.h"
#include "mc_generic_library.h"
#include "mc_error_handler.h"
#include "math.h"

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define CURRENT_CONTROL_MODULE_CONFIG  {  \
    0, \
    /* Input Ports */ \
    { \
        &mcSpeI_ReferenceIdCurrent_gds16,  \
        &mcSpeI_ReferenceIqCurrent_gds16,   \
        &mcMocI_FeedbackDQCurrent_gds.direct,   \
        &mcMocI_FeedbackDQCurrent_gds.quadrature,    \
        NULL  \
    },    \
    /* Output Ports */    \
    {  \
        &mcMocI_DQVoltage_gds.direct ,     \
        &mcMocI_DQVoltage_gds.quadrature     \
    },       \
    /* User Parameters */ \
    {     \
        /* Q axis current controller parameters */ \
        {\
            /* Proportional gain */ \
            D_CURRENT_KP,      \
                             \
            /* Integral gain */ \
            D_CURRENT_KI,            \
                                                 \
            /* Anti-windup back calculation gain */ \
            D_CURRENT_YMAX   \
        },\
       /* Q axis current controller parameters */ \
        { \
            /* Proportional gain */ \
            Q_CURRENT_KP, \
                                             \
            /* Integral gain */ \
            Q_CURRENT_KI, \
                                        \
            /* Anti-windup back calculation gain */ \
            Q_CURRENT_YMAX \
        } \
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
    volatile int16_t * Idref;
    volatile int16_t * Iqref;
    volatile int16_t * Idact;
    volatile int16_t * Iqact;
    volatile int16_t * UacPeak;
}tmcReg_InputPorts_s;


typedef struct _tmcReg_OutputPorts_s
{
    int16_t * Ud;
    int16_t * Uq;
}tmcReg_OutputPorts_s;

typedef struct _tmcReg_PiController_s
{
    float Kp;
    float Ki;
    float Ymax;
}tmcReg_PiController_s;

typedef struct _tmcReg_UserParameters_s
{
    tmcReg_PiController_s IdController;
    tmcReg_PiController_s IqController;
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
extern tmcReg_ConfigParameters_s mcRegI_ConfigurationParameters_gds;

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
void  mcRegI_CurrentRegulationInit( tmcReg_ConfigParameters_s * regParam );

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
#ifdef RAM_EXECUTE
void __ramfunc__ mcRegI_CurrentRegulationRun( const tmcReg_InstanceId_e Id );
#else
void mcRegI_CurrentRegulationRun( const tmcReg_InstanceId_e Id );
#endif


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

#endif //_MCREG_H

/**
 End of File
*/
