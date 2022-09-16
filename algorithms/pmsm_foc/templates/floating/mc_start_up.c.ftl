/*******************************************************************************
 Open loop start up functions 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_start_up.c

  Summary:
  Open loop start up functions 

  Description:
  Open loop start up functions 
 
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
#include "mc_start_up.h"

/*******************************************************************************
 * Constants 
 *******************************************************************************/
#define CONSTANT_Pi                       (float)( 3.14159265358979323846 )
#define CONSTANT_PiBy2                 (float)( 0.5f * CONSTANT_Pi         )


/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef enum
{
    startupState_InitialPosition,
    startupState_OpenLoopRamp,
    startupState_OpenLoopStable     
}tmcSup_StartupState_e;

typedef struct _tmcSup_Parameters_s
{
    float currentRampRate;
    float alignmentCurrent;
    float openLoopCurrent;
    float openLoopSpeedRate;
    uint32_t alignmentTimeLoopCount;
    uint32_t halfAlignmentTimeLoopCount;
    uint32_t openLoopRampTimeLoopCount;
    uint32_t openLoopStabTimeLoopCount;
}tmcSup_Parameters_s;

typedef struct _tmcSup_StateVariables_s
{
    tmcSup_StartupState_e startupStatus;
    float openLoopIncrementTheta;
    uint32_t   trackCounter;
}tmcSup_StateVariables_s;

/*******************************************************************************
 Private variables 
 *******************************************************************************/
static tmcSup_OutputPorts_s mcSup_OutputPorts_mas[START_UP_INSTANCES];
static tmcSup_Parameters_s mcSup_Parameters_mas[START_UP_INSTANCES];
tmcSup_StateVariables_s mcSup_StateVariables_mas[START_UP_INSTANCES];

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcSup_ConfigParameters_s mcSupI_ConfigurationParameters_gas[START_UP_INSTANCES] = 
{
    START_UP_MODULE_A_CONFIG,
#if( 2u == START_UP_INSTANCES )
    START_UP_MODULE_B_CONFIG
#endif
};

/*******************************************************************************
 Private Functions 
 *******************************************************************************/
static tStd_ReturnType_e  mcSup_AssertionFailedReaction( const char * message )
{
    /*ToDo: Decide appropriate fail reaction */
     return returnType_Failed;
}

#define ASSERT(expression, message) { if(!expression) mcSup_AssertionFailedReaction( message);}

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
/*! \brief Open loop start up initialization function 
 * 
 * Details.
 *  Open loop start up initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e  mcSupI_OpenLoopStartupInit( tmcSup_ConfigParameters_s * supParam )
{
    float openLoopTransSpeedinRadPerSec = 0.0f;
    tmcSup_Parameters_s * pParam;
    
    /* Check if the configuration parameters do not points to NULL */
    ASSERT( ( NULL != supParam ), "Configuration parameters points to NULL");
    
    /*Initialize output ports */
    ASSERT( ( ( NULL != supParam->outPort.Idref ) && ( NULL != supParam->outPort.Iqref )
                && ( NULL != supParam->outPort.theta )) , "Output ports are not assigned properly");
    
     mcSup_OutputPorts_mas[supParam->Id] = supParam->outPort;
     
     /*Update and calculate independent and dependent parameters respectively */     
     pParam = & mcSup_Parameters_mas[supParam->Id];
    
     pParam->alignmentCurrent = supParam->userParam.alignmentCurrent;
     pParam->alignmentTimeLoopCount = supParam->userParam.alignmentTime  / supParam->userParam.Ts;

     pParam->halfAlignmentTimeLoopCount = pParam->alignmentTimeLoopCount >> 1u;
    
     pParam->openLoopCurrent = supParam->userParam.openLoopCurrent;
     pParam->openLoopRampTimeLoopCount = supParam->userParam.openLoopRampTime / supParam->userParam.Ts;
     pParam->openLoopStabTimeLoopCount = supParam->userParam.openLoopStabTime / supParam->userParam.Ts;
     pParam->currentRampRate = pParam->openLoopCurrent/ pParam->halfAlignmentTimeLoopCount;
    
     openLoopTransSpeedinRadPerSec  =  2.0f * CONSTANT_Pi * NUM_POLE_PAIRS * supParam->userParam.openLoopTransSpeed / 60.0f;
     pParam->openLoopSpeedRate =   openLoopTransSpeedinRadPerSec /( pParam->openLoopRampTimeLoopCount / supParam->userParam.Ts ); 
    
     /* Update state variables */
     mcSup_StateVariables_mas[supParam->Id].startupStatus = startupState_InitialPosition;
             
    return returnType_Passed;
}


