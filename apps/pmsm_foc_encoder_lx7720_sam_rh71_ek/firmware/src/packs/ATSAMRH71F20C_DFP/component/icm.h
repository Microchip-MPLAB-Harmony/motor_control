/**
 * \brief Component description for ICM
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
#ifndef _SAMRH71_ICM_COMPONENT_H_
#define _SAMRH71_ICM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ICM                                          */
/* ************************************************************************** */

/* -------- ICM_RADDR : (ICM Offset: 0x00) (R/W 32) Region Start Address -------- */
#define ICM_RADDR_RADDR_Pos                   _U_(0)                                               /**< (ICM_RADDR) Region Start Address Position */
#define ICM_RADDR_RADDR_Msk                   (_U_(0xFFFFFFFF) << ICM_RADDR_RADDR_Pos)             /**< (ICM_RADDR) Region Start Address Mask */
#define ICM_RADDR_RADDR(value)                (ICM_RADDR_RADDR_Msk & ((value) << ICM_RADDR_RADDR_Pos))
#define ICM_RADDR_Msk                         _U_(0xFFFFFFFF)                                      /**< (ICM_RADDR) Register Mask  */


/* -------- ICM_RCFG : (ICM Offset: 0x04) (R/W 32) Region Configuration -------- */
#define ICM_RCFG_RESETVALUE                   _U_(0x00)                                            /**<  (ICM_RCFG) Region Configuration  Reset Value */

#define ICM_RCFG_CDWBN_Pos                    _U_(0)                                               /**< (ICM_RCFG) Compare Digest Write Back Position */
#define ICM_RCFG_CDWBN_Msk                    (_U_(0x1) << ICM_RCFG_CDWBN_Pos)                     /**< (ICM_RCFG) Compare Digest Write Back Mask */
#define ICM_RCFG_CDWBN(value)                 (ICM_RCFG_CDWBN_Msk & ((value) << ICM_RCFG_CDWBN_Pos))
#define   ICM_RCFG_CDWBN_WRBA_Val             _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_CDWBN_COMP_Val             _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_CDWBN_WRBA                   (ICM_RCFG_CDWBN_WRBA_Val << ICM_RCFG_CDWBN_Pos)      /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_CDWBN_COMP                   (ICM_RCFG_CDWBN_COMP_Val << ICM_RCFG_CDWBN_Pos)      /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_WRAP_Pos                     _U_(1)                                               /**< (ICM_RCFG) Region Wrap Position */
#define ICM_RCFG_WRAP_Msk                     (_U_(0x1) << ICM_RCFG_WRAP_Pos)                      /**< (ICM_RCFG) Region Wrap Mask */
#define ICM_RCFG_WRAP(value)                  (ICM_RCFG_WRAP_Msk & ((value) << ICM_RCFG_WRAP_Pos))
#define   ICM_RCFG_WRAP_NO_Val                _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_WRAP_YES_Val               _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_WRAP_NO                      (ICM_RCFG_WRAP_NO_Val << ICM_RCFG_WRAP_Pos)          /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_WRAP_YES                     (ICM_RCFG_WRAP_YES_Val << ICM_RCFG_WRAP_Pos)         /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_EOM_Pos                      _U_(2)                                               /**< (ICM_RCFG) End of Monitoring Position */
#define ICM_RCFG_EOM_Msk                      (_U_(0x1) << ICM_RCFG_EOM_Pos)                       /**< (ICM_RCFG) End of Monitoring Mask */
#define ICM_RCFG_EOM(value)                   (ICM_RCFG_EOM_Msk & ((value) << ICM_RCFG_EOM_Pos))  
#define   ICM_RCFG_EOM_NO_Val                 _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_EOM_YES_Val                _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_EOM_NO                       (ICM_RCFG_EOM_NO_Val << ICM_RCFG_EOM_Pos)            /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_EOM_YES                      (ICM_RCFG_EOM_YES_Val << ICM_RCFG_EOM_Pos)           /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_RHIEN_Pos                    _U_(4)                                               /**< (ICM_RCFG) Region Hash Interrupt Enable Position */
#define ICM_RCFG_RHIEN_Msk                    (_U_(0x1) << ICM_RCFG_RHIEN_Pos)                     /**< (ICM_RCFG) Region Hash Interrupt Enable Mask */
#define ICM_RCFG_RHIEN(value)                 (ICM_RCFG_RHIEN_Msk & ((value) << ICM_RCFG_RHIEN_Pos))
#define   ICM_RCFG_RHIEN_EN_Val               _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_RHIEN_DIS_Val              _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_RHIEN_EN                     (ICM_RCFG_RHIEN_EN_Val << ICM_RCFG_RHIEN_Pos)        /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_RHIEN_DIS                    (ICM_RCFG_RHIEN_DIS_Val << ICM_RCFG_RHIEN_Pos)       /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_DMIEN_Pos                    _U_(5)                                               /**< (ICM_RCFG) Region Digest Mismatch Interrupt Enable Position */
#define ICM_RCFG_DMIEN_Msk                    (_U_(0x1) << ICM_RCFG_DMIEN_Pos)                     /**< (ICM_RCFG) Region Digest Mismatch Interrupt Enable Mask */
#define ICM_RCFG_DMIEN(value)                 (ICM_RCFG_DMIEN_Msk & ((value) << ICM_RCFG_DMIEN_Pos))
#define   ICM_RCFG_DMIEN_EN_Val               _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_DMIEN_DIS_Val              _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_DMIEN_EN                     (ICM_RCFG_DMIEN_EN_Val << ICM_RCFG_DMIEN_Pos)        /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_DMIEN_DIS                    (ICM_RCFG_DMIEN_DIS_Val << ICM_RCFG_DMIEN_Pos)       /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_BEIEN_Pos                    _U_(6)                                               /**< (ICM_RCFG) Region Bus Error Interrupt Enable Position */
#define ICM_RCFG_BEIEN_Msk                    (_U_(0x1) << ICM_RCFG_BEIEN_Pos)                     /**< (ICM_RCFG) Region Bus Error Interrupt Enable Mask */
#define ICM_RCFG_BEIEN(value)                 (ICM_RCFG_BEIEN_Msk & ((value) << ICM_RCFG_BEIEN_Pos))
#define   ICM_RCFG_BEIEN_EN_Val               _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_BEIEN_DIS_Val              _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_BEIEN_EN                     (ICM_RCFG_BEIEN_EN_Val << ICM_RCFG_BEIEN_Pos)        /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_BEIEN_DIS                    (ICM_RCFG_BEIEN_DIS_Val << ICM_RCFG_BEIEN_Pos)       /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_WCIEN_Pos                    _U_(7)                                               /**< (ICM_RCFG) Region Wrap Condition Detected Interrupt Enable Position */
#define ICM_RCFG_WCIEN_Msk                    (_U_(0x1) << ICM_RCFG_WCIEN_Pos)                     /**< (ICM_RCFG) Region Wrap Condition Detected Interrupt Enable Mask */
#define ICM_RCFG_WCIEN(value)                 (ICM_RCFG_WCIEN_Msk & ((value) << ICM_RCFG_WCIEN_Pos))
#define   ICM_RCFG_WCIEN_EN_Val               _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_WCIEN_DIS_Val              _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_WCIEN_EN                     (ICM_RCFG_WCIEN_EN_Val << ICM_RCFG_WCIEN_Pos)        /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_WCIEN_DIS                    (ICM_RCFG_WCIEN_DIS_Val << ICM_RCFG_WCIEN_Pos)       /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_ECIEN_Pos                    _U_(8)                                               /**< (ICM_RCFG) Region End bit Condition detected Interrupt Enable Position */
#define ICM_RCFG_ECIEN_Msk                    (_U_(0x1) << ICM_RCFG_ECIEN_Pos)                     /**< (ICM_RCFG) Region End bit Condition detected Interrupt Enable Mask */
#define ICM_RCFG_ECIEN(value)                 (ICM_RCFG_ECIEN_Msk & ((value) << ICM_RCFG_ECIEN_Pos))
#define   ICM_RCFG_ECIEN_EN_Val               _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_ECIEN_DIS_Val              _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_ECIEN_EN                     (ICM_RCFG_ECIEN_EN_Val << ICM_RCFG_ECIEN_Pos)        /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_ECIEN_DIS                    (ICM_RCFG_ECIEN_DIS_Val << ICM_RCFG_ECIEN_Pos)       /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_SUIEN_Pos                    _U_(9)                                               /**< (ICM_RCFG) Region Status Updated Interrupt Enable Position */
#define ICM_RCFG_SUIEN_Msk                    (_U_(0x1) << ICM_RCFG_SUIEN_Pos)                     /**< (ICM_RCFG) Region Status Updated Interrupt Enable Mask */
#define ICM_RCFG_SUIEN(value)                 (ICM_RCFG_SUIEN_Msk & ((value) << ICM_RCFG_SUIEN_Pos))
#define   ICM_RCFG_SUIEN_EN_Val               _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_SUIEN_DIS_Val              _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_SUIEN_EN                     (ICM_RCFG_SUIEN_EN_Val << ICM_RCFG_SUIEN_Pos)        /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_SUIEN_DIS                    (ICM_RCFG_SUIEN_DIS_Val << ICM_RCFG_SUIEN_Pos)       /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_PROCDLY_Pos                  _U_(10)                                              /**< (ICM_RCFG) SHA Processing Delay Position */
#define ICM_RCFG_PROCDLY_Msk                  (_U_(0x1) << ICM_RCFG_PROCDLY_Pos)                   /**< (ICM_RCFG) SHA Processing Delay Mask */
#define ICM_RCFG_PROCDLY(value)               (ICM_RCFG_PROCDLY_Msk & ((value) << ICM_RCFG_PROCDLY_Pos))
#define   ICM_RCFG_PROCDLY_SHORT_Val          _U_(0x0)                                             /**< (ICM_RCFG)   */
#define   ICM_RCFG_PROCDLY_LONG_Val           _U_(0x1)                                             /**< (ICM_RCFG)   */
#define ICM_RCFG_PROCDLY_SHORT                (ICM_RCFG_PROCDLY_SHORT_Val << ICM_RCFG_PROCDLY_Pos) /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_PROCDLY_LONG                 (ICM_RCFG_PROCDLY_LONG_Val << ICM_RCFG_PROCDLY_Pos)  /**< (ICM_RCFG)  Position  */
#define ICM_RCFG_ALGO_Pos                     _U_(12)                                              /**< (ICM_RCFG) SHA Algorithm Position */
#define ICM_RCFG_ALGO_Msk                     (_U_(0x7) << ICM_RCFG_ALGO_Pos)                      /**< (ICM_RCFG) SHA Algorithm Mask */
#define ICM_RCFG_ALGO(value)                  (ICM_RCFG_ALGO_Msk & ((value) << ICM_RCFG_ALGO_Pos))
#define   ICM_RCFG_ALGO_SHA1_Val              _U_(0x0)                                             /**< (ICM_RCFG) SHA1 algorithm processed  */
#define   ICM_RCFG_ALGO_SHA256_Val            _U_(0x1)                                             /**< (ICM_RCFG) SHA256 algorithm processed  */
#define   ICM_RCFG_ALGO_SHA224_Val            _U_(0x4)                                             /**< (ICM_RCFG) SHA224 algorithm processed  */
#define ICM_RCFG_ALGO_SHA1                    (ICM_RCFG_ALGO_SHA1_Val << ICM_RCFG_ALGO_Pos)        /**< (ICM_RCFG) SHA1 algorithm processed Position  */
#define ICM_RCFG_ALGO_SHA256                  (ICM_RCFG_ALGO_SHA256_Val << ICM_RCFG_ALGO_Pos)      /**< (ICM_RCFG) SHA256 algorithm processed Position  */
#define ICM_RCFG_ALGO_SHA224                  (ICM_RCFG_ALGO_SHA224_Val << ICM_RCFG_ALGO_Pos)      /**< (ICM_RCFG) SHA224 algorithm processed Position  */
#define ICM_RCFG_Msk                          _U_(0x000077F7)                                      /**< (ICM_RCFG) Register Mask  */


