/**
 * @file application.c
 *
 * @brief 
 *   Application source file
 *
 * @Company 
 *    Microchip Technology Inc.
 *
 * @Summary
 *   Header file defining application-specific details.
 *
 * @Description
 *   This header file provides definitions and structures specific to the application,
 *   including configuration settings, function prototypes, and any other necessary details.
 */


// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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
#include "mc_application.h"

/*******************************************************************************
 * Constants
 *******************************************************************************/

/*******************************************************************************
 Private data-types
 *******************************************************************************/

/*******************************************************************************
 Private variables
 *******************************************************************************/
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
static button_response_t  mcAppI_StartStopButton_gds;
</#if>
<#if "Direction Toggle" == buttonFunction(index)>
static button_response_t  mcAppI_DirectionButton_gds;
</#if>
</#list>
</#if>
static uint32_t mcAppI_1msSyncCounter_gdu32;
static uintptr_t dummyForMisra;
static uint8_t runStatus = 0u;

/*******************************************************************************
 Interface variables
 *******************************************************************************/

/*******************************************************************************
 Private Functions
 *******************************************************************************/
/**
 * @brief Start/stop button scan
 *
 * @details Controls motor start/stop based on button input.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
__STATIC_INLINE void mcAppI_MotorStartStop(void)
{
    if( 0u == runStatus )
    {
<#if true == MCPMSMFOC_FOC_X2C_ENABLE>
        /** Start motor  */
        mcFocI_FieldOrientedControlEnable();
<#else>
        /** Start motor  */
        mcFocI_FieldOrientedControlEnable( &mcFocI_ModuleData_gds );
</#if>

<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
        /** Enable initial position detection  */
        mcIpdI_InitialPositionDetectEnable(&mcIpdI_ModuleData_gds);

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (AFEC_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADCHS_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
</#if>
</#if>
</#if>

        /** Enable voltage source inverter */
        mcHalI_InverterPwmEnable();

        runStatus = 1u;
    }
    else
    {
<#if true == MCPMSMFOC_FOC_X2C_ENABLE>
        /** Stop motor  */
        mcFocI_FieldOrientedControlDisable();
<#else>
        /** Start motor  */
        mcFocI_FieldOrientedControlDisable( &mcFocI_ModuleData_gds );
</#if>

<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
 <#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
        /** Disable initial position detection  */
        mcIpdI_InitialPositionDetectDisable(&mcIpdI_ModuleData_gds);
</#if>
</#if>

        /** Enable voltage source inverter */
        mcHalI_InverterPwmDisable();

        runStatus = 0u;
    }
}

/**
 * @brief Direction reverse button scan
 *
 * @details Reverses motor direction based on button input.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
<#--  Get led function  -->
<#function ledFunction index>
  <#if 0 == index>
    <#return MCPMSMFOC_LED_0_FUNCTION>
  <#elseif 1 == index>
    <#return MCPMSMFOC_LED_1_FUNCTION>
  <#else>
    <#return "Error">
  </#if>
</#function>
__STATIC_INLINE void mcAppI_DirectionReverse(void)
{
    if( 0u == runStatus )
    {
<#if true == MCPMSMFOC_FOC_X2C_ENABLE>
       /** Change state variable to toggle motor spin direction  */
       mcFocI_MotorDirectionChange( );
<#else>
       /** Change state variable to toggle motor spin direction  */
       mcFocI_MotorDirectionChange(&mcFocI_ModuleData_gds);
</#if>


<#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
<#list 0..10 as index>
<#if "Direction Indication" == ledFunction(index)>
        /** Set fault indicator */
        mcHal_DirectionIndication();
<#break>
</#if>
</#list>
</#if>
    }
}

/**
 * @brief 1 ms tasks handler
 *
 * @details Handles tasks to be executed every 1 ms.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
__STATIC_INLINE void mcAppI_1msTasksHandler( void )
{
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
    /** Start-stop button scan  */
    mcAppI_StartStopButton_gds.inputVal = mcHalI_StartStopButtonState();
    mcUtils_ButtonResponse(&mcAppI_StartStopButton_gds, &mcAppI_MotorStartStop);

<#elseif "Direction Toggle" == buttonFunction(index)>
    /** Direction button scan  */
    mcAppI_DirectionButton_gds.inputVal = mcHalI_DirectionButtonState();
    mcUtils_ButtonResponse(&mcAppI_DirectionButton_gds, &mcAppI_DirectionReverse);
</#if>
</#list>
</#if>

<#if true == MCPMSMFOC_FOC_X2C_ENABLE>

