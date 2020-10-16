/**
 * \brief Component description for TCMECC
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
#ifndef _SAMRH71_TCMECC_COMPONENT_H_
#define _SAMRH71_TCMECC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR TCMECC                                       */
/* ************************************************************************** */

/* -------- TCMECC_CR : (TCMECC Offset: 0x00) (R/W 32) TCMECC Control Register -------- */
#define TCMECC_CR_ENABLE_Pos                  _U_(0)                                               /**< (TCMECC_CR) ECC protection enable Position */
#define TCMECC_CR_ENABLE_Msk                  (_U_(0x1) << TCMECC_CR_ENABLE_Pos)                   /**< (TCMECC_CR) ECC protection enable Mask */
#define TCMECC_CR_ENABLE(value)               (TCMECC_CR_ENABLE_Msk & ((value) << TCMECC_CR_ENABLE_Pos))
#define TCMECC_CR_TEST_MODE_RD_Pos            _U_(1)                                               /**< (TCMECC_CR) test mode of ECC protection - read mode Position */
#define TCMECC_CR_TEST_MODE_RD_Msk            (_U_(0x1) << TCMECC_CR_TEST_MODE_RD_Pos)             /**< (TCMECC_CR) test mode of ECC protection - read mode Mask */
#define TCMECC_CR_TEST_MODE_RD(value)         (TCMECC_CR_TEST_MODE_RD_Msk & ((value) << TCMECC_CR_TEST_MODE_RD_Pos))
#define TCMECC_CR_TEST_MODE_WR_Pos            _U_(2)                                               /**< (TCMECC_CR) test mode of ECC protection - write mode Position */
#define TCMECC_CR_TEST_MODE_WR_Msk            (_U_(0x1) << TCMECC_CR_TEST_MODE_WR_Pos)             /**< (TCMECC_CR) test mode of ECC protection - write mode Mask */
#define TCMECC_CR_TEST_MODE_WR(value)         (TCMECC_CR_TEST_MODE_WR_Msk & ((value) << TCMECC_CR_TEST_MODE_WR_Pos))
#define TCMECC_CR_RST_FIX_CPT_Pos             _U_(4)                                               /**< (TCMECC_CR) reset the fixable error counter Position */
#define TCMECC_CR_RST_FIX_CPT_Msk             (_U_(0x1) << TCMECC_CR_RST_FIX_CPT_Pos)              /**< (TCMECC_CR) reset the fixable error counter Mask */
#define TCMECC_CR_RST_FIX_CPT(value)          (TCMECC_CR_RST_FIX_CPT_Msk & ((value) << TCMECC_CR_RST_FIX_CPT_Pos))
#define TCMECC_CR_RST_NOFIX_CPT_Pos           _U_(5)                                               /**< (TCMECC_CR) reset the un-fixable error counter Position */
#define TCMECC_CR_RST_NOFIX_CPT_Msk           (_U_(0x1) << TCMECC_CR_RST_NOFIX_CPT_Pos)            /**< (TCMECC_CR) reset the un-fixable error counter Mask */
#define TCMECC_CR_RST_NOFIX_CPT(value)        (TCMECC_CR_RST_NOFIX_CPT_Msk & ((value) << TCMECC_CR_RST_NOFIX_CPT_Pos))
#define TCMECC_CR_Msk                         _U_(0x00000037)                                      /**< (TCMECC_CR) Register Mask  */


