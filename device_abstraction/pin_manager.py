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
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
import xml.etree.ElementTree as ET
import os

class mcDevI_PinManager:
    def __init__(self, component ):
        self.component = component

        # Get pin package details
        packageName = str(Database.getSymbolValue("core", "COMPONENT_PACKAGE"))

        pinout = ""
        children = (ATDF.getNode("/avr-tools-device-file/variants")).getChildren()
        for index in range(0, len(children)):
            if packageName in children[index].getAttribute("package"):
                pinout = children[index].getAttribute("pinout")

        architecture = ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("architecture")

        if "MIPS" != architecture:

            pins = ATDF.getNode("/avr-tools-device-file/pinouts/pinout@[name=\"" + pinout + "\"]").getChildren()
            self.pad_to_pin_map = {}
            for pin in pins:
                self.pad_to_pin_map[pin.getAttribute("pad")] = str(pin.getAttribute("position"))

        else:
            for module in ATDF.getNode("/avr-tools-device-file/modules").getChildren():
                if module.getAttribute("name") == "GPIO":
                    GPIO = module.getAttribute("name").lower() + "_" + module.getAttribute("id").lower()
                    break

            currentPath = Variables.get("__CSP_DIR") + "/peripheral/gpio_02467"
            deviceXmlPath = os.path.join(currentPath, "plugin/pin_xml/components/" + Variables.get("__PROCESSOR") + ".xml")
            deviceXmlTree = ET.parse(deviceXmlPath)
            deviceXmlRoot = deviceXmlTree.getroot()
            pinoutXmlName = deviceXmlRoot.get("pins")
            pinoutXmlPath = os.path.join(currentPath, "plugin/pin_xml/pins/" + pinoutXmlName + ".xml")
            pinoutXmlPath = os.path.normpath(pinoutXmlPath)

            pinFileContent = ET.fromstring((open(pinoutXmlPath, "r")).read())
            self.pad_to_pin_map = {}
            for pad in pinFileContent.findall("pins/pin"):
                for number in pad.findall("number"):
                        temp = self.stringReplace(pad.attrib["name"])
                        self.pad_to_pin_map[temp] = number.attrib["pin"]

    def stringReplace( self, my_String ):
        my_String = my_String.replace("RP","R")
        return my_String

