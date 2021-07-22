/*******************************************************************************
 Motor Control Application Source file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_speed_control.c

  Summary:
    This file contains all the functions related to speed control

  Description:
    This file contains implementation of speed control functions
 
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
#include "mc_speed_control.h"


/*******************************************************************************
 Constants 
 *******************************************************************************/
#define RPM_TO_RAD_PER_SEC  (float)( 2.0f * NUM_POLE_PAIRS * M_PI / 60.0f )
#define RPM_TO_INTERNAL_UNITS (float)( K_SPEED * RPM_TO_RAD_PER_SEC )
#define POT_TO_RAD_PER_SEC (float)( RATED_SPEED / 4096.0f )
#define POT_TO_SPEED_INTERNAL_UNITS (float)( K_SPEED * POT_TO_RAD_PER_SEC )
#define RPM_TO_RAMP_RATE_LIMIT ( float )( RPM_TO_INTERNAL_UNITS * CURRENT_CONTROL_SAMPLING_TIME )
/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcSpe_Parameters_s
{
    int16_t adcCountToSpeedVal;
    uint16_t adcCountToSpeedSh;
    int16_t refSpeedRampLimit;
    int16_t minReferenceSpeed;
    int16_t maxReferenceSpeed;
#if( CONTROL_LOOP == TORQUE_LOOP )
    int16_t maxTorqueCurrent;
    int16_t adcCountToCurrentVal;
    int16_t adcCountToCurrentSh;
#endif
}tmcSpe_Parameters_s;

typedef struct _tmcSpe_StateVariables_s
{
    int16_t absReferenceSpeed;
    int32_t scaledReferenceSpeed;
}tmcSpe_StateVariables_s;


/*******************************************************************************
 * Module variables 
*******************************************************************************/
static tmcSpe_InputPorts_s mcSpe_InputPorts_mas[1u];
static tmcSpe_OutputPorts_s mcSpe_OutputPorts_mas[1u];
static tmcSpe_Parameters_s mcSpe_Parameters_mas[1u];
#if (( CONTROL_LOOP == SPEED_LOOP ) && (  ENABLE == POTENTIOMETER_INPUT_ENABLED))
static tmcSpe_StateVariables_s mcSpe_StateVariables_mas[1u];
#endif
static tmcLib_PiController_s mcSpe_SpeedController_mas[1u];

/*******************************************************************************
 * Global variables 
*******************************************************************************/
tmcSpe_ConfigParameters_s  mcSpeI_ConfigParameters_gds = SPEED_CONTROL_MODULE_CONFIG;

tmcSpe_RampProfiler_s mcSpeI_ReferenceSpeedProfile_gas[1u] = 
{
    {
        0.0f,
        0.0f,
        1.0f    
    }
};

/*******************************************************************************
 * Local Functions  
*******************************************************************************/
void mcSpe_SpeedRampLimiter( int16_t input, tmcSpe_StateVariables_s * state, int16_t rampRate  )
{
    int32_t scaledInput;
    int32_t scaledReference;
  
    scaledInput = (int32_t)( input * BASE_VALUE );
    scaledReference = state->scaledReferenceSpeed;
    
    if( ( scaledReference + rampRate ) < scaledInput )
    {
        scaledReference += rampRate;
    }
    else if( ( scaledReference - rampRate ) > scaledInput )
    {
        scaledReference -= rampRate;
    }
    else 
    {
        scaledReference = scaledInput;
    }
    
    /* Set the reference value */
    state->scaledReferenceSpeed = scaledReference; 
    state->absReferenceSpeed = scaledReference >> SH_BASE_VALUE;
}


/*******************************************************************************
Interface Functions
*******************************************************************************/

/*! \brief Initialize PMSM speed control 
 * 
 * Details.
 * Initialize PMSM speed control 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */ 