/* -------- TCMECC_TESTCB1 : (TCMECC Offset: 0x04) (R/W 32) TCMECC Test mode register 1 -------- */
#define TCMECC_TESTCB1_TCB1_Pos               _U_(0)                                               /**< (TCMECC_TESTCB1) test check bit (8 bit) Position */
#define TCMECC_TESTCB1_TCB1_Msk               (_U_(0xFF) << TCMECC_TESTCB1_TCB1_Pos)               /**< (TCMECC_TESTCB1) test check bit (8 bit) Mask */
#define TCMECC_TESTCB1_TCB1(value)            (TCMECC_TESTCB1_TCB1_Msk & ((value) << TCMECC_TESTCB1_TCB1_Pos))
#define TCMECC_TESTCB1_TCB2_Pos               _U_(8)                                               /**< (TCMECC_TESTCB1) test check bit (8 bit) Position */
#define TCMECC_TESTCB1_TCB2_Msk               (_U_(0xFF) << TCMECC_TESTCB1_TCB2_Pos)               /**< (TCMECC_TESTCB1) test check bit (8 bit) Mask */
#define TCMECC_TESTCB1_TCB2(value)            (TCMECC_TESTCB1_TCB2_Msk & ((value) << TCMECC_TESTCB1_TCB2_Pos))
#define TCMECC_TESTCB1_Msk                    _U_(0x0000FFFF)                                      /**< (TCMECC_TESTCB1) Register Mask  */


