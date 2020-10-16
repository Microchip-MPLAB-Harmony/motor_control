/**
 * \brief Component description for SHA
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
#ifndef _SAMRH71_SHA_COMPONENT_H_
#define _SAMRH71_SHA_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SHA                                          */
/* ************************************************************************** */

/* -------- SHA_CR : (SHA Offset: 0x00) ( /W 32) Control Register -------- */
#define SHA_CR_START_Pos                      _U_(0)                                               /**< (SHA_CR) Start Processing Position */
#define SHA_CR_START_Msk                      (_U_(0x1) << SHA_CR_START_Pos)                       /**< (SHA_CR) Start Processing Mask */
#define SHA_CR_START(value)                   (SHA_CR_START_Msk & ((value) << SHA_CR_START_Pos))  
#define SHA_CR_FIRST_Pos                      _U_(4)                                               /**< (SHA_CR) First Block of a Message Position */
#define SHA_CR_FIRST_Msk                      (_U_(0x1) << SHA_CR_FIRST_Pos)                       /**< (SHA_CR) First Block of a Message Mask */
#define SHA_CR_FIRST(value)                   (SHA_CR_FIRST_Msk & ((value) << SHA_CR_FIRST_Pos))  
#define SHA_CR_SWRST_Pos                      _U_(8)                                               /**< (SHA_CR) Software Reset Position */
#define SHA_CR_SWRST_Msk                      (_U_(0x1) << SHA_CR_SWRST_Pos)                       /**< (SHA_CR) Software Reset Mask */
#define SHA_CR_SWRST(value)                   (SHA_CR_SWRST_Msk & ((value) << SHA_CR_SWRST_Pos))  
#define SHA_CR_WUIHV_Pos                      _U_(12)                                              /**< (SHA_CR) Write User Initial Hash Values Position */
#define SHA_CR_WUIHV_Msk                      (_U_(0x1) << SHA_CR_WUIHV_Pos)                       /**< (SHA_CR) Write User Initial Hash Values Mask */
#define SHA_CR_WUIHV(value)                   (SHA_CR_WUIHV_Msk & ((value) << SHA_CR_WUIHV_Pos))  
#define SHA_CR_WUIEHV_Pos                     _U_(13)                                              /**< (SHA_CR) Write User Initial or Expected Hash Values Position */
#define SHA_CR_WUIEHV_Msk                     (_U_(0x1) << SHA_CR_WUIEHV_Pos)                      /**< (SHA_CR) Write User Initial or Expected Hash Values Mask */
#define SHA_CR_WUIEHV(value)                  (SHA_CR_WUIEHV_Msk & ((value) << SHA_CR_WUIEHV_Pos))
#define SHA_CR_Msk                            _U_(0x00003111)                                      /**< (SHA_CR) Register Mask  */


