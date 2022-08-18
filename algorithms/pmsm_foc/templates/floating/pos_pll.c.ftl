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
#include <stdint.h>
#include "mc_rotor_position.h"
#include "mc_generic_library.h"

/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct
{
    float   dLsByDt;
    float   Rs;
    float   oneByKe;
    float   EdqFilterParam;
    float   WrFilterParam;
    float   Wrmin;
    float   Ts;
}tmcRpo_Parameters_s;

typedef struct _tmcRpo_StateVariables_s
{
    float  ealpha;
    float  ebeta;
    float  Ed;
    float  Eq;
    float  ualpha;
    float  ubeta;
    float ialpha;
    float ibeta;
    float  theta;
    float  Wre;
    float  accel;
}tmcRpo_StateVariables_s;


/*******************************************************************************
 Constants 
 *******************************************************************************/
/*
 * Zero Boundary
 */
#define EPSILON   1E-31

/*
 * Constant value for PI
 */
#define CONSTANT_pi        (float)3.14159265358979323846

/*
 * Constant value for root 3
 */
#define CONSTANT_squareRootOf3              ((float)1.732)

/*
 * Back EMF constant conversion factor from Vpeak / kRPM to Vpeak-s/rad
 */
#define  CONSTANT_vPeakPerKrpmTovPeakSecPerRad (float)( 3.0f  / ( 100.0f * CONSTANT_squareRootOf3 * CONSTANT_pi * NUM_POLE_PAIRS ))

/*
 * RPM to electrical rad/s conversion factor
 */
#define  CONSTANT_mechRpmToElecRadPerSec  (float)( CONSTANT_pi *NUM_POLE_PAIRS / 30.0f ) 

