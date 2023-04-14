/*******************************************************************************
  System Definitions

  File Name:
    mc_flying_start.h

  Summary:
    Header file which contains variables and function prototypes for flying start
 
  Description:
    This file contains variables and function prototypes which are generally used for flying
    start.

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

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
}tmcFly_Parameters_s;

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
extern tmcFly_Parameters_s mcFlyI_Parameters_gds;

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
__STATIC_INLINE void mcFlyI_ParameterSet( tmcFly_Parameters_s * const pParameters )
{

}

/*******************************************************************************
 Interface Functions 
*******************************************************************************/
/*! \brief Initialize flying Start module
 *
 * Details.
 * Initialize flying Start module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlyI_FlyingStartInit( tmcFly_Parameters_s * const pParameters );

/*! \brief Enable flying Start module
 *
 * Details.
 * Enable flying Start module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlyI_FlyingStartEnable( tmcFly_Parameters_s * const pParameters );

/*! \brief Disable flying Start module
 *
 * Details.
 * Disable flying Start module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcFlyI_FlyingStartDisable( tmcFly_Parameters_s * const pParameters );

/*! \brief Flying Start
 *
 * Details.
 * Flying Start
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlyI_FlyingStart( const tmcFly_Parameters_s * const pParameters  );
#else
void mcFlyI_FlyingStart( const tmcFly_Parameters_s * const pParameters );
#endif

/*! \brief Reset Flying Start
 *
 * Details.
 * Reset Flying Start
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return:
 */
void mcFlyI_FlyingStartReset( const tmcFly_Parameters_s * const pParameters );

#endif // MCFLY_H
