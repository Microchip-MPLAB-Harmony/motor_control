/*******************************************************************************
 Application source file

  Company:
  Microchip Technology Inc.

  File Name:
  application.c

  Summary:
  Application source file

  Description:
  Application source file
 
 *******************************************************************************/

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
#include "mc_types.h" /** ToDO: Move it to header files */
#include "application.h" 
#include "mc_hardware_abstraction.h"  /** ToDO: Move it to header files */
#include "definitions.h"
#include "mc_utilities.h"
#include "mc_voltage_measurement.h"
#include "mc_motor.h"

/*******************************************************************************
 * Constants 
 *******************************************************************************/

/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct
{
    bool referenceFromPot;
    bool startFromButton;
    bool directionFromButton;
}tmcApp_GeneralFlags_s;
   
/*******************************************************************************
 Private variables 
 *******************************************************************************/
static button_response_t  mcAppI_DirectionButton_gds;
static button_response_t  mcAppI_StartStopButton_gds;
static uint32_t mcAppI_1msSyncCounter_gdu32;
static uintptr_t dummyForMisra;

/*******************************************************************************
 Interface variables 
 *******************************************************************************/
static tmcApp_GeneralFlags_s mcAppI_GeneralFlags_gds;

/*******************************************************************************
 Private Functions 
 *******************************************************************************/

 /*! \brief General flags initialization
 * 
 * Details.
 * General flags initialization
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_GeneralFlagsInit(void)
{
    mcAppI_GeneralFlags_gds.referenceFromPot = true;
    mcAppI_GeneralFlags_gds.startFromButton = true;
    mcAppI_GeneralFlags_gds.directionFromButton = true;
}


/*! \brief Start stop button scan
 *
 * Details.
 * Start stop button scan
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
/** ToDO: To replace later with a structure variable */
static uint8_t runStatus = 0u;
__STATIC_INLINE void mcAppI_MotorStartStop(void)
{
     if( 0u == runStatus )
     {
         /** Start motor  */
         mcFocI_FieldOrientedControlEnable( &mcFocI_ModuleData_gds );

         /** Enable voltage source inverter */
         mcHalI_InverterPwmEnable();

         runStatus = 1u;
     }
     else
     {
          /** Stop motor  */
          mcFocI_FieldOrientedControlDisable( &mcFocI_ModuleData_gds );

          /** Enable voltage source inverter */
          mcHalI_InverterPwmDisable();

          runStatus = 0u;
      }

     GPIO_PB13_Toggle();

}

/*! \brief Start stop button scan
 * 
 * Details.
 * Start stop button scan
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

__STATIC_INLINE void mcAppI_DirectionReverse(void)
{
     /** ToDO: Change state variable to toggle motor spin direction  */
//     mcFocI_MotorDirectionChange(&mcFocI_ModuleData_gds);

     GPIO_PB12_Toggle();
}

/*! \brief Read phase currents ADC input
 *
 * Details.
 * Read phase currents ADC input
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_INLINE void mcAppI_PhaseCurrentInputRead( void )
{
#if defined USE_THREE_SHUNT
    mcHalI_IaAdcInput_gdu16 = mcHalI_IaInputGet();
    mcHalI_IbAdcInput_gdu16 = mcHalI_IbInputGet();
    mcHalI_IcAdcInput_gdu16 = mcHalI_IcInputGet();
#elif defined USE_DUAL_SHUNT
    mcHalI_IaAdcInput_gdu16 = mcHalI_IaInputGet();
    mcHalI_IbAdcInput_gdu16 = mcHalI_IbInputGet();
#elif defined USE_SINGLE_SHUNT
    /** ToDO: */
#endif
}

/*! \brief 1 ms tasks handler
 *
 * Details.
 * 1 ms tasks handler
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_INLINE void mcAppI_1msTasksHandler( void )
{
    /** Start-stop button scan  */
    mcAppI_StartStopButton_gds.inputVal = mcHalI_StartStopButtonState();
    mcUtils_ButtonResponse(&mcAppI_StartStopButton_gds, &mcAppI_MotorStartStop);

    /** Direction button scan  */
    mcAppI_DirectionButton_gds.inputVal = mcHalI_DirectionButtonState();
    mcUtils_ButtonResponse(&mcAppI_DirectionButton_gds, &mcAppI_DirectionReverse);

    /** Field Oriented control - Slow Tasks */
    mcFocI_FieldOrientedControlSlow(&mcFocI_ModuleData_gds);
}

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
void mcAppI_ApplicationInit( void )
{   
     /** ADC end of conversion interrupt generation for FOC control */
      mcHalI_AdcInterruptDisable();
      mcHalI_AdcInterruptClear();

      /** Enable ADC interrupt for field oriented control */
      mcHalI_AdcCallBackRegister(  (ADC_CALLBACK)mcAppI_AdcCalibrationIsr, (uintptr_t)dummyForMisra );
      mcHalI_AdcInterruptEnable( );

      /** Enable ADC module */
      mcHalI_AdcEnable();

      /** Enable interrupt for fault detection */
      mcHalI_PwmCallbackRegister( (TCC_CALLBACK)mcAppI_OverCurrentReactionIsr, (uintptr_t)dummyForMisra );

      /** ToDO: Check if it is needed */
      // mcHalI_PwmInterruptEnable( );

      /** Enables PWM channels. */
      mcHalI_PwmTimerStart( );

      /** Disable PWM output */
      mcHalI_InverterPwmDisable();

      /** Initialize general flags */
      mcAppI_GeneralFlagsInit();

      /** Set motor parameters */
      mcMotorI_MotorParametersInit( &mcMotor_MotorParameters_gds);

      /** Initialize Current measurement  */
      mcCurI_CurrentCalculationInit( &mcCurI_ModuleData_gds );

      /** Initialize Voltage measurement  */
      mcVolI_VoltageCalculationInit( &mcVolI_ModuleData_gds );

      /** Initialize PMSM motor control */
      mcFocI_FieldOrientedControlInit( &mcFocI_ModuleData_gds);
}

