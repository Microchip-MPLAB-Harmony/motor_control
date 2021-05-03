/*******************************************************************************
  System Definitions

  File Name:
    mc_current_measurement.h

  Summary:
    Header file which contains variables and function prototypes for feedback 
    current measurement for FOC

  Description:
    This file contains variables and function prototypes which are generally
    used for feedback current measurement for FOC. It is implemented in Q2.14
    fixed Point Arithmetic.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCCUR_H
#define MCCUR_H

#include <stdint.h>
#include <sys/attribs.h>
#include "mc_error_handler.h"
#include "mc_hardware_abstraction.h"
#include "mc_interface_handling.h"

/*******************************************************************************
 * Constants    
*******************************************************************************/
#define      MINIMUM_OFFSET               1950
#define      MAXIMUM_OFFSET              2150

/*******************************************************************************
  Default Module Configuration Parameters     
*******************************************************************************/
#define CURRENT_MEASUREMENT_MODULE_CONFIG  {\
    /* Instance Id */\
    0u,\
    /* Input ports */\
    {\
        &mcHalI_PhaseACurrent_gdu16,\
        &mcHalI_PhaseBCurrent_gdu16 \
    },\
    /* Output ports */\
    {\
        {\
            &mcCurI_PhaseCurrents_gds.a,\
            &mcCurI_PhaseCurrents_gds.b,\
            &mcCurI_PhaseCurrents_gds.c,\
        },\
        &mcCurI_CurrentOffsetCalibDone_gdu8  \
    },\
    /* User Parameters */\
    {\
          MINIMUM_OFFSET,\
          MAXIMUM_OFFSET,\
          BASE_CURRENT,\
          KAD_CUR \
    }\
}


/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef enum _tmcCur_InstanceId_e
{
    curModuleInstance_01,
    curModuleInstance_02,
    CurModuleInstance_max 
}tmcCur_InstanceId_e;

typedef struct _tmcCur_InputPorts_s
{
    uint16_t * iaAdcInput;
    uint16_t * ibAdcInput;
}tmcCur_InputPorts_s;


typedef struct _tmcCur_PhaseCurrents_s
{
    int16_t * ia;
    int16_t * ib;
    int16_t * ic;
}tmcCur_PhaseCurrents_s;

typedef struct _tmcCur_OutputPorts_s
{
    tmcCur_PhaseCurrents_s  phaseCurrents;
    uint8_t * calibDone;
}tmcCur_OutputPorts_s;

typedef struct _tmcCur_UserParameters_s
{
   uint16_t minOffset;
   uint16_t maxOffset;
   float baseCurrent;
   float adcToCurrent;
}tmcCur_UserParameters_s;

typedef struct _tmcCur_ConfigParameters_s
{
   /* Instance Id */
    uint8_t Id;
    
    /* Input ports */
    tmcCur_InputPorts_s inPort;
    
    /* Output ports */
    tmcCur_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcCur_UserParameters_s userParam;
    
}tmcCur_ConfigParameters_s;


/*******************************************************************************
 Interface variables 
 *******************************************************************************/
extern tmcCur_ConfigParameters_s mcCurI_ConfigurationParameters_gds;

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
void mcCurI_CurrentCalculationInit( tmcCur_ConfigParameters_s * curParam );

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
void mcCurI_CurrentSensorOffsetCalculate( const tmcCur_InstanceId_e Id );
    
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
void __ramfunc__  mcCurI_CurrentCalculationRun( const tmcCur_InstanceId_e Id );
#else
void  mcCurI_CurrentCalculationRun( const tmcCur_InstanceId_e Id );
#endif

   
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
void mcCurI_CurrentCalculationReset( const tmcCur_InstanceId_e Id );

#endif //_MCCUR_H

/**
 End of File
*/
