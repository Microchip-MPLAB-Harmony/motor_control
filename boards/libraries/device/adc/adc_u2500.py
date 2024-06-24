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
#                                  Global Variables                                     #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                      Classes                                          #
#---------------------------------------------------------------------------------------#

class AdapterService:
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper
        self.adc_adapter(object_wrapper)

    def adc_adapter(self, object_wrapper):
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

        # Define the path to the ADC module in ATDF
        ATDF = object_wrapper.get_atdf_object()
        adc_module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"ADC\"]"
        modules = ATDF.getNode(adc_module_path).getChildren()

        # Initialize dictionaries to store function list and function names
        function_list = {}
        self.function_name = {}

        # Iterate through each module to extract PAD to ADC mapping
        for module in modules:
            instance = module.getAttribute("name")
            self.function_name[instance] = {}
            self.adc_data['analog_interfaces'][instance] = {}

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
                    if channel in self.adc_data['analog_interfaces'][instance]:
                        self.adc_data['analog_interfaces'][instance][channel].append(pad)
                    else:
                        self.adc_data['analog_interfaces'][instance][channel] = [pad]

        self.adc_data['resolution'] = ["12", "16", "10", "8"]

    def set_adc_pin( self, name, instance, channel, pad):
        if instance not in self.function_name.keys():
            return
        if pad not in self.function_name[instance].keys():
            return

        mode = instance + "_" + self.function_name[instance][pad]
        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)









