/*******************************************************************************
  PMSM_FOC App interface file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pmsm_foc.c

  Summary:
    This file contains functions to initialize the motor control
    peripherals and interface functions to control the motor.

  Description:
  This file contains functions to initialize the motor control
  peripherals and interface functions to control the motor.

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
 File inclusions
 *******************************************************************************/
#include "mc_error_handler.h"
#include "mc_pmsm_foc.h"
#include "mc_function_coordinator.h"

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
void PMSM_FOC_Initialize( void )
{   
    mcFcoI_ApplicationInit();
}


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
void PMSM_FOC_MotorStartStop(void)
{
    mcMocI_M1StartStop();
}

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
void PMSM_FOC_MotorStart(void)
{
    mcMocI_M1Start();
}

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
void PMSM_FOC_MotorStop(void)
{
    mcMocI_M1Stop();
}

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
void PMSM_FOC_DirectionToggle(void)
{
    mcMocI_M1DirectionToggle();
}

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
void PMSM_FOC_MotorSpeedSet(void)
{
  
}

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
void PMSM_FOC_MotorSpeedGet(void)
{
  
}


/*! \brief Configure thread tasks 
 * 
 * Details.
 * Configure thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void PMSM_FOC_ThreadTasksConfig(void)
{
    
}

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
void PMSM_FOC_ThreadTasksRun(void)
{
    mcFcoI_ThreadTasksRun();
}
