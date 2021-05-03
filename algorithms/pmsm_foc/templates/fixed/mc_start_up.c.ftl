/*******************************************************************************
 Motor Control Application Source file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_start_up.c

  Summary:
    This file contains all the functions related to open loop start-up 

  Description:
    This file contains implementation of open loop start-up
 
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
#include "math.h"
#include "mc_start_up.h"

/*******************************************************************************
 * Constants 
*******************************************************************************/
#define DEGREE_TO_FIXED_FORMAT       (float)( 65535.0f / 360.0f )
#define RPM_TO_SPEED_INTERNAL_UNITS  (float)( 2.0f * M_PI * NUM_POLE_PAIRS * K_SPEED / 60.0f )

/*******************************************************************************
 Module data type  
*******************************************************************************/
typedef enum
{
    startupState_InitialPosition,
    startupState_OpenLoopRamp,
    startupState_OpenLoopStable     
}tmcSup_StartupState_e;

typedef struct _tmcSup_StateVariables_s
{
    tmcSup_StartupState_e startupStatus;
    uint16_t  openLoopThetaIncrement;
    uint16_t   trackCounter;
 }tmcSup_StateVariables_s;

typedef struct _tmcSup_Parameters_s
{
    /* Alignment parameters */
    int16_t  alignmentCurrent;  
    uint32_t  alignmentTimeLoopCount;
    uint16_t  alignmentCurrentRampVal;
    uint16_t  alignementCurrentRampSh;
    
    /* Open loop start-up parameters */
    int16_t  openLoopCurrent;
    int16_t  openLoopTransitionSpeed;
    uint16_t openLoopSpeedRampRateVal;
    uint16_t  openLoopSpeedRampRateSh;
    uint16_t  openLoopRampTimeLoopCount;
    uint16_t  openLoopStabTimeLoopCount;
}tmcSup_Parameters_s;