/*! \brief Initial rotor position set 
 * 
 * Details.
 *  Initial rotor position set 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSupI_InitialPositionSet( void )
{
    
  
}

/*! \brief Open loop start up execution function 
 * 
 * Details.
 *  Open loop start up execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
uint8_t mcSupI_OpenLoopStartupRun( const tmcSup_InstanceId_e Id )
{
    uint8_t status = 0u; 
     
    switch( mcSup_StateVariables_mas[Id].startupStatus )
    {
        /* Lock the rotor at specified rotor angle */
        case startupState_InitialPosition:
        {   
           float iref;
            
           mcSup_StateVariables_mas[Id].trackCounter++;
           iref = mcSup_StateVariables_mas[Id].trackCounter *   mcSup_Parameters_mas[Id].currentRampRate; 

            if( mcSup_Parameters_mas[Id].halfAlignmentTimeLoopCount >= mcSup_StateVariables_mas[Id].trackCounter )
            {
              #if(Q_AXIS == ALIGNMENT_METHOD )
                *mcSup_OutputPorts_mas[Id].theta = mcMocI_RotationSign_gas8[Id] * CONSTANT_Pi;
                *mcSup_OutputPorts_mas[Id].Idref = 0.0f;
                *mcSup_OutputPorts_mas[Id].Iqref = mcMocI_RotationSign_gas8[Id] * iref;
              #else
               *mcSup_OutputPorts_mas[Id].theta =  mcMocI_RotationSign_gas8[Id] * CONSTANT_PiBy2;
               *mcSup_OutputPorts_mas[Id].Iqref = 0.0f;
               *mcSup_OutputPorts_mas[Id].Idref = mcMocI_RotationSign_gas8[Id] * iref;
              #endif
            }
            else if( mcSup_Parameters_mas[Id].alignmentTimeLoopCount >= mcSup_StateVariables_mas[Id].trackCounter )
            {
              #if(Q_AXIS == ALIGNMENT_METHOD )
                *mcSup_OutputPorts_mas[Id].theta = 3*mcMocI_RotationSign_gas8[Id] * CONSTANT_PiBy2;
                *mcSup_OutputPorts_mas[Id].Idref = 0.0f;
                *mcSup_OutputPorts_mas[Id].Iqref = mcMocI_RotationSign_gas8[Id] *  mcSup_Parameters_mas[Id].alignmentCurrent;
              #else
               *mcSup_OutputPorts_mas[Id].theta = 0.0f;
               *mcSup_OutputPorts_mas[Id].Idref =  mcMocI_RotationSign_gas8[Id] *  mcSup_Parameters_mas[Id].alignmentCurrent;
                *mcSup_OutputPorts_mas[Id].Iqref = 0.0f;
              #endif
            }
            else 
            {
                mcSup_StateVariables_mas[Id].trackCounter = 0u;
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
                /* Trigger Encoder */
                mcRpoI_RotorPositionCalculationStart(Id);

              #if ( OPEN_LOOP  == CONTROL_LOOP )
                /* Change open loop state */
                mcSup_StateVariables_mas[Id].startupStatus = startupState_OpenLoopRamp;

              #else
                /* Update alignment status */
                mcSupI_RotorFieldAlignmentStatus_gdu8 = 1u;
                
                /* Return success  */
                status = 1u; 
                
              #endif
<#elseif MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORLESS_SMO'>
              /* Trigger rotor position calculation */
              mcRpoI_RotorPositionCalculationTrigger(Id);

              /* Change open loop state */
              mcSup_StateVariables_mas[Id].startupStatus = startupState_OpenLoopRamp; 

<#else>  
              /* Change open loop state */
              mcSup_StateVariables_mas[Id].startupStatus = startupState_OpenLoopRamp;             
             
</#if>                
            }
        }
        break;
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
   #if ( OPEN_LOOP  == CONTROL_LOOP )
