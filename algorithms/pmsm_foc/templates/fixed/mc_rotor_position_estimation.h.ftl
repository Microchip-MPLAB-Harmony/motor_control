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

#ifndef MCRPE_H
#define MCRPE_H

/*******************************************************************************
 * Header inclusions 
*******************************************************************************/
#include "mc_types.h"
#include "mc_motor.h"
#include "mc_utilities.h"
#include "mc_userparams.h"

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef struct
{
/** Motor parameters */
     tmcMotor_PmsmParameters_s  * pMotorParameters;

     /** BEMF observer parameters */
     float32_t Ke;
     float32_t dt;
     float32_t nMin;
     void * pStatePointer;
}tmcRpe_Parameters_s;

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
__STATIC_INLINE void mcRpeI_ParametersSet( tmcRpe_Parameters_s * const pParameters )
{
     /** Motor parameters */
     pParameters->pMotorParameters = &mcMotor_MotorParameters_gds;
     /** BEMF observer parameters */
     pParameters->Ke = 0.007515f;
     pParameters->dt = 1.0f/ (float32_t)PWM_FREQUENCY;
     pParameters->nMin = 500.0f ;
}

/*******************************************************************************
 Interface Functions 
*******************************************************************************/
/*! \brief Initialize rotor position estimation module
 * 
 * Details.
 * Initialize rotor position estimation module
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
void  mcRpeI_RotorPositionEstimInit( tmcRpe_Parameters_s * const pParameters );

/*! \brief Enable rotor position estimation module
 *
 * Details.
 * Enable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpeI_RotorPositionEstimEnable( tmcRpe_Parameters_s * const pParameters );

/*! \brief Disable rotor position estimation module
 *
 * Details.
 * Disable rotor position estimation module
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
void  mcRpeI_RotorPositionEstimDisable( tmcRpe_Parameters_s * const pParameters );

/*! \brief Rotor position estimation
 *
 * Details.
 * Rotor position estimation
 *
 * @param[in]: None
 * @param[in/out]: None
 * @param[out]: None
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcRpeI_RotorPositionEstim( const tmcRpe_Parameters_s * const pParameters,
                                                                         const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                                         const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                                         uint16_t * pAngle, int16_t * pSpeed  );
#else
void mcRpeI_RotorPositionEstim(  const tmcRpe_Parameters_s * const pParameters,
                                                     const tmcTypes_AlphaBeta_s * pIAlphaBeta,
                                                     const tmcTypes_AlphaBeta_s * pUAlphaBeta,
                                                     uint16_t * pAngle, int16_t * pSpeed );
#endif

/*! \brief Reset Rotor position estimation
 * 
 * Details.
 * Reset Rotor position estimation
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcRpeI_RotorPositionEstimReset( const tmcRpe_Parameters_s * const pParameters );

#endif // MCRPE_H