void mcSpeI_SpeedRegulationInit( const tmcSpe_ConfigParameters_s * const speParam )
{   
    float f32a;
    tStd_ReturnType_e status;
    tmcSpe_Parameters_s * pParam;

#if( DISABLE == POTENTIOMETER_INPUT_ENABLED )
  #if( CONTROL_LOOP == SPEED_LOOP )
     tmcRmp_ReferenceSpeed_s  rampProfile = { 
                                             (tmcRmp_ReferenceProfile_e)RAMP_PROFILE, 
                                              ${MCPMSMFOC_RAMP_VELOCITY}, 
                                              0, 
                                              MINIMUM_SPEED_IN_RPM, 
                                              ${MCPMSMFOC_END_SPEED},
                                              ${MCPMSMFOC_RAMP_TIME}, 
                                              RPM_TO_INTERNAL_UNITS 
                                            };
  #elif( CONTROL_LOOP == TORQUE_LOOP )
     tmcRmp_ReferenceSpeed_s  rampProfile = { 
                                              (tmcRmp_ReferenceProfile_e)RAMP_PROFILE, 
                                              ${MCPMSMFOC_RAMP_VELOCITY}, 
                                              0, 
                                              TORQUE_MODE_MAXIMUM_CURRENT,
                                              TORQUE_MODE_MAXIMUM_CURRENT, 
                                              ${MCPMSMFOC_RAMP_TIME}, 
                                              K_CURRENT 
                                            };
  #endif
#endif
    
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
    
    /* Update and calculate independent and dependent parameters respectively */
    pParam = &mcSpe_Parameters_mas[speParam->Id];
    f32a = ( RPM_TO_INTERNAL_UNITS *  speParam->userParam.minReferenceSpeed ) + 0.5f;
    pParam->minReferenceSpeed  = (int16_t)( f32a );
    
    f32a =  ( RPM_TO_INTERNAL_UNITS *  speParam->userParam.maxReferenceSpeed ) + 0.5f;
    pParam->maxReferenceSpeed = (int16_t)( f32a );
    
    f32a = pParam->maxReferenceSpeed / 4096.0f;
    pParam->adcCountToSpeedSh = 0u;
    while( ( 10u >= pParam->adcCountToSpeedSh ) && ( 16384.0f > f32a ))
    {
        f32a *= 2.0f;
        pParam->adcCountToSpeedSh++;
    }
    pParam->adcCountToSpeedVal = f32a;
    
    /* Ramp rate limit calculation */
    f32a = speParam->userParam.rpmPerSecondLimit;
    f32a *= RPM_TO_RAMP_RATE_LIMIT; 
    f32a *= BASE_VALUE;
     
    pParam->refSpeedRampLimit = (int32_t)( f32a + 0.5f );
    
#if(( CONTROL_LOOP == TORQUE_LOOP ) && ( ENABLE == POTENTIOMETER_INPUT_ENABLED ))
    f32a = K_CURRENT * speParam->userParam.maxTorqueCurrent + 0.5f;
    f32a /= 4096;
    while( ( 10u >= pParam->adcCountToCurrentSh ) && ( 16384.0f > f32a ))
    {
        f32a *= 2.0f;
        pParam->adcCountToCurrentSh++;
    }
    pParam->adcCountToCurrentVal = f32a;
#elif ((CONTROL_LOOP == TORQUE_LOOP ) && ( DISABLE == POTENTIOMETER_INPUT_ENABLED ))
    rampProfile.finalValue = speParam->userParam.maxTorqueCurrent;
    rampProfile.initialValue = 0.0f;
    rampProfile.rampTimeInSec = 1.0f;
    mcRmpI_ReferenceProfileInit( &rampProfile);
#elif (( CONTROL_LOOP == SPEED_LOOP ) && ( DISABLE == POTENTIOMETER_INPUT_ENABLED ))
    mcRmpI_ReferenceProfileInit( &rampProfile);
#endif

       
    
    /* Initialize Speed PI Controller */
    status = mcLib_PiControllerParametersSet(  speParam->userParam.speedController.Kp, 
                                                           speParam->userParam.speedController.Ki,
                                                           speParam->userParam.speedController.Ymax,
                                                          &mcSpe_SpeedController_mas[0u] );    
    
    ASSERT(( returnType_Failed != status ), "PI Controller parameter setting failed")

}



/*! \brief Speed PI controller integral setting 
 * 
 * Details.
 * Speed PI controller integral setting 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */ 
void mcSpeI_SpeedControlIntegralSet( uint8_t Id )
{
    int32_t s32a;
    
    s32a =  mcSpeI_ReferenceIqCurrent_gds16 << SH_BASE_VALUE;
 #ifdef BIDIRECTION_CONTROL
    s32a *= (int32_t)( *mcSpe_InputPorts_mas[Id].rotationSign );
#endif 
    mcLib_PiControllerIntegralSet(s32a, &mcSpe_SpeedController_mas[Id] );
}

