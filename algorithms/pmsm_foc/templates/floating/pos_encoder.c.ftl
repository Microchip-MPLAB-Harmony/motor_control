/*******************************************************************************

  Rotor Position Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotor_position.c

  Summary:
    This file contains functions to get the rotor position of a motor

  Description:
    This file contains functions to get the rotor position of a motor
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
#include "mc_rotor_position.h"

<#if __PROCESSOR?matches(".*PIC32MK.*") == true>

/*******************************************************************************
 Constants
 *******************************************************************************/
#define CONSTANT_Pi                                        (float)3.14159265358979323846
#define CONSTANT_QdecPulsesPerElecRev         (uint16_t)( ( CONFIG_EncoderPulsesPerMechRev * 4 ) /CONFIG_RpoNumberOfPolePairs)
#define CONSTANT_QdecPulsesToMechAngle     (float)(2.0f*CONSTANT_Pi/CONFIG_EncoderPulsesPerMechRev )
#define CONSTANT_QdecPulsesToElecAngle       (float)(2.0f*CONSTANT_Pi/CONSTANT_QdecPulsesPerElecRev )
#define CONSTANT_QdecVelocitySampleFreq     (float)((float)PWM_FREQUENCY / (float)CONFIG_VelcoityCalculationPrescale)
#define CONSTANT_QdecPulsesToElecSpeed      (float)(((float) 2.0f * CONSTANT_Pi * CONSTANT_QdecVelocitySampleFreq  )/((float)CONSTANT_QdecPulsesPerElecRev ))

/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcRpo_Parameters_s
{
    uint16_t encoderPulsesPerElecRev;
    uint16_t velocityCountPrescaler;
    float encCountToElecVelocity;
    float encCountToElecAngle;    
    float encCountToMechAngle;  
}tmcRpo_Parameters_s;

typedef struct _tmcRpo_StateVariables_s
{
    int32_t synCounter;
    int32_t elecAngleCount;
    int32_t mechAngleCount;
    int32_t elecVelocityCount;
}tmcRpo_StateVariables_s;

/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcRpo_OutputPorts_s mcRpo_OutputPorts_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_StateVariables_s mcRpo_StateVariables_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_Parameters_s mcRpo_Parameters_mas[ROTOR_POSITION_INSTANCES];

/*******************************************************************************
 Interface variables  
 *******************************************************************************/
tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES] = 
{
   ROTOR_POSITION_MODULE_A_CONFIG,
#if( 2u == ROTOR_POSITION_INSTANCES )
   ROTOR_POSITION_MODULE_B_CONFIG
#endif
};

/*******************************************************************************
 Private Functions 
 *******************************************************************************/
static tStd_ReturnType_e mcRpo_AssertionFailedReaction( const char * message )
{
    /* ToDo: Decide appropriate reaction function */
     return returnType_Failed;
}

static inline void mcRpo_EulerFilter( float new, float * old, float filterParam )
{
    *old += ( new - ( *old ) ) * filterParam;
 }

#define ASSERT( expression, message ) { if(!expression)mcRpo_AssertionFailedReaction(message);}

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Rotor position calculation initialization function 
 * 
 * Details.
 *  Rotor position calculation initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( const tmcRpo_ConfigParameters_s * const encParam )
{
     tmcRpo_Parameters_s * pParam;
    
    /* Check if the configuration parameters data has valid address */
    ASSERT(( NULL != encParam ), "Configuration parameters points to NULL address ");
    
    /* Initialize output ports */
    ASSERT((      ( NULL != encParam->outPort.elecAngle ) && ( NULL != encParam->outPort.mechAngle) 
                    && ( NULL != encParam->outPort.elecVelocity )  &&  ( NULL != encParam->outPort.accel ) ), 
                          "Output ports are not assigned properly" );
        
    mcRpo_OutputPorts_mas[encParam->Id] = encParam->outPort;
    
    /* Update and calculate independent and dependent parameters respectively */
    pParam = &mcRpo_Parameters_mas[encParam->Id];
    pParam->encoderPulsesPerElecRev = CONSTANT_QdecPulsesPerElecRev;
    pParam->velocityCountPrescaler =  CONFIG_VelcoityCalculationPrescale;
    pParam->encCountToElecVelocity = CONSTANT_QdecPulsesToElecSpeed ;
    pParam->encCountToMechAngle = CONSTANT_QdecPulsesToMechAngle ;
    pParam->encCountToElecAngle = CONSTANT_QdecPulsesToElecAngle ;

    return returnType_Passed;
}



