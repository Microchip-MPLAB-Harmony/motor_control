/**
 * @file mc_ipd.h
 *
 * @brief 
 *    System Definitions for Inverse Park Transform
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *    Header file containing variables and function prototypes for Inverse Park Transform.
 *
 * @Description
 *    This file defines variables and function prototypes typically used for
 *    implementing the Inverse Park Transform in motor control applications.
 */

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCIPD_H
#define MCIPD_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

/*******************************************************************************
 Header inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"
#include "mc_hardware_abstraction.h"
#include "mc_key_manager.h"


/*******************************************************************************
 Macros
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

typedef struct
{
   float32_t iA;      /*!< Phase A current */
   float32_t iB;      /*!< Phase B current */
   float32_t iC;      /*!< Phase C current */
   float32_t uBus;    /*!< DC bus voltage */
} tmcIpd_Input_s;

typedef struct
{
  float32_t uPulse;       /*!< Pulse amplitude */
  float32_t tPulse;       /*!< Pulse duration */
  float32_t tPeriod;      /*!< Pulse period */
  float32_t fsInHertz;    /*!< PWM frequency in Hertz */
  uint16_t  yPeriodCount; /*!< PWM period count */
} tmcIpd_Parameters_s;

typedef struct
{
   int16_t duty[3u];  /*!< PWM duty cycle array */
   float32_t phi;     /*!< Phase angle */
   bool ready;        /*!< Module readiness flag */
} tmcIpd_Output_s;

typedef struct
{
   tmcIpd_Input_s dInput;           /*!< Input structure */
   tmcIpd_Parameters_s dParameter;  /*!< Parameters structure */
   tmcIpd_Output_s dOutput;         /*!< Output structure */
   void * pStatePointer;            /*!< Pointer to module state */
} tmcIpd_ModuleData_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
extern tmcIpd_ModuleData_s mcIpdI_ModuleData_gds;  /*!< Global module data */

/*******************************************************************************
 Static functions
 *******************************************************************************/
/*******************************************************************************
 * Static functions
 ******************************************************************************/

/*! \brief Read input ports
 *
 * This function reads input ports and updates the input structure.
 *
 * @param[in] pInput Pointer to the input structure.
 * @return None
 */
__STATIC_INLINE void mcIpdI_InputPortsRead( tmcIpd_Input_s * const pInput )
{
     pInput->iA = mcCurI_ModuleData_gds.dOutput.iABC.a;
     pInput->iB = mcCurI_ModuleData_gds.dOutput.iABC.b;
     pInput->iC = mcCurI_ModuleData_gds.dOutput.iABC.c;

     pInput->uBus = mcVolI_ModuleData_gds.dOutput.uBus;
}

/*! \brief Write output ports
 *
 * This function writes output ports based on the output structure.
 *
 * @param[in] pOutput Pointer to the output structure.
 * @return None
 */
__STATIC_INLINE void mcIpdI_OutputPortsWrite( tmcIpd_Output_s * const pOutput )
{
    mcPwmI_Duty_gau16[0u] =  pOutput->duty[0u];
    mcPwmI_Duty_gau16[1u] =  pOutput->duty[1u];
    mcPwmI_Duty_gau16[2u] =  pOutput->duty[2u];
}

/*! \brief Set module parameters
 *
 * This function sets module parameters from predefined constants.
 *
 * @param[in] pParameter Pointer to the parameters structure.
 * @return None
 */
__STATIC_INLINE void mcIpdI_ParametersSet( tmcIpd_Parameters_s * const pParameter )
{
    pParameter->uPulse = (float32_t)(${MCPMSMFOC_IPD_PULSE_AMPLITUDE});
    pParameter->tPulse = (float32_t)(${MCPMSMFOC_IPD_PULSE_DURATION});
    pParameter->tPeriod = (float32_t)(${MCPMSMFOC_IPD_PULSE_PERIOD});
    pParameter->fsInHertz = (float32_t)(${MCPMSMFOC_PWM_FREQUENCY}u);
    pParameter->yPeriodCount = mcHalI_PwmPeriodGet();
}

/*******************************************************************************
 * Interface functions
 ******************************************************************************/

/*! \brief Enable initial position detection
 *
 * This function enables the initial position detection module.
 *
 * @param[in] pModule Pointer to the module data structure.
 * @return None
 */
void mcIpdI_InitialPositionDetectEnable(tmcIpd_ModuleData_s * const pModule);

/*! \brief Disable initial position detection
 *
 * This function disables the initial position detection module.
 *
 * @param[in] pModule Pointer to the module data structure.
 * @return None
 */
void mcIpdI_InitialPositionDetectDisable(tmcIpd_ModuleData_s * const pModule);

/*! \brief Initialize initial position detection
 *
 * This function initializes the initial position detection module.
 *
 * @param[in] pModule Pointer to the module data structure.
 * @return None
 */
void mcIpdI_InitialPositionDetectInit(tmcIpd_ModuleData_s * const pModule);

/*! \brief Perform initial position detection
 *
 * This function performs initial position detection.
 *
 * @param[in] pModule Pointer to the module data structure.
 * @return None
 */
void mcIpdI_InitialPositionDetect(tmcIpd_ModuleData_s * const pModule);

/*! \brief Reset initial position detection
 *
 * This function resets the initial position detection module.
 *
 * @param[in] pModule Pointer to the module data structure.
 * @return None
 */
void mcIpdI_InitialPositionDetectReset(tmcIpd_ModuleData_s *pModule);

#endif

#ifdef __cplusplus
}
#endif // MCIPD_H
