/*******************************************************************************
  PMSM FOC Control Loop Interrupt Handler

  Company:
    Microchip Technology Inc.

  File Name:
    mc_motor_control.c

  Summary:
    This file contains the state machine and control loop of the motor control
   algorithm.

  Description:
    This file contains the control loop of the PMSM FOC.
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
 Header File inclusions  
 *******************************************************************************/
#include "mc_motor_control.h"
#include "mc_hardware_abstraction.h"



/*******************************************************************************
 Constants  
 *******************************************************************************/
#define CONSTANT_Pi                                (float)(3.141593)
#define CONSTANT_2Pi                              (float)(2.0f * CONSTANT_Pi )
#define CONFIG_AngleDecrementRate      (float)(0.0005)
#define CONFIG_TransitionDeltaAngle      (float)(0.0000 + CONFIG_AngleDecrementRate )


/*******************************************************************************
 Private Variables 
 *******************************************************************************/
typedef struct _tmcMoc_StateVariables_s
{
    float openToCloseLoopDelAngle;
}tmcMoc_StateVariables_s;

/*******************************************************************************
 Private Functions 
 *******************************************************************************/
static tmcMoc_StateVariables_s mcMoc_StateVariables_mas[1u];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Motor M1 control application initialization 
 * 
 * Details.
 *  Motor M1 Control application initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1ControlApplicationInit( void )
{   
    tStd_ReturnType_e initStatus;
    
    mcMocI_RotationSign_gas8[0u] = 1;
    mcMocI_MotorRunningState_gae[0u] = mcState_Idle;
    
    /* Initialize voltage calculation module */
    initStatus = mcVolI_VoltageCalculationInit(&mcVolI_ConfigurationParameters_gas[0u]);
    
    /* Initialize current calculation module */
    initStatus |= mcCurI_CurrentCalculationInit( &mcCurI_ConfigurationParameters_gas[0u]);
    
    /* Initialize open loop start-up module */
    initStatus |= mcSupI_OpenLoopStartupInit(&mcSupI_ConfigurationParameters_gas[0u]);
    
    /* Initialize rotor position calculation module */
    initStatus |= mcRpoI_RotorPositionCalculationInit(&mcRpoI_ConfigParameters_gas[0u]);
     
    /* Initialize current regulation module */
    initStatus |= mcRegI_CurrentRegulationInit(&mcRegI_ConfigurationParameters_gas[0u]);
    
    /* Initialize speed regulation module */
    initStatus |= mcSpeI_SpeedRegulationInit(&mcSpeI_ConfigParameters_gas[0u]);
    
    initStatus |= mcPwmI_PulseWidthModulationInit( &mcPwmI_ConfigParameters_gas[0u] );
    
#if ( ENABLE == ENABLE_FLUX_WEAKENING )
    initStatus |= mcFlxI_FluxRegulationInit( &mcFlxI_ConfigParameters_gas[0u] );
#endif
    
#if ( ENABLE == ENABLE_FLYING_START )
     initStatus |= mcFlyI_FlyingStartInit( &mcFlyI_ConfigParameters_gas[0u] );
#endif
    
#if ( POSITION_LOOP == CONTROL_LOOP )
     /* Initialize position  control module */
     initStatus |= mcPosI_PositionRegulationInit(&mcPosI_ConfigParameters_gas[0u]);
#endif
     
     if( ( initStatus & returnType_Failed ) || ( initStatus & returnType_Aborted ))
     {
         /* Log initialization failure flag  */
     }
}

 
 
/*! \brief Motor M2 control application initialization 
 * 
 * Details.
 *  Motor M2 Control application initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M2ControlApplicationInit( void )
{   
     
}

/*! \brief Motor start stop function 
 * 
 * Details.
 * Motor start stop function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1StartStop(void)
{
    if( mcState_Idle == mcMocI_MotorRunningState_gae[0u])
    {
        mcMocI_M1Start();
    }
    else
    {
        mcMocI_M1Stop();
    }
}

/*! \brief Motor start function 
 * 
 * Details.
 * Motor start function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1Start(void)
{
    mcMocI_RunningStatus_gde[0u] = 1u;
#if ( ENABLE == ENABLE_FLYING_START )
    /* Switch the motor control state to flying start */
    mcMocI_MotorRunningState_gae[0u] =  mcState_FlyingStart;
#else 
<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'> 
    if( 0u == mcSupI_RotorFieldAlignmentStatus_gdu8 )
    {
        /* Switch the motor control state to start-up */
        mcMocI_MotorRunningState_gae[0u] = mcState_Startup;
    }
    else 
    {
        /* Switch the motor control state to flying start */
        mcMocI_MotorRunningState_gae[0u] =  mcState_Foc;
    }
