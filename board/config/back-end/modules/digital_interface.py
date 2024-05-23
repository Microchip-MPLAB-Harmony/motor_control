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
#                                   Imports                                             #
#---------------------------------------------------------------------------------------#
import imp
import xml.etree.ElementTree as ET
from collections import OrderedDict

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcBspI_DigitalInterfaceClass:
    def __init__(self, component ):
        self.component = component
        self.information = {
                                "BUTTONS": {
                                    "BUTTON_1": { "PAD": "", "PIN": "" },
                                    "BUTTON_02": { "PAD": "", "PIN": "" },
                                },
                                "LEDS": {
                                    "LED_1": { "PAD": "", "PIN": "" },
                                    "LED_2": { "PAD": "", "PIN": "" },
                                }
                            }
        self.pin_manager = mcBspI_PinManager(component)

    def sendMessage( self ):
        Database.sendMessage("pmsm_foc", "BSP_DIGITAL_INTERFACE", self.information)

    def handleMessage( self, id, args):
        if "MCPMSMFOC_DIGITAL_INTERFACE_SET" == id:
            if args["TYPE"] == "LED":
                self.pin_manager.configureLed(args["PAD"], args["ID"], "GPIO")

                # Buttons
            if args["TYPE"] == "BUTTON":
                self.pin_manager.configureButton(args["PAD"], args["ID"], "GPIO")

    def __call__(self):
        self.sendMessage()






