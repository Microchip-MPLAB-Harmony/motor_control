/**
 * \brief Header file for ATSAMRH71F20C
 *
 * Copyright (c) 2020 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2020-07-08T08:12:01Z */
#ifndef _SAMRH71F20C_H_
#define _SAMRH71F20C_H_

// Header version uses Semantic Versioning 2.0.0 (https://semver.org/)
#define HEADER_FORMAT_VERSION "2.0.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (0)

/** \addtogroup SAMRH71F20C_definitions SAMRH71F20C definitions
  This file defines all structures and symbols for SAMRH71F20C:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
 *  @{
 */

#ifdef __cplusplus
 extern "C" {
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)
#  if defined(_U_) || defined(_L_) || defined(_UL_)
#    error "Integer Literals macros already defined elsewhere"
#  endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with adding suffixes to integer literal constants for C/C++ */
#  define _U_(x) (x ## U)    /**< C code: Unsigned integer literal constant value */
#  define _L_(x) (x ## L)    /**< C code: Long integer literal constant value */
#  define _UL_(x) (x ## UL)  /**< C code: Unsigned Long integer literal constant value */

#else /* Assembler */

#  define _U_(x) x    /**< Assembler: Unsigned integer literal constant value */
#  define _L_(x) x    /**< Assembler: Long integer literal constant value */
#  define _UL_(x) x   /**< Assembler: Unsigned Long integer literal constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* SKIP_INTEGER_LITERALS */
/** @}  end of Atmel Global Defines */

/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR SAMRH71F20C                                        */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M7 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /**< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /**< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /**< -13 Hard Fault, all classes of Fault    */
  MemoryManagement_IRQn     = -12, /**< -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11, /**< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn           = -10, /**< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SVCall_IRQn               =  -5, /**< -5  System Service Call via SVC instruction */
  DebugMonitor_IRQn         =  -4, /**< -4  Debug Monitor                       */
  PendSV_IRQn               =  -2, /**< -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /**< -1  System Tick Timer                   */
