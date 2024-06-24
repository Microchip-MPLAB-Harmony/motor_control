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
        Variables = object_wrapper.get_variable_object()

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

        uart_channels = {}
        for group in pinFileContent.findall("groups/group"):
            for function in group.findall("function"):
                if function.attrib["name"].startswith("U") and function.attrib["name"].endswith("TX"):
                    for pin in group.findall("pin"):
                        instance = self.numeric_filter(function.attrib["name"])
                        unit = "UART" + instance
                        pad = (pin.attrib["name"]).replace('RP', 'R')
                        channel = self.numeric_filter(unit)

                        if unit not in uart_channels:
                            uart_channels[unit] = { 'transmit': {}, 'receive': {}}

                        if channel not in uart_channels[unit]['transmit'].keys():
                            uart_channels[unit]['transmit'][channel] = []

                        uart_channels[unit]['transmit'][channel].append(pad)

                if function.attrib["name"].startswith("U") and function.attrib["name"].endswith("RX"):
                    for pin in group.findall("pin"):
                        instance = self.numeric_filter(function.attrib["name"])
                        unit = "UART" + instance
                        pad = (pin.attrib["name"]).replace('RP', 'R')
                        channel = self.numeric_filter(unit)

                        if unit not in uart_channels:
                           uart_channels[unit] = { 'transmit': {}, 'receive': {}}

                        if channel not in uart_channels[unit]['receive'].keys():
                            uart_channels[unit]['receive'][channel] = []

                        uart_channels[unit]['receive'][channel].append(pad)

            self.uart_data['uart_interface'] = uart_channels

    def numeric_filter( self, input_String ):
        digits = filter(str.isdigit, str(input_String))
        return "".join(digits)

    def set_uart_transmit_pin( self, name, instance, channel, pad):
        print('UART pins', self.uart_data)
        if instance not in self.uart_data['uart_interface'].keys():
            return

        if pad not in self.uart_data['uart_interface'][instance]['transmit'][channel]:
            return

        mode = 'U' + str(channel) + 'TX'
        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)


    def set_uart_receive_pin( self, name, instance, channel, pad):
        if instance not in self.uart_data['uart_interface'].keys():
            return
        if pad not in self.uart_data['uart_interface'][instance]['receive'][channel]:
            return

        mode = 'U' + str(channel) + 'RX'
        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
        pin_manager_module.configurePin(pad, name, mode)