<#else>
    /** Field Oriented control - Slow Tasks */
    mcFocI_FieldOrientedControlSlow(&mcFocI_ModuleData_gds);
</#if>

}

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
/**
 * @brief Application initialization
 *
 * @details Initializes the application.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_ApplicationInit( void )
{
    /** ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptDisable();
    mcHalI_AdcInterruptClear();

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    /** Enable ADC interrupt for field oriented control */
    mcHalI_AdcCallBackRegister(  (ADC_CALLBACK)mcAppI_AdcCalibrationIsr, (uintptr_t)dummyForMisra );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    /** Enable ADC interrupt for field oriented control */
    mcHalI_AdcCallBackRegister(  (AFEC_CALLBACK)mcAppI_AdcCalibrationIsr, (uintptr_t)dummyForMisra );
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
    /** Enable ADC interrupt for field oriented control */
    mcHalI_AdcCallBackRegister(  (ADC_CALLBACK)mcAppI_AdcCalibrationIsr, (uintptr_t)dummyForMisra );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
    /** Enable ADC interrupt for field oriented control */
    mcHalI_AdcCallBackRegister(  (ADCHS_CALLBACK)mcAppI_AdcCalibrationIsr, (uintptr_t)dummyForMisra );
</#if>
    mcHalI_AdcInterruptEnable( );

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    /** Enable ADC module */
    mcHalI_AdcEnable();
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
    /** Enable ADC module */
    mcHalI_AdcEnable();
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
    /** Enable ADC module */
    mcHalI_AdcEnable();
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
</#if>

<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
    /** Enable interrupt for fault detection */
    mcHalI_PwmCallbackRegister( (TCC_CALLBACK)mcAppI_OverCurrentReactionIsr, (uintptr_t)dummyForMisra );

    /** Enable PWM interrupt to detect fault */
    mcHalI_PwmInterruptEnable( );

<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
    /** Enable interrupt for fault detection */
    mcHalI_PwmCallbackRegister( (PWM_CALLBACK)mcAppI_OverCurrentReactionIsr, (uintptr_t)dummyForMisra );

    /** Enable PWM interrupt to detect fault */
    mcHalI_PwmInterruptEnable( );

<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
    /** Enable interrupt for fault detection */
    mcHalI_PwmCallbackRegister( (MCPWM_CH_CALLBACK)mcAppI_OverCurrentReactionIsr, (uintptr_t)dummyForMisra );
</#if>

    /** Enables PWM channels. */
    mcHalI_PwmTimerStart( );

    /** Disable PWM output */
    mcHalI_InverterPwmDisable();

    /** Set motor parameters */
    mcMotI_MotorParametersInit( &mcMotI_PMSM_gds);

    /** Initialize Current calculation */
    mcCurI_CurrentCalculationInit(&mcCurI_ModuleData_gds);

    /** Initialize Voltage measurement  */
    mcVolI_VoltageCalculationInit( &mcVolI_ModuleData_gds );

<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER' )>
    /** Initialize rotor position calculation  */
    mcRpcI_RotorPositionCalcInit( &mcRpcI_ModuleData_gds );

    /** Enable rotor position calculation  */
    mcRpcI_RotorPositionCalcEnable( &mcRpcI_ModuleData_gds );
</#if>

<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
    /** Initialize Initial position detection */
    mcIpdI_InitialPositionDetectInit(&mcIpdI_ModuleData_gds);
</#if>
</#if>

<#if true == MCPMSMFOC_FOC_X2C_ENABLE>
    /** Initialize PMSM motor control */
    mcFocI_FieldOrientedControlInit();
<#else>
    /** Initialize PMSM motor control */
    mcFocI_FieldOrientedControlInit( &mcFocI_ModuleData_gds);
</#if>

 <#if ('IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS )  ||  ('SENSORLESS_ZSMT_HYBRID' == MCPMSMFOC_POSITION_CALC_ALGORITHM )>
    /** Initialize key manager */
    mcKeyI_KeyManagerInit();
</#if>

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    /** Set phase A and phase B current channels */
    mcHalI_PhaseACurrentChannelSelect();
    mcHalI_PhaseBCurrentChannelSelect();
</#if>

}