/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcRpo_InputPorts_s mcRpo_InputPorts_mas[ROTOR_POSITION_INSTANCES];
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
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( const tmcRpo_ConfigParameters_s * const rpoParam )
{
    float Ke;
    
    tmcRpo_Parameters_s * pParam;
    
    /* Check if the configuration parameters data has valid address */
    ASSERT(( NULL != rpoParam ), "Configuration parameters points to NULL address ");
    
    /* Initialize input ports */
    ASSERT((      ( NULL != rpoParam->inPort.ialpha ) && (NULL != rpoParam->inPort.ibeta) 
                     && ( NULL != rpoParam->inPort.ualpha) && (NULL != rpoParam->inPort.ubeta ) 
                     && ( NULL != rpoParam->inPort.umax ) ), "Input ports are not assigned properly");
    
    
    mcRpo_InputPorts_mas[rpoParam->Id] = rpoParam->inPort;
    
    /* Initialize output ports */
    ASSERT((      ( NULL != rpoParam->outPort.theta ) && (NULL != rpoParam->outPort.Wre) 
                     && ( NULL != rpoParam->outPort.accel ) ), "Output ports are not assigned properly");
        
    mcRpo_OutputPorts_mas[rpoParam->Id] = rpoParam->outPort;
    
    /* Update and calculate independent and dependent parameters respectively */
    pParam = &mcRpo_Parameters_mas[rpoParam->Id];
    pParam->Rs = rpoParam->userParam.Rs;
    pParam->Wrmin = CONSTANT_mechRpmToElecRadPerSec * rpoParam->userParam.Wrmin;
    pParam->Ts = rpoParam->userParam.Ts;
    
    ASSERT((EPSILON < rpoParam->userParam.Ts ), "Division by zero");
    pParam->dLsByDt  = rpoParam->userParam.Ls / rpoParam->userParam.Ts;
    
    ASSERT((EPSILON < rpoParam->userParam.Ke ), "Division by zero");
    Ke = CONSTANT_vPeakPerKrpmTovPeakSecPerRad * rpoParam->userParam.Ke;
    pParam->oneByKe  = 1.0f / Ke;
    pParam->EdqFilterParam = rpoParam->userParam.EdqFilterBandwidth;
    pParam->WrFilterParam = rpoParam->userParam.WrFilterBandwidth;
    
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
    float sine, cosine;
    float ealpha, ebeta;
    float Wre, Ed, Eq;

#if (ENABLE == ENABLE_FLUX_WEAKENING )
    float esSquare;
#endif
    
    /* Read input ports */

    
    /* Calculate back EMF along alpha and beta axis */
    ealpha  =   mcRpo_StateVariables_mas[Id].ialpha - (*mcRpo_InputPorts_mas[Id].ialpha );
    ealpha *=  mcRpo_Parameters_mas[Id].dLsByDt;
    ealpha -= (*mcRpo_InputPorts_mas[Id].ialpha * mcRpo_Parameters_mas[Id].Rs );
    ealpha += mcRpo_StateVariables_mas[Id].ualpha; 
    mcRpo_EulerFilter( ealpha, &mcRpo_StateVariables_mas[Id].ealpha, 1.0f );
    
    ebeta  =   mcRpo_StateVariables_mas[Id].ibeta - (*mcRpo_InputPorts_mas[Id].ibeta );
    ebeta *=  mcRpo_Parameters_mas[Id].dLsByDt;
    ebeta -= (*mcRpo_InputPorts_mas[Id].ibeta * mcRpo_Parameters_mas[Id].Rs );
    ebeta +=  mcRpo_StateVariables_mas[Id].ubeta; 
    mcRpo_EulerFilter( ebeta, &mcRpo_StateVariables_mas[Id].ebeta, 1.0f);

#if (ENABLE == ENABLE_FLUX_WEAKENING )
    /* Calculate BEMF for field weakening*/
    esSquare =  ( mcRpo_StateVariables_mas[Id].ebeta * mcRpo_StateVariables_mas[Id].ebeta ) 
       +  ( mcRpo_StateVariables_mas[Id].ealpha * mcRpo_StateVariables_mas[Id].ealpha );

    *mcRpo_OutputPorts_mas[Id].es = mcLib_SquareRootCalculate(esSquare);
#endif
    
    /* Determine back EMF along direct and quadrature axis using estimated angle */
    mcLib_SinCosCalc( mcRpo_StateVariables_mas[Id].theta, &sine, &cosine );
    
    Ed  =     mcRpo_StateVariables_mas[Id].ealpha * cosine;
    Ed +=  ( mcRpo_StateVariables_mas[Id].ebeta * sine );
    mcRpo_EulerFilter( Ed, &mcRpo_StateVariables_mas[Id].Ed, mcRpo_Parameters_mas[Id].EdqFilterParam);
    
    Eq  =    -mcRpo_StateVariables_mas[Id].ealpha * sine;
    Eq +=  ( mcRpo_StateVariables_mas[Id].ebeta * cosine );
    mcRpo_EulerFilter( Eq, &mcRpo_StateVariables_mas[Id].Eq, mcRpo_Parameters_mas[Id].EdqFilterParam);
     
     /* Determine speed  */
    if( mcRpo_StateVariables_mas[Id].Eq  > 0.0f )
    {
         Wre  = mcRpo_StateVariables_mas[Id].Eq - mcRpo_StateVariables_mas[Id].Ed;
    }
    else
    {
         Wre  = mcRpo_StateVariables_mas[Id].Eq + mcRpo_StateVariables_mas[Id].Ed;
    }
    
    Wre *= mcRpo_Parameters_mas[Id].oneByKe;
    mcRpo_EulerFilter( Wre, &mcRpo_StateVariables_mas[Id].Wre, mcRpo_Parameters_mas[Id].WrFilterParam);
               
    /*Determine phase angle */
    mcRpo_StateVariables_mas[Id].theta += ( mcRpo_Parameters_mas[Id].Ts * mcRpo_StateVariables_mas[Id].Wre );
    mcLib_WrapAngleTo2Pi( &mcRpo_StateVariables_mas[Id].theta );
    
    /* Update state variables for next cycle calculation */
    mcRpo_StateVariables_mas[Id].ualpha  = (*mcRpo_InputPorts_mas[Id].ualpha ) * (*mcRpo_InputPorts_mas[Id].umax );
    mcRpo_StateVariables_mas[Id].ubeta  =  (*mcRpo_InputPorts_mas[Id].ubeta )* (*mcRpo_InputPorts_mas[Id].umax );
    mcRpo_StateVariables_mas[Id].ialpha  = *mcRpo_InputPorts_mas[Id].ialpha;
    mcRpo_StateVariables_mas[Id].ibeta   = *mcRpo_InputPorts_mas[Id].ibeta;
      
    /* Update output ports */
    *mcRpo_OutputPorts_mas[Id].theta = mcRpo_StateVariables_mas[Id].theta;
    *mcRpo_OutputPorts_mas[Id].Wre = mcRpo_StateVariables_mas[Id].Wre;
    *mcRpo_OutputPorts_mas[Id].accel = mcRpo_StateVariables_mas[Id].accel;
    
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
    mcRpo_StateVariables_mas[Id].Ed = 0.0f;
    mcRpo_StateVariables_mas[Id].Eq = 0.0f;
    mcRpo_StateVariables_mas[Id].ealpha = 0.0f;
    mcRpo_StateVariables_mas[Id].ebeta = 0.0f;
    mcRpo_StateVariables_mas[Id].theta = 0.0f;
    mcRpo_StateVariables_mas[Id].Wre = 0.0f;
    mcRpo_StateVariables_mas[Id].accel = 0.0f;
    mcRpo_StateVariables_mas[Id].ualpha = 0.0f;
    mcRpo_StateVariables_mas[Id].ubeta = 0.0f;
    mcRpo_StateVariables_mas[Id].ialpha = 0.0f;
    mcRpo_StateVariables_mas[Id].ibeta = 0.0f;
    
    /* Reset output ports */
    *mcRpo_OutputPorts_mas[Id].Wre = 0.0f;
    *mcRpo_OutputPorts_mas[Id].theta = 0.0f;
    *mcRpo_OutputPorts_mas[Id].accel = 0.0f; 
}

