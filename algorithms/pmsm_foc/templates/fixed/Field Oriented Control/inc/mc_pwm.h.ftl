/*******************************************************************************
  System Definitions

  File Name:
    mc_pwm.h

  Summary:
    Header file which contains variables and function prototypes for pulse width modulation
 
  Description:
    This file contains variables and function prototypes which are generally used for pulse 
    width modulation. It is implemented in Q2.14 fixed Point Arithmetic.

 *******************************************************************************/

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

#ifndef MCPWM_H
#define MCPWM_H

/*******************************************************************************
 * Header inclusions 
*******************************************************************************/
#include "mc_types.h"
#include "mc_utilities.h"

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
/**
 * PWM period count
 */
#define CONFIG_PwmPeriodCount   (int16_t)3000

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
     uint16_t pwmPeriodCount;
     void * pStatePointer;
}tmcPwm_Parameters_s;

/*******************************************************************************
 * Interface variables 
*******************************************************************************/

/*******************************************************************************
 Static Interface Functions
*******************************************************************************/
/*! \brief Set module parameters
 *
 * Details.
 * Set module parameters
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
__STATIC_INLINE void mcPwmI_ParametersSet( tmcPwm_Parameters_s * const pParameters )
{
     pParameters->pwmPeriodCount = CONFIG_PwmPeriodCount;
}

/*******************************************************************************
 Interface Functions 
*******************************************************************************/
/*! \brief Initialize PWM modulator
 * 
 * Details.
 * Initialize PWM Modulator 
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
void  mcPwmI_PulseWidthModulationInit( tmcPwm_Parameters_s * const pParameters );

/*! \brief Enable PWM modulator
 *
 * Details.
 * Enable PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcPwmI_PulseWidthModulationEnable( tmcPwm_Parameters_s * const pParameters );

/*! \brief Disable PWM modulator
 *
 * Details.
 * Disable PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcPwmI_PulseWidthModulationDisable( tmcPwm_Parameters_s * const pParameters );

/*! \brief PWM Modulator
 *
 * Details.
 * PWM Modulator
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcPwmI_PulseWidthModulation( const tmcPwm_Parameters_s * const pParameters,
                                                                                const tmcTypes_AlphaBeta_s * const pUalphaBeta,
                                                                                int16_t * const pDuty );
#else
void mcPwmI_PulseWidthModulation( const tmcPwm_Parameters_s * const pParameters,
                                                           const tmcTypes_AlphaBeta_s * const pIalphaBeta,
                                                           int16_t * const pDuty );
#endif

/*! \brief Reset PWM Modulator
 * 
 * Details.
 * Reset PWM Modulator
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcPwmI_PulseWidthModulationReset( const tmcPwm_Parameters_s * const pParameters );

#endif // MCPWM_H
