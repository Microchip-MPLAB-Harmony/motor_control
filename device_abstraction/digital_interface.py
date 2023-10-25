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
import imp
import xml.etree.ElementTree as ET
from collections import OrderedDict

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcDevI_DigitalInterfaceClass:
    def __init__(self, component):
        self.component = component

        # Get pin package details
        packageName = str(Database.getSymbolValue("core", "COMPONENT_PACKAGE"))

        pinout = ""
        children = (ATDF.getNode("/avr-tools-device-file/variants")).getChildren()
        for index in range(0, len(children)):
            if packageName in children[index].getAttribute("package"):
                pinout = children[index].getAttribute("pinout")

        # Get list of function_Maps
        self.function_Map = list()

        architecture = ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("architecture")

        if "MIPS" != architecture:

            pins = ATDF.getNode("/avr-tools-device-file/pinouts/pinout@[name=\"" + pinout + "\"]").getChildren()

            for pin in pins:
                pad = pin.getAttribute("pad")
                if pad.startswith("P"):
                    self.function_Map.append(pad)

        else:
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
            for item in pinFileContent.findall("pins/pin"):
                if item.attrib["name"].startswith("R"):
                    self.function_Map.append(item.attrib["name"])

        self.function_Map.append("** Select **")
        self.function_Map.sort()




