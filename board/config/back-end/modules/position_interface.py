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
import xml.etree.ElementTree as ET
import os

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

class mcBspI_PositionInterfaceClass:
    def __init__(self, component):
        self.component = component

        # Instantiate analog interface class
        self.device = mcDevI_PositionInterfaceClass(component)
        self.information = self.device.information

        self.pin_manager = mcBspI_PinManager(component)

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def getFunctionMode(self, unit, channel, phase):
        if ( self.device.name == "PDEC" ) and ( self.device.id == "U2263"):
            if phase == "QEA":
                mode = unit + "_QDI0"
            elif phase == "QEB":
                mode = unit + "_QDI1"

        elif ( self.device.name == "TC" ) and ( self.device.id == "6082"):
            if phase == "QEA":
                mode = unit + "_TIOA" + channel
            elif phase == "QEB":
                mode = unit + "_TIOB" + channel

        elif ( self.device.name == "QEI" ) and ( self.device.id == "01494"):
            if phase == "QEA":
                mode = "QEA" + self.numericFilter(unit)
            elif phase == "QEB":
                mode = "QEB" + self.numericFilter(unit)

        else:
            mode = ""

        return mode

    def handleMessage(self, id, args):
        if id == "MCPMSMFOC_POSITION_INTERFACE_SET":
            type = self.getFunctionMode( args["UNIT"], args["QEA"]["CHANNEL"], "QEA" )
            self.pin_manager.configurePin(args["QEA"]["PAD"], "QEA", type)

            type = self.getFunctionMode( args["UNIT"], args["QEB"]["CHANNEL"], "QEB" )
            self.pin_manager.configurePin(args["QEB"]["PAD"], "QEB", type)

    def __call__(self):
        print("Log: Position interface instantiated")
