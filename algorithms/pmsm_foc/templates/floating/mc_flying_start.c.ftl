/*******************************************************************************
   Flying start source file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_flying_start.c

  Summary:
    Flying start source file 

  Description:
    Flying start source file 
 
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
#include "mc_flying_start.h"
#include "math.h"

/*******************************************************************************
 Constants
*******************************************************************************/

/*
 * RPM to Radians per second conversion factor 
 */
#define RPM_TO_RADIANS_PER_SECOND  (float)( M_PI * NUM_POLE_PAIRS / 30.0f )

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef enum _tmcFly_FlyingStartState_e
{
    flyingStart_Initialize,
    flyingStart_Detect,
    flyingStart_Decide,
    flyingStart_Brake,
    flyingStart_FadeOut,
    flyingStart_Complete
}tmcFly_FlyingStartState_e;

typedef struct 
{
    tmcFly_FlyingStartState_e flyingStartState;
    uint32_t detectCounter;
    uint32_t fadeOutCounter;
    uint32_t fadeOutBurstCounter;
    tStd_ReturnType_e completionStatus;
    
}tmcFly_StateVariables_s;


typedef struct 
{
   uint32_t detectLoopCount;
   float minSpeedForFlyingStart;
   float flyingStartCurrent;
   float brakeCurrent;
   float brakeCurrentStep;
   uint32_t fadeOutLoopCount;
   uint32_t halfFadeOutBurstLoopCount;
   uint32_t fadeOutBurstLoopCount; 
}tmcFly_Parameters_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcFly_InputPorts_s  mcFly_InputPorts_mas[1u];
static tmcFly_Parameters_s  mcFly_Parameters_mas[1u];
static tmcFly_StateVariables_s  mcFly_StateVariables_mas[1u];
static tmcFly_OutputPorts_s mcFly_OutputPorts_mas[1u];
static tmcLib_PiControllerParameter_s mcFly_IdControlParamForFlyingStart_mas[1u] = { FLYING_START_CONTOLLER_PARAMETERS_CONFIG };
static tmcLib_PiControllerParameter_s mcFly_IqControlParamForFlyingStart_mas[1u] = { FLYING_START_CONTOLLER_PARAMETERS_CONFIG };
static tmcLib_PiControllerParameter_s mcFly_IdControlParamForCloseLoop_mas[1u] = { CURRENT_CONTOLLER_PARAMETERS_CONFIG };
static tmcLib_PiControllerParameter_s mcFly_IqControlParamForCloseLoop_mas[1u] = { CURRENT_CONTOLLER_PARAMETERS_CONFIG };

/*******************************************************************************
Interface  variables
*******************************************************************************/
tmcFly_ConfigParameters_s mcFlyI_ConfigParameters_gas[1u] = { FLYING_START_MODULE_CONFIG };

extern int32_t __aeabi_idiv(int32_t numerator, int32_t denominator);

/*******************************************************************************
Private Functions
*******************************************************************************/
#define ASSERT(expression, message) if(!expression) mcFly_AssertFailedReaction( message);

tStd_ReturnType_e mcFly_AssertFailedReaction( const char * message )
{
    /*ToDo: Decide an appropriate error reaction */
     return returnType_Failed;
}

/*******************************************************************************
 * Interface Functions 
*******************************************************************************/

/* !\brief Initialize flying start  
 * 
 * Details.
 * Initialize flying start  
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
tStd_ReturnType_e  mcFlyI_FlyingStartInit(const tmcFly_ConfigParameters_s * const flyConfigParam)
{
     /* Check  if configuration parameters have valid memory location  */
    ASSERT(( NULL != flyConfigParam ), "Configuration parameters points to NULL");
    
    /* Initialize input ports */
    ASSERT( ( ( NULL != flyConfigParam->inPort.observedElecVelocity) && ( NULL != flyConfigParam->inPort.rotationSign) ),
                  "Input ports are not assigned");
    
    mcFly_InputPorts_mas[flyConfigParam->Id] = flyConfigParam->inPort;
    
     /* Initialize output ports */
    ASSERT( ( ( NULL != flyConfigParam->outPort.idRef) && ( NULL != flyConfigParam->outPort.iqRef) ),
                  "Output ports are not assigned");
    
    mcFly_OutputPorts_mas[flyConfigParam->Id] = flyConfigParam->outPort;
          
    /* Update and calculate independent and independent parameters respectively */ 
     
    mcFly_Parameters_mas[0u].detectLoopCount = flyConfigParam->userParam.detectTime * PWM_FREQUENCY;
    mcFly_Parameters_mas[0u].minSpeedForFlyingStart =  RPM_TO_RADIANS_PER_SECOND * flyConfigParam->userParam.minRpmForFlyingStart;
    mcFly_Parameters_mas[0u].flyingStartCurrent = flyConfigParam->userParam.flyingStartCurrentInAmps;
    mcFly_Parameters_mas[0u].brakeCurrent = flyConfigParam->userParam.brakeCurrenInAmps;
    mcFly_Parameters_mas[0u].brakeCurrentStep = flyConfigParam->userParam.brakeCurrentStepInAmps;
    mcFly_Parameters_mas[0u].fadeOutLoopCount = flyConfigParam->userParam.fadeOutTime * PWM_FREQUENCY;
    mcFly_Parameters_mas[0u].fadeOutBurstLoopCount = flyConfigParam->userParam.fadeOutBurstTime * PWM_FREQUENCY;
    mcFly_Parameters_mas[0u].halfFadeOutBurstLoopCount =  mcFly_Parameters_mas[0u].fadeOutBurstLoopCount >> 1u; 
 
    
    /* Set PI controller parameters for flying start */
    
     return returnType_Passed;
}