/**
 * @brief Over current reaction ISR
 *
 * @details Interrupt service routine for over current reaction.
 *
 * @param[in] status Status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if "TCC_U2213" == MCPMSMFOC_PWM_IP>
void mcAppI_OverCurrentReactionIsr( uint32_t status,  uintptr_t context )
<#elseif "PWM_6343" == MCPMSMFOC_PWM_IP>
void mcAppI_OverCurrentReactionIsr( uint32_t status,  uintptr_t context )
<#elseif "MCPWM_01477" == MCPMSMFOC_PWM_IP>
void mcAppI_OverCurrentReactionIsr( MCPWM_CH_STATUS status, uintptr_t context )
</#if>
{
<#if true == MCPMSMFOC_FOC_X2C_ENABLE>
    /** Initialize PMSM motor control */
    mcFocI_FieldOrientedControlDisable();
<#else>
    /** Initialize PMSM motor control */
    mcFocI_FieldOrientedControlInit( &mcFocI_ModuleData_gds);
</#if>

    /** Reset software modules */
    mcAppI_ApplicationReset();

    /** Enable voltage source inverter */
    mcHalI_InverterPwmDisable();

<#if MCPMSMFOC_LEDS_AVAILABLE != 0 >
<#list 0..10 as index>
<#if "Fault Indication" == ledFunction(index)>
    /** Set fault indicator */
    mcHal_FaultIndicationSet();
<#break>
</#if>
</#list>
</#if>

}

