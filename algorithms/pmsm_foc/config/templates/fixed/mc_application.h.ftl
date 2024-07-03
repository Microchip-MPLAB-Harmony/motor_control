/**
 * @file application.h
 *
 * @brief 
 *   Application Header file
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *   Header file defining application-specific details.
 *
 * @Description
 *   This header file provides definitions and structures specific to the application,
 *   including configuration settings, function prototypes, and any other necessary details.
 */

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

#ifndef MCAPP_H    // Guards against multiple inclusion
#define MCAPP_H

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "definitions.h"
#include "mc_field_oriented_control.h"
#include "mc_current_calculation.h"

/*******************************************************************************
 Private data-types
 *******************************************************************************/

/*******************************************************************************
 * Interface variables
 *******************************************************************************/

/*******************************************************************************
 Interface Functions
 *******************************************************************************/

/**
 * @brief Application initialization
 *
 * @details Initializes the application.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_ApplicationInit(void);

/**
 * @brief Over current reaction ISR
 *
 * @details Interrupt service routine for over current reaction.
 *
 * @param[in] status Status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
void mcAppI_OverCurrentReactionIsr(uint32_t status, uintptr_t context);

/**
 * @brief Motor control application calibration ISR
 *
 * @details Interrupt service routine for motor control application calibration.
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
void mcAppI_AdcCalibrationIsr(ADC_STATUS status, uintptr_t context);

/**
 * @brief ADC finished ISR
 *
 * @details Interrupt service routine for ADC finished tasks.
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
#ifdef RAM_EXECUTE
void __ramfunc__ mcAppI_AdcFinishedIsr(ADC_STATUS status, uintptr_t context);
#else
void mcAppI_AdcFinishedIsr(ADC_STATUS status, uintptr_t context);
#endif

/**
 * @brief Non-ISR tasks execution
 *
 * @details Executes non-interrupt service routine tasks.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_NonISRTasks(void);

/**
 * @brief Application reset
 *
 * @details Resets the application.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_ApplicationReset(void);


#endif //MCAPP_H

/**
 End of File
*/
