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
float mcVolI_DcBusVoltage_gaf32[1u];
float mcVolI_UacPeakVoltage_gaf32[1u];
float mcVolI_DcBusVoltageFilt_gaf32[1u];

/* Speed regulation module */
float mcSpeI_ReferenceElectricalSpeed_gaf32[1u];
float mcSpeI_FeedbackSpeed_gaf32[1u];

/* Current calculation module */
tmcInf_ThreePhaseQuantity_s mcCurI_PhaseCurrents_gas[1u];
uint8_t mcCurI_CurrentOffsetCalibDone_gau8[1u];

/* Rotor position calculation module */
float mcRpoI_MechanicalRotorPosition_gaf32[1u];
float mcRpoI_ElectricalRotorPosition_gaf32[1u];
float mcRpoI_ElectricalRotorSpeed_gaf32[1u];
float mcRpoI_ElectricalRotorAccel_gaf32[1u];
float mcRpoI_BackEMF_gaf32[1u];

/* Speed Regulation module */
float mcSpeI_ReferenceIqCurrent_gaf32[1u];
float mcSpeI_ReferenceIdCurrent_gaf32[1u];

/* Current Regulation module */
float mcRegI_UdReferenceVoltage_gaf32[1u];
float mcRegI_UqReferenceVoltage_gaf32[1u];

/* Motor Control module */
int8_t mcMocI_RotationSign_gas8[1u];
float mcMocI_SpaceVectorAngle_gaf32[1u];
tmcLib_ClarkTransform_s mcMocI_FeedbackAlphaBetaCurrent_gas[1u];
tmcLib_ClarkTransform_s mcMocI_AlphaBetaVoltage_gas[1u];
tmcLib_ParkTransform_s mcMocI_FeedbackDQCurrent_gas[1u];
tmcLib_ParkTransform_s mcMocI_DQVoltage_gas[1u];
tmcMoc_ControlStates_e mcMocI_MotorRunningState_gae[1u];
uint8_t mcMocI_RunningStatus_gde[1u];

/* Position Control module */
float mcPosI_ReferenceElectricalPosition_gaf32[1u];

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'> 
/* Start-up module */
uint8_t mcSupI_RotorFieldAlignmentStatus_gdu8 = 0u;
</#if>