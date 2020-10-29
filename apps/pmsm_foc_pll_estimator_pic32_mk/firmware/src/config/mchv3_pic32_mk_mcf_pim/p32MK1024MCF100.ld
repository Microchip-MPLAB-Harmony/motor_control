/*--------------------------------------------------------------------------
 * MPLAB XC Compiler -  PIC32MK1024MCF100 linker script
 * Build date : Aug 19 2020
 * 
 * Copyright (c) 2020, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 * 
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above 
 *         copyright notice, this list of conditions and the following 
 *         disclaimer in the documentation and/or other materials provided 
 *         with the distribution. Publication is not required when this file 
 *         is used in an embedded application.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written 
 *         permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

/* Default linker script, for normal executables */

/*  NOTE: This single-file linker script replaces the two-file system used
 *  for older PIC32 devices. 
 */

OUTPUT_FORMAT("elf32-tradlittlemips")
OUTPUT_ARCH(pic32mx)
ENTRY(_reset)
/*
 * Provide for a minimum stack and heap size
 * - _min_stack_size - represents the minimum space that must be made
 *                     available for the stack.  Can be overridden from
 *                     the command line using the linker's --defsym option.
 * - _min_heap_size  - represents the minimum space that must be made
 *                     available for the heap.  Must be specified on
 *                     the command line using the linker's --defsym option.
 */
EXTERN (_min_stack_size _min_heap_size)
PROVIDE(_min_stack_size = 0x400) ;

/*************************************************************************
 * Legacy processor-specific object file.  Contains SFR definitions.
 * The SFR definitions are now provided in a processor-specific *.S
 * assembly source file rather than the processor.o file. Use the new
 * .S file rather than this processor.o file for new projects. MPLAB XC32
 * v2.10 and later will automatically link the new .S file.
 *************************************************************************/
#if defined(__XC32_VERSION__) && (__XC32_VERSION__ < 2100)
OPTIONAL("processor.o")
#endif

/*************************************************************************
 * Vector-offset initialization
 *************************************************************************/
OPTIONAL("vector_offset_init.o")

/*************************************************************************
 * Symbols used for interrupt-vector table generation
 * To override the defaults, define the _ebase_address symbol using
 * the --defsym linker opt as shown in this example:
 *   xc32-gcc src.c -Wl,--defsym=_ebase_address=0x9D001000
 *************************************************************************/
PROVIDE(_vector_spacing = 0x0001);
PROVIDE(_ebase_address = 0x9D000000);

/*************************************************************************
 * Memory Address Equates
 * _RESET_ADDR                    -- Reset Vector or entry point
 * _BEV_EXCPT_ADDR                -- Boot exception Vector
 * _DBG_EXCPT_ADDR                -- In-circuit Debugging Exception Vector
 * _SIMPLE_TLB_REFILL_EXCPT_ADDR  -- Simple TLB-Refill Exception Vector
 * _GEN_EXCPT_ADDR                -- General Exception Vector
 *************************************************************************/
_RESET_ADDR                    = 0xBFC00000;
_BEV_EXCPT_ADDR                = 0xBFC00380;
_DBG_EXCPT_ADDR                = 0xBFC00480;
_SIMPLE_TLB_REFILL_EXCPT_ADDR  = _ebase_address + 0;
_GEN_EXCPT_ADDR                = _ebase_address + 0x180;

/*************************************************************************
 * Memory Regions
 *
 * Memory regions without attributes cannot be used for orphaned sections.
 * Only sections specifically assigned to these regions can be allocated
 * into these regions.
 *
 * The Debug exception vector is located at 0x9FC00480.
 *
 * The config_<address> sections are used to locate the config words at
 * their absolute addresses.
 *************************************************************************/


MEMORY
{
  kseg0_program_mem     (rx)  : ORIGIN = 0x9D000000, LENGTH = 0x100000
  kseg0_boot_mem              : ORIGIN = 0x9FC004B0, LENGTH = 0x0
  debug_exec_mem              : ORIGIN = 0x9FC20490, LENGTH = 0x3B20
  kseg0_boot_mem              : ORIGIN = 0x9FC20490, LENGTH = 0x0
  kseg1_boot_mem              : ORIGIN = 0xBFC00000, LENGTH = 0x480
  kseg1_boot_mem_4B0          : ORIGIN = 0xBFC004B0, LENGTH = 0x3B00
  config_BFC03FC0             : ORIGIN = 0xBFC03FC0, LENGTH = 0x4
  config_BFC03FC4             : ORIGIN = 0xBFC03FC4, LENGTH = 0x4
  config_BFC03FC8             : ORIGIN = 0xBFC03FC8, LENGTH = 0x4
  config_BFC03FCC             : ORIGIN = 0xBFC03FCC, LENGTH = 0x4
  config_BFC03FDC             : ORIGIN = 0xBFC03FDC, LENGTH = 0x4
  config_BFC03FEC             : ORIGIN = 0xBFC03FEC, LENGTH = 0x4
  config_BFC03FF0             : ORIGIN = 0xBFC03FF0, LENGTH = 0x4
  lowerbootaliaslastpage      : ORIGIN = 0xBFC04000, LENGTH = 0x1000
  upperbootalias              : ORIGIN = 0xBFC20000, LENGTH = 0x3FB0
  config_BFC23FC0             : ORIGIN = 0xBFC23FC0, LENGTH = 0x4
  config_BFC23FC4             : ORIGIN = 0xBFC23FC4, LENGTH = 0x4
  config_BFC23FC8             : ORIGIN = 0xBFC23FC8, LENGTH = 0x4
  config_BFC23FCC             : ORIGIN = 0xBFC23FCC, LENGTH = 0x4
  config_BFC23FDC             : ORIGIN = 0xBFC23FDC, LENGTH = 0x4
  config_BFC23FEC             : ORIGIN = 0xBFC23FEC, LENGTH = 0x4
  config_BFC23FF0             : ORIGIN = 0xBFC23FF0, LENGTH = 0x4
  upperbootaliaslastpage      : ORIGIN = 0xBFC24000, LENGTH = 0x1000
  boot1                       : ORIGIN = 0xBFC40000, LENGTH = 0x3FB0
  config_BFC43FC0             : ORIGIN = 0xBFC43FC0, LENGTH = 0x4
  config_BFC43FC4             : ORIGIN = 0xBFC43FC4, LENGTH = 0x4
  config_BFC43FC8             : ORIGIN = 0xBFC43FC8, LENGTH = 0x4
  config_BFC43FCC             : ORIGIN = 0xBFC43FCC, LENGTH = 0x4
  config_BFC43FDC             : ORIGIN = 0xBFC43FDC, LENGTH = 0x4
  config_BFC43FEC             : ORIGIN = 0xBFC43FEC, LENGTH = 0x4
  config_BFC43FF0             : ORIGIN = 0xBFC43FF0, LENGTH = 0x4
  boot1lastpage               : ORIGIN = 0xBFC44000, LENGTH = 0x1000
  config_BFC45000             : ORIGIN = 0xBFC45000, LENGTH = 0x4
  config_BFC45004             : ORIGIN = 0xBFC45004, LENGTH = 0x4
  config_BFC45008             : ORIGIN = 0xBFC45008, LENGTH = 0x4
  config_BFC4500C             : ORIGIN = 0xBFC4500C, LENGTH = 0x4
  config_BFC45010             : ORIGIN = 0xBFC45010, LENGTH = 0x4
  config_BFC45014             : ORIGIN = 0xBFC45014, LENGTH = 0x4
  config_BFC45018             : ORIGIN = 0xBFC45018, LENGTH = 0x4
  config_BFC45020             : ORIGIN = 0xBFC45020, LENGTH = 0x4
  config_BFC45024             : ORIGIN = 0xBFC45024, LENGTH = 0x4
  config_BFC45028             : ORIGIN = 0xBFC45028, LENGTH = 0x4
  config_BFC4502C             : ORIGIN = 0xBFC4502C, LENGTH = 0x4
  config_BFC45030             : ORIGIN = 0xBFC45030, LENGTH = 0x4
  config_BFC45034             : ORIGIN = 0xBFC45034, LENGTH = 0x4
  config_BFC45038             : ORIGIN = 0xBFC45038, LENGTH = 0x4
  config_BFC4503C             : ORIGIN = 0xBFC4503C, LENGTH = 0x4
  boot2                       : ORIGIN = 0xBFC60000, LENGTH = 0x3FB0
  config_BFC63FC0             : ORIGIN = 0xBFC63FC0, LENGTH = 0x4
  config_BFC63FC4             : ORIGIN = 0xBFC63FC4, LENGTH = 0x4
  config_BFC63FC8             : ORIGIN = 0xBFC63FC8, LENGTH = 0x4
  config_BFC63FCC             : ORIGIN = 0xBFC63FCC, LENGTH = 0x4
  config_BFC63FDC             : ORIGIN = 0xBFC63FDC, LENGTH = 0x4
  config_BFC63FEC             : ORIGIN = 0xBFC63FEC, LENGTH = 0x4
  config_BFC63FF0             : ORIGIN = 0xBFC63FF0, LENGTH = 0x4
  boot2lastpage               : ORIGIN = 0xBFC64000, LENGTH = 0x1000
  kseg0_data_mem       (w!x)  : ORIGIN = 0x80000000, LENGTH = 0x40000
  sfrs                        : ORIGIN = 0xBF800000, LENGTH = 0x100000
  configsfrs_BFC03FB0         : ORIGIN = 0xBFC03FB0, LENGTH = 0x1C
  configsfrs_BFC23FB0         : ORIGIN = 0xBFC23FB0, LENGTH = 0x1C
  configsfrs_BFC43FB0         : ORIGIN = 0xBFC43FB0, LENGTH = 0x1C
  configsfrs_BFC45000         : ORIGIN = 0xBFC45000, LENGTH = 0x1C
  configsfrs_BFC45020         : ORIGIN = 0xBFC45020, LENGTH = 0x10
  configsfrs_BFC45030         : ORIGIN = 0xBFC45030, LENGTH = 0x10
  configsfrs_BFC63FB0         : ORIGIN = 0xBFC63FB0, LENGTH = 0x1C
}

