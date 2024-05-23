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

/*! \brief  Field oriented control enable
 *
 * Details.
 *   Field oriented control enable
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFocI_FieldOrientedControlEnable( void )
{
  #if ( X2CMODEL_TYPE == FLOATING_POINT_F32_MODEL )
    x2cModel.inports.bS2 = 1U;
  #endif

#if ( X2CMODEL_TYPE == FIXED_POINT_Q15_MODEL )
    x2cModel.inports.bS2 = INT16_MAX;
#endif
}

/*! \brief  Field oriented control disable
 *
 * Details.
 *   Field oriented control disable
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFocI_FieldOrientedControlDisable( void )
{
    x2cModel.inports.bS2 = 0U;
}

/*! \brief  Field oriented control initialization
 *
 * Details.
 *   Field oriented control initialization
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFocI_FieldOrientedControlInit( void )
{
    /** Initialize FOC model */
    X2C_Initialize();
}

/*! \brief Field oriented control
 *
 * Details.
 *   Field oriented control
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
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


/*! \brief Field oriented control
 *
 * Details.
 *   Field oriented control
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcFocI_FieldOrientedControlSlow( void  )
{
    /**ToDO */
}

/*! \brief  Direction change
 *
 * Details.
 * Direction change
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFocI_MotorDirectionChange( void )
{
    x2cModel.inports.bS3 = x2cModel.inports.bS3 ^ 0U;
}

/*! \brief  Field oriented control reset
 *
 * Details.
 * Field oriented control reset
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFocI_FieldOrientedControlReset(  void   )
{

}
