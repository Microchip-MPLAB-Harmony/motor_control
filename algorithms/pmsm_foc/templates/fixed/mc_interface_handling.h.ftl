/*******************************************************************************
 Interface handling header file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_interface_handling.h

  Summary:
   Interface handling header file 

  Description:
  Interface handling header file 
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

#ifndef MCINF_H    // Guards against multiple inclusion
#define MCINF_H

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include <stddef.h>
#include "definitions.h"

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef struct _tmcInf_ThreePhaseQuantity_s
{
    int16_t a;
    int16_t b;
    int16_t c;
}tmcInf_ThreePhaseQuantity_s;

typedef struct
{
    int16_t alpha;
    int16_t beta;
}tmcLib_ClarkTransform_s;

typedef struct
{
    int16_t direct;
    int16_t quadrature;
}tmcLib_ParkTransform_s;

typedef enum _tStd_ReturnType_e
{
    returnType_Running,
    returnType_Passed,
    returnType_Failed,
    returnType_Aborted
}tStd_ReturnType_e;

typedef enum
{
    mcState_Startup,
    mcState_Foc,
    mcState_Idle,
    mcState_Error
}tmcMoc_ControlStates_e;

/*******************************************************************************
 Interface variables 
 *******************************************************************************/

/* Analog interfaces */
extern uint16_t mcHalI_PhaseACurrent_gdu16;
extern uint16_t mcHalI_PhaseBCurrent_gdu16;
extern uint16_t mcHalI_DcBusVoltage_gdu16;
extern uint16_t mcHalI_Potentiometer_gdu16;

/* Voltage calculation module interface */
extern int16_t mcVolI_DcBusVoltage_gds16;
extern int16_t mcVolI_UacPeakVoltage_gds16;
extern int16_t mcVolI_DcBusVoltageFilt_gds16;

/* Speed regulation module */
extern int16_t mcSpeI_ReferenceElectricalSpeed_gds16;
extern float mcSpeI_FeedbackSpeed_gdf32;

/* Current calculation module */
extern tmcInf_ThreePhaseQuantity_s mcCurI_PhaseCurrents_gds;
extern uint8_t mcCurI_CurrentOffsetCalibDone_gdu8;

/* Rotor position calculation module */
extern uint16_t mcRpoI_ElectricalRotorPosition_gdu16;
extern int16_t mcRpoI_ElectricalRotorSpeed_gds16;
extern int16_t mcRpoI_ElectricalRotorAccel_gds16;
extern int16_t mcRpoI_BackEmfMagnitude_gds16;

/* Speed Regulation module */
extern int16_t mcSpeI_ReferenceIqCurrent_gds16;
extern int16_t mcSpeI_ReferenceIdCurrent_gds16;

/* Current Regulation module */
extern float mcRegI_UdReferenceVoltage_gdf32;
extern float mcRegI_UqReferenceVoltage_gdf32;

/* Motor Control module */
extern int8_t mcMocI_RotationSign_gds8;
extern uint16_t mcMocI_SpaceVectorPosition_gdu16;
extern tmcLib_ClarkTransform_s mcMocI_FeedbackAlphaBetaCurrent_gds;
extern tmcLib_ClarkTransform_s mcMocI_AlphaBetaVoltage_gds;
extern tmcLib_ParkTransform_s mcMocI_FeedbackDQCurrent_gds;
extern tmcLib_ParkTransform_s mcMocI_DQVoltage_gds;
extern tmcMoc_ControlStates_e mcMocI_MotorRunningState_gde;

/* Position Control module */
extern float mcPosI_ReferenceElectricalPosition_gdf32;

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*******************************************************************************
 User defined data-types 
 *******************************************************************************/
#endif //_MCINF_H

/**
 End of File
*/