/* -------- TCMECC_SR : (TCMECC Offset: 0x0C) ( R/ 32) TCMECC Status register -------- */
#define TCMECC_SR_MEM_FIX_I_Pos               _U_(0)                                               /**< (TCMECC_SR) Fixable error status in instruction memory Position */
#define TCMECC_SR_MEM_FIX_I_Msk               (_U_(0x1) << TCMECC_SR_MEM_FIX_I_Pos)                /**< (TCMECC_SR) Fixable error status in instruction memory Mask */
#define TCMECC_SR_MEM_FIX_I(value)            (TCMECC_SR_MEM_FIX_I_Msk & ((value) << TCMECC_SR_MEM_FIX_I_Pos))
#define TCMECC_SR_MEM_FIX_D_Pos               _U_(1)                                               /**< (TCMECC_SR) Fixable error status in data memory Position */
#define TCMECC_SR_MEM_FIX_D_Msk               (_U_(0x1) << TCMECC_SR_MEM_FIX_D_Pos)                /**< (TCMECC_SR) Fixable error status in data memory Mask */
#define TCMECC_SR_MEM_FIX_D(value)            (TCMECC_SR_MEM_FIX_D_Msk & ((value) << TCMECC_SR_MEM_FIX_D_Pos))
#define TCMECC_SR_CPT_FIX_Pos                 _U_(2)                                               /**< (TCMECC_SR) 5 bits counter Position */
#define TCMECC_SR_CPT_FIX_Msk                 (_U_(0x1F) << TCMECC_SR_CPT_FIX_Pos)                 /**< (TCMECC_SR) 5 bits counter Mask */
#define TCMECC_SR_CPT_FIX(value)              (TCMECC_SR_CPT_FIX_Msk & ((value) << TCMECC_SR_CPT_FIX_Pos))
#define TCMECC_SR_OVER_FIX_Pos                _U_(7)                                               /**< (TCMECC_SR) counter overflow Position */
#define TCMECC_SR_OVER_FIX_Msk                (_U_(0x1) << TCMECC_SR_OVER_FIX_Pos)                 /**< (TCMECC_SR) counter overflow Mask */
#define TCMECC_SR_OVER_FIX(value)             (TCMECC_SR_OVER_FIX_Msk & ((value) << TCMECC_SR_OVER_FIX_Pos))
#define TCMECC_SR_MEM_NOFIX_I_Pos             _U_(8)                                               /**< (TCMECC_SR) Un-fixable error status in instruction memory Position */
#define TCMECC_SR_MEM_NOFIX_I_Msk             (_U_(0x1) << TCMECC_SR_MEM_NOFIX_I_Pos)              /**< (TCMECC_SR) Un-fixable error status in instruction memory Mask */
#define TCMECC_SR_MEM_NOFIX_I(value)          (TCMECC_SR_MEM_NOFIX_I_Msk & ((value) << TCMECC_SR_MEM_NOFIX_I_Pos))
#define TCMECC_SR_MEM_NOFIX_D_Pos             _U_(9)                                               /**< (TCMECC_SR) Un-fixable error status in data memory Position */
#define TCMECC_SR_MEM_NOFIX_D_Msk             (_U_(0x1) << TCMECC_SR_MEM_NOFIX_D_Pos)              /**< (TCMECC_SR) Un-fixable error status in data memory Mask */
#define TCMECC_SR_MEM_NOFIX_D(value)          (TCMECC_SR_MEM_NOFIX_D_Msk & ((value) << TCMECC_SR_MEM_NOFIX_D_Pos))
#define TCMECC_SR_CPT_NOFIX_Pos               _U_(10)                                              /**< (TCMECC_SR) 5 bits counter Position */
#define TCMECC_SR_CPT_NOFIX_Msk               (_U_(0x1F) << TCMECC_SR_CPT_NOFIX_Pos)               /**< (TCMECC_SR) 5 bits counter Mask */
#define TCMECC_SR_CPT_NOFIX(value)            (TCMECC_SR_CPT_NOFIX_Msk & ((value) << TCMECC_SR_CPT_NOFIX_Pos))
#define TCMECC_SR_OVER_NOFIX_Pos              _U_(15)                                              /**< (TCMECC_SR) counter overflow Position */
#define TCMECC_SR_OVER_NOFIX_Msk              (_U_(0x1) << TCMECC_SR_OVER_NOFIX_Pos)               /**< (TCMECC_SR) counter overflow Mask */
#define TCMECC_SR_OVER_NOFIX(value)           (TCMECC_SR_OVER_NOFIX_Msk & ((value) << TCMECC_SR_OVER_NOFIX_Pos))
#define TCMECC_SR_HES_Pos                     _U_(24)                                              /**< (TCMECC_SR) Hardware Error Size Position */
#define TCMECC_SR_HES_Msk                     (_U_(0x7) << TCMECC_SR_HES_Pos)                      /**< (TCMECC_SR) Hardware Error Size Mask */
#define TCMECC_SR_HES(value)                  (TCMECC_SR_HES_Msk & ((value) << TCMECC_SR_HES_Pos))
#define TCMECC_SR_ONE_Pos                     _U_(27)                                              /**< (TCMECC_SR) one Position */
#define TCMECC_SR_ONE_Msk                     (_U_(0x1) << TCMECC_SR_ONE_Pos)                      /**< (TCMECC_SR) one Mask */
#define TCMECC_SR_ONE(value)                  (TCMECC_SR_ONE_Msk & ((value) << TCMECC_SR_ONE_Pos))
#define TCMECC_SR_MEM_ID_I_Pos                _U_(28)                                              /**< (TCMECC_SR) memory identification number Position */
#define TCMECC_SR_MEM_ID_I_Msk                (_U_(0x1) << TCMECC_SR_MEM_ID_I_Pos)                 /**< (TCMECC_SR) memory identification number Mask */
#define TCMECC_SR_MEM_ID_I(value)             (TCMECC_SR_MEM_ID_I_Msk & ((value) << TCMECC_SR_MEM_ID_I_Pos))
#define TCMECC_SR_MEM_ID_D_Pos                _U_(29)                                              /**< (TCMECC_SR) memory identification number Position */
#define TCMECC_SR_MEM_ID_D_Msk                (_U_(0x1) << TCMECC_SR_MEM_ID_D_Pos)                 /**< (TCMECC_SR) memory identification number Mask */
#define TCMECC_SR_MEM_ID_D(value)             (TCMECC_SR_MEM_ID_D_Msk & ((value) << TCMECC_SR_MEM_ID_D_Pos))
#define TCMECC_SR_Msk                         _U_(0x3F00FFFF)                                      /**< (TCMECC_SR) Register Mask  */


