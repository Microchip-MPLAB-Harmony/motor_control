# coding: utf-8
"""*****************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************"""

#---------------------------------------------------------------------------------------#
#                                   Imports                                             #
#---------------------------------------------------------------------------------------#
from device.gpio import pin_manager

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class AdapterService:
    def __init__(self, wrapper):
        # Get ATDF object
        self.wrapper = wrapper

        # Get ATDF object
        ATDF = wrapper.get_atdf_object()

        # Get ATDF object
        Database = wrapper.get_database_object()

        # Get pin package details
        packageName = str(Database.getSymbolValue("core", "COMPONENT_PACKAGE"))

        pinout = ""
        children = (ATDF.getNode("/avr-tools-device-file/variants")).getChildren()
        for index in range(0, len(children)):
            if packageName in children[index].getAttribute("package"):
                pinout = children[index].getAttribute("pinout")

        # Get list of function_Maps
        self.gpio_data = []

        pins = ATDF.getNode("/avr-tools-device-file/pinouts/pinout@[name=\"" + pinout + "\"]").getChildren()

        for pin in pins:
            pad = pin.getAttribute("pad")
            if pad.startswith("P"):
                self.gpio_data.append(pad)

    def get_gpio_data(self):
        return self.gpio_data

    def set_led_pin(self, name, pad):
        pin_manager_module = pin_manager.PinManager(self.wrapper)
        pin_manager_module.configureLed(pad, name, "GPIO")

    def set_button_pin(self, name, pad):
        pin_manager_module = pin_manager.PinManager(self.wrapper)
        pin_manager_module.configureButton(pad, name, "GPIO")