/*! \brief Rotor position calculation execution  function 
 * 
 * Details.
 *  Rotor position calculation execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( const tmcRpo_InstanceId_e Id )
{ 
    mcRpo_StateVariables_mas[Id].synCounter++;
    
    /* Calculate mechanical position */
    mcRpo_StateVariables_mas[Id].mechAngleCount = (int32_t)mcHalI_EncoderPositionGet( Id );
   *mcRpo_OutputPorts_mas[Id].mechAngle = mcRpo_StateVariables_mas[Id].mechAngleCount *  mcRpo_Parameters_mas[Id].encCountToMechAngle;
    mcLib_WrapAngleTo2Pi( mcRpo_OutputPorts_mas[Id].mechAngle  );
    
    /* Calculate electrical position */
    mcRpo_StateVariables_mas[Id].elecAngleCount = (int32_t)mcHalI_EncoderPositionGet( Id ) % CONSTANT_QdecPulsesPerElecRev;
   *mcRpo_OutputPorts_mas[Id].elecAngle = mcRpo_StateVariables_mas[Id].elecAngleCount *  mcRpo_Parameters_mas[Id].encCountToElecAngle;
    mcLib_WrapAngleTo2Pi( mcRpo_OutputPorts_mas[Id].elecAngle  );

    /* Calculate velocity */
    if( mcRpo_StateVariables_mas[Id].synCounter > mcRpo_Parameters_mas[Id].velocityCountPrescaler  )
    {
        mcRpo_StateVariables_mas[Id].synCounter = 0;
        mcRpo_StateVariables_mas[Id].elecVelocityCount = (int32_t)mcHalI_EncoderVelocityGet( Id );
    }
    *mcRpo_OutputPorts_mas[Id].elecVelocity = mcRpo_StateVariables_mas[Id].elecVelocityCount *  mcRpo_Parameters_mas[Id].encCountToElecVelocity;
   
}


/*! \brief Rotor position calculation trigger 
 * 
 * Details.
 *  Rotor position calculation trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationStart( const tmcRpo_InstanceId_e Id )
{
    /* Start the encoder */
    mcHalI_EncoderStart( Id );
    
    /* Reset state variables */
    mcRpoI_RotorPositionCalculationReset( Id );
    
} 

/*! \brief Rotor position calculation reset function 
 * 
 * Details.
 *  Rotor position calculation reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationReset( const tmcRpo_InstanceId_e Id )
{
    /* Reset state variables */
    mcRpo_StateVariables_mas[Id].synCounter = 0u;
    
    /* Reset output ports */
    *mcRpo_OutputPorts_mas[Id].elecAngle = 0.0f;
    *mcRpo_OutputPorts_mas[Id].mechAngle = 0.0f;
    *mcRpo_OutputPorts_mas[Id].elecVelocity = 0.0f;
    *mcRpo_OutputPorts_mas[Id].accel = 0.0f;
        
}

<#else>

/*******************************************************************************
 Constants
 *******************************************************************************/
#define CONSTANT_Pi                                        (float)3.14159265358979323846
#define CONSTANT_2Pi                                      (float)(2.0f * CONSTANT_Pi )
#define CONSTANT_QdecResetCount                 (uint32_t)( 65536u )
#define CONSTANT_QdecUpperThreshold          (uint32_t)( 49151u )
#define CONSTANT_QdecLowerThreshold          (uint32_t)( 16384u )
#define CONSTANT_QdecPulsesPerElecRev         (uint16_t)( CONFIG_EncoderPulsesPerMechRev  /CONFIG_RpoNumberOfPolePairs)
#define CONSTANT_QdecOverflowCount            (uint16_t)( CONSTANT_QdecResetCount % CONFIG_EncoderPulsesPerMechRev)
#define CONSTANT_QdecUnderflowCount          (uint16_t)( CONFIG_EncoderPulsesPerMechRev - CONSTANT_QdecOverflowCount)
#define CONSTANT_QdecPulsesToElecAngle       (float)(2.0f * CONSTANT_Pi/CONSTANT_QdecPulsesPerElecRev )
#define CONSTANT_QdecPulsesToMechAngle     (float)(2.0f * CONSTANT_Pi/CONFIG_EncoderPulsesPerMechRev )
#define CONSTANT_QdecVelocitySampleFreq     (float)((float)PWM_FREQUENCY / (float)CONFIG_VelcoityCalculationPrescale)
#define CONSTANT_QdecPulsesToElecSpeed      (float)(((float) 2.0f * CONSTANT_Pi * CONSTANT_QdecVelocitySampleFreq  )/((float)CONSTANT_QdecPulsesPerElecRev ))

