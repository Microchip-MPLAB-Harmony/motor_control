/**
 * \brief Component description for SUPC
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
#ifndef _SAMRH71_SUPC_COMPONENT_H_
#define _SAMRH71_SUPC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SUPC                                         */
/* ************************************************************************** */

/* -------- SUPC_CR : (SUPC Offset: 0x00) ( /W 32) Supply Controller Control Register -------- */
#define SUPC_CR_ZERO_Pos                      _U_(2)                                               /**< (SUPC_CR) Shall be always write at '0' Position */
#define SUPC_CR_ZERO_Msk                      (_U_(0x1) << SUPC_CR_ZERO_Pos)                       /**< (SUPC_CR) Shall be always write at '0' Mask */
#define SUPC_CR_ZERO(value)                   (SUPC_CR_ZERO_Msk & ((value) << SUPC_CR_ZERO_Pos))  
#define SUPC_CR_TDXTALSEL_Pos                 _U_(3)                                               /**< (SUPC_CR) Timing Domain Crystal Oscillator Select Position */
#define SUPC_CR_TDXTALSEL_Msk                 (_U_(0x1) << SUPC_CR_TDXTALSEL_Pos)                  /**< (SUPC_CR) Timing Domain Crystal Oscillator Select Mask */
#define SUPC_CR_TDXTALSEL(value)              (SUPC_CR_TDXTALSEL_Msk & ((value) << SUPC_CR_TDXTALSEL_Pos))
#define   SUPC_CR_TDXTALSEL_NO_EFFECT_Val     _U_(0x0)                                             /**< (SUPC_CR) No effect.  */
#define   SUPC_CR_TDXTALSEL_CRYSTAL_SEL_Val   _U_(0x1)                                             /**< (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock of the timing domain (TD_SLCK) on the 32.768 kHz crystal oscillator output.  */
#define SUPC_CR_TDXTALSEL_NO_EFFECT           (SUPC_CR_TDXTALSEL_NO_EFFECT_Val << SUPC_CR_TDXTALSEL_Pos) /**< (SUPC_CR) No effect. Position  */
#define SUPC_CR_TDXTALSEL_CRYSTAL_SEL         (SUPC_CR_TDXTALSEL_CRYSTAL_SEL_Val << SUPC_CR_TDXTALSEL_Pos) /**< (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock of the timing domain (TD_SLCK) on the 32.768 kHz crystal oscillator output. Position  */
#define SUPC_CR_MDRCSEL_Pos                   _U_(5)                                               /**< (SUPC_CR) Monitoring Domain RC Oscillator Select Position */
#define SUPC_CR_MDRCSEL_Msk                   (_U_(0x1) << SUPC_CR_MDRCSEL_Pos)                    /**< (SUPC_CR) Monitoring Domain RC Oscillator Select Mask */
#define SUPC_CR_MDRCSEL(value)                (SUPC_CR_MDRCSEL_Msk & ((value) << SUPC_CR_MDRCSEL_Pos))
#define   SUPC_CR_MDRCSEL_NO_EFFECT_Val       _U_(0x0)                                             /**< (SUPC_CR) No effect.  */
#define   SUPC_CR_MDRCSEL_CRYSTAL_SEL_Val     _U_(0x1)                                             /**< (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock of the monitoring domain (MD_SLCK) on the slow RC oscillator output.  */
#define SUPC_CR_MDRCSEL_NO_EFFECT             (SUPC_CR_MDRCSEL_NO_EFFECT_Val << SUPC_CR_MDRCSEL_Pos) /**< (SUPC_CR) No effect. Position  */
#define SUPC_CR_MDRCSEL_CRYSTAL_SEL           (SUPC_CR_MDRCSEL_CRYSTAL_SEL_Val << SUPC_CR_MDRCSEL_Pos) /**< (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock of the monitoring domain (MD_SLCK) on the slow RC oscillator output. Position  */
#define SUPC_CR_KEY_Pos                       _U_(24)                                              /**< (SUPC_CR) Password Position */
#define SUPC_CR_KEY_Msk                       (_U_(0xFF) << SUPC_CR_KEY_Pos)                       /**< (SUPC_CR) Password Mask */
#define SUPC_CR_KEY(value)                    (SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos))    
#define   SUPC_CR_KEY_PASSWD_Val              _U_(0xA5)                                            /**< (SUPC_CR) Writing any other value in this field aborts the write operation.  */
#define SUPC_CR_KEY_PASSWD                    (SUPC_CR_KEY_PASSWD_Val << SUPC_CR_KEY_Pos)          /**< (SUPC_CR) Writing any other value in this field aborts the write operation. Position  */
#define SUPC_CR_Msk                           _U_(0xFF00002C)                                      /**< (SUPC_CR) Register Mask  */