</#if>
       /* Ramp the speed of the motor  */
        case startupState_OpenLoopRamp:
        {
            if( mcSup_Parameters_mas[Id].openLoopRampTimeLoopCount >= mcSup_StateVariables_mas[Id].trackCounter )
            {               
                mcSup_StateVariables_mas[Id].trackCounter++; 
                mcSup_StateVariables_mas[Id].openLoopIncrementTheta +=  mcSup_Parameters_mas[Id].openLoopSpeedRate;
            }
            else
            {
                mcSup_StateVariables_mas[Id].trackCounter = 0u;
                mcSup_StateVariables_mas[Id].startupStatus = startupState_OpenLoopStable;
            }
                       
            /* Set output ports for alignment */
            *mcSup_OutputPorts_mas[Id].Idref = 0.0f;
            *mcSup_OutputPorts_mas[Id].Iqref =  mcMocI_RotationSign_gas8[Id] * mcSup_Parameters_mas[Id].alignmentCurrent;
            *mcSup_OutputPorts_mas[Id].theta += ( mcMocI_RotationSign_gas8[Id] * mcSup_StateVariables_mas[Id].openLoopIncrementTheta );
            mcLib_WrapAngleTo2Pi( mcSup_OutputPorts_mas[Id].theta );
        }
        break;
        
         /* Maintain the speed of the motor  */
        case startupState_OpenLoopStable:
        {
            if( mcSup_Parameters_mas[Id].openLoopStabTimeLoopCount >= mcSup_StateVariables_mas[Id].trackCounter )
            {
                mcSup_StateVariables_mas[Id].trackCounter++; 
            }
            else
            {
                mcSup_StateVariables_mas[Id].trackCounter = 0u; 
            #if ( OPEN_LOOP  != CONTROL_LOOP )
                mcSup_StateVariables_mas[Id].startupStatus = startupState_InitialPosition;
                status = 1u;
            #endif
            }
            
             /* Set output ports for alignment */
             *mcSup_OutputPorts_mas[Id].Idref = 0.0f;
             *mcSup_OutputPorts_mas[Id].Iqref =  mcMocI_RotationSign_gas8[Id] * mcSup_Parameters_mas[0].alignmentCurrent;
             *mcSup_OutputPorts_mas[Id].theta += ( mcMocI_RotationSign_gas8[Id] * mcSup_StateVariables_mas[Id].openLoopIncrementTheta );
             mcLib_WrapAngleTo2Pi( mcSup_OutputPorts_mas[Id].theta );
        }
        break;
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
#endif 
</#if>  
        default:
        {
            /* Should not come here */
        }
    }
    return status;
}

/*! \brief Open loop start up reset function 
 * 
 * Details.
 *  Open loop start up  reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcSupI_OpenLoopStartupReset( const tmcSup_InstanceId_e Id )
{
    /* Reset state variables */
    mcSup_StateVariables_mas[Id].openLoopIncrementTheta = 0.0f;
    mcSup_StateVariables_mas[Id].trackCounter = 0u;
    mcSup_StateVariables_mas[Id].startupStatus = startupState_InitialPosition;
    
    /* Reset output ports */
    *mcSup_OutputPorts_mas[Id].Idref = 0.0f;
    *mcSup_OutputPorts_mas[Id].Iqref = 0.0f;
    *mcSup_OutputPorts_mas[Id].theta = 0.0f;
    
}