/* -------- ICM_RCTRL : (ICM Offset: 0x08) (R/W 32) Region Control -------- */
#define ICM_RCTRL_TRSIZE_Pos                  _U_(0)                                               /**< (ICM_RCTRL) Transfer Size for the Current Chunk of Data Position */
#define ICM_RCTRL_TRSIZE_Msk                  (_U_(0xFFFF) << ICM_RCTRL_TRSIZE_Pos)                /**< (ICM_RCTRL) Transfer Size for the Current Chunk of Data Mask */
#define ICM_RCTRL_TRSIZE(value)               (ICM_RCTRL_TRSIZE_Msk & ((value) << ICM_RCTRL_TRSIZE_Pos))
#define ICM_RCTRL_Msk                         _U_(0x0000FFFF)                                      /**< (ICM_RCTRL) Register Mask  */


/* -------- ICM_RNEXT : (ICM Offset: 0x0C) (R/W 32) Region Next Address -------- */
#define ICM_RNEXT_NEXT_Pos                    _U_(2)                                               /**< (ICM_RNEXT) Region Transfer Descriptor Next Address Position */
#define ICM_RNEXT_NEXT_Msk                    (_U_(0x3FFFFFFF) << ICM_RNEXT_NEXT_Pos)              /**< (ICM_RNEXT) Region Transfer Descriptor Next Address Mask */
#define ICM_RNEXT_NEXT(value)                 (ICM_RNEXT_NEXT_Msk & ((value) << ICM_RNEXT_NEXT_Pos))
#define ICM_RNEXT_Msk                         _U_(0xFFFFFFFC)                                      /**< (ICM_RNEXT) Register Mask  */


