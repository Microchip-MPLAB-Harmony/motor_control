/*******************************************************************************
  Speed control Source File

  Company:
    Microchip Technology Inc.

  File Name:
  mc_speed_control.c

  Summary:
    This file contains functions for speed control

  Description:
    This file contains functions for speed control 
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "mc_speed_control.h"

/*******************************************************************************
 Constants 
 *******************************************************************************/
#define EPSILON   1E-31


/**
 * Constant value of PI
 */
#define CONSTANT_Pi                                (float)3.14159265358979323846

/**
 * RPM to Rad Per Second Conversion factor
 */
#define CONSTANT_RpmToRadPerSec        (float)( 2.0f * CONFIG_SpeNumberOfPolePairs * CONSTANT_Pi / 60.0f )


/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcSpe_Parameters_s
{
    float adcCountToSpeed;
    float refSpeedFiltParam;
    float minReferenceSpeed;
    float maxReferenceSpeed;
}tmcSpe_Parameters_s;

typedef struct _tmcSpe_StateVariables_s
{
    float referenceSpeed;
}tmcSpe_StateVariables_s;



/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcSpe_InputPorts_s mcSpe_InputPorts_mas[SPEED_CONTROL_INSTANCES];
static tmcSpe_OutputPorts_s mcSpe_OutputPorts_mas[SPEED_CONTROL_INSTANCES];
static tmcSpe_Parameters_s mcSpe_Parameters_mas[SPEED_CONTROL_INSTANCES];
static tmcLib_PiController_s mcSpe_SpeedController_mas[SPEED_CONTROL_INSTANCES];

/*******************************************************************************
 Interface variables  
 *******************************************************************************/
tmcSpe_ConfigParameters_s  mcSpeI_ConfigParameters_gas[SPEED_CONTROL_INSTANCES] = 
{
   SPEED_CONTROL_MODULE_A_CONFIG,
#if( 2u == SPEED_CONTROL_INSTANCES )
   SPEED_CONTROL_MODULE_B_CONFIG
#endif
};

/*******************************************************************************
 Private Functions 
 *******************************************************************************/
static tStd_ReturnType_e mcSpe_AssertionFailedReaction( const char * message )
{
    /* ToDo: Decide an appropriate assertion failed reaction function */
     return returnType_Failed;
}


void mcSpe_LinearRamping( float * pInput, const float rampRate, float Final )
{
    if( *pInput < ( Final - rampRate ))
    {
        *pInput += rampRate;
    }
    else if( *pInput > ( Final + rampRate ))
    {
        *pInput -= rampRate;
    }
    else
    {
        *pInput = Final;
    }
}


void mcSpe_MinimumLimitSet( float * value, float minLimit )
{
    if( *value < minLimit ) 
    {
        *value = minLimit;
    }
}

#define ASSERT( expression, message ) {if(!expression)mcSpe_AssertionFailedReaction(message);}

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Speed control module initialization function 
 * 
 * Details.
 *  Speed control module initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e  mcSpeI_SpeedRegulationInit( const tmcSpe_ConfigParameters_s * const speParam )
{
    tmcSpe_Parameters_s * pParam;
    
    /* Check if the configuration parameters data has valid address */
    ASSERT(( NULL != speParam ), "Configuration parameters points to NULL address ");
    
    /* Initialize input ports */
    ASSERT((      ( NULL != speParam->inPort.actualSpeed) && (NULL != speParam->inPort.potReading) 
                     && ( NULL != speParam->inPort.referenceSpeed)), "Input ports are not assigned properly");
    
    
    mcSpe_InputPorts_mas[speParam->Id] = speParam->inPort;
    
    /* Initialize output ports */
    ASSERT((( NULL != speParam->outPort.iqref ) && (NULL != speParam->outPort.referenceSpeed)), 
                     "Output ports are not assigned properly");
        
    mcSpe_OutputPorts_mas[speParam->Id] = speParam->outPort;

#if (( CONTROL_LOOP == SPEED_LOOP ) && ( ENABLE != POTENTIOMETER_INPUT_ENABLED ) ) 
   mcRmpI_ReferenceProfileInit( &mcRmpI_RampProfilerConfig_mds);
#endif
    
    /* Update and calculate independent and dependent parameters respectively */
    pParam = &mcSpe_Parameters_mas[speParam->Id];
    
    pParam->minReferenceSpeed = CONSTANT_RpmToRadPerSec * speParam->userParam.minReferenceSpeed;
    pParam->maxReferenceSpeed = CONSTANT_RpmToRadPerSec * speParam->userParam.maxReferenceSpeed;
    pParam->adcCountToSpeed = pParam->maxReferenceSpeed / 4096.0f;
    pParam->refSpeedFiltParam = speParam->userParam.speedFilterParam;
    
    mcSpe_SpeedController_mas[speParam->Id] = speParam->userParam.speedController;
    
    return returnType_Passed;
}