/* -------- SHA_MR : (SHA Offset: 0x04) (R/W 32) Mode Register -------- */
#define SHA_MR_SMOD_Pos                       _U_(0)                                               /**< (SHA_MR) Start Mode Position */
#define SHA_MR_SMOD_Msk                       (_U_(0x3) << SHA_MR_SMOD_Pos)                        /**< (SHA_MR) Start Mode Mask */
#define SHA_MR_SMOD(value)                    (SHA_MR_SMOD_Msk & ((value) << SHA_MR_SMOD_Pos))    
#define   SHA_MR_SMOD_MANUAL_START_Val        _U_(0x0)                                             /**< (SHA_MR) Manual mode  */
#define   SHA_MR_SMOD_AUTO_START_Val          _U_(0x1)                                             /**< (SHA_MR) Auto mode  */
#define   SHA_MR_SMOD_IDATAR0_START_Val       _U_(0x2)                                             /**< (SHA_MR) SHA_IDATAR0 access only mode (mandatory when DMA is used)  */
#define SHA_MR_SMOD_MANUAL_START              (SHA_MR_SMOD_MANUAL_START_Val << SHA_MR_SMOD_Pos)    /**< (SHA_MR) Manual mode Position  */
#define SHA_MR_SMOD_AUTO_START                (SHA_MR_SMOD_AUTO_START_Val << SHA_MR_SMOD_Pos)      /**< (SHA_MR) Auto mode Position  */
#define SHA_MR_SMOD_IDATAR0_START             (SHA_MR_SMOD_IDATAR0_START_Val << SHA_MR_SMOD_Pos)   /**< (SHA_MR) SHA_IDATAR0 access only mode (mandatory when DMA is used) Position  */
#define SHA_MR_UIHV_Pos                       _U_(5)                                               /**< (SHA_MR) User Initial Hash Value Registers Position */
#define SHA_MR_UIHV_Msk                       (_U_(0x1) << SHA_MR_UIHV_Pos)                        /**< (SHA_MR) User Initial Hash Value Registers Mask */
#define SHA_MR_UIHV(value)                    (SHA_MR_UIHV_Msk & ((value) << SHA_MR_UIHV_Pos))    
#define SHA_MR_UIEHV_Pos                      _U_(6)                                               /**< (SHA_MR) User Initial or Expected Hash Value Registers Position */
#define SHA_MR_UIEHV_Msk                      (_U_(0x1) << SHA_MR_UIEHV_Pos)                       /**< (SHA_MR) User Initial or Expected Hash Value Registers Mask */
#define SHA_MR_UIEHV(value)                   (SHA_MR_UIEHV_Msk & ((value) << SHA_MR_UIEHV_Pos))  
#define SHA_MR_ALGO_Pos                       _U_(8)                                               /**< (SHA_MR) SHA Algorithm Position */
#define SHA_MR_ALGO_Msk                       (_U_(0xF) << SHA_MR_ALGO_Pos)                        /**< (SHA_MR) SHA Algorithm Mask */
#define SHA_MR_ALGO(value)                    (SHA_MR_ALGO_Msk & ((value) << SHA_MR_ALGO_Pos))    
#define   SHA_MR_ALGO_SHA1_Val                _U_(0x0)                                             /**< (SHA_MR) SHA1 algorithm processed  */
#define   SHA_MR_ALGO_SHA256_Val              _U_(0x1)                                             /**< (SHA_MR) SHA256 algorithm processed  */
#define   SHA_MR_ALGO_SHA384_Val              _U_(0x2)                                             /**< (SHA_MR) SHA384 algorithm processed  */
#define   SHA_MR_ALGO_SHA512_Val              _U_(0x3)                                             /**< (SHA_MR) SHA512 algorithm processed  */
#define   SHA_MR_ALGO_SHA224_Val              _U_(0x4)                                             /**< (SHA_MR) SHA224 algorithm processed  */
#define   SHA_MR_ALGO_HMAC_SHA1_Val           _U_(0x8)                                             /**< (SHA_MR) HMAC algorithm with SHA1 Hash processed  */
#define   SHA_MR_ALGO_HMAC_SHA256_Val         _U_(0x9)                                             /**< (SHA_MR) HMAC algorithm with SHA256 Hash processed  */
#define   SHA_MR_ALGO_HMAC_SHA384_Val         _U_(0xA)                                             /**< (SHA_MR) HMAC algorithm with SHA384 Hash processed  */
#define   SHA_MR_ALGO_HMAC_SHA512_Val         _U_(0xB)                                             /**< (SHA_MR) HMAC algorithm with SHA512 Hash processed  */
#define   SHA_MR_ALGO_HMAC_SHA224_Val         _U_(0xC)                                             /**< (SHA_MR) HMAC algorithm with SHA224 Hash processed  */
#define SHA_MR_ALGO_SHA1                      (SHA_MR_ALGO_SHA1_Val << SHA_MR_ALGO_Pos)            /**< (SHA_MR) SHA1 algorithm processed Position  */
#define SHA_MR_ALGO_SHA256                    (SHA_MR_ALGO_SHA256_Val << SHA_MR_ALGO_Pos)          /**< (SHA_MR) SHA256 algorithm processed Position  */
#define SHA_MR_ALGO_SHA384                    (SHA_MR_ALGO_SHA384_Val << SHA_MR_ALGO_Pos)          /**< (SHA_MR) SHA384 algorithm processed Position  */
#define SHA_MR_ALGO_SHA512                    (SHA_MR_ALGO_SHA512_Val << SHA_MR_ALGO_Pos)          /**< (SHA_MR) SHA512 algorithm processed Position  */
#define SHA_MR_ALGO_SHA224                    (SHA_MR_ALGO_SHA224_Val << SHA_MR_ALGO_Pos)          /**< (SHA_MR) SHA224 algorithm processed Position  */
#define SHA_MR_ALGO_HMAC_SHA1                 (SHA_MR_ALGO_HMAC_SHA1_Val << SHA_MR_ALGO_Pos)       /**< (SHA_MR) HMAC algorithm with SHA1 Hash processed Position  */
#define SHA_MR_ALGO_HMAC_SHA256               (SHA_MR_ALGO_HMAC_SHA256_Val << SHA_MR_ALGO_Pos)     /**< (SHA_MR) HMAC algorithm with SHA256 Hash processed Position  */
#define SHA_MR_ALGO_HMAC_SHA384               (SHA_MR_ALGO_HMAC_SHA384_Val << SHA_MR_ALGO_Pos)     /**< (SHA_MR) HMAC algorithm with SHA384 Hash processed Position  */
#define SHA_MR_ALGO_HMAC_SHA512               (SHA_MR_ALGO_HMAC_SHA512_Val << SHA_MR_ALGO_Pos)     /**< (SHA_MR) HMAC algorithm with SHA512 Hash processed Position  */
#define SHA_MR_ALGO_HMAC_SHA224               (SHA_MR_ALGO_HMAC_SHA224_Val << SHA_MR_ALGO_Pos)     /**< (SHA_MR) HMAC algorithm with SHA224 Hash processed Position  */
#define SHA_MR_DUALBUFF_Pos                   _U_(16)                                              /**< (SHA_MR) Dual Input Buffer Position */
#define SHA_MR_DUALBUFF_Msk                   (_U_(0x1) << SHA_MR_DUALBUFF_Pos)                    /**< (SHA_MR) Dual Input Buffer Mask */
#define SHA_MR_DUALBUFF(value)                (SHA_MR_DUALBUFF_Msk & ((value) << SHA_MR_DUALBUFF_Pos))
#define   SHA_MR_DUALBUFF_INACTIVE_Val        _U_(0x0)                                             /**< (SHA_MR) SHA_IDATARx and SHA_IODATARx cannot be written during processing of previous block.  */
#define   SHA_MR_DUALBUFF_ACTIVE_Val          _U_(0x1)                                             /**< (SHA_MR) SHA_IDATARx and SHA_IODATARx can be written during processing of previous block when SMOD value = 2. It speeds up the overall runtime of large files.  */
#define SHA_MR_DUALBUFF_INACTIVE              (SHA_MR_DUALBUFF_INACTIVE_Val << SHA_MR_DUALBUFF_Pos) /**< (SHA_MR) SHA_IDATARx and SHA_IODATARx cannot be written during processing of previous block. Position  */
#define SHA_MR_DUALBUFF_ACTIVE                (SHA_MR_DUALBUFF_ACTIVE_Val << SHA_MR_DUALBUFF_Pos)  /**< (SHA_MR) SHA_IDATARx and SHA_IODATARx can be written during processing of previous block when SMOD value = 2. It speeds up the overall runtime of large files. Position  */
#define SHA_MR_CHECK_Pos                      _U_(24)                                              /**< (SHA_MR) Hash Check Position */
#define SHA_MR_CHECK_Msk                      (_U_(0x3) << SHA_MR_CHECK_Pos)                       /**< (SHA_MR) Hash Check Mask */
#define SHA_MR_CHECK(value)                   (SHA_MR_CHECK_Msk & ((value) << SHA_MR_CHECK_Pos))  
#define   SHA_MR_CHECK_NO_CHECK_Val           _U_(0x0)                                             /**< (SHA_MR) No check is performed  */
#define   SHA_MR_CHECK_CHECK_EHV_Val          _U_(0x1)                                             /**< (SHA_MR) Check is performed with expected hash stored in internal expected hash value registers.  */
#define   SHA_MR_CHECK_CHECK_MESSAGE_Val      _U_(0x2)                                             /**< (SHA_MR) Check is performed with expected hash provided after the message.  */
#define SHA_MR_CHECK_NO_CHECK                 (SHA_MR_CHECK_NO_CHECK_Val << SHA_MR_CHECK_Pos)      /**< (SHA_MR) No check is performed Position  */
#define SHA_MR_CHECK_CHECK_EHV                (SHA_MR_CHECK_CHECK_EHV_Val << SHA_MR_CHECK_Pos)     /**< (SHA_MR) Check is performed with expected hash stored in internal expected hash value registers. Position  */
#define SHA_MR_CHECK_CHECK_MESSAGE            (SHA_MR_CHECK_CHECK_MESSAGE_Val << SHA_MR_CHECK_Pos) /**< (SHA_MR) Check is performed with expected hash provided after the message. Position  */
#define SHA_MR_CHKCNT_Pos                     _U_(28)                                              /**< (SHA_MR) Check Counter Position */
#define SHA_MR_CHKCNT_Msk                     (_U_(0xF) << SHA_MR_CHKCNT_Pos)                      /**< (SHA_MR) Check Counter Mask */
#define SHA_MR_CHKCNT(value)                  (SHA_MR_CHKCNT_Msk & ((value) << SHA_MR_CHKCNT_Pos))
#define SHA_MR_Msk                            _U_(0xF3010F63)                                      /**< (SHA_MR) Register Mask  */


/* -------- SHA_IER : (SHA Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define SHA_IER_DATRDY_Pos                    _U_(0)                                               /**< (SHA_IER) Data Ready Interrupt Enable Position */
#define SHA_IER_DATRDY_Msk                    (_U_(0x1) << SHA_IER_DATRDY_Pos)                     /**< (SHA_IER) Data Ready Interrupt Enable Mask */
#define SHA_IER_DATRDY(value)                 (SHA_IER_DATRDY_Msk & ((value) << SHA_IER_DATRDY_Pos))
#define SHA_IER_URAD_Pos                      _U_(8)                                               /**< (SHA_IER) Unspecified Register Access Detection Interrupt Enable Position */
#define SHA_IER_URAD_Msk                      (_U_(0x1) << SHA_IER_URAD_Pos)                       /**< (SHA_IER) Unspecified Register Access Detection Interrupt Enable Mask */
#define SHA_IER_URAD(value)                   (SHA_IER_URAD_Msk & ((value) << SHA_IER_URAD_Pos))  
#define SHA_IER_CHECKF_Pos                    _U_(16)                                              /**< (SHA_IER) Check Done Interrupt Enable Position */
#define SHA_IER_CHECKF_Msk                    (_U_(0x1) << SHA_IER_CHECKF_Pos)                     /**< (SHA_IER) Check Done Interrupt Enable Mask */
#define SHA_IER_CHECKF(value)                 (SHA_IER_CHECKF_Msk & ((value) << SHA_IER_CHECKF_Pos))
#define SHA_IER_SECE_Pos                      _U_(24)                                              /**< (SHA_IER) Safety Event Interrupt Enable Position */
#define SHA_IER_SECE_Msk                      (_U_(0x1) << SHA_IER_SECE_Pos)                       /**< (SHA_IER) Safety Event Interrupt Enable Mask */
#define SHA_IER_SECE(value)                   (SHA_IER_SECE_Msk & ((value) << SHA_IER_SECE_Pos))  
#define SHA_IER_Msk                           _U_(0x01010101)                                      /**< (SHA_IER) Register Mask  */