/* -------- TCMECC_IER : (TCMECC Offset: 0x10) ( /W 32) TCMECC Interrupt Enable Register -------- */
#define TCMECC_IER_MEM_FIX_I_Pos              _U_(0)                                               /**< (TCMECC_IER) Fixable error on instruction Position */
#define TCMECC_IER_MEM_FIX_I_Msk              (_U_(0x1) << TCMECC_IER_MEM_FIX_I_Pos)               /**< (TCMECC_IER) Fixable error on instruction Mask */
#define TCMECC_IER_MEM_FIX_I(value)           (TCMECC_IER_MEM_FIX_I_Msk & ((value) << TCMECC_IER_MEM_FIX_I_Pos))
#define TCMECC_IER_MEM_NOFIX_I_Pos            _U_(1)                                               /**< (TCMECC_IER) Un-fixable error on instruction Position */
#define TCMECC_IER_MEM_NOFIX_I_Msk            (_U_(0x1) << TCMECC_IER_MEM_NOFIX_I_Pos)             /**< (TCMECC_IER) Un-fixable error on instruction Mask */
#define TCMECC_IER_MEM_NOFIX_I(value)         (TCMECC_IER_MEM_NOFIX_I_Msk & ((value) << TCMECC_IER_MEM_NOFIX_I_Pos))
#define TCMECC_IER_MEM_FIX_D_Pos              _U_(2)                                               /**< (TCMECC_IER) Fixable error on data Position */
#define TCMECC_IER_MEM_FIX_D_Msk              (_U_(0x1) << TCMECC_IER_MEM_FIX_D_Pos)               /**< (TCMECC_IER) Fixable error on data Mask */
#define TCMECC_IER_MEM_FIX_D(value)           (TCMECC_IER_MEM_FIX_D_Msk & ((value) << TCMECC_IER_MEM_FIX_D_Pos))
#define TCMECC_IER_MEM_NOFIX_D_Pos            _U_(3)                                               /**< (TCMECC_IER) Un-fixable error on data Position */
#define TCMECC_IER_MEM_NOFIX_D_Msk            (_U_(0x1) << TCMECC_IER_MEM_NOFIX_D_Pos)             /**< (TCMECC_IER) Un-fixable error on data Mask */
#define TCMECC_IER_MEM_NOFIX_D(value)         (TCMECC_IER_MEM_NOFIX_D_Msk & ((value) << TCMECC_IER_MEM_NOFIX_D_Pos))
#define TCMECC_IER_Msk                        _U_(0x0000000F)                                      /**< (TCMECC_IER) Register Mask  */


/* -------- TCMECC_IDR : (TCMECC Offset: 0x14) ( /W 32) TCMECC Interrupt Disable Register -------- */
#define TCMECC_IDR_MEM_FIX_I_Pos              _U_(0)                                               /**< (TCMECC_IDR) fixable error on instruction Position */
#define TCMECC_IDR_MEM_FIX_I_Msk              (_U_(0x1) << TCMECC_IDR_MEM_FIX_I_Pos)               /**< (TCMECC_IDR) fixable error on instruction Mask */
#define TCMECC_IDR_MEM_FIX_I(value)           (TCMECC_IDR_MEM_FIX_I_Msk & ((value) << TCMECC_IDR_MEM_FIX_I_Pos))
#define TCMECC_IDR_MEM_NOFIX_I_Pos            _U_(1)                                               /**< (TCMECC_IDR) un-fixable error on instruction Position */
#define TCMECC_IDR_MEM_NOFIX_I_Msk            (_U_(0x1) << TCMECC_IDR_MEM_NOFIX_I_Pos)             /**< (TCMECC_IDR) un-fixable error on instruction Mask */
#define TCMECC_IDR_MEM_NOFIX_I(value)         (TCMECC_IDR_MEM_NOFIX_I_Msk & ((value) << TCMECC_IDR_MEM_NOFIX_I_Pos))
#define TCMECC_IDR_MEM_FIX_D_Pos              _U_(2)                                               /**< (TCMECC_IDR) fixable error on data Position */
#define TCMECC_IDR_MEM_FIX_D_Msk              (_U_(0x1) << TCMECC_IDR_MEM_FIX_D_Pos)               /**< (TCMECC_IDR) fixable error on data Mask */
#define TCMECC_IDR_MEM_FIX_D(value)           (TCMECC_IDR_MEM_FIX_D_Msk & ((value) << TCMECC_IDR_MEM_FIX_D_Pos))
#define TCMECC_IDR_MEM_NOFIX_D_Pos            _U_(3)                                               /**< (TCMECC_IDR) un-fixable error on data Position */
#define TCMECC_IDR_MEM_NOFIX_D_Msk            (_U_(0x1) << TCMECC_IDR_MEM_NOFIX_D_Pos)             /**< (TCMECC_IDR) un-fixable error on data Mask */
#define TCMECC_IDR_MEM_NOFIX_D(value)         (TCMECC_IDR_MEM_NOFIX_D_Msk & ((value) << TCMECC_IDR_MEM_NOFIX_D_Pos))
#define TCMECC_IDR_Msk                        _U_(0x0000000F)                                      /**< (TCMECC_IDR) Register Mask  */