/******  SAMRH71F20C specific Interrupt Numbers ***********************************/
  SUPC_IRQn                 =   0, /**< 0   Supply Controller (SUPC)            */
  RSTC_IRQn                 =   1, /**< 1   Reset Controller (RSTC)             */
  RTC_IRQn                  =   2, /**< 2   Real-time Clock (RTC)               */
  RTT_IRQn                  =   3, /**< 3   Real-time Timer (RTT)               */
  WDT_IRQn                  =   4, /**< 4   Watchdog Timer (WDT)                */
  PMC_IRQn                  =   5, /**< 5   Power Management Controller (PMC)   */
  MATRIX0_IRQn              =   6, /**< 6   AHB Bus Matrix (MATRIX0)            */
  FLEXCOM0_IRQn             =   7, /**< 7   Flexible Serial Communication (FLEXCOM0) */
  FLEXCOM1_IRQn             =   8, /**< 8   Flexible Serial Communication (FLEXCOM1) */
  NMIC_IRQn                 =   9, /**< 9   Non-maskable Interrupt Controller (NMIC) */
  PIOA_IRQn                 =  10, /**< 10  Parallel Input/Output Controller (PIOA) */
  PIOB_IRQn                 =  11, /**< 11  Parallel Input/Output Controller (PIOB) */
  PIOC_IRQn                 =  12, /**< 12  Parallel Input/Output Controller (PIOC) */
  FLEXCOM2_IRQn             =  13, /**< 13  Flexible Serial Communication (FLEXCOM2) */
  FLEXCOM3_IRQn             =  14, /**< 14  Flexible Serial Communication (FLEXCOM3) */
  FLEXCOM4_IRQn             =  15, /**< 15  Flexible Serial Communication (FLEXCOM4) */
  PIOD_IRQn                 =  16, /**< 16  Parallel Input/Output Controller (PIOD) */
  PIOE_IRQn                 =  17, /**< 17  Parallel Input/Output Controller (PIOE) */
  CCW_IRQn                  =  18, /**< 18  System Control Block (SCB)          */
  CCF_IRQn                  =  19, /**< 19  System Control Block (SCB)          */
  FPU_IRQn                  =  20, /**< 20  Floating Point Unit (FPU)           */
  IXC_IRQn                  =  21, /**< 21  Floating Point Unit (FPU)           */
  FLEXCOM5_IRQn             =  22, /**< 22  Flexible Serial Communication (FLEXCOM5) */
  FLEXCOM6_IRQn             =  23, /**< 23  Flexible Serial Communication (FLEXCOM6) */
  FLEXCOM7_IRQn             =  24, /**< 24  Flexible Serial Communication (FLEXCOM7) */
  TC0_CH0_IRQn              =  25, /**< 25  Timer/Counter 0 Channel 0 (TC0)     */
  TC0_CH1_IRQn              =  26, /**< 26  Timer/Counter 0 Channel 1 (TC0)     */
  TC0_CH2_IRQn              =  27, /**< 27  Timer/Counter 0 Channel 2 (TC0)     */
  TC1_CH0_IRQn              =  28, /**< 28  Timer/Counter 1 Channel 0 (TC1)     */
  TC1_CH1_IRQn              =  29, /**< 29  Timer/Counter 1 Channel 1 (TC1)     */
  TC1_CH2_IRQn              =  30, /**< 30  Timer/Counter 1 Channel 2 (TC1)     */
  PWM0_IRQn                 =  31, /**< 31  Pulse Width Modulation Controller (PWM0) */
  PWM1_IRQn                 =  32, /**< 32  Pulse Width Modulation Controller (PWM1) */
  ICM_IRQn                  =  33, /**< 33  Integrity Check Monitor (ICM)       */
  PIOF_IRQn                 =  34, /**< 34  Parallel Input/Output Controller (PIOF) */
  PIOG_IRQn                 =  35, /**< 35  Parallel Input/Output Controller (PIOG) */
  MCAN0_INT0_IRQn           =  36, /**< 36  Controller Area Network (MCAN0)     */
  MCAN0_INT1_IRQn           =  37, /**< 37  Controller Area Network (MCAN0)     */
  MCAN1_INT0_IRQn           =  38, /**< 38  Controller Area Network (MCAN1)     */
  MCAN1_INT1_IRQn           =  39, /**< 39  Controller Area Network (MCAN1)     */
  TCMECC_INTFIX_IRQn        =  40, /**< 40  HECC (TCMECC)                       */
  TCMECC_INTNOFIX_IRQn      =  41, /**< 41  HECC (TCMECC)                       */
  FLEXRAMECC_INTFIX_IRQn    =  42, /**< 42  FLEXRAMECC (FLEXRAMECC)             */
  FLEXRAMECC_INTNOFIX_IRQn  =  43, /**< 43  FLEXRAMECC (FLEXRAMECC)             */
  SHA_IRQn                  =  44, /**< 44  Secure Hash Algorithm (SHA)         */
  FLEXCOM8_IRQn             =  45, /**< 45  Flexible Serial Communication (FLEXCOM8) */
  FLEXCOM9_IRQn             =  46, /**< 46  Flexible Serial Communication (FLEXCOM9) */
  WDT1_IRQn                 =  47, /**< 47  Watchdog Timer (WDT1)               */
  QSPI_IRQn                 =  49, /**< 49  Quad Serial Peripheral Interface (QSPI) */
  HEFC_INT0_IRQn            =  50, /**< 50  Harden Embedded Flash Controller (HEFC) */
  HEFC_INTFIX_IRQn          =  51, /**< 51  Harden Embedded Flash Controller (HEFC) */
  HEFC_INTNOFIX_IRQn        =  52, /**< 52  Harden Embedded Flash Controller (HEFC) */
  TC2_CH0_IRQn              =  53, /**< 53  Timer/Counter 2 Channel 0 (TC2)     */
  TC2_CH1_IRQn              =  54, /**< 54  Timer/Counter 2 Channel 1 (TC2)     */
  TC2_CH2_IRQn              =  55, /**< 55  Timer/Counter 2 Channel 2 (TC2)     */
  TC3_CH0_IRQn              =  56, /**< 56  Timer/Counter 3 Channel 0 (TC3)     */
  TC3_CH1_IRQn              =  57, /**< 57  Timer/Counter 3 Channel 1 (TC3)     */
  TC3_CH2_IRQn              =  58, /**< 58  Timer/Counter 3 Channel 2 (TC3)     */
  HEMC_INTSDRAMC_IRQn       =  59, /**< 59  HEMC (HEMC)                         */
  HEMC_INTFIX_IRQn          =  60, /**< 60  HEMC (HEMC)                         */
  HEMC_INTNOFIX_IRQn        =  61, /**< 61  HEMC (HEMC)                         */
  SFR_IRQn                  =  62, /**< 62  Special Function Registers (SFR)    */
  TRNG_IRQn                 =  63, /**< 63  True Random Number Generator (TRNG) */
  XDMAC_IRQn                =  64, /**< 64  Extensible DMA Controller (XDMAC)   */
  SPW_IRQn                  =  65, /**< 65  SpW (SPW)                           */
  IP1553_IRQn               =  68, /**< 68  IP 1553 (IP1553)                    */
  GMAC_IRQn                 =  69, /**< 69  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q1_IRQn              =  70, /**< 70  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q2_IRQn              =  71, /**< 71  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q3_IRQn              =  72, /**< 72  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q4_IRQn              =  73, /**< 73  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q5_IRQn              =  74, /**< 74  Gigabit Ethernet MAC (GMAC)         */

  PERIPH_MAX_IRQn           =  74  /**< Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M7 handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnSUPC_Handler;                         /*   0 Supply Controller (SUPC) */
  void* pfnRSTC_Handler;                         /*   1 Reset Controller (RSTC) */
  void* pfnRTC_Handler;                          /*   2 Real-time Clock (RTC) */
  void* pfnRTT_Handler;                          /*   3 Real-time Timer (RTT) */
  void* pfnWDT_Handler;                          /*   4 Watchdog Timer (WDT) */
  void* pfnPMC_Handler;                          /*   5 Power Management Controller (PMC) */
  void* pfnMATRIX0_Handler;                      /*   6 AHB Bus Matrix (MATRIX0) */
  void* pfnFLEXCOM0_Handler;                     /*   7 Flexible Serial Communication (FLEXCOM0) */
  void* pfnFLEXCOM1_Handler;                     /*   8 Flexible Serial Communication (FLEXCOM1) */
  void* pfnNMIC_Handler;                         /*   9 Non-maskable Interrupt Controller (NMIC) */
  void* pfnPIOA_Handler;                         /*  10 Parallel Input/Output Controller (PIOA) */
  void* pfnPIOB_Handler;                         /*  11 Parallel Input/Output Controller (PIOB) */
  void* pfnPIOC_Handler;                         /*  12 Parallel Input/Output Controller (PIOC) */
  void* pfnFLEXCOM2_Handler;                     /*  13 Flexible Serial Communication (FLEXCOM2) */
  void* pfnFLEXCOM3_Handler;                     /*  14 Flexible Serial Communication (FLEXCOM3) */
  void* pfnFLEXCOM4_Handler;                     /*  15 Flexible Serial Communication (FLEXCOM4) */
  void* pfnPIOD_Handler;                         /*  16 Parallel Input/Output Controller (PIOD) */
  void* pfnPIOE_Handler;                         /*  17 Parallel Input/Output Controller (PIOE) */
  void* pfnCCW_Handler;                          /*  18 System Control Block (SCB) */
  void* pfnCCF_Handler;                          /*  19 System Control Block (SCB) */
  void* pfnFPU_Handler;                          /*  20 Floating Point Unit (FPU) */
  void* pfnIXC_Handler;                          /*  21 Floating Point Unit (FPU) */
  void* pfnFLEXCOM5_Handler;                     /*  22 Flexible Serial Communication (FLEXCOM5) */
  void* pfnFLEXCOM6_Handler;                     /*  23 Flexible Serial Communication (FLEXCOM6) */
  void* pfnFLEXCOM7_Handler;                     /*  24 Flexible Serial Communication (FLEXCOM7) */
  void* pfnTC0_CH0_Handler;                      /*  25 Timer/Counter 0 Channel 0 (TC0) */
  void* pfnTC0_CH1_Handler;                      /*  26 Timer/Counter 0 Channel 1 (TC0) */
  void* pfnTC0_CH2_Handler;                      /*  27 Timer/Counter 0 Channel 2 (TC0) */
  void* pfnTC1_CH0_Handler;                      /*  28 Timer/Counter 1 Channel 0 (TC1) */
  void* pfnTC1_CH1_Handler;                      /*  29 Timer/Counter 1 Channel 1 (TC1) */
  void* pfnTC1_CH2_Handler;                      /*  30 Timer/Counter 1 Channel 2 (TC1) */
  void* pfnPWM0_Handler;                         /*  31 Pulse Width Modulation Controller (PWM0) */
  void* pfnPWM1_Handler;                         /*  32 Pulse Width Modulation Controller (PWM1) */
  void* pfnICM_Handler;                          /*  33 Integrity Check Monitor (ICM) */
  void* pfnPIOF_Handler;                         /*  34 Parallel Input/Output Controller (PIOF) */
  void* pfnPIOG_Handler;                         /*  35 Parallel Input/Output Controller (PIOG) */
  void* pfnMCAN0_INT0_Handler;                   /*  36 Controller Area Network (MCAN0) */
  void* pfnMCAN0_INT1_Handler;                   /*  37 Controller Area Network (MCAN0) */
  void* pfnMCAN1_INT0_Handler;                   /*  38 Controller Area Network (MCAN1) */
  void* pfnMCAN1_INT1_Handler;                   /*  39 Controller Area Network (MCAN1) */
  void* pfnTCMECC_INTFIX_Handler;                /*  40 HECC (TCMECC) */
  void* pfnTCMECC_INTNOFIX_Handler;              /*  41 HECC (TCMECC) */
  void* pfnFLEXRAMECC_INTFIX_Handler;            /*  42 FLEXRAMECC (FLEXRAMECC) */
  void* pfnFLEXRAMECC_INTNOFIX_Handler;          /*  43 FLEXRAMECC (FLEXRAMECC) */
  void* pfnSHA_Handler;                          /*  44 Secure Hash Algorithm (SHA) */
  void* pfnFLEXCOM8_Handler;                     /*  45 Flexible Serial Communication (FLEXCOM8) */
  void* pfnFLEXCOM9_Handler;                     /*  46 Flexible Serial Communication (FLEXCOM9) */
  void* pfnWDT1_Handler;                         /*  47 Watchdog Timer (WDT1) */
  void* pvReserved48;
  void* pfnQSPI_Handler;                         /*  49 Quad Serial Peripheral Interface (QSPI) */
  void* pfnHEFC_INT0_Handler;                    /*  50 Harden Embedded Flash Controller (HEFC) */
  void* pfnHEFC_INTFIX_Handler;                  /*  51 Harden Embedded Flash Controller (HEFC) */
  void* pfnHEFC_INTNOFIX_Handler;                /*  52 Harden Embedded Flash Controller (HEFC) */
  void* pfnTC2_CH0_Handler;                      /*  53 Timer/Counter 2 Channel 0 (TC2) */
  void* pfnTC2_CH1_Handler;                      /*  54 Timer/Counter 2 Channel 1 (TC2) */
  void* pfnTC2_CH2_Handler;                      /*  55 Timer/Counter 2 Channel 2 (TC2) */
  void* pfnTC3_CH0_Handler;                      /*  56 Timer/Counter 3 Channel 0 (TC3) */
  void* pfnTC3_CH1_Handler;                      /*  57 Timer/Counter 3 Channel 1 (TC3) */
  void* pfnTC3_CH2_Handler;                      /*  58 Timer/Counter 3 Channel 2 (TC3) */
  void* pfnHEMC_INTSDRAMC_Handler;               /*  59 HEMC (HEMC) */
  void* pfnHEMC_INTFIX_Handler;                  /*  60 HEMC (HEMC) */
  void* pfnHEMC_INTNOFIX_Handler;                /*  61 HEMC (HEMC) */
  void* pfnSFR_Handler;                          /*  62 Special Function Registers (SFR) */
  void* pfnTRNG_Handler;                         /*  63 True Random Number Generator (TRNG) */
  void* pfnXDMAC_Handler;                        /*  64 Extensible DMA Controller (XDMAC) */
  void* pfnSPW_Handler;                          /*  65 SpW (SPW) */
  void* pvReserved66;
  void* pvReserved67;
  void* pfnIP1553_Handler;                       /*  68 IP 1553 (IP1553) */
  void* pfnGMAC_Handler;                         /*  69 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q1_Handler;                      /*  70 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q2_Handler;                      /*  71 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q3_Handler;                      /*  72 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q4_Handler;                      /*  73 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q5_Handler;                      /*  74 Gigabit Ethernet MAC (GMAC) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M7 exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void SUPC_Handler                  ( void );
void RSTC_Handler                  ( void );
void RTC_Handler                   ( void );
void RTT_Handler                   ( void );
void WDT_Handler                   ( void );
void PMC_Handler                   ( void );
void MATRIX0_Handler               ( void );
void FLEXCOM0_Handler              ( void );
void FLEXCOM1_Handler              ( void );
void NMIC_Handler                  ( void );
void PIOA_Handler                  ( void );
void PIOB_Handler                  ( void );
void PIOC_Handler                  ( void );
void FLEXCOM2_Handler              ( void );
void FLEXCOM3_Handler              ( void );
void FLEXCOM4_Handler              ( void );
void PIOD_Handler                  ( void );
void PIOE_Handler                  ( void );
void CCW_Handler                   ( void );
void CCF_Handler                   ( void );
void FPU_Handler                   ( void );
void IXC_Handler                   ( void );
void FLEXCOM5_Handler              ( void );
void FLEXCOM6_Handler              ( void );
void FLEXCOM7_Handler              ( void );
void TC0_CH0_Handler               ( void );
void TC0_CH1_Handler               ( void );
void TC0_CH2_Handler               ( void );
void TC1_CH0_Handler               ( void );
void TC1_CH1_Handler               ( void );
void TC1_CH2_Handler               ( void );
void PWM0_Handler                  ( void );
void PWM1_Handler                  ( void );
void ICM_Handler                   ( void );
void PIOF_Handler                  ( void );
void PIOG_Handler                  ( void );
void MCAN0_INT0_Handler            ( void );
void MCAN0_INT1_Handler            ( void );
void MCAN1_INT0_Handler            ( void );
void MCAN1_INT1_Handler            ( void );
void TCMECC_INTFIX_Handler         ( void );
void TCMECC_INTNOFIX_Handler       ( void );
void FLEXRAMECC_INTFIX_Handler     ( void );
void FLEXRAMECC_INTNOFIX_Handler   ( void );
void SHA_Handler                   ( void );
void FLEXCOM8_Handler              ( void );
void FLEXCOM9_Handler              ( void );
void WDT1_Handler                  ( void );
void QSPI_Handler                  ( void );
void HEFC_INT0_Handler             ( void );
void HEFC_INTFIX_Handler           ( void );
void HEFC_INTNOFIX_Handler         ( void );
void TC2_CH0_Handler               ( void );
void TC2_CH1_Handler               ( void );
void TC2_CH2_Handler               ( void );
void TC3_CH0_Handler               ( void );
void TC3_CH1_Handler               ( void );
void TC3_CH2_Handler               ( void );
void HEMC_INTSDRAMC_Handler        ( void );
void HEMC_INTFIX_Handler           ( void );
void HEMC_INTNOFIX_Handler         ( void );
void SFR_Handler                   ( void );
void TRNG_Handler                  ( void );
void XDMAC_Handler                 ( void );
void SPW_Handler                   ( void );
void IP1553_Handler                ( void );
void GMAC_Handler                  ( void );
void GMAC_Q1_Handler               ( void );
void GMAC_Q2_Handler               ( void );
void GMAC_Q3_Handler               ( void );
void GMAC_Q4_Handler               ( void );
void GMAC_Q5_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/** \brief Configuration of the CORTEX-M7 Processor and Core Peripherals */
#define __CM7_REV                 0x0101 /**< CM7 Core Revision                                                         */
#define __NVIC_PRIO_BITS               3 /**< Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig         0 /**< Set to 1 if different SysTick Config is used                              */
#define __MPU_PRESENT                  1 /**< MPU present or not                                                        */
#define __VTOR_PRESENT                 1 /**< Vector Table Offset Register present or not                               */
#define __FPU_PRESENT                  1 /**< FPU present or not                                                        */
#define __FPU_DP                       1 /**< Double Precision FPU                                                      */
#define __ICACHE_PRESENT               1 /**< Instruction Cache present                                                 */
#define __DCACHE_PRESENT               1 /**< Data Cache present                                                        */
#define __ITCM_PRESENT                 1 /**< Instruction TCM present                                                   */
#define __DTCM_PRESENT                 1 /**< Data TCM present                                                          */
#define __DEBUG_LVL                    1
#define __TRACE_LVL                    1
#define __ARCH_ARM                     1
#define __ARCH_ARM_CORTEX_M            1

