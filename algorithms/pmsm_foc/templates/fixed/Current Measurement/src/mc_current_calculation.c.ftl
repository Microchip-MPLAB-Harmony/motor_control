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
#define USE_DUAL_SHUNT

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
    int16_t iaOffset;
    int16_t ibOffset;
    int16_t minOffset;
    int16_t maxOffset;
    int32_t  iaOffsetBuffer;
    int32_t  ibOffsetBuffer;
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
        
   /* Set parameters */   
    mcCur_ParametersSet( &pModule->pParameters);
    
    /* Update intermediate parameters */
    pState = &mcCur_State_mds;
    pState->maxOffset = pModule->pParameters.maxOffset;
    pState->minOffset = pModule->pParameters.minOffset;
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
void mcCurI_CurrentSensorOffsetCalculate( tmcCur_ModuleData_s * const pModule )
{
    tmcCur_States_s * pState;
    tmcCur_Input_s * pInput;
    tmcCur_Output_s * pOutput;
    
    pInput = &pModule->pInput;
    pOutput = &pModule->dOutput;
    pState = &mcCur_State_mds;
    
    mcCur_InputPortsRead( pInput );
    
    if ( pState->adcSampleCounter < OFFSET_SAMPLES)
    {

#if defined USE_DUAL_SHUNT
        pState->iaOffsetBuffer += pInput->iaAdcInput;
        pState->ibOffsetBuffer += pInput->ibAdcInput;
#elif defined USE_TRIPLE_SHUNT
        /** ToDO: */
#else
        /** ToDO: */
#endif
        pState->adcSampleCounter++;
    }
    else
    {

        pState->iaOffset = (int16_t)( pState->iaOffsetBuffer/ (int16_t)OFFSET_SAMPLES );
        pState->ibOffset = (int16_t)( pState->ibOffsetBuffer/ (int16_t)OFFSET_SAMPLES );

        /**Set ADC Calibration Done Flag */
        pOutput->calibDone = 1u;
    }
    
    mcCur_OutputPortsWrite( &pModule->dOutput );
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
    tmcCur_Input_s * pInput;
    tmcCur_Output_s * pOutput;
    
    pInput = &pModule->pInput;
    pOutput = &pModule->dOutput;
    pState = &mcCur_State_mds;
    
    mcCur_InputPortsRead( &pModule->pInput );

#if defined USE_DUAL_SHUNT
     /** Phase A current measurement */
    pOutput->iABC.a = mcUtils_LeftShiftS16((pInput->iaAdcInput - pState->iaOffset), 3u );

    /** Phase B current measurement */
    pOutput->iABC.b = mcUtils_LeftShiftS16((pInput->ibAdcInput - pState->ibOffset), 3u );
    
#elif defined USE_TRIPLE_SHUNT
    /** ToDO*/
#elif defined USE_SINGLE_SHUNT
    /** ToDO*/
#else
#endif
       
    mcCur_OutputPortsWrite( &pModule->dOutput );
      
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
    tmcCur_Output_s * pOutput;
    pOutput = &pModule->dOutput;
    
    /** Reset state variables */
           
    /** Reset output ports */
    pOutput->iABC.a = 0;
    pOutput->iABC.b = 0;
    pOutput->iABC.c = 0;
    
    /** Update output ports */
    mcCur_OutputPortsWrite( &pModule->dOutput );
    
}
