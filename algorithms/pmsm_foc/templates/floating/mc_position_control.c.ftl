/*******************************************************************************
  Speed control Source File

  Company:
    Microchip Technology Inc.

  File Name:
  mc_position_control.c

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
#include "mc_position_control.h"
#include "math.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
#define CONSTANT_Pi                                        (float)( 3.14159265358979323846 )
#define CONSTANT_2Pi                                      (float)( 2.0f * CONSTANT_Pi )

/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcPos_Parameters_s
{
    float adcCountToPosition;
    float maximumPosition;
    float halfMaximumPosition;
}tmcPos_Parameters_s;

typedef struct _tmcPos_StateVariables_s
{
    float referenceSpeed;
}tmcPos_StateVariables_s;


/*******************************************************************************
 Constants 
 *******************************************************************************/

/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcPos_InputPorts_s mcPos_InputPorts_mas[POSITION_CONTROL_INSTANCES];
static tmcPos_OutputPorts_s mcPos_OutputPorts_mas[POSITION_CONTROL_INSTANCES];
static tmcPos_Parameters_s mcPos_Parameters_mas[POSITION_CONTROL_INSTANCES];
static tmcPos_PiController_s mcPos_PositionController_mas[POSITION_CONTROL_INSTANCES];

/*******************************************************************************
 Interface variables  
 *******************************************************************************/
tmcPos_ConfigParameters_s  mcPosI_ConfigParameters_gas[POSITION_CONTROL_INSTANCES] = 
{
   POSITION_CONTROL_MODULE_A_CONFIG,
#if( 2u == POSITION_CONTROL_INSTANCES )
   POSITION_CONTROL_MODULE_B_CONFIG
#endif
};

static float mcPosI_ReferencePosition_gaf32[2u];


/*******************************************************************************
 Private Functions 
 *******************************************************************************/
tStd_ReturnType_e mcPos_AssertionFailedReaction( const char * message )
{
    /* ToDo: Decide an appropriate assertion failed reaction function */
     return returnType_Failed;
}

void mcPos_EulerFilter( float input, float * filterOut, float filterParam )
{
    *filterOut = (*filterOut ) + filterParam * ( input - (*filterOut ) );
}

void mcPos_MinimumLimitSet( float * value, float minLimit )
{
    if( *value < minLimit ) 
    {
        *value = minLimit;
    }
}

static float mcLib_WrapFromMinusPiToPi( float * input )
{
    if( *input > CONSTANT_Pi )
    {
        *input -= CONSTANT_2Pi;
    }
    else if( *input < -CONSTANT_Pi )
    {
         *input += CONSTANT_2Pi;
    }
    else
    {
        /* Do nothing */
    }
     
    return ( *input);
}


void mcPos_PiControllerRun( tmcPos_PiController_s * piController )
{
    float err;
    float out;
    float exc;
        
    /* Wrap angular error */
    err  = piController->reference - piController->feedback; 
    err = mcLib_WrapFromMinusPiToPi( &err );
        
    /* PI controller  */
    out  = piController->Yi + piController->Kp * err;

    /* Limit checking for PI output */
    if( out > piController->Ymax )
    {
       piController->Yout = piController->Ymax;
    }
    else if( out < piController->Ymin )
    {
       piController->Yout = piController->Ymin;
    }
    else
    {
       piController->Yout = out;
    }

    exc = out - piController->Yout;
    piController->Yi = piController->Yi + piController->Ki * err - piController->Kc * exc;
}


static void mcPos_PiControllerReset( tmcPos_PiController_s * piController )
{
    piController->Yi = 0.0f;
    piController->reference = 0.0f;
    piController->feedback = 0.0f;
}

#define ASSERT( expression, message ) {if(!expression)mcPos_AssertionFailedReaction(message);}

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
tStd_ReturnType_e  mcPosI_PositionRegulationInit( const tmcPos_ConfigParameters_s * const posParam )
{
    float maxAngle;
    
    /* Check  if configuration parameters have valid memory location  */
    ASSERT(( NULL != posParam ), "Configuration parameters points to NULL");
    
    /* Initialize input ports */
    ASSERT( ( ( NULL != posParam->inPort.potReading ) && ( NULL != posParam->inPort.actualPosition ) ),
                  "Input ports are not assigned");
    
    mcPos_InputPorts_mas[posParam->Id] = posParam->inPort;
        
    /* Initialize output ports */
    ASSERT( ( NULL != posParam->outPort.commandSpeed ), "Output ports are not assigned");
    mcPos_OutputPorts_mas[posParam->Id] = posParam->outPort;
          
    /* Update and calculate independent and independent parameters respectively */
    maxAngle =  M_PI * posParam->userParam.maximumReferenceAngle / 180.0f; 
    mcPos_Parameters_mas[posParam->Id].adcCountToPosition = maxAngle / 4096.0f;
    mcPos_Parameters_mas[posParam->Id].maximumPosition = maxAngle;
    mcPos_Parameters_mas[posParam->Id].halfMaximumPosition = 0.5f * maxAngle;
    
    /* Update PI controller parameters */
    mcPos_PositionController_mas[posParam->Id]  = posParam->userParam.positionController;
    
#if (( CONTROL_LOOP == POSITION_LOOP ) && ( ENABLE != POTENTIOMETER_INPUT_ENABLED ) ) 
    mcRmpI_ReferenceProfileInit( &mcRmpI_RampProfilerConfig_mds);
 #endif

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

float mcPosI_PositionSet( tmcPos_RampProfiler_s * profile )
{
    return 0;
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
void mcPosI_PositionRegulationRun( const tmcPos_InstanceId_e Id )
{  
#if ( ENABLE == POTENTIOMETER_INPUT_ENABLED )
    /* Read input command position */
    mcPosI_ReferencePosition_gaf32[Id] = *mcPos_InputPorts_mas[Id].potReading * mcPos_Parameters_mas[Id].adcCountToPosition;
#else 
    /* Get input from ramp profiler */
   mcPosI_ReferencePosition_gaf32[Id]  = mcRmpI_ReferenceProfileGenerate();
#endif 
    /* Execute PI controller for position control */
    mcPos_PositionController_mas[Id].reference = mcLib_WrapFromMinusPiToPi( &mcPosI_ReferencePosition_gaf32[Id] );
    mcPos_PositionController_mas[Id].feedback = mcLib_WrapFromMinusPiToPi( mcPos_InputPorts_mas[Id].actualPosition );    
    mcPos_PiControllerRun(&mcPos_PositionController_mas[Id] );
   
    /* Update controller output */
    *mcPos_OutputPorts_mas[Id].commandSpeed = mcPos_PositionController_mas[Id].Yout;   
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
void mcPosI_PositionControlOutputSet( uint8_t Id, float value )
{
    
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
void mcPosI_PositionControlIntegralSet( uint8_t Id, float value )
{
   
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
void mcPosI_PositionRegulationReset( const tmcPos_InstanceId_e Id )
{
     mcPos_PiControllerReset( &mcPos_PositionController_mas[Id]);
     
#if ( DISABLE == POTENTIOMETER_INPUT_ENABLED )
    /* Reset ramp profiler */
     mcRmpI_ReferenceProfileReset();
#endif 
}