/* -------- ICM_CFG : (ICM Offset: 0x00) (R/W 32) Configuration Register -------- */
#define ICM_CFG_WBDIS_Pos                     _U_(0)                                               /**< (ICM_CFG) Write Back Disable Position */
#define ICM_CFG_WBDIS_Msk                     (_U_(0x1) << ICM_CFG_WBDIS_Pos)                      /**< (ICM_CFG) Write Back Disable Mask */
#define ICM_CFG_WBDIS(value)                  (ICM_CFG_WBDIS_Msk & ((value) << ICM_CFG_WBDIS_Pos))
#define ICM_CFG_EOMDIS_Pos                    _U_(1)                                               /**< (ICM_CFG) End of Monitoring Disable Position */
#define ICM_CFG_EOMDIS_Msk                    (_U_(0x1) << ICM_CFG_EOMDIS_Pos)                     /**< (ICM_CFG) End of Monitoring Disable Mask */
#define ICM_CFG_EOMDIS(value)                 (ICM_CFG_EOMDIS_Msk & ((value) << ICM_CFG_EOMDIS_Pos))
#define ICM_CFG_SLBDIS_Pos                    _U_(2)                                               /**< (ICM_CFG) Secondary List Branching Disable Position */
#define ICM_CFG_SLBDIS_Msk                    (_U_(0x1) << ICM_CFG_SLBDIS_Pos)                     /**< (ICM_CFG) Secondary List Branching Disable Mask */
#define ICM_CFG_SLBDIS(value)                 (ICM_CFG_SLBDIS_Msk & ((value) << ICM_CFG_SLBDIS_Pos))
#define ICM_CFG_BBC_Pos                       _U_(4)                                               /**< (ICM_CFG) Bus Burden Control Position */
#define ICM_CFG_BBC_Msk                       (_U_(0xF) << ICM_CFG_BBC_Pos)                        /**< (ICM_CFG) Bus Burden Control Mask */
#define ICM_CFG_BBC(value)                    (ICM_CFG_BBC_Msk & ((value) << ICM_CFG_BBC_Pos))    
#define ICM_CFG_ASCD_Pos                      _U_(8)                                               /**< (ICM_CFG) Automatic Switch To Compare Digest Position */
#define ICM_CFG_ASCD_Msk                      (_U_(0x1) << ICM_CFG_ASCD_Pos)                       /**< (ICM_CFG) Automatic Switch To Compare Digest Mask */
#define ICM_CFG_ASCD(value)                   (ICM_CFG_ASCD_Msk & ((value) << ICM_CFG_ASCD_Pos))  
#define ICM_CFG_DUALBUFF_Pos                  _U_(9)                                               /**< (ICM_CFG) Dual Input Buffer Position */
#define ICM_CFG_DUALBUFF_Msk                  (_U_(0x1) << ICM_CFG_DUALBUFF_Pos)                   /**< (ICM_CFG) Dual Input Buffer Mask */
#define ICM_CFG_DUALBUFF(value)               (ICM_CFG_DUALBUFF_Msk & ((value) << ICM_CFG_DUALBUFF_Pos))
#define ICM_CFG_UIHASH_Pos                    _U_(12)                                              /**< (ICM_CFG) User Initial Hash Value Position */
#define ICM_CFG_UIHASH_Msk                    (_U_(0x1) << ICM_CFG_UIHASH_Pos)                     /**< (ICM_CFG) User Initial Hash Value Mask */
#define ICM_CFG_UIHASH(value)                 (ICM_CFG_UIHASH_Msk & ((value) << ICM_CFG_UIHASH_Pos))
#define ICM_CFG_UALGO_Pos                     _U_(13)                                              /**< (ICM_CFG) User SHA Algorithm Position */
#define ICM_CFG_UALGO_Msk                     (_U_(0x7) << ICM_CFG_UALGO_Pos)                      /**< (ICM_CFG) User SHA Algorithm Mask */
#define ICM_CFG_UALGO(value)                  (ICM_CFG_UALGO_Msk & ((value) << ICM_CFG_UALGO_Pos))
#define   ICM_CFG_UALGO_SHA1_Val              _U_(0x0)                                             /**< (ICM_CFG) SHA1 algorithm processed  */
#define   ICM_CFG_UALGO_SHA256_Val            _U_(0x1)                                             /**< (ICM_CFG) SHA256 algorithm processed  */
#define   ICM_CFG_UALGO_SHA224_Val            _U_(0x4)                                             /**< (ICM_CFG) SHA224 algorithm processed  */
#define ICM_CFG_UALGO_SHA1                    (ICM_CFG_UALGO_SHA1_Val << ICM_CFG_UALGO_Pos)        /**< (ICM_CFG) SHA1 algorithm processed Position  */
#define ICM_CFG_UALGO_SHA256                  (ICM_CFG_UALGO_SHA256_Val << ICM_CFG_UALGO_Pos)      /**< (ICM_CFG) SHA256 algorithm processed Position  */
#define ICM_CFG_UALGO_SHA224                  (ICM_CFG_UALGO_SHA224_Val << ICM_CFG_UALGO_Pos)      /**< (ICM_CFG) SHA224 algorithm processed Position  */
#define ICM_CFG_Msk                           _U_(0x0000F3F7)                                      /**< (ICM_CFG) Register Mask  */


/* -------- ICM_CTRL : (ICM Offset: 0x04) ( /W 32) Control Register -------- */
#define ICM_CTRL_ENABLE_Pos                   _U_(0)                                               /**< (ICM_CTRL) ICM Enable Position */
#define ICM_CTRL_ENABLE_Msk                   (_U_(0x1) << ICM_CTRL_ENABLE_Pos)                    /**< (ICM_CTRL) ICM Enable Mask */
#define ICM_CTRL_ENABLE(value)                (ICM_CTRL_ENABLE_Msk & ((value) << ICM_CTRL_ENABLE_Pos))
#define ICM_CTRL_DISABLE_Pos                  _U_(1)                                               /**< (ICM_CTRL) ICM Disable Register Position */
#define ICM_CTRL_DISABLE_Msk                  (_U_(0x1) << ICM_CTRL_DISABLE_Pos)                   /**< (ICM_CTRL) ICM Disable Register Mask */
#define ICM_CTRL_DISABLE(value)               (ICM_CTRL_DISABLE_Msk & ((value) << ICM_CTRL_DISABLE_Pos))
#define ICM_CTRL_SWRST_Pos                    _U_(2)                                               /**< (ICM_CTRL) Software Reset Position */
#define ICM_CTRL_SWRST_Msk                    (_U_(0x1) << ICM_CTRL_SWRST_Pos)                     /**< (ICM_CTRL) Software Reset Mask */
#define ICM_CTRL_SWRST(value)                 (ICM_CTRL_SWRST_Msk & ((value) << ICM_CTRL_SWRST_Pos))
#define ICM_CTRL_REHASH_Pos                   _U_(4)                                               /**< (ICM_CTRL) Recompute Internal Hash Position */
#define ICM_CTRL_REHASH_Msk                   (_U_(0xF) << ICM_CTRL_REHASH_Pos)                    /**< (ICM_CTRL) Recompute Internal Hash Mask */
#define ICM_CTRL_REHASH(value)                (ICM_CTRL_REHASH_Msk & ((value) << ICM_CTRL_REHASH_Pos))
#define ICM_CTRL_RMDIS_Pos                    _U_(8)                                               /**< (ICM_CTRL) Region Monitoring Disable Position */
#define ICM_CTRL_RMDIS_Msk                    (_U_(0xF) << ICM_CTRL_RMDIS_Pos)                     /**< (ICM_CTRL) Region Monitoring Disable Mask */
#define ICM_CTRL_RMDIS(value)                 (ICM_CTRL_RMDIS_Msk & ((value) << ICM_CTRL_RMDIS_Pos))
#define ICM_CTRL_RMEN_Pos                     _U_(12)                                              /**< (ICM_CTRL) Region Monitoring Enable Position */
#define ICM_CTRL_RMEN_Msk                     (_U_(0xF) << ICM_CTRL_RMEN_Pos)                      /**< (ICM_CTRL) Region Monitoring Enable Mask */
#define ICM_CTRL_RMEN(value)                  (ICM_CTRL_RMEN_Msk & ((value) << ICM_CTRL_RMEN_Pos))
#define ICM_CTRL_Msk                          _U_(0x0000FFF7)                                      /**< (ICM_CTRL) Register Mask  */