<#else>
    /* Switch the motor control state to start-up */
    mcMocI_MotorRunningState_gae[0u] = mcState_Startup;
</#if>
#endif
       
    /* Enable / Re-enable PWM output */
    mcHalI_VoltageSourceInverterPwmEnable();

}

/*! \brief Motor stop function 
 * 
 * Details.
 * Motor stop function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1Stop(void)
{
    mcMocI_RunningStatus_gde[0u] = 0u;

    /* Disable PWM output */
    mcHalI_VoltageSourceInverterPwmDisable();

    /* Switch the motor control state to mcState_Idle */
    mcMocI_MotorRunningState_gae[0u] = mcState_Idle;
    
    /* Motor Controller parameter initialization */
    mcMocI_M1ControlReset( );
}

/*! \brief Motor direction toggle 
 * 
 * Details.
 * Motor direction toggle
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1DirectionToggle(void)
{
    if( mcState_Idle == mcMocI_MotorRunningState_gae[0u])
    {
        /* Change rotation sign */
        mcMocI_RotationSign_gas8[0u] = -mcMocI_RotationSign_gas8[0u];

    <#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
      <#if "Direction indication" == MCPMSMFOC_LED_0_FUNCTION >
        ${MCPMSMFOC_LED_0_NAME}_Toggle();
      <#elseif "Direction indication" == MCPMSMFOC_LED_1_FUNCTION >
        ${MCPMSMFOC_LED_1_NAME}_Toggle();   
      </#if>
    </#if>
    }
}

/*! \brief Motor M1 control application ISR tasks
 * 
 * Details.
 *  Motor M1 Control application ISR tasks  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1ControlTasksRun( void  )
{
    tmcMoc_StateVariables_s * pState;
     
    pState = &mcMoc_StateVariables_mas[0u];

    /* Read phase currents ( Group 01 )*/
    mcHalI_Group01SignalRead( 0u );
    
    /* Re-assign ADC channels and perform trigger  */
    mcHalI_Group02SignalSoftwareTrigger( 0u );
    
    /* Current Measurement */
    mcCurI_CurrentCalculationRun( 0u );

    /* Clarke transform */
    mcLib_ClarkeTransform(&mcCurI_PhaseCurrents_gas[0u], &mcMocI_FeedbackAlphaBetaCurrent_gas[0u]);

    /* Park transform */
    mcLib_ParkTransform(&mcMocI_FeedbackAlphaBetaCurrent_gas[0u], mcMocI_SpaceVectorAngle_gaf32[0u], &mcMocI_FeedbackDQCurrent_gas[0u]);

    /* Rotor position estimation */
    mcRpoI_RotorPositionCalculationRun( 0u );   
    
    switch( mcMocI_MotorRunningState_gae[0u] )
    {
        case mcState_Idle:
        {
        }
        break;
#if ( ENABLE == ENABLE_FLYING_START )
        case mcState_FlyingStart:
        {
           tStd_ReturnType_e completionStatus;
           
           completionStatus = mcFlyI_FlyingStartRun( 0u );
           if( returnType_Failed == completionStatus )
           {
               mcMocI_MotorRunningState_gae[0u] = mcState_Foc;
           }
           else if( returnType_Passed == completionStatus)
           {
               mcMocI_MotorRunningState_gae[0u] = mcState_Foc;
           }
           else
           {
               /* Do nothing */
           }
        }
        break;
#endif
        case mcState_Startup:
        {
           if( 1u ==  mcSupI_OpenLoopStartupRun( 0u ) )
           {              
               /* Calculate difference between close loop and open loop angle */
               pState->openToCloseLoopDelAngle = mcMocI_SpaceVectorAngle_gaf32[0u] - mcRpoI_ElectricalRotorPosition_gaf32[0u];
               if( CONSTANT_Pi <  pState->openToCloseLoopDelAngle )
               {
                    pState->openToCloseLoopDelAngle -= CONSTANT_2Pi;
               }
               else if( -CONSTANT_Pi >  pState->openToCloseLoopDelAngle )
               {
                    pState->openToCloseLoopDelAngle += CONSTANT_2Pi;
               }
               else 
               {
                   /* Do nothing */
               }
                            
                /* Update current controller states */
               mcRegI_IdCurrentControlIntegralSet(0u, mcMocI_DQVoltage_gas[0u].direct );
               mcRegI_IqCurrentControlIntegralSet(0u, mcMocI_DQVoltage_gas[0u].quadrature );
               
               /* Update speed controller parameters */
               mcSpeI_SpeedControlIntegralSet( 0u, mcMocI_FeedbackDQCurrent_gas[0u].quadrature );
               mcSpeI_ReferenceElectricalSpeed_gaf32[0u] = mcRpoI_ElectricalRotorSpeed_gaf32[0u];
               
               /* Change control state */
               mcMocI_MotorRunningState_gae[0u] = mcState_StartupToFoc;
           }
   
        }
        break;
        
        case mcState_StartupToFoc:
        {
            mcMocI_SpaceVectorAngle_gaf32[0u] = mcRpoI_ElectricalRotorPosition_gaf32[0u] + pState->openToCloseLoopDelAngle;
            mcLib_WrapAngleTo2Pi(&mcMocI_SpaceVectorAngle_gaf32[0u] );
            
            if(  pState->openToCloseLoopDelAngle >  CONFIG_TransitionDeltaAngle )
            {
                 pState->openToCloseLoopDelAngle -= CONFIG_AngleDecrementRate;
            }
            else if(  pState->openToCloseLoopDelAngle < -CONFIG_TransitionDeltaAngle )
            {
                 pState->openToCloseLoopDelAngle += CONFIG_AngleDecrementRate;
            }
            else 
            {
               mcMocI_MotorRunningState_gae[0u] = mcState_Foc;
            }
            
            /* Speed regulation  */
            mcSpeI_SpeedRegulationRun( 0u );
        }
        break;
        case mcState_Foc:
        {
            /* Switched to closed by slowly decreasing the offset which is present in the estimated angle during open loop */
            mcMocI_SpaceVectorAngle_gaf32[0u] = mcRpoI_ElectricalRotorPosition_gaf32[0u];

            /* d- axis reference current calculation */
            mcSpeI_ReferenceIdCurrent_gaf32[0u] = 0.0f;
          
          #if ( ENABLE == ENABLE_FLUX_WEAKENING )
            mcFlxI_FluxRegulationRun( 0u );
          #endif
            
          #if ( POSITION_LOOP == CONTROL_LOOP )
            mcPosI_PositionRegulationRun( 0u );
          #endif
            /* Speed regulation  */
            mcSpeI_SpeedRegulationRun( 0u );
        }
        break;
        default:
        {
            /* Undefined state: Should never come here */
        }
    }
    
     /* Direct and Quadrature axis current control */
    mcRegI_CurrentRegulationRun( 0u );

    /* Calculate qValpha, qVbeta from qSin,qCos,qVd,qVq */
    mcLib_InvParkTransform(&mcMocI_DQVoltage_gas[0u], mcMocI_SpaceVectorAngle_gaf32[0u], &mcMocI_AlphaBetaVoltage_gas[0u]);

    /* PWM modulation */
    mcPwmI_PulseWidthModulationRun( 0u );
    
    /* Read voltage and potentiometer signal ( Group 02 ) */
    mcHalI_Group02SignalRead( 0u );
    
    /* Re-assign and enable hardware trigger for Group 01 signal */
    mcHalI_Group01SignalHardwareTrigger( 0u );
      
    /* Voltage measurement */
    mcVolI_VoltageCalculationRun( 0u );
}

