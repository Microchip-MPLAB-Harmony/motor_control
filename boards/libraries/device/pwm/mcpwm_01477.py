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
from device.gpio import pin_manager_pic32mk
import os
import xml.etree.ElementTree as ET

#---------------------------------------------------------------------------------------#
#                                      Classes                                          #
#---------------------------------------------------------------------------------------#

class AdapterService:
    """
        This function shall read ADC IP data from device files and convert to following uniform format.
        PWM:
        {
        'resolution': '',
        'pwm_interface': {
                            'instance': {
                                            'channel': {
                                                        'high': [ pad list for high channels],
                                                        'low': [ pad list for low channels]
                                                        },
                                            'fault_source': {
                                                        'internal': {
                                                                        'source' : [ pad list]
                                                                    },
                                                        'external': {
                                                                        'source' : [ pad list]
                                                                    },
                                                        }

                                        }
                            }
        }
    """
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper
        self.pwm_data =  {
                            'resolution': '',
                            'pwm_interface': {}
                         }

        # Adapter function
        self.adapter(object_wrapper)

    def adapter(self, object_wrapper):
        ATDF = object_wrapper.get_atdf_object()
        Variables = object_wrapper.get_variable_object()

        # Pad to PWM mapping
        module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"MCPWM\"]"
        modules = ATDF.getNode(module_path).getChildren()

        # Iterate through modules
        pwm_channels = {}
        fault_channels = {}

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
        pwm_channels = {}
        for item in pinFileContent.findall("pins/pin"):
            for function in item.findall("function"):
                channel_Name = function.attrib["name"]
                if channel_Name.startswith("PWM") and channel_Name.endswith("L"):
                    channel = self.numeric_filter(function.attrib["name"])
                    pad = item.attrib["name"] # self.stringReplace(item.attrib["name"])

                    if channel not in pwm_channels:
                        pwm_channels[channel] = {}

                    if "low" not in pwm_channels[channel]:
                        pwm_channels[channel]["low"] = []

                    pwm_channels[channel]["low"].append(pad)

                elif channel_Name.startswith("PWM") and channel_Name.endswith("H"):
                    channel = self.numeric_filter(function.attrib["name"])
                    pad = item.attrib["name"] # self.stringReplace(item.attrib["name"])

                    if channel not in pwm_channels:
                        pwm_channels[channel] = {}

                    if "high" not in pwm_channels[channel]:
                        pwm_channels[channel]["high"] = []

                    pwm_channels[channel]["high"].append(pad)

        # PWM Fault external sources
        register_name = "IOCON1__FLTSRC"
        value_group_path = self.getValueGroupPath("MCPWM", register_name)
        values = ATDF.getNode(value_group_path).getChildren()
        fault_channels = {'internal': {}, 'external': {}}

        for item in pinFileContent.findall("pins/pin"):
            for function in item.findall("function"):
                channel_Name = function.attrib["name"]
                if channel_Name.startswith("FLT"):
                    channel = self.numeric_filter(channel_Name)
                    pad = item.attrib["name"]

                    if channel not in fault_channels['external'].keys():
                        fault_channels['external'][channel] = []

                    fault_channels['external'][channel].append(pad)
        
        instance = 'MCPWM'
        if instance not in self.pwm_data.keys():
            self.pwm_data['pwm_interface']['MCPWM'] = { 'fault': {}, 'output': {}}
            
        self.pwm_data['pwm_interface']['MCPWM']['fault'] = fault_channels
        self.pwm_data['pwm_interface']['MCPWM']['output'] = pwm_channels

    def fault_channel_get(self, instance, pad):
        fault_dict = self.pwm_data['pwm_interface']['MCPWM']['fault']['external']

        for channel, pad_list in fault_dict.items():
            if pad in pad_list:
                return 'FLT' + str(self.numeric_filter(channel))
        return ''

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
    def numeric_filter( self, input_String ):
        digits = filter(str.isdigit, str(input_String))
        return "".join(digits)

    def stringReplace( self, my_String ):
        my_String = my_String.replace("RP","R")
        return my_String

    def numeric_filter(self, input_String):
        digits = filter(str.isdigit, str(input_String))
        return "".join(digits)

    def set_high_side_pwm_pin(self, name, instance, channel, pad):
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface'].keys():
            return

        # Check if the instance has the input channel
        if str(channel) not in self.pwm_data['pwm_interface'][instance]['output'].keys():
            return

        # Check if the pad is correct
        if pad not in self.pwm_data['pwm_interface'][instance]['output'][str(channel)]['high']:
            return

        mode = "PWM" + str(channel) + "H"

        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)

    def set_low_side_pwm_pin(self, name, instance, channel, pad):
        print('Check point 0 ', self.pwm_data)
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface'].keys():
            print('Check point', 1)
            return

        # Check if the instance has the input channel
        if str(channel) not in self.pwm_data['pwm_interface'][instance]['output'].keys():
            print('Check point', 2)
            return

        # Check if the pad is correct
        if pad not in self.pwm_data['pwm_interface'][instance]['output'][str(channel)]['low']:
            print('Check point', 3)
            return

        mode = "PWM" + str(channel) + "L"
        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)

    def set_fault_source(self, name, instance, channel, pad):
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface'].keys():
            return

        # Get PWM fault channel from pad
        for channel, pad_list in self.pwm_data['pwm_interface'][instance]['fault']["external"].items():
            if pad in pad_list:
                mode = 'FLT' + str(channel)

                pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
                pin_manager_module.configurePin(pad, name, mode)
                return








