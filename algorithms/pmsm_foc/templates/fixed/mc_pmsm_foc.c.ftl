/*******************************************************************************
 Motor Control Application Source file 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pmsm_foc.c

  Summary:
    This file contains all the functions related to motor control application

  Description:
    This file contains implementation of the application state machine
 
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
Headers inclusions
*******************************************************************************/
#include "mc_pmsm_foc.h"
#include "mc_motor_control.h"
#include "mc_function_coordinator.h"

/*******************************************************************************
Interface Functions
*******************************************************************************/
/*! \brief Motor Control functions initialization 
 *  
 *  Details.
 *  Initializes software components for PMSM motor control function 
 
 */
void PMSM_FOC_Initialize( void )
{
     /* Initialize application */
     mcFcoI_ApplicationInit( );
}


/*! \brief Main loop tasks 
 *  
 *  Details.
 *  Main Loop tasks  
 
 */
void PMSM_FOC_Tasks( void )
{
     /* Initialize application */
     mcFcoI_ThreadTasksRun( );
}

/*! \brief Start motor
 *  
 *  Details.
 *  Interface to start the motor
 
 */
void PMSM_FOC_MotorStart( void )
{
    mcMocI_MotorStart();
}

/*! \brief Motor stop
 *  
 *  Details.
 *  Interface function to stop the motor.
 
 */
void PMSM_FOC_MotorStop( void )
{
    mcMocI_MotorStop();
}

