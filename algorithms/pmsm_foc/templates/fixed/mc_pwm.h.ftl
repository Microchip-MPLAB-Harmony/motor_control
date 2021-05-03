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

#ifndef MCPWM_H
#define MCPWM_H
/*******************************************************************************
 * Header inclusions 
*******************************************************************************/
#include <stdint.h>
#include <sys/attribs.h>
#include "mc_generic_library.h"
#include "mc_hardware_abstraction.h"
#include "mc_interface_handling.h"
#include "mc_error_handler.h"

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define PWM_MODULE_CONFIG {\
    pwmModuleInstance_01,\
    {\
        &mcVolI_DcBusVoltage_gds16, &mcMocI_AlphaBetaVoltage_gds \
    }\
}

/*******************************************************************************
Type Definition
*******************************************************************************/
typedef enum _tmcPwm_InstanceId_e
{
    pwmModuleInstance_01,
    pwmModuleInstance_02,
    pwmModuleInstance_max 
}tmcPwm_InstanceId_e;

typedef struct 
{
    int16_t      * Ubus;
    tmcLib_ClarkTransform_s  * Uab;
}tmcPwm_InputPorts_s;

typedef struct _tmcPwm_UserParameters_s 
{
   
}tmcPwm_UserParameters_s;



typedef struct 
{
    uint32_t dutyCycle[3];
}tmcPwm_OutputPorts_s;


typedef struct _tmcPwm_ConfigParameters_s 
{
    /* Instance Id */
    tmcPwm_InstanceId_e Id; 
    
    /* Input port */
    tmcPwm_InputPorts_s     inPort;
    
    /* User Parameter */
   // tmcPwm_UserParameters_s   userParam;
        
}tmcPwm_ConfigParameters_s;

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
extern tmcPwm_ConfigParameters_s mcPwmI_ConfigParameters_gds;
/*******************************************************************************
 Interface Functions 
*******************************************************************************/

/* !\brief Initialize PWM Modulator  
 * 
 * Details.
 * Initialize PWM Modulator 
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
extern void mcPwmI_PulseWidthModulationInit(const tmcPwm_ConfigParameters_s * const pwmConfigParam);



/* !\brief Reset PWM Modulator  
 * 
 * Details.
 * Reset PWM Modulator 
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
void mcPwmI_PulseWidthModulationReset(const tmcPwm_InstanceId_e Id);


/* !\brief  PWM Modulator  
 * 
 * Details.
 *  PWM Modulator 
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: 
 */
#ifdef RAM_EXECUTE
void  __ramfunc__ mcPwmI_PulseWidthModulationRun(const tmcPwm_InstanceId_e Id);
#else
void mcPwmI_PulseWidthModulationRun( const tmcPwm_InstanceId_e Id);
#endif

#endif // _MCPWM_H
