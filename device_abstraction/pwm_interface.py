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
#                                           IMPORT                                      #
#---------------------------------------------------------------------------------------#
import xml.etree.ElementTree as ET
import os

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#
SupportedPWMIps = {
    "PWM" : [
              { "name": "TCC", "id": "U2213"},
              { "name": "PWM", "id": "6343"},
              { "name": "MCPWM", "id": "01477"}
            ]
}

def getPWMIP(modules):
    for module in modules:
        for entry in SupportedPWMIps.get("PWM", []):
            if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                return entry["name"], entry["id"]
    return "",""

#---------------------------------------------------------------------------------------#
#                                     Classes                                           #
#---------------------------------------------------------------------------------------#
class mcDevI_PwmInterfaceClass:
    def __init__(self, component):
         """
    Description:
    This is initilaization function
    """
    def __init__(self, component):
        self.component = component

        # Get ADC IP from the ATDF file
        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()
        self.name, self.id = getPWMIP(modules)

        # Create a symbol for ADC IP
        self.IP  = self.component.createStringSymbol("MCPMSMFOC_PWM_IP", None )
        self.IP.setLabel("PWM IP")
        self.IP.setValue( self.name + "_" + self.id)
        self.IP.setVisible(False)

        if ( self.name == "PWM" ) and ( self.id == "6343"):
            # Pad to PWM mapping
            module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"PWM\"]"
            modules = ATDF.getNode(module_path).getChildren()

            # Initialize an empty dictionary to store information
            self.information = {}

            # Iterate through modules
            for module in modules:
                instance = module.getAttribute("name")
                signal_path = module_path + "/instance@[name=\"" + instance + "\"]/signals"
                signals = ATDF.getNode(signal_path).getChildren()

                # Initialize instance dictionary
                self.information[instance] ={}
                self.externalFaultSources = []

                # Iterate through signals and group by "WO" attribute
                for signal in signals:
                    group = signal.getAttribute("group")
                    pad = signal.getAttribute("pad")
                    channel = signal.getAttribute("index")

                    if "PWMFI" in group:
                        fault_source = "FAULT_PWM_ID" + channel
                        self.externalFaultSources.append(fault_source)

                    # Determine the polarity based on the "group" attribute
                    polarity = "high" if "PWMH" in group else "low" if "PWML" in group else None

                    # Skip signals that don't belong to PWMH or PWML groups
                    if polarity is None:
                        continue

                    # Initialize a dictionary for each channel if it doesn't exist
                    self.information.setdefault(instance, {}).setdefault(channel, {"high": [], "low": []})

                    # Append the pad to the appropriate polarity list
                    self.information[instance][channel][polarity].append(pad)

        elif ( self.name == "TCC" ) and ( self.id == "U2213"):
            # Pad to PWM mapping
            module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"TCC\"]"
            modules = ATDF.getNode(module_path).getChildren()

            # Initialize an empty dictionary to store information
            information = {}

            # Iterate through modules
            for module in modules:
                instance = module.getAttribute("name")
                signal_path = module_path + "/instance@[name=\"" + instance + "\"]/signals"
                signals = ATDF.getNode(signal_path).getChildren()

                # Initialize a dictionary for the current instance
                instance_info = {}

                # Iterate through signals and group by "WO" attribute
                for signal in signals:
                    if "WO" == signal.getAttribute("group"):
                        pad = signal.getAttribute("pad")
                        channel = signal.getAttribute("index")

                        # Initialize a list for each channel if not exists
                        if channel not in instance_info:
                            instance_info[channel] = []

                        instance_info[channel].append(pad)

                # Filter out instances with fewer than 6 channels
                if len(instance_info) >= 6:
                    information[instance] = instance_info

            # Initialize a new dictionary for the final result
            result_information = {}

            # Iterate through instances and channels to reorganize the data
            for instance, channels in information.items():
                result_information[instance] = {}

                # Calculate the number of channels and split into "high" and "low"
                self.no_of_channels = len(channels) // 2
                for channel, pad_list in channels.items():
                    if int(channel) < self.no_of_channels:
                        if channel not in result_information[instance]:
                            result_information[instance][channel] = {}
                        result_information[instance][channel]["high"] = pad_list
                    else:
                        new_channel = str(int(channel) - self.no_of_channels)
                        if new_channel not in result_information[instance]:
                            result_information[instance][new_channel] = {}
                        result_information[instance][new_channel]["low"] = pad_list


            # Assign the final result to the class attribute
            self.information = result_information

            module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"EIC\"]"
            modules = ATDF.getNode(module_path).getChildren()

            self.externalFaultSources = []

            # Iterate through modules
            for module in modules:
                instance = module.getAttribute("name")
                signal_path = module_path + "/instance@[name=\"" + instance + "\"]/signals"
                signals = ATDF.getNode(signal_path).getChildren()

                for signal in signals:
                    if signal.getAttribute("group") == "EXTINT":
                        source =  "EIC_CHANNEL_" + signal.getAttribute("index")

                        if source not in self.externalFaultSources:
                            self.externalFaultSources.append(source)

        elif ( self.name == "MCPWM" ) and ( self.id == "01477"):
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

            pinFileContent = ET.fromstring((open(pinoutXmlPath, "r")).read())
            self.information = {}
            for item in pinFileContent.findall("pins/pin"):
                for function in item.findall("function"):
                    channel_Name = function.attrib["name"]
                    if channel_Name.startswith("PWM") and channel_Name.endswith("L"):
                        unit = "MCPWM"
                        # channel = self.numericFilter(function.attrib["name"])
                        channel = self.numericFilter(function.attrib["name"])
                        pad = item.attrib["name"] # self.stringReplace(item.attrib["name"])

                        if unit not in self.information:
                            self.information[unit] = {}

                        if channel not in self.information[unit]:
                            self.information[unit][channel] = {}

                        if "low" not in self.information[unit][channel]:
                            self.information[unit][channel]["low"] = []

                        self.information[unit][channel]["low"].append(pad)

                    elif channel_Name.startswith("PWM") and channel_Name.endswith("H"):
                        unit = "MCPWM"
                        # channel = self.numericFilter(function.attrib["name"])
                        channel = self.numericFilter(function.attrib["name"])
                        pad = item.attrib["name"] # self.stringReplace(item.attrib["name"])

                        if unit not in self.information:
                            self.information[unit] = {}

                        if channel not in self.information[unit]:
                            self.information[unit][channel] = {}

                        if "high" not in self.information[unit][channel]:
                            self.information[unit][channel]["high"] = []

                        self.information[unit][channel]["high"].append(pad)

            # PWM Fault external sources
            register_name = "IOCON1__FLTSRC"
            value_group_path = self.getValueGroupPath("MCPWM", register_name)
            values = ATDF.getNode(value_group_path).getChildren()

            self.externalFaultSources = []

            for value in values:
                self.externalFaultSources.append(value.getAttribute("caption"))

            self.externalFaultSources.sort()

            # PWM Fault internal sources
    def getRegisterPath(self, ModuleName, RegisterName):
        labelPath = str('/avr-tools-device-file/modules/module@[name="'
                       + ModuleName + '"]/register-group@[name="'
                       + ModuleName + '"]/register@[name="'
                       + RegisterName + '"]')
        return labelPath

    def getRegisterBitfieldPath(self, ModuleName, RegisterName, BitfieldName):
        labelPath = str('/avr-tools-device-file/modules/module@[name="' +
            ModuleName + '"]/register-group@[name="' + ModuleName +
            '"]/register@[name="' + RegisterName + '"]/bitfield@[name="'
            + BitfieldName +'"]')
        return labelPath

    def getValueGroupPath(self, ModuleName, ValueGroupName):
        value_groupPath = str('/avr-tools-device-file/modules/module@[name="'
            + ModuleName + '"]/value-group@[name="' + ValueGroupName + '"]')
        return value_groupPath

    def getValueGroupValuePath(self, ModuleName, ValueGroupName, ValueString):
        valuePath = str('/avr-tools-device-file/modules/module@[name="' + ModuleName
            + '"]/value-group@[name="' + ValueGroupName + '"]/value@[value="' +
            ValueString + '"]')
        return valuePath

    """
    Description:
    This function discards alphabets and returns the numbers only
    """
    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def stringReplace( self, my_String ):
        my_String = my_String.replace("RP","R")
        return my_String