/* -------- ICM_SR : (ICM Offset: 0x08) ( R/ 32) Status Register -------- */
#define ICM_SR_ENABLE_Pos                     _U_(0)                                               /**< (ICM_SR) ICM Enable Register Position */
#define ICM_SR_ENABLE_Msk                     (_U_(0x1) << ICM_SR_ENABLE_Pos)                      /**< (ICM_SR) ICM Enable Register Mask */
#define ICM_SR_ENABLE(value)                  (ICM_SR_ENABLE_Msk & ((value) << ICM_SR_ENABLE_Pos))
#define ICM_SR_RAWRMDIS_Pos                   _U_(8)                                               /**< (ICM_SR) Region Monitoring Disabled Raw Status Position */
#define ICM_SR_RAWRMDIS_Msk                   (_U_(0xF) << ICM_SR_RAWRMDIS_Pos)                    /**< (ICM_SR) Region Monitoring Disabled Raw Status Mask */
#define ICM_SR_RAWRMDIS(value)                (ICM_SR_RAWRMDIS_Msk & ((value) << ICM_SR_RAWRMDIS_Pos))
#define ICM_SR_RMDIS_Pos                      _U_(12)                                              /**< (ICM_SR) Region Monitoring Disabled Status Position */
#define ICM_SR_RMDIS_Msk                      (_U_(0xF) << ICM_SR_RMDIS_Pos)                       /**< (ICM_SR) Region Monitoring Disabled Status Mask */
#define ICM_SR_RMDIS(value)                   (ICM_SR_RMDIS_Msk & ((value) << ICM_SR_RMDIS_Pos))  
#define ICM_SR_Msk                            _U_(0x0000FF01)                                      /**< (ICM_SR) Register Mask  */


/* -------- ICM_IER : (ICM Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define ICM_IER_RHC_Pos                       _U_(0)                                               /**< (ICM_IER) Region Hash Completed Interrupt Enable Position */
#define ICM_IER_RHC_Msk                       (_U_(0xF) << ICM_IER_RHC_Pos)                        /**< (ICM_IER) Region Hash Completed Interrupt Enable Mask */
#define ICM_IER_RHC(value)                    (ICM_IER_RHC_Msk & ((value) << ICM_IER_RHC_Pos))    
#define ICM_IER_RDM_Pos                       _U_(4)                                               /**< (ICM_IER) Region Digest Mismatch Interrupt Enable Position */
#define ICM_IER_RDM_Msk                       (_U_(0xF) << ICM_IER_RDM_Pos)                        /**< (ICM_IER) Region Digest Mismatch Interrupt Enable Mask */
#define ICM_IER_RDM(value)                    (ICM_IER_RDM_Msk & ((value) << ICM_IER_RDM_Pos))    
#define ICM_IER_RBE_Pos                       _U_(8)                                               /**< (ICM_IER) Region Bus Error Interrupt Enable Position */
#define ICM_IER_RBE_Msk                       (_U_(0xF) << ICM_IER_RBE_Pos)                        /**< (ICM_IER) Region Bus Error Interrupt Enable Mask */
#define ICM_IER_RBE(value)                    (ICM_IER_RBE_Msk & ((value) << ICM_IER_RBE_Pos))    
#define ICM_IER_RWC_Pos                       _U_(12)                                              /**< (ICM_IER) Region Wrap Condition detected Interrupt Enable Position */
#define ICM_IER_RWC_Msk                       (_U_(0xF) << ICM_IER_RWC_Pos)                        /**< (ICM_IER) Region Wrap Condition detected Interrupt Enable Mask */
#define ICM_IER_RWC(value)                    (ICM_IER_RWC_Msk & ((value) << ICM_IER_RWC_Pos))    
#define ICM_IER_REC_Pos                       _U_(16)                                              /**< (ICM_IER) Region End bit Condition Detected Interrupt Enable Position */
#define ICM_IER_REC_Msk                       (_U_(0xF) << ICM_IER_REC_Pos)                        /**< (ICM_IER) Region End bit Condition Detected Interrupt Enable Mask */
#define ICM_IER_REC(value)                    (ICM_IER_REC_Msk & ((value) << ICM_IER_REC_Pos))    
#define ICM_IER_RSU_Pos                       _U_(20)                                              /**< (ICM_IER) Region Status Updated Interrupt Disable Position */
#define ICM_IER_RSU_Msk                       (_U_(0xF) << ICM_IER_RSU_Pos)                        /**< (ICM_IER) Region Status Updated Interrupt Disable Mask */
#define ICM_IER_RSU(value)                    (ICM_IER_RSU_Msk & ((value) << ICM_IER_RSU_Pos))    
#define ICM_IER_URAD_Pos                      _U_(24)                                              /**< (ICM_IER) Undefined Register Access Detection Interrupt Enable Position */
#define ICM_IER_URAD_Msk                      (_U_(0x1) << ICM_IER_URAD_Pos)                       /**< (ICM_IER) Undefined Register Access Detection Interrupt Enable Mask */
#define ICM_IER_URAD(value)                   (ICM_IER_URAD_Msk & ((value) << ICM_IER_URAD_Pos))  
#define ICM_IER_Msk                           _U_(0x01FFFFFF)                                      /**< (ICM_IER) Register Mask  */