/* -------- TCMECC_IMR : (TCMECC Offset: 0x18) ( R/ 32) TCMECC Interrupt Mask Register -------- */
#define TCMECC_IMR_MEM_FIX_I_Pos              _U_(0)                                               /**< (TCMECC_IMR) fixable error on instruction Position */
#define TCMECC_IMR_MEM_FIX_I_Msk              (_U_(0x1) << TCMECC_IMR_MEM_FIX_I_Pos)               /**< (TCMECC_IMR) fixable error on instruction Mask */
#define TCMECC_IMR_MEM_FIX_I(value)           (TCMECC_IMR_MEM_FIX_I_Msk & ((value) << TCMECC_IMR_MEM_FIX_I_Pos))
#define TCMECC_IMR_MEM_NOFIX_I_Pos            _U_(1)                                               /**< (TCMECC_IMR) un-fixable error on instruction Position */
#define TCMECC_IMR_MEM_NOFIX_I_Msk            (_U_(0x1) << TCMECC_IMR_MEM_NOFIX_I_Pos)             /**< (TCMECC_IMR) un-fixable error on instruction Mask */
#define TCMECC_IMR_MEM_NOFIX_I(value)         (TCMECC_IMR_MEM_NOFIX_I_Msk & ((value) << TCMECC_IMR_MEM_NOFIX_I_Pos))
#define TCMECC_IMR_MEM_FIX_D_Pos              _U_(2)                                               /**< (TCMECC_IMR) fixable error on data Position */
#define TCMECC_IMR_MEM_FIX_D_Msk              (_U_(0x1) << TCMECC_IMR_MEM_FIX_D_Pos)               /**< (TCMECC_IMR) fixable error on data Mask */
#define TCMECC_IMR_MEM_FIX_D(value)           (TCMECC_IMR_MEM_FIX_D_Msk & ((value) << TCMECC_IMR_MEM_FIX_D_Pos))
#define TCMECC_IMR_MEM_NOFIX_D_Pos            _U_(3)                                               /**< (TCMECC_IMR) un-fixable error on data Position */
#define TCMECC_IMR_MEM_NOFIX_D_Msk            (_U_(0x1) << TCMECC_IMR_MEM_NOFIX_D_Pos)             /**< (TCMECC_IMR) un-fixable error on data Mask */
#define TCMECC_IMR_MEM_NOFIX_D(value)         (TCMECC_IMR_MEM_NOFIX_D_Msk & ((value) << TCMECC_IMR_MEM_NOFIX_D_Pos))
#define TCMECC_IMR_Msk                        _U_(0x0000000F)                                      /**< (TCMECC_IMR) Register Mask  */


