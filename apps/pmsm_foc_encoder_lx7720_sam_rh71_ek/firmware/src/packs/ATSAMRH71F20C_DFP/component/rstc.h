/**
 * \brief Component description for RSTC
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
#ifndef _SAMRH71_RSTC_COMPONENT_H_
#define _SAMRH71_RSTC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR RSTC                                         */
/* ************************************************************************** */

/* -------- RSTC_CR : (RSTC Offset: 0x00) ( /W 32) Control Register -------- */
#define RSTC_CR_PROCRST_Pos                   _U_(0)                                               /**< (RSTC_CR) Processor Reset Position */
#define RSTC_CR_PROCRST_Msk                   (_U_(0x1) << RSTC_CR_PROCRST_Pos)                    /**< (RSTC_CR) Processor Reset Mask */
#define RSTC_CR_PROCRST(value)                (RSTC_CR_PROCRST_Msk & ((value) << RSTC_CR_PROCRST_Pos))
#define RSTC_CR_EXTRST_Pos                    _U_(3)                                               /**< (RSTC_CR) External Reset Position */
#define RSTC_CR_EXTRST_Msk                    (_U_(0x1) << RSTC_CR_EXTRST_Pos)                     /**< (RSTC_CR) External Reset Mask */
#define RSTC_CR_EXTRST(value)                 (RSTC_CR_EXTRST_Msk & ((value) << RSTC_CR_EXTRST_Pos))
#define RSTC_CR_PERIIDON_Pos                  _U_(4)                                               /**< (RSTC_CR) External Reset Position */
#define RSTC_CR_PERIIDON_Msk                  (_U_(0x1) << RSTC_CR_PERIIDON_Pos)                   /**< (RSTC_CR) External Reset Mask */
#define RSTC_CR_PERIIDON(value)               (RSTC_CR_PERIIDON_Msk & ((value) << RSTC_CR_PERIIDON_Pos))
#define RSTC_CR_PERIID_Pos                    _U_(8)                                               /**< (RSTC_CR) Peripheral Identifier Position */
#define RSTC_CR_PERIID_Msk                    (_U_(0xFF) << RSTC_CR_PERIID_Pos)                    /**< (RSTC_CR) Peripheral Identifier Mask */
#define RSTC_CR_PERIID(value)                 (RSTC_CR_PERIID_Msk & ((value) << RSTC_CR_PERIID_Pos))
#define RSTC_CR_KEY_Pos                       _U_(24)                                              /**< (RSTC_CR) System Reset Key Position */
#define RSTC_CR_KEY_Msk                       (_U_(0xFF) << RSTC_CR_KEY_Pos)                       /**< (RSTC_CR) System Reset Key Mask */
#define RSTC_CR_KEY(value)                    (RSTC_CR_KEY_Msk & ((value) << RSTC_CR_KEY_Pos))    
#define   RSTC_CR_KEY_PASSWD_Val              _U_(0xA5)                                            /**< (RSTC_CR) Writing any other value in this field aborts the write operation.  */
#define RSTC_CR_KEY_PASSWD                    (RSTC_CR_KEY_PASSWD_Val << RSTC_CR_KEY_Pos)          /**< (RSTC_CR) Writing any other value in this field aborts the write operation. Position  */
#define RSTC_CR_Msk                           _U_(0xFF00FF19)                                      /**< (RSTC_CR) Register Mask  */