/* -------- SUPC_SMMR : (SUPC Offset: 0x04) (R/W 32) Supply Controller Supply Monitor Mode Register -------- */
#define SUPC_SMMR_CORESMUSEL_Pos              _U_(23)                                              /**< (SUPC_SMMR) Core Supply Monitor User Selection Position */
#define SUPC_SMMR_CORESMUSEL_Msk              (_U_(0x1) << SUPC_SMMR_CORESMUSEL_Pos)               /**< (SUPC_SMMR) Core Supply Monitor User Selection Mask */
#define SUPC_SMMR_CORESMUSEL(value)           (SUPC_SMMR_CORESMUSEL_Msk & ((value) << SUPC_SMMR_CORESMUSEL_Pos))
#define SUPC_SMMR_Msk                         _U_(0x00800000)                                      /**< (SUPC_SMMR) Register Mask  */


/* -------- SUPC_MR : (SUPC Offset: 0x08) (R/W 32) Supply Controller Mode Register -------- */
#define SUPC_MR_CORSMRSTEN_Pos                _U_(12)                                              /**< (SUPC_MR) VDDCORE Supply Monitor Reset Enable Position */
#define SUPC_MR_CORSMRSTEN_Msk                (_U_(0x1) << SUPC_MR_CORSMRSTEN_Pos)                 /**< (SUPC_MR) VDDCORE Supply Monitor Reset Enable Mask */
#define SUPC_MR_CORSMRSTEN(value)             (SUPC_MR_CORSMRSTEN_Msk & ((value) << SUPC_MR_CORSMRSTEN_Pos))
#define   SUPC_MR_CORSMRSTEN_NOT_ENABLE_Val   _U_(0x0)                                             /**< (SUPC_MR) The core reset signal vddcore_nreset is not affected when a VDDCORE supply monitor detection occurs.  */
#define   SUPC_MR_CORSMRSTEN_ENABLE_Val       _U_(0x1)                                             /**< (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a VDDCORE supply monitor detection occurs.  */
#define SUPC_MR_CORSMRSTEN_NOT_ENABLE         (SUPC_MR_CORSMRSTEN_NOT_ENABLE_Val << SUPC_MR_CORSMRSTEN_Pos) /**< (SUPC_MR) The core reset signal vddcore_nreset is not affected when a VDDCORE supply monitor detection occurs. Position  */
#define SUPC_MR_CORSMRSTEN_ENABLE             (SUPC_MR_CORSMRSTEN_ENABLE_Val << SUPC_MR_CORSMRSTEN_Pos) /**< (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a VDDCORE supply monitor detection occurs. Position  */
#define SUPC_MR_CORSMDIS_Pos                  _U_(13)                                              /**< (SUPC_MR) VDDCORE Supply Monitor Disable Position */
#define SUPC_MR_CORSMDIS_Msk                  (_U_(0x1) << SUPC_MR_CORSMDIS_Pos)                   /**< (SUPC_MR) VDDCORE Supply Monitor Disable Mask */
#define SUPC_MR_CORSMDIS(value)               (SUPC_MR_CORSMDIS_Msk & ((value) << SUPC_MR_CORSMDIS_Pos))
#define   SUPC_MR_CORSMDIS_ENABLE_Val         _U_(0x0)                                             /**< (SUPC_MR) The VDDCORE supply monitor is enabled.  */
#define   SUPC_MR_CORSMDIS_DISABLE_Val        _U_(0x1)                                             /**< (SUPC_MR) The VDDCORE supply monitor is disabled.  */
#define SUPC_MR_CORSMDIS_ENABLE               (SUPC_MR_CORSMDIS_ENABLE_Val << SUPC_MR_CORSMDIS_Pos) /**< (SUPC_MR) The VDDCORE supply monitor is enabled. Position  */
#define SUPC_MR_CORSMDIS_DISABLE              (SUPC_MR_CORSMDIS_DISABLE_Val << SUPC_MR_CORSMDIS_Pos) /**< (SUPC_MR) The VDDCORE supply monitor is disabled. Position  */
#define SUPC_MR_OSCBYPASS_Pos                 _U_(20)                                              /**< (SUPC_MR) Oscillator Bypass Position */
#define SUPC_MR_OSCBYPASS_Msk                 (_U_(0x1) << SUPC_MR_OSCBYPASS_Pos)                  /**< (SUPC_MR) Oscillator Bypass Mask */
#define SUPC_MR_OSCBYPASS(value)              (SUPC_MR_OSCBYPASS_Msk & ((value) << SUPC_MR_OSCBYPASS_Pos))
#define   SUPC_MR_OSCBYPASS_NO_EFFECT_Val     _U_(0x0)                                             /**< (SUPC_MR) No effect. Clock selection depends on the value of XTALSEL (SUPC_CR).  */
#define   SUPC_MR_OSCBYPASS_BYPASS_Val        _U_(0x1)                                             /**< (SUPC_MR) The 32.768 kHz crystal oscillator is bypassed if XTALSEL (SUPC_CR) is set. OSCBYPASS must be set prior to setting XTALSEL.  */
#define SUPC_MR_OSCBYPASS_NO_EFFECT           (SUPC_MR_OSCBYPASS_NO_EFFECT_Val << SUPC_MR_OSCBYPASS_Pos) /**< (SUPC_MR) No effect. Clock selection depends on the value of XTALSEL (SUPC_CR). Position  */
#define SUPC_MR_OSCBYPASS_BYPASS              (SUPC_MR_OSCBYPASS_BYPASS_Val << SUPC_MR_OSCBYPASS_Pos) /**< (SUPC_MR) The 32.768 kHz crystal oscillator is bypassed if XTALSEL (SUPC_CR) is set. OSCBYPASS must be set prior to setting XTALSEL. Position  */
#define SUPC_MR_FXTALSTUP_Pos                 _U_(22)                                              /**< (SUPC_MR) Fast Startup 32.768 kHz Crystal Oscillator Position */
#define SUPC_MR_FXTALSTUP_Msk                 (_U_(0x1) << SUPC_MR_FXTALSTUP_Pos)                  /**< (SUPC_MR) Fast Startup 32.768 kHz Crystal Oscillator Mask */
#define SUPC_MR_FXTALSTUP(value)              (SUPC_MR_FXTALSTUP_Msk & ((value) << SUPC_MR_FXTALSTUP_Pos))
#define SUPC_MR_KEY_Pos                       _U_(24)                                              /**< (SUPC_MR) Password Key Position */
#define SUPC_MR_KEY_Msk                       (_U_(0xFF) << SUPC_MR_KEY_Pos)                       /**< (SUPC_MR) Password Key Mask */
#define SUPC_MR_KEY(value)                    (SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos))    
#define   SUPC_MR_KEY_PASSWD_Val              _U_(0xA5)                                            /**< (SUPC_MR) Writing any other value in this field aborts the write operation.  */
#define SUPC_MR_KEY_PASSWD                    (SUPC_MR_KEY_PASSWD_Val << SUPC_MR_KEY_Pos)          /**< (SUPC_MR) Writing any other value in this field aborts the write operation. Position  */
#define SUPC_MR_Msk                           _U_(0xFF503000)                                      /**< (SUPC_MR) Register Mask  */


