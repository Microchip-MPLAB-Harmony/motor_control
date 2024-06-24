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
from device.gpio import pin_manager_pic32mk

#---------------------------------------------------------------------------------------#
#                                      Classes                                          #
#---------------------------------------------------------------------------------------#

class AdapterService:
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper
        self.adc_adapter(object_wrapper)

    def adc_adapter(self, object_wrapper):
        # Define the path to the ADC module in ATDF
        ATDF = object_wrapper.get_atdf_object()

        # Initialize a dictionary to store PAD to ADC mapping adc_data
        self.adc_data = {
            "resolution": [],
            "ref_voltage": [],
            "max_sampling_rate": "",
            "analog_interfaces": {},
            "conversion_modes": [],
            "conversion_trigger": {
                "software_trigger": "",
                "hardware_trigger": []
            }
        }

        # ToDO: Update reference voltage options
        self.adc_data["ref_voltage"] = []

        # ToDO: Update maximum sampling rate in MSPS
        self.adc_data["max_sampling_rate"] = 1

        # ToDO: Update conversion modes
        self.adc_data["conversion_modes"] = []

        # ToDO: Update software and hardware triggers

        # Update ADC resolution options
        self.adc_data["resolution"] = ["12", "13", "14", "15", "16"]

        # Initialize dictionaries
        channel_to_pad_map = {}

        # Load device XML
        for module in ATDF.getNode("/avr-tools-device-file/modules").getChildren():
            if module.getAttribute("name") == "GPIO":
                GPIO = module.getAttribute("name").lower() + "_" + module.getAttribute("id").lower()
                break

        # Get variable object
        Variables = self.object_wrapper.get_variable_object()
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
                    channel_to_pad_map[self.numeric_filter(function.attrib["name"])] = pad

        # Initialize variables and data structures
        instance_list = []
        information = {}

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
                information[adc_unit] = {}

                for value in values:
                    analog_channel = self.numeric_filter(value.getAttribute("caption"))
                    pad = channel_to_pad_map[analog_channel]
                    if analog_channel in information[adc_unit]:
                        information[adc_unit][analog_channel].append(pad)
                    else:
                        information[adc_unit][analog_channel] = [pad]

        # Process shared channels
        signal_number = 0
        MAX_AVAILABLE_SIGNALS = 64
        adc_unit = "ADC7"
        information[adc_unit] = {}
        for signal_number in range(ADC_Max_DedicatedChannels, MAX_AVAILABLE_SIGNALS):
            label_path = self.adchsATDFRegisterPath("ADCHS", "ADCDATA" + str(signal_number))
            label_node = ATDF.getNode(label_path)

            if label_node is not None:
                channel = str(signal_number)

                if channel in channel_to_pad_map:
                    pad = channel_to_pad_map[channel]
                    if channel in information[adc_unit]:
                        information[adc_unit][channel].append(pad)
                    else:
                        information[adc_unit][channel] = [pad]

        self.adc_data["analog_interfaces"] = information

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

    def numeric_filter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)


    def set_adc_pin( self, name, instance, channel, pad):
        channel_str = str(channel)
        if instance not in self.adc_data['analog_interfaces'].keys():
            return
        if channel_str not in self.adc_data['analog_interfaces'][instance].keys():
            return
        if pad not in self.adc_data['analog_interfaces'][instance][channel_str]:
            return

        mode = "AN" + channel_str
        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)





