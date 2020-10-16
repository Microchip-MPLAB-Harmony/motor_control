/**
 * \brief Component description for FLEXRAMECC
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
#ifndef _SAMRH71_FLEXRAMECC_COMPONENT_H_
#define _SAMRH71_FLEXRAMECC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FLEXRAMECC                                   */
/* ************************************************************************** */

/* -------- FLEXRAMECC_CR : (FLEXRAMECC Offset: 0x00) (R/W 32) FLEXRAMECC Control Register -------- */
#define FLEXRAMECC_CR_ENABLE_Pos              _U_(0)                                               /**< (FLEXRAMECC_CR) ECC protection enable Position */
#define FLEXRAMECC_CR_ENABLE_Msk              (_U_(0x1) << FLEXRAMECC_CR_ENABLE_Pos)               /**< (FLEXRAMECC_CR) ECC protection enable Mask */
#define FLEXRAMECC_CR_ENABLE(value)           (FLEXRAMECC_CR_ENABLE_Msk & ((value) << FLEXRAMECC_CR_ENABLE_Pos))
#define FLEXRAMECC_CR_TEST_MODE_RD_Pos        _U_(1)                                               /**< (FLEXRAMECC_CR) test mode of ECC protection - read mode Position */
#define FLEXRAMECC_CR_TEST_MODE_RD_Msk        (_U_(0x1) << FLEXRAMECC_CR_TEST_MODE_RD_Pos)         /**< (FLEXRAMECC_CR) test mode of ECC protection - read mode Mask */
#define FLEXRAMECC_CR_TEST_MODE_RD(value)     (FLEXRAMECC_CR_TEST_MODE_RD_Msk & ((value) << FLEXRAMECC_CR_TEST_MODE_RD_Pos))
#define FLEXRAMECC_CR_TEST_MODE_WR_Pos        _U_(2)                                               /**< (FLEXRAMECC_CR) test mode of ECC protection - write mode Position */
#define FLEXRAMECC_CR_TEST_MODE_WR_Msk        (_U_(0x1) << FLEXRAMECC_CR_TEST_MODE_WR_Pos)         /**< (FLEXRAMECC_CR) test mode of ECC protection - write mode Mask */
#define FLEXRAMECC_CR_TEST_MODE_WR(value)     (FLEXRAMECC_CR_TEST_MODE_WR_Msk & ((value) << FLEXRAMECC_CR_TEST_MODE_WR_Pos))
#define FLEXRAMECC_CR_RST_FIX_CPT_Pos         _U_(4)                                               /**< (FLEXRAMECC_CR) reset the fixable error counter Position */
#define FLEXRAMECC_CR_RST_FIX_CPT_Msk         (_U_(0x1) << FLEXRAMECC_CR_RST_FIX_CPT_Pos)          /**< (FLEXRAMECC_CR) reset the fixable error counter Mask */
#define FLEXRAMECC_CR_RST_FIX_CPT(value)      (FLEXRAMECC_CR_RST_FIX_CPT_Msk & ((value) << FLEXRAMECC_CR_RST_FIX_CPT_Pos))
#define FLEXRAMECC_CR_RST_NOFIX_CPT_Pos       _U_(5)                                               /**< (FLEXRAMECC_CR) reset the un-fixable error counter Position */
#define FLEXRAMECC_CR_RST_NOFIX_CPT_Msk       (_U_(0x1) << FLEXRAMECC_CR_RST_NOFIX_CPT_Pos)        /**< (FLEXRAMECC_CR) reset the un-fixable error counter Mask */
#define FLEXRAMECC_CR_RST_NOFIX_CPT(value)    (FLEXRAMECC_CR_RST_NOFIX_CPT_Msk & ((value) << FLEXRAMECC_CR_RST_NOFIX_CPT_Pos))
#define FLEXRAMECC_CR_ECC12_ENABLE_Pos        _U_(6)                                               /**< (FLEXRAMECC_CR) BCH ECC enable Position */
#define FLEXRAMECC_CR_ECC12_ENABLE_Msk        (_U_(0x1) << FLEXRAMECC_CR_ECC12_ENABLE_Pos)         /**< (FLEXRAMECC_CR) BCH ECC enable Mask */
#define FLEXRAMECC_CR_ECC12_ENABLE(value)     (FLEXRAMECC_CR_ECC12_ENABLE_Msk & ((value) << FLEXRAMECC_CR_ECC12_ENABLE_Pos))
#define FLEXRAMECC_CR_Msk                     _U_(0x00000077)                                      /**< (FLEXRAMECC_CR) Register Mask  */


