/*******************************************************************************
  System Definitions

  File Name:
    mc_torque_control.h

  Summary:
    Header file which contains variables and function prototypes for torque control
 
  Description:
    This file contains variables and function prototypes which are generally used for
    torque control.

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

#ifndef MCTOR_H
#define MCTOR_H

/*******************************************************************************
 * Header inclusions 
*******************************************************************************/
#include "mc_types.h"
#include "mc_pi_control.h"
#include  "mc_userparams.h"

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define CURRENT_LOOP_KP_   0.6f
#define CURRENT_LOOP_KI_   50.0f

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
     float32_t Kp;
     float32_t Ki;
     float32_t dt;
     void * pStatePointer;
}tmcTor_Parameters_s;

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
//#define RAM_EXECUTE

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
__STATIC_INLINE void mcTorI_ParametersSet( tmcTor_Parameters_s * const pParameters )
{
#if defined ENABLE_AUTO_TUNING
/** ToDO: */
#else
   pParameters->Kp = CURRENT_LOOP_KP_;
   pParameters->Ki = CURRENT_LOOP_KI_;
   pParameters->dt = 1.0f/ (float32_t)PWM_FREQUENCY;
#endif
}

/*******************************************************************************
 Interface Functions 
*******************************************************************************/
/*! \brief Initialize flux control module
 *
 * Details.
 * Initialize flux control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcTorI_TorqueControlInit( tmcTor_Parameters_s * const pParameters );

/*! \brief Enable flux control module
 *
 * Details.
 * Enable flux control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcTorI_TorqueControlEnable( tmcTor_Parameters_s * const pParameters );

/*! \brief Disable flux control module
 *
 * Details.
 * Disable flux control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcTorI_TorqueControlDisable( tmcTor_Parameters_s * const pParameters );

/*! \brief Torque control
 *
 * Details.
 * Torque control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcTorI_TorqueControlManual( const tmcTor_Parameters_s * const pParameters,
                                                                   const int16_t Out   );
#else
void mcTorI_TorqueControlManual(  const tmcTor_Parameters_s * const pParameters,
                                                         const int16_t  Out );
#endif

/*! \brief Torque control
 *
 * Details.
 * Torque control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcTorI_TorqueControlAuto( const tmcTor_Parameters_s * const pParameters,
                                                                   const int16_t iQref, const int16_t iQact, int16_t * const pOut   );
#else
void mcTorI_TorqueControlAuto(  const tmcTor_Parameters_s * const pParameters,
                                              const int16_t iQref, const int16_t iQact, int16_t * const pOut );
#endif

/*! \brief Reset Torque control
 *
 * Details.
 * Reset Torque control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcTorI_TorqueControlReset( const tmcTor_Parameters_s * const pParameters );

#endif // MCTOR_H