/**
 * @brief Motor control application calibration ISR
 *
 * @details Interrupt service routine for motor control application calibration.
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
void mcAppI_AdcCalibrationIsr(ADC_STATUS status, uintptr_t context)
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcCalibrationIsr( uint32_t status, uintptr_t context )
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcCalibrationIsr( uint32_t status, uintptr_t context )
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcCalibrationIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context )
</#if>
{
    tmcTypes_StdReturn_e returnStatus;

    /** ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptDisable();
    mcHalI_AdcInterruptClear();

    /** Read phase currents  */
    mcHalI_PhaseACurrentGet();
    mcHalI_PhaseBCurrentGet();

    /** Phase current offset measurement  */
    returnStatus = mcCurI_CurrentOffsetCalculation(&mcCurI_ModuleData_gds );

    /** Current sense amplifiers offset calculation */
    if( StdReturn_Complete == returnStatus )
    {
<#if MCPMSMFOC_FOC_X2C_ENABLE == true>
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (AFEC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADCHS_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
</#if>
<#else>
<#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (AFEC_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADCHS_CALLBACK)mcAppI_InitialPositionDetectIsr, (uintptr_t)dummyForMisra );
</#if>
<#else>
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (AFEC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADCHS_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
</#if>
</#if>
</#if>
    }
    else
    {
        /** For MISRA Compliance */
    }

<#if MCPMSMFOC_X2CSCOPE == "X2Cscope">
    /** Calibration and monitoring update */
    X2Cscope_Update();
</#if>

     /** ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptClear();
    mcHalI_AdcInterruptEnable();
}
<#if MCPMSMFOC_FOC_X2C_ENABLE == false>
 <#if 'IPD' == MCPMSMFOC_ALIGN_OR_DETECT_AXIS >

/**
 * @brief ADC finished ISR
 *
 * @details Interrupt service routine for ADC finished tasks for IPD
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
void mcAppI_InitialPositionDetectIsr(ADC_STATUS status, uintptr_t context )
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
void mcAppI_InitialPositionDetectIsr( uint32_t status, uintptr_t context )
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
void mcAppI_InitialPositionDetectIsr( uint32_t status, uintptr_t context )
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
void mcAppI_InitialPositionDetectIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context )
</#if>
{
    /** ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptDisable();
    mcHalI_AdcInterruptClear();

    /** Read phase currents  */
    mcHalI_PhaseACurrentGet();
    mcHalI_PhaseBCurrentGet();

    if (false == mcIpdI_ModuleData_gds.dOutput.ready )
    {
        /** Current measurement  */
        mcCurI_CurrentCalculation( &mcCurI_ModuleData_gds );

        /** Initial position detection  */
        mcIpdI_InitialPositionDetect(&mcIpdI_ModuleData_gds);

        /** Bus voltage calculation */
        mcVolI_VoltageCalculation( &mcVolI_ModuleData_gds );

        /** Set duty */
        mcHalI_InverterPwmSet(mcPwmI_Duty_gau16);

        /** Bus voltage calculation */
        mcVolI_VoltageCalculation( &mcVolI_ModuleData_gds );

    }
    else
    {
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (AFEC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
        mcHalI_AdcCallBackRegister( (ADCHS_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
</#if>

    }

    /** Read DC bus voltage */
    mcHalI_DcLinkVoltageGet();

    /** Increment interrupt counter */
    mcAppI_1msSyncCounter_gdu32++;

<#if MCPMSMFOC_X2CSCOPE == "X2Cscope">
    /** Calibration and monitoring update */
    X2Cscope_Update();
</#if>

    /** ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptClear();
    mcHalI_AdcInterruptEnable();
}

</#if>
</#if>

/**
 * @brief ADC finished ISR
 *
 * @details Interrupt service routine for ADC finished tasks.
 *
 * @param[in] status ADC status information
 * @param[in/out] context Interrupt context
 * @param[out] None
 *
 * @return None
 */
<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
void mcAppI_AdcFinishedIsr(ADC_STATUS status, uintptr_t context )
<#elseif "AFEC_11147" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcFinishedIsr( uint32_t status, uintptr_t context )
<#elseif "ADC_44073" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcFinishedIsr( uint32_t status, uintptr_t context )
<#elseif "ADCHS_02508" == MCPMSMFOC_ADC_IP>
void mcAppI_AdcFinishedIsr( ADCHS_CHANNEL_NUM channel, uintptr_t context )
</#if>
{
    /** ADC interrupt disable  */
    mcHalI_AdcInterruptDisable();
    mcHalI_AdcInterruptClear();

    /** Read phase currents  */
    mcHalI_PhaseACurrentGet();
    mcHalI_PhaseBCurrentGet();

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    /** Set Potentiometer and bus voltage channels */
    mcHalI_PotentiometerChannelSelect();
    mcHalI_DcLinkVoltageChannelSelect();

    /** Start software conversion */
    mcHalI_AdcSoftwareConversionStart();
</#if>

    /** Current calculation */
    mcCurI_CurrentCalculation(&mcCurI_ModuleData_gds);

<#if ( MCPMSMFOC_POSITION_CALC_ALGORITHM == 'SENSORED_ENCODER' )>
    /** Rotor position calculation  */
    mcRpcI_RotorPositionCalc( &mcRpcI_ModuleData_gds );
</#if>

<#if true == MCPMSMFOC_FOC_X2C_ENABLE>
    /** Initialize PMSM motor control */
    mcFocI_FieldOrientedControlFast();
<#else>
    /** Initialize PMSM motor control */
    mcFocI_FieldOrientedControlFast( &mcFocI_ModuleData_gds);
</#if>

    /** Set duty */
    mcHalI_InverterPwmSet(mcPwmI_Duty_gau16);

    /** Bus voltage calculation */
    mcVolI_VoltageCalculation( &mcVolI_ModuleData_gds );

    /** Read DC bus voltage */
    mcHalI_DcLinkVoltageGet();

    /** Read potentiometer input */
    mcHalI_PotentiometerInputGet();

<#if ("ADC_U2500" == MCPMSMFOC_ADC_IP )  || ("ADC_U2247" == MCPMSMFOC_ADC_IP )>
    /** Set phase A and phase B current channels */
    mcHalI_PhaseACurrentChannelSelect();
    mcHalI_PhaseBCurrentChannelSelect();

    /** Re-enable hardware trigger for ADC channels */
    mcHalI_AdcHardwareTriggerRenable();
</#if>

<#if MCPMSMFOC_X2CSCOPE == "X2Cscope">
    /** Calibration and monitoring update */
    X2Cscope_Update();
</#if>

    /** Increment interrupt counter */
    mcAppI_1msSyncCounter_gdu32++;

    /** ADC interrupt clear  */
    mcHalI_AdcInterruptClear();
    mcHalI_AdcInterruptEnable();
}

/**
 * @brief Non-ISR tasks execution
 *
 * @details Executes non-interrupt service routine tasks.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_NonISRTasks( void )
{
    float32_t loopCount = 0.001f * (float32_t)(${MCPMSMFOC_PWM_FREQUENCY});
    if( mcAppI_1msSyncCounter_gdu32 >= (uint32_t)loopCount )
    {
        mcAppI_1msSyncCounter_gdu32 = 0u;
        mcAppI_1msTasksHandler();
    }
}

/**
 * @brief Application reset
 *
 * @details Resets the application.
 *
 * @param[in] None
 * @param[in/out] None
 * @param[out] None
 *
 * @return None
 */
void mcAppI_ApplicationReset( void )
{
    /** Voltage measurement  */
    mcVolI_VoltageCalculationReset( &mcVolI_ModuleData_gds );

<#if true == MCPMSMFOC_FOC_X2C_ENABLE>
    /** PMSM motor control */
    mcFocI_FieldOrientedControlReset();
<#else>
    /** PMSM motor control */
    mcFocI_FieldOrientedControlReset( &mcFocI_ModuleData_gds);
</#if>
}
