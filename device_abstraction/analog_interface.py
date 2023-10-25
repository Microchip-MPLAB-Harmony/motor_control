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
#                                     Imports                                           #
#---------------------------------------------------------------------------------------#
import xml.etree.ElementTree as ET
import os
import copy

#---------------------------------------------------------------------------------------#
#                                  Global Variables                                     #
#---------------------------------------------------------------------------------------#
SupportedADCIps = {
    "ADC" : [
               { "name": "ADC",   "id": "U2247" },
               { "name": "ADC",   "id": "U2500" },
               { "name": "AFEC",  "id": "11147" },
               { "name": "ADCHS", "id": "02508" },
               { "name": "ADC",   "id": "44073" }
            ]
}

def getADCIP(modules):
    for module in modules:
        for entry in SupportedADCIps.get("ADC", []):
            if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                return entry["name"], entry["id"]
    return "",""

#---------------------------------------------------------------------------------------#
#                                      Classes                                          #
#---------------------------------------------------------------------------------------#

class mcDevI_AnalogInterfaceClass:
    def __init__(self, component ):
        self.component = component

        # Get ADC IP from the ATDF file
        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()

        self.name, self.id = getADCIP(modules)


        # Create a symbol for ADC IP
        self.IP  = self.component.createStringSymbol("MCPMSMFOC_ADC_IP", None )
        self.IP.setLabel("ADC IP")

        self.IP.setValue( self.name + "_" + self.id)
        self.IP.setVisible(False)

        self.function_Map  = { "** Select **":[] }

        if ( self.name == "ADCHS" ) and ( self.id == "02508"):

            # Initialize dictionaries
            channel_to_pad_map = {}

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

            self.pinFileContent = ET.fromstring(open(pinoutXmlPath, "r").read())

            # Populate map_ANALOG_CHANNEL_TO_PAD
            for item in self.pinFileContent.findall("pins/pin"):
                for function in item.findall("function"):
                    if function.attrib["name"].startswith("AN"):
                        pad = item.attrib["name"]
                        channel_to_pad_map[self.numericFilter(function.attrib["name"])] = pad

            # Initialize variables and data structures
            instance_list = []
            self.information = {}

            ADC_Max_DedicatedChannels = 0

            # Get information from ATDF
            register_path = ATDF.getNode(self.adchsATDFRegisterPath("ADCHS", "ADCCON3"))
            bitfields = register_path.getChildren()

            # Extract dedicated channels
            for bitfield in bitfields:
                if "DIGEN" in bitfield.getAttribute("name") and bitfield.getAttribute("values") is not None:
                    if bitfield.getAttribute("values")[-1] != '7':
                        instance_list.append(bitfield.getAttribute("values")[-1])  # Append the last digit

            # Process dedicated channels
            for channel_number in instance_list:
                labelPath = self.adchsATDFRegisterBitfieldPath("ADCHS", "ADCCON3", "DIGEN" + str(channel_number))
                labelNode = ATDF.getNode(labelPath).getAttribute("values")

                if labelNode is not None:
                    ADC_Max_DedicatedChannels += 1
                    RegisterName = "ADCTRGMODE__SH" + str(channel_number) + "ALT"
                    value_group_path = self.adchsATDFValueGroupPath("ADCHS", RegisterName)
                    values = ATDF.getNode(value_group_path).getChildren()
                    adc_unit = "ADC" + str(channel_number)
                    self.information[adc_unit] = {}

                    for value in values:
                        analog_channel = self.numericFilter(value.getAttribute("caption"))
                        pad = channel_to_pad_map[analog_channel]
                        if analog_channel in self.information[adc_unit]:
                            self.information[adc_unit][analog_channel].append(pad)
                        else:
                            self.information[adc_unit][analog_channel] = [pad]

            # Process shared channels
            signal_number = 0
            MAX_AVAILABLE_SIGNALS = 64
            adc_unit = "ADC7"
            self.information[adc_unit] = {}
            for signal_number in range(ADC_Max_DedicatedChannels, MAX_AVAILABLE_SIGNALS):
                label_path = self.adchsATDFRegisterPath("ADCHS", "ADCDATA" + str(signal_number))
                label_node = ATDF.getNode(label_path)

                if label_node is not None:
                    channel = str(signal_number)

                    if channel in channel_to_pad_map:
                        pad = channel_to_pad_map[channel]
                        if channel in self.information[adc_unit]:
                            self.information[adc_unit][channel].append(pad)
                        else:
                            self.information[adc_unit][channel] = [pad]

            self.resolution = ["12", "10", "8", "6"]

        elif ( self.name == "AFEC" ) and ( self.id == "11147"):
            # Define the path to the ADC module in ATDF file
            adc_module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"AFEC\"]"

            # Get all modules under the ADC module path
            modules = ATDF.getNode(adc_module_path).getChildren()

            # Initialize a dictionary to store PAD to ADC mapping information
            self.information = {}

            # Iterate through each module
            for module in modules:
                instance = module.getAttribute("name")

                # Define the path to the interface signals for the current module
                interface_path = adc_module_path + "/instance@[name=\"" + instance + "\"]/signals"

                # Get all interface entries for the current module
                interfaces = ATDF.getNode(interface_path).getChildren()

                # Initialize a dictionary for the current module
                self.information[instance] = {}

                # Iterate through each entry in the interface
                for entry in interfaces:
                    channel = entry.getAttribute("index")
                    group = entry.getAttribute("group")
                    pad = entry.getAttribute("pad")

                    # Check if the entry belongs to the AD group and has a valid channel
                    if channel is not None and group == "AD":
                        # Check if the channel key already exists in the module's dictionary
                        if channel in self.information[instance]:
                            self.information[instance][channel].append(pad)
                        else:
                            self.information[instance][channel] = [pad]

            self.resolution = ["12", "13", "14", "15", "16"]

        elif ( self.name == "ADC" ) and ( self.id == "44073"):
            # Define the path to the ADC module in ATDF file
            adc_module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"ADC\"]"

            # Get all modules under the ADC module path
            modules = ATDF.getNode(adc_module_path).getChildren()

            # Initialize a dictionary to store PAD to ADC mapping information
            self.information = {}

            # Iterate through each module
            for module in modules:
                instance = module.getAttribute("name")

                # Define the path to the interface signals for the current module
                interface_path = adc_module_path + "/instance@[name=\"" + instance + "\"]/signals"

                # Get all interface entries for the current module
                interfaces = ATDF.getNode(interface_path).getChildren()

                # Initialize a dictionary for the current module
                self.information[instance] = {}

                # Iterate through each entry in the interface
                for entry in interfaces:
                    channel = entry.getAttribute("index")
                    group = entry.getAttribute("group")
                    pad = entry.getAttribute("pad")

                    # Check if the entry belongs to the AD group and has a valid channel
                    if channel is not None and group == "AD":
                        # Check if the channel key already exists in the module's dictionary
                        if channel in self.information[instance]:
                            self.information[instance][channel].append(pad)
                        else:
                            self.information[instance][channel] = [pad]

            self.resolution = ["12", "13", "14", "15", "16"]



        elif ( self.name == "ADC" ) and (( self.id == "U2500") or ( self.id == "U2247")):
            # Initialize a dictionary to store PAD to ADC mapping information
            self.information = {}

            # Define the path to the ADC module in ATDF
            adc_module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"ADC\"]"
            modules = ATDF.getNode(adc_module_path).getChildren()

            # Initialize dictionaries to store function list and function names
            function_list = {}
            self.function_name = {}

            # Iterate through each module to extract PAD to ADC mapping
            for module in modules:
                instance = module.getAttribute("name")
                self.function_name[instance] = {}
                self.information[instance] = {}

                # Define the path to the interface signals for the current module
                interface_path = "/".join([adc_module_path, "instance@[name=\"" + instance + "\"]", "signals"])
                interfaces = ATDF.getNode(interface_path).getChildren()

                # Initialize dictionaries to store function list and function names
                function_list = {}

                # Iterate through each entry in the interface signals
                for entry in interfaces:
                    pad = entry.getAttribute("pad")

                    if entry.getAttribute("index") is not None:
                        function = entry.getAttribute("group") + entry.getAttribute("index")
                    else:
                        function = entry.getAttribute("group")

                    # Add the function to the list associated with the PAD
                    if pad in function_list:
                        function_list[pad].append(function)
                    else:
                        function_list[pad] = [function]

                    # Store the concatenated function names for the PAD
                    self.function_name[instance][pad] = '/'.join(function_list[pad])

                # Iterate through the interface signals again to find AIN channels
                for entry in interfaces:
                    if entry.getAttribute("group") == "AIN":
                        pad = entry.getAttribute("pad")
                        channel = entry.getAttribute("index")

                        # Create or append to the AIN channel list for the current instance
                        if channel in self.information[instance]:
                            self.information[instance][channel].append(pad)
                        else:
                            self.information[instance][channel] = [pad]

            self.resolution = ["12", "16", "10", "8"]

    def adchsATDFRegisterPath(self, ModuleName, RegisterName):
        labelPath = str('/avr-tools-device-file/modules/module@[name="'
                       + ModuleName + '"]/register-group@[name="'
                       + ModuleName + '"]/register@[name="'
                       + RegisterName + '"]')
        return labelPath

    def adchsATDFRegisterBitfieldPath(self, ModuleName, RegisterName, BitfieldName):
        labelPath = str('/avr-tools-device-file/modules/module@[name="' +
            ModuleName + '"]/register-group@[name="' + ModuleName +
            '"]/register@[name="' + RegisterName + '"]/bitfield@[name="'
            + BitfieldName +'"]')
        return labelPath

    def adchsATDFValueGroupPath(self, ModuleName, ValueGroupName):
        value_groupPath = str('/avr-tools-device-file/modules/module@[name="'
            + ModuleName + '"]/value-group@[name="' + ValueGroupName + '"]')
        return value_groupPath

    def adchsATDFValueGroupValuePath(self, ModuleName, ValueGroupName, ValueString):
        valuePath = str('/avr-tools-device-file/modules/module@[name="' + ModuleName
            + '"]/value-group@[name="' + ValueGroupName + '"]/value@[value="' +
            ValueString + '"]')
        return valuePath

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)