/* -------- SHA_IDR : (SHA Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define SHA_IDR_DATRDY_Pos                    _U_(0)                                               /**< (SHA_IDR) Data Ready Interrupt Disable Position */
#define SHA_IDR_DATRDY_Msk                    (_U_(0x1) << SHA_IDR_DATRDY_Pos)                     /**< (SHA_IDR) Data Ready Interrupt Disable Mask */
#define SHA_IDR_DATRDY(value)                 (SHA_IDR_DATRDY_Msk & ((value) << SHA_IDR_DATRDY_Pos))
#define SHA_IDR_URAD_Pos                      _U_(8)                                               /**< (SHA_IDR) Unspecified Register Access Detection Interrupt Disable Position */
#define SHA_IDR_URAD_Msk                      (_U_(0x1) << SHA_IDR_URAD_Pos)                       /**< (SHA_IDR) Unspecified Register Access Detection Interrupt Disable Mask */
#define SHA_IDR_URAD(value)                   (SHA_IDR_URAD_Msk & ((value) << SHA_IDR_URAD_Pos))  
#define SHA_IDR_CHECKF_Pos                    _U_(16)                                              /**< (SHA_IDR) Check Done Interrupt Disable Position */
#define SHA_IDR_CHECKF_Msk                    (_U_(0x1) << SHA_IDR_CHECKF_Pos)                     /**< (SHA_IDR) Check Done Interrupt Disable Mask */
#define SHA_IDR_CHECKF(value)                 (SHA_IDR_CHECKF_Msk & ((value) << SHA_IDR_CHECKF_Pos))
#define SHA_IDR_SECE_Pos                      _U_(24)                                              /**< (SHA_IDR) Safety Event Interrupt Disable Position */
#define SHA_IDR_SECE_Msk                      (_U_(0x1) << SHA_IDR_SECE_Pos)                       /**< (SHA_IDR) Safety Event Interrupt Disable Mask */
#define SHA_IDR_SECE(value)                   (SHA_IDR_SECE_Msk & ((value) << SHA_IDR_SECE_Pos))  
#define SHA_IDR_Msk                           _U_(0x01010101)                                      /**< (SHA_IDR) Register Mask  */


/* -------- SHA_IMR : (SHA Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define SHA_IMR_DATRDY_Pos                    _U_(0)                                               /**< (SHA_IMR) Data Ready Interrupt Mask Position */
#define SHA_IMR_DATRDY_Msk                    (_U_(0x1) << SHA_IMR_DATRDY_Pos)                     /**< (SHA_IMR) Data Ready Interrupt Mask Mask */
#define SHA_IMR_DATRDY(value)                 (SHA_IMR_DATRDY_Msk & ((value) << SHA_IMR_DATRDY_Pos))
#define SHA_IMR_URAD_Pos                      _U_(8)                                               /**< (SHA_IMR) Unspecified Register Access Detection Interrupt Mask Position */
#define SHA_IMR_URAD_Msk                      (_U_(0x1) << SHA_IMR_URAD_Pos)                       /**< (SHA_IMR) Unspecified Register Access Detection Interrupt Mask Mask */
#define SHA_IMR_URAD(value)                   (SHA_IMR_URAD_Msk & ((value) << SHA_IMR_URAD_Pos))  
#define SHA_IMR_CHECKF_Pos                    _U_(16)                                              /**< (SHA_IMR) Check Done Interrupt Mask Position */
#define SHA_IMR_CHECKF_Msk                    (_U_(0x1) << SHA_IMR_CHECKF_Pos)                     /**< (SHA_IMR) Check Done Interrupt Mask Mask */
#define SHA_IMR_CHECKF(value)                 (SHA_IMR_CHECKF_Msk & ((value) << SHA_IMR_CHECKF_Pos))
#define SHA_IMR_SECE_Pos                      _U_(24)                                              /**< (SHA_IMR) Safety Event Interrupt Mask Position */
#define SHA_IMR_SECE_Msk                      (_U_(0x1) << SHA_IMR_SECE_Pos)                       /**< (SHA_IMR) Safety Event Interrupt Mask Mask */
#define SHA_IMR_SECE(value)                   (SHA_IMR_SECE_Msk & ((value) << SHA_IMR_SECE_Pos))  
#define SHA_IMR_Msk                           _U_(0x01010101)                                      /**< (SHA_IMR) Register Mask  */


/* -------- SHA_ISR : (SHA Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define SHA_ISR_DATRDY_Pos                    _U_(0)                                               /**< (SHA_ISR) Data Ready (cleared by writing a 1 to bit SWRST or START in SHA_CR, or by reading SHA_IODATARx) Position */
#define SHA_ISR_DATRDY_Msk                    (_U_(0x1) << SHA_ISR_DATRDY_Pos)                     /**< (SHA_ISR) Data Ready (cleared by writing a 1 to bit SWRST or START in SHA_CR, or by reading SHA_IODATARx) Mask */
#define SHA_ISR_DATRDY(value)                 (SHA_ISR_DATRDY_Msk & ((value) << SHA_ISR_DATRDY_Pos))
#define SHA_ISR_WRDY_Pos                      _U_(4)                                               /**< (SHA_ISR) Input Data Register Write Ready Position */
#define SHA_ISR_WRDY_Msk                      (_U_(0x1) << SHA_ISR_WRDY_Pos)                       /**< (SHA_ISR) Input Data Register Write Ready Mask */
#define SHA_ISR_WRDY(value)                   (SHA_ISR_WRDY_Msk & ((value) << SHA_ISR_WRDY_Pos))  
#define SHA_ISR_URAD_Pos                      _U_(8)                                               /**< (SHA_ISR) Unspecified Register Access Detection Status (cleared by writing a 1 to SWRST bit in SHA_CR) Position */
#define SHA_ISR_URAD_Msk                      (_U_(0x1) << SHA_ISR_URAD_Pos)                       /**< (SHA_ISR) Unspecified Register Access Detection Status (cleared by writing a 1 to SWRST bit in SHA_CR) Mask */
#define SHA_ISR_URAD(value)                   (SHA_ISR_URAD_Msk & ((value) << SHA_ISR_URAD_Pos))  
#define SHA_ISR_URAT_Pos                      _U_(12)                                              /**< (SHA_ISR) Unspecified Register Access Type (cleared by writing a 1 to SWRST bit in SHA_CR) Position */
#define SHA_ISR_URAT_Msk                      (_U_(0x7) << SHA_ISR_URAT_Pos)                       /**< (SHA_ISR) Unspecified Register Access Type (cleared by writing a 1 to SWRST bit in SHA_CR) Mask */
#define SHA_ISR_URAT(value)                   (SHA_ISR_URAT_Msk & ((value) << SHA_ISR_URAT_Pos))  
#define SHA_ISR_CHECKF_Pos                    _U_(16)                                              /**< (SHA_ISR) Check Done Status (cleared by writing START or SWRST bits in SHA_CR or by reading SHA_IODATARx) Position */
#define SHA_ISR_CHECKF_Msk                    (_U_(0x1) << SHA_ISR_CHECKF_Pos)                     /**< (SHA_ISR) Check Done Status (cleared by writing START or SWRST bits in SHA_CR or by reading SHA_IODATARx) Mask */
#define SHA_ISR_CHECKF(value)                 (SHA_ISR_CHECKF_Msk & ((value) << SHA_ISR_CHECKF_Pos))
#define SHA_ISR_CHKST_Pos                     _U_(20)                                              /**< (SHA_ISR) Check Status (cleared by writing START or SWRST bits in SHA_CR or by reading SHA_IODATARx) Position */
#define SHA_ISR_CHKST_Msk                     (_U_(0xF) << SHA_ISR_CHKST_Pos)                      /**< (SHA_ISR) Check Status (cleared by writing START or SWRST bits in SHA_CR or by reading SHA_IODATARx) Mask */
#define SHA_ISR_CHKST(value)                  (SHA_ISR_CHKST_Msk & ((value) << SHA_ISR_CHKST_Pos))
#define SHA_ISR_SECE_Pos                      _U_(24)                                              /**< (SHA_ISR) Security and/or Safety Event Position */
#define SHA_ISR_SECE_Msk                      (_U_(0x1) << SHA_ISR_SECE_Pos)                       /**< (SHA_ISR) Security and/or Safety Event Mask */
#define SHA_ISR_SECE(value)                   (SHA_ISR_SECE_Msk & ((value) << SHA_ISR_SECE_Pos))  
#define SHA_ISR_Msk                           _U_(0x01F17111)                                      /**< (SHA_ISR) Register Mask  */


