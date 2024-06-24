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
import importlib

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#
SupportedQEIIps = {
    "QDEC" : [
                { "name": "PDEC", "id": "U2263"},
                { "name": "TC", "id": "6082"},
                { "name": "QEI", "id": "01494"}
             ]
}

def getQEIIP(modules):
    for module in modules:
        for entry in SupportedQEIIps.get("QDEC", []):
            if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                return entry["name"], entry["id"]
    return "",""

#---------------------------------------------------------------------------------------#
#                                 Classes                                               #
#---------------------------------------------------------------------------------------#

class QdecPeripheral:
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper

        # Get ADC IP from the ATDF file
        ATDF = object_wrapper.get_atdf_object()

        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()
        self.name, self.id = getQEIIP(modules)

        # Load QDEC library
        module_name = self.name.lower() + '_' + self.id.lower()
        module = importlib.import_module('device.qdec.' + module_name)
        self.qdec = module.AdapterService(object_wrapper)

    def get_qdec_data(self):
        pass

    def set_qdec_pin(self, name, instance, channel, qea_pad, qeb_pad):
        self.qdec.set_qdec_pin(name, instance, channel, qea_pad, qeb_pad )