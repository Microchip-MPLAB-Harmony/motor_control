/**
 * @brief 
 *    Hardware abstraction source file
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @File Name
 *   mc_hardware_abstraction.c
 *
 * @Summary
 *   This file contains implementation of the hardware abstraction
 *
 * @Description
 *   This file contains implementation of the hardware abstraction
 */
 
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
uint16_t mcHalI_IaAdcInput_gdu16;         /**< Phase A current ADC input */
uint16_t mcHalI_IbAdcInput_gdu16;         /**< Phase B current ADC input */
uint16_t mcHalI_UbusAdcInput_gdu16;     /**< DC bus voltage ADC input   */
uint16_t mcHalI_Potentiometer_gdu16;      /**< Potentiometer ADC input     */
int16_t mcPwmI_Duty_gau16[3u];              /**< PWM duty cycle array        */

/*******************************************************************************
 * Interface Functions
*******************************************************************************/

/**
 * @brief Enable three phase inverter
 *
 * @details
 * Enable three phase inverter
 */
void mcHalI_InverterPwmEnable( void )
{
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
    bool status;

    /** Disable PWM override*/
    status = ${MCPMSMFOC_PWM_INSTANCE}_PWMPatternSet(0u, 0u );

    if( false == status )
    {
        /** ToDO: Log error */
    }
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_A_CHANNEL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_B_CHANNEL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideEnable( PWM_CHANNEL_${MCPMSMFOC_PWM_C_CHANNEL} );
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_1 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_2 );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelPinsOwnershipEnable( ${MCPMSMFOC_PWM_INSTANCE}_CH_3 );
</#if>
}

/**
 * @brief Disable three phase inverter
 *
 * @details
 * Disable three phase inverter
 */
void mcHalI_InverterPwmDisable( void )
{
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
    bool status;

    /** Override all PWM outputs to low */
    status = TCC0_PWMPatternSet((TCC_PATT_PGE0_Msk|TCC_PATT_PGE1_Msk|TCC_PATT_PGE2_Msk
            |TCC_PATT_PGE4_Msk|TCC_PATT_PGE5_Msk|TCC_PATT_PGE6_Msk),
            (TCC_PATT_PGE0(0u)|TCC_PATT_PGE1(0u)|TCC_PATT_PGE2(0u)|TCC_PATT_PGE4(0u)
            |TCC_PATT_PGE5(0u)|TCC_PATT_PGE6(0u)));


    if( false == status )
    {
        /** ToDO: Log error */
    }
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_A_CHANNEL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_B_CHANNEL} );
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelOverrideDisable( PWM_CHANNEL_${MCPMSMFOC_PWM_C_CHANNEL} );
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
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
<#if "Direction Indication" == ledFunction(index)>
/**
 * @brief Set direction indication
 *
 * @details
 * Set direction indication
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
<#if "Fault Indication" == ledFunction(index)>
/**
 * @brief Set direction indication
 *
 * @details
 * Set direction indication
 */
void mcHal_FaultIndicationSet( void )
{
   ${ledName(index)}_Set();
}
<#break>
</#if>
</#list>
</#if>

/**
 * @brief Enable ADC peripheral
 *
 * @details
 * Enable ADC peripheral
 */
void mcHalI_AdcEnable( void )
{
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_Enable();
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    /** Nothing to do */
    __NOP();
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
</#if>
}

/**
 * @brief Enable PWM fault interrupt
 *
 * @details
 * Enable PWM fault interrupt
 */
void mcHalI_PwmInterruptEnable( void )
{
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )>
    NVIC_EnableIRQ(${MCPMSMFOC_PWM_INSTANCE}_OTHER_IRQn);
<#elseif ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    NVIC_EnableIRQ(${MCPMSMFOC_PWM_INSTANCE}_IRQn);
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    NVIC_EnableIRQ(${MCPMSMFOC_PWM_INSTANCE}_IRQn);
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
    EVIC_SourceEnable( INT_SOURCE_PWM1 );
</#if>
}

/**
 * @brief Start PWM timer
 *
 * @details
 * Start PWM timer
 */