/* -------- ICM_IDR : (ICM Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define ICM_IDR_RHC_Pos                       _U_(0)                                               /**< (ICM_IDR) Region Hash Completed Interrupt Disable Position */
#define ICM_IDR_RHC_Msk                       (_U_(0xF) << ICM_IDR_RHC_Pos)                        /**< (ICM_IDR) Region Hash Completed Interrupt Disable Mask */
#define ICM_IDR_RHC(value)                    (ICM_IDR_RHC_Msk & ((value) << ICM_IDR_RHC_Pos))    
#define ICM_IDR_RDM_Pos                       _U_(4)                                               /**< (ICM_IDR) Region Digest Mismatch Interrupt Disable Position */
#define ICM_IDR_RDM_Msk                       (_U_(0xF) << ICM_IDR_RDM_Pos)                        /**< (ICM_IDR) Region Digest Mismatch Interrupt Disable Mask */
#define ICM_IDR_RDM(value)                    (ICM_IDR_RDM_Msk & ((value) << ICM_IDR_RDM_Pos))    
#define ICM_IDR_RBE_Pos                       _U_(8)                                               /**< (ICM_IDR) Region Bus Error Interrupt Disable Position */
#define ICM_IDR_RBE_Msk                       (_U_(0xF) << ICM_IDR_RBE_Pos)                        /**< (ICM_IDR) Region Bus Error Interrupt Disable Mask */
#define ICM_IDR_RBE(value)                    (ICM_IDR_RBE_Msk & ((value) << ICM_IDR_RBE_Pos))    
#define ICM_IDR_RWC_Pos                       _U_(12)                                              /**< (ICM_IDR) Region Wrap Condition Detected Interrupt Disable Position */
#define ICM_IDR_RWC_Msk                       (_U_(0xF) << ICM_IDR_RWC_Pos)                        /**< (ICM_IDR) Region Wrap Condition Detected Interrupt Disable Mask */
#define ICM_IDR_RWC(value)                    (ICM_IDR_RWC_Msk & ((value) << ICM_IDR_RWC_Pos))    
#define ICM_IDR_REC_Pos                       _U_(16)                                              /**< (ICM_IDR) Region End bit Condition detected Interrupt Disable Position */
#define ICM_IDR_REC_Msk                       (_U_(0xF) << ICM_IDR_REC_Pos)                        /**< (ICM_IDR) Region End bit Condition detected Interrupt Disable Mask */
#define ICM_IDR_REC(value)                    (ICM_IDR_REC_Msk & ((value) << ICM_IDR_REC_Pos))    
#define ICM_IDR_RSU_Pos                       _U_(20)                                              /**< (ICM_IDR) Region Status Updated Interrupt Disable Position */
#define ICM_IDR_RSU_Msk                       (_U_(0xF) << ICM_IDR_RSU_Pos)                        /**< (ICM_IDR) Region Status Updated Interrupt Disable Mask */
#define ICM_IDR_RSU(value)                    (ICM_IDR_RSU_Msk & ((value) << ICM_IDR_RSU_Pos))    
#define ICM_IDR_URAD_Pos                      _U_(24)                                              /**< (ICM_IDR) Undefined Register Access Detection Interrupt Disable Position */
#define ICM_IDR_URAD_Msk                      (_U_(0x1) << ICM_IDR_URAD_Pos)                       /**< (ICM_IDR) Undefined Register Access Detection Interrupt Disable Mask */
#define ICM_IDR_URAD(value)                   (ICM_IDR_URAD_Msk & ((value) << ICM_IDR_URAD_Pos))  
#define ICM_IDR_Msk                           _U_(0x01FFFFFF)                                      /**< (ICM_IDR) Register Mask  */


/* -------- ICM_IMR : (ICM Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define ICM_IMR_RHC_Pos                       _U_(0)                                               /**< (ICM_IMR) Region Hash Completed Interrupt Mask Position */
#define ICM_IMR_RHC_Msk                       (_U_(0xF) << ICM_IMR_RHC_Pos)                        /**< (ICM_IMR) Region Hash Completed Interrupt Mask Mask */
#define ICM_IMR_RHC(value)                    (ICM_IMR_RHC_Msk & ((value) << ICM_IMR_RHC_Pos))    
#define ICM_IMR_RDM_Pos                       _U_(4)                                               /**< (ICM_IMR) Region Digest Mismatch Interrupt Mask Position */
#define ICM_IMR_RDM_Msk                       (_U_(0xF) << ICM_IMR_RDM_Pos)                        /**< (ICM_IMR) Region Digest Mismatch Interrupt Mask Mask */
#define ICM_IMR_RDM(value)                    (ICM_IMR_RDM_Msk & ((value) << ICM_IMR_RDM_Pos))    
#define ICM_IMR_RBE_Pos                       _U_(8)                                               /**< (ICM_IMR) Region Bus Error Interrupt Mask Position */
#define ICM_IMR_RBE_Msk                       (_U_(0xF) << ICM_IMR_RBE_Pos)                        /**< (ICM_IMR) Region Bus Error Interrupt Mask Mask */
#define ICM_IMR_RBE(value)                    (ICM_IMR_RBE_Msk & ((value) << ICM_IMR_RBE_Pos))    
#define ICM_IMR_RWC_Pos                       _U_(12)                                              /**< (ICM_IMR) Region Wrap Condition Detected Interrupt Mask Position */
#define ICM_IMR_RWC_Msk                       (_U_(0xF) << ICM_IMR_RWC_Pos)                        /**< (ICM_IMR) Region Wrap Condition Detected Interrupt Mask Mask */
#define ICM_IMR_RWC(value)                    (ICM_IMR_RWC_Msk & ((value) << ICM_IMR_RWC_Pos))    
#define ICM_IMR_REC_Pos                       _U_(16)                                              /**< (ICM_IMR) Region End bit Condition Detected Interrupt Mask Position */
#define ICM_IMR_REC_Msk                       (_U_(0xF) << ICM_IMR_REC_Pos)                        /**< (ICM_IMR) Region End bit Condition Detected Interrupt Mask Mask */
#define ICM_IMR_REC(value)                    (ICM_IMR_REC_Msk & ((value) << ICM_IMR_REC_Pos))    
#define ICM_IMR_RSU_Pos                       _U_(20)                                              /**< (ICM_IMR) Region Status Updated Interrupt Mask Position */
#define ICM_IMR_RSU_Msk                       (_U_(0xF) << ICM_IMR_RSU_Pos)                        /**< (ICM_IMR) Region Status Updated Interrupt Mask Mask */
#define ICM_IMR_RSU(value)                    (ICM_IMR_RSU_Msk & ((value) << ICM_IMR_RSU_Pos))    
#define ICM_IMR_URAD_Pos                      _U_(24)                                              /**< (ICM_IMR) Undefined Register Access Detection Interrupt Mask Position */
#define ICM_IMR_URAD_Msk                      (_U_(0x1) << ICM_IMR_URAD_Pos)                       /**< (ICM_IMR) Undefined Register Access Detection Interrupt Mask Mask */
#define ICM_IMR_URAD(value)                   (ICM_IMR_URAD_Msk & ((value) << ICM_IMR_URAD_Pos))  
#define ICM_IMR_Msk                           _U_(0x01FFFFFF)                                      /**< (ICM_IMR) Register Mask  */


/* -------- ICM_ISR : (ICM Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define ICM_ISR_RHC_Pos                       _U_(0)                                               /**< (ICM_ISR) Region Hash Completed Position */
#define ICM_ISR_RHC_Msk                       (_U_(0xF) << ICM_ISR_RHC_Pos)                        /**< (ICM_ISR) Region Hash Completed Mask */
#define ICM_ISR_RHC(value)                    (ICM_ISR_RHC_Msk & ((value) << ICM_ISR_RHC_Pos))    
#define ICM_ISR_RDM_Pos                       _U_(4)                                               /**< (ICM_ISR) Region Digest Mismatch Position */
#define ICM_ISR_RDM_Msk                       (_U_(0xF) << ICM_ISR_RDM_Pos)                        /**< (ICM_ISR) Region Digest Mismatch Mask */
#define ICM_ISR_RDM(value)                    (ICM_ISR_RDM_Msk & ((value) << ICM_ISR_RDM_Pos))    
#define ICM_ISR_RBE_Pos                       _U_(8)                                               /**< (ICM_ISR) Region Bus Error Position */
#define ICM_ISR_RBE_Msk                       (_U_(0xF) << ICM_ISR_RBE_Pos)                        /**< (ICM_ISR) Region Bus Error Mask */
#define ICM_ISR_RBE(value)                    (ICM_ISR_RBE_Msk & ((value) << ICM_ISR_RBE_Pos))    
#define ICM_ISR_RWC_Pos                       _U_(12)                                              /**< (ICM_ISR) Region Wrap Condition Detected Position */
#define ICM_ISR_RWC_Msk                       (_U_(0xF) << ICM_ISR_RWC_Pos)                        /**< (ICM_ISR) Region Wrap Condition Detected Mask */
#define ICM_ISR_RWC(value)                    (ICM_ISR_RWC_Msk & ((value) << ICM_ISR_RWC_Pos))    
#define ICM_ISR_REC_Pos                       _U_(16)                                              /**< (ICM_ISR) Region End Bit Condition Detected Position */
#define ICM_ISR_REC_Msk                       (_U_(0xF) << ICM_ISR_REC_Pos)                        /**< (ICM_ISR) Region End Bit Condition Detected Mask */
#define ICM_ISR_REC(value)                    (ICM_ISR_REC_Msk & ((value) << ICM_ISR_REC_Pos))    
#define ICM_ISR_RSU_Pos                       _U_(20)                                              /**< (ICM_ISR) Region Status Updated Detected Position */
#define ICM_ISR_RSU_Msk                       (_U_(0xF) << ICM_ISR_RSU_Pos)                        /**< (ICM_ISR) Region Status Updated Detected Mask */
#define ICM_ISR_RSU(value)                    (ICM_ISR_RSU_Msk & ((value) << ICM_ISR_RSU_Pos))    
#define ICM_ISR_URAD_Pos                      _U_(24)                                              /**< (ICM_ISR) Undefined Register Access Detection Status Position */
#define ICM_ISR_URAD_Msk                      (_U_(0x1) << ICM_ISR_URAD_Pos)                       /**< (ICM_ISR) Undefined Register Access Detection Status Mask */
#define ICM_ISR_URAD(value)                   (ICM_ISR_URAD_Msk & ((value) << ICM_ISR_URAD_Pos))  
#define ICM_ISR_Msk                           _U_(0x01FFFFFF)                                      /**< (ICM_ISR) Register Mask  */