/*! \brief Execute PMSM speed control 
 * 
 * Details.
 * Set PMSM torque
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcSpeI_SpeedRegulationRun( const tmcSpe_InstanceId_e Id )
#else
void mcSpeI_SpeedRegulationRun( const tmcSpe_InstanceId_e Id )
#endif
{       
#if ( CONTROL_LOOP == TORQUE_LOOP ) 
  #if ( ENABLE == POTENTIOMETER_INPUT_ENABLED )
     int32_t s32a;
     s32a   =  *mcSpe_InputPorts_mas[Id].potReading;
     s32a *=    mcSpe_Parameters_mas[Id].adcCountToCurrentVal;
     s32a >>=   mcSpe_Parameters_mas[Id].adcCountToCurrentSh;
     s32a *= (int32_t)( *mcSpe_InputPorts_mas[Id].rotationSign );
   *mcSpe_OutputPorts_mas[Id].iqref =  s32a;
  #else 
    *mcSpe_OutputPorts_mas[Id].iqref =  mcRmpI_ReferenceProfileGenerate();
    *mcSpe_OutputPorts_mas[Id].iqref *=  (int16_t)( *mcSpe_InputPorts_mas[Id].rotationSign );
  #endif                                                        
#elif(  CONTROL_LOOP == SPEED_LOOP )
  #if ( ENABLE == POTENTIOMETER_INPUT_ENABLED )
     int32_t s32a;
     s32a   =  *mcSpe_InputPorts_mas[Id].potReading;
     s32a *=    mcSpe_Parameters_mas[Id].adcCountToSpeedVal;
     s32a >>=   mcSpe_Parameters_mas[Id].adcCountToSpeedSh;
           
     mcSpe_SpeedRampLimiter( (int16_t)s32a, &mcSpe_StateVariables_mas[Id], mcSpe_Parameters_mas[Id].refSpeedRampLimit );
        
     if( mcSpe_Parameters_mas[Id].minReferenceSpeed > mcSpe_StateVariables_mas[Id].absReferenceSpeed )
     {
         mcSpe_StateVariables_mas[Id].absReferenceSpeed = mcSpe_Parameters_mas[Id].minReferenceSpeed;
     }
     else if( mcSpe_Parameters_mas[Id].maxReferenceSpeed < mcSpe_StateVariables_mas[Id].absReferenceSpeed )
     {
         mcSpe_StateVariables_mas[Id].absReferenceSpeed = mcSpe_Parameters_mas[Id].maxReferenceSpeed;
     }
     else
     {
         /* Do nothing */
     }
     
    #ifdef BIDIRECTION_CONTROL

      mcSpe_SpeedController_mas[Id].reference =  mcSpe_StateVariables_mas[Id].absReferenceSpeed
                                                                          * (int16_t)( *mcSpe_InputPorts_mas[Id].rotationSign );
    #endif
      
      /* Determine q-axis reference current */
      mcSpe_SpeedController_mas[Id].feedback = (int32_t)(*mcSpe_InputPorts_mas[Id].actualSpeed );
    *mcSpe_OutputPorts_mas[Id].iqref = mcLib_PiControllerRun( &mcSpe_SpeedController_mas[Id] );
  #else 
      mcSpe_SpeedController_mas[Id].reference  = mcRmpI_ReferenceProfileGenerate();
      mcSpe_SpeedController_mas[Id].reference  *= (*mcSpe_InputPorts_mas[Id].rotationSign);

      /* Determine q-axis reference current */
      mcSpe_SpeedController_mas[Id].feedback = (int32_t)(*mcSpe_InputPorts_mas[Id].actualSpeed );
     *mcSpe_OutputPorts_mas[Id].iqref = mcLib_PiControllerRun( &mcSpe_SpeedController_mas[Id] );
  #endif
#endif
               
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
    mcSpe_StateVariables_mas[Id].absReferenceSpeed = 0;
    mcSpe_StateVariables_mas[Id].scaledReferenceSpeed = 0;
           
    /* Reset output ports */
    *mcSpe_OutputPorts_mas[Id].iqref = 0.0f;
    *mcSpe_OutputPorts_mas[Id].referenceSpeed = 0.0f;
    
}
