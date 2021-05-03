/*******************************************************************************
 Pulse width modulation function 

  Company:
    Microchip Technology Inc.

  File Name:
    mc_pwm.c

  Summary:
    Pulse width modulation functions.

  Description:
    This file implements functions for pulse width modulation .
 
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
#include "mc_pwm.h"

/*******************************************************************************
 Private data types
*******************************************************************************/
typedef struct 
{
    tmcLib_ClarkTransform_s       Uab;
    tmcInf_ThreePhaseQuantity_s Uuvw;
    uint32_t dutyCycle[3];
}tmcPwm_StateVariables_s;


typedef struct 
{
   uint32_t period;
   uint32_t halfPeriod;
   uint16_t deadTime;
}tmcPwm_Parameters_s;

/*******************************************************************************
Private variables
*******************************************************************************/
static tmcPwm_InputPorts_s  mcPwm_InputPorts_mas[1u];
static tmcPwm_Parameters_s  mcPwm_Parameters_mas[1u];
static tmcPwm_StateVariables_s  mcPwm_StatePorts_mas[1u];
static tmcPwm_OutputPorts_s mcPwm_OutputPorts_mas[1u];

/*******************************************************************************
Interface  variables
*******************************************************************************/
tmcPwm_ConfigParameters_s mcPwmI_ConfigParameters_gds = PWM_MODULE_CONFIG;

extern int32_t __aeabi_idiv(int32_t numerator, int32_t denominator);

/*******************************************************************************
Private Functions
*******************************************************************************/

/* !\brief Find maximum
 * 
 * Details.
 * Find maximum 
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
__STATIC_INLINE int16_t mcPwm_FindMaximum(const tmcInf_ThreePhaseQuantity_s * const input )
{
    int16_t max;
    if((input->a >= input->b ) && (input->a >= input->c ))
    {
        max = input->a;
    }
    else if(input->b >= input->c)
    {
        max = input->b;
    }
    else 
    {
        max = input->c;
    }
    return max;
}


/* !\brief Find minimum 
 * 
 * Details.
 * Find minimum
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
__STATIC_INLINE int16_t mcPwm_FindMinimum(const tmcInf_ThreePhaseQuantity_s * const input )
{
    int16_t min;
    if((input->a <= input->b ) && (input->a <= input->c ))
    {
        min = input->a;
    }
    else if(input->b <= input->c)
    {
        min = input->b;
    }
    else 
    {
        min = input->c;
    }
    return min;
}


/*******************************************************************************
 * Interface Functions 
*******************************************************************************/

/* !\brief Initialize PWM modulator
 * 
 * Details.
 * Initialize PWM Modulator 
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
void  mcPwmI_PulseWidthModulationInit( const tmcPwm_ConfigParameters_s * const pwmConfigParam )
{  
    /* Check  if configuration parameters have valid memory location  */
    ASSERT(( NULL != pwmConfigParam ), "Configuration parameters points to NULL");
    
    /* Initialize input ports */
    ASSERT( ( ( NULL != pwmConfigParam->inPort.Uab) && ( NULL != pwmConfigParam->inPort.Ubus) ),
                  "Input ports are not assigned");
    
    mcPwm_InputPorts_mas[pwmConfigParam->Id] = pwmConfigParam->inPort;
          
    /* Update and calculate independent and independent parameters respectively */ 
    mcPwm_Parameters_mas[pwmConfigParam->Id].period  = mcHal_InverterPwmPeriodGet();
    mcPwm_Parameters_mas[pwmConfigParam->Id].halfPeriod  = mcPwm_Parameters_mas[0u].period >> 1u;
    
    /* Initializes PWM duty */
    mcPwm_OutputPorts_mas[pwmConfigParam->Id].dutyCycle[0] = mcPwm_Parameters_mas[pwmConfigParam->Id].halfPeriod;
    mcPwm_OutputPorts_mas[pwmConfigParam->Id].dutyCycle[1] = mcPwm_Parameters_mas[pwmConfigParam->Id].halfPeriod;
    mcPwm_OutputPorts_mas[pwmConfigParam->Id].dutyCycle[2] = mcPwm_Parameters_mas[pwmConfigParam->Id].halfPeriod;

    /* Update PWM duty cycles of the voltage source inverter  */
    mcHal_InverterDutySet(mcPwm_OutputPorts_mas[pwmConfigParam->Id].dutyCycle); 
 
}



/* !\brief PWM Modulator 
 * 
 * Details.
 * PWM Modulator
 * 
 * @param[in]: None 
 * @param[in/out]: None
 * @param[out]: None 
 * @return: None
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcPwmI_PulseWidthModulationRun( const  tmcPwm_InstanceId_e Id )
#else
void mcPwmI_PulseWidthModulationRun( const  tmcPwm_InstanceId_e Id )
#endif
{
    int16_t Umax;
    int16_t Umin;
    int16_t Uoffset;
    int32_t Factor;
   
    /* Reverse-Clarke transformation */
    mcLib_ReverseClarkTransform( mcPwm_InputPorts_mas[Id].Uab, &mcPwm_StatePorts_mas[Id].Uuvw);

    /* Find maximum and minimum quantities */
    Umax= mcPwm_FindMaximum( &mcPwm_StatePorts_mas[Id].Uuvw );
    Umin= mcPwm_FindMinimum( &mcPwm_StatePorts_mas[Id].Uuvw );
 
    /* Determine offset */
    Uoffset = ( *mcPwm_InputPorts_mas[0u].Ubus - Umax - Umin ) >> 1 ;
    
    /* Determine voltage to duty conversion factor */
    Factor =  __aeabi_idiv( (int32_t)( mcPwm_Parameters_mas[Id].period  << SH_BASE_VALUE ),  (int32_t)*mcPwm_InputPorts_mas[Id].Ubus );

    /* Determine PWM duty */
    mcPwm_OutputPorts_mas[Id].dutyCycle[0] = mcPwm_Parameters_mas[Id].period - ((( mcPwm_StatePorts_mas[Id].Uuvw.a + Uoffset ) * Factor ) >> SH_BASE_VALUE ); 
    mcPwm_OutputPorts_mas[Id].dutyCycle[1] = mcPwm_Parameters_mas[Id].period - ((( mcPwm_StatePorts_mas[Id].Uuvw.b + Uoffset ) * Factor ) >> SH_BASE_VALUE ); 
    mcPwm_OutputPorts_mas[Id].dutyCycle[2] = mcPwm_Parameters_mas[Id].period - ((( mcPwm_StatePorts_mas[Id].Uuvw.c + Uoffset ) * Factor ) >> SH_BASE_VALUE ); 

    /* Update duty */ 
    mcHal_InverterDutySet(mcPwm_OutputPorts_mas[Id].dutyCycle); 

}


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
void mcPwmI_PulseWidthModulationReset( const tmcPwm_InstanceId_e Id )
{
    mcPwm_OutputPorts_mas[Id].dutyCycle[0] = mcPwm_Parameters_mas[Id].halfPeriod;
    mcPwm_OutputPorts_mas[Id].dutyCycle[1] = mcPwm_Parameters_mas[Id].halfPeriod;
    mcPwm_OutputPorts_mas[Id].dutyCycle[2] = mcPwm_Parameters_mas[Id].halfPeriod;

    /* Update duty  */
    mcHal_InverterDutySet(mcPwm_OutputPorts_mas[Id].dutyCycle); 
}
