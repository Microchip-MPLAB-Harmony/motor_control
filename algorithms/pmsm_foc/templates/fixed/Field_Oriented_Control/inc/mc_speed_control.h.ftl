/*******************************************************************************
  System Definitions

  File Name:
    mc_speed_control.h

  Summary:
    Header file which contains variables and function prototypes for speed control

  Description:
    This file contains variables and function prototypes which are generally used for speed
    control

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

#ifndef MCSPE_H
#define MCSPE_H

/*******************************************************************************
 * Header inclusions
*******************************************************************************/
#include "mc_types.h"
#include "mc_pi_control.h"
#include "mc_userparams.h"

/*******************************************************************************
 Default Module configuration parameters
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
     float32_t Kp;
     float32_t Ki;
     float32_t Ymax;
     float32_t dt;
     void * pStatePointer;
}tmcSpe_Parameters_s;

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
__STATIC_INLINE void mcSpeI_ParametersSet( tmcSpe_Parameters_s * const pParameters )
{
    pParameters->Kp = (float32_t)${MCPMSMFOC_SPEED_PID_KP};
    pParameters->Ki = (float32_t)${MCPMSMFOC_SPEED_PID_KI};
    pParameters->dt = (float32_t)(${MCPMSMFOC_PWM_PERIOD});
    pParameters->Ymax = (float32_t)${MCPMSMFOC_MAX_MOTOR_CURRENT};
}

/*******************************************************************************
 Interface Functions
*******************************************************************************/
/*! \brief Initialize speed control module
 *
 * Details.
 * Initialize speed control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSpeI_SpeedControlInit( tmcSpe_Parameters_s * const pParameters );

/*! \brief Enable speed control module
 *
 * Details.
 * Enable speed control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSpeI_SpeedControlEnable( tmcSpe_Parameters_s * const pParameters );

/*! \brief Disable speed control module
 *
 * Details.
 * Disable speed control module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcSpeI_SpeedControlDisable( tmcSpe_Parameters_s * const pParameters );

/*! \brief Speed control
 *
 * Details.
 * Speed control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcSpeI_SpeedControlManual( const tmcSpe_Parameters_s * const pParameters,
                                                                   const int16_t Out   );
#else
void mcSpeI_SpeedControlManual(  const tmcSpe_Parameters_s * const pParameters,
                                                         const int16_t  Out );
#endif

/*! \brief Speed control
 *
 * Details.
 * Speed control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcSpeI_SpeedControlAuto( const tmcSpe_Parameters_s * const pParameters,
                                                                   const int16_t nref, const int16_t nact, int16_t * const pOut   );
#else
void mcSpeI_SpeedControlAuto(  const tmcSpe_Parameters_s * const pParameters,
                                              const int16_t nref, const  int16_t nact, int16_t * const pOut );
#endif

/*! \brief Reset Speed control
 *
 * Details.
 * Reset Speed control
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcSpeI_SpeedControlReset( const tmcSpe_Parameters_s * const pParameters );

#endif // MCSPE_H
