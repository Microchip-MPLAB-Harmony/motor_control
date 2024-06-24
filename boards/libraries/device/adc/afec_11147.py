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
from device.gpio import pin_manager

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

        # Define the path to the ADC module in ATDF file
        adc_module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"AFEC\"]"

        # Get all modules under the ADC module path
        modules = ATDF.getNode(adc_module_path).getChildren()

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

        # Iterate through each module
        for module in modules:
            instance = module.getAttribute("name")

            # Define the path to the interface signals for the current module
            interface_path = adc_module_path + "/instance@[name=\"" + instance + "\"]/signals"

            # Get all interface entries for the current module
            interfaces = ATDF.getNode(interface_path).getChildren()

            # Initialize a dictionary for the current module
            self.adc_data["analog_interfaces"][instance] = {}

            # Iterate through each entry in the interface
            for entry in interfaces:
                channel = entry.getAttribute("index")
                group = entry.getAttribute("group")
                pad = entry.getAttribute("pad")

                # Check if the entry belongs to the AD group and has a valid channel
                if channel is not None and group == "AD":
                    # Check if the channel key already exists in the module's dictionary
                    if channel in self.adc_data['analog_interfaces'][instance]:
                        self.adc_data['analog_interfaces'][instance][channel].append(pad)
                    else:
                        self.adc_data['analog_interfaces'][instance][channel] = [pad]

    def set_adc_pin( self, name, instance, channel, pad):
        channel_str = str(channel)
        if instance not in self.adc_data['analog_interfaces'].keys():
            return
        if channel_str not in self.adc_data['analog_interfaces'][instance].keys():
            return
        if pad not in self.adc_data['analog_interfaces'][instance][channel_str]:
            return

        mode = instance + "_AD" + channel_str
        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)