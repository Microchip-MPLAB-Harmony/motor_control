/*******************************************************************************
 System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt.c

  Summary:
    Interrupt vectors mapping

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

extern uint32_t _stack;

void Dummy_Handler(void);

/* Brief default interrupt handler for unused IRQs.*/
void __attribute__((optimize("-O1"),section(".text.Dummy_Handler"),long_call, noreturn))Dummy_Handler(void)
{
#if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
#endif
    while (1)
    {
    }
}
/* Device vectors list dummy definition*/
void Reset_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
void NonMaskableInt_Handler     ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HardFault_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
void MemoryManagement_Handler   ( void ) __attribute__((weak, alias("Dummy_Handler")));
void BusFault_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void UsageFault_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SVCall_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
void DebugMonitor_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PendSV_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SysTick_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SUPC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void RSTC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void RTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void RTT_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void WDT_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PMC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void MATRIX0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM0_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM1_InterruptHandler  ( void ) __attribute__((weak, alias("Dummy_Handler")));
void NMIC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PIOA_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PIOB_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PIOC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM2_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM4_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PIOD_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PIOE_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void CCW_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void CCF_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FPU_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void IXC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM5_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM6_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM7_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC0_CH0_InterruptHandler   ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC0_CH1_InterruptHandler   ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC0_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC1_CH0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC1_CH1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC1_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PWM0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PWM1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void ICM_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PIOF_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void PIOG_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void MCAN0_INT0_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
void MCAN0_INT1_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
void MCAN1_INT0_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
void MCAN1_INT1_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TCMECC_INTFIX_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TCMECC_INTNOFIX_Handler    ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXRAMECC_INTFIX_Handler  ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXRAMECC_INTNOFIX_Handler ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SHA_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM8_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void FLEXCOM9_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
void WDT1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void QSPI_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HEFC_INT0_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HEFC_INTFIX_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HEFC_INTNOFIX_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC2_CH0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC2_CH1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC2_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC3_CH0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC3_CH1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TC3_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HEMC_INTSDRAMC_Handler     ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HEMC_INTFIX_Handler        ( void ) __attribute__((weak, alias("Dummy_Handler")));
void HEMC_INTNOFIX_Handler      ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SFR_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void TRNG_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void XDMAC_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
void SPW_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
void IP1553_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
void GMAC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
void GMAC_Q1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void GMAC_Q2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void GMAC_Q3_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void GMAC_Q4_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
void GMAC_Q5_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));



/* Mutiple handlers for vector */



