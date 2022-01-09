/*******************************************************************************
 PMSM_FOC App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pmsm_foc.h

  Summary:
    Header file for PMSM_FOC APP

  Description:
    This file contains the data structures and function prototypes used by
    PMSM FOC module.
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

#ifndef PMSM_FOC_H    // Guards against multiple inclusion
#define PMSM_FOC_H

/*******************************************************************************
 Header File inclusions 
 *******************************************************************************/

#include <stddef.h>
#include "mc_interface_handling.h"

/*******************************************************************************
 User data types 
 *******************************************************************************/

/*******************************************************************************
 Private variables 
 *******************************************************************************/

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Application initialization 
 * 
 * Details.
 * Application initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_Initialize( void );

/*! \brief Motor start-stop function 
 * 
 * Details.
 * Motor start-stop function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_MotorStartStop(void);

/*! \brief Motor start function 
 * 
 * Details.
 * Motor start function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_MotorStart(void);

/*! \brief Motor stop function 
 * 
 * Details.
 * Motor stop function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_MotorStop(void);

/*! \brief Motor direction toggle 
 * 
 * Details.
 * Motor direction toggle
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_DirectionToggle(void);

/*! \brief Motor speed set 
 * 
 * Details.
 * Motor speed set
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_MotorSpeedSet(void);

/*! \brief Motor speed get 
 * 
 * Details.
 * Motor speed get
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_MotorSpeedGet(void);

/*! \brief Run thread tasks 
 * 
 * Details.
 * Run thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_ThreadTasksRun(void);

#endif //PMSM_FOC_H

/**
 End of File
*/
