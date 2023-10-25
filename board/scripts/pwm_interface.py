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
import xml.etree.ElementTree as ET
import os

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                     Classes                                           #
#---------------------------------------------------------------------------------------#
class mcBspI_PwmInterfaceClass:
    def __init__(self, component):
        self.component = component

        # Instantiate analog interface class
        self.device = mcDevI_PwmInterfaceClass(component)
        self.information = self.device.information
        self.name = self.device.name
        self.id = self.device.id

        self.family = ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("family")


        self.pin_manager = mcBspI_PinManager(component)

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def getFunctionMode(self, unit, channel, polarity ):
        if ( self.name == "TCC" ) and ( self.id == "U2213"):
            if polarity == "high":
                mode = unit + "_WO" + self.numericFilter(channel)
            else:
                mode = unit + "_WO" + str( int(self.numericFilter(channel)) + self.device.no_of_channels )

        elif ( self.name == "PWM" ) and ( self.id == "6343"):
            # Work-around. I am not sure why they have different type names for same IP
            # ToDO: Check if the family check can be removed
            if "SAMRH" in self.family:
                if polarity == "high":
                    mode = unit + "_" + "PWMC" + self.numericFilter(unit) + "_PWMH" + self.numericFilter(channel)
                else:
                    mode = unit + "_" + "PWMC" + self.numericFilter(unit) + "_PWML" + self.numericFilter(channel)
            else:
                if polarity == "high":
                    mode = unit + "_" + "PWMH" + self.numericFilter(channel)
                else:
                    mode = unit + "_" + "PWML" + self.numericFilter(channel)

        elif ( self.name == "MCPWM" ) and ( self.id == "01477"):
            if polarity == "high":
                mode = "PWM" + channel + "H"
            else:
                mode = "PWM" + channel + "L"
        else:
            mode = ""

        return mode

    def handleMessage(self, id,  args):
        if id == "MCPMSMFOC_PWM_INTERFACE_SET":
            # Set high side channel for phase A
            type = self.getFunctionMode(args["UNIT"], args["PWMAH"]["CHANNEL"], "high")
            status = self.pin_manager.configurePin(args["PWMAH"]["PAD"], "PWMAH", type)

            type = self.getFunctionMode(args["UNIT"], args["PWMBH"]["CHANNEL"], "high")
            status = self.pin_manager.configurePin(args["PWMBH"]["PAD"], "PWMBH", type)

            type = self.getFunctionMode(args["UNIT"], args["PWMCH"]["CHANNEL"], "high")
            status = self.pin_manager.configurePin(args["PWMCH"]["PAD"], "PWMCH", type)

            type = self.getFunctionMode(args["UNIT"], args["PWMAL"]["CHANNEL"], "low")
            status = self.pin_manager.configurePin(args["PWMAL"]["PAD"], "PWMAL", type)

            type = self.getFunctionMode(args["UNIT"], args["PWMBL"]["CHANNEL"], "low")
            status = self.pin_manager.configurePin(args["PWMBL"]["PAD"], "PWMBL", type)

            type = self.getFunctionMode(args["UNIT"], args["PWMCL"]["CHANNEL"], "low")
            status = self.pin_manager.configurePin(args["PWMCL"]["PAD"], "PWMCL", type)


    """
    Description:
    This function discards alphabets and returns the numbers only
    """
    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def __call__(self):
        print("Log: PWM interface instantiated")