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
#                                 IMPORTS                                               #
#---------------------------------------------------------------------------------------#
import os.path

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
SupportedCommPorts = {
    "UART" : [
                { "name": "SERCOM", "id": "U2201"},
                { "name": "UART", "id": "6418"},
                { "name": "UART", "id": "02478"},
                { "name": "FLEXCOM", "id":"11268"}
             ],
    "CAN":   [
                { "name": "CAN", "id": "U2003"},
                { "name": "MCAN", "id": "11273"},
                { "name": "CAN", "id": "03247"},
             ],
    "TCP/IP":   [
             ]}

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcDevI_DataMonitorClass:
    def __init__(self, component):
        self.component = component

        # Get ADC IP from the ATDF file
        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()
        self.getCommunicationPorts(modules)
        self.name, self.id = self.getCommPortsIP(modules)

        if ( self.name == "SERCOM" ) and ( self.id == "U2201"):
            sercom_unit_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"SERCOM\"]"
            sercom_units = ATDF.getNode(sercom_unit_path).getChildren()

            self.information = {}

            # Iterate through SERCOM units
            for unit in sercom_units:
                unit_name = unit.getAttribute("name")

                self.information[unit_name] = {
                    "TRANSMIT": {"CHANNEL": []},
                    "RECEIVE": {"CHANNEL": []}
                }

                # Create a channel path specific to the current unit
                instance_path = sercom_unit_path + '/instance@[name="' + unit_name + '"]'
                channel_path = instance_path + "/signals"
                channels = ATDF.getNode(channel_path).getChildren()

                # Iterate through channels
                for channel in channels:
                    channel_index = channel.getAttribute("index")
                    channel_pad = channel.getAttribute("pad")

                    # Populate transmit and receive lists based on channel index
                    if channel_index == "0":
                        self.information[unit_name]["TRANSMIT"]["CHANNEL"].append(channel_pad)
                    elif channel_index == "1":
                        self.information[unit_name]["RECEIVE"]["CHANNEL"].append(channel_pad)

        elif ( self.name == "FLEXCOM" ) and ( self.id == "11268"):
            flexcom_unit_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"FLEXCOM\"]"
            flexcom_units = ATDF.getNode(flexcom_unit_path).getChildren()

            self.information = {}

            # Iterate through SERCOM units
            for unit in flexcom_units:
                unit_name = unit.getAttribute("name")

                self.information[unit_name] = {
                    "TRANSMIT": {"CHANNEL": []},
                    "RECEIVE": {"CHANNEL": []}
                }

                # Create a channel path specific to the current unit
                instance_path = flexcom_unit_path + '/instance@[name="' + unit_name + '"]'
                channel_path = instance_path + "/signals"
                channels = ATDF.getNode(channel_path).getChildren()

                # Iterate through channels
                for channel in channels:
                    channel_index = channel.getAttribute("index")
                    channel_pad = channel.getAttribute("pad")

                    # Populate transmit and receive lists based on channel index
                    if channel_index == "0":
                        self.information[unit_name]["TRANSMIT"]["CHANNEL"].append(channel_pad)
                    elif channel_index == "1":
                        self.information[unit_name]["RECEIVE"]["CHANNEL"].append(channel_pad)

        elif ( self.name == "UART" ) and ( self.id == "6418"):
            unit_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"UART\"]"
            units = ATDF.getNode(unit_path).getChildren()

            self.information = {}

            # Iterate through UART units
            for unit in units:
                unit_name = unit.getAttribute("name")

                # Create a channel path specific to the current unit
                instance_path = unit_path + '/instance@[name="' + unit_name + '"]'
                channel_path = instance_path + "/signals"
                channels = ATDF.getNode(channel_path).getChildren()

                # Initialize UART transmit and receive lists for the current unit
                self.information[unit_name] = {
                    "TRANSMIT": {"CHANNEL": []},
                    "RECEIVE": {"CHANNEL": []}
                }

                # Iterate through channels
                for channel in channels:
                    channel_group = channel.getAttribute("group")
                    channel_pad = channel.getAttribute("pad")

                    # Populate transmit and receive lists based on channel index
                    if channel_group == "UTXD":
                        self.information[unit_name]["TRANSMIT"]["CHANNEL"].append(channel_pad)
                    elif channel_group == "URXD":
                        self.information[unit_name]["RECEIVE"]["CHANNEL"].append(channel_pad)


        elif self.name == "UART" and self.id== "02478":
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
                    if function.attrib["name"].startswith("U") and function.attrib["name"].endswith("TX"):
                        for pin in group.findall("pin"):
                            instance = self.numericFilter(function.attrib["name"])
                            unit = "UART" + instance
                            pad = self.stringReplace(pin.attrib["name"])

                            if unit not in self.information:
                                self.information[unit] = {}

                            if "TRANSMIT" not in self.information[unit]:
                                self.information[unit]["TRANSMIT"] = {"CHANNEL":[]}

                            self.information[unit]["TRANSMIT"]["CHANNEL"].append(pad)

                    if function.attrib["name"].startswith("U") and function.attrib["name"].endswith("RX"):
                        for pin in group.findall("pin"):
                            instance = self.numericFilter(function.attrib["name"])
                            unit = "UART" + instance
                            pad = self.stringReplace(pin.attrib["name"])

                            if unit not in self.information:
                                self.information[unit] = {}

                            if "RECEIVE" not in self.information[unit]:
                                self.information[unit]["RECEIVE"] = {"CHANNEL":[]}

                            self.information[unit]["RECEIVE"]["CHANNEL"].append(pad)

    def getCommPortsIP(self, modules):
        for module in modules:
            for entry in SupportedCommPorts.get("UART", []):
                if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                    return entry["name"], entry["id"]
        return "",""

    def getCommunicationPorts(self, modules):
        self.physical_ports = []
        for module in modules:
            for entry in SupportedCommPorts.get("UART", []):
                if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                    self.physical_ports.append("UART")

            for entry in SupportedCommPorts.get("CAN", []):
                if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                    self.physical_ports.append("CAN")

            for entry in SupportedCommPorts.get("TCP/IP", []):
                if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                    self.physical_ports.append("TCP/IP")

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def stringReplace( self, my_String ):
        my_String = my_String.replace("RP","R")
        return my_String