/* -------- ICM_UASR : (ICM Offset: 0x20) ( R/ 32) Undefined Access Status Register -------- */
#define ICM_UASR_URAT_Pos                     _U_(0)                                               /**< (ICM_UASR) Undefined Register Access Trace Position */
#define ICM_UASR_URAT_Msk                     (_U_(0x7) << ICM_UASR_URAT_Pos)                      /**< (ICM_UASR) Undefined Register Access Trace Mask */
#define ICM_UASR_URAT(value)                  (ICM_UASR_URAT_Msk & ((value) << ICM_UASR_URAT_Pos))
#define   ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER_Val _U_(0x0)                                             /**< (ICM_UASR) Unspecified structure member set to one detected when the descriptor is loaded.  */
#define   ICM_UASR_URAT_ICM_CFG_MODIFIED_Val  _U_(0x1)                                             /**< (ICM_UASR) ICM_CFG modified during active monitoring.  */
#define   ICM_UASR_URAT_ICM_DSCR_MODIFIED_Val _U_(0x2)                                             /**< (ICM_UASR) ICM_DSCR modified during active monitoring.  */
#define   ICM_UASR_URAT_ICM_HASH_MODIFIED_Val _U_(0x3)                                             /**< (ICM_UASR) ICM_HASH modified during active monitoring  */
#define   ICM_UASR_URAT_READ_ACCESS_Val       _U_(0x4)                                             /**< (ICM_UASR) Write-only register read access  */
#define ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER    (ICM_UASR_URAT_UNSPEC_STRUCT_MEMBER_Val << ICM_UASR_URAT_Pos) /**< (ICM_UASR) Unspecified structure member set to one detected when the descriptor is loaded. Position  */
#define ICM_UASR_URAT_ICM_CFG_MODIFIED        (ICM_UASR_URAT_ICM_CFG_MODIFIED_Val << ICM_UASR_URAT_Pos) /**< (ICM_UASR) ICM_CFG modified during active monitoring. Position  */
#define ICM_UASR_URAT_ICM_DSCR_MODIFIED       (ICM_UASR_URAT_ICM_DSCR_MODIFIED_Val << ICM_UASR_URAT_Pos) /**< (ICM_UASR) ICM_DSCR modified during active monitoring. Position  */
#define ICM_UASR_URAT_ICM_HASH_MODIFIED       (ICM_UASR_URAT_ICM_HASH_MODIFIED_Val << ICM_UASR_URAT_Pos) /**< (ICM_UASR) ICM_HASH modified during active monitoring Position  */
#define ICM_UASR_URAT_READ_ACCESS             (ICM_UASR_URAT_READ_ACCESS_Val << ICM_UASR_URAT_Pos) /**< (ICM_UASR) Write-only register read access Position  */
#define ICM_UASR_Msk                          _U_(0x00000007)                                      /**< (ICM_UASR) Register Mask  */


/* -------- ICM_DSCR : (ICM Offset: 0x30) (R/W 32) Region Descriptor Area Start Address Register -------- */
#define ICM_DSCR_DASA_Pos                     _U_(6)                                               /**< (ICM_DSCR) Descriptor Area Start Address Position */
#define ICM_DSCR_DASA_Msk                     (_U_(0x3FFFFFF) << ICM_DSCR_DASA_Pos)                /**< (ICM_DSCR) Descriptor Area Start Address Mask */
#define ICM_DSCR_DASA(value)                  (ICM_DSCR_DASA_Msk & ((value) << ICM_DSCR_DASA_Pos))
#define ICM_DSCR_Msk                          _U_(0xFFFFFFC0)                                      /**< (ICM_DSCR) Register Mask  */


/* -------- ICM_HASH : (ICM Offset: 0x34) (R/W 32) Region Hash Area Start Address Register -------- */
#define ICM_HASH_HASA_Pos                     _U_(7)                                               /**< (ICM_HASH) Hash Area Start Address Position */
#define ICM_HASH_HASA_Msk                     (_U_(0x1FFFFFF) << ICM_HASH_HASA_Pos)                /**< (ICM_HASH) Hash Area Start Address Mask */
#define ICM_HASH_HASA(value)                  (ICM_HASH_HASA_Msk & ((value) << ICM_HASH_HASA_Pos))
#define ICM_HASH_Msk                          _U_(0xFFFFFF80)                                      /**< (ICM_HASH) Register Mask  */


/* -------- ICM_UIHVAL0 : (ICM Offset: 0x38) ( /W 32) User Initial Hash Value 0 Register 0 -------- */
#define ICM_UIHVAL0_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL0) Initial Hash Value Position */
#define ICM_UIHVAL0_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL0_VAL_Pos)             /**< (ICM_UIHVAL0) Initial Hash Value Mask */
#define ICM_UIHVAL0_VAL(value)                (ICM_UIHVAL0_VAL_Msk & ((value) << ICM_UIHVAL0_VAL_Pos))
#define ICM_UIHVAL0_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL0) Register Mask  */


/* -------- ICM_UIHVAL1 : (ICM Offset: 0x3C) ( /W 32) User Initial Hash Value 0 Register 1 -------- */
#define ICM_UIHVAL1_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL1) Initial Hash Value Position */
#define ICM_UIHVAL1_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL1_VAL_Pos)             /**< (ICM_UIHVAL1) Initial Hash Value Mask */
#define ICM_UIHVAL1_VAL(value)                (ICM_UIHVAL1_VAL_Msk & ((value) << ICM_UIHVAL1_VAL_Pos))
#define ICM_UIHVAL1_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL1) Register Mask  */


