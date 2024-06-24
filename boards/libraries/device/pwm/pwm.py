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
#                                           IMPORT                                      #
#---------------------------------------------------------------------------------------#
import importlib

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#
SupportedPWMIps = {
    "PWM" : [
              { "name": "TCC", "id": "U2213", "version":"3.0.0"},
              { "name": "TCC", "id": "U2213", "version":"3.1.0"},
              { "name": "PWM", "id": "6343", "version":"Y"},
              { "name": "PWM", "id": "6343", "version":"ZB"},
              { "name": "MCPWM", "id": "01477", "version":""}
            ]
}

def getPWMIP(modules):
    for module in modules:
        for entry in SupportedPWMIps.get("PWM", []):
            if ( entry["name"] == module.getAttribute("name") and
                 entry["id"] == module.getAttribute("id") and
                 entry["version"] == module.getAttribute("version")):

                return entry["name"], entry["id"], entry["version"]
    return "","", ""

#---------------------------------------------------------------------------------------#
#                                     Classes                                           #
#---------------------------------------------------------------------------------------#
class PwmPeripheral:
    """
    Description:
    This is initilaization function
    """
    def __init__(self, object_wrapper):
        # Get ADC IP from the ATDF file
        ATDF = object_wrapper.get_atdf_object()
        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()
        self.name, self.id, self.version = getPWMIP(modules)

        if self.version != "":
            module_name = self.name.lower() + '_' + self.id.lower() + "_" + (self.version.lower()).replace(".", "-")
        else:
            module_name = self.name.lower() + '_' + self.id.lower()

        module = importlib.import_module('device.pwm.'+ module_name)
        self.pwm = module.AdapterService(object_wrapper)

    def fault_channel_get(self, instance, pad):
        return self.pwm.fault_channel_get(instance, pad)

    def set_high_side_pwm_pin( self, name, instance, channel, pad):
        self.pwm.set_high_side_pwm_pin(name, instance, channel, pad)

    def set_low_side_pwm_pin( self, name, instance, channel, pad):
        self.pwm.set_low_side_pwm_pin(name, instance, channel, pad)

    def set_fault_source(self, name, instance, channel, pad):
        self.pwm.set_fault_source(name, instance, channel, pad)



