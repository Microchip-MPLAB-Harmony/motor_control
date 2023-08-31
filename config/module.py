
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
SupportedIps = {
    "PWM" : [
              { "name": "TCC", "id": "U2213"},
              { "name": "PWM", "id": "6343"},
              { "name": "MCPWM", "id": "01477"}
            ],
    "ADC" : [
              { "name": "ADC", "id": "U2500"},
              { "name": "AFEC", "id": "11147"},
              { "name": "ADCHS", "id": "02508"}
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

    if (pwmPresent and adcPresent ):

        mcPmsmFocComponent = Module.CreateComponent("pmsm_foc", "PMSM FOC", "Motor Control/", "algorithms/pmsm_foc/config/pmsm_foc.py")

        mcPmsmFocComponent.setDisplayType("Motor Control Algorithm")

        # Add dependency symbol for ADC peripheral
        mcPmsmFocComponent.addMultiDependency("pmsmfoc_ADC", "ADC", "ADC", pwmPresent)

        # Add dependency symbol for PWM peripheral
        mcPmsmFocComponent.addDependency("pmsmfoc_PWM", "PWM", False, pwmPresent)

        # Add dependency symbol for QDEC peripheral
        mcPmsmFocComponent.addDependency("pmsmfoc_QDEC", "QDEC", False, encoderPresent)

        # Add dependency symbol for DSCI peripheral
        mcPmsmFocComponent.addDependency("pmsmfoc_X2CSCOPE", "DSCI", False, True)
