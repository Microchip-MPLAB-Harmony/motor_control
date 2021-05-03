/*******************************************************************************
 Motor Control Application Source file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_torque_control.c

  Summary:
    This file contains all the functions related to torque control 

  Description:
    This file contains implementation of torque control functions
 
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
static tmcReg_InputPorts_s mcReg_InputPorts_mas[1u];
static tmcReg_OutputPorts_s mcReg_OutputPorts_mas[1u];
static tmcLib_PiController_s mcReg_IdController_mas[1u];
static tmcLib_PiController_s mcReg_IqController_mas[1u];

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcReg_ConfigParameters_s mcRegI_ConfigurationParameters_gds = CURRENT_CONTROL_MODULE_CONFIG;

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

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
void  mcRegI_CurrentRegulationInit( tmcReg_ConfigParameters_s * regParam )
{
    tStd_ReturnType_e status;
    
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
     /* D axis current PI controller initialization */
     status = mcLib_PiControllerParametersSet( regParam->userParam.IdController.Kp,  regParam->userParam.IdController.Ki,
                                                           regParam->userParam.IdController.Ymax, &mcReg_IdController_mas[0u] );
    
    /* Q axis current PI controller initialization */
    status = mcLib_PiControllerParametersSet( regParam->userParam.IqController.Kp,  regParam->userParam.IqController.Ki,
                                                           regParam->userParam.IqController.Ymax, &mcReg_IqController_mas[0u] );
     
    ASSERT( ( returnType_Failed != status ), "PI Controller parameters setting failed");
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
#ifdef RAM_EXECUTE
void __ramfunc__ mcRegI_CurrentRegulationRun( const tmcReg_InstanceId_e Id )
#else
void mcRegI_CurrentRegulationRun( const tmcReg_InstanceId_e Id )
#endif
{    
     tmcLib_PiController_s  * idState;
     tmcLib_PiController_s  * iqState; 
     
     idState = &mcReg_IdController_mas[Id];
     iqState = &mcReg_IqController_mas[Id];
     
     if( mcState_Foc == mcMocI_MotorRunningState_gde )
     {
        /* Execute D axis current control */
        idState->Ymax = (int16_t)(*mcReg_InputPorts_mas[Id].UacPeak );      
        idState->Ymin = - idState->Ymax;
               
        idState->reference = *mcReg_InputPorts_mas[Id].Idref;
        idState->feedback = *mcReg_InputPorts_mas[Id].Idact;
        *mcReg_OutputPorts_mas[Id].Ud = mcLib_PiControllerRun( idState );
        
     }
     
     /* Execute Q axis current Control */ 
     iqState->Ymax =   mcLib_DetermineAdjSide(*mcReg_InputPorts_mas[Id].UacPeak, *mcReg_OutputPorts_mas[Id].Ud ); 
     iqState->Ymin  = - iqState->Ymax;
     iqState->reference = *mcReg_InputPorts_mas[Id].Iqref;
     iqState->feedback = *mcReg_InputPorts_mas[Id].Iqact; 
     *mcReg_OutputPorts_mas[Id].Uq = mcLib_PiControllerRun( iqState );

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

