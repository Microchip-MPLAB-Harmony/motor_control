/*******************************************************************************
  System Definitions

  File Name:
    mc_function_coordinator.h

  Summary:
    Header file which contains variables and function prototypes to coordinate
    motor Control and PFC functions ( if enabled ).

  Description:
    This file contains variables and function prototypes which are generally
    used in to coordinate motor control functions. It is implemented in Q2.14
    fixed Point Arithmetic.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef MCFCO_H
#define MCFCO_H

/*******************************************************************************
 Header Inclusions
*******************************************************************************/
#include <stdint.h>
#include <sys/attribs.h>
#include "mc_motor_control.h"
#include "mc_voltage_measurement.h"
#include "mc_hardware_abstraction.h"
#include "mc_current_measurement.h"
#include "mc_hardware_abstraction.h"
#include "mc_interface_handling.h"




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
void mcFcoI_ApplicationInit( void );


/*! \brief Interrupt tasks execution 
 * 
 * Details.
 *  Interrupt tasks execution 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_InterruptTasksRun( void );


/*! \brief First Cycle interrupt task run 
 * 
 * Details.
 * First Cycle interrupt task run 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFco_1stCycleInterruptTasksRun( void );

/*! \brief Second Cycle interrupt task run 
 * 
 * Details.
 * Second Cycle interrupt task run 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFco_2ndCycleInterruptTasksRun( void );

/*! \brief Third Cycle interrupt task run 
 * 
 * Details.
 * Third Cycle interrupt task run 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFco_3rdCycleInterruptTasksRun( void );


/*! \brief Fourth Cycle interrupt task run 
 * 
 * Details.
 * Fourth Cycle interrupt task run 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFco_4thCycleInterruptTasksRun( void );

/*! \brief Motor control thread tasks  
 * 
 * Details.
 * Motor control thread tasks
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_ThreadTasksRun( void );

/*! \brief 1 ms thread tasks 
 * 
 * Details.
 * 1 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_1msThreadTasksRun( void );


/*! \brief 10 ms thread tasks 
 * 
 * Details.
 * 10 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_10msThreadTasksRun( void );


/*! \brief 100 ms thread tasks 
 * 
 * Details.
 * 100 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_100msThreadTasksRun( void );

/*! \brief 1000 ms thread tasks 
 * 
 * Details.
 * 1000 ms thread tasks 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_1000msThreadTasksRun( void );


/*! \brief Button polling
 * 
 * Details.
 * Button polling
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFcoI_ButtonPolling( void );

#endif //_MCFCO_H

/**
 End of File
*/