/*******************************************************************************
Private variables 
*******************************************************************************/
static tmcSup_Parameters_s mcSup_Parameters_mas[1u];
static tmcSup_StateVariables_s mcSup_StateVariables_mas[1u];
static tmcSup_OutputPorts_s mcSup_OutputPorts_mas[1u];

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcSup_ConfigParameters_s mcSupI_ConfigurationParameters_gds = START_UP_MODULE_CONFIG;

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

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
void  mcSupI_OpenLoopStartupInit( tmcSup_ConfigParameters_s * supParam )
{
    float f32a;
    tmcSup_Parameters_s * pParam;
    
    /* Check if the configuration parameters do not points to NULL */
    ASSERT( ( NULL != supParam ), "Configuration parameters points to NULL");
    
    /*Initialize output ports */
    ASSERT( ( ( NULL != supParam->outPort.Idref ) && ( NULL != supParam->outPort.Iqref )
                && ( NULL != supParam->outPort.theta )) , "Output ports are not assigned properly");
    
     mcSup_OutputPorts_mas[supParam->Id] = supParam->outPort;
     
     /*Update and calculate independent and dependent parameters respectively */     
     pParam = &mcSup_Parameters_mas[supParam->Id];
    
     /* Update start-up parameters */
     f32a = ( supParam->userParam.alignmentCurrent * K_CURRENT )  + 0.5f;
     pParam->alignmentCurrent = (int16_t)( f32a );
     pParam->alignmentTimeLoopCount = supParam->userParam.alignmentTime  / supParam->userParam.Ts;
     
     f32a = (float)pParam->alignmentCurrent / (float)pParam->alignmentTimeLoopCount;
     
     while(( f32a < (float)BASE_VALUE ) && ( (uint16_t)SH_BASE_VALUE > pParam->alignementCurrentRampSh))
     {
         f32a *= 2.0f;
         pParam->alignementCurrentRampSh++; 
     }
     
     pParam->alignmentCurrentRampVal = (int16_t)( f32a + 0.5f );
             
     pParam->openLoopCurrent = supParam->userParam.openLoopCurrent * K_CURRENT;
     pParam->openLoopRampTimeLoopCount = supParam->userParam.openLoopRampTime / supParam->userParam.Ts;
     pParam->openLoopStabTimeLoopCount = supParam->userParam.openLoopStabTime / supParam->userParam.Ts;
     
     f32a   = ( RPM_TO_SPEED_INTERNAL_UNITS * supParam->userParam.openLoopTransSpeed );
     pParam->openLoopTransitionSpeed = (int16_t)f32a;
     f32a /=  pParam->openLoopRampTimeLoopCount;
     
     while(( (float)BASE_VALUE < f32a ) || ( (uint16_t)SH_BASE_VALUE > pParam->openLoopSpeedRampRateSh ) )
     {
         f32a *= 2.0f;
         pParam->openLoopSpeedRampRateSh++;
     }
     pParam->openLoopSpeedRampRateVal = (int16_t)( f32a + 0.5f );
     
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
    uint16_t u16a;
#ifdef BIDIRECTION_CONTROL
    int16_t  s16a;
#endif
    uint32_t u32a;
        
    switch( mcSup_StateVariables_mas[Id].startupStatus )
    {
        /* Lock the rotor at specified rotor angle */
        case startupState_InitialPosition:
        {  
            if( mcSup_Parameters_mas[Id].alignmentTimeLoopCount >= mcSup_StateVariables_mas[Id].trackCounter )
            {
                mcSup_StateVariables_mas[Id].trackCounter++;
                u32a   = (uint32_t)mcSup_Parameters_mas[0u].alignmentCurrentRampVal * (uint32_t)mcSup_StateVariables_mas[Id].trackCounter;
                u32a >>= mcSup_Parameters_mas[0u].openLoopSpeedRampRateSh;
                                
            #ifdef BIDIRECTION_CONTROL
               *mcSup_OutputPorts_mas[Id].Iqref = (int16_t)u32a * (int16_t)mcMocI_RotationSign_gds8;
            #else
               *mcSup_OutputPorts_mas[Id].Iqref = (int32_t)u32a;
            #endif
                
            }
            else 
            {
                  mcSup_StateVariables_mas[Id].trackCounter = 0u;
                                    
                  /* Change open loop state */
                  mcSup_StateVariables_mas[Id].startupStatus = startupState_OpenLoopRamp;
            }
              
            /* Set output ports for alignment */
            *mcSup_OutputPorts_mas[Id].Idref = 0;
            *mcSup_OutputPorts_mas[Id].theta = 0u;
        }
        break;
        
         /* Ramp the speed of the motor  */
        case startupState_OpenLoopRamp:
        {
            if( mcSup_Parameters_mas[Id].openLoopRampTimeLoopCount >= mcSup_StateVariables_mas[Id].trackCounter )
            {               
                mcSup_StateVariables_mas[Id].trackCounter++; 
                u32a   =  (uint32_t)mcSup_Parameters_mas[Id].openLoopSpeedRampRateVal * (uint32_t)mcSup_StateVariables_mas[Id].trackCounter;
                u32a >>= mcSup_Parameters_mas[Id].openLoopSpeedRampRateSh;
                u32a *= (uint32_t)K_SPEED_L;           
                mcSup_StateVariables_mas[Id].openLoopThetaIncrement = u32a >> SH_BASE_VALUE;
            }
            else
            {
                mcSup_StateVariables_mas[Id].trackCounter = 0u;
                mcSup_StateVariables_mas[Id].startupStatus = startupState_OpenLoopStable;
            }
                       
            /* Set output ports for alignment */
            *mcSup_OutputPorts_mas[Id].Idref  = 0;
            *mcSup_OutputPorts_mas[Id].Iqref  = mcSup_Parameters_mas[Id].alignmentCurrent;
          #ifdef BIDIRECTION_CONTROL
           *mcSup_OutputPorts_mas[Id].Iqref *= (int16_t)mcMocI_RotationSign_gds8;
             s16a = ((int16_t)mcSup_StateVariables_mas[Id].openLoopThetaIncrement  * (int16_t)mcMocI_RotationSign_gds8);
             u16a = (uint16_t)s16a;
          #else
             u16a = (uint16_t)mcSup_StateVariables_mas[Id].openLoopThetaIncrement;
          #endif
           *mcSup_OutputPorts_mas[Id].theta += u16a;
            
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
            #if ( CONTROL_LOOP != OPEN_LOOP)
                mcSup_StateVariables_mas[Id].startupStatus = startupState_InitialPosition;
                status = 1u;
            #endif
            }
            
             /* Set output ports for alignment */
             *mcSup_OutputPorts_mas[Id].Idref = 0.0f;
          #ifdef BIDIRECTION_CONTROL
             s16a = ((int16_t)mcSup_StateVariables_mas[Id].openLoopThetaIncrement  * (int16_t)mcMocI_RotationSign_gds8);
             u16a = (uint16_t)s16a;
          #else
               u16a = (uint16_t)mcSup_StateVariables_mas[Id].openLoopThetaIncrement;
         #endif
             *mcSup_OutputPorts_mas[Id].theta += u16a;    
        }
        break;
        
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
    mcSup_StateVariables_mas[Id].openLoopThetaIncrement = 0;
    mcSup_StateVariables_mas[Id].trackCounter = 0u;
    mcSup_StateVariables_mas[Id].startupStatus = startupState_InitialPosition;
    
    /* Reset output ports */
    *mcSup_OutputPorts_mas[Id].Idref = 0;
    *mcSup_OutputPorts_mas[Id].Iqref = 0;
    *mcSup_OutputPorts_mas[Id].theta = 0;
    
}