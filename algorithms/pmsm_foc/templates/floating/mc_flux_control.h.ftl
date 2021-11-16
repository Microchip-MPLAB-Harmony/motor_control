/*******************************************************************************
 PMSM Flux Regulation 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_flux_control.h

  Summary:
    Header file for PMSM flux regulation 

  Description:
 PMSM flux regulation 
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

#ifndef MCFLX_H    // Guards against multiple inclusion
#define MCFLX_H

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
#include <stddef.h>
#include "mc_generic_library.h"
#include "mc_interface_handling.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
#define     FLUX_CONTROL_INSTANCES 1u
#define     ANGLE_OFFSET_MIN        ((float)(M_PI_2)/(float)(32767))
#define     DECIMATE_RATED_SPEED        (float)((RATED_SPEED_RPM *((float)M_PI/30)) * NUM_POLE_PAIRS/10)

/*******************************************************************************
 Default module parameters 
 *******************************************************************************/
#define FLUX_CONTROL_MODULE_A_CONFIG { \
    /* Instance Id */ \
    0u, \
    /* Input ports */ \
    { \
        NULL, \
        &mcMocI_DQVoltage_gas[0u].direct, \
        &mcRpoI_ElectricalRotorSpeed_gaf32[0u], \
        &mcSpeI_ReferenceIqCurrent_gaf32[0u], \
        NULL, \
        NULL \
    }, \
    /* Output ports */ \
    { \
        NULL \
    }, \
    /* User Parameters */ \
    { \
       0.0f \
    } \
}


#define FLUX_CONTROL_MODULE_B_CONFIG { \
    /* Instance Id */ \
    1u, \
    /* Input ports */ \
    { \
        NULL, \
        mcMocI_DQVoltage_gas[1u].direct, \
        &mcRpoI_ElectricalRotorSpeed_gaf32[1u], \
        &mcSpeI_ReferenceIqCurrent_gaf32[1u], \
        NULL, \
        NULL \
    }, \
    /* Output ports */ \
    { \
        NULL \
    }, \
    /* User Parameters */ \
    { \
       0.0f \
    } \
}

/*******************************************************************************
 User defined data types  
 *******************************************************************************/
typedef enum _tmcFlx_InstanceId_e
{
    flxModuleInstance_01,
    flxModuleInstance_02,
    flxModuleInstance_max 
}tmcFlx_InstanceId_e;

typedef struct _tmcFlx_InputPorts_s 
{
    volatile float * yd;
    volatile float * ud;
    volatile float * wel;
    volatile float * iqref;
    volatile float * umax;
    volatile float * esFilt;
}tmcFlx_InputPorts_s;

typedef struct _tmcFlx_OutputPorts_s
{
    float  * idref;
}tmcFlx_OutputPorts_s;

typedef struct _tmcFlx_UserParameters_s
{
    float  wbase;                 
    float  umaxSqr;    
    float  esFiltCoeff; 
    float  ls; 
    float  rs; 
    float  fs; 
    float  idmax;   
}tmcFlx_UserParameters_s;

typedef struct _tmcFlx_ConfigParameters_s
{
    /* Instance identifier */
    uint8_t Id;
    
    /* Input ports */
    tmcFlx_InputPorts_s inPort;
    
    /* Output ports */
    tmcFlx_OutputPorts_s outPort;
    
    /* User Parameters */
    tmcFlx_UserParameters_s userParam;
    
}tmcFlx_ConfigParameters_s;


/*******************************************************************************
 Interface variables  
 *******************************************************************************/
extern tmcFlx_ConfigParameters_s  mcFlxI_ConfigParameters_gas[FLUX_CONTROL_INSTANCES];

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Flux regulation initialization  
 * 
 * Details.
 * Flux regulation module initialization 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcFlxI_FluxRegulationInit( const tmcFlx_ConfigParameters_s * const FlxParam );

/*! \brief Flux regulation run function 
 * 
 * Details.
 *  Flux regulation run function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFlxI_FluxRegulationRun( const tmcFlx_InstanceId_e Id );

/*! \brief Flux regulation reset function 
 * 
 * Details.
 *  Flux regulation reset function 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFlxI_FluxRegulationReset( const tmcFlx_InstanceId_e Id );

#endif //MCFLX_H

/**
 End of File
*/