/* -------- SHA_MSR : (SHA Offset: 0x20) (R/W 32) Message Size Register -------- */
#define SHA_MSR_MSGSIZE_Pos                   _U_(0)                                               /**< (SHA_MSR) Message Size Position */
#define SHA_MSR_MSGSIZE_Msk                   (_U_(0xFFFFFFFF) << SHA_MSR_MSGSIZE_Pos)             /**< (SHA_MSR) Message Size Mask */
#define SHA_MSR_MSGSIZE(value)                (SHA_MSR_MSGSIZE_Msk & ((value) << SHA_MSR_MSGSIZE_Pos))
#define SHA_MSR_Msk                           _U_(0xFFFFFFFF)                                      /**< (SHA_MSR) Register Mask  */


/* -------- SHA_BCR : (SHA Offset: 0x30) (R/W 32) Bytes Count Register -------- */
#define SHA_BCR_BYTCNT_Pos                    _U_(0)                                               /**< (SHA_BCR) Remaining Byte Count Before Auto Padding Position */
#define SHA_BCR_BYTCNT_Msk                    (_U_(0xFFFFFFFF) << SHA_BCR_BYTCNT_Pos)              /**< (SHA_BCR) Remaining Byte Count Before Auto Padding Mask */
#define SHA_BCR_BYTCNT(value)                 (SHA_BCR_BYTCNT_Msk & ((value) << SHA_BCR_BYTCNT_Pos))
#define SHA_BCR_Msk                           _U_(0xFFFFFFFF)                                      /**< (SHA_BCR) Register Mask  */


/* -------- SHA_IDATAR0 : (SHA Offset: 0x40) ( /W 32) Input Data 0 Register 0 -------- */
#define SHA_IDATAR0_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR0) Input Data Position */
#define SHA_IDATAR0_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR0_IDATA_Pos)           /**< (SHA_IDATAR0) Input Data Mask */
#define SHA_IDATAR0_IDATA(value)              (SHA_IDATAR0_IDATA_Msk & ((value) << SHA_IDATAR0_IDATA_Pos))
#define SHA_IDATAR0_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR0) Register Mask  */


/* -------- SHA_IDATAR1 : (SHA Offset: 0x44) ( /W 32) Input Data 0 Register 1 -------- */
#define SHA_IDATAR1_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR1) Input Data Position */
#define SHA_IDATAR1_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR1_IDATA_Pos)           /**< (SHA_IDATAR1) Input Data Mask */
#define SHA_IDATAR1_IDATA(value)              (SHA_IDATAR1_IDATA_Msk & ((value) << SHA_IDATAR1_IDATA_Pos))
#define SHA_IDATAR1_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR1) Register Mask  */


/* -------- SHA_IDATAR2 : (SHA Offset: 0x48) ( /W 32) Input Data 0 Register 2 -------- */
#define SHA_IDATAR2_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR2) Input Data Position */
#define SHA_IDATAR2_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR2_IDATA_Pos)           /**< (SHA_IDATAR2) Input Data Mask */
#define SHA_IDATAR2_IDATA(value)              (SHA_IDATAR2_IDATA_Msk & ((value) << SHA_IDATAR2_IDATA_Pos))
#define SHA_IDATAR2_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR2) Register Mask  */


/* -------- SHA_IDATAR3 : (SHA Offset: 0x4C) ( /W 32) Input Data 0 Register 3 -------- */
#define SHA_IDATAR3_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR3) Input Data Position */
#define SHA_IDATAR3_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR3_IDATA_Pos)           /**< (SHA_IDATAR3) Input Data Mask */
#define SHA_IDATAR3_IDATA(value)              (SHA_IDATAR3_IDATA_Msk & ((value) << SHA_IDATAR3_IDATA_Pos))
#define SHA_IDATAR3_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR3) Register Mask  */


/* -------- SHA_IDATAR4 : (SHA Offset: 0x50) ( /W 32) Input Data 0 Register 4 -------- */
#define SHA_IDATAR4_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR4) Input Data Position */
#define SHA_IDATAR4_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR4_IDATA_Pos)           /**< (SHA_IDATAR4) Input Data Mask */
#define SHA_IDATAR4_IDATA(value)              (SHA_IDATAR4_IDATA_Msk & ((value) << SHA_IDATAR4_IDATA_Pos))
#define SHA_IDATAR4_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR4) Register Mask  */


/* -------- SHA_IDATAR5 : (SHA Offset: 0x54) ( /W 32) Input Data 0 Register 5 -------- */
#define SHA_IDATAR5_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR5) Input Data Position */
#define SHA_IDATAR5_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR5_IDATA_Pos)           /**< (SHA_IDATAR5) Input Data Mask */
#define SHA_IDATAR5_IDATA(value)              (SHA_IDATAR5_IDATA_Msk & ((value) << SHA_IDATAR5_IDATA_Pos))
#define SHA_IDATAR5_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR5) Register Mask  */


/* -------- SHA_IDATAR6 : (SHA Offset: 0x58) ( /W 32) Input Data 0 Register 6 -------- */
#define SHA_IDATAR6_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR6) Input Data Position */
#define SHA_IDATAR6_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR6_IDATA_Pos)           /**< (SHA_IDATAR6) Input Data Mask */
#define SHA_IDATAR6_IDATA(value)              (SHA_IDATAR6_IDATA_Msk & ((value) << SHA_IDATAR6_IDATA_Pos))
#define SHA_IDATAR6_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR6) Register Mask  */


/* -------- SHA_IDATAR7 : (SHA Offset: 0x5C) ( /W 32) Input Data 0 Register 7 -------- */
#define SHA_IDATAR7_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR7) Input Data Position */
#define SHA_IDATAR7_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR7_IDATA_Pos)           /**< (SHA_IDATAR7) Input Data Mask */
#define SHA_IDATAR7_IDATA(value)              (SHA_IDATAR7_IDATA_Msk & ((value) << SHA_IDATAR7_IDATA_Pos))
#define SHA_IDATAR7_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR7) Register Mask  */


/* -------- SHA_IDATAR8 : (SHA Offset: 0x60) ( /W 32) Input Data 0 Register 8 -------- */
#define SHA_IDATAR8_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR8) Input Data Position */
#define SHA_IDATAR8_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR8_IDATA_Pos)           /**< (SHA_IDATAR8) Input Data Mask */
#define SHA_IDATAR8_IDATA(value)              (SHA_IDATAR8_IDATA_Msk & ((value) << SHA_IDATAR8_IDATA_Pos))
#define SHA_IDATAR8_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR8) Register Mask  */


