/*******************************************************************************
  Hardware abstraction source file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_hardware_abstraction.c

  Summary:
    This file contains all the functions related to hardware abstraction

  Description:
    This file contains implementation of the hardware abstraction
 
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
#include "mc_hardware_abstraction.h"

/*******************************************************************************
 * Constants
*******************************************************************************/

/*******************************************************************************
 * Interface variables
*******************************************************************************/
/** Analog interfaces */
uint16_t mcHalI_IaAdcInput_gdu16;
uint16_t mcHalI_IbAdcInput_gdu16;
uint16_t mcHalI_UbusAdcInput_gdu16;
uint16_t mcHalI_Potentiometer_gdu16;
int16_t mcPwmI_Duty_gau16[3u];

/*******************************************************************************
 * Interface Functions
*******************************************************************************/

/*! \brief Enable PWM inverter 
 * 
 * Details.
 * Enable PWM inverter
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_InverterPwmEnable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    /*Disable PWM override*/
    while ((${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_PATT_Msk)) == TCC_SYNCBUSY_PATT_Msk)
    {
        __NOP();
    }
    ${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_PATT = 0x0000;
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL} );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_1 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_2 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_3 );
</#if>
}

/*! \brief Disable PWM inverter 
 * 
 * Details.
 * Disable PWM inverter
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_InverterPwmDisable( void )
{
/** Disable PWM override*/
<#if __PROCESSOR?matches(".*SAME54.*") == true>
   /*Override all PWM outputs to low*/
    while ((${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_SYNCBUSY & (TCC_SYNCBUSY_PATT_Msk)) == TCC_SYNCBUSY_PATT_Msk)
    {
       __NOP();
    }
    ${MCPMSMFOC_PWM_INSTANCE}_REGS->TCC_PATT = 0x00FF;
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL} );
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipDisable( ${MCPMSMFOC_PWM_INSTANCE}_CH_1 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipDisable( ${MCPMSMFOC_PWM_INSTANCE}_CH_2 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipDisable( ${MCPMSMFOC_PWM_INSTANCE}_CH_3 );
</#if>
}

<#--  Get button name  -->
<#function ledName index>
<#if 0 == index>
<#return MCPMSMFOC_LED_0_NAME>
<#elseif 1 == index>
<#return MCPMSMFOC_LED_1_NAME>
<#else>
<#return "Error">
</#if>
</#function>

<#--  Get button function  -->
<#function ledFunction index>
<#if 0 == index>
<#return MCPMSMFOC_LED_0_FUNCTION>
<#elseif 1 == index>
<#return MCPMSMFOC_LED_1_FUNCTION>
<#else>
<#return "Error">
</#if>
</#function>

<#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
<#list 0..10 as index>
<#if "Direction indication" == ledFunction(index)>
/*! \brief Set direction indicator
 * 
 * Details.
 * Set direction indicator
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHal_DirectionIndication( void )
{
    ${ledName(index)}_Toggle();
}
<#break>
</#if>
</#list>
</#if>

<#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
<#list 0..10 as index>
<#if "Fault indication" == ledFunction(index)>
/*! \brief Set fault indicator
 * 
 * Details.
 * Set fault indicator
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHal_FaultIndicationSet( void )
{
   ${ledName(index)}_Set();
}
<#break>
</#if>
</#list>
</#if>

/*! \brief ADC Enable
 * 
 * Details.
 * ADC Enable
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_AdcEnable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ADC0_Enable();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    /** Nothing to do */
    __NOP();
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>

</#if>
}