/*! \brief Speed control module run function 
 * 
 * Details.
 *  Speed control module run function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedRegulationRun( const tmcSpe_InstanceId_e Id )
{  
    if(  1u == mcMocI_RunningStatus_gde[Id] )
    {  
        /* Read input ports */
        
    #if ( CONTROL_LOOP == TORQUE_LOOP )
    #if ( ENABLE == POTENTIOMETER_INPUT_ENABLED )  
        *mcSpe_OutputPorts_mas[Id].iqref =  mcHalI_Potentiometer_gdu16 * Q_CURRENT_REF_TORQUE / 4096.0f; 
        *mcSpe_OutputPorts_mas[Id].iqref*= (float)mcMocI_RotationSign_gas8[0u];
     #else 
        *mcSpe_OutputPorts_mas[Id].iqref = Q_CURRENT_REF_TORQUE;
        *mcSpe_OutputPorts_mas[Id].iqref *= (float)mcMocI_RotationSign_gas8[0u];
       #endif
        return;
    #endif      
        
    #if ( CONTROL_LOOP == SPEED_LOOP )
    #if ( ENABLE == POTENTIOMETER_INPUT_ENABLED )  
        float refSpeed;
        
        /* Calculate reference speed */
        refSpeed  = *mcSpe_InputPorts_mas[Id].potReading * mcSpe_Parameters_mas[Id].adcCountToSpeed;
        mcSpe_MinimumLimitSet( &refSpeed,  mcSpe_Parameters_mas[Id].minReferenceSpeed );
        refSpeed *= mcMocI_RotationSign_gas8[Id];
        mcSpe_LinearRamping(mcSpe_OutputPorts_mas[Id].referenceSpeed, CONFIG_RampRate, refSpeed);
    #else
        float refSpeed;
        refSpeed = mcRmpI_ReferenceProfileGenerate(  );
        mcSpe_MinimumLimitSet( &refSpeed,  mcSpe_Parameters_mas[Id].minReferenceSpeed );
        *mcSpe_OutputPorts_mas[Id].referenceSpeed  = mcMocI_RotationSign_gas8[Id] *  refSpeed;
    #endif
      /*Run PI controller for speed */
       mcSpe_SpeedController_mas[Id].reference = *mcSpe_OutputPorts_mas[Id].referenceSpeed;        
       mcSpe_SpeedController_mas[Id].feedback = *mcSpe_InputPorts_mas[Id].actualSpeed;

        mcLib_PiControllerRun(&mcSpe_SpeedController_mas[Id] );
        
        /* Update PI controller output */
       *mcSpe_OutputPorts_mas[Id].iqref =  mcSpe_SpeedController_mas[Id].Yout;
        
        /* Write output ports */
    #endif
    }
        
}



/*! \brief Set speed control control output directly 
 * 
 * Details.
 *  Set speed control output directly 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedControlOutputSet( uint8_t Id, float value )
{
    mcSpe_SpeedController_mas[Id].Yout = value;
}

/*! \brief Set speed control integrator directly 
 * 
 * Details.
 *  Set speed control integrator directly
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedControlIntegralSet( uint8_t Id, float value )
{
    mcSpe_SpeedController_mas[Id].Yi = value;
}

/*! \brief Speed control module reset function 
 * 
 * Details.
 *  Speed control module reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSpeI_SpeedRegulationReset( const tmcSpe_InstanceId_e Id )
{
    /* Reset state variables */
    mcLib_PiControllerReset( &mcSpe_SpeedController_mas[Id]);
#if (( CONTROL_LOOP == SPEED_LOOP ) && ( ENABLE != POTENTIOMETER_INPUT_ENABLED ))  
    mcRmpI_ReferenceProfileReset();
#endif 
           
    /* Reset output ports */
    *mcSpe_OutputPorts_mas[Id].iqref = 0.0f;
    *mcSpe_OutputPorts_mas[Id].referenceSpeed = 0.0f;
    
}
