# coding: utf-8
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

        module_path_eic = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"EIC\"]"  # Corrected module_path for EIC module
        modules_eic = ATDF.getNode(module_path_eic).getChildren()

        fault_channels = {'internal': {}, 'external': {}}

        # Iterate through modules
        for module in modules_eic:
            instance = module.getAttribute("name")
            signal_path = module_path_eic + "/instance@[name=\"" + instance + "\"]/signals"
            signals = ATDF.getNode(signal_path).getChildren()

            for signal in signals:
                if signal.getAttribute("group") == "EXTINT":
                    source = "EIC_CHANNEL_" + signal.getAttribute("index")
                    if source not in fault_channels['external'].keys():
                        fault_channels['external'][source] = [signal.getAttribute("pad")]
                    fault_channels['external'][source].append(signal.getAttribute("pad"))

        # Iterate through instances and channels to reorganize the data
        for instance, channels in information.items():
            pwm_channels = {}

            # Calculate the number of channels and split into "high" and "low"
            self.no_of_channels = len(channels) // 2
            for channel, pad_list in channels.items():
                if int(channel) < self.no_of_channels:
                    if channel not in pwm_channels:
                        pwm_channels[channel] = {}
                    pwm_channels[channel]["high"] = pad_list
                else:
                    new_channel = str(int(channel) - self.no_of_channels)
                    if new_channel not in pwm_channels:
                        pwm_channels[new_channel] = {}
                    pwm_channels[new_channel]["low"] = pad_list

            # Assign the final result to the class attribute
            if instance not in self.pwm_data['pwm_interface'].keys():
                self.pwm_data['pwm_interface'][instance] = {}
            self.pwm_data['pwm_interface'][instance] = pwm_channels

            # Update fault sources
            if instance not in self.pwm_data['pwm_interface'].keys():
                self.pwm_data['pwm_interface'][instance] = {'fault_sources':{'internal': {}, 'external': {}}}
            self.pwm_data['pwm_interface'][instance]['fault_sources'] = fault_channels

    def numeric_filter(self, input_String):
        digits = filter(str.isdigit, str(input_String))
        return "".join(digits)


    def fault_channel_get(self, instance, pad):

        fault_dict = self.pwm_data['pwm_interface'][instance]['fault_sources']['external']

        for channel, pad_list in fault_dict.items():
            if pad in pad_list:
                return 'EIC_CHANNEL_' + str(self.numeric_filter(channel))

        return ''

    def set_high_side_pwm_pin(self, name, instance, channel, pad):
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface'].keys():
            return

        # Check if the instance has the input channel
        if str(channel) not in self.pwm_data['pwm_interface'][instance].keys():
            return

        # Check if the pad is correct
        if pad not in self.pwm_data['pwm_interface'][instance][str(channel)]['high']:
            return

        mode = instance + "_WO" + self.numeric_filter(channel)

        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)

    def set_low_side_pwm_pin(self, name, instance, channel, pad):
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface'].keys():
            return

        # Check if the instance has the input channel
        if str(channel) not in self.pwm_data['pwm_interface'][instance].keys():
            return

        # Check if the pad is correct
        if pad not in self.pwm_data['pwm_interface'][instance][str(channel)]['low']:
            return

        mode = instance + "_WO" + str( int(self.numeric_filter(channel)) + self.no_of_channels )
        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)

    def set_fault_source(self, name, instance, channel, pad):
        for eic_channel, pad_list in (self.pwm_data['pwm_interface'][instance]['fault_sources']['external']).items():
           if pad in pad_list:
                mode = 'EIC_EXTINT' + self.numeric_filter(eic_channel)
                pin_manager_module = pin_manager.PinManager(self.object_wrapper)
                pin_manager_module.configurePin(pad, 'FAULT', mode)