void mcHalI_PwmTimerStart( void )
{
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
    ${MCPMSMFOC_PWM_INSTANCE}_PWMStart( );
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelsStart(PWM_CHANNEL_${MCPMSMFOC_PWM_A_CHANNEL}_MASK);
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelsStart(PWM_CHANNEL_${MCPMSMFOC_PWM_B_CHANNEL}_MASK);
    ${MCPMSMFOC_PWM_INSTANCE}_ChannelsStart(PWM_CHANNEL_${MCPMSMFOC_PWM_C_CHANNEL}_MASK);
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
    ${MCPMSMFOC_PWM_INSTANCE}_Start();
</#if>
}

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
/**
 * @brief ADC conversion complete interrupt callback function
 *
 * @details
 * ADC conversion complete interrupt callback function
 */
void mcHalI_AdcCallBackRegister( ADC_CALLBACK callback, uintptr_t context )
{
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_CallbackRegister( callback, context);
}
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
/**
 * @brief ADC conversion complete interrupt callback function
 *
 * @details
 * ADC conversion complete interrupt callback function
 */
void mcHalI_AdcCallBackRegister( AFEC_CALLBACK callback, uintptr_t context )
{
    ${MCPMSMFOC_PHASE_CURRENT_IA_UNIT}_CallbackRegister( callback, context);
}
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
/**
 * @brief ADC conversion complete interrupt callback function
 *
 * @details
 * ADC conversion complete interrupt callback function
 */
void mcHalI_AdcCallBackRegister( ADCHS_CALLBACK callback, uintptr_t context )
{
    ADCHS_CallbackRegister(${.vars["${MCPMSMFOC_ADC_MODULE_01?lower_case}"].ADC_CH_PHASE_U}, callback, context);
}
</#if>

<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
/**
 * @brief PWM fault interrupt callback function
 *
 * @details
 * PWM fault interrupt callback function
 */
void mcHalI_PwmCallbackRegister( TCC_CALLBACK callback, uintptr_t context )
{
    ${MCPMSMFOC_PWM_INSTANCE}_PWMCallbackRegister( callback, (uintptr_t)context);
}
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
/**
 * @brief PWM fault interrupt callback function
 *
 * @details
 * PWM fault interrupt callback function
 */
void mcHalI_PwmCallbackRegister( PWM_CALLBACK callback, uintptr_t context )
{
    ${MCPMSMFOC_PWM_INSTANCE}_CallbackRegister( callback, (uintptr_t)context);
}

<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
/**
 * @brief PWM fault interrupt callback function
 *
 * @details
 * PWM fault interrupt callback function
 */
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
<#list 0..( MCPMSMFOC_BUTTONS_AVAILABLE - 1 ) as index>
<#if "Start/Stop" == buttonFunction(index)>
/**
 * @brief Get start-stop button state
 *
 * @details
 * Get start-stop button state
 *
 * @return  True if button is pressed, false if button is not pressed
 */
bool mcHalI_StartStopButtonState( void )
{
    return (bool)${buttonName(index)}_Get();
}
<#break>
</#if>
</#list>
</#if>

<#if MCPMSMFOC_BUTTONS_AVAILABLE != 0 >
<#list 0..( MCPMSMFOC_BUTTONS_AVAILABLE - 1 ) as index>
<#if "Direction Toggle" == buttonFunction(index)>
/**
 * @brief Get direction button state
 *
 * @details
 * Get direction button state
 *
 * @return  True if button is pressed, false if button is not pressed
 */
bool mcHalI_DirectionButtonState( void )
{
     return (bool)${buttonName(index)}_Get();
}
<#break>
</#if>
</#list>
</#if>

<#if MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER'>
/**
 * @brief Start encoder pulses counter of qudarature decoder
 *
 * @details
 * Start encoder pulses counter of qudarature decoder
 */
void mcHalI_EncoderStart( void  )
{
<#if "PDEC_U2263" == MCPMSMFOC_QEI_IP>
    ${MCPMSMFOC_ENCODER_PERIPHERAL}_QDECStart();
<#elseif "TC_6082" == MCPMSMFOC_QEI_IP>
   ${MCPMSMFOC_ENCODER_PERIPHERAL}_QuadratureStart();
<#elseif "QEI_01494" == MCPMSMFOC_QEI_IP>
    ${MCPMSMFOC_ENCODER_PERIPHERAL}_Start();
</#if>
}
</#if>
