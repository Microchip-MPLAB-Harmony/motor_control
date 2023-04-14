#ifndef MCIPD_H
#define MCIPD_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

/*******************************************************************************
 Header inclusions
 *******************************************************************************/
#include "mc_types.h"
#include "mc_current_calculation.h"
#include "mc_voltage_measurement.h"

/*******************************************************************************
 User defined data-types
 *******************************************************************************/
typedef struct
{
   float32_t iA;
   float32_t iB;
   float32_t iC;
   float32_t uBus;
}tmcIpd_Input_s;

typedef struct
{
  float32_t uPulse;
  float32_t tPulse;
  float32_t tPeriod;
  float32_t fsInHertz;
  uint16_t  yPeriodCount;
}tmcIpd_Parameters_s;

typedef struct
{
   int16_t duty[3u];
   float32_t phi;
   bool ready;
}tmcIpd_Output_s;

typedef struct
{
   tmcIpd_Input_s dInput;
   tmcIpd_Parameters_s dParameter;
   tmcIpd_Output_s dOutput;
   void * pStatePointer;
}tmcIpd_ModuleData_s;

/*******************************************************************************
 Interface variables
 *******************************************************************************/
extern tmcIpd_ModuleData_s mcIpdI_ModuleData_gds;

/*******************************************************************************
 Static functions
 *******************************************************************************/
/*! \brief Read input ports
 *
 * Details.
 * Read input ports
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
__STATIC_INLINE void mcIpdI_InputPortsRead( tmcIpd_Input_s * const pInput )
{
     pInput->iA = mcCurI_ModuleData_gds.dOutput.iABC.a;
     pInput->iB = mcCurI_ModuleData_gds.dOutput.iABC.b;
     pInput->iC = mcCurI_ModuleData_gds.dOutput.iABC.c;
     
     pInput->uBus = mcVolI_ModuleData_gds.dOutput.uBus;
}

/*! \brief Read input ports
 *
 * Details.
 * Read input ports
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
__STATIC_INLINE void mcIpdI_OutputPortsWrite( tmcIpd_Output_s * const pOutput )
{
    mcPwmI_Duty_gau16[0u] =  pOutput->duty[0u];
    mcPwmI_Duty_gau16[1u] =  pOutput->duty[1u];
    mcPwmI_Duty_gau16[2u] =  pOutput->duty[2u];
}


/*! \brief Set module parameters
 *
 * Details.
 * Set module parameters
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
__STATIC_INLINE void mcIpdI_ParametersSet( tmcIpd_Parameters_s * const pParameter )
{
    pParameter->uPulse = (float32_t)(${MCPMSMFOC_IPD_PULSE_AMPLITUDE});
    pParameter->tPulse = (float32_t)(${MCPMSMFOC_IPD_PULSE_DURATION});
    pParameter->tPeriod = (float32_t)(${MCPMSMFOC_IPD_PULSE_PERIOD});
    pParameter->fsInHertz = (float32_t)(${MCPMSMFOC_PWM_FREQUENCY}u);
    pParameter->yPeriodCount = mcHalI_PwmPeriodGet();
}
/*******************************************************************************
 Interface functions
 *******************************************************************************/

/*! \brief Initial position detection enable
 *
 * Details.
 * Initial position detection enable
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
void mcIpdI_InitialPositionDetectEnable(tmcIpd_ModuleData_s * const pModule);

/*! \brief Initial position detection disable
 *
 * Details.
 * Initial position detection disable
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
void mcIpdI_InitialPositionDetectDisable(tmcIpd_ModuleData_s * const pModule);

/*! \brief Initial position detection initialization
 *
 * Details.
 * Initial position detection initialization
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
void mcIpdI_InitialPositionDetectInit(tmcIpd_ModuleData_s * const pModule);


/*! \brief Initial position detection
 *
 * Details.
 * Initial position detection
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
void mcIpdI_InitialPositionDetect(tmcIpd_ModuleData_s * const pModule);

/*! \brief Initial position detection reset
 *
 * Details.
 * Initial position detection reset
 *
 * @param[in]: Input structure
 * @param[in/out]: State structure
 * @param[out]: Output structure
 * @return: None
 */
void mcIpdI_InitialPositionDetectReset(tmcIpd_ModuleData_s *pModule);


#endif

#ifdef __cplusplus
}
#endif // MCIPD_H
