/**
 * \brief Component description for MATRIX
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
#ifndef _SAMRH71_MATRIX_COMPONENT_H_
#define _SAMRH71_MATRIX_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR MATRIX                                       */
/* ************************************************************************** */

/* -------- MATRIX_MCFG0 : (MATRIX Offset: 0x00) (R/W 32) Master Configuration Register 0 -------- */
#define MATRIX_MCFG0_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG0) Undefined Length Burst Type Position */
#define MATRIX_MCFG0_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG0_ULBT_Pos)                  /**< (MATRIX_MCFG0) Undefined Length Burst Type Mask */
#define MATRIX_MCFG0_ULBT(value)              (MATRIX_MCFG0_ULBT_Msk & ((value) << MATRIX_MCFG0_ULBT_Pos))
#define   MATRIX_MCFG0_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG0) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG0_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG0) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG0_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG0) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG0_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG0) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG0_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG0) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG0_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG0) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG0_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG0) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG0_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG0) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG0_ULBT_UNLIMITED           (MATRIX_MCFG0_ULBT_UNLIMITED_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG0_ULBT_SINGLE              (MATRIX_MCFG0_ULBT_SINGLE_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG0_ULBT_4_BEAT              (MATRIX_MCFG0_ULBT_4_BEAT_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG0_ULBT_8_BEAT              (MATRIX_MCFG0_ULBT_8_BEAT_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG0_ULBT_16_BEAT             (MATRIX_MCFG0_ULBT_16_BEAT_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG0_ULBT_32_BEAT             (MATRIX_MCFG0_ULBT_32_BEAT_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG0_ULBT_64_BEAT             (MATRIX_MCFG0_ULBT_64_BEAT_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG0_ULBT_128_BEAT            (MATRIX_MCFG0_ULBT_128_BEAT_Val << MATRIX_MCFG0_ULBT_Pos) /**< (MATRIX_MCFG0) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG0_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG0) Register Mask  */


/* -------- MATRIX_MCFG1 : (MATRIX Offset: 0x04) (R/W 32) Master Configuration Register 1 -------- */
#define MATRIX_MCFG1_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG1) Undefined Length Burst Type Position */
#define MATRIX_MCFG1_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG1_ULBT_Pos)                  /**< (MATRIX_MCFG1) Undefined Length Burst Type Mask */
#define MATRIX_MCFG1_ULBT(value)              (MATRIX_MCFG1_ULBT_Msk & ((value) << MATRIX_MCFG1_ULBT_Pos))
#define   MATRIX_MCFG1_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG1) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG1_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG1) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG1_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG1) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG1_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG1) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG1_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG1) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG1_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG1) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG1_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG1) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG1_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG1) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG1_ULBT_UNLIMITED           (MATRIX_MCFG1_ULBT_UNLIMITED_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG1_ULBT_SINGLE              (MATRIX_MCFG1_ULBT_SINGLE_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG1_ULBT_4_BEAT              (MATRIX_MCFG1_ULBT_4_BEAT_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG1_ULBT_8_BEAT              (MATRIX_MCFG1_ULBT_8_BEAT_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG1_ULBT_16_BEAT             (MATRIX_MCFG1_ULBT_16_BEAT_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG1_ULBT_32_BEAT             (MATRIX_MCFG1_ULBT_32_BEAT_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG1_ULBT_64_BEAT             (MATRIX_MCFG1_ULBT_64_BEAT_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG1_ULBT_128_BEAT            (MATRIX_MCFG1_ULBT_128_BEAT_Val << MATRIX_MCFG1_ULBT_Pos) /**< (MATRIX_MCFG1) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG1_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG1) Register Mask  */


/* -------- MATRIX_MCFG2 : (MATRIX Offset: 0x08) (R/W 32) Master Configuration Register 2 -------- */
#define MATRIX_MCFG2_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG2) Undefined Length Burst Type Position */
#define MATRIX_MCFG2_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG2_ULBT_Pos)                  /**< (MATRIX_MCFG2) Undefined Length Burst Type Mask */
#define MATRIX_MCFG2_ULBT(value)              (MATRIX_MCFG2_ULBT_Msk & ((value) << MATRIX_MCFG2_ULBT_Pos))
#define   MATRIX_MCFG2_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG2) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG2_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG2) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG2_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG2) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG2_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG2) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG2_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG2) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG2_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG2) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG2_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG2) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG2_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG2) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG2_ULBT_UNLIMITED           (MATRIX_MCFG2_ULBT_UNLIMITED_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG2_ULBT_SINGLE              (MATRIX_MCFG2_ULBT_SINGLE_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG2_ULBT_4_BEAT              (MATRIX_MCFG2_ULBT_4_BEAT_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG2_ULBT_8_BEAT              (MATRIX_MCFG2_ULBT_8_BEAT_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG2_ULBT_16_BEAT             (MATRIX_MCFG2_ULBT_16_BEAT_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG2_ULBT_32_BEAT             (MATRIX_MCFG2_ULBT_32_BEAT_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG2_ULBT_64_BEAT             (MATRIX_MCFG2_ULBT_64_BEAT_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG2_ULBT_128_BEAT            (MATRIX_MCFG2_ULBT_128_BEAT_Val << MATRIX_MCFG2_ULBT_Pos) /**< (MATRIX_MCFG2) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG2_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG2) Register Mask  */


/* -------- MATRIX_MCFG3 : (MATRIX Offset: 0x0C) (R/W 32) Master Configuration Register 3 -------- */
#define MATRIX_MCFG3_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG3) Undefined Length Burst Type Position */
#define MATRIX_MCFG3_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG3_ULBT_Pos)                  /**< (MATRIX_MCFG3) Undefined Length Burst Type Mask */
#define MATRIX_MCFG3_ULBT(value)              (MATRIX_MCFG3_ULBT_Msk & ((value) << MATRIX_MCFG3_ULBT_Pos))
#define   MATRIX_MCFG3_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG3) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG3_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG3) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG3_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG3) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG3_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG3) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG3_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG3) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG3_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG3) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG3_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG3) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG3_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG3) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG3_ULBT_UNLIMITED           (MATRIX_MCFG3_ULBT_UNLIMITED_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG3_ULBT_SINGLE              (MATRIX_MCFG3_ULBT_SINGLE_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG3_ULBT_4_BEAT              (MATRIX_MCFG3_ULBT_4_BEAT_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG3_ULBT_8_BEAT              (MATRIX_MCFG3_ULBT_8_BEAT_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG3_ULBT_16_BEAT             (MATRIX_MCFG3_ULBT_16_BEAT_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG3_ULBT_32_BEAT             (MATRIX_MCFG3_ULBT_32_BEAT_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG3_ULBT_64_BEAT             (MATRIX_MCFG3_ULBT_64_BEAT_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG3_ULBT_128_BEAT            (MATRIX_MCFG3_ULBT_128_BEAT_Val << MATRIX_MCFG3_ULBT_Pos) /**< (MATRIX_MCFG3) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG3_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG3) Register Mask  */


/* -------- MATRIX_MCFG4 : (MATRIX Offset: 0x10) (R/W 32) Master Configuration Register 4 -------- */
#define MATRIX_MCFG4_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG4) Undefined Length Burst Type Position */
#define MATRIX_MCFG4_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG4_ULBT_Pos)                  /**< (MATRIX_MCFG4) Undefined Length Burst Type Mask */
#define MATRIX_MCFG4_ULBT(value)              (MATRIX_MCFG4_ULBT_Msk & ((value) << MATRIX_MCFG4_ULBT_Pos))
#define   MATRIX_MCFG4_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG4) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG4_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG4) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG4_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG4) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG4_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG4) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG4_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG4) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG4_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG4) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG4_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG4) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG4_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG4) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG4_ULBT_UNLIMITED           (MATRIX_MCFG4_ULBT_UNLIMITED_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG4_ULBT_SINGLE              (MATRIX_MCFG4_ULBT_SINGLE_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG4_ULBT_4_BEAT              (MATRIX_MCFG4_ULBT_4_BEAT_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG4_ULBT_8_BEAT              (MATRIX_MCFG4_ULBT_8_BEAT_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG4_ULBT_16_BEAT             (MATRIX_MCFG4_ULBT_16_BEAT_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG4_ULBT_32_BEAT             (MATRIX_MCFG4_ULBT_32_BEAT_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG4_ULBT_64_BEAT             (MATRIX_MCFG4_ULBT_64_BEAT_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG4_ULBT_128_BEAT            (MATRIX_MCFG4_ULBT_128_BEAT_Val << MATRIX_MCFG4_ULBT_Pos) /**< (MATRIX_MCFG4) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG4_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG4) Register Mask  */


/* -------- MATRIX_MCFG5 : (MATRIX Offset: 0x14) (R/W 32) Master Configuration Register 5 -------- */
#define MATRIX_MCFG5_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG5) Undefined Length Burst Type Position */
#define MATRIX_MCFG5_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG5_ULBT_Pos)                  /**< (MATRIX_MCFG5) Undefined Length Burst Type Mask */
#define MATRIX_MCFG5_ULBT(value)              (MATRIX_MCFG5_ULBT_Msk & ((value) << MATRIX_MCFG5_ULBT_Pos))
#define   MATRIX_MCFG5_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG5) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG5_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG5) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG5_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG5) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG5_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG5) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG5_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG5) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG5_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG5) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG5_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG5) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG5_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG5) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG5_ULBT_UNLIMITED           (MATRIX_MCFG5_ULBT_UNLIMITED_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG5_ULBT_SINGLE              (MATRIX_MCFG5_ULBT_SINGLE_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG5_ULBT_4_BEAT              (MATRIX_MCFG5_ULBT_4_BEAT_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG5_ULBT_8_BEAT              (MATRIX_MCFG5_ULBT_8_BEAT_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG5_ULBT_16_BEAT             (MATRIX_MCFG5_ULBT_16_BEAT_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG5_ULBT_32_BEAT             (MATRIX_MCFG5_ULBT_32_BEAT_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG5_ULBT_64_BEAT             (MATRIX_MCFG5_ULBT_64_BEAT_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG5_ULBT_128_BEAT            (MATRIX_MCFG5_ULBT_128_BEAT_Val << MATRIX_MCFG5_ULBT_Pos) /**< (MATRIX_MCFG5) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG5_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG5) Register Mask  */


/* -------- MATRIX_MCFG6 : (MATRIX Offset: 0x18) (R/W 32) Master Configuration Register 6 -------- */
#define MATRIX_MCFG6_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG6) Undefined Length Burst Type Position */
#define MATRIX_MCFG6_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG6_ULBT_Pos)                  /**< (MATRIX_MCFG6) Undefined Length Burst Type Mask */
#define MATRIX_MCFG6_ULBT(value)              (MATRIX_MCFG6_ULBT_Msk & ((value) << MATRIX_MCFG6_ULBT_Pos))
#define   MATRIX_MCFG6_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG6) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG6_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG6) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG6_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG6) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG6_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG6) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG6_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG6) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG6_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG6) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG6_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG6) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG6_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG6) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG6_ULBT_UNLIMITED           (MATRIX_MCFG6_ULBT_UNLIMITED_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG6_ULBT_SINGLE              (MATRIX_MCFG6_ULBT_SINGLE_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG6_ULBT_4_BEAT              (MATRIX_MCFG6_ULBT_4_BEAT_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG6_ULBT_8_BEAT              (MATRIX_MCFG6_ULBT_8_BEAT_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG6_ULBT_16_BEAT             (MATRIX_MCFG6_ULBT_16_BEAT_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG6_ULBT_32_BEAT             (MATRIX_MCFG6_ULBT_32_BEAT_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG6_ULBT_64_BEAT             (MATRIX_MCFG6_ULBT_64_BEAT_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG6_ULBT_128_BEAT            (MATRIX_MCFG6_ULBT_128_BEAT_Val << MATRIX_MCFG6_ULBT_Pos) /**< (MATRIX_MCFG6) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG6_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG6) Register Mask  */


/* -------- MATRIX_MCFG7 : (MATRIX Offset: 0x1C) (R/W 32) Master Configuration Register 7 -------- */
#define MATRIX_MCFG7_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG7) Undefined Length Burst Type Position */
#define MATRIX_MCFG7_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG7_ULBT_Pos)                  /**< (MATRIX_MCFG7) Undefined Length Burst Type Mask */
#define MATRIX_MCFG7_ULBT(value)              (MATRIX_MCFG7_ULBT_Msk & ((value) << MATRIX_MCFG7_ULBT_Pos))
#define   MATRIX_MCFG7_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG7) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG7_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG7) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG7_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG7) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG7_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG7) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG7_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG7) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG7_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG7) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG7_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG7) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG7_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG7) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG7_ULBT_UNLIMITED           (MATRIX_MCFG7_ULBT_UNLIMITED_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG7_ULBT_SINGLE              (MATRIX_MCFG7_ULBT_SINGLE_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG7_ULBT_4_BEAT              (MATRIX_MCFG7_ULBT_4_BEAT_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG7_ULBT_8_BEAT              (MATRIX_MCFG7_ULBT_8_BEAT_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG7_ULBT_16_BEAT             (MATRIX_MCFG7_ULBT_16_BEAT_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG7_ULBT_32_BEAT             (MATRIX_MCFG7_ULBT_32_BEAT_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG7_ULBT_64_BEAT             (MATRIX_MCFG7_ULBT_64_BEAT_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG7_ULBT_128_BEAT            (MATRIX_MCFG7_ULBT_128_BEAT_Val << MATRIX_MCFG7_ULBT_Pos) /**< (MATRIX_MCFG7) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG7_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG7) Register Mask  */


/* -------- MATRIX_MCFG8 : (MATRIX Offset: 0x20) (R/W 32) Master Configuration Register 8 -------- */
#define MATRIX_MCFG8_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG8) Undefined Length Burst Type Position */
#define MATRIX_MCFG8_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG8_ULBT_Pos)                  /**< (MATRIX_MCFG8) Undefined Length Burst Type Mask */
#define MATRIX_MCFG8_ULBT(value)              (MATRIX_MCFG8_ULBT_Msk & ((value) << MATRIX_MCFG8_ULBT_Pos))
#define   MATRIX_MCFG8_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG8) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG8_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG8) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG8_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG8) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG8_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG8) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG8_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG8) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG8_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG8) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG8_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG8) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG8_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG8) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG8_ULBT_UNLIMITED           (MATRIX_MCFG8_ULBT_UNLIMITED_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG8_ULBT_SINGLE              (MATRIX_MCFG8_ULBT_SINGLE_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG8_ULBT_4_BEAT              (MATRIX_MCFG8_ULBT_4_BEAT_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG8_ULBT_8_BEAT              (MATRIX_MCFG8_ULBT_8_BEAT_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG8_ULBT_16_BEAT             (MATRIX_MCFG8_ULBT_16_BEAT_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG8_ULBT_32_BEAT             (MATRIX_MCFG8_ULBT_32_BEAT_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG8_ULBT_64_BEAT             (MATRIX_MCFG8_ULBT_64_BEAT_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG8_ULBT_128_BEAT            (MATRIX_MCFG8_ULBT_128_BEAT_Val << MATRIX_MCFG8_ULBT_Pos) /**< (MATRIX_MCFG8) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG8_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG8) Register Mask  */


/* -------- MATRIX_MCFG9 : (MATRIX Offset: 0x24) (R/W 32) Master Configuration Register 9 -------- */
#define MATRIX_MCFG9_ULBT_Pos                 _U_(0)                                               /**< (MATRIX_MCFG9) Undefined Length Burst Type Position */
#define MATRIX_MCFG9_ULBT_Msk                 (_U_(0x7) << MATRIX_MCFG9_ULBT_Pos)                  /**< (MATRIX_MCFG9) Undefined Length Burst Type Mask */
#define MATRIX_MCFG9_ULBT(value)              (MATRIX_MCFG9_ULBT_Msk & ((value) << MATRIX_MCFG9_ULBT_Pos))
#define   MATRIX_MCFG9_ULBT_UNLIMITED_Val     _U_(0x0)                                             /**< (MATRIX_MCFG9) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG9_ULBT_SINGLE_Val        _U_(0x1)                                             /**< (MATRIX_MCFG9) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG9_ULBT_4_BEAT_Val        _U_(0x2)                                             /**< (MATRIX_MCFG9) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG9_ULBT_8_BEAT_Val        _U_(0x3)                                             /**< (MATRIX_MCFG9) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG9_ULBT_16_BEAT_Val       _U_(0x4)                                             /**< (MATRIX_MCFG9) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG9_ULBT_32_BEAT_Val       _U_(0x5)                                             /**< (MATRIX_MCFG9) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG9_ULBT_64_BEAT_Val       _U_(0x6)                                             /**< (MATRIX_MCFG9) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG9_ULBT_128_BEAT_Val      _U_(0x7)                                             /**< (MATRIX_MCFG9) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG9_ULBT_UNLIMITED           (MATRIX_MCFG9_ULBT_UNLIMITED_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG9_ULBT_SINGLE              (MATRIX_MCFG9_ULBT_SINGLE_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG9_ULBT_4_BEAT              (MATRIX_MCFG9_ULBT_4_BEAT_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG9_ULBT_8_BEAT              (MATRIX_MCFG9_ULBT_8_BEAT_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG9_ULBT_16_BEAT             (MATRIX_MCFG9_ULBT_16_BEAT_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG9_ULBT_32_BEAT             (MATRIX_MCFG9_ULBT_32_BEAT_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG9_ULBT_64_BEAT             (MATRIX_MCFG9_ULBT_64_BEAT_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG9_ULBT_128_BEAT            (MATRIX_MCFG9_ULBT_128_BEAT_Val << MATRIX_MCFG9_ULBT_Pos) /**< (MATRIX_MCFG9) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG9_Msk                      _U_(0x00000007)                                      /**< (MATRIX_MCFG9) Register Mask  */


/* -------- MATRIX_MCFG10 : (MATRIX Offset: 0x28) (R/W 32) Master Configuration Register 10 -------- */
#define MATRIX_MCFG10_ULBT_Pos                _U_(0)                                               /**< (MATRIX_MCFG10) Undefined Length Burst Type Position */
#define MATRIX_MCFG10_ULBT_Msk                (_U_(0x7) << MATRIX_MCFG10_ULBT_Pos)                 /**< (MATRIX_MCFG10) Undefined Length Burst Type Mask */
#define MATRIX_MCFG10_ULBT(value)             (MATRIX_MCFG10_ULBT_Msk & ((value) << MATRIX_MCFG10_ULBT_Pos))
#define   MATRIX_MCFG10_ULBT_UNLIMITED_Val    _U_(0x0)                                             /**< (MATRIX_MCFG10) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG10_ULBT_SINGLE_Val       _U_(0x1)                                             /**< (MATRIX_MCFG10) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG10_ULBT_4_BEAT_Val       _U_(0x2)                                             /**< (MATRIX_MCFG10) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG10_ULBT_8_BEAT_Val       _U_(0x3)                                             /**< (MATRIX_MCFG10) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG10_ULBT_16_BEAT_Val      _U_(0x4)                                             /**< (MATRIX_MCFG10) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG10_ULBT_32_BEAT_Val      _U_(0x5)                                             /**< (MATRIX_MCFG10) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG10_ULBT_64_BEAT_Val      _U_(0x6)                                             /**< (MATRIX_MCFG10) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG10_ULBT_128_BEAT_Val     _U_(0x7)                                             /**< (MATRIX_MCFG10) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG10_ULBT_UNLIMITED          (MATRIX_MCFG10_ULBT_UNLIMITED_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG10_ULBT_SINGLE             (MATRIX_MCFG10_ULBT_SINGLE_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG10_ULBT_4_BEAT             (MATRIX_MCFG10_ULBT_4_BEAT_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG10_ULBT_8_BEAT             (MATRIX_MCFG10_ULBT_8_BEAT_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG10_ULBT_16_BEAT            (MATRIX_MCFG10_ULBT_16_BEAT_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG10_ULBT_32_BEAT            (MATRIX_MCFG10_ULBT_32_BEAT_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG10_ULBT_64_BEAT            (MATRIX_MCFG10_ULBT_64_BEAT_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG10_ULBT_128_BEAT           (MATRIX_MCFG10_ULBT_128_BEAT_Val << MATRIX_MCFG10_ULBT_Pos) /**< (MATRIX_MCFG10) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG10_Msk                     _U_(0x00000007)                                      /**< (MATRIX_MCFG10) Register Mask  */


/* -------- MATRIX_MCFG11 : (MATRIX Offset: 0x2C) (R/W 32) Master Configuration Register 11 -------- */
#define MATRIX_MCFG11_ULBT_Pos                _U_(0)                                               /**< (MATRIX_MCFG11) Undefined Length Burst Type Position */
#define MATRIX_MCFG11_ULBT_Msk                (_U_(0x7) << MATRIX_MCFG11_ULBT_Pos)                 /**< (MATRIX_MCFG11) Undefined Length Burst Type Mask */
#define MATRIX_MCFG11_ULBT(value)             (MATRIX_MCFG11_ULBT_Msk & ((value) << MATRIX_MCFG11_ULBT_Pos))
#define   MATRIX_MCFG11_ULBT_UNLIMITED_Val    _U_(0x0)                                             /**< (MATRIX_MCFG11) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG11_ULBT_SINGLE_Val       _U_(0x1)                                             /**< (MATRIX_MCFG11) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG11_ULBT_4_BEAT_Val       _U_(0x2)                                             /**< (MATRIX_MCFG11) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG11_ULBT_8_BEAT_Val       _U_(0x3)                                             /**< (MATRIX_MCFG11) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG11_ULBT_16_BEAT_Val      _U_(0x4)                                             /**< (MATRIX_MCFG11) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG11_ULBT_32_BEAT_Val      _U_(0x5)                                             /**< (MATRIX_MCFG11) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG11_ULBT_64_BEAT_Val      _U_(0x6)                                             /**< (MATRIX_MCFG11) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG11_ULBT_128_BEAT_Val     _U_(0x7)                                             /**< (MATRIX_MCFG11) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG11_ULBT_UNLIMITED          (MATRIX_MCFG11_ULBT_UNLIMITED_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG11_ULBT_SINGLE             (MATRIX_MCFG11_ULBT_SINGLE_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG11_ULBT_4_BEAT             (MATRIX_MCFG11_ULBT_4_BEAT_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG11_ULBT_8_BEAT             (MATRIX_MCFG11_ULBT_8_BEAT_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG11_ULBT_16_BEAT            (MATRIX_MCFG11_ULBT_16_BEAT_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG11_ULBT_32_BEAT            (MATRIX_MCFG11_ULBT_32_BEAT_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG11_ULBT_64_BEAT            (MATRIX_MCFG11_ULBT_64_BEAT_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG11_ULBT_128_BEAT           (MATRIX_MCFG11_ULBT_128_BEAT_Val << MATRIX_MCFG11_ULBT_Pos) /**< (MATRIX_MCFG11) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG11_Msk                     _U_(0x00000007)                                      /**< (MATRIX_MCFG11) Register Mask  */


/* -------- MATRIX_MCFG12 : (MATRIX Offset: 0x30) (R/W 32) Master Configuration Register 12 -------- */
#define MATRIX_MCFG12_ULBT_Pos                _U_(0)                                               /**< (MATRIX_MCFG12) Undefined Length Burst Type Position */
#define MATRIX_MCFG12_ULBT_Msk                (_U_(0x7) << MATRIX_MCFG12_ULBT_Pos)                 /**< (MATRIX_MCFG12) Undefined Length Burst Type Mask */
#define MATRIX_MCFG12_ULBT(value)             (MATRIX_MCFG12_ULBT_Msk & ((value) << MATRIX_MCFG12_ULBT_Pos))
#define   MATRIX_MCFG12_ULBT_UNLIMITED_Val    _U_(0x0)                                             /**< (MATRIX_MCFG12) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG12_ULBT_SINGLE_Val       _U_(0x1)                                             /**< (MATRIX_MCFG12) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG12_ULBT_4_BEAT_Val       _U_(0x2)                                             /**< (MATRIX_MCFG12) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG12_ULBT_8_BEAT_Val       _U_(0x3)                                             /**< (MATRIX_MCFG12) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG12_ULBT_16_BEAT_Val      _U_(0x4)                                             /**< (MATRIX_MCFG12) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG12_ULBT_32_BEAT_Val      _U_(0x5)                                             /**< (MATRIX_MCFG12) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG12_ULBT_64_BEAT_Val      _U_(0x6)                                             /**< (MATRIX_MCFG12) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG12_ULBT_128_BEAT_Val     _U_(0x7)                                             /**< (MATRIX_MCFG12) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG12_ULBT_UNLIMITED          (MATRIX_MCFG12_ULBT_UNLIMITED_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG12_ULBT_SINGLE             (MATRIX_MCFG12_ULBT_SINGLE_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG12_ULBT_4_BEAT             (MATRIX_MCFG12_ULBT_4_BEAT_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG12_ULBT_8_BEAT             (MATRIX_MCFG12_ULBT_8_BEAT_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG12_ULBT_16_BEAT            (MATRIX_MCFG12_ULBT_16_BEAT_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG12_ULBT_32_BEAT            (MATRIX_MCFG12_ULBT_32_BEAT_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG12_ULBT_64_BEAT            (MATRIX_MCFG12_ULBT_64_BEAT_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG12_ULBT_128_BEAT           (MATRIX_MCFG12_ULBT_128_BEAT_Val << MATRIX_MCFG12_ULBT_Pos) /**< (MATRIX_MCFG12) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG12_Msk                     _U_(0x00000007)                                      /**< (MATRIX_MCFG12) Register Mask  */


/* -------- MATRIX_MCFG13 : (MATRIX Offset: 0x34) (R/W 32) Master Configuration Register 13 -------- */
#define MATRIX_MCFG13_ULBT_Pos                _U_(0)                                               /**< (MATRIX_MCFG13) Undefined Length Burst Type Position */
#define MATRIX_MCFG13_ULBT_Msk                (_U_(0x7) << MATRIX_MCFG13_ULBT_Pos)                 /**< (MATRIX_MCFG13) Undefined Length Burst Type Mask */
#define MATRIX_MCFG13_ULBT(value)             (MATRIX_MCFG13_ULBT_Msk & ((value) << MATRIX_MCFG13_ULBT_Pos))
#define   MATRIX_MCFG13_ULBT_UNLIMITED_Val    _U_(0x0)                                             /**< (MATRIX_MCFG13) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG13_ULBT_SINGLE_Val       _U_(0x1)                                             /**< (MATRIX_MCFG13) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG13_ULBT_4_BEAT_Val       _U_(0x2)                                             /**< (MATRIX_MCFG13) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG13_ULBT_8_BEAT_Val       _U_(0x3)                                             /**< (MATRIX_MCFG13) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG13_ULBT_16_BEAT_Val      _U_(0x4)                                             /**< (MATRIX_MCFG13) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG13_ULBT_32_BEAT_Val      _U_(0x5)                                             /**< (MATRIX_MCFG13) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG13_ULBT_64_BEAT_Val      _U_(0x6)                                             /**< (MATRIX_MCFG13) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG13_ULBT_128_BEAT_Val     _U_(0x7)                                             /**< (MATRIX_MCFG13) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG13_ULBT_UNLIMITED          (MATRIX_MCFG13_ULBT_UNLIMITED_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG13_ULBT_SINGLE             (MATRIX_MCFG13_ULBT_SINGLE_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG13_ULBT_4_BEAT             (MATRIX_MCFG13_ULBT_4_BEAT_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG13_ULBT_8_BEAT             (MATRIX_MCFG13_ULBT_8_BEAT_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG13_ULBT_16_BEAT            (MATRIX_MCFG13_ULBT_16_BEAT_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG13_ULBT_32_BEAT            (MATRIX_MCFG13_ULBT_32_BEAT_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG13_ULBT_64_BEAT            (MATRIX_MCFG13_ULBT_64_BEAT_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG13_ULBT_128_BEAT           (MATRIX_MCFG13_ULBT_128_BEAT_Val << MATRIX_MCFG13_ULBT_Pos) /**< (MATRIX_MCFG13) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG13_Msk                     _U_(0x00000007)                                      /**< (MATRIX_MCFG13) Register Mask  */


/* -------- MATRIX_MCFG14 : (MATRIX Offset: 0x38) (R/W 32) Master Configuration Register 14 -------- */
#define MATRIX_MCFG14_ULBT_Pos                _U_(0)                                               /**< (MATRIX_MCFG14) Undefined Length Burst Type Position */
#define MATRIX_MCFG14_ULBT_Msk                (_U_(0x7) << MATRIX_MCFG14_ULBT_Pos)                 /**< (MATRIX_MCFG14) Undefined Length Burst Type Mask */
#define MATRIX_MCFG14_ULBT(value)             (MATRIX_MCFG14_ULBT_Msk & ((value) << MATRIX_MCFG14_ULBT_Pos))
#define   MATRIX_MCFG14_ULBT_UNLIMITED_Val    _U_(0x0)                                             /**< (MATRIX_MCFG14) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG14_ULBT_SINGLE_Val       _U_(0x1)                                             /**< (MATRIX_MCFG14) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG14_ULBT_4_BEAT_Val       _U_(0x2)                                             /**< (MATRIX_MCFG14) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG14_ULBT_8_BEAT_Val       _U_(0x3)                                             /**< (MATRIX_MCFG14) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG14_ULBT_16_BEAT_Val      _U_(0x4)                                             /**< (MATRIX_MCFG14) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG14_ULBT_32_BEAT_Val      _U_(0x5)                                             /**< (MATRIX_MCFG14) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG14_ULBT_64_BEAT_Val      _U_(0x6)                                             /**< (MATRIX_MCFG14) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG14_ULBT_128_BEAT_Val     _U_(0x7)                                             /**< (MATRIX_MCFG14) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG14_ULBT_UNLIMITED          (MATRIX_MCFG14_ULBT_UNLIMITED_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG14_ULBT_SINGLE             (MATRIX_MCFG14_ULBT_SINGLE_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG14_ULBT_4_BEAT             (MATRIX_MCFG14_ULBT_4_BEAT_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG14_ULBT_8_BEAT             (MATRIX_MCFG14_ULBT_8_BEAT_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG14_ULBT_16_BEAT            (MATRIX_MCFG14_ULBT_16_BEAT_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG14_ULBT_32_BEAT            (MATRIX_MCFG14_ULBT_32_BEAT_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG14_ULBT_64_BEAT            (MATRIX_MCFG14_ULBT_64_BEAT_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG14_ULBT_128_BEAT           (MATRIX_MCFG14_ULBT_128_BEAT_Val << MATRIX_MCFG14_ULBT_Pos) /**< (MATRIX_MCFG14) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG14_Msk                     _U_(0x00000007)                                      /**< (MATRIX_MCFG14) Register Mask  */


/* -------- MATRIX_MCFG15 : (MATRIX Offset: 0x3C) (R/W 32) Master Configuration Register 15 -------- */
#define MATRIX_MCFG15_ULBT_Pos                _U_(0)                                               /**< (MATRIX_MCFG15) Undefined Length Burst Type Position */
#define MATRIX_MCFG15_ULBT_Msk                (_U_(0x7) << MATRIX_MCFG15_ULBT_Pos)                 /**< (MATRIX_MCFG15) Undefined Length Burst Type Mask */
#define MATRIX_MCFG15_ULBT(value)             (MATRIX_MCFG15_ULBT_Msk & ((value) << MATRIX_MCFG15_ULBT_Pos))
#define   MATRIX_MCFG15_ULBT_UNLIMITED_Val    _U_(0x0)                                             /**< (MATRIX_MCFG15) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave.  */
#define   MATRIX_MCFG15_ULBT_SINGLE_Val       _U_(0x1)                                             /**< (MATRIX_MCFG15) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence.  */
#define   MATRIX_MCFG15_ULBT_4_BEAT_Val       _U_(0x2)                                             /**< (MATRIX_MCFG15) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats.  */
#define   MATRIX_MCFG15_ULBT_8_BEAT_Val       _U_(0x3)                                             /**< (MATRIX_MCFG15) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats.  */
#define   MATRIX_MCFG15_ULBT_16_BEAT_Val      _U_(0x4)                                             /**< (MATRIX_MCFG15) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats.  */
#define   MATRIX_MCFG15_ULBT_32_BEAT_Val      _U_(0x5)                                             /**< (MATRIX_MCFG15) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats.  */
#define   MATRIX_MCFG15_ULBT_64_BEAT_Val      _U_(0x6)                                             /**< (MATRIX_MCFG15) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats.  */
#define   MATRIX_MCFG15_ULBT_128_BEAT_Val     _U_(0x7)                                             /**< (MATRIX_MCFG15) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving.  */
#define MATRIX_MCFG15_ULBT_UNLIMITED          (MATRIX_MCFG15_ULBT_UNLIMITED_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) Unlimited Length Burst-No predicted end of burst is generated, therefore INCR bursts coming from this master can only be broken if the Slave Slot Cycle Limit is reached. If the Slot Cycle Limit is not reached, the burst is normally completed by the master, at the latest, on the next AHB 1 Kbyte address boundary, allowing up to 256-beat word bursts or 128-beat double-word bursts.This value should not be used in the very particular case of a master capable of performing back-to-back undefined length bursts on a single slave, since this could indefinitely freeze the slave arbitration and thus prevent another master from accessing this slave. Position  */
#define MATRIX_MCFG15_ULBT_SINGLE             (MATRIX_MCFG15_ULBT_SINGLE_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) Single Access-The undefined length burst is treated as a succession of single accesses, allowing re-arbitration at each beat of the INCR burst or bursts sequence. Position  */
#define MATRIX_MCFG15_ULBT_4_BEAT             (MATRIX_MCFG15_ULBT_4_BEAT_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) 4-beat Burst-The undefined length burst or bursts sequence is split into 4-beat bursts or less, allowing re-arbitration every 4 beats. Position  */
#define MATRIX_MCFG15_ULBT_8_BEAT             (MATRIX_MCFG15_ULBT_8_BEAT_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) 8-beat Burst-The undefined length burst or bursts sequence is split into 8-beat bursts or less, allowing re-arbitration every 8 beats. Position  */
#define MATRIX_MCFG15_ULBT_16_BEAT            (MATRIX_MCFG15_ULBT_16_BEAT_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) 16-beat Burst-The undefined length burst or bursts sequence is split into 16-beat bursts or less, allowing re-arbitration every 16 beats. Position  */
#define MATRIX_MCFG15_ULBT_32_BEAT            (MATRIX_MCFG15_ULBT_32_BEAT_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) 32-beat Burst-The undefined length burst or bursts sequence is split into 32-beat bursts or less, allowing re-arbitration every 32 beats. Position  */
#define MATRIX_MCFG15_ULBT_64_BEAT            (MATRIX_MCFG15_ULBT_64_BEAT_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) 64-beat Burst-The undefined length burst or bursts sequence is split into 64-beat bursts or less, allowing re-arbitration every 64 beats. Position  */
#define MATRIX_MCFG15_ULBT_128_BEAT           (MATRIX_MCFG15_ULBT_128_BEAT_Val << MATRIX_MCFG15_ULBT_Pos) /**< (MATRIX_MCFG15) 128-beat Burst-The undefined length burst or bursts sequence is split into 128-beat bursts or less, allowing re-arbitration every 128 beats.Unless duly needed, the ULBT should be left at its default 0 value for power saving. Position  */
#define MATRIX_MCFG15_Msk                     _U_(0x00000007)                                      /**< (MATRIX_MCFG15) Register Mask  */


/* -------- MATRIX_SCFG0 : (MATRIX Offset: 0x40) (R/W 32) Slave Configuration Register 0 -------- */
#define MATRIX_SCFG0_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG0) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG0_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG0_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG0) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG0_SLOT_CYCLE(value)        (MATRIX_SCFG0_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG0_SLOT_CYCLE_Pos))
#define MATRIX_SCFG0_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG0) Default Master Type Position */
#define MATRIX_SCFG0_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG0_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG0) Default Master Type Mask */
#define MATRIX_SCFG0_DEFMSTR_TYPE(value)      (MATRIX_SCFG0_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG0_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG0_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG0) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG0_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG0) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG0_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG0) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG0_DEFMSTR_TYPE_NONE        (MATRIX_SCFG0_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG0_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG0) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG0_DEFMSTR_TYPE_LAST        (MATRIX_SCFG0_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG0_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG0) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG0_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG0_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG0_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG0) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG0_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG0) Fixed Default Master Position */
#define MATRIX_SCFG0_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG0_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG0) Fixed Default Master Mask */
#define MATRIX_SCFG0_FIXED_DEFMSTR(value)     (MATRIX_SCFG0_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG0_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG0_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG0) Register Mask  */


/* -------- MATRIX_SCFG1 : (MATRIX Offset: 0x44) (R/W 32) Slave Configuration Register 1 -------- */
#define MATRIX_SCFG1_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG1) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG1_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG1_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG1) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG1_SLOT_CYCLE(value)        (MATRIX_SCFG1_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG1_SLOT_CYCLE_Pos))
#define MATRIX_SCFG1_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG1) Default Master Type Position */
#define MATRIX_SCFG1_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG1_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG1) Default Master Type Mask */
#define MATRIX_SCFG1_DEFMSTR_TYPE(value)      (MATRIX_SCFG1_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG1_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG1_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG1) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG1_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG1) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG1_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG1) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG1_DEFMSTR_TYPE_NONE        (MATRIX_SCFG1_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG1_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG1) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG1_DEFMSTR_TYPE_LAST        (MATRIX_SCFG1_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG1_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG1) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG1_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG1_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG1_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG1) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG1_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG1) Fixed Default Master Position */
#define MATRIX_SCFG1_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG1_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG1) Fixed Default Master Mask */
#define MATRIX_SCFG1_FIXED_DEFMSTR(value)     (MATRIX_SCFG1_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG1_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG1_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG1) Register Mask  */


/* -------- MATRIX_SCFG2 : (MATRIX Offset: 0x48) (R/W 32) Slave Configuration Register 2 -------- */
#define MATRIX_SCFG2_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG2) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG2_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG2_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG2) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG2_SLOT_CYCLE(value)        (MATRIX_SCFG2_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG2_SLOT_CYCLE_Pos))
#define MATRIX_SCFG2_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG2) Default Master Type Position */
#define MATRIX_SCFG2_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG2_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG2) Default Master Type Mask */
#define MATRIX_SCFG2_DEFMSTR_TYPE(value)      (MATRIX_SCFG2_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG2_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG2_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG2) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG2_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG2) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG2_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG2) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG2_DEFMSTR_TYPE_NONE        (MATRIX_SCFG2_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG2_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG2) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG2_DEFMSTR_TYPE_LAST        (MATRIX_SCFG2_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG2_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG2) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG2_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG2_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG2_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG2) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG2_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG2) Fixed Default Master Position */
#define MATRIX_SCFG2_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG2_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG2) Fixed Default Master Mask */
#define MATRIX_SCFG2_FIXED_DEFMSTR(value)     (MATRIX_SCFG2_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG2_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG2_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG2) Register Mask  */


/* -------- MATRIX_SCFG3 : (MATRIX Offset: 0x4C) (R/W 32) Slave Configuration Register 3 -------- */
#define MATRIX_SCFG3_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG3) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG3_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG3_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG3) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG3_SLOT_CYCLE(value)        (MATRIX_SCFG3_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG3_SLOT_CYCLE_Pos))
#define MATRIX_SCFG3_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG3) Default Master Type Position */
#define MATRIX_SCFG3_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG3_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG3) Default Master Type Mask */
#define MATRIX_SCFG3_DEFMSTR_TYPE(value)      (MATRIX_SCFG3_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG3_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG3_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG3) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG3_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG3) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG3_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG3) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG3_DEFMSTR_TYPE_NONE        (MATRIX_SCFG3_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG3_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG3) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG3_DEFMSTR_TYPE_LAST        (MATRIX_SCFG3_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG3_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG3) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG3_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG3_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG3_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG3) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG3_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG3) Fixed Default Master Position */
#define MATRIX_SCFG3_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG3_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG3) Fixed Default Master Mask */
#define MATRIX_SCFG3_FIXED_DEFMSTR(value)     (MATRIX_SCFG3_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG3_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG3_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG3) Register Mask  */


/* -------- MATRIX_SCFG4 : (MATRIX Offset: 0x50) (R/W 32) Slave Configuration Register 4 -------- */
#define MATRIX_SCFG4_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG4) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG4_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG4_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG4) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG4_SLOT_CYCLE(value)        (MATRIX_SCFG4_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG4_SLOT_CYCLE_Pos))
#define MATRIX_SCFG4_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG4) Default Master Type Position */
#define MATRIX_SCFG4_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG4_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG4) Default Master Type Mask */
#define MATRIX_SCFG4_DEFMSTR_TYPE(value)      (MATRIX_SCFG4_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG4_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG4_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG4) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG4_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG4) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG4_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG4) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG4_DEFMSTR_TYPE_NONE        (MATRIX_SCFG4_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG4_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG4) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG4_DEFMSTR_TYPE_LAST        (MATRIX_SCFG4_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG4_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG4) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG4_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG4_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG4_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG4) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG4_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG4) Fixed Default Master Position */
#define MATRIX_SCFG4_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG4_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG4) Fixed Default Master Mask */
#define MATRIX_SCFG4_FIXED_DEFMSTR(value)     (MATRIX_SCFG4_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG4_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG4_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG4) Register Mask  */


/* -------- MATRIX_SCFG5 : (MATRIX Offset: 0x54) (R/W 32) Slave Configuration Register 5 -------- */
#define MATRIX_SCFG5_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG5) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG5_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG5_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG5) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG5_SLOT_CYCLE(value)        (MATRIX_SCFG5_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG5_SLOT_CYCLE_Pos))
#define MATRIX_SCFG5_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG5) Default Master Type Position */
#define MATRIX_SCFG5_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG5_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG5) Default Master Type Mask */
#define MATRIX_SCFG5_DEFMSTR_TYPE(value)      (MATRIX_SCFG5_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG5_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG5_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG5) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG5_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG5) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG5_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG5) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG5_DEFMSTR_TYPE_NONE        (MATRIX_SCFG5_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG5_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG5) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG5_DEFMSTR_TYPE_LAST        (MATRIX_SCFG5_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG5_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG5) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG5_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG5_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG5_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG5) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG5_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG5) Fixed Default Master Position */
#define MATRIX_SCFG5_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG5_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG5) Fixed Default Master Mask */
#define MATRIX_SCFG5_FIXED_DEFMSTR(value)     (MATRIX_SCFG5_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG5_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG5_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG5) Register Mask  */


/* -------- MATRIX_SCFG6 : (MATRIX Offset: 0x58) (R/W 32) Slave Configuration Register 6 -------- */
#define MATRIX_SCFG6_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG6) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG6_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG6_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG6) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG6_SLOT_CYCLE(value)        (MATRIX_SCFG6_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG6_SLOT_CYCLE_Pos))
#define MATRIX_SCFG6_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG6) Default Master Type Position */
#define MATRIX_SCFG6_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG6_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG6) Default Master Type Mask */
#define MATRIX_SCFG6_DEFMSTR_TYPE(value)      (MATRIX_SCFG6_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG6_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG6_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG6) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG6_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG6) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG6_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG6) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG6_DEFMSTR_TYPE_NONE        (MATRIX_SCFG6_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG6_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG6) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG6_DEFMSTR_TYPE_LAST        (MATRIX_SCFG6_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG6_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG6) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG6_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG6_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG6_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG6) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG6_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG6) Fixed Default Master Position */
#define MATRIX_SCFG6_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG6_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG6) Fixed Default Master Mask */
#define MATRIX_SCFG6_FIXED_DEFMSTR(value)     (MATRIX_SCFG6_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG6_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG6_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG6) Register Mask  */


/* -------- MATRIX_SCFG7 : (MATRIX Offset: 0x5C) (R/W 32) Slave Configuration Register 7 -------- */
#define MATRIX_SCFG7_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG7) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG7_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG7_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG7) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG7_SLOT_CYCLE(value)        (MATRIX_SCFG7_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG7_SLOT_CYCLE_Pos))
#define MATRIX_SCFG7_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG7) Default Master Type Position */
#define MATRIX_SCFG7_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG7_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG7) Default Master Type Mask */
#define MATRIX_SCFG7_DEFMSTR_TYPE(value)      (MATRIX_SCFG7_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG7_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG7_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG7) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG7_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG7) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG7_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG7) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG7_DEFMSTR_TYPE_NONE        (MATRIX_SCFG7_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG7_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG7) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG7_DEFMSTR_TYPE_LAST        (MATRIX_SCFG7_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG7_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG7) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG7_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG7_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG7_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG7) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG7_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG7) Fixed Default Master Position */
#define MATRIX_SCFG7_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG7_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG7) Fixed Default Master Mask */
#define MATRIX_SCFG7_FIXED_DEFMSTR(value)     (MATRIX_SCFG7_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG7_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG7_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG7) Register Mask  */


/* -------- MATRIX_SCFG8 : (MATRIX Offset: 0x60) (R/W 32) Slave Configuration Register 8 -------- */
#define MATRIX_SCFG8_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG8) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG8_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG8_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG8) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG8_SLOT_CYCLE(value)        (MATRIX_SCFG8_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG8_SLOT_CYCLE_Pos))
#define MATRIX_SCFG8_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG8) Default Master Type Position */
#define MATRIX_SCFG8_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG8_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG8) Default Master Type Mask */
#define MATRIX_SCFG8_DEFMSTR_TYPE(value)      (MATRIX_SCFG8_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG8_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG8_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG8) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG8_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG8) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG8_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG8) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG8_DEFMSTR_TYPE_NONE        (MATRIX_SCFG8_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG8_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG8) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG8_DEFMSTR_TYPE_LAST        (MATRIX_SCFG8_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG8_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG8) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG8_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG8_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG8_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG8) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG8_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG8) Fixed Default Master Position */
#define MATRIX_SCFG8_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG8_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG8) Fixed Default Master Mask */
#define MATRIX_SCFG8_FIXED_DEFMSTR(value)     (MATRIX_SCFG8_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG8_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG8_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG8) Register Mask  */


/* -------- MATRIX_SCFG9 : (MATRIX Offset: 0x64) (R/W 32) Slave Configuration Register 9 -------- */
#define MATRIX_SCFG9_SLOT_CYCLE_Pos           _U_(0)                                               /**< (MATRIX_SCFG9) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG9_SLOT_CYCLE_Msk           (_U_(0x1FF) << MATRIX_SCFG9_SLOT_CYCLE_Pos)          /**< (MATRIX_SCFG9) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG9_SLOT_CYCLE(value)        (MATRIX_SCFG9_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG9_SLOT_CYCLE_Pos))
#define MATRIX_SCFG9_DEFMSTR_TYPE_Pos         _U_(16)                                              /**< (MATRIX_SCFG9) Default Master Type Position */
#define MATRIX_SCFG9_DEFMSTR_TYPE_Msk         (_U_(0x3) << MATRIX_SCFG9_DEFMSTR_TYPE_Pos)          /**< (MATRIX_SCFG9) Default Master Type Mask */
#define MATRIX_SCFG9_DEFMSTR_TYPE(value)      (MATRIX_SCFG9_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG9_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG9_DEFMSTR_TYPE_NONE_Val  _U_(0x0)                                             /**< (MATRIX_SCFG9) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG9_DEFMSTR_TYPE_LAST_Val  _U_(0x1)                                             /**< (MATRIX_SCFG9) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG9_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG9) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG9_DEFMSTR_TYPE_NONE        (MATRIX_SCFG9_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG9_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG9) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG9_DEFMSTR_TYPE_LAST        (MATRIX_SCFG9_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG9_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG9) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG9_DEFMSTR_TYPE_FIXED       (MATRIX_SCFG9_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG9_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG9) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG9_FIXED_DEFMSTR_Pos        _U_(18)                                              /**< (MATRIX_SCFG9) Fixed Default Master Position */
#define MATRIX_SCFG9_FIXED_DEFMSTR_Msk        (_U_(0xF) << MATRIX_SCFG9_FIXED_DEFMSTR_Pos)         /**< (MATRIX_SCFG9) Fixed Default Master Mask */
#define MATRIX_SCFG9_FIXED_DEFMSTR(value)     (MATRIX_SCFG9_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG9_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG9_Msk                      _U_(0x003F01FF)                                      /**< (MATRIX_SCFG9) Register Mask  */


/* -------- MATRIX_SCFG10 : (MATRIX Offset: 0x68) (R/W 32) Slave Configuration Register 10 -------- */
#define MATRIX_SCFG10_SLOT_CYCLE_Pos          _U_(0)                                               /**< (MATRIX_SCFG10) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG10_SLOT_CYCLE_Msk          (_U_(0x1FF) << MATRIX_SCFG10_SLOT_CYCLE_Pos)         /**< (MATRIX_SCFG10) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG10_SLOT_CYCLE(value)       (MATRIX_SCFG10_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG10_SLOT_CYCLE_Pos))
#define MATRIX_SCFG10_DEFMSTR_TYPE_Pos        _U_(16)                                              /**< (MATRIX_SCFG10) Default Master Type Position */
#define MATRIX_SCFG10_DEFMSTR_TYPE_Msk        (_U_(0x3) << MATRIX_SCFG10_DEFMSTR_TYPE_Pos)         /**< (MATRIX_SCFG10) Default Master Type Mask */
#define MATRIX_SCFG10_DEFMSTR_TYPE(value)     (MATRIX_SCFG10_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG10_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG10_DEFMSTR_TYPE_NONE_Val _U_(0x0)                                             /**< (MATRIX_SCFG10) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG10_DEFMSTR_TYPE_LAST_Val _U_(0x1)                                             /**< (MATRIX_SCFG10) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG10_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG10) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG10_DEFMSTR_TYPE_NONE       (MATRIX_SCFG10_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG10_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG10) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG10_DEFMSTR_TYPE_LAST       (MATRIX_SCFG10_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG10_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG10) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG10_DEFMSTR_TYPE_FIXED      (MATRIX_SCFG10_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG10_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG10) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG10_FIXED_DEFMSTR_Pos       _U_(18)                                              /**< (MATRIX_SCFG10) Fixed Default Master Position */
#define MATRIX_SCFG10_FIXED_DEFMSTR_Msk       (_U_(0xF) << MATRIX_SCFG10_FIXED_DEFMSTR_Pos)        /**< (MATRIX_SCFG10) Fixed Default Master Mask */
#define MATRIX_SCFG10_FIXED_DEFMSTR(value)    (MATRIX_SCFG10_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG10_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG10_Msk                     _U_(0x003F01FF)                                      /**< (MATRIX_SCFG10) Register Mask  */


/* -------- MATRIX_SCFG11 : (MATRIX Offset: 0x6C) (R/W 32) Slave Configuration Register 11 -------- */
#define MATRIX_SCFG11_SLOT_CYCLE_Pos          _U_(0)                                               /**< (MATRIX_SCFG11) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG11_SLOT_CYCLE_Msk          (_U_(0x1FF) << MATRIX_SCFG11_SLOT_CYCLE_Pos)         /**< (MATRIX_SCFG11) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG11_SLOT_CYCLE(value)       (MATRIX_SCFG11_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG11_SLOT_CYCLE_Pos))
#define MATRIX_SCFG11_DEFMSTR_TYPE_Pos        _U_(16)                                              /**< (MATRIX_SCFG11) Default Master Type Position */
#define MATRIX_SCFG11_DEFMSTR_TYPE_Msk        (_U_(0x3) << MATRIX_SCFG11_DEFMSTR_TYPE_Pos)         /**< (MATRIX_SCFG11) Default Master Type Mask */
#define MATRIX_SCFG11_DEFMSTR_TYPE(value)     (MATRIX_SCFG11_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG11_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG11_DEFMSTR_TYPE_NONE_Val _U_(0x0)                                             /**< (MATRIX_SCFG11) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG11_DEFMSTR_TYPE_LAST_Val _U_(0x1)                                             /**< (MATRIX_SCFG11) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG11_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG11) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG11_DEFMSTR_TYPE_NONE       (MATRIX_SCFG11_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG11_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG11) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG11_DEFMSTR_TYPE_LAST       (MATRIX_SCFG11_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG11_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG11) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG11_DEFMSTR_TYPE_FIXED      (MATRIX_SCFG11_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG11_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG11) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG11_FIXED_DEFMSTR_Pos       _U_(18)                                              /**< (MATRIX_SCFG11) Fixed Default Master Position */
#define MATRIX_SCFG11_FIXED_DEFMSTR_Msk       (_U_(0xF) << MATRIX_SCFG11_FIXED_DEFMSTR_Pos)        /**< (MATRIX_SCFG11) Fixed Default Master Mask */
#define MATRIX_SCFG11_FIXED_DEFMSTR(value)    (MATRIX_SCFG11_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG11_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG11_Msk                     _U_(0x003F01FF)                                      /**< (MATRIX_SCFG11) Register Mask  */


/* -------- MATRIX_SCFG12 : (MATRIX Offset: 0x70) (R/W 32) Slave Configuration Register 12 -------- */
#define MATRIX_SCFG12_SLOT_CYCLE_Pos          _U_(0)                                               /**< (MATRIX_SCFG12) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG12_SLOT_CYCLE_Msk          (_U_(0x1FF) << MATRIX_SCFG12_SLOT_CYCLE_Pos)         /**< (MATRIX_SCFG12) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG12_SLOT_CYCLE(value)       (MATRIX_SCFG12_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG12_SLOT_CYCLE_Pos))
#define MATRIX_SCFG12_DEFMSTR_TYPE_Pos        _U_(16)                                              /**< (MATRIX_SCFG12) Default Master Type Position */
#define MATRIX_SCFG12_DEFMSTR_TYPE_Msk        (_U_(0x3) << MATRIX_SCFG12_DEFMSTR_TYPE_Pos)         /**< (MATRIX_SCFG12) Default Master Type Mask */
#define MATRIX_SCFG12_DEFMSTR_TYPE(value)     (MATRIX_SCFG12_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG12_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG12_DEFMSTR_TYPE_NONE_Val _U_(0x0)                                             /**< (MATRIX_SCFG12) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG12_DEFMSTR_TYPE_LAST_Val _U_(0x1)                                             /**< (MATRIX_SCFG12) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG12_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG12) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG12_DEFMSTR_TYPE_NONE       (MATRIX_SCFG12_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG12_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG12) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG12_DEFMSTR_TYPE_LAST       (MATRIX_SCFG12_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG12_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG12) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG12_DEFMSTR_TYPE_FIXED      (MATRIX_SCFG12_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG12_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG12) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG12_FIXED_DEFMSTR_Pos       _U_(18)                                              /**< (MATRIX_SCFG12) Fixed Default Master Position */
#define MATRIX_SCFG12_FIXED_DEFMSTR_Msk       (_U_(0xF) << MATRIX_SCFG12_FIXED_DEFMSTR_Pos)        /**< (MATRIX_SCFG12) Fixed Default Master Mask */
#define MATRIX_SCFG12_FIXED_DEFMSTR(value)    (MATRIX_SCFG12_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG12_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG12_Msk                     _U_(0x003F01FF)                                      /**< (MATRIX_SCFG12) Register Mask  */


/* -------- MATRIX_SCFG13 : (MATRIX Offset: 0x74) (R/W 32) Slave Configuration Register 13 -------- */
#define MATRIX_SCFG13_SLOT_CYCLE_Pos          _U_(0)                                               /**< (MATRIX_SCFG13) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG13_SLOT_CYCLE_Msk          (_U_(0x1FF) << MATRIX_SCFG13_SLOT_CYCLE_Pos)         /**< (MATRIX_SCFG13) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG13_SLOT_CYCLE(value)       (MATRIX_SCFG13_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG13_SLOT_CYCLE_Pos))
#define MATRIX_SCFG13_DEFMSTR_TYPE_Pos        _U_(16)                                              /**< (MATRIX_SCFG13) Default Master Type Position */
#define MATRIX_SCFG13_DEFMSTR_TYPE_Msk        (_U_(0x3) << MATRIX_SCFG13_DEFMSTR_TYPE_Pos)         /**< (MATRIX_SCFG13) Default Master Type Mask */
#define MATRIX_SCFG13_DEFMSTR_TYPE(value)     (MATRIX_SCFG13_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG13_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG13_DEFMSTR_TYPE_NONE_Val _U_(0x0)                                             /**< (MATRIX_SCFG13) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG13_DEFMSTR_TYPE_LAST_Val _U_(0x1)                                             /**< (MATRIX_SCFG13) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG13_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG13) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG13_DEFMSTR_TYPE_NONE       (MATRIX_SCFG13_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG13_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG13) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG13_DEFMSTR_TYPE_LAST       (MATRIX_SCFG13_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG13_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG13) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG13_DEFMSTR_TYPE_FIXED      (MATRIX_SCFG13_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG13_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG13) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG13_FIXED_DEFMSTR_Pos       _U_(18)                                              /**< (MATRIX_SCFG13) Fixed Default Master Position */
#define MATRIX_SCFG13_FIXED_DEFMSTR_Msk       (_U_(0xF) << MATRIX_SCFG13_FIXED_DEFMSTR_Pos)        /**< (MATRIX_SCFG13) Fixed Default Master Mask */
#define MATRIX_SCFG13_FIXED_DEFMSTR(value)    (MATRIX_SCFG13_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG13_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG13_Msk                     _U_(0x003F01FF)                                      /**< (MATRIX_SCFG13) Register Mask  */


/* -------- MATRIX_SCFG14 : (MATRIX Offset: 0x78) (R/W 32) Slave Configuration Register 14 -------- */
#define MATRIX_SCFG14_SLOT_CYCLE_Pos          _U_(0)                                               /**< (MATRIX_SCFG14) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG14_SLOT_CYCLE_Msk          (_U_(0x1FF) << MATRIX_SCFG14_SLOT_CYCLE_Pos)         /**< (MATRIX_SCFG14) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG14_SLOT_CYCLE(value)       (MATRIX_SCFG14_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG14_SLOT_CYCLE_Pos))
#define MATRIX_SCFG14_DEFMSTR_TYPE_Pos        _U_(16)                                              /**< (MATRIX_SCFG14) Default Master Type Position */
#define MATRIX_SCFG14_DEFMSTR_TYPE_Msk        (_U_(0x3) << MATRIX_SCFG14_DEFMSTR_TYPE_Pos)         /**< (MATRIX_SCFG14) Default Master Type Mask */
#define MATRIX_SCFG14_DEFMSTR_TYPE(value)     (MATRIX_SCFG14_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG14_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG14_DEFMSTR_TYPE_NONE_Val _U_(0x0)                                             /**< (MATRIX_SCFG14) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG14_DEFMSTR_TYPE_LAST_Val _U_(0x1)                                             /**< (MATRIX_SCFG14) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG14_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG14) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG14_DEFMSTR_TYPE_NONE       (MATRIX_SCFG14_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG14_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG14) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG14_DEFMSTR_TYPE_LAST       (MATRIX_SCFG14_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG14_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG14) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG14_DEFMSTR_TYPE_FIXED      (MATRIX_SCFG14_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG14_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG14) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG14_FIXED_DEFMSTR_Pos       _U_(18)                                              /**< (MATRIX_SCFG14) Fixed Default Master Position */
#define MATRIX_SCFG14_FIXED_DEFMSTR_Msk       (_U_(0xF) << MATRIX_SCFG14_FIXED_DEFMSTR_Pos)        /**< (MATRIX_SCFG14) Fixed Default Master Mask */
#define MATRIX_SCFG14_FIXED_DEFMSTR(value)    (MATRIX_SCFG14_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG14_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG14_Msk                     _U_(0x003F01FF)                                      /**< (MATRIX_SCFG14) Register Mask  */


/* -------- MATRIX_SCFG15 : (MATRIX Offset: 0x7C) (R/W 32) Slave Configuration Register 15 -------- */
#define MATRIX_SCFG15_SLOT_CYCLE_Pos          _U_(0)                                               /**< (MATRIX_SCFG15) Maximum Bus Grant Duration for Masters Position */
#define MATRIX_SCFG15_SLOT_CYCLE_Msk          (_U_(0x1FF) << MATRIX_SCFG15_SLOT_CYCLE_Pos)         /**< (MATRIX_SCFG15) Maximum Bus Grant Duration for Masters Mask */
#define MATRIX_SCFG15_SLOT_CYCLE(value)       (MATRIX_SCFG15_SLOT_CYCLE_Msk & ((value) << MATRIX_SCFG15_SLOT_CYCLE_Pos))
#define MATRIX_SCFG15_DEFMSTR_TYPE_Pos        _U_(16)                                              /**< (MATRIX_SCFG15) Default Master Type Position */
#define MATRIX_SCFG15_DEFMSTR_TYPE_Msk        (_U_(0x3) << MATRIX_SCFG15_DEFMSTR_TYPE_Pos)         /**< (MATRIX_SCFG15) Default Master Type Mask */
#define MATRIX_SCFG15_DEFMSTR_TYPE(value)     (MATRIX_SCFG15_DEFMSTR_TYPE_Msk & ((value) << MATRIX_SCFG15_DEFMSTR_TYPE_Pos))
#define   MATRIX_SCFG15_DEFMSTR_TYPE_NONE_Val _U_(0x0)                                             /**< (MATRIX_SCFG15) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access.  */
#define   MATRIX_SCFG15_DEFMSTR_TYPE_LAST_Val _U_(0x1)                                             /**< (MATRIX_SCFG15) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again.  */
#define   MATRIX_SCFG15_DEFMSTR_TYPE_FIXED_Val _U_(0x2)                                             /**< (MATRIX_SCFG15) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again.  */
#define MATRIX_SCFG15_DEFMSTR_TYPE_NONE       (MATRIX_SCFG15_DEFMSTR_TYPE_NONE_Val << MATRIX_SCFG15_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG15) No Default Master-At the end of the current slave access, if no other master request is pending, the slave is disconnected from all masters.This results in a one clock cycle latency for the first access of a burst transfer or for a single access. Position  */
#define MATRIX_SCFG15_DEFMSTR_TYPE_LAST       (MATRIX_SCFG15_DEFMSTR_TYPE_LAST_Val << MATRIX_SCFG15_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG15) Last Default Master-At the end of the current slave access, if no other master request is pending, the slave stays connected to the last master having accessed it.This results in not having one clock cycle latency when the last master tries to access the slave again. Position  */
#define MATRIX_SCFG15_DEFMSTR_TYPE_FIXED      (MATRIX_SCFG15_DEFMSTR_TYPE_FIXED_Val << MATRIX_SCFG15_DEFMSTR_TYPE_Pos) /**< (MATRIX_SCFG15) Fixed Default Master-At the end of the current slave access, if no other master request is pending, the slave connects to the fixed master the number that has been written in the FIXED_DEFMSTR field.This results in not having one clock cycle latency when the fixed master tries to access the slave again. Position  */
#define MATRIX_SCFG15_FIXED_DEFMSTR_Pos       _U_(18)                                              /**< (MATRIX_SCFG15) Fixed Default Master Position */
#define MATRIX_SCFG15_FIXED_DEFMSTR_Msk       (_U_(0xF) << MATRIX_SCFG15_FIXED_DEFMSTR_Pos)        /**< (MATRIX_SCFG15) Fixed Default Master Mask */
#define MATRIX_SCFG15_FIXED_DEFMSTR(value)    (MATRIX_SCFG15_FIXED_DEFMSTR_Msk & ((value) << MATRIX_SCFG15_FIXED_DEFMSTR_Pos))
#define MATRIX_SCFG15_Msk                     _U_(0x003F01FF)                                      /**< (MATRIX_SCFG15) Register Mask  */


/* -------- MATRIX_PRAS0 : (MATRIX Offset: 0x80) (R/W 32) Priority Register A for Slave 0 -------- */
#define MATRIX_PRAS0_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS0) Master 0 Priority Position */
#define MATRIX_PRAS0_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M0PR_Pos)                  /**< (MATRIX_PRAS0) Master 0 Priority Mask */
#define MATRIX_PRAS0_M0PR(value)              (MATRIX_PRAS0_M0PR_Msk & ((value) << MATRIX_PRAS0_M0PR_Pos))
#define MATRIX_PRAS0_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS0_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN0_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS0_LQOSEN0(value)           (MATRIX_PRAS0_LQOSEN0_Msk & ((value) << MATRIX_PRAS0_LQOSEN0_Pos))
#define MATRIX_PRAS0_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS0) Master 1 Priority Position */
#define MATRIX_PRAS0_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M1PR_Pos)                  /**< (MATRIX_PRAS0) Master 1 Priority Mask */
#define MATRIX_PRAS0_M1PR(value)              (MATRIX_PRAS0_M1PR_Msk & ((value) << MATRIX_PRAS0_M1PR_Pos))
#define MATRIX_PRAS0_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS0_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN1_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS0_LQOSEN1(value)           (MATRIX_PRAS0_LQOSEN1_Msk & ((value) << MATRIX_PRAS0_LQOSEN1_Pos))
#define MATRIX_PRAS0_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS0) Master 2 Priority Position */
#define MATRIX_PRAS0_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M2PR_Pos)                  /**< (MATRIX_PRAS0) Master 2 Priority Mask */
#define MATRIX_PRAS0_M2PR(value)              (MATRIX_PRAS0_M2PR_Msk & ((value) << MATRIX_PRAS0_M2PR_Pos))
#define MATRIX_PRAS0_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS0_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN2_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS0_LQOSEN2(value)           (MATRIX_PRAS0_LQOSEN2_Msk & ((value) << MATRIX_PRAS0_LQOSEN2_Pos))
#define MATRIX_PRAS0_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS0) Master 3 Priority Position */
#define MATRIX_PRAS0_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M3PR_Pos)                  /**< (MATRIX_PRAS0) Master 3 Priority Mask */
#define MATRIX_PRAS0_M3PR(value)              (MATRIX_PRAS0_M3PR_Msk & ((value) << MATRIX_PRAS0_M3PR_Pos))
#define MATRIX_PRAS0_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS0_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN3_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS0_LQOSEN3(value)           (MATRIX_PRAS0_LQOSEN3_Msk & ((value) << MATRIX_PRAS0_LQOSEN3_Pos))
#define MATRIX_PRAS0_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS0) Master 4 Priority Position */
#define MATRIX_PRAS0_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M4PR_Pos)                  /**< (MATRIX_PRAS0) Master 4 Priority Mask */
#define MATRIX_PRAS0_M4PR(value)              (MATRIX_PRAS0_M4PR_Msk & ((value) << MATRIX_PRAS0_M4PR_Pos))
#define MATRIX_PRAS0_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS0_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN4_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS0_LQOSEN4(value)           (MATRIX_PRAS0_LQOSEN4_Msk & ((value) << MATRIX_PRAS0_LQOSEN4_Pos))
#define MATRIX_PRAS0_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS0) Master 5 Priority Position */
#define MATRIX_PRAS0_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M5PR_Pos)                  /**< (MATRIX_PRAS0) Master 5 Priority Mask */
#define MATRIX_PRAS0_M5PR(value)              (MATRIX_PRAS0_M5PR_Msk & ((value) << MATRIX_PRAS0_M5PR_Pos))
#define MATRIX_PRAS0_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS0_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN5_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS0_LQOSEN5(value)           (MATRIX_PRAS0_LQOSEN5_Msk & ((value) << MATRIX_PRAS0_LQOSEN5_Pos))
#define MATRIX_PRAS0_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS0) Master 6 Priority Position */
#define MATRIX_PRAS0_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M6PR_Pos)                  /**< (MATRIX_PRAS0) Master 6 Priority Mask */
#define MATRIX_PRAS0_M6PR(value)              (MATRIX_PRAS0_M6PR_Msk & ((value) << MATRIX_PRAS0_M6PR_Pos))
#define MATRIX_PRAS0_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS0_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN6_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS0_LQOSEN6(value)           (MATRIX_PRAS0_LQOSEN6_Msk & ((value) << MATRIX_PRAS0_LQOSEN6_Pos))
#define MATRIX_PRAS0_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS0) Master 7 Priority Position */
#define MATRIX_PRAS0_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS0_M7PR_Pos)                  /**< (MATRIX_PRAS0) Master 7 Priority Mask */
#define MATRIX_PRAS0_M7PR(value)              (MATRIX_PRAS0_M7PR_Msk & ((value) << MATRIX_PRAS0_M7PR_Pos))
#define MATRIX_PRAS0_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS0_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS0_LQOSEN7_Pos)               /**< (MATRIX_PRAS0) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS0_LQOSEN7(value)           (MATRIX_PRAS0_LQOSEN7_Msk & ((value) << MATRIX_PRAS0_LQOSEN7_Pos))
#define MATRIX_PRAS0_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS0) Register Mask  */


/* -------- MATRIX_PRBS0 : (MATRIX Offset: 0x84) (R/W 32) Priority Register B for Slave 0 -------- */
#define MATRIX_PRBS0_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS0) Master 8 Priority Position */
#define MATRIX_PRBS0_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS0_M8PR_Pos)                  /**< (MATRIX_PRBS0) Master 8 Priority Mask */
#define MATRIX_PRBS0_M8PR(value)              (MATRIX_PRBS0_M8PR_Msk & ((value) << MATRIX_PRBS0_M8PR_Pos))
#define MATRIX_PRBS0_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS0_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS0_LQOSEN8_Pos)               /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS0_LQOSEN8(value)           (MATRIX_PRBS0_LQOSEN8_Msk & ((value) << MATRIX_PRBS0_LQOSEN8_Pos))
#define MATRIX_PRBS0_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS0) Master 9 Priority Position */
#define MATRIX_PRBS0_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS0_M9PR_Pos)                  /**< (MATRIX_PRBS0) Master 9 Priority Mask */
#define MATRIX_PRBS0_M9PR(value)              (MATRIX_PRBS0_M9PR_Msk & ((value) << MATRIX_PRBS0_M9PR_Pos))
#define MATRIX_PRBS0_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS0_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS0_LQOSEN9_Pos)               /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS0_LQOSEN9(value)           (MATRIX_PRBS0_LQOSEN9_Msk & ((value) << MATRIX_PRBS0_LQOSEN9_Pos))
#define MATRIX_PRBS0_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS0) Master 10 Priority Position */
#define MATRIX_PRBS0_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS0_M10PR_Pos)                 /**< (MATRIX_PRBS0) Master 10 Priority Mask */
#define MATRIX_PRBS0_M10PR(value)             (MATRIX_PRBS0_M10PR_Msk & ((value) << MATRIX_PRBS0_M10PR_Pos))
#define MATRIX_PRBS0_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS0_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS0_LQOSEN10_Pos)              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS0_LQOSEN10(value)          (MATRIX_PRBS0_LQOSEN10_Msk & ((value) << MATRIX_PRBS0_LQOSEN10_Pos))
#define MATRIX_PRBS0_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS0) Master 11 Priority Position */
#define MATRIX_PRBS0_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS0_M11PR_Pos)                 /**< (MATRIX_PRBS0) Master 11 Priority Mask */
#define MATRIX_PRBS0_M11PR(value)             (MATRIX_PRBS0_M11PR_Msk & ((value) << MATRIX_PRBS0_M11PR_Pos))
#define MATRIX_PRBS0_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS0_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS0_LQOSEN11_Pos)              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS0_LQOSEN11(value)          (MATRIX_PRBS0_LQOSEN11_Msk & ((value) << MATRIX_PRBS0_LQOSEN11_Pos))
#define MATRIX_PRBS0_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS0) Master 12 Priority Position */
#define MATRIX_PRBS0_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS0_M12PR_Pos)                 /**< (MATRIX_PRBS0) Master 12 Priority Mask */
#define MATRIX_PRBS0_M12PR(value)             (MATRIX_PRBS0_M12PR_Msk & ((value) << MATRIX_PRBS0_M12PR_Pos))
#define MATRIX_PRBS0_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS0_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS0_LQOSEN12_Pos)              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS0_LQOSEN12(value)          (MATRIX_PRBS0_LQOSEN12_Msk & ((value) << MATRIX_PRBS0_LQOSEN12_Pos))
#define MATRIX_PRBS0_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS0) Master 13 Priority Position */
#define MATRIX_PRBS0_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS0_M13PR_Pos)                 /**< (MATRIX_PRBS0) Master 13 Priority Mask */
#define MATRIX_PRBS0_M13PR(value)             (MATRIX_PRBS0_M13PR_Msk & ((value) << MATRIX_PRBS0_M13PR_Pos))
#define MATRIX_PRBS0_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS0_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS0_LQOSEN13_Pos)              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS0_LQOSEN13(value)          (MATRIX_PRBS0_LQOSEN13_Msk & ((value) << MATRIX_PRBS0_LQOSEN13_Pos))
#define MATRIX_PRBS0_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS0) Master 14 Priority Position */
#define MATRIX_PRBS0_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS0_M14PR_Pos)                 /**< (MATRIX_PRBS0) Master 14 Priority Mask */
#define MATRIX_PRBS0_M14PR(value)             (MATRIX_PRBS0_M14PR_Msk & ((value) << MATRIX_PRBS0_M14PR_Pos))
#define MATRIX_PRBS0_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS0_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS0_LQOSEN14_Pos)              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS0_LQOSEN14(value)          (MATRIX_PRBS0_LQOSEN14_Msk & ((value) << MATRIX_PRBS0_LQOSEN14_Pos))
#define MATRIX_PRBS0_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS0) Master 15 Priority Position */
#define MATRIX_PRBS0_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS0_M15PR_Pos)                 /**< (MATRIX_PRBS0) Master 15 Priority Mask */
#define MATRIX_PRBS0_M15PR(value)             (MATRIX_PRBS0_M15PR_Msk & ((value) << MATRIX_PRBS0_M15PR_Pos))
#define MATRIX_PRBS0_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS0_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS0_LQOSEN15_Pos)              /**< (MATRIX_PRBS0) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS0_LQOSEN15(value)          (MATRIX_PRBS0_LQOSEN15_Msk & ((value) << MATRIX_PRBS0_LQOSEN15_Pos))
#define MATRIX_PRBS0_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS0) Register Mask  */


/* -------- MATRIX_PRAS1 : (MATRIX Offset: 0x88) (R/W 32) Priority Register A for Slave 1 -------- */
#define MATRIX_PRAS1_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS1) Master 0 Priority Position */
#define MATRIX_PRAS1_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M0PR_Pos)                  /**< (MATRIX_PRAS1) Master 0 Priority Mask */
#define MATRIX_PRAS1_M0PR(value)              (MATRIX_PRAS1_M0PR_Msk & ((value) << MATRIX_PRAS1_M0PR_Pos))
#define MATRIX_PRAS1_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS1_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN0_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS1_LQOSEN0(value)           (MATRIX_PRAS1_LQOSEN0_Msk & ((value) << MATRIX_PRAS1_LQOSEN0_Pos))
#define MATRIX_PRAS1_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS1) Master 1 Priority Position */
#define MATRIX_PRAS1_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M1PR_Pos)                  /**< (MATRIX_PRAS1) Master 1 Priority Mask */
#define MATRIX_PRAS1_M1PR(value)              (MATRIX_PRAS1_M1PR_Msk & ((value) << MATRIX_PRAS1_M1PR_Pos))
#define MATRIX_PRAS1_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS1_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN1_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS1_LQOSEN1(value)           (MATRIX_PRAS1_LQOSEN1_Msk & ((value) << MATRIX_PRAS1_LQOSEN1_Pos))
#define MATRIX_PRAS1_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS1) Master 2 Priority Position */
#define MATRIX_PRAS1_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M2PR_Pos)                  /**< (MATRIX_PRAS1) Master 2 Priority Mask */
#define MATRIX_PRAS1_M2PR(value)              (MATRIX_PRAS1_M2PR_Msk & ((value) << MATRIX_PRAS1_M2PR_Pos))
#define MATRIX_PRAS1_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS1_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN2_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS1_LQOSEN2(value)           (MATRIX_PRAS1_LQOSEN2_Msk & ((value) << MATRIX_PRAS1_LQOSEN2_Pos))
#define MATRIX_PRAS1_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS1) Master 3 Priority Position */
#define MATRIX_PRAS1_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M3PR_Pos)                  /**< (MATRIX_PRAS1) Master 3 Priority Mask */
#define MATRIX_PRAS1_M3PR(value)              (MATRIX_PRAS1_M3PR_Msk & ((value) << MATRIX_PRAS1_M3PR_Pos))
#define MATRIX_PRAS1_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS1_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN3_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS1_LQOSEN3(value)           (MATRIX_PRAS1_LQOSEN3_Msk & ((value) << MATRIX_PRAS1_LQOSEN3_Pos))
#define MATRIX_PRAS1_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS1) Master 4 Priority Position */
#define MATRIX_PRAS1_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M4PR_Pos)                  /**< (MATRIX_PRAS1) Master 4 Priority Mask */
#define MATRIX_PRAS1_M4PR(value)              (MATRIX_PRAS1_M4PR_Msk & ((value) << MATRIX_PRAS1_M4PR_Pos))
#define MATRIX_PRAS1_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS1_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN4_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS1_LQOSEN4(value)           (MATRIX_PRAS1_LQOSEN4_Msk & ((value) << MATRIX_PRAS1_LQOSEN4_Pos))
#define MATRIX_PRAS1_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS1) Master 5 Priority Position */
#define MATRIX_PRAS1_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M5PR_Pos)                  /**< (MATRIX_PRAS1) Master 5 Priority Mask */
#define MATRIX_PRAS1_M5PR(value)              (MATRIX_PRAS1_M5PR_Msk & ((value) << MATRIX_PRAS1_M5PR_Pos))
#define MATRIX_PRAS1_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS1_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN5_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS1_LQOSEN5(value)           (MATRIX_PRAS1_LQOSEN5_Msk & ((value) << MATRIX_PRAS1_LQOSEN5_Pos))
#define MATRIX_PRAS1_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS1) Master 6 Priority Position */
#define MATRIX_PRAS1_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M6PR_Pos)                  /**< (MATRIX_PRAS1) Master 6 Priority Mask */
#define MATRIX_PRAS1_M6PR(value)              (MATRIX_PRAS1_M6PR_Msk & ((value) << MATRIX_PRAS1_M6PR_Pos))
#define MATRIX_PRAS1_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS1_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN6_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS1_LQOSEN6(value)           (MATRIX_PRAS1_LQOSEN6_Msk & ((value) << MATRIX_PRAS1_LQOSEN6_Pos))
#define MATRIX_PRAS1_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS1) Master 7 Priority Position */
#define MATRIX_PRAS1_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS1_M7PR_Pos)                  /**< (MATRIX_PRAS1) Master 7 Priority Mask */
#define MATRIX_PRAS1_M7PR(value)              (MATRIX_PRAS1_M7PR_Msk & ((value) << MATRIX_PRAS1_M7PR_Pos))
#define MATRIX_PRAS1_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS1_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS1_LQOSEN7_Pos)               /**< (MATRIX_PRAS1) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS1_LQOSEN7(value)           (MATRIX_PRAS1_LQOSEN7_Msk & ((value) << MATRIX_PRAS1_LQOSEN7_Pos))
#define MATRIX_PRAS1_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS1) Register Mask  */


/* -------- MATRIX_PRBS1 : (MATRIX Offset: 0x8C) (R/W 32) Priority Register B for Slave 1 -------- */
#define MATRIX_PRBS1_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS1) Master 8 Priority Position */
#define MATRIX_PRBS1_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS1_M8PR_Pos)                  /**< (MATRIX_PRBS1) Master 8 Priority Mask */
#define MATRIX_PRBS1_M8PR(value)              (MATRIX_PRBS1_M8PR_Msk & ((value) << MATRIX_PRBS1_M8PR_Pos))
#define MATRIX_PRBS1_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS1_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS1_LQOSEN8_Pos)               /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS1_LQOSEN8(value)           (MATRIX_PRBS1_LQOSEN8_Msk & ((value) << MATRIX_PRBS1_LQOSEN8_Pos))
#define MATRIX_PRBS1_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS1) Master 9 Priority Position */
#define MATRIX_PRBS1_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS1_M9PR_Pos)                  /**< (MATRIX_PRBS1) Master 9 Priority Mask */
#define MATRIX_PRBS1_M9PR(value)              (MATRIX_PRBS1_M9PR_Msk & ((value) << MATRIX_PRBS1_M9PR_Pos))
#define MATRIX_PRBS1_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS1_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS1_LQOSEN9_Pos)               /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS1_LQOSEN9(value)           (MATRIX_PRBS1_LQOSEN9_Msk & ((value) << MATRIX_PRBS1_LQOSEN9_Pos))
#define MATRIX_PRBS1_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS1) Master 10 Priority Position */
#define MATRIX_PRBS1_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS1_M10PR_Pos)                 /**< (MATRIX_PRBS1) Master 10 Priority Mask */
#define MATRIX_PRBS1_M10PR(value)             (MATRIX_PRBS1_M10PR_Msk & ((value) << MATRIX_PRBS1_M10PR_Pos))
#define MATRIX_PRBS1_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS1_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS1_LQOSEN10_Pos)              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS1_LQOSEN10(value)          (MATRIX_PRBS1_LQOSEN10_Msk & ((value) << MATRIX_PRBS1_LQOSEN10_Pos))
#define MATRIX_PRBS1_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS1) Master 11 Priority Position */
#define MATRIX_PRBS1_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS1_M11PR_Pos)                 /**< (MATRIX_PRBS1) Master 11 Priority Mask */
#define MATRIX_PRBS1_M11PR(value)             (MATRIX_PRBS1_M11PR_Msk & ((value) << MATRIX_PRBS1_M11PR_Pos))
#define MATRIX_PRBS1_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS1_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS1_LQOSEN11_Pos)              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS1_LQOSEN11(value)          (MATRIX_PRBS1_LQOSEN11_Msk & ((value) << MATRIX_PRBS1_LQOSEN11_Pos))
#define MATRIX_PRBS1_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS1) Master 12 Priority Position */
#define MATRIX_PRBS1_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS1_M12PR_Pos)                 /**< (MATRIX_PRBS1) Master 12 Priority Mask */
#define MATRIX_PRBS1_M12PR(value)             (MATRIX_PRBS1_M12PR_Msk & ((value) << MATRIX_PRBS1_M12PR_Pos))
#define MATRIX_PRBS1_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS1_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS1_LQOSEN12_Pos)              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS1_LQOSEN12(value)          (MATRIX_PRBS1_LQOSEN12_Msk & ((value) << MATRIX_PRBS1_LQOSEN12_Pos))
#define MATRIX_PRBS1_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS1) Master 13 Priority Position */
#define MATRIX_PRBS1_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS1_M13PR_Pos)                 /**< (MATRIX_PRBS1) Master 13 Priority Mask */
#define MATRIX_PRBS1_M13PR(value)             (MATRIX_PRBS1_M13PR_Msk & ((value) << MATRIX_PRBS1_M13PR_Pos))
#define MATRIX_PRBS1_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS1_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS1_LQOSEN13_Pos)              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS1_LQOSEN13(value)          (MATRIX_PRBS1_LQOSEN13_Msk & ((value) << MATRIX_PRBS1_LQOSEN13_Pos))
#define MATRIX_PRBS1_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS1) Master 14 Priority Position */
#define MATRIX_PRBS1_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS1_M14PR_Pos)                 /**< (MATRIX_PRBS1) Master 14 Priority Mask */
#define MATRIX_PRBS1_M14PR(value)             (MATRIX_PRBS1_M14PR_Msk & ((value) << MATRIX_PRBS1_M14PR_Pos))
#define MATRIX_PRBS1_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS1_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS1_LQOSEN14_Pos)              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS1_LQOSEN14(value)          (MATRIX_PRBS1_LQOSEN14_Msk & ((value) << MATRIX_PRBS1_LQOSEN14_Pos))
#define MATRIX_PRBS1_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS1) Master 15 Priority Position */
#define MATRIX_PRBS1_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS1_M15PR_Pos)                 /**< (MATRIX_PRBS1) Master 15 Priority Mask */
#define MATRIX_PRBS1_M15PR(value)             (MATRIX_PRBS1_M15PR_Msk & ((value) << MATRIX_PRBS1_M15PR_Pos))
#define MATRIX_PRBS1_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS1_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS1_LQOSEN15_Pos)              /**< (MATRIX_PRBS1) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS1_LQOSEN15(value)          (MATRIX_PRBS1_LQOSEN15_Msk & ((value) << MATRIX_PRBS1_LQOSEN15_Pos))
#define MATRIX_PRBS1_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS1) Register Mask  */


/* -------- MATRIX_PRAS2 : (MATRIX Offset: 0x90) (R/W 32) Priority Register A for Slave 2 -------- */
#define MATRIX_PRAS2_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS2) Master 0 Priority Position */
#define MATRIX_PRAS2_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M0PR_Pos)                  /**< (MATRIX_PRAS2) Master 0 Priority Mask */
#define MATRIX_PRAS2_M0PR(value)              (MATRIX_PRAS2_M0PR_Msk & ((value) << MATRIX_PRAS2_M0PR_Pos))
#define MATRIX_PRAS2_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS2_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN0_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS2_LQOSEN0(value)           (MATRIX_PRAS2_LQOSEN0_Msk & ((value) << MATRIX_PRAS2_LQOSEN0_Pos))
#define MATRIX_PRAS2_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS2) Master 1 Priority Position */
#define MATRIX_PRAS2_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M1PR_Pos)                  /**< (MATRIX_PRAS2) Master 1 Priority Mask */
#define MATRIX_PRAS2_M1PR(value)              (MATRIX_PRAS2_M1PR_Msk & ((value) << MATRIX_PRAS2_M1PR_Pos))
#define MATRIX_PRAS2_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS2_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN1_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS2_LQOSEN1(value)           (MATRIX_PRAS2_LQOSEN1_Msk & ((value) << MATRIX_PRAS2_LQOSEN1_Pos))
#define MATRIX_PRAS2_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS2) Master 2 Priority Position */
#define MATRIX_PRAS2_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M2PR_Pos)                  /**< (MATRIX_PRAS2) Master 2 Priority Mask */
#define MATRIX_PRAS2_M2PR(value)              (MATRIX_PRAS2_M2PR_Msk & ((value) << MATRIX_PRAS2_M2PR_Pos))
#define MATRIX_PRAS2_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS2_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN2_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS2_LQOSEN2(value)           (MATRIX_PRAS2_LQOSEN2_Msk & ((value) << MATRIX_PRAS2_LQOSEN2_Pos))
#define MATRIX_PRAS2_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS2) Master 3 Priority Position */
#define MATRIX_PRAS2_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M3PR_Pos)                  /**< (MATRIX_PRAS2) Master 3 Priority Mask */
#define MATRIX_PRAS2_M3PR(value)              (MATRIX_PRAS2_M3PR_Msk & ((value) << MATRIX_PRAS2_M3PR_Pos))
#define MATRIX_PRAS2_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS2_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN3_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS2_LQOSEN3(value)           (MATRIX_PRAS2_LQOSEN3_Msk & ((value) << MATRIX_PRAS2_LQOSEN3_Pos))
#define MATRIX_PRAS2_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS2) Master 4 Priority Position */
#define MATRIX_PRAS2_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M4PR_Pos)                  /**< (MATRIX_PRAS2) Master 4 Priority Mask */
#define MATRIX_PRAS2_M4PR(value)              (MATRIX_PRAS2_M4PR_Msk & ((value) << MATRIX_PRAS2_M4PR_Pos))
#define MATRIX_PRAS2_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS2_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN4_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS2_LQOSEN4(value)           (MATRIX_PRAS2_LQOSEN4_Msk & ((value) << MATRIX_PRAS2_LQOSEN4_Pos))
#define MATRIX_PRAS2_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS2) Master 5 Priority Position */
#define MATRIX_PRAS2_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M5PR_Pos)                  /**< (MATRIX_PRAS2) Master 5 Priority Mask */
#define MATRIX_PRAS2_M5PR(value)              (MATRIX_PRAS2_M5PR_Msk & ((value) << MATRIX_PRAS2_M5PR_Pos))
#define MATRIX_PRAS2_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS2_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN5_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS2_LQOSEN5(value)           (MATRIX_PRAS2_LQOSEN5_Msk & ((value) << MATRIX_PRAS2_LQOSEN5_Pos))
#define MATRIX_PRAS2_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS2) Master 6 Priority Position */
#define MATRIX_PRAS2_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M6PR_Pos)                  /**< (MATRIX_PRAS2) Master 6 Priority Mask */
#define MATRIX_PRAS2_M6PR(value)              (MATRIX_PRAS2_M6PR_Msk & ((value) << MATRIX_PRAS2_M6PR_Pos))
#define MATRIX_PRAS2_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS2_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN6_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS2_LQOSEN6(value)           (MATRIX_PRAS2_LQOSEN6_Msk & ((value) << MATRIX_PRAS2_LQOSEN6_Pos))
#define MATRIX_PRAS2_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS2) Master 7 Priority Position */
#define MATRIX_PRAS2_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS2_M7PR_Pos)                  /**< (MATRIX_PRAS2) Master 7 Priority Mask */
#define MATRIX_PRAS2_M7PR(value)              (MATRIX_PRAS2_M7PR_Msk & ((value) << MATRIX_PRAS2_M7PR_Pos))
#define MATRIX_PRAS2_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS2_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS2_LQOSEN7_Pos)               /**< (MATRIX_PRAS2) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS2_LQOSEN7(value)           (MATRIX_PRAS2_LQOSEN7_Msk & ((value) << MATRIX_PRAS2_LQOSEN7_Pos))
#define MATRIX_PRAS2_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS2) Register Mask  */


/* -------- MATRIX_PRBS2 : (MATRIX Offset: 0x94) (R/W 32) Priority Register B for Slave 2 -------- */
#define MATRIX_PRBS2_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS2) Master 8 Priority Position */
#define MATRIX_PRBS2_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS2_M8PR_Pos)                  /**< (MATRIX_PRBS2) Master 8 Priority Mask */
#define MATRIX_PRBS2_M8PR(value)              (MATRIX_PRBS2_M8PR_Msk & ((value) << MATRIX_PRBS2_M8PR_Pos))
#define MATRIX_PRBS2_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS2_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS2_LQOSEN8_Pos)               /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS2_LQOSEN8(value)           (MATRIX_PRBS2_LQOSEN8_Msk & ((value) << MATRIX_PRBS2_LQOSEN8_Pos))
#define MATRIX_PRBS2_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS2) Master 9 Priority Position */
#define MATRIX_PRBS2_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS2_M9PR_Pos)                  /**< (MATRIX_PRBS2) Master 9 Priority Mask */
#define MATRIX_PRBS2_M9PR(value)              (MATRIX_PRBS2_M9PR_Msk & ((value) << MATRIX_PRBS2_M9PR_Pos))
#define MATRIX_PRBS2_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS2_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS2_LQOSEN9_Pos)               /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS2_LQOSEN9(value)           (MATRIX_PRBS2_LQOSEN9_Msk & ((value) << MATRIX_PRBS2_LQOSEN9_Pos))
#define MATRIX_PRBS2_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS2) Master 10 Priority Position */
#define MATRIX_PRBS2_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS2_M10PR_Pos)                 /**< (MATRIX_PRBS2) Master 10 Priority Mask */
#define MATRIX_PRBS2_M10PR(value)             (MATRIX_PRBS2_M10PR_Msk & ((value) << MATRIX_PRBS2_M10PR_Pos))
#define MATRIX_PRBS2_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS2_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS2_LQOSEN10_Pos)              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS2_LQOSEN10(value)          (MATRIX_PRBS2_LQOSEN10_Msk & ((value) << MATRIX_PRBS2_LQOSEN10_Pos))
#define MATRIX_PRBS2_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS2) Master 11 Priority Position */
#define MATRIX_PRBS2_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS2_M11PR_Pos)                 /**< (MATRIX_PRBS2) Master 11 Priority Mask */
#define MATRIX_PRBS2_M11PR(value)             (MATRIX_PRBS2_M11PR_Msk & ((value) << MATRIX_PRBS2_M11PR_Pos))
#define MATRIX_PRBS2_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS2_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS2_LQOSEN11_Pos)              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS2_LQOSEN11(value)          (MATRIX_PRBS2_LQOSEN11_Msk & ((value) << MATRIX_PRBS2_LQOSEN11_Pos))
#define MATRIX_PRBS2_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS2) Master 12 Priority Position */
#define MATRIX_PRBS2_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS2_M12PR_Pos)                 /**< (MATRIX_PRBS2) Master 12 Priority Mask */
#define MATRIX_PRBS2_M12PR(value)             (MATRIX_PRBS2_M12PR_Msk & ((value) << MATRIX_PRBS2_M12PR_Pos))
#define MATRIX_PRBS2_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS2_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS2_LQOSEN12_Pos)              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS2_LQOSEN12(value)          (MATRIX_PRBS2_LQOSEN12_Msk & ((value) << MATRIX_PRBS2_LQOSEN12_Pos))
#define MATRIX_PRBS2_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS2) Master 13 Priority Position */
#define MATRIX_PRBS2_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS2_M13PR_Pos)                 /**< (MATRIX_PRBS2) Master 13 Priority Mask */
#define MATRIX_PRBS2_M13PR(value)             (MATRIX_PRBS2_M13PR_Msk & ((value) << MATRIX_PRBS2_M13PR_Pos))
#define MATRIX_PRBS2_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS2_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS2_LQOSEN13_Pos)              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS2_LQOSEN13(value)          (MATRIX_PRBS2_LQOSEN13_Msk & ((value) << MATRIX_PRBS2_LQOSEN13_Pos))
#define MATRIX_PRBS2_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS2) Master 14 Priority Position */
#define MATRIX_PRBS2_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS2_M14PR_Pos)                 /**< (MATRIX_PRBS2) Master 14 Priority Mask */
#define MATRIX_PRBS2_M14PR(value)             (MATRIX_PRBS2_M14PR_Msk & ((value) << MATRIX_PRBS2_M14PR_Pos))
#define MATRIX_PRBS2_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS2_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS2_LQOSEN14_Pos)              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS2_LQOSEN14(value)          (MATRIX_PRBS2_LQOSEN14_Msk & ((value) << MATRIX_PRBS2_LQOSEN14_Pos))
#define MATRIX_PRBS2_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS2) Master 15 Priority Position */
#define MATRIX_PRBS2_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS2_M15PR_Pos)                 /**< (MATRIX_PRBS2) Master 15 Priority Mask */
#define MATRIX_PRBS2_M15PR(value)             (MATRIX_PRBS2_M15PR_Msk & ((value) << MATRIX_PRBS2_M15PR_Pos))
#define MATRIX_PRBS2_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS2_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS2_LQOSEN15_Pos)              /**< (MATRIX_PRBS2) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS2_LQOSEN15(value)          (MATRIX_PRBS2_LQOSEN15_Msk & ((value) << MATRIX_PRBS2_LQOSEN15_Pos))
#define MATRIX_PRBS2_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS2) Register Mask  */


/* -------- MATRIX_PRAS3 : (MATRIX Offset: 0x98) (R/W 32) Priority Register A for Slave 3 -------- */
#define MATRIX_PRAS3_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS3) Master 0 Priority Position */
#define MATRIX_PRAS3_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M0PR_Pos)                  /**< (MATRIX_PRAS3) Master 0 Priority Mask */
#define MATRIX_PRAS3_M0PR(value)              (MATRIX_PRAS3_M0PR_Msk & ((value) << MATRIX_PRAS3_M0PR_Pos))
#define MATRIX_PRAS3_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS3_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN0_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS3_LQOSEN0(value)           (MATRIX_PRAS3_LQOSEN0_Msk & ((value) << MATRIX_PRAS3_LQOSEN0_Pos))
#define MATRIX_PRAS3_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS3) Master 1 Priority Position */
#define MATRIX_PRAS3_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M1PR_Pos)                  /**< (MATRIX_PRAS3) Master 1 Priority Mask */
#define MATRIX_PRAS3_M1PR(value)              (MATRIX_PRAS3_M1PR_Msk & ((value) << MATRIX_PRAS3_M1PR_Pos))
#define MATRIX_PRAS3_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS3_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN1_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS3_LQOSEN1(value)           (MATRIX_PRAS3_LQOSEN1_Msk & ((value) << MATRIX_PRAS3_LQOSEN1_Pos))
#define MATRIX_PRAS3_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS3) Master 2 Priority Position */
#define MATRIX_PRAS3_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M2PR_Pos)                  /**< (MATRIX_PRAS3) Master 2 Priority Mask */
#define MATRIX_PRAS3_M2PR(value)              (MATRIX_PRAS3_M2PR_Msk & ((value) << MATRIX_PRAS3_M2PR_Pos))
#define MATRIX_PRAS3_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS3_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN2_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS3_LQOSEN2(value)           (MATRIX_PRAS3_LQOSEN2_Msk & ((value) << MATRIX_PRAS3_LQOSEN2_Pos))
#define MATRIX_PRAS3_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS3) Master 3 Priority Position */
#define MATRIX_PRAS3_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M3PR_Pos)                  /**< (MATRIX_PRAS3) Master 3 Priority Mask */
#define MATRIX_PRAS3_M3PR(value)              (MATRIX_PRAS3_M3PR_Msk & ((value) << MATRIX_PRAS3_M3PR_Pos))
#define MATRIX_PRAS3_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS3_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN3_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS3_LQOSEN3(value)           (MATRIX_PRAS3_LQOSEN3_Msk & ((value) << MATRIX_PRAS3_LQOSEN3_Pos))
#define MATRIX_PRAS3_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS3) Master 4 Priority Position */
#define MATRIX_PRAS3_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M4PR_Pos)                  /**< (MATRIX_PRAS3) Master 4 Priority Mask */
#define MATRIX_PRAS3_M4PR(value)              (MATRIX_PRAS3_M4PR_Msk & ((value) << MATRIX_PRAS3_M4PR_Pos))
#define MATRIX_PRAS3_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS3_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN4_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS3_LQOSEN4(value)           (MATRIX_PRAS3_LQOSEN4_Msk & ((value) << MATRIX_PRAS3_LQOSEN4_Pos))
#define MATRIX_PRAS3_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS3) Master 5 Priority Position */
#define MATRIX_PRAS3_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M5PR_Pos)                  /**< (MATRIX_PRAS3) Master 5 Priority Mask */
#define MATRIX_PRAS3_M5PR(value)              (MATRIX_PRAS3_M5PR_Msk & ((value) << MATRIX_PRAS3_M5PR_Pos))
#define MATRIX_PRAS3_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS3_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN5_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS3_LQOSEN5(value)           (MATRIX_PRAS3_LQOSEN5_Msk & ((value) << MATRIX_PRAS3_LQOSEN5_Pos))
#define MATRIX_PRAS3_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS3) Master 6 Priority Position */
#define MATRIX_PRAS3_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M6PR_Pos)                  /**< (MATRIX_PRAS3) Master 6 Priority Mask */
#define MATRIX_PRAS3_M6PR(value)              (MATRIX_PRAS3_M6PR_Msk & ((value) << MATRIX_PRAS3_M6PR_Pos))
#define MATRIX_PRAS3_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS3_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN6_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS3_LQOSEN6(value)           (MATRIX_PRAS3_LQOSEN6_Msk & ((value) << MATRIX_PRAS3_LQOSEN6_Pos))
#define MATRIX_PRAS3_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS3) Master 7 Priority Position */
#define MATRIX_PRAS3_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS3_M7PR_Pos)                  /**< (MATRIX_PRAS3) Master 7 Priority Mask */
#define MATRIX_PRAS3_M7PR(value)              (MATRIX_PRAS3_M7PR_Msk & ((value) << MATRIX_PRAS3_M7PR_Pos))
#define MATRIX_PRAS3_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS3_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS3_LQOSEN7_Pos)               /**< (MATRIX_PRAS3) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS3_LQOSEN7(value)           (MATRIX_PRAS3_LQOSEN7_Msk & ((value) << MATRIX_PRAS3_LQOSEN7_Pos))
#define MATRIX_PRAS3_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS3) Register Mask  */


/* -------- MATRIX_PRBS3 : (MATRIX Offset: 0x9C) (R/W 32) Priority Register B for Slave 3 -------- */
#define MATRIX_PRBS3_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS3) Master 8 Priority Position */
#define MATRIX_PRBS3_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS3_M8PR_Pos)                  /**< (MATRIX_PRBS3) Master 8 Priority Mask */
#define MATRIX_PRBS3_M8PR(value)              (MATRIX_PRBS3_M8PR_Msk & ((value) << MATRIX_PRBS3_M8PR_Pos))
#define MATRIX_PRBS3_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS3_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS3_LQOSEN8_Pos)               /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS3_LQOSEN8(value)           (MATRIX_PRBS3_LQOSEN8_Msk & ((value) << MATRIX_PRBS3_LQOSEN8_Pos))
#define MATRIX_PRBS3_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS3) Master 9 Priority Position */
#define MATRIX_PRBS3_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS3_M9PR_Pos)                  /**< (MATRIX_PRBS3) Master 9 Priority Mask */
#define MATRIX_PRBS3_M9PR(value)              (MATRIX_PRBS3_M9PR_Msk & ((value) << MATRIX_PRBS3_M9PR_Pos))
#define MATRIX_PRBS3_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS3_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS3_LQOSEN9_Pos)               /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS3_LQOSEN9(value)           (MATRIX_PRBS3_LQOSEN9_Msk & ((value) << MATRIX_PRBS3_LQOSEN9_Pos))
#define MATRIX_PRBS3_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS3) Master 10 Priority Position */
#define MATRIX_PRBS3_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS3_M10PR_Pos)                 /**< (MATRIX_PRBS3) Master 10 Priority Mask */
#define MATRIX_PRBS3_M10PR(value)             (MATRIX_PRBS3_M10PR_Msk & ((value) << MATRIX_PRBS3_M10PR_Pos))
#define MATRIX_PRBS3_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS3_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS3_LQOSEN10_Pos)              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS3_LQOSEN10(value)          (MATRIX_PRBS3_LQOSEN10_Msk & ((value) << MATRIX_PRBS3_LQOSEN10_Pos))
#define MATRIX_PRBS3_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS3) Master 11 Priority Position */
#define MATRIX_PRBS3_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS3_M11PR_Pos)                 /**< (MATRIX_PRBS3) Master 11 Priority Mask */
#define MATRIX_PRBS3_M11PR(value)             (MATRIX_PRBS3_M11PR_Msk & ((value) << MATRIX_PRBS3_M11PR_Pos))
#define MATRIX_PRBS3_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS3_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS3_LQOSEN11_Pos)              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS3_LQOSEN11(value)          (MATRIX_PRBS3_LQOSEN11_Msk & ((value) << MATRIX_PRBS3_LQOSEN11_Pos))
#define MATRIX_PRBS3_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS3) Master 12 Priority Position */
#define MATRIX_PRBS3_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS3_M12PR_Pos)                 /**< (MATRIX_PRBS3) Master 12 Priority Mask */
#define MATRIX_PRBS3_M12PR(value)             (MATRIX_PRBS3_M12PR_Msk & ((value) << MATRIX_PRBS3_M12PR_Pos))
#define MATRIX_PRBS3_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS3_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS3_LQOSEN12_Pos)              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS3_LQOSEN12(value)          (MATRIX_PRBS3_LQOSEN12_Msk & ((value) << MATRIX_PRBS3_LQOSEN12_Pos))
#define MATRIX_PRBS3_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS3) Master 13 Priority Position */
#define MATRIX_PRBS3_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS3_M13PR_Pos)                 /**< (MATRIX_PRBS3) Master 13 Priority Mask */
#define MATRIX_PRBS3_M13PR(value)             (MATRIX_PRBS3_M13PR_Msk & ((value) << MATRIX_PRBS3_M13PR_Pos))
#define MATRIX_PRBS3_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS3_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS3_LQOSEN13_Pos)              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS3_LQOSEN13(value)          (MATRIX_PRBS3_LQOSEN13_Msk & ((value) << MATRIX_PRBS3_LQOSEN13_Pos))
#define MATRIX_PRBS3_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS3) Master 14 Priority Position */
#define MATRIX_PRBS3_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS3_M14PR_Pos)                 /**< (MATRIX_PRBS3) Master 14 Priority Mask */
#define MATRIX_PRBS3_M14PR(value)             (MATRIX_PRBS3_M14PR_Msk & ((value) << MATRIX_PRBS3_M14PR_Pos))
#define MATRIX_PRBS3_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS3_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS3_LQOSEN14_Pos)              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS3_LQOSEN14(value)          (MATRIX_PRBS3_LQOSEN14_Msk & ((value) << MATRIX_PRBS3_LQOSEN14_Pos))
#define MATRIX_PRBS3_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS3) Master 15 Priority Position */
#define MATRIX_PRBS3_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS3_M15PR_Pos)                 /**< (MATRIX_PRBS3) Master 15 Priority Mask */
#define MATRIX_PRBS3_M15PR(value)             (MATRIX_PRBS3_M15PR_Msk & ((value) << MATRIX_PRBS3_M15PR_Pos))
#define MATRIX_PRBS3_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS3_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS3_LQOSEN15_Pos)              /**< (MATRIX_PRBS3) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS3_LQOSEN15(value)          (MATRIX_PRBS3_LQOSEN15_Msk & ((value) << MATRIX_PRBS3_LQOSEN15_Pos))
#define MATRIX_PRBS3_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS3) Register Mask  */


/* -------- MATRIX_PRAS4 : (MATRIX Offset: 0xA0) (R/W 32) Priority Register A for Slave 4 -------- */
#define MATRIX_PRAS4_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS4) Master 0 Priority Position */
#define MATRIX_PRAS4_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M0PR_Pos)                  /**< (MATRIX_PRAS4) Master 0 Priority Mask */
#define MATRIX_PRAS4_M0PR(value)              (MATRIX_PRAS4_M0PR_Msk & ((value) << MATRIX_PRAS4_M0PR_Pos))
#define MATRIX_PRAS4_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS4_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN0_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS4_LQOSEN0(value)           (MATRIX_PRAS4_LQOSEN0_Msk & ((value) << MATRIX_PRAS4_LQOSEN0_Pos))
#define MATRIX_PRAS4_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS4) Master 1 Priority Position */
#define MATRIX_PRAS4_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M1PR_Pos)                  /**< (MATRIX_PRAS4) Master 1 Priority Mask */
#define MATRIX_PRAS4_M1PR(value)              (MATRIX_PRAS4_M1PR_Msk & ((value) << MATRIX_PRAS4_M1PR_Pos))
#define MATRIX_PRAS4_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS4_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN1_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS4_LQOSEN1(value)           (MATRIX_PRAS4_LQOSEN1_Msk & ((value) << MATRIX_PRAS4_LQOSEN1_Pos))
#define MATRIX_PRAS4_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS4) Master 2 Priority Position */
#define MATRIX_PRAS4_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M2PR_Pos)                  /**< (MATRIX_PRAS4) Master 2 Priority Mask */
#define MATRIX_PRAS4_M2PR(value)              (MATRIX_PRAS4_M2PR_Msk & ((value) << MATRIX_PRAS4_M2PR_Pos))
#define MATRIX_PRAS4_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS4_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN2_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS4_LQOSEN2(value)           (MATRIX_PRAS4_LQOSEN2_Msk & ((value) << MATRIX_PRAS4_LQOSEN2_Pos))
#define MATRIX_PRAS4_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS4) Master 3 Priority Position */
#define MATRIX_PRAS4_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M3PR_Pos)                  /**< (MATRIX_PRAS4) Master 3 Priority Mask */
#define MATRIX_PRAS4_M3PR(value)              (MATRIX_PRAS4_M3PR_Msk & ((value) << MATRIX_PRAS4_M3PR_Pos))
#define MATRIX_PRAS4_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS4_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN3_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS4_LQOSEN3(value)           (MATRIX_PRAS4_LQOSEN3_Msk & ((value) << MATRIX_PRAS4_LQOSEN3_Pos))
#define MATRIX_PRAS4_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS4) Master 4 Priority Position */
#define MATRIX_PRAS4_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M4PR_Pos)                  /**< (MATRIX_PRAS4) Master 4 Priority Mask */
#define MATRIX_PRAS4_M4PR(value)              (MATRIX_PRAS4_M4PR_Msk & ((value) << MATRIX_PRAS4_M4PR_Pos))
#define MATRIX_PRAS4_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS4_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN4_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS4_LQOSEN4(value)           (MATRIX_PRAS4_LQOSEN4_Msk & ((value) << MATRIX_PRAS4_LQOSEN4_Pos))
#define MATRIX_PRAS4_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS4) Master 5 Priority Position */
#define MATRIX_PRAS4_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M5PR_Pos)                  /**< (MATRIX_PRAS4) Master 5 Priority Mask */
#define MATRIX_PRAS4_M5PR(value)              (MATRIX_PRAS4_M5PR_Msk & ((value) << MATRIX_PRAS4_M5PR_Pos))
#define MATRIX_PRAS4_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS4_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN5_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS4_LQOSEN5(value)           (MATRIX_PRAS4_LQOSEN5_Msk & ((value) << MATRIX_PRAS4_LQOSEN5_Pos))
#define MATRIX_PRAS4_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS4) Master 6 Priority Position */
#define MATRIX_PRAS4_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M6PR_Pos)                  /**< (MATRIX_PRAS4) Master 6 Priority Mask */
#define MATRIX_PRAS4_M6PR(value)              (MATRIX_PRAS4_M6PR_Msk & ((value) << MATRIX_PRAS4_M6PR_Pos))
#define MATRIX_PRAS4_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS4_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN6_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS4_LQOSEN6(value)           (MATRIX_PRAS4_LQOSEN6_Msk & ((value) << MATRIX_PRAS4_LQOSEN6_Pos))
#define MATRIX_PRAS4_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS4) Master 7 Priority Position */
#define MATRIX_PRAS4_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS4_M7PR_Pos)                  /**< (MATRIX_PRAS4) Master 7 Priority Mask */
#define MATRIX_PRAS4_M7PR(value)              (MATRIX_PRAS4_M7PR_Msk & ((value) << MATRIX_PRAS4_M7PR_Pos))
#define MATRIX_PRAS4_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS4_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS4_LQOSEN7_Pos)               /**< (MATRIX_PRAS4) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS4_LQOSEN7(value)           (MATRIX_PRAS4_LQOSEN7_Msk & ((value) << MATRIX_PRAS4_LQOSEN7_Pos))
#define MATRIX_PRAS4_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS4) Register Mask  */


/* -------- MATRIX_PRBS4 : (MATRIX Offset: 0xA4) (R/W 32) Priority Register B for Slave 4 -------- */
#define MATRIX_PRBS4_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS4) Master 8 Priority Position */
#define MATRIX_PRBS4_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS4_M8PR_Pos)                  /**< (MATRIX_PRBS4) Master 8 Priority Mask */
#define MATRIX_PRBS4_M8PR(value)              (MATRIX_PRBS4_M8PR_Msk & ((value) << MATRIX_PRBS4_M8PR_Pos))
#define MATRIX_PRBS4_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS4_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS4_LQOSEN8_Pos)               /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS4_LQOSEN8(value)           (MATRIX_PRBS4_LQOSEN8_Msk & ((value) << MATRIX_PRBS4_LQOSEN8_Pos))
#define MATRIX_PRBS4_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS4) Master 9 Priority Position */
#define MATRIX_PRBS4_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS4_M9PR_Pos)                  /**< (MATRIX_PRBS4) Master 9 Priority Mask */
#define MATRIX_PRBS4_M9PR(value)              (MATRIX_PRBS4_M9PR_Msk & ((value) << MATRIX_PRBS4_M9PR_Pos))
#define MATRIX_PRBS4_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS4_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS4_LQOSEN9_Pos)               /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS4_LQOSEN9(value)           (MATRIX_PRBS4_LQOSEN9_Msk & ((value) << MATRIX_PRBS4_LQOSEN9_Pos))
#define MATRIX_PRBS4_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS4) Master 10 Priority Position */
#define MATRIX_PRBS4_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS4_M10PR_Pos)                 /**< (MATRIX_PRBS4) Master 10 Priority Mask */
#define MATRIX_PRBS4_M10PR(value)             (MATRIX_PRBS4_M10PR_Msk & ((value) << MATRIX_PRBS4_M10PR_Pos))
#define MATRIX_PRBS4_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS4_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS4_LQOSEN10_Pos)              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS4_LQOSEN10(value)          (MATRIX_PRBS4_LQOSEN10_Msk & ((value) << MATRIX_PRBS4_LQOSEN10_Pos))
#define MATRIX_PRBS4_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS4) Master 11 Priority Position */
#define MATRIX_PRBS4_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS4_M11PR_Pos)                 /**< (MATRIX_PRBS4) Master 11 Priority Mask */
#define MATRIX_PRBS4_M11PR(value)             (MATRIX_PRBS4_M11PR_Msk & ((value) << MATRIX_PRBS4_M11PR_Pos))
#define MATRIX_PRBS4_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS4_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS4_LQOSEN11_Pos)              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS4_LQOSEN11(value)          (MATRIX_PRBS4_LQOSEN11_Msk & ((value) << MATRIX_PRBS4_LQOSEN11_Pos))
#define MATRIX_PRBS4_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS4) Master 12 Priority Position */
#define MATRIX_PRBS4_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS4_M12PR_Pos)                 /**< (MATRIX_PRBS4) Master 12 Priority Mask */
#define MATRIX_PRBS4_M12PR(value)             (MATRIX_PRBS4_M12PR_Msk & ((value) << MATRIX_PRBS4_M12PR_Pos))
#define MATRIX_PRBS4_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS4_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS4_LQOSEN12_Pos)              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS4_LQOSEN12(value)          (MATRIX_PRBS4_LQOSEN12_Msk & ((value) << MATRIX_PRBS4_LQOSEN12_Pos))
#define MATRIX_PRBS4_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS4) Master 13 Priority Position */
#define MATRIX_PRBS4_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS4_M13PR_Pos)                 /**< (MATRIX_PRBS4) Master 13 Priority Mask */
#define MATRIX_PRBS4_M13PR(value)             (MATRIX_PRBS4_M13PR_Msk & ((value) << MATRIX_PRBS4_M13PR_Pos))
#define MATRIX_PRBS4_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS4_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS4_LQOSEN13_Pos)              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS4_LQOSEN13(value)          (MATRIX_PRBS4_LQOSEN13_Msk & ((value) << MATRIX_PRBS4_LQOSEN13_Pos))
#define MATRIX_PRBS4_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS4) Master 14 Priority Position */
#define MATRIX_PRBS4_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS4_M14PR_Pos)                 /**< (MATRIX_PRBS4) Master 14 Priority Mask */
#define MATRIX_PRBS4_M14PR(value)             (MATRIX_PRBS4_M14PR_Msk & ((value) << MATRIX_PRBS4_M14PR_Pos))
#define MATRIX_PRBS4_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS4_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS4_LQOSEN14_Pos)              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS4_LQOSEN14(value)          (MATRIX_PRBS4_LQOSEN14_Msk & ((value) << MATRIX_PRBS4_LQOSEN14_Pos))
#define MATRIX_PRBS4_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS4) Master 15 Priority Position */
#define MATRIX_PRBS4_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS4_M15PR_Pos)                 /**< (MATRIX_PRBS4) Master 15 Priority Mask */
#define MATRIX_PRBS4_M15PR(value)             (MATRIX_PRBS4_M15PR_Msk & ((value) << MATRIX_PRBS4_M15PR_Pos))
#define MATRIX_PRBS4_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS4_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS4_LQOSEN15_Pos)              /**< (MATRIX_PRBS4) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS4_LQOSEN15(value)          (MATRIX_PRBS4_LQOSEN15_Msk & ((value) << MATRIX_PRBS4_LQOSEN15_Pos))
#define MATRIX_PRBS4_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS4) Register Mask  */


/* -------- MATRIX_PRAS5 : (MATRIX Offset: 0xA8) (R/W 32) Priority Register A for Slave 5 -------- */
#define MATRIX_PRAS5_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS5) Master 0 Priority Position */
#define MATRIX_PRAS5_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M0PR_Pos)                  /**< (MATRIX_PRAS5) Master 0 Priority Mask */
#define MATRIX_PRAS5_M0PR(value)              (MATRIX_PRAS5_M0PR_Msk & ((value) << MATRIX_PRAS5_M0PR_Pos))
#define MATRIX_PRAS5_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS5_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN0_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS5_LQOSEN0(value)           (MATRIX_PRAS5_LQOSEN0_Msk & ((value) << MATRIX_PRAS5_LQOSEN0_Pos))
#define MATRIX_PRAS5_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS5) Master 1 Priority Position */
#define MATRIX_PRAS5_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M1PR_Pos)                  /**< (MATRIX_PRAS5) Master 1 Priority Mask */
#define MATRIX_PRAS5_M1PR(value)              (MATRIX_PRAS5_M1PR_Msk & ((value) << MATRIX_PRAS5_M1PR_Pos))
#define MATRIX_PRAS5_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS5_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN1_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS5_LQOSEN1(value)           (MATRIX_PRAS5_LQOSEN1_Msk & ((value) << MATRIX_PRAS5_LQOSEN1_Pos))
#define MATRIX_PRAS5_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS5) Master 2 Priority Position */
#define MATRIX_PRAS5_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M2PR_Pos)                  /**< (MATRIX_PRAS5) Master 2 Priority Mask */
#define MATRIX_PRAS5_M2PR(value)              (MATRIX_PRAS5_M2PR_Msk & ((value) << MATRIX_PRAS5_M2PR_Pos))
#define MATRIX_PRAS5_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS5_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN2_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS5_LQOSEN2(value)           (MATRIX_PRAS5_LQOSEN2_Msk & ((value) << MATRIX_PRAS5_LQOSEN2_Pos))
#define MATRIX_PRAS5_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS5) Master 3 Priority Position */
#define MATRIX_PRAS5_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M3PR_Pos)                  /**< (MATRIX_PRAS5) Master 3 Priority Mask */
#define MATRIX_PRAS5_M3PR(value)              (MATRIX_PRAS5_M3PR_Msk & ((value) << MATRIX_PRAS5_M3PR_Pos))
#define MATRIX_PRAS5_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS5_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN3_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS5_LQOSEN3(value)           (MATRIX_PRAS5_LQOSEN3_Msk & ((value) << MATRIX_PRAS5_LQOSEN3_Pos))
#define MATRIX_PRAS5_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS5) Master 4 Priority Position */
#define MATRIX_PRAS5_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M4PR_Pos)                  /**< (MATRIX_PRAS5) Master 4 Priority Mask */
#define MATRIX_PRAS5_M4PR(value)              (MATRIX_PRAS5_M4PR_Msk & ((value) << MATRIX_PRAS5_M4PR_Pos))
#define MATRIX_PRAS5_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS5_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN4_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS5_LQOSEN4(value)           (MATRIX_PRAS5_LQOSEN4_Msk & ((value) << MATRIX_PRAS5_LQOSEN4_Pos))
#define MATRIX_PRAS5_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS5) Master 5 Priority Position */
#define MATRIX_PRAS5_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M5PR_Pos)                  /**< (MATRIX_PRAS5) Master 5 Priority Mask */
#define MATRIX_PRAS5_M5PR(value)              (MATRIX_PRAS5_M5PR_Msk & ((value) << MATRIX_PRAS5_M5PR_Pos))
#define MATRIX_PRAS5_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS5_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN5_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS5_LQOSEN5(value)           (MATRIX_PRAS5_LQOSEN5_Msk & ((value) << MATRIX_PRAS5_LQOSEN5_Pos))
#define MATRIX_PRAS5_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS5) Master 6 Priority Position */
#define MATRIX_PRAS5_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M6PR_Pos)                  /**< (MATRIX_PRAS5) Master 6 Priority Mask */
#define MATRIX_PRAS5_M6PR(value)              (MATRIX_PRAS5_M6PR_Msk & ((value) << MATRIX_PRAS5_M6PR_Pos))
#define MATRIX_PRAS5_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS5_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN6_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS5_LQOSEN6(value)           (MATRIX_PRAS5_LQOSEN6_Msk & ((value) << MATRIX_PRAS5_LQOSEN6_Pos))
#define MATRIX_PRAS5_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS5) Master 7 Priority Position */
#define MATRIX_PRAS5_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS5_M7PR_Pos)                  /**< (MATRIX_PRAS5) Master 7 Priority Mask */
#define MATRIX_PRAS5_M7PR(value)              (MATRIX_PRAS5_M7PR_Msk & ((value) << MATRIX_PRAS5_M7PR_Pos))
#define MATRIX_PRAS5_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS5_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS5_LQOSEN7_Pos)               /**< (MATRIX_PRAS5) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS5_LQOSEN7(value)           (MATRIX_PRAS5_LQOSEN7_Msk & ((value) << MATRIX_PRAS5_LQOSEN7_Pos))
#define MATRIX_PRAS5_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS5) Register Mask  */


/* -------- MATRIX_PRBS5 : (MATRIX Offset: 0xAC) (R/W 32) Priority Register B for Slave 5 -------- */
#define MATRIX_PRBS5_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS5) Master 8 Priority Position */
#define MATRIX_PRBS5_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS5_M8PR_Pos)                  /**< (MATRIX_PRBS5) Master 8 Priority Mask */
#define MATRIX_PRBS5_M8PR(value)              (MATRIX_PRBS5_M8PR_Msk & ((value) << MATRIX_PRBS5_M8PR_Pos))
#define MATRIX_PRBS5_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS5_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS5_LQOSEN8_Pos)               /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS5_LQOSEN8(value)           (MATRIX_PRBS5_LQOSEN8_Msk & ((value) << MATRIX_PRBS5_LQOSEN8_Pos))
#define MATRIX_PRBS5_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS5) Master 9 Priority Position */
#define MATRIX_PRBS5_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS5_M9PR_Pos)                  /**< (MATRIX_PRBS5) Master 9 Priority Mask */
#define MATRIX_PRBS5_M9PR(value)              (MATRIX_PRBS5_M9PR_Msk & ((value) << MATRIX_PRBS5_M9PR_Pos))
#define MATRIX_PRBS5_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS5_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS5_LQOSEN9_Pos)               /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS5_LQOSEN9(value)           (MATRIX_PRBS5_LQOSEN9_Msk & ((value) << MATRIX_PRBS5_LQOSEN9_Pos))
#define MATRIX_PRBS5_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS5) Master 10 Priority Position */
#define MATRIX_PRBS5_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS5_M10PR_Pos)                 /**< (MATRIX_PRBS5) Master 10 Priority Mask */
#define MATRIX_PRBS5_M10PR(value)             (MATRIX_PRBS5_M10PR_Msk & ((value) << MATRIX_PRBS5_M10PR_Pos))
#define MATRIX_PRBS5_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS5_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS5_LQOSEN10_Pos)              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS5_LQOSEN10(value)          (MATRIX_PRBS5_LQOSEN10_Msk & ((value) << MATRIX_PRBS5_LQOSEN10_Pos))
#define MATRIX_PRBS5_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS5) Master 11 Priority Position */
#define MATRIX_PRBS5_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS5_M11PR_Pos)                 /**< (MATRIX_PRBS5) Master 11 Priority Mask */
#define MATRIX_PRBS5_M11PR(value)             (MATRIX_PRBS5_M11PR_Msk & ((value) << MATRIX_PRBS5_M11PR_Pos))
#define MATRIX_PRBS5_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS5_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS5_LQOSEN11_Pos)              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS5_LQOSEN11(value)          (MATRIX_PRBS5_LQOSEN11_Msk & ((value) << MATRIX_PRBS5_LQOSEN11_Pos))
#define MATRIX_PRBS5_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS5) Master 12 Priority Position */
#define MATRIX_PRBS5_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS5_M12PR_Pos)                 /**< (MATRIX_PRBS5) Master 12 Priority Mask */
#define MATRIX_PRBS5_M12PR(value)             (MATRIX_PRBS5_M12PR_Msk & ((value) << MATRIX_PRBS5_M12PR_Pos))
#define MATRIX_PRBS5_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS5_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS5_LQOSEN12_Pos)              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS5_LQOSEN12(value)          (MATRIX_PRBS5_LQOSEN12_Msk & ((value) << MATRIX_PRBS5_LQOSEN12_Pos))
#define MATRIX_PRBS5_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS5) Master 13 Priority Position */
#define MATRIX_PRBS5_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS5_M13PR_Pos)                 /**< (MATRIX_PRBS5) Master 13 Priority Mask */
#define MATRIX_PRBS5_M13PR(value)             (MATRIX_PRBS5_M13PR_Msk & ((value) << MATRIX_PRBS5_M13PR_Pos))
#define MATRIX_PRBS5_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS5_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS5_LQOSEN13_Pos)              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS5_LQOSEN13(value)          (MATRIX_PRBS5_LQOSEN13_Msk & ((value) << MATRIX_PRBS5_LQOSEN13_Pos))
#define MATRIX_PRBS5_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS5) Master 14 Priority Position */
#define MATRIX_PRBS5_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS5_M14PR_Pos)                 /**< (MATRIX_PRBS5) Master 14 Priority Mask */
#define MATRIX_PRBS5_M14PR(value)             (MATRIX_PRBS5_M14PR_Msk & ((value) << MATRIX_PRBS5_M14PR_Pos))
#define MATRIX_PRBS5_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS5_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS5_LQOSEN14_Pos)              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS5_LQOSEN14(value)          (MATRIX_PRBS5_LQOSEN14_Msk & ((value) << MATRIX_PRBS5_LQOSEN14_Pos))
#define MATRIX_PRBS5_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS5) Master 15 Priority Position */
#define MATRIX_PRBS5_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS5_M15PR_Pos)                 /**< (MATRIX_PRBS5) Master 15 Priority Mask */
#define MATRIX_PRBS5_M15PR(value)             (MATRIX_PRBS5_M15PR_Msk & ((value) << MATRIX_PRBS5_M15PR_Pos))
#define MATRIX_PRBS5_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS5_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS5_LQOSEN15_Pos)              /**< (MATRIX_PRBS5) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS5_LQOSEN15(value)          (MATRIX_PRBS5_LQOSEN15_Msk & ((value) << MATRIX_PRBS5_LQOSEN15_Pos))
#define MATRIX_PRBS5_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS5) Register Mask  */


/* -------- MATRIX_PRAS6 : (MATRIX Offset: 0xB0) (R/W 32) Priority Register A for Slave 6 -------- */
#define MATRIX_PRAS6_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS6) Master 0 Priority Position */
#define MATRIX_PRAS6_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M0PR_Pos)                  /**< (MATRIX_PRAS6) Master 0 Priority Mask */
#define MATRIX_PRAS6_M0PR(value)              (MATRIX_PRAS6_M0PR_Msk & ((value) << MATRIX_PRAS6_M0PR_Pos))
#define MATRIX_PRAS6_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS6_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN0_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS6_LQOSEN0(value)           (MATRIX_PRAS6_LQOSEN0_Msk & ((value) << MATRIX_PRAS6_LQOSEN0_Pos))
#define MATRIX_PRAS6_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS6) Master 1 Priority Position */
#define MATRIX_PRAS6_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M1PR_Pos)                  /**< (MATRIX_PRAS6) Master 1 Priority Mask */
#define MATRIX_PRAS6_M1PR(value)              (MATRIX_PRAS6_M1PR_Msk & ((value) << MATRIX_PRAS6_M1PR_Pos))
#define MATRIX_PRAS6_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS6_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN1_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS6_LQOSEN1(value)           (MATRIX_PRAS6_LQOSEN1_Msk & ((value) << MATRIX_PRAS6_LQOSEN1_Pos))
#define MATRIX_PRAS6_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS6) Master 2 Priority Position */
#define MATRIX_PRAS6_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M2PR_Pos)                  /**< (MATRIX_PRAS6) Master 2 Priority Mask */
#define MATRIX_PRAS6_M2PR(value)              (MATRIX_PRAS6_M2PR_Msk & ((value) << MATRIX_PRAS6_M2PR_Pos))
#define MATRIX_PRAS6_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS6_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN2_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS6_LQOSEN2(value)           (MATRIX_PRAS6_LQOSEN2_Msk & ((value) << MATRIX_PRAS6_LQOSEN2_Pos))
#define MATRIX_PRAS6_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS6) Master 3 Priority Position */
#define MATRIX_PRAS6_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M3PR_Pos)                  /**< (MATRIX_PRAS6) Master 3 Priority Mask */
#define MATRIX_PRAS6_M3PR(value)              (MATRIX_PRAS6_M3PR_Msk & ((value) << MATRIX_PRAS6_M3PR_Pos))
#define MATRIX_PRAS6_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS6_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN3_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS6_LQOSEN3(value)           (MATRIX_PRAS6_LQOSEN3_Msk & ((value) << MATRIX_PRAS6_LQOSEN3_Pos))
#define MATRIX_PRAS6_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS6) Master 4 Priority Position */
#define MATRIX_PRAS6_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M4PR_Pos)                  /**< (MATRIX_PRAS6) Master 4 Priority Mask */
#define MATRIX_PRAS6_M4PR(value)              (MATRIX_PRAS6_M4PR_Msk & ((value) << MATRIX_PRAS6_M4PR_Pos))
#define MATRIX_PRAS6_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS6_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN4_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS6_LQOSEN4(value)           (MATRIX_PRAS6_LQOSEN4_Msk & ((value) << MATRIX_PRAS6_LQOSEN4_Pos))
#define MATRIX_PRAS6_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS6) Master 5 Priority Position */
#define MATRIX_PRAS6_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M5PR_Pos)                  /**< (MATRIX_PRAS6) Master 5 Priority Mask */
#define MATRIX_PRAS6_M5PR(value)              (MATRIX_PRAS6_M5PR_Msk & ((value) << MATRIX_PRAS6_M5PR_Pos))
#define MATRIX_PRAS6_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS6_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN5_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS6_LQOSEN5(value)           (MATRIX_PRAS6_LQOSEN5_Msk & ((value) << MATRIX_PRAS6_LQOSEN5_Pos))
#define MATRIX_PRAS6_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS6) Master 6 Priority Position */
#define MATRIX_PRAS6_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M6PR_Pos)                  /**< (MATRIX_PRAS6) Master 6 Priority Mask */
#define MATRIX_PRAS6_M6PR(value)              (MATRIX_PRAS6_M6PR_Msk & ((value) << MATRIX_PRAS6_M6PR_Pos))
#define MATRIX_PRAS6_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS6_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN6_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS6_LQOSEN6(value)           (MATRIX_PRAS6_LQOSEN6_Msk & ((value) << MATRIX_PRAS6_LQOSEN6_Pos))
#define MATRIX_PRAS6_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS6) Master 7 Priority Position */
#define MATRIX_PRAS6_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS6_M7PR_Pos)                  /**< (MATRIX_PRAS6) Master 7 Priority Mask */
#define MATRIX_PRAS6_M7PR(value)              (MATRIX_PRAS6_M7PR_Msk & ((value) << MATRIX_PRAS6_M7PR_Pos))
#define MATRIX_PRAS6_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS6_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS6_LQOSEN7_Pos)               /**< (MATRIX_PRAS6) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS6_LQOSEN7(value)           (MATRIX_PRAS6_LQOSEN7_Msk & ((value) << MATRIX_PRAS6_LQOSEN7_Pos))
#define MATRIX_PRAS6_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS6) Register Mask  */


/* -------- MATRIX_PRBS6 : (MATRIX Offset: 0xB4) (R/W 32) Priority Register B for Slave 6 -------- */
#define MATRIX_PRBS6_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS6) Master 8 Priority Position */
#define MATRIX_PRBS6_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS6_M8PR_Pos)                  /**< (MATRIX_PRBS6) Master 8 Priority Mask */
#define MATRIX_PRBS6_M8PR(value)              (MATRIX_PRBS6_M8PR_Msk & ((value) << MATRIX_PRBS6_M8PR_Pos))
#define MATRIX_PRBS6_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS6_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS6_LQOSEN8_Pos)               /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS6_LQOSEN8(value)           (MATRIX_PRBS6_LQOSEN8_Msk & ((value) << MATRIX_PRBS6_LQOSEN8_Pos))
#define MATRIX_PRBS6_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS6) Master 9 Priority Position */
#define MATRIX_PRBS6_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS6_M9PR_Pos)                  /**< (MATRIX_PRBS6) Master 9 Priority Mask */
#define MATRIX_PRBS6_M9PR(value)              (MATRIX_PRBS6_M9PR_Msk & ((value) << MATRIX_PRBS6_M9PR_Pos))
#define MATRIX_PRBS6_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS6_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS6_LQOSEN9_Pos)               /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS6_LQOSEN9(value)           (MATRIX_PRBS6_LQOSEN9_Msk & ((value) << MATRIX_PRBS6_LQOSEN9_Pos))
#define MATRIX_PRBS6_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS6) Master 10 Priority Position */
#define MATRIX_PRBS6_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS6_M10PR_Pos)                 /**< (MATRIX_PRBS6) Master 10 Priority Mask */
#define MATRIX_PRBS6_M10PR(value)             (MATRIX_PRBS6_M10PR_Msk & ((value) << MATRIX_PRBS6_M10PR_Pos))
#define MATRIX_PRBS6_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS6_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS6_LQOSEN10_Pos)              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS6_LQOSEN10(value)          (MATRIX_PRBS6_LQOSEN10_Msk & ((value) << MATRIX_PRBS6_LQOSEN10_Pos))
#define MATRIX_PRBS6_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS6) Master 11 Priority Position */
#define MATRIX_PRBS6_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS6_M11PR_Pos)                 /**< (MATRIX_PRBS6) Master 11 Priority Mask */
#define MATRIX_PRBS6_M11PR(value)             (MATRIX_PRBS6_M11PR_Msk & ((value) << MATRIX_PRBS6_M11PR_Pos))
#define MATRIX_PRBS6_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS6_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS6_LQOSEN11_Pos)              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS6_LQOSEN11(value)          (MATRIX_PRBS6_LQOSEN11_Msk & ((value) << MATRIX_PRBS6_LQOSEN11_Pos))
#define MATRIX_PRBS6_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS6) Master 12 Priority Position */
#define MATRIX_PRBS6_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS6_M12PR_Pos)                 /**< (MATRIX_PRBS6) Master 12 Priority Mask */
#define MATRIX_PRBS6_M12PR(value)             (MATRIX_PRBS6_M12PR_Msk & ((value) << MATRIX_PRBS6_M12PR_Pos))
#define MATRIX_PRBS6_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS6_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS6_LQOSEN12_Pos)              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS6_LQOSEN12(value)          (MATRIX_PRBS6_LQOSEN12_Msk & ((value) << MATRIX_PRBS6_LQOSEN12_Pos))
#define MATRIX_PRBS6_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS6) Master 13 Priority Position */
#define MATRIX_PRBS6_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS6_M13PR_Pos)                 /**< (MATRIX_PRBS6) Master 13 Priority Mask */
#define MATRIX_PRBS6_M13PR(value)             (MATRIX_PRBS6_M13PR_Msk & ((value) << MATRIX_PRBS6_M13PR_Pos))
#define MATRIX_PRBS6_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS6_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS6_LQOSEN13_Pos)              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS6_LQOSEN13(value)          (MATRIX_PRBS6_LQOSEN13_Msk & ((value) << MATRIX_PRBS6_LQOSEN13_Pos))
#define MATRIX_PRBS6_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS6) Master 14 Priority Position */
#define MATRIX_PRBS6_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS6_M14PR_Pos)                 /**< (MATRIX_PRBS6) Master 14 Priority Mask */
#define MATRIX_PRBS6_M14PR(value)             (MATRIX_PRBS6_M14PR_Msk & ((value) << MATRIX_PRBS6_M14PR_Pos))
#define MATRIX_PRBS6_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS6_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS6_LQOSEN14_Pos)              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS6_LQOSEN14(value)          (MATRIX_PRBS6_LQOSEN14_Msk & ((value) << MATRIX_PRBS6_LQOSEN14_Pos))
#define MATRIX_PRBS6_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS6) Master 15 Priority Position */
#define MATRIX_PRBS6_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS6_M15PR_Pos)                 /**< (MATRIX_PRBS6) Master 15 Priority Mask */
#define MATRIX_PRBS6_M15PR(value)             (MATRIX_PRBS6_M15PR_Msk & ((value) << MATRIX_PRBS6_M15PR_Pos))
#define MATRIX_PRBS6_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS6_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS6_LQOSEN15_Pos)              /**< (MATRIX_PRBS6) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS6_LQOSEN15(value)          (MATRIX_PRBS6_LQOSEN15_Msk & ((value) << MATRIX_PRBS6_LQOSEN15_Pos))
#define MATRIX_PRBS6_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS6) Register Mask  */


/* -------- MATRIX_PRAS7 : (MATRIX Offset: 0xB8) (R/W 32) Priority Register A for Slave 7 -------- */
#define MATRIX_PRAS7_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS7) Master 0 Priority Position */
#define MATRIX_PRAS7_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M0PR_Pos)                  /**< (MATRIX_PRAS7) Master 0 Priority Mask */
#define MATRIX_PRAS7_M0PR(value)              (MATRIX_PRAS7_M0PR_Msk & ((value) << MATRIX_PRAS7_M0PR_Pos))
#define MATRIX_PRAS7_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS7_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN0_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS7_LQOSEN0(value)           (MATRIX_PRAS7_LQOSEN0_Msk & ((value) << MATRIX_PRAS7_LQOSEN0_Pos))
#define MATRIX_PRAS7_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS7) Master 1 Priority Position */
#define MATRIX_PRAS7_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M1PR_Pos)                  /**< (MATRIX_PRAS7) Master 1 Priority Mask */
#define MATRIX_PRAS7_M1PR(value)              (MATRIX_PRAS7_M1PR_Msk & ((value) << MATRIX_PRAS7_M1PR_Pos))
#define MATRIX_PRAS7_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS7_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN1_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS7_LQOSEN1(value)           (MATRIX_PRAS7_LQOSEN1_Msk & ((value) << MATRIX_PRAS7_LQOSEN1_Pos))
#define MATRIX_PRAS7_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS7) Master 2 Priority Position */
#define MATRIX_PRAS7_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M2PR_Pos)                  /**< (MATRIX_PRAS7) Master 2 Priority Mask */
#define MATRIX_PRAS7_M2PR(value)              (MATRIX_PRAS7_M2PR_Msk & ((value) << MATRIX_PRAS7_M2PR_Pos))
#define MATRIX_PRAS7_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS7_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN2_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS7_LQOSEN2(value)           (MATRIX_PRAS7_LQOSEN2_Msk & ((value) << MATRIX_PRAS7_LQOSEN2_Pos))
#define MATRIX_PRAS7_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS7) Master 3 Priority Position */
#define MATRIX_PRAS7_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M3PR_Pos)                  /**< (MATRIX_PRAS7) Master 3 Priority Mask */
#define MATRIX_PRAS7_M3PR(value)              (MATRIX_PRAS7_M3PR_Msk & ((value) << MATRIX_PRAS7_M3PR_Pos))
#define MATRIX_PRAS7_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS7_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN3_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS7_LQOSEN3(value)           (MATRIX_PRAS7_LQOSEN3_Msk & ((value) << MATRIX_PRAS7_LQOSEN3_Pos))
#define MATRIX_PRAS7_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS7) Master 4 Priority Position */
#define MATRIX_PRAS7_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M4PR_Pos)                  /**< (MATRIX_PRAS7) Master 4 Priority Mask */
#define MATRIX_PRAS7_M4PR(value)              (MATRIX_PRAS7_M4PR_Msk & ((value) << MATRIX_PRAS7_M4PR_Pos))
#define MATRIX_PRAS7_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS7_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN4_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS7_LQOSEN4(value)           (MATRIX_PRAS7_LQOSEN4_Msk & ((value) << MATRIX_PRAS7_LQOSEN4_Pos))
#define MATRIX_PRAS7_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS7) Master 5 Priority Position */
#define MATRIX_PRAS7_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M5PR_Pos)                  /**< (MATRIX_PRAS7) Master 5 Priority Mask */
#define MATRIX_PRAS7_M5PR(value)              (MATRIX_PRAS7_M5PR_Msk & ((value) << MATRIX_PRAS7_M5PR_Pos))
#define MATRIX_PRAS7_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS7_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN5_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS7_LQOSEN5(value)           (MATRIX_PRAS7_LQOSEN5_Msk & ((value) << MATRIX_PRAS7_LQOSEN5_Pos))
#define MATRIX_PRAS7_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS7) Master 6 Priority Position */
#define MATRIX_PRAS7_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M6PR_Pos)                  /**< (MATRIX_PRAS7) Master 6 Priority Mask */
#define MATRIX_PRAS7_M6PR(value)              (MATRIX_PRAS7_M6PR_Msk & ((value) << MATRIX_PRAS7_M6PR_Pos))
#define MATRIX_PRAS7_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS7_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN6_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS7_LQOSEN6(value)           (MATRIX_PRAS7_LQOSEN6_Msk & ((value) << MATRIX_PRAS7_LQOSEN6_Pos))
#define MATRIX_PRAS7_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS7) Master 7 Priority Position */
#define MATRIX_PRAS7_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS7_M7PR_Pos)                  /**< (MATRIX_PRAS7) Master 7 Priority Mask */
#define MATRIX_PRAS7_M7PR(value)              (MATRIX_PRAS7_M7PR_Msk & ((value) << MATRIX_PRAS7_M7PR_Pos))
#define MATRIX_PRAS7_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS7_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS7_LQOSEN7_Pos)               /**< (MATRIX_PRAS7) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS7_LQOSEN7(value)           (MATRIX_PRAS7_LQOSEN7_Msk & ((value) << MATRIX_PRAS7_LQOSEN7_Pos))
#define MATRIX_PRAS7_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS7) Register Mask  */


/* -------- MATRIX_PRBS7 : (MATRIX Offset: 0xBC) (R/W 32) Priority Register B for Slave 7 -------- */
#define MATRIX_PRBS7_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS7) Master 8 Priority Position */
#define MATRIX_PRBS7_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS7_M8PR_Pos)                  /**< (MATRIX_PRBS7) Master 8 Priority Mask */
#define MATRIX_PRBS7_M8PR(value)              (MATRIX_PRBS7_M8PR_Msk & ((value) << MATRIX_PRBS7_M8PR_Pos))
#define MATRIX_PRBS7_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS7_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS7_LQOSEN8_Pos)               /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS7_LQOSEN8(value)           (MATRIX_PRBS7_LQOSEN8_Msk & ((value) << MATRIX_PRBS7_LQOSEN8_Pos))
#define MATRIX_PRBS7_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS7) Master 9 Priority Position */
#define MATRIX_PRBS7_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS7_M9PR_Pos)                  /**< (MATRIX_PRBS7) Master 9 Priority Mask */
#define MATRIX_PRBS7_M9PR(value)              (MATRIX_PRBS7_M9PR_Msk & ((value) << MATRIX_PRBS7_M9PR_Pos))
#define MATRIX_PRBS7_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS7_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS7_LQOSEN9_Pos)               /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS7_LQOSEN9(value)           (MATRIX_PRBS7_LQOSEN9_Msk & ((value) << MATRIX_PRBS7_LQOSEN9_Pos))
#define MATRIX_PRBS7_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS7) Master 10 Priority Position */
#define MATRIX_PRBS7_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS7_M10PR_Pos)                 /**< (MATRIX_PRBS7) Master 10 Priority Mask */
#define MATRIX_PRBS7_M10PR(value)             (MATRIX_PRBS7_M10PR_Msk & ((value) << MATRIX_PRBS7_M10PR_Pos))
#define MATRIX_PRBS7_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS7_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS7_LQOSEN10_Pos)              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS7_LQOSEN10(value)          (MATRIX_PRBS7_LQOSEN10_Msk & ((value) << MATRIX_PRBS7_LQOSEN10_Pos))
#define MATRIX_PRBS7_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS7) Master 11 Priority Position */
#define MATRIX_PRBS7_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS7_M11PR_Pos)                 /**< (MATRIX_PRBS7) Master 11 Priority Mask */
#define MATRIX_PRBS7_M11PR(value)             (MATRIX_PRBS7_M11PR_Msk & ((value) << MATRIX_PRBS7_M11PR_Pos))
#define MATRIX_PRBS7_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS7_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS7_LQOSEN11_Pos)              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS7_LQOSEN11(value)          (MATRIX_PRBS7_LQOSEN11_Msk & ((value) << MATRIX_PRBS7_LQOSEN11_Pos))
#define MATRIX_PRBS7_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS7) Master 12 Priority Position */
#define MATRIX_PRBS7_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS7_M12PR_Pos)                 /**< (MATRIX_PRBS7) Master 12 Priority Mask */
#define MATRIX_PRBS7_M12PR(value)             (MATRIX_PRBS7_M12PR_Msk & ((value) << MATRIX_PRBS7_M12PR_Pos))
#define MATRIX_PRBS7_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS7_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS7_LQOSEN12_Pos)              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS7_LQOSEN12(value)          (MATRIX_PRBS7_LQOSEN12_Msk & ((value) << MATRIX_PRBS7_LQOSEN12_Pos))
#define MATRIX_PRBS7_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS7) Master 13 Priority Position */
#define MATRIX_PRBS7_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS7_M13PR_Pos)                 /**< (MATRIX_PRBS7) Master 13 Priority Mask */
#define MATRIX_PRBS7_M13PR(value)             (MATRIX_PRBS7_M13PR_Msk & ((value) << MATRIX_PRBS7_M13PR_Pos))
#define MATRIX_PRBS7_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS7_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS7_LQOSEN13_Pos)              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS7_LQOSEN13(value)          (MATRIX_PRBS7_LQOSEN13_Msk & ((value) << MATRIX_PRBS7_LQOSEN13_Pos))
#define MATRIX_PRBS7_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS7) Master 14 Priority Position */
#define MATRIX_PRBS7_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS7_M14PR_Pos)                 /**< (MATRIX_PRBS7) Master 14 Priority Mask */
#define MATRIX_PRBS7_M14PR(value)             (MATRIX_PRBS7_M14PR_Msk & ((value) << MATRIX_PRBS7_M14PR_Pos))
#define MATRIX_PRBS7_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS7_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS7_LQOSEN14_Pos)              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS7_LQOSEN14(value)          (MATRIX_PRBS7_LQOSEN14_Msk & ((value) << MATRIX_PRBS7_LQOSEN14_Pos))
#define MATRIX_PRBS7_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS7) Master 15 Priority Position */
#define MATRIX_PRBS7_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS7_M15PR_Pos)                 /**< (MATRIX_PRBS7) Master 15 Priority Mask */
#define MATRIX_PRBS7_M15PR(value)             (MATRIX_PRBS7_M15PR_Msk & ((value) << MATRIX_PRBS7_M15PR_Pos))
#define MATRIX_PRBS7_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS7_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS7_LQOSEN15_Pos)              /**< (MATRIX_PRBS7) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS7_LQOSEN15(value)          (MATRIX_PRBS7_LQOSEN15_Msk & ((value) << MATRIX_PRBS7_LQOSEN15_Pos))
#define MATRIX_PRBS7_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS7) Register Mask  */


/* -------- MATRIX_PRAS8 : (MATRIX Offset: 0xC0) (R/W 32) Priority Register A for Slave 8 -------- */
#define MATRIX_PRAS8_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS8) Master 0 Priority Position */
#define MATRIX_PRAS8_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M0PR_Pos)                  /**< (MATRIX_PRAS8) Master 0 Priority Mask */
#define MATRIX_PRAS8_M0PR(value)              (MATRIX_PRAS8_M0PR_Msk & ((value) << MATRIX_PRAS8_M0PR_Pos))
#define MATRIX_PRAS8_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS8_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN0_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS8_LQOSEN0(value)           (MATRIX_PRAS8_LQOSEN0_Msk & ((value) << MATRIX_PRAS8_LQOSEN0_Pos))
#define MATRIX_PRAS8_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS8) Master 1 Priority Position */
#define MATRIX_PRAS8_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M1PR_Pos)                  /**< (MATRIX_PRAS8) Master 1 Priority Mask */
#define MATRIX_PRAS8_M1PR(value)              (MATRIX_PRAS8_M1PR_Msk & ((value) << MATRIX_PRAS8_M1PR_Pos))
#define MATRIX_PRAS8_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS8_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN1_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS8_LQOSEN1(value)           (MATRIX_PRAS8_LQOSEN1_Msk & ((value) << MATRIX_PRAS8_LQOSEN1_Pos))
#define MATRIX_PRAS8_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS8) Master 2 Priority Position */
#define MATRIX_PRAS8_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M2PR_Pos)                  /**< (MATRIX_PRAS8) Master 2 Priority Mask */
#define MATRIX_PRAS8_M2PR(value)              (MATRIX_PRAS8_M2PR_Msk & ((value) << MATRIX_PRAS8_M2PR_Pos))
#define MATRIX_PRAS8_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS8_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN2_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS8_LQOSEN2(value)           (MATRIX_PRAS8_LQOSEN2_Msk & ((value) << MATRIX_PRAS8_LQOSEN2_Pos))
#define MATRIX_PRAS8_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS8) Master 3 Priority Position */
#define MATRIX_PRAS8_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M3PR_Pos)                  /**< (MATRIX_PRAS8) Master 3 Priority Mask */
#define MATRIX_PRAS8_M3PR(value)              (MATRIX_PRAS8_M3PR_Msk & ((value) << MATRIX_PRAS8_M3PR_Pos))
#define MATRIX_PRAS8_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS8_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN3_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS8_LQOSEN3(value)           (MATRIX_PRAS8_LQOSEN3_Msk & ((value) << MATRIX_PRAS8_LQOSEN3_Pos))
#define MATRIX_PRAS8_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS8) Master 4 Priority Position */
#define MATRIX_PRAS8_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M4PR_Pos)                  /**< (MATRIX_PRAS8) Master 4 Priority Mask */
#define MATRIX_PRAS8_M4PR(value)              (MATRIX_PRAS8_M4PR_Msk & ((value) << MATRIX_PRAS8_M4PR_Pos))
#define MATRIX_PRAS8_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS8_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN4_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS8_LQOSEN4(value)           (MATRIX_PRAS8_LQOSEN4_Msk & ((value) << MATRIX_PRAS8_LQOSEN4_Pos))
#define MATRIX_PRAS8_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS8) Master 5 Priority Position */
#define MATRIX_PRAS8_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M5PR_Pos)                  /**< (MATRIX_PRAS8) Master 5 Priority Mask */
#define MATRIX_PRAS8_M5PR(value)              (MATRIX_PRAS8_M5PR_Msk & ((value) << MATRIX_PRAS8_M5PR_Pos))
#define MATRIX_PRAS8_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS8_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN5_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS8_LQOSEN5(value)           (MATRIX_PRAS8_LQOSEN5_Msk & ((value) << MATRIX_PRAS8_LQOSEN5_Pos))
#define MATRIX_PRAS8_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS8) Master 6 Priority Position */
#define MATRIX_PRAS8_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M6PR_Pos)                  /**< (MATRIX_PRAS8) Master 6 Priority Mask */
#define MATRIX_PRAS8_M6PR(value)              (MATRIX_PRAS8_M6PR_Msk & ((value) << MATRIX_PRAS8_M6PR_Pos))
#define MATRIX_PRAS8_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS8_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN6_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS8_LQOSEN6(value)           (MATRIX_PRAS8_LQOSEN6_Msk & ((value) << MATRIX_PRAS8_LQOSEN6_Pos))
#define MATRIX_PRAS8_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS8) Master 7 Priority Position */
#define MATRIX_PRAS8_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS8_M7PR_Pos)                  /**< (MATRIX_PRAS8) Master 7 Priority Mask */
#define MATRIX_PRAS8_M7PR(value)              (MATRIX_PRAS8_M7PR_Msk & ((value) << MATRIX_PRAS8_M7PR_Pos))
#define MATRIX_PRAS8_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS8_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS8_LQOSEN7_Pos)               /**< (MATRIX_PRAS8) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS8_LQOSEN7(value)           (MATRIX_PRAS8_LQOSEN7_Msk & ((value) << MATRIX_PRAS8_LQOSEN7_Pos))
#define MATRIX_PRAS8_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS8) Register Mask  */


/* -------- MATRIX_PRBS8 : (MATRIX Offset: 0xC4) (R/W 32) Priority Register B for Slave 8 -------- */
#define MATRIX_PRBS8_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS8) Master 8 Priority Position */
#define MATRIX_PRBS8_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS8_M8PR_Pos)                  /**< (MATRIX_PRBS8) Master 8 Priority Mask */
#define MATRIX_PRBS8_M8PR(value)              (MATRIX_PRBS8_M8PR_Msk & ((value) << MATRIX_PRBS8_M8PR_Pos))
#define MATRIX_PRBS8_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS8_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS8_LQOSEN8_Pos)               /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS8_LQOSEN8(value)           (MATRIX_PRBS8_LQOSEN8_Msk & ((value) << MATRIX_PRBS8_LQOSEN8_Pos))
#define MATRIX_PRBS8_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS8) Master 9 Priority Position */
#define MATRIX_PRBS8_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS8_M9PR_Pos)                  /**< (MATRIX_PRBS8) Master 9 Priority Mask */
#define MATRIX_PRBS8_M9PR(value)              (MATRIX_PRBS8_M9PR_Msk & ((value) << MATRIX_PRBS8_M9PR_Pos))
#define MATRIX_PRBS8_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS8_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS8_LQOSEN9_Pos)               /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS8_LQOSEN9(value)           (MATRIX_PRBS8_LQOSEN9_Msk & ((value) << MATRIX_PRBS8_LQOSEN9_Pos))
#define MATRIX_PRBS8_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS8) Master 10 Priority Position */
#define MATRIX_PRBS8_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS8_M10PR_Pos)                 /**< (MATRIX_PRBS8) Master 10 Priority Mask */
#define MATRIX_PRBS8_M10PR(value)             (MATRIX_PRBS8_M10PR_Msk & ((value) << MATRIX_PRBS8_M10PR_Pos))
#define MATRIX_PRBS8_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS8_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS8_LQOSEN10_Pos)              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS8_LQOSEN10(value)          (MATRIX_PRBS8_LQOSEN10_Msk & ((value) << MATRIX_PRBS8_LQOSEN10_Pos))
#define MATRIX_PRBS8_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS8) Master 11 Priority Position */
#define MATRIX_PRBS8_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS8_M11PR_Pos)                 /**< (MATRIX_PRBS8) Master 11 Priority Mask */
#define MATRIX_PRBS8_M11PR(value)             (MATRIX_PRBS8_M11PR_Msk & ((value) << MATRIX_PRBS8_M11PR_Pos))
#define MATRIX_PRBS8_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS8_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS8_LQOSEN11_Pos)              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS8_LQOSEN11(value)          (MATRIX_PRBS8_LQOSEN11_Msk & ((value) << MATRIX_PRBS8_LQOSEN11_Pos))
#define MATRIX_PRBS8_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS8) Master 12 Priority Position */
#define MATRIX_PRBS8_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS8_M12PR_Pos)                 /**< (MATRIX_PRBS8) Master 12 Priority Mask */
#define MATRIX_PRBS8_M12PR(value)             (MATRIX_PRBS8_M12PR_Msk & ((value) << MATRIX_PRBS8_M12PR_Pos))
#define MATRIX_PRBS8_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS8_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS8_LQOSEN12_Pos)              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS8_LQOSEN12(value)          (MATRIX_PRBS8_LQOSEN12_Msk & ((value) << MATRIX_PRBS8_LQOSEN12_Pos))
#define MATRIX_PRBS8_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS8) Master 13 Priority Position */
#define MATRIX_PRBS8_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS8_M13PR_Pos)                 /**< (MATRIX_PRBS8) Master 13 Priority Mask */
#define MATRIX_PRBS8_M13PR(value)             (MATRIX_PRBS8_M13PR_Msk & ((value) << MATRIX_PRBS8_M13PR_Pos))
#define MATRIX_PRBS8_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS8_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS8_LQOSEN13_Pos)              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS8_LQOSEN13(value)          (MATRIX_PRBS8_LQOSEN13_Msk & ((value) << MATRIX_PRBS8_LQOSEN13_Pos))
#define MATRIX_PRBS8_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS8) Master 14 Priority Position */
#define MATRIX_PRBS8_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS8_M14PR_Pos)                 /**< (MATRIX_PRBS8) Master 14 Priority Mask */
#define MATRIX_PRBS8_M14PR(value)             (MATRIX_PRBS8_M14PR_Msk & ((value) << MATRIX_PRBS8_M14PR_Pos))
#define MATRIX_PRBS8_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS8_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS8_LQOSEN14_Pos)              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS8_LQOSEN14(value)          (MATRIX_PRBS8_LQOSEN14_Msk & ((value) << MATRIX_PRBS8_LQOSEN14_Pos))
#define MATRIX_PRBS8_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS8) Master 15 Priority Position */
#define MATRIX_PRBS8_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS8_M15PR_Pos)                 /**< (MATRIX_PRBS8) Master 15 Priority Mask */
#define MATRIX_PRBS8_M15PR(value)             (MATRIX_PRBS8_M15PR_Msk & ((value) << MATRIX_PRBS8_M15PR_Pos))
#define MATRIX_PRBS8_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS8_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS8_LQOSEN15_Pos)              /**< (MATRIX_PRBS8) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS8_LQOSEN15(value)          (MATRIX_PRBS8_LQOSEN15_Msk & ((value) << MATRIX_PRBS8_LQOSEN15_Pos))
#define MATRIX_PRBS8_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS8) Register Mask  */


/* -------- MATRIX_PRAS9 : (MATRIX Offset: 0xC8) (R/W 32) Priority Register A for Slave 9 -------- */
#define MATRIX_PRAS9_M0PR_Pos                 _U_(0)                                               /**< (MATRIX_PRAS9) Master 0 Priority Position */
#define MATRIX_PRAS9_M0PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M0PR_Pos)                  /**< (MATRIX_PRAS9) Master 0 Priority Mask */
#define MATRIX_PRAS9_M0PR(value)              (MATRIX_PRAS9_M0PR_Msk & ((value) << MATRIX_PRAS9_M0PR_Pos))
#define MATRIX_PRAS9_LQOSEN0_Pos              _U_(2)                                               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS9_LQOSEN0_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN0_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS9_LQOSEN0(value)           (MATRIX_PRAS9_LQOSEN0_Msk & ((value) << MATRIX_PRAS9_LQOSEN0_Pos))
#define MATRIX_PRAS9_M1PR_Pos                 _U_(4)                                               /**< (MATRIX_PRAS9) Master 1 Priority Position */
#define MATRIX_PRAS9_M1PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M1PR_Pos)                  /**< (MATRIX_PRAS9) Master 1 Priority Mask */
#define MATRIX_PRAS9_M1PR(value)              (MATRIX_PRAS9_M1PR_Msk & ((value) << MATRIX_PRAS9_M1PR_Pos))
#define MATRIX_PRAS9_LQOSEN1_Pos              _U_(6)                                               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS9_LQOSEN1_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN1_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS9_LQOSEN1(value)           (MATRIX_PRAS9_LQOSEN1_Msk & ((value) << MATRIX_PRAS9_LQOSEN1_Pos))
#define MATRIX_PRAS9_M2PR_Pos                 _U_(8)                                               /**< (MATRIX_PRAS9) Master 2 Priority Position */
#define MATRIX_PRAS9_M2PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M2PR_Pos)                  /**< (MATRIX_PRAS9) Master 2 Priority Mask */
#define MATRIX_PRAS9_M2PR(value)              (MATRIX_PRAS9_M2PR_Msk & ((value) << MATRIX_PRAS9_M2PR_Pos))
#define MATRIX_PRAS9_LQOSEN2_Pos              _U_(10)                                              /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS9_LQOSEN2_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN2_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS9_LQOSEN2(value)           (MATRIX_PRAS9_LQOSEN2_Msk & ((value) << MATRIX_PRAS9_LQOSEN2_Pos))
#define MATRIX_PRAS9_M3PR_Pos                 _U_(12)                                              /**< (MATRIX_PRAS9) Master 3 Priority Position */
#define MATRIX_PRAS9_M3PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M3PR_Pos)                  /**< (MATRIX_PRAS9) Master 3 Priority Mask */
#define MATRIX_PRAS9_M3PR(value)              (MATRIX_PRAS9_M3PR_Msk & ((value) << MATRIX_PRAS9_M3PR_Pos))
#define MATRIX_PRAS9_LQOSEN3_Pos              _U_(14)                                              /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS9_LQOSEN3_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN3_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS9_LQOSEN3(value)           (MATRIX_PRAS9_LQOSEN3_Msk & ((value) << MATRIX_PRAS9_LQOSEN3_Pos))
#define MATRIX_PRAS9_M4PR_Pos                 _U_(16)                                              /**< (MATRIX_PRAS9) Master 4 Priority Position */
#define MATRIX_PRAS9_M4PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M4PR_Pos)                  /**< (MATRIX_PRAS9) Master 4 Priority Mask */
#define MATRIX_PRAS9_M4PR(value)              (MATRIX_PRAS9_M4PR_Msk & ((value) << MATRIX_PRAS9_M4PR_Pos))
#define MATRIX_PRAS9_LQOSEN4_Pos              _U_(18)                                              /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS9_LQOSEN4_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN4_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS9_LQOSEN4(value)           (MATRIX_PRAS9_LQOSEN4_Msk & ((value) << MATRIX_PRAS9_LQOSEN4_Pos))
#define MATRIX_PRAS9_M5PR_Pos                 _U_(20)                                              /**< (MATRIX_PRAS9) Master 5 Priority Position */
#define MATRIX_PRAS9_M5PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M5PR_Pos)                  /**< (MATRIX_PRAS9) Master 5 Priority Mask */
#define MATRIX_PRAS9_M5PR(value)              (MATRIX_PRAS9_M5PR_Msk & ((value) << MATRIX_PRAS9_M5PR_Pos))
#define MATRIX_PRAS9_LQOSEN5_Pos              _U_(22)                                              /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS9_LQOSEN5_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN5_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS9_LQOSEN5(value)           (MATRIX_PRAS9_LQOSEN5_Msk & ((value) << MATRIX_PRAS9_LQOSEN5_Pos))
#define MATRIX_PRAS9_M6PR_Pos                 _U_(24)                                              /**< (MATRIX_PRAS9) Master 6 Priority Position */
#define MATRIX_PRAS9_M6PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M6PR_Pos)                  /**< (MATRIX_PRAS9) Master 6 Priority Mask */
#define MATRIX_PRAS9_M6PR(value)              (MATRIX_PRAS9_M6PR_Msk & ((value) << MATRIX_PRAS9_M6PR_Pos))
#define MATRIX_PRAS9_LQOSEN6_Pos              _U_(26)                                              /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS9_LQOSEN6_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN6_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS9_LQOSEN6(value)           (MATRIX_PRAS9_LQOSEN6_Msk & ((value) << MATRIX_PRAS9_LQOSEN6_Pos))
#define MATRIX_PRAS9_M7PR_Pos                 _U_(28)                                              /**< (MATRIX_PRAS9) Master 7 Priority Position */
#define MATRIX_PRAS9_M7PR_Msk                 (_U_(0x3) << MATRIX_PRAS9_M7PR_Pos)                  /**< (MATRIX_PRAS9) Master 7 Priority Mask */
#define MATRIX_PRAS9_M7PR(value)              (MATRIX_PRAS9_M7PR_Msk & ((value) << MATRIX_PRAS9_M7PR_Pos))
#define MATRIX_PRAS9_LQOSEN7_Pos              _U_(30)                                              /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS9_LQOSEN7_Msk              (_U_(0x1) << MATRIX_PRAS9_LQOSEN7_Pos)               /**< (MATRIX_PRAS9) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS9_LQOSEN7(value)           (MATRIX_PRAS9_LQOSEN7_Msk & ((value) << MATRIX_PRAS9_LQOSEN7_Pos))
#define MATRIX_PRAS9_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRAS9) Register Mask  */


/* -------- MATRIX_PRBS9 : (MATRIX Offset: 0xCC) (R/W 32) Priority Register B for Slave 9 -------- */
#define MATRIX_PRBS9_M8PR_Pos                 _U_(0)                                               /**< (MATRIX_PRBS9) Master 8 Priority Position */
#define MATRIX_PRBS9_M8PR_Msk                 (_U_(0x3) << MATRIX_PRBS9_M8PR_Pos)                  /**< (MATRIX_PRBS9) Master 8 Priority Mask */
#define MATRIX_PRBS9_M8PR(value)              (MATRIX_PRBS9_M8PR_Msk & ((value) << MATRIX_PRBS9_M8PR_Pos))
#define MATRIX_PRBS9_LQOSEN8_Pos              _U_(2)                                               /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS9_LQOSEN8_Msk              (_U_(0x1) << MATRIX_PRBS9_LQOSEN8_Pos)               /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS9_LQOSEN8(value)           (MATRIX_PRBS9_LQOSEN8_Msk & ((value) << MATRIX_PRBS9_LQOSEN8_Pos))
#define MATRIX_PRBS9_M9PR_Pos                 _U_(4)                                               /**< (MATRIX_PRBS9) Master 9 Priority Position */
#define MATRIX_PRBS9_M9PR_Msk                 (_U_(0x3) << MATRIX_PRBS9_M9PR_Pos)                  /**< (MATRIX_PRBS9) Master 9 Priority Mask */
#define MATRIX_PRBS9_M9PR(value)              (MATRIX_PRBS9_M9PR_Msk & ((value) << MATRIX_PRBS9_M9PR_Pos))
#define MATRIX_PRBS9_LQOSEN9_Pos              _U_(6)                                               /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS9_LQOSEN9_Msk              (_U_(0x1) << MATRIX_PRBS9_LQOSEN9_Pos)               /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS9_LQOSEN9(value)           (MATRIX_PRBS9_LQOSEN9_Msk & ((value) << MATRIX_PRBS9_LQOSEN9_Pos))
#define MATRIX_PRBS9_M10PR_Pos                _U_(8)                                               /**< (MATRIX_PRBS9) Master 10 Priority Position */
#define MATRIX_PRBS9_M10PR_Msk                (_U_(0x3) << MATRIX_PRBS9_M10PR_Pos)                 /**< (MATRIX_PRBS9) Master 10 Priority Mask */
#define MATRIX_PRBS9_M10PR(value)             (MATRIX_PRBS9_M10PR_Msk & ((value) << MATRIX_PRBS9_M10PR_Pos))
#define MATRIX_PRBS9_LQOSEN10_Pos             _U_(10)                                              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS9_LQOSEN10_Msk             (_U_(0x1) << MATRIX_PRBS9_LQOSEN10_Pos)              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS9_LQOSEN10(value)          (MATRIX_PRBS9_LQOSEN10_Msk & ((value) << MATRIX_PRBS9_LQOSEN10_Pos))
#define MATRIX_PRBS9_M11PR_Pos                _U_(12)                                              /**< (MATRIX_PRBS9) Master 11 Priority Position */
#define MATRIX_PRBS9_M11PR_Msk                (_U_(0x3) << MATRIX_PRBS9_M11PR_Pos)                 /**< (MATRIX_PRBS9) Master 11 Priority Mask */
#define MATRIX_PRBS9_M11PR(value)             (MATRIX_PRBS9_M11PR_Msk & ((value) << MATRIX_PRBS9_M11PR_Pos))
#define MATRIX_PRBS9_LQOSEN11_Pos             _U_(14)                                              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS9_LQOSEN11_Msk             (_U_(0x1) << MATRIX_PRBS9_LQOSEN11_Pos)              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS9_LQOSEN11(value)          (MATRIX_PRBS9_LQOSEN11_Msk & ((value) << MATRIX_PRBS9_LQOSEN11_Pos))
#define MATRIX_PRBS9_M12PR_Pos                _U_(16)                                              /**< (MATRIX_PRBS9) Master 12 Priority Position */
#define MATRIX_PRBS9_M12PR_Msk                (_U_(0x3) << MATRIX_PRBS9_M12PR_Pos)                 /**< (MATRIX_PRBS9) Master 12 Priority Mask */
#define MATRIX_PRBS9_M12PR(value)             (MATRIX_PRBS9_M12PR_Msk & ((value) << MATRIX_PRBS9_M12PR_Pos))
#define MATRIX_PRBS9_LQOSEN12_Pos             _U_(18)                                              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS9_LQOSEN12_Msk             (_U_(0x1) << MATRIX_PRBS9_LQOSEN12_Pos)              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS9_LQOSEN12(value)          (MATRIX_PRBS9_LQOSEN12_Msk & ((value) << MATRIX_PRBS9_LQOSEN12_Pos))
#define MATRIX_PRBS9_M13PR_Pos                _U_(20)                                              /**< (MATRIX_PRBS9) Master 13 Priority Position */
#define MATRIX_PRBS9_M13PR_Msk                (_U_(0x3) << MATRIX_PRBS9_M13PR_Pos)                 /**< (MATRIX_PRBS9) Master 13 Priority Mask */
#define MATRIX_PRBS9_M13PR(value)             (MATRIX_PRBS9_M13PR_Msk & ((value) << MATRIX_PRBS9_M13PR_Pos))
#define MATRIX_PRBS9_LQOSEN13_Pos             _U_(22)                                              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS9_LQOSEN13_Msk             (_U_(0x1) << MATRIX_PRBS9_LQOSEN13_Pos)              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS9_LQOSEN13(value)          (MATRIX_PRBS9_LQOSEN13_Msk & ((value) << MATRIX_PRBS9_LQOSEN13_Pos))
#define MATRIX_PRBS9_M14PR_Pos                _U_(24)                                              /**< (MATRIX_PRBS9) Master 14 Priority Position */
#define MATRIX_PRBS9_M14PR_Msk                (_U_(0x3) << MATRIX_PRBS9_M14PR_Pos)                 /**< (MATRIX_PRBS9) Master 14 Priority Mask */
#define MATRIX_PRBS9_M14PR(value)             (MATRIX_PRBS9_M14PR_Msk & ((value) << MATRIX_PRBS9_M14PR_Pos))
#define MATRIX_PRBS9_LQOSEN14_Pos             _U_(26)                                              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS9_LQOSEN14_Msk             (_U_(0x1) << MATRIX_PRBS9_LQOSEN14_Pos)              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS9_LQOSEN14(value)          (MATRIX_PRBS9_LQOSEN14_Msk & ((value) << MATRIX_PRBS9_LQOSEN14_Pos))
#define MATRIX_PRBS9_M15PR_Pos                _U_(28)                                              /**< (MATRIX_PRBS9) Master 15 Priority Position */
#define MATRIX_PRBS9_M15PR_Msk                (_U_(0x3) << MATRIX_PRBS9_M15PR_Pos)                 /**< (MATRIX_PRBS9) Master 15 Priority Mask */
#define MATRIX_PRBS9_M15PR(value)             (MATRIX_PRBS9_M15PR_Msk & ((value) << MATRIX_PRBS9_M15PR_Pos))
#define MATRIX_PRBS9_LQOSEN15_Pos             _U_(30)                                              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS9_LQOSEN15_Msk             (_U_(0x1) << MATRIX_PRBS9_LQOSEN15_Pos)              /**< (MATRIX_PRBS9) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS9_LQOSEN15(value)          (MATRIX_PRBS9_LQOSEN15_Msk & ((value) << MATRIX_PRBS9_LQOSEN15_Pos))
#define MATRIX_PRBS9_Msk                      _U_(0x77777777)                                      /**< (MATRIX_PRBS9) Register Mask  */


/* -------- MATRIX_PRAS10 : (MATRIX Offset: 0xD0) (R/W 32) Priority Register A for Slave 10 -------- */
#define MATRIX_PRAS10_M0PR_Pos                _U_(0)                                               /**< (MATRIX_PRAS10) Master 0 Priority Position */
#define MATRIX_PRAS10_M0PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M0PR_Pos)                 /**< (MATRIX_PRAS10) Master 0 Priority Mask */
#define MATRIX_PRAS10_M0PR(value)             (MATRIX_PRAS10_M0PR_Msk & ((value) << MATRIX_PRAS10_M0PR_Pos))
#define MATRIX_PRAS10_LQOSEN0_Pos             _U_(2)                                               /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS10_LQOSEN0_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN0_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS10_LQOSEN0(value)          (MATRIX_PRAS10_LQOSEN0_Msk & ((value) << MATRIX_PRAS10_LQOSEN0_Pos))
#define MATRIX_PRAS10_M1PR_Pos                _U_(4)                                               /**< (MATRIX_PRAS10) Master 1 Priority Position */
#define MATRIX_PRAS10_M1PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M1PR_Pos)                 /**< (MATRIX_PRAS10) Master 1 Priority Mask */
#define MATRIX_PRAS10_M1PR(value)             (MATRIX_PRAS10_M1PR_Msk & ((value) << MATRIX_PRAS10_M1PR_Pos))
#define MATRIX_PRAS10_LQOSEN1_Pos             _U_(6)                                               /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS10_LQOSEN1_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN1_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS10_LQOSEN1(value)          (MATRIX_PRAS10_LQOSEN1_Msk & ((value) << MATRIX_PRAS10_LQOSEN1_Pos))
#define MATRIX_PRAS10_M2PR_Pos                _U_(8)                                               /**< (MATRIX_PRAS10) Master 2 Priority Position */
#define MATRIX_PRAS10_M2PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M2PR_Pos)                 /**< (MATRIX_PRAS10) Master 2 Priority Mask */
#define MATRIX_PRAS10_M2PR(value)             (MATRIX_PRAS10_M2PR_Msk & ((value) << MATRIX_PRAS10_M2PR_Pos))
#define MATRIX_PRAS10_LQOSEN2_Pos             _U_(10)                                              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS10_LQOSEN2_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN2_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS10_LQOSEN2(value)          (MATRIX_PRAS10_LQOSEN2_Msk & ((value) << MATRIX_PRAS10_LQOSEN2_Pos))
#define MATRIX_PRAS10_M3PR_Pos                _U_(12)                                              /**< (MATRIX_PRAS10) Master 3 Priority Position */
#define MATRIX_PRAS10_M3PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M3PR_Pos)                 /**< (MATRIX_PRAS10) Master 3 Priority Mask */
#define MATRIX_PRAS10_M3PR(value)             (MATRIX_PRAS10_M3PR_Msk & ((value) << MATRIX_PRAS10_M3PR_Pos))
#define MATRIX_PRAS10_LQOSEN3_Pos             _U_(14)                                              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS10_LQOSEN3_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN3_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS10_LQOSEN3(value)          (MATRIX_PRAS10_LQOSEN3_Msk & ((value) << MATRIX_PRAS10_LQOSEN3_Pos))
#define MATRIX_PRAS10_M4PR_Pos                _U_(16)                                              /**< (MATRIX_PRAS10) Master 4 Priority Position */
#define MATRIX_PRAS10_M4PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M4PR_Pos)                 /**< (MATRIX_PRAS10) Master 4 Priority Mask */
#define MATRIX_PRAS10_M4PR(value)             (MATRIX_PRAS10_M4PR_Msk & ((value) << MATRIX_PRAS10_M4PR_Pos))
#define MATRIX_PRAS10_LQOSEN4_Pos             _U_(18)                                              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS10_LQOSEN4_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN4_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS10_LQOSEN4(value)          (MATRIX_PRAS10_LQOSEN4_Msk & ((value) << MATRIX_PRAS10_LQOSEN4_Pos))
#define MATRIX_PRAS10_M5PR_Pos                _U_(20)                                              /**< (MATRIX_PRAS10) Master 5 Priority Position */
#define MATRIX_PRAS10_M5PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M5PR_Pos)                 /**< (MATRIX_PRAS10) Master 5 Priority Mask */
#define MATRIX_PRAS10_M5PR(value)             (MATRIX_PRAS10_M5PR_Msk & ((value) << MATRIX_PRAS10_M5PR_Pos))
#define MATRIX_PRAS10_LQOSEN5_Pos             _U_(22)                                              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS10_LQOSEN5_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN5_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS10_LQOSEN5(value)          (MATRIX_PRAS10_LQOSEN5_Msk & ((value) << MATRIX_PRAS10_LQOSEN5_Pos))
#define MATRIX_PRAS10_M6PR_Pos                _U_(24)                                              /**< (MATRIX_PRAS10) Master 6 Priority Position */
#define MATRIX_PRAS10_M6PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M6PR_Pos)                 /**< (MATRIX_PRAS10) Master 6 Priority Mask */
#define MATRIX_PRAS10_M6PR(value)             (MATRIX_PRAS10_M6PR_Msk & ((value) << MATRIX_PRAS10_M6PR_Pos))
#define MATRIX_PRAS10_LQOSEN6_Pos             _U_(26)                                              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS10_LQOSEN6_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN6_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS10_LQOSEN6(value)          (MATRIX_PRAS10_LQOSEN6_Msk & ((value) << MATRIX_PRAS10_LQOSEN6_Pos))
#define MATRIX_PRAS10_M7PR_Pos                _U_(28)                                              /**< (MATRIX_PRAS10) Master 7 Priority Position */
#define MATRIX_PRAS10_M7PR_Msk                (_U_(0x3) << MATRIX_PRAS10_M7PR_Pos)                 /**< (MATRIX_PRAS10) Master 7 Priority Mask */
#define MATRIX_PRAS10_M7PR(value)             (MATRIX_PRAS10_M7PR_Msk & ((value) << MATRIX_PRAS10_M7PR_Pos))
#define MATRIX_PRAS10_LQOSEN7_Pos             _U_(30)                                              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS10_LQOSEN7_Msk             (_U_(0x1) << MATRIX_PRAS10_LQOSEN7_Pos)              /**< (MATRIX_PRAS10) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS10_LQOSEN7(value)          (MATRIX_PRAS10_LQOSEN7_Msk & ((value) << MATRIX_PRAS10_LQOSEN7_Pos))
#define MATRIX_PRAS10_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRAS10) Register Mask  */


/* -------- MATRIX_PRBS10 : (MATRIX Offset: 0xD4) (R/W 32) Priority Register B for Slave 10 -------- */
#define MATRIX_PRBS10_M8PR_Pos                _U_(0)                                               /**< (MATRIX_PRBS10) Master 8 Priority Position */
#define MATRIX_PRBS10_M8PR_Msk                (_U_(0x3) << MATRIX_PRBS10_M8PR_Pos)                 /**< (MATRIX_PRBS10) Master 8 Priority Mask */
#define MATRIX_PRBS10_M8PR(value)             (MATRIX_PRBS10_M8PR_Msk & ((value) << MATRIX_PRBS10_M8PR_Pos))
#define MATRIX_PRBS10_LQOSEN8_Pos             _U_(2)                                               /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS10_LQOSEN8_Msk             (_U_(0x1) << MATRIX_PRBS10_LQOSEN8_Pos)              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS10_LQOSEN8(value)          (MATRIX_PRBS10_LQOSEN8_Msk & ((value) << MATRIX_PRBS10_LQOSEN8_Pos))
#define MATRIX_PRBS10_M9PR_Pos                _U_(4)                                               /**< (MATRIX_PRBS10) Master 9 Priority Position */
#define MATRIX_PRBS10_M9PR_Msk                (_U_(0x3) << MATRIX_PRBS10_M9PR_Pos)                 /**< (MATRIX_PRBS10) Master 9 Priority Mask */
#define MATRIX_PRBS10_M9PR(value)             (MATRIX_PRBS10_M9PR_Msk & ((value) << MATRIX_PRBS10_M9PR_Pos))
#define MATRIX_PRBS10_LQOSEN9_Pos             _U_(6)                                               /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS10_LQOSEN9_Msk             (_U_(0x1) << MATRIX_PRBS10_LQOSEN9_Pos)              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS10_LQOSEN9(value)          (MATRIX_PRBS10_LQOSEN9_Msk & ((value) << MATRIX_PRBS10_LQOSEN9_Pos))
#define MATRIX_PRBS10_M10PR_Pos               _U_(8)                                               /**< (MATRIX_PRBS10) Master 10 Priority Position */
#define MATRIX_PRBS10_M10PR_Msk               (_U_(0x3) << MATRIX_PRBS10_M10PR_Pos)                /**< (MATRIX_PRBS10) Master 10 Priority Mask */
#define MATRIX_PRBS10_M10PR(value)            (MATRIX_PRBS10_M10PR_Msk & ((value) << MATRIX_PRBS10_M10PR_Pos))
#define MATRIX_PRBS10_LQOSEN10_Pos            _U_(10)                                              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS10_LQOSEN10_Msk            (_U_(0x1) << MATRIX_PRBS10_LQOSEN10_Pos)             /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS10_LQOSEN10(value)         (MATRIX_PRBS10_LQOSEN10_Msk & ((value) << MATRIX_PRBS10_LQOSEN10_Pos))
#define MATRIX_PRBS10_M11PR_Pos               _U_(12)                                              /**< (MATRIX_PRBS10) Master 11 Priority Position */
#define MATRIX_PRBS10_M11PR_Msk               (_U_(0x3) << MATRIX_PRBS10_M11PR_Pos)                /**< (MATRIX_PRBS10) Master 11 Priority Mask */
#define MATRIX_PRBS10_M11PR(value)            (MATRIX_PRBS10_M11PR_Msk & ((value) << MATRIX_PRBS10_M11PR_Pos))
#define MATRIX_PRBS10_LQOSEN11_Pos            _U_(14)                                              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS10_LQOSEN11_Msk            (_U_(0x1) << MATRIX_PRBS10_LQOSEN11_Pos)             /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS10_LQOSEN11(value)         (MATRIX_PRBS10_LQOSEN11_Msk & ((value) << MATRIX_PRBS10_LQOSEN11_Pos))
#define MATRIX_PRBS10_M12PR_Pos               _U_(16)                                              /**< (MATRIX_PRBS10) Master 12 Priority Position */
#define MATRIX_PRBS10_M12PR_Msk               (_U_(0x3) << MATRIX_PRBS10_M12PR_Pos)                /**< (MATRIX_PRBS10) Master 12 Priority Mask */
#define MATRIX_PRBS10_M12PR(value)            (MATRIX_PRBS10_M12PR_Msk & ((value) << MATRIX_PRBS10_M12PR_Pos))
#define MATRIX_PRBS10_LQOSEN12_Pos            _U_(18)                                              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS10_LQOSEN12_Msk            (_U_(0x1) << MATRIX_PRBS10_LQOSEN12_Pos)             /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS10_LQOSEN12(value)         (MATRIX_PRBS10_LQOSEN12_Msk & ((value) << MATRIX_PRBS10_LQOSEN12_Pos))
#define MATRIX_PRBS10_M13PR_Pos               _U_(20)                                              /**< (MATRIX_PRBS10) Master 13 Priority Position */
#define MATRIX_PRBS10_M13PR_Msk               (_U_(0x3) << MATRIX_PRBS10_M13PR_Pos)                /**< (MATRIX_PRBS10) Master 13 Priority Mask */
#define MATRIX_PRBS10_M13PR(value)            (MATRIX_PRBS10_M13PR_Msk & ((value) << MATRIX_PRBS10_M13PR_Pos))
#define MATRIX_PRBS10_LQOSEN13_Pos            _U_(22)                                              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS10_LQOSEN13_Msk            (_U_(0x1) << MATRIX_PRBS10_LQOSEN13_Pos)             /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS10_LQOSEN13(value)         (MATRIX_PRBS10_LQOSEN13_Msk & ((value) << MATRIX_PRBS10_LQOSEN13_Pos))
#define MATRIX_PRBS10_M14PR_Pos               _U_(24)                                              /**< (MATRIX_PRBS10) Master 14 Priority Position */
#define MATRIX_PRBS10_M14PR_Msk               (_U_(0x3) << MATRIX_PRBS10_M14PR_Pos)                /**< (MATRIX_PRBS10) Master 14 Priority Mask */
#define MATRIX_PRBS10_M14PR(value)            (MATRIX_PRBS10_M14PR_Msk & ((value) << MATRIX_PRBS10_M14PR_Pos))
#define MATRIX_PRBS10_LQOSEN14_Pos            _U_(26)                                              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS10_LQOSEN14_Msk            (_U_(0x1) << MATRIX_PRBS10_LQOSEN14_Pos)             /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS10_LQOSEN14(value)         (MATRIX_PRBS10_LQOSEN14_Msk & ((value) << MATRIX_PRBS10_LQOSEN14_Pos))
#define MATRIX_PRBS10_M15PR_Pos               _U_(28)                                              /**< (MATRIX_PRBS10) Master 15 Priority Position */
#define MATRIX_PRBS10_M15PR_Msk               (_U_(0x3) << MATRIX_PRBS10_M15PR_Pos)                /**< (MATRIX_PRBS10) Master 15 Priority Mask */
#define MATRIX_PRBS10_M15PR(value)            (MATRIX_PRBS10_M15PR_Msk & ((value) << MATRIX_PRBS10_M15PR_Pos))
#define MATRIX_PRBS10_LQOSEN15_Pos            _U_(30)                                              /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS10_LQOSEN15_Msk            (_U_(0x1) << MATRIX_PRBS10_LQOSEN15_Pos)             /**< (MATRIX_PRBS10) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS10_LQOSEN15(value)         (MATRIX_PRBS10_LQOSEN15_Msk & ((value) << MATRIX_PRBS10_LQOSEN15_Pos))
#define MATRIX_PRBS10_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRBS10) Register Mask  */


/* -------- MATRIX_PRAS11 : (MATRIX Offset: 0xD8) (R/W 32) Priority Register A for Slave 11 -------- */
#define MATRIX_PRAS11_M0PR_Pos                _U_(0)                                               /**< (MATRIX_PRAS11) Master 0 Priority Position */
#define MATRIX_PRAS11_M0PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M0PR_Pos)                 /**< (MATRIX_PRAS11) Master 0 Priority Mask */
#define MATRIX_PRAS11_M0PR(value)             (MATRIX_PRAS11_M0PR_Msk & ((value) << MATRIX_PRAS11_M0PR_Pos))
#define MATRIX_PRAS11_LQOSEN0_Pos             _U_(2)                                               /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS11_LQOSEN0_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN0_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS11_LQOSEN0(value)          (MATRIX_PRAS11_LQOSEN0_Msk & ((value) << MATRIX_PRAS11_LQOSEN0_Pos))
#define MATRIX_PRAS11_M1PR_Pos                _U_(4)                                               /**< (MATRIX_PRAS11) Master 1 Priority Position */
#define MATRIX_PRAS11_M1PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M1PR_Pos)                 /**< (MATRIX_PRAS11) Master 1 Priority Mask */
#define MATRIX_PRAS11_M1PR(value)             (MATRIX_PRAS11_M1PR_Msk & ((value) << MATRIX_PRAS11_M1PR_Pos))
#define MATRIX_PRAS11_LQOSEN1_Pos             _U_(6)                                               /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS11_LQOSEN1_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN1_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS11_LQOSEN1(value)          (MATRIX_PRAS11_LQOSEN1_Msk & ((value) << MATRIX_PRAS11_LQOSEN1_Pos))
#define MATRIX_PRAS11_M2PR_Pos                _U_(8)                                               /**< (MATRIX_PRAS11) Master 2 Priority Position */
#define MATRIX_PRAS11_M2PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M2PR_Pos)                 /**< (MATRIX_PRAS11) Master 2 Priority Mask */
#define MATRIX_PRAS11_M2PR(value)             (MATRIX_PRAS11_M2PR_Msk & ((value) << MATRIX_PRAS11_M2PR_Pos))
#define MATRIX_PRAS11_LQOSEN2_Pos             _U_(10)                                              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS11_LQOSEN2_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN2_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS11_LQOSEN2(value)          (MATRIX_PRAS11_LQOSEN2_Msk & ((value) << MATRIX_PRAS11_LQOSEN2_Pos))
#define MATRIX_PRAS11_M3PR_Pos                _U_(12)                                              /**< (MATRIX_PRAS11) Master 3 Priority Position */
#define MATRIX_PRAS11_M3PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M3PR_Pos)                 /**< (MATRIX_PRAS11) Master 3 Priority Mask */
#define MATRIX_PRAS11_M3PR(value)             (MATRIX_PRAS11_M3PR_Msk & ((value) << MATRIX_PRAS11_M3PR_Pos))
#define MATRIX_PRAS11_LQOSEN3_Pos             _U_(14)                                              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS11_LQOSEN3_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN3_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS11_LQOSEN3(value)          (MATRIX_PRAS11_LQOSEN3_Msk & ((value) << MATRIX_PRAS11_LQOSEN3_Pos))
#define MATRIX_PRAS11_M4PR_Pos                _U_(16)                                              /**< (MATRIX_PRAS11) Master 4 Priority Position */
#define MATRIX_PRAS11_M4PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M4PR_Pos)                 /**< (MATRIX_PRAS11) Master 4 Priority Mask */
#define MATRIX_PRAS11_M4PR(value)             (MATRIX_PRAS11_M4PR_Msk & ((value) << MATRIX_PRAS11_M4PR_Pos))
#define MATRIX_PRAS11_LQOSEN4_Pos             _U_(18)                                              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS11_LQOSEN4_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN4_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS11_LQOSEN4(value)          (MATRIX_PRAS11_LQOSEN4_Msk & ((value) << MATRIX_PRAS11_LQOSEN4_Pos))
#define MATRIX_PRAS11_M5PR_Pos                _U_(20)                                              /**< (MATRIX_PRAS11) Master 5 Priority Position */
#define MATRIX_PRAS11_M5PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M5PR_Pos)                 /**< (MATRIX_PRAS11) Master 5 Priority Mask */
#define MATRIX_PRAS11_M5PR(value)             (MATRIX_PRAS11_M5PR_Msk & ((value) << MATRIX_PRAS11_M5PR_Pos))
#define MATRIX_PRAS11_LQOSEN5_Pos             _U_(22)                                              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS11_LQOSEN5_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN5_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS11_LQOSEN5(value)          (MATRIX_PRAS11_LQOSEN5_Msk & ((value) << MATRIX_PRAS11_LQOSEN5_Pos))
#define MATRIX_PRAS11_M6PR_Pos                _U_(24)                                              /**< (MATRIX_PRAS11) Master 6 Priority Position */
#define MATRIX_PRAS11_M6PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M6PR_Pos)                 /**< (MATRIX_PRAS11) Master 6 Priority Mask */
#define MATRIX_PRAS11_M6PR(value)             (MATRIX_PRAS11_M6PR_Msk & ((value) << MATRIX_PRAS11_M6PR_Pos))
#define MATRIX_PRAS11_LQOSEN6_Pos             _U_(26)                                              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS11_LQOSEN6_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN6_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS11_LQOSEN6(value)          (MATRIX_PRAS11_LQOSEN6_Msk & ((value) << MATRIX_PRAS11_LQOSEN6_Pos))
#define MATRIX_PRAS11_M7PR_Pos                _U_(28)                                              /**< (MATRIX_PRAS11) Master 7 Priority Position */
#define MATRIX_PRAS11_M7PR_Msk                (_U_(0x3) << MATRIX_PRAS11_M7PR_Pos)                 /**< (MATRIX_PRAS11) Master 7 Priority Mask */
#define MATRIX_PRAS11_M7PR(value)             (MATRIX_PRAS11_M7PR_Msk & ((value) << MATRIX_PRAS11_M7PR_Pos))
#define MATRIX_PRAS11_LQOSEN7_Pos             _U_(30)                                              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS11_LQOSEN7_Msk             (_U_(0x1) << MATRIX_PRAS11_LQOSEN7_Pos)              /**< (MATRIX_PRAS11) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS11_LQOSEN7(value)          (MATRIX_PRAS11_LQOSEN7_Msk & ((value) << MATRIX_PRAS11_LQOSEN7_Pos))
#define MATRIX_PRAS11_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRAS11) Register Mask  */


/* -------- MATRIX_PRBS11 : (MATRIX Offset: 0xDC) (R/W 32) Priority Register B for Slave 11 -------- */
#define MATRIX_PRBS11_M8PR_Pos                _U_(0)                                               /**< (MATRIX_PRBS11) Master 8 Priority Position */
#define MATRIX_PRBS11_M8PR_Msk                (_U_(0x3) << MATRIX_PRBS11_M8PR_Pos)                 /**< (MATRIX_PRBS11) Master 8 Priority Mask */
#define MATRIX_PRBS11_M8PR(value)             (MATRIX_PRBS11_M8PR_Msk & ((value) << MATRIX_PRBS11_M8PR_Pos))
#define MATRIX_PRBS11_LQOSEN8_Pos             _U_(2)                                               /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS11_LQOSEN8_Msk             (_U_(0x1) << MATRIX_PRBS11_LQOSEN8_Pos)              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS11_LQOSEN8(value)          (MATRIX_PRBS11_LQOSEN8_Msk & ((value) << MATRIX_PRBS11_LQOSEN8_Pos))
#define MATRIX_PRBS11_M9PR_Pos                _U_(4)                                               /**< (MATRIX_PRBS11) Master 9 Priority Position */
#define MATRIX_PRBS11_M9PR_Msk                (_U_(0x3) << MATRIX_PRBS11_M9PR_Pos)                 /**< (MATRIX_PRBS11) Master 9 Priority Mask */
#define MATRIX_PRBS11_M9PR(value)             (MATRIX_PRBS11_M9PR_Msk & ((value) << MATRIX_PRBS11_M9PR_Pos))
#define MATRIX_PRBS11_LQOSEN9_Pos             _U_(6)                                               /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS11_LQOSEN9_Msk             (_U_(0x1) << MATRIX_PRBS11_LQOSEN9_Pos)              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS11_LQOSEN9(value)          (MATRIX_PRBS11_LQOSEN9_Msk & ((value) << MATRIX_PRBS11_LQOSEN9_Pos))
#define MATRIX_PRBS11_M10PR_Pos               _U_(8)                                               /**< (MATRIX_PRBS11) Master 10 Priority Position */
#define MATRIX_PRBS11_M10PR_Msk               (_U_(0x3) << MATRIX_PRBS11_M10PR_Pos)                /**< (MATRIX_PRBS11) Master 10 Priority Mask */
#define MATRIX_PRBS11_M10PR(value)            (MATRIX_PRBS11_M10PR_Msk & ((value) << MATRIX_PRBS11_M10PR_Pos))
#define MATRIX_PRBS11_LQOSEN10_Pos            _U_(10)                                              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS11_LQOSEN10_Msk            (_U_(0x1) << MATRIX_PRBS11_LQOSEN10_Pos)             /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS11_LQOSEN10(value)         (MATRIX_PRBS11_LQOSEN10_Msk & ((value) << MATRIX_PRBS11_LQOSEN10_Pos))
#define MATRIX_PRBS11_M11PR_Pos               _U_(12)                                              /**< (MATRIX_PRBS11) Master 11 Priority Position */
#define MATRIX_PRBS11_M11PR_Msk               (_U_(0x3) << MATRIX_PRBS11_M11PR_Pos)                /**< (MATRIX_PRBS11) Master 11 Priority Mask */
#define MATRIX_PRBS11_M11PR(value)            (MATRIX_PRBS11_M11PR_Msk & ((value) << MATRIX_PRBS11_M11PR_Pos))
#define MATRIX_PRBS11_LQOSEN11_Pos            _U_(14)                                              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS11_LQOSEN11_Msk            (_U_(0x1) << MATRIX_PRBS11_LQOSEN11_Pos)             /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS11_LQOSEN11(value)         (MATRIX_PRBS11_LQOSEN11_Msk & ((value) << MATRIX_PRBS11_LQOSEN11_Pos))
#define MATRIX_PRBS11_M12PR_Pos               _U_(16)                                              /**< (MATRIX_PRBS11) Master 12 Priority Position */
#define MATRIX_PRBS11_M12PR_Msk               (_U_(0x3) << MATRIX_PRBS11_M12PR_Pos)                /**< (MATRIX_PRBS11) Master 12 Priority Mask */
#define MATRIX_PRBS11_M12PR(value)            (MATRIX_PRBS11_M12PR_Msk & ((value) << MATRIX_PRBS11_M12PR_Pos))
#define MATRIX_PRBS11_LQOSEN12_Pos            _U_(18)                                              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS11_LQOSEN12_Msk            (_U_(0x1) << MATRIX_PRBS11_LQOSEN12_Pos)             /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS11_LQOSEN12(value)         (MATRIX_PRBS11_LQOSEN12_Msk & ((value) << MATRIX_PRBS11_LQOSEN12_Pos))
#define MATRIX_PRBS11_M13PR_Pos               _U_(20)                                              /**< (MATRIX_PRBS11) Master 13 Priority Position */
#define MATRIX_PRBS11_M13PR_Msk               (_U_(0x3) << MATRIX_PRBS11_M13PR_Pos)                /**< (MATRIX_PRBS11) Master 13 Priority Mask */
#define MATRIX_PRBS11_M13PR(value)            (MATRIX_PRBS11_M13PR_Msk & ((value) << MATRIX_PRBS11_M13PR_Pos))
#define MATRIX_PRBS11_LQOSEN13_Pos            _U_(22)                                              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS11_LQOSEN13_Msk            (_U_(0x1) << MATRIX_PRBS11_LQOSEN13_Pos)             /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS11_LQOSEN13(value)         (MATRIX_PRBS11_LQOSEN13_Msk & ((value) << MATRIX_PRBS11_LQOSEN13_Pos))
#define MATRIX_PRBS11_M14PR_Pos               _U_(24)                                              /**< (MATRIX_PRBS11) Master 14 Priority Position */
#define MATRIX_PRBS11_M14PR_Msk               (_U_(0x3) << MATRIX_PRBS11_M14PR_Pos)                /**< (MATRIX_PRBS11) Master 14 Priority Mask */
#define MATRIX_PRBS11_M14PR(value)            (MATRIX_PRBS11_M14PR_Msk & ((value) << MATRIX_PRBS11_M14PR_Pos))
#define MATRIX_PRBS11_LQOSEN14_Pos            _U_(26)                                              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS11_LQOSEN14_Msk            (_U_(0x1) << MATRIX_PRBS11_LQOSEN14_Pos)             /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS11_LQOSEN14(value)         (MATRIX_PRBS11_LQOSEN14_Msk & ((value) << MATRIX_PRBS11_LQOSEN14_Pos))
#define MATRIX_PRBS11_M15PR_Pos               _U_(28)                                              /**< (MATRIX_PRBS11) Master 15 Priority Position */
#define MATRIX_PRBS11_M15PR_Msk               (_U_(0x3) << MATRIX_PRBS11_M15PR_Pos)                /**< (MATRIX_PRBS11) Master 15 Priority Mask */
#define MATRIX_PRBS11_M15PR(value)            (MATRIX_PRBS11_M15PR_Msk & ((value) << MATRIX_PRBS11_M15PR_Pos))
#define MATRIX_PRBS11_LQOSEN15_Pos            _U_(30)                                              /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS11_LQOSEN15_Msk            (_U_(0x1) << MATRIX_PRBS11_LQOSEN15_Pos)             /**< (MATRIX_PRBS11) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS11_LQOSEN15(value)         (MATRIX_PRBS11_LQOSEN15_Msk & ((value) << MATRIX_PRBS11_LQOSEN15_Pos))
#define MATRIX_PRBS11_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRBS11) Register Mask  */


/* -------- MATRIX_PRAS12 : (MATRIX Offset: 0xE0) (R/W 32) Priority Register A for Slave 12 -------- */
#define MATRIX_PRAS12_M0PR_Pos                _U_(0)                                               /**< (MATRIX_PRAS12) Master 0 Priority Position */
#define MATRIX_PRAS12_M0PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M0PR_Pos)                 /**< (MATRIX_PRAS12) Master 0 Priority Mask */
#define MATRIX_PRAS12_M0PR(value)             (MATRIX_PRAS12_M0PR_Msk & ((value) << MATRIX_PRAS12_M0PR_Pos))
#define MATRIX_PRAS12_LQOSEN0_Pos             _U_(2)                                               /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS12_LQOSEN0_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN0_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS12_LQOSEN0(value)          (MATRIX_PRAS12_LQOSEN0_Msk & ((value) << MATRIX_PRAS12_LQOSEN0_Pos))
#define MATRIX_PRAS12_M1PR_Pos                _U_(4)                                               /**< (MATRIX_PRAS12) Master 1 Priority Position */
#define MATRIX_PRAS12_M1PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M1PR_Pos)                 /**< (MATRIX_PRAS12) Master 1 Priority Mask */
#define MATRIX_PRAS12_M1PR(value)             (MATRIX_PRAS12_M1PR_Msk & ((value) << MATRIX_PRAS12_M1PR_Pos))
#define MATRIX_PRAS12_LQOSEN1_Pos             _U_(6)                                               /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS12_LQOSEN1_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN1_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS12_LQOSEN1(value)          (MATRIX_PRAS12_LQOSEN1_Msk & ((value) << MATRIX_PRAS12_LQOSEN1_Pos))
#define MATRIX_PRAS12_M2PR_Pos                _U_(8)                                               /**< (MATRIX_PRAS12) Master 2 Priority Position */
#define MATRIX_PRAS12_M2PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M2PR_Pos)                 /**< (MATRIX_PRAS12) Master 2 Priority Mask */
#define MATRIX_PRAS12_M2PR(value)             (MATRIX_PRAS12_M2PR_Msk & ((value) << MATRIX_PRAS12_M2PR_Pos))
#define MATRIX_PRAS12_LQOSEN2_Pos             _U_(10)                                              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS12_LQOSEN2_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN2_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS12_LQOSEN2(value)          (MATRIX_PRAS12_LQOSEN2_Msk & ((value) << MATRIX_PRAS12_LQOSEN2_Pos))
#define MATRIX_PRAS12_M3PR_Pos                _U_(12)                                              /**< (MATRIX_PRAS12) Master 3 Priority Position */
#define MATRIX_PRAS12_M3PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M3PR_Pos)                 /**< (MATRIX_PRAS12) Master 3 Priority Mask */
#define MATRIX_PRAS12_M3PR(value)             (MATRIX_PRAS12_M3PR_Msk & ((value) << MATRIX_PRAS12_M3PR_Pos))
#define MATRIX_PRAS12_LQOSEN3_Pos             _U_(14)                                              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS12_LQOSEN3_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN3_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS12_LQOSEN3(value)          (MATRIX_PRAS12_LQOSEN3_Msk & ((value) << MATRIX_PRAS12_LQOSEN3_Pos))
#define MATRIX_PRAS12_M4PR_Pos                _U_(16)                                              /**< (MATRIX_PRAS12) Master 4 Priority Position */
#define MATRIX_PRAS12_M4PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M4PR_Pos)                 /**< (MATRIX_PRAS12) Master 4 Priority Mask */
#define MATRIX_PRAS12_M4PR(value)             (MATRIX_PRAS12_M4PR_Msk & ((value) << MATRIX_PRAS12_M4PR_Pos))
#define MATRIX_PRAS12_LQOSEN4_Pos             _U_(18)                                              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS12_LQOSEN4_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN4_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS12_LQOSEN4(value)          (MATRIX_PRAS12_LQOSEN4_Msk & ((value) << MATRIX_PRAS12_LQOSEN4_Pos))
#define MATRIX_PRAS12_M5PR_Pos                _U_(20)                                              /**< (MATRIX_PRAS12) Master 5 Priority Position */
#define MATRIX_PRAS12_M5PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M5PR_Pos)                 /**< (MATRIX_PRAS12) Master 5 Priority Mask */
#define MATRIX_PRAS12_M5PR(value)             (MATRIX_PRAS12_M5PR_Msk & ((value) << MATRIX_PRAS12_M5PR_Pos))
#define MATRIX_PRAS12_LQOSEN5_Pos             _U_(22)                                              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS12_LQOSEN5_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN5_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS12_LQOSEN5(value)          (MATRIX_PRAS12_LQOSEN5_Msk & ((value) << MATRIX_PRAS12_LQOSEN5_Pos))
#define MATRIX_PRAS12_M6PR_Pos                _U_(24)                                              /**< (MATRIX_PRAS12) Master 6 Priority Position */
#define MATRIX_PRAS12_M6PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M6PR_Pos)                 /**< (MATRIX_PRAS12) Master 6 Priority Mask */
#define MATRIX_PRAS12_M6PR(value)             (MATRIX_PRAS12_M6PR_Msk & ((value) << MATRIX_PRAS12_M6PR_Pos))
#define MATRIX_PRAS12_LQOSEN6_Pos             _U_(26)                                              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS12_LQOSEN6_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN6_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS12_LQOSEN6(value)          (MATRIX_PRAS12_LQOSEN6_Msk & ((value) << MATRIX_PRAS12_LQOSEN6_Pos))
#define MATRIX_PRAS12_M7PR_Pos                _U_(28)                                              /**< (MATRIX_PRAS12) Master 7 Priority Position */
#define MATRIX_PRAS12_M7PR_Msk                (_U_(0x3) << MATRIX_PRAS12_M7PR_Pos)                 /**< (MATRIX_PRAS12) Master 7 Priority Mask */
#define MATRIX_PRAS12_M7PR(value)             (MATRIX_PRAS12_M7PR_Msk & ((value) << MATRIX_PRAS12_M7PR_Pos))
#define MATRIX_PRAS12_LQOSEN7_Pos             _U_(30)                                              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS12_LQOSEN7_Msk             (_U_(0x1) << MATRIX_PRAS12_LQOSEN7_Pos)              /**< (MATRIX_PRAS12) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS12_LQOSEN7(value)          (MATRIX_PRAS12_LQOSEN7_Msk & ((value) << MATRIX_PRAS12_LQOSEN7_Pos))
#define MATRIX_PRAS12_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRAS12) Register Mask  */


/* -------- MATRIX_PRBS12 : (MATRIX Offset: 0xE4) (R/W 32) Priority Register B for Slave 12 -------- */
#define MATRIX_PRBS12_M8PR_Pos                _U_(0)                                               /**< (MATRIX_PRBS12) Master 8 Priority Position */
#define MATRIX_PRBS12_M8PR_Msk                (_U_(0x3) << MATRIX_PRBS12_M8PR_Pos)                 /**< (MATRIX_PRBS12) Master 8 Priority Mask */
#define MATRIX_PRBS12_M8PR(value)             (MATRIX_PRBS12_M8PR_Msk & ((value) << MATRIX_PRBS12_M8PR_Pos))
#define MATRIX_PRBS12_LQOSEN8_Pos             _U_(2)                                               /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS12_LQOSEN8_Msk             (_U_(0x1) << MATRIX_PRBS12_LQOSEN8_Pos)              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS12_LQOSEN8(value)          (MATRIX_PRBS12_LQOSEN8_Msk & ((value) << MATRIX_PRBS12_LQOSEN8_Pos))
#define MATRIX_PRBS12_M9PR_Pos                _U_(4)                                               /**< (MATRIX_PRBS12) Master 9 Priority Position */
#define MATRIX_PRBS12_M9PR_Msk                (_U_(0x3) << MATRIX_PRBS12_M9PR_Pos)                 /**< (MATRIX_PRBS12) Master 9 Priority Mask */
#define MATRIX_PRBS12_M9PR(value)             (MATRIX_PRBS12_M9PR_Msk & ((value) << MATRIX_PRBS12_M9PR_Pos))
#define MATRIX_PRBS12_LQOSEN9_Pos             _U_(6)                                               /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS12_LQOSEN9_Msk             (_U_(0x1) << MATRIX_PRBS12_LQOSEN9_Pos)              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS12_LQOSEN9(value)          (MATRIX_PRBS12_LQOSEN9_Msk & ((value) << MATRIX_PRBS12_LQOSEN9_Pos))
#define MATRIX_PRBS12_M10PR_Pos               _U_(8)                                               /**< (MATRIX_PRBS12) Master 10 Priority Position */
#define MATRIX_PRBS12_M10PR_Msk               (_U_(0x3) << MATRIX_PRBS12_M10PR_Pos)                /**< (MATRIX_PRBS12) Master 10 Priority Mask */
#define MATRIX_PRBS12_M10PR(value)            (MATRIX_PRBS12_M10PR_Msk & ((value) << MATRIX_PRBS12_M10PR_Pos))
#define MATRIX_PRBS12_LQOSEN10_Pos            _U_(10)                                              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS12_LQOSEN10_Msk            (_U_(0x1) << MATRIX_PRBS12_LQOSEN10_Pos)             /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS12_LQOSEN10(value)         (MATRIX_PRBS12_LQOSEN10_Msk & ((value) << MATRIX_PRBS12_LQOSEN10_Pos))
#define MATRIX_PRBS12_M11PR_Pos               _U_(12)                                              /**< (MATRIX_PRBS12) Master 11 Priority Position */
#define MATRIX_PRBS12_M11PR_Msk               (_U_(0x3) << MATRIX_PRBS12_M11PR_Pos)                /**< (MATRIX_PRBS12) Master 11 Priority Mask */
#define MATRIX_PRBS12_M11PR(value)            (MATRIX_PRBS12_M11PR_Msk & ((value) << MATRIX_PRBS12_M11PR_Pos))
#define MATRIX_PRBS12_LQOSEN11_Pos            _U_(14)                                              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS12_LQOSEN11_Msk            (_U_(0x1) << MATRIX_PRBS12_LQOSEN11_Pos)             /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS12_LQOSEN11(value)         (MATRIX_PRBS12_LQOSEN11_Msk & ((value) << MATRIX_PRBS12_LQOSEN11_Pos))
#define MATRIX_PRBS12_M12PR_Pos               _U_(16)                                              /**< (MATRIX_PRBS12) Master 12 Priority Position */
#define MATRIX_PRBS12_M12PR_Msk               (_U_(0x3) << MATRIX_PRBS12_M12PR_Pos)                /**< (MATRIX_PRBS12) Master 12 Priority Mask */
#define MATRIX_PRBS12_M12PR(value)            (MATRIX_PRBS12_M12PR_Msk & ((value) << MATRIX_PRBS12_M12PR_Pos))
#define MATRIX_PRBS12_LQOSEN12_Pos            _U_(18)                                              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS12_LQOSEN12_Msk            (_U_(0x1) << MATRIX_PRBS12_LQOSEN12_Pos)             /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS12_LQOSEN12(value)         (MATRIX_PRBS12_LQOSEN12_Msk & ((value) << MATRIX_PRBS12_LQOSEN12_Pos))
#define MATRIX_PRBS12_M13PR_Pos               _U_(20)                                              /**< (MATRIX_PRBS12) Master 13 Priority Position */
#define MATRIX_PRBS12_M13PR_Msk               (_U_(0x3) << MATRIX_PRBS12_M13PR_Pos)                /**< (MATRIX_PRBS12) Master 13 Priority Mask */
#define MATRIX_PRBS12_M13PR(value)            (MATRIX_PRBS12_M13PR_Msk & ((value) << MATRIX_PRBS12_M13PR_Pos))
#define MATRIX_PRBS12_LQOSEN13_Pos            _U_(22)                                              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS12_LQOSEN13_Msk            (_U_(0x1) << MATRIX_PRBS12_LQOSEN13_Pos)             /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS12_LQOSEN13(value)         (MATRIX_PRBS12_LQOSEN13_Msk & ((value) << MATRIX_PRBS12_LQOSEN13_Pos))
#define MATRIX_PRBS12_M14PR_Pos               _U_(24)                                              /**< (MATRIX_PRBS12) Master 14 Priority Position */
#define MATRIX_PRBS12_M14PR_Msk               (_U_(0x3) << MATRIX_PRBS12_M14PR_Pos)                /**< (MATRIX_PRBS12) Master 14 Priority Mask */
#define MATRIX_PRBS12_M14PR(value)            (MATRIX_PRBS12_M14PR_Msk & ((value) << MATRIX_PRBS12_M14PR_Pos))
#define MATRIX_PRBS12_LQOSEN14_Pos            _U_(26)                                              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS12_LQOSEN14_Msk            (_U_(0x1) << MATRIX_PRBS12_LQOSEN14_Pos)             /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS12_LQOSEN14(value)         (MATRIX_PRBS12_LQOSEN14_Msk & ((value) << MATRIX_PRBS12_LQOSEN14_Pos))
#define MATRIX_PRBS12_M15PR_Pos               _U_(28)                                              /**< (MATRIX_PRBS12) Master 15 Priority Position */
#define MATRIX_PRBS12_M15PR_Msk               (_U_(0x3) << MATRIX_PRBS12_M15PR_Pos)                /**< (MATRIX_PRBS12) Master 15 Priority Mask */
#define MATRIX_PRBS12_M15PR(value)            (MATRIX_PRBS12_M15PR_Msk & ((value) << MATRIX_PRBS12_M15PR_Pos))
#define MATRIX_PRBS12_LQOSEN15_Pos            _U_(30)                                              /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS12_LQOSEN15_Msk            (_U_(0x1) << MATRIX_PRBS12_LQOSEN15_Pos)             /**< (MATRIX_PRBS12) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS12_LQOSEN15(value)         (MATRIX_PRBS12_LQOSEN15_Msk & ((value) << MATRIX_PRBS12_LQOSEN15_Pos))
#define MATRIX_PRBS12_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRBS12) Register Mask  */


/* -------- MATRIX_PRAS13 : (MATRIX Offset: 0xE8) (R/W 32) Priority Register A for Slave 13 -------- */
#define MATRIX_PRAS13_M0PR_Pos                _U_(0)                                               /**< (MATRIX_PRAS13) Master 0 Priority Position */
#define MATRIX_PRAS13_M0PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M0PR_Pos)                 /**< (MATRIX_PRAS13) Master 0 Priority Mask */
#define MATRIX_PRAS13_M0PR(value)             (MATRIX_PRAS13_M0PR_Msk & ((value) << MATRIX_PRAS13_M0PR_Pos))
#define MATRIX_PRAS13_LQOSEN0_Pos             _U_(2)                                               /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS13_LQOSEN0_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN0_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS13_LQOSEN0(value)          (MATRIX_PRAS13_LQOSEN0_Msk & ((value) << MATRIX_PRAS13_LQOSEN0_Pos))
#define MATRIX_PRAS13_M1PR_Pos                _U_(4)                                               /**< (MATRIX_PRAS13) Master 1 Priority Position */
#define MATRIX_PRAS13_M1PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M1PR_Pos)                 /**< (MATRIX_PRAS13) Master 1 Priority Mask */
#define MATRIX_PRAS13_M1PR(value)             (MATRIX_PRAS13_M1PR_Msk & ((value) << MATRIX_PRAS13_M1PR_Pos))
#define MATRIX_PRAS13_LQOSEN1_Pos             _U_(6)                                               /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS13_LQOSEN1_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN1_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS13_LQOSEN1(value)          (MATRIX_PRAS13_LQOSEN1_Msk & ((value) << MATRIX_PRAS13_LQOSEN1_Pos))
#define MATRIX_PRAS13_M2PR_Pos                _U_(8)                                               /**< (MATRIX_PRAS13) Master 2 Priority Position */
#define MATRIX_PRAS13_M2PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M2PR_Pos)                 /**< (MATRIX_PRAS13) Master 2 Priority Mask */
#define MATRIX_PRAS13_M2PR(value)             (MATRIX_PRAS13_M2PR_Msk & ((value) << MATRIX_PRAS13_M2PR_Pos))
#define MATRIX_PRAS13_LQOSEN2_Pos             _U_(10)                                              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS13_LQOSEN2_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN2_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS13_LQOSEN2(value)          (MATRIX_PRAS13_LQOSEN2_Msk & ((value) << MATRIX_PRAS13_LQOSEN2_Pos))
#define MATRIX_PRAS13_M3PR_Pos                _U_(12)                                              /**< (MATRIX_PRAS13) Master 3 Priority Position */
#define MATRIX_PRAS13_M3PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M3PR_Pos)                 /**< (MATRIX_PRAS13) Master 3 Priority Mask */
#define MATRIX_PRAS13_M3PR(value)             (MATRIX_PRAS13_M3PR_Msk & ((value) << MATRIX_PRAS13_M3PR_Pos))
#define MATRIX_PRAS13_LQOSEN3_Pos             _U_(14)                                              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS13_LQOSEN3_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN3_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS13_LQOSEN3(value)          (MATRIX_PRAS13_LQOSEN3_Msk & ((value) << MATRIX_PRAS13_LQOSEN3_Pos))
#define MATRIX_PRAS13_M4PR_Pos                _U_(16)                                              /**< (MATRIX_PRAS13) Master 4 Priority Position */
#define MATRIX_PRAS13_M4PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M4PR_Pos)                 /**< (MATRIX_PRAS13) Master 4 Priority Mask */
#define MATRIX_PRAS13_M4PR(value)             (MATRIX_PRAS13_M4PR_Msk & ((value) << MATRIX_PRAS13_M4PR_Pos))
#define MATRIX_PRAS13_LQOSEN4_Pos             _U_(18)                                              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS13_LQOSEN4_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN4_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS13_LQOSEN4(value)          (MATRIX_PRAS13_LQOSEN4_Msk & ((value) << MATRIX_PRAS13_LQOSEN4_Pos))
#define MATRIX_PRAS13_M5PR_Pos                _U_(20)                                              /**< (MATRIX_PRAS13) Master 5 Priority Position */
#define MATRIX_PRAS13_M5PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M5PR_Pos)                 /**< (MATRIX_PRAS13) Master 5 Priority Mask */
#define MATRIX_PRAS13_M5PR(value)             (MATRIX_PRAS13_M5PR_Msk & ((value) << MATRIX_PRAS13_M5PR_Pos))
#define MATRIX_PRAS13_LQOSEN5_Pos             _U_(22)                                              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS13_LQOSEN5_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN5_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS13_LQOSEN5(value)          (MATRIX_PRAS13_LQOSEN5_Msk & ((value) << MATRIX_PRAS13_LQOSEN5_Pos))
#define MATRIX_PRAS13_M6PR_Pos                _U_(24)                                              /**< (MATRIX_PRAS13) Master 6 Priority Position */
#define MATRIX_PRAS13_M6PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M6PR_Pos)                 /**< (MATRIX_PRAS13) Master 6 Priority Mask */
#define MATRIX_PRAS13_M6PR(value)             (MATRIX_PRAS13_M6PR_Msk & ((value) << MATRIX_PRAS13_M6PR_Pos))
#define MATRIX_PRAS13_LQOSEN6_Pos             _U_(26)                                              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS13_LQOSEN6_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN6_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS13_LQOSEN6(value)          (MATRIX_PRAS13_LQOSEN6_Msk & ((value) << MATRIX_PRAS13_LQOSEN6_Pos))
#define MATRIX_PRAS13_M7PR_Pos                _U_(28)                                              /**< (MATRIX_PRAS13) Master 7 Priority Position */
#define MATRIX_PRAS13_M7PR_Msk                (_U_(0x3) << MATRIX_PRAS13_M7PR_Pos)                 /**< (MATRIX_PRAS13) Master 7 Priority Mask */
#define MATRIX_PRAS13_M7PR(value)             (MATRIX_PRAS13_M7PR_Msk & ((value) << MATRIX_PRAS13_M7PR_Pos))
#define MATRIX_PRAS13_LQOSEN7_Pos             _U_(30)                                              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS13_LQOSEN7_Msk             (_U_(0x1) << MATRIX_PRAS13_LQOSEN7_Pos)              /**< (MATRIX_PRAS13) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS13_LQOSEN7(value)          (MATRIX_PRAS13_LQOSEN7_Msk & ((value) << MATRIX_PRAS13_LQOSEN7_Pos))
#define MATRIX_PRAS13_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRAS13) Register Mask  */


/* -------- MATRIX_PRBS13 : (MATRIX Offset: 0xEC) (R/W 32) Priority Register B for Slave 13 -------- */
#define MATRIX_PRBS13_M8PR_Pos                _U_(0)                                               /**< (MATRIX_PRBS13) Master 8 Priority Position */
#define MATRIX_PRBS13_M8PR_Msk                (_U_(0x3) << MATRIX_PRBS13_M8PR_Pos)                 /**< (MATRIX_PRBS13) Master 8 Priority Mask */
#define MATRIX_PRBS13_M8PR(value)             (MATRIX_PRBS13_M8PR_Msk & ((value) << MATRIX_PRBS13_M8PR_Pos))
#define MATRIX_PRBS13_LQOSEN8_Pos             _U_(2)                                               /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS13_LQOSEN8_Msk             (_U_(0x1) << MATRIX_PRBS13_LQOSEN8_Pos)              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS13_LQOSEN8(value)          (MATRIX_PRBS13_LQOSEN8_Msk & ((value) << MATRIX_PRBS13_LQOSEN8_Pos))
#define MATRIX_PRBS13_M9PR_Pos                _U_(4)                                               /**< (MATRIX_PRBS13) Master 9 Priority Position */
#define MATRIX_PRBS13_M9PR_Msk                (_U_(0x3) << MATRIX_PRBS13_M9PR_Pos)                 /**< (MATRIX_PRBS13) Master 9 Priority Mask */
#define MATRIX_PRBS13_M9PR(value)             (MATRIX_PRBS13_M9PR_Msk & ((value) << MATRIX_PRBS13_M9PR_Pos))
#define MATRIX_PRBS13_LQOSEN9_Pos             _U_(6)                                               /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS13_LQOSEN9_Msk             (_U_(0x1) << MATRIX_PRBS13_LQOSEN9_Pos)              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS13_LQOSEN9(value)          (MATRIX_PRBS13_LQOSEN9_Msk & ((value) << MATRIX_PRBS13_LQOSEN9_Pos))
#define MATRIX_PRBS13_M10PR_Pos               _U_(8)                                               /**< (MATRIX_PRBS13) Master 10 Priority Position */
#define MATRIX_PRBS13_M10PR_Msk               (_U_(0x3) << MATRIX_PRBS13_M10PR_Pos)                /**< (MATRIX_PRBS13) Master 10 Priority Mask */
#define MATRIX_PRBS13_M10PR(value)            (MATRIX_PRBS13_M10PR_Msk & ((value) << MATRIX_PRBS13_M10PR_Pos))
#define MATRIX_PRBS13_LQOSEN10_Pos            _U_(10)                                              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS13_LQOSEN10_Msk            (_U_(0x1) << MATRIX_PRBS13_LQOSEN10_Pos)             /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS13_LQOSEN10(value)         (MATRIX_PRBS13_LQOSEN10_Msk & ((value) << MATRIX_PRBS13_LQOSEN10_Pos))
#define MATRIX_PRBS13_M11PR_Pos               _U_(12)                                              /**< (MATRIX_PRBS13) Master 11 Priority Position */
#define MATRIX_PRBS13_M11PR_Msk               (_U_(0x3) << MATRIX_PRBS13_M11PR_Pos)                /**< (MATRIX_PRBS13) Master 11 Priority Mask */
#define MATRIX_PRBS13_M11PR(value)            (MATRIX_PRBS13_M11PR_Msk & ((value) << MATRIX_PRBS13_M11PR_Pos))
#define MATRIX_PRBS13_LQOSEN11_Pos            _U_(14)                                              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS13_LQOSEN11_Msk            (_U_(0x1) << MATRIX_PRBS13_LQOSEN11_Pos)             /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS13_LQOSEN11(value)         (MATRIX_PRBS13_LQOSEN11_Msk & ((value) << MATRIX_PRBS13_LQOSEN11_Pos))
#define MATRIX_PRBS13_M12PR_Pos               _U_(16)                                              /**< (MATRIX_PRBS13) Master 12 Priority Position */
#define MATRIX_PRBS13_M12PR_Msk               (_U_(0x3) << MATRIX_PRBS13_M12PR_Pos)                /**< (MATRIX_PRBS13) Master 12 Priority Mask */
#define MATRIX_PRBS13_M12PR(value)            (MATRIX_PRBS13_M12PR_Msk & ((value) << MATRIX_PRBS13_M12PR_Pos))
#define MATRIX_PRBS13_LQOSEN12_Pos            _U_(18)                                              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS13_LQOSEN12_Msk            (_U_(0x1) << MATRIX_PRBS13_LQOSEN12_Pos)             /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS13_LQOSEN12(value)         (MATRIX_PRBS13_LQOSEN12_Msk & ((value) << MATRIX_PRBS13_LQOSEN12_Pos))
#define MATRIX_PRBS13_M13PR_Pos               _U_(20)                                              /**< (MATRIX_PRBS13) Master 13 Priority Position */
#define MATRIX_PRBS13_M13PR_Msk               (_U_(0x3) << MATRIX_PRBS13_M13PR_Pos)                /**< (MATRIX_PRBS13) Master 13 Priority Mask */
#define MATRIX_PRBS13_M13PR(value)            (MATRIX_PRBS13_M13PR_Msk & ((value) << MATRIX_PRBS13_M13PR_Pos))
#define MATRIX_PRBS13_LQOSEN13_Pos            _U_(22)                                              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS13_LQOSEN13_Msk            (_U_(0x1) << MATRIX_PRBS13_LQOSEN13_Pos)             /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS13_LQOSEN13(value)         (MATRIX_PRBS13_LQOSEN13_Msk & ((value) << MATRIX_PRBS13_LQOSEN13_Pos))
#define MATRIX_PRBS13_M14PR_Pos               _U_(24)                                              /**< (MATRIX_PRBS13) Master 14 Priority Position */
#define MATRIX_PRBS13_M14PR_Msk               (_U_(0x3) << MATRIX_PRBS13_M14PR_Pos)                /**< (MATRIX_PRBS13) Master 14 Priority Mask */
#define MATRIX_PRBS13_M14PR(value)            (MATRIX_PRBS13_M14PR_Msk & ((value) << MATRIX_PRBS13_M14PR_Pos))
#define MATRIX_PRBS13_LQOSEN14_Pos            _U_(26)                                              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS13_LQOSEN14_Msk            (_U_(0x1) << MATRIX_PRBS13_LQOSEN14_Pos)             /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS13_LQOSEN14(value)         (MATRIX_PRBS13_LQOSEN14_Msk & ((value) << MATRIX_PRBS13_LQOSEN14_Pos))
#define MATRIX_PRBS13_M15PR_Pos               _U_(28)                                              /**< (MATRIX_PRBS13) Master 15 Priority Position */
#define MATRIX_PRBS13_M15PR_Msk               (_U_(0x3) << MATRIX_PRBS13_M15PR_Pos)                /**< (MATRIX_PRBS13) Master 15 Priority Mask */
#define MATRIX_PRBS13_M15PR(value)            (MATRIX_PRBS13_M15PR_Msk & ((value) << MATRIX_PRBS13_M15PR_Pos))
#define MATRIX_PRBS13_LQOSEN15_Pos            _U_(30)                                              /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS13_LQOSEN15_Msk            (_U_(0x1) << MATRIX_PRBS13_LQOSEN15_Pos)             /**< (MATRIX_PRBS13) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS13_LQOSEN15(value)         (MATRIX_PRBS13_LQOSEN15_Msk & ((value) << MATRIX_PRBS13_LQOSEN15_Pos))
#define MATRIX_PRBS13_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRBS13) Register Mask  */


/* -------- MATRIX_PRAS14 : (MATRIX Offset: 0xF0) (R/W 32) Priority Register A for Slave 14 -------- */
#define MATRIX_PRAS14_M0PR_Pos                _U_(0)                                               /**< (MATRIX_PRAS14) Master 0 Priority Position */
#define MATRIX_PRAS14_M0PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M0PR_Pos)                 /**< (MATRIX_PRAS14) Master 0 Priority Mask */
#define MATRIX_PRAS14_M0PR(value)             (MATRIX_PRAS14_M0PR_Msk & ((value) << MATRIX_PRAS14_M0PR_Pos))
#define MATRIX_PRAS14_LQOSEN0_Pos             _U_(2)                                               /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS14_LQOSEN0_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN0_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS14_LQOSEN0(value)          (MATRIX_PRAS14_LQOSEN0_Msk & ((value) << MATRIX_PRAS14_LQOSEN0_Pos))
#define MATRIX_PRAS14_M1PR_Pos                _U_(4)                                               /**< (MATRIX_PRAS14) Master 1 Priority Position */
#define MATRIX_PRAS14_M1PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M1PR_Pos)                 /**< (MATRIX_PRAS14) Master 1 Priority Mask */
#define MATRIX_PRAS14_M1PR(value)             (MATRIX_PRAS14_M1PR_Msk & ((value) << MATRIX_PRAS14_M1PR_Pos))
#define MATRIX_PRAS14_LQOSEN1_Pos             _U_(6)                                               /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS14_LQOSEN1_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN1_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS14_LQOSEN1(value)          (MATRIX_PRAS14_LQOSEN1_Msk & ((value) << MATRIX_PRAS14_LQOSEN1_Pos))
#define MATRIX_PRAS14_M2PR_Pos                _U_(8)                                               /**< (MATRIX_PRAS14) Master 2 Priority Position */
#define MATRIX_PRAS14_M2PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M2PR_Pos)                 /**< (MATRIX_PRAS14) Master 2 Priority Mask */
#define MATRIX_PRAS14_M2PR(value)             (MATRIX_PRAS14_M2PR_Msk & ((value) << MATRIX_PRAS14_M2PR_Pos))
#define MATRIX_PRAS14_LQOSEN2_Pos             _U_(10)                                              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS14_LQOSEN2_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN2_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS14_LQOSEN2(value)          (MATRIX_PRAS14_LQOSEN2_Msk & ((value) << MATRIX_PRAS14_LQOSEN2_Pos))
#define MATRIX_PRAS14_M3PR_Pos                _U_(12)                                              /**< (MATRIX_PRAS14) Master 3 Priority Position */
#define MATRIX_PRAS14_M3PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M3PR_Pos)                 /**< (MATRIX_PRAS14) Master 3 Priority Mask */
#define MATRIX_PRAS14_M3PR(value)             (MATRIX_PRAS14_M3PR_Msk & ((value) << MATRIX_PRAS14_M3PR_Pos))
#define MATRIX_PRAS14_LQOSEN3_Pos             _U_(14)                                              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS14_LQOSEN3_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN3_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS14_LQOSEN3(value)          (MATRIX_PRAS14_LQOSEN3_Msk & ((value) << MATRIX_PRAS14_LQOSEN3_Pos))
#define MATRIX_PRAS14_M4PR_Pos                _U_(16)                                              /**< (MATRIX_PRAS14) Master 4 Priority Position */
#define MATRIX_PRAS14_M4PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M4PR_Pos)                 /**< (MATRIX_PRAS14) Master 4 Priority Mask */
#define MATRIX_PRAS14_M4PR(value)             (MATRIX_PRAS14_M4PR_Msk & ((value) << MATRIX_PRAS14_M4PR_Pos))
#define MATRIX_PRAS14_LQOSEN4_Pos             _U_(18)                                              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS14_LQOSEN4_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN4_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS14_LQOSEN4(value)          (MATRIX_PRAS14_LQOSEN4_Msk & ((value) << MATRIX_PRAS14_LQOSEN4_Pos))
#define MATRIX_PRAS14_M5PR_Pos                _U_(20)                                              /**< (MATRIX_PRAS14) Master 5 Priority Position */
#define MATRIX_PRAS14_M5PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M5PR_Pos)                 /**< (MATRIX_PRAS14) Master 5 Priority Mask */
#define MATRIX_PRAS14_M5PR(value)             (MATRIX_PRAS14_M5PR_Msk & ((value) << MATRIX_PRAS14_M5PR_Pos))
#define MATRIX_PRAS14_LQOSEN5_Pos             _U_(22)                                              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS14_LQOSEN5_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN5_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS14_LQOSEN5(value)          (MATRIX_PRAS14_LQOSEN5_Msk & ((value) << MATRIX_PRAS14_LQOSEN5_Pos))
#define MATRIX_PRAS14_M6PR_Pos                _U_(24)                                              /**< (MATRIX_PRAS14) Master 6 Priority Position */
#define MATRIX_PRAS14_M6PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M6PR_Pos)                 /**< (MATRIX_PRAS14) Master 6 Priority Mask */
#define MATRIX_PRAS14_M6PR(value)             (MATRIX_PRAS14_M6PR_Msk & ((value) << MATRIX_PRAS14_M6PR_Pos))
#define MATRIX_PRAS14_LQOSEN6_Pos             _U_(26)                                              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS14_LQOSEN6_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN6_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS14_LQOSEN6(value)          (MATRIX_PRAS14_LQOSEN6_Msk & ((value) << MATRIX_PRAS14_LQOSEN6_Pos))
#define MATRIX_PRAS14_M7PR_Pos                _U_(28)                                              /**< (MATRIX_PRAS14) Master 7 Priority Position */
#define MATRIX_PRAS14_M7PR_Msk                (_U_(0x3) << MATRIX_PRAS14_M7PR_Pos)                 /**< (MATRIX_PRAS14) Master 7 Priority Mask */
#define MATRIX_PRAS14_M7PR(value)             (MATRIX_PRAS14_M7PR_Msk & ((value) << MATRIX_PRAS14_M7PR_Pos))
#define MATRIX_PRAS14_LQOSEN7_Pos             _U_(30)                                              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS14_LQOSEN7_Msk             (_U_(0x1) << MATRIX_PRAS14_LQOSEN7_Pos)              /**< (MATRIX_PRAS14) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS14_LQOSEN7(value)          (MATRIX_PRAS14_LQOSEN7_Msk & ((value) << MATRIX_PRAS14_LQOSEN7_Pos))
#define MATRIX_PRAS14_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRAS14) Register Mask  */


/* -------- MATRIX_PRBS14 : (MATRIX Offset: 0xF4) (R/W 32) Priority Register B for Slave 14 -------- */
#define MATRIX_PRBS14_M8PR_Pos                _U_(0)                                               /**< (MATRIX_PRBS14) Master 8 Priority Position */
#define MATRIX_PRBS14_M8PR_Msk                (_U_(0x3) << MATRIX_PRBS14_M8PR_Pos)                 /**< (MATRIX_PRBS14) Master 8 Priority Mask */
#define MATRIX_PRBS14_M8PR(value)             (MATRIX_PRBS14_M8PR_Msk & ((value) << MATRIX_PRBS14_M8PR_Pos))
#define MATRIX_PRBS14_LQOSEN8_Pos             _U_(2)                                               /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS14_LQOSEN8_Msk             (_U_(0x1) << MATRIX_PRBS14_LQOSEN8_Pos)              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS14_LQOSEN8(value)          (MATRIX_PRBS14_LQOSEN8_Msk & ((value) << MATRIX_PRBS14_LQOSEN8_Pos))
#define MATRIX_PRBS14_M9PR_Pos                _U_(4)                                               /**< (MATRIX_PRBS14) Master 9 Priority Position */
#define MATRIX_PRBS14_M9PR_Msk                (_U_(0x3) << MATRIX_PRBS14_M9PR_Pos)                 /**< (MATRIX_PRBS14) Master 9 Priority Mask */
#define MATRIX_PRBS14_M9PR(value)             (MATRIX_PRBS14_M9PR_Msk & ((value) << MATRIX_PRBS14_M9PR_Pos))
#define MATRIX_PRBS14_LQOSEN9_Pos             _U_(6)                                               /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS14_LQOSEN9_Msk             (_U_(0x1) << MATRIX_PRBS14_LQOSEN9_Pos)              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS14_LQOSEN9(value)          (MATRIX_PRBS14_LQOSEN9_Msk & ((value) << MATRIX_PRBS14_LQOSEN9_Pos))
#define MATRIX_PRBS14_M10PR_Pos               _U_(8)                                               /**< (MATRIX_PRBS14) Master 10 Priority Position */
#define MATRIX_PRBS14_M10PR_Msk               (_U_(0x3) << MATRIX_PRBS14_M10PR_Pos)                /**< (MATRIX_PRBS14) Master 10 Priority Mask */
#define MATRIX_PRBS14_M10PR(value)            (MATRIX_PRBS14_M10PR_Msk & ((value) << MATRIX_PRBS14_M10PR_Pos))
#define MATRIX_PRBS14_LQOSEN10_Pos            _U_(10)                                              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS14_LQOSEN10_Msk            (_U_(0x1) << MATRIX_PRBS14_LQOSEN10_Pos)             /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS14_LQOSEN10(value)         (MATRIX_PRBS14_LQOSEN10_Msk & ((value) << MATRIX_PRBS14_LQOSEN10_Pos))
#define MATRIX_PRBS14_M11PR_Pos               _U_(12)                                              /**< (MATRIX_PRBS14) Master 11 Priority Position */
#define MATRIX_PRBS14_M11PR_Msk               (_U_(0x3) << MATRIX_PRBS14_M11PR_Pos)                /**< (MATRIX_PRBS14) Master 11 Priority Mask */
#define MATRIX_PRBS14_M11PR(value)            (MATRIX_PRBS14_M11PR_Msk & ((value) << MATRIX_PRBS14_M11PR_Pos))
#define MATRIX_PRBS14_LQOSEN11_Pos            _U_(14)                                              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS14_LQOSEN11_Msk            (_U_(0x1) << MATRIX_PRBS14_LQOSEN11_Pos)             /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS14_LQOSEN11(value)         (MATRIX_PRBS14_LQOSEN11_Msk & ((value) << MATRIX_PRBS14_LQOSEN11_Pos))
#define MATRIX_PRBS14_M12PR_Pos               _U_(16)                                              /**< (MATRIX_PRBS14) Master 12 Priority Position */
#define MATRIX_PRBS14_M12PR_Msk               (_U_(0x3) << MATRIX_PRBS14_M12PR_Pos)                /**< (MATRIX_PRBS14) Master 12 Priority Mask */
#define MATRIX_PRBS14_M12PR(value)            (MATRIX_PRBS14_M12PR_Msk & ((value) << MATRIX_PRBS14_M12PR_Pos))
#define MATRIX_PRBS14_LQOSEN12_Pos            _U_(18)                                              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS14_LQOSEN12_Msk            (_U_(0x1) << MATRIX_PRBS14_LQOSEN12_Pos)             /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS14_LQOSEN12(value)         (MATRIX_PRBS14_LQOSEN12_Msk & ((value) << MATRIX_PRBS14_LQOSEN12_Pos))
#define MATRIX_PRBS14_M13PR_Pos               _U_(20)                                              /**< (MATRIX_PRBS14) Master 13 Priority Position */
#define MATRIX_PRBS14_M13PR_Msk               (_U_(0x3) << MATRIX_PRBS14_M13PR_Pos)                /**< (MATRIX_PRBS14) Master 13 Priority Mask */
#define MATRIX_PRBS14_M13PR(value)            (MATRIX_PRBS14_M13PR_Msk & ((value) << MATRIX_PRBS14_M13PR_Pos))
#define MATRIX_PRBS14_LQOSEN13_Pos            _U_(22)                                              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS14_LQOSEN13_Msk            (_U_(0x1) << MATRIX_PRBS14_LQOSEN13_Pos)             /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS14_LQOSEN13(value)         (MATRIX_PRBS14_LQOSEN13_Msk & ((value) << MATRIX_PRBS14_LQOSEN13_Pos))
#define MATRIX_PRBS14_M14PR_Pos               _U_(24)                                              /**< (MATRIX_PRBS14) Master 14 Priority Position */
#define MATRIX_PRBS14_M14PR_Msk               (_U_(0x3) << MATRIX_PRBS14_M14PR_Pos)                /**< (MATRIX_PRBS14) Master 14 Priority Mask */
#define MATRIX_PRBS14_M14PR(value)            (MATRIX_PRBS14_M14PR_Msk & ((value) << MATRIX_PRBS14_M14PR_Pos))
#define MATRIX_PRBS14_LQOSEN14_Pos            _U_(26)                                              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS14_LQOSEN14_Msk            (_U_(0x1) << MATRIX_PRBS14_LQOSEN14_Pos)             /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS14_LQOSEN14(value)         (MATRIX_PRBS14_LQOSEN14_Msk & ((value) << MATRIX_PRBS14_LQOSEN14_Pos))
#define MATRIX_PRBS14_M15PR_Pos               _U_(28)                                              /**< (MATRIX_PRBS14) Master 15 Priority Position */
#define MATRIX_PRBS14_M15PR_Msk               (_U_(0x3) << MATRIX_PRBS14_M15PR_Pos)                /**< (MATRIX_PRBS14) Master 15 Priority Mask */
#define MATRIX_PRBS14_M15PR(value)            (MATRIX_PRBS14_M15PR_Msk & ((value) << MATRIX_PRBS14_M15PR_Pos))
#define MATRIX_PRBS14_LQOSEN15_Pos            _U_(30)                                              /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS14_LQOSEN15_Msk            (_U_(0x1) << MATRIX_PRBS14_LQOSEN15_Pos)             /**< (MATRIX_PRBS14) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS14_LQOSEN15(value)         (MATRIX_PRBS14_LQOSEN15_Msk & ((value) << MATRIX_PRBS14_LQOSEN15_Pos))
#define MATRIX_PRBS14_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRBS14) Register Mask  */


/* -------- MATRIX_PRAS15 : (MATRIX Offset: 0xF8) (R/W 32) Priority Register A for Slave 15 -------- */
#define MATRIX_PRAS15_M0PR_Pos                _U_(0)                                               /**< (MATRIX_PRAS15) Master 0 Priority Position */
#define MATRIX_PRAS15_M0PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M0PR_Pos)                 /**< (MATRIX_PRAS15) Master 0 Priority Mask */
#define MATRIX_PRAS15_M0PR(value)             (MATRIX_PRAS15_M0PR_Msk & ((value) << MATRIX_PRAS15_M0PR_Pos))
#define MATRIX_PRAS15_LQOSEN0_Pos             _U_(2)                                               /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 0 Position */
#define MATRIX_PRAS15_LQOSEN0_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN0_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 0 Mask */
#define MATRIX_PRAS15_LQOSEN0(value)          (MATRIX_PRAS15_LQOSEN0_Msk & ((value) << MATRIX_PRAS15_LQOSEN0_Pos))
#define MATRIX_PRAS15_M1PR_Pos                _U_(4)                                               /**< (MATRIX_PRAS15) Master 1 Priority Position */
#define MATRIX_PRAS15_M1PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M1PR_Pos)                 /**< (MATRIX_PRAS15) Master 1 Priority Mask */
#define MATRIX_PRAS15_M1PR(value)             (MATRIX_PRAS15_M1PR_Msk & ((value) << MATRIX_PRAS15_M1PR_Pos))
#define MATRIX_PRAS15_LQOSEN1_Pos             _U_(6)                                               /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 1 Position */
#define MATRIX_PRAS15_LQOSEN1_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN1_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 1 Mask */
#define MATRIX_PRAS15_LQOSEN1(value)          (MATRIX_PRAS15_LQOSEN1_Msk & ((value) << MATRIX_PRAS15_LQOSEN1_Pos))
#define MATRIX_PRAS15_M2PR_Pos                _U_(8)                                               /**< (MATRIX_PRAS15) Master 2 Priority Position */
#define MATRIX_PRAS15_M2PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M2PR_Pos)                 /**< (MATRIX_PRAS15) Master 2 Priority Mask */
#define MATRIX_PRAS15_M2PR(value)             (MATRIX_PRAS15_M2PR_Msk & ((value) << MATRIX_PRAS15_M2PR_Pos))
#define MATRIX_PRAS15_LQOSEN2_Pos             _U_(10)                                              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 2 Position */
#define MATRIX_PRAS15_LQOSEN2_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN2_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 2 Mask */
#define MATRIX_PRAS15_LQOSEN2(value)          (MATRIX_PRAS15_LQOSEN2_Msk & ((value) << MATRIX_PRAS15_LQOSEN2_Pos))
#define MATRIX_PRAS15_M3PR_Pos                _U_(12)                                              /**< (MATRIX_PRAS15) Master 3 Priority Position */
#define MATRIX_PRAS15_M3PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M3PR_Pos)                 /**< (MATRIX_PRAS15) Master 3 Priority Mask */
#define MATRIX_PRAS15_M3PR(value)             (MATRIX_PRAS15_M3PR_Msk & ((value) << MATRIX_PRAS15_M3PR_Pos))
#define MATRIX_PRAS15_LQOSEN3_Pos             _U_(14)                                              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 3 Position */
#define MATRIX_PRAS15_LQOSEN3_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN3_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 3 Mask */
#define MATRIX_PRAS15_LQOSEN3(value)          (MATRIX_PRAS15_LQOSEN3_Msk & ((value) << MATRIX_PRAS15_LQOSEN3_Pos))
#define MATRIX_PRAS15_M4PR_Pos                _U_(16)                                              /**< (MATRIX_PRAS15) Master 4 Priority Position */
#define MATRIX_PRAS15_M4PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M4PR_Pos)                 /**< (MATRIX_PRAS15) Master 4 Priority Mask */
#define MATRIX_PRAS15_M4PR(value)             (MATRIX_PRAS15_M4PR_Msk & ((value) << MATRIX_PRAS15_M4PR_Pos))
#define MATRIX_PRAS15_LQOSEN4_Pos             _U_(18)                                              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 4 Position */
#define MATRIX_PRAS15_LQOSEN4_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN4_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 4 Mask */
#define MATRIX_PRAS15_LQOSEN4(value)          (MATRIX_PRAS15_LQOSEN4_Msk & ((value) << MATRIX_PRAS15_LQOSEN4_Pos))
#define MATRIX_PRAS15_M5PR_Pos                _U_(20)                                              /**< (MATRIX_PRAS15) Master 5 Priority Position */
#define MATRIX_PRAS15_M5PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M5PR_Pos)                 /**< (MATRIX_PRAS15) Master 5 Priority Mask */
#define MATRIX_PRAS15_M5PR(value)             (MATRIX_PRAS15_M5PR_Msk & ((value) << MATRIX_PRAS15_M5PR_Pos))
#define MATRIX_PRAS15_LQOSEN5_Pos             _U_(22)                                              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 5 Position */
#define MATRIX_PRAS15_LQOSEN5_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN5_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 5 Mask */
#define MATRIX_PRAS15_LQOSEN5(value)          (MATRIX_PRAS15_LQOSEN5_Msk & ((value) << MATRIX_PRAS15_LQOSEN5_Pos))
#define MATRIX_PRAS15_M6PR_Pos                _U_(24)                                              /**< (MATRIX_PRAS15) Master 6 Priority Position */
#define MATRIX_PRAS15_M6PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M6PR_Pos)                 /**< (MATRIX_PRAS15) Master 6 Priority Mask */
#define MATRIX_PRAS15_M6PR(value)             (MATRIX_PRAS15_M6PR_Msk & ((value) << MATRIX_PRAS15_M6PR_Pos))
#define MATRIX_PRAS15_LQOSEN6_Pos             _U_(26)                                              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 6 Position */
#define MATRIX_PRAS15_LQOSEN6_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN6_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 6 Mask */
#define MATRIX_PRAS15_LQOSEN6(value)          (MATRIX_PRAS15_LQOSEN6_Msk & ((value) << MATRIX_PRAS15_LQOSEN6_Pos))
#define MATRIX_PRAS15_M7PR_Pos                _U_(28)                                              /**< (MATRIX_PRAS15) Master 7 Priority Position */
#define MATRIX_PRAS15_M7PR_Msk                (_U_(0x3) << MATRIX_PRAS15_M7PR_Pos)                 /**< (MATRIX_PRAS15) Master 7 Priority Mask */
#define MATRIX_PRAS15_M7PR(value)             (MATRIX_PRAS15_M7PR_Msk & ((value) << MATRIX_PRAS15_M7PR_Pos))
#define MATRIX_PRAS15_LQOSEN7_Pos             _U_(30)                                              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 7 Position */
#define MATRIX_PRAS15_LQOSEN7_Msk             (_U_(0x1) << MATRIX_PRAS15_LQOSEN7_Pos)              /**< (MATRIX_PRAS15) Latency Quality of Service Enable for Master 7 Mask */
#define MATRIX_PRAS15_LQOSEN7(value)          (MATRIX_PRAS15_LQOSEN7_Msk & ((value) << MATRIX_PRAS15_LQOSEN7_Pos))
#define MATRIX_PRAS15_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRAS15) Register Mask  */


/* -------- MATRIX_PRBS15 : (MATRIX Offset: 0xFC) (R/W 32) Priority Register B for Slave 15 -------- */
#define MATRIX_PRBS15_M8PR_Pos                _U_(0)                                               /**< (MATRIX_PRBS15) Master 8 Priority Position */
#define MATRIX_PRBS15_M8PR_Msk                (_U_(0x3) << MATRIX_PRBS15_M8PR_Pos)                 /**< (MATRIX_PRBS15) Master 8 Priority Mask */
#define MATRIX_PRBS15_M8PR(value)             (MATRIX_PRBS15_M8PR_Msk & ((value) << MATRIX_PRBS15_M8PR_Pos))
#define MATRIX_PRBS15_LQOSEN8_Pos             _U_(2)                                               /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 8 Position */
#define MATRIX_PRBS15_LQOSEN8_Msk             (_U_(0x1) << MATRIX_PRBS15_LQOSEN8_Pos)              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 8 Mask */
#define MATRIX_PRBS15_LQOSEN8(value)          (MATRIX_PRBS15_LQOSEN8_Msk & ((value) << MATRIX_PRBS15_LQOSEN8_Pos))
#define MATRIX_PRBS15_M9PR_Pos                _U_(4)                                               /**< (MATRIX_PRBS15) Master 9 Priority Position */
#define MATRIX_PRBS15_M9PR_Msk                (_U_(0x3) << MATRIX_PRBS15_M9PR_Pos)                 /**< (MATRIX_PRBS15) Master 9 Priority Mask */
#define MATRIX_PRBS15_M9PR(value)             (MATRIX_PRBS15_M9PR_Msk & ((value) << MATRIX_PRBS15_M9PR_Pos))
#define MATRIX_PRBS15_LQOSEN9_Pos             _U_(6)                                               /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 9 Position */
#define MATRIX_PRBS15_LQOSEN9_Msk             (_U_(0x1) << MATRIX_PRBS15_LQOSEN9_Pos)              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 9 Mask */
#define MATRIX_PRBS15_LQOSEN9(value)          (MATRIX_PRBS15_LQOSEN9_Msk & ((value) << MATRIX_PRBS15_LQOSEN9_Pos))
#define MATRIX_PRBS15_M10PR_Pos               _U_(8)                                               /**< (MATRIX_PRBS15) Master 10 Priority Position */
#define MATRIX_PRBS15_M10PR_Msk               (_U_(0x3) << MATRIX_PRBS15_M10PR_Pos)                /**< (MATRIX_PRBS15) Master 10 Priority Mask */
#define MATRIX_PRBS15_M10PR(value)            (MATRIX_PRBS15_M10PR_Msk & ((value) << MATRIX_PRBS15_M10PR_Pos))
#define MATRIX_PRBS15_LQOSEN10_Pos            _U_(10)                                              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 10 Position */
#define MATRIX_PRBS15_LQOSEN10_Msk            (_U_(0x1) << MATRIX_PRBS15_LQOSEN10_Pos)             /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 10 Mask */
#define MATRIX_PRBS15_LQOSEN10(value)         (MATRIX_PRBS15_LQOSEN10_Msk & ((value) << MATRIX_PRBS15_LQOSEN10_Pos))
#define MATRIX_PRBS15_M11PR_Pos               _U_(12)                                              /**< (MATRIX_PRBS15) Master 11 Priority Position */
#define MATRIX_PRBS15_M11PR_Msk               (_U_(0x3) << MATRIX_PRBS15_M11PR_Pos)                /**< (MATRIX_PRBS15) Master 11 Priority Mask */
#define MATRIX_PRBS15_M11PR(value)            (MATRIX_PRBS15_M11PR_Msk & ((value) << MATRIX_PRBS15_M11PR_Pos))
#define MATRIX_PRBS15_LQOSEN11_Pos            _U_(14)                                              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 11 Position */
#define MATRIX_PRBS15_LQOSEN11_Msk            (_U_(0x1) << MATRIX_PRBS15_LQOSEN11_Pos)             /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 11 Mask */
#define MATRIX_PRBS15_LQOSEN11(value)         (MATRIX_PRBS15_LQOSEN11_Msk & ((value) << MATRIX_PRBS15_LQOSEN11_Pos))
#define MATRIX_PRBS15_M12PR_Pos               _U_(16)                                              /**< (MATRIX_PRBS15) Master 12 Priority Position */
#define MATRIX_PRBS15_M12PR_Msk               (_U_(0x3) << MATRIX_PRBS15_M12PR_Pos)                /**< (MATRIX_PRBS15) Master 12 Priority Mask */
#define MATRIX_PRBS15_M12PR(value)            (MATRIX_PRBS15_M12PR_Msk & ((value) << MATRIX_PRBS15_M12PR_Pos))
#define MATRIX_PRBS15_LQOSEN12_Pos            _U_(18)                                              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 12 Position */
#define MATRIX_PRBS15_LQOSEN12_Msk            (_U_(0x1) << MATRIX_PRBS15_LQOSEN12_Pos)             /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 12 Mask */
#define MATRIX_PRBS15_LQOSEN12(value)         (MATRIX_PRBS15_LQOSEN12_Msk & ((value) << MATRIX_PRBS15_LQOSEN12_Pos))
#define MATRIX_PRBS15_M13PR_Pos               _U_(20)                                              /**< (MATRIX_PRBS15) Master 13 Priority Position */
#define MATRIX_PRBS15_M13PR_Msk               (_U_(0x3) << MATRIX_PRBS15_M13PR_Pos)                /**< (MATRIX_PRBS15) Master 13 Priority Mask */
#define MATRIX_PRBS15_M13PR(value)            (MATRIX_PRBS15_M13PR_Msk & ((value) << MATRIX_PRBS15_M13PR_Pos))
#define MATRIX_PRBS15_LQOSEN13_Pos            _U_(22)                                              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 13 Position */
#define MATRIX_PRBS15_LQOSEN13_Msk            (_U_(0x1) << MATRIX_PRBS15_LQOSEN13_Pos)             /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 13 Mask */
#define MATRIX_PRBS15_LQOSEN13(value)         (MATRIX_PRBS15_LQOSEN13_Msk & ((value) << MATRIX_PRBS15_LQOSEN13_Pos))
#define MATRIX_PRBS15_M14PR_Pos               _U_(24)                                              /**< (MATRIX_PRBS15) Master 14 Priority Position */
#define MATRIX_PRBS15_M14PR_Msk               (_U_(0x3) << MATRIX_PRBS15_M14PR_Pos)                /**< (MATRIX_PRBS15) Master 14 Priority Mask */
#define MATRIX_PRBS15_M14PR(value)            (MATRIX_PRBS15_M14PR_Msk & ((value) << MATRIX_PRBS15_M14PR_Pos))
#define MATRIX_PRBS15_LQOSEN14_Pos            _U_(26)                                              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 14 Position */
#define MATRIX_PRBS15_LQOSEN14_Msk            (_U_(0x1) << MATRIX_PRBS15_LQOSEN14_Pos)             /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 14 Mask */
#define MATRIX_PRBS15_LQOSEN14(value)         (MATRIX_PRBS15_LQOSEN14_Msk & ((value) << MATRIX_PRBS15_LQOSEN14_Pos))
#define MATRIX_PRBS15_M15PR_Pos               _U_(28)                                              /**< (MATRIX_PRBS15) Master 15 Priority Position */
#define MATRIX_PRBS15_M15PR_Msk               (_U_(0x3) << MATRIX_PRBS15_M15PR_Pos)                /**< (MATRIX_PRBS15) Master 15 Priority Mask */
#define MATRIX_PRBS15_M15PR(value)            (MATRIX_PRBS15_M15PR_Msk & ((value) << MATRIX_PRBS15_M15PR_Pos))
#define MATRIX_PRBS15_LQOSEN15_Pos            _U_(30)                                              /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 15 Position */
#define MATRIX_PRBS15_LQOSEN15_Msk            (_U_(0x1) << MATRIX_PRBS15_LQOSEN15_Pos)             /**< (MATRIX_PRBS15) Latency Quality of Service Enable for Master 15 Mask */
#define MATRIX_PRBS15_LQOSEN15(value)         (MATRIX_PRBS15_LQOSEN15_Msk & ((value) << MATRIX_PRBS15_LQOSEN15_Pos))
#define MATRIX_PRBS15_Msk                     _U_(0x77777777)                                      /**< (MATRIX_PRBS15) Register Mask  */


/* -------- MATRIX_MRCR : (MATRIX Offset: 0x100) (R/W 32) Master Remap Control Register -------- */
#define MATRIX_MRCR_RCB0_Pos                  _U_(0)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 0 Position */
#define MATRIX_MRCR_RCB0_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB0_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 0 Mask */
#define MATRIX_MRCR_RCB0(value)               (MATRIX_MRCR_RCB0_Msk & ((value) << MATRIX_MRCR_RCB0_Pos))
#define MATRIX_MRCR_RCB1_Pos                  _U_(1)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 1 Position */
#define MATRIX_MRCR_RCB1_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB1_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 1 Mask */
#define MATRIX_MRCR_RCB1(value)               (MATRIX_MRCR_RCB1_Msk & ((value) << MATRIX_MRCR_RCB1_Pos))
#define MATRIX_MRCR_RCB2_Pos                  _U_(2)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 2 Position */
#define MATRIX_MRCR_RCB2_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB2_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 2 Mask */
#define MATRIX_MRCR_RCB2(value)               (MATRIX_MRCR_RCB2_Msk & ((value) << MATRIX_MRCR_RCB2_Pos))
#define MATRIX_MRCR_RCB3_Pos                  _U_(3)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 3 Position */
#define MATRIX_MRCR_RCB3_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB3_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 3 Mask */
#define MATRIX_MRCR_RCB3(value)               (MATRIX_MRCR_RCB3_Msk & ((value) << MATRIX_MRCR_RCB3_Pos))
#define MATRIX_MRCR_RCB4_Pos                  _U_(4)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 4 Position */
#define MATRIX_MRCR_RCB4_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB4_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 4 Mask */
#define MATRIX_MRCR_RCB4(value)               (MATRIX_MRCR_RCB4_Msk & ((value) << MATRIX_MRCR_RCB4_Pos))
#define MATRIX_MRCR_RCB5_Pos                  _U_(5)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 5 Position */
#define MATRIX_MRCR_RCB5_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB5_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 5 Mask */
#define MATRIX_MRCR_RCB5(value)               (MATRIX_MRCR_RCB5_Msk & ((value) << MATRIX_MRCR_RCB5_Pos))
#define MATRIX_MRCR_RCB6_Pos                  _U_(6)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 6 Position */
#define MATRIX_MRCR_RCB6_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB6_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 6 Mask */
#define MATRIX_MRCR_RCB6(value)               (MATRIX_MRCR_RCB6_Msk & ((value) << MATRIX_MRCR_RCB6_Pos))
#define MATRIX_MRCR_RCB7_Pos                  _U_(7)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 7 Position */
#define MATRIX_MRCR_RCB7_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB7_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 7 Mask */
#define MATRIX_MRCR_RCB7(value)               (MATRIX_MRCR_RCB7_Msk & ((value) << MATRIX_MRCR_RCB7_Pos))
#define MATRIX_MRCR_RCB8_Pos                  _U_(8)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 8 Position */
#define MATRIX_MRCR_RCB8_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB8_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 8 Mask */
#define MATRIX_MRCR_RCB8(value)               (MATRIX_MRCR_RCB8_Msk & ((value) << MATRIX_MRCR_RCB8_Pos))
#define MATRIX_MRCR_RCB9_Pos                  _U_(9)                                               /**< (MATRIX_MRCR) Remap Command Bit for Master 9 Position */
#define MATRIX_MRCR_RCB9_Msk                  (_U_(0x1) << MATRIX_MRCR_RCB9_Pos)                   /**< (MATRIX_MRCR) Remap Command Bit for Master 9 Mask */
#define MATRIX_MRCR_RCB9(value)               (MATRIX_MRCR_RCB9_Msk & ((value) << MATRIX_MRCR_RCB9_Pos))
#define MATRIX_MRCR_RCB10_Pos                 _U_(10)                                              /**< (MATRIX_MRCR) Remap Command Bit for Master 10 Position */
#define MATRIX_MRCR_RCB10_Msk                 (_U_(0x1) << MATRIX_MRCR_RCB10_Pos)                  /**< (MATRIX_MRCR) Remap Command Bit for Master 10 Mask */
#define MATRIX_MRCR_RCB10(value)              (MATRIX_MRCR_RCB10_Msk & ((value) << MATRIX_MRCR_RCB10_Pos))
#define MATRIX_MRCR_RCB11_Pos                 _U_(11)                                              /**< (MATRIX_MRCR) Remap Command Bit for Master 11 Position */
#define MATRIX_MRCR_RCB11_Msk                 (_U_(0x1) << MATRIX_MRCR_RCB11_Pos)                  /**< (MATRIX_MRCR) Remap Command Bit for Master 11 Mask */
#define MATRIX_MRCR_RCB11(value)              (MATRIX_MRCR_RCB11_Msk & ((value) << MATRIX_MRCR_RCB11_Pos))
#define MATRIX_MRCR_RCB12_Pos                 _U_(12)                                              /**< (MATRIX_MRCR) Remap Command Bit for Master 12 Position */
#define MATRIX_MRCR_RCB12_Msk                 (_U_(0x1) << MATRIX_MRCR_RCB12_Pos)                  /**< (MATRIX_MRCR) Remap Command Bit for Master 12 Mask */
#define MATRIX_MRCR_RCB12(value)              (MATRIX_MRCR_RCB12_Msk & ((value) << MATRIX_MRCR_RCB12_Pos))
#define MATRIX_MRCR_RCB13_Pos                 _U_(13)                                              /**< (MATRIX_MRCR) Remap Command Bit for Master 13 Position */
#define MATRIX_MRCR_RCB13_Msk                 (_U_(0x1) << MATRIX_MRCR_RCB13_Pos)                  /**< (MATRIX_MRCR) Remap Command Bit for Master 13 Mask */
#define MATRIX_MRCR_RCB13(value)              (MATRIX_MRCR_RCB13_Msk & ((value) << MATRIX_MRCR_RCB13_Pos))
#define MATRIX_MRCR_RCB14_Pos                 _U_(14)                                              /**< (MATRIX_MRCR) Remap Command Bit for Master 14 Position */
#define MATRIX_MRCR_RCB14_Msk                 (_U_(0x1) << MATRIX_MRCR_RCB14_Pos)                  /**< (MATRIX_MRCR) Remap Command Bit for Master 14 Mask */
#define MATRIX_MRCR_RCB14(value)              (MATRIX_MRCR_RCB14_Msk & ((value) << MATRIX_MRCR_RCB14_Pos))
#define MATRIX_MRCR_RCB15_Pos                 _U_(15)                                              /**< (MATRIX_MRCR) Remap Command Bit for Master 15 Position */
#define MATRIX_MRCR_RCB15_Msk                 (_U_(0x1) << MATRIX_MRCR_RCB15_Pos)                  /**< (MATRIX_MRCR) Remap Command Bit for Master 15 Mask */
#define MATRIX_MRCR_RCB15(value)              (MATRIX_MRCR_RCB15_Msk & ((value) << MATRIX_MRCR_RCB15_Pos))
#define MATRIX_MRCR_Msk                       _U_(0x0000FFFF)                                      /**< (MATRIX_MRCR) Register Mask  */

#define MATRIX_MRCR_RCB_Pos                   _U_(0)                                               /**< (MATRIX_MRCR Position) Remap Command Bit for Master x5 */
#define MATRIX_MRCR_RCB_Msk                   (_U_(0xFFFF) << MATRIX_MRCR_RCB_Pos)                 /**< (MATRIX_MRCR Mask) RCB */
#define MATRIX_MRCR_RCB(value)                (MATRIX_MRCR_RCB_Msk & ((value) << MATRIX_MRCR_RCB_Pos)) 

/* -------- MATRIX_MEIER : (MATRIX Offset: 0x150) ( /W 32) Master Error Interrupt Enable Register -------- */
#define MATRIX_MEIER_MERR0_Pos                _U_(0)                                               /**< (MATRIX_MEIER) Master 0 Access Error Position */
#define MATRIX_MEIER_MERR0_Msk                (_U_(0x1) << MATRIX_MEIER_MERR0_Pos)                 /**< (MATRIX_MEIER) Master 0 Access Error Mask */
#define MATRIX_MEIER_MERR0(value)             (MATRIX_MEIER_MERR0_Msk & ((value) << MATRIX_MEIER_MERR0_Pos))
#define MATRIX_MEIER_MERR1_Pos                _U_(1)                                               /**< (MATRIX_MEIER) Master 1 Access Error Position */
#define MATRIX_MEIER_MERR1_Msk                (_U_(0x1) << MATRIX_MEIER_MERR1_Pos)                 /**< (MATRIX_MEIER) Master 1 Access Error Mask */
#define MATRIX_MEIER_MERR1(value)             (MATRIX_MEIER_MERR1_Msk & ((value) << MATRIX_MEIER_MERR1_Pos))
#define MATRIX_MEIER_MERR2_Pos                _U_(2)                                               /**< (MATRIX_MEIER) Master 2 Access Error Position */
#define MATRIX_MEIER_MERR2_Msk                (_U_(0x1) << MATRIX_MEIER_MERR2_Pos)                 /**< (MATRIX_MEIER) Master 2 Access Error Mask */
#define MATRIX_MEIER_MERR2(value)             (MATRIX_MEIER_MERR2_Msk & ((value) << MATRIX_MEIER_MERR2_Pos))
#define MATRIX_MEIER_MERR3_Pos                _U_(3)                                               /**< (MATRIX_MEIER) Master 3 Access Error Position */
#define MATRIX_MEIER_MERR3_Msk                (_U_(0x1) << MATRIX_MEIER_MERR3_Pos)                 /**< (MATRIX_MEIER) Master 3 Access Error Mask */
#define MATRIX_MEIER_MERR3(value)             (MATRIX_MEIER_MERR3_Msk & ((value) << MATRIX_MEIER_MERR3_Pos))
#define MATRIX_MEIER_MERR4_Pos                _U_(4)                                               /**< (MATRIX_MEIER) Master 4 Access Error Position */
#define MATRIX_MEIER_MERR4_Msk                (_U_(0x1) << MATRIX_MEIER_MERR4_Pos)                 /**< (MATRIX_MEIER) Master 4 Access Error Mask */
#define MATRIX_MEIER_MERR4(value)             (MATRIX_MEIER_MERR4_Msk & ((value) << MATRIX_MEIER_MERR4_Pos))
#define MATRIX_MEIER_MERR5_Pos                _U_(5)                                               /**< (MATRIX_MEIER) Master 5 Access Error Position */
#define MATRIX_MEIER_MERR5_Msk                (_U_(0x1) << MATRIX_MEIER_MERR5_Pos)                 /**< (MATRIX_MEIER) Master 5 Access Error Mask */
#define MATRIX_MEIER_MERR5(value)             (MATRIX_MEIER_MERR5_Msk & ((value) << MATRIX_MEIER_MERR5_Pos))
#define MATRIX_MEIER_MERR6_Pos                _U_(6)                                               /**< (MATRIX_MEIER) Master 6 Access Error Position */
#define MATRIX_MEIER_MERR6_Msk                (_U_(0x1) << MATRIX_MEIER_MERR6_Pos)                 /**< (MATRIX_MEIER) Master 6 Access Error Mask */
#define MATRIX_MEIER_MERR6(value)             (MATRIX_MEIER_MERR6_Msk & ((value) << MATRIX_MEIER_MERR6_Pos))
#define MATRIX_MEIER_MERR7_Pos                _U_(7)                                               /**< (MATRIX_MEIER) Master 7 Access Error Position */
#define MATRIX_MEIER_MERR7_Msk                (_U_(0x1) << MATRIX_MEIER_MERR7_Pos)                 /**< (MATRIX_MEIER) Master 7 Access Error Mask */
#define MATRIX_MEIER_MERR7(value)             (MATRIX_MEIER_MERR7_Msk & ((value) << MATRIX_MEIER_MERR7_Pos))
#define MATRIX_MEIER_MERR8_Pos                _U_(8)                                               /**< (MATRIX_MEIER) Master 8 Access Error Position */
#define MATRIX_MEIER_MERR8_Msk                (_U_(0x1) << MATRIX_MEIER_MERR8_Pos)                 /**< (MATRIX_MEIER) Master 8 Access Error Mask */
#define MATRIX_MEIER_MERR8(value)             (MATRIX_MEIER_MERR8_Msk & ((value) << MATRIX_MEIER_MERR8_Pos))
#define MATRIX_MEIER_MERR9_Pos                _U_(9)                                               /**< (MATRIX_MEIER) Master 9 Access Error Position */
#define MATRIX_MEIER_MERR9_Msk                (_U_(0x1) << MATRIX_MEIER_MERR9_Pos)                 /**< (MATRIX_MEIER) Master 9 Access Error Mask */
#define MATRIX_MEIER_MERR9(value)             (MATRIX_MEIER_MERR9_Msk & ((value) << MATRIX_MEIER_MERR9_Pos))
#define MATRIX_MEIER_MERR10_Pos               _U_(10)                                              /**< (MATRIX_MEIER) Master 10 Access Error Position */
#define MATRIX_MEIER_MERR10_Msk               (_U_(0x1) << MATRIX_MEIER_MERR10_Pos)                /**< (MATRIX_MEIER) Master 10 Access Error Mask */
#define MATRIX_MEIER_MERR10(value)            (MATRIX_MEIER_MERR10_Msk & ((value) << MATRIX_MEIER_MERR10_Pos))
#define MATRIX_MEIER_MERR11_Pos               _U_(11)                                              /**< (MATRIX_MEIER) Master 11 Access Error Position */
#define MATRIX_MEIER_MERR11_Msk               (_U_(0x1) << MATRIX_MEIER_MERR11_Pos)                /**< (MATRIX_MEIER) Master 11 Access Error Mask */
#define MATRIX_MEIER_MERR11(value)            (MATRIX_MEIER_MERR11_Msk & ((value) << MATRIX_MEIER_MERR11_Pos))
#define MATRIX_MEIER_MERR12_Pos               _U_(12)                                              /**< (MATRIX_MEIER) Master 12 Access Error Position */
#define MATRIX_MEIER_MERR12_Msk               (_U_(0x1) << MATRIX_MEIER_MERR12_Pos)                /**< (MATRIX_MEIER) Master 12 Access Error Mask */
#define MATRIX_MEIER_MERR12(value)            (MATRIX_MEIER_MERR12_Msk & ((value) << MATRIX_MEIER_MERR12_Pos))
#define MATRIX_MEIER_MERR13_Pos               _U_(13)                                              /**< (MATRIX_MEIER) Master 13 Access Error Position */
#define MATRIX_MEIER_MERR13_Msk               (_U_(0x1) << MATRIX_MEIER_MERR13_Pos)                /**< (MATRIX_MEIER) Master 13 Access Error Mask */
#define MATRIX_MEIER_MERR13(value)            (MATRIX_MEIER_MERR13_Msk & ((value) << MATRIX_MEIER_MERR13_Pos))
#define MATRIX_MEIER_MERR14_Pos               _U_(14)                                              /**< (MATRIX_MEIER) Master 14 Access Error Position */
#define MATRIX_MEIER_MERR14_Msk               (_U_(0x1) << MATRIX_MEIER_MERR14_Pos)                /**< (MATRIX_MEIER) Master 14 Access Error Mask */
#define MATRIX_MEIER_MERR14(value)            (MATRIX_MEIER_MERR14_Msk & ((value) << MATRIX_MEIER_MERR14_Pos))
#define MATRIX_MEIER_MERR15_Pos               _U_(15)                                              /**< (MATRIX_MEIER) Master 15 Access Error Position */
#define MATRIX_MEIER_MERR15_Msk               (_U_(0x1) << MATRIX_MEIER_MERR15_Pos)                /**< (MATRIX_MEIER) Master 15 Access Error Mask */
#define MATRIX_MEIER_MERR15(value)            (MATRIX_MEIER_MERR15_Msk & ((value) << MATRIX_MEIER_MERR15_Pos))
#define MATRIX_MEIER_Msk                      _U_(0x0000FFFF)                                      /**< (MATRIX_MEIER) Register Mask  */

#define MATRIX_MEIER_MERR_Pos                 _U_(0)                                               /**< (MATRIX_MEIER Position) Master x5 Access Error */
#define MATRIX_MEIER_MERR_Msk                 (_U_(0xFFFF) << MATRIX_MEIER_MERR_Pos)               /**< (MATRIX_MEIER Mask) MERR */
#define MATRIX_MEIER_MERR(value)              (MATRIX_MEIER_MERR_Msk & ((value) << MATRIX_MEIER_MERR_Pos)) 

/* -------- MATRIX_MEIDR : (MATRIX Offset: 0x154) ( /W 32) Master Error Interrupt Disable Register -------- */
#define MATRIX_MEIDR_MERR0_Pos                _U_(0)                                               /**< (MATRIX_MEIDR) Master 0 Access Error Position */
#define MATRIX_MEIDR_MERR0_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR0_Pos)                 /**< (MATRIX_MEIDR) Master 0 Access Error Mask */
#define MATRIX_MEIDR_MERR0(value)             (MATRIX_MEIDR_MERR0_Msk & ((value) << MATRIX_MEIDR_MERR0_Pos))
#define MATRIX_MEIDR_MERR1_Pos                _U_(1)                                               /**< (MATRIX_MEIDR) Master 1 Access Error Position */
#define MATRIX_MEIDR_MERR1_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR1_Pos)                 /**< (MATRIX_MEIDR) Master 1 Access Error Mask */
#define MATRIX_MEIDR_MERR1(value)             (MATRIX_MEIDR_MERR1_Msk & ((value) << MATRIX_MEIDR_MERR1_Pos))
#define MATRIX_MEIDR_MERR2_Pos                _U_(2)                                               /**< (MATRIX_MEIDR) Master 2 Access Error Position */
#define MATRIX_MEIDR_MERR2_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR2_Pos)                 /**< (MATRIX_MEIDR) Master 2 Access Error Mask */
#define MATRIX_MEIDR_MERR2(value)             (MATRIX_MEIDR_MERR2_Msk & ((value) << MATRIX_MEIDR_MERR2_Pos))
#define MATRIX_MEIDR_MERR3_Pos                _U_(3)                                               /**< (MATRIX_MEIDR) Master 3 Access Error Position */
#define MATRIX_MEIDR_MERR3_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR3_Pos)                 /**< (MATRIX_MEIDR) Master 3 Access Error Mask */
#define MATRIX_MEIDR_MERR3(value)             (MATRIX_MEIDR_MERR3_Msk & ((value) << MATRIX_MEIDR_MERR3_Pos))
#define MATRIX_MEIDR_MERR4_Pos                _U_(4)                                               /**< (MATRIX_MEIDR) Master 4 Access Error Position */
#define MATRIX_MEIDR_MERR4_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR4_Pos)                 /**< (MATRIX_MEIDR) Master 4 Access Error Mask */
#define MATRIX_MEIDR_MERR4(value)             (MATRIX_MEIDR_MERR4_Msk & ((value) << MATRIX_MEIDR_MERR4_Pos))
#define MATRIX_MEIDR_MERR5_Pos                _U_(5)                                               /**< (MATRIX_MEIDR) Master 5 Access Error Position */
#define MATRIX_MEIDR_MERR5_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR5_Pos)                 /**< (MATRIX_MEIDR) Master 5 Access Error Mask */
#define MATRIX_MEIDR_MERR5(value)             (MATRIX_MEIDR_MERR5_Msk & ((value) << MATRIX_MEIDR_MERR5_Pos))
#define MATRIX_MEIDR_MERR6_Pos                _U_(6)                                               /**< (MATRIX_MEIDR) Master 6 Access Error Position */
#define MATRIX_MEIDR_MERR6_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR6_Pos)                 /**< (MATRIX_MEIDR) Master 6 Access Error Mask */
#define MATRIX_MEIDR_MERR6(value)             (MATRIX_MEIDR_MERR6_Msk & ((value) << MATRIX_MEIDR_MERR6_Pos))
#define MATRIX_MEIDR_MERR7_Pos                _U_(7)                                               /**< (MATRIX_MEIDR) Master 7 Access Error Position */
#define MATRIX_MEIDR_MERR7_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR7_Pos)                 /**< (MATRIX_MEIDR) Master 7 Access Error Mask */
#define MATRIX_MEIDR_MERR7(value)             (MATRIX_MEIDR_MERR7_Msk & ((value) << MATRIX_MEIDR_MERR7_Pos))
#define MATRIX_MEIDR_MERR8_Pos                _U_(8)                                               /**< (MATRIX_MEIDR) Master 8 Access Error Position */
#define MATRIX_MEIDR_MERR8_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR8_Pos)                 /**< (MATRIX_MEIDR) Master 8 Access Error Mask */
#define MATRIX_MEIDR_MERR8(value)             (MATRIX_MEIDR_MERR8_Msk & ((value) << MATRIX_MEIDR_MERR8_Pos))
#define MATRIX_MEIDR_MERR9_Pos                _U_(9)                                               /**< (MATRIX_MEIDR) Master 9 Access Error Position */
#define MATRIX_MEIDR_MERR9_Msk                (_U_(0x1) << MATRIX_MEIDR_MERR9_Pos)                 /**< (MATRIX_MEIDR) Master 9 Access Error Mask */
#define MATRIX_MEIDR_MERR9(value)             (MATRIX_MEIDR_MERR9_Msk & ((value) << MATRIX_MEIDR_MERR9_Pos))
#define MATRIX_MEIDR_MERR10_Pos               _U_(10)                                              /**< (MATRIX_MEIDR) Master 10 Access Error Position */
#define MATRIX_MEIDR_MERR10_Msk               (_U_(0x1) << MATRIX_MEIDR_MERR10_Pos)                /**< (MATRIX_MEIDR) Master 10 Access Error Mask */
#define MATRIX_MEIDR_MERR10(value)            (MATRIX_MEIDR_MERR10_Msk & ((value) << MATRIX_MEIDR_MERR10_Pos))
#define MATRIX_MEIDR_MERR11_Pos               _U_(11)                                              /**< (MATRIX_MEIDR) Master 11 Access Error Position */
#define MATRIX_MEIDR_MERR11_Msk               (_U_(0x1) << MATRIX_MEIDR_MERR11_Pos)                /**< (MATRIX_MEIDR) Master 11 Access Error Mask */
#define MATRIX_MEIDR_MERR11(value)            (MATRIX_MEIDR_MERR11_Msk & ((value) << MATRIX_MEIDR_MERR11_Pos))
#define MATRIX_MEIDR_MERR12_Pos               _U_(12)                                              /**< (MATRIX_MEIDR) Master 12 Access Error Position */
#define MATRIX_MEIDR_MERR12_Msk               (_U_(0x1) << MATRIX_MEIDR_MERR12_Pos)                /**< (MATRIX_MEIDR) Master 12 Access Error Mask */
#define MATRIX_MEIDR_MERR12(value)            (MATRIX_MEIDR_MERR12_Msk & ((value) << MATRIX_MEIDR_MERR12_Pos))
#define MATRIX_MEIDR_MERR13_Pos               _U_(13)                                              /**< (MATRIX_MEIDR) Master 13 Access Error Position */
#define MATRIX_MEIDR_MERR13_Msk               (_U_(0x1) << MATRIX_MEIDR_MERR13_Pos)                /**< (MATRIX_MEIDR) Master 13 Access Error Mask */
#define MATRIX_MEIDR_MERR13(value)            (MATRIX_MEIDR_MERR13_Msk & ((value) << MATRIX_MEIDR_MERR13_Pos))
#define MATRIX_MEIDR_MERR14_Pos               _U_(14)                                              /**< (MATRIX_MEIDR) Master 14 Access Error Position */
#define MATRIX_MEIDR_MERR14_Msk               (_U_(0x1) << MATRIX_MEIDR_MERR14_Pos)                /**< (MATRIX_MEIDR) Master 14 Access Error Mask */
#define MATRIX_MEIDR_MERR14(value)            (MATRIX_MEIDR_MERR14_Msk & ((value) << MATRIX_MEIDR_MERR14_Pos))
#define MATRIX_MEIDR_MERR15_Pos               _U_(15)                                              /**< (MATRIX_MEIDR) Master 15 Access Error Position */
#define MATRIX_MEIDR_MERR15_Msk               (_U_(0x1) << MATRIX_MEIDR_MERR15_Pos)                /**< (MATRIX_MEIDR) Master 15 Access Error Mask */
#define MATRIX_MEIDR_MERR15(value)            (MATRIX_MEIDR_MERR15_Msk & ((value) << MATRIX_MEIDR_MERR15_Pos))
#define MATRIX_MEIDR_Msk                      _U_(0x0000FFFF)                                      /**< (MATRIX_MEIDR) Register Mask  */

#define MATRIX_MEIDR_MERR_Pos                 _U_(0)                                               /**< (MATRIX_MEIDR Position) Master x5 Access Error */
#define MATRIX_MEIDR_MERR_Msk                 (_U_(0xFFFF) << MATRIX_MEIDR_MERR_Pos)               /**< (MATRIX_MEIDR Mask) MERR */
#define MATRIX_MEIDR_MERR(value)              (MATRIX_MEIDR_MERR_Msk & ((value) << MATRIX_MEIDR_MERR_Pos)) 

/* -------- MATRIX_MEIMR : (MATRIX Offset: 0x158) ( R/ 32) Master Error Interrupt Mask Register -------- */
#define MATRIX_MEIMR_MERR0_Pos                _U_(0)                                               /**< (MATRIX_MEIMR) Master 0 Access Error Position */
#define MATRIX_MEIMR_MERR0_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR0_Pos)                 /**< (MATRIX_MEIMR) Master 0 Access Error Mask */
#define MATRIX_MEIMR_MERR0(value)             (MATRIX_MEIMR_MERR0_Msk & ((value) << MATRIX_MEIMR_MERR0_Pos))
#define MATRIX_MEIMR_MERR1_Pos                _U_(1)                                               /**< (MATRIX_MEIMR) Master 1 Access Error Position */
#define MATRIX_MEIMR_MERR1_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR1_Pos)                 /**< (MATRIX_MEIMR) Master 1 Access Error Mask */
#define MATRIX_MEIMR_MERR1(value)             (MATRIX_MEIMR_MERR1_Msk & ((value) << MATRIX_MEIMR_MERR1_Pos))
#define MATRIX_MEIMR_MERR2_Pos                _U_(2)                                               /**< (MATRIX_MEIMR) Master 2 Access Error Position */
#define MATRIX_MEIMR_MERR2_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR2_Pos)                 /**< (MATRIX_MEIMR) Master 2 Access Error Mask */
#define MATRIX_MEIMR_MERR2(value)             (MATRIX_MEIMR_MERR2_Msk & ((value) << MATRIX_MEIMR_MERR2_Pos))
#define MATRIX_MEIMR_MERR3_Pos                _U_(3)                                               /**< (MATRIX_MEIMR) Master 3 Access Error Position */
#define MATRIX_MEIMR_MERR3_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR3_Pos)                 /**< (MATRIX_MEIMR) Master 3 Access Error Mask */
#define MATRIX_MEIMR_MERR3(value)             (MATRIX_MEIMR_MERR3_Msk & ((value) << MATRIX_MEIMR_MERR3_Pos))
#define MATRIX_MEIMR_MERR4_Pos                _U_(4)                                               /**< (MATRIX_MEIMR) Master 4 Access Error Position */
#define MATRIX_MEIMR_MERR4_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR4_Pos)                 /**< (MATRIX_MEIMR) Master 4 Access Error Mask */
#define MATRIX_MEIMR_MERR4(value)             (MATRIX_MEIMR_MERR4_Msk & ((value) << MATRIX_MEIMR_MERR4_Pos))
#define MATRIX_MEIMR_MERR5_Pos                _U_(5)                                               /**< (MATRIX_MEIMR) Master 5 Access Error Position */
#define MATRIX_MEIMR_MERR5_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR5_Pos)                 /**< (MATRIX_MEIMR) Master 5 Access Error Mask */
#define MATRIX_MEIMR_MERR5(value)             (MATRIX_MEIMR_MERR5_Msk & ((value) << MATRIX_MEIMR_MERR5_Pos))
#define MATRIX_MEIMR_MERR6_Pos                _U_(6)                                               /**< (MATRIX_MEIMR) Master 6 Access Error Position */
#define MATRIX_MEIMR_MERR6_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR6_Pos)                 /**< (MATRIX_MEIMR) Master 6 Access Error Mask */
#define MATRIX_MEIMR_MERR6(value)             (MATRIX_MEIMR_MERR6_Msk & ((value) << MATRIX_MEIMR_MERR6_Pos))
#define MATRIX_MEIMR_MERR7_Pos                _U_(7)                                               /**< (MATRIX_MEIMR) Master 7 Access Error Position */
#define MATRIX_MEIMR_MERR7_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR7_Pos)                 /**< (MATRIX_MEIMR) Master 7 Access Error Mask */
#define MATRIX_MEIMR_MERR7(value)             (MATRIX_MEIMR_MERR7_Msk & ((value) << MATRIX_MEIMR_MERR7_Pos))
#define MATRIX_MEIMR_MERR8_Pos                _U_(8)                                               /**< (MATRIX_MEIMR) Master 8 Access Error Position */
#define MATRIX_MEIMR_MERR8_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR8_Pos)                 /**< (MATRIX_MEIMR) Master 8 Access Error Mask */
#define MATRIX_MEIMR_MERR8(value)             (MATRIX_MEIMR_MERR8_Msk & ((value) << MATRIX_MEIMR_MERR8_Pos))
#define MATRIX_MEIMR_MERR9_Pos                _U_(9)                                               /**< (MATRIX_MEIMR) Master 9 Access Error Position */
#define MATRIX_MEIMR_MERR9_Msk                (_U_(0x1) << MATRIX_MEIMR_MERR9_Pos)                 /**< (MATRIX_MEIMR) Master 9 Access Error Mask */
#define MATRIX_MEIMR_MERR9(value)             (MATRIX_MEIMR_MERR9_Msk & ((value) << MATRIX_MEIMR_MERR9_Pos))
#define MATRIX_MEIMR_MERR10_Pos               _U_(10)                                              /**< (MATRIX_MEIMR) Master 10 Access Error Position */
#define MATRIX_MEIMR_MERR10_Msk               (_U_(0x1) << MATRIX_MEIMR_MERR10_Pos)                /**< (MATRIX_MEIMR) Master 10 Access Error Mask */
#define MATRIX_MEIMR_MERR10(value)            (MATRIX_MEIMR_MERR10_Msk & ((value) << MATRIX_MEIMR_MERR10_Pos))
#define MATRIX_MEIMR_MERR11_Pos               _U_(11)                                              /**< (MATRIX_MEIMR) Master 11 Access Error Position */
#define MATRIX_MEIMR_MERR11_Msk               (_U_(0x1) << MATRIX_MEIMR_MERR11_Pos)                /**< (MATRIX_MEIMR) Master 11 Access Error Mask */
#define MATRIX_MEIMR_MERR11(value)            (MATRIX_MEIMR_MERR11_Msk & ((value) << MATRIX_MEIMR_MERR11_Pos))
#define MATRIX_MEIMR_MERR12_Pos               _U_(12)                                              /**< (MATRIX_MEIMR) Master 12 Access Error Position */
#define MATRIX_MEIMR_MERR12_Msk               (_U_(0x1) << MATRIX_MEIMR_MERR12_Pos)                /**< (MATRIX_MEIMR) Master 12 Access Error Mask */
#define MATRIX_MEIMR_MERR12(value)            (MATRIX_MEIMR_MERR12_Msk & ((value) << MATRIX_MEIMR_MERR12_Pos))
#define MATRIX_MEIMR_MERR13_Pos               _U_(13)                                              /**< (MATRIX_MEIMR) Master 13 Access Error Position */
#define MATRIX_MEIMR_MERR13_Msk               (_U_(0x1) << MATRIX_MEIMR_MERR13_Pos)                /**< (MATRIX_MEIMR) Master 13 Access Error Mask */
#define MATRIX_MEIMR_MERR13(value)            (MATRIX_MEIMR_MERR13_Msk & ((value) << MATRIX_MEIMR_MERR13_Pos))
#define MATRIX_MEIMR_MERR14_Pos               _U_(14)                                              /**< (MATRIX_MEIMR) Master 14 Access Error Position */
#define MATRIX_MEIMR_MERR14_Msk               (_U_(0x1) << MATRIX_MEIMR_MERR14_Pos)                /**< (MATRIX_MEIMR) Master 14 Access Error Mask */
#define MATRIX_MEIMR_MERR14(value)            (MATRIX_MEIMR_MERR14_Msk & ((value) << MATRIX_MEIMR_MERR14_Pos))
#define MATRIX_MEIMR_MERR15_Pos               _U_(15)                                              /**< (MATRIX_MEIMR) Master 15 Access Error Position */
#define MATRIX_MEIMR_MERR15_Msk               (_U_(0x1) << MATRIX_MEIMR_MERR15_Pos)                /**< (MATRIX_MEIMR) Master 15 Access Error Mask */
#define MATRIX_MEIMR_MERR15(value)            (MATRIX_MEIMR_MERR15_Msk & ((value) << MATRIX_MEIMR_MERR15_Pos))
#define MATRIX_MEIMR_Msk                      _U_(0x0000FFFF)                                      /**< (MATRIX_MEIMR) Register Mask  */

#define MATRIX_MEIMR_MERR_Pos                 _U_(0)                                               /**< (MATRIX_MEIMR Position) Master x5 Access Error */
#define MATRIX_MEIMR_MERR_Msk                 (_U_(0xFFFF) << MATRIX_MEIMR_MERR_Pos)               /**< (MATRIX_MEIMR Mask) MERR */
#define MATRIX_MEIMR_MERR(value)              (MATRIX_MEIMR_MERR_Msk & ((value) << MATRIX_MEIMR_MERR_Pos)) 

/* -------- MATRIX_MESR : (MATRIX Offset: 0x15C) ( R/ 32) Master Error Status Register -------- */
#define MATRIX_MESR_MERR0_Pos                 _U_(0)                                               /**< (MATRIX_MESR) Master 0 Access Error Position */
#define MATRIX_MESR_MERR0_Msk                 (_U_(0x1) << MATRIX_MESR_MERR0_Pos)                  /**< (MATRIX_MESR) Master 0 Access Error Mask */
#define MATRIX_MESR_MERR0(value)              (MATRIX_MESR_MERR0_Msk & ((value) << MATRIX_MESR_MERR0_Pos))
#define MATRIX_MESR_MERR1_Pos                 _U_(1)                                               /**< (MATRIX_MESR) Master 1 Access Error Position */
#define MATRIX_MESR_MERR1_Msk                 (_U_(0x1) << MATRIX_MESR_MERR1_Pos)                  /**< (MATRIX_MESR) Master 1 Access Error Mask */
#define MATRIX_MESR_MERR1(value)              (MATRIX_MESR_MERR1_Msk & ((value) << MATRIX_MESR_MERR1_Pos))
#define MATRIX_MESR_MERR2_Pos                 _U_(2)                                               /**< (MATRIX_MESR) Master 2 Access Error Position */
#define MATRIX_MESR_MERR2_Msk                 (_U_(0x1) << MATRIX_MESR_MERR2_Pos)                  /**< (MATRIX_MESR) Master 2 Access Error Mask */
#define MATRIX_MESR_MERR2(value)              (MATRIX_MESR_MERR2_Msk & ((value) << MATRIX_MESR_MERR2_Pos))
#define MATRIX_MESR_MERR3_Pos                 _U_(3)                                               /**< (MATRIX_MESR) Master 3 Access Error Position */
#define MATRIX_MESR_MERR3_Msk                 (_U_(0x1) << MATRIX_MESR_MERR3_Pos)                  /**< (MATRIX_MESR) Master 3 Access Error Mask */
#define MATRIX_MESR_MERR3(value)              (MATRIX_MESR_MERR3_Msk & ((value) << MATRIX_MESR_MERR3_Pos))
#define MATRIX_MESR_MERR4_Pos                 _U_(4)                                               /**< (MATRIX_MESR) Master 4 Access Error Position */
#define MATRIX_MESR_MERR4_Msk                 (_U_(0x1) << MATRIX_MESR_MERR4_Pos)                  /**< (MATRIX_MESR) Master 4 Access Error Mask */
#define MATRIX_MESR_MERR4(value)              (MATRIX_MESR_MERR4_Msk & ((value) << MATRIX_MESR_MERR4_Pos))
#define MATRIX_MESR_MERR5_Pos                 _U_(5)                                               /**< (MATRIX_MESR) Master 5 Access Error Position */
#define MATRIX_MESR_MERR5_Msk                 (_U_(0x1) << MATRIX_MESR_MERR5_Pos)                  /**< (MATRIX_MESR) Master 5 Access Error Mask */
#define MATRIX_MESR_MERR5(value)              (MATRIX_MESR_MERR5_Msk & ((value) << MATRIX_MESR_MERR5_Pos))
#define MATRIX_MESR_MERR6_Pos                 _U_(6)                                               /**< (MATRIX_MESR) Master 6 Access Error Position */
#define MATRIX_MESR_MERR6_Msk                 (_U_(0x1) << MATRIX_MESR_MERR6_Pos)                  /**< (MATRIX_MESR) Master 6 Access Error Mask */
#define MATRIX_MESR_MERR6(value)              (MATRIX_MESR_MERR6_Msk & ((value) << MATRIX_MESR_MERR6_Pos))
#define MATRIX_MESR_MERR7_Pos                 _U_(7)                                               /**< (MATRIX_MESR) Master 7 Access Error Position */
#define MATRIX_MESR_MERR7_Msk                 (_U_(0x1) << MATRIX_MESR_MERR7_Pos)                  /**< (MATRIX_MESR) Master 7 Access Error Mask */
#define MATRIX_MESR_MERR7(value)              (MATRIX_MESR_MERR7_Msk & ((value) << MATRIX_MESR_MERR7_Pos))
#define MATRIX_MESR_MERR8_Pos                 _U_(8)                                               /**< (MATRIX_MESR) Master 8 Access Error Position */
#define MATRIX_MESR_MERR8_Msk                 (_U_(0x1) << MATRIX_MESR_MERR8_Pos)                  /**< (MATRIX_MESR) Master 8 Access Error Mask */
#define MATRIX_MESR_MERR8(value)              (MATRIX_MESR_MERR8_Msk & ((value) << MATRIX_MESR_MERR8_Pos))
#define MATRIX_MESR_MERR9_Pos                 _U_(9)                                               /**< (MATRIX_MESR) Master 9 Access Error Position */
#define MATRIX_MESR_MERR9_Msk                 (_U_(0x1) << MATRIX_MESR_MERR9_Pos)                  /**< (MATRIX_MESR) Master 9 Access Error Mask */
#define MATRIX_MESR_MERR9(value)              (MATRIX_MESR_MERR9_Msk & ((value) << MATRIX_MESR_MERR9_Pos))
#define MATRIX_MESR_MERR10_Pos                _U_(10)                                              /**< (MATRIX_MESR) Master 10 Access Error Position */
#define MATRIX_MESR_MERR10_Msk                (_U_(0x1) << MATRIX_MESR_MERR10_Pos)                 /**< (MATRIX_MESR) Master 10 Access Error Mask */
#define MATRIX_MESR_MERR10(value)             (MATRIX_MESR_MERR10_Msk & ((value) << MATRIX_MESR_MERR10_Pos))
#define MATRIX_MESR_MERR11_Pos                _U_(11)                                              /**< (MATRIX_MESR) Master 11 Access Error Position */
#define MATRIX_MESR_MERR11_Msk                (_U_(0x1) << MATRIX_MESR_MERR11_Pos)                 /**< (MATRIX_MESR) Master 11 Access Error Mask */
#define MATRIX_MESR_MERR11(value)             (MATRIX_MESR_MERR11_Msk & ((value) << MATRIX_MESR_MERR11_Pos))
#define MATRIX_MESR_MERR12_Pos                _U_(12)                                              /**< (MATRIX_MESR) Master 12 Access Error Position */
#define MATRIX_MESR_MERR12_Msk                (_U_(0x1) << MATRIX_MESR_MERR12_Pos)                 /**< (MATRIX_MESR) Master 12 Access Error Mask */
#define MATRIX_MESR_MERR12(value)             (MATRIX_MESR_MERR12_Msk & ((value) << MATRIX_MESR_MERR12_Pos))
#define MATRIX_MESR_MERR13_Pos                _U_(13)                                              /**< (MATRIX_MESR) Master 13 Access Error Position */
#define MATRIX_MESR_MERR13_Msk                (_U_(0x1) << MATRIX_MESR_MERR13_Pos)                 /**< (MATRIX_MESR) Master 13 Access Error Mask */
#define MATRIX_MESR_MERR13(value)             (MATRIX_MESR_MERR13_Msk & ((value) << MATRIX_MESR_MERR13_Pos))
#define MATRIX_MESR_MERR14_Pos                _U_(14)                                              /**< (MATRIX_MESR) Master 14 Access Error Position */
#define MATRIX_MESR_MERR14_Msk                (_U_(0x1) << MATRIX_MESR_MERR14_Pos)                 /**< (MATRIX_MESR) Master 14 Access Error Mask */
#define MATRIX_MESR_MERR14(value)             (MATRIX_MESR_MERR14_Msk & ((value) << MATRIX_MESR_MERR14_Pos))
#define MATRIX_MESR_MERR15_Pos                _U_(15)                                              /**< (MATRIX_MESR) Master 15 Access Error Position */
#define MATRIX_MESR_MERR15_Msk                (_U_(0x1) << MATRIX_MESR_MERR15_Pos)                 /**< (MATRIX_MESR) Master 15 Access Error Mask */
#define MATRIX_MESR_MERR15(value)             (MATRIX_MESR_MERR15_Msk & ((value) << MATRIX_MESR_MERR15_Pos))
#define MATRIX_MESR_Msk                       _U_(0x0000FFFF)                                      /**< (MATRIX_MESR) Register Mask  */

#define MATRIX_MESR_MERR_Pos                  _U_(0)                                               /**< (MATRIX_MESR Position) Master x5 Access Error */
#define MATRIX_MESR_MERR_Msk                  (_U_(0xFFFF) << MATRIX_MESR_MERR_Pos)                /**< (MATRIX_MESR Mask) MERR */
#define MATRIX_MESR_MERR(value)               (MATRIX_MESR_MERR_Msk & ((value) << MATRIX_MESR_MERR_Pos)) 

/* -------- MATRIX_MEAR0 : (MATRIX Offset: 0x160) ( R/ 32) Master 0 Error Address Register 0 -------- */
#define MATRIX_MEAR0_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR0) Master Error Address Position */
#define MATRIX_MEAR0_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR0_ERRADD_Pos)         /**< (MATRIX_MEAR0) Master Error Address Mask */
#define MATRIX_MEAR0_ERRADD(value)            (MATRIX_MEAR0_ERRADD_Msk & ((value) << MATRIX_MEAR0_ERRADD_Pos))
#define MATRIX_MEAR0_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR0) Register Mask  */


/* -------- MATRIX_MEAR1 : (MATRIX Offset: 0x164) ( R/ 32) Master 0 Error Address Register 1 -------- */
#define MATRIX_MEAR1_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR1) Master Error Address Position */
#define MATRIX_MEAR1_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR1_ERRADD_Pos)         /**< (MATRIX_MEAR1) Master Error Address Mask */
#define MATRIX_MEAR1_ERRADD(value)            (MATRIX_MEAR1_ERRADD_Msk & ((value) << MATRIX_MEAR1_ERRADD_Pos))
#define MATRIX_MEAR1_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR1) Register Mask  */


/* -------- MATRIX_MEAR2 : (MATRIX Offset: 0x168) ( R/ 32) Master 0 Error Address Register 2 -------- */
#define MATRIX_MEAR2_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR2) Master Error Address Position */
#define MATRIX_MEAR2_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR2_ERRADD_Pos)         /**< (MATRIX_MEAR2) Master Error Address Mask */
#define MATRIX_MEAR2_ERRADD(value)            (MATRIX_MEAR2_ERRADD_Msk & ((value) << MATRIX_MEAR2_ERRADD_Pos))
#define MATRIX_MEAR2_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR2) Register Mask  */


/* -------- MATRIX_MEAR3 : (MATRIX Offset: 0x16C) ( R/ 32) Master 0 Error Address Register 3 -------- */
#define MATRIX_MEAR3_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR3) Master Error Address Position */
#define MATRIX_MEAR3_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR3_ERRADD_Pos)         /**< (MATRIX_MEAR3) Master Error Address Mask */
#define MATRIX_MEAR3_ERRADD(value)            (MATRIX_MEAR3_ERRADD_Msk & ((value) << MATRIX_MEAR3_ERRADD_Pos))
#define MATRIX_MEAR3_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR3) Register Mask  */


/* -------- MATRIX_MEAR4 : (MATRIX Offset: 0x170) ( R/ 32) Master 0 Error Address Register 4 -------- */
#define MATRIX_MEAR4_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR4) Master Error Address Position */
#define MATRIX_MEAR4_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR4_ERRADD_Pos)         /**< (MATRIX_MEAR4) Master Error Address Mask */
#define MATRIX_MEAR4_ERRADD(value)            (MATRIX_MEAR4_ERRADD_Msk & ((value) << MATRIX_MEAR4_ERRADD_Pos))
#define MATRIX_MEAR4_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR4) Register Mask  */


/* -------- MATRIX_MEAR5 : (MATRIX Offset: 0x174) ( R/ 32) Master 0 Error Address Register 5 -------- */
#define MATRIX_MEAR5_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR5) Master Error Address Position */
#define MATRIX_MEAR5_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR5_ERRADD_Pos)         /**< (MATRIX_MEAR5) Master Error Address Mask */
#define MATRIX_MEAR5_ERRADD(value)            (MATRIX_MEAR5_ERRADD_Msk & ((value) << MATRIX_MEAR5_ERRADD_Pos))
#define MATRIX_MEAR5_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR5) Register Mask  */


/* -------- MATRIX_MEAR6 : (MATRIX Offset: 0x178) ( R/ 32) Master 0 Error Address Register 6 -------- */
#define MATRIX_MEAR6_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR6) Master Error Address Position */
#define MATRIX_MEAR6_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR6_ERRADD_Pos)         /**< (MATRIX_MEAR6) Master Error Address Mask */
#define MATRIX_MEAR6_ERRADD(value)            (MATRIX_MEAR6_ERRADD_Msk & ((value) << MATRIX_MEAR6_ERRADD_Pos))
#define MATRIX_MEAR6_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR6) Register Mask  */


/* -------- MATRIX_MEAR7 : (MATRIX Offset: 0x17C) ( R/ 32) Master 0 Error Address Register 7 -------- */
#define MATRIX_MEAR7_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR7) Master Error Address Position */
#define MATRIX_MEAR7_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR7_ERRADD_Pos)         /**< (MATRIX_MEAR7) Master Error Address Mask */
#define MATRIX_MEAR7_ERRADD(value)            (MATRIX_MEAR7_ERRADD_Msk & ((value) << MATRIX_MEAR7_ERRADD_Pos))
#define MATRIX_MEAR7_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR7) Register Mask  */


/* -------- MATRIX_MEAR8 : (MATRIX Offset: 0x180) ( R/ 32) Master 0 Error Address Register 8 -------- */
#define MATRIX_MEAR8_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR8) Master Error Address Position */
#define MATRIX_MEAR8_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR8_ERRADD_Pos)         /**< (MATRIX_MEAR8) Master Error Address Mask */
#define MATRIX_MEAR8_ERRADD(value)            (MATRIX_MEAR8_ERRADD_Msk & ((value) << MATRIX_MEAR8_ERRADD_Pos))
#define MATRIX_MEAR8_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR8) Register Mask  */


/* -------- MATRIX_MEAR9 : (MATRIX Offset: 0x184) ( R/ 32) Master 0 Error Address Register 9 -------- */
#define MATRIX_MEAR9_ERRADD_Pos               _U_(0)                                               /**< (MATRIX_MEAR9) Master Error Address Position */
#define MATRIX_MEAR9_ERRADD_Msk               (_U_(0xFFFFFFFF) << MATRIX_MEAR9_ERRADD_Pos)         /**< (MATRIX_MEAR9) Master Error Address Mask */
#define MATRIX_MEAR9_ERRADD(value)            (MATRIX_MEAR9_ERRADD_Msk & ((value) << MATRIX_MEAR9_ERRADD_Pos))
#define MATRIX_MEAR9_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR9) Register Mask  */


/* -------- MATRIX_MEAR10 : (MATRIX Offset: 0x188) ( R/ 32) Master 0 Error Address Register 10 -------- */
#define MATRIX_MEAR10_ERRADD_Pos              _U_(0)                                               /**< (MATRIX_MEAR10) Master Error Address Position */
#define MATRIX_MEAR10_ERRADD_Msk              (_U_(0xFFFFFFFF) << MATRIX_MEAR10_ERRADD_Pos)        /**< (MATRIX_MEAR10) Master Error Address Mask */
#define MATRIX_MEAR10_ERRADD(value)           (MATRIX_MEAR10_ERRADD_Msk & ((value) << MATRIX_MEAR10_ERRADD_Pos))
#define MATRIX_MEAR10_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR10) Register Mask  */


/* -------- MATRIX_MEAR11 : (MATRIX Offset: 0x18C) ( R/ 32) Master 0 Error Address Register 11 -------- */
#define MATRIX_MEAR11_ERRADD_Pos              _U_(0)                                               /**< (MATRIX_MEAR11) Master Error Address Position */
#define MATRIX_MEAR11_ERRADD_Msk              (_U_(0xFFFFFFFF) << MATRIX_MEAR11_ERRADD_Pos)        /**< (MATRIX_MEAR11) Master Error Address Mask */
#define MATRIX_MEAR11_ERRADD(value)           (MATRIX_MEAR11_ERRADD_Msk & ((value) << MATRIX_MEAR11_ERRADD_Pos))
#define MATRIX_MEAR11_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR11) Register Mask  */


/* -------- MATRIX_MEAR12 : (MATRIX Offset: 0x190) ( R/ 32) Master 0 Error Address Register 12 -------- */
#define MATRIX_MEAR12_ERRADD_Pos              _U_(0)                                               /**< (MATRIX_MEAR12) Master Error Address Position */
#define MATRIX_MEAR12_ERRADD_Msk              (_U_(0xFFFFFFFF) << MATRIX_MEAR12_ERRADD_Pos)        /**< (MATRIX_MEAR12) Master Error Address Mask */
#define MATRIX_MEAR12_ERRADD(value)           (MATRIX_MEAR12_ERRADD_Msk & ((value) << MATRIX_MEAR12_ERRADD_Pos))
#define MATRIX_MEAR12_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR12) Register Mask  */


/* -------- MATRIX_MEAR13 : (MATRIX Offset: 0x194) ( R/ 32) Master 0 Error Address Register 13 -------- */
#define MATRIX_MEAR13_ERRADD_Pos              _U_(0)                                               /**< (MATRIX_MEAR13) Master Error Address Position */
#define MATRIX_MEAR13_ERRADD_Msk              (_U_(0xFFFFFFFF) << MATRIX_MEAR13_ERRADD_Pos)        /**< (MATRIX_MEAR13) Master Error Address Mask */
#define MATRIX_MEAR13_ERRADD(value)           (MATRIX_MEAR13_ERRADD_Msk & ((value) << MATRIX_MEAR13_ERRADD_Pos))
#define MATRIX_MEAR13_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR13) Register Mask  */


/* -------- MATRIX_MEAR14 : (MATRIX Offset: 0x198) ( R/ 32) Master 0 Error Address Register 14 -------- */
#define MATRIX_MEAR14_ERRADD_Pos              _U_(0)                                               /**< (MATRIX_MEAR14) Master Error Address Position */
#define MATRIX_MEAR14_ERRADD_Msk              (_U_(0xFFFFFFFF) << MATRIX_MEAR14_ERRADD_Pos)        /**< (MATRIX_MEAR14) Master Error Address Mask */
#define MATRIX_MEAR14_ERRADD(value)           (MATRIX_MEAR14_ERRADD_Msk & ((value) << MATRIX_MEAR14_ERRADD_Pos))
#define MATRIX_MEAR14_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR14) Register Mask  */


/* -------- MATRIX_MEAR15 : (MATRIX Offset: 0x19C) ( R/ 32) Master 0 Error Address Register 15 -------- */
#define MATRIX_MEAR15_ERRADD_Pos              _U_(0)                                               /**< (MATRIX_MEAR15) Master Error Address Position */
#define MATRIX_MEAR15_ERRADD_Msk              (_U_(0xFFFFFFFF) << MATRIX_MEAR15_ERRADD_Pos)        /**< (MATRIX_MEAR15) Master Error Address Mask */
#define MATRIX_MEAR15_ERRADD(value)           (MATRIX_MEAR15_ERRADD_Msk & ((value) << MATRIX_MEAR15_ERRADD_Pos))
#define MATRIX_MEAR15_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_MEAR15) Register Mask  */


/* -------- MATRIX_WPMR : (MATRIX Offset: 0x1E4) (R/W 32) Write Protect Mode Register -------- */
#define MATRIX_WPMR_WPEN_Pos                  _U_(0)                                               /**< (MATRIX_WPMR) Write Protection Enable Position */
#define MATRIX_WPMR_WPEN_Msk                  (_U_(0x1) << MATRIX_WPMR_WPEN_Pos)                   /**< (MATRIX_WPMR) Write Protection Enable Mask */
#define MATRIX_WPMR_WPEN(value)               (MATRIX_WPMR_WPEN_Msk & ((value) << MATRIX_WPMR_WPEN_Pos))
#define MATRIX_WPMR_CFGFRZ_Pos                _U_(7)                                               /**< (MATRIX_WPMR)  Position */
#define MATRIX_WPMR_CFGFRZ_Msk                (_U_(0x1) << MATRIX_WPMR_CFGFRZ_Pos)                 /**< (MATRIX_WPMR)  Mask */
#define MATRIX_WPMR_CFGFRZ(value)             (MATRIX_WPMR_CFGFRZ_Msk & ((value) << MATRIX_WPMR_CFGFRZ_Pos))
#define MATRIX_WPMR_WPKEY_Pos                 _U_(8)                                               /**< (MATRIX_WPMR) Write Protection Key Position */
#define MATRIX_WPMR_WPKEY_Msk                 (_U_(0xFFFFFF) << MATRIX_WPMR_WPKEY_Pos)             /**< (MATRIX_WPMR) Write Protection Key Mask */
#define MATRIX_WPMR_WPKEY(value)              (MATRIX_WPMR_WPKEY_Msk & ((value) << MATRIX_WPMR_WPKEY_Pos))
#define   MATRIX_WPMR_WPKEY_PASSWD_Val        _U_(0x4D4154)                                        /**< (MATRIX_WPMR) Writing any other value in this field aborts the write operation of the WPEN and CFGFRZ bits. Always reads as 0.  */
#define MATRIX_WPMR_WPKEY_PASSWD              (MATRIX_WPMR_WPKEY_PASSWD_Val << MATRIX_WPMR_WPKEY_Pos) /**< (MATRIX_WPMR) Writing any other value in this field aborts the write operation of the WPEN and CFGFRZ bits. Always reads as 0. Position  */
#define MATRIX_WPMR_Msk                       _U_(0xFFFFFF81)                                      /**< (MATRIX_WPMR) Register Mask  */


/* -------- MATRIX_WPSR : (MATRIX Offset: 0x1E8) ( R/ 32) Write Protect Status Register -------- */
#define MATRIX_WPSR_WPVS_Pos                  _U_(0)                                               /**< (MATRIX_WPSR) Write Protection Violation Status Position */
#define MATRIX_WPSR_WPVS_Msk                  (_U_(0x1) << MATRIX_WPSR_WPVS_Pos)                   /**< (MATRIX_WPSR) Write Protection Violation Status Mask */
#define MATRIX_WPSR_WPVS(value)               (MATRIX_WPSR_WPVS_Msk & ((value) << MATRIX_WPSR_WPVS_Pos))
#define MATRIX_WPSR_WPVSRC_Pos                _U_(8)                                               /**< (MATRIX_WPSR) Write Protection Violation Source Position */
#define MATRIX_WPSR_WPVSRC_Msk                (_U_(0xFFFF) << MATRIX_WPSR_WPVSRC_Pos)              /**< (MATRIX_WPSR) Write Protection Violation Source Mask */
#define MATRIX_WPSR_WPVSRC(value)             (MATRIX_WPSR_WPVSRC_Msk & ((value) << MATRIX_WPSR_WPVSRC_Pos))
#define MATRIX_WPSR_Msk                       _U_(0x00FFFF01)                                      /**< (MATRIX_WPSR) Register Mask  */


/* -------- MATRIX_PSR0 : (MATRIX Offset: 0x200) (R/W 32) Protection Slave 0 Register 0 -------- */
#define MATRIX_PSR0_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH0_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH0(value)           (MATRIX_PSR0_LAUSERH0_Msk & ((value) << MATRIX_PSR0_LAUSERH0_Pos))
#define MATRIX_PSR0_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH1_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH1(value)           (MATRIX_PSR0_LAUSERH1_Msk & ((value) << MATRIX_PSR0_LAUSERH1_Pos))
#define MATRIX_PSR0_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH2_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH2(value)           (MATRIX_PSR0_LAUSERH2_Msk & ((value) << MATRIX_PSR0_LAUSERH2_Pos))
#define MATRIX_PSR0_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH3_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH3(value)           (MATRIX_PSR0_LAUSERH3_Msk & ((value) << MATRIX_PSR0_LAUSERH3_Pos))
#define MATRIX_PSR0_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH4_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH4(value)           (MATRIX_PSR0_LAUSERH4_Msk & ((value) << MATRIX_PSR0_LAUSERH4_Pos))
#define MATRIX_PSR0_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH5_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH5(value)           (MATRIX_PSR0_LAUSERH5_Msk & ((value) << MATRIX_PSR0_LAUSERH5_Pos))
#define MATRIX_PSR0_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH6_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH6(value)           (MATRIX_PSR0_LAUSERH6_Msk & ((value) << MATRIX_PSR0_LAUSERH6_Pos))
#define MATRIX_PSR0_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR0_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR0_LAUSERH7_Pos)               /**< (MATRIX_PSR0) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR0_LAUSERH7(value)           (MATRIX_PSR0_LAUSERH7_Msk & ((value) << MATRIX_PSR0_LAUSERH7_Pos))
#define MATRIX_PSR0_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH0_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH0(value)           (MATRIX_PSR0_RDUSERH0_Msk & ((value) << MATRIX_PSR0_RDUSERH0_Pos))
#define MATRIX_PSR0_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH1_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH1(value)           (MATRIX_PSR0_RDUSERH1_Msk & ((value) << MATRIX_PSR0_RDUSERH1_Pos))
#define MATRIX_PSR0_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH2_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH2(value)           (MATRIX_PSR0_RDUSERH2_Msk & ((value) << MATRIX_PSR0_RDUSERH2_Pos))
#define MATRIX_PSR0_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH3_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH3(value)           (MATRIX_PSR0_RDUSERH3_Msk & ((value) << MATRIX_PSR0_RDUSERH3_Pos))
#define MATRIX_PSR0_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH4_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH4(value)           (MATRIX_PSR0_RDUSERH4_Msk & ((value) << MATRIX_PSR0_RDUSERH4_Pos))
#define MATRIX_PSR0_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH5_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH5(value)           (MATRIX_PSR0_RDUSERH5_Msk & ((value) << MATRIX_PSR0_RDUSERH5_Pos))
#define MATRIX_PSR0_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH6_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH6(value)           (MATRIX_PSR0_RDUSERH6_Msk & ((value) << MATRIX_PSR0_RDUSERH6_Pos))
#define MATRIX_PSR0_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR0_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR0_RDUSERH7_Pos)               /**< (MATRIX_PSR0) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_RDUSERH7(value)           (MATRIX_PSR0_RDUSERH7_Msk & ((value) << MATRIX_PSR0_RDUSERH7_Pos))
#define MATRIX_PSR0_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH0_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH0(value)           (MATRIX_PSR0_WRUSERH0_Msk & ((value) << MATRIX_PSR0_WRUSERH0_Pos))
#define MATRIX_PSR0_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH1_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH1(value)           (MATRIX_PSR0_WRUSERH1_Msk & ((value) << MATRIX_PSR0_WRUSERH1_Pos))
#define MATRIX_PSR0_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH2_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH2(value)           (MATRIX_PSR0_WRUSERH2_Msk & ((value) << MATRIX_PSR0_WRUSERH2_Pos))
#define MATRIX_PSR0_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH3_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH3(value)           (MATRIX_PSR0_WRUSERH3_Msk & ((value) << MATRIX_PSR0_WRUSERH3_Pos))
#define MATRIX_PSR0_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH4_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH4(value)           (MATRIX_PSR0_WRUSERH4_Msk & ((value) << MATRIX_PSR0_WRUSERH4_Pos))
#define MATRIX_PSR0_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH5_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH5(value)           (MATRIX_PSR0_WRUSERH5_Msk & ((value) << MATRIX_PSR0_WRUSERH5_Pos))
#define MATRIX_PSR0_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH6_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH6(value)           (MATRIX_PSR0_WRUSERH6_Msk & ((value) << MATRIX_PSR0_WRUSERH6_Pos))
#define MATRIX_PSR0_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR0_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR0_WRUSERH7_Pos)               /**< (MATRIX_PSR0) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR0_WRUSERH7(value)           (MATRIX_PSR0_WRUSERH7_Msk & ((value) << MATRIX_PSR0_WRUSERH7_Pos))
#define MATRIX_PSR0_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA0_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA0(value)             (MATRIX_PSR0_DPSOA0_Msk & ((value) << MATRIX_PSR0_DPSOA0_Pos))
#define MATRIX_PSR0_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA1_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA1(value)             (MATRIX_PSR0_DPSOA1_Msk & ((value) << MATRIX_PSR0_DPSOA1_Pos))
#define MATRIX_PSR0_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA2_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA2(value)             (MATRIX_PSR0_DPSOA2_Msk & ((value) << MATRIX_PSR0_DPSOA2_Pos))
#define MATRIX_PSR0_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA3_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA3(value)             (MATRIX_PSR0_DPSOA3_Msk & ((value) << MATRIX_PSR0_DPSOA3_Pos))
#define MATRIX_PSR0_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA4_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA4(value)             (MATRIX_PSR0_DPSOA4_Msk & ((value) << MATRIX_PSR0_DPSOA4_Pos))
#define MATRIX_PSR0_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA5_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA5(value)             (MATRIX_PSR0_DPSOA5_Msk & ((value) << MATRIX_PSR0_DPSOA5_Pos))
#define MATRIX_PSR0_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA6_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA6(value)             (MATRIX_PSR0_DPSOA6_Msk & ((value) << MATRIX_PSR0_DPSOA6_Pos))
#define MATRIX_PSR0_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR0_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR0_DPSOA7_Pos)                 /**< (MATRIX_PSR0) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR0_DPSOA7(value)             (MATRIX_PSR0_DPSOA7_Msk & ((value) << MATRIX_PSR0_DPSOA7_Pos))
#define MATRIX_PSR0_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR0) Register Mask  */

#define MATRIX_PSR0_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR0 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR0_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR0_LAUSERH_Pos)               /**< (MATRIX_PSR0 Mask) LAUSERH */
#define MATRIX_PSR0_LAUSERH(value)            (MATRIX_PSR0_LAUSERH_Msk & ((value) << MATRIX_PSR0_LAUSERH_Pos)) 
#define MATRIX_PSR0_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR0 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR0_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR0_RDUSERH_Pos)               /**< (MATRIX_PSR0 Mask) RDUSERH */
#define MATRIX_PSR0_RDUSERH(value)            (MATRIX_PSR0_RDUSERH_Msk & ((value) << MATRIX_PSR0_RDUSERH_Pos)) 
#define MATRIX_PSR0_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR0 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR0_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR0_WRUSERH_Pos)               /**< (MATRIX_PSR0 Mask) WRUSERH */
#define MATRIX_PSR0_WRUSERH(value)            (MATRIX_PSR0_WRUSERH_Msk & ((value) << MATRIX_PSR0_WRUSERH_Pos)) 
#define MATRIX_PSR0_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR0 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR0_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR0_DPSOA_Pos)                 /**< (MATRIX_PSR0 Mask) DPSOA */
#define MATRIX_PSR0_DPSOA(value)              (MATRIX_PSR0_DPSOA_Msk & ((value) << MATRIX_PSR0_DPSOA_Pos)) 

/* -------- MATRIX_PSR1 : (MATRIX Offset: 0x204) (R/W 32) Protection Slave 0 Register 1 -------- */
#define MATRIX_PSR1_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH0_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH0(value)           (MATRIX_PSR1_LAUSERH0_Msk & ((value) << MATRIX_PSR1_LAUSERH0_Pos))
#define MATRIX_PSR1_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH1_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH1(value)           (MATRIX_PSR1_LAUSERH1_Msk & ((value) << MATRIX_PSR1_LAUSERH1_Pos))
#define MATRIX_PSR1_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH2_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH2(value)           (MATRIX_PSR1_LAUSERH2_Msk & ((value) << MATRIX_PSR1_LAUSERH2_Pos))
#define MATRIX_PSR1_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH3_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH3(value)           (MATRIX_PSR1_LAUSERH3_Msk & ((value) << MATRIX_PSR1_LAUSERH3_Pos))
#define MATRIX_PSR1_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH4_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH4(value)           (MATRIX_PSR1_LAUSERH4_Msk & ((value) << MATRIX_PSR1_LAUSERH4_Pos))
#define MATRIX_PSR1_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH5_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH5(value)           (MATRIX_PSR1_LAUSERH5_Msk & ((value) << MATRIX_PSR1_LAUSERH5_Pos))
#define MATRIX_PSR1_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH6_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH6(value)           (MATRIX_PSR1_LAUSERH6_Msk & ((value) << MATRIX_PSR1_LAUSERH6_Pos))
#define MATRIX_PSR1_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR1_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR1_LAUSERH7_Pos)               /**< (MATRIX_PSR1) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR1_LAUSERH7(value)           (MATRIX_PSR1_LAUSERH7_Msk & ((value) << MATRIX_PSR1_LAUSERH7_Pos))
#define MATRIX_PSR1_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH0_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH0(value)           (MATRIX_PSR1_RDUSERH0_Msk & ((value) << MATRIX_PSR1_RDUSERH0_Pos))
#define MATRIX_PSR1_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH1_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH1(value)           (MATRIX_PSR1_RDUSERH1_Msk & ((value) << MATRIX_PSR1_RDUSERH1_Pos))
#define MATRIX_PSR1_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH2_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH2(value)           (MATRIX_PSR1_RDUSERH2_Msk & ((value) << MATRIX_PSR1_RDUSERH2_Pos))
#define MATRIX_PSR1_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH3_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH3(value)           (MATRIX_PSR1_RDUSERH3_Msk & ((value) << MATRIX_PSR1_RDUSERH3_Pos))
#define MATRIX_PSR1_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH4_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH4(value)           (MATRIX_PSR1_RDUSERH4_Msk & ((value) << MATRIX_PSR1_RDUSERH4_Pos))
#define MATRIX_PSR1_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH5_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH5(value)           (MATRIX_PSR1_RDUSERH5_Msk & ((value) << MATRIX_PSR1_RDUSERH5_Pos))
#define MATRIX_PSR1_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH6_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH6(value)           (MATRIX_PSR1_RDUSERH6_Msk & ((value) << MATRIX_PSR1_RDUSERH6_Pos))
#define MATRIX_PSR1_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR1_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR1_RDUSERH7_Pos)               /**< (MATRIX_PSR1) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_RDUSERH7(value)           (MATRIX_PSR1_RDUSERH7_Msk & ((value) << MATRIX_PSR1_RDUSERH7_Pos))
#define MATRIX_PSR1_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH0_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH0(value)           (MATRIX_PSR1_WRUSERH0_Msk & ((value) << MATRIX_PSR1_WRUSERH0_Pos))
#define MATRIX_PSR1_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH1_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH1(value)           (MATRIX_PSR1_WRUSERH1_Msk & ((value) << MATRIX_PSR1_WRUSERH1_Pos))
#define MATRIX_PSR1_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH2_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH2(value)           (MATRIX_PSR1_WRUSERH2_Msk & ((value) << MATRIX_PSR1_WRUSERH2_Pos))
#define MATRIX_PSR1_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH3_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH3(value)           (MATRIX_PSR1_WRUSERH3_Msk & ((value) << MATRIX_PSR1_WRUSERH3_Pos))
#define MATRIX_PSR1_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH4_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH4(value)           (MATRIX_PSR1_WRUSERH4_Msk & ((value) << MATRIX_PSR1_WRUSERH4_Pos))
#define MATRIX_PSR1_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH5_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH5(value)           (MATRIX_PSR1_WRUSERH5_Msk & ((value) << MATRIX_PSR1_WRUSERH5_Pos))
#define MATRIX_PSR1_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH6_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH6(value)           (MATRIX_PSR1_WRUSERH6_Msk & ((value) << MATRIX_PSR1_WRUSERH6_Pos))
#define MATRIX_PSR1_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR1_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR1_WRUSERH7_Pos)               /**< (MATRIX_PSR1) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR1_WRUSERH7(value)           (MATRIX_PSR1_WRUSERH7_Msk & ((value) << MATRIX_PSR1_WRUSERH7_Pos))
#define MATRIX_PSR1_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA0_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA0(value)             (MATRIX_PSR1_DPSOA0_Msk & ((value) << MATRIX_PSR1_DPSOA0_Pos))
#define MATRIX_PSR1_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA1_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA1(value)             (MATRIX_PSR1_DPSOA1_Msk & ((value) << MATRIX_PSR1_DPSOA1_Pos))
#define MATRIX_PSR1_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA2_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA2(value)             (MATRIX_PSR1_DPSOA2_Msk & ((value) << MATRIX_PSR1_DPSOA2_Pos))
#define MATRIX_PSR1_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA3_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA3(value)             (MATRIX_PSR1_DPSOA3_Msk & ((value) << MATRIX_PSR1_DPSOA3_Pos))
#define MATRIX_PSR1_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA4_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA4(value)             (MATRIX_PSR1_DPSOA4_Msk & ((value) << MATRIX_PSR1_DPSOA4_Pos))
#define MATRIX_PSR1_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA5_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA5(value)             (MATRIX_PSR1_DPSOA5_Msk & ((value) << MATRIX_PSR1_DPSOA5_Pos))
#define MATRIX_PSR1_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA6_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA6(value)             (MATRIX_PSR1_DPSOA6_Msk & ((value) << MATRIX_PSR1_DPSOA6_Pos))
#define MATRIX_PSR1_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR1_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR1_DPSOA7_Pos)                 /**< (MATRIX_PSR1) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR1_DPSOA7(value)             (MATRIX_PSR1_DPSOA7_Msk & ((value) << MATRIX_PSR1_DPSOA7_Pos))
#define MATRIX_PSR1_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR1) Register Mask  */

#define MATRIX_PSR1_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR1 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR1_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR1_LAUSERH_Pos)               /**< (MATRIX_PSR1 Mask) LAUSERH */
#define MATRIX_PSR1_LAUSERH(value)            (MATRIX_PSR1_LAUSERH_Msk & ((value) << MATRIX_PSR1_LAUSERH_Pos)) 
#define MATRIX_PSR1_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR1 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR1_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR1_RDUSERH_Pos)               /**< (MATRIX_PSR1 Mask) RDUSERH */
#define MATRIX_PSR1_RDUSERH(value)            (MATRIX_PSR1_RDUSERH_Msk & ((value) << MATRIX_PSR1_RDUSERH_Pos)) 
#define MATRIX_PSR1_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR1 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR1_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR1_WRUSERH_Pos)               /**< (MATRIX_PSR1 Mask) WRUSERH */
#define MATRIX_PSR1_WRUSERH(value)            (MATRIX_PSR1_WRUSERH_Msk & ((value) << MATRIX_PSR1_WRUSERH_Pos)) 
#define MATRIX_PSR1_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR1 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR1_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR1_DPSOA_Pos)                 /**< (MATRIX_PSR1 Mask) DPSOA */
#define MATRIX_PSR1_DPSOA(value)              (MATRIX_PSR1_DPSOA_Msk & ((value) << MATRIX_PSR1_DPSOA_Pos)) 

/* -------- MATRIX_PSR2 : (MATRIX Offset: 0x208) (R/W 32) Protection Slave 0 Register 2 -------- */
#define MATRIX_PSR2_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH0_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH0(value)           (MATRIX_PSR2_LAUSERH0_Msk & ((value) << MATRIX_PSR2_LAUSERH0_Pos))
#define MATRIX_PSR2_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH1_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH1(value)           (MATRIX_PSR2_LAUSERH1_Msk & ((value) << MATRIX_PSR2_LAUSERH1_Pos))
#define MATRIX_PSR2_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH2_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH2(value)           (MATRIX_PSR2_LAUSERH2_Msk & ((value) << MATRIX_PSR2_LAUSERH2_Pos))
#define MATRIX_PSR2_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH3_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH3(value)           (MATRIX_PSR2_LAUSERH3_Msk & ((value) << MATRIX_PSR2_LAUSERH3_Pos))
#define MATRIX_PSR2_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH4_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH4(value)           (MATRIX_PSR2_LAUSERH4_Msk & ((value) << MATRIX_PSR2_LAUSERH4_Pos))
#define MATRIX_PSR2_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH5_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH5(value)           (MATRIX_PSR2_LAUSERH5_Msk & ((value) << MATRIX_PSR2_LAUSERH5_Pos))
#define MATRIX_PSR2_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH6_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH6(value)           (MATRIX_PSR2_LAUSERH6_Msk & ((value) << MATRIX_PSR2_LAUSERH6_Pos))
#define MATRIX_PSR2_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR2_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR2_LAUSERH7_Pos)               /**< (MATRIX_PSR2) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR2_LAUSERH7(value)           (MATRIX_PSR2_LAUSERH7_Msk & ((value) << MATRIX_PSR2_LAUSERH7_Pos))
#define MATRIX_PSR2_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH0_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH0(value)           (MATRIX_PSR2_RDUSERH0_Msk & ((value) << MATRIX_PSR2_RDUSERH0_Pos))
#define MATRIX_PSR2_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH1_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH1(value)           (MATRIX_PSR2_RDUSERH1_Msk & ((value) << MATRIX_PSR2_RDUSERH1_Pos))
#define MATRIX_PSR2_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH2_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH2(value)           (MATRIX_PSR2_RDUSERH2_Msk & ((value) << MATRIX_PSR2_RDUSERH2_Pos))
#define MATRIX_PSR2_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH3_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH3(value)           (MATRIX_PSR2_RDUSERH3_Msk & ((value) << MATRIX_PSR2_RDUSERH3_Pos))
#define MATRIX_PSR2_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH4_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH4(value)           (MATRIX_PSR2_RDUSERH4_Msk & ((value) << MATRIX_PSR2_RDUSERH4_Pos))
#define MATRIX_PSR2_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH5_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH5(value)           (MATRIX_PSR2_RDUSERH5_Msk & ((value) << MATRIX_PSR2_RDUSERH5_Pos))
#define MATRIX_PSR2_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH6_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH6(value)           (MATRIX_PSR2_RDUSERH6_Msk & ((value) << MATRIX_PSR2_RDUSERH6_Pos))
#define MATRIX_PSR2_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR2_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR2_RDUSERH7_Pos)               /**< (MATRIX_PSR2) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_RDUSERH7(value)           (MATRIX_PSR2_RDUSERH7_Msk & ((value) << MATRIX_PSR2_RDUSERH7_Pos))
#define MATRIX_PSR2_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH0_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH0(value)           (MATRIX_PSR2_WRUSERH0_Msk & ((value) << MATRIX_PSR2_WRUSERH0_Pos))
#define MATRIX_PSR2_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH1_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH1(value)           (MATRIX_PSR2_WRUSERH1_Msk & ((value) << MATRIX_PSR2_WRUSERH1_Pos))
#define MATRIX_PSR2_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH2_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH2(value)           (MATRIX_PSR2_WRUSERH2_Msk & ((value) << MATRIX_PSR2_WRUSERH2_Pos))
#define MATRIX_PSR2_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH3_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH3(value)           (MATRIX_PSR2_WRUSERH3_Msk & ((value) << MATRIX_PSR2_WRUSERH3_Pos))
#define MATRIX_PSR2_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH4_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH4(value)           (MATRIX_PSR2_WRUSERH4_Msk & ((value) << MATRIX_PSR2_WRUSERH4_Pos))
#define MATRIX_PSR2_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH5_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH5(value)           (MATRIX_PSR2_WRUSERH5_Msk & ((value) << MATRIX_PSR2_WRUSERH5_Pos))
#define MATRIX_PSR2_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH6_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH6(value)           (MATRIX_PSR2_WRUSERH6_Msk & ((value) << MATRIX_PSR2_WRUSERH6_Pos))
#define MATRIX_PSR2_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR2_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR2_WRUSERH7_Pos)               /**< (MATRIX_PSR2) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR2_WRUSERH7(value)           (MATRIX_PSR2_WRUSERH7_Msk & ((value) << MATRIX_PSR2_WRUSERH7_Pos))
#define MATRIX_PSR2_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA0_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA0(value)             (MATRIX_PSR2_DPSOA0_Msk & ((value) << MATRIX_PSR2_DPSOA0_Pos))
#define MATRIX_PSR2_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA1_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA1(value)             (MATRIX_PSR2_DPSOA1_Msk & ((value) << MATRIX_PSR2_DPSOA1_Pos))
#define MATRIX_PSR2_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA2_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA2(value)             (MATRIX_PSR2_DPSOA2_Msk & ((value) << MATRIX_PSR2_DPSOA2_Pos))
#define MATRIX_PSR2_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA3_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA3(value)             (MATRIX_PSR2_DPSOA3_Msk & ((value) << MATRIX_PSR2_DPSOA3_Pos))
#define MATRIX_PSR2_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA4_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA4(value)             (MATRIX_PSR2_DPSOA4_Msk & ((value) << MATRIX_PSR2_DPSOA4_Pos))
#define MATRIX_PSR2_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA5_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA5(value)             (MATRIX_PSR2_DPSOA5_Msk & ((value) << MATRIX_PSR2_DPSOA5_Pos))
#define MATRIX_PSR2_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA6_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA6(value)             (MATRIX_PSR2_DPSOA6_Msk & ((value) << MATRIX_PSR2_DPSOA6_Pos))
#define MATRIX_PSR2_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR2_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR2_DPSOA7_Pos)                 /**< (MATRIX_PSR2) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR2_DPSOA7(value)             (MATRIX_PSR2_DPSOA7_Msk & ((value) << MATRIX_PSR2_DPSOA7_Pos))
#define MATRIX_PSR2_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR2) Register Mask  */

#define MATRIX_PSR2_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR2 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR2_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR2_LAUSERH_Pos)               /**< (MATRIX_PSR2 Mask) LAUSERH */
#define MATRIX_PSR2_LAUSERH(value)            (MATRIX_PSR2_LAUSERH_Msk & ((value) << MATRIX_PSR2_LAUSERH_Pos)) 
#define MATRIX_PSR2_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR2 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR2_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR2_RDUSERH_Pos)               /**< (MATRIX_PSR2 Mask) RDUSERH */
#define MATRIX_PSR2_RDUSERH(value)            (MATRIX_PSR2_RDUSERH_Msk & ((value) << MATRIX_PSR2_RDUSERH_Pos)) 
#define MATRIX_PSR2_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR2 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR2_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR2_WRUSERH_Pos)               /**< (MATRIX_PSR2 Mask) WRUSERH */
#define MATRIX_PSR2_WRUSERH(value)            (MATRIX_PSR2_WRUSERH_Msk & ((value) << MATRIX_PSR2_WRUSERH_Pos)) 
#define MATRIX_PSR2_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR2 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR2_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR2_DPSOA_Pos)                 /**< (MATRIX_PSR2 Mask) DPSOA */
#define MATRIX_PSR2_DPSOA(value)              (MATRIX_PSR2_DPSOA_Msk & ((value) << MATRIX_PSR2_DPSOA_Pos)) 

/* -------- MATRIX_PSR3 : (MATRIX Offset: 0x20C) (R/W 32) Protection Slave 0 Register 3 -------- */
#define MATRIX_PSR3_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH0_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH0(value)           (MATRIX_PSR3_LAUSERH0_Msk & ((value) << MATRIX_PSR3_LAUSERH0_Pos))
#define MATRIX_PSR3_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH1_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH1(value)           (MATRIX_PSR3_LAUSERH1_Msk & ((value) << MATRIX_PSR3_LAUSERH1_Pos))
#define MATRIX_PSR3_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH2_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH2(value)           (MATRIX_PSR3_LAUSERH2_Msk & ((value) << MATRIX_PSR3_LAUSERH2_Pos))
#define MATRIX_PSR3_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH3_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH3(value)           (MATRIX_PSR3_LAUSERH3_Msk & ((value) << MATRIX_PSR3_LAUSERH3_Pos))
#define MATRIX_PSR3_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH4_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH4(value)           (MATRIX_PSR3_LAUSERH4_Msk & ((value) << MATRIX_PSR3_LAUSERH4_Pos))
#define MATRIX_PSR3_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH5_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH5(value)           (MATRIX_PSR3_LAUSERH5_Msk & ((value) << MATRIX_PSR3_LAUSERH5_Pos))
#define MATRIX_PSR3_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH6_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH6(value)           (MATRIX_PSR3_LAUSERH6_Msk & ((value) << MATRIX_PSR3_LAUSERH6_Pos))
#define MATRIX_PSR3_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR3_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR3_LAUSERH7_Pos)               /**< (MATRIX_PSR3) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR3_LAUSERH7(value)           (MATRIX_PSR3_LAUSERH7_Msk & ((value) << MATRIX_PSR3_LAUSERH7_Pos))
#define MATRIX_PSR3_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH0_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH0(value)           (MATRIX_PSR3_RDUSERH0_Msk & ((value) << MATRIX_PSR3_RDUSERH0_Pos))
#define MATRIX_PSR3_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH1_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH1(value)           (MATRIX_PSR3_RDUSERH1_Msk & ((value) << MATRIX_PSR3_RDUSERH1_Pos))
#define MATRIX_PSR3_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH2_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH2(value)           (MATRIX_PSR3_RDUSERH2_Msk & ((value) << MATRIX_PSR3_RDUSERH2_Pos))
#define MATRIX_PSR3_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH3_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH3(value)           (MATRIX_PSR3_RDUSERH3_Msk & ((value) << MATRIX_PSR3_RDUSERH3_Pos))
#define MATRIX_PSR3_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH4_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH4(value)           (MATRIX_PSR3_RDUSERH4_Msk & ((value) << MATRIX_PSR3_RDUSERH4_Pos))
#define MATRIX_PSR3_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH5_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH5(value)           (MATRIX_PSR3_RDUSERH5_Msk & ((value) << MATRIX_PSR3_RDUSERH5_Pos))
#define MATRIX_PSR3_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH6_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH6(value)           (MATRIX_PSR3_RDUSERH6_Msk & ((value) << MATRIX_PSR3_RDUSERH6_Pos))
#define MATRIX_PSR3_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR3_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR3_RDUSERH7_Pos)               /**< (MATRIX_PSR3) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_RDUSERH7(value)           (MATRIX_PSR3_RDUSERH7_Msk & ((value) << MATRIX_PSR3_RDUSERH7_Pos))
#define MATRIX_PSR3_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH0_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH0(value)           (MATRIX_PSR3_WRUSERH0_Msk & ((value) << MATRIX_PSR3_WRUSERH0_Pos))
#define MATRIX_PSR3_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH1_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH1(value)           (MATRIX_PSR3_WRUSERH1_Msk & ((value) << MATRIX_PSR3_WRUSERH1_Pos))
#define MATRIX_PSR3_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH2_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH2(value)           (MATRIX_PSR3_WRUSERH2_Msk & ((value) << MATRIX_PSR3_WRUSERH2_Pos))
#define MATRIX_PSR3_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH3_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH3(value)           (MATRIX_PSR3_WRUSERH3_Msk & ((value) << MATRIX_PSR3_WRUSERH3_Pos))
#define MATRIX_PSR3_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH4_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH4(value)           (MATRIX_PSR3_WRUSERH4_Msk & ((value) << MATRIX_PSR3_WRUSERH4_Pos))
#define MATRIX_PSR3_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH5_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH5(value)           (MATRIX_PSR3_WRUSERH5_Msk & ((value) << MATRIX_PSR3_WRUSERH5_Pos))
#define MATRIX_PSR3_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH6_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH6(value)           (MATRIX_PSR3_WRUSERH6_Msk & ((value) << MATRIX_PSR3_WRUSERH6_Pos))
#define MATRIX_PSR3_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR3_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR3_WRUSERH7_Pos)               /**< (MATRIX_PSR3) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR3_WRUSERH7(value)           (MATRIX_PSR3_WRUSERH7_Msk & ((value) << MATRIX_PSR3_WRUSERH7_Pos))
#define MATRIX_PSR3_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA0_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA0(value)             (MATRIX_PSR3_DPSOA0_Msk & ((value) << MATRIX_PSR3_DPSOA0_Pos))
#define MATRIX_PSR3_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA1_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA1(value)             (MATRIX_PSR3_DPSOA1_Msk & ((value) << MATRIX_PSR3_DPSOA1_Pos))
#define MATRIX_PSR3_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA2_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA2(value)             (MATRIX_PSR3_DPSOA2_Msk & ((value) << MATRIX_PSR3_DPSOA2_Pos))
#define MATRIX_PSR3_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA3_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA3(value)             (MATRIX_PSR3_DPSOA3_Msk & ((value) << MATRIX_PSR3_DPSOA3_Pos))
#define MATRIX_PSR3_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA4_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA4(value)             (MATRIX_PSR3_DPSOA4_Msk & ((value) << MATRIX_PSR3_DPSOA4_Pos))
#define MATRIX_PSR3_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA5_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA5(value)             (MATRIX_PSR3_DPSOA5_Msk & ((value) << MATRIX_PSR3_DPSOA5_Pos))
#define MATRIX_PSR3_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA6_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA6(value)             (MATRIX_PSR3_DPSOA6_Msk & ((value) << MATRIX_PSR3_DPSOA6_Pos))
#define MATRIX_PSR3_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR3_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR3_DPSOA7_Pos)                 /**< (MATRIX_PSR3) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR3_DPSOA7(value)             (MATRIX_PSR3_DPSOA7_Msk & ((value) << MATRIX_PSR3_DPSOA7_Pos))
#define MATRIX_PSR3_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR3) Register Mask  */

#define MATRIX_PSR3_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR3 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR3_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR3_LAUSERH_Pos)               /**< (MATRIX_PSR3 Mask) LAUSERH */
#define MATRIX_PSR3_LAUSERH(value)            (MATRIX_PSR3_LAUSERH_Msk & ((value) << MATRIX_PSR3_LAUSERH_Pos)) 
#define MATRIX_PSR3_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR3 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR3_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR3_RDUSERH_Pos)               /**< (MATRIX_PSR3 Mask) RDUSERH */
#define MATRIX_PSR3_RDUSERH(value)            (MATRIX_PSR3_RDUSERH_Msk & ((value) << MATRIX_PSR3_RDUSERH_Pos)) 
#define MATRIX_PSR3_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR3 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR3_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR3_WRUSERH_Pos)               /**< (MATRIX_PSR3 Mask) WRUSERH */
#define MATRIX_PSR3_WRUSERH(value)            (MATRIX_PSR3_WRUSERH_Msk & ((value) << MATRIX_PSR3_WRUSERH_Pos)) 
#define MATRIX_PSR3_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR3 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR3_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR3_DPSOA_Pos)                 /**< (MATRIX_PSR3 Mask) DPSOA */
#define MATRIX_PSR3_DPSOA(value)              (MATRIX_PSR3_DPSOA_Msk & ((value) << MATRIX_PSR3_DPSOA_Pos)) 

/* -------- MATRIX_PSR4 : (MATRIX Offset: 0x210) (R/W 32) Protection Slave 0 Register 4 -------- */
#define MATRIX_PSR4_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH0_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH0(value)           (MATRIX_PSR4_LAUSERH0_Msk & ((value) << MATRIX_PSR4_LAUSERH0_Pos))
#define MATRIX_PSR4_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH1_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH1(value)           (MATRIX_PSR4_LAUSERH1_Msk & ((value) << MATRIX_PSR4_LAUSERH1_Pos))
#define MATRIX_PSR4_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH2_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH2(value)           (MATRIX_PSR4_LAUSERH2_Msk & ((value) << MATRIX_PSR4_LAUSERH2_Pos))
#define MATRIX_PSR4_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH3_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH3(value)           (MATRIX_PSR4_LAUSERH3_Msk & ((value) << MATRIX_PSR4_LAUSERH3_Pos))
#define MATRIX_PSR4_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH4_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH4(value)           (MATRIX_PSR4_LAUSERH4_Msk & ((value) << MATRIX_PSR4_LAUSERH4_Pos))
#define MATRIX_PSR4_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH5_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH5(value)           (MATRIX_PSR4_LAUSERH5_Msk & ((value) << MATRIX_PSR4_LAUSERH5_Pos))
#define MATRIX_PSR4_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH6_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH6(value)           (MATRIX_PSR4_LAUSERH6_Msk & ((value) << MATRIX_PSR4_LAUSERH6_Pos))
#define MATRIX_PSR4_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR4_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR4_LAUSERH7_Pos)               /**< (MATRIX_PSR4) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR4_LAUSERH7(value)           (MATRIX_PSR4_LAUSERH7_Msk & ((value) << MATRIX_PSR4_LAUSERH7_Pos))
#define MATRIX_PSR4_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH0_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH0(value)           (MATRIX_PSR4_RDUSERH0_Msk & ((value) << MATRIX_PSR4_RDUSERH0_Pos))
#define MATRIX_PSR4_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH1_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH1(value)           (MATRIX_PSR4_RDUSERH1_Msk & ((value) << MATRIX_PSR4_RDUSERH1_Pos))
#define MATRIX_PSR4_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH2_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH2(value)           (MATRIX_PSR4_RDUSERH2_Msk & ((value) << MATRIX_PSR4_RDUSERH2_Pos))
#define MATRIX_PSR4_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH3_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH3(value)           (MATRIX_PSR4_RDUSERH3_Msk & ((value) << MATRIX_PSR4_RDUSERH3_Pos))
#define MATRIX_PSR4_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH4_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH4(value)           (MATRIX_PSR4_RDUSERH4_Msk & ((value) << MATRIX_PSR4_RDUSERH4_Pos))
#define MATRIX_PSR4_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH5_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH5(value)           (MATRIX_PSR4_RDUSERH5_Msk & ((value) << MATRIX_PSR4_RDUSERH5_Pos))
#define MATRIX_PSR4_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH6_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH6(value)           (MATRIX_PSR4_RDUSERH6_Msk & ((value) << MATRIX_PSR4_RDUSERH6_Pos))
#define MATRIX_PSR4_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR4_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR4_RDUSERH7_Pos)               /**< (MATRIX_PSR4) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_RDUSERH7(value)           (MATRIX_PSR4_RDUSERH7_Msk & ((value) << MATRIX_PSR4_RDUSERH7_Pos))
#define MATRIX_PSR4_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH0_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH0(value)           (MATRIX_PSR4_WRUSERH0_Msk & ((value) << MATRIX_PSR4_WRUSERH0_Pos))
#define MATRIX_PSR4_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH1_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH1(value)           (MATRIX_PSR4_WRUSERH1_Msk & ((value) << MATRIX_PSR4_WRUSERH1_Pos))
#define MATRIX_PSR4_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH2_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH2(value)           (MATRIX_PSR4_WRUSERH2_Msk & ((value) << MATRIX_PSR4_WRUSERH2_Pos))
#define MATRIX_PSR4_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH3_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH3(value)           (MATRIX_PSR4_WRUSERH3_Msk & ((value) << MATRIX_PSR4_WRUSERH3_Pos))
#define MATRIX_PSR4_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH4_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH4(value)           (MATRIX_PSR4_WRUSERH4_Msk & ((value) << MATRIX_PSR4_WRUSERH4_Pos))
#define MATRIX_PSR4_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH5_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH5(value)           (MATRIX_PSR4_WRUSERH5_Msk & ((value) << MATRIX_PSR4_WRUSERH5_Pos))
#define MATRIX_PSR4_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH6_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH6(value)           (MATRIX_PSR4_WRUSERH6_Msk & ((value) << MATRIX_PSR4_WRUSERH6_Pos))
#define MATRIX_PSR4_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR4_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR4_WRUSERH7_Pos)               /**< (MATRIX_PSR4) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR4_WRUSERH7(value)           (MATRIX_PSR4_WRUSERH7_Msk & ((value) << MATRIX_PSR4_WRUSERH7_Pos))
#define MATRIX_PSR4_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA0_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA0(value)             (MATRIX_PSR4_DPSOA0_Msk & ((value) << MATRIX_PSR4_DPSOA0_Pos))
#define MATRIX_PSR4_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA1_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA1(value)             (MATRIX_PSR4_DPSOA1_Msk & ((value) << MATRIX_PSR4_DPSOA1_Pos))
#define MATRIX_PSR4_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA2_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA2(value)             (MATRIX_PSR4_DPSOA2_Msk & ((value) << MATRIX_PSR4_DPSOA2_Pos))
#define MATRIX_PSR4_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA3_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA3(value)             (MATRIX_PSR4_DPSOA3_Msk & ((value) << MATRIX_PSR4_DPSOA3_Pos))
#define MATRIX_PSR4_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA4_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA4(value)             (MATRIX_PSR4_DPSOA4_Msk & ((value) << MATRIX_PSR4_DPSOA4_Pos))
#define MATRIX_PSR4_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA5_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA5(value)             (MATRIX_PSR4_DPSOA5_Msk & ((value) << MATRIX_PSR4_DPSOA5_Pos))
#define MATRIX_PSR4_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA6_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA6(value)             (MATRIX_PSR4_DPSOA6_Msk & ((value) << MATRIX_PSR4_DPSOA6_Pos))
#define MATRIX_PSR4_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR4_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR4_DPSOA7_Pos)                 /**< (MATRIX_PSR4) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR4_DPSOA7(value)             (MATRIX_PSR4_DPSOA7_Msk & ((value) << MATRIX_PSR4_DPSOA7_Pos))
#define MATRIX_PSR4_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR4) Register Mask  */

#define MATRIX_PSR4_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR4 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR4_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR4_LAUSERH_Pos)               /**< (MATRIX_PSR4 Mask) LAUSERH */
#define MATRIX_PSR4_LAUSERH(value)            (MATRIX_PSR4_LAUSERH_Msk & ((value) << MATRIX_PSR4_LAUSERH_Pos)) 
#define MATRIX_PSR4_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR4 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR4_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR4_RDUSERH_Pos)               /**< (MATRIX_PSR4 Mask) RDUSERH */
#define MATRIX_PSR4_RDUSERH(value)            (MATRIX_PSR4_RDUSERH_Msk & ((value) << MATRIX_PSR4_RDUSERH_Pos)) 
#define MATRIX_PSR4_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR4 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR4_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR4_WRUSERH_Pos)               /**< (MATRIX_PSR4 Mask) WRUSERH */
#define MATRIX_PSR4_WRUSERH(value)            (MATRIX_PSR4_WRUSERH_Msk & ((value) << MATRIX_PSR4_WRUSERH_Pos)) 
#define MATRIX_PSR4_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR4 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR4_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR4_DPSOA_Pos)                 /**< (MATRIX_PSR4 Mask) DPSOA */
#define MATRIX_PSR4_DPSOA(value)              (MATRIX_PSR4_DPSOA_Msk & ((value) << MATRIX_PSR4_DPSOA_Pos)) 

/* -------- MATRIX_PSR5 : (MATRIX Offset: 0x214) (R/W 32) Protection Slave 0 Register 5 -------- */
#define MATRIX_PSR5_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH0_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH0(value)           (MATRIX_PSR5_LAUSERH0_Msk & ((value) << MATRIX_PSR5_LAUSERH0_Pos))
#define MATRIX_PSR5_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH1_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH1(value)           (MATRIX_PSR5_LAUSERH1_Msk & ((value) << MATRIX_PSR5_LAUSERH1_Pos))
#define MATRIX_PSR5_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH2_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH2(value)           (MATRIX_PSR5_LAUSERH2_Msk & ((value) << MATRIX_PSR5_LAUSERH2_Pos))
#define MATRIX_PSR5_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH3_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH3(value)           (MATRIX_PSR5_LAUSERH3_Msk & ((value) << MATRIX_PSR5_LAUSERH3_Pos))
#define MATRIX_PSR5_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH4_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH4(value)           (MATRIX_PSR5_LAUSERH4_Msk & ((value) << MATRIX_PSR5_LAUSERH4_Pos))
#define MATRIX_PSR5_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH5_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH5(value)           (MATRIX_PSR5_LAUSERH5_Msk & ((value) << MATRIX_PSR5_LAUSERH5_Pos))
#define MATRIX_PSR5_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH6_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH6(value)           (MATRIX_PSR5_LAUSERH6_Msk & ((value) << MATRIX_PSR5_LAUSERH6_Pos))
#define MATRIX_PSR5_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR5_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR5_LAUSERH7_Pos)               /**< (MATRIX_PSR5) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR5_LAUSERH7(value)           (MATRIX_PSR5_LAUSERH7_Msk & ((value) << MATRIX_PSR5_LAUSERH7_Pos))
#define MATRIX_PSR5_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH0_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH0(value)           (MATRIX_PSR5_RDUSERH0_Msk & ((value) << MATRIX_PSR5_RDUSERH0_Pos))
#define MATRIX_PSR5_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH1_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH1(value)           (MATRIX_PSR5_RDUSERH1_Msk & ((value) << MATRIX_PSR5_RDUSERH1_Pos))
#define MATRIX_PSR5_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH2_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH2(value)           (MATRIX_PSR5_RDUSERH2_Msk & ((value) << MATRIX_PSR5_RDUSERH2_Pos))
#define MATRIX_PSR5_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH3_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH3(value)           (MATRIX_PSR5_RDUSERH3_Msk & ((value) << MATRIX_PSR5_RDUSERH3_Pos))
#define MATRIX_PSR5_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH4_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH4(value)           (MATRIX_PSR5_RDUSERH4_Msk & ((value) << MATRIX_PSR5_RDUSERH4_Pos))
#define MATRIX_PSR5_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH5_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH5(value)           (MATRIX_PSR5_RDUSERH5_Msk & ((value) << MATRIX_PSR5_RDUSERH5_Pos))
#define MATRIX_PSR5_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH6_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH6(value)           (MATRIX_PSR5_RDUSERH6_Msk & ((value) << MATRIX_PSR5_RDUSERH6_Pos))
#define MATRIX_PSR5_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR5_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR5_RDUSERH7_Pos)               /**< (MATRIX_PSR5) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_RDUSERH7(value)           (MATRIX_PSR5_RDUSERH7_Msk & ((value) << MATRIX_PSR5_RDUSERH7_Pos))
#define MATRIX_PSR5_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH0_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH0(value)           (MATRIX_PSR5_WRUSERH0_Msk & ((value) << MATRIX_PSR5_WRUSERH0_Pos))
#define MATRIX_PSR5_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH1_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH1(value)           (MATRIX_PSR5_WRUSERH1_Msk & ((value) << MATRIX_PSR5_WRUSERH1_Pos))
#define MATRIX_PSR5_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH2_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH2(value)           (MATRIX_PSR5_WRUSERH2_Msk & ((value) << MATRIX_PSR5_WRUSERH2_Pos))
#define MATRIX_PSR5_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH3_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH3(value)           (MATRIX_PSR5_WRUSERH3_Msk & ((value) << MATRIX_PSR5_WRUSERH3_Pos))
#define MATRIX_PSR5_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH4_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH4(value)           (MATRIX_PSR5_WRUSERH4_Msk & ((value) << MATRIX_PSR5_WRUSERH4_Pos))
#define MATRIX_PSR5_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH5_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH5(value)           (MATRIX_PSR5_WRUSERH5_Msk & ((value) << MATRIX_PSR5_WRUSERH5_Pos))
#define MATRIX_PSR5_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH6_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH6(value)           (MATRIX_PSR5_WRUSERH6_Msk & ((value) << MATRIX_PSR5_WRUSERH6_Pos))
#define MATRIX_PSR5_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR5_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR5_WRUSERH7_Pos)               /**< (MATRIX_PSR5) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR5_WRUSERH7(value)           (MATRIX_PSR5_WRUSERH7_Msk & ((value) << MATRIX_PSR5_WRUSERH7_Pos))
#define MATRIX_PSR5_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA0_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA0(value)             (MATRIX_PSR5_DPSOA0_Msk & ((value) << MATRIX_PSR5_DPSOA0_Pos))
#define MATRIX_PSR5_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA1_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA1(value)             (MATRIX_PSR5_DPSOA1_Msk & ((value) << MATRIX_PSR5_DPSOA1_Pos))
#define MATRIX_PSR5_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA2_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA2(value)             (MATRIX_PSR5_DPSOA2_Msk & ((value) << MATRIX_PSR5_DPSOA2_Pos))
#define MATRIX_PSR5_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA3_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA3(value)             (MATRIX_PSR5_DPSOA3_Msk & ((value) << MATRIX_PSR5_DPSOA3_Pos))
#define MATRIX_PSR5_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA4_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA4(value)             (MATRIX_PSR5_DPSOA4_Msk & ((value) << MATRIX_PSR5_DPSOA4_Pos))
#define MATRIX_PSR5_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA5_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA5(value)             (MATRIX_PSR5_DPSOA5_Msk & ((value) << MATRIX_PSR5_DPSOA5_Pos))
#define MATRIX_PSR5_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA6_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA6(value)             (MATRIX_PSR5_DPSOA6_Msk & ((value) << MATRIX_PSR5_DPSOA6_Pos))
#define MATRIX_PSR5_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR5_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR5_DPSOA7_Pos)                 /**< (MATRIX_PSR5) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR5_DPSOA7(value)             (MATRIX_PSR5_DPSOA7_Msk & ((value) << MATRIX_PSR5_DPSOA7_Pos))
#define MATRIX_PSR5_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR5) Register Mask  */

#define MATRIX_PSR5_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR5 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR5_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR5_LAUSERH_Pos)               /**< (MATRIX_PSR5 Mask) LAUSERH */
#define MATRIX_PSR5_LAUSERH(value)            (MATRIX_PSR5_LAUSERH_Msk & ((value) << MATRIX_PSR5_LAUSERH_Pos)) 
#define MATRIX_PSR5_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR5 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR5_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR5_RDUSERH_Pos)               /**< (MATRIX_PSR5 Mask) RDUSERH */
#define MATRIX_PSR5_RDUSERH(value)            (MATRIX_PSR5_RDUSERH_Msk & ((value) << MATRIX_PSR5_RDUSERH_Pos)) 
#define MATRIX_PSR5_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR5 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR5_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR5_WRUSERH_Pos)               /**< (MATRIX_PSR5 Mask) WRUSERH */
#define MATRIX_PSR5_WRUSERH(value)            (MATRIX_PSR5_WRUSERH_Msk & ((value) << MATRIX_PSR5_WRUSERH_Pos)) 
#define MATRIX_PSR5_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR5 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR5_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR5_DPSOA_Pos)                 /**< (MATRIX_PSR5 Mask) DPSOA */
#define MATRIX_PSR5_DPSOA(value)              (MATRIX_PSR5_DPSOA_Msk & ((value) << MATRIX_PSR5_DPSOA_Pos)) 

/* -------- MATRIX_PSR6 : (MATRIX Offset: 0x218) (R/W 32) Protection Slave 0 Register 6 -------- */
#define MATRIX_PSR6_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH0_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH0(value)           (MATRIX_PSR6_LAUSERH0_Msk & ((value) << MATRIX_PSR6_LAUSERH0_Pos))
#define MATRIX_PSR6_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH1_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH1(value)           (MATRIX_PSR6_LAUSERH1_Msk & ((value) << MATRIX_PSR6_LAUSERH1_Pos))
#define MATRIX_PSR6_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH2_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH2(value)           (MATRIX_PSR6_LAUSERH2_Msk & ((value) << MATRIX_PSR6_LAUSERH2_Pos))
#define MATRIX_PSR6_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH3_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH3(value)           (MATRIX_PSR6_LAUSERH3_Msk & ((value) << MATRIX_PSR6_LAUSERH3_Pos))
#define MATRIX_PSR6_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH4_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH4(value)           (MATRIX_PSR6_LAUSERH4_Msk & ((value) << MATRIX_PSR6_LAUSERH4_Pos))
#define MATRIX_PSR6_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH5_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH5(value)           (MATRIX_PSR6_LAUSERH5_Msk & ((value) << MATRIX_PSR6_LAUSERH5_Pos))
#define MATRIX_PSR6_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH6_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH6(value)           (MATRIX_PSR6_LAUSERH6_Msk & ((value) << MATRIX_PSR6_LAUSERH6_Pos))
#define MATRIX_PSR6_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR6_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR6_LAUSERH7_Pos)               /**< (MATRIX_PSR6) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR6_LAUSERH7(value)           (MATRIX_PSR6_LAUSERH7_Msk & ((value) << MATRIX_PSR6_LAUSERH7_Pos))
#define MATRIX_PSR6_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH0_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH0(value)           (MATRIX_PSR6_RDUSERH0_Msk & ((value) << MATRIX_PSR6_RDUSERH0_Pos))
#define MATRIX_PSR6_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH1_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH1(value)           (MATRIX_PSR6_RDUSERH1_Msk & ((value) << MATRIX_PSR6_RDUSERH1_Pos))
#define MATRIX_PSR6_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH2_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH2(value)           (MATRIX_PSR6_RDUSERH2_Msk & ((value) << MATRIX_PSR6_RDUSERH2_Pos))
#define MATRIX_PSR6_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH3_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH3(value)           (MATRIX_PSR6_RDUSERH3_Msk & ((value) << MATRIX_PSR6_RDUSERH3_Pos))
#define MATRIX_PSR6_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH4_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH4(value)           (MATRIX_PSR6_RDUSERH4_Msk & ((value) << MATRIX_PSR6_RDUSERH4_Pos))
#define MATRIX_PSR6_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH5_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH5(value)           (MATRIX_PSR6_RDUSERH5_Msk & ((value) << MATRIX_PSR6_RDUSERH5_Pos))
#define MATRIX_PSR6_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH6_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH6(value)           (MATRIX_PSR6_RDUSERH6_Msk & ((value) << MATRIX_PSR6_RDUSERH6_Pos))
#define MATRIX_PSR6_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR6_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR6_RDUSERH7_Pos)               /**< (MATRIX_PSR6) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_RDUSERH7(value)           (MATRIX_PSR6_RDUSERH7_Msk & ((value) << MATRIX_PSR6_RDUSERH7_Pos))
#define MATRIX_PSR6_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH0_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH0(value)           (MATRIX_PSR6_WRUSERH0_Msk & ((value) << MATRIX_PSR6_WRUSERH0_Pos))
#define MATRIX_PSR6_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH1_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH1(value)           (MATRIX_PSR6_WRUSERH1_Msk & ((value) << MATRIX_PSR6_WRUSERH1_Pos))
#define MATRIX_PSR6_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH2_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH2(value)           (MATRIX_PSR6_WRUSERH2_Msk & ((value) << MATRIX_PSR6_WRUSERH2_Pos))
#define MATRIX_PSR6_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH3_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH3(value)           (MATRIX_PSR6_WRUSERH3_Msk & ((value) << MATRIX_PSR6_WRUSERH3_Pos))
#define MATRIX_PSR6_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH4_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH4(value)           (MATRIX_PSR6_WRUSERH4_Msk & ((value) << MATRIX_PSR6_WRUSERH4_Pos))
#define MATRIX_PSR6_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH5_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH5(value)           (MATRIX_PSR6_WRUSERH5_Msk & ((value) << MATRIX_PSR6_WRUSERH5_Pos))
#define MATRIX_PSR6_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH6_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH6(value)           (MATRIX_PSR6_WRUSERH6_Msk & ((value) << MATRIX_PSR6_WRUSERH6_Pos))
#define MATRIX_PSR6_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR6_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR6_WRUSERH7_Pos)               /**< (MATRIX_PSR6) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR6_WRUSERH7(value)           (MATRIX_PSR6_WRUSERH7_Msk & ((value) << MATRIX_PSR6_WRUSERH7_Pos))
#define MATRIX_PSR6_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA0_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA0(value)             (MATRIX_PSR6_DPSOA0_Msk & ((value) << MATRIX_PSR6_DPSOA0_Pos))
#define MATRIX_PSR6_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA1_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA1(value)             (MATRIX_PSR6_DPSOA1_Msk & ((value) << MATRIX_PSR6_DPSOA1_Pos))
#define MATRIX_PSR6_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA2_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA2(value)             (MATRIX_PSR6_DPSOA2_Msk & ((value) << MATRIX_PSR6_DPSOA2_Pos))
#define MATRIX_PSR6_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA3_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA3(value)             (MATRIX_PSR6_DPSOA3_Msk & ((value) << MATRIX_PSR6_DPSOA3_Pos))
#define MATRIX_PSR6_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA4_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA4(value)             (MATRIX_PSR6_DPSOA4_Msk & ((value) << MATRIX_PSR6_DPSOA4_Pos))
#define MATRIX_PSR6_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA5_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA5(value)             (MATRIX_PSR6_DPSOA5_Msk & ((value) << MATRIX_PSR6_DPSOA5_Pos))
#define MATRIX_PSR6_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA6_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA6(value)             (MATRIX_PSR6_DPSOA6_Msk & ((value) << MATRIX_PSR6_DPSOA6_Pos))
#define MATRIX_PSR6_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR6_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR6_DPSOA7_Pos)                 /**< (MATRIX_PSR6) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR6_DPSOA7(value)             (MATRIX_PSR6_DPSOA7_Msk & ((value) << MATRIX_PSR6_DPSOA7_Pos))
#define MATRIX_PSR6_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR6) Register Mask  */

#define MATRIX_PSR6_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR6 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR6_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR6_LAUSERH_Pos)               /**< (MATRIX_PSR6 Mask) LAUSERH */
#define MATRIX_PSR6_LAUSERH(value)            (MATRIX_PSR6_LAUSERH_Msk & ((value) << MATRIX_PSR6_LAUSERH_Pos)) 
#define MATRIX_PSR6_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR6 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR6_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR6_RDUSERH_Pos)               /**< (MATRIX_PSR6 Mask) RDUSERH */
#define MATRIX_PSR6_RDUSERH(value)            (MATRIX_PSR6_RDUSERH_Msk & ((value) << MATRIX_PSR6_RDUSERH_Pos)) 
#define MATRIX_PSR6_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR6 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR6_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR6_WRUSERH_Pos)               /**< (MATRIX_PSR6 Mask) WRUSERH */
#define MATRIX_PSR6_WRUSERH(value)            (MATRIX_PSR6_WRUSERH_Msk & ((value) << MATRIX_PSR6_WRUSERH_Pos)) 
#define MATRIX_PSR6_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR6 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR6_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR6_DPSOA_Pos)                 /**< (MATRIX_PSR6 Mask) DPSOA */
#define MATRIX_PSR6_DPSOA(value)              (MATRIX_PSR6_DPSOA_Msk & ((value) << MATRIX_PSR6_DPSOA_Pos)) 

/* -------- MATRIX_PSR7 : (MATRIX Offset: 0x21C) (R/W 32) Protection Slave 0 Register 7 -------- */
#define MATRIX_PSR7_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH0_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH0(value)           (MATRIX_PSR7_LAUSERH0_Msk & ((value) << MATRIX_PSR7_LAUSERH0_Pos))
#define MATRIX_PSR7_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH1_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH1(value)           (MATRIX_PSR7_LAUSERH1_Msk & ((value) << MATRIX_PSR7_LAUSERH1_Pos))
#define MATRIX_PSR7_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH2_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH2(value)           (MATRIX_PSR7_LAUSERH2_Msk & ((value) << MATRIX_PSR7_LAUSERH2_Pos))
#define MATRIX_PSR7_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH3_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH3(value)           (MATRIX_PSR7_LAUSERH3_Msk & ((value) << MATRIX_PSR7_LAUSERH3_Pos))
#define MATRIX_PSR7_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH4_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH4(value)           (MATRIX_PSR7_LAUSERH4_Msk & ((value) << MATRIX_PSR7_LAUSERH4_Pos))
#define MATRIX_PSR7_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH5_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH5(value)           (MATRIX_PSR7_LAUSERH5_Msk & ((value) << MATRIX_PSR7_LAUSERH5_Pos))
#define MATRIX_PSR7_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH6_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH6(value)           (MATRIX_PSR7_LAUSERH6_Msk & ((value) << MATRIX_PSR7_LAUSERH6_Pos))
#define MATRIX_PSR7_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR7_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR7_LAUSERH7_Pos)               /**< (MATRIX_PSR7) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR7_LAUSERH7(value)           (MATRIX_PSR7_LAUSERH7_Msk & ((value) << MATRIX_PSR7_LAUSERH7_Pos))
#define MATRIX_PSR7_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH0_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH0(value)           (MATRIX_PSR7_RDUSERH0_Msk & ((value) << MATRIX_PSR7_RDUSERH0_Pos))
#define MATRIX_PSR7_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH1_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH1(value)           (MATRIX_PSR7_RDUSERH1_Msk & ((value) << MATRIX_PSR7_RDUSERH1_Pos))
#define MATRIX_PSR7_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH2_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH2(value)           (MATRIX_PSR7_RDUSERH2_Msk & ((value) << MATRIX_PSR7_RDUSERH2_Pos))
#define MATRIX_PSR7_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH3_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH3(value)           (MATRIX_PSR7_RDUSERH3_Msk & ((value) << MATRIX_PSR7_RDUSERH3_Pos))
#define MATRIX_PSR7_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH4_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH4(value)           (MATRIX_PSR7_RDUSERH4_Msk & ((value) << MATRIX_PSR7_RDUSERH4_Pos))
#define MATRIX_PSR7_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH5_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH5(value)           (MATRIX_PSR7_RDUSERH5_Msk & ((value) << MATRIX_PSR7_RDUSERH5_Pos))
#define MATRIX_PSR7_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH6_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH6(value)           (MATRIX_PSR7_RDUSERH6_Msk & ((value) << MATRIX_PSR7_RDUSERH6_Pos))
#define MATRIX_PSR7_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR7_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR7_RDUSERH7_Pos)               /**< (MATRIX_PSR7) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_RDUSERH7(value)           (MATRIX_PSR7_RDUSERH7_Msk & ((value) << MATRIX_PSR7_RDUSERH7_Pos))
#define MATRIX_PSR7_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH0_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH0(value)           (MATRIX_PSR7_WRUSERH0_Msk & ((value) << MATRIX_PSR7_WRUSERH0_Pos))
#define MATRIX_PSR7_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH1_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH1(value)           (MATRIX_PSR7_WRUSERH1_Msk & ((value) << MATRIX_PSR7_WRUSERH1_Pos))
#define MATRIX_PSR7_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH2_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH2(value)           (MATRIX_PSR7_WRUSERH2_Msk & ((value) << MATRIX_PSR7_WRUSERH2_Pos))
#define MATRIX_PSR7_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH3_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH3(value)           (MATRIX_PSR7_WRUSERH3_Msk & ((value) << MATRIX_PSR7_WRUSERH3_Pos))
#define MATRIX_PSR7_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH4_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH4(value)           (MATRIX_PSR7_WRUSERH4_Msk & ((value) << MATRIX_PSR7_WRUSERH4_Pos))
#define MATRIX_PSR7_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH5_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH5(value)           (MATRIX_PSR7_WRUSERH5_Msk & ((value) << MATRIX_PSR7_WRUSERH5_Pos))
#define MATRIX_PSR7_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH6_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH6(value)           (MATRIX_PSR7_WRUSERH6_Msk & ((value) << MATRIX_PSR7_WRUSERH6_Pos))
#define MATRIX_PSR7_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR7_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR7_WRUSERH7_Pos)               /**< (MATRIX_PSR7) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR7_WRUSERH7(value)           (MATRIX_PSR7_WRUSERH7_Msk & ((value) << MATRIX_PSR7_WRUSERH7_Pos))
#define MATRIX_PSR7_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA0_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA0(value)             (MATRIX_PSR7_DPSOA0_Msk & ((value) << MATRIX_PSR7_DPSOA0_Pos))
#define MATRIX_PSR7_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA1_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA1(value)             (MATRIX_PSR7_DPSOA1_Msk & ((value) << MATRIX_PSR7_DPSOA1_Pos))
#define MATRIX_PSR7_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA2_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA2(value)             (MATRIX_PSR7_DPSOA2_Msk & ((value) << MATRIX_PSR7_DPSOA2_Pos))
#define MATRIX_PSR7_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA3_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA3(value)             (MATRIX_PSR7_DPSOA3_Msk & ((value) << MATRIX_PSR7_DPSOA3_Pos))
#define MATRIX_PSR7_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA4_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA4(value)             (MATRIX_PSR7_DPSOA4_Msk & ((value) << MATRIX_PSR7_DPSOA4_Pos))
#define MATRIX_PSR7_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA5_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA5(value)             (MATRIX_PSR7_DPSOA5_Msk & ((value) << MATRIX_PSR7_DPSOA5_Pos))
#define MATRIX_PSR7_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA6_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA6(value)             (MATRIX_PSR7_DPSOA6_Msk & ((value) << MATRIX_PSR7_DPSOA6_Pos))
#define MATRIX_PSR7_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR7_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR7_DPSOA7_Pos)                 /**< (MATRIX_PSR7) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR7_DPSOA7(value)             (MATRIX_PSR7_DPSOA7_Msk & ((value) << MATRIX_PSR7_DPSOA7_Pos))
#define MATRIX_PSR7_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR7) Register Mask  */

#define MATRIX_PSR7_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR7 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR7_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR7_LAUSERH_Pos)               /**< (MATRIX_PSR7 Mask) LAUSERH */
#define MATRIX_PSR7_LAUSERH(value)            (MATRIX_PSR7_LAUSERH_Msk & ((value) << MATRIX_PSR7_LAUSERH_Pos)) 
#define MATRIX_PSR7_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR7 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR7_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR7_RDUSERH_Pos)               /**< (MATRIX_PSR7 Mask) RDUSERH */
#define MATRIX_PSR7_RDUSERH(value)            (MATRIX_PSR7_RDUSERH_Msk & ((value) << MATRIX_PSR7_RDUSERH_Pos)) 
#define MATRIX_PSR7_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR7 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR7_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR7_WRUSERH_Pos)               /**< (MATRIX_PSR7 Mask) WRUSERH */
#define MATRIX_PSR7_WRUSERH(value)            (MATRIX_PSR7_WRUSERH_Msk & ((value) << MATRIX_PSR7_WRUSERH_Pos)) 
#define MATRIX_PSR7_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR7 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR7_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR7_DPSOA_Pos)                 /**< (MATRIX_PSR7 Mask) DPSOA */
#define MATRIX_PSR7_DPSOA(value)              (MATRIX_PSR7_DPSOA_Msk & ((value) << MATRIX_PSR7_DPSOA_Pos)) 

/* -------- MATRIX_PSR8 : (MATRIX Offset: 0x220) (R/W 32) Protection Slave 0 Register 8 -------- */
#define MATRIX_PSR8_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH0_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH0(value)           (MATRIX_PSR8_LAUSERH0_Msk & ((value) << MATRIX_PSR8_LAUSERH0_Pos))
#define MATRIX_PSR8_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH1_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH1(value)           (MATRIX_PSR8_LAUSERH1_Msk & ((value) << MATRIX_PSR8_LAUSERH1_Pos))
#define MATRIX_PSR8_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH2_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH2(value)           (MATRIX_PSR8_LAUSERH2_Msk & ((value) << MATRIX_PSR8_LAUSERH2_Pos))
#define MATRIX_PSR8_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH3_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH3(value)           (MATRIX_PSR8_LAUSERH3_Msk & ((value) << MATRIX_PSR8_LAUSERH3_Pos))
#define MATRIX_PSR8_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH4_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH4(value)           (MATRIX_PSR8_LAUSERH4_Msk & ((value) << MATRIX_PSR8_LAUSERH4_Pos))
#define MATRIX_PSR8_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH5_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH5(value)           (MATRIX_PSR8_LAUSERH5_Msk & ((value) << MATRIX_PSR8_LAUSERH5_Pos))
#define MATRIX_PSR8_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH6_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH6(value)           (MATRIX_PSR8_LAUSERH6_Msk & ((value) << MATRIX_PSR8_LAUSERH6_Pos))
#define MATRIX_PSR8_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR8_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR8_LAUSERH7_Pos)               /**< (MATRIX_PSR8) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR8_LAUSERH7(value)           (MATRIX_PSR8_LAUSERH7_Msk & ((value) << MATRIX_PSR8_LAUSERH7_Pos))
#define MATRIX_PSR8_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH0_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH0(value)           (MATRIX_PSR8_RDUSERH0_Msk & ((value) << MATRIX_PSR8_RDUSERH0_Pos))
#define MATRIX_PSR8_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH1_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH1(value)           (MATRIX_PSR8_RDUSERH1_Msk & ((value) << MATRIX_PSR8_RDUSERH1_Pos))
#define MATRIX_PSR8_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH2_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH2(value)           (MATRIX_PSR8_RDUSERH2_Msk & ((value) << MATRIX_PSR8_RDUSERH2_Pos))
#define MATRIX_PSR8_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH3_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH3(value)           (MATRIX_PSR8_RDUSERH3_Msk & ((value) << MATRIX_PSR8_RDUSERH3_Pos))
#define MATRIX_PSR8_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH4_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH4(value)           (MATRIX_PSR8_RDUSERH4_Msk & ((value) << MATRIX_PSR8_RDUSERH4_Pos))
#define MATRIX_PSR8_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH5_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH5(value)           (MATRIX_PSR8_RDUSERH5_Msk & ((value) << MATRIX_PSR8_RDUSERH5_Pos))
#define MATRIX_PSR8_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH6_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH6(value)           (MATRIX_PSR8_RDUSERH6_Msk & ((value) << MATRIX_PSR8_RDUSERH6_Pos))
#define MATRIX_PSR8_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR8_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR8_RDUSERH7_Pos)               /**< (MATRIX_PSR8) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_RDUSERH7(value)           (MATRIX_PSR8_RDUSERH7_Msk & ((value) << MATRIX_PSR8_RDUSERH7_Pos))
#define MATRIX_PSR8_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH0_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH0(value)           (MATRIX_PSR8_WRUSERH0_Msk & ((value) << MATRIX_PSR8_WRUSERH0_Pos))
#define MATRIX_PSR8_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH1_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH1(value)           (MATRIX_PSR8_WRUSERH1_Msk & ((value) << MATRIX_PSR8_WRUSERH1_Pos))
#define MATRIX_PSR8_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH2_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH2(value)           (MATRIX_PSR8_WRUSERH2_Msk & ((value) << MATRIX_PSR8_WRUSERH2_Pos))
#define MATRIX_PSR8_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH3_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH3(value)           (MATRIX_PSR8_WRUSERH3_Msk & ((value) << MATRIX_PSR8_WRUSERH3_Pos))
#define MATRIX_PSR8_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH4_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH4(value)           (MATRIX_PSR8_WRUSERH4_Msk & ((value) << MATRIX_PSR8_WRUSERH4_Pos))
#define MATRIX_PSR8_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH5_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH5(value)           (MATRIX_PSR8_WRUSERH5_Msk & ((value) << MATRIX_PSR8_WRUSERH5_Pos))
#define MATRIX_PSR8_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH6_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH6(value)           (MATRIX_PSR8_WRUSERH6_Msk & ((value) << MATRIX_PSR8_WRUSERH6_Pos))
#define MATRIX_PSR8_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR8_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR8_WRUSERH7_Pos)               /**< (MATRIX_PSR8) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR8_WRUSERH7(value)           (MATRIX_PSR8_WRUSERH7_Msk & ((value) << MATRIX_PSR8_WRUSERH7_Pos))
#define MATRIX_PSR8_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA0_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA0(value)             (MATRIX_PSR8_DPSOA0_Msk & ((value) << MATRIX_PSR8_DPSOA0_Pos))
#define MATRIX_PSR8_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA1_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA1(value)             (MATRIX_PSR8_DPSOA1_Msk & ((value) << MATRIX_PSR8_DPSOA1_Pos))
#define MATRIX_PSR8_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA2_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA2(value)             (MATRIX_PSR8_DPSOA2_Msk & ((value) << MATRIX_PSR8_DPSOA2_Pos))
#define MATRIX_PSR8_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA3_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA3(value)             (MATRIX_PSR8_DPSOA3_Msk & ((value) << MATRIX_PSR8_DPSOA3_Pos))
#define MATRIX_PSR8_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA4_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA4(value)             (MATRIX_PSR8_DPSOA4_Msk & ((value) << MATRIX_PSR8_DPSOA4_Pos))
#define MATRIX_PSR8_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA5_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA5(value)             (MATRIX_PSR8_DPSOA5_Msk & ((value) << MATRIX_PSR8_DPSOA5_Pos))
#define MATRIX_PSR8_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA6_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA6(value)             (MATRIX_PSR8_DPSOA6_Msk & ((value) << MATRIX_PSR8_DPSOA6_Pos))
#define MATRIX_PSR8_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR8_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR8_DPSOA7_Pos)                 /**< (MATRIX_PSR8) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR8_DPSOA7(value)             (MATRIX_PSR8_DPSOA7_Msk & ((value) << MATRIX_PSR8_DPSOA7_Pos))
#define MATRIX_PSR8_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR8) Register Mask  */

#define MATRIX_PSR8_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR8 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR8_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR8_LAUSERH_Pos)               /**< (MATRIX_PSR8 Mask) LAUSERH */
#define MATRIX_PSR8_LAUSERH(value)            (MATRIX_PSR8_LAUSERH_Msk & ((value) << MATRIX_PSR8_LAUSERH_Pos)) 
#define MATRIX_PSR8_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR8 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR8_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR8_RDUSERH_Pos)               /**< (MATRIX_PSR8 Mask) RDUSERH */
#define MATRIX_PSR8_RDUSERH(value)            (MATRIX_PSR8_RDUSERH_Msk & ((value) << MATRIX_PSR8_RDUSERH_Pos)) 
#define MATRIX_PSR8_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR8 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR8_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR8_WRUSERH_Pos)               /**< (MATRIX_PSR8 Mask) WRUSERH */
#define MATRIX_PSR8_WRUSERH(value)            (MATRIX_PSR8_WRUSERH_Msk & ((value) << MATRIX_PSR8_WRUSERH_Pos)) 
#define MATRIX_PSR8_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR8 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR8_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR8_DPSOA_Pos)                 /**< (MATRIX_PSR8 Mask) DPSOA */
#define MATRIX_PSR8_DPSOA(value)              (MATRIX_PSR8_DPSOA_Msk & ((value) << MATRIX_PSR8_DPSOA_Pos)) 

/* -------- MATRIX_PSR9 : (MATRIX Offset: 0x224) (R/W 32) Protection Slave 0 Register 9 -------- */
#define MATRIX_PSR9_LAUSERH0_Pos              _U_(0)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH0_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH0_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH0(value)           (MATRIX_PSR9_LAUSERH0_Msk & ((value) << MATRIX_PSR9_LAUSERH0_Pos))
#define MATRIX_PSR9_LAUSERH1_Pos              _U_(1)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH1_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH1_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH1(value)           (MATRIX_PSR9_LAUSERH1_Msk & ((value) << MATRIX_PSR9_LAUSERH1_Pos))
#define MATRIX_PSR9_LAUSERH2_Pos              _U_(2)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH2_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH2_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH2(value)           (MATRIX_PSR9_LAUSERH2_Msk & ((value) << MATRIX_PSR9_LAUSERH2_Pos))
#define MATRIX_PSR9_LAUSERH3_Pos              _U_(3)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH3_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH3_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH3(value)           (MATRIX_PSR9_LAUSERH3_Msk & ((value) << MATRIX_PSR9_LAUSERH3_Pos))
#define MATRIX_PSR9_LAUSERH4_Pos              _U_(4)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH4_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH4_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH4(value)           (MATRIX_PSR9_LAUSERH4_Msk & ((value) << MATRIX_PSR9_LAUSERH4_Pos))
#define MATRIX_PSR9_LAUSERH5_Pos              _U_(5)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH5_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH5_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH5(value)           (MATRIX_PSR9_LAUSERH5_Msk & ((value) << MATRIX_PSR9_LAUSERH5_Pos))
#define MATRIX_PSR9_LAUSERH6_Pos              _U_(6)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH6_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH6_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH6(value)           (MATRIX_PSR9_LAUSERH6_Msk & ((value) << MATRIX_PSR9_LAUSERH6_Pos))
#define MATRIX_PSR9_LAUSERH7_Pos              _U_(7)                                               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR9_LAUSERH7_Msk              (_U_(0x1) << MATRIX_PSR9_LAUSERH7_Pos)               /**< (MATRIX_PSR9) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR9_LAUSERH7(value)           (MATRIX_PSR9_LAUSERH7_Msk & ((value) << MATRIX_PSR9_LAUSERH7_Pos))
#define MATRIX_PSR9_RDUSERH0_Pos              _U_(8)                                               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH0_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH0_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH0(value)           (MATRIX_PSR9_RDUSERH0_Msk & ((value) << MATRIX_PSR9_RDUSERH0_Pos))
#define MATRIX_PSR9_RDUSERH1_Pos              _U_(9)                                               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH1_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH1_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH1(value)           (MATRIX_PSR9_RDUSERH1_Msk & ((value) << MATRIX_PSR9_RDUSERH1_Pos))
#define MATRIX_PSR9_RDUSERH2_Pos              _U_(10)                                              /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH2_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH2_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH2(value)           (MATRIX_PSR9_RDUSERH2_Msk & ((value) << MATRIX_PSR9_RDUSERH2_Pos))
#define MATRIX_PSR9_RDUSERH3_Pos              _U_(11)                                              /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH3_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH3_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH3(value)           (MATRIX_PSR9_RDUSERH3_Msk & ((value) << MATRIX_PSR9_RDUSERH3_Pos))
#define MATRIX_PSR9_RDUSERH4_Pos              _U_(12)                                              /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH4_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH4_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH4(value)           (MATRIX_PSR9_RDUSERH4_Msk & ((value) << MATRIX_PSR9_RDUSERH4_Pos))
#define MATRIX_PSR9_RDUSERH5_Pos              _U_(13)                                              /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH5_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH5_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH5(value)           (MATRIX_PSR9_RDUSERH5_Msk & ((value) << MATRIX_PSR9_RDUSERH5_Pos))
#define MATRIX_PSR9_RDUSERH6_Pos              _U_(14)                                              /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH6_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH6_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH6(value)           (MATRIX_PSR9_RDUSERH6_Msk & ((value) << MATRIX_PSR9_RDUSERH6_Pos))
#define MATRIX_PSR9_RDUSERH7_Pos              _U_(15)                                              /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR9_RDUSERH7_Msk              (_U_(0x1) << MATRIX_PSR9_RDUSERH7_Pos)               /**< (MATRIX_PSR9) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_RDUSERH7(value)           (MATRIX_PSR9_RDUSERH7_Msk & ((value) << MATRIX_PSR9_RDUSERH7_Pos))
#define MATRIX_PSR9_WRUSERH0_Pos              _U_(16)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH0_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH0_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH0(value)           (MATRIX_PSR9_WRUSERH0_Msk & ((value) << MATRIX_PSR9_WRUSERH0_Pos))
#define MATRIX_PSR9_WRUSERH1_Pos              _U_(17)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH1_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH1_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH1(value)           (MATRIX_PSR9_WRUSERH1_Msk & ((value) << MATRIX_PSR9_WRUSERH1_Pos))
#define MATRIX_PSR9_WRUSERH2_Pos              _U_(18)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH2_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH2_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH2(value)           (MATRIX_PSR9_WRUSERH2_Msk & ((value) << MATRIX_PSR9_WRUSERH2_Pos))
#define MATRIX_PSR9_WRUSERH3_Pos              _U_(19)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH3_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH3_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH3(value)           (MATRIX_PSR9_WRUSERH3_Msk & ((value) << MATRIX_PSR9_WRUSERH3_Pos))
#define MATRIX_PSR9_WRUSERH4_Pos              _U_(20)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH4_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH4_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH4(value)           (MATRIX_PSR9_WRUSERH4_Msk & ((value) << MATRIX_PSR9_WRUSERH4_Pos))
#define MATRIX_PSR9_WRUSERH5_Pos              _U_(21)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH5_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH5_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH5(value)           (MATRIX_PSR9_WRUSERH5_Msk & ((value) << MATRIX_PSR9_WRUSERH5_Pos))
#define MATRIX_PSR9_WRUSERH6_Pos              _U_(22)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH6_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH6_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH6(value)           (MATRIX_PSR9_WRUSERH6_Msk & ((value) << MATRIX_PSR9_WRUSERH6_Pos))
#define MATRIX_PSR9_WRUSERH7_Pos              _U_(23)                                              /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR9_WRUSERH7_Msk              (_U_(0x1) << MATRIX_PSR9_WRUSERH7_Pos)               /**< (MATRIX_PSR9) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR9_WRUSERH7(value)           (MATRIX_PSR9_WRUSERH7_Msk & ((value) << MATRIX_PSR9_WRUSERH7_Pos))
#define MATRIX_PSR9_DPSOA0_Pos                _U_(24)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA0_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA0_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA0(value)             (MATRIX_PSR9_DPSOA0_Msk & ((value) << MATRIX_PSR9_DPSOA0_Pos))
#define MATRIX_PSR9_DPSOA1_Pos                _U_(25)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA1_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA1_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA1(value)             (MATRIX_PSR9_DPSOA1_Msk & ((value) << MATRIX_PSR9_DPSOA1_Pos))
#define MATRIX_PSR9_DPSOA2_Pos                _U_(26)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA2_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA2_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA2(value)             (MATRIX_PSR9_DPSOA2_Msk & ((value) << MATRIX_PSR9_DPSOA2_Pos))
#define MATRIX_PSR9_DPSOA3_Pos                _U_(27)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA3_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA3_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA3(value)             (MATRIX_PSR9_DPSOA3_Msk & ((value) << MATRIX_PSR9_DPSOA3_Pos))
#define MATRIX_PSR9_DPSOA4_Pos                _U_(28)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA4_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA4_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA4(value)             (MATRIX_PSR9_DPSOA4_Msk & ((value) << MATRIX_PSR9_DPSOA4_Pos))
#define MATRIX_PSR9_DPSOA5_Pos                _U_(29)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA5_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA5_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA5(value)             (MATRIX_PSR9_DPSOA5_Msk & ((value) << MATRIX_PSR9_DPSOA5_Pos))
#define MATRIX_PSR9_DPSOA6_Pos                _U_(30)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA6_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA6_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA6(value)             (MATRIX_PSR9_DPSOA6_Msk & ((value) << MATRIX_PSR9_DPSOA6_Pos))
#define MATRIX_PSR9_DPSOA7_Pos                _U_(31)                                              /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR9_DPSOA7_Msk                (_U_(0x1) << MATRIX_PSR9_DPSOA7_Pos)                 /**< (MATRIX_PSR9) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR9_DPSOA7(value)             (MATRIX_PSR9_DPSOA7_Msk & ((value) << MATRIX_PSR9_DPSOA7_Pos))
#define MATRIX_PSR9_Msk                       _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR9) Register Mask  */

#define MATRIX_PSR9_LAUSERH_Pos               _U_(0)                                               /**< (MATRIX_PSR9 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR9_LAUSERH_Msk               (_U_(0xFF) << MATRIX_PSR9_LAUSERH_Pos)               /**< (MATRIX_PSR9 Mask) LAUSERH */
#define MATRIX_PSR9_LAUSERH(value)            (MATRIX_PSR9_LAUSERH_Msk & ((value) << MATRIX_PSR9_LAUSERH_Pos)) 
#define MATRIX_PSR9_RDUSERH_Pos               _U_(8)                                               /**< (MATRIX_PSR9 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR9_RDUSERH_Msk               (_U_(0xFF) << MATRIX_PSR9_RDUSERH_Pos)               /**< (MATRIX_PSR9 Mask) RDUSERH */
#define MATRIX_PSR9_RDUSERH(value)            (MATRIX_PSR9_RDUSERH_Msk & ((value) << MATRIX_PSR9_RDUSERH_Pos)) 
#define MATRIX_PSR9_WRUSERH_Pos               _U_(16)                                              /**< (MATRIX_PSR9 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR9_WRUSERH_Msk               (_U_(0xFF) << MATRIX_PSR9_WRUSERH_Pos)               /**< (MATRIX_PSR9 Mask) WRUSERH */
#define MATRIX_PSR9_WRUSERH(value)            (MATRIX_PSR9_WRUSERH_Msk & ((value) << MATRIX_PSR9_WRUSERH_Pos)) 
#define MATRIX_PSR9_DPSOA_Pos                 _U_(24)                                              /**< (MATRIX_PSR9 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR9_DPSOA_Msk                 (_U_(0xFF) << MATRIX_PSR9_DPSOA_Pos)                 /**< (MATRIX_PSR9 Mask) DPSOA */
#define MATRIX_PSR9_DPSOA(value)              (MATRIX_PSR9_DPSOA_Msk & ((value) << MATRIX_PSR9_DPSOA_Pos)) 

/* -------- MATRIX_PSR10 : (MATRIX Offset: 0x228) (R/W 32) Protection Slave 0 Register 10 -------- */
#define MATRIX_PSR10_LAUSERH0_Pos             _U_(0)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH0_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH0_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH0(value)          (MATRIX_PSR10_LAUSERH0_Msk & ((value) << MATRIX_PSR10_LAUSERH0_Pos))
#define MATRIX_PSR10_LAUSERH1_Pos             _U_(1)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH1_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH1_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH1(value)          (MATRIX_PSR10_LAUSERH1_Msk & ((value) << MATRIX_PSR10_LAUSERH1_Pos))
#define MATRIX_PSR10_LAUSERH2_Pos             _U_(2)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH2_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH2_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH2(value)          (MATRIX_PSR10_LAUSERH2_Msk & ((value) << MATRIX_PSR10_LAUSERH2_Pos))
#define MATRIX_PSR10_LAUSERH3_Pos             _U_(3)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH3_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH3_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH3(value)          (MATRIX_PSR10_LAUSERH3_Msk & ((value) << MATRIX_PSR10_LAUSERH3_Pos))
#define MATRIX_PSR10_LAUSERH4_Pos             _U_(4)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH4_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH4_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH4(value)          (MATRIX_PSR10_LAUSERH4_Msk & ((value) << MATRIX_PSR10_LAUSERH4_Pos))
#define MATRIX_PSR10_LAUSERH5_Pos             _U_(5)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH5_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH5_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH5(value)          (MATRIX_PSR10_LAUSERH5_Msk & ((value) << MATRIX_PSR10_LAUSERH5_Pos))
#define MATRIX_PSR10_LAUSERH6_Pos             _U_(6)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH6_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH6_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH6(value)          (MATRIX_PSR10_LAUSERH6_Msk & ((value) << MATRIX_PSR10_LAUSERH6_Pos))
#define MATRIX_PSR10_LAUSERH7_Pos             _U_(7)                                               /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR10_LAUSERH7_Msk             (_U_(0x1) << MATRIX_PSR10_LAUSERH7_Pos)              /**< (MATRIX_PSR10) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR10_LAUSERH7(value)          (MATRIX_PSR10_LAUSERH7_Msk & ((value) << MATRIX_PSR10_LAUSERH7_Pos))
#define MATRIX_PSR10_RDUSERH0_Pos             _U_(8)                                               /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH0_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH0_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH0(value)          (MATRIX_PSR10_RDUSERH0_Msk & ((value) << MATRIX_PSR10_RDUSERH0_Pos))
#define MATRIX_PSR10_RDUSERH1_Pos             _U_(9)                                               /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH1_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH1_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH1(value)          (MATRIX_PSR10_RDUSERH1_Msk & ((value) << MATRIX_PSR10_RDUSERH1_Pos))
#define MATRIX_PSR10_RDUSERH2_Pos             _U_(10)                                              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH2_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH2_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH2(value)          (MATRIX_PSR10_RDUSERH2_Msk & ((value) << MATRIX_PSR10_RDUSERH2_Pos))
#define MATRIX_PSR10_RDUSERH3_Pos             _U_(11)                                              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH3_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH3_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH3(value)          (MATRIX_PSR10_RDUSERH3_Msk & ((value) << MATRIX_PSR10_RDUSERH3_Pos))
#define MATRIX_PSR10_RDUSERH4_Pos             _U_(12)                                              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH4_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH4_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH4(value)          (MATRIX_PSR10_RDUSERH4_Msk & ((value) << MATRIX_PSR10_RDUSERH4_Pos))
#define MATRIX_PSR10_RDUSERH5_Pos             _U_(13)                                              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH5_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH5_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH5(value)          (MATRIX_PSR10_RDUSERH5_Msk & ((value) << MATRIX_PSR10_RDUSERH5_Pos))
#define MATRIX_PSR10_RDUSERH6_Pos             _U_(14)                                              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH6_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH6_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH6(value)          (MATRIX_PSR10_RDUSERH6_Msk & ((value) << MATRIX_PSR10_RDUSERH6_Pos))
#define MATRIX_PSR10_RDUSERH7_Pos             _U_(15)                                              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR10_RDUSERH7_Msk             (_U_(0x1) << MATRIX_PSR10_RDUSERH7_Pos)              /**< (MATRIX_PSR10) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_RDUSERH7(value)          (MATRIX_PSR10_RDUSERH7_Msk & ((value) << MATRIX_PSR10_RDUSERH7_Pos))
#define MATRIX_PSR10_WRUSERH0_Pos             _U_(16)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH0_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH0_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH0(value)          (MATRIX_PSR10_WRUSERH0_Msk & ((value) << MATRIX_PSR10_WRUSERH0_Pos))
#define MATRIX_PSR10_WRUSERH1_Pos             _U_(17)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH1_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH1_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH1(value)          (MATRIX_PSR10_WRUSERH1_Msk & ((value) << MATRIX_PSR10_WRUSERH1_Pos))
#define MATRIX_PSR10_WRUSERH2_Pos             _U_(18)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH2_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH2_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH2(value)          (MATRIX_PSR10_WRUSERH2_Msk & ((value) << MATRIX_PSR10_WRUSERH2_Pos))
#define MATRIX_PSR10_WRUSERH3_Pos             _U_(19)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH3_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH3_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH3(value)          (MATRIX_PSR10_WRUSERH3_Msk & ((value) << MATRIX_PSR10_WRUSERH3_Pos))
#define MATRIX_PSR10_WRUSERH4_Pos             _U_(20)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH4_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH4_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH4(value)          (MATRIX_PSR10_WRUSERH4_Msk & ((value) << MATRIX_PSR10_WRUSERH4_Pos))
#define MATRIX_PSR10_WRUSERH5_Pos             _U_(21)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH5_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH5_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH5(value)          (MATRIX_PSR10_WRUSERH5_Msk & ((value) << MATRIX_PSR10_WRUSERH5_Pos))
#define MATRIX_PSR10_WRUSERH6_Pos             _U_(22)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH6_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH6_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH6(value)          (MATRIX_PSR10_WRUSERH6_Msk & ((value) << MATRIX_PSR10_WRUSERH6_Pos))
#define MATRIX_PSR10_WRUSERH7_Pos             _U_(23)                                              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR10_WRUSERH7_Msk             (_U_(0x1) << MATRIX_PSR10_WRUSERH7_Pos)              /**< (MATRIX_PSR10) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR10_WRUSERH7(value)          (MATRIX_PSR10_WRUSERH7_Msk & ((value) << MATRIX_PSR10_WRUSERH7_Pos))
#define MATRIX_PSR10_DPSOA0_Pos               _U_(24)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA0_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA0_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA0(value)            (MATRIX_PSR10_DPSOA0_Msk & ((value) << MATRIX_PSR10_DPSOA0_Pos))
#define MATRIX_PSR10_DPSOA1_Pos               _U_(25)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA1_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA1_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA1(value)            (MATRIX_PSR10_DPSOA1_Msk & ((value) << MATRIX_PSR10_DPSOA1_Pos))
#define MATRIX_PSR10_DPSOA2_Pos               _U_(26)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA2_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA2_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA2(value)            (MATRIX_PSR10_DPSOA2_Msk & ((value) << MATRIX_PSR10_DPSOA2_Pos))
#define MATRIX_PSR10_DPSOA3_Pos               _U_(27)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA3_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA3_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA3(value)            (MATRIX_PSR10_DPSOA3_Msk & ((value) << MATRIX_PSR10_DPSOA3_Pos))
#define MATRIX_PSR10_DPSOA4_Pos               _U_(28)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA4_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA4_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA4(value)            (MATRIX_PSR10_DPSOA4_Msk & ((value) << MATRIX_PSR10_DPSOA4_Pos))
#define MATRIX_PSR10_DPSOA5_Pos               _U_(29)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA5_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA5_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA5(value)            (MATRIX_PSR10_DPSOA5_Msk & ((value) << MATRIX_PSR10_DPSOA5_Pos))
#define MATRIX_PSR10_DPSOA6_Pos               _U_(30)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA6_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA6_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA6(value)            (MATRIX_PSR10_DPSOA6_Msk & ((value) << MATRIX_PSR10_DPSOA6_Pos))
#define MATRIX_PSR10_DPSOA7_Pos               _U_(31)                                              /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR10_DPSOA7_Msk               (_U_(0x1) << MATRIX_PSR10_DPSOA7_Pos)                /**< (MATRIX_PSR10) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR10_DPSOA7(value)            (MATRIX_PSR10_DPSOA7_Msk & ((value) << MATRIX_PSR10_DPSOA7_Pos))
#define MATRIX_PSR10_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR10) Register Mask  */

#define MATRIX_PSR10_LAUSERH_Pos              _U_(0)                                               /**< (MATRIX_PSR10 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR10_LAUSERH_Msk              (_U_(0xFF) << MATRIX_PSR10_LAUSERH_Pos)              /**< (MATRIX_PSR10 Mask) LAUSERH */
#define MATRIX_PSR10_LAUSERH(value)           (MATRIX_PSR10_LAUSERH_Msk & ((value) << MATRIX_PSR10_LAUSERH_Pos)) 
#define MATRIX_PSR10_RDUSERH_Pos              _U_(8)                                               /**< (MATRIX_PSR10 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR10_RDUSERH_Msk              (_U_(0xFF) << MATRIX_PSR10_RDUSERH_Pos)              /**< (MATRIX_PSR10 Mask) RDUSERH */
#define MATRIX_PSR10_RDUSERH(value)           (MATRIX_PSR10_RDUSERH_Msk & ((value) << MATRIX_PSR10_RDUSERH_Pos)) 
#define MATRIX_PSR10_WRUSERH_Pos              _U_(16)                                              /**< (MATRIX_PSR10 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR10_WRUSERH_Msk              (_U_(0xFF) << MATRIX_PSR10_WRUSERH_Pos)              /**< (MATRIX_PSR10 Mask) WRUSERH */
#define MATRIX_PSR10_WRUSERH(value)           (MATRIX_PSR10_WRUSERH_Msk & ((value) << MATRIX_PSR10_WRUSERH_Pos)) 
#define MATRIX_PSR10_DPSOA_Pos                _U_(24)                                              /**< (MATRIX_PSR10 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR10_DPSOA_Msk                (_U_(0xFF) << MATRIX_PSR10_DPSOA_Pos)                /**< (MATRIX_PSR10 Mask) DPSOA */
#define MATRIX_PSR10_DPSOA(value)             (MATRIX_PSR10_DPSOA_Msk & ((value) << MATRIX_PSR10_DPSOA_Pos)) 

/* -------- MATRIX_PSR11 : (MATRIX Offset: 0x22C) (R/W 32) Protection Slave 0 Register 11 -------- */
#define MATRIX_PSR11_LAUSERH0_Pos             _U_(0)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH0_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH0_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH0(value)          (MATRIX_PSR11_LAUSERH0_Msk & ((value) << MATRIX_PSR11_LAUSERH0_Pos))
#define MATRIX_PSR11_LAUSERH1_Pos             _U_(1)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH1_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH1_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH1(value)          (MATRIX_PSR11_LAUSERH1_Msk & ((value) << MATRIX_PSR11_LAUSERH1_Pos))
#define MATRIX_PSR11_LAUSERH2_Pos             _U_(2)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH2_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH2_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH2(value)          (MATRIX_PSR11_LAUSERH2_Msk & ((value) << MATRIX_PSR11_LAUSERH2_Pos))
#define MATRIX_PSR11_LAUSERH3_Pos             _U_(3)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH3_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH3_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH3(value)          (MATRIX_PSR11_LAUSERH3_Msk & ((value) << MATRIX_PSR11_LAUSERH3_Pos))
#define MATRIX_PSR11_LAUSERH4_Pos             _U_(4)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH4_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH4_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH4(value)          (MATRIX_PSR11_LAUSERH4_Msk & ((value) << MATRIX_PSR11_LAUSERH4_Pos))
#define MATRIX_PSR11_LAUSERH5_Pos             _U_(5)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH5_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH5_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH5(value)          (MATRIX_PSR11_LAUSERH5_Msk & ((value) << MATRIX_PSR11_LAUSERH5_Pos))
#define MATRIX_PSR11_LAUSERH6_Pos             _U_(6)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH6_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH6_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH6(value)          (MATRIX_PSR11_LAUSERH6_Msk & ((value) << MATRIX_PSR11_LAUSERH6_Pos))
#define MATRIX_PSR11_LAUSERH7_Pos             _U_(7)                                               /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR11_LAUSERH7_Msk             (_U_(0x1) << MATRIX_PSR11_LAUSERH7_Pos)              /**< (MATRIX_PSR11) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR11_LAUSERH7(value)          (MATRIX_PSR11_LAUSERH7_Msk & ((value) << MATRIX_PSR11_LAUSERH7_Pos))
#define MATRIX_PSR11_RDUSERH0_Pos             _U_(8)                                               /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH0_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH0_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH0(value)          (MATRIX_PSR11_RDUSERH0_Msk & ((value) << MATRIX_PSR11_RDUSERH0_Pos))
#define MATRIX_PSR11_RDUSERH1_Pos             _U_(9)                                               /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH1_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH1_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH1(value)          (MATRIX_PSR11_RDUSERH1_Msk & ((value) << MATRIX_PSR11_RDUSERH1_Pos))
#define MATRIX_PSR11_RDUSERH2_Pos             _U_(10)                                              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH2_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH2_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH2(value)          (MATRIX_PSR11_RDUSERH2_Msk & ((value) << MATRIX_PSR11_RDUSERH2_Pos))
#define MATRIX_PSR11_RDUSERH3_Pos             _U_(11)                                              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH3_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH3_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH3(value)          (MATRIX_PSR11_RDUSERH3_Msk & ((value) << MATRIX_PSR11_RDUSERH3_Pos))
#define MATRIX_PSR11_RDUSERH4_Pos             _U_(12)                                              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH4_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH4_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH4(value)          (MATRIX_PSR11_RDUSERH4_Msk & ((value) << MATRIX_PSR11_RDUSERH4_Pos))
#define MATRIX_PSR11_RDUSERH5_Pos             _U_(13)                                              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH5_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH5_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH5(value)          (MATRIX_PSR11_RDUSERH5_Msk & ((value) << MATRIX_PSR11_RDUSERH5_Pos))
#define MATRIX_PSR11_RDUSERH6_Pos             _U_(14)                                              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH6_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH6_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH6(value)          (MATRIX_PSR11_RDUSERH6_Msk & ((value) << MATRIX_PSR11_RDUSERH6_Pos))
#define MATRIX_PSR11_RDUSERH7_Pos             _U_(15)                                              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR11_RDUSERH7_Msk             (_U_(0x1) << MATRIX_PSR11_RDUSERH7_Pos)              /**< (MATRIX_PSR11) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_RDUSERH7(value)          (MATRIX_PSR11_RDUSERH7_Msk & ((value) << MATRIX_PSR11_RDUSERH7_Pos))
#define MATRIX_PSR11_WRUSERH0_Pos             _U_(16)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH0_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH0_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH0(value)          (MATRIX_PSR11_WRUSERH0_Msk & ((value) << MATRIX_PSR11_WRUSERH0_Pos))
#define MATRIX_PSR11_WRUSERH1_Pos             _U_(17)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH1_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH1_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH1(value)          (MATRIX_PSR11_WRUSERH1_Msk & ((value) << MATRIX_PSR11_WRUSERH1_Pos))
#define MATRIX_PSR11_WRUSERH2_Pos             _U_(18)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH2_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH2_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH2(value)          (MATRIX_PSR11_WRUSERH2_Msk & ((value) << MATRIX_PSR11_WRUSERH2_Pos))
#define MATRIX_PSR11_WRUSERH3_Pos             _U_(19)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH3_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH3_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH3(value)          (MATRIX_PSR11_WRUSERH3_Msk & ((value) << MATRIX_PSR11_WRUSERH3_Pos))
#define MATRIX_PSR11_WRUSERH4_Pos             _U_(20)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH4_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH4_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH4(value)          (MATRIX_PSR11_WRUSERH4_Msk & ((value) << MATRIX_PSR11_WRUSERH4_Pos))
#define MATRIX_PSR11_WRUSERH5_Pos             _U_(21)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH5_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH5_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH5(value)          (MATRIX_PSR11_WRUSERH5_Msk & ((value) << MATRIX_PSR11_WRUSERH5_Pos))
#define MATRIX_PSR11_WRUSERH6_Pos             _U_(22)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH6_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH6_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH6(value)          (MATRIX_PSR11_WRUSERH6_Msk & ((value) << MATRIX_PSR11_WRUSERH6_Pos))
#define MATRIX_PSR11_WRUSERH7_Pos             _U_(23)                                              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR11_WRUSERH7_Msk             (_U_(0x1) << MATRIX_PSR11_WRUSERH7_Pos)              /**< (MATRIX_PSR11) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR11_WRUSERH7(value)          (MATRIX_PSR11_WRUSERH7_Msk & ((value) << MATRIX_PSR11_WRUSERH7_Pos))
#define MATRIX_PSR11_DPSOA0_Pos               _U_(24)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA0_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA0_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA0(value)            (MATRIX_PSR11_DPSOA0_Msk & ((value) << MATRIX_PSR11_DPSOA0_Pos))
#define MATRIX_PSR11_DPSOA1_Pos               _U_(25)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA1_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA1_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA1(value)            (MATRIX_PSR11_DPSOA1_Msk & ((value) << MATRIX_PSR11_DPSOA1_Pos))
#define MATRIX_PSR11_DPSOA2_Pos               _U_(26)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA2_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA2_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA2(value)            (MATRIX_PSR11_DPSOA2_Msk & ((value) << MATRIX_PSR11_DPSOA2_Pos))
#define MATRIX_PSR11_DPSOA3_Pos               _U_(27)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA3_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA3_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA3(value)            (MATRIX_PSR11_DPSOA3_Msk & ((value) << MATRIX_PSR11_DPSOA3_Pos))
#define MATRIX_PSR11_DPSOA4_Pos               _U_(28)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA4_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA4_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA4(value)            (MATRIX_PSR11_DPSOA4_Msk & ((value) << MATRIX_PSR11_DPSOA4_Pos))
#define MATRIX_PSR11_DPSOA5_Pos               _U_(29)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA5_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA5_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA5(value)            (MATRIX_PSR11_DPSOA5_Msk & ((value) << MATRIX_PSR11_DPSOA5_Pos))
#define MATRIX_PSR11_DPSOA6_Pos               _U_(30)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA6_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA6_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA6(value)            (MATRIX_PSR11_DPSOA6_Msk & ((value) << MATRIX_PSR11_DPSOA6_Pos))
#define MATRIX_PSR11_DPSOA7_Pos               _U_(31)                                              /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR11_DPSOA7_Msk               (_U_(0x1) << MATRIX_PSR11_DPSOA7_Pos)                /**< (MATRIX_PSR11) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR11_DPSOA7(value)            (MATRIX_PSR11_DPSOA7_Msk & ((value) << MATRIX_PSR11_DPSOA7_Pos))
#define MATRIX_PSR11_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR11) Register Mask  */

#define MATRIX_PSR11_LAUSERH_Pos              _U_(0)                                               /**< (MATRIX_PSR11 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR11_LAUSERH_Msk              (_U_(0xFF) << MATRIX_PSR11_LAUSERH_Pos)              /**< (MATRIX_PSR11 Mask) LAUSERH */
#define MATRIX_PSR11_LAUSERH(value)           (MATRIX_PSR11_LAUSERH_Msk & ((value) << MATRIX_PSR11_LAUSERH_Pos)) 
#define MATRIX_PSR11_RDUSERH_Pos              _U_(8)                                               /**< (MATRIX_PSR11 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR11_RDUSERH_Msk              (_U_(0xFF) << MATRIX_PSR11_RDUSERH_Pos)              /**< (MATRIX_PSR11 Mask) RDUSERH */
#define MATRIX_PSR11_RDUSERH(value)           (MATRIX_PSR11_RDUSERH_Msk & ((value) << MATRIX_PSR11_RDUSERH_Pos)) 
#define MATRIX_PSR11_WRUSERH_Pos              _U_(16)                                              /**< (MATRIX_PSR11 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR11_WRUSERH_Msk              (_U_(0xFF) << MATRIX_PSR11_WRUSERH_Pos)              /**< (MATRIX_PSR11 Mask) WRUSERH */
#define MATRIX_PSR11_WRUSERH(value)           (MATRIX_PSR11_WRUSERH_Msk & ((value) << MATRIX_PSR11_WRUSERH_Pos)) 
#define MATRIX_PSR11_DPSOA_Pos                _U_(24)                                              /**< (MATRIX_PSR11 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR11_DPSOA_Msk                (_U_(0xFF) << MATRIX_PSR11_DPSOA_Pos)                /**< (MATRIX_PSR11 Mask) DPSOA */
#define MATRIX_PSR11_DPSOA(value)             (MATRIX_PSR11_DPSOA_Msk & ((value) << MATRIX_PSR11_DPSOA_Pos)) 

/* -------- MATRIX_PSR12 : (MATRIX Offset: 0x230) (R/W 32) Protection Slave 0 Register 12 -------- */
#define MATRIX_PSR12_LAUSERH0_Pos             _U_(0)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH0_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH0_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH0(value)          (MATRIX_PSR12_LAUSERH0_Msk & ((value) << MATRIX_PSR12_LAUSERH0_Pos))
#define MATRIX_PSR12_LAUSERH1_Pos             _U_(1)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH1_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH1_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH1(value)          (MATRIX_PSR12_LAUSERH1_Msk & ((value) << MATRIX_PSR12_LAUSERH1_Pos))
#define MATRIX_PSR12_LAUSERH2_Pos             _U_(2)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH2_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH2_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH2(value)          (MATRIX_PSR12_LAUSERH2_Msk & ((value) << MATRIX_PSR12_LAUSERH2_Pos))
#define MATRIX_PSR12_LAUSERH3_Pos             _U_(3)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH3_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH3_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH3(value)          (MATRIX_PSR12_LAUSERH3_Msk & ((value) << MATRIX_PSR12_LAUSERH3_Pos))
#define MATRIX_PSR12_LAUSERH4_Pos             _U_(4)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH4_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH4_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH4(value)          (MATRIX_PSR12_LAUSERH4_Msk & ((value) << MATRIX_PSR12_LAUSERH4_Pos))
#define MATRIX_PSR12_LAUSERH5_Pos             _U_(5)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH5_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH5_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH5(value)          (MATRIX_PSR12_LAUSERH5_Msk & ((value) << MATRIX_PSR12_LAUSERH5_Pos))
#define MATRIX_PSR12_LAUSERH6_Pos             _U_(6)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH6_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH6_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH6(value)          (MATRIX_PSR12_LAUSERH6_Msk & ((value) << MATRIX_PSR12_LAUSERH6_Pos))
#define MATRIX_PSR12_LAUSERH7_Pos             _U_(7)                                               /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR12_LAUSERH7_Msk             (_U_(0x1) << MATRIX_PSR12_LAUSERH7_Pos)              /**< (MATRIX_PSR12) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR12_LAUSERH7(value)          (MATRIX_PSR12_LAUSERH7_Msk & ((value) << MATRIX_PSR12_LAUSERH7_Pos))
#define MATRIX_PSR12_RDUSERH0_Pos             _U_(8)                                               /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH0_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH0_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH0(value)          (MATRIX_PSR12_RDUSERH0_Msk & ((value) << MATRIX_PSR12_RDUSERH0_Pos))
#define MATRIX_PSR12_RDUSERH1_Pos             _U_(9)                                               /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH1_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH1_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH1(value)          (MATRIX_PSR12_RDUSERH1_Msk & ((value) << MATRIX_PSR12_RDUSERH1_Pos))
#define MATRIX_PSR12_RDUSERH2_Pos             _U_(10)                                              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH2_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH2_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH2(value)          (MATRIX_PSR12_RDUSERH2_Msk & ((value) << MATRIX_PSR12_RDUSERH2_Pos))
#define MATRIX_PSR12_RDUSERH3_Pos             _U_(11)                                              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH3_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH3_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH3(value)          (MATRIX_PSR12_RDUSERH3_Msk & ((value) << MATRIX_PSR12_RDUSERH3_Pos))
#define MATRIX_PSR12_RDUSERH4_Pos             _U_(12)                                              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH4_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH4_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH4(value)          (MATRIX_PSR12_RDUSERH4_Msk & ((value) << MATRIX_PSR12_RDUSERH4_Pos))
#define MATRIX_PSR12_RDUSERH5_Pos             _U_(13)                                              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH5_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH5_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH5(value)          (MATRIX_PSR12_RDUSERH5_Msk & ((value) << MATRIX_PSR12_RDUSERH5_Pos))
#define MATRIX_PSR12_RDUSERH6_Pos             _U_(14)                                              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH6_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH6_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH6(value)          (MATRIX_PSR12_RDUSERH6_Msk & ((value) << MATRIX_PSR12_RDUSERH6_Pos))
#define MATRIX_PSR12_RDUSERH7_Pos             _U_(15)                                              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR12_RDUSERH7_Msk             (_U_(0x1) << MATRIX_PSR12_RDUSERH7_Pos)              /**< (MATRIX_PSR12) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_RDUSERH7(value)          (MATRIX_PSR12_RDUSERH7_Msk & ((value) << MATRIX_PSR12_RDUSERH7_Pos))
#define MATRIX_PSR12_WRUSERH0_Pos             _U_(16)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH0_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH0_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH0(value)          (MATRIX_PSR12_WRUSERH0_Msk & ((value) << MATRIX_PSR12_WRUSERH0_Pos))
#define MATRIX_PSR12_WRUSERH1_Pos             _U_(17)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH1_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH1_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH1(value)          (MATRIX_PSR12_WRUSERH1_Msk & ((value) << MATRIX_PSR12_WRUSERH1_Pos))
#define MATRIX_PSR12_WRUSERH2_Pos             _U_(18)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH2_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH2_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH2(value)          (MATRIX_PSR12_WRUSERH2_Msk & ((value) << MATRIX_PSR12_WRUSERH2_Pos))
#define MATRIX_PSR12_WRUSERH3_Pos             _U_(19)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH3_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH3_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH3(value)          (MATRIX_PSR12_WRUSERH3_Msk & ((value) << MATRIX_PSR12_WRUSERH3_Pos))
#define MATRIX_PSR12_WRUSERH4_Pos             _U_(20)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH4_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH4_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH4(value)          (MATRIX_PSR12_WRUSERH4_Msk & ((value) << MATRIX_PSR12_WRUSERH4_Pos))
#define MATRIX_PSR12_WRUSERH5_Pos             _U_(21)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH5_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH5_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH5(value)          (MATRIX_PSR12_WRUSERH5_Msk & ((value) << MATRIX_PSR12_WRUSERH5_Pos))
#define MATRIX_PSR12_WRUSERH6_Pos             _U_(22)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH6_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH6_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH6(value)          (MATRIX_PSR12_WRUSERH6_Msk & ((value) << MATRIX_PSR12_WRUSERH6_Pos))
#define MATRIX_PSR12_WRUSERH7_Pos             _U_(23)                                              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR12_WRUSERH7_Msk             (_U_(0x1) << MATRIX_PSR12_WRUSERH7_Pos)              /**< (MATRIX_PSR12) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR12_WRUSERH7(value)          (MATRIX_PSR12_WRUSERH7_Msk & ((value) << MATRIX_PSR12_WRUSERH7_Pos))
#define MATRIX_PSR12_DPSOA0_Pos               _U_(24)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA0_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA0_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA0(value)            (MATRIX_PSR12_DPSOA0_Msk & ((value) << MATRIX_PSR12_DPSOA0_Pos))
#define MATRIX_PSR12_DPSOA1_Pos               _U_(25)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA1_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA1_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA1(value)            (MATRIX_PSR12_DPSOA1_Msk & ((value) << MATRIX_PSR12_DPSOA1_Pos))
#define MATRIX_PSR12_DPSOA2_Pos               _U_(26)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA2_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA2_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA2(value)            (MATRIX_PSR12_DPSOA2_Msk & ((value) << MATRIX_PSR12_DPSOA2_Pos))
#define MATRIX_PSR12_DPSOA3_Pos               _U_(27)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA3_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA3_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA3(value)            (MATRIX_PSR12_DPSOA3_Msk & ((value) << MATRIX_PSR12_DPSOA3_Pos))
#define MATRIX_PSR12_DPSOA4_Pos               _U_(28)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA4_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA4_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA4(value)            (MATRIX_PSR12_DPSOA4_Msk & ((value) << MATRIX_PSR12_DPSOA4_Pos))
#define MATRIX_PSR12_DPSOA5_Pos               _U_(29)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA5_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA5_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA5(value)            (MATRIX_PSR12_DPSOA5_Msk & ((value) << MATRIX_PSR12_DPSOA5_Pos))
#define MATRIX_PSR12_DPSOA6_Pos               _U_(30)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA6_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA6_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA6(value)            (MATRIX_PSR12_DPSOA6_Msk & ((value) << MATRIX_PSR12_DPSOA6_Pos))
#define MATRIX_PSR12_DPSOA7_Pos               _U_(31)                                              /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR12_DPSOA7_Msk               (_U_(0x1) << MATRIX_PSR12_DPSOA7_Pos)                /**< (MATRIX_PSR12) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR12_DPSOA7(value)            (MATRIX_PSR12_DPSOA7_Msk & ((value) << MATRIX_PSR12_DPSOA7_Pos))
#define MATRIX_PSR12_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR12) Register Mask  */

#define MATRIX_PSR12_LAUSERH_Pos              _U_(0)                                               /**< (MATRIX_PSR12 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR12_LAUSERH_Msk              (_U_(0xFF) << MATRIX_PSR12_LAUSERH_Pos)              /**< (MATRIX_PSR12 Mask) LAUSERH */
#define MATRIX_PSR12_LAUSERH(value)           (MATRIX_PSR12_LAUSERH_Msk & ((value) << MATRIX_PSR12_LAUSERH_Pos)) 
#define MATRIX_PSR12_RDUSERH_Pos              _U_(8)                                               /**< (MATRIX_PSR12 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR12_RDUSERH_Msk              (_U_(0xFF) << MATRIX_PSR12_RDUSERH_Pos)              /**< (MATRIX_PSR12 Mask) RDUSERH */
#define MATRIX_PSR12_RDUSERH(value)           (MATRIX_PSR12_RDUSERH_Msk & ((value) << MATRIX_PSR12_RDUSERH_Pos)) 
#define MATRIX_PSR12_WRUSERH_Pos              _U_(16)                                              /**< (MATRIX_PSR12 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR12_WRUSERH_Msk              (_U_(0xFF) << MATRIX_PSR12_WRUSERH_Pos)              /**< (MATRIX_PSR12 Mask) WRUSERH */
#define MATRIX_PSR12_WRUSERH(value)           (MATRIX_PSR12_WRUSERH_Msk & ((value) << MATRIX_PSR12_WRUSERH_Pos)) 
#define MATRIX_PSR12_DPSOA_Pos                _U_(24)                                              /**< (MATRIX_PSR12 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR12_DPSOA_Msk                (_U_(0xFF) << MATRIX_PSR12_DPSOA_Pos)                /**< (MATRIX_PSR12 Mask) DPSOA */
#define MATRIX_PSR12_DPSOA(value)             (MATRIX_PSR12_DPSOA_Msk & ((value) << MATRIX_PSR12_DPSOA_Pos)) 

/* -------- MATRIX_PSR13 : (MATRIX Offset: 0x234) (R/W 32) Protection Slave 0 Register 13 -------- */
#define MATRIX_PSR13_LAUSERH0_Pos             _U_(0)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH0_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH0_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH0(value)          (MATRIX_PSR13_LAUSERH0_Msk & ((value) << MATRIX_PSR13_LAUSERH0_Pos))
#define MATRIX_PSR13_LAUSERH1_Pos             _U_(1)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH1_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH1_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH1(value)          (MATRIX_PSR13_LAUSERH1_Msk & ((value) << MATRIX_PSR13_LAUSERH1_Pos))
#define MATRIX_PSR13_LAUSERH2_Pos             _U_(2)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH2_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH2_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH2(value)          (MATRIX_PSR13_LAUSERH2_Msk & ((value) << MATRIX_PSR13_LAUSERH2_Pos))
#define MATRIX_PSR13_LAUSERH3_Pos             _U_(3)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH3_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH3_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH3(value)          (MATRIX_PSR13_LAUSERH3_Msk & ((value) << MATRIX_PSR13_LAUSERH3_Pos))
#define MATRIX_PSR13_LAUSERH4_Pos             _U_(4)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH4_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH4_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH4(value)          (MATRIX_PSR13_LAUSERH4_Msk & ((value) << MATRIX_PSR13_LAUSERH4_Pos))
#define MATRIX_PSR13_LAUSERH5_Pos             _U_(5)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH5_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH5_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH5(value)          (MATRIX_PSR13_LAUSERH5_Msk & ((value) << MATRIX_PSR13_LAUSERH5_Pos))
#define MATRIX_PSR13_LAUSERH6_Pos             _U_(6)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH6_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH6_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH6(value)          (MATRIX_PSR13_LAUSERH6_Msk & ((value) << MATRIX_PSR13_LAUSERH6_Pos))
#define MATRIX_PSR13_LAUSERH7_Pos             _U_(7)                                               /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR13_LAUSERH7_Msk             (_U_(0x1) << MATRIX_PSR13_LAUSERH7_Pos)              /**< (MATRIX_PSR13) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR13_LAUSERH7(value)          (MATRIX_PSR13_LAUSERH7_Msk & ((value) << MATRIX_PSR13_LAUSERH7_Pos))
#define MATRIX_PSR13_RDUSERH0_Pos             _U_(8)                                               /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH0_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH0_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH0(value)          (MATRIX_PSR13_RDUSERH0_Msk & ((value) << MATRIX_PSR13_RDUSERH0_Pos))
#define MATRIX_PSR13_RDUSERH1_Pos             _U_(9)                                               /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH1_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH1_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH1(value)          (MATRIX_PSR13_RDUSERH1_Msk & ((value) << MATRIX_PSR13_RDUSERH1_Pos))
#define MATRIX_PSR13_RDUSERH2_Pos             _U_(10)                                              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH2_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH2_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH2(value)          (MATRIX_PSR13_RDUSERH2_Msk & ((value) << MATRIX_PSR13_RDUSERH2_Pos))
#define MATRIX_PSR13_RDUSERH3_Pos             _U_(11)                                              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH3_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH3_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH3(value)          (MATRIX_PSR13_RDUSERH3_Msk & ((value) << MATRIX_PSR13_RDUSERH3_Pos))
#define MATRIX_PSR13_RDUSERH4_Pos             _U_(12)                                              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH4_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH4_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH4(value)          (MATRIX_PSR13_RDUSERH4_Msk & ((value) << MATRIX_PSR13_RDUSERH4_Pos))
#define MATRIX_PSR13_RDUSERH5_Pos             _U_(13)                                              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH5_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH5_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH5(value)          (MATRIX_PSR13_RDUSERH5_Msk & ((value) << MATRIX_PSR13_RDUSERH5_Pos))
#define MATRIX_PSR13_RDUSERH6_Pos             _U_(14)                                              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH6_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH6_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH6(value)          (MATRIX_PSR13_RDUSERH6_Msk & ((value) << MATRIX_PSR13_RDUSERH6_Pos))
#define MATRIX_PSR13_RDUSERH7_Pos             _U_(15)                                              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR13_RDUSERH7_Msk             (_U_(0x1) << MATRIX_PSR13_RDUSERH7_Pos)              /**< (MATRIX_PSR13) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_RDUSERH7(value)          (MATRIX_PSR13_RDUSERH7_Msk & ((value) << MATRIX_PSR13_RDUSERH7_Pos))
#define MATRIX_PSR13_WRUSERH0_Pos             _U_(16)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH0_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH0_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH0(value)          (MATRIX_PSR13_WRUSERH0_Msk & ((value) << MATRIX_PSR13_WRUSERH0_Pos))
#define MATRIX_PSR13_WRUSERH1_Pos             _U_(17)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH1_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH1_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH1(value)          (MATRIX_PSR13_WRUSERH1_Msk & ((value) << MATRIX_PSR13_WRUSERH1_Pos))
#define MATRIX_PSR13_WRUSERH2_Pos             _U_(18)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH2_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH2_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH2(value)          (MATRIX_PSR13_WRUSERH2_Msk & ((value) << MATRIX_PSR13_WRUSERH2_Pos))
#define MATRIX_PSR13_WRUSERH3_Pos             _U_(19)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH3_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH3_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH3(value)          (MATRIX_PSR13_WRUSERH3_Msk & ((value) << MATRIX_PSR13_WRUSERH3_Pos))
#define MATRIX_PSR13_WRUSERH4_Pos             _U_(20)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH4_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH4_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH4(value)          (MATRIX_PSR13_WRUSERH4_Msk & ((value) << MATRIX_PSR13_WRUSERH4_Pos))
#define MATRIX_PSR13_WRUSERH5_Pos             _U_(21)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH5_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH5_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH5(value)          (MATRIX_PSR13_WRUSERH5_Msk & ((value) << MATRIX_PSR13_WRUSERH5_Pos))
#define MATRIX_PSR13_WRUSERH6_Pos             _U_(22)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH6_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH6_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH6(value)          (MATRIX_PSR13_WRUSERH6_Msk & ((value) << MATRIX_PSR13_WRUSERH6_Pos))
#define MATRIX_PSR13_WRUSERH7_Pos             _U_(23)                                              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR13_WRUSERH7_Msk             (_U_(0x1) << MATRIX_PSR13_WRUSERH7_Pos)              /**< (MATRIX_PSR13) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR13_WRUSERH7(value)          (MATRIX_PSR13_WRUSERH7_Msk & ((value) << MATRIX_PSR13_WRUSERH7_Pos))
#define MATRIX_PSR13_DPSOA0_Pos               _U_(24)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA0_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA0_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA0(value)            (MATRIX_PSR13_DPSOA0_Msk & ((value) << MATRIX_PSR13_DPSOA0_Pos))
#define MATRIX_PSR13_DPSOA1_Pos               _U_(25)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA1_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA1_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA1(value)            (MATRIX_PSR13_DPSOA1_Msk & ((value) << MATRIX_PSR13_DPSOA1_Pos))
#define MATRIX_PSR13_DPSOA2_Pos               _U_(26)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA2_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA2_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA2(value)            (MATRIX_PSR13_DPSOA2_Msk & ((value) << MATRIX_PSR13_DPSOA2_Pos))
#define MATRIX_PSR13_DPSOA3_Pos               _U_(27)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA3_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA3_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA3(value)            (MATRIX_PSR13_DPSOA3_Msk & ((value) << MATRIX_PSR13_DPSOA3_Pos))
#define MATRIX_PSR13_DPSOA4_Pos               _U_(28)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA4_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA4_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA4(value)            (MATRIX_PSR13_DPSOA4_Msk & ((value) << MATRIX_PSR13_DPSOA4_Pos))
#define MATRIX_PSR13_DPSOA5_Pos               _U_(29)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA5_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA5_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA5(value)            (MATRIX_PSR13_DPSOA5_Msk & ((value) << MATRIX_PSR13_DPSOA5_Pos))
#define MATRIX_PSR13_DPSOA6_Pos               _U_(30)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA6_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA6_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA6(value)            (MATRIX_PSR13_DPSOA6_Msk & ((value) << MATRIX_PSR13_DPSOA6_Pos))
#define MATRIX_PSR13_DPSOA7_Pos               _U_(31)                                              /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR13_DPSOA7_Msk               (_U_(0x1) << MATRIX_PSR13_DPSOA7_Pos)                /**< (MATRIX_PSR13) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR13_DPSOA7(value)            (MATRIX_PSR13_DPSOA7_Msk & ((value) << MATRIX_PSR13_DPSOA7_Pos))
#define MATRIX_PSR13_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR13) Register Mask  */

#define MATRIX_PSR13_LAUSERH_Pos              _U_(0)                                               /**< (MATRIX_PSR13 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR13_LAUSERH_Msk              (_U_(0xFF) << MATRIX_PSR13_LAUSERH_Pos)              /**< (MATRIX_PSR13 Mask) LAUSERH */
#define MATRIX_PSR13_LAUSERH(value)           (MATRIX_PSR13_LAUSERH_Msk & ((value) << MATRIX_PSR13_LAUSERH_Pos)) 
#define MATRIX_PSR13_RDUSERH_Pos              _U_(8)                                               /**< (MATRIX_PSR13 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR13_RDUSERH_Msk              (_U_(0xFF) << MATRIX_PSR13_RDUSERH_Pos)              /**< (MATRIX_PSR13 Mask) RDUSERH */
#define MATRIX_PSR13_RDUSERH(value)           (MATRIX_PSR13_RDUSERH_Msk & ((value) << MATRIX_PSR13_RDUSERH_Pos)) 
#define MATRIX_PSR13_WRUSERH_Pos              _U_(16)                                              /**< (MATRIX_PSR13 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR13_WRUSERH_Msk              (_U_(0xFF) << MATRIX_PSR13_WRUSERH_Pos)              /**< (MATRIX_PSR13 Mask) WRUSERH */
#define MATRIX_PSR13_WRUSERH(value)           (MATRIX_PSR13_WRUSERH_Msk & ((value) << MATRIX_PSR13_WRUSERH_Pos)) 
#define MATRIX_PSR13_DPSOA_Pos                _U_(24)                                              /**< (MATRIX_PSR13 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR13_DPSOA_Msk                (_U_(0xFF) << MATRIX_PSR13_DPSOA_Pos)                /**< (MATRIX_PSR13 Mask) DPSOA */
#define MATRIX_PSR13_DPSOA(value)             (MATRIX_PSR13_DPSOA_Msk & ((value) << MATRIX_PSR13_DPSOA_Pos)) 

/* -------- MATRIX_PSR14 : (MATRIX Offset: 0x238) (R/W 32) Protection Slave 0 Register 14 -------- */
#define MATRIX_PSR14_LAUSERH0_Pos             _U_(0)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH0_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH0_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH0(value)          (MATRIX_PSR14_LAUSERH0_Msk & ((value) << MATRIX_PSR14_LAUSERH0_Pos))
#define MATRIX_PSR14_LAUSERH1_Pos             _U_(1)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH1_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH1_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH1(value)          (MATRIX_PSR14_LAUSERH1_Msk & ((value) << MATRIX_PSR14_LAUSERH1_Pos))
#define MATRIX_PSR14_LAUSERH2_Pos             _U_(2)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH2_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH2_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH2(value)          (MATRIX_PSR14_LAUSERH2_Msk & ((value) << MATRIX_PSR14_LAUSERH2_Pos))
#define MATRIX_PSR14_LAUSERH3_Pos             _U_(3)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH3_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH3_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH3(value)          (MATRIX_PSR14_LAUSERH3_Msk & ((value) << MATRIX_PSR14_LAUSERH3_Pos))
#define MATRIX_PSR14_LAUSERH4_Pos             _U_(4)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH4_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH4_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH4(value)          (MATRIX_PSR14_LAUSERH4_Msk & ((value) << MATRIX_PSR14_LAUSERH4_Pos))
#define MATRIX_PSR14_LAUSERH5_Pos             _U_(5)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH5_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH5_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH5(value)          (MATRIX_PSR14_LAUSERH5_Msk & ((value) << MATRIX_PSR14_LAUSERH5_Pos))
#define MATRIX_PSR14_LAUSERH6_Pos             _U_(6)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH6_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH6_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH6(value)          (MATRIX_PSR14_LAUSERH6_Msk & ((value) << MATRIX_PSR14_LAUSERH6_Pos))
#define MATRIX_PSR14_LAUSERH7_Pos             _U_(7)                                               /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR14_LAUSERH7_Msk             (_U_(0x1) << MATRIX_PSR14_LAUSERH7_Pos)              /**< (MATRIX_PSR14) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR14_LAUSERH7(value)          (MATRIX_PSR14_LAUSERH7_Msk & ((value) << MATRIX_PSR14_LAUSERH7_Pos))
#define MATRIX_PSR14_RDUSERH0_Pos             _U_(8)                                               /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH0_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH0_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH0(value)          (MATRIX_PSR14_RDUSERH0_Msk & ((value) << MATRIX_PSR14_RDUSERH0_Pos))
#define MATRIX_PSR14_RDUSERH1_Pos             _U_(9)                                               /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH1_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH1_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH1(value)          (MATRIX_PSR14_RDUSERH1_Msk & ((value) << MATRIX_PSR14_RDUSERH1_Pos))
#define MATRIX_PSR14_RDUSERH2_Pos             _U_(10)                                              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH2_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH2_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH2(value)          (MATRIX_PSR14_RDUSERH2_Msk & ((value) << MATRIX_PSR14_RDUSERH2_Pos))
#define MATRIX_PSR14_RDUSERH3_Pos             _U_(11)                                              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH3_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH3_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH3(value)          (MATRIX_PSR14_RDUSERH3_Msk & ((value) << MATRIX_PSR14_RDUSERH3_Pos))
#define MATRIX_PSR14_RDUSERH4_Pos             _U_(12)                                              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH4_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH4_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH4(value)          (MATRIX_PSR14_RDUSERH4_Msk & ((value) << MATRIX_PSR14_RDUSERH4_Pos))
#define MATRIX_PSR14_RDUSERH5_Pos             _U_(13)                                              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH5_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH5_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH5(value)          (MATRIX_PSR14_RDUSERH5_Msk & ((value) << MATRIX_PSR14_RDUSERH5_Pos))
#define MATRIX_PSR14_RDUSERH6_Pos             _U_(14)                                              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH6_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH6_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH6(value)          (MATRIX_PSR14_RDUSERH6_Msk & ((value) << MATRIX_PSR14_RDUSERH6_Pos))
#define MATRIX_PSR14_RDUSERH7_Pos             _U_(15)                                              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR14_RDUSERH7_Msk             (_U_(0x1) << MATRIX_PSR14_RDUSERH7_Pos)              /**< (MATRIX_PSR14) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_RDUSERH7(value)          (MATRIX_PSR14_RDUSERH7_Msk & ((value) << MATRIX_PSR14_RDUSERH7_Pos))
#define MATRIX_PSR14_WRUSERH0_Pos             _U_(16)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH0_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH0_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH0(value)          (MATRIX_PSR14_WRUSERH0_Msk & ((value) << MATRIX_PSR14_WRUSERH0_Pos))
#define MATRIX_PSR14_WRUSERH1_Pos             _U_(17)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH1_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH1_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH1(value)          (MATRIX_PSR14_WRUSERH1_Msk & ((value) << MATRIX_PSR14_WRUSERH1_Pos))
#define MATRIX_PSR14_WRUSERH2_Pos             _U_(18)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH2_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH2_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH2(value)          (MATRIX_PSR14_WRUSERH2_Msk & ((value) << MATRIX_PSR14_WRUSERH2_Pos))
#define MATRIX_PSR14_WRUSERH3_Pos             _U_(19)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH3_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH3_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH3(value)          (MATRIX_PSR14_WRUSERH3_Msk & ((value) << MATRIX_PSR14_WRUSERH3_Pos))
#define MATRIX_PSR14_WRUSERH4_Pos             _U_(20)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH4_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH4_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH4(value)          (MATRIX_PSR14_WRUSERH4_Msk & ((value) << MATRIX_PSR14_WRUSERH4_Pos))
#define MATRIX_PSR14_WRUSERH5_Pos             _U_(21)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH5_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH5_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH5(value)          (MATRIX_PSR14_WRUSERH5_Msk & ((value) << MATRIX_PSR14_WRUSERH5_Pos))
#define MATRIX_PSR14_WRUSERH6_Pos             _U_(22)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH6_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH6_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH6(value)          (MATRIX_PSR14_WRUSERH6_Msk & ((value) << MATRIX_PSR14_WRUSERH6_Pos))
#define MATRIX_PSR14_WRUSERH7_Pos             _U_(23)                                              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR14_WRUSERH7_Msk             (_U_(0x1) << MATRIX_PSR14_WRUSERH7_Pos)              /**< (MATRIX_PSR14) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR14_WRUSERH7(value)          (MATRIX_PSR14_WRUSERH7_Msk & ((value) << MATRIX_PSR14_WRUSERH7_Pos))
#define MATRIX_PSR14_DPSOA0_Pos               _U_(24)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA0_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA0_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA0(value)            (MATRIX_PSR14_DPSOA0_Msk & ((value) << MATRIX_PSR14_DPSOA0_Pos))
#define MATRIX_PSR14_DPSOA1_Pos               _U_(25)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA1_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA1_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA1(value)            (MATRIX_PSR14_DPSOA1_Msk & ((value) << MATRIX_PSR14_DPSOA1_Pos))
#define MATRIX_PSR14_DPSOA2_Pos               _U_(26)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA2_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA2_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA2(value)            (MATRIX_PSR14_DPSOA2_Msk & ((value) << MATRIX_PSR14_DPSOA2_Pos))
#define MATRIX_PSR14_DPSOA3_Pos               _U_(27)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA3_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA3_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA3(value)            (MATRIX_PSR14_DPSOA3_Msk & ((value) << MATRIX_PSR14_DPSOA3_Pos))
#define MATRIX_PSR14_DPSOA4_Pos               _U_(28)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA4_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA4_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA4(value)            (MATRIX_PSR14_DPSOA4_Msk & ((value) << MATRIX_PSR14_DPSOA4_Pos))
#define MATRIX_PSR14_DPSOA5_Pos               _U_(29)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA5_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA5_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA5(value)            (MATRIX_PSR14_DPSOA5_Msk & ((value) << MATRIX_PSR14_DPSOA5_Pos))
#define MATRIX_PSR14_DPSOA6_Pos               _U_(30)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA6_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA6_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA6(value)            (MATRIX_PSR14_DPSOA6_Msk & ((value) << MATRIX_PSR14_DPSOA6_Pos))
#define MATRIX_PSR14_DPSOA7_Pos               _U_(31)                                              /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR14_DPSOA7_Msk               (_U_(0x1) << MATRIX_PSR14_DPSOA7_Pos)                /**< (MATRIX_PSR14) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR14_DPSOA7(value)            (MATRIX_PSR14_DPSOA7_Msk & ((value) << MATRIX_PSR14_DPSOA7_Pos))
#define MATRIX_PSR14_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR14) Register Mask  */

#define MATRIX_PSR14_LAUSERH_Pos              _U_(0)                                               /**< (MATRIX_PSR14 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR14_LAUSERH_Msk              (_U_(0xFF) << MATRIX_PSR14_LAUSERH_Pos)              /**< (MATRIX_PSR14 Mask) LAUSERH */
#define MATRIX_PSR14_LAUSERH(value)           (MATRIX_PSR14_LAUSERH_Msk & ((value) << MATRIX_PSR14_LAUSERH_Pos)) 
#define MATRIX_PSR14_RDUSERH_Pos              _U_(8)                                               /**< (MATRIX_PSR14 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR14_RDUSERH_Msk              (_U_(0xFF) << MATRIX_PSR14_RDUSERH_Pos)              /**< (MATRIX_PSR14 Mask) RDUSERH */
#define MATRIX_PSR14_RDUSERH(value)           (MATRIX_PSR14_RDUSERH_Msk & ((value) << MATRIX_PSR14_RDUSERH_Pos)) 
#define MATRIX_PSR14_WRUSERH_Pos              _U_(16)                                              /**< (MATRIX_PSR14 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR14_WRUSERH_Msk              (_U_(0xFF) << MATRIX_PSR14_WRUSERH_Pos)              /**< (MATRIX_PSR14 Mask) WRUSERH */
#define MATRIX_PSR14_WRUSERH(value)           (MATRIX_PSR14_WRUSERH_Msk & ((value) << MATRIX_PSR14_WRUSERH_Pos)) 
#define MATRIX_PSR14_DPSOA_Pos                _U_(24)                                              /**< (MATRIX_PSR14 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR14_DPSOA_Msk                (_U_(0xFF) << MATRIX_PSR14_DPSOA_Pos)                /**< (MATRIX_PSR14 Mask) DPSOA */
#define MATRIX_PSR14_DPSOA(value)             (MATRIX_PSR14_DPSOA_Msk & ((value) << MATRIX_PSR14_DPSOA_Pos)) 

/* -------- MATRIX_PSR15 : (MATRIX Offset: 0x23C) (R/W 32) Protection Slave 0 Register 15 -------- */
#define MATRIX_PSR15_LAUSERH0_Pos             _U_(0)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH0_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH0_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH0(value)          (MATRIX_PSR15_LAUSERH0_Msk & ((value) << MATRIX_PSR15_LAUSERH0_Pos))
#define MATRIX_PSR15_LAUSERH1_Pos             _U_(1)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH1_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH1_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH1(value)          (MATRIX_PSR15_LAUSERH1_Msk & ((value) << MATRIX_PSR15_LAUSERH1_Pos))
#define MATRIX_PSR15_LAUSERH2_Pos             _U_(2)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH2_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH2_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH2(value)          (MATRIX_PSR15_LAUSERH2_Msk & ((value) << MATRIX_PSR15_LAUSERH2_Pos))
#define MATRIX_PSR15_LAUSERH3_Pos             _U_(3)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH3_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH3_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH3(value)          (MATRIX_PSR15_LAUSERH3_Msk & ((value) << MATRIX_PSR15_LAUSERH3_Pos))
#define MATRIX_PSR15_LAUSERH4_Pos             _U_(4)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH4_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH4_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH4(value)          (MATRIX_PSR15_LAUSERH4_Msk & ((value) << MATRIX_PSR15_LAUSERH4_Pos))
#define MATRIX_PSR15_LAUSERH5_Pos             _U_(5)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH5_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH5_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH5(value)          (MATRIX_PSR15_LAUSERH5_Msk & ((value) << MATRIX_PSR15_LAUSERH5_Pos))
#define MATRIX_PSR15_LAUSERH6_Pos             _U_(6)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH6_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH6_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH6(value)          (MATRIX_PSR15_LAUSERH6_Msk & ((value) << MATRIX_PSR15_LAUSERH6_Pos))
#define MATRIX_PSR15_LAUSERH7_Pos             _U_(7)                                               /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Position */
#define MATRIX_PSR15_LAUSERH7_Msk             (_U_(0x1) << MATRIX_PSR15_LAUSERH7_Pos)              /**< (MATRIX_PSR15) Low Area USER in HSELx Protected Region Mask */
#define MATRIX_PSR15_LAUSERH7(value)          (MATRIX_PSR15_LAUSERH7_Msk & ((value) << MATRIX_PSR15_LAUSERH7_Pos))
#define MATRIX_PSR15_RDUSERH0_Pos             _U_(8)                                               /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH0_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH0_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH0(value)          (MATRIX_PSR15_RDUSERH0_Msk & ((value) << MATRIX_PSR15_RDUSERH0_Pos))
#define MATRIX_PSR15_RDUSERH1_Pos             _U_(9)                                               /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH1_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH1_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH1(value)          (MATRIX_PSR15_RDUSERH1_Msk & ((value) << MATRIX_PSR15_RDUSERH1_Pos))
#define MATRIX_PSR15_RDUSERH2_Pos             _U_(10)                                              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH2_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH2_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH2(value)          (MATRIX_PSR15_RDUSERH2_Msk & ((value) << MATRIX_PSR15_RDUSERH2_Pos))
#define MATRIX_PSR15_RDUSERH3_Pos             _U_(11)                                              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH3_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH3_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH3(value)          (MATRIX_PSR15_RDUSERH3_Msk & ((value) << MATRIX_PSR15_RDUSERH3_Pos))
#define MATRIX_PSR15_RDUSERH4_Pos             _U_(12)                                              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH4_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH4_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH4(value)          (MATRIX_PSR15_RDUSERH4_Msk & ((value) << MATRIX_PSR15_RDUSERH4_Pos))
#define MATRIX_PSR15_RDUSERH5_Pos             _U_(13)                                              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH5_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH5_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH5(value)          (MATRIX_PSR15_RDUSERH5_Msk & ((value) << MATRIX_PSR15_RDUSERH5_Pos))
#define MATRIX_PSR15_RDUSERH6_Pos             _U_(14)                                              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH6_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH6_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH6(value)          (MATRIX_PSR15_RDUSERH6_Msk & ((value) << MATRIX_PSR15_RDUSERH6_Pos))
#define MATRIX_PSR15_RDUSERH7_Pos             _U_(15)                                              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Position */
#define MATRIX_PSR15_RDUSERH7_Msk             (_U_(0x1) << MATRIX_PSR15_RDUSERH7_Pos)              /**< (MATRIX_PSR15) Read USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_RDUSERH7(value)          (MATRIX_PSR15_RDUSERH7_Msk & ((value) << MATRIX_PSR15_RDUSERH7_Pos))
#define MATRIX_PSR15_WRUSERH0_Pos             _U_(16)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH0_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH0_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH0(value)          (MATRIX_PSR15_WRUSERH0_Msk & ((value) << MATRIX_PSR15_WRUSERH0_Pos))
#define MATRIX_PSR15_WRUSERH1_Pos             _U_(17)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH1_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH1_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH1(value)          (MATRIX_PSR15_WRUSERH1_Msk & ((value) << MATRIX_PSR15_WRUSERH1_Pos))
#define MATRIX_PSR15_WRUSERH2_Pos             _U_(18)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH2_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH2_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH2(value)          (MATRIX_PSR15_WRUSERH2_Msk & ((value) << MATRIX_PSR15_WRUSERH2_Pos))
#define MATRIX_PSR15_WRUSERH3_Pos             _U_(19)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH3_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH3_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH3(value)          (MATRIX_PSR15_WRUSERH3_Msk & ((value) << MATRIX_PSR15_WRUSERH3_Pos))
#define MATRIX_PSR15_WRUSERH4_Pos             _U_(20)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH4_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH4_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH4(value)          (MATRIX_PSR15_WRUSERH4_Msk & ((value) << MATRIX_PSR15_WRUSERH4_Pos))
#define MATRIX_PSR15_WRUSERH5_Pos             _U_(21)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH5_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH5_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH5(value)          (MATRIX_PSR15_WRUSERH5_Msk & ((value) << MATRIX_PSR15_WRUSERH5_Pos))
#define MATRIX_PSR15_WRUSERH6_Pos             _U_(22)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH6_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH6_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH6(value)          (MATRIX_PSR15_WRUSERH6_Msk & ((value) << MATRIX_PSR15_WRUSERH6_Pos))
#define MATRIX_PSR15_WRUSERH7_Pos             _U_(23)                                              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Position */
#define MATRIX_PSR15_WRUSERH7_Msk             (_U_(0x1) << MATRIX_PSR15_WRUSERH7_Pos)              /**< (MATRIX_PSR15) Write USER for HSELx Protected Region Mask */
#define MATRIX_PSR15_WRUSERH7(value)          (MATRIX_PSR15_WRUSERH7_Msk & ((value) << MATRIX_PSR15_WRUSERH7_Pos))
#define MATRIX_PSR15_DPSOA0_Pos               _U_(24)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA0_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA0_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA0(value)            (MATRIX_PSR15_DPSOA0_Msk & ((value) << MATRIX_PSR15_DPSOA0_Pos))
#define MATRIX_PSR15_DPSOA1_Pos               _U_(25)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA1_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA1_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA1(value)            (MATRIX_PSR15_DPSOA1_Msk & ((value) << MATRIX_PSR15_DPSOA1_Pos))
#define MATRIX_PSR15_DPSOA2_Pos               _U_(26)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA2_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA2_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA2(value)            (MATRIX_PSR15_DPSOA2_Msk & ((value) << MATRIX_PSR15_DPSOA2_Pos))
#define MATRIX_PSR15_DPSOA3_Pos               _U_(27)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA3_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA3_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA3(value)            (MATRIX_PSR15_DPSOA3_Msk & ((value) << MATRIX_PSR15_DPSOA3_Pos))
#define MATRIX_PSR15_DPSOA4_Pos               _U_(28)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA4_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA4_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA4(value)            (MATRIX_PSR15_DPSOA4_Msk & ((value) << MATRIX_PSR15_DPSOA4_Pos))
#define MATRIX_PSR15_DPSOA5_Pos               _U_(29)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA5_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA5_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA5(value)            (MATRIX_PSR15_DPSOA5_Msk & ((value) << MATRIX_PSR15_DPSOA5_Pos))
#define MATRIX_PSR15_DPSOA6_Pos               _U_(30)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA6_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA6_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA6(value)            (MATRIX_PSR15_DPSOA6_Msk & ((value) << MATRIX_PSR15_DPSOA6_Pos))
#define MATRIX_PSR15_DPSOA7_Pos               _U_(31)                                              /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Position */
#define MATRIX_PSR15_DPSOA7_Msk               (_U_(0x1) << MATRIX_PSR15_DPSOA7_Pos)                /**< (MATRIX_PSR15) Downward Protection Split Address for HSELx Protected Region Mask */
#define MATRIX_PSR15_DPSOA7(value)            (MATRIX_PSR15_DPSOA7_Msk & ((value) << MATRIX_PSR15_DPSOA7_Pos))
#define MATRIX_PSR15_Msk                      _U_(0xFFFFFFFF)                                      /**< (MATRIX_PSR15) Register Mask  */

#define MATRIX_PSR15_LAUSERH_Pos              _U_(0)                                               /**< (MATRIX_PSR15 Position) Low Area USER in HSELx Protected Region */
#define MATRIX_PSR15_LAUSERH_Msk              (_U_(0xFF) << MATRIX_PSR15_LAUSERH_Pos)              /**< (MATRIX_PSR15 Mask) LAUSERH */
#define MATRIX_PSR15_LAUSERH(value)           (MATRIX_PSR15_LAUSERH_Msk & ((value) << MATRIX_PSR15_LAUSERH_Pos)) 
#define MATRIX_PSR15_RDUSERH_Pos              _U_(8)                                               /**< (MATRIX_PSR15 Position) Read USER for HSELx Protected Region */
#define MATRIX_PSR15_RDUSERH_Msk              (_U_(0xFF) << MATRIX_PSR15_RDUSERH_Pos)              /**< (MATRIX_PSR15 Mask) RDUSERH */
#define MATRIX_PSR15_RDUSERH(value)           (MATRIX_PSR15_RDUSERH_Msk & ((value) << MATRIX_PSR15_RDUSERH_Pos)) 
#define MATRIX_PSR15_WRUSERH_Pos              _U_(16)                                              /**< (MATRIX_PSR15 Position) Write USER for HSELx Protected Region */
#define MATRIX_PSR15_WRUSERH_Msk              (_U_(0xFF) << MATRIX_PSR15_WRUSERH_Pos)              /**< (MATRIX_PSR15 Mask) WRUSERH */
#define MATRIX_PSR15_WRUSERH(value)           (MATRIX_PSR15_WRUSERH_Msk & ((value) << MATRIX_PSR15_WRUSERH_Pos)) 
#define MATRIX_PSR15_DPSOA_Pos                _U_(24)                                              /**< (MATRIX_PSR15 Position) Downward Protection Split Address for HSELx Protected Region */
#define MATRIX_PSR15_DPSOA_Msk                (_U_(0xFF) << MATRIX_PSR15_DPSOA_Pos)                /**< (MATRIX_PSR15 Mask) DPSOA */
#define MATRIX_PSR15_DPSOA(value)             (MATRIX_PSR15_DPSOA_Msk & ((value) << MATRIX_PSR15_DPSOA_Pos)) 

/* -------- MATRIX_PASSR0 : (MATRIX Offset: 0x240) (R/W 32) Protected Areas Split Slave 0 Register 0 -------- */
#define MATRIX_PASSR0_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT0_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT0(value)         (MATRIX_PASSR0_PASPLIT0_Msk & ((value) << MATRIX_PASSR0_PASPLIT0_Pos))
#define MATRIX_PASSR0_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT1_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT1(value)         (MATRIX_PASSR0_PASPLIT1_Msk & ((value) << MATRIX_PASSR0_PASPLIT1_Pos))
#define MATRIX_PASSR0_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT2_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT2(value)         (MATRIX_PASSR0_PASPLIT2_Msk & ((value) << MATRIX_PASSR0_PASPLIT2_Pos))
#define MATRIX_PASSR0_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT3_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT3(value)         (MATRIX_PASSR0_PASPLIT3_Msk & ((value) << MATRIX_PASSR0_PASPLIT3_Pos))
#define MATRIX_PASSR0_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT4_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT4(value)         (MATRIX_PASSR0_PASPLIT4_Msk & ((value) << MATRIX_PASSR0_PASPLIT4_Pos))
#define MATRIX_PASSR0_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT5_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT5(value)         (MATRIX_PASSR0_PASPLIT5_Msk & ((value) << MATRIX_PASSR0_PASPLIT5_Pos))
#define MATRIX_PASSR0_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT6_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT6(value)         (MATRIX_PASSR0_PASPLIT6_Msk & ((value) << MATRIX_PASSR0_PASPLIT6_Pos))
#define MATRIX_PASSR0_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR0_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR0_PASPLIT7_Pos)             /**< (MATRIX_PASSR0) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR0_PASPLIT7(value)         (MATRIX_PASSR0_PASPLIT7_Msk & ((value) << MATRIX_PASSR0_PASPLIT7_Pos))
#define MATRIX_PASSR0_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR0) Register Mask  */


/* -------- MATRIX_PASSR1 : (MATRIX Offset: 0x244) (R/W 32) Protected Areas Split Slave 0 Register 1 -------- */
#define MATRIX_PASSR1_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT0_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT0(value)         (MATRIX_PASSR1_PASPLIT0_Msk & ((value) << MATRIX_PASSR1_PASPLIT0_Pos))
#define MATRIX_PASSR1_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT1_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT1(value)         (MATRIX_PASSR1_PASPLIT1_Msk & ((value) << MATRIX_PASSR1_PASPLIT1_Pos))
#define MATRIX_PASSR1_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT2_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT2(value)         (MATRIX_PASSR1_PASPLIT2_Msk & ((value) << MATRIX_PASSR1_PASPLIT2_Pos))
#define MATRIX_PASSR1_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT3_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT3(value)         (MATRIX_PASSR1_PASPLIT3_Msk & ((value) << MATRIX_PASSR1_PASPLIT3_Pos))
#define MATRIX_PASSR1_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT4_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT4(value)         (MATRIX_PASSR1_PASPLIT4_Msk & ((value) << MATRIX_PASSR1_PASPLIT4_Pos))
#define MATRIX_PASSR1_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT5_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT5(value)         (MATRIX_PASSR1_PASPLIT5_Msk & ((value) << MATRIX_PASSR1_PASPLIT5_Pos))
#define MATRIX_PASSR1_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT6_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT6(value)         (MATRIX_PASSR1_PASPLIT6_Msk & ((value) << MATRIX_PASSR1_PASPLIT6_Pos))
#define MATRIX_PASSR1_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR1_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR1_PASPLIT7_Pos)             /**< (MATRIX_PASSR1) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR1_PASPLIT7(value)         (MATRIX_PASSR1_PASPLIT7_Msk & ((value) << MATRIX_PASSR1_PASPLIT7_Pos))
#define MATRIX_PASSR1_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR1) Register Mask  */


/* -------- MATRIX_PASSR2 : (MATRIX Offset: 0x248) (R/W 32) Protected Areas Split Slave 0 Register 2 -------- */
#define MATRIX_PASSR2_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT0_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT0(value)         (MATRIX_PASSR2_PASPLIT0_Msk & ((value) << MATRIX_PASSR2_PASPLIT0_Pos))
#define MATRIX_PASSR2_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT1_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT1(value)         (MATRIX_PASSR2_PASPLIT1_Msk & ((value) << MATRIX_PASSR2_PASPLIT1_Pos))
#define MATRIX_PASSR2_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT2_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT2(value)         (MATRIX_PASSR2_PASPLIT2_Msk & ((value) << MATRIX_PASSR2_PASPLIT2_Pos))
#define MATRIX_PASSR2_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT3_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT3(value)         (MATRIX_PASSR2_PASPLIT3_Msk & ((value) << MATRIX_PASSR2_PASPLIT3_Pos))
#define MATRIX_PASSR2_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT4_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT4(value)         (MATRIX_PASSR2_PASPLIT4_Msk & ((value) << MATRIX_PASSR2_PASPLIT4_Pos))
#define MATRIX_PASSR2_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT5_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT5(value)         (MATRIX_PASSR2_PASPLIT5_Msk & ((value) << MATRIX_PASSR2_PASPLIT5_Pos))
#define MATRIX_PASSR2_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT6_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT6(value)         (MATRIX_PASSR2_PASPLIT6_Msk & ((value) << MATRIX_PASSR2_PASPLIT6_Pos))
#define MATRIX_PASSR2_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR2_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR2_PASPLIT7_Pos)             /**< (MATRIX_PASSR2) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR2_PASPLIT7(value)         (MATRIX_PASSR2_PASPLIT7_Msk & ((value) << MATRIX_PASSR2_PASPLIT7_Pos))
#define MATRIX_PASSR2_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR2) Register Mask  */


/* -------- MATRIX_PASSR3 : (MATRIX Offset: 0x24C) (R/W 32) Protected Areas Split Slave 0 Register 3 -------- */
#define MATRIX_PASSR3_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT0_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT0(value)         (MATRIX_PASSR3_PASPLIT0_Msk & ((value) << MATRIX_PASSR3_PASPLIT0_Pos))
#define MATRIX_PASSR3_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT1_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT1(value)         (MATRIX_PASSR3_PASPLIT1_Msk & ((value) << MATRIX_PASSR3_PASPLIT1_Pos))
#define MATRIX_PASSR3_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT2_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT2(value)         (MATRIX_PASSR3_PASPLIT2_Msk & ((value) << MATRIX_PASSR3_PASPLIT2_Pos))
#define MATRIX_PASSR3_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT3_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT3(value)         (MATRIX_PASSR3_PASPLIT3_Msk & ((value) << MATRIX_PASSR3_PASPLIT3_Pos))
#define MATRIX_PASSR3_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT4_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT4(value)         (MATRIX_PASSR3_PASPLIT4_Msk & ((value) << MATRIX_PASSR3_PASPLIT4_Pos))
#define MATRIX_PASSR3_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT5_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT5(value)         (MATRIX_PASSR3_PASPLIT5_Msk & ((value) << MATRIX_PASSR3_PASPLIT5_Pos))
#define MATRIX_PASSR3_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT6_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT6(value)         (MATRIX_PASSR3_PASPLIT6_Msk & ((value) << MATRIX_PASSR3_PASPLIT6_Pos))
#define MATRIX_PASSR3_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR3_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR3_PASPLIT7_Pos)             /**< (MATRIX_PASSR3) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR3_PASPLIT7(value)         (MATRIX_PASSR3_PASPLIT7_Msk & ((value) << MATRIX_PASSR3_PASPLIT7_Pos))
#define MATRIX_PASSR3_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR3) Register Mask  */


/* -------- MATRIX_PASSR4 : (MATRIX Offset: 0x250) (R/W 32) Protected Areas Split Slave 0 Register 4 -------- */
#define MATRIX_PASSR4_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT0_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT0(value)         (MATRIX_PASSR4_PASPLIT0_Msk & ((value) << MATRIX_PASSR4_PASPLIT0_Pos))
#define MATRIX_PASSR4_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT1_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT1(value)         (MATRIX_PASSR4_PASPLIT1_Msk & ((value) << MATRIX_PASSR4_PASPLIT1_Pos))
#define MATRIX_PASSR4_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT2_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT2(value)         (MATRIX_PASSR4_PASPLIT2_Msk & ((value) << MATRIX_PASSR4_PASPLIT2_Pos))
#define MATRIX_PASSR4_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT3_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT3(value)         (MATRIX_PASSR4_PASPLIT3_Msk & ((value) << MATRIX_PASSR4_PASPLIT3_Pos))
#define MATRIX_PASSR4_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT4_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT4(value)         (MATRIX_PASSR4_PASPLIT4_Msk & ((value) << MATRIX_PASSR4_PASPLIT4_Pos))
#define MATRIX_PASSR4_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT5_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT5(value)         (MATRIX_PASSR4_PASPLIT5_Msk & ((value) << MATRIX_PASSR4_PASPLIT5_Pos))
#define MATRIX_PASSR4_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT6_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT6(value)         (MATRIX_PASSR4_PASPLIT6_Msk & ((value) << MATRIX_PASSR4_PASPLIT6_Pos))
#define MATRIX_PASSR4_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR4_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR4_PASPLIT7_Pos)             /**< (MATRIX_PASSR4) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR4_PASPLIT7(value)         (MATRIX_PASSR4_PASPLIT7_Msk & ((value) << MATRIX_PASSR4_PASPLIT7_Pos))
#define MATRIX_PASSR4_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR4) Register Mask  */


/* -------- MATRIX_PASSR5 : (MATRIX Offset: 0x254) (R/W 32) Protected Areas Split Slave 0 Register 5 -------- */
#define MATRIX_PASSR5_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT0_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT0(value)         (MATRIX_PASSR5_PASPLIT0_Msk & ((value) << MATRIX_PASSR5_PASPLIT0_Pos))
#define MATRIX_PASSR5_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT1_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT1(value)         (MATRIX_PASSR5_PASPLIT1_Msk & ((value) << MATRIX_PASSR5_PASPLIT1_Pos))
#define MATRIX_PASSR5_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT2_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT2(value)         (MATRIX_PASSR5_PASPLIT2_Msk & ((value) << MATRIX_PASSR5_PASPLIT2_Pos))
#define MATRIX_PASSR5_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT3_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT3(value)         (MATRIX_PASSR5_PASPLIT3_Msk & ((value) << MATRIX_PASSR5_PASPLIT3_Pos))
#define MATRIX_PASSR5_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT4_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT4(value)         (MATRIX_PASSR5_PASPLIT4_Msk & ((value) << MATRIX_PASSR5_PASPLIT4_Pos))
#define MATRIX_PASSR5_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT5_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT5(value)         (MATRIX_PASSR5_PASPLIT5_Msk & ((value) << MATRIX_PASSR5_PASPLIT5_Pos))
#define MATRIX_PASSR5_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT6_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT6(value)         (MATRIX_PASSR5_PASPLIT6_Msk & ((value) << MATRIX_PASSR5_PASPLIT6_Pos))
#define MATRIX_PASSR5_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR5_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR5_PASPLIT7_Pos)             /**< (MATRIX_PASSR5) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR5_PASPLIT7(value)         (MATRIX_PASSR5_PASPLIT7_Msk & ((value) << MATRIX_PASSR5_PASPLIT7_Pos))
#define MATRIX_PASSR5_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR5) Register Mask  */


/* -------- MATRIX_PASSR6 : (MATRIX Offset: 0x258) (R/W 32) Protected Areas Split Slave 0 Register 6 -------- */
#define MATRIX_PASSR6_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT0_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT0(value)         (MATRIX_PASSR6_PASPLIT0_Msk & ((value) << MATRIX_PASSR6_PASPLIT0_Pos))
#define MATRIX_PASSR6_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT1_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT1(value)         (MATRIX_PASSR6_PASPLIT1_Msk & ((value) << MATRIX_PASSR6_PASPLIT1_Pos))
#define MATRIX_PASSR6_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT2_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT2(value)         (MATRIX_PASSR6_PASPLIT2_Msk & ((value) << MATRIX_PASSR6_PASPLIT2_Pos))
#define MATRIX_PASSR6_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT3_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT3(value)         (MATRIX_PASSR6_PASPLIT3_Msk & ((value) << MATRIX_PASSR6_PASPLIT3_Pos))
#define MATRIX_PASSR6_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT4_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT4(value)         (MATRIX_PASSR6_PASPLIT4_Msk & ((value) << MATRIX_PASSR6_PASPLIT4_Pos))
#define MATRIX_PASSR6_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT5_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT5(value)         (MATRIX_PASSR6_PASPLIT5_Msk & ((value) << MATRIX_PASSR6_PASPLIT5_Pos))
#define MATRIX_PASSR6_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT6_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT6(value)         (MATRIX_PASSR6_PASPLIT6_Msk & ((value) << MATRIX_PASSR6_PASPLIT6_Pos))
#define MATRIX_PASSR6_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR6_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR6_PASPLIT7_Pos)             /**< (MATRIX_PASSR6) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR6_PASPLIT7(value)         (MATRIX_PASSR6_PASPLIT7_Msk & ((value) << MATRIX_PASSR6_PASPLIT7_Pos))
#define MATRIX_PASSR6_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR6) Register Mask  */


/* -------- MATRIX_PASSR7 : (MATRIX Offset: 0x25C) (R/W 32) Protected Areas Split Slave 0 Register 7 -------- */
#define MATRIX_PASSR7_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT0_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT0(value)         (MATRIX_PASSR7_PASPLIT0_Msk & ((value) << MATRIX_PASSR7_PASPLIT0_Pos))
#define MATRIX_PASSR7_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT1_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT1(value)         (MATRIX_PASSR7_PASPLIT1_Msk & ((value) << MATRIX_PASSR7_PASPLIT1_Pos))
#define MATRIX_PASSR7_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT2_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT2(value)         (MATRIX_PASSR7_PASPLIT2_Msk & ((value) << MATRIX_PASSR7_PASPLIT2_Pos))
#define MATRIX_PASSR7_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT3_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT3(value)         (MATRIX_PASSR7_PASPLIT3_Msk & ((value) << MATRIX_PASSR7_PASPLIT3_Pos))
#define MATRIX_PASSR7_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT4_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT4(value)         (MATRIX_PASSR7_PASPLIT4_Msk & ((value) << MATRIX_PASSR7_PASPLIT4_Pos))
#define MATRIX_PASSR7_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT5_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT5(value)         (MATRIX_PASSR7_PASPLIT5_Msk & ((value) << MATRIX_PASSR7_PASPLIT5_Pos))
#define MATRIX_PASSR7_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT6_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT6(value)         (MATRIX_PASSR7_PASPLIT6_Msk & ((value) << MATRIX_PASSR7_PASPLIT6_Pos))
#define MATRIX_PASSR7_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR7_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR7_PASPLIT7_Pos)             /**< (MATRIX_PASSR7) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR7_PASPLIT7(value)         (MATRIX_PASSR7_PASPLIT7_Msk & ((value) << MATRIX_PASSR7_PASPLIT7_Pos))
#define MATRIX_PASSR7_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR7) Register Mask  */


/* -------- MATRIX_PASSR8 : (MATRIX Offset: 0x260) (R/W 32) Protected Areas Split Slave 0 Register 8 -------- */
#define MATRIX_PASSR8_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT0_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT0(value)         (MATRIX_PASSR8_PASPLIT0_Msk & ((value) << MATRIX_PASSR8_PASPLIT0_Pos))
#define MATRIX_PASSR8_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT1_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT1(value)         (MATRIX_PASSR8_PASPLIT1_Msk & ((value) << MATRIX_PASSR8_PASPLIT1_Pos))
#define MATRIX_PASSR8_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT2_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT2(value)         (MATRIX_PASSR8_PASPLIT2_Msk & ((value) << MATRIX_PASSR8_PASPLIT2_Pos))
#define MATRIX_PASSR8_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT3_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT3(value)         (MATRIX_PASSR8_PASPLIT3_Msk & ((value) << MATRIX_PASSR8_PASPLIT3_Pos))
#define MATRIX_PASSR8_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT4_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT4(value)         (MATRIX_PASSR8_PASPLIT4_Msk & ((value) << MATRIX_PASSR8_PASPLIT4_Pos))
#define MATRIX_PASSR8_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT5_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT5(value)         (MATRIX_PASSR8_PASPLIT5_Msk & ((value) << MATRIX_PASSR8_PASPLIT5_Pos))
#define MATRIX_PASSR8_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT6_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT6(value)         (MATRIX_PASSR8_PASPLIT6_Msk & ((value) << MATRIX_PASSR8_PASPLIT6_Pos))
#define MATRIX_PASSR8_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR8_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR8_PASPLIT7_Pos)             /**< (MATRIX_PASSR8) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR8_PASPLIT7(value)         (MATRIX_PASSR8_PASPLIT7_Msk & ((value) << MATRIX_PASSR8_PASPLIT7_Pos))
#define MATRIX_PASSR8_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR8) Register Mask  */


/* -------- MATRIX_PASSR9 : (MATRIX Offset: 0x264) (R/W 32) Protected Areas Split Slave 0 Register 9 -------- */
#define MATRIX_PASSR9_PASPLIT0_Pos            _U_(0)                                               /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT0_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT0_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT0(value)         (MATRIX_PASSR9_PASPLIT0_Msk & ((value) << MATRIX_PASSR9_PASPLIT0_Pos))
#define MATRIX_PASSR9_PASPLIT1_Pos            _U_(4)                                               /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT1_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT1_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT1(value)         (MATRIX_PASSR9_PASPLIT1_Msk & ((value) << MATRIX_PASSR9_PASPLIT1_Pos))
#define MATRIX_PASSR9_PASPLIT2_Pos            _U_(8)                                               /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT2_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT2_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT2(value)         (MATRIX_PASSR9_PASPLIT2_Msk & ((value) << MATRIX_PASSR9_PASPLIT2_Pos))
#define MATRIX_PASSR9_PASPLIT3_Pos            _U_(12)                                              /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT3_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT3_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT3(value)         (MATRIX_PASSR9_PASPLIT3_Msk & ((value) << MATRIX_PASSR9_PASPLIT3_Pos))
#define MATRIX_PASSR9_PASPLIT4_Pos            _U_(16)                                              /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT4_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT4_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT4(value)         (MATRIX_PASSR9_PASPLIT4_Msk & ((value) << MATRIX_PASSR9_PASPLIT4_Pos))
#define MATRIX_PASSR9_PASPLIT5_Pos            _U_(20)                                              /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT5_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT5_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT5(value)         (MATRIX_PASSR9_PASPLIT5_Msk & ((value) << MATRIX_PASSR9_PASPLIT5_Pos))
#define MATRIX_PASSR9_PASPLIT6_Pos            _U_(24)                                              /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT6_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT6_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT6(value)         (MATRIX_PASSR9_PASPLIT6_Msk & ((value) << MATRIX_PASSR9_PASPLIT6_Pos))
#define MATRIX_PASSR9_PASPLIT7_Pos            _U_(28)                                              /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR9_PASPLIT7_Msk            (_U_(0xF) << MATRIX_PASSR9_PASPLIT7_Pos)             /**< (MATRIX_PASSR9) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR9_PASPLIT7(value)         (MATRIX_PASSR9_PASPLIT7_Msk & ((value) << MATRIX_PASSR9_PASPLIT7_Pos))
#define MATRIX_PASSR9_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR9) Register Mask  */


/* -------- MATRIX_PASSR10 : (MATRIX Offset: 0x268) (R/W 32) Protected Areas Split Slave 0 Register 10 -------- */
#define MATRIX_PASSR10_PASPLIT0_Pos           _U_(0)                                               /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT0_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT0_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT0(value)        (MATRIX_PASSR10_PASPLIT0_Msk & ((value) << MATRIX_PASSR10_PASPLIT0_Pos))
#define MATRIX_PASSR10_PASPLIT1_Pos           _U_(4)                                               /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT1_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT1_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT1(value)        (MATRIX_PASSR10_PASPLIT1_Msk & ((value) << MATRIX_PASSR10_PASPLIT1_Pos))
#define MATRIX_PASSR10_PASPLIT2_Pos           _U_(8)                                               /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT2_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT2_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT2(value)        (MATRIX_PASSR10_PASPLIT2_Msk & ((value) << MATRIX_PASSR10_PASPLIT2_Pos))
#define MATRIX_PASSR10_PASPLIT3_Pos           _U_(12)                                              /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT3_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT3_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT3(value)        (MATRIX_PASSR10_PASPLIT3_Msk & ((value) << MATRIX_PASSR10_PASPLIT3_Pos))
#define MATRIX_PASSR10_PASPLIT4_Pos           _U_(16)                                              /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT4_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT4_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT4(value)        (MATRIX_PASSR10_PASPLIT4_Msk & ((value) << MATRIX_PASSR10_PASPLIT4_Pos))
#define MATRIX_PASSR10_PASPLIT5_Pos           _U_(20)                                              /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT5_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT5_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT5(value)        (MATRIX_PASSR10_PASPLIT5_Msk & ((value) << MATRIX_PASSR10_PASPLIT5_Pos))
#define MATRIX_PASSR10_PASPLIT6_Pos           _U_(24)                                              /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT6_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT6_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT6(value)        (MATRIX_PASSR10_PASPLIT6_Msk & ((value) << MATRIX_PASSR10_PASPLIT6_Pos))
#define MATRIX_PASSR10_PASPLIT7_Pos           _U_(28)                                              /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR10_PASPLIT7_Msk           (_U_(0xF) << MATRIX_PASSR10_PASPLIT7_Pos)            /**< (MATRIX_PASSR10) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR10_PASPLIT7(value)        (MATRIX_PASSR10_PASPLIT7_Msk & ((value) << MATRIX_PASSR10_PASPLIT7_Pos))
#define MATRIX_PASSR10_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR10) Register Mask  */


/* -------- MATRIX_PASSR11 : (MATRIX Offset: 0x26C) (R/W 32) Protected Areas Split Slave 0 Register 11 -------- */
#define MATRIX_PASSR11_PASPLIT0_Pos           _U_(0)                                               /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT0_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT0_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT0(value)        (MATRIX_PASSR11_PASPLIT0_Msk & ((value) << MATRIX_PASSR11_PASPLIT0_Pos))
#define MATRIX_PASSR11_PASPLIT1_Pos           _U_(4)                                               /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT1_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT1_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT1(value)        (MATRIX_PASSR11_PASPLIT1_Msk & ((value) << MATRIX_PASSR11_PASPLIT1_Pos))
#define MATRIX_PASSR11_PASPLIT2_Pos           _U_(8)                                               /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT2_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT2_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT2(value)        (MATRIX_PASSR11_PASPLIT2_Msk & ((value) << MATRIX_PASSR11_PASPLIT2_Pos))
#define MATRIX_PASSR11_PASPLIT3_Pos           _U_(12)                                              /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT3_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT3_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT3(value)        (MATRIX_PASSR11_PASPLIT3_Msk & ((value) << MATRIX_PASSR11_PASPLIT3_Pos))
#define MATRIX_PASSR11_PASPLIT4_Pos           _U_(16)                                              /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT4_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT4_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT4(value)        (MATRIX_PASSR11_PASPLIT4_Msk & ((value) << MATRIX_PASSR11_PASPLIT4_Pos))
#define MATRIX_PASSR11_PASPLIT5_Pos           _U_(20)                                              /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT5_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT5_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT5(value)        (MATRIX_PASSR11_PASPLIT5_Msk & ((value) << MATRIX_PASSR11_PASPLIT5_Pos))
#define MATRIX_PASSR11_PASPLIT6_Pos           _U_(24)                                              /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT6_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT6_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT6(value)        (MATRIX_PASSR11_PASPLIT6_Msk & ((value) << MATRIX_PASSR11_PASPLIT6_Pos))
#define MATRIX_PASSR11_PASPLIT7_Pos           _U_(28)                                              /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR11_PASPLIT7_Msk           (_U_(0xF) << MATRIX_PASSR11_PASPLIT7_Pos)            /**< (MATRIX_PASSR11) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR11_PASPLIT7(value)        (MATRIX_PASSR11_PASPLIT7_Msk & ((value) << MATRIX_PASSR11_PASPLIT7_Pos))
#define MATRIX_PASSR11_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR11) Register Mask  */


/* -------- MATRIX_PASSR12 : (MATRIX Offset: 0x270) (R/W 32) Protected Areas Split Slave 0 Register 12 -------- */
#define MATRIX_PASSR12_PASPLIT0_Pos           _U_(0)                                               /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT0_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT0_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT0(value)        (MATRIX_PASSR12_PASPLIT0_Msk & ((value) << MATRIX_PASSR12_PASPLIT0_Pos))
#define MATRIX_PASSR12_PASPLIT1_Pos           _U_(4)                                               /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT1_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT1_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT1(value)        (MATRIX_PASSR12_PASPLIT1_Msk & ((value) << MATRIX_PASSR12_PASPLIT1_Pos))
#define MATRIX_PASSR12_PASPLIT2_Pos           _U_(8)                                               /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT2_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT2_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT2(value)        (MATRIX_PASSR12_PASPLIT2_Msk & ((value) << MATRIX_PASSR12_PASPLIT2_Pos))
#define MATRIX_PASSR12_PASPLIT3_Pos           _U_(12)                                              /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT3_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT3_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT3(value)        (MATRIX_PASSR12_PASPLIT3_Msk & ((value) << MATRIX_PASSR12_PASPLIT3_Pos))
#define MATRIX_PASSR12_PASPLIT4_Pos           _U_(16)                                              /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT4_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT4_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT4(value)        (MATRIX_PASSR12_PASPLIT4_Msk & ((value) << MATRIX_PASSR12_PASPLIT4_Pos))
#define MATRIX_PASSR12_PASPLIT5_Pos           _U_(20)                                              /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT5_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT5_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT5(value)        (MATRIX_PASSR12_PASPLIT5_Msk & ((value) << MATRIX_PASSR12_PASPLIT5_Pos))
#define MATRIX_PASSR12_PASPLIT6_Pos           _U_(24)                                              /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT6_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT6_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT6(value)        (MATRIX_PASSR12_PASPLIT6_Msk & ((value) << MATRIX_PASSR12_PASPLIT6_Pos))
#define MATRIX_PASSR12_PASPLIT7_Pos           _U_(28)                                              /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR12_PASPLIT7_Msk           (_U_(0xF) << MATRIX_PASSR12_PASPLIT7_Pos)            /**< (MATRIX_PASSR12) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR12_PASPLIT7(value)        (MATRIX_PASSR12_PASPLIT7_Msk & ((value) << MATRIX_PASSR12_PASPLIT7_Pos))
#define MATRIX_PASSR12_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR12) Register Mask  */


/* -------- MATRIX_PASSR13 : (MATRIX Offset: 0x274) (R/W 32) Protected Areas Split Slave 0 Register 13 -------- */
#define MATRIX_PASSR13_PASPLIT0_Pos           _U_(0)                                               /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT0_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT0_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT0(value)        (MATRIX_PASSR13_PASPLIT0_Msk & ((value) << MATRIX_PASSR13_PASPLIT0_Pos))
#define MATRIX_PASSR13_PASPLIT1_Pos           _U_(4)                                               /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT1_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT1_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT1(value)        (MATRIX_PASSR13_PASPLIT1_Msk & ((value) << MATRIX_PASSR13_PASPLIT1_Pos))
#define MATRIX_PASSR13_PASPLIT2_Pos           _U_(8)                                               /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT2_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT2_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT2(value)        (MATRIX_PASSR13_PASPLIT2_Msk & ((value) << MATRIX_PASSR13_PASPLIT2_Pos))
#define MATRIX_PASSR13_PASPLIT3_Pos           _U_(12)                                              /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT3_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT3_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT3(value)        (MATRIX_PASSR13_PASPLIT3_Msk & ((value) << MATRIX_PASSR13_PASPLIT3_Pos))
#define MATRIX_PASSR13_PASPLIT4_Pos           _U_(16)                                              /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT4_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT4_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT4(value)        (MATRIX_PASSR13_PASPLIT4_Msk & ((value) << MATRIX_PASSR13_PASPLIT4_Pos))
#define MATRIX_PASSR13_PASPLIT5_Pos           _U_(20)                                              /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT5_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT5_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT5(value)        (MATRIX_PASSR13_PASPLIT5_Msk & ((value) << MATRIX_PASSR13_PASPLIT5_Pos))
#define MATRIX_PASSR13_PASPLIT6_Pos           _U_(24)                                              /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT6_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT6_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT6(value)        (MATRIX_PASSR13_PASPLIT6_Msk & ((value) << MATRIX_PASSR13_PASPLIT6_Pos))
#define MATRIX_PASSR13_PASPLIT7_Pos           _U_(28)                                              /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR13_PASPLIT7_Msk           (_U_(0xF) << MATRIX_PASSR13_PASPLIT7_Pos)            /**< (MATRIX_PASSR13) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR13_PASPLIT7(value)        (MATRIX_PASSR13_PASPLIT7_Msk & ((value) << MATRIX_PASSR13_PASPLIT7_Pos))
#define MATRIX_PASSR13_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR13) Register Mask  */


/* -------- MATRIX_PASSR14 : (MATRIX Offset: 0x278) (R/W 32) Protected Areas Split Slave 0 Register 14 -------- */
#define MATRIX_PASSR14_PASPLIT0_Pos           _U_(0)                                               /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT0_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT0_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT0(value)        (MATRIX_PASSR14_PASPLIT0_Msk & ((value) << MATRIX_PASSR14_PASPLIT0_Pos))
#define MATRIX_PASSR14_PASPLIT1_Pos           _U_(4)                                               /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT1_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT1_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT1(value)        (MATRIX_PASSR14_PASPLIT1_Msk & ((value) << MATRIX_PASSR14_PASPLIT1_Pos))
#define MATRIX_PASSR14_PASPLIT2_Pos           _U_(8)                                               /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT2_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT2_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT2(value)        (MATRIX_PASSR14_PASPLIT2_Msk & ((value) << MATRIX_PASSR14_PASPLIT2_Pos))
#define MATRIX_PASSR14_PASPLIT3_Pos           _U_(12)                                              /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT3_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT3_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT3(value)        (MATRIX_PASSR14_PASPLIT3_Msk & ((value) << MATRIX_PASSR14_PASPLIT3_Pos))
#define MATRIX_PASSR14_PASPLIT4_Pos           _U_(16)                                              /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT4_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT4_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT4(value)        (MATRIX_PASSR14_PASPLIT4_Msk & ((value) << MATRIX_PASSR14_PASPLIT4_Pos))
#define MATRIX_PASSR14_PASPLIT5_Pos           _U_(20)                                              /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT5_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT5_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT5(value)        (MATRIX_PASSR14_PASPLIT5_Msk & ((value) << MATRIX_PASSR14_PASPLIT5_Pos))
#define MATRIX_PASSR14_PASPLIT6_Pos           _U_(24)                                              /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT6_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT6_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT6(value)        (MATRIX_PASSR14_PASPLIT6_Msk & ((value) << MATRIX_PASSR14_PASPLIT6_Pos))
#define MATRIX_PASSR14_PASPLIT7_Pos           _U_(28)                                              /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR14_PASPLIT7_Msk           (_U_(0xF) << MATRIX_PASSR14_PASPLIT7_Pos)            /**< (MATRIX_PASSR14) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR14_PASPLIT7(value)        (MATRIX_PASSR14_PASPLIT7_Msk & ((value) << MATRIX_PASSR14_PASPLIT7_Pos))
#define MATRIX_PASSR14_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR14) Register Mask  */


/* -------- MATRIX_PASSR15 : (MATRIX Offset: 0x27C) (R/W 32) Protected Areas Split Slave 0 Register 15 -------- */
#define MATRIX_PASSR15_PASPLIT0_Pos           _U_(0)                                               /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT0_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT0_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT0(value)        (MATRIX_PASSR15_PASPLIT0_Msk & ((value) << MATRIX_PASSR15_PASPLIT0_Pos))
#define MATRIX_PASSR15_PASPLIT1_Pos           _U_(4)                                               /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT1_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT1_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT1(value)        (MATRIX_PASSR15_PASPLIT1_Msk & ((value) << MATRIX_PASSR15_PASPLIT1_Pos))
#define MATRIX_PASSR15_PASPLIT2_Pos           _U_(8)                                               /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT2_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT2_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT2(value)        (MATRIX_PASSR15_PASPLIT2_Msk & ((value) << MATRIX_PASSR15_PASPLIT2_Pos))
#define MATRIX_PASSR15_PASPLIT3_Pos           _U_(12)                                              /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT3_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT3_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT3(value)        (MATRIX_PASSR15_PASPLIT3_Msk & ((value) << MATRIX_PASSR15_PASPLIT3_Pos))
#define MATRIX_PASSR15_PASPLIT4_Pos           _U_(16)                                              /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT4_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT4_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT4(value)        (MATRIX_PASSR15_PASPLIT4_Msk & ((value) << MATRIX_PASSR15_PASPLIT4_Pos))
#define MATRIX_PASSR15_PASPLIT5_Pos           _U_(20)                                              /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT5_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT5_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT5(value)        (MATRIX_PASSR15_PASPLIT5_Msk & ((value) << MATRIX_PASSR15_PASPLIT5_Pos))
#define MATRIX_PASSR15_PASPLIT6_Pos           _U_(24)                                              /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT6_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT6_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT6(value)        (MATRIX_PASSR15_PASPLIT6_Msk & ((value) << MATRIX_PASSR15_PASPLIT6_Pos))
#define MATRIX_PASSR15_PASPLIT7_Pos           _U_(28)                                              /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Position */
#define MATRIX_PASSR15_PASPLIT7_Msk           (_U_(0xF) << MATRIX_PASSR15_PASPLIT7_Pos)            /**< (MATRIX_PASSR15) Protected Areas Split for HSELx Protected Region Mask */
#define MATRIX_PASSR15_PASPLIT7(value)        (MATRIX_PASSR15_PASPLIT7_Msk & ((value) << MATRIX_PASSR15_PASPLIT7_Pos))
#define MATRIX_PASSR15_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PASSR15) Register Mask  */


/* -------- MATRIX_PRTSR0 : (MATRIX Offset: 0x280) (R/W 32) Protected Region Top Slave 0 Register 0 -------- */
#define MATRIX_PRTSR0_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP0_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP0(value)           (MATRIX_PRTSR0_PRTOP0_Msk & ((value) << MATRIX_PRTSR0_PRTOP0_Pos))
#define MATRIX_PRTSR0_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP1_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP1(value)           (MATRIX_PRTSR0_PRTOP1_Msk & ((value) << MATRIX_PRTSR0_PRTOP1_Pos))
#define MATRIX_PRTSR0_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP2_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP2(value)           (MATRIX_PRTSR0_PRTOP2_Msk & ((value) << MATRIX_PRTSR0_PRTOP2_Pos))
#define MATRIX_PRTSR0_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP3_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP3(value)           (MATRIX_PRTSR0_PRTOP3_Msk & ((value) << MATRIX_PRTSR0_PRTOP3_Pos))
#define MATRIX_PRTSR0_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP4_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP4(value)           (MATRIX_PRTSR0_PRTOP4_Msk & ((value) << MATRIX_PRTSR0_PRTOP4_Pos))
#define MATRIX_PRTSR0_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP5_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP5(value)           (MATRIX_PRTSR0_PRTOP5_Msk & ((value) << MATRIX_PRTSR0_PRTOP5_Pos))
#define MATRIX_PRTSR0_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP6_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP6(value)           (MATRIX_PRTSR0_PRTOP6_Msk & ((value) << MATRIX_PRTSR0_PRTOP6_Pos))
#define MATRIX_PRTSR0_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR0) HSELx Protected Region Top Position */
#define MATRIX_PRTSR0_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR0_PRTOP7_Pos)               /**< (MATRIX_PRTSR0) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR0_PRTOP7(value)           (MATRIX_PRTSR0_PRTOP7_Msk & ((value) << MATRIX_PRTSR0_PRTOP7_Pos))
#define MATRIX_PRTSR0_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR0) Register Mask  */


/* -------- MATRIX_PRTSR1 : (MATRIX Offset: 0x284) (R/W 32) Protected Region Top Slave 0 Register 1 -------- */
#define MATRIX_PRTSR1_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP0_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP0(value)           (MATRIX_PRTSR1_PRTOP0_Msk & ((value) << MATRIX_PRTSR1_PRTOP0_Pos))
#define MATRIX_PRTSR1_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP1_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP1(value)           (MATRIX_PRTSR1_PRTOP1_Msk & ((value) << MATRIX_PRTSR1_PRTOP1_Pos))
#define MATRIX_PRTSR1_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP2_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP2(value)           (MATRIX_PRTSR1_PRTOP2_Msk & ((value) << MATRIX_PRTSR1_PRTOP2_Pos))
#define MATRIX_PRTSR1_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP3_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP3(value)           (MATRIX_PRTSR1_PRTOP3_Msk & ((value) << MATRIX_PRTSR1_PRTOP3_Pos))
#define MATRIX_PRTSR1_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP4_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP4(value)           (MATRIX_PRTSR1_PRTOP4_Msk & ((value) << MATRIX_PRTSR1_PRTOP4_Pos))
#define MATRIX_PRTSR1_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP5_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP5(value)           (MATRIX_PRTSR1_PRTOP5_Msk & ((value) << MATRIX_PRTSR1_PRTOP5_Pos))
#define MATRIX_PRTSR1_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP6_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP6(value)           (MATRIX_PRTSR1_PRTOP6_Msk & ((value) << MATRIX_PRTSR1_PRTOP6_Pos))
#define MATRIX_PRTSR1_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR1) HSELx Protected Region Top Position */
#define MATRIX_PRTSR1_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR1_PRTOP7_Pos)               /**< (MATRIX_PRTSR1) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR1_PRTOP7(value)           (MATRIX_PRTSR1_PRTOP7_Msk & ((value) << MATRIX_PRTSR1_PRTOP7_Pos))
#define MATRIX_PRTSR1_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR1) Register Mask  */


/* -------- MATRIX_PRTSR2 : (MATRIX Offset: 0x288) (R/W 32) Protected Region Top Slave 0 Register 2 -------- */
#define MATRIX_PRTSR2_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP0_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP0(value)           (MATRIX_PRTSR2_PRTOP0_Msk & ((value) << MATRIX_PRTSR2_PRTOP0_Pos))
#define MATRIX_PRTSR2_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP1_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP1(value)           (MATRIX_PRTSR2_PRTOP1_Msk & ((value) << MATRIX_PRTSR2_PRTOP1_Pos))
#define MATRIX_PRTSR2_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP2_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP2(value)           (MATRIX_PRTSR2_PRTOP2_Msk & ((value) << MATRIX_PRTSR2_PRTOP2_Pos))
#define MATRIX_PRTSR2_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP3_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP3(value)           (MATRIX_PRTSR2_PRTOP3_Msk & ((value) << MATRIX_PRTSR2_PRTOP3_Pos))
#define MATRIX_PRTSR2_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP4_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP4(value)           (MATRIX_PRTSR2_PRTOP4_Msk & ((value) << MATRIX_PRTSR2_PRTOP4_Pos))
#define MATRIX_PRTSR2_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP5_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP5(value)           (MATRIX_PRTSR2_PRTOP5_Msk & ((value) << MATRIX_PRTSR2_PRTOP5_Pos))
#define MATRIX_PRTSR2_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP6_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP6(value)           (MATRIX_PRTSR2_PRTOP6_Msk & ((value) << MATRIX_PRTSR2_PRTOP6_Pos))
#define MATRIX_PRTSR2_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR2) HSELx Protected Region Top Position */
#define MATRIX_PRTSR2_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR2_PRTOP7_Pos)               /**< (MATRIX_PRTSR2) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR2_PRTOP7(value)           (MATRIX_PRTSR2_PRTOP7_Msk & ((value) << MATRIX_PRTSR2_PRTOP7_Pos))
#define MATRIX_PRTSR2_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR2) Register Mask  */


/* -------- MATRIX_PRTSR3 : (MATRIX Offset: 0x28C) (R/W 32) Protected Region Top Slave 0 Register 3 -------- */
#define MATRIX_PRTSR3_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP0_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP0(value)           (MATRIX_PRTSR3_PRTOP0_Msk & ((value) << MATRIX_PRTSR3_PRTOP0_Pos))
#define MATRIX_PRTSR3_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP1_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP1(value)           (MATRIX_PRTSR3_PRTOP1_Msk & ((value) << MATRIX_PRTSR3_PRTOP1_Pos))
#define MATRIX_PRTSR3_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP2_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP2(value)           (MATRIX_PRTSR3_PRTOP2_Msk & ((value) << MATRIX_PRTSR3_PRTOP2_Pos))
#define MATRIX_PRTSR3_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP3_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP3(value)           (MATRIX_PRTSR3_PRTOP3_Msk & ((value) << MATRIX_PRTSR3_PRTOP3_Pos))
#define MATRIX_PRTSR3_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP4_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP4(value)           (MATRIX_PRTSR3_PRTOP4_Msk & ((value) << MATRIX_PRTSR3_PRTOP4_Pos))
#define MATRIX_PRTSR3_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP5_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP5(value)           (MATRIX_PRTSR3_PRTOP5_Msk & ((value) << MATRIX_PRTSR3_PRTOP5_Pos))
#define MATRIX_PRTSR3_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP6_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP6(value)           (MATRIX_PRTSR3_PRTOP6_Msk & ((value) << MATRIX_PRTSR3_PRTOP6_Pos))
#define MATRIX_PRTSR3_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR3) HSELx Protected Region Top Position */
#define MATRIX_PRTSR3_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR3_PRTOP7_Pos)               /**< (MATRIX_PRTSR3) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR3_PRTOP7(value)           (MATRIX_PRTSR3_PRTOP7_Msk & ((value) << MATRIX_PRTSR3_PRTOP7_Pos))
#define MATRIX_PRTSR3_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR3) Register Mask  */


/* -------- MATRIX_PRTSR4 : (MATRIX Offset: 0x290) (R/W 32) Protected Region Top Slave 0 Register 4 -------- */
#define MATRIX_PRTSR4_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP0_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP0(value)           (MATRIX_PRTSR4_PRTOP0_Msk & ((value) << MATRIX_PRTSR4_PRTOP0_Pos))
#define MATRIX_PRTSR4_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP1_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP1(value)           (MATRIX_PRTSR4_PRTOP1_Msk & ((value) << MATRIX_PRTSR4_PRTOP1_Pos))
#define MATRIX_PRTSR4_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP2_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP2(value)           (MATRIX_PRTSR4_PRTOP2_Msk & ((value) << MATRIX_PRTSR4_PRTOP2_Pos))
#define MATRIX_PRTSR4_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP3_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP3(value)           (MATRIX_PRTSR4_PRTOP3_Msk & ((value) << MATRIX_PRTSR4_PRTOP3_Pos))
#define MATRIX_PRTSR4_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP4_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP4(value)           (MATRIX_PRTSR4_PRTOP4_Msk & ((value) << MATRIX_PRTSR4_PRTOP4_Pos))
#define MATRIX_PRTSR4_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP5_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP5(value)           (MATRIX_PRTSR4_PRTOP5_Msk & ((value) << MATRIX_PRTSR4_PRTOP5_Pos))
#define MATRIX_PRTSR4_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP6_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP6(value)           (MATRIX_PRTSR4_PRTOP6_Msk & ((value) << MATRIX_PRTSR4_PRTOP6_Pos))
#define MATRIX_PRTSR4_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR4) HSELx Protected Region Top Position */
#define MATRIX_PRTSR4_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR4_PRTOP7_Pos)               /**< (MATRIX_PRTSR4) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR4_PRTOP7(value)           (MATRIX_PRTSR4_PRTOP7_Msk & ((value) << MATRIX_PRTSR4_PRTOP7_Pos))
#define MATRIX_PRTSR4_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR4) Register Mask  */


/* -------- MATRIX_PRTSR5 : (MATRIX Offset: 0x294) (R/W 32) Protected Region Top Slave 0 Register 5 -------- */
#define MATRIX_PRTSR5_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP0_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP0(value)           (MATRIX_PRTSR5_PRTOP0_Msk & ((value) << MATRIX_PRTSR5_PRTOP0_Pos))
#define MATRIX_PRTSR5_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP1_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP1(value)           (MATRIX_PRTSR5_PRTOP1_Msk & ((value) << MATRIX_PRTSR5_PRTOP1_Pos))
#define MATRIX_PRTSR5_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP2_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP2(value)           (MATRIX_PRTSR5_PRTOP2_Msk & ((value) << MATRIX_PRTSR5_PRTOP2_Pos))
#define MATRIX_PRTSR5_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP3_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP3(value)           (MATRIX_PRTSR5_PRTOP3_Msk & ((value) << MATRIX_PRTSR5_PRTOP3_Pos))
#define MATRIX_PRTSR5_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP4_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP4(value)           (MATRIX_PRTSR5_PRTOP4_Msk & ((value) << MATRIX_PRTSR5_PRTOP4_Pos))
#define MATRIX_PRTSR5_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP5_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP5(value)           (MATRIX_PRTSR5_PRTOP5_Msk & ((value) << MATRIX_PRTSR5_PRTOP5_Pos))
#define MATRIX_PRTSR5_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP6_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP6(value)           (MATRIX_PRTSR5_PRTOP6_Msk & ((value) << MATRIX_PRTSR5_PRTOP6_Pos))
#define MATRIX_PRTSR5_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR5) HSELx Protected Region Top Position */
#define MATRIX_PRTSR5_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR5_PRTOP7_Pos)               /**< (MATRIX_PRTSR5) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR5_PRTOP7(value)           (MATRIX_PRTSR5_PRTOP7_Msk & ((value) << MATRIX_PRTSR5_PRTOP7_Pos))
#define MATRIX_PRTSR5_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR5) Register Mask  */


/* -------- MATRIX_PRTSR6 : (MATRIX Offset: 0x298) (R/W 32) Protected Region Top Slave 0 Register 6 -------- */
#define MATRIX_PRTSR6_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP0_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP0(value)           (MATRIX_PRTSR6_PRTOP0_Msk & ((value) << MATRIX_PRTSR6_PRTOP0_Pos))
#define MATRIX_PRTSR6_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP1_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP1(value)           (MATRIX_PRTSR6_PRTOP1_Msk & ((value) << MATRIX_PRTSR6_PRTOP1_Pos))
#define MATRIX_PRTSR6_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP2_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP2(value)           (MATRIX_PRTSR6_PRTOP2_Msk & ((value) << MATRIX_PRTSR6_PRTOP2_Pos))
#define MATRIX_PRTSR6_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP3_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP3(value)           (MATRIX_PRTSR6_PRTOP3_Msk & ((value) << MATRIX_PRTSR6_PRTOP3_Pos))
#define MATRIX_PRTSR6_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP4_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP4(value)           (MATRIX_PRTSR6_PRTOP4_Msk & ((value) << MATRIX_PRTSR6_PRTOP4_Pos))
#define MATRIX_PRTSR6_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP5_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP5(value)           (MATRIX_PRTSR6_PRTOP5_Msk & ((value) << MATRIX_PRTSR6_PRTOP5_Pos))
#define MATRIX_PRTSR6_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP6_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP6(value)           (MATRIX_PRTSR6_PRTOP6_Msk & ((value) << MATRIX_PRTSR6_PRTOP6_Pos))
#define MATRIX_PRTSR6_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR6) HSELx Protected Region Top Position */
#define MATRIX_PRTSR6_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR6_PRTOP7_Pos)               /**< (MATRIX_PRTSR6) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR6_PRTOP7(value)           (MATRIX_PRTSR6_PRTOP7_Msk & ((value) << MATRIX_PRTSR6_PRTOP7_Pos))
#define MATRIX_PRTSR6_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR6) Register Mask  */


/* -------- MATRIX_PRTSR7 : (MATRIX Offset: 0x29C) (R/W 32) Protected Region Top Slave 0 Register 7 -------- */
#define MATRIX_PRTSR7_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP0_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP0(value)           (MATRIX_PRTSR7_PRTOP0_Msk & ((value) << MATRIX_PRTSR7_PRTOP0_Pos))
#define MATRIX_PRTSR7_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP1_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP1(value)           (MATRIX_PRTSR7_PRTOP1_Msk & ((value) << MATRIX_PRTSR7_PRTOP1_Pos))
#define MATRIX_PRTSR7_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP2_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP2(value)           (MATRIX_PRTSR7_PRTOP2_Msk & ((value) << MATRIX_PRTSR7_PRTOP2_Pos))
#define MATRIX_PRTSR7_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP3_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP3(value)           (MATRIX_PRTSR7_PRTOP3_Msk & ((value) << MATRIX_PRTSR7_PRTOP3_Pos))
#define MATRIX_PRTSR7_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP4_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP4(value)           (MATRIX_PRTSR7_PRTOP4_Msk & ((value) << MATRIX_PRTSR7_PRTOP4_Pos))
#define MATRIX_PRTSR7_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP5_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP5(value)           (MATRIX_PRTSR7_PRTOP5_Msk & ((value) << MATRIX_PRTSR7_PRTOP5_Pos))
#define MATRIX_PRTSR7_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP6_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP6(value)           (MATRIX_PRTSR7_PRTOP6_Msk & ((value) << MATRIX_PRTSR7_PRTOP6_Pos))
#define MATRIX_PRTSR7_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR7) HSELx Protected Region Top Position */
#define MATRIX_PRTSR7_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR7_PRTOP7_Pos)               /**< (MATRIX_PRTSR7) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR7_PRTOP7(value)           (MATRIX_PRTSR7_PRTOP7_Msk & ((value) << MATRIX_PRTSR7_PRTOP7_Pos))
#define MATRIX_PRTSR7_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR7) Register Mask  */


/* -------- MATRIX_PRTSR8 : (MATRIX Offset: 0x2A0) (R/W 32) Protected Region Top Slave 0 Register 8 -------- */
#define MATRIX_PRTSR8_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP0_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP0(value)           (MATRIX_PRTSR8_PRTOP0_Msk & ((value) << MATRIX_PRTSR8_PRTOP0_Pos))
#define MATRIX_PRTSR8_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP1_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP1(value)           (MATRIX_PRTSR8_PRTOP1_Msk & ((value) << MATRIX_PRTSR8_PRTOP1_Pos))
#define MATRIX_PRTSR8_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP2_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP2(value)           (MATRIX_PRTSR8_PRTOP2_Msk & ((value) << MATRIX_PRTSR8_PRTOP2_Pos))
#define MATRIX_PRTSR8_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP3_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP3(value)           (MATRIX_PRTSR8_PRTOP3_Msk & ((value) << MATRIX_PRTSR8_PRTOP3_Pos))
#define MATRIX_PRTSR8_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP4_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP4(value)           (MATRIX_PRTSR8_PRTOP4_Msk & ((value) << MATRIX_PRTSR8_PRTOP4_Pos))
#define MATRIX_PRTSR8_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP5_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP5(value)           (MATRIX_PRTSR8_PRTOP5_Msk & ((value) << MATRIX_PRTSR8_PRTOP5_Pos))
#define MATRIX_PRTSR8_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP6_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP6(value)           (MATRIX_PRTSR8_PRTOP6_Msk & ((value) << MATRIX_PRTSR8_PRTOP6_Pos))
#define MATRIX_PRTSR8_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR8) HSELx Protected Region Top Position */
#define MATRIX_PRTSR8_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR8_PRTOP7_Pos)               /**< (MATRIX_PRTSR8) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR8_PRTOP7(value)           (MATRIX_PRTSR8_PRTOP7_Msk & ((value) << MATRIX_PRTSR8_PRTOP7_Pos))
#define MATRIX_PRTSR8_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR8) Register Mask  */


/* -------- MATRIX_PRTSR9 : (MATRIX Offset: 0x2A4) (R/W 32) Protected Region Top Slave 0 Register 9 -------- */
#define MATRIX_PRTSR9_PRTOP0_Pos              _U_(0)                                               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP0_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP0_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP0(value)           (MATRIX_PRTSR9_PRTOP0_Msk & ((value) << MATRIX_PRTSR9_PRTOP0_Pos))
#define MATRIX_PRTSR9_PRTOP1_Pos              _U_(4)                                               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP1_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP1_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP1(value)           (MATRIX_PRTSR9_PRTOP1_Msk & ((value) << MATRIX_PRTSR9_PRTOP1_Pos))
#define MATRIX_PRTSR9_PRTOP2_Pos              _U_(8)                                               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP2_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP2_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP2(value)           (MATRIX_PRTSR9_PRTOP2_Msk & ((value) << MATRIX_PRTSR9_PRTOP2_Pos))
#define MATRIX_PRTSR9_PRTOP3_Pos              _U_(12)                                              /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP3_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP3_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP3(value)           (MATRIX_PRTSR9_PRTOP3_Msk & ((value) << MATRIX_PRTSR9_PRTOP3_Pos))
#define MATRIX_PRTSR9_PRTOP4_Pos              _U_(16)                                              /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP4_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP4_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP4(value)           (MATRIX_PRTSR9_PRTOP4_Msk & ((value) << MATRIX_PRTSR9_PRTOP4_Pos))
#define MATRIX_PRTSR9_PRTOP5_Pos              _U_(20)                                              /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP5_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP5_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP5(value)           (MATRIX_PRTSR9_PRTOP5_Msk & ((value) << MATRIX_PRTSR9_PRTOP5_Pos))
#define MATRIX_PRTSR9_PRTOP6_Pos              _U_(24)                                              /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP6_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP6_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP6(value)           (MATRIX_PRTSR9_PRTOP6_Msk & ((value) << MATRIX_PRTSR9_PRTOP6_Pos))
#define MATRIX_PRTSR9_PRTOP7_Pos              _U_(28)                                              /**< (MATRIX_PRTSR9) HSELx Protected Region Top Position */
#define MATRIX_PRTSR9_PRTOP7_Msk              (_U_(0xF) << MATRIX_PRTSR9_PRTOP7_Pos)               /**< (MATRIX_PRTSR9) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR9_PRTOP7(value)           (MATRIX_PRTSR9_PRTOP7_Msk & ((value) << MATRIX_PRTSR9_PRTOP7_Pos))
#define MATRIX_PRTSR9_Msk                     _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR9) Register Mask  */


/* -------- MATRIX_PRTSR10 : (MATRIX Offset: 0x2A8) (R/W 32) Protected Region Top Slave 0 Register 10 -------- */
#define MATRIX_PRTSR10_PRTOP0_Pos             _U_(0)                                               /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP0_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP0_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP0(value)          (MATRIX_PRTSR10_PRTOP0_Msk & ((value) << MATRIX_PRTSR10_PRTOP0_Pos))
#define MATRIX_PRTSR10_PRTOP1_Pos             _U_(4)                                               /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP1_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP1_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP1(value)          (MATRIX_PRTSR10_PRTOP1_Msk & ((value) << MATRIX_PRTSR10_PRTOP1_Pos))
#define MATRIX_PRTSR10_PRTOP2_Pos             _U_(8)                                               /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP2_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP2_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP2(value)          (MATRIX_PRTSR10_PRTOP2_Msk & ((value) << MATRIX_PRTSR10_PRTOP2_Pos))
#define MATRIX_PRTSR10_PRTOP3_Pos             _U_(12)                                              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP3_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP3_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP3(value)          (MATRIX_PRTSR10_PRTOP3_Msk & ((value) << MATRIX_PRTSR10_PRTOP3_Pos))
#define MATRIX_PRTSR10_PRTOP4_Pos             _U_(16)                                              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP4_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP4_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP4(value)          (MATRIX_PRTSR10_PRTOP4_Msk & ((value) << MATRIX_PRTSR10_PRTOP4_Pos))
#define MATRIX_PRTSR10_PRTOP5_Pos             _U_(20)                                              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP5_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP5_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP5(value)          (MATRIX_PRTSR10_PRTOP5_Msk & ((value) << MATRIX_PRTSR10_PRTOP5_Pos))
#define MATRIX_PRTSR10_PRTOP6_Pos             _U_(24)                                              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP6_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP6_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP6(value)          (MATRIX_PRTSR10_PRTOP6_Msk & ((value) << MATRIX_PRTSR10_PRTOP6_Pos))
#define MATRIX_PRTSR10_PRTOP7_Pos             _U_(28)                                              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Position */
#define MATRIX_PRTSR10_PRTOP7_Msk             (_U_(0xF) << MATRIX_PRTSR10_PRTOP7_Pos)              /**< (MATRIX_PRTSR10) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR10_PRTOP7(value)          (MATRIX_PRTSR10_PRTOP7_Msk & ((value) << MATRIX_PRTSR10_PRTOP7_Pos))
#define MATRIX_PRTSR10_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR10) Register Mask  */


/* -------- MATRIX_PRTSR11 : (MATRIX Offset: 0x2AC) (R/W 32) Protected Region Top Slave 0 Register 11 -------- */
#define MATRIX_PRTSR11_PRTOP0_Pos             _U_(0)                                               /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP0_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP0_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP0(value)          (MATRIX_PRTSR11_PRTOP0_Msk & ((value) << MATRIX_PRTSR11_PRTOP0_Pos))
#define MATRIX_PRTSR11_PRTOP1_Pos             _U_(4)                                               /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP1_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP1_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP1(value)          (MATRIX_PRTSR11_PRTOP1_Msk & ((value) << MATRIX_PRTSR11_PRTOP1_Pos))
#define MATRIX_PRTSR11_PRTOP2_Pos             _U_(8)                                               /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP2_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP2_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP2(value)          (MATRIX_PRTSR11_PRTOP2_Msk & ((value) << MATRIX_PRTSR11_PRTOP2_Pos))
#define MATRIX_PRTSR11_PRTOP3_Pos             _U_(12)                                              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP3_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP3_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP3(value)          (MATRIX_PRTSR11_PRTOP3_Msk & ((value) << MATRIX_PRTSR11_PRTOP3_Pos))
#define MATRIX_PRTSR11_PRTOP4_Pos             _U_(16)                                              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP4_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP4_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP4(value)          (MATRIX_PRTSR11_PRTOP4_Msk & ((value) << MATRIX_PRTSR11_PRTOP4_Pos))
#define MATRIX_PRTSR11_PRTOP5_Pos             _U_(20)                                              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP5_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP5_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP5(value)          (MATRIX_PRTSR11_PRTOP5_Msk & ((value) << MATRIX_PRTSR11_PRTOP5_Pos))
#define MATRIX_PRTSR11_PRTOP6_Pos             _U_(24)                                              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP6_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP6_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP6(value)          (MATRIX_PRTSR11_PRTOP6_Msk & ((value) << MATRIX_PRTSR11_PRTOP6_Pos))
#define MATRIX_PRTSR11_PRTOP7_Pos             _U_(28)                                              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Position */
#define MATRIX_PRTSR11_PRTOP7_Msk             (_U_(0xF) << MATRIX_PRTSR11_PRTOP7_Pos)              /**< (MATRIX_PRTSR11) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR11_PRTOP7(value)          (MATRIX_PRTSR11_PRTOP7_Msk & ((value) << MATRIX_PRTSR11_PRTOP7_Pos))
#define MATRIX_PRTSR11_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR11) Register Mask  */


/* -------- MATRIX_PRTSR12 : (MATRIX Offset: 0x2B0) (R/W 32) Protected Region Top Slave 0 Register 12 -------- */
#define MATRIX_PRTSR12_PRTOP0_Pos             _U_(0)                                               /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP0_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP0_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP0(value)          (MATRIX_PRTSR12_PRTOP0_Msk & ((value) << MATRIX_PRTSR12_PRTOP0_Pos))
#define MATRIX_PRTSR12_PRTOP1_Pos             _U_(4)                                               /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP1_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP1_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP1(value)          (MATRIX_PRTSR12_PRTOP1_Msk & ((value) << MATRIX_PRTSR12_PRTOP1_Pos))
#define MATRIX_PRTSR12_PRTOP2_Pos             _U_(8)                                               /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP2_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP2_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP2(value)          (MATRIX_PRTSR12_PRTOP2_Msk & ((value) << MATRIX_PRTSR12_PRTOP2_Pos))
#define MATRIX_PRTSR12_PRTOP3_Pos             _U_(12)                                              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP3_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP3_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP3(value)          (MATRIX_PRTSR12_PRTOP3_Msk & ((value) << MATRIX_PRTSR12_PRTOP3_Pos))
#define MATRIX_PRTSR12_PRTOP4_Pos             _U_(16)                                              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP4_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP4_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP4(value)          (MATRIX_PRTSR12_PRTOP4_Msk & ((value) << MATRIX_PRTSR12_PRTOP4_Pos))
#define MATRIX_PRTSR12_PRTOP5_Pos             _U_(20)                                              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP5_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP5_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP5(value)          (MATRIX_PRTSR12_PRTOP5_Msk & ((value) << MATRIX_PRTSR12_PRTOP5_Pos))
#define MATRIX_PRTSR12_PRTOP6_Pos             _U_(24)                                              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP6_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP6_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP6(value)          (MATRIX_PRTSR12_PRTOP6_Msk & ((value) << MATRIX_PRTSR12_PRTOP6_Pos))
#define MATRIX_PRTSR12_PRTOP7_Pos             _U_(28)                                              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Position */
#define MATRIX_PRTSR12_PRTOP7_Msk             (_U_(0xF) << MATRIX_PRTSR12_PRTOP7_Pos)              /**< (MATRIX_PRTSR12) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR12_PRTOP7(value)          (MATRIX_PRTSR12_PRTOP7_Msk & ((value) << MATRIX_PRTSR12_PRTOP7_Pos))
#define MATRIX_PRTSR12_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR12) Register Mask  */


/* -------- MATRIX_PRTSR13 : (MATRIX Offset: 0x2B4) (R/W 32) Protected Region Top Slave 0 Register 13 -------- */
#define MATRIX_PRTSR13_PRTOP0_Pos             _U_(0)                                               /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP0_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP0_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP0(value)          (MATRIX_PRTSR13_PRTOP0_Msk & ((value) << MATRIX_PRTSR13_PRTOP0_Pos))
#define MATRIX_PRTSR13_PRTOP1_Pos             _U_(4)                                               /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP1_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP1_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP1(value)          (MATRIX_PRTSR13_PRTOP1_Msk & ((value) << MATRIX_PRTSR13_PRTOP1_Pos))
#define MATRIX_PRTSR13_PRTOP2_Pos             _U_(8)                                               /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP2_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP2_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP2(value)          (MATRIX_PRTSR13_PRTOP2_Msk & ((value) << MATRIX_PRTSR13_PRTOP2_Pos))
#define MATRIX_PRTSR13_PRTOP3_Pos             _U_(12)                                              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP3_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP3_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP3(value)          (MATRIX_PRTSR13_PRTOP3_Msk & ((value) << MATRIX_PRTSR13_PRTOP3_Pos))
#define MATRIX_PRTSR13_PRTOP4_Pos             _U_(16)                                              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP4_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP4_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP4(value)          (MATRIX_PRTSR13_PRTOP4_Msk & ((value) << MATRIX_PRTSR13_PRTOP4_Pos))
#define MATRIX_PRTSR13_PRTOP5_Pos             _U_(20)                                              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP5_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP5_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP5(value)          (MATRIX_PRTSR13_PRTOP5_Msk & ((value) << MATRIX_PRTSR13_PRTOP5_Pos))
#define MATRIX_PRTSR13_PRTOP6_Pos             _U_(24)                                              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP6_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP6_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP6(value)          (MATRIX_PRTSR13_PRTOP6_Msk & ((value) << MATRIX_PRTSR13_PRTOP6_Pos))
#define MATRIX_PRTSR13_PRTOP7_Pos             _U_(28)                                              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Position */
#define MATRIX_PRTSR13_PRTOP7_Msk             (_U_(0xF) << MATRIX_PRTSR13_PRTOP7_Pos)              /**< (MATRIX_PRTSR13) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR13_PRTOP7(value)          (MATRIX_PRTSR13_PRTOP7_Msk & ((value) << MATRIX_PRTSR13_PRTOP7_Pos))
#define MATRIX_PRTSR13_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR13) Register Mask  */


/* -------- MATRIX_PRTSR14 : (MATRIX Offset: 0x2B8) (R/W 32) Protected Region Top Slave 0 Register 14 -------- */
#define MATRIX_PRTSR14_PRTOP0_Pos             _U_(0)                                               /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP0_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP0_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP0(value)          (MATRIX_PRTSR14_PRTOP0_Msk & ((value) << MATRIX_PRTSR14_PRTOP0_Pos))
#define MATRIX_PRTSR14_PRTOP1_Pos             _U_(4)                                               /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP1_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP1_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP1(value)          (MATRIX_PRTSR14_PRTOP1_Msk & ((value) << MATRIX_PRTSR14_PRTOP1_Pos))
#define MATRIX_PRTSR14_PRTOP2_Pos             _U_(8)                                               /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP2_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP2_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP2(value)          (MATRIX_PRTSR14_PRTOP2_Msk & ((value) << MATRIX_PRTSR14_PRTOP2_Pos))
#define MATRIX_PRTSR14_PRTOP3_Pos             _U_(12)                                              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP3_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP3_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP3(value)          (MATRIX_PRTSR14_PRTOP3_Msk & ((value) << MATRIX_PRTSR14_PRTOP3_Pos))
#define MATRIX_PRTSR14_PRTOP4_Pos             _U_(16)                                              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP4_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP4_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP4(value)          (MATRIX_PRTSR14_PRTOP4_Msk & ((value) << MATRIX_PRTSR14_PRTOP4_Pos))
#define MATRIX_PRTSR14_PRTOP5_Pos             _U_(20)                                              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP5_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP5_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP5(value)          (MATRIX_PRTSR14_PRTOP5_Msk & ((value) << MATRIX_PRTSR14_PRTOP5_Pos))
#define MATRIX_PRTSR14_PRTOP6_Pos             _U_(24)                                              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP6_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP6_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP6(value)          (MATRIX_PRTSR14_PRTOP6_Msk & ((value) << MATRIX_PRTSR14_PRTOP6_Pos))
#define MATRIX_PRTSR14_PRTOP7_Pos             _U_(28)                                              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Position */
#define MATRIX_PRTSR14_PRTOP7_Msk             (_U_(0xF) << MATRIX_PRTSR14_PRTOP7_Pos)              /**< (MATRIX_PRTSR14) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR14_PRTOP7(value)          (MATRIX_PRTSR14_PRTOP7_Msk & ((value) << MATRIX_PRTSR14_PRTOP7_Pos))
#define MATRIX_PRTSR14_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR14) Register Mask  */


/* -------- MATRIX_PRTSR15 : (MATRIX Offset: 0x2BC) (R/W 32) Protected Region Top Slave 0 Register 15 -------- */
#define MATRIX_PRTSR15_PRTOP0_Pos             _U_(0)                                               /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP0_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP0_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP0(value)          (MATRIX_PRTSR15_PRTOP0_Msk & ((value) << MATRIX_PRTSR15_PRTOP0_Pos))
#define MATRIX_PRTSR15_PRTOP1_Pos             _U_(4)                                               /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP1_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP1_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP1(value)          (MATRIX_PRTSR15_PRTOP1_Msk & ((value) << MATRIX_PRTSR15_PRTOP1_Pos))
#define MATRIX_PRTSR15_PRTOP2_Pos             _U_(8)                                               /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP2_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP2_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP2(value)          (MATRIX_PRTSR15_PRTOP2_Msk & ((value) << MATRIX_PRTSR15_PRTOP2_Pos))
#define MATRIX_PRTSR15_PRTOP3_Pos             _U_(12)                                              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP3_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP3_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP3(value)          (MATRIX_PRTSR15_PRTOP3_Msk & ((value) << MATRIX_PRTSR15_PRTOP3_Pos))
#define MATRIX_PRTSR15_PRTOP4_Pos             _U_(16)                                              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP4_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP4_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP4(value)          (MATRIX_PRTSR15_PRTOP4_Msk & ((value) << MATRIX_PRTSR15_PRTOP4_Pos))
#define MATRIX_PRTSR15_PRTOP5_Pos             _U_(20)                                              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP5_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP5_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP5(value)          (MATRIX_PRTSR15_PRTOP5_Msk & ((value) << MATRIX_PRTSR15_PRTOP5_Pos))
#define MATRIX_PRTSR15_PRTOP6_Pos             _U_(24)                                              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP6_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP6_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP6(value)          (MATRIX_PRTSR15_PRTOP6_Msk & ((value) << MATRIX_PRTSR15_PRTOP6_Pos))
#define MATRIX_PRTSR15_PRTOP7_Pos             _U_(28)                                              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Position */
#define MATRIX_PRTSR15_PRTOP7_Msk             (_U_(0xF) << MATRIX_PRTSR15_PRTOP7_Pos)              /**< (MATRIX_PRTSR15) HSELx Protected Region Top Mask */
#define MATRIX_PRTSR15_PRTOP7(value)          (MATRIX_PRTSR15_PRTOP7_Msk & ((value) << MATRIX_PRTSR15_PRTOP7_Pos))
#define MATRIX_PRTSR15_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PRTSR15) Register Mask  */


/* -------- MATRIX_PPSELR0 : (MATRIX Offset: 0x2C0) (R/W 32) Protected Peripheral Select 1 Register 0 -------- */
#define MATRIX_PPSELR0_USERP0_Pos             _U_(0)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP0_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP0_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP0(value)          (MATRIX_PPSELR0_USERP0_Msk & ((value) << MATRIX_PPSELR0_USERP0_Pos))
#define MATRIX_PPSELR0_USERP1_Pos             _U_(1)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP1_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP1_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP1(value)          (MATRIX_PPSELR0_USERP1_Msk & ((value) << MATRIX_PPSELR0_USERP1_Pos))
#define MATRIX_PPSELR0_USERP2_Pos             _U_(2)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP2_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP2_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP2(value)          (MATRIX_PPSELR0_USERP2_Msk & ((value) << MATRIX_PPSELR0_USERP2_Pos))
#define MATRIX_PPSELR0_USERP3_Pos             _U_(3)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP3_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP3_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP3(value)          (MATRIX_PPSELR0_USERP3_Msk & ((value) << MATRIX_PPSELR0_USERP3_Pos))
#define MATRIX_PPSELR0_USERP4_Pos             _U_(4)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP4_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP4_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP4(value)          (MATRIX_PPSELR0_USERP4_Msk & ((value) << MATRIX_PPSELR0_USERP4_Pos))
#define MATRIX_PPSELR0_USERP5_Pos             _U_(5)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP5_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP5_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP5(value)          (MATRIX_PPSELR0_USERP5_Msk & ((value) << MATRIX_PPSELR0_USERP5_Pos))
#define MATRIX_PPSELR0_USERP6_Pos             _U_(6)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP6_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP6_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP6(value)          (MATRIX_PPSELR0_USERP6_Msk & ((value) << MATRIX_PPSELR0_USERP6_Pos))
#define MATRIX_PPSELR0_USERP7_Pos             _U_(7)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP7_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP7_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP7(value)          (MATRIX_PPSELR0_USERP7_Msk & ((value) << MATRIX_PPSELR0_USERP7_Pos))
#define MATRIX_PPSELR0_USERP8_Pos             _U_(8)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP8_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP8_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP8(value)          (MATRIX_PPSELR0_USERP8_Msk & ((value) << MATRIX_PPSELR0_USERP8_Pos))
#define MATRIX_PPSELR0_USERP9_Pos             _U_(9)                                               /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP9_Msk             (_U_(0x1) << MATRIX_PPSELR0_USERP9_Pos)              /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP9(value)          (MATRIX_PPSELR0_USERP9_Msk & ((value) << MATRIX_PPSELR0_USERP9_Pos))
#define MATRIX_PPSELR0_USERP10_Pos            _U_(10)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP10_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP10_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP10(value)         (MATRIX_PPSELR0_USERP10_Msk & ((value) << MATRIX_PPSELR0_USERP10_Pos))
#define MATRIX_PPSELR0_USERP11_Pos            _U_(11)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP11_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP11_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP11(value)         (MATRIX_PPSELR0_USERP11_Msk & ((value) << MATRIX_PPSELR0_USERP11_Pos))
#define MATRIX_PPSELR0_USERP12_Pos            _U_(12)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP12_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP12_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP12(value)         (MATRIX_PPSELR0_USERP12_Msk & ((value) << MATRIX_PPSELR0_USERP12_Pos))
#define MATRIX_PPSELR0_USERP13_Pos            _U_(13)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP13_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP13_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP13(value)         (MATRIX_PPSELR0_USERP13_Msk & ((value) << MATRIX_PPSELR0_USERP13_Pos))
#define MATRIX_PPSELR0_USERP14_Pos            _U_(14)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP14_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP14_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP14(value)         (MATRIX_PPSELR0_USERP14_Msk & ((value) << MATRIX_PPSELR0_USERP14_Pos))
#define MATRIX_PPSELR0_USERP15_Pos            _U_(15)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP15_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP15_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP15(value)         (MATRIX_PPSELR0_USERP15_Msk & ((value) << MATRIX_PPSELR0_USERP15_Pos))
#define MATRIX_PPSELR0_USERP16_Pos            _U_(16)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP16_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP16_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP16(value)         (MATRIX_PPSELR0_USERP16_Msk & ((value) << MATRIX_PPSELR0_USERP16_Pos))
#define MATRIX_PPSELR0_USERP17_Pos            _U_(17)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP17_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP17_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP17(value)         (MATRIX_PPSELR0_USERP17_Msk & ((value) << MATRIX_PPSELR0_USERP17_Pos))
#define MATRIX_PPSELR0_USERP18_Pos            _U_(18)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP18_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP18_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP18(value)         (MATRIX_PPSELR0_USERP18_Msk & ((value) << MATRIX_PPSELR0_USERP18_Pos))
#define MATRIX_PPSELR0_USERP19_Pos            _U_(19)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP19_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP19_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP19(value)         (MATRIX_PPSELR0_USERP19_Msk & ((value) << MATRIX_PPSELR0_USERP19_Pos))
#define MATRIX_PPSELR0_USERP20_Pos            _U_(20)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP20_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP20_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP20(value)         (MATRIX_PPSELR0_USERP20_Msk & ((value) << MATRIX_PPSELR0_USERP20_Pos))
#define MATRIX_PPSELR0_USERP21_Pos            _U_(21)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP21_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP21_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP21(value)         (MATRIX_PPSELR0_USERP21_Msk & ((value) << MATRIX_PPSELR0_USERP21_Pos))
#define MATRIX_PPSELR0_USERP22_Pos            _U_(22)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP22_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP22_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP22(value)         (MATRIX_PPSELR0_USERP22_Msk & ((value) << MATRIX_PPSELR0_USERP22_Pos))
#define MATRIX_PPSELR0_USERP23_Pos            _U_(23)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP23_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP23_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP23(value)         (MATRIX_PPSELR0_USERP23_Msk & ((value) << MATRIX_PPSELR0_USERP23_Pos))
#define MATRIX_PPSELR0_USERP24_Pos            _U_(24)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP24_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP24_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP24(value)         (MATRIX_PPSELR0_USERP24_Msk & ((value) << MATRIX_PPSELR0_USERP24_Pos))
#define MATRIX_PPSELR0_USERP25_Pos            _U_(25)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP25_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP25_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP25(value)         (MATRIX_PPSELR0_USERP25_Msk & ((value) << MATRIX_PPSELR0_USERP25_Pos))
#define MATRIX_PPSELR0_USERP26_Pos            _U_(26)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP26_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP26_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP26(value)         (MATRIX_PPSELR0_USERP26_Msk & ((value) << MATRIX_PPSELR0_USERP26_Pos))
#define MATRIX_PPSELR0_USERP27_Pos            _U_(27)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP27_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP27_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP27(value)         (MATRIX_PPSELR0_USERP27_Msk & ((value) << MATRIX_PPSELR0_USERP27_Pos))
#define MATRIX_PPSELR0_USERP28_Pos            _U_(28)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP28_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP28_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP28(value)         (MATRIX_PPSELR0_USERP28_Msk & ((value) << MATRIX_PPSELR0_USERP28_Pos))
#define MATRIX_PPSELR0_USERP29_Pos            _U_(29)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP29_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP29_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP29(value)         (MATRIX_PPSELR0_USERP29_Msk & ((value) << MATRIX_PPSELR0_USERP29_Pos))
#define MATRIX_PPSELR0_USERP30_Pos            _U_(30)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP30_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP30_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP30(value)         (MATRIX_PPSELR0_USERP30_Msk & ((value) << MATRIX_PPSELR0_USERP30_Pos))
#define MATRIX_PPSELR0_USERP31_Pos            _U_(31)                                              /**< (MATRIX_PPSELR0) User PSELy Peripheral Position */
#define MATRIX_PPSELR0_USERP31_Msk            (_U_(0x1) << MATRIX_PPSELR0_USERP31_Pos)             /**< (MATRIX_PPSELR0) User PSELy Peripheral Mask */
#define MATRIX_PPSELR0_USERP31(value)         (MATRIX_PPSELR0_USERP31_Msk & ((value) << MATRIX_PPSELR0_USERP31_Pos))
#define MATRIX_PPSELR0_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PPSELR0) Register Mask  */

#define MATRIX_PPSELR0_USERP_Pos              _U_(0)                                               /**< (MATRIX_PPSELR0 Position) User PSELy Peripheral */
#define MATRIX_PPSELR0_USERP_Msk              (_U_(0xFFFFFFFF) << MATRIX_PPSELR0_USERP_Pos)        /**< (MATRIX_PPSELR0 Mask) USERP */
#define MATRIX_PPSELR0_USERP(value)           (MATRIX_PPSELR0_USERP_Msk & ((value) << MATRIX_PPSELR0_USERP_Pos)) 

/* -------- MATRIX_PPSELR1 : (MATRIX Offset: 0x2C4) (R/W 32) Protected Peripheral Select 1 Register 1 -------- */
#define MATRIX_PPSELR1_USERP0_Pos             _U_(0)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP0_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP0_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP0(value)          (MATRIX_PPSELR1_USERP0_Msk & ((value) << MATRIX_PPSELR1_USERP0_Pos))
#define MATRIX_PPSELR1_USERP1_Pos             _U_(1)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP1_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP1_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP1(value)          (MATRIX_PPSELR1_USERP1_Msk & ((value) << MATRIX_PPSELR1_USERP1_Pos))
#define MATRIX_PPSELR1_USERP2_Pos             _U_(2)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP2_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP2_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP2(value)          (MATRIX_PPSELR1_USERP2_Msk & ((value) << MATRIX_PPSELR1_USERP2_Pos))
#define MATRIX_PPSELR1_USERP3_Pos             _U_(3)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP3_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP3_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP3(value)          (MATRIX_PPSELR1_USERP3_Msk & ((value) << MATRIX_PPSELR1_USERP3_Pos))
#define MATRIX_PPSELR1_USERP4_Pos             _U_(4)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP4_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP4_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP4(value)          (MATRIX_PPSELR1_USERP4_Msk & ((value) << MATRIX_PPSELR1_USERP4_Pos))
#define MATRIX_PPSELR1_USERP5_Pos             _U_(5)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP5_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP5_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP5(value)          (MATRIX_PPSELR1_USERP5_Msk & ((value) << MATRIX_PPSELR1_USERP5_Pos))
#define MATRIX_PPSELR1_USERP6_Pos             _U_(6)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP6_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP6_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP6(value)          (MATRIX_PPSELR1_USERP6_Msk & ((value) << MATRIX_PPSELR1_USERP6_Pos))
#define MATRIX_PPSELR1_USERP7_Pos             _U_(7)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP7_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP7_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP7(value)          (MATRIX_PPSELR1_USERP7_Msk & ((value) << MATRIX_PPSELR1_USERP7_Pos))
#define MATRIX_PPSELR1_USERP8_Pos             _U_(8)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP8_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP8_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP8(value)          (MATRIX_PPSELR1_USERP8_Msk & ((value) << MATRIX_PPSELR1_USERP8_Pos))
#define MATRIX_PPSELR1_USERP9_Pos             _U_(9)                                               /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP9_Msk             (_U_(0x1) << MATRIX_PPSELR1_USERP9_Pos)              /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP9(value)          (MATRIX_PPSELR1_USERP9_Msk & ((value) << MATRIX_PPSELR1_USERP9_Pos))
#define MATRIX_PPSELR1_USERP10_Pos            _U_(10)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP10_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP10_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP10(value)         (MATRIX_PPSELR1_USERP10_Msk & ((value) << MATRIX_PPSELR1_USERP10_Pos))
#define MATRIX_PPSELR1_USERP11_Pos            _U_(11)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP11_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP11_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP11(value)         (MATRIX_PPSELR1_USERP11_Msk & ((value) << MATRIX_PPSELR1_USERP11_Pos))
#define MATRIX_PPSELR1_USERP12_Pos            _U_(12)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP12_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP12_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP12(value)         (MATRIX_PPSELR1_USERP12_Msk & ((value) << MATRIX_PPSELR1_USERP12_Pos))
#define MATRIX_PPSELR1_USERP13_Pos            _U_(13)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP13_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP13_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP13(value)         (MATRIX_PPSELR1_USERP13_Msk & ((value) << MATRIX_PPSELR1_USERP13_Pos))
#define MATRIX_PPSELR1_USERP14_Pos            _U_(14)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP14_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP14_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP14(value)         (MATRIX_PPSELR1_USERP14_Msk & ((value) << MATRIX_PPSELR1_USERP14_Pos))
#define MATRIX_PPSELR1_USERP15_Pos            _U_(15)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP15_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP15_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP15(value)         (MATRIX_PPSELR1_USERP15_Msk & ((value) << MATRIX_PPSELR1_USERP15_Pos))
#define MATRIX_PPSELR1_USERP16_Pos            _U_(16)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP16_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP16_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP16(value)         (MATRIX_PPSELR1_USERP16_Msk & ((value) << MATRIX_PPSELR1_USERP16_Pos))
#define MATRIX_PPSELR1_USERP17_Pos            _U_(17)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP17_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP17_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP17(value)         (MATRIX_PPSELR1_USERP17_Msk & ((value) << MATRIX_PPSELR1_USERP17_Pos))
#define MATRIX_PPSELR1_USERP18_Pos            _U_(18)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP18_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP18_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP18(value)         (MATRIX_PPSELR1_USERP18_Msk & ((value) << MATRIX_PPSELR1_USERP18_Pos))
#define MATRIX_PPSELR1_USERP19_Pos            _U_(19)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP19_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP19_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP19(value)         (MATRIX_PPSELR1_USERP19_Msk & ((value) << MATRIX_PPSELR1_USERP19_Pos))
#define MATRIX_PPSELR1_USERP20_Pos            _U_(20)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP20_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP20_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP20(value)         (MATRIX_PPSELR1_USERP20_Msk & ((value) << MATRIX_PPSELR1_USERP20_Pos))
#define MATRIX_PPSELR1_USERP21_Pos            _U_(21)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP21_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP21_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP21(value)         (MATRIX_PPSELR1_USERP21_Msk & ((value) << MATRIX_PPSELR1_USERP21_Pos))
#define MATRIX_PPSELR1_USERP22_Pos            _U_(22)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP22_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP22_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP22(value)         (MATRIX_PPSELR1_USERP22_Msk & ((value) << MATRIX_PPSELR1_USERP22_Pos))
#define MATRIX_PPSELR1_USERP23_Pos            _U_(23)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP23_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP23_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP23(value)         (MATRIX_PPSELR1_USERP23_Msk & ((value) << MATRIX_PPSELR1_USERP23_Pos))
#define MATRIX_PPSELR1_USERP24_Pos            _U_(24)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP24_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP24_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP24(value)         (MATRIX_PPSELR1_USERP24_Msk & ((value) << MATRIX_PPSELR1_USERP24_Pos))
#define MATRIX_PPSELR1_USERP25_Pos            _U_(25)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP25_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP25_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP25(value)         (MATRIX_PPSELR1_USERP25_Msk & ((value) << MATRIX_PPSELR1_USERP25_Pos))
#define MATRIX_PPSELR1_USERP26_Pos            _U_(26)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP26_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP26_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP26(value)         (MATRIX_PPSELR1_USERP26_Msk & ((value) << MATRIX_PPSELR1_USERP26_Pos))
#define MATRIX_PPSELR1_USERP27_Pos            _U_(27)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP27_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP27_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP27(value)         (MATRIX_PPSELR1_USERP27_Msk & ((value) << MATRIX_PPSELR1_USERP27_Pos))
#define MATRIX_PPSELR1_USERP28_Pos            _U_(28)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP28_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP28_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP28(value)         (MATRIX_PPSELR1_USERP28_Msk & ((value) << MATRIX_PPSELR1_USERP28_Pos))
#define MATRIX_PPSELR1_USERP29_Pos            _U_(29)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP29_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP29_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP29(value)         (MATRIX_PPSELR1_USERP29_Msk & ((value) << MATRIX_PPSELR1_USERP29_Pos))
#define MATRIX_PPSELR1_USERP30_Pos            _U_(30)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP30_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP30_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP30(value)         (MATRIX_PPSELR1_USERP30_Msk & ((value) << MATRIX_PPSELR1_USERP30_Pos))
#define MATRIX_PPSELR1_USERP31_Pos            _U_(31)                                              /**< (MATRIX_PPSELR1) User PSELy Peripheral Position */
#define MATRIX_PPSELR1_USERP31_Msk            (_U_(0x1) << MATRIX_PPSELR1_USERP31_Pos)             /**< (MATRIX_PPSELR1) User PSELy Peripheral Mask */
#define MATRIX_PPSELR1_USERP31(value)         (MATRIX_PPSELR1_USERP31_Msk & ((value) << MATRIX_PPSELR1_USERP31_Pos))
#define MATRIX_PPSELR1_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PPSELR1) Register Mask  */

#define MATRIX_PPSELR1_USERP_Pos              _U_(0)                                               /**< (MATRIX_PPSELR1 Position) User PSELy Peripheral */
#define MATRIX_PPSELR1_USERP_Msk              (_U_(0xFFFFFFFF) << MATRIX_PPSELR1_USERP_Pos)        /**< (MATRIX_PPSELR1 Mask) USERP */
#define MATRIX_PPSELR1_USERP(value)           (MATRIX_PPSELR1_USERP_Msk & ((value) << MATRIX_PPSELR1_USERP_Pos)) 

/* -------- MATRIX_PPSELR2 : (MATRIX Offset: 0x2C8) (R/W 32) Protected Peripheral Select 1 Register 2 -------- */
#define MATRIX_PPSELR2_USERP0_Pos             _U_(0)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP0_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP0_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP0(value)          (MATRIX_PPSELR2_USERP0_Msk & ((value) << MATRIX_PPSELR2_USERP0_Pos))
#define MATRIX_PPSELR2_USERP1_Pos             _U_(1)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP1_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP1_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP1(value)          (MATRIX_PPSELR2_USERP1_Msk & ((value) << MATRIX_PPSELR2_USERP1_Pos))
#define MATRIX_PPSELR2_USERP2_Pos             _U_(2)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP2_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP2_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP2(value)          (MATRIX_PPSELR2_USERP2_Msk & ((value) << MATRIX_PPSELR2_USERP2_Pos))
#define MATRIX_PPSELR2_USERP3_Pos             _U_(3)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP3_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP3_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP3(value)          (MATRIX_PPSELR2_USERP3_Msk & ((value) << MATRIX_PPSELR2_USERP3_Pos))
#define MATRIX_PPSELR2_USERP4_Pos             _U_(4)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP4_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP4_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP4(value)          (MATRIX_PPSELR2_USERP4_Msk & ((value) << MATRIX_PPSELR2_USERP4_Pos))
#define MATRIX_PPSELR2_USERP5_Pos             _U_(5)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP5_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP5_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP5(value)          (MATRIX_PPSELR2_USERP5_Msk & ((value) << MATRIX_PPSELR2_USERP5_Pos))
#define MATRIX_PPSELR2_USERP6_Pos             _U_(6)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP6_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP6_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP6(value)          (MATRIX_PPSELR2_USERP6_Msk & ((value) << MATRIX_PPSELR2_USERP6_Pos))
#define MATRIX_PPSELR2_USERP7_Pos             _U_(7)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP7_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP7_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP7(value)          (MATRIX_PPSELR2_USERP7_Msk & ((value) << MATRIX_PPSELR2_USERP7_Pos))
#define MATRIX_PPSELR2_USERP8_Pos             _U_(8)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP8_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP8_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP8(value)          (MATRIX_PPSELR2_USERP8_Msk & ((value) << MATRIX_PPSELR2_USERP8_Pos))
#define MATRIX_PPSELR2_USERP9_Pos             _U_(9)                                               /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP9_Msk             (_U_(0x1) << MATRIX_PPSELR2_USERP9_Pos)              /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP9(value)          (MATRIX_PPSELR2_USERP9_Msk & ((value) << MATRIX_PPSELR2_USERP9_Pos))
#define MATRIX_PPSELR2_USERP10_Pos            _U_(10)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP10_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP10_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP10(value)         (MATRIX_PPSELR2_USERP10_Msk & ((value) << MATRIX_PPSELR2_USERP10_Pos))
#define MATRIX_PPSELR2_USERP11_Pos            _U_(11)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP11_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP11_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP11(value)         (MATRIX_PPSELR2_USERP11_Msk & ((value) << MATRIX_PPSELR2_USERP11_Pos))
#define MATRIX_PPSELR2_USERP12_Pos            _U_(12)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP12_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP12_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP12(value)         (MATRIX_PPSELR2_USERP12_Msk & ((value) << MATRIX_PPSELR2_USERP12_Pos))
#define MATRIX_PPSELR2_USERP13_Pos            _U_(13)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP13_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP13_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP13(value)         (MATRIX_PPSELR2_USERP13_Msk & ((value) << MATRIX_PPSELR2_USERP13_Pos))
#define MATRIX_PPSELR2_USERP14_Pos            _U_(14)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP14_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP14_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP14(value)         (MATRIX_PPSELR2_USERP14_Msk & ((value) << MATRIX_PPSELR2_USERP14_Pos))
#define MATRIX_PPSELR2_USERP15_Pos            _U_(15)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP15_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP15_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP15(value)         (MATRIX_PPSELR2_USERP15_Msk & ((value) << MATRIX_PPSELR2_USERP15_Pos))
#define MATRIX_PPSELR2_USERP16_Pos            _U_(16)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP16_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP16_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP16(value)         (MATRIX_PPSELR2_USERP16_Msk & ((value) << MATRIX_PPSELR2_USERP16_Pos))
#define MATRIX_PPSELR2_USERP17_Pos            _U_(17)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP17_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP17_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP17(value)         (MATRIX_PPSELR2_USERP17_Msk & ((value) << MATRIX_PPSELR2_USERP17_Pos))
#define MATRIX_PPSELR2_USERP18_Pos            _U_(18)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP18_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP18_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP18(value)         (MATRIX_PPSELR2_USERP18_Msk & ((value) << MATRIX_PPSELR2_USERP18_Pos))
#define MATRIX_PPSELR2_USERP19_Pos            _U_(19)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP19_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP19_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP19(value)         (MATRIX_PPSELR2_USERP19_Msk & ((value) << MATRIX_PPSELR2_USERP19_Pos))
#define MATRIX_PPSELR2_USERP20_Pos            _U_(20)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP20_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP20_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP20(value)         (MATRIX_PPSELR2_USERP20_Msk & ((value) << MATRIX_PPSELR2_USERP20_Pos))
#define MATRIX_PPSELR2_USERP21_Pos            _U_(21)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP21_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP21_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP21(value)         (MATRIX_PPSELR2_USERP21_Msk & ((value) << MATRIX_PPSELR2_USERP21_Pos))
#define MATRIX_PPSELR2_USERP22_Pos            _U_(22)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP22_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP22_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP22(value)         (MATRIX_PPSELR2_USERP22_Msk & ((value) << MATRIX_PPSELR2_USERP22_Pos))
#define MATRIX_PPSELR2_USERP23_Pos            _U_(23)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP23_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP23_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP23(value)         (MATRIX_PPSELR2_USERP23_Msk & ((value) << MATRIX_PPSELR2_USERP23_Pos))
#define MATRIX_PPSELR2_USERP24_Pos            _U_(24)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP24_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP24_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP24(value)         (MATRIX_PPSELR2_USERP24_Msk & ((value) << MATRIX_PPSELR2_USERP24_Pos))
#define MATRIX_PPSELR2_USERP25_Pos            _U_(25)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP25_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP25_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP25(value)         (MATRIX_PPSELR2_USERP25_Msk & ((value) << MATRIX_PPSELR2_USERP25_Pos))
#define MATRIX_PPSELR2_USERP26_Pos            _U_(26)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP26_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP26_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP26(value)         (MATRIX_PPSELR2_USERP26_Msk & ((value) << MATRIX_PPSELR2_USERP26_Pos))
#define MATRIX_PPSELR2_USERP27_Pos            _U_(27)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP27_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP27_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP27(value)         (MATRIX_PPSELR2_USERP27_Msk & ((value) << MATRIX_PPSELR2_USERP27_Pos))
#define MATRIX_PPSELR2_USERP28_Pos            _U_(28)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP28_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP28_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP28(value)         (MATRIX_PPSELR2_USERP28_Msk & ((value) << MATRIX_PPSELR2_USERP28_Pos))
#define MATRIX_PPSELR2_USERP29_Pos            _U_(29)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP29_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP29_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP29(value)         (MATRIX_PPSELR2_USERP29_Msk & ((value) << MATRIX_PPSELR2_USERP29_Pos))
#define MATRIX_PPSELR2_USERP30_Pos            _U_(30)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP30_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP30_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP30(value)         (MATRIX_PPSELR2_USERP30_Msk & ((value) << MATRIX_PPSELR2_USERP30_Pos))
#define MATRIX_PPSELR2_USERP31_Pos            _U_(31)                                              /**< (MATRIX_PPSELR2) User PSELy Peripheral Position */
#define MATRIX_PPSELR2_USERP31_Msk            (_U_(0x1) << MATRIX_PPSELR2_USERP31_Pos)             /**< (MATRIX_PPSELR2) User PSELy Peripheral Mask */
#define MATRIX_PPSELR2_USERP31(value)         (MATRIX_PPSELR2_USERP31_Msk & ((value) << MATRIX_PPSELR2_USERP31_Pos))
#define MATRIX_PPSELR2_Msk                    _U_(0xFFFFFFFF)                                      /**< (MATRIX_PPSELR2) Register Mask  */

#define MATRIX_PPSELR2_USERP_Pos              _U_(0)                                               /**< (MATRIX_PPSELR2 Position) User PSELy Peripheral */
#define MATRIX_PPSELR2_USERP_Msk              (_U_(0xFFFFFFFF) << MATRIX_PPSELR2_USERP_Pos)        /**< (MATRIX_PPSELR2 Mask) USERP */
#define MATRIX_PPSELR2_USERP(value)           (MATRIX_PPSELR2_USERP_Msk & ((value) << MATRIX_PPSELR2_USERP_Pos)) 

/** \brief MATRIX register offsets definitions */
#define MATRIX_MCFG0_REG_OFST          (0x00)              /**< (MATRIX_MCFG0) Master Configuration Register 0 Offset */
#define MATRIX_MCFG1_REG_OFST          (0x04)              /**< (MATRIX_MCFG1) Master Configuration Register 1 Offset */
#define MATRIX_MCFG2_REG_OFST          (0x08)              /**< (MATRIX_MCFG2) Master Configuration Register 2 Offset */
#define MATRIX_MCFG3_REG_OFST          (0x0C)              /**< (MATRIX_MCFG3) Master Configuration Register 3 Offset */
#define MATRIX_MCFG4_REG_OFST          (0x10)              /**< (MATRIX_MCFG4) Master Configuration Register 4 Offset */
#define MATRIX_MCFG5_REG_OFST          (0x14)              /**< (MATRIX_MCFG5) Master Configuration Register 5 Offset */
#define MATRIX_MCFG6_REG_OFST          (0x18)              /**< (MATRIX_MCFG6) Master Configuration Register 6 Offset */
#define MATRIX_MCFG7_REG_OFST          (0x1C)              /**< (MATRIX_MCFG7) Master Configuration Register 7 Offset */
#define MATRIX_MCFG8_REG_OFST          (0x20)              /**< (MATRIX_MCFG8) Master Configuration Register 8 Offset */
#define MATRIX_MCFG9_REG_OFST          (0x24)              /**< (MATRIX_MCFG9) Master Configuration Register 9 Offset */
#define MATRIX_MCFG10_REG_OFST         (0x28)              /**< (MATRIX_MCFG10) Master Configuration Register 10 Offset */
#define MATRIX_MCFG11_REG_OFST         (0x2C)              /**< (MATRIX_MCFG11) Master Configuration Register 11 Offset */
#define MATRIX_MCFG12_REG_OFST         (0x30)              /**< (MATRIX_MCFG12) Master Configuration Register 12 Offset */
#define MATRIX_MCFG13_REG_OFST         (0x34)              /**< (MATRIX_MCFG13) Master Configuration Register 13 Offset */
#define MATRIX_MCFG14_REG_OFST         (0x38)              /**< (MATRIX_MCFG14) Master Configuration Register 14 Offset */
#define MATRIX_MCFG15_REG_OFST         (0x3C)              /**< (MATRIX_MCFG15) Master Configuration Register 15 Offset */
#define MATRIX_SCFG0_REG_OFST          (0x40)              /**< (MATRIX_SCFG0) Slave Configuration Register 0 Offset */
#define MATRIX_SCFG1_REG_OFST          (0x44)              /**< (MATRIX_SCFG1) Slave Configuration Register 1 Offset */
#define MATRIX_SCFG2_REG_OFST          (0x48)              /**< (MATRIX_SCFG2) Slave Configuration Register 2 Offset */
#define MATRIX_SCFG3_REG_OFST          (0x4C)              /**< (MATRIX_SCFG3) Slave Configuration Register 3 Offset */
#define MATRIX_SCFG4_REG_OFST          (0x50)              /**< (MATRIX_SCFG4) Slave Configuration Register 4 Offset */
#define MATRIX_SCFG5_REG_OFST          (0x54)              /**< (MATRIX_SCFG5) Slave Configuration Register 5 Offset */
#define MATRIX_SCFG6_REG_OFST          (0x58)              /**< (MATRIX_SCFG6) Slave Configuration Register 6 Offset */
#define MATRIX_SCFG7_REG_OFST          (0x5C)              /**< (MATRIX_SCFG7) Slave Configuration Register 7 Offset */
#define MATRIX_SCFG8_REG_OFST          (0x60)              /**< (MATRIX_SCFG8) Slave Configuration Register 8 Offset */
#define MATRIX_SCFG9_REG_OFST          (0x64)              /**< (MATRIX_SCFG9) Slave Configuration Register 9 Offset */
#define MATRIX_SCFG10_REG_OFST         (0x68)              /**< (MATRIX_SCFG10) Slave Configuration Register 10 Offset */
#define MATRIX_SCFG11_REG_OFST         (0x6C)              /**< (MATRIX_SCFG11) Slave Configuration Register 11 Offset */
#define MATRIX_SCFG12_REG_OFST         (0x70)              /**< (MATRIX_SCFG12) Slave Configuration Register 12 Offset */
#define MATRIX_SCFG13_REG_OFST         (0x74)              /**< (MATRIX_SCFG13) Slave Configuration Register 13 Offset */
#define MATRIX_SCFG14_REG_OFST         (0x78)              /**< (MATRIX_SCFG14) Slave Configuration Register 14 Offset */
#define MATRIX_SCFG15_REG_OFST         (0x7C)              /**< (MATRIX_SCFG15) Slave Configuration Register 15 Offset */
#define MATRIX_PRAS0_REG_OFST          (0x80)              /**< (MATRIX_PRAS0) Priority Register A for Slave 0 Offset */
#define MATRIX_PRBS0_REG_OFST          (0x84)              /**< (MATRIX_PRBS0) Priority Register B for Slave 0 Offset */
#define MATRIX_PRAS1_REG_OFST          (0x88)              /**< (MATRIX_PRAS1) Priority Register A for Slave 1 Offset */
#define MATRIX_PRBS1_REG_OFST          (0x8C)              /**< (MATRIX_PRBS1) Priority Register B for Slave 1 Offset */
#define MATRIX_PRAS2_REG_OFST          (0x90)              /**< (MATRIX_PRAS2) Priority Register A for Slave 2 Offset */
#define MATRIX_PRBS2_REG_OFST          (0x94)              /**< (MATRIX_PRBS2) Priority Register B for Slave 2 Offset */
#define MATRIX_PRAS3_REG_OFST          (0x98)              /**< (MATRIX_PRAS3) Priority Register A for Slave 3 Offset */
#define MATRIX_PRBS3_REG_OFST          (0x9C)              /**< (MATRIX_PRBS3) Priority Register B for Slave 3 Offset */
#define MATRIX_PRAS4_REG_OFST          (0xA0)              /**< (MATRIX_PRAS4) Priority Register A for Slave 4 Offset */
#define MATRIX_PRBS4_REG_OFST          (0xA4)              /**< (MATRIX_PRBS4) Priority Register B for Slave 4 Offset */
#define MATRIX_PRAS5_REG_OFST          (0xA8)              /**< (MATRIX_PRAS5) Priority Register A for Slave 5 Offset */
#define MATRIX_PRBS5_REG_OFST          (0xAC)              /**< (MATRIX_PRBS5) Priority Register B for Slave 5 Offset */
#define MATRIX_PRAS6_REG_OFST          (0xB0)              /**< (MATRIX_PRAS6) Priority Register A for Slave 6 Offset */
#define MATRIX_PRBS6_REG_OFST          (0xB4)              /**< (MATRIX_PRBS6) Priority Register B for Slave 6 Offset */
#define MATRIX_PRAS7_REG_OFST          (0xB8)              /**< (MATRIX_PRAS7) Priority Register A for Slave 7 Offset */
#define MATRIX_PRBS7_REG_OFST          (0xBC)              /**< (MATRIX_PRBS7) Priority Register B for Slave 7 Offset */
#define MATRIX_PRAS8_REG_OFST          (0xC0)              /**< (MATRIX_PRAS8) Priority Register A for Slave 8 Offset */
#define MATRIX_PRBS8_REG_OFST          (0xC4)              /**< (MATRIX_PRBS8) Priority Register B for Slave 8 Offset */
#define MATRIX_PRAS9_REG_OFST          (0xC8)              /**< (MATRIX_PRAS9) Priority Register A for Slave 9 Offset */
#define MATRIX_PRBS9_REG_OFST          (0xCC)              /**< (MATRIX_PRBS9) Priority Register B for Slave 9 Offset */
#define MATRIX_PRAS10_REG_OFST         (0xD0)              /**< (MATRIX_PRAS10) Priority Register A for Slave 10 Offset */
#define MATRIX_PRBS10_REG_OFST         (0xD4)              /**< (MATRIX_PRBS10) Priority Register B for Slave 10 Offset */
#define MATRIX_PRAS11_REG_OFST         (0xD8)              /**< (MATRIX_PRAS11) Priority Register A for Slave 11 Offset */
#define MATRIX_PRBS11_REG_OFST         (0xDC)              /**< (MATRIX_PRBS11) Priority Register B for Slave 11 Offset */
#define MATRIX_PRAS12_REG_OFST         (0xE0)              /**< (MATRIX_PRAS12) Priority Register A for Slave 12 Offset */
#define MATRIX_PRBS12_REG_OFST         (0xE4)              /**< (MATRIX_PRBS12) Priority Register B for Slave 12 Offset */
#define MATRIX_PRAS13_REG_OFST         (0xE8)              /**< (MATRIX_PRAS13) Priority Register A for Slave 13 Offset */
#define MATRIX_PRBS13_REG_OFST         (0xEC)              /**< (MATRIX_PRBS13) Priority Register B for Slave 13 Offset */
#define MATRIX_PRAS14_REG_OFST         (0xF0)              /**< (MATRIX_PRAS14) Priority Register A for Slave 14 Offset */
#define MATRIX_PRBS14_REG_OFST         (0xF4)              /**< (MATRIX_PRBS14) Priority Register B for Slave 14 Offset */
#define MATRIX_PRAS15_REG_OFST         (0xF8)              /**< (MATRIX_PRAS15) Priority Register A for Slave 15 Offset */
#define MATRIX_PRBS15_REG_OFST         (0xFC)              /**< (MATRIX_PRBS15) Priority Register B for Slave 15 Offset */
#define MATRIX_MRCR_REG_OFST           (0x100)             /**< (MATRIX_MRCR) Master Remap Control Register Offset */
#define MATRIX_MEIER_REG_OFST          (0x150)             /**< (MATRIX_MEIER) Master Error Interrupt Enable Register Offset */
#define MATRIX_MEIDR_REG_OFST          (0x154)             /**< (MATRIX_MEIDR) Master Error Interrupt Disable Register Offset */
#define MATRIX_MEIMR_REG_OFST          (0x158)             /**< (MATRIX_MEIMR) Master Error Interrupt Mask Register Offset */
#define MATRIX_MESR_REG_OFST           (0x15C)             /**< (MATRIX_MESR) Master Error Status Register Offset */
#define MATRIX_MEAR0_REG_OFST          (0x160)             /**< (MATRIX_MEAR0) Master 0 Error Address Register 0 Offset */
#define MATRIX_MEAR1_REG_OFST          (0x164)             /**< (MATRIX_MEAR1) Master 0 Error Address Register 1 Offset */
#define MATRIX_MEAR2_REG_OFST          (0x168)             /**< (MATRIX_MEAR2) Master 0 Error Address Register 2 Offset */
#define MATRIX_MEAR3_REG_OFST          (0x16C)             /**< (MATRIX_MEAR3) Master 0 Error Address Register 3 Offset */
#define MATRIX_MEAR4_REG_OFST          (0x170)             /**< (MATRIX_MEAR4) Master 0 Error Address Register 4 Offset */
#define MATRIX_MEAR5_REG_OFST          (0x174)             /**< (MATRIX_MEAR5) Master 0 Error Address Register 5 Offset */
#define MATRIX_MEAR6_REG_OFST          (0x178)             /**< (MATRIX_MEAR6) Master 0 Error Address Register 6 Offset */
#define MATRIX_MEAR7_REG_OFST          (0x17C)             /**< (MATRIX_MEAR7) Master 0 Error Address Register 7 Offset */
#define MATRIX_MEAR8_REG_OFST          (0x180)             /**< (MATRIX_MEAR8) Master 0 Error Address Register 8 Offset */
#define MATRIX_MEAR9_REG_OFST          (0x184)             /**< (MATRIX_MEAR9) Master 0 Error Address Register 9 Offset */
#define MATRIX_MEAR10_REG_OFST         (0x188)             /**< (MATRIX_MEAR10) Master 0 Error Address Register 10 Offset */
#define MATRIX_MEAR11_REG_OFST         (0x18C)             /**< (MATRIX_MEAR11) Master 0 Error Address Register 11 Offset */
#define MATRIX_MEAR12_REG_OFST         (0x190)             /**< (MATRIX_MEAR12) Master 0 Error Address Register 12 Offset */
#define MATRIX_MEAR13_REG_OFST         (0x194)             /**< (MATRIX_MEAR13) Master 0 Error Address Register 13 Offset */
#define MATRIX_MEAR14_REG_OFST         (0x198)             /**< (MATRIX_MEAR14) Master 0 Error Address Register 14 Offset */
#define MATRIX_MEAR15_REG_OFST         (0x19C)             /**< (MATRIX_MEAR15) Master 0 Error Address Register 15 Offset */
#define MATRIX_WPMR_REG_OFST           (0x1E4)             /**< (MATRIX_WPMR) Write Protect Mode Register Offset */
#define MATRIX_WPSR_REG_OFST           (0x1E8)             /**< (MATRIX_WPSR) Write Protect Status Register Offset */
#define MATRIX_PSR0_REG_OFST           (0x200)             /**< (MATRIX_PSR0) Protection Slave 0 Register 0 Offset */
#define MATRIX_PSR1_REG_OFST           (0x204)             /**< (MATRIX_PSR1) Protection Slave 0 Register 1 Offset */
#define MATRIX_PSR2_REG_OFST           (0x208)             /**< (MATRIX_PSR2) Protection Slave 0 Register 2 Offset */
#define MATRIX_PSR3_REG_OFST           (0x20C)             /**< (MATRIX_PSR3) Protection Slave 0 Register 3 Offset */
#define MATRIX_PSR4_REG_OFST           (0x210)             /**< (MATRIX_PSR4) Protection Slave 0 Register 4 Offset */
#define MATRIX_PSR5_REG_OFST           (0x214)             /**< (MATRIX_PSR5) Protection Slave 0 Register 5 Offset */
#define MATRIX_PSR6_REG_OFST           (0x218)             /**< (MATRIX_PSR6) Protection Slave 0 Register 6 Offset */
#define MATRIX_PSR7_REG_OFST           (0x21C)             /**< (MATRIX_PSR7) Protection Slave 0 Register 7 Offset */
#define MATRIX_PSR8_REG_OFST           (0x220)             /**< (MATRIX_PSR8) Protection Slave 0 Register 8 Offset */
#define MATRIX_PSR9_REG_OFST           (0x224)             /**< (MATRIX_PSR9) Protection Slave 0 Register 9 Offset */
#define MATRIX_PSR10_REG_OFST          (0x228)             /**< (MATRIX_PSR10) Protection Slave 0 Register 10 Offset */
#define MATRIX_PSR11_REG_OFST          (0x22C)             /**< (MATRIX_PSR11) Protection Slave 0 Register 11 Offset */
#define MATRIX_PSR12_REG_OFST          (0x230)             /**< (MATRIX_PSR12) Protection Slave 0 Register 12 Offset */
#define MATRIX_PSR13_REG_OFST          (0x234)             /**< (MATRIX_PSR13) Protection Slave 0 Register 13 Offset */
#define MATRIX_PSR14_REG_OFST          (0x238)             /**< (MATRIX_PSR14) Protection Slave 0 Register 14 Offset */
#define MATRIX_PSR15_REG_OFST          (0x23C)             /**< (MATRIX_PSR15) Protection Slave 0 Register 15 Offset */
#define MATRIX_PASSR0_REG_OFST         (0x240)             /**< (MATRIX_PASSR0) Protected Areas Split Slave 0 Register 0 Offset */
#define MATRIX_PASSR1_REG_OFST         (0x244)             /**< (MATRIX_PASSR1) Protected Areas Split Slave 0 Register 1 Offset */
#define MATRIX_PASSR2_REG_OFST         (0x248)             /**< (MATRIX_PASSR2) Protected Areas Split Slave 0 Register 2 Offset */
#define MATRIX_PASSR3_REG_OFST         (0x24C)             /**< (MATRIX_PASSR3) Protected Areas Split Slave 0 Register 3 Offset */
#define MATRIX_PASSR4_REG_OFST         (0x250)             /**< (MATRIX_PASSR4) Protected Areas Split Slave 0 Register 4 Offset */
#define MATRIX_PASSR5_REG_OFST         (0x254)             /**< (MATRIX_PASSR5) Protected Areas Split Slave 0 Register 5 Offset */
#define MATRIX_PASSR6_REG_OFST         (0x258)             /**< (MATRIX_PASSR6) Protected Areas Split Slave 0 Register 6 Offset */
#define MATRIX_PASSR7_REG_OFST         (0x25C)             /**< (MATRIX_PASSR7) Protected Areas Split Slave 0 Register 7 Offset */
#define MATRIX_PASSR8_REG_OFST         (0x260)             /**< (MATRIX_PASSR8) Protected Areas Split Slave 0 Register 8 Offset */
#define MATRIX_PASSR9_REG_OFST         (0x264)             /**< (MATRIX_PASSR9) Protected Areas Split Slave 0 Register 9 Offset */
#define MATRIX_PASSR10_REG_OFST        (0x268)             /**< (MATRIX_PASSR10) Protected Areas Split Slave 0 Register 10 Offset */
#define MATRIX_PASSR11_REG_OFST        (0x26C)             /**< (MATRIX_PASSR11) Protected Areas Split Slave 0 Register 11 Offset */
#define MATRIX_PASSR12_REG_OFST        (0x270)             /**< (MATRIX_PASSR12) Protected Areas Split Slave 0 Register 12 Offset */
#define MATRIX_PASSR13_REG_OFST        (0x274)             /**< (MATRIX_PASSR13) Protected Areas Split Slave 0 Register 13 Offset */
#define MATRIX_PASSR14_REG_OFST        (0x278)             /**< (MATRIX_PASSR14) Protected Areas Split Slave 0 Register 14 Offset */
#define MATRIX_PASSR15_REG_OFST        (0x27C)             /**< (MATRIX_PASSR15) Protected Areas Split Slave 0 Register 15 Offset */
#define MATRIX_PRTSR0_REG_OFST         (0x280)             /**< (MATRIX_PRTSR0) Protected Region Top Slave 0 Register 0 Offset */
#define MATRIX_PRTSR1_REG_OFST         (0x284)             /**< (MATRIX_PRTSR1) Protected Region Top Slave 0 Register 1 Offset */
#define MATRIX_PRTSR2_REG_OFST         (0x288)             /**< (MATRIX_PRTSR2) Protected Region Top Slave 0 Register 2 Offset */
#define MATRIX_PRTSR3_REG_OFST         (0x28C)             /**< (MATRIX_PRTSR3) Protected Region Top Slave 0 Register 3 Offset */
#define MATRIX_PRTSR4_REG_OFST         (0x290)             /**< (MATRIX_PRTSR4) Protected Region Top Slave 0 Register 4 Offset */
#define MATRIX_PRTSR5_REG_OFST         (0x294)             /**< (MATRIX_PRTSR5) Protected Region Top Slave 0 Register 5 Offset */
#define MATRIX_PRTSR6_REG_OFST         (0x298)             /**< (MATRIX_PRTSR6) Protected Region Top Slave 0 Register 6 Offset */
#define MATRIX_PRTSR7_REG_OFST         (0x29C)             /**< (MATRIX_PRTSR7) Protected Region Top Slave 0 Register 7 Offset */
#define MATRIX_PRTSR8_REG_OFST         (0x2A0)             /**< (MATRIX_PRTSR8) Protected Region Top Slave 0 Register 8 Offset */
#define MATRIX_PRTSR9_REG_OFST         (0x2A4)             /**< (MATRIX_PRTSR9) Protected Region Top Slave 0 Register 9 Offset */
#define MATRIX_PRTSR10_REG_OFST        (0x2A8)             /**< (MATRIX_PRTSR10) Protected Region Top Slave 0 Register 10 Offset */
#define MATRIX_PRTSR11_REG_OFST        (0x2AC)             /**< (MATRIX_PRTSR11) Protected Region Top Slave 0 Register 11 Offset */
#define MATRIX_PRTSR12_REG_OFST        (0x2B0)             /**< (MATRIX_PRTSR12) Protected Region Top Slave 0 Register 12 Offset */
#define MATRIX_PRTSR13_REG_OFST        (0x2B4)             /**< (MATRIX_PRTSR13) Protected Region Top Slave 0 Register 13 Offset */
#define MATRIX_PRTSR14_REG_OFST        (0x2B8)             /**< (MATRIX_PRTSR14) Protected Region Top Slave 0 Register 14 Offset */
#define MATRIX_PRTSR15_REG_OFST        (0x2BC)             /**< (MATRIX_PRTSR15) Protected Region Top Slave 0 Register 15 Offset */
#define MATRIX_PPSELR0_REG_OFST        (0x2C0)             /**< (MATRIX_PPSELR0) Protected Peripheral Select 1 Register 0 Offset */
#define MATRIX_PPSELR1_REG_OFST        (0x2C4)             /**< (MATRIX_PPSELR1) Protected Peripheral Select 1 Register 1 Offset */
#define MATRIX_PPSELR2_REG_OFST        (0x2C8)             /**< (MATRIX_PPSELR2) Protected Peripheral Select 1 Register 2 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief MATRIX register API structure */
typedef struct
{
  __IO  uint32_t                       MATRIX_MCFG0;       /**< Offset: 0x00 (R/W  32) Master Configuration Register 0 */
  __IO  uint32_t                       MATRIX_MCFG1;       /**< Offset: 0x04 (R/W  32) Master Configuration Register 1 */
  __IO  uint32_t                       MATRIX_MCFG2;       /**< Offset: 0x08 (R/W  32) Master Configuration Register 2 */
  __IO  uint32_t                       MATRIX_MCFG3;       /**< Offset: 0x0C (R/W  32) Master Configuration Register 3 */
  __IO  uint32_t                       MATRIX_MCFG4;       /**< Offset: 0x10 (R/W  32) Master Configuration Register 4 */
  __IO  uint32_t                       MATRIX_MCFG5;       /**< Offset: 0x14 (R/W  32) Master Configuration Register 5 */
  __IO  uint32_t                       MATRIX_MCFG6;       /**< Offset: 0x18 (R/W  32) Master Configuration Register 6 */
  __IO  uint32_t                       MATRIX_MCFG7;       /**< Offset: 0x1C (R/W  32) Master Configuration Register 7 */
  __IO  uint32_t                       MATRIX_MCFG8;       /**< Offset: 0x20 (R/W  32) Master Configuration Register 8 */
  __IO  uint32_t                       MATRIX_MCFG9;       /**< Offset: 0x24 (R/W  32) Master Configuration Register 9 */
  __IO  uint32_t                       MATRIX_MCFG10;      /**< Offset: 0x28 (R/W  32) Master Configuration Register 10 */
  __IO  uint32_t                       MATRIX_MCFG11;      /**< Offset: 0x2C (R/W  32) Master Configuration Register 11 */
  __IO  uint32_t                       MATRIX_MCFG12;      /**< Offset: 0x30 (R/W  32) Master Configuration Register 12 */
  __IO  uint32_t                       MATRIX_MCFG13;      /**< Offset: 0x34 (R/W  32) Master Configuration Register 13 */
  __IO  uint32_t                       MATRIX_MCFG14;      /**< Offset: 0x38 (R/W  32) Master Configuration Register 14 */
  __IO  uint32_t                       MATRIX_MCFG15;      /**< Offset: 0x3C (R/W  32) Master Configuration Register 15 */
  __IO  uint32_t                       MATRIX_SCFG0;       /**< Offset: 0x40 (R/W  32) Slave Configuration Register 0 */
  __IO  uint32_t                       MATRIX_SCFG1;       /**< Offset: 0x44 (R/W  32) Slave Configuration Register 1 */
  __IO  uint32_t                       MATRIX_SCFG2;       /**< Offset: 0x48 (R/W  32) Slave Configuration Register 2 */
  __IO  uint32_t                       MATRIX_SCFG3;       /**< Offset: 0x4C (R/W  32) Slave Configuration Register 3 */
  __IO  uint32_t                       MATRIX_SCFG4;       /**< Offset: 0x50 (R/W  32) Slave Configuration Register 4 */
  __IO  uint32_t                       MATRIX_SCFG5;       /**< Offset: 0x54 (R/W  32) Slave Configuration Register 5 */
  __IO  uint32_t                       MATRIX_SCFG6;       /**< Offset: 0x58 (R/W  32) Slave Configuration Register 6 */
  __IO  uint32_t                       MATRIX_SCFG7;       /**< Offset: 0x5C (R/W  32) Slave Configuration Register 7 */
  __IO  uint32_t                       MATRIX_SCFG8;       /**< Offset: 0x60 (R/W  32) Slave Configuration Register 8 */
  __IO  uint32_t                       MATRIX_SCFG9;       /**< Offset: 0x64 (R/W  32) Slave Configuration Register 9 */
  __IO  uint32_t                       MATRIX_SCFG10;      /**< Offset: 0x68 (R/W  32) Slave Configuration Register 10 */
  __IO  uint32_t                       MATRIX_SCFG11;      /**< Offset: 0x6C (R/W  32) Slave Configuration Register 11 */
  __IO  uint32_t                       MATRIX_SCFG12;      /**< Offset: 0x70 (R/W  32) Slave Configuration Register 12 */
  __IO  uint32_t                       MATRIX_SCFG13;      /**< Offset: 0x74 (R/W  32) Slave Configuration Register 13 */
  __IO  uint32_t                       MATRIX_SCFG14;      /**< Offset: 0x78 (R/W  32) Slave Configuration Register 14 */
  __IO  uint32_t                       MATRIX_SCFG15;      /**< Offset: 0x7C (R/W  32) Slave Configuration Register 15 */
  __IO  uint32_t                       MATRIX_PRAS0;       /**< Offset: 0x80 (R/W  32) Priority Register A for Slave 0 */
  __IO  uint32_t                       MATRIX_PRBS0;       /**< Offset: 0x84 (R/W  32) Priority Register B for Slave 0 */
  __IO  uint32_t                       MATRIX_PRAS1;       /**< Offset: 0x88 (R/W  32) Priority Register A for Slave 1 */
  __IO  uint32_t                       MATRIX_PRBS1;       /**< Offset: 0x8C (R/W  32) Priority Register B for Slave 1 */
  __IO  uint32_t                       MATRIX_PRAS2;       /**< Offset: 0x90 (R/W  32) Priority Register A for Slave 2 */
  __IO  uint32_t                       MATRIX_PRBS2;       /**< Offset: 0x94 (R/W  32) Priority Register B for Slave 2 */
  __IO  uint32_t                       MATRIX_PRAS3;       /**< Offset: 0x98 (R/W  32) Priority Register A for Slave 3 */
  __IO  uint32_t                       MATRIX_PRBS3;       /**< Offset: 0x9C (R/W  32) Priority Register B for Slave 3 */
  __IO  uint32_t                       MATRIX_PRAS4;       /**< Offset: 0xA0 (R/W  32) Priority Register A for Slave 4 */
  __IO  uint32_t                       MATRIX_PRBS4;       /**< Offset: 0xA4 (R/W  32) Priority Register B for Slave 4 */
  __IO  uint32_t                       MATRIX_PRAS5;       /**< Offset: 0xA8 (R/W  32) Priority Register A for Slave 5 */
  __IO  uint32_t                       MATRIX_PRBS5;       /**< Offset: 0xAC (R/W  32) Priority Register B for Slave 5 */
  __IO  uint32_t                       MATRIX_PRAS6;       /**< Offset: 0xB0 (R/W  32) Priority Register A for Slave 6 */
  __IO  uint32_t                       MATRIX_PRBS6;       /**< Offset: 0xB4 (R/W  32) Priority Register B for Slave 6 */
  __IO  uint32_t                       MATRIX_PRAS7;       /**< Offset: 0xB8 (R/W  32) Priority Register A for Slave 7 */
  __IO  uint32_t                       MATRIX_PRBS7;       /**< Offset: 0xBC (R/W  32) Priority Register B for Slave 7 */
  __IO  uint32_t                       MATRIX_PRAS8;       /**< Offset: 0xC0 (R/W  32) Priority Register A for Slave 8 */
  __IO  uint32_t                       MATRIX_PRBS8;       /**< Offset: 0xC4 (R/W  32) Priority Register B for Slave 8 */
  __IO  uint32_t                       MATRIX_PRAS9;       /**< Offset: 0xC8 (R/W  32) Priority Register A for Slave 9 */
  __IO  uint32_t                       MATRIX_PRBS9;       /**< Offset: 0xCC (R/W  32) Priority Register B for Slave 9 */
  __IO  uint32_t                       MATRIX_PRAS10;      /**< Offset: 0xD0 (R/W  32) Priority Register A for Slave 10 */
  __IO  uint32_t                       MATRIX_PRBS10;      /**< Offset: 0xD4 (R/W  32) Priority Register B for Slave 10 */
  __IO  uint32_t                       MATRIX_PRAS11;      /**< Offset: 0xD8 (R/W  32) Priority Register A for Slave 11 */
  __IO  uint32_t                       MATRIX_PRBS11;      /**< Offset: 0xDC (R/W  32) Priority Register B for Slave 11 */
  __IO  uint32_t                       MATRIX_PRAS12;      /**< Offset: 0xE0 (R/W  32) Priority Register A for Slave 12 */
  __IO  uint32_t                       MATRIX_PRBS12;      /**< Offset: 0xE4 (R/W  32) Priority Register B for Slave 12 */
  __IO  uint32_t                       MATRIX_PRAS13;      /**< Offset: 0xE8 (R/W  32) Priority Register A for Slave 13 */
  __IO  uint32_t                       MATRIX_PRBS13;      /**< Offset: 0xEC (R/W  32) Priority Register B for Slave 13 */
  __IO  uint32_t                       MATRIX_PRAS14;      /**< Offset: 0xF0 (R/W  32) Priority Register A for Slave 14 */
  __IO  uint32_t                       MATRIX_PRBS14;      /**< Offset: 0xF4 (R/W  32) Priority Register B for Slave 14 */
  __IO  uint32_t                       MATRIX_PRAS15;      /**< Offset: 0xF8 (R/W  32) Priority Register A for Slave 15 */
  __IO  uint32_t                       MATRIX_PRBS15;      /**< Offset: 0xFC (R/W  32) Priority Register B for Slave 15 */
  __IO  uint32_t                       MATRIX_MRCR;        /**< Offset: 0x100 (R/W  32) Master Remap Control Register */
  __I   uint8_t                        Reserved1[0x4C];
  __O   uint32_t                       MATRIX_MEIER;       /**< Offset: 0x150 ( /W  32) Master Error Interrupt Enable Register */
  __O   uint32_t                       MATRIX_MEIDR;       /**< Offset: 0x154 ( /W  32) Master Error Interrupt Disable Register */
  __I   uint32_t                       MATRIX_MEIMR;       /**< Offset: 0x158 (R/   32) Master Error Interrupt Mask Register */
  __I   uint32_t                       MATRIX_MESR;        /**< Offset: 0x15C (R/   32) Master Error Status Register */
  __I   uint32_t                       MATRIX_MEAR0;       /**< Offset: 0x160 (R/   32) Master 0 Error Address Register 0 */
  __I   uint32_t                       MATRIX_MEAR1;       /**< Offset: 0x164 (R/   32) Master 0 Error Address Register 1 */
  __I   uint32_t                       MATRIX_MEAR2;       /**< Offset: 0x168 (R/   32) Master 0 Error Address Register 2 */
  __I   uint32_t                       MATRIX_MEAR3;       /**< Offset: 0x16C (R/   32) Master 0 Error Address Register 3 */
  __I   uint32_t                       MATRIX_MEAR4;       /**< Offset: 0x170 (R/   32) Master 0 Error Address Register 4 */
  __I   uint32_t                       MATRIX_MEAR5;       /**< Offset: 0x174 (R/   32) Master 0 Error Address Register 5 */
  __I   uint32_t                       MATRIX_MEAR6;       /**< Offset: 0x178 (R/   32) Master 0 Error Address Register 6 */
  __I   uint32_t                       MATRIX_MEAR7;       /**< Offset: 0x17C (R/   32) Master 0 Error Address Register 7 */
  __I   uint32_t                       MATRIX_MEAR8;       /**< Offset: 0x180 (R/   32) Master 0 Error Address Register 8 */
  __I   uint32_t                       MATRIX_MEAR9;       /**< Offset: 0x184 (R/   32) Master 0 Error Address Register 9 */
  __I   uint32_t                       MATRIX_MEAR10;      /**< Offset: 0x188 (R/   32) Master 0 Error Address Register 10 */
  __I   uint32_t                       MATRIX_MEAR11;      /**< Offset: 0x18C (R/   32) Master 0 Error Address Register 11 */
  __I   uint32_t                       MATRIX_MEAR12;      /**< Offset: 0x190 (R/   32) Master 0 Error Address Register 12 */
  __I   uint32_t                       MATRIX_MEAR13;      /**< Offset: 0x194 (R/   32) Master 0 Error Address Register 13 */
  __I   uint32_t                       MATRIX_MEAR14;      /**< Offset: 0x198 (R/   32) Master 0 Error Address Register 14 */
  __I   uint32_t                       MATRIX_MEAR15;      /**< Offset: 0x19C (R/   32) Master 0 Error Address Register 15 */
  __I   uint8_t                        Reserved2[0x44];
  __IO  uint32_t                       MATRIX_WPMR;        /**< Offset: 0x1E4 (R/W  32) Write Protect Mode Register */
  __I   uint32_t                       MATRIX_WPSR;        /**< Offset: 0x1E8 (R/   32) Write Protect Status Register */
  __I   uint8_t                        Reserved3[0x14];
  __IO  uint32_t                       MATRIX_PSR0;        /**< Offset: 0x200 (R/W  32) Protection Slave 0 Register 0 */
  __IO  uint32_t                       MATRIX_PSR1;        /**< Offset: 0x204 (R/W  32) Protection Slave 0 Register 1 */
  __IO  uint32_t                       MATRIX_PSR2;        /**< Offset: 0x208 (R/W  32) Protection Slave 0 Register 2 */
  __IO  uint32_t                       MATRIX_PSR3;        /**< Offset: 0x20C (R/W  32) Protection Slave 0 Register 3 */
  __IO  uint32_t                       MATRIX_PSR4;        /**< Offset: 0x210 (R/W  32) Protection Slave 0 Register 4 */
  __IO  uint32_t                       MATRIX_PSR5;        /**< Offset: 0x214 (R/W  32) Protection Slave 0 Register 5 */
  __IO  uint32_t                       MATRIX_PSR6;        /**< Offset: 0x218 (R/W  32) Protection Slave 0 Register 6 */
  __IO  uint32_t                       MATRIX_PSR7;        /**< Offset: 0x21C (R/W  32) Protection Slave 0 Register 7 */
  __IO  uint32_t                       MATRIX_PSR8;        /**< Offset: 0x220 (R/W  32) Protection Slave 0 Register 8 */
  __IO  uint32_t                       MATRIX_PSR9;        /**< Offset: 0x224 (R/W  32) Protection Slave 0 Register 9 */
  __IO  uint32_t                       MATRIX_PSR10;       /**< Offset: 0x228 (R/W  32) Protection Slave 0 Register 10 */
  __IO  uint32_t                       MATRIX_PSR11;       /**< Offset: 0x22C (R/W  32) Protection Slave 0 Register 11 */
  __IO  uint32_t                       MATRIX_PSR12;       /**< Offset: 0x230 (R/W  32) Protection Slave 0 Register 12 */
  __IO  uint32_t                       MATRIX_PSR13;       /**< Offset: 0x234 (R/W  32) Protection Slave 0 Register 13 */
  __IO  uint32_t                       MATRIX_PSR14;       /**< Offset: 0x238 (R/W  32) Protection Slave 0 Register 14 */
  __IO  uint32_t                       MATRIX_PSR15;       /**< Offset: 0x23C (R/W  32) Protection Slave 0 Register 15 */
  __IO  uint32_t                       MATRIX_PASSR0;      /**< Offset: 0x240 (R/W  32) Protected Areas Split Slave 0 Register 0 */
  __IO  uint32_t                       MATRIX_PASSR1;      /**< Offset: 0x244 (R/W  32) Protected Areas Split Slave 0 Register 1 */
  __IO  uint32_t                       MATRIX_PASSR2;      /**< Offset: 0x248 (R/W  32) Protected Areas Split Slave 0 Register 2 */
  __IO  uint32_t                       MATRIX_PASSR3;      /**< Offset: 0x24C (R/W  32) Protected Areas Split Slave 0 Register 3 */
  __IO  uint32_t                       MATRIX_PASSR4;      /**< Offset: 0x250 (R/W  32) Protected Areas Split Slave 0 Register 4 */
  __IO  uint32_t                       MATRIX_PASSR5;      /**< Offset: 0x254 (R/W  32) Protected Areas Split Slave 0 Register 5 */
  __IO  uint32_t                       MATRIX_PASSR6;      /**< Offset: 0x258 (R/W  32) Protected Areas Split Slave 0 Register 6 */
  __IO  uint32_t                       MATRIX_PASSR7;      /**< Offset: 0x25C (R/W  32) Protected Areas Split Slave 0 Register 7 */
  __IO  uint32_t                       MATRIX_PASSR8;      /**< Offset: 0x260 (R/W  32) Protected Areas Split Slave 0 Register 8 */
  __IO  uint32_t                       MATRIX_PASSR9;      /**< Offset: 0x264 (R/W  32) Protected Areas Split Slave 0 Register 9 */
  __IO  uint32_t                       MATRIX_PASSR10;     /**< Offset: 0x268 (R/W  32) Protected Areas Split Slave 0 Register 10 */
  __IO  uint32_t                       MATRIX_PASSR11;     /**< Offset: 0x26C (R/W  32) Protected Areas Split Slave 0 Register 11 */
  __IO  uint32_t                       MATRIX_PASSR12;     /**< Offset: 0x270 (R/W  32) Protected Areas Split Slave 0 Register 12 */
  __IO  uint32_t                       MATRIX_PASSR13;     /**< Offset: 0x274 (R/W  32) Protected Areas Split Slave 0 Register 13 */
  __IO  uint32_t                       MATRIX_PASSR14;     /**< Offset: 0x278 (R/W  32) Protected Areas Split Slave 0 Register 14 */
  __IO  uint32_t                       MATRIX_PASSR15;     /**< Offset: 0x27C (R/W  32) Protected Areas Split Slave 0 Register 15 */
  __IO  uint32_t                       MATRIX_PRTSR0;      /**< Offset: 0x280 (R/W  32) Protected Region Top Slave 0 Register 0 */
  __IO  uint32_t                       MATRIX_PRTSR1;      /**< Offset: 0x284 (R/W  32) Protected Region Top Slave 0 Register 1 */
  __IO  uint32_t                       MATRIX_PRTSR2;      /**< Offset: 0x288 (R/W  32) Protected Region Top Slave 0 Register 2 */
  __IO  uint32_t                       MATRIX_PRTSR3;      /**< Offset: 0x28C (R/W  32) Protected Region Top Slave 0 Register 3 */
  __IO  uint32_t                       MATRIX_PRTSR4;      /**< Offset: 0x290 (R/W  32) Protected Region Top Slave 0 Register 4 */
  __IO  uint32_t                       MATRIX_PRTSR5;      /**< Offset: 0x294 (R/W  32) Protected Region Top Slave 0 Register 5 */
  __IO  uint32_t                       MATRIX_PRTSR6;      /**< Offset: 0x298 (R/W  32) Protected Region Top Slave 0 Register 6 */
  __IO  uint32_t                       MATRIX_PRTSR7;      /**< Offset: 0x29C (R/W  32) Protected Region Top Slave 0 Register 7 */
  __IO  uint32_t                       MATRIX_PRTSR8;      /**< Offset: 0x2A0 (R/W  32) Protected Region Top Slave 0 Register 8 */
  __IO  uint32_t                       MATRIX_PRTSR9;      /**< Offset: 0x2A4 (R/W  32) Protected Region Top Slave 0 Register 9 */
  __IO  uint32_t                       MATRIX_PRTSR10;     /**< Offset: 0x2A8 (R/W  32) Protected Region Top Slave 0 Register 10 */
  __IO  uint32_t                       MATRIX_PRTSR11;     /**< Offset: 0x2AC (R/W  32) Protected Region Top Slave 0 Register 11 */
  __IO  uint32_t                       MATRIX_PRTSR12;     /**< Offset: 0x2B0 (R/W  32) Protected Region Top Slave 0 Register 12 */
  __IO  uint32_t                       MATRIX_PRTSR13;     /**< Offset: 0x2B4 (R/W  32) Protected Region Top Slave 0 Register 13 */
  __IO  uint32_t                       MATRIX_PRTSR14;     /**< Offset: 0x2B8 (R/W  32) Protected Region Top Slave 0 Register 14 */
  __IO  uint32_t                       MATRIX_PRTSR15;     /**< Offset: 0x2BC (R/W  32) Protected Region Top Slave 0 Register 15 */
  __IO  uint32_t                       MATRIX_PPSELR0;     /**< Offset: 0x2C0 (R/W  32) Protected Peripheral Select 1 Register 0 */
  __IO  uint32_t                       MATRIX_PPSELR1;     /**< Offset: 0x2C4 (R/W  32) Protected Peripheral Select 1 Register 1 */
  __IO  uint32_t                       MATRIX_PPSELR2;     /**< Offset: 0x2C8 (R/W  32) Protected Peripheral Select 1 Register 2 */
} matrix_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMRH71_MATRIX_COMPONENT_H_ */
