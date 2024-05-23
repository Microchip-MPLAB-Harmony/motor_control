/*******************************************************************************
 Voltage calculation functions

  Company:
    Microchip Technology Inc.

  File Name:
    mc_voltage_measurement.c

  Summary:
  Voltage calculation functions

  Description:
  Voltage Calculation functions

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
#include "mc_voltage_measurement.h"

/*******************************************************************************
 * Constants
 *******************************************************************************/

/*******************************************************************************
 Private data-types
 *******************************************************************************/
  typedef struct
  {
     float32_t adcToVoltsFactor;
  }tmcVol_State_s;

/*******************************************************************************
 Private variables
 *******************************************************************************/
static tmcVol_State_s mcVol_State_mds;

/*******************************************************************************
 Interface Variables
 *******************************************************************************/
tmcVol_ModuleData_s mcVolI_ModuleData_gds;

/*******************************************************************************
 Private Functions
 *******************************************************************************/

/*******************************************************************************
 Interface Functions
 *******************************************************************************/

/*! \brief Voltage calculation initialization function
 *
 * Details.
 *  Voltage calculation initialization function
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void  mcVolI_VoltageCalculationInit( tmcVol_ModuleData_s * const pModule )
{
    /** Link state variable structure to the module */
    pModule->dParameters.pStatePointer = (void *)&mcVol_State_mds;

    /** Set parameters */
    mcVol_ParametersSet( &pModule->dParameters);

    /** Update state variables */
    mcVol_State_mds.adcToVoltsFactor = pModule->dParameters.adcToVoltsFactor;


}


/*! \brief Voltage calculation function
 *
 * Details.
 *  Voltage calculation function
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcVolI_VoltageCalculation( tmcVol_ModuleData_s * const pModule )
{
    tmcVol_Input_s * pInput;

    pInput = &pModule->dInput;

     /** Get the linked state variable */
    tmcVol_State_s * pState;
    pState = (tmcVol_State_s *)pModule->dParameters.pStatePointer;

    /** Read input ports */
    mcVol_InputPortsRead(pInput);

    /** Calculate DC bus voltage */
    pModule->dOutput.uBus =   (float32_t)pInput->sensorInput * pState->adcToVoltsFactor;
}




/*! \brief Voltage calculation reset
 *
 * Details.
 *  Voltage calculation reset
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcVolI_VoltageCalculationReset( tmcVol_ModuleData_s * const pModule )
{
    tmcVol_Output_s * pOutput;
    pOutput = &pModule->dOutput;

    /** Reset output ports */
    pOutput->uBus = 0.0f;
}