/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcRpo_Parameters_s
{
    uint16_t encPulsesPerElecRev;
    uint16_t velocityCountPrescaler;
    uint16_t encOverflow;
    uint16_t encUnderflow;
    uint16_t encUpperThreshold;
    uint16_t encLowerThreshold;
    float encPulsesToElecVelocity;
    float encPulsesToMechAngle;
}tmcRpo_Parameters_s;

typedef struct _tmcRpo_StateVariables_s
{
    uint16_t synCounter;
    uint16_t encCount;
    uint16_t encCountForPositionLast;
    uint16_t encCountForPosition;
    uint16_t positionCompensation;
    int16_t encCountForVelocity;
    int16_t encCountForVelocityLast;
}tmcRpo_StateVariables_s;

/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcRpo_OutputPorts_s mcRpo_OutputPorts_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_StateVariables_s mcRpo_StateVariables_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_Parameters_s mcRpo_Parameters_mas[ROTOR_POSITION_INSTANCES];

/*******************************************************************************
 Interface variables  
 *******************************************************************************/
tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES] = 
{
   ROTOR_POSITION_MODULE_A_CONFIG,
#if( 2u == ROTOR_POSITION_INSTANCES )
   ROTOR_POSITION_MODULE_B_CONFIG
#endif
};

/*******************************************************************************
 Private Functions 
 *******************************************************************************/
static tStd_ReturnType_e mcRpo_AssertionFailedReaction( const char * message )
{
    /* ToDo: Decide appropriate reaction function */
     return returnType_Failed;
}

static inline void mcRpo_EulerFilter( float new, float * old, float filterParam )
{
    *old += ( new - ( *old ) ) * filterParam;
 }

static void mcRpo_WrapAngleFrom0To2Pi( float *angle )
{
    float rotationNumber;
    
    rotationNumber = ( *angle )/CONSTANT_2Pi;
    if( *angle > 0.0f )
    {
        *angle = ( rotationNumber - (int16_t)rotationNumber ) * CONSTANT_2Pi;
    }
    else 
    {
        *angle = -( rotationNumber - (int16_t)rotationNumber ) * CONSTANT_2Pi;
    }
}

#define ASSERT( expression, message ) { if(!expression)mcRpo_AssertionFailedReaction(message);}

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Rotor position calculation initialization function 
 * 
 * Details.
 *  Rotor position calculation initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( const tmcRpo_ConfigParameters_s * const encParam )
{
    tmcRpo_Parameters_s * pParam;
    
    /* Check if the configuration parameters data has valid address */
    ASSERT(( NULL != encParam ), "Configuration parameters points to NULL address ");
    
    /* Initialize output ports */
    ASSERT((      ( NULL != encParam->outPort.elecAngle ) && (NULL != encParam->outPort.mechAngle) 
                     && ( NULL != encParam->outPort.elecVelocity ) && ( NULL != encParam->outPort.accel ) ),
                         "Output ports are not assigned properly");
        
    mcRpo_OutputPorts_mas[encParam->Id] = encParam->outPort;
    
    /* Update and calculate independent and dependent parameters respectively */
    pParam = &mcRpo_Parameters_mas[encParam->Id];
    pParam->encPulsesPerElecRev =  CONSTANT_QdecPulsesPerElecRev;
    pParam->velocityCountPrescaler = encParam->userParam.velocityCountPrescaler ;
    pParam->encPulsesToElecVelocity =  CONSTANT_QdecPulsesToElecSpeed;
    pParam->encPulsesToMechAngle = CONSTANT_QdecPulsesToMechAngle ;
    pParam->encUpperThreshold = CONSTANT_QdecUpperThreshold;
    pParam->encLowerThreshold = CONSTANT_QdecLowerThreshold ;
    pParam->encUnderflow = CONSTANT_QdecUnderflowCount;
    pParam->encOverflow = CONSTANT_QdecOverflowCount;
    return returnType_Passed;
}



