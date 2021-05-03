/*******************************************************************************
  System Definitions

  File Name:
    mc_flux_control.h

  Summary:
    Header file which contains variables and function prototypes to control the flux
    component of current for FOC. 

  Description:
    This file contains variables and function prototypes which are generally
    used in to control the flux component of current for FOC. It is implemented in Q2.14
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

#ifndef MCFLX_H
#define MCFLX_H

#include <stdint.h>
#include <stdlib.h>
#include <sys/attribs.h>
#include "mc_generic_library.h"
#include "mc_error_handler.h"
#include "mc_interface_handling.h"
#include "mc_userparams.h"

/*******************************************************************************
 * Constants
*******************************************************************************/
/**
 * Maximum negative field weakening current
 */
#define MAXIMUM_NEGATIVE_FW_CURRENT (float)(${MCPMSMFOC_MAX_FW_CURRENT} )

/*******************************************************************************
 Default Module configuration parameters 
*******************************************************************************/
#define FLUX_CONTROL_MODULE_CONFIG {\
   /* Identifier */\
   0u,\
   /* Input Ports */\
   {\
      &mcMocI_DQVoltage_gds.direct,\
      &mcSpeI_ReferenceIqCurrent_gds16,\
      &mcRpoI_ElectricalRotorSpeed_gds16,\
      &mcVolI_UacPeakVoltage_gds16, \
      &mcRpoI_BackEmfMagnitude_gds16\
   },\
   \
   /* Output Ports */\
   {\
      &mcSpeI_ReferenceIdCurrent_gds16 \
   },\
   \
   /* User parameters  */\
   {\
      MOTOR_PER_PHASE_RESISTANCE_IN_OHM,\
      QUADRATURE_AXIS_INDUCTANCE_IN_HENRY,\
      DIRECT_AXIS_INDUCTANCE_IN_HENRY,\
      MOTOR_BEMF_CONST_VOLTS_PER_KRPM_MECH,\
      NUM_POLE_PAIRS,\
      MAXIMUM_NEGATIVE_FW_CURRENT\
   }\
}

/*******************************************************************************
 * User defined data-structure  
*******************************************************************************/
typedef struct tmcFlx_InputPorts_s
{ 
    int16_t  * Ud;
    int16_t  * iq;
    int16_t  * Wr;
    int16_t  * Udmax;
    int16_t * Es;
}tmcFlx_InputPorts_s;

typedef struct tmcFlx_OutputPorts_s
{
    int16_t  * idref;
}tmcFlx_OutputPorts_s;

typedef struct tmcFlx_UserParameters_s
{
    float Rs;
    float Ld;
    float Lq;
    float Ke;
    float Zp;
    float Idmin;
}tmcFlx_UserParameters_s;

typedef struct tmcFlx_ConfigParameters_s
{
    /* Identifier */
    uint8_t Id;
    
    /* Input Ports */
    tmcFlx_InputPorts_s inPort;
    
    /* Output Ports */
    tmcFlx_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcFlx_UserParameters_s userParam;    
}tmcFlx_ConfigParameters_s;

/*******************************************************************************
 * Interface Variables   
*******************************************************************************/
extern tmcFlx_ConfigParameters_s  mcFlxI_ConfigParameters_gds;

/*******************************************************************************
 * Interface Functions  
*******************************************************************************/

/*! \brief Initialize flux control 
 * 
 * Details.
 * Initialize flux control  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcFlxI_FluxControlInit(  tmcFlx_ConfigParameters_s * flxParam );


/*! \brief Execute Flux control 
 * 
 * Details.
 * Execute flux control 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

#ifdef RAM_EXECUTE
void __ramfunc__  mcFlxI_FluxControlRun( uint8_t Id  );
#else
void mcFlxI_FluxControlRun( uint8_t Id  );
#endif


/*! \brief Reset Flux control
 * 
 * Details.
 * Reset Flux control
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFlx_FluxControlReset(  uint8_t Id );

#endif // _MCFLX_H
