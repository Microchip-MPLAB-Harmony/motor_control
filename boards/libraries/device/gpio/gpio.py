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
import importlib

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class GpioPeripheral:
    def __init__(self, object_wrapper):
        # Get ATDF object
        self.object_wrapper = object_wrapper

        # Get ATDF object
        ATDF = object_wrapper.get_atdf_object()

        # Get ATDF object
        Database = object_wrapper.get_database_object()

        core_type = ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("architecture")

        if core_type == 'MIPS':
            import os
            import xml.etree.ElementTree as ET
            from pin_manager_pic32mk import PinManager
            self.pin_manager = PinManager(object_wrapper)

             # Get ATDF object
            ATDF = object_wrapper.get_atdf_object()
            Variables = object_wrapper.get_variable_object()

            for module in ATDF.getNode("/avr-tools-device-file/modules").getChildren():
                if module.getAttribute("name") == "GPIO":
                    GPIO = module.getAttribute("name").lower() + "_" + module.getAttribute("id").lower()
                    break

            currentPath = Variables.get("__CSP_DIR") + "/peripheral/" + GPIO
            deviceXmlPath = os.path.join(currentPath, "plugin/pin_xml/components/" + Variables.get("__PROCESSOR") + ".xml")
            deviceXmlTree = ET.parse(deviceXmlPath)
            deviceXmlRoot = deviceXmlTree.getroot()
            pinoutXmlName = deviceXmlRoot.get("pins")
            pinoutXmlPath = os.path.join(currentPath, "plugin/pin_xml/pins/" + pinoutXmlName + ".xml")
            pinoutXmlPath = os.path.normpath(pinoutXmlPath)

            pinFileContent = ET.fromstring((open(pinoutXmlPath, "r")).read())

            # Get list of function_Maps
            self.gpio_data = []
            for item in pinFileContent.findall("pins/pin"):
                if item.attrib["name"].startswith("R"):
                    self.gpio_data.append(item.attrib["name"])

        else:
            from pin_manager import PinManager
            self.pin_manager = PinManager(object_wrapper)

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
        self.pin_manager.configureLed(pad, name, "GPIO")

    def set_button_pin(self, name, pad):
        self.pin_manager.configureButton(pad, name, "GPIO")