/*************************************************************************
 * Configuration-word sections. Map the config-pragma input sections to
 * absolute-address output sections.
 *************************************************************************/
SECTIONS
{
  .config_BFC03FC0 : {
    KEEP(*(.config_BFC03FC0))
  } > config_BFC03FC0
  .config_BFC03FC4 : {
    KEEP(*(.config_BFC03FC4))
  } > config_BFC03FC4
  .config_BFC03FC8 : {
    KEEP(*(.config_BFC03FC8))
  } > config_BFC03FC8
  .config_BFC03FCC : {
    KEEP(*(.config_BFC03FCC))
  } > config_BFC03FCC
  .config_BFC03FDC : {
    KEEP(*(.config_BFC03FDC))
  } > config_BFC03FDC
  .config_BFC03FEC : {
    KEEP(*(.config_BFC03FEC))
  } > config_BFC03FEC
  .config_BFC03FF0 : {
    KEEP(*(.config_BFC03FF0))
  } > config_BFC03FF0
  .config_BFC23FC0 : {
    KEEP(*(.config_BFC23FC0))
  } > config_BFC23FC0
  .config_BFC23FC4 : {
    KEEP(*(.config_BFC23FC4))
  } > config_BFC23FC4
  .config_BFC23FC8 : {
    KEEP(*(.config_BFC23FC8))
  } > config_BFC23FC8
  .config_BFC23FCC : {
    KEEP(*(.config_BFC23FCC))
  } > config_BFC23FCC
  .config_BFC23FDC : {
    KEEP(*(.config_BFC23FDC))
  } > config_BFC23FDC
  .config_BFC23FEC : {
    KEEP(*(.config_BFC23FEC))
  } > config_BFC23FEC
  .config_BFC23FF0 : {
    KEEP(*(.config_BFC23FF0))
  } > config_BFC23FF0
  .config_BFC43FC0 : {
    KEEP(*(.config_BFC43FC0))
  } > config_BFC43FC0
  .config_BFC43FC4 : {
    KEEP(*(.config_BFC43FC4))
  } > config_BFC43FC4
  .config_BFC43FC8 : {
    KEEP(*(.config_BFC43FC8))
  } > config_BFC43FC8
  .config_BFC43FCC : {
    KEEP(*(.config_BFC43FCC))
  } > config_BFC43FCC
  .config_BFC43FDC : {
    KEEP(*(.config_BFC43FDC))
  } > config_BFC43FDC
  .config_BFC43FEC : {
    KEEP(*(.config_BFC43FEC))
  } > config_BFC43FEC
  .config_BFC43FF0 : {
    KEEP(*(.config_BFC43FF0))
  } > config_BFC43FF0
  .config_BFC45000 : {
    KEEP(*(.config_BFC45000))
  } > config_BFC45000
  .config_BFC45004 : {
    KEEP(*(.config_BFC45004))
  } > config_BFC45004
  .config_BFC45008 : {
    KEEP(*(.config_BFC45008))
  } > config_BFC45008
  .config_BFC4500C : {
    KEEP(*(.config_BFC4500C))
  } > config_BFC4500C
  .config_BFC45010 : {
    KEEP(*(.config_BFC45010))
  } > config_BFC45010
  .config_BFC45014 : {
    KEEP(*(.config_BFC45014))
  } > config_BFC45014
  .config_BFC45018 : {
    KEEP(*(.config_BFC45018))
  } > config_BFC45018
  .config_BFC45020 : {
    KEEP(*(.config_BFC45020))
  } > config_BFC45020
  .config_BFC45024 : {
    KEEP(*(.config_BFC45024))
  } > config_BFC45024
  .config_BFC45028 : {
    KEEP(*(.config_BFC45028))
  } > config_BFC45028
  .config_BFC4502C : {
    KEEP(*(.config_BFC4502C))
  } > config_BFC4502C
  .config_BFC45030 : {
    KEEP(*(.config_BFC45030))
  } > config_BFC45030
  .config_BFC45034 : {
    KEEP(*(.config_BFC45034))
  } > config_BFC45034
  .config_BFC45038 : {
    KEEP(*(.config_BFC45038))
  } > config_BFC45038
  .config_BFC4503C : {
    KEEP(*(.config_BFC4503C))
  } > config_BFC4503C
  .config_BFC63FC0 : {
    KEEP(*(.config_BFC63FC0))
  } > config_BFC63FC0
  .config_BFC63FC4 : {
    KEEP(*(.config_BFC63FC4))
  } > config_BFC63FC4
  .config_BFC63FC8 : {
    KEEP(*(.config_BFC63FC8))
  } > config_BFC63FC8
  .config_BFC63FCC : {
    KEEP(*(.config_BFC63FCC))
  } > config_BFC63FCC
  .config_BFC63FDC : {
    KEEP(*(.config_BFC63FDC))
  } > config_BFC63FDC
  .config_BFC63FEC : {
    KEEP(*(.config_BFC63FEC))
  } > config_BFC63FEC
  .config_BFC63FF0 : {
    KEEP(*(.config_BFC63FF0))
  } > config_BFC63FF0
}
SECTIONS
{
  /* Boot Sections */
  .reset _RESET_ADDR :
  {
    KEEP(*(.reset))
    KEEP(*(.reset.startup))
  } > kseg1_boot_mem
  .bev_excpt _BEV_EXCPT_ADDR :
  {
    KEEP(*(.bev_handler))
  } > kseg1_boot_mem

  .app_excpt _GEN_EXCPT_ADDR :
  {
    KEEP(*(.gen_handler))
  } > kseg0_program_mem

  /* Interrupt vector table with vector offsets */
  .vectors _ebase_address + 0x200 :
  {
    /*  Symbol __vector_offset_n points to .vector_n if it exists, 
     *  otherwise points to the default handler. The
     *  vector_offset_init.o module then provides a .data section
     *  containing values used to initialize the vector-offset SFRs
     *  in the crt0 startup code.
     */
    . = ALIGN(4) ;
    __vector_offset_0 = (DEFINED(__vector_dispatch_0) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_0))
    . = ALIGN(4) ;
    __vector_offset_1 = (DEFINED(__vector_dispatch_1) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_1))
    . = ALIGN(4) ;
    __vector_offset_2 = (DEFINED(__vector_dispatch_2) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_2))
    . = ALIGN(4) ;
    __vector_offset_3 = (DEFINED(__vector_dispatch_3) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_3))
    . = ALIGN(4) ;
    __vector_offset_4 = (DEFINED(__vector_dispatch_4) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_4))
    . = ALIGN(4) ;
    __vector_offset_5 = (DEFINED(__vector_dispatch_5) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_5))
    . = ALIGN(4) ;
    __vector_offset_6 = (DEFINED(__vector_dispatch_6) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_6))
    . = ALIGN(4) ;
    __vector_offset_7 = (DEFINED(__vector_dispatch_7) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_7))
    . = ALIGN(4) ;
    __vector_offset_8 = (DEFINED(__vector_dispatch_8) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_8))
    . = ALIGN(4) ;
    __vector_offset_9 = (DEFINED(__vector_dispatch_9) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_9))
    . = ALIGN(4) ;
    __vector_offset_10 = (DEFINED(__vector_dispatch_10) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_10))
    . = ALIGN(4) ;
    __vector_offset_11 = (DEFINED(__vector_dispatch_11) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_11))
    . = ALIGN(4) ;
    __vector_offset_12 = (DEFINED(__vector_dispatch_12) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_12))
    . = ALIGN(4) ;
    __vector_offset_13 = (DEFINED(__vector_dispatch_13) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_13))
    . = ALIGN(4) ;
    __vector_offset_14 = (DEFINED(__vector_dispatch_14) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_14))
    . = ALIGN(4) ;
    __vector_offset_15 = (DEFINED(__vector_dispatch_15) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_15))
    . = ALIGN(4) ;
    __vector_offset_16 = (DEFINED(__vector_dispatch_16) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_16))
    . = ALIGN(4) ;
    __vector_offset_17 = (DEFINED(__vector_dispatch_17) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_17))
    . = ALIGN(4) ;
    __vector_offset_18 = (DEFINED(__vector_dispatch_18) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_18))
    . = ALIGN(4) ;
    __vector_offset_19 = (DEFINED(__vector_dispatch_19) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_19))
    . = ALIGN(4) ;
    __vector_offset_20 = (DEFINED(__vector_dispatch_20) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_20))
    . = ALIGN(4) ;
    __vector_offset_21 = (DEFINED(__vector_dispatch_21) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_21))
    . = ALIGN(4) ;
    __vector_offset_22 = (DEFINED(__vector_dispatch_22) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_22))
    . = ALIGN(4) ;
    __vector_offset_23 = (DEFINED(__vector_dispatch_23) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_23))
    . = ALIGN(4) ;
    __vector_offset_24 = (DEFINED(__vector_dispatch_24) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_24))
    . = ALIGN(4) ;
    __vector_offset_25 = (DEFINED(__vector_dispatch_25) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_25))
    . = ALIGN(4) ;
    __vector_offset_26 = (DEFINED(__vector_dispatch_26) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_26))
    . = ALIGN(4) ;
    __vector_offset_27 = (DEFINED(__vector_dispatch_27) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_27))
    . = ALIGN(4) ;
    __vector_offset_28 = (DEFINED(__vector_dispatch_28) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_28))
    . = ALIGN(4) ;
    __vector_offset_29 = (DEFINED(__vector_dispatch_29) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_29))
    . = ALIGN(4) ;
    __vector_offset_30 = (DEFINED(__vector_dispatch_30) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_30))
    . = ALIGN(4) ;
    __vector_offset_31 = (DEFINED(__vector_dispatch_31) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_31))
    . = ALIGN(4) ;
    __vector_offset_32 = (DEFINED(__vector_dispatch_32) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_32))
    . = ALIGN(4) ;
    __vector_offset_33 = (DEFINED(__vector_dispatch_33) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_33))
    . = ALIGN(4) ;
    __vector_offset_34 = (DEFINED(__vector_dispatch_34) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_34))
    . = ALIGN(4) ;
    __vector_offset_35 = (DEFINED(__vector_dispatch_35) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_35))
    . = ALIGN(4) ;
    __vector_offset_36 = (DEFINED(__vector_dispatch_36) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_36))
    . = ALIGN(4) ;
    __vector_offset_37 = (DEFINED(__vector_dispatch_37) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_37))
    . = ALIGN(4) ;
    __vector_offset_38 = (DEFINED(__vector_dispatch_38) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_38))
    . = ALIGN(4) ;
    __vector_offset_39 = (DEFINED(__vector_dispatch_39) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_39))
    . = ALIGN(4) ;
    __vector_offset_40 = (DEFINED(__vector_dispatch_40) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_40))
    . = ALIGN(4) ;
    __vector_offset_41 = (DEFINED(__vector_dispatch_41) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_41))
    . = ALIGN(4) ;
    __vector_offset_42 = (DEFINED(__vector_dispatch_42) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_42))
    . = ALIGN(4) ;
    __vector_offset_43 = (DEFINED(__vector_dispatch_43) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_43))
    . = ALIGN(4) ;
    __vector_offset_44 = (DEFINED(__vector_dispatch_44) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_44))
    . = ALIGN(4) ;
    __vector_offset_45 = (DEFINED(__vector_dispatch_45) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_45))
    . = ALIGN(4) ;
    __vector_offset_46 = (DEFINED(__vector_dispatch_46) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_46))
    . = ALIGN(4) ;
    __vector_offset_47 = (DEFINED(__vector_dispatch_47) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_47))
    . = ALIGN(4) ;
    __vector_offset_48 = (DEFINED(__vector_dispatch_48) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_48))
    . = ALIGN(4) ;
    __vector_offset_49 = (DEFINED(__vector_dispatch_49) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_49))
    . = ALIGN(4) ;
    __vector_offset_50 = (DEFINED(__vector_dispatch_50) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_50))
    . = ALIGN(4) ;
    __vector_offset_51 = (DEFINED(__vector_dispatch_51) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_51))
    . = ALIGN(4) ;
    __vector_offset_52 = (DEFINED(__vector_dispatch_52) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_52))
    . = ALIGN(4) ;
    __vector_offset_53 = (DEFINED(__vector_dispatch_53) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_53))
    . = ALIGN(4) ;
    __vector_offset_54 = (DEFINED(__vector_dispatch_54) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_54))
    . = ALIGN(4) ;
    __vector_offset_55 = (DEFINED(__vector_dispatch_55) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_55))
    . = ALIGN(4) ;
    __vector_offset_56 = (DEFINED(__vector_dispatch_56) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_56))
    . = ALIGN(4) ;
    __vector_offset_57 = (DEFINED(__vector_dispatch_57) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_57))
    . = ALIGN(4) ;
    __vector_offset_58 = (DEFINED(__vector_dispatch_58) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_58))
    . = ALIGN(4) ;
    __vector_offset_59 = (DEFINED(__vector_dispatch_59) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_59))
    . = ALIGN(4) ;
    __vector_offset_60 = (DEFINED(__vector_dispatch_60) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_60))
    . = ALIGN(4) ;
    __vector_offset_61 = (DEFINED(__vector_dispatch_61) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_61))
    . = ALIGN(4) ;
    __vector_offset_62 = (DEFINED(__vector_dispatch_62) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_62))
    . = ALIGN(4) ;
    __vector_offset_63 = (DEFINED(__vector_dispatch_63) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_63))
    . = ALIGN(4) ;
    __vector_offset_64 = (DEFINED(__vector_dispatch_64) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_64))
    . = ALIGN(4) ;
    __vector_offset_65 = (DEFINED(__vector_dispatch_65) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_65))
    . = ALIGN(4) ;
    __vector_offset_66 = (DEFINED(__vector_dispatch_66) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_66))
    . = ALIGN(4) ;
    __vector_offset_67 = (DEFINED(__vector_dispatch_67) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_67))
    . = ALIGN(4) ;
    __vector_offset_68 = (DEFINED(__vector_dispatch_68) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_68))
    . = ALIGN(4) ;
    __vector_offset_69 = (DEFINED(__vector_dispatch_69) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_69))
    . = ALIGN(4) ;
    __vector_offset_70 = (DEFINED(__vector_dispatch_70) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_70))
    . = ALIGN(4) ;
    __vector_offset_71 = (DEFINED(__vector_dispatch_71) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_71))
    . = ALIGN(4) ;
    __vector_offset_72 = (DEFINED(__vector_dispatch_72) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_72))
    . = ALIGN(4) ;
    __vector_offset_73 = (DEFINED(__vector_dispatch_73) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_73))
    . = ALIGN(4) ;
    __vector_offset_74 = (DEFINED(__vector_dispatch_74) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_74))
    . = ALIGN(4) ;
    __vector_offset_75 = (DEFINED(__vector_dispatch_75) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_75))
    . = ALIGN(4) ;
    __vector_offset_76 = (DEFINED(__vector_dispatch_76) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_76))
    . = ALIGN(4) ;
    __vector_offset_77 = (DEFINED(__vector_dispatch_77) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_77))
    . = ALIGN(4) ;
    __vector_offset_78 = (DEFINED(__vector_dispatch_78) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_78))
    . = ALIGN(4) ;
    __vector_offset_79 = (DEFINED(__vector_dispatch_79) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_79))
    . = ALIGN(4) ;
    __vector_offset_80 = (DEFINED(__vector_dispatch_80) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_80))
    . = ALIGN(4) ;
    __vector_offset_81 = (DEFINED(__vector_dispatch_81) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_81))
    . = ALIGN(4) ;
    __vector_offset_82 = (DEFINED(__vector_dispatch_82) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_82))
    . = ALIGN(4) ;
    __vector_offset_83 = (DEFINED(__vector_dispatch_83) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_83))
    . = ALIGN(4) ;
    __vector_offset_84 = (DEFINED(__vector_dispatch_84) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_84))
    . = ALIGN(4) ;
    __vector_offset_85 = (DEFINED(__vector_dispatch_85) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_85))
    . = ALIGN(4) ;
    __vector_offset_86 = (DEFINED(__vector_dispatch_86) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_86))
    . = ALIGN(4) ;
    __vector_offset_87 = (DEFINED(__vector_dispatch_87) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_87))
    . = ALIGN(4) ;
    __vector_offset_88 = (DEFINED(__vector_dispatch_88) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_88))
    . = ALIGN(4) ;
    __vector_offset_89 = (DEFINED(__vector_dispatch_89) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_89))
    . = ALIGN(4) ;
    __vector_offset_90 = (DEFINED(__vector_dispatch_90) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_90))
    . = ALIGN(4) ;
    __vector_offset_91 = (DEFINED(__vector_dispatch_91) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_91))
    . = ALIGN(4) ;
    __vector_offset_92 = (DEFINED(__vector_dispatch_92) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_92))
    . = ALIGN(4) ;
    __vector_offset_93 = (DEFINED(__vector_dispatch_93) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_93))
    . = ALIGN(4) ;
    __vector_offset_94 = (DEFINED(__vector_dispatch_94) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_94))
    . = ALIGN(4) ;
    __vector_offset_95 = (DEFINED(__vector_dispatch_95) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_95))
    . = ALIGN(4) ;
    __vector_offset_96 = (DEFINED(__vector_dispatch_96) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_96))
    . = ALIGN(4) ;
    __vector_offset_97 = (DEFINED(__vector_dispatch_97) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_97))
    . = ALIGN(4) ;
    __vector_offset_98 = (DEFINED(__vector_dispatch_98) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_98))
    . = ALIGN(4) ;
    __vector_offset_99 = (DEFINED(__vector_dispatch_99) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_99))
    . = ALIGN(4) ;
    __vector_offset_100 = (DEFINED(__vector_dispatch_100) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_100))
    . = ALIGN(4) ;
    __vector_offset_101 = (DEFINED(__vector_dispatch_101) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_101))
    . = ALIGN(4) ;
    __vector_offset_102 = (DEFINED(__vector_dispatch_102) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_102))
    . = ALIGN(4) ;
    __vector_offset_103 = (DEFINED(__vector_dispatch_103) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_103))
    . = ALIGN(4) ;
    __vector_offset_104 = (DEFINED(__vector_dispatch_104) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_104))
    . = ALIGN(4) ;
    __vector_offset_105 = (DEFINED(__vector_dispatch_105) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_105))
    . = ALIGN(4) ;
    __vector_offset_106 = (DEFINED(__vector_dispatch_106) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_106))
    . = ALIGN(4) ;
    __vector_offset_107 = (DEFINED(__vector_dispatch_107) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_107))
    . = ALIGN(4) ;
    __vector_offset_108 = (DEFINED(__vector_dispatch_108) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_108))
    . = ALIGN(4) ;
    __vector_offset_109 = (DEFINED(__vector_dispatch_109) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_109))
    . = ALIGN(4) ;
    __vector_offset_110 = (DEFINED(__vector_dispatch_110) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_110))
    . = ALIGN(4) ;
    __vector_offset_111 = (DEFINED(__vector_dispatch_111) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_111))
    . = ALIGN(4) ;
    __vector_offset_112 = (DEFINED(__vector_dispatch_112) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_112))
    . = ALIGN(4) ;
    __vector_offset_113 = (DEFINED(__vector_dispatch_113) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_113))
    . = ALIGN(4) ;
    __vector_offset_114 = (DEFINED(__vector_dispatch_114) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_114))
    . = ALIGN(4) ;
    __vector_offset_115 = (DEFINED(__vector_dispatch_115) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_115))
    . = ALIGN(4) ;
    __vector_offset_116 = (DEFINED(__vector_dispatch_116) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_116))
    . = ALIGN(4) ;
    __vector_offset_117 = (DEFINED(__vector_dispatch_117) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_117))
    . = ALIGN(4) ;
    __vector_offset_118 = (DEFINED(__vector_dispatch_118) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_118))
    . = ALIGN(4) ;
    __vector_offset_119 = (DEFINED(__vector_dispatch_119) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_119))
    . = ALIGN(4) ;
    __vector_offset_120 = (DEFINED(__vector_dispatch_120) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_120))
    . = ALIGN(4) ;
    __vector_offset_121 = (DEFINED(__vector_dispatch_121) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_121))
    . = ALIGN(4) ;
    __vector_offset_122 = (DEFINED(__vector_dispatch_122) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_122))
    . = ALIGN(4) ;
    __vector_offset_123 = (DEFINED(__vector_dispatch_123) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_123))
    . = ALIGN(4) ;
    __vector_offset_124 = (DEFINED(__vector_dispatch_124) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_124))
    . = ALIGN(4) ;
    __vector_offset_125 = (DEFINED(__vector_dispatch_125) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_125))
    . = ALIGN(4) ;
    __vector_offset_126 = (DEFINED(__vector_dispatch_126) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_126))
    . = ALIGN(4) ;
    __vector_offset_127 = (DEFINED(__vector_dispatch_127) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_127))
    . = ALIGN(4) ;
    __vector_offset_128 = (DEFINED(__vector_dispatch_128) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_128))
    . = ALIGN(4) ;
    __vector_offset_129 = (DEFINED(__vector_dispatch_129) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_129))
    . = ALIGN(4) ;
    __vector_offset_130 = (DEFINED(__vector_dispatch_130) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_130))
    . = ALIGN(4) ;
    __vector_offset_131 = (DEFINED(__vector_dispatch_131) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_131))
    . = ALIGN(4) ;
    __vector_offset_132 = (DEFINED(__vector_dispatch_132) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_132))
    . = ALIGN(4) ;
    __vector_offset_133 = (DEFINED(__vector_dispatch_133) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_133))
    . = ALIGN(4) ;
    __vector_offset_134 = (DEFINED(__vector_dispatch_134) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_134))
    . = ALIGN(4) ;
    __vector_offset_135 = (DEFINED(__vector_dispatch_135) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_135))
    . = ALIGN(4) ;
    __vector_offset_136 = (DEFINED(__vector_dispatch_136) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_136))
    . = ALIGN(4) ;
    __vector_offset_137 = (DEFINED(__vector_dispatch_137) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_137))
    . = ALIGN(4) ;
    __vector_offset_138 = (DEFINED(__vector_dispatch_138) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_138))
    . = ALIGN(4) ;
    __vector_offset_139 = (DEFINED(__vector_dispatch_139) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_139))
    . = ALIGN(4) ;
    __vector_offset_140 = (DEFINED(__vector_dispatch_140) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_140))
    . = ALIGN(4) ;
    __vector_offset_141 = (DEFINED(__vector_dispatch_141) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_141))
    . = ALIGN(4) ;
    __vector_offset_142 = (DEFINED(__vector_dispatch_142) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_142))
    . = ALIGN(4) ;
    __vector_offset_143 = (DEFINED(__vector_dispatch_143) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_143))
    . = ALIGN(4) ;
    __vector_offset_144 = (DEFINED(__vector_dispatch_144) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_144))
    . = ALIGN(4) ;
    __vector_offset_145 = (DEFINED(__vector_dispatch_145) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_145))
    . = ALIGN(4) ;
    __vector_offset_146 = (DEFINED(__vector_dispatch_146) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_146))
    . = ALIGN(4) ;
    __vector_offset_147 = (DEFINED(__vector_dispatch_147) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_147))
    . = ALIGN(4) ;
    __vector_offset_148 = (DEFINED(__vector_dispatch_148) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_148))
    . = ALIGN(4) ;
    __vector_offset_149 = (DEFINED(__vector_dispatch_149) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_149))
    . = ALIGN(4) ;
    __vector_offset_150 = (DEFINED(__vector_dispatch_150) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_150))
    . = ALIGN(4) ;
    __vector_offset_151 = (DEFINED(__vector_dispatch_151) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_151))
    . = ALIGN(4) ;
    __vector_offset_152 = (DEFINED(__vector_dispatch_152) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_152))
    . = ALIGN(4) ;
    __vector_offset_153 = (DEFINED(__vector_dispatch_153) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_153))
    . = ALIGN(4) ;
    __vector_offset_154 = (DEFINED(__vector_dispatch_154) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_154))
    . = ALIGN(4) ;
    __vector_offset_155 = (DEFINED(__vector_dispatch_155) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_155))
    . = ALIGN(4) ;
    __vector_offset_156 = (DEFINED(__vector_dispatch_156) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_156))
    . = ALIGN(4) ;
    __vector_offset_157 = (DEFINED(__vector_dispatch_157) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_157))
    . = ALIGN(4) ;
    __vector_offset_158 = (DEFINED(__vector_dispatch_158) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_158))
    . = ALIGN(4) ;
    __vector_offset_159 = (DEFINED(__vector_dispatch_159) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_159))
    . = ALIGN(4) ;
    __vector_offset_160 = (DEFINED(__vector_dispatch_160) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_160))
    . = ALIGN(4) ;
    __vector_offset_161 = (DEFINED(__vector_dispatch_161) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_161))
    . = ALIGN(4) ;
    __vector_offset_162 = (DEFINED(__vector_dispatch_162) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_162))
    . = ALIGN(4) ;
    __vector_offset_163 = (DEFINED(__vector_dispatch_163) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_163))
    . = ALIGN(4) ;
    __vector_offset_164 = (DEFINED(__vector_dispatch_164) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_164))
    . = ALIGN(4) ;
    __vector_offset_165 = (DEFINED(__vector_dispatch_165) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_165))
    . = ALIGN(4) ;
    __vector_offset_166 = (DEFINED(__vector_dispatch_166) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_166))
    . = ALIGN(4) ;
    __vector_offset_167 = (DEFINED(__vector_dispatch_167) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_167))
    . = ALIGN(4) ;
    __vector_offset_168 = (DEFINED(__vector_dispatch_168) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_168))
    . = ALIGN(4) ;
    __vector_offset_169 = (DEFINED(__vector_dispatch_169) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_169))
    . = ALIGN(4) ;
    __vector_offset_170 = (DEFINED(__vector_dispatch_170) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_170))
    . = ALIGN(4) ;
    __vector_offset_171 = (DEFINED(__vector_dispatch_171) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_171))
    . = ALIGN(4) ;
    __vector_offset_172 = (DEFINED(__vector_dispatch_172) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_172))
    . = ALIGN(4) ;
    __vector_offset_173 = (DEFINED(__vector_dispatch_173) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_173))
    . = ALIGN(4) ;
    __vector_offset_174 = (DEFINED(__vector_dispatch_174) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_174))
    . = ALIGN(4) ;
    __vector_offset_175 = (DEFINED(__vector_dispatch_175) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_175))
    . = ALIGN(4) ;
    __vector_offset_176 = (DEFINED(__vector_dispatch_176) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_176))
    . = ALIGN(4) ;
    __vector_offset_177 = (DEFINED(__vector_dispatch_177) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_177))
    . = ALIGN(4) ;
    __vector_offset_178 = (DEFINED(__vector_dispatch_178) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_178))
    . = ALIGN(4) ;
    __vector_offset_179 = (DEFINED(__vector_dispatch_179) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_179))
    . = ALIGN(4) ;
    __vector_offset_180 = (DEFINED(__vector_dispatch_180) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_180))
    . = ALIGN(4) ;
    __vector_offset_181 = (DEFINED(__vector_dispatch_181) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_181))
    . = ALIGN(4) ;
    __vector_offset_182 = (DEFINED(__vector_dispatch_182) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_182))
    . = ALIGN(4) ;
    __vector_offset_183 = (DEFINED(__vector_dispatch_183) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_183))
    . = ALIGN(4) ;
    __vector_offset_184 = (DEFINED(__vector_dispatch_184) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_184))
    . = ALIGN(4) ;
    __vector_offset_185 = (DEFINED(__vector_dispatch_185) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_185))
    . = ALIGN(4) ;
    __vector_offset_186 = (DEFINED(__vector_dispatch_186) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_186))
    . = ALIGN(4) ;
    __vector_offset_187 = (DEFINED(__vector_dispatch_187) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_187))
    . = ALIGN(4) ;
    __vector_offset_188 = (DEFINED(__vector_dispatch_188) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_188))
    . = ALIGN(4) ;
    __vector_offset_189 = (DEFINED(__vector_dispatch_189) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_189))
    . = ALIGN(4) ;
    __vector_offset_190 = (DEFINED(__vector_dispatch_190) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_190))
    . = ALIGN(4) ;
    __vector_offset_191 = (DEFINED(__vector_dispatch_191) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_191))
    . = ALIGN(4) ;
    __vector_offset_192 = (DEFINED(__vector_dispatch_192) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_192))
    . = ALIGN(4) ;
    __vector_offset_193 = (DEFINED(__vector_dispatch_193) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_193))
    . = ALIGN(4) ;
    __vector_offset_194 = (DEFINED(__vector_dispatch_194) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_194))
    . = ALIGN(4) ;
    __vector_offset_195 = (DEFINED(__vector_dispatch_195) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_195))
    . = ALIGN(4) ;
    __vector_offset_196 = (DEFINED(__vector_dispatch_196) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_196))
    . = ALIGN(4) ;
    __vector_offset_197 = (DEFINED(__vector_dispatch_197) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_197))
    . = ALIGN(4) ;
    __vector_offset_198 = (DEFINED(__vector_dispatch_198) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_198))
    . = ALIGN(4) ;
    __vector_offset_199 = (DEFINED(__vector_dispatch_199) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_199))
    . = ALIGN(4) ;
    __vector_offset_200 = (DEFINED(__vector_dispatch_200) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_200))
    . = ALIGN(4) ;
    __vector_offset_201 = (DEFINED(__vector_dispatch_201) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_201))
    . = ALIGN(4) ;
    __vector_offset_202 = (DEFINED(__vector_dispatch_202) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_202))
    . = ALIGN(4) ;
    __vector_offset_203 = (DEFINED(__vector_dispatch_203) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_203))
    . = ALIGN(4) ;
    __vector_offset_204 = (DEFINED(__vector_dispatch_204) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_204))
    . = ALIGN(4) ;
    __vector_offset_205 = (DEFINED(__vector_dispatch_205) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_205))
    . = ALIGN(4) ;
    __vector_offset_206 = (DEFINED(__vector_dispatch_206) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_206))
    . = ALIGN(4) ;
    __vector_offset_207 = (DEFINED(__vector_dispatch_207) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_207))
    . = ALIGN(4) ;
    __vector_offset_208 = (DEFINED(__vector_dispatch_208) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_208))
    . = ALIGN(4) ;
    __vector_offset_209 = (DEFINED(__vector_dispatch_209) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_209))
    . = ALIGN(4) ;
    __vector_offset_210 = (DEFINED(__vector_dispatch_210) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_210))
    . = ALIGN(4) ;
    __vector_offset_211 = (DEFINED(__vector_dispatch_211) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_211))
    . = ALIGN(4) ;
    __vector_offset_212 = (DEFINED(__vector_dispatch_212) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_212))
    . = ALIGN(4) ;
    __vector_offset_213 = (DEFINED(__vector_dispatch_213) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_213))
    . = ALIGN(4) ;
    __vector_offset_214 = (DEFINED(__vector_dispatch_214) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_214))
    . = ALIGN(4) ;
    __vector_offset_215 = (DEFINED(__vector_dispatch_215) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_215))
    . = ALIGN(4) ;
    __vector_offset_216 = (DEFINED(__vector_dispatch_216) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_216))
    . = ALIGN(4) ;
    __vector_offset_217 = (DEFINED(__vector_dispatch_217) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_217))
    . = ALIGN(4) ;
    __vector_offset_218 = (DEFINED(__vector_dispatch_218) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_218))
    . = ALIGN(4) ;
    __vector_offset_219 = (DEFINED(__vector_dispatch_219) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_219))
    . = ALIGN(4) ;
    __vector_offset_220 = (DEFINED(__vector_dispatch_220) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_220))
    . = ALIGN(4) ;
    __vector_offset_221 = (DEFINED(__vector_dispatch_221) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_221))
    . = ALIGN(4) ;
    __vector_offset_222 = (DEFINED(__vector_dispatch_222) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_222))
    . = ALIGN(4) ;
    __vector_offset_223 = (DEFINED(__vector_dispatch_223) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_223))
    . = ALIGN(4) ;
    __vector_offset_224 = (DEFINED(__vector_dispatch_224) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_224))
    . = ALIGN(4) ;
    __vector_offset_225 = (DEFINED(__vector_dispatch_225) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_225))
    . = ALIGN(4) ;
    __vector_offset_226 = (DEFINED(__vector_dispatch_226) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_226))
    . = ALIGN(4) ;
    __vector_offset_227 = (DEFINED(__vector_dispatch_227) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_227))
    . = ALIGN(4) ;
    __vector_offset_228 = (DEFINED(__vector_dispatch_228) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_228))
    . = ALIGN(4) ;
    __vector_offset_229 = (DEFINED(__vector_dispatch_229) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_229))
    . = ALIGN(4) ;
    __vector_offset_230 = (DEFINED(__vector_dispatch_230) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_230))
    . = ALIGN(4) ;
    __vector_offset_231 = (DEFINED(__vector_dispatch_231) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_231))
    . = ALIGN(4) ;
    __vector_offset_232 = (DEFINED(__vector_dispatch_232) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_232))
    . = ALIGN(4) ;
    __vector_offset_233 = (DEFINED(__vector_dispatch_233) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_233))
    . = ALIGN(4) ;
    __vector_offset_234 = (DEFINED(__vector_dispatch_234) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_234))
    . = ALIGN(4) ;
    __vector_offset_235 = (DEFINED(__vector_dispatch_235) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_235))
    . = ALIGN(4) ;
    __vector_offset_236 = (DEFINED(__vector_dispatch_236) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_236))
    . = ALIGN(4) ;
    __vector_offset_237 = (DEFINED(__vector_dispatch_237) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_237))
    . = ALIGN(4) ;
    __vector_offset_238 = (DEFINED(__vector_dispatch_238) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_238))
    . = ALIGN(4) ;
    __vector_offset_239 = (DEFINED(__vector_dispatch_239) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_239))
    . = ALIGN(4) ;
    __vector_offset_240 = (DEFINED(__vector_dispatch_240) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_240))
    . = ALIGN(4) ;
    __vector_offset_241 = (DEFINED(__vector_dispatch_241) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_241))
    . = ALIGN(4) ;
    __vector_offset_242 = (DEFINED(__vector_dispatch_242) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_242))
    . = ALIGN(4) ;
    __vector_offset_243 = (DEFINED(__vector_dispatch_243) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_243))
    . = ALIGN(4) ;
    __vector_offset_244 = (DEFINED(__vector_dispatch_244) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_244))
    . = ALIGN(4) ;
    __vector_offset_245 = (DEFINED(__vector_dispatch_245) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_245))
    . = ALIGN(4) ;
    __vector_offset_246 = (DEFINED(__vector_dispatch_246) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_246))
    . = ALIGN(4) ;
    __vector_offset_247 = (DEFINED(__vector_dispatch_247) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_247))
    . = ALIGN(4) ;
    __vector_offset_248 = (DEFINED(__vector_dispatch_248) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_248))
    . = ALIGN(4) ;
    __vector_offset_249 = (DEFINED(__vector_dispatch_249) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_249))
    . = ALIGN(4) ;
    __vector_offset_250 = (DEFINED(__vector_dispatch_250) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_250))
    . = ALIGN(4) ;
    __vector_offset_251 = (DEFINED(__vector_dispatch_251) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_251))
    . = ALIGN(4) ;
    __vector_offset_252 = (DEFINED(__vector_dispatch_252) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_252))
    . = ALIGN(4) ;
    __vector_offset_253 = (DEFINED(__vector_dispatch_253) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_253))
    . = ALIGN(4) ;
    __vector_offset_254 = (DEFINED(__vector_dispatch_254) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_254))
    . = ALIGN(4) ;
    __vector_offset_255 = (DEFINED(__vector_dispatch_255) ? (. - _ebase_address) : __vector_offset_default);
    KEEP(*(.vector_255))
    /* Default interrupt handler */
    . = ALIGN(4) ;
    __vector_offset_default = . - _ebase_address;
    KEEP(*(.vector_default))
  } > kseg0_program_mem

  /*  The startup code is in the .reset.startup section.
   *  Keep this here for backwards compatibility with older
   *  C32 v1.xx releases.
   */
  .startup ORIGIN(kseg0_boot_mem) :
  {
    KEEP(*(.startup))
  } > kseg0_boot_mem

  /* Code Sections - Note that input sections *(.text) and *(.text.*)
   * are not mapped here. The best-fit allocator locates them,
   * so that .text may flow around absolute sections as needed.
   */
  .text :
  {
    *(.stub .gnu.linkonce.t.*)
    KEEP (*(.text.*personality*))
    *(.mips16.fn.*)
    *(.mips16.call.*)
    *(.gnu.warning)
    . = ALIGN(4) ;
  } >kseg0_program_mem
  /* Global-namespace object initialization */
  .init   :
  {
    KEEP (*crti.o(.init))
    KEEP (*crtbegin.o(.init))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o *crtn.o ).init))
    KEEP (*crtend.o(.init))
    KEEP (*crtn.o(.init))
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .fini   :
  {
    KEEP (*(.fini))
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .preinit_array   :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .init_array   :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array))
    PROVIDE_HIDDEN (__init_array_end = .);
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .fini_array   :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array))
    PROVIDE_HIDDEN (__fini_array_end = .);
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .ctors   :
  {
    /* XC32 uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .dtors   :
  {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
    . = ALIGN(4) ;
  } >kseg0_program_mem
  /* Read-only sections */
  .rodata   :
  {
    *( .gnu.linkonce.r.*)
    *(.rodata1)
    . = ALIGN(4) ;
  } >kseg0_program_mem
  /*
   * Small initialized constant global and static data can be placed in the
   * .sdata2 section.  This is different from .sdata, which contains small
   * initialized non-constant global and static data.
   */
  .sdata2 ALIGN(4) :
  {
    *(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
    . = ALIGN(4) ;
  } >kseg0_program_mem
  /*
   * Uninitialized constant global and static data (i.e., variables which will
   * always be zero).  Again, this is different from .sbss, which contains
   * small non-initialized, non-constant global and static data.
   */
  .sbss2 ALIGN(4) :
  {
    *(.sbss2 .sbss2.* .gnu.linkonce.sb2.*)
    . = ALIGN(4) ;
  } >kseg0_program_mem
  .eh_frame_hdr   :
  {
    *(.eh_frame_hdr)
  } >kseg0_program_mem
    . = ALIGN(4) ;
  .eh_frame   : ONLY_IF_RO
  {
    KEEP (*(.eh_frame))
  } >kseg0_program_mem
    . = ALIGN(4) ;
  .gcc_except_table   : ONLY_IF_RO
  {
    *(.gcc_except_table .gcc_except_table.*)
  } >kseg0_program_mem
    . = ALIGN(4) ;
  .dbg_data (NOLOAD) :
  {
    . += (DEFINED (_DEBUGGER) ? 0x200 : 0x0);
    /* Additional data memory required for DSPr2 registers */
    . += (DEFINED (_DEBUGGER) ? 0x80 : 0x0);
    /* Additional data memory required for FPU64 registers */
    . += (DEFINED (_DEBUGGER) ? 0x100 : 0x0);
  } >kseg0_data_mem
  .jcr   :
  {
    KEEP (*(.jcr))
    . = ALIGN(4) ;
  } >kseg0_data_mem
  .eh_frame    : ONLY_IF_RW
  {
    KEEP (*(.eh_frame))
  } >kseg0_data_mem
    . = ALIGN(4) ;
  .gcc_except_table    : ONLY_IF_RW
  {
    *(.gcc_except_table .gcc_except_table.*)
  } >kseg0_data_mem
    . = ALIGN(4) ;
  /* Persistent data - Use the new C 'persistent' attribute instead. */
  .persist   :
  {
    _persist_begin = .;
    *(.persist .persist.*)
    . = ALIGN(4) ;
    _persist_end = .;
  } >kseg0_data_mem
  /*
   *  Note that input sections named .data* are not mapped here.
   *  The best-fit allocator locates them, so that they may flow
   *  around absolute sections as needed.
   */
  .data   :
  {
    *( .gnu.linkonce.d.*)
    SORT(CONSTRUCTORS)
    *(.data1)
    . = ALIGN(4) ;
  } >kseg0_data_mem
  . = .;
  _gp = ALIGN(16) + 0x7ff0;
  .got ALIGN(4) :
  {
    *(.got.plt) *(.got)
    . = ALIGN(4) ;
  } >kseg0_data_mem /* AT>kseg0_program_mem */
  /*
   * Note that 'small' data sections are still mapped in the linker
   * script. This ensures that they are grouped together for
   * gp-relative addressing. Absolute sections are allocated after
   * the 'small' data sections so small data cannot flow around them.
   */
  /*
   * We want the small data sections together, so single-instruction offsets
   * can access them all, and initialized data all before uninitialized, so
   * we can shorten the on-disk segment size.
   */
  .sdata ALIGN(4) :
  {
    _sdata_begin = . ;
    *(.sdata .sdata.* .gnu.linkonce.s.*)
    . = ALIGN(4) ;
    _sdata_end = . ;
  } >kseg0_data_mem
  .lit8           :
  {
    *(.lit8)
  } >kseg0_data_mem
  .lit4           :
  {
    *(.lit4)
  } >kseg0_data_mem
  . = ALIGN (4) ;
  _data_end = . ;
  _bss_begin = . ;
  .sbss ALIGN(4) :
  {
    _sbss_begin = . ;
    *(.dynsbss)
    *(.sbss .sbss.* .gnu.linkonce.sb.*)
    *(.scommon)
    _sbss_end = . ;
    . = ALIGN(4) ;
  } >kseg0_data_mem
  /*
   *  Align here to ensure that the .bss section occupies space up to
   *  _end.  Align after .bss to ensure correct alignment even if the
   *  .bss section disappears because there are no input sections.
   *
   *  Note that input sections named .bss* are no longer mapped here.
   *  The best-fit allocator locates them, so that they may flow
   *  around absolute sections as needed.
   *
   */
  .bss     :
  {
    *(.dynbss)
    *(COMMON)
   /* Align here to ensure that the .bss section occupies space up to
      _end.  Align after .bss to ensure correct alignment even if the
      .bss section disappears because there are no input sections. */
   . = ALIGN(. != 0 ? 4 : 1);
  } >kseg0_data_mem
  . = ALIGN(4) ;
  _end = . ;
  _bss_end = . ;
  /*
   *  The heap and stack are best-fit allocated by the linker after other
   *  data and bss sections have been allocated.
   */
  /*
   * RAM functions go at the end of our stack and heap allocation.
   * Alignment of 2K required by the boundary register (BMXDKPBA).
   *
   * RAM functions are now allocated by the linker. The linker generates
   * _ramfunc_begin and _bmxdkpba_address symbols depending on the
   * location of RAM functions.
   */
  _bmxdudba_address = LENGTH(kseg0_data_mem) ;
  _bmxdupba_address = LENGTH(kseg0_data_mem) ;
    /* The .pdr section belongs in the absolute section */
    /DISCARD/ : { *(.pdr) }
  .gptab.sdata : { *(.gptab.data) *(.gptab.sdata) }
  .gptab.sbss : { *(.gptab.bss) *(.gptab.sbss) }
  .mdebug.abi32 0 : { KEEP(*(.mdebug.abi32)) }
  .mdebug.abiN32 0 : { KEEP(*(.mdebug.abiN32)) }
  .mdebug.abi64 0 : { KEEP(*(.mdebug.abi64)) }
  .mdebug.abiO64 0 : { KEEP(*(.mdebug.abiO64)) }
  .mdebug.eabi32 0 : { KEEP(*(.mdebug.eabi32)) }
  .mdebug.eabi64 0 : { KEEP(*(.mdebug.eabi64)) }
  .gcc_compiled_long32 : { KEEP(*(.gcc_compiled_long32)) }
  .gcc_compiled_long64 : { KEEP(*(.gcc_compiled_long64)) }
  /* Stabs debugging sections.  */
  .stab          0 : { *(.stab) }
  .stabstr       0 : { *(.stabstr) }
  .stab.excl     0 : { *(.stab.excl) }
  .stab.exclstr  0 : { *(.stab.exclstr) }
  .stab.index    0 : { *(.stab.index) }
  .stab.indexstr 0 : { *(.stab.indexstr) }
  .comment       0 : { *(.comment) }
  /* DWARF debug sections used by MPLAB X for source-level debugging. 
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *.elf(.debug) *(.debug) }
  .line           0 : { *.elf(.line) *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *.elf(.debug_srcinfo) *(.debug_srcinfo) }
  .debug_sfnames  0 : { *.elf(.debug_sfnames) *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *.elf(.debug_aranges) *(.debug_aranges) }
  .debug_pubnames 0 : { *.elf(.debug_pubnames) *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *.elf(.debug_info .gnu.linkonce.wi.*) *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *.elf(.debug_abbrev) *(.debug_abbrev) }
  .debug_line     0 : { *.elf(.debug_line) *(.debug_line) }
  .debug_frame    0 : { *.elf(.debug_frame) *(.debug_frame) }
  .debug_str      0 : { *.elf(.debug_str) *(.debug_str) }
  .debug_loc      0 : { *.elf(.debug_loc) *(.debug_loc) }
  .debug_macinfo  0 : { *.elf(.debug_macinfo) *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *.elf(.debug_weaknames) *(.debug_weaknames) }
  .debug_funcnames 0 : { *.elf(.debug_funcnames) *(.debug_funcnames) }
  .debug_typenames 0 : { *.elf(.debug_typenames) *(.debug_typenames) }
  .debug_varnames  0 : { *.elf(.debug_varnames) *(.debug_varnames) }
  .debug_pubtypes 0 : { *.elf(.debug_pubtypes) *(.debug_pubtypes) }
  .debug_ranges   0 : { *.elf(.debug_ranges) *(.debug_ranges) }
  /DISCARD/ : { *(.rel.dyn) }
  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  /DISCARD/ : { *(.note.GNU-stack) }
  /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) *(.discard) }
}