/* -------- FLEXRAMECC_TESTCB1 : (FLEXRAMECC Offset: 0x04) (R/W 32) FLEXRAMECC Test mode register 1 -------- */
#define FLEXRAMECC_TESTCB1_TCB1_Pos           _U_(0)                                               /**< (FLEXRAMECC_TESTCB1) Test Check Bit Position */
#define FLEXRAMECC_TESTCB1_TCB1_Msk           (_U_(0xFF) << FLEXRAMECC_TESTCB1_TCB1_Pos)           /**< (FLEXRAMECC_TESTCB1) Test Check Bit Mask */
#define FLEXRAMECC_TESTCB1_TCB1(value)        (FLEXRAMECC_TESTCB1_TCB1_Msk & ((value) << FLEXRAMECC_TESTCB1_TCB1_Pos))
#define FLEXRAMECC_TESTCB1_Msk                _U_(0x000000FF)                                      /**< (FLEXRAMECC_TESTCB1) Register Mask  */


/* -------- FLEXRAMECC_SR : (FLEXRAMECC Offset: 0x0C) ( R/ 32) FLEXRAMECC Status register -------- */
#define FLEXRAMECC_SR_MEM_FIX_Pos             _U_(0)                                               /**< (FLEXRAMECC_SR) Fixable error status Position */
#define FLEXRAMECC_SR_MEM_FIX_Msk             (_U_(0x1) << FLEXRAMECC_SR_MEM_FIX_Pos)              /**< (FLEXRAMECC_SR) Fixable error status Mask */
#define FLEXRAMECC_SR_MEM_FIX(value)          (FLEXRAMECC_SR_MEM_FIX_Msk & ((value) << FLEXRAMECC_SR_MEM_FIX_Pos))
#define FLEXRAMECC_SR_CPT_FIX_Pos             _U_(2)                                               /**< (FLEXRAMECC_SR) 5 bits counter Position */
#define FLEXRAMECC_SR_CPT_FIX_Msk             (_U_(0x1F) << FLEXRAMECC_SR_CPT_FIX_Pos)             /**< (FLEXRAMECC_SR) 5 bits counter Mask */
#define FLEXRAMECC_SR_CPT_FIX(value)          (FLEXRAMECC_SR_CPT_FIX_Msk & ((value) << FLEXRAMECC_SR_CPT_FIX_Pos))
#define FLEXRAMECC_SR_OVER_FIX_Pos            _U_(7)                                               /**< (FLEXRAMECC_SR) counter overflow Position */
#define FLEXRAMECC_SR_OVER_FIX_Msk            (_U_(0x1) << FLEXRAMECC_SR_OVER_FIX_Pos)             /**< (FLEXRAMECC_SR) counter overflow Mask */
#define FLEXRAMECC_SR_OVER_FIX(value)         (FLEXRAMECC_SR_OVER_FIX_Msk & ((value) << FLEXRAMECC_SR_OVER_FIX_Pos))
#define FLEXRAMECC_SR_MEM_NOFIX_Pos           _U_(8)                                               /**< (FLEXRAMECC_SR) Un-fixable error status Position */
#define FLEXRAMECC_SR_MEM_NOFIX_Msk           (_U_(0x1) << FLEXRAMECC_SR_MEM_NOFIX_Pos)            /**< (FLEXRAMECC_SR) Un-fixable error status Mask */
#define FLEXRAMECC_SR_MEM_NOFIX(value)        (FLEXRAMECC_SR_MEM_NOFIX_Msk & ((value) << FLEXRAMECC_SR_MEM_NOFIX_Pos))
#define FLEXRAMECC_SR_CPT_NOFIX_Pos           _U_(10)                                              /**< (FLEXRAMECC_SR) 5 bits counter Position */
#define FLEXRAMECC_SR_CPT_NOFIX_Msk           (_U_(0x1F) << FLEXRAMECC_SR_CPT_NOFIX_Pos)           /**< (FLEXRAMECC_SR) 5 bits counter Mask */
#define FLEXRAMECC_SR_CPT_NOFIX(value)        (FLEXRAMECC_SR_CPT_NOFIX_Msk & ((value) << FLEXRAMECC_SR_CPT_NOFIX_Pos))
#define FLEXRAMECC_SR_OVER_NOFIX_Pos          _U_(15)                                              /**< (FLEXRAMECC_SR) counter overflow Position */
#define FLEXRAMECC_SR_OVER_NOFIX_Msk          (_U_(0x1) << FLEXRAMECC_SR_OVER_NOFIX_Pos)           /**< (FLEXRAMECC_SR) counter overflow Mask */
#define FLEXRAMECC_SR_OVER_NOFIX(value)       (FLEXRAMECC_SR_OVER_NOFIX_Msk & ((value) << FLEXRAMECC_SR_OVER_NOFIX_Pos))
#define FLEXRAMECC_SR_HES_Pos                 _U_(24)                                              /**< (FLEXRAMECC_SR) Hardware Error Size Position */
#define FLEXRAMECC_SR_HES_Msk                 (_U_(0x7) << FLEXRAMECC_SR_HES_Pos)                  /**< (FLEXRAMECC_SR) Hardware Error Size Mask */
#define FLEXRAMECC_SR_HES(value)              (FLEXRAMECC_SR_HES_Msk & ((value) << FLEXRAMECC_SR_HES_Pos))
#define FLEXRAMECC_SR_TYPE_Pos                _U_(27)                                              /**< (FLEXRAMECC_SR) write or read access Position */
#define FLEXRAMECC_SR_TYPE_Msk                (_U_(0x1) << FLEXRAMECC_SR_TYPE_Pos)                 /**< (FLEXRAMECC_SR) write or read access Mask */
#define FLEXRAMECC_SR_TYPE(value)             (FLEXRAMECC_SR_TYPE_Msk & ((value) << FLEXRAMECC_SR_TYPE_Pos))
#define FLEXRAMECC_SR_Msk                     _U_(0x0F00FDFD)                                      /**< (FLEXRAMECC_SR) Register Mask  */