/* !\brief  Run flying start 
 * 
 * Details.
 * Run flying start
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
#ifdef RAM_EXECUTE
tStd_ReturnType_e  __ramfunc__ mcFlyI_FlyingStartRun(const tmcFly_InstanceId_e Id)
#else
tStd_ReturnType_e mcFlyI_FlyingStartRun( const tmcFly_InstanceId_e Id)
#endif
{
    tStd_ReturnType_e completionStatus = returnType_Running;
    
    /* Flying start state machine  */
    switch( mcFly_StateVariables_mas[0u].flyingStartState )
    { 
        case flyingStart_Initialize:
        {
            /* Initialize current controller parameters for flying start */
            mcRegI_CurrentControllerParameterSet( Id, &mcFly_IdControlParamForFlyingStart_mas[Id]);
            mcRegI_CurrentControllerParameterSet( Id, &mcFly_IqControlParamForFlyingStart_mas[Id]);
            
            /* Update flying start state */
            mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Detect;
        }
        break;
        
        case flyingStart_Detect:
        {          
            if( mcFly_StateVariables_mas[0u].detectCounter > mcFly_Parameters_mas[0u].detectLoopCount )
            {
                mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Decide;
                mcFly_StateVariables_mas[0u].detectCounter = 0u;
            }
            else 
            {
                 mcFly_StateVariables_mas[0u].detectCounter++;
            }
           
            /* Apply NULL current vector */
            *mcFly_OutputPorts_mas[0u].idRef = 0.0f;
            *mcFly_OutputPorts_mas[0u].iqRef = 0.0f;      
            
            /* Update SVPWM angle */
             *mcFly_OutputPorts_mas[0u].observedElecTheta = *mcFly_InputPorts_mas[0u].observedElecTheta;

        }
        break;
        
        case flyingStart_Decide:
        {
            /* Commanded speed and free running speed are same */
            if( 0u < *mcFly_InputPorts_mas[0u].rotationSign  )
            {
                /* Check if the rotor speed is above threshold for switching to close loop */
                if(  *mcFly_InputPorts_mas[0u].observedElecVelocity   > mcFly_Parameters_mas[0u].minSpeedForFlyingStart )
                {
                    mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Complete; 
                    mcFly_StateVariables_mas[0u].completionStatus = returnType_Passed;
                    
                    /* Apply flying start current vector */
                    *mcFly_OutputPorts_mas[0u].idRef = 0;
                    *mcFly_OutputPorts_mas[0u].iqRef = mcFly_Parameters_mas[0u].flyingStartCurrent;                          
                }
                else
                {
                  #ifdef REGENERATIVE_BRAKING  
                    mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Brake;
                 #else 
                    mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_FadeOut;
                 #endif
                    mcFly_StateVariables_mas[0u].completionStatus = returnType_Failed;
                    
                }
                            
                  /* Update SVPWM angle */
                  *mcFly_OutputPorts_mas[0u].observedElecTheta = *mcFly_InputPorts_mas[0u].observedElecTheta;
            }
            else
            {
                /* Check if the rotor speed is above threshold for switching to close loop */
                if(  *mcFly_InputPorts_mas[0u].observedElecVelocity  < -mcFly_Parameters_mas[0u].minSpeedForFlyingStart )
                {
                    mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Complete; 
                    mcFly_StateVariables_mas[0u].completionStatus = returnType_Passed;
                    
                     /* Apply flying start current vector */
                    *mcFly_OutputPorts_mas[0u].idRef = 0;
                    *mcFly_OutputPorts_mas[0u].iqRef = -mcFly_Parameters_mas[0u].flyingStartCurrent;                        
                }
                else
                {
                  #ifdef REGENERATIVE_BRAKING  
                     mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Brake;
                 #else 
                    mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_FadeOut;
                 #endif
                    mcFly_StateVariables_mas[0u].completionStatus = returnType_Failed;                 
                }                
                 /* Update SVPWM angle */
                 *mcFly_OutputPorts_mas[0u].observedElecTheta = *mcFly_InputPorts_mas[0u].observedElecTheta;
            }
        }
        break;

#ifdef REGENERATIVE_BRAKING        
        case flyingStart_Brake:
        {
            if( *mcFly_InputPorts_mas[0u].observedElecVelocity > mcFly_Parameters_mas[0u].minSpeedForFlyingStart )
            {
                if( *mcFly_OutputPorts_mas[0u].iqRef < mcFly_Parameters_mas[0u].brakeCurrent )
                {
                     *mcFly_OutputPorts_mas[0u].iqRef += mcFly_Parameters_mas[0u].brakeCurrentStep;
                }
            }
            else if( *mcFly_InputPorts_mas[0u].observedElecVelocity < -mcFly_Parameters_mas[0u].minSpeedForFlyingStart )
            {
                if( *mcFly_OutputPorts_mas[0u].iqRef > -mcFly_Parameters_mas[0u].brakeCurrent )
                {
                     *mcFly_OutputPorts_mas[0u].iqRef -= mcFly_Parameters_mas[0u].brakeCurrentStep;
                }                
            } 
            else
            {
                mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_FadeOut;
            } 
        }
        break;
#endif 
        
        case flyingStart_FadeOut:
        {
            uint16_t dutyCycle[3u] = { 1200u, 1200u, 1200u};
            
            /* Set 50% duty ratio for the PWM inverter for active short */
            mcHalI_VoltageSourceInverterPwmSet( 0u, dutyCycle );
            
            if( mcFly_StateVariables_mas[0u].fadeOutCounter < mcFly_Parameters_mas[0u].fadeOutLoopCount )
            {
                mcFly_StateVariables_mas[0u].fadeOutCounter++;
                mcFly_StateVariables_mas[0u].fadeOutBurstCounter++;
                if( mcFly_StateVariables_mas[0u].fadeOutBurstCounter < mcFly_Parameters_mas[0u].halfFadeOutBurstLoopCount )
                {
                    mcHalI_VoltageSourceInverterPwmEnable( );
                }
                else if( mcFly_StateVariables_mas[0u].fadeOutBurstCounter < mcFly_Parameters_mas[0u].fadeOutBurstLoopCount )
                {
                    mcHalI_VoltageSourceInverterPwmDisable( );
                }
                else 
                {
                    mcFly_StateVariables_mas[0u].fadeOutBurstCounter = 0u;
                }
                
            }
            else 
            {
                mcHalI_VoltageSourceInverterPwmEnable( );
                mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Complete;
                mcFly_StateVariables_mas[0u].fadeOutCounter  = 0u;
            }
        }
        break;
        
        case flyingStart_Complete:
        {
           /* Initialize current controller parameters for close loop */
           mcRegI_CurrentControllerParameterSet( Id, &mcFly_IdControlParamForCloseLoop_mas[Id]);
           mcRegI_CurrentControllerParameterSet( Id, &mcFly_IqControlParamForCloseLoop_mas[Id]);
            
           mcFly_StateVariables_mas[0u].flyingStartState = flyingStart_Initialize;
           completionStatus = mcFly_StateVariables_mas[0u].completionStatus;
        }
        break;
        
        default:
        {
            /* Should not come here */
        }
        
    }
    
    return completionStatus;
    
}

/* !\brief Reset flying reset   
 * 
 * Details.
 * Reset flying start
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcFlyI_FlyingStartReset(const tmcFly_InstanceId_e Id)
{
    /* Reset state variables */
    mcFly_StateVariables_mas[0u].flyingStartState = 0u;
    mcFly_StateVariables_mas[0u].detectCounter = 0u;
    mcFly_StateVariables_mas[0u].fadeOutCounter = 0u;
    mcFly_StateVariables_mas[0u].fadeOutBurstCounter = 0u;
    
    /* Reset output ports */
   *mcFly_OutputPorts_mas[0u].idRef = 0;
   *mcFly_OutputPorts_mas[0u].iqRef = 0;
    
}