/* -------- SHA_IDATAR9 : (SHA Offset: 0x64) ( /W 32) Input Data 0 Register 9 -------- */
#define SHA_IDATAR9_IDATA_Pos                 _U_(0)                                               /**< (SHA_IDATAR9) Input Data Position */
#define SHA_IDATAR9_IDATA_Msk                 (_U_(0xFFFFFFFF) << SHA_IDATAR9_IDATA_Pos)           /**< (SHA_IDATAR9) Input Data Mask */
#define SHA_IDATAR9_IDATA(value)              (SHA_IDATAR9_IDATA_Msk & ((value) << SHA_IDATAR9_IDATA_Pos))
#define SHA_IDATAR9_Msk                       _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR9) Register Mask  */


/* -------- SHA_IDATAR10 : (SHA Offset: 0x68) ( /W 32) Input Data 0 Register 10 -------- */
#define SHA_IDATAR10_IDATA_Pos                _U_(0)                                               /**< (SHA_IDATAR10) Input Data Position */
#define SHA_IDATAR10_IDATA_Msk                (_U_(0xFFFFFFFF) << SHA_IDATAR10_IDATA_Pos)          /**< (SHA_IDATAR10) Input Data Mask */
#define SHA_IDATAR10_IDATA(value)             (SHA_IDATAR10_IDATA_Msk & ((value) << SHA_IDATAR10_IDATA_Pos))
#define SHA_IDATAR10_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR10) Register Mask  */


/* -------- SHA_IDATAR11 : (SHA Offset: 0x6C) ( /W 32) Input Data 0 Register 11 -------- */
#define SHA_IDATAR11_IDATA_Pos                _U_(0)                                               /**< (SHA_IDATAR11) Input Data Position */
#define SHA_IDATAR11_IDATA_Msk                (_U_(0xFFFFFFFF) << SHA_IDATAR11_IDATA_Pos)          /**< (SHA_IDATAR11) Input Data Mask */
#define SHA_IDATAR11_IDATA(value)             (SHA_IDATAR11_IDATA_Msk & ((value) << SHA_IDATAR11_IDATA_Pos))
#define SHA_IDATAR11_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR11) Register Mask  */


/* -------- SHA_IDATAR12 : (SHA Offset: 0x70) ( /W 32) Input Data 0 Register 12 -------- */
#define SHA_IDATAR12_IDATA_Pos                _U_(0)                                               /**< (SHA_IDATAR12) Input Data Position */
#define SHA_IDATAR12_IDATA_Msk                (_U_(0xFFFFFFFF) << SHA_IDATAR12_IDATA_Pos)          /**< (SHA_IDATAR12) Input Data Mask */
#define SHA_IDATAR12_IDATA(value)             (SHA_IDATAR12_IDATA_Msk & ((value) << SHA_IDATAR12_IDATA_Pos))
#define SHA_IDATAR12_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR12) Register Mask  */


/* -------- SHA_IDATAR13 : (SHA Offset: 0x74) ( /W 32) Input Data 0 Register 13 -------- */
#define SHA_IDATAR13_IDATA_Pos                _U_(0)                                               /**< (SHA_IDATAR13) Input Data Position */
#define SHA_IDATAR13_IDATA_Msk                (_U_(0xFFFFFFFF) << SHA_IDATAR13_IDATA_Pos)          /**< (SHA_IDATAR13) Input Data Mask */
#define SHA_IDATAR13_IDATA(value)             (SHA_IDATAR13_IDATA_Msk & ((value) << SHA_IDATAR13_IDATA_Pos))
#define SHA_IDATAR13_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR13) Register Mask  */


/* -------- SHA_IDATAR14 : (SHA Offset: 0x78) ( /W 32) Input Data 0 Register 14 -------- */
#define SHA_IDATAR14_IDATA_Pos                _U_(0)                                               /**< (SHA_IDATAR14) Input Data Position */
#define SHA_IDATAR14_IDATA_Msk                (_U_(0xFFFFFFFF) << SHA_IDATAR14_IDATA_Pos)          /**< (SHA_IDATAR14) Input Data Mask */
#define SHA_IDATAR14_IDATA(value)             (SHA_IDATAR14_IDATA_Msk & ((value) << SHA_IDATAR14_IDATA_Pos))
#define SHA_IDATAR14_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR14) Register Mask  */


/* -------- SHA_IDATAR15 : (SHA Offset: 0x7C) ( /W 32) Input Data 0 Register 15 -------- */
#define SHA_IDATAR15_IDATA_Pos                _U_(0)                                               /**< (SHA_IDATAR15) Input Data Position */
#define SHA_IDATAR15_IDATA_Msk                (_U_(0xFFFFFFFF) << SHA_IDATAR15_IDATA_Pos)          /**< (SHA_IDATAR15) Input Data Mask */
#define SHA_IDATAR15_IDATA(value)             (SHA_IDATAR15_IDATA_Msk & ((value) << SHA_IDATAR15_IDATA_Pos))
#define SHA_IDATAR15_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IDATAR15) Register Mask  */


/* -------- SHA_IODATAR0 : (SHA Offset: 0x80) (R/W 32) Input/Output Data 0 Register 0 -------- */
#define SHA_IODATAR0_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR0) Input/Output Data Position */
#define SHA_IODATAR0_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR0_IODATA_Pos)         /**< (SHA_IODATAR0) Input/Output Data Mask */
#define SHA_IODATAR0_IODATA(value)            (SHA_IODATAR0_IODATA_Msk & ((value) << SHA_IODATAR0_IODATA_Pos))
#define SHA_IODATAR0_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR0) Register Mask  */


/* -------- SHA_IODATAR1 : (SHA Offset: 0x84) (R/W 32) Input/Output Data 0 Register 1 -------- */
#define SHA_IODATAR1_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR1) Input/Output Data Position */
#define SHA_IODATAR1_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR1_IODATA_Pos)         /**< (SHA_IODATAR1) Input/Output Data Mask */
#define SHA_IODATAR1_IODATA(value)            (SHA_IODATAR1_IODATA_Msk & ((value) << SHA_IODATAR1_IODATA_Pos))
#define SHA_IODATAR1_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR1) Register Mask  */


/* -------- SHA_IODATAR2 : (SHA Offset: 0x88) (R/W 32) Input/Output Data 0 Register 2 -------- */
#define SHA_IODATAR2_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR2) Input/Output Data Position */
#define SHA_IODATAR2_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR2_IODATA_Pos)         /**< (SHA_IODATAR2) Input/Output Data Mask */
#define SHA_IODATAR2_IODATA(value)            (SHA_IODATAR2_IODATA_Msk & ((value) << SHA_IODATAR2_IODATA_Pos))
#define SHA_IODATAR2_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR2) Register Mask  */


/* -------- SHA_IODATAR3 : (SHA Offset: 0x8C) (R/W 32) Input/Output Data 0 Register 3 -------- */
#define SHA_IODATAR3_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR3) Input/Output Data Position */
#define SHA_IODATAR3_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR3_IODATA_Pos)         /**< (SHA_IODATAR3) Input/Output Data Mask */
#define SHA_IODATAR3_IODATA(value)            (SHA_IODATAR3_IODATA_Msk & ((value) << SHA_IODATAR3_IODATA_Pos))
#define SHA_IODATAR3_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR3) Register Mask  */


/* -------- SHA_IODATAR4 : (SHA Offset: 0x90) (R/W 32) Input/Output Data 0 Register 4 -------- */
#define SHA_IODATAR4_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR4) Input/Output Data Position */
#define SHA_IODATAR4_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR4_IODATA_Pos)         /**< (SHA_IODATAR4) Input/Output Data Mask */
#define SHA_IODATAR4_IODATA(value)            (SHA_IODATAR4_IODATA_Msk & ((value) << SHA_IODATAR4_IODATA_Pos))
#define SHA_IODATAR4_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR4) Register Mask  */