/*! \brief PWM Enable
 *
 * Details.
 * PWM Enable
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmInterruptEnable( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    NVIC_EnableIRQ(${MCPMSMFOC_PWM_INSTANCE}_OTHER_IRQn);  
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    NVIC_EnableIRQ(${MCPMSMFOC_PWM_INSTANCE}_IRQn);
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    EVIC_SourceEnable( INT_SOURCE_PWM1 );
</#if>
}

/*! \brief PWM timer Start
 * 
 * Details.
 * PWM timer Start
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_PwmTimerStart( void )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_PWMStart( );  
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelsStart(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL}_MASK); 
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelsStart(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_B_FINAL}_MASK); 
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelsStart(PWM_CHANNEL_${MCPMSMFOC_PWM_INSTANCE_PWM_C_FINAL}_MASK); 
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_PWM_INSTANCE}_Start();
</#if>
}

/*! \brief ADC callback function
 * 
 * Details.
 * ADC callback function
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcHalI_AdcCallBackRegister( ADC_CALLBACK callback, uintptr_t context )
{
    ADC0_CallbackRegister( callback, context);
}
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcHalI_AdcCallBackRegister( AFEC_CALLBACK callback, uintptr_t context )
{
    AFEC0_CallbackRegister( callback, context);
}
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcHalI_AdcCallBackRegister( ADCHS_CALLBACK callback, uintptr_t context )
{
    ADCHS_CallbackRegister(${.vars["${MCPMSMFOC_ADC_MODULE_01?lower_case}"].ADC_CH_PHASE_U}, callback, context);
}
</#if>

/*! \brief PWM fault callback function
 * 
 * Details.
 * PWM fault callback function
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
<#if __PROCESSOR?matches(".*SAME54.*") == true>
void mcHalI_PwmCallbackRegister( TCC_CALLBACK callback, uintptr_t context )
{
    ${MCPMSMFOC_PWM_INSTANCE}_PWMCallbackRegister( callback, (uintptr_t)context);
}
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
void mcHalI_PwmCallbackRegister( PWM_CALLBACK callback, uintptr_t context )
{
    ${MCPMSMFOC_PWM_INSTANCE}_CallbackRegister( callback, (uintptr_t)context);
}

<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
void mcHalI_PwmCallbackRegister( MCPWM_CH_CALLBACK callback, uintptr_t context )
{
    ${MCPMSMFOC_PWM_INSTANCE}_CallbackRegister(${MCPMSMFOC_PWM_INSTANCE}_CH_1, callback, (uintptr_t)context);
}
</#if>


<#--  Get button name  -->
<#function buttonName index>
<#if 0 == index>
<#return MCPMSMFOC_BUTTON_0_NAME>
<#elseif 1 == index>
<#return MCPMSMFOC_BUTTON_1_NAME>
<#else>
<#return "Error">
</#if>
</#function>

<#--  Get button function  -->
<#function buttonFunction index>
<#if 0 == index>
<#return MCPMSMFOC_BUTTON_0_FUNCTION>
<#elseif 1 == index>
<#return MCPMSMFOC_BUTTON_1_FUNCTION>
<#else>
<#return "Error">
</#if>
</#function>

<#if MCPMSMFOC_BUTTONS_AVAILABLE != 0 >
<#list 0..10 as index>
<#if "Start/Stop" == buttonFunction(index)>
bool mcHalI_StartStopButtonState( void )
{
     return (bool)${buttonName(index)}_Get();
}
<#break>
</#if>
</#list>
</#if>


<#if MCPMSMFOC_BUTTONS_AVAILABLE != 0 >
<#list 0..10 as index>
<#if "Direction Toggle" == buttonFunction(index)>
bool mcHalI_DirectionButtonState( void )
{
     return (bool)${buttonName(index)}_Get();
}
<#break>
</#if>
</#list>
</#if>  

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
/*! \brief Start the encoder peripheral
 * 
 * Details.
 * Start the encoder peripheral
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcHalI_EncoderStart( void  )
{
<#if __PROCESSOR?matches(".*SAME54.*") == true>
    ${MCPMSMFOC_ENCODER_PERIPHERAL}_QDECStart();
<#elseif __PROCESSOR?matches(".*SAME70.*") == true>
   ${MCPMSMFOC_ENCODER_PERIPHERAL}_QuadratureStart();
<#elseif __PROCESSOR?matches(".*PIC32MK.*") == true>
    ${MCPMSMFOC_ENCODER_PERIPHERAL}_Start();
</#if>
}
</#if>
