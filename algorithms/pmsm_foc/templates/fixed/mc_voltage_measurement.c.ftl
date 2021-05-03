/*******************************************************************************
 Voltage measurement module

  Company:
    Microchip Technology Inc.

  File Name:
    mc_voltage_measurement.c

  Summary:
    Voltage measurement module .

  Description:
    This file implements functions for voltage measurement.
 
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
Headers inclusions
*******************************************************************************/
#include "mc_voltage_measurement.h"

/*******************************************************************************
Module data types 
*******************************************************************************/
typedef struct
{
   int16_t filterParam;
   int16_t adcToVoltageInternalUnits;
}tmcVol_Parameters_s;

typedef struct
{
    int16_t dcLinkVoltage;
}tmcVol_StateVariables_s;

/*******************************************************************************
Global variables 
*******************************************************************************/
   
/*******************************************************************************
 Private variables 
 *******************************************************************************/
static tmcVol_InputPorts_s mcVol_InputPorts_mas[1u];
static tmcVol_OutputPorts_s mcVol_OutputPorts_mas[1u];
static tmcVol_Parameters_s mcVol_Parameters_mas[1u];

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
tmcVol_ConfigParameters_s mcVolI_ConfigurationParameters_gds = VOLTAGE_MEASUREMENT_MODULE;


/*******************************************************************************
 Private Functions 
 *******************************************************************************/

/*******************************************************************************
 * Interface functions
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
void  mcVolI_VoltageCalculationInit( tmcVol_ConfigParameters_s * volParam )
{
    /* Check if configuration parameters does not point to NULL */
    ASSERT(( NULL != volParam), "Configuration parameters points to NULL");
    
    /* Check if input ports are initialized properly */
    ASSERT( (  NULL != volParam->inPort.sensorInput ) , "Input Ports are not assigned" );
    
    mcVol_InputPorts_mas[volParam->Id] = volParam->inPort;
    
     /* Check if output ports are initialized properly */
     ASSERT(((  NULL != volParam->outPort.busVoltage ) && ( NULL != volParam->outPort.filteredBusVoltage ) ),
                      "Output Ports are not assigned");
    
     mcVol_OutputPorts_mas[volParam->Id] = volParam->outPort;
     
     /* Update and calculate independent and dependent parameters respectively */
     mcVol_Parameters_mas[volParam->Id].filterParam = volParam->userParam.busVoltageFiltParam;
     mcVol_Parameters_mas[volParam->Id].adcToVoltageInternalUnits  = KAD_VOL;
}



/*! \brief Measure bus voltage  
 * 
 * Details.
 * Measure bus voltage  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcVolI_VoltageCalculationRun( const tmcVol_InstanceId_e Id )
#else
void mcVolI_VoltageCalculationRun( const tmcVol_InstanceId_e Id )
#endif
{
    int32_t s32a;
    
     /* Scale the DC bus voltage to Q14 internal units  */
  #if(0 != SH_KAD_VOL)
    s32a   = (int32_t)(*mcVol_InputPorts_mas[Id].sensorInput); 
    s32a *=  (int32_t)(  mcVol_Parameters_mas[Id].adcToVoltageInternalUnits);
    s32a >>= SH_KAD_VOL;
  #else 
    s32a   = (int32_t)(*mcVol_InputPorts_mas[Id].sensorInput); 
    s32a *=  (int32_t)(  mcVol_Parameters_mas[Id].adcToVoltageInternalUnits);
  #endif
   *mcVol_OutputPorts_mas[Id].busVoltage = (int16_t)s32a; 
   
   s32a *=  ONEBYSQRT3; 
   s32a >>= SH_BASE_VALUE;
    
   *mcVol_OutputPorts_mas[Id].maximumUacPeak = (int16_t)s32a;
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
void mcVolI_VoltageCalculationReset( const tmcVol_InstanceId_e Id )
{
    *mcVol_OutputPorts_mas[Id].busVoltage = 0;
    *mcVol_OutputPorts_mas[Id].filteredBusVoltage = 0;
    *mcVol_OutputPorts_mas[Id].maximumUacPeak = 0;
}