/*******************************************************************************
 Flux regulation source filr 
 * 
  Company:
    Microchip Technology Inc.

  File Name:
    mc_flux_regulation.c

  Summary:
    This file contains functions for PMSM flux regulation 

  Description:
    This file contains functions for PMSM flux regulation 
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
#include "mc_flux_control.h"
/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcFlx_Parameters_s
{
    float  wbase;                 
    float  umaxSqr;    
    float  usFiltCoeff; 
    float  lsByDt; 
    float  rs;  
    float ls;
    float  idmax;   
}tmcFlx_Parameters_s;

typedef struct _tmcFlx_StateVariables_s
{
    float uqrefFilt;                              
    float iqrefFilt;                            
    float iqrefLast;    
}tmcFlx_StateVariables_s;


/*******************************************************************************
 Constants 
 *******************************************************************************/

/**
 * Constant value of PI
 */
#define CONSTANT_Pi                                (float)3.14159265358979323846

/**
 * RPM to Rad Per Second Conversion factor
 */
#define CONSTANT_RpmToRadPerSec        (float)( 2.0f * NUM_POLE_PAIRS * CONSTANT_Pi / 60.0f )


/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcFlx_InputPorts_s mcFlx_InputPorts_mas[FLUX_CONTROL_INSTANCES];
static tmcFlx_OutputPorts_s mcFlx_OutputPorts_mas[FLUX_CONTROL_INSTANCES];
static tmcFlx_StateVariables_s mcFlx_StateVariables_mas[FLUX_CONTROL_INSTANCES];
static tmcFlx_Parameters_s mcFlx_Parameters_mas[FLUX_CONTROL_INSTANCES];

/*******************************************************************************
 Interface variables  
 *******************************************************************************/
tmcFlx_ConfigParameters_s  mcFlxI_ConfigParameters_gas[FLUX_CONTROL_INSTANCES] = 
{
    FLUX_CONTROL_MODULE_A_CONFIG,
#if( 2u == FLUX_CONTROL_INSTANCES )
    FLUX_CONTROL_MODULE_B_CONFIG
#endif
};

/*******************************************************************************
 Private Functions 
 *******************************************************************************/
static tStd_ReturnType_e mcFlx_AssertionFailedReaction( const char * message )
{
    /* ToDo: Decide appropriate reaction function */
     return returnType_Failed;
}

static inline void mcFlx_EulerFilter( float new, float * old, float filterParam )
{
    *old += ( new - ( *old ) ) * filterParam;
 }

#define ASSERT( expression, message ) { if(!expression)mcFlx_AssertionFailedReaction(message);}

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Flux regulation module initialization function 
 * 
 * Details.
 *  Flux regulation module initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcFlxI_FluxRegulationInit( const tmcFlx_ConfigParameters_s * const flxParam )
{   
    tmcFlx_Parameters_s * pParam;
    
    /* Check if the configuration parameters data has valid address */
    ASSERT(( NULL != flxParam ), "Configuration parameters points to NULL address ");
    
    /* Initialize input ports */
    ASSERT((      ( NULL != flxParam->inPort.es ) && (NULL != flxParam->inPort.iqref) 
                     && ( NULL != flxParam->inPort.ud) && (NULL != flxParam->inPort.umax ) 
                     && ( NULL != flxParam->inPort.wel )),"Input ports are not assigned properly");
    
    
    mcFlx_InputPorts_mas[flxParam->Id] = flxParam->inPort;
    
    /* Initialize output ports */
    ASSERT( ( NULL != flxParam->outPort.idref ), "Output ports are not assigned properly");
        
    mcFlx_OutputPorts_mas[flxParam->Id] = flxParam->outPort;
    
    /* Update and calculate independent and dependent parameters respectively */
    pParam = &mcFlx_Parameters_mas[flxParam->Id];
    pParam->rs =flxParam->userParam.rs ;   
    pParam->wbase = CONSTANT_RpmToRadPerSec* flxParam->userParam.wbase;
    pParam->umaxSqr = flxParam->userParam.umaxSqr;
    pParam->usFiltCoeff = flxParam->userParam.usFiltCoeff;
    pParam->idmax = flxParam->userParam.idmax;
    pParam->ls = flxParam->userParam.ls;
    pParam->lsByDt = flxParam->userParam.fs * flxParam->userParam.ls;
    
    return returnType_Passed;
}


/*! \brief Flux regulation  execution  function 
 * 
 * Details.
 * Flux regulation execution function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFlxI_FluxRegulationRun( const tmcFlx_InstanceId_e Id )
{
    float UqRef, UdSquare,OmegaLs, idref;

    UdSquare = ( *mcFlx_InputPorts_mas[Id].ud ) *  ( *mcFlx_InputPorts_mas[Id].ud ) ;

    if(  ( *mcFlx_InputPorts_mas[Id].wel  ) >  mcFlx_Parameters_mas[Id].wbase )
    {
        if(UdSquare >= mcFlx_Parameters_mas[Id].umaxSqr)
        {
            UdSquare = mcFlx_Parameters_mas[Id].umaxSqr;
        }

        UqRef = mcLib_SquareRootCalculate((float)(  mcFlx_Parameters_mas[Id].umaxSqr - UdSquare));
        mcFlx_EulerFilter( UqRef, & mcFlx_StateVariables_mas[Id].uqrefFilt, mcFlx_Parameters_mas[Id].usFiltCoeff );
      
        OmegaLs = ( ( *mcFlx_InputPorts_mas[Id].wel  ) *  mcFlx_Parameters_mas[Id].ls);

        /* Id reference for feed forward control */
        idref =  ( *mcFlx_InputPorts_mas[Id].iqref ) - mcFlx_StateVariables_mas[Id].iqrefLast;
        idref *= mcFlx_Parameters_mas[Id].lsByDt;
        idref +=  mcFlx_StateVariables_mas[Id].uqrefFilt * ( *mcFlx_InputPorts_mas[Id].umax);
        idref -= (  mcFlx_Parameters_mas[Id].rs * ( *mcFlx_InputPorts_mas[Id].iqref ) );
        idref -= ( *mcFlx_InputPorts_mas[Id].es );
        idref /= OmegaLs;
        
        mcFlx_StateVariables_mas[Id].iqrefLast = ( *mcFlx_InputPorts_mas[Id].iqref );

        /* d-axis current saturation  */
        if(idref > 0)
        {
             *mcFlx_OutputPorts_mas[Id].idref = 0;
        }
        else if( idref <  mcFlx_Parameters_mas[Id].idmax)
        {
            *mcFlx_OutputPorts_mas[Id].idref =  mcFlx_Parameters_mas[Id].idmax;
        }
        else
        {
            *mcFlx_OutputPorts_mas[Id].idref = idref;
        }
    }
    else
    {
        /* Field weakening is disabled below rated speed. */
        *mcFlx_OutputPorts_mas[Id].idref = 0;
    }
}

/*! \brief Flux regulation reset function 
 * 
 * Details.
 *  Flux regulation reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFlxI_FluxRegulationReset( const tmcFlx_InstanceId_e Id )
{
     /* Reset state variables */
    mcFlx_StateVariables_mas[Id].iqrefFilt = 0.0f;
    mcFlx_StateVariables_mas[Id].iqrefLast = 0.0f;
    mcFlx_StateVariables_mas[Id].uqrefFilt = 0.0f;
    
    /* Reset output ports */
    *mcFlx_OutputPorts_mas[Id].idref = 0.0f;
}

