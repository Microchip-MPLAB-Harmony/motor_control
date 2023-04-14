/*******************************************************************************
 Current calculation functions 

  Company:
     - Microchip Technology Inc.

  File Name:
      - mc_current_calculation.c

  Summary:
      - Current calculation functions

  Description:
     - Current calculation functions
 
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
 Header files inclusions
 *******************************************************************************/
#include "mc_current_calculation.h"

/*******************************************************************************
 Module configuration
 *******************************************************************************/

/*******************************************************************************
 Private constants 
 *******************************************************************************/
#define OFFSET_SAMPLES    128u

/*******************************************************************************
 Private data-types 
 *******************************************************************************/

typedef struct
{
    uint8_t  calibDone;
    uint16_t  adcSampleCounter;
    float32_t iaOffset;
    float32_t ibOffset;
    float32_t adcToCurrentFactor;
<#if MCPMSMFOC_OFFSET_OOR == true >
    float32_t minOffset;
    float32_t maxOffset;
</#if>
    uint32_t iaOffsetBuffer;
    uint32_t ibOffsetBuffer;
}tmcCur_States_s;

/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcCur_States_s  mcCur_State_mds;

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcCur_ModuleData_s mcCurI_ModuleData_gds;

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Current control initialization function 
 * 
 * Details.
 *  Current control initialization function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcCurI_CurrentCalculationInit( tmcCur_ModuleData_s * const pModule )
{   
    tmcCur_States_s * pState;
    pState = &mcCur_State_mds;
        
    /** Set parameters */
    tmcCur_Parameters_s * pParameters = &pModule->dParameters;
    mcCur_ParametersSet( pParameters);
    
    /** Update intermediate parameters */
    pState = &mcCur_State_mds;
    pState->adcToCurrentFactor = pParameters->adcToCurrentFactor;
    
<#if MCPMSMFOC_OFFSET_OOR == true >
    pState->maxOffset = pParameters->maxOffset;
    pState->minOffset = pParameters->minOffset;
</#if>
}



/*! \brief Function to calculate the current sensor offset  
 * 
 * Details.
 * Function to calculate current sensor offset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tmcTypes_StdReturn_e mcCurI_CurrentOffsetCalculation( tmcCur_ModuleData_s * const pModule )
{
    tmcCur_States_s * pState;
    pState = &mcCur_State_mds;

    tmcTypes_StdReturn_e status = StdReturn_Progress;

    /** Read input ports */
    mcCur_InputsRead(&pModule->dInput);

    if ( pState->adcSampleCounter < OFFSET_SAMPLES)
    {
        pState->iaOffsetBuffer += (uint32_t)pModule->dInput.iaAdcInput;
        pState->ibOffsetBuffer += (uint32_t)pModule->dInput.ibAdcInput;
        pState->adcSampleCounter++;
    }
    else
    {

        pState->iaOffset = (float32_t)( (float32_t)pState->iaOffsetBuffer/ (float32_t)OFFSET_SAMPLES );
        pState->ibOffset = (float32_t)( (float32_t)pState->ibOffsetBuffer/ (float32_t)OFFSET_SAMPLES );

        /**Set ADC Calibration Done Flag */
        pState->calibDone = 1u;
        status = StdReturn_Complete;

<#if MCPMSMFOC_OFFSET_OOR == true >
        /** Plausibility check for offset values  */
        if( ( pState->minOffset > pState->iaOffset ) || ( pState->maxOffset < pState->iaOffset ) )
        {
            status = StdReturn_Fail;

            /** ToDO: Log error */
        }

        if( ( pState->minOffset > pState->ibOffset ) || ( pState->maxOffset < pState->ibOffset ) )
        {
            status = StdReturn_Fail;

            /** ToDO: Log error */
        }
        
</#if>

    }

    return status;
}
    
/*! \brief Function to calculate the phase  currents
 * 
 * Details.
 * Function to calculate phase currents 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcCurI_CurrentCalculation( tmcCur_ModuleData_s * const pModule )
{  
    tmcCur_States_s * pState;
    pState = &mcCur_State_mds;

    /** Read input ports */
    mcCur_InputsRead(&pModule->dInput);

    /** Phase A current measurement */
    pModule->dOutput.iABC.a = ( pState->iaOffset - (float32_t)pModule->dInput.iaAdcInput ) * pState->adcToCurrentFactor;

    /** Phase B current measurement */
    pModule->dOutput.iABC.b = ( pState->ibOffset - (float32_t)pModule->dInput.ibAdcInput ) * pState->adcToCurrentFactor;

    /** Phase C current calculation */
    pModule->dOutput.iABC.c = -pModule->dOutput.iABC.a - pModule->dOutput.iABC.b;
}


   
/*! \brief Function to reset phase current calculation 
 * 
 * Details.
 * Function to reset phase current calculation  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcCurI_CurrentCalculationReset( tmcCur_ModuleData_s * const pModule )
{
    /** Nothing to do */
}
