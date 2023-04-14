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

#ifndef MCREF_H
#define MCREF_H

/*******************************************************************************
 * Header inclusions 
*******************************************************************************/
#include "mc_types.h"
#include "mc_userparams.h"

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
#if( ENABLE == ENABLE_SPEED_CONTROL )
    float32_t minimumRpm;
    float32_t maximumRpm;
    float32_t rpmPerSeccond;
    float32_t dt;
#endif
    void * pStatePointer;
}tmcRef_Parameters_s;

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
__STATIC_INLINE void mcRefI_ParametersSet( tmcRef_Parameters_s * const pParameters )
{
#if( ENABLE == ENABLE_SPEED_CONTROL )
    pParameters->minimumRpm = 500.0f;
    pParameters->maximumRpm = 2804.0f;
    pParameters->rpmPerSeccond = 100.0f;
    pParameters->dt = ( 1.0f / (float)PWM_FREQUENCY );
#endif
}

/*******************************************************************************
 Interface Functions 
*******************************************************************************/
/*! \brief Initialize reference control module
 * 
 * Details.
 * Initialize reference control module
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
void  mcRefI_ReferenceControlInit( tmcRef_Parameters_s * const pParameters );

/*! \brief Enable reference control module
 *
 * Details.
 * Enable reference control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRefI_ReferenceControlEnable( tmcRef_Parameters_s * const pParameters );

/*! \brief Disable reference control module
 *
 * Details.
 * Disable reference control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRefI_ReferenceControlDisable( tmcRef_Parameters_s * const pParameters );

/*! \brief Reference control
 *
 * Details.
 * Reference control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcRefI_ReferenceControl( tmcRef_Parameters_s * const pParameters,
                                                                       const int16_t command, int16_t * const pOut   );
#else
void mcRefI_ReferenceControl(  tmcRef_Parameters_s * const pParameters,
                                                    const int16_t command, int16_t * const pOut );
#endif

/*! \brief Reset Reference control
 * 
 * Details.
 * Reset Reference control
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcRefI_ReferenceControlReset( tmcRef_Parameters_s * const pParameters );

#endif // MCREF_H