/* -------- SUPC_SR : (SUPC Offset: 0x14) ( R/ 32) Supply Controller Status Register -------- */
#define SUPC_SR_CORSMRSTS_Pos                 _U_(3)                                               /**< (SUPC_SR) VDDCORE Supply Monitor Reset Status (cleared on read) Position */
#define SUPC_SR_CORSMRSTS_Msk                 (_U_(0x1) << SUPC_SR_CORSMRSTS_Pos)                  /**< (SUPC_SR) VDDCORE Supply Monitor Reset Status (cleared on read) Mask */
#define SUPC_SR_CORSMRSTS(value)              (SUPC_SR_CORSMRSTS_Msk & ((value) << SUPC_SR_CORSMRSTS_Pos))
#define   SUPC_SR_CORSMRSTS_NO_Val            _U_(0x0)                                             /**< (SUPC_SR) No VDDCORE Supply Monitor reset event has been detected since the last read of the SUPC_SR.  */
#define   SUPC_SR_CORSMRSTS_PRESENT_Val       _U_(0x1)                                             /**< (SUPC_SR) At least one VDDCORE Supply Monitor reset event has been detected since the last read of the SUPC_SR.  */
#define SUPC_SR_CORSMRSTS_NO                  (SUPC_SR_CORSMRSTS_NO_Val << SUPC_SR_CORSMRSTS_Pos)  /**< (SUPC_SR) No VDDCORE Supply Monitor reset event has been detected since the last read of the SUPC_SR. Position  */
#define SUPC_SR_CORSMRSTS_PRESENT             (SUPC_SR_CORSMRSTS_PRESENT_Val << SUPC_SR_CORSMRSTS_Pos) /**< (SUPC_SR) At least one VDDCORE Supply Monitor reset event has been detected since the last read of the SUPC_SR. Position  */
#define SUPC_SR_TDOSCSEL_Pos                  _U_(7)                                               /**< (SUPC_SR) 32 kHz Oscillator Selection Status Position */
#define SUPC_SR_TDOSCSEL_Msk                  (_U_(0x1) << SUPC_SR_TDOSCSEL_Pos)                   /**< (SUPC_SR) 32 kHz Oscillator Selection Status Mask */
#define SUPC_SR_TDOSCSEL(value)               (SUPC_SR_TDOSCSEL_Msk & ((value) << SUPC_SR_TDOSCSEL_Pos))
#define   SUPC_SR_TDOSCSEL_RC_Val             _U_(0x0)                                             /**< (SUPC_SR) The timing domain slow clock, TD_SLCK, is generated by the slow RC oscillator.  */
#define   SUPC_SR_TDOSCSEL_CRYST_Val          _U_(0x1)                                             /**< (SUPC_SR) The timing domain slow clock, TD_SLCK, is generated by the 32.768 kHz crystal oscillator.  */
#define SUPC_SR_TDOSCSEL_RC                   (SUPC_SR_TDOSCSEL_RC_Val << SUPC_SR_TDOSCSEL_Pos)    /**< (SUPC_SR) The timing domain slow clock, TD_SLCK, is generated by the slow RC oscillator. Position  */
#define SUPC_SR_TDOSCSEL_CRYST                (SUPC_SR_TDOSCSEL_CRYST_Val << SUPC_SR_TDOSCSEL_Pos) /**< (SUPC_SR) The timing domain slow clock, TD_SLCK, is generated by the 32.768 kHz crystal oscillator. Position  */
#define SUPC_SR_Msk                           _U_(0x00000088)                                      /**< (SUPC_SR) Register Mask  */