__attribute__ ((section(".vectors")))
const DeviceVectors exception_table=
{
    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = (void*) (&_stack),

    .pfnReset_Handler              = ( void * ) Reset_Handler,
    .pfnNonMaskableInt_Handler     = ( void * ) NonMaskableInt_Handler,
    .pfnHardFault_Handler          = ( void * ) HardFault_Handler,
    .pfnMemoryManagement_Handler   = ( void * ) MemoryManagement_Handler,
    .pfnBusFault_Handler           = ( void * ) BusFault_Handler,
    .pfnUsageFault_Handler         = ( void * ) UsageFault_Handler,
    .pfnSVCall_Handler             = ( void * ) SVCall_Handler,
    .pfnDebugMonitor_Handler       = ( void * ) DebugMonitor_Handler,
    .pfnPendSV_Handler             = ( void * ) PendSV_Handler,
    .pfnSysTick_Handler            = ( void * ) SysTick_Handler,
    .pfnSUPC_Handler               = ( void * ) SUPC_Handler,
    .pfnRSTC_Handler               = ( void * ) RSTC_Handler,
    .pfnRTC_Handler                = ( void * ) RTC_Handler,
    .pfnRTT_Handler                = ( void * ) RTT_Handler,
    .pfnWDT_Handler                = ( void * ) WDT_Handler,
    .pfnPMC_Handler                = ( void * ) PMC_Handler,
    .pfnMATRIX0_Handler            = ( void * ) MATRIX0_Handler,
    .pfnFLEXCOM0_Handler           = ( void * ) FLEXCOM0_Handler,
    .pfnFLEXCOM1_Handler           = ( void * ) FLEXCOM1_InterruptHandler,
    .pfnNMIC_Handler               = ( void * ) NMIC_Handler,
    .pfnPIOA_Handler               = ( void * ) PIOA_Handler,
    .pfnPIOB_Handler               = ( void * ) PIOB_Handler,
    .pfnPIOC_Handler               = ( void * ) PIOC_Handler,
    .pfnFLEXCOM2_Handler           = ( void * ) FLEXCOM2_Handler,
    .pfnFLEXCOM3_Handler           = ( void * ) FLEXCOM3_Handler,
    .pfnFLEXCOM4_Handler           = ( void * ) FLEXCOM4_Handler,
    .pfnPIOD_Handler               = ( void * ) PIOD_Handler,
    .pfnPIOE_Handler               = ( void * ) PIOE_Handler,
    .pfnCCW_Handler                = ( void * ) CCW_Handler,
    .pfnCCF_Handler                = ( void * ) CCF_Handler,
    .pfnFPU_Handler                = ( void * ) FPU_Handler,
    .pfnIXC_Handler                = ( void * ) IXC_Handler,
    .pfnFLEXCOM5_Handler           = ( void * ) FLEXCOM5_Handler,
    .pfnFLEXCOM6_Handler           = ( void * ) FLEXCOM6_Handler,
    .pfnFLEXCOM7_Handler           = ( void * ) FLEXCOM7_Handler,
    .pfnTC0_CH0_Handler            = ( void * ) TC0_CH0_InterruptHandler,
    .pfnTC0_CH1_Handler            = ( void * ) TC0_CH1_InterruptHandler,
    .pfnTC0_CH2_Handler            = ( void * ) TC0_CH2_Handler,
    .pfnTC1_CH0_Handler            = ( void * ) TC1_CH0_Handler,
    .pfnTC1_CH1_Handler            = ( void * ) TC1_CH1_Handler,
    .pfnTC1_CH2_Handler            = ( void * ) TC1_CH2_Handler,
    .pfnPWM0_Handler               = ( void * ) PWM0_Handler,
    .pfnPWM1_Handler               = ( void * ) PWM1_Handler,
    .pfnICM_Handler                = ( void * ) ICM_Handler,
    .pfnPIOF_Handler               = ( void * ) PIOF_Handler,
    .pfnPIOG_Handler               = ( void * ) PIOG_Handler,
    .pfnMCAN0_INT0_Handler         = ( void * ) MCAN0_INT0_Handler,
    .pfnMCAN0_INT1_Handler         = ( void * ) MCAN0_INT1_Handler,
    .pfnMCAN1_INT0_Handler         = ( void * ) MCAN1_INT0_Handler,
    .pfnMCAN1_INT1_Handler         = ( void * ) MCAN1_INT1_Handler,
    .pfnTCMECC_INTFIX_Handler      = ( void * ) TCMECC_INTFIX_Handler,
    .pfnTCMECC_INTNOFIX_Handler    = ( void * ) TCMECC_INTNOFIX_Handler,
    .pfnFLEXRAMECC_INTFIX_Handler  = ( void * ) FLEXRAMECC_INTFIX_Handler,
    .pfnFLEXRAMECC_INTNOFIX_Handler = ( void * ) FLEXRAMECC_INTNOFIX_Handler,
    .pfnSHA_Handler                = ( void * ) SHA_Handler,
    .pfnFLEXCOM8_Handler           = ( void * ) FLEXCOM8_Handler,
    .pfnFLEXCOM9_Handler           = ( void * ) FLEXCOM9_Handler,
    .pfnWDT1_Handler               = ( void * ) WDT1_Handler,
    .pfnQSPI_Handler               = ( void * ) QSPI_Handler,
    .pfnHEFC_INT0_Handler          = ( void * ) HEFC_INT0_Handler,
    .pfnHEFC_INTFIX_Handler        = ( void * ) HEFC_INTFIX_Handler,
    .pfnHEFC_INTNOFIX_Handler      = ( void * ) HEFC_INTNOFIX_Handler,
    .pfnTC2_CH0_Handler            = ( void * ) TC2_CH0_Handler,
    .pfnTC2_CH1_Handler            = ( void * ) TC2_CH1_Handler,
    .pfnTC2_CH2_Handler            = ( void * ) TC2_CH2_Handler,
    .pfnTC3_CH0_Handler            = ( void * ) TC3_CH0_Handler,
    .pfnTC3_CH1_Handler            = ( void * ) TC3_CH1_Handler,
    .pfnTC3_CH2_Handler            = ( void * ) TC3_CH2_Handler,
    .pfnHEMC_INTSDRAMC_Handler     = ( void * ) HEMC_INTSDRAMC_Handler,
    .pfnHEMC_INTFIX_Handler        = ( void * ) HEMC_INTFIX_Handler,
    .pfnHEMC_INTNOFIX_Handler      = ( void * ) HEMC_INTNOFIX_Handler,
    .pfnSFR_Handler                = ( void * ) SFR_Handler,
    .pfnTRNG_Handler               = ( void * ) TRNG_Handler,
    .pfnXDMAC_Handler              = ( void * ) XDMAC_Handler,
    .pfnSPW_Handler                = ( void * ) SPW_Handler,
    .pfnIP1553_Handler             = ( void * ) IP1553_Handler,
    .pfnGMAC_Handler               = ( void * ) GMAC_Handler,
    .pfnGMAC_Q1_Handler            = ( void * ) GMAC_Q1_Handler,
    .pfnGMAC_Q2_Handler            = ( void * ) GMAC_Q2_Handler,
    .pfnGMAC_Q3_Handler            = ( void * ) GMAC_Q3_Handler,
    .pfnGMAC_Q4_Handler            = ( void * ) GMAC_Q4_Handler,
    .pfnGMAC_Q5_Handler            = ( void * ) GMAC_Q5_Handler,


};

/*******************************************************************************
 End of File
*/