/* -------- ICM_UIHVAL2 : (ICM Offset: 0x40) ( /W 32) User Initial Hash Value 0 Register 2 -------- */
#define ICM_UIHVAL2_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL2) Initial Hash Value Position */
#define ICM_UIHVAL2_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL2_VAL_Pos)             /**< (ICM_UIHVAL2) Initial Hash Value Mask */
#define ICM_UIHVAL2_VAL(value)                (ICM_UIHVAL2_VAL_Msk & ((value) << ICM_UIHVAL2_VAL_Pos))
#define ICM_UIHVAL2_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL2) Register Mask  */


/* -------- ICM_UIHVAL3 : (ICM Offset: 0x44) ( /W 32) User Initial Hash Value 0 Register 3 -------- */
#define ICM_UIHVAL3_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL3) Initial Hash Value Position */
#define ICM_UIHVAL3_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL3_VAL_Pos)             /**< (ICM_UIHVAL3) Initial Hash Value Mask */
#define ICM_UIHVAL3_VAL(value)                (ICM_UIHVAL3_VAL_Msk & ((value) << ICM_UIHVAL3_VAL_Pos))
#define ICM_UIHVAL3_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL3) Register Mask  */


/* -------- ICM_UIHVAL4 : (ICM Offset: 0x48) ( /W 32) User Initial Hash Value 0 Register 4 -------- */
#define ICM_UIHVAL4_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL4) Initial Hash Value Position */
#define ICM_UIHVAL4_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL4_VAL_Pos)             /**< (ICM_UIHVAL4) Initial Hash Value Mask */
#define ICM_UIHVAL4_VAL(value)                (ICM_UIHVAL4_VAL_Msk & ((value) << ICM_UIHVAL4_VAL_Pos))
#define ICM_UIHVAL4_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL4) Register Mask  */


/* -------- ICM_UIHVAL5 : (ICM Offset: 0x4C) ( /W 32) User Initial Hash Value 0 Register 5 -------- */
#define ICM_UIHVAL5_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL5) Initial Hash Value Position */
#define ICM_UIHVAL5_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL5_VAL_Pos)             /**< (ICM_UIHVAL5) Initial Hash Value Mask */
#define ICM_UIHVAL5_VAL(value)                (ICM_UIHVAL5_VAL_Msk & ((value) << ICM_UIHVAL5_VAL_Pos))
#define ICM_UIHVAL5_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL5) Register Mask  */


/* -------- ICM_UIHVAL6 : (ICM Offset: 0x50) ( /W 32) User Initial Hash Value 0 Register 6 -------- */
#define ICM_UIHVAL6_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL6) Initial Hash Value Position */
#define ICM_UIHVAL6_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL6_VAL_Pos)             /**< (ICM_UIHVAL6) Initial Hash Value Mask */
#define ICM_UIHVAL6_VAL(value)                (ICM_UIHVAL6_VAL_Msk & ((value) << ICM_UIHVAL6_VAL_Pos))
#define ICM_UIHVAL6_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL6) Register Mask  */


/* -------- ICM_UIHVAL7 : (ICM Offset: 0x54) ( /W 32) User Initial Hash Value 0 Register 7 -------- */
#define ICM_UIHVAL7_VAL_Pos                   _U_(0)                                               /**< (ICM_UIHVAL7) Initial Hash Value Position */
#define ICM_UIHVAL7_VAL_Msk                   (_U_(0xFFFFFFFF) << ICM_UIHVAL7_VAL_Pos)             /**< (ICM_UIHVAL7) Initial Hash Value Mask */
#define ICM_UIHVAL7_VAL(value)                (ICM_UIHVAL7_VAL_Msk & ((value) << ICM_UIHVAL7_VAL_Pos))
#define ICM_UIHVAL7_Msk                       _U_(0xFFFFFFFF)                                      /**< (ICM_UIHVAL7) Register Mask  */


/* -------- ICM_WPMR : (ICM Offset: 0xE4) (R/W 32) ICM Write Protection Mode Register -------- */
#define ICM_WPMR_WPEN_Pos                     _U_(0)                                               /**< (ICM_WPMR) Write Protection Enable Position */
#define ICM_WPMR_WPEN_Msk                     (_U_(0x1) << ICM_WPMR_WPEN_Pos)                      /**< (ICM_WPMR) Write Protection Enable Mask */
#define ICM_WPMR_WPEN(value)                  (ICM_WPMR_WPEN_Msk & ((value) << ICM_WPMR_WPEN_Pos))
#define ICM_WPMR_WPITEN_Pos                   _U_(1)                                               /**< (ICM_WPMR) Write Protection Interrupt Enable Position */
#define ICM_WPMR_WPITEN_Msk                   (_U_(0x1) << ICM_WPMR_WPITEN_Pos)                    /**< (ICM_WPMR) Write Protection Interrupt Enable Mask */
#define ICM_WPMR_WPITEN(value)                (ICM_WPMR_WPITEN_Msk & ((value) << ICM_WPMR_WPITEN_Pos))
#define ICM_WPMR_WPCREN_Pos                   _U_(2)                                               /**< (ICM_WPMR) Write Protection Control Enable Position */
#define ICM_WPMR_WPCREN_Msk                   (_U_(0x1) << ICM_WPMR_WPCREN_Pos)                    /**< (ICM_WPMR) Write Protection Control Enable Mask */
#define ICM_WPMR_WPCREN(value)                (ICM_WPMR_WPCREN_Msk & ((value) << ICM_WPMR_WPCREN_Pos))
#define ICM_WPMR_WPKEY_Pos                    _U_(8)                                               /**< (ICM_WPMR) Write Protection Key Position */
#define ICM_WPMR_WPKEY_Msk                    (_U_(0xFFFFFF) << ICM_WPMR_WPKEY_Pos)                /**< (ICM_WPMR) Write Protection Key Mask */
#define ICM_WPMR_WPKEY(value)                 (ICM_WPMR_WPKEY_Msk & ((value) << ICM_WPMR_WPKEY_Pos))
#define   ICM_WPMR_WPKEY_PASSWD_Val           _U_(0x49434D)                                        /**< (ICM_WPMR) Writing any other value in this field aborts the write operation of the WPEN, WPITEN and WPCREN bits.Always reads as 0  */
#define ICM_WPMR_WPKEY_PASSWD                 (ICM_WPMR_WPKEY_PASSWD_Val << ICM_WPMR_WPKEY_Pos)    /**< (ICM_WPMR) Writing any other value in this field aborts the write operation of the WPEN, WPITEN and WPCREN bits.Always reads as 0 Position  */
#define ICM_WPMR_Msk                          _U_(0xFFFFFF07)                                      /**< (ICM_WPMR) Register Mask  */


/* -------- ICM_WPSR : (ICM Offset: 0xE8) ( R/ 32) ICM Write Protection Status Register -------- */
#define ICM_WPSR_WPVS_Pos                     _U_(0)                                               /**< (ICM_WPSR) Write Protection Violation Status (Cleared on read) Position */
#define ICM_WPSR_WPVS_Msk                     (_U_(0x1) << ICM_WPSR_WPVS_Pos)                      /**< (ICM_WPSR) Write Protection Violation Status (Cleared on read) Mask */
#define ICM_WPSR_WPVS(value)                  (ICM_WPSR_WPVS_Msk & ((value) << ICM_WPSR_WPVS_Pos))
#define ICM_WPSR_WPVSRC_Pos                   _U_(8)                                               /**< (ICM_WPSR) Write Protection Violation Source Position */
#define ICM_WPSR_WPVSRC_Msk                   (_U_(0xFF) << ICM_WPSR_WPVSRC_Pos)                   /**< (ICM_WPSR) Write Protection Violation Source Mask */
#define ICM_WPSR_WPVSRC(value)                (ICM_WPSR_WPVSRC_Msk & ((value) << ICM_WPSR_WPVSRC_Pos))
#define ICM_WPSR_Msk                          _U_(0x0000FF01)                                      /**< (ICM_WPSR) Register Mask  */


