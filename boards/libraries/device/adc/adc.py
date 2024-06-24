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
import importlib

#---------------------------------------------------------------------------------------#
#                                  Global Variables                                     #
#---------------------------------------------------------------------------------------#
SupportedADCIps = {
    "ADC" : [
               { "name": "ADC",   "id": "U2247" },
               { "name": "ADC",   "id": "U2500" },
               { "name": "AFEC",  "id": "11147" },
               { "name": "ADCHS", "id": "02508" },
               { "name": "ADC",   "id": "44073" }
            ]
}

def getADCIP(modules):
    for module in modules:
        for entry in SupportedADCIps.get("ADC", []):
            if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                return entry["name"], entry["id"]
    return "",""

#---------------------------------------------------------------------------------------#
#                                      Classes                                          #
#---------------------------------------------------------------------------------------#
class AdcPeripheralClass:
    def __init__(self, object_wrapper ):
        # Get ADC IP from the ATDF file
        ATDF = object_wrapper.get_atdf_object()

        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()

        self.name, self.id = getADCIP(modules)

        module_name = self.name.lower() + '_' + self.id.lower()
        module = importlib.import_module('device.adc.' + module_name)
        self.adc = module.AdapterService(object_wrapper)

    """
    This API shall return ADC data in a uniform format.
    """
    def get_adc_data(self):
        return self.adc.adc_data

    def get_adc_units(self):
        # Get list of ADC channels from ADC data
        self.adc.adc_data["interfaces"].keys()

    def get_adc_channels(self, instance):
        self.adc.adc_data["interfaces"][instance].keys()

    def set_adc_interface(self, config_params ):
        # ToDO: Set ADC PLIB based on configuration data
        pass

    def get_adc_pad_and_pin(self):
        pass

    def set_adc_pin( self, name, instance, channel, pad):
        self.adc.set_adc_pin(name, instance, channel, pad)