/* -------- FLEXRAMECC_IER : (FLEXRAMECC Offset: 0x10) ( /W 32) FLEXRAMECC Interrupt Enable Register -------- */
#define FLEXRAMECC_IER_MEM_FIX_Pos            _U_(0)                                               /**< (FLEXRAMECC_IER) Fixable error Position */
#define FLEXRAMECC_IER_MEM_FIX_Msk            (_U_(0x1) << FLEXRAMECC_IER_MEM_FIX_Pos)             /**< (FLEXRAMECC_IER) Fixable error Mask */
#define FLEXRAMECC_IER_MEM_FIX(value)         (FLEXRAMECC_IER_MEM_FIX_Msk & ((value) << FLEXRAMECC_IER_MEM_FIX_Pos))
#define FLEXRAMECC_IER_MEM_NOFIX_Pos          _U_(1)                                               /**< (FLEXRAMECC_IER) Un-fixable error Position */
#define FLEXRAMECC_IER_MEM_NOFIX_Msk          (_U_(0x1) << FLEXRAMECC_IER_MEM_NOFIX_Pos)           /**< (FLEXRAMECC_IER) Un-fixable error Mask */
#define FLEXRAMECC_IER_MEM_NOFIX(value)       (FLEXRAMECC_IER_MEM_NOFIX_Msk & ((value) << FLEXRAMECC_IER_MEM_NOFIX_Pos))
#define FLEXRAMECC_IER_Msk                    _U_(0x00000003)                                      /**< (FLEXRAMECC_IER) Register Mask  */


/* -------- FLEXRAMECC_IDR : (FLEXRAMECC Offset: 0x14) ( /W 32) FLEXRAMECC Interrupt Disable Register -------- */
#define FLEXRAMECC_IDR_MEM_FIX_Pos            _U_(0)                                               /**< (FLEXRAMECC_IDR) fixable error Position */
#define FLEXRAMECC_IDR_MEM_FIX_Msk            (_U_(0x1) << FLEXRAMECC_IDR_MEM_FIX_Pos)             /**< (FLEXRAMECC_IDR) fixable error Mask */
#define FLEXRAMECC_IDR_MEM_FIX(value)         (FLEXRAMECC_IDR_MEM_FIX_Msk & ((value) << FLEXRAMECC_IDR_MEM_FIX_Pos))
#define FLEXRAMECC_IDR_MEM_NOFIX_Pos          _U_(1)                                               /**< (FLEXRAMECC_IDR) un-fixable error Position */
#define FLEXRAMECC_IDR_MEM_NOFIX_Msk          (_U_(0x1) << FLEXRAMECC_IDR_MEM_NOFIX_Pos)           /**< (FLEXRAMECC_IDR) un-fixable error Mask */
#define FLEXRAMECC_IDR_MEM_NOFIX(value)       (FLEXRAMECC_IDR_MEM_NOFIX_Msk & ((value) << FLEXRAMECC_IDR_MEM_NOFIX_Pos))
#define FLEXRAMECC_IDR_Msk                    _U_(0x00000003)                                      /**< (FLEXRAMECC_IDR) Register Mask  */


