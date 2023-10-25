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
#                                     IMPORT                                            #
#---------------------------------------------------------------------------------------#
import xml.etree.ElementTree as ET
import os

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#
SupportedQEIIps = {
    "QDEC" : [
                { "name": "PDEC", "id": "U2263"},
                { "name": "TC", "id": "6082"},
                { "name": "QEI", "id": "01494"}
             ]
}

def getQEIIP(modules):
    for module in modules:
        for entry in SupportedQEIIps.get("QDEC", []):
            if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                return entry["name"], entry["id"]
    return "",""

#---------------------------------------------------------------------------------------#
#                                 Classes                                               #
#---------------------------------------------------------------------------------------#

class mcDevI_PositionInterfaceClass:
    def __init__(self, component):
        self.component = component

        # Read position interfaces from ATDF file
        self.mapForQea = dict()
        self.mapForQeb = dict()

        # Get ADC IP from the ATDF file
        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()
        self.name, self.id = getQEIIP(modules)

        # Create a symbol for ADC IP
        self.IP  = self.component.createStringSymbol("MCPMSMFOC_QEI_IP", None )
        self.IP.setLabel("QEI IP")
        self.IP.setValue( self.name + "_" + self.id)
        self.IP.setVisible(False)


        if ( self.name == "PDEC" ) and ( self.id == "U2263"):

            # Define the module path in the ATDF file
            module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"PDEC\"]"

            # Get all modules related to PDEC
            modules = ATDF.getNode(module_path).getChildren()

            # Initialize a dictionary to store information about pins and channels
            self.information = {}

            # Iterate through the modules
            for module in modules:
                unit = module.getAttribute("name")

                # Define the channel path for the current module
                channel_path = module_path + "/instance@[name=\"" + unit + "\"]/signals"

                # Get all channels for the current module
                channels = ATDF.getNode(channel_path).getChildren()

                # Initialize a sub-dictionary for the current unit
                self.information[unit] = {"QEA": {}, "QEB": {}, "QEI": {}}

                # Iterate through the channels
                for channel in channels:
                    pad = channel.getAttribute("pad")
                    index = channel.getAttribute("index")

                    # Append the pad to the appropriate list based on the index
                    if index == "0":
                        if index not in self.information[unit]["QEA"]:
                            self.information[unit]["QEA"][index] = []
                        self.information[unit]["QEA"][index].append(pad)
                    elif index == "1":
                        if index not in self.information[unit]["QEB"]:
                            self.information[unit]["QEB"][index] = []
                        self.information[unit]["QEB"][index].append(pad)
                    elif index == "2":
                        if index not in self.information[unit]["QEI"]:
                            self.information[unit]["QEI"][index] = []
                        self.information[unit]["QEI"][index].append(pad)

        elif ( self.name == "TC" ) and ( self.id == "6082"):

            # Define the module path in the ATDF file
            module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"TC\"]"

            # Get all modules related to PDEC
            modules = ATDF.getNode(module_path).getChildren()

            # Initialize a dictionary to store information about pins and channels
            self.information = {}

            # Iterate through the modules
            for module in modules:
                unit = module.getAttribute("name")

                # Define the channel path for the current module
                channel_path = module_path + "/instance@[name=\"" + unit + "\"]/signals"

                # Get all channels for the current module
                channels = ATDF.getNode(channel_path).getChildren()

                # Initialize a sub-dictionary for the current unit
                self.information[unit] = {"QEA": {}, "QEB":{}}

                # Iterate through the channels
                for channel in channels:
                    pad = channel.getAttribute("pad")
                    group = channel.getAttribute("group")
                    index = channel.getAttribute("index")

                    # Append the pad to the appropriate list based on the group and index
                    if group == "TIOA":
                        if index not in self.information[unit]["QEA"]:
                            self.information[unit]["QEA"][index] = []
                        self.information[unit]["QEA"][index].append(pad)

                    elif group == "TIOB":
                        if index not in self.information[unit]["QEB"]:
                            self.information[unit]["QEB"][index] = []
                        self.information[unit]["QEB"][index].append(pad)

        elif ( self.name == "QEI" ) and ( self.id == "01494"):
            # Load device XML
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

            familiesXmlName = deviceXmlRoot.get("families")
            familiesXmlPath = os.path.join(currentPath, "plugin/pin_xml/families/" + familiesXmlName + ".xml")
            familiesXmlPath = os.path.normpath(familiesXmlPath)

            pinFileContent = ET.fromstring((open(familiesXmlPath, "r")).read())

            self.information = {}
            for group in pinFileContent.findall("groups/group"):
                for function in group.findall("function"):
                    if function.attrib["name"].startswith("QEA"):
                        for pin in group.findall("pin"):
                            channel = self.numericFilter(function.attrib["name"])
                            unit = "QEI" + channel
                            pad = self.stringReplace(pin.attrib["name"])

                            if unit not in self.information:
                                self.information[unit] = {}

                            if "QEA" not in self.information[unit]:
                                self.information[unit]["QEA"] = {"CHANNEL":[]}

                            self.information[unit]["QEA"]["CHANNEL"].append(pad)

                    if function.attrib["name"].startswith("QEB"):
                        for pin in group.findall("pin"):
                            channel = self.numericFilter(function.attrib["name"])
                            unit = "QEI" + channel
                            pad = self.stringReplace(pin.attrib["name"])

                            if unit not in self.information:
                                self.information[unit] = {}

                            if "QEB" not in self.information[unit]:
                                self.information[unit]["QEB"] = {"CHANNEL":[]}

                            self.information[unit]["QEB"]["CHANNEL"].append(pad)

        else:
            self.information = {}

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def stringReplace( self, my_String ):
        my_String = my_String.replace("RP","R")
        return my_String