/* -------- SHA_IODATAR5 : (SHA Offset: 0x94) (R/W 32) Input/Output Data 0 Register 5 -------- */
#define SHA_IODATAR5_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR5) Input/Output Data Position */
#define SHA_IODATAR5_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR5_IODATA_Pos)         /**< (SHA_IODATAR5) Input/Output Data Mask */
#define SHA_IODATAR5_IODATA(value)            (SHA_IODATAR5_IODATA_Msk & ((value) << SHA_IODATAR5_IODATA_Pos))
#define SHA_IODATAR5_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR5) Register Mask  */


/* -------- SHA_IODATAR6 : (SHA Offset: 0x98) (R/W 32) Input/Output Data 0 Register 6 -------- */
#define SHA_IODATAR6_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR6) Input/Output Data Position */
#define SHA_IODATAR6_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR6_IODATA_Pos)         /**< (SHA_IODATAR6) Input/Output Data Mask */
#define SHA_IODATAR6_IODATA(value)            (SHA_IODATAR6_IODATA_Msk & ((value) << SHA_IODATAR6_IODATA_Pos))
#define SHA_IODATAR6_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR6) Register Mask  */


/* -------- SHA_IODATAR7 : (SHA Offset: 0x9C) (R/W 32) Input/Output Data 0 Register 7 -------- */
#define SHA_IODATAR7_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR7) Input/Output Data Position */
#define SHA_IODATAR7_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR7_IODATA_Pos)         /**< (SHA_IODATAR7) Input/Output Data Mask */
#define SHA_IODATAR7_IODATA(value)            (SHA_IODATAR7_IODATA_Msk & ((value) << SHA_IODATAR7_IODATA_Pos))
#define SHA_IODATAR7_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR7) Register Mask  */


/* -------- SHA_IODATAR8 : (SHA Offset: 0xA0) (R/W 32) Input/Output Data 0 Register 8 -------- */
#define SHA_IODATAR8_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR8) Input/Output Data Position */
#define SHA_IODATAR8_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR8_IODATA_Pos)         /**< (SHA_IODATAR8) Input/Output Data Mask */
#define SHA_IODATAR8_IODATA(value)            (SHA_IODATAR8_IODATA_Msk & ((value) << SHA_IODATAR8_IODATA_Pos))
#define SHA_IODATAR8_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR8) Register Mask  */


/* -------- SHA_IODATAR9 : (SHA Offset: 0xA4) (R/W 32) Input/Output Data 0 Register 9 -------- */
#define SHA_IODATAR9_IODATA_Pos               _U_(0)                                               /**< (SHA_IODATAR9) Input/Output Data Position */
#define SHA_IODATAR9_IODATA_Msk               (_U_(0xFFFFFFFF) << SHA_IODATAR9_IODATA_Pos)         /**< (SHA_IODATAR9) Input/Output Data Mask */
#define SHA_IODATAR9_IODATA(value)            (SHA_IODATAR9_IODATA_Msk & ((value) << SHA_IODATAR9_IODATA_Pos))
#define SHA_IODATAR9_Msk                      _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR9) Register Mask  */


/* -------- SHA_IODATAR10 : (SHA Offset: 0xA8) (R/W 32) Input/Output Data 0 Register 10 -------- */
#define SHA_IODATAR10_IODATA_Pos              _U_(0)                                               /**< (SHA_IODATAR10) Input/Output Data Position */
#define SHA_IODATAR10_IODATA_Msk              (_U_(0xFFFFFFFF) << SHA_IODATAR10_IODATA_Pos)        /**< (SHA_IODATAR10) Input/Output Data Mask */
#define SHA_IODATAR10_IODATA(value)           (SHA_IODATAR10_IODATA_Msk & ((value) << SHA_IODATAR10_IODATA_Pos))
#define SHA_IODATAR10_Msk                     _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR10) Register Mask  */


/* -------- SHA_IODATAR11 : (SHA Offset: 0xAC) (R/W 32) Input/Output Data 0 Register 11 -------- */
#define SHA_IODATAR11_IODATA_Pos              _U_(0)                                               /**< (SHA_IODATAR11) Input/Output Data Position */
#define SHA_IODATAR11_IODATA_Msk              (_U_(0xFFFFFFFF) << SHA_IODATAR11_IODATA_Pos)        /**< (SHA_IODATAR11) Input/Output Data Mask */
#define SHA_IODATAR11_IODATA(value)           (SHA_IODATAR11_IODATA_Msk & ((value) << SHA_IODATAR11_IODATA_Pos))
#define SHA_IODATAR11_Msk                     _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR11) Register Mask  */


/* -------- SHA_IODATAR12 : (SHA Offset: 0xB0) (R/W 32) Input/Output Data 0 Register 12 -------- */
#define SHA_IODATAR12_IODATA_Pos              _U_(0)                                               /**< (SHA_IODATAR12) Input/Output Data Position */
#define SHA_IODATAR12_IODATA_Msk              (_U_(0xFFFFFFFF) << SHA_IODATAR12_IODATA_Pos)        /**< (SHA_IODATAR12) Input/Output Data Mask */
#define SHA_IODATAR12_IODATA(value)           (SHA_IODATAR12_IODATA_Msk & ((value) << SHA_IODATAR12_IODATA_Pos))
#define SHA_IODATAR12_Msk                     _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR12) Register Mask  */


/* -------- SHA_IODATAR13 : (SHA Offset: 0xB4) (R/W 32) Input/Output Data 0 Register 13 -------- */
#define SHA_IODATAR13_IODATA_Pos              _U_(0)                                               /**< (SHA_IODATAR13) Input/Output Data Position */
#define SHA_IODATAR13_IODATA_Msk              (_U_(0xFFFFFFFF) << SHA_IODATAR13_IODATA_Pos)        /**< (SHA_IODATAR13) Input/Output Data Mask */
#define SHA_IODATAR13_IODATA(value)           (SHA_IODATAR13_IODATA_Msk & ((value) << SHA_IODATAR13_IODATA_Pos))
#define SHA_IODATAR13_Msk                     _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR13) Register Mask  */


/* -------- SHA_IODATAR14 : (SHA Offset: 0xB8) (R/W 32) Input/Output Data 0 Register 14 -------- */
#define SHA_IODATAR14_IODATA_Pos              _U_(0)                                               /**< (SHA_IODATAR14) Input/Output Data Position */
#define SHA_IODATAR14_IODATA_Msk              (_U_(0xFFFFFFFF) << SHA_IODATAR14_IODATA_Pos)        /**< (SHA_IODATAR14) Input/Output Data Mask */
#define SHA_IODATAR14_IODATA(value)           (SHA_IODATAR14_IODATA_Msk & ((value) << SHA_IODATAR14_IODATA_Pos))
#define SHA_IODATAR14_Msk                     _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR14) Register Mask  */


/* -------- SHA_IODATAR15 : (SHA Offset: 0xBC) (R/W 32) Input/Output Data 0 Register 15 -------- */
#define SHA_IODATAR15_IODATA_Pos              _U_(0)                                               /**< (SHA_IODATAR15) Input/Output Data Position */
#define SHA_IODATAR15_IODATA_Msk              (_U_(0xFFFFFFFF) << SHA_IODATAR15_IODATA_Pos)        /**< (SHA_IODATAR15) Input/Output Data Mask */
#define SHA_IODATAR15_IODATA(value)           (SHA_IODATAR15_IODATA_Msk & ((value) << SHA_IODATAR15_IODATA_Pos))
#define SHA_IODATAR15_Msk                     _U_(0xFFFFFFFF)                                      /**< (SHA_IODATAR15) Register Mask  */


