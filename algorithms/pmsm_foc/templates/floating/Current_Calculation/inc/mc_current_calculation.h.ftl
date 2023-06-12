/*******************************************************************************
 Motor Control current measurement interface file

  Company:
    - Microchip Technology Inc.

  File Name:
    - mc_current_calculation.h

  Summary:
    - Header file for current measurement

  Description:
    - This file contains the data structures and function prototypes of current measurement.
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

#ifndef MCCUR_H_    // Guards against multiple inclusion
#define MCCUR_H_

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_utilities.h"
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 Default module parameters
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

typedef struct
{
    uint16_t  iaAdcInput;
    uint16_t  ibAdcInput;
}tmcCur_Input_s;

typedef struct
{
    tmcTypes_ABC_s  iABC;
    uint8_t  calibDone;
}tmcCur_Output_s;

typedef struct
{
    float32_t adcToCurrentFactor;
<#if MCPMSMFOC_OFFSET_OOR == true >
    float32_t minOffset;
    float32_t maxOffset;
</#if>
    void * pStatePointer;
}tmcCur_Parameters_s;

typedef struct
{
   tmcCur_Input_s dInput;
   tmcCur_Output_s dOutput;
   tmcCur_Parameters_s dParameters;
}tmcCur_ModuleData_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
extern tmcCur_ModuleData_s mcCurI_ModuleData_gds;

/*******************************************************************************
 Static Functions
 *******************************************************************************/
__STATIC_INLINE void mcCur_InputsRead( tmcCur_Input_s * const pInput )
{
    pInput->iaAdcInput = (uint16_t)mcHalI_IaAdcInput_gdu16;
    pInput->ibAdcInput = (uint16_t)mcHalI_IbAdcInput_gdu16;
}

__STATIC_INLINE void mcCur_ParametersSet( tmcCur_Parameters_s * const pParameters )
{
    pParameters->adcToCurrentFactor = (float32_t)(${MCPMSMFOC_CURRENT_SCALING_FACTORT});

<#if MCPMSMFOC_OFFSET_OOR == true >
    pParameters->minOffset = (float32_t)(${MCPMSMFOC_OFFSET_OOR_MINIMUM});
    pParameters->maxOffset = (float32_t)(${MCPMSMFOC_OFFSET_OOR_MAXIMUM});
</#if>
}

/*******************************************************************************
 Interface functions
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
void mcCurI_CurrentCalculationInit( tmcCur_ModuleData_s * const pModule );

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
tmcTypes_StdReturn_e mcCurI_CurrentOffsetCalculation( tmcCur_ModuleData_s * const pModule );

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
void mcCurI_CurrentCalculation( tmcCur_ModuleData_s * const pModule );


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
void mcCurI_CurrentCalculationReset( tmcCur_ModuleData_s * const pModule );

#endif //MCCUR_H_

/**
 End of File
*/