/*
 * \brief CMSIS includes
 */
#include "core_cm7.h"
#if defined USE_CMSIS_INIT
#include "system_samrh71.h"
#endif /* USE_CMSIS_INIT */

/** \defgroup SAMRH71F20C_api Peripheral Software API
 *  @{
 */

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR SAMRH71F20C                       */
/* ************************************************************************** */
#include "component/chipid.h"
#include "component/flexcom.h"
#include "component/flexramecc.h"
#include "component/gmac.h"
#include "component/hefc.h"
#include "component/hemc.h"
#include "component/hsdramc.h"
#include "component/hsmc.h"
#include "component/icm.h"
#include "component/ip1553.h"
#include "component/matrix.h"
#include "component/mcan.h"
#include "component/nmic.h"
#include "component/pio.h"
#include "component/pmc.h"
#include "component/pwm.h"
#include "component/qspi.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/sfr.h"
#include "component/sha.h"
#include "component/spw.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/tcmecc.h"
#include "component/trng.h"
#include "component/wdt.h"
#include "component/xdmac.h"
/** @}  end of Peripheral Software API */

/** \addtogroup SAMRH71F20C_id Peripheral Ids Definitions
 *  @{
 */

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR SAMRH71F20C                                 */
/* ************************************************************************** */
#define ID_SUPC          (  0) /**< \brief Supply Controller (SUPC) */
#define ID_RSTC          (  1) /**< \brief Reset Controller (RSTC) */
#define ID_RTC           (  2) /**< \brief Real-time Clock (RTC) */
#define ID_RTT           (  3) /**< \brief Real-time Timer (RTT) */
#define ID_WDT           (  4) /**< \brief Watchdog Timer (WDT) */
#define ID_PMC           (  5) /**< \brief Power Management Controller (PMC) */
#define ID_MATRIX0       (  6) /**< \brief AHB Bus Matrix (MATRIX0) */
#define ID_FLEXCOM0      (  7) /**< \brief Flexible Serial Communication (FLEXCOM0) */
#define ID_FLEXCOM1      (  8) /**< \brief Flexible Serial Communication (FLEXCOM1) */
#define ID_NMIC          (  9) /**< \brief Non-maskable Interrupt Controller (NMIC) */
#define ID_PIOA          ( 10) /**< \brief Parallel Input/Output Controller (PIOA) */
#define ID_PIOB          ( 11) /**< \brief Parallel Input/Output Controller (PIOB) */
#define ID_PIOC          ( 12) /**< \brief Parallel Input/Output Controller (PIOC) */
#define ID_FLEXCOM2      ( 13) /**< \brief Flexible Serial Communication (FLEXCOM2) */
#define ID_FLEXCOM3      ( 14) /**< \brief Flexible Serial Communication (FLEXCOM3) */
#define ID_FLEXCOM4      ( 15) /**< \brief Flexible Serial Communication (FLEXCOM4) */
#define ID_PIOD          ( 16) /**< \brief Parallel Input/Output Controller (PIOD) */
#define ID_PIOE          ( 17) /**< \brief Parallel Input/Output Controller (PIOE) */
#define ID_FLEXCOM5      ( 22) /**< \brief Flexible Serial Communication (FLEXCOM5) */
#define ID_FLEXCOM6      ( 23) /**< \brief Flexible Serial Communication (FLEXCOM6) */
#define ID_FLEXCOM7      ( 24) /**< \brief Flexible Serial Communication (FLEXCOM7) */
#define ID_TC0_CHANNEL0  ( 25) /**< \brief Timer Counter (TC0_CHANNEL0) */
#define ID_TC0_CHANNEL1  ( 26) /**< \brief Timer Counter (TC0_CHANNEL1) */
#define ID_TC0_CHANNEL2  ( 27) /**< \brief Timer Counter (TC0_CHANNEL2) */
#define ID_TC1_CHANNEL0  ( 28) /**< \brief Timer Counter (TC1_CHANNEL0) */
#define ID_TC1_CHANNEL1  ( 29) /**< \brief Timer Counter (TC1_CHANNEL1) */
#define ID_TC1_CHANNEL2  ( 30) /**< \brief Timer Counter (TC1_CHANNEL2) */
#define ID_PWM0          ( 31) /**< \brief Pulse Width Modulation Controller (PWM0) */
#define ID_PWM1          ( 32) /**< \brief Pulse Width Modulation Controller (PWM1) */
#define ID_ICM           ( 33) /**< \brief Integrity Check Monitor (ICM) */
#define ID_PIOF          ( 34) /**< \brief Parallel Input/Output Controller (PIOF) */
#define ID_PIOG          ( 35) /**< \brief Parallel Input/Output Controller (PIOG) */
#define ID_MCAN0         ( 36) /**< \brief Controller Area Network (MCAN0) */
#define ID_MCAN1         ( 38) /**< \brief Controller Area Network (MCAN1) */
#define ID_SHA           ( 44) /**< \brief Secure Hash Algorithm (SHA) */
#define ID_FLEXCOM8      ( 45) /**< \brief Flexible Serial Communication (FLEXCOM8) */
#define ID_FLEXCOM9      ( 46) /**< \brief Flexible Serial Communication (FLEXCOM9) */
#define ID_WDT1          ( 47) /**< \brief Watchdog Timer (WDT1) */
#define ID_QSPI          ( 49) /**< \brief Quad Serial Peripheral Interface (QSPI) */
#define ID_HEFC          ( 50) /**< \brief Harden Embedded Flash Controller (HEFC) */
#define ID_TC2_CHANNEL0  ( 53) /**< \brief Timer Counter (TC2_CHANNEL0) */
#define ID_TC2_CHANNEL1  ( 54) /**< \brief Timer Counter (TC2_CHANNEL1) */
#define ID_TC2_CHANNEL2  ( 55) /**< \brief Timer Counter (TC2_CHANNEL2) */
#define ID_TC3_CHANNEL0  ( 56) /**< \brief Timer Counter (TC3_CHANNEL0) */
#define ID_TC3_CHANNEL1  ( 57) /**< \brief Timer Counter (TC3_CHANNEL1) */
#define ID_TC3_CHANNEL2  ( 58) /**< \brief Timer Counter (TC3_CHANNEL2) */
#define ID_TRNG          ( 63) /**< \brief True Random Number Generator (TRNG) */
#define ID_XDMAC         ( 64) /**< \brief Extensible DMA Controller (XDMAC) */
#define ID_SPW_SPW       ( 65) /**< \brief SpW (SPW_SPW) */
#define ID_SPW_SPW_TIMETICK ( 66) /**< \brief SpW (SPW_SPW_TIMETICK) */
#define ID_IP1553        ( 68) /**< \brief IP 1553 (IP1553) */
#define ID_GMAC          ( 69) /**< \brief Gigabit Ethernet MAC (GMAC) */