/** \brief ICM register offsets definitions */
#define ICM_RADDR_REG_OFST             (0x00)              /**< (ICM_RADDR) Region Start Address Offset */
#define ICM_RCFG_REG_OFST              (0x04)              /**< (ICM_RCFG) Region Configuration Offset */
#define ICM_RCTRL_REG_OFST             (0x08)              /**< (ICM_RCTRL) Region Control Offset */
#define ICM_RNEXT_REG_OFST             (0x0C)              /**< (ICM_RNEXT) Region Next Address Offset */
#define ICM_CFG_REG_OFST               (0x00)              /**< (ICM_CFG) Configuration Register Offset */
#define ICM_CTRL_REG_OFST              (0x04)              /**< (ICM_CTRL) Control Register Offset */
#define ICM_SR_REG_OFST                (0x08)              /**< (ICM_SR) Status Register Offset */
#define ICM_IER_REG_OFST               (0x10)              /**< (ICM_IER) Interrupt Enable Register Offset */
#define ICM_IDR_REG_OFST               (0x14)              /**< (ICM_IDR) Interrupt Disable Register Offset */
#define ICM_IMR_REG_OFST               (0x18)              /**< (ICM_IMR) Interrupt Mask Register Offset */
#define ICM_ISR_REG_OFST               (0x1C)              /**< (ICM_ISR) Interrupt Status Register Offset */
#define ICM_UASR_REG_OFST              (0x20)              /**< (ICM_UASR) Undefined Access Status Register Offset */
#define ICM_DSCR_REG_OFST              (0x30)              /**< (ICM_DSCR) Region Descriptor Area Start Address Register Offset */
#define ICM_HASH_REG_OFST              (0x34)              /**< (ICM_HASH) Region Hash Area Start Address Register Offset */
#define ICM_UIHVAL0_REG_OFST           (0x38)              /**< (ICM_UIHVAL0) User Initial Hash Value 0 Register 0 Offset */
#define ICM_UIHVAL1_REG_OFST           (0x3C)              /**< (ICM_UIHVAL1) User Initial Hash Value 0 Register 1 Offset */
#define ICM_UIHVAL2_REG_OFST           (0x40)              /**< (ICM_UIHVAL2) User Initial Hash Value 0 Register 2 Offset */
#define ICM_UIHVAL3_REG_OFST           (0x44)              /**< (ICM_UIHVAL3) User Initial Hash Value 0 Register 3 Offset */
#define ICM_UIHVAL4_REG_OFST           (0x48)              /**< (ICM_UIHVAL4) User Initial Hash Value 0 Register 4 Offset */
#define ICM_UIHVAL5_REG_OFST           (0x4C)              /**< (ICM_UIHVAL5) User Initial Hash Value 0 Register 5 Offset */
#define ICM_UIHVAL6_REG_OFST           (0x50)              /**< (ICM_UIHVAL6) User Initial Hash Value 0 Register 6 Offset */
#define ICM_UIHVAL7_REG_OFST           (0x54)              /**< (ICM_UIHVAL7) User Initial Hash Value 0 Register 7 Offset */
#define ICM_WPMR_REG_OFST              (0xE4)              /**< (ICM_WPMR) ICM Write Protection Mode Register Offset */
#define ICM_WPSR_REG_OFST              (0xE8)              /**< (ICM_WPSR) ICM Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief ICM_DESCRIPTOR register API structure */
typedef struct
{  /* Region Descriptor Structure */
  __IO  uint32_t                       ICM_RADDR;          /**< Offset: 0x00 (R/W  32) Region Start Address */
  __IO  uint32_t                       ICM_RCFG;           /**< Offset: 0x04 (R/W  32) Region Configuration */
  __IO  uint32_t                       ICM_RCTRL;          /**< Offset: 0x08 (R/W  32) Region Control */
  __IO  uint32_t                       ICM_RNEXT;          /**< Offset: 0x0C (R/W  32) Region Next Address */
} icm_descriptor_registers_t
#ifdef __GNUC__
  __attribute__ ((aligned (8)))
#endif
;

/** \brief ICM register API structure */
typedef struct
{
  __IO  uint32_t                       ICM_CFG;            /**< Offset: 0x00 (R/W  32) Configuration Register */
  __O   uint32_t                       ICM_CTRL;           /**< Offset: 0x04 ( /W  32) Control Register */
  __I   uint32_t                       ICM_SR;             /**< Offset: 0x08 (R/   32) Status Register */
  __I   uint8_t                        Reserved1[0x04];
  __O   uint32_t                       ICM_IER;            /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       ICM_IDR;            /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       ICM_IMR;            /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       ICM_ISR;            /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __I   uint32_t                       ICM_UASR;           /**< Offset: 0x20 (R/   32) Undefined Access Status Register */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       ICM_DSCR;           /**< Offset: 0x30 (R/W  32) Region Descriptor Area Start Address Register */
  __IO  uint32_t                       ICM_HASH;           /**< Offset: 0x34 (R/W  32) Region Hash Area Start Address Register */
  __O   uint32_t                       ICM_UIHVAL0;        /**< Offset: 0x38 ( /W  32) User Initial Hash Value 0 Register 0 */
  __O   uint32_t                       ICM_UIHVAL1;        /**< Offset: 0x3C ( /W  32) User Initial Hash Value 0 Register 1 */
  __O   uint32_t                       ICM_UIHVAL2;        /**< Offset: 0x40 ( /W  32) User Initial Hash Value 0 Register 2 */
  __O   uint32_t                       ICM_UIHVAL3;        /**< Offset: 0x44 ( /W  32) User Initial Hash Value 0 Register 3 */
  __O   uint32_t                       ICM_UIHVAL4;        /**< Offset: 0x48 ( /W  32) User Initial Hash Value 0 Register 4 */
  __O   uint32_t                       ICM_UIHVAL5;        /**< Offset: 0x4C ( /W  32) User Initial Hash Value 0 Register 5 */
  __O   uint32_t                       ICM_UIHVAL6;        /**< Offset: 0x50 ( /W  32) User Initial Hash Value 0 Register 6 */
  __O   uint32_t                       ICM_UIHVAL7;        /**< Offset: 0x54 ( /W  32) User Initial Hash Value 0 Register 7 */
  __I   uint8_t                        Reserved3[0x8C];
  __IO  uint32_t                       ICM_WPMR;           /**< Offset: 0xE4 (R/W  32) ICM Write Protection Mode Register */
  __I   uint32_t                       ICM_WPSR;           /**< Offset: 0xE8 (R/   32) ICM Write Protection Status Register */
} icm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** \brief ICM_DESCRIPTOR memory section attribute */
#define SECTION_ICM_DESCRIPTOR

#endif /* _SAMRH71_ICM_COMPONENT_H_ */
