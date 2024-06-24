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
#                                     IMPORT                                            #
#---------------------------------------------------------------------------------------#
from device.gpio import pin_manager_pic32mk
import os
import xml.etree.ElementTree as ET

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 Classes                                               #
#---------------------------------------------------------------------------------------#

class AdapterService:
    """
        This function shall read QDEC IP data from device files and convert to following uniform format.
        QDEC:
        {
        'qdec_interface': {
                            'instance': {
                                            'channel': {
                                                           'qea': [ pad list for high channels],
                                                           'qeb': [ pad list for low channels],
                                                           'idx': [ pad list for low channels]
                                                        }

                                        }
                            }
        }
    """
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper

        self.qdec_data = {
                            'qdec_interface': {}
                         }
        self.adapter()

    def adapter(self):
        # Define the module path in the ATDF file
        module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"PDEC\"]"

        # Get all modules related to PDEC
        ATDF = self.object_wrapper.get_atdf_object()
        Variables = self.object_wrapper.get_variable_object()

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

        qdec_interface = {}
        for group in pinFileContent.findall("groups/group"):
            for function in group.findall("function"):
                if function.attrib["name"].startswith("QEA"):
                    for pin in group.findall("pin"):
                        channel = self.numeric_filter(function.attrib["name"])
                        instance = "QEI" + channel
                        pad = (pin.attrib["name"]).replace('RP', 'R')

                        if instance not in qdec_interface:
                            qdec_interface[instance] = {}

                        if channel not in qdec_interface[instance].keys():
                            qdec_interface[instance] = { channel: { 'qea': [], 'qeb': []}}

                        qdec_interface[instance][channel]['qea'].append(pad)

                if function.attrib["name"].startswith("QEB"):
                    for pin in group.findall("pin"):
                        channel = self.numeric_filter(function.attrib["name"])
                        instance = "QEI" + channel
                        pad = (pin.attrib["name"]).replace('RP', 'R')

                        if instance not in qdec_interface:
                            qdec_interface[instance] = {}

                        if channel not in qdec_interface[instance].keys():
                            qdec_interface[instance] = { channel: { 'qea': [], 'qeb': []}}

                        qdec_interface[instance][channel]['qeb'].append(pad)

            self.qdec_data['qdec_interface'] = qdec_interface

    def numeric_filter( self, input_String ):
        digits = filter(str.isdigit, str(input_String))
        return "".join(digits)

    def get_qdec_data(self):
        return self.qdec_data

    def set_qdec_pin(self, name, instance, channel, qea_pad, qeb_pad ):
        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)

        mode = "QEA" + str(channel)
        pin_manager_module.configurePin( qea_pad, name + "_QEA", mode)

        mode = "QEB" + str(channel)
        pin_manager_module.configurePin( qeb_pad, name + "_QEB", mode)