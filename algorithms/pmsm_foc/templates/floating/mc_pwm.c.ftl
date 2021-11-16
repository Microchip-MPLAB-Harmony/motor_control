/*******************************************************************************
 Generic Motor Control Library 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_generic_library.c

  Summary:
    Generic Motor Control Library implemented in Q14 fixed point arithmetic.

  Description:
    This file implements generic vector motor control related functions
    like  Transformations, PI Control
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
#include "mc_pwm.h"

/*******************************************************************************
 * Constants 
 *******************************************************************************/
#define     SQRT3_BY2                              (float)(0.866025403788)

/*******************************************************************************
 Private variables 
 *******************************************************************************/
typedef struct _tmcPwm_StateVariables_s 
{
    float ualpha_df32;
    float ubeta_df32;
    float ua_df32;
    float ub_df32;
    float uc_df32;
    float t1_f32;
    float t2_f32;
    float ta_f32;
    float tb_f32;
    float tc_f32;
    uint16_t duty[3];
}tmcPwm_StateVariables_s;

/*******************************************************************************
 Private variables 
 *******************************************************************************/
#define ASSERT(expression, message ) { if(!expression) mcPwm_AssertFailedReaction( message );}
static tmcPwm_InputPorts_s mcPwm_InputPorts_mas[PWM_INSTANCES];
static tmcPwm_StateVariables_s mcPwm_StateVariables_mas[PWM_INSTANCES];
static tmcPwm_Parameters_s mcPwm_Parameters_mas[PWM_INSTANCES];

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcPwm_ConfigParameters_s mcPwmI_ConfigParameters_gas[PWM_INSTANCES] = 
{
    PWM_MODULE_A_CONFIG,
#if( 2u == PWM_INSTANCES )
    PWM_MODULE_B_CONFIG
#endif
};

float mcPwmI_PhaseADutyCycle_gdf32;
float mcPwmI_PhaseBDutyCycke_gdf32;
float mcPwmI_PhaseCDutyCycle_gdf32;

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

tStd_ReturnType_e mcPwm_AssertFailedReaction( const char * message )
{
    /*ToDo: Decide an appropriate error reaction */
     return returnType_Failed;
}

static inline void mcPwm_SvpwmTimeCalculation( tmcPwm_StateVariables_s * const pState, const float Ts )
{ 
    float T1, T2;
    T1 = Ts * pState->t1_f32;
    T2 = Ts * pState->t2_f32;
    pState->tc_f32 = ( Ts  - T1 - T2 )/2.0f;
    pState->tb_f32 =   pState->tc_f32 +   T2;
    pState->ta_f32 =   pState->tb_f32 +   T1;
}
/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief PWM Module instance initialization 
 * 
 * Details.
 *  PWM Module instance initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

tStd_ReturnType_e mcPwmI_PulseWidthModulationInit( const tmcPwm_ConfigParameters_s * const pwmConfigParam )
{
    /* Check  if configuration parameters have valid memory location  */
    ASSERT(( NULL != pwmConfigParam ), "Configuration parameters points to NULL");
    
    /* Initialize input ports */
    ASSERT( ( ( NULL != pwmConfigParam->inPort.ualpha_pf32) && ( NULL != pwmConfigParam->inPort.ubeta_pf32) ),
                  "Input ports are not assigned");
    
    mcPwm_InputPorts_mas[pwmConfigParam->Id] = pwmConfigParam->inPort;
          
    /* Update and calculate independent and independent parameters respectively */
    mcPwm_Parameters_mas[pwmConfigParam->Id].frequencyInHz = pwmConfigParam->userParam.frequencyInHz;
    mcPwm_Parameters_mas[pwmConfigParam->Id].period = mcHalI_PwmPeriodGet(  );
    
     return returnType_Passed;   
}


