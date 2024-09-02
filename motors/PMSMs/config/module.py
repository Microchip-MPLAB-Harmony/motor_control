
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
#                                 Imports                                               #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 Global variables                                      #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

SupportedDeviceSeries = [
    "LAN9255ZMX", "PIC32CXSG41", "PIC32CXSG60","PIC32CXSG61", "SAMD51A", "SAME51A", "SAME53A", "SAME54A",
    "PIC32MK MC",
    "SAME70B", "SAMS70B", "SAMV70B", "SAMV71B", "SAMV71RT", "PIC32CZCA70", "PIC32CZMC70",
    "SAMC20A", "SAMC21A",
    "SAMRH707A",
    "PIC32CMMC00",
]

SupportedIps = {
    "PWM" : [
              { "name": "TCC", "id": "U2213"},
              { "name": "PWM", "id": "6343"},
              { "name": "MCPWM", "id": "01477"}
            ],
    "ADC" : [
              { "name": "ADC",   "id": "U2500"},
              { "name": "ADC",   "id": "U2247"},
              { "name": "AFEC",  "id": "11147"},
              { "name": "ADCHS", "id": "02508"},
              { "name": "ADC",   "id": "44073"}
            ],
    "QDEC": [
              { "name": "PDEC", "id": "U2263"},
              { "name": "TC", "id": "6082"},
              { "name": "QEI", "id": "01494"}
            ]
}

def checkIpSupport(module, ip):
    for entry in SupportedIps.get(ip, []):
        if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
            return True
    return False

#---------------------------------------------------------------------------------------#
#                                 Load module                                           #
#---------------------------------------------------------------------------------------#
def loadModule():

    # Get the processor name
    series = str(ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series"))

    device_supported = False
    for entry in SupportedDeviceSeries:
        if series in entry:
            device_supported = True
            break

    if not device_supported:
        return

    # Get the available modules from ATDF file
    periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
    modules = periphNode.getChildren()


    pwmPresent = adcPresent = encoderPresent = False

    for module in modules:
        if checkIpSupport(module, "PWM"):
            pwmPresent = True
        if checkIpSupport(module, "ADC"):
            adcPresent = True
        if checkIpSupport(module, "QDEC"):
            encoderPresent = True

    if (pwmPresent and adcPresent):
        motor_component = Module.CreateComponent("pmsm_motor", "Permanent Magnet Synchronous Motor","/Motor Control/Motors/", "config/back-end/motor.py")
        motor_component.addCapability("motortype_PMSM", "PMSM")