/* -------- FLEXRAMECC_IMR : (FLEXRAMECC Offset: 0x18) ( R/ 32) FLEXRAMECC Interrupt Mask Register -------- */
#define FLEXRAMECC_IMR_MEM_FIX_Pos            _U_(0)                                               /**< (FLEXRAMECC_IMR) fixable error Position */
#define FLEXRAMECC_IMR_MEM_FIX_Msk            (_U_(0x1) << FLEXRAMECC_IMR_MEM_FIX_Pos)             /**< (FLEXRAMECC_IMR) fixable error Mask */
#define FLEXRAMECC_IMR_MEM_FIX(value)         (FLEXRAMECC_IMR_MEM_FIX_Msk & ((value) << FLEXRAMECC_IMR_MEM_FIX_Pos))
#define FLEXRAMECC_IMR_MEM_NOFIX_Pos          _U_(1)                                               /**< (FLEXRAMECC_IMR) un-fixable error Position */
#define FLEXRAMECC_IMR_MEM_NOFIX_Msk          (_U_(0x1) << FLEXRAMECC_IMR_MEM_NOFIX_Pos)           /**< (FLEXRAMECC_IMR) un-fixable error Mask */
#define FLEXRAMECC_IMR_MEM_NOFIX(value)       (FLEXRAMECC_IMR_MEM_NOFIX_Msk & ((value) << FLEXRAMECC_IMR_MEM_NOFIX_Pos))
#define FLEXRAMECC_IMR_Msk                    _U_(0x00000003)                                      /**< (FLEXRAMECC_IMR) Register Mask  */


/* -------- FLEXRAMECC_FAILAR : (FLEXRAMECC Offset: 0x1C) ( R/ 32) FLEXRAMECC Fail address register -------- */
#define FLEXRAMECC_FAILAR_ADDRESS_Pos         _U_(0)                                               /**< (FLEXRAMECC_FAILAR) address of the error detected Position */
#define FLEXRAMECC_FAILAR_ADDRESS_Msk         (_U_(0xFFFFFFFF) << FLEXRAMECC_FAILAR_ADDRESS_Pos)   /**< (FLEXRAMECC_FAILAR) address of the error detected Mask */
#define FLEXRAMECC_FAILAR_ADDRESS(value)      (FLEXRAMECC_FAILAR_ADDRESS_Msk & ((value) << FLEXRAMECC_FAILAR_ADDRESS_Pos))
#define FLEXRAMECC_FAILAR_Msk                 _U_(0xFFFFFFFF)                                      /**< (FLEXRAMECC_FAILAR) Register Mask  */


/** \brief FLEXRAMECC register offsets definitions */
#define FLEXRAMECC_CR_REG_OFST         (0x00)              /**< (FLEXRAMECC_CR) FLEXRAMECC Control Register Offset */
#define FLEXRAMECC_TESTCB1_REG_OFST    (0x04)              /**< (FLEXRAMECC_TESTCB1) FLEXRAMECC Test mode register 1 Offset */
#define FLEXRAMECC_SR_REG_OFST         (0x0C)              /**< (FLEXRAMECC_SR) FLEXRAMECC Status register Offset */
#define FLEXRAMECC_IER_REG_OFST        (0x10)              /**< (FLEXRAMECC_IER) FLEXRAMECC Interrupt Enable Register Offset */
#define FLEXRAMECC_IDR_REG_OFST        (0x14)              /**< (FLEXRAMECC_IDR) FLEXRAMECC Interrupt Disable Register Offset */
#define FLEXRAMECC_IMR_REG_OFST        (0x18)              /**< (FLEXRAMECC_IMR) FLEXRAMECC Interrupt Mask Register Offset */
#define FLEXRAMECC_FAILAR_REG_OFST     (0x1C)              /**< (FLEXRAMECC_FAILAR) FLEXRAMECC Fail address register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief FLEXRAMECC register API structure */
typedef struct
{
  __IO  uint32_t                       FLEXRAMECC_CR;      /**< Offset: 0x00 (R/W  32) FLEXRAMECC Control Register */
  __IO  uint32_t                       FLEXRAMECC_TESTCB1; /**< Offset: 0x04 (R/W  32) FLEXRAMECC Test mode register 1 */
  __I   uint8_t                        Reserved1[0x04];
  __I   uint32_t                       FLEXRAMECC_SR;      /**< Offset: 0x0C (R/   32) FLEXRAMECC Status register */
  __O   uint32_t                       FLEXRAMECC_IER;     /**< Offset: 0x10 ( /W  32) FLEXRAMECC Interrupt Enable Register */
  __O   uint32_t                       FLEXRAMECC_IDR;     /**< Offset: 0x14 ( /W  32) FLEXRAMECC Interrupt Disable Register */
  __I   uint32_t                       FLEXRAMECC_IMR;     /**< Offset: 0x18 (R/   32) FLEXRAMECC Interrupt Mask Register */
  __I   uint32_t                       FLEXRAMECC_FAILAR;  /**< Offset: 0x1C (R/   32) FLEXRAMECC Fail address register */
} flexramecc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_FLEXRAMECC_COMPONENT_H_ */