/*! \brief Execute PWM Module instance
 * 
 * Details.
 *  Execute PWM Module instance   
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcPwmI_PulseWidthModulationRun( const tmcPwm_InstanceId_e Id )
{
    /* Read input ports */
    
    /* Inverse Clarke transformation*/
    mcPwm_StateVariables_mas[Id].ua_df32 = *mcPwm_InputPorts_mas[Id].ubeta_pf32;
    mcPwm_StateVariables_mas[Id].ub_df32 = - (( *mcPwm_InputPorts_mas[Id].ubeta_pf32 ) /2 )
                                                                        +  (SQRT3_BY2 *  ( *mcPwm_InputPorts_mas[Id].ualpha_pf32 ));
    mcPwm_StateVariables_mas[Id].uc_df32 = - (( *mcPwm_InputPorts_mas[Id].ubeta_pf32 )/2 )
                                                                       -   ( SQRT3_BY2 *  ( *mcPwm_InputPorts_mas[Id].ualpha_pf32));

    /* Space vector modulation */
    if( mcPwm_StateVariables_mas[Id].ua_df32 >= 0 )
    {
        // (xx1)
        if( mcPwm_StateVariables_mas[Id].ub_df32 >= 0 )
        {
            // (x11)
            // Must be Sector 3 since Sector 7 not allowed
            // Sector 3: (0,1,1)  0-60 degrees
            mcPwm_StateVariables_mas[Id].t1_f32 = mcPwm_StateVariables_mas[Id].ub_df32;
            mcPwm_StateVariables_mas[Id].t2_f32 = mcPwm_StateVariables_mas[Id].ua_df32;
            mcPwm_SvpwmTimeCalculation( &mcPwm_StateVariables_mas[Id ], mcPwm_Parameters_mas[Id].period );
            mcPwm_StateVariables_mas[Id].duty[0] = (uint32_t) mcPwm_StateVariables_mas[Id].ta_f32;
            mcPwm_StateVariables_mas[Id].duty[1]  = (uint32_t) mcPwm_StateVariables_mas[Id].tb_f32;
            mcPwm_StateVariables_mas[Id].duty[2]  = (uint32_t) mcPwm_StateVariables_mas[Id].tc_f32;
        }
        else
        {
            // (x01)
            if(  mcPwm_StateVariables_mas[Id].uc_df32 >= 0 )
            {
               // Sector 5: (1,0,1)  120-180 degrees              
               mcPwm_StateVariables_mas[Id].t1_f32 = mcPwm_StateVariables_mas[Id].ua_df32;
               mcPwm_StateVariables_mas[Id].t2_f32 = mcPwm_StateVariables_mas[Id].uc_df32;
               mcPwm_SvpwmTimeCalculation( &mcPwm_StateVariables_mas[Id ], mcPwm_Parameters_mas[Id].period );
               mcPwm_StateVariables_mas[Id].duty[0] = (uint32_t) mcPwm_StateVariables_mas[Id].tc_f32;
               mcPwm_StateVariables_mas[Id].duty[1]  = (uint32_t) mcPwm_StateVariables_mas[Id].ta_f32;
               mcPwm_StateVariables_mas[Id].duty[2]  = (uint32_t) mcPwm_StateVariables_mas[Id].tb_f32;
            }
            else
            {
               // Sector 1: (0,0,1)  60-120 degrees              
               mcPwm_StateVariables_mas[Id].t1_f32 = -mcPwm_StateVariables_mas[Id].ub_df32;
               mcPwm_StateVariables_mas[Id].t2_f32 = -mcPwm_StateVariables_mas[Id].uc_df32;
               mcPwm_SvpwmTimeCalculation( &mcPwm_StateVariables_mas[Id ], mcPwm_Parameters_mas[Id].period );
               mcPwm_StateVariables_mas[Id].duty[0] = (uint32_t) mcPwm_StateVariables_mas[Id].tb_f32;
               mcPwm_StateVariables_mas[Id].duty[1]  = (uint32_t) mcPwm_StateVariables_mas[Id].ta_f32;
               mcPwm_StateVariables_mas[Id].duty[2]  = (uint32_t) mcPwm_StateVariables_mas[Id].tc_f32;
            }
           }
      }
      else
      {
            // (xx0)
            if(  mcPwm_StateVariables_mas[Id].ub_df32 >= 0 )
            {
                  // (x10)
                  if(  mcPwm_StateVariables_mas[Id].uc_df32 >= 0 )
                  {
                        // Sector 6: (1,1,0)  240-300 degrees
                        mcPwm_StateVariables_mas[Id].t1_f32 = mcPwm_StateVariables_mas[Id].uc_df32;
                        mcPwm_StateVariables_mas[Id].t2_f32 = mcPwm_StateVariables_mas[Id].ub_df32;
                        mcPwm_SvpwmTimeCalculation( &mcPwm_StateVariables_mas[Id ], mcPwm_Parameters_mas[Id].period );
                        mcPwm_StateVariables_mas[Id].duty[0] = (uint32_t) mcPwm_StateVariables_mas[Id].tb_f32;
                        mcPwm_StateVariables_mas[Id].duty[1]  = (uint32_t) mcPwm_StateVariables_mas[Id].tc_f32;
                        mcPwm_StateVariables_mas[Id].duty[2]  = (uint32_t) mcPwm_StateVariables_mas[Id].ta_f32 ;
                  }
                  else
                  {
                        // Sector 2: (0,1,0)  300-0 degrees
                        mcPwm_StateVariables_mas[Id].t1_f32 = -mcPwm_StateVariables_mas[Id].uc_df32;
                        mcPwm_StateVariables_mas[Id].t2_f32 = -mcPwm_StateVariables_mas[Id].ua_df32;
                        mcPwm_SvpwmTimeCalculation( &mcPwm_StateVariables_mas[Id ], mcPwm_Parameters_mas[Id].period );
                        mcPwm_StateVariables_mas[Id].duty[0] = (uint32_t) mcPwm_StateVariables_mas[Id].ta_f32;
                        mcPwm_StateVariables_mas[Id].duty[1]  = (uint32_t) mcPwm_StateVariables_mas[Id].tc_f32;
                        mcPwm_StateVariables_mas[Id].duty[2]  = (uint32_t) mcPwm_StateVariables_mas[Id].tb_f32;
                  }
            }
            else
            {
                  // (x00)
                  // Must be Sector 4 since Sector 0 not allowed
                  // Sector 4: (1,0,0)  180-240 degrees
                  mcPwm_StateVariables_mas[Id].t1_f32 = -mcPwm_StateVariables_mas[Id].ua_df32;
                  mcPwm_StateVariables_mas[Id].t2_f32 = -mcPwm_StateVariables_mas[Id].ub_df32;
                  mcPwm_SvpwmTimeCalculation( &mcPwm_StateVariables_mas[Id ], mcPwm_Parameters_mas[Id].period );
                  mcPwm_StateVariables_mas[Id].duty[0] = (uint32_t) mcPwm_StateVariables_mas[Id].tc_f32;
                  mcPwm_StateVariables_mas[Id].duty[1]  = (uint32_t) mcPwm_StateVariables_mas[Id].tb_f32;
                  mcPwm_StateVariables_mas[Id].duty[2]  = (uint32_t) mcPwm_StateVariables_mas[Id].ta_f32;
            }
      }
    
    <#if __PROCESSOR?matches(".*PIC32MK.*") != true>
     /* Update PWM timers */
     mcPwm_StateVariables_mas[Id].duty[0] = mcPwm_Parameters_mas[Id].period -  mcPwm_StateVariables_mas[Id].duty[0];
     mcPwm_StateVariables_mas[Id].duty[1] = mcPwm_Parameters_mas[Id].period -  mcPwm_StateVariables_mas[Id].duty[1];
     mcPwm_StateVariables_mas[Id].duty[2] = mcPwm_Parameters_mas[Id].period -  mcPwm_StateVariables_mas[Id].duty[2];
    </#if>

     mcHalI_VoltageSourceInverterPwmSet( Id, &mcPwm_StateVariables_mas[Id].duty[0] );
    
    /* Write output ports */
    
   
}


/*! \brief  PWM Module instance reset 
 * 
 * Details.
 *  PWM Module instance  reset
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcPwmI_PulseWidthModulationReset( const tmcPwm_InstanceId_e Id   )
{
   /* Reset state variables */
    mcPwm_StateVariables_mas[Id].ualpha_df32 = 0.0f;
    mcPwm_StateVariables_mas[Id].ubeta_df32 = 0.0f;
    mcPwm_StateVariables_mas[Id].ua_df32 = 0.0f;
    mcPwm_StateVariables_mas[Id].ub_df32 = 0.0f;
    mcPwm_StateVariables_mas[Id].uc_df32  = 0.0f;
    mcPwm_StateVariables_mas[Id].duty[0] = 0u;
    mcPwm_StateVariables_mas[Id].duty[1] = 0u;
    mcPwm_StateVariables_mas[Id].duty[2] = 0u;
    
    /* Reset output ports */

}
