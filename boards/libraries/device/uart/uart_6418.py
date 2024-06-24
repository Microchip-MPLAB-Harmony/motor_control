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
        UART:
        {
            'max_baud_rate': 115200,
            'uart_interface': {
                                'instance': {
                                                'transmit': {
                                                                'channel':[]
                                                            },
                                                'receive':  {
                                                                'channel':[]
                                                            },
                                            }
        }
    """
    def __init__(self, object_wrapper):
        self.uart_data =  {
                            'max_baud_rate': 115200,
                            'uart_interface': {}
                         }

        # Update object_wrapper
        self.object_wrapper = object_wrapper

        # Adapter function
        self.adapter(object_wrapper)

    def adapter(self, object_wrapper):
        # Pad to PWM mapping
        ATDF = object_wrapper.get_atdf_object()
        module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"UART\"]"
        uart_instances = (ATDF.getNode(module_path)).getChildren()

        uart_channels = {}

        # Iterate through SERCOM units
        for module in uart_instances:
            instance = module.getAttribute("name")
            uart_channels[instance] = {}

            # Create a channel path specific to the current instance
            instance_path = module_path + '/instance@[name="' + instance + '"]'
            channel_path = instance_path + "/signals"
            channels = ATDF.getNode(channel_path).getChildren()

            for channel in channels:
                channel_group = str(channel.getAttribute("group"))
                channel_pad = str(channel.getAttribute("pad"))
                channel_num = str(channel.getAttribute("index"))

                if channel_num not in uart_channels[instance].keys():
                    uart_channels[instance][channel_num] = {
                                                            'transmit': [],
                                                            'receive':[]
                                                        }

                # Populate transmit and receive lists based on channel index
                if 'UTXD' in channel_group:
                    uart_channels[instance][channel_num]['transmit'].append(channel_pad)
                elif 'URXD' in channel_group:
                    uart_channels[instance][channel_num]['receive'].append(channel_pad)

            self.uart_data['uart_interface'] = uart_channels

    def set_uart_transmit_pin( self, name, instance, channel, pad):
        if instance not in self.uart_data['uart_interface'].keys():
            return

        if pad not in self.uart_data['uart_interface'][instance][channel]['transmit']:
            return

        mode = instance + '_UTXD' + str(channel)
        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)


    def set_uart_receive_pin( self, name, instance, channel, pad):
        if instance not in self.uart_data['uart_interface'].keys():
            return
        if pad not in self.uart_data['uart_interface'][instance][channel]['receive']:
            return

        mode = instance + '_URXD' + str(channel)
        pin_manager_module = pin_manager.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)