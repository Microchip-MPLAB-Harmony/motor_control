/*******************************************************************************
 Current control functions 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_current_control.c

  Summary:
 Current control functions 

  Description:
 Current control functions 
 
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


/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include "mc_current_control.h"

/*******************************************************************************
 * Constants 
 *******************************************************************************/
#define     SQRT3_BY2                              (float)(0.866025403788)

/*******************************************************************************
 Private data-types 
 *******************************************************************************/

/*******************************************************************************
 Private variables 
 *******************************************************************************/
static tmcReg_InputPorts_s mcReg_InputPorts_mas[CURRENT_CONTROL_INSTANCES];
static tmcReg_OutputPorts_s mcReg_OutputPorts_mas[CURRENT_CONTROL_INSTANCES];
static tmcLib_PiController_s mcReg_IdController_mas[CURRENT_CONTROL_INSTANCES];
static tmcLib_PiController_s mcReg_IqController_mas[CURRENT_CONTROL_INSTANCES];

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcReg_ConfigParameters_s mcRegI_ConfigurationParameters_gas[CURRENT_CONTROL_INSTANCES] = 
{
   CURRENT_CONTROL_MODULE_A_CONFIG,
#if( 2u == CURRENT_CONTROL_INSTANCES )
   CURRENT_CONTROL_MODULE_B_CONFIG
#endif
};


/*******************************************************************************
 Private Functions 
 *******************************************************************************/
static tStd_ReturnType_e mcReg_AssertionFailedReaction( const char * message )
{
    /*ToDo: Decide appropriate fail reaction */
     return returnType_Failed;
}

#define ASSERT(expression, message) { if(!expression) mcReg_AssertionFailedReaction( message);}

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
tStd_ReturnType_e mcRegI_CurrentRegulationInit( tmcReg_ConfigParameters_s * regParam )
{
    /* Check if configuration parameters does not point to NULL */
    ASSERT(( NULL != regParam), "Configuration parameters points to NULL");
    
    /* Check if input ports are initialized properly */
    ASSERT(    ((  NULL != regParam->inPort.Idact ) && ( NULL != regParam->inPort.Iqact ) 
                 &&  (  NULL != regParam->inPort.Idref ) && ( NULL != regParam->inPort.Iqref ) ),
                          "Input Ports are not assigned");
    
    mcReg_InputPorts_mas[regParam->Id] = regParam->inPort;
    
     /* Check if output ports are initialized properly */
     ASSERT(((  NULL != regParam->outPort.Ud ) && ( NULL != regParam->outPort.Uq ) ),
                      "Output Ports are not assigned");
    
     mcReg_OutputPorts_mas[regParam->Id] = regParam->outPort;
     
     /* Update and calculate independent and dependent parameters respectively */
     mcReg_IdController_mas[regParam->Id] = regParam->userParam.IdController;
     mcReg_IqController_mas[regParam->Id] = regParam->userParam.IqController;
     
      return returnType_Passed;
}

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
void mcRegI_CurrentControllerParameterSet( const tmcReg_InstanceId_e Id,  tmcLib_PiControllerParameter_s * piParam )
{
    mcLib_PiControllerParametersSet( &mcReg_IdController_mas[Id], piParam );
}

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
void mcRegI_CurrentRegulationRun( const tmcReg_InstanceId_e Id )
{
    /* Direct axis current control  */
    mcReg_IdController_mas[Id].feedback =  *mcReg_InputPorts_mas[Id].Idact;
    mcReg_IdController_mas[Id].reference  =  *mcReg_InputPorts_mas[Id].Idref;
    mcLib_PiControllerRun(&mcReg_IdController_mas[Id] );
    
    /* Quadrature axis current reference  */ 
#if ( CONTROL_LOOP == TORQUE_LOOP )
  #if ( ENABLE == POTENTIOMETER_INPUT_ENABLED )  
    mcReg_IqController_mas[Id].reference = mcHalI_Potentiometer_gdu16 * Q_CURRENT_REF_TORQUE / 4096.0f; 
  #else 
    mcReg_IqController_mas[Id].reference  = Q_CURRENT_REF_TORQUE;
  #endif
#else 
    mcReg_IqController_mas[Id].reference  = *mcReg_InputPorts_mas[Id].Iqref;
#endif
    
    /* Quadrature axis current control  */
    mcReg_IqController_mas[Id].feedback = *mcReg_InputPorts_mas[Id].Iqact;
    mcLib_PiControllerRun(&mcReg_IqController_mas[Id]);
  
    /* Write output ports */
    *mcReg_OutputPorts_mas[Id].Uq =  mcReg_IqController_mas[0].Yout;
    *mcReg_OutputPorts_mas[Id].Ud =  mcReg_IdController_mas[0].Yout;
}

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
void mcRegI_IdCurrentControlOutputSet( uint8_t Id, float value )
{
    mcReg_IdController_mas[Id].Yout = value;
}

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
void mcRegI_IdCurrentControlIntegralSet( uint8_t Id, float value )
{
    mcReg_IdController_mas[Id].Yi = value;
}


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
void mcRegI_IqCurrentControlOutputSet( uint8_t Id, float value )
{
    mcReg_IqController_mas[Id].Yout = value;
}

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
void mcRegI_IqCurrentControlIntegralSet( uint8_t Id, float value )
{
    mcReg_IqController_mas[Id].Yi = value;
}

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
void mcRegI_CurrentRegulationReset( const tmcReg_InstanceId_e Id )
{
    /* Reset PI controller states */
    mcLib_PiControllerReset(&mcReg_IdController_mas[Id]);
    mcLib_PiControllerReset(&mcReg_IqController_mas[Id]);
    
    /* Reset output ports */
    *mcReg_OutputPorts_mas[Id].Uq =  0.0f;
    *mcReg_OutputPorts_mas[Id].Ud =  0.0f;
}
