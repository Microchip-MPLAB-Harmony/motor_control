/*******************************************************************************
 Motor Control Coordination Functions 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_motor_control.c

  Summary:
    Motor Control  functions.

  Description:
    This file implements functions for motor control.
 
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
#include "mc_motor_control.h"

/*******************************************************************************
Private Variables
*******************************************************************************/
static tmcMoc_StateSignal_s  mcMoc_StateSignal_mds;

#ifdef MOTOR_START_STOP_FROM_BUTTON  
static button_response_t button_S2_data;
#if (ENABLE == BIDIRECTION_CONTROL )
static button_response_t button_S3_data;
#endif
#endif

/*******************************************************************************
Interface Variables
*******************************************************************************/
uint8_t  adc_interrupt_counter;

/*******************************************************************************
Private Functions
*******************************************************************************/

/*******************************************************************************
Interface Functions
*******************************************************************************/

/*! \brief Initialize Application
 * 
 * Details.
 * Initialize Application
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */   

void mcMocI_MotorControlInit( void )
{    
    /* Disable inverter during initialization */
    mcHalI_VoltageSourceInverterPwmDisable();
    
    /* Initialize motor start-up */
    mcSupI_OpenLoopStartupInit( &mcSupI_ConfigurationParameters_gds );
    
    /* Initialize Torque control */
    mcRegI_CurrentRegulationInit(&mcRegI_ConfigurationParameters_gds);
    
    /* Initialize Speed Control */
    mcSpeI_SpeedRegulationInit( &mcSpeI_ConfigParameters_gds );
    
    /* Initialize Rotor position calculation module */
    mcRpoI_RotorPositionCalculationInit( &mcRpoI_ConfigParameters_gds);
   
    /* Initialize Flux Control */
    //mcFlxI_FluxControlInit( &mcFlxI_ConfigParameters_gds );
        
    /* Initialize PWM Modulator */
    mcPwmI_PulseWidthModulationInit( &mcPwmI_ConfigParameters_gds );    
}


/*! \brief ADC Finish ISR
 * 
 * Details.
 * ADC Finish ISR
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */   
void mcMocI_MotorControlTasksRun( void )
{
    /* Motor control */
    if (0u != mcMoc_StateSignal_mds.runState)
    {
        /* Clarke Transformation */
        mcLib_ClarkTransform(&mcCurI_PhaseCurrents_gds, &mcMocI_FeedbackAlphaBetaCurrent_gds);
        
        /* Rotor position estimation */
        mcRpoI_RotorPositionCalculationRun( 0u );

        /* Parks Transformation  */
        mcLib_ParkTransform(mcMocI_SpaceVectorPosition_gdu16, &mcMocI_FeedbackAlphaBetaCurrent_gds, &mcMocI_FeedbackDQCurrent_gds);

        /* motor control state machine */
        switch(mcMoc_StateSignal_mds.appState)
        {
            case mcState_Idle:
            {
                /* Do nothing */
            }
            break;

            case mcState_Startup:
            {
                if ( 1u  == mcSupI_OpenLoopStartupRun(0u))
                {
                #if ( CONTROL_LOOP != OPEN_LOOP)
                    mcSpeI_SpeedControlIntegralSet( 0u );
                    mcMoc_StateSignal_mds.appState = mcState_Foc;
                #endif 
                }
            }                 
            break;

            case mcState_Foc:
            {  
                mcMocI_SpaceVectorPosition_gdu16 = mcRpoI_ElectricalRotorPosition_gdu16;
                mcSpeI_SpeedRegulationRun( 0u );
            }
            break;
            default:
            {
               /* empty case: control should not come here */
            }
            break;
       }      
       mcMocI_MotorRunningState_gde = mcMoc_StateSignal_mds.appState;

       /* Torque control */
       mcRegI_CurrentRegulationRun(0u); 

       /* Reverse-Park transformation */
       mcLib_ReverseParkTransform(mcMocI_SpaceVectorPosition_gdu16, &mcMocI_DQVoltage_gds, &mcMocI_AlphaBetaVoltage_gds);

       /* Execute SVPWM Modulation */
       mcPwmI_PulseWidthModulationRun( 0u );       
                  
    }
      
    return;
}

/*! \brief Motor control application reset
 * 
 * Details.
 *  Motor Control application reset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
 void mcMocI_MotorControlReset(void)
{
     /* Set run state to zero */
     mcMoc_StateSignal_mds.runState = 0;
             
     /* Reset open loop start-up module */
     mcSupI_OpenLoopStartupReset( 0u );
    
     /* Initialize rotor position calculation module */
     mcRpoI_RotorPositionCalculationReset(0u);
     
     /* Reset current regulation module */
     mcRegI_CurrentRegulationReset( 0u );
    
     /* Reset speed regulation module */
     mcSpeI_SpeedRegulationReset( 0u );
     
     /* Reset pulse width modulation function */
     mcPwmI_PulseWidthModulationReset( 0u );
       
}

/*! \brief Motor Stop function 
 * 
 * Details.
 * Motor stop function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorStop(void)
{        
    /* Disable inverter */
    mcHalI_VoltageSourceInverterPwmDisable();
     
     /* Reset start up parameters */
     mcMocI_MotorControlReset();

    /* Reset control */
    mcPwmI_PulseWidthModulationReset( 0u );

}

/*! \brief Motor Start function 
 * 
 * Details.
 * Motor start function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorStart(void)
{
    mcHalI_VoltageSourceInverterPwmEnable( );
    mcMoc_StateSignal_mds.runState = 1;
    mcMoc_StateSignal_mds.appState = mcState_Startup;
}

#if ENABLE == BIDIRECTION_CONTROL
/*! \brief Motor direction toggle function 
 * 
 * Details.
 * Motor direction toggle function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorDirectionToggle(void)
{
    if( 0u == mcMoc_StateSignal_mds.runState ) 
    {
        mcMocI_RotationSign_gds8 = -mcMocI_RotationSign_gds8; 
        mcRpoI_RotorPositionCalculationInit( &mcRpoI_ConfigParameters_gds );
        mcHal_DirectionIndicationSet();
    }
}
#endif


/*! \brief Button Polling function 
 * 
 * Details.
 * Button polling function
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcMocI_MotorControlCommandGet( void )
{
#ifdef MOTOR_START_STOP_FROM_BUTTON  
    button_S2_data.inputVal = mcHalI_StartStopButtonGet();
    if( 0u == mcMoc_StateSignal_mds.runState )
    {
         mcLib_ButtonRespond(&button_S2_data, &mcMocI_MotorStart);
    }
    else
    {
        mcLib_ButtonRespond(&button_S2_data, &mcMocI_MotorStop);
    }  
  #if (ENABLE == BIDIRECTION_CONTROL )        
    button_S3_data.inputVal = mcHalI_DirectionButtonGet();
    mcLib_ButtonRespond(&button_S3_data, &mcMocI_MotorDirectionToggle);
  #endif
#endif
}

/* EOF motor_control.c */
