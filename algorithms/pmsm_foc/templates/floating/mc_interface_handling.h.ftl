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

#ifndef MCINF_H_    // Guards against multiple inclusion
#define MCINF_H_

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef struct _tmcInf_ThreePhaseQuantity_s
{
    float a;
    float b;
    float c;
}tmcInf_ThreePhaseQuantity_s;

typedef struct
{
    float alpha;
    float beta;
}tmcLib_ClarkTransform_s;

typedef struct
{
    float direct;
    float quadrature;
}tmcLib_ParkTransform_s;

typedef enum
{
#ifdef ENABLE_FLYING_START
    mcState_FlyingStart,
#endif
    mcState_Startup,
    mcState_Foc,
    mcState_Idle,
    mcState_Error
}tmcMoc_ControlStates_e;

typedef enum _tStd_ReturnType_e
{
    returnType_Running = 0x0,
    returnType_Passed = 0x1u ,
    returnType_Failed = 0x2u,
    returnType_Aborted = 0x4u,
}tStd_ReturnType_e;

/*******************************************************************************
 Interface variables 
 *******************************************************************************/

/* Analog interfaces */
extern uint16_t mcHalI_PhaseACurrent_gdu16;
extern uint16_t mcHalI_PhaseBCurrent_gdu16;
extern uint16_t mcHalI_DcBusVoltage_gdu16;
extern uint16_t mcHalI_Potentiometer_gdu16;

/* Voltage calculation module interface */
extern float mcVolI_DcBusVoltage_gaf32[1u];
extern float mcVolI_UacPeakVoltage_gaf32[1u];
extern float mcVolI_DcBusVoltageFilt_gaf32[1u];

/* Speed regulation module */
extern float mcSpeI_ReferenceElectricalSpeed_gaf32[1u];
extern float mcSpeI_FeedbackSpeed_gaf32[1u];

/* Current calculation module */
extern tmcInf_ThreePhaseQuantity_s mcCurI_PhaseCurrents_gas[1u];
extern uint8_t mcCurI_CurrentOffsetCalibDone_gau8[1u];

/* Rotor position calculation module */
extern float mcRpoI_MechanicalRotorPosition_gaf32[1u];
extern float mcRpoI_ElectricalRotorPosition_gaf32[1u];
extern float mcRpoI_ElectricalRotorSpeed_gaf32[1u];
extern float mcRpoI_ElectricalRotorAccel_gaf32[1u];
extern float mcRpoI_BackEMF_gaf32[1u];

/* Speed Regulation module */
extern float mcSpeI_ReferenceIqCurrent_gaf32[1u];
extern float mcSpeI_ReferenceIdCurrent_gaf32[1u];

/* Current Regulation module */
extern float mcRegI_UdReferenceVoltage_gaf32[1u];
extern float mcRegI_UqReferenceVoltage_gaf32[1u];

/* Motor Control module */
extern int8_t mcMocI_RotationSign_gas8[1u];
extern float mcMocI_SpaceVectorAngle_gaf32[1u];
extern tmcLib_ClarkTransform_s mcMocI_FeedbackAlphaBetaCurrent_gas[1u];
extern tmcLib_ClarkTransform_s mcMocI_AlphaBetaVoltage_gas[1u];
extern tmcLib_ParkTransform_s mcMocI_FeedbackDQCurrent_gas[1u];
extern tmcLib_ParkTransform_s mcMocI_DQVoltage_gas[1u];
extern tmcMoc_ControlStates_e mcMocI_MotorRunningState_gae[1u];

/* Position Control module */
extern float mcPosI_ReferenceElectricalPosition_gaf32[1u];

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'> 
/* Start-up module */
extern uint8_t mcSupI_RotorFieldAlignmentStatus_gdu8;
</#if>

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*******************************************************************************
 User defined data-types 
 *******************************************************************************/
#endif //MCINF_H_

/**
 End of File
*/
