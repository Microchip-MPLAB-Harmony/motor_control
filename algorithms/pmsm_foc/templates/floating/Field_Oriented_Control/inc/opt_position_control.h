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

#ifndef MCPOS_H
#define MCPOS_H

/*******************************************************************************
 * Header inclusions 
*******************************************************************************/
#include "mc_types.h"
#include "mc_pi_control.h"

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
     float32_t dt;
     void * pStatePointer;
}tmcPos_Parameters_s;

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
__STATIC_INLINE void mcPosI_ParametersSet( tmcPos_Parameters_s * const pParameters )
{
   pParameters->Kp = (float32_t)${MCPMSMFOC_POSITION_PID_KP};
   pParameters->Ki = (float32_t)${MCPMSMFOC_POSITION_PID_KI};
   pParameters->dt = (float32_t)${MCPMSMFOC_POSITION_PID_KC};
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
void  mcPosI_PositionControlInit( tmcPos_Parameters_s * const pParameters );

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
void  mcPosI_PositionControlEnable( tmcPos_Parameters_s * const pParameters );

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
void  mcPosI_PositionControlDisable( tmcPos_Parameters_s * const pParameters );

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
void mcPosI_PositionControlManual(  const tmcPos_Parameters_s * const pParameters,
                                                         const float32_t  Out );

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
void mcPosI_PositionControlAuto(  const tmcPos_Parameters_s * const pParameters,
                                              const float32_t nref, const  float32_t nact, float32_t * const pOut );

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
void mcPosI_PositionControlReset( const tmcPos_Parameters_s * const pParameters );

#endif // mcPos_H
