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
        module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"PWM\"]"
        modules = ATDF.getNode(module_path).getChildren()

        # Initialize an empty dictionary to store information
        information = {}

        # Iterate through modules
        pwm_channels = {}
        fault_channels = {}
        for module in modules:
            instance = module.getAttribute("name")
            signal_path = module_path + "/instance@[name=\"" + instance + "\"]/signals"
            signals = ATDF.getNode(signal_path).getChildren()

            # Initialize a dictionary for the current instance
            pwm_channels[instance] = {}
            fault_channels[instance] = { 'external': {}, 'internal':{}}

            # Iterate through signals and group by "WO" attribute
            for signal in signals:
                if "PWMH" in signal.getAttribute("group"):
                    pad = signal.getAttribute("pad")
                    channel = signal.getAttribute("index")

                    # Initialize a list for each channel if not exists
                    if channel not in pwm_channels[instance]:
                        pwm_channels[instance][channel] = {'high': [], 'low':[]}
                    pwm_channels[instance][channel]['high'].append(pad)

                elif "PWML" in signal.getAttribute("group"):
                    pad = signal.getAttribute("pad")
                    channel = signal.getAttribute("index")

                    # Initialize a list for each channel if not exists
                    if channel not in pwm_channels[instance]:
                        pwm_channels[instance][channel] = {'high': [], 'low':[]}
                    pwm_channels[instance][channel]['low'].append(pad)

                elif "PWMFI" in signal.getAttribute("group"):
                    pad = signal.getAttribute("pad")
                    channel = signal.getAttribute("index")
                    if channel not in pwm_channels[instance]:
                        fault_channels[instance]['external'][channel] = []
                    fault_channels[instance]["external"][channel].append(pad)

            self.pwm_data['pwm_interface']['output'] = pwm_channels
            self.pwm_data['pwm_interface']['faults'] = fault_channels

    def numeric_filter(self, input_String):
        digits = filter(str.isdigit, str(input_String))
        return "".join(digits)


    def fault_channel_get(self, instance, pad):
        fault_dict = self.pwm_data['pwm_interface']['faults'][instance]['external']

        for channel, pad_list in fault_dict.items():
            if pad in pad_list:
                return "FAULT_PWM_ID" + str(self.numeric_filter(channel))
        return ''

    def set_high_side_pwm_pin(self, name, instance, channel, pad):
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface']['output'].keys():
            return

        # Check if the instance has the input channel
        if str(channel) not in self.pwm_data['pwm_interface']['output'][instance].keys():
            return

        # Check if the pad is correct
        if pad not in self.pwm_data['pwm_interface']['output'][instance][str(channel)]['high']:
            return

        mode = instance + "_" + "PWMC" + self.numeric_filter(instance) + "_PWMH" + str(channel)

        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)

    def set_low_side_pwm_pin(self, name, instance, channel, pad):
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface']['output'].keys():
            return

        # Check if the instance has the input channel
        if str(channel) not in self.pwm_data['pwm_interface']['output'][instance].keys():
            return

        # Check if the pad is correct
        if pad not in self.pwm_data['pwm_interface']['output'][instance][str(channel)]['low']:
            return

        mode = instance + "_" + "PWMC" + self.numeric_filter(instance) + "_PWML" + str(channel)
        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)

    def set_fault_source(self, name, instance, channel, pad):
        # Check if instance of TCC is present
        if instance not in self.pwm_data['pwm_interface']['output'].keys():
            return

        # Get PWM fault channel from pad
        for channel, pad_list in self.pwm_data['pwm_interface']['faults'][instance]["external"].items():
            if pad in pad_list:
                mode = instance + "_" + "PWMC" + self.numeric_filter(instance) + "_PWMFI" + str(channel)

                pin_manager_module = pin_manager.PinManager(self.object_wrapper)
                pin_manager_module.configurePin(pad, name, mode)
                break