/* -------- SUPC_PWR : (SUPC Offset: 0x1C) (R/W 32) Supply Controller Power Register -------- */
#define SUPC_PWR_ZERO_Pos                     _U_(18)                                              /**< (SUPC_PWR) MD_SLCK always generated by the slow RC oscillator Position */
#define SUPC_PWR_ZERO_Msk                     (_U_(0x1) << SUPC_PWR_ZERO_Pos)                      /**< (SUPC_PWR) MD_SLCK always generated by the slow RC oscillator Mask */
#define SUPC_PWR_ZERO(value)                  (SUPC_PWR_ZERO_Msk & ((value) << SUPC_PWR_ZERO_Pos))
#define SUPC_PWR_Msk                          _U_(0x00040000)                                      /**< (SUPC_PWR) Register Mask  */


/* -------- SYSC_WPMR : (SUPC Offset: 0xD4) (R/W 32) Write Protection Mode Register -------- */
#define SYSC_WPMR_WPEN_Pos                    _U_(0)                                               /**< (SYSC_WPMR) Write Protection Enable Position */
#define SYSC_WPMR_WPEN_Msk                    (_U_(0x1) << SYSC_WPMR_WPEN_Pos)                     /**< (SYSC_WPMR) Write Protection Enable Mask */
#define SYSC_WPMR_WPEN(value)                 (SYSC_WPMR_WPEN_Msk & ((value) << SYSC_WPMR_WPEN_Pos))
#define SYSC_WPMR_WPKEY_Pos                   _U_(8)                                               /**< (SYSC_WPMR) Write Protection Key. Position */
#define SYSC_WPMR_WPKEY_Msk                   (_U_(0xFFFFFF) << SYSC_WPMR_WPKEY_Pos)               /**< (SYSC_WPMR) Write Protection Key. Mask */
#define SYSC_WPMR_WPKEY(value)                (SYSC_WPMR_WPKEY_Msk & ((value) << SYSC_WPMR_WPKEY_Pos))
#define   SYSC_WPMR_WPKEY_PASSWD_Val          _U_(0x525443)                                        /**< (SYSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define SYSC_WPMR_WPKEY_PASSWD                (SYSC_WPMR_WPKEY_PASSWD_Val << SYSC_WPMR_WPKEY_Pos)  /**< (SYSC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define SYSC_WPMR_Msk                         _U_(0xFFFFFF01)                                      /**< (SYSC_WPMR) Register Mask  */