/* -------- TCMECC_FAILAR : (TCMECC Offset: 0x1C) ( R/ 32) TCMECC Fail address register -------- */
#define TCMECC_FAILAR_ADDRESS_Pos             _U_(0)                                               /**< (TCMECC_FAILAR) address of the error detected (refers to instruction memory) Position */
#define TCMECC_FAILAR_ADDRESS_Msk             (_U_(0xFFFFFFFF) << TCMECC_FAILAR_ADDRESS_Pos)       /**< (TCMECC_FAILAR) address of the error detected (refers to instruction memory) Mask */
#define TCMECC_FAILAR_ADDRESS(value)          (TCMECC_FAILAR_ADDRESS_Msk & ((value) << TCMECC_FAILAR_ADDRESS_Pos))
#define TCMECC_FAILAR_Msk                     _U_(0xFFFFFFFF)                                      /**< (TCMECC_FAILAR) Register Mask  */


/* -------- TCMECC_FAILARD : (TCMECC Offset: 0x20) ( R/ 32) TCMECC Fail address register data -------- */
#define TCMECC_FAILARD_ADDRESS_Pos            _U_(0)                                               /**< (TCMECC_FAILARD) address of the error detected Position */
#define TCMECC_FAILARD_ADDRESS_Msk            (_U_(0xFFFFFFFF) << TCMECC_FAILARD_ADDRESS_Pos)      /**< (TCMECC_FAILARD) address of the error detected Mask */
#define TCMECC_FAILARD_ADDRESS(value)         (TCMECC_FAILARD_ADDRESS_Msk & ((value) << TCMECC_FAILARD_ADDRESS_Pos))
#define TCMECC_FAILARD_Msk                    _U_(0xFFFFFFFF)                                      /**< (TCMECC_FAILARD) Register Mask  */


/** \brief TCMECC register offsets definitions */
#define TCMECC_CR_REG_OFST             (0x00)              /**< (TCMECC_CR) TCMECC Control Register Offset */
#define TCMECC_TESTCB1_REG_OFST        (0x04)              /**< (TCMECC_TESTCB1) TCMECC Test mode register 1 Offset */
#define TCMECC_SR_REG_OFST             (0x0C)              /**< (TCMECC_SR) TCMECC Status register Offset */
#define TCMECC_IER_REG_OFST            (0x10)              /**< (TCMECC_IER) TCMECC Interrupt Enable Register Offset */
#define TCMECC_IDR_REG_OFST            (0x14)              /**< (TCMECC_IDR) TCMECC Interrupt Disable Register Offset */
#define TCMECC_IMR_REG_OFST            (0x18)              /**< (TCMECC_IMR) TCMECC Interrupt Mask Register Offset */
#define TCMECC_FAILAR_REG_OFST         (0x1C)              /**< (TCMECC_FAILAR) TCMECC Fail address register Offset */
#define TCMECC_FAILARD_REG_OFST        (0x20)              /**< (TCMECC_FAILARD) TCMECC Fail address register data Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief TCMECC register API structure */
typedef struct
{
  __IO  uint32_t                       TCMECC_CR;          /**< Offset: 0x00 (R/W  32) TCMECC Control Register */
  __IO  uint32_t                       TCMECC_TESTCB1;     /**< Offset: 0x04 (R/W  32) TCMECC Test mode register 1 */
  __I   uint8_t                        Reserved1[0x04];
  __I   uint32_t                       TCMECC_SR;          /**< Offset: 0x0C (R/   32) TCMECC Status register */
  __O   uint32_t                       TCMECC_IER;         /**< Offset: 0x10 ( /W  32) TCMECC Interrupt Enable Register */
  __O   uint32_t                       TCMECC_IDR;         /**< Offset: 0x14 ( /W  32) TCMECC Interrupt Disable Register */
  __I   uint32_t                       TCMECC_IMR;         /**< Offset: 0x18 (R/   32) TCMECC Interrupt Mask Register */
  __I   uint32_t                       TCMECC_FAILAR;      /**< Offset: 0x1C (R/   32) TCMECC Fail address register */
  __I   uint32_t                       TCMECC_FAILARD;     /**< Offset: 0x20 (R/   32) TCMECC Fail address register data */
} tcmecc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_TCMECC_COMPONENT_H_ */
