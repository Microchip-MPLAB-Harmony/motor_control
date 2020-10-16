/**
 * \brief Component description for SFR
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
#ifndef _SAMRH71_SFR_COMPONENT_H_
#define _SAMRH71_SFR_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SFR                                          */
/* ************************************************************************** */

/* -------- SFR_CAN0 : (SFR Offset: 0xA0) (R/W 32) CAN0 MSB Base Address 0 -------- */
#define SFR_CAN0_EXT_MEM_ADDR_Pos             _U_(16)                                              /**< (SFR_CAN0) MSB Base Address Position */
#define SFR_CAN0_EXT_MEM_ADDR_Msk             (_U_(0xFFFF) << SFR_CAN0_EXT_MEM_ADDR_Pos)           /**< (SFR_CAN0) MSB Base Address Mask */
#define SFR_CAN0_EXT_MEM_ADDR(value)          (SFR_CAN0_EXT_MEM_ADDR_Msk & ((value) << SFR_CAN0_EXT_MEM_ADDR_Pos))
#define SFR_CAN0_Msk                          _U_(0xFFFF0000)                                      /**< (SFR_CAN0) Register Mask  */


/* -------- SFR_CAN1 : (SFR Offset: 0xA4) (R/W 32) CAN0 MSB Base Address 1 -------- */
#define SFR_CAN1_EXT_MEM_ADDR_Pos             _U_(16)                                              /**< (SFR_CAN1) MSB Base Address Position */
#define SFR_CAN1_EXT_MEM_ADDR_Msk             (_U_(0xFFFF) << SFR_CAN1_EXT_MEM_ADDR_Pos)           /**< (SFR_CAN1) MSB Base Address Mask */
#define SFR_CAN1_EXT_MEM_ADDR(value)          (SFR_CAN1_EXT_MEM_ADDR_Msk & ((value) << SFR_CAN1_EXT_MEM_ADDR_Pos))
#define SFR_CAN1_Msk                          _U_(0xFFFF0000)                                      /**< (SFR_CAN1) Register Mask  */


/* -------- SFR_WPMR : (SFR Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define SFR_WPMR_WPEN_Pos                     _U_(0)                                               /**< (SFR_WPMR) Write Protection Enable Position */
#define SFR_WPMR_WPEN_Msk                     (_U_(0x1) << SFR_WPMR_WPEN_Pos)                      /**< (SFR_WPMR) Write Protection Enable Mask */
#define SFR_WPMR_WPEN(value)                  (SFR_WPMR_WPEN_Msk & ((value) << SFR_WPMR_WPEN_Pos))
#define SFR_WPMR_WPKEY_Pos                    _U_(8)                                               /**< (SFR_WPMR) Write Protection Key Position */
#define SFR_WPMR_WPKEY_Msk                    (_U_(0xFFFFFF) << SFR_WPMR_WPKEY_Pos)                /**< (SFR_WPMR) Write Protection Key Mask */
#define SFR_WPMR_WPKEY(value)                 (SFR_WPMR_WPKEY_Msk & ((value) << SFR_WPMR_WPKEY_Pos))
#define   SFR_WPMR_WPKEY_PASSWD_Val           _U_(0x534652)                                        /**< (SFR_WPMR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define SFR_WPMR_WPKEY_PASSWD                 (SFR_WPMR_WPKEY_PASSWD_Val << SFR_WPMR_WPKEY_Pos)    /**< (SFR_WPMR) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define SFR_WPMR_Msk                          _U_(0xFFFFFF01)                                      /**< (SFR_WPMR) Register Mask  */


/** \brief SFR register offsets definitions */
#define SFR_CAN0_REG_OFST              (0xA0)              /**< (SFR_CAN0) CAN0 MSB Base Address 0 Offset */
#define SFR_CAN1_REG_OFST              (0xA4)              /**< (SFR_CAN1) CAN0 MSB Base Address 1 Offset */
#define SFR_WPMR_REG_OFST              (0xE4)              /**< (SFR_WPMR) Write Protection Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SFR register API structure */
typedef struct
{
  __I   uint8_t                        Reserved1[0xA0];
  __IO  uint32_t                       SFR_CAN0;           /**< Offset: 0xA0 (R/W  32) CAN0 MSB Base Address 0 */
  __IO  uint32_t                       SFR_CAN1;           /**< Offset: 0xA4 (R/W  32) CAN0 MSB Base Address 1 */
  __I   uint8_t                        Reserved2[0x3C];
  __IO  uint32_t                       SFR_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
} sfr_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_SFR_COMPONENT_H_ */