/** \brief SUPC register offsets definitions */
#define SUPC_CR_REG_OFST               (0x00)              /**< (SUPC_CR) Supply Controller Control Register Offset */
#define SUPC_SMMR_REG_OFST             (0x04)              /**< (SUPC_SMMR) Supply Controller Supply Monitor Mode Register Offset */
#define SUPC_MR_REG_OFST               (0x08)              /**< (SUPC_MR) Supply Controller Mode Register Offset */
#define SUPC_SR_REG_OFST               (0x14)              /**< (SUPC_SR) Supply Controller Status Register Offset */
#define SUPC_PWR_REG_OFST              (0x1C)              /**< (SUPC_PWR) Supply Controller Power Register Offset */
#define SYSC_WPMR_REG_OFST             (0xD4)              /**< (SYSC_WPMR) Write Protection Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SUPC register API structure */
typedef struct
{
  __O   uint32_t                       SUPC_CR;            /**< Offset: 0x00 ( /W  32) Supply Controller Control Register */
  __IO  uint32_t                       SUPC_SMMR;          /**< Offset: 0x04 (R/W  32) Supply Controller Supply Monitor Mode Register */
  __IO  uint32_t                       SUPC_MR;            /**< Offset: 0x08 (R/W  32) Supply Controller Mode Register */
  __I   uint8_t                        Reserved1[0x08];
  __I   uint32_t                       SUPC_SR;            /**< Offset: 0x14 (R/   32) Supply Controller Status Register */
  __I   uint8_t                        Reserved2[0x04];
  __IO  uint32_t                       SUPC_PWR;           /**< Offset: 0x1C (R/W  32) Supply Controller Power Register */
  __I   uint8_t                        Reserved3[0xB4];
  __IO  uint32_t                       SYSC_WPMR;          /**< Offset: 0xD4 (R/W  32) Write Protection Mode Register */
} supc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_SUPC_COMPONENT_H_ */