#define ID_PERIPH_MAX    ( 69) /**< \brief Number of peripheral IDs */
/** @}  end of Peripheral Ids Definitions */

/** \addtogroup SAMRH71F20C_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR SAMRH71F20C                   */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define CHIPID_REGS                      ((chipid_registers_t*)0x40100000)             /**< \brief CHIPID Registers Address     */
#define FLEXCOM0_REGS                    ((flexcom_registers_t*)0x40010000)            /**< \brief FLEXCOM0 Registers Address   */
#define FLEXCOM1_REGS                    ((flexcom_registers_t*)0x40014000)            /**< \brief FLEXCOM1 Registers Address   */
#define FLEXCOM2_REGS                    ((flexcom_registers_t*)0x40018000)            /**< \brief FLEXCOM2 Registers Address   */
#define FLEXCOM3_REGS                    ((flexcom_registers_t*)0x4001c000)            /**< \brief FLEXCOM3 Registers Address   */
#define FLEXCOM4_REGS                    ((flexcom_registers_t*)0x40020000)            /**< \brief FLEXCOM4 Registers Address   */
#define FLEXCOM5_REGS                    ((flexcom_registers_t*)0x40024000)            /**< \brief FLEXCOM5 Registers Address   */
#define FLEXCOM6_REGS                    ((flexcom_registers_t*)0x40028000)            /**< \brief FLEXCOM6 Registers Address   */
#define FLEXCOM7_REGS                    ((flexcom_registers_t*)0x4002c000)            /**< \brief FLEXCOM7 Registers Address   */
#define FLEXCOM8_REGS                    ((flexcom_registers_t*)0x40030000)            /**< \brief FLEXCOM8 Registers Address   */
#define FLEXCOM9_REGS                    ((flexcom_registers_t*)0x40034000)            /**< \brief FLEXCOM9 Registers Address   */
#define FLEXRAMECC_REGS                  ((flexramecc_registers_t*)0x40100600)         /**< \brief FLEXRAMECC Registers Address */
#define GMAC_REGS                        ((gmac_registers_t*)0x4009c000)               /**< \brief GMAC Registers Address       */
#define HEFC_REGS                        ((hefc_registers_t*)0x40004000)               /**< \brief HEFC Registers Address       */
#define HEMC_REGS                        ((hemc_registers_t*)0x40080000)               /**< \brief HEMC Registers Address       */
#define HSDRAMC_REGS                     ((hsdramc_registers_t*)0x40082000)            /**< \brief HSDRAMC Registers Address    */
#define HSMC_REGS                        ((hsmc_registers_t*)0x40081000)               /**< \brief HSMC Registers Address       */
#define ICM_REGS                         ((icm_registers_t*)0x4008c000)                /**< \brief ICM Registers Address        */
#define IP1553_REGS                      ((ip1553_registers_t*)0x4003c000)             /**< \brief IP1553 Registers Address     */
#define MATRIX0_REGS                     ((matrix_registers_t*)0x40000000)             /**< \brief MATRIX0 Registers Address    */
#define MCAN0_REGS                       ((mcan_registers_t*)0x40058000)               /**< \brief MCAN0 Registers Address      */
#define MCAN1_REGS                       ((mcan_registers_t*)0x4005c000)               /**< \brief MCAN1 Registers Address      */
#define NMIC_REGS                        ((nmic_registers_t*)0x400a8000)               /**< \brief NMIC Registers Address       */
#define PIO_REGS                         ((pio_registers_t*)0x40008000)                /**< \brief PIO Registers Address        */
#define PMC_REGS                         ((pmc_registers_t*)0x4000c000)                /**< \brief PMC Registers Address        */
#define PWM0_REGS                        ((pwm_registers_t*)0x40068000)                /**< \brief PWM0 Registers Address       */
#define PWM1_REGS                        ((pwm_registers_t*)0x4006c000)                /**< \brief PWM1 Registers Address       */
#define QSPI_REGS                        ((qspi_registers_t*)0x40038000)               /**< \brief QSPI Registers Address       */
#define RSTC_REGS                        ((rstc_registers_t*)0x40100200)               /**< \brief RSTC Registers Address       */
#define RTC_REGS                         ((rtc_registers_t*)0x40100260)                /**< \brief RTC Registers Address        */
#define RTT_REGS                         ((rtt_registers_t*)0x40100230)                /**< \brief RTT Registers Address        */
#define SFR_REGS                         ((sfr_registers_t*)0x400a0000)                /**< \brief SFR Registers Address        */
#define SHA_REGS                         ((sha_registers_t*)0x40094000)                /**< \brief SHA Registers Address        */
#define SPW_REGS                         ((spw_registers_t*)0x40040000)                /**< \brief SPW Registers Address        */
#define SUPC_REGS                        ((supc_registers_t*)0x40100210)               /**< \brief SUPC Registers Address       */
#define TC0_REGS                         ((tc_registers_t*)0x40070000)                 /**< \brief TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0x40074000)                 /**< \brief TC1 Registers Address        */
#define TC2_REGS                         ((tc_registers_t*)0x40078000)                 /**< \brief TC2 Registers Address        */
#define TC3_REGS                         ((tc_registers_t*)0x4007c000)                 /**< \brief TC3 Registers Address        */
#define TCMECC_REGS                      ((tcmecc_registers_t*)0x40100400)             /**< \brief TCMECC Registers Address     */
#define TRNG_REGS                        ((trng_registers_t*)0x40090000)               /**< \brief TRNG Registers Address       */
#define WDT_REGS                         ((wdt_registers_t*)0x40100250)                /**< \brief WDT Registers Address        */
#define WDT1_REGS                        ((wdt_registers_t*)0x40100300)                /**< \brief WDT1 Registers Address       */
#define XDMAC_REGS                       ((xdmac_registers_t*)0x40098000)              /**< \brief XDMAC Registers Address      */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup SAMRH71F20C_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAMRH71F20C                                 */
/* ************************************************************************** */
#define CHIPID_BASE_ADDRESS              _UL_(0x40100000)                              /**< \brief CHIPID Base Address */
#define FLEXCOM0_BASE_ADDRESS            _UL_(0x40010000)                              /**< \brief FLEXCOM0 Base Address */
#define FLEXCOM1_BASE_ADDRESS            _UL_(0x40014000)                              /**< \brief FLEXCOM1 Base Address */
#define FLEXCOM2_BASE_ADDRESS            _UL_(0x40018000)                              /**< \brief FLEXCOM2 Base Address */
#define FLEXCOM3_BASE_ADDRESS            _UL_(0x4001c000)                              /**< \brief FLEXCOM3 Base Address */
#define FLEXCOM4_BASE_ADDRESS            _UL_(0x40020000)                              /**< \brief FLEXCOM4 Base Address */
#define FLEXCOM5_BASE_ADDRESS            _UL_(0x40024000)                              /**< \brief FLEXCOM5 Base Address */
#define FLEXCOM6_BASE_ADDRESS            _UL_(0x40028000)                              /**< \brief FLEXCOM6 Base Address */
#define FLEXCOM7_BASE_ADDRESS            _UL_(0x4002c000)                              /**< \brief FLEXCOM7 Base Address */
#define FLEXCOM8_BASE_ADDRESS            _UL_(0x40030000)                              /**< \brief FLEXCOM8 Base Address */
#define FLEXCOM9_BASE_ADDRESS            _UL_(0x40034000)                              /**< \brief FLEXCOM9 Base Address */
#define FLEXRAMECC_BASE_ADDRESS          _UL_(0x40100600)                              /**< \brief FLEXRAMECC Base Address */
#define GMAC_BASE_ADDRESS                _UL_(0x4009c000)                              /**< \brief GMAC Base Address */
#define HEFC_BASE_ADDRESS                _UL_(0x40004000)                              /**< \brief HEFC Base Address */
#define HEMC_BASE_ADDRESS                _UL_(0x40080000)                              /**< \brief HEMC Base Address */
#define HSDRAMC_BASE_ADDRESS             _UL_(0x40082000)                              /**< \brief HSDRAMC Base Address */
#define HSMC_BASE_ADDRESS                _UL_(0x40081000)                              /**< \brief HSMC Base Address */
#define ICM_BASE_ADDRESS                 _UL_(0x4008c000)                              /**< \brief ICM Base Address */
#define IP1553_BASE_ADDRESS              _UL_(0x4003c000)                              /**< \brief IP1553 Base Address */
#define MATRIX0_BASE_ADDRESS             _UL_(0x40000000)                              /**< \brief MATRIX0 Base Address */
#define MCAN0_BASE_ADDRESS               _UL_(0x40058000)                              /**< \brief MCAN0 Base Address */
#define MCAN1_BASE_ADDRESS               _UL_(0x4005c000)                              /**< \brief MCAN1 Base Address */
#define NMIC_BASE_ADDRESS                _UL_(0x400a8000)                              /**< \brief NMIC Base Address */
#define PIO_BASE_ADDRESS                 _UL_(0x40008000)                              /**< \brief PIO Base Address */
#define PMC_BASE_ADDRESS                 _UL_(0x4000c000)                              /**< \brief PMC Base Address */
#define PWM0_BASE_ADDRESS                _UL_(0x40068000)                              /**< \brief PWM0 Base Address */
#define PWM1_BASE_ADDRESS                _UL_(0x4006c000)                              /**< \brief PWM1 Base Address */
#define QSPI_BASE_ADDRESS                _UL_(0x40038000)                              /**< \brief QSPI Base Address */
#define RSTC_BASE_ADDRESS                _UL_(0x40100200)                              /**< \brief RSTC Base Address */
#define RTC_BASE_ADDRESS                 _UL_(0x40100260)                              /**< \brief RTC Base Address */
#define RTT_BASE_ADDRESS                 _UL_(0x40100230)                              /**< \brief RTT Base Address */
#define SFR_BASE_ADDRESS                 _UL_(0x400a0000)                              /**< \brief SFR Base Address */
#define SHA_BASE_ADDRESS                 _UL_(0x40094000)                              /**< \brief SHA Base Address */
#define SPW_BASE_ADDRESS                 _UL_(0x40040000)                              /**< \brief SPW Base Address */
#define SUPC_BASE_ADDRESS                _UL_(0x40100210)                              /**< \brief SUPC Base Address */
#define TC0_BASE_ADDRESS                 _UL_(0x40070000)                              /**< \brief TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UL_(0x40074000)                              /**< \brief TC1 Base Address */
#define TC2_BASE_ADDRESS                 _UL_(0x40078000)                              /**< \brief TC2 Base Address */
#define TC3_BASE_ADDRESS                 _UL_(0x4007c000)                              /**< \brief TC3 Base Address */
#define TCMECC_BASE_ADDRESS              _UL_(0x40100400)                              /**< \brief TCMECC Base Address */
#define TRNG_BASE_ADDRESS                _UL_(0x40090000)                              /**< \brief TRNG Base Address */
#define WDT_BASE_ADDRESS                 _UL_(0x40100250)                              /**< \brief WDT Base Address */
#define WDT1_BASE_ADDRESS                _UL_(0x40100300)                              /**< \brief WDT1 Base Address */
#define XDMAC_BASE_ADDRESS               _UL_(0x40098000)                              /**< \brief XDMAC Base Address */
/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup SAMRH71F20C_pio Peripheral Pio Definitions
 *  @{
 */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAMRH71F20C                                          */
/* ************************************************************************** */
#include "pio/samrh71f20c.h"
/** @}  end of Peripheral Pio Definitions */

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAMRH71F20C                               */
/* ************************************************************************** */

#define PERIPHERALS_SIZE               _UL_(0x20000000)    /* 524288kB Memory segment type: io */
#define SYSTEM_SIZE                    _UL_(0x10000000)    /* 262144kB Memory segment type: io */
#define QSPIMEM_SIZE                   _UL_(0x08000000)    /* 131072kB Memory segment type: other */
#define AXIMX_SIZE                     _UL_(0x00100000)    /* 1024kB Memory segment type: other */
#define ITCM_SIZE                      _UL_(0x00020000)    /*  128kB Memory segment type: other */
#define IFLASH_SIZE                    _UL_(0x00020000)    /*  128kB Memory segment type: flash */
#define IFLASH_PAGE_SIZE               _UL_(       256)
#define IFLASH_NB_OF_PAGES             _UL_(       512)

#define DTCM_SIZE                      _UL_(0x00040000)    /*  256kB Memory segment type: other */
#define FlexRAM_SIZE                   _UL_(0x000c0000)    /*  768kB Memory segment type: ram */
#define EBI_CSHEMC_SIZE                _UL_(0x80000000)    /* 2097152kB Memory segment type: other */

#define PERIPHERALS_ADDR               _UL_(0x40000000)    /**< PERIPHERALS base address (type: io)*/
#define SYSTEM_ADDR                    _UL_(0xe0000000)    /**< SYSTEM base address (type: io)*/
#define QSPIMEM_ADDR                   _UL_(0x18000000)    /**< QSPIMEM base address (type: other)*/
#define AXIMX_ADDR                     _UL_(0x22000000)    /**< AXIMX base address (type: other)*/
#define ITCM_ADDR                      _UL_(0x00000000)    /**< ITCM base address (type: other)*/
#define IFLASH_ADDR                    _UL_(0x10000000)    /**< IFLASH base address (type: flash)*/
#define DTCM_ADDR                      _UL_(0x20000000)    /**< DTCM base address (type: other)*/
#define FLEXRAM_ADDR                   _UL_(0x21000000)    /**< FLEXRAM base address (type: ram)*/
#define EBI_CSHEMC_ADDR                _UL_(0x60000000)    /**< EBI_CSHEMC base address (type: other)*/

/* ************************************************************************** */
/**  DEVICE SIGNATURES FOR SAMRH71F20C                                        */
/* ************************************************************************** */
#define CHIP_JTAGID                    _UL_(0X05D0503F)
#define CHIP_CIDR                      _UL_(0XA22F0700)
#define CHIP_EXID                      _UL_(0X00000001)

/* ************************************************************************** */
/**  ELECTRICAL DEFINITIONS FOR SAMRH71F20C                                   */
/* ************************************************************************** */



#ifdef __cplusplus
}
#endif

/** @}  end of SAMRH71F20C definitions */


#endif /* _SAMRH71F20C_H_ */

