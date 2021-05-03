/*******************************************************************************
 Motor current measurement module 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_current_measurement.c

  Summary:
     Motor current measurement module .

  Description:
    This file implements functions for  motor current measurement module 
 
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
 * Headers inclusions
*******************************************************************************/
#include "mc_current_measurement.h"


/*******************************************************************************
 Private constants 
 *******************************************************************************/
#define OFFSET_SAMPLES    (uint16_t)128

/*******************************************************************************
 Private data-types 
 *******************************************************************************/

typedef struct _mcCur_StateVariables_s
{
    uint8_t  calibDone;
    uint16_t  adcSampleCounter;
    uint32_t  iaOffsetBuffer;
    uint32_t  ibOffsetBuffer;
    uint16_t iaOffset;
    uint16_t ibOffset;
}tmcCur_StateVariables_s;

typedef struct _tmcCur_Parameters_s
{
   uint16_t  minOffset;
   uint16_t  maxOffset;
   float adcToCurrent;
}tmcCur_Parameters_s;


/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcCur_InputPorts_s mcCur_InputPorts_mas[1u];
static tmcCur_OutputPorts_s mcCur_OutputPorts_mas[1u];
static tmcCur_Parameters_s mcCur_Parameters_mas[1u];
static tmcCur_StateVariables_s mcCur_StateVariables_mas[1u];

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcCur_ConfigParameters_s mcCurI_ConfigurationParameters_gds = CURRENT_MEASUREMENT_MODULE_CONFIG;

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
void mcCurI_CurrentCalculationInit( tmcCur_ConfigParameters_s * curParam )
{   
    /* Check if the configuration data has a valid address */
    ASSERT(( NULL != curParam ), "Configuration data points to NULL address ");
    
    /* Initialize input ports */
    ASSERT((( NULL != curParam->inPort.iaAdcInput) && ( NULL != curParam->inPort.ibAdcInput )),
                      "Input ports are not assigned properly");
    
    mcCur_InputPorts_mas[curParam->Id] = curParam->inPort;
    
    /* Initialize output ports */
    ASSERT((( NULL != curParam->outPort.calibDone ) && ( NULL != curParam->outPort.phaseCurrents.ia ) &&
                    ( NULL != curParam->outPort.phaseCurrents.ib ) &&  ( NULL != curParam->outPort.phaseCurrents.ic )),
                     " Output ports are not initialized properly " );
    
    mcCur_OutputPorts_mas[curParam->Id] = curParam->outPort;
    
    /* Update and calculate independent and dependent module parameters respectively */
    mcCur_Parameters_mas[curParam->Id].maxOffset = curParam->userParam.maxOffset;
    mcCur_Parameters_mas[curParam->Id].minOffset = curParam->userParam.minOffset;
    mcCur_Parameters_mas[curParam->Id].adcToCurrent = -curParam->userParam.adcToCurrent;
      
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
#ifdef RAM_EXECUTE
void __ramfunc__  mcCurI_CurrentSensorOffsetCalculate( const tmcCur_InstanceId_e Id )
#else
void mcCurI_CurrentSensorOffsetCalculate( const tmcCur_InstanceId_e Id )
#endif
{    
    if ( mcCur_StateVariables_mas[Id].adcSampleCounter < OFFSET_SAMPLES)
    {
        mcCur_StateVariables_mas[Id].iaOffsetBuffer += (*mcCur_InputPorts_mas[Id].iaAdcInput );
        mcCur_StateVariables_mas[Id].ibOffsetBuffer += (*mcCur_InputPorts_mas[Id].ibAdcInput );
        mcCur_StateVariables_mas[Id].adcSampleCounter++;
    }
    else
    {

        mcCur_StateVariables_mas[Id].iaOffset = (uint16_t)(mcCur_StateVariables_mas[Id].iaOffsetBuffer/(uint32_t)OFFSET_SAMPLES );
        mcCur_StateVariables_mas[Id].ibOffset = (uint16_t)(mcCur_StateVariables_mas[Id].ibOffsetBuffer/(uint32_t)OFFSET_SAMPLES );
        
        /*Set ADC Calibration Done Flag*/
        *mcCur_OutputPorts_mas[Id].calibDone = 1u;
    }

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
#ifdef RAM_EXECUTE
void __ramfunc__  mcCurI_CurrentCalculationRun( const tmcCur_InstanceId_e Id )
#else
void  mcCurI_CurrentCalculationRun( const tmcCur_InstanceId_e Id )
#endif
{    
     /* Phase A current measurement */
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ia  = ( mcCur_StateVariables_mas[0u].iaOffset );
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ia -= (*mcCur_InputPorts_mas[0u].iaAdcInput ); 
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ia *= ( mcCur_Parameters_mas[0u].adcToCurrent );
    
    /* Phase B current measurement */
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ib  = ( mcCur_StateVariables_mas[0u].ibOffset );
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ib -= (*mcCur_InputPorts_mas[0u].ibAdcInput ); 
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ib *= ( mcCur_Parameters_mas[0u].adcToCurrent );
    
    /* Calculate phase W current by Kirchhoff's principle  */
    *mcCur_OutputPorts_mas[0u].phaseCurrents.ic   = -(*mcCur_OutputPorts_mas[0u].phaseCurrents.ia );
    *mcCur_OutputPorts_mas[0u].phaseCurrents.ic  -=  (*mcCur_OutputPorts_mas[0u].phaseCurrents.ib );
 
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
void mcCurI_CurrentCalculationReset( const tmcCur_InstanceId_e Id )
{
    /* Reset state variables */
    mcCur_StateVariables_mas[Id].adcSampleCounter = 0u;
    mcCur_StateVariables_mas[Id].calibDone = 0u;
    mcCur_StateVariables_mas[Id].iaOffsetBuffer = 0u;
    mcCur_StateVariables_mas[Id].ibOffsetBuffer = 0u;
    mcCur_StateVariables_mas[Id].iaOffset = 0u;
    mcCur_StateVariables_mas[Id].ibOffset = 0u;
    
    /* Reset output ports */
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ia = 0.0f;
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ib = 0.0f;
    *mcCur_OutputPorts_mas[Id].phaseCurrents.ic = 0.0f;
    
}

/* EOF mc_CurrentMeasurement.c */

