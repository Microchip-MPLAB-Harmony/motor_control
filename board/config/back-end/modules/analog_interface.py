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
import xml.etree.ElementTree as ET
import os
import copy

#---------------------------------------------------------------------------------------#
#                                  Global Variables                                     #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                      Classes                                          #
#---------------------------------------------------------------------------------------#

class mcBspI_AnalogInterfaceClass:
    def __init__(self, component ):
        self.component = component

        # Instantiate analog interface class
        self.device = mcDevI_AnalogInterfaceClass(component)
        self.pin_manager = mcBspI_PinManager(component)

    """
    Description:
    This function discards alphabets and returns the numbers only
    """
    def handleMessage(self, id, args):
        if "MCPMSMFOC_ANALOG_PAD_SET" == id:
            # Verify if the received message is valid, i.e. there is
            # a ADC unit and channel for the specified pin
            if args["PAD"] in self.device.information[args["UNIT"]][args["CHANNEL"]]:
                if ( self.device.name == "ADC" ) and (( self.device.id == "U2500") or ( self.device.id == "U2247")):
                    mode = args["UNIT"] + "_" + self.device.function_name[args["UNIT"]][args["PAD"]]
                elif ( self.device.name == "AFEC" ) and ( self.device.id == "11147"):
                    mode = args["UNIT"] + "_AD" + args["CHANNEL"]
                elif ( self.device.name == "ADC" ) and ( self.device.id == "44073"):
                    mode = args["UNIT"] + "_AD" + args["CHANNEL"]
                elif ( self.device.name == "ADCHS" ) and ( self.device.id == "02508"):
                    mode = "AN" + args["CHANNEL"]
                else:
                    mode = ""

                self.pin_manager.configurePin(args["PAD"], args["ID"], mode)

                return "success"
            else:
                return "failure"

    def __call__(self):
        print("Log: Analog interface class")





