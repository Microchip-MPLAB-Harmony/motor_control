---
title: Microchip MPLAB® Harmony 3 Motor Control
nav_order: 1
has_children: false
has_toc: false
---

# Microchip MPLAB® Harmony 3 Motor Control

MPLAB Harmony 3 is an extension of the MPLAB® ecosystem for creating
embedded firmware solutions for Microchip 32-bit SAM and PIC32 microcontroller
and microprocessor devices.  Refer to the following links for more information.
 - [Microchip 32-bit MCUs for Motor Control Applications](https://www.microchip.com/design-centers/motor-control-and-drive/control-products/32-bit-solutions)
 - [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
 - [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
 - [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
 - [Microchip MPLAB Harmony](https://www.microchip.com/mplab/mplab-harmony)
 - [Microchip MPLAB Harmony Pages](https://microchip-mplab-harmony.github.io/)
 - [MPLAB Harmony License](mplab_harmony_license.md)

This repository serves as the home for Harmony QSpin, a GUI-based motor control system configuration tool. Designed for ease of use, it empowers users to swiftly construct motor control applications featuring well-architected code and MISRA-compliant content. Achieving this is made simple by following intuitive steps, ensuring a seamless and efficient motor control development experience.
    <p align="center">
        <img src="Images/Harmony QSpin.JPG" />
        <figcaption align= "center"> Harmony QSpin </figcaption>
    </p>

For a detailed understanding of the tool's various features, consult the [Harmony QSpin Quick Guide](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MH3_motor_control&redirect=true) to view the online documentation

To view the documentation offline, follow these steps:
 - Download the publication as a zip file from [here](https://onlinedocs.microchip.com/download/GUID-0A4BC4EE-29F5-4736-8125-17139B84E7B5?type=webhelp).
 - Extract the zip file into a folder.
 - Navigate to the folder and open **index.html** in a web browser of your choice
Additionally, keep yourself informed with the latest updates and improvements by checking out our release notes:
 - [Release Notes](./release_notes.md)

# Harmony QSpin Device and Algorithm Compatibility

Harmony QSpin is designed to support a wide range of devices and algorithms for motor control applications. Below are the lists of supported devices, motors, and algorithms:

## Supported Devices

Harmony QSpin supports various microcontroller families from Microchip, ensuring compatibility with different motor control applications.

| Device Families                                                                                           | Tested On                                                        | Remarks |
|-----------------------------------------------------------------------------------------------------------|------------------------------------------------------------------|---------|
| [SAMD/E5x](https://www.microchip.com/en-us/solutions/technologies/motor-control-and-drive/motor-control-products/32-bit-microcontrollers-for-motor-control-applications/sam-d5x-and-e5x) | [ATSAME54P20A](https://www.microchip.com/en-us/product/atsame54p20a) | -       |
| [SAME7x](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/32-bit-mcus/sam-32-bit-mcus/sam-e)                          | [ATSAME70Q21B](https://www.microchip.com/en-us/product/atsame70q21) | -       |
| [SAMV7x](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/32-bit-mcus/sam-32-bit-mcus/sam-v)                          | -                                                                | -       |
| [SAMC2x](https://www.microchip.com/en-us/solutions/technologies/motor-control-and-drive/motor-control-products/32-bit-microcontrollers-for-motor-control-applications/sam-c2x-and-d2x) | [ATSAMC21J18A](https://www.microchip.com/en-us/product/atsamc21j18a) | -       |
| [PIC32CM MC](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/32-bit-mcus/pic32-32-bit-mcus/pic32cm-mc)             | [PIC32CM1216MC00048](https://www.microchip.com/en-us/product/PIC32CM1216MC00048) | -       |
| [PIC32MK MCF](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/32-bit-mcus/pic32-32-bit-mcus/pic32mk)               | [PIC32MK1024MCF100](https://www.microchip.com/en-us/product/pic32mk1024mcf100) | -       |
| [PIC32MK MCM](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/32-bit-mcus/pic32-32-bit-mcus/pic32mk)               | [PIC32MK1024MCM100](https://www.microchip.com/en-us/product/PIC32MK1024MCM100) | -       |
| [PIC32MK MCA](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/32-bit-mcus/pic32-32-bit-mcus/pic32mk)               | [PIC32MK0128MCA048](https://www.microchip.com/en-us/product/PIC32MK0128MCA048) | -       |

## Supported Motors

Harmony QSpin provides support for following motors:
- Permanent Magnet Synchronous Motors (PMSM)

## Supported Algorithms

Harmony QSpin integrates advanced algorithms tailored for different microcontroller families, enabling efficient motor control strategies.

| Algorithms                                          | SAMD/E5x   | SAME7x / SAMV7x   | SAMC2x/ PIC32CM MC |  PIC32MK MCF/ PIC32MK MCM/ PIC32MK MCA |
|-----------------------------------------------|------------|--------------------|---------------------|----------------------------------------|
| Classical PLL based Estimator                   | Yes        | Yes                | Yes                 | Yes                                    |
| Sliding mode observer                           | Yes        | Yes                | No                  | Yes                                    |
| Reduced Order Luenberger Observer               | Yes        | Yes                | Yes                  | Yes                                    |
| Encoder based position calculation              | Yes        | Yes                | No                  | Yes                                    |
| ZSMT-HF Hybrid                                   | Yes        | No                 | No                  | Yes                                    |
| Flux weakening                                   | Yes        | Yes                | No                  | Yes                                    |
| MTPA                                             | Yes        | Yes                | No                  | Yes                                    |
| Null vector Flying start                         | Yes        | Yes                | No                  | Yes                                    |
| Encoder based position control                  | Yes        | Yes                | No                  | Yes                                    |

# Additional Resources

Explore a variety of example application projects generated from QSpin and discover high-value standalone projects in the following repositories:

| Repository Name | Description | Help Document | 
| ----------------- | ------------------- | ---------------- |
| [mc_apps_pic32cm_mc](https://github.com/Microchip-MPLAB-Harmony/mc_apps_pic32cm_mc) | Motor Control Applications for PIC32CM MC family | [mc_apps_pic32cm_mc help](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MC_APPS_PIC32CM_MC_INTRODUCTION&redirect=true) |
| [mc_apps_pic32mk](https://github.com/Microchip-MPLAB-Harmony/mc_apps_pic32mk) | Motor Control Applications for PIC32MK family | [mc_apps_pic32mk help](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MC_APPS_PIC32MK_INTRODUCTION&redirect=true) |
| [mc_apps_sam_c2x](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_c2x) | Motor Control Applications for SAM C2x family | [mc_apps_sam_c2x help](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MC_APPS_SAM_C2X_INTRODUCTION&redirect=true) |
| [mc_apps_sam_d5x_e5x](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_d5x_e5x) | Motor Control Applications for SAM E5x family | [mc_apps_sam_d5x_e5x help](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MC_APPS_SAM_D5X_E5X_INTRODUCTION&redirect=true) |
| [mc_apps_sam_e7x_s7x_v7x](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_e7x_s7x_v7x) | Motor Control Applications for SAM E7x family | [mc_apps_sam_e7x_s7x_v7x help](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MC_APPS_SAM_E7X_S7X_V7X_INTRODUCTION&redirect=true) |
| [mc_apps_sam_rh71](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_rh71) | Motor Control Applications for SAM RH71 family | [mc_apps_sam_rh71 help](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MC_APPS_SAM_RH71_INTRODUCTION&redirect=true) |
[mc_apps_sam_rh707](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_rh707) | Motor Control Applications for SAM RH707 family | [mc_apps_sam_rh707 help](https://onlinedocs.microchip.com/v2/keyword-lookup?keyword=MC_APPS_SAM_RH707_INTRODUCTION&redirect=true) |

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/mc.svg)]()
____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/mc.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/mc.svg?style=social)]()