/* -------- RSTC_SR : (RSTC Offset: 0x04) ( R/ 32) Status Register -------- */
#define RSTC_SR_RSTTYP_Pos                    _U_(8)                                               /**< (RSTC_SR) Reset Type Position */
#define RSTC_SR_RSTTYP_Msk                    (_U_(0x7) << RSTC_SR_RSTTYP_Pos)                     /**< (RSTC_SR) Reset Type Mask */
#define RSTC_SR_RSTTYP(value)                 (RSTC_SR_RSTTYP_Msk & ((value) << RSTC_SR_RSTTYP_Pos))
#define   RSTC_SR_RSTTYP_GENERAL_RST_Val      _U_(0x0)                                             /**< (RSTC_SR) First powerup reset  */
#define   RSTC_SR_RSTTYP_WDT_RST_Val          _U_(0x2)                                             /**< (RSTC_SR) Watchdog fault occurred  */
#define   RSTC_SR_RSTTYP_SOFT_RST_Val         _U_(0x3)                                             /**< (RSTC_SR) Processor reset required by the software  */
#define   RSTC_SR_RSTTYP_USER_RST_Val         _U_(0x4)                                             /**< (RSTC_SR) NRST pin detected low  */
#define   RSTC_SR_RSTTYP_CPU_FAIL_RST_Val     _U_(0x6)                                             /**< (RSTC_SR) CPU clock failure detection occurred  */
#define   RSTC_SR_RSTTYP_SLCK_XTAL_RST_Val    _U_(0x7)                                             /**< (RSTC_SR) 32.768 kHz crystal failure detection fault occurred  */
#define RSTC_SR_RSTTYP_GENERAL_RST            (RSTC_SR_RSTTYP_GENERAL_RST_Val << RSTC_SR_RSTTYP_Pos) /**< (RSTC_SR) First powerup reset Position  */
#define RSTC_SR_RSTTYP_WDT_RST                (RSTC_SR_RSTTYP_WDT_RST_Val << RSTC_SR_RSTTYP_Pos)   /**< (RSTC_SR) Watchdog fault occurred Position  */
#define RSTC_SR_RSTTYP_SOFT_RST               (RSTC_SR_RSTTYP_SOFT_RST_Val << RSTC_SR_RSTTYP_Pos)  /**< (RSTC_SR) Processor reset required by the software Position  */
#define RSTC_SR_RSTTYP_USER_RST               (RSTC_SR_RSTTYP_USER_RST_Val << RSTC_SR_RSTTYP_Pos)  /**< (RSTC_SR) NRST pin detected low Position  */
#define RSTC_SR_RSTTYP_CPU_FAIL_RST           (RSTC_SR_RSTTYP_CPU_FAIL_RST_Val << RSTC_SR_RSTTYP_Pos) /**< (RSTC_SR) CPU clock failure detection occurred Position  */
#define RSTC_SR_RSTTYP_SLCK_XTAL_RST          (RSTC_SR_RSTTYP_SLCK_XTAL_RST_Val << RSTC_SR_RSTTYP_Pos) /**< (RSTC_SR) 32.768 kHz crystal failure detection fault occurred Position  */
#define RSTC_SR_NRSTL_Pos                     _U_(16)                                              /**< (RSTC_SR) NRST Pin Level Position */
#define RSTC_SR_NRSTL_Msk                     (_U_(0x1) << RSTC_SR_NRSTL_Pos)                      /**< (RSTC_SR) NRST Pin Level Mask */
#define RSTC_SR_NRSTL(value)                  (RSTC_SR_NRSTL_Msk & ((value) << RSTC_SR_NRSTL_Pos))
#define RSTC_SR_SRCMP_Pos                     _U_(17)                                              /**< (RSTC_SR) Software Reset Command in Progress Position */
#define RSTC_SR_SRCMP_Msk                     (_U_(0x1) << RSTC_SR_SRCMP_Pos)                      /**< (RSTC_SR) Software Reset Command in Progress Mask */
#define RSTC_SR_SRCMP(value)                  (RSTC_SR_SRCMP_Msk & ((value) << RSTC_SR_SRCMP_Pos))
#define RSTC_SR_Msk                           _U_(0x00030700)                                      /**< (RSTC_SR) Register Mask  */


/* -------- RSTC_MR : (RSTC Offset: 0x08) (R/W 32) Mode Register -------- */
#define RSTC_MR_SCKSW_Pos                     _U_(1)                                               /**< (RSTC_MR) Slow Clock Switching Position */
#define RSTC_MR_SCKSW_Msk                     (_U_(0x1) << RSTC_MR_SCKSW_Pos)                      /**< (RSTC_MR) Slow Clock Switching Mask */
#define RSTC_MR_SCKSW(value)                  (RSTC_MR_SCKSW_Msk & ((value) << RSTC_MR_SCKSW_Pos))
#define RSTC_MR_CPUFEN_Pos                    _U_(3)                                               /**< (RSTC_MR) CPU Fail Enable Position */
#define RSTC_MR_CPUFEN_Msk                    (_U_(0x1) << RSTC_MR_CPUFEN_Pos)                     /**< (RSTC_MR) CPU Fail Enable Mask */
#define RSTC_MR_CPUFEN(value)                 (RSTC_MR_CPUFEN_Msk & ((value) << RSTC_MR_CPUFEN_Pos))
#define RSTC_MR_KEY_Pos                       _U_(24)                                              /**< (RSTC_MR) Write Access Password Position */
#define RSTC_MR_KEY_Msk                       (_U_(0xFF) << RSTC_MR_KEY_Pos)                       /**< (RSTC_MR) Write Access Password Mask */
#define RSTC_MR_KEY(value)                    (RSTC_MR_KEY_Msk & ((value) << RSTC_MR_KEY_Pos))    
#define   RSTC_MR_KEY_PASSWD_Val              _U_(0xA5)                                            /**< (RSTC_MR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define RSTC_MR_KEY_PASSWD                    (RSTC_MR_KEY_PASSWD_Val << RSTC_MR_KEY_Pos)          /**< (RSTC_MR) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define RSTC_MR_Msk                           _U_(0xFF00000A)                                      /**< (RSTC_MR) Register Mask  */


/** \brief RSTC register offsets definitions */
#define RSTC_CR_REG_OFST               (0x00)              /**< (RSTC_CR) Control Register Offset */
#define RSTC_SR_REG_OFST               (0x04)              /**< (RSTC_SR) Status Register Offset */
#define RSTC_MR_REG_OFST               (0x08)              /**< (RSTC_MR) Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief RSTC register API structure */
typedef struct
{
  __O   uint32_t                       RSTC_CR;            /**< Offset: 0x00 ( /W  32) Control Register */
  __I   uint32_t                       RSTC_SR;            /**< Offset: 0x04 (R/   32) Status Register */
  __IO  uint32_t                       RSTC_MR;            /**< Offset: 0x08 (R/W  32) Mode Register */
} rstc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_RSTC_COMPONENT_H_ */