/* -------- SHA_WPMR : (SHA Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define SHA_WPMR_WPEN_Pos                     _U_(0)                                               /**< (SHA_WPMR) Write Protection Configuration Enable Position */
#define SHA_WPMR_WPEN_Msk                     (_U_(0x1) << SHA_WPMR_WPEN_Pos)                      /**< (SHA_WPMR) Write Protection Configuration Enable Mask */
#define SHA_WPMR_WPEN(value)                  (SHA_WPMR_WPEN_Msk & ((value) << SHA_WPMR_WPEN_Pos))
#define SHA_WPMR_WPITEN_Pos                   _U_(1)                                               /**< (SHA_WPMR) Write Protection Interruption Enable Position */
#define SHA_WPMR_WPITEN_Msk                   (_U_(0x1) << SHA_WPMR_WPITEN_Pos)                    /**< (SHA_WPMR) Write Protection Interruption Enable Mask */
#define SHA_WPMR_WPITEN(value)                (SHA_WPMR_WPITEN_Msk & ((value) << SHA_WPMR_WPITEN_Pos))
#define SHA_WPMR_WPCREN_Pos                   _U_(2)                                               /**< (SHA_WPMR) Write Protection Control Enable Position */
#define SHA_WPMR_WPCREN_Msk                   (_U_(0x1) << SHA_WPMR_WPCREN_Pos)                    /**< (SHA_WPMR) Write Protection Control Enable Mask */
#define SHA_WPMR_WPCREN(value)                (SHA_WPMR_WPCREN_Msk & ((value) << SHA_WPMR_WPCREN_Pos))
#define SHA_WPMR_WPKEY_Pos                    _U_(8)                                               /**< (SHA_WPMR) Write Protection Key Position */
#define SHA_WPMR_WPKEY_Msk                    (_U_(0xFFFFFF) << SHA_WPMR_WPKEY_Pos)                /**< (SHA_WPMR) Write Protection Key Mask */
#define SHA_WPMR_WPKEY(value)                 (SHA_WPMR_WPKEY_Msk & ((value) << SHA_WPMR_WPKEY_Pos))
#define   SHA_WPMR_WPKEY_PASSWD_Val           _U_(0x534841)                                        /**< (SHA_WPMR) Writing any other value in this field aborts the write operation of the WPEN,WPITEN,WPCREN bits.Always reads as 0.  */
#define SHA_WPMR_WPKEY_PASSWD                 (SHA_WPMR_WPKEY_PASSWD_Val << SHA_WPMR_WPKEY_Pos)    /**< (SHA_WPMR) Writing any other value in this field aborts the write operation of the WPEN,WPITEN,WPCREN bits.Always reads as 0. Position  */
#define SHA_WPMR_Msk                          _U_(0xFFFFFF07)                                      /**< (SHA_WPMR) Register Mask  */


/* -------- SHA_WPSR : (SHA Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define SHA_WPSR_WPVS_Pos                     _U_(0)                                               /**< (SHA_WPSR) Write Protection Violation Status (cleared on read) Position */
#define SHA_WPSR_WPVS_Msk                     (_U_(0x1) << SHA_WPSR_WPVS_Pos)                      /**< (SHA_WPSR) Write Protection Violation Status (cleared on read) Mask */
#define SHA_WPSR_WPVS(value)                  (SHA_WPSR_WPVS_Msk & ((value) << SHA_WPSR_WPVS_Pos))
#define SHA_WPSR_WPVSRC_Pos                   _U_(8)                                               /**< (SHA_WPSR) Write Protection Violation Source Position */
#define SHA_WPSR_WPVSRC_Msk                   (_U_(0xFF) << SHA_WPSR_WPVSRC_Pos)                   /**< (SHA_WPSR) Write Protection Violation Source Mask */
#define SHA_WPSR_WPVSRC(value)                (SHA_WPSR_WPVSRC_Msk & ((value) << SHA_WPSR_WPVSRC_Pos))
#define SHA_WPSR_Msk                          _U_(0x0000FF01)                                      /**< (SHA_WPSR) Register Mask  */


