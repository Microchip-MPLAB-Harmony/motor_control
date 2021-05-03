/*******************************************************************************
  System Definitions

  File Name:
    mc_voltage_measurement.h

  Summary:
    Header file which contains variables and function prototypes for voltage 
     measurement module

  Description:
    This file contains variables and function prototypes which are generally
    used in to for voltage  measurement module. It is implemented in Q2.14
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

#ifndef MCVOL_H
#define MCVOL_H


/*******************************************************************************
 * Header Inclusions   
*******************************************************************************/
#include <stdint.h>
#include <sys/attribs.h>
#include "mc_generic_library.h"
#include "mc_hardware_abstraction.h"
#include "mc_interface_handling.h"
#include "mc_error_handler.h"
#include "mc_userparams.h"

/*******************************************************************************
 Constants 
*******************************************************************************/
#define  BUS_VOLTAGE_FILTER_PARAMETER ( float )( 1.0f )
/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define VOLTAGE_MEASUREMENT_MODULE {\
    0u,\
    /* Input Ports */\
    {\
        &mcHalI_DcBusVoltage_gdu16 \
    },\
    \
    /* Output Ports */\
    {\
        &mcVolI_DcBusVoltage_gds16, \
        &mcVolI_DcBusVoltageFilt_gds16, \
        &mcVolI_UacPeakVoltage_gds16, \
    },\
    \
    /* User Parameters */\
    {\
        BASE_VOLTAGE, \
        KAD_VOL,\
        BUS_VOLTAGE_FILTER_PARAMETER \
    }  \
}

/*******************************************************************************
  User-defined data-structure   
*******************************************************************************/

typedef enum _tmcVol_InstanceId_e
{
    volModuleInstance_01,
    volModuleInstance_02,
    volModuleInstance_max 
}tmcVol_InstanceId_e;

typedef struct
{
   uint16_t * sensorInput;
}tmcVol_InputPorts_s;

typedef struct
{
   int16_t * busVoltage;
   int16_t * filteredBusVoltage;
   int16_t * maximumUacPeak;
}tmcVol_OutputPorts_s;


typedef struct _tmcVol_UserParameters_s
{
    float baseVoltage;
    float adcToVoltage;
    float busVoltageFiltParam;
}tmcVol_UserParameters_s;

typedef struct _tmcVol_Dependencies_s
{
    
}tmcVol_Dependencies_s;


typedef struct _tmcVol_ConfigParameters_s
{
    /* Instance Identifier */
    uint8_t Id;
    
    /* Input ports */
    tmcVol_InputPorts_s inPort;
    
    /* Output ports */
    tmcVol_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcVol_UserParameters_s userParam;
       
}tmcVol_ConfigParameters_s;

/*******************************************************************************
 * Interface variables   
*******************************************************************************/
extern tmcVol_ConfigParameters_s mcVolI_ConfigurationParameters_gds;

/*******************************************************************************
 * Interface Functions   
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
void mcVolI_VoltageCalculationInit( tmcVol_ConfigParameters_s * volParam );

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
#ifdef RAM_EXECUTE
void __ramfunc__ mcVolI_VoltageCalculationRun( const tmcVol_InstanceId_e Id );
#else
void mcVolI_VoltageCalculationRun( const tmcVol_InstanceId_e Id );
#endif


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
void mcVolI_VoltageCalculationReset( const tmcVol_InstanceId_e Id );

#endif //_MCVOL_H

/**
 End of File
*/

  