/*! \brief Motor M2 control application ISR tasks
 * 
 * Details.
 *  Motor M2 Control application ISR tasks  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M2ControlTasksRun( void  )
{
        
}

/*! \brief Motor M1 control application reset
 * 
 * Details.
 *  Motor M1 Control application reset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M1ControlReset( void )
{
     /* Reset voltage calculation module */
    mcVolI_VoltageCalculationReset( 0u );
        
    /* Reset open loop start-up module */
    mcSupI_OpenLoopStartupReset( 0u );

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM != 'SENSORED_ENCODER'>    
    /* Reset rotor position calculation module */
    mcRpoI_RotorPositionCalculationReset( 0u );
</#if>
     
    /* Reset current regulation module */
    mcRegI_CurrentRegulationReset( 0u );
    
    /* Reset speed regulation module */
    mcSpeI_SpeedRegulationReset( 0u );
    
    /* Reset PWM modulator */
    mcPwmI_PulseWidthModulationReset( 0u );
    
#if ( ENABLE == ENABLE_FLUX_WEAKENING )
    mcFlxI_FluxRegulationReset( 0u );
#endif
            
#if ( ENABLE == ENABLE_FLYING_START )
     mcFlyI_FlyingStartReset( 0u );
#endif
    
#if( POSITION_LOOP == CONTROL_LOOP )
     /* Reset position  control module */
     mcPosI_PositionRegulationReset( 0u );
#endif
    
    /* Reset pulse width modulation function */
    mcPwmI_PulseWidthModulationReset( 0u );
}
 
 
/*! \brief Motor M2 control application reset
 * 
 * Details.
 *  Motor M2 Control application reset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_M2ControlReset( void )
{
       
}