/** \brief SHA register offsets definitions */
#define SHA_CR_REG_OFST                (0x00)              /**< (SHA_CR) Control Register Offset */
#define SHA_MR_REG_OFST                (0x04)              /**< (SHA_MR) Mode Register Offset */
#define SHA_IER_REG_OFST               (0x10)              /**< (SHA_IER) Interrupt Enable Register Offset */
#define SHA_IDR_REG_OFST               (0x14)              /**< (SHA_IDR) Interrupt Disable Register Offset */
#define SHA_IMR_REG_OFST               (0x18)              /**< (SHA_IMR) Interrupt Mask Register Offset */
#define SHA_ISR_REG_OFST               (0x1C)              /**< (SHA_ISR) Interrupt Status Register Offset */
#define SHA_MSR_REG_OFST               (0x20)              /**< (SHA_MSR) Message Size Register Offset */
#define SHA_BCR_REG_OFST               (0x30)              /**< (SHA_BCR) Bytes Count Register Offset */
#define SHA_IDATAR0_REG_OFST           (0x40)              /**< (SHA_IDATAR0) Input Data 0 Register 0 Offset */
#define SHA_IDATAR1_REG_OFST           (0x44)              /**< (SHA_IDATAR1) Input Data 0 Register 1 Offset */
#define SHA_IDATAR2_REG_OFST           (0x48)              /**< (SHA_IDATAR2) Input Data 0 Register 2 Offset */
#define SHA_IDATAR3_REG_OFST           (0x4C)              /**< (SHA_IDATAR3) Input Data 0 Register 3 Offset */
#define SHA_IDATAR4_REG_OFST           (0x50)              /**< (SHA_IDATAR4) Input Data 0 Register 4 Offset */
#define SHA_IDATAR5_REG_OFST           (0x54)              /**< (SHA_IDATAR5) Input Data 0 Register 5 Offset */
#define SHA_IDATAR6_REG_OFST           (0x58)              /**< (SHA_IDATAR6) Input Data 0 Register 6 Offset */
#define SHA_IDATAR7_REG_OFST           (0x5C)              /**< (SHA_IDATAR7) Input Data 0 Register 7 Offset */
#define SHA_IDATAR8_REG_OFST           (0x60)              /**< (SHA_IDATAR8) Input Data 0 Register 8 Offset */
#define SHA_IDATAR9_REG_OFST           (0x64)              /**< (SHA_IDATAR9) Input Data 0 Register 9 Offset */
#define SHA_IDATAR10_REG_OFST          (0x68)              /**< (SHA_IDATAR10) Input Data 0 Register 10 Offset */
#define SHA_IDATAR11_REG_OFST          (0x6C)              /**< (SHA_IDATAR11) Input Data 0 Register 11 Offset */
#define SHA_IDATAR12_REG_OFST          (0x70)              /**< (SHA_IDATAR12) Input Data 0 Register 12 Offset */
#define SHA_IDATAR13_REG_OFST          (0x74)              /**< (SHA_IDATAR13) Input Data 0 Register 13 Offset */
#define SHA_IDATAR14_REG_OFST          (0x78)              /**< (SHA_IDATAR14) Input Data 0 Register 14 Offset */
#define SHA_IDATAR15_REG_OFST          (0x7C)              /**< (SHA_IDATAR15) Input Data 0 Register 15 Offset */
#define SHA_IODATAR0_REG_OFST          (0x80)              /**< (SHA_IODATAR0) Input/Output Data 0 Register 0 Offset */
#define SHA_IODATAR1_REG_OFST          (0x84)              /**< (SHA_IODATAR1) Input/Output Data 0 Register 1 Offset */
#define SHA_IODATAR2_REG_OFST          (0x88)              /**< (SHA_IODATAR2) Input/Output Data 0 Register 2 Offset */
#define SHA_IODATAR3_REG_OFST          (0x8C)              /**< (SHA_IODATAR3) Input/Output Data 0 Register 3 Offset */
#define SHA_IODATAR4_REG_OFST          (0x90)              /**< (SHA_IODATAR4) Input/Output Data 0 Register 4 Offset */
#define SHA_IODATAR5_REG_OFST          (0x94)              /**< (SHA_IODATAR5) Input/Output Data 0 Register 5 Offset */
#define SHA_IODATAR6_REG_OFST          (0x98)              /**< (SHA_IODATAR6) Input/Output Data 0 Register 6 Offset */
#define SHA_IODATAR7_REG_OFST          (0x9C)              /**< (SHA_IODATAR7) Input/Output Data 0 Register 7 Offset */
#define SHA_IODATAR8_REG_OFST          (0xA0)              /**< (SHA_IODATAR8) Input/Output Data 0 Register 8 Offset */
#define SHA_IODATAR9_REG_OFST          (0xA4)              /**< (SHA_IODATAR9) Input/Output Data 0 Register 9 Offset */
#define SHA_IODATAR10_REG_OFST         (0xA8)              /**< (SHA_IODATAR10) Input/Output Data 0 Register 10 Offset */
#define SHA_IODATAR11_REG_OFST         (0xAC)              /**< (SHA_IODATAR11) Input/Output Data 0 Register 11 Offset */
#define SHA_IODATAR12_REG_OFST         (0xB0)              /**< (SHA_IODATAR12) Input/Output Data 0 Register 12 Offset */
#define SHA_IODATAR13_REG_OFST         (0xB4)              /**< (SHA_IODATAR13) Input/Output Data 0 Register 13 Offset */
#define SHA_IODATAR14_REG_OFST         (0xB8)              /**< (SHA_IODATAR14) Input/Output Data 0 Register 14 Offset */
#define SHA_IODATAR15_REG_OFST         (0xBC)              /**< (SHA_IODATAR15) Input/Output Data 0 Register 15 Offset */
#define SHA_WPMR_REG_OFST              (0xE4)              /**< (SHA_WPMR) Write Protection Mode Register Offset */
#define SHA_WPSR_REG_OFST              (0xE8)              /**< (SHA_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SHA register API structure */
typedef struct
{
  __O   uint32_t                       SHA_CR;             /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       SHA_MR;             /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint8_t                        Reserved1[0x08];
  __O   uint32_t                       SHA_IER;            /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       SHA_IDR;            /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       SHA_IMR;            /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       SHA_ISR;            /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __IO  uint32_t                       SHA_MSR;            /**< Offset: 0x20 (R/W  32) Message Size Register */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       SHA_BCR;            /**< Offset: 0x30 (R/W  32) Bytes Count Register */
  __I   uint8_t                        Reserved3[0x0C];
  __O   uint32_t                       SHA_IDATAR0;        /**< Offset: 0x40 ( /W  32) Input Data 0 Register 0 */
  __O   uint32_t                       SHA_IDATAR1;        /**< Offset: 0x44 ( /W  32) Input Data 0 Register 1 */
  __O   uint32_t                       SHA_IDATAR2;        /**< Offset: 0x48 ( /W  32) Input Data 0 Register 2 */
  __O   uint32_t                       SHA_IDATAR3;        /**< Offset: 0x4C ( /W  32) Input Data 0 Register 3 */
  __O   uint32_t                       SHA_IDATAR4;        /**< Offset: 0x50 ( /W  32) Input Data 0 Register 4 */
  __O   uint32_t                       SHA_IDATAR5;        /**< Offset: 0x54 ( /W  32) Input Data 0 Register 5 */
  __O   uint32_t                       SHA_IDATAR6;        /**< Offset: 0x58 ( /W  32) Input Data 0 Register 6 */
  __O   uint32_t                       SHA_IDATAR7;        /**< Offset: 0x5C ( /W  32) Input Data 0 Register 7 */
  __O   uint32_t                       SHA_IDATAR8;        /**< Offset: 0x60 ( /W  32) Input Data 0 Register 8 */
  __O   uint32_t                       SHA_IDATAR9;        /**< Offset: 0x64 ( /W  32) Input Data 0 Register 9 */
  __O   uint32_t                       SHA_IDATAR10;       /**< Offset: 0x68 ( /W  32) Input Data 0 Register 10 */
  __O   uint32_t                       SHA_IDATAR11;       /**< Offset: 0x6C ( /W  32) Input Data 0 Register 11 */
  __O   uint32_t                       SHA_IDATAR12;       /**< Offset: 0x70 ( /W  32) Input Data 0 Register 12 */
  __O   uint32_t                       SHA_IDATAR13;       /**< Offset: 0x74 ( /W  32) Input Data 0 Register 13 */
  __O   uint32_t                       SHA_IDATAR14;       /**< Offset: 0x78 ( /W  32) Input Data 0 Register 14 */
  __O   uint32_t                       SHA_IDATAR15;       /**< Offset: 0x7C ( /W  32) Input Data 0 Register 15 */
  __IO  uint32_t                       SHA_IODATAR0;       /**< Offset: 0x80 (R/W  32) Input/Output Data 0 Register 0 */
  __IO  uint32_t                       SHA_IODATAR1;       /**< Offset: 0x84 (R/W  32) Input/Output Data 0 Register 1 */
  __IO  uint32_t                       SHA_IODATAR2;       /**< Offset: 0x88 (R/W  32) Input/Output Data 0 Register 2 */
  __IO  uint32_t                       SHA_IODATAR3;       /**< Offset: 0x8C (R/W  32) Input/Output Data 0 Register 3 */
  __IO  uint32_t                       SHA_IODATAR4;       /**< Offset: 0x90 (R/W  32) Input/Output Data 0 Register 4 */
  __IO  uint32_t                       SHA_IODATAR5;       /**< Offset: 0x94 (R/W  32) Input/Output Data 0 Register 5 */
  __IO  uint32_t                       SHA_IODATAR6;       /**< Offset: 0x98 (R/W  32) Input/Output Data 0 Register 6 */
  __IO  uint32_t                       SHA_IODATAR7;       /**< Offset: 0x9C (R/W  32) Input/Output Data 0 Register 7 */
  __IO  uint32_t                       SHA_IODATAR8;       /**< Offset: 0xA0 (R/W  32) Input/Output Data 0 Register 8 */
  __IO  uint32_t                       SHA_IODATAR9;       /**< Offset: 0xA4 (R/W  32) Input/Output Data 0 Register 9 */
  __IO  uint32_t                       SHA_IODATAR10;      /**< Offset: 0xA8 (R/W  32) Input/Output Data 0 Register 10 */
  __IO  uint32_t                       SHA_IODATAR11;      /**< Offset: 0xAC (R/W  32) Input/Output Data 0 Register 11 */
  __IO  uint32_t                       SHA_IODATAR12;      /**< Offset: 0xB0 (R/W  32) Input/Output Data 0 Register 12 */
  __IO  uint32_t                       SHA_IODATAR13;      /**< Offset: 0xB4 (R/W  32) Input/Output Data 0 Register 13 */
  __IO  uint32_t                       SHA_IODATAR14;      /**< Offset: 0xB8 (R/W  32) Input/Output Data 0 Register 14 */
  __IO  uint32_t                       SHA_IODATAR15;      /**< Offset: 0xBC (R/W  32) Input/Output Data 0 Register 15 */
  __I   uint8_t                        Reserved4[0x24];
  __IO  uint32_t                       SHA_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       SHA_WPSR;           /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} sha_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_SHA_COMPONENT_H_ */