/*! \brief Rotor position calculation execution  function 
 * 
 * Details.
 *  Rotor position calculation execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( const tmcRpo_InstanceId_e Id )
{
       mcRpo_StateVariables_mas[Id].synCounter++;
    
     /* Calculate position */
     mcRpo_StateVariables_mas[Id].encCount = (uint16_t)mcHalI_EncoderPositionGet( Id );
    
    if(       ( mcRpo_StateVariables_mas[Id].encCount > mcRpo_Parameters_mas[Id].encUpperThreshold ) 
          && ( mcRpo_StateVariables_mas[Id].encCountForPositionLast < mcRpo_Parameters_mas[Id].encLowerThreshold))
    {
         mcRpo_StateVariables_mas[Id].positionCompensation += mcRpo_Parameters_mas[Id].encUnderflow;
    }
    else if(( mcRpo_StateVariables_mas[Id].encCountForPositionLast > mcRpo_Parameters_mas[Id].encUpperThreshold) 
          && ( mcRpo_StateVariables_mas[Id].encCount < mcRpo_Parameters_mas[Id].encLowerThreshold))
    {
         mcRpo_StateVariables_mas[Id].positionCompensation += mcRpo_Parameters_mas[Id].encOverflow;
    }
    else
    {
        /* Do nothing */
    }

    mcRpo_StateVariables_mas[Id].positionCompensation %=  mcRpo_Parameters_mas[Id].encPulsesPerElecRev;
    mcRpo_StateVariables_mas[Id].encCountForPosition  =  ( mcRpo_StateVariables_mas[Id].encCount + mcRpo_StateVariables_mas[Id].positionCompensation) % CONFIG_EncoderPulsesPerMechRev;
    mcRpo_StateVariables_mas[Id].encCountForPositionLast =  mcRpo_StateVariables_mas[Id].encCount;

    /* Calculate velocity */
    if( mcRpo_StateVariables_mas[Id].synCounter > mcRpo_Parameters_mas[Id].velocityCountPrescaler )
    {
         mcRpo_StateVariables_mas[Id].synCounter = 0u;
         mcRpo_StateVariables_mas[Id].encCountForVelocity = ( int16_t )mcRpo_StateVariables_mas[Id].encCount 
                                                                                           -  ( int16_t )mcRpo_StateVariables_mas[Id].encCountForVelocityLast;
         mcRpo_StateVariables_mas[Id].encCountForVelocityLast = (int16_t)mcRpo_StateVariables_mas[Id].encCount;
    }
   
    /* Write speed and position output */
    *mcRpo_OutputPorts_mas[Id].elecVelocity = (float)mcRpo_StateVariables_mas[Id].encCountForVelocity 
                                                                       * mcRpo_Parameters_mas[Id].encPulsesToElecVelocity;
    
    *mcRpo_OutputPorts_mas[Id].mechAngle = (float)mcRpo_StateVariables_mas[Id].encCountForPosition 
                                                                     * mcRpo_Parameters_mas[Id].encPulsesToMechAngle;
    
    *mcRpo_OutputPorts_mas[Id].elecAngle  =  ( *mcRpo_OutputPorts_mas[Id].mechAngle ) * CONFIG_RpoNumberOfPolePairs;
   
    /* Limit rotor angle range to 0 to 2*M_PI for lookup table */
    mcRpo_WrapAngleFrom0To2Pi( mcRpo_OutputPorts_mas[Id].elecAngle  );
 
}


/*! \brief Rotor position calculation trigger 
 * 
 * Details.
 *  Rotor position calculation trigger 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationStart( const tmcRpo_InstanceId_e Id )
{
    /* Start the encoder */
    mcHalI_EncoderStart( Id );
    
    /* Reset state variables */
    mcRpoI_RotorPositionCalculationReset( Id );
    
} 

/*! \brief Rotor position calculation reset function 
 * 
 * Details.
 *  Rotor position calculation reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationReset( const tmcRpo_InstanceId_e Id )
{
    /* Reset state variables */
    mcRpo_StateVariables_mas[Id].positionCompensation = 0u;
    mcRpo_StateVariables_mas[Id].encCountForPosition = 0u;
    mcRpo_StateVariables_mas[Id].encCountForPositionLast = 0u;
    mcRpo_StateVariables_mas[Id].encCountForVelocityLast = 0u;
    mcRpo_StateVariables_mas[Id].synCounter = 0u;
    
    /* Reset output ports */
    *mcRpo_OutputPorts_mas[Id].mechAngle = 0.0f;
    *mcRpo_OutputPorts_mas[Id].elecAngle = 0.0f;
    *mcRpo_OutputPorts_mas[Id].elecVelocity = 0.0f;
    *mcRpo_OutputPorts_mas[Id].accel = 0.0f;
        
}

</#if>
