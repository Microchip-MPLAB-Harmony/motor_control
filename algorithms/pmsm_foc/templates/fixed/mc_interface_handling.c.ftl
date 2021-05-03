/*******************************************************************************
 Motor control interface handling 

  Company:
   Motor control interface handling .

  File Name:
    mc_interface_handling.c

  Summary:
    This file contains motor control firmware interface handling functions 

  Description:
    The file contains motor control firmware interface handling functions 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
 Header file inclusions 
 *******************************************************************************/
#include <stdint.h>
#include "mc_interface_handling.h"

/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcSafe_UnsignedInt_s
{
    uint16_t primaryValue;
    uint16_t redundantValue;
    uint16_t maxValue;
    uint16_t minValue;
}tmcSafe_UnsignedInt_s;

//#define Read_Safely(interface) {if( interface.primaryValue == interface.redundantValue ) return interface.primaryValue;}
//#define Write_Safely( interface, value ) {                                                                                                                 
//                                                                      if(( value > interface.minValue ) && (value < interface.maxValue))          
//                                                                      {                                                                                                            
//                                                                           interface.primaryValue = value;   interface.redundantValue = value;  
//                                                                      }                                                                                                            
//                                                                  }
/*******************************************************************************
 Constants 
 *******************************************************************************/


/*******************************************************************************
 Private variables  
 *******************************************************************************/

/*******************************************************************************
 Interface variables  
 *******************************************************************************/

/*******************************************************************************
 Private Functions 
 *******************************************************************************/
/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
/* Analog interfaces */
uint16_t mcHalI_PhaseACurrent_gdu16;
uint16_t mcHalI_PhaseBCurrent_gdu16;
uint16_t mcHalI_DcBusVoltage_gdu16;
uint16_t mcHalI_Potentiometer_gdu16;

/* Voltage Calculation module */
int16_t mcVolI_DcBusVoltage_gds16;
int16_t mcVolI_UacPeakVoltage_gds16;
int16_t mcVolI_DcBusVoltageFilt_gds16;

/* Speed regulation module */
int16_t mcSpeI_ReferenceElectricalSpeed_gds16;
float mcSpeI_FeedbackSpeed_gdf32;

/* Current calculation module */
tmcInf_ThreePhaseQuantity_s mcCurI_PhaseCurrents_gds;
uint8_t mcCurI_CurrentOffsetCalibDone_gdu8;

/* Rotor position calculation module */
uint16_t mcRpoI_ElectricalRotorPosition_gdu16;
int16_t mcRpoI_ElectricalRotorSpeed_gds16;
int16_t mcRpoI_ElectricalRotorAccel_gds16;
int16_t mcRpoI_BackEmfMagnitude_gds16;

/* Speed Regulation module */
int16_t mcSpeI_ReferenceIqCurrent_gds16;
int16_t mcSpeI_ReferenceIdCurrent_gds16;

/* Current Regulation module */
float mcRegI_UdReferenceVoltage_gdf32;
float mcRegI_UqReferenceVoltage_gdf32;

/* Motor Control module */
int8_t mcMocI_RotationSign_gds8 = 1;
uint16_t mcMocI_SpaceVectorPosition_gdu16;
tmcLib_ClarkTransform_s mcMocI_FeedbackAlphaBetaCurrent_gds;
tmcLib_ClarkTransform_s mcMocI_AlphaBetaVoltage_gds;
tmcLib_ParkTransform_s mcMocI_FeedbackDQCurrent_gds;
tmcLib_ParkTransform_s mcMocI_DQVoltage_gds;
tmcMoc_ControlStates_e mcMocI_MotorRunningState_gde;

/* Position Control module */
float mcPosI_ReferenceElectricalPosition_gdf32;