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
#include "mc_interface_handling.h"

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
/**
 * Minimum offset
 */
#define CONSTANT_MinimumOffset  ( 1950 )

/**
Maximum offset 
 */
#define CONSTANT_MaximumOffset ( 2300 )

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

typedef struct
{
    int16_t  iaAdcInput;
    int16_t  ibAdcInput;
}tmcCur_Input_s;

typedef struct
{
    tmcTypes_ABC_s  iABC;
    uint8_t  calibDone;
}tmcCur_Output_s;

typedef struct
{
   int16_t minOffset;
   int16_t maxOffset;
}tmcCur_Parameters_s;

typedef struct
{
    /* Input ports */
    tmcCur_Input_s pInput;
    
    /* Output ports */
    tmcCur_Output_s dOutput;
    
    /* User Parameters */
    tmcCur_Parameters_s pParameters;
    
}tmcCur_ModuleData_s;


/*******************************************************************************
 Interface variables 
 *******************************************************************************/
extern tmcCur_ModuleData_s mcCurI_ModuleData_gds;


/*******************************************************************************
 Static Functions
 *******************************************************************************/
__STATIC_INLINE  void mcCur_InputPortsRead( tmcCur_Input_s * const pInput )
{
    pInput->iaAdcInput = (int16_t)mcHalI_IaAdcInput_gdu16;
    pInput->ibAdcInput = (int16_t)mcHalI_IbAdcInput_gdu16;
}

__STATIC_INLINE void mcCur_OutputPortsWrite( tmcCur_Output_s * const pOutput )
{
    /** ToDO: Remove for  optimization */
}

__STATIC_INLINE void mcCur_ParametersSet( tmcCur_Parameters_s * const pParameters )
{
    pParameters->minOffset = CONSTANT_MinimumOffset;
    pParameters->maxOffset = CONSTANT_MaximumOffset;
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
void mcCurI_CurrentSensorOffsetCalculate( tmcCur_ModuleData_s * const pModule );
    
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
