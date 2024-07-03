/*******************************************************************************
  Field Oriented control main source file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_field_oriented_control.c

  Summary:
    This file contains the state machine and control loop of the motor control
   algorithm.

  Description:
    This file contains the control loop of the PMSM FOC.
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

/*******************************************************************************
 Header File inclusions
 *******************************************************************************/
#include "mc_field_oriented_control.h"

/*******************************************************************************
 Constants
 *******************************************************************************/

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

/*******************************************************************************
 Private variables
 *******************************************************************************/

/*******************************************************************************
 Interface Variables
 *******************************************************************************/

/*******************************************************************************
 Private functions
 *******************************************************************************/

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
/**
 * @brief Enable Field Oriented Control (FOC) module
 *
 * @details Enables the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlEnable( void )
{
  /** Please note that the ports may vary depending on your specific model. 
      Please adjust as needed. */
  #if ( X2CMODEL_TYPE == FLOATING_POINT_F32_MODEL )
    x2cModel.inports.bSW1 = 1U;
  #endif

#if ( X2CMODEL_TYPE == FIXED_POINT_Q15_MODEL )
    x2cModel.inports.bSW1 = 1U;//INT16_MAX;
#endif
}

/**
 * @brief Disable Field Oriented Control (FOC) module
 *
 * @details Disables the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlDisable( void )
{
  /** Please note that the ports may vary depending on your specific model. 
      Please adjust as needed. */
    x2cModel.inports.bSW1 = 0U;
}

/**
 * @brief Initialize Field Oriented Control (FOC) module
 *
 * @details Initializes the FOC module.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlInit( void )
{
    /** Initialize FOC model */
    X2C_Initialize();
}

/**
 * @brief Execute Field Oriented Control (FOC) fast loop
 *
 * @details Executes the fast loop of the FOC algorithm.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlFast( void  )
{
    /** Read input ports */
    mcFoc_InputPortsRead();

    /** Execute FOC model */
    X2C_Update();

    /** Write output ports */
    mcFoc_OutputPortsWrite();
}


/**
 * @brief Execute Field Oriented Control (FOC) slow loop
 *
 * @details Executes the slow loop of the FOC algorithm.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlSlow( void  )
{
    /**ToDO */
}

/**
 * @brief Change motor direction
 *
 * @details Changes the direction of the motor.
 *
 * @param[in] pModule Pointer to the FOC module data
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_MotorDirectionChange( void )
{
  /** Please note that the ports may vary depending on your specific model. 
      Please adjust as needed. */

  #if ( X2CMODEL_TYPE == FLOATING_POINT_F32_MODEL )
    x2cModel.inports.bSW2 ^= 1U;
  #endif

#if ( X2CMODEL_TYPE == FIXED_POINT_Q15_MODEL )
    if( x2cModel.inports.bSW2 == 0U )
    {
        x2cModel.inports.bSW2 = INT16_MAX;
     }
    else
    {
        x2cModel.inports.bSW2 = 0U;
    }
#endif

}

/**
 * @brief Reset Field Oriented Control (FOC)
 *
 * @details Resets the FOC module.
 *
 * @param[in] pParameters Pointer to the FOC parameters
 * @param[in,out] None
 * @param[out] None
 * @return None
 */
void mcFocI_FieldOrientedControlReset(  void   )
{

}
