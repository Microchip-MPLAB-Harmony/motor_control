/*******************************************************************************
 Motor Control application interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_motor_control.h

  Summary:
    Motor control algorithm interface

  Description:
    This file contains the data structures and function prototypes of motor control loop.
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

#ifndef MC_MOC_H    // Guards against multiple inclusion
#define MC_MOC_H


/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "X2C_Utilities.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"
#include "X2C.h"

/*******************************************************************************
 User defined data-types
 *******************************************************************************/

/*******************************************************************************
 Interface variables
 *******************************************************************************/

/*******************************************************************************
 Static Functions
 *******************************************************************************/
static inline void mcFoc_InputPortsRead( void  )
{
   /** User code - Begin */

   /** User code - End */
}


static inline void mcFoc_OutputPortsWrite( void  )
{
   /** User code - Begin */

    /** User code - End */
}

/*******************************************************************************
 * Interface Functions
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
void mcFocI_FieldOrientedControlEnable( void );

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
void mcFocI_FieldOrientedControlDisable( void );

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
void mcFocI_FieldOrientedControlInit( void  );

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

void mcFocI_FieldOrientedControlFast( void  );

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

void mcFocI_FieldOrientedControlSlow( void  );

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
void mcFocI_MotorDirectionChange( void );

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
void mcFocI_FieldOrientedControlReset( void );

#endif //MC_MOC_H

/**
 End of File
*/