/*! \brief Over current reaction ISR
 *
 * Details.
 * Fault reaction ISR
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_OverCurrentReactionIsr( uint32_t status,  uintptr_t context )
{
    /** Disable field oriented control  */
    mcFocI_FieldOrientedControlDisable( &mcFocI_ModuleData_gds );

    /** Reset software modules */
    mcAppI_ApplicationReset();

    /** Enable voltage source inverter */
    mcHalI_InverterPwmDisable();

}

/*! \brief Motor control application calibration
 * 
 * Details.
 *  Motor Control application calibration 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_AdcCalibrationIsr( ADC_STATUS status, uintptr_t context )
{    
    /** ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptDisable();
    mcHalI_AdcInterruptClear();

    /** Read phase currents  */
    mcHalI_PhaseACurrentGet();
    mcHalI_PhaseBCurrentGet();

    /** Current sense amplifiers offset calculation */
    if( 0u == mcCurI_ModuleData_gds.dOutput.calibDone )
    {
        mcCurI_CurrentSensorOffsetCalculate( &mcCurI_ModuleData_gds );
    }
    else
    {
        mcHalI_AdcCallBackRegister( (ADC_CALLBACK)mcAppI_AdcFinishedIsr, (uintptr_t)dummyForMisra );
    }

    /** Calibration and monitoring update */
    X2CScope_Update();

     /** ADC end of conversion interrupt generation for FOC control */
    mcHalI_AdcInterruptClear();
    mcHalI_AdcInterruptEnable();
}

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
#ifdef RAM_EXECUTE
void __ramfunc__  mcAppI_AdcFinishedIsr( ADC_STATUS status, uintptr_t context )
#else
void  mcAppI_AdcFinishedIsr( ADC_STATUS status, uintptr_t context )
#endif
{

  /** Band-width calculation ( determined by using LED toggling ):
   *            Motor control:  microsecond
   *            Total:   microsecond
   */

    /** ADC interrupt disable  */
    mcHalI_AdcInterruptDisable();
    mcHalI_AdcInterruptClear();

    /** Read phase currents  */
    mcHalI_PhaseACurrentGet();
    mcHalI_PhaseBCurrentGet();

    /** Re-assign ADC channels for DC link voltage and potentiometer input */
    mcHalI_DcLinkVoltageChannelSet();
    mcHalI_PotentiometerChannelSet();

    /** Trigger ADC channel conversion */
    mcHalI_AdcConversionTrigger();

    /** Current measurement  */
    mcCurI_CurrentCalculation( &mcCurI_ModuleData_gds );

    /** Field Oriented Control  */
    mcFocI_FieldOrientedControlFast(&mcFocI_ModuleData_gds);

    /** Set duty */
    mcHalI_InverterPwmSet(mcPwmI_Duty_gau16);

    /** Bus voltage calculation */
    mcVolI_VoltageCalculation( &mcVolI_ModuleData_gds );

    /** Wait for ADC conversion to complete */
    mcHalI_AdcConversionWait();

    /** Read DC bus voltage */
    mcHalI_DcLinkVoltageGet();

    /** Read potentiometer input */
    mcHalI_PotentiometerInputGet();

    /** Re-assign ADC Channels for phase current measurement at next PWM trigger */
    mcHalI_PhaseACurrentChannelSet();
    mcHalI_PhaseBCurrentChannelSet();

    /** Re-enable ADC hardware trigger */

    /** Calibration and monitoring update */
    X2CScope_Update();

    /** Increment interrupt counter */
    mcAppI_1msSyncCounter_gdu32++;

    /** ADC interrupt clear  */
    mcHalI_AdcInterruptClear();
    mcHalI_AdcInterruptEnable();
}

/*! \brief Non-ISR tasks
 *
 * Details.
 * Non-ISR tasks
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_NonISRTasks( void )
{
    float32_t loopCount = 0.001f * (float32_t)PWM_FREQUENCY;
    if( mcAppI_1msSyncCounter_gdu32 >= (uint32_t)loopCount )
    {
        mcAppI_1msSyncCounter_gdu32 = 0u;
        mcAppI_1msTasksHandler();
    }
}

/*! \brief Application reset 
 * 
 * Details.
 * Application reset 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcAppI_ApplicationReset( void )
{
    /** Current measurement  */
    mcCurI_CurrentCalculationReset( &mcCurI_ModuleData_gds );

    /** Voltage measurement  */
    mcVolI_VoltageCalculationReset( &mcVolI_ModuleData_gds );

    /** PMSM motor control */
    mcFocI_FieldOrientedControlReset( &mcFocI_ModuleData_gds);
}
