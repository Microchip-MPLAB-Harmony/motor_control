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
#                                 IMPORTS                                               #
#---------------------------------------------------------------------------------------#
import os.path

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcBspI_DataMonitorClass:
    def __init__(self, component ):
        self.component = component

        # Instantiate analog interface class
        self.device = mcDevI_DataMonitorClass(component)
        self.information = self.device.information
        self.physical_ports = self.device.physical_ports

        self.pin_manager = mcBspI_PinManager(component)

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def handleMessage( self, ID, args):
        if( ID == "MCPMSMFOC_DEBUG_PAD_SET" ):
            if ( self.device.name == "SERCOM" ) and ( self.device.id == "U2201"):
                # Set transmit pin
                type = args["UNIT"] + "_PAD0"
                self.pin_manager.configurePin(args["TRANSMIT"]["PAD"], "TRANSMIT", type)

                type = args["UNIT"] + "_PAD1"
                self.pin_manager.configurePin(args["RECEIVE"]["PAD"], "RECEIVE", type)
            elif ( self.device.name == "UART" ) and ( self.device.id == "6418"):

                index = self.numericFilter(args["UNIT"])

                type = args["UNIT"] + "_URXD" + index
                self.pin_manager.configurePin(args["RECEIVE"]["PAD"], "RECEIVE", type)

                type = args["UNIT"] + "_UTXD0" + index
                self.pin_manager.configurePin(args["TRANSMIT"]["PAD"], "TRANSMIT", type)

            elif ( self.device.name == "UART" ) and ( self.device.id == "02478"):
                index = self.numericFilter(args["UNIT"])

                type = "U" + index + "RX"
                self.pin_manager.configurePin(args["RECEIVE"]["PAD"], "RECEIVE", type)

                type = "U" + index + "TX"
                self.pin_manager.configurePin(args["TRANSMIT"]["PAD"], "TRANSMIT", type)

            elif ( self.device.name == "FLEXCOM" ) and ( self.device.id == "11268"):
                # Set transmit pin
                type = args["UNIT"] + "_IO0"
                self.pin_manager.configurePin(args["TRANSMIT"]["PAD"], "TRANSMIT", type)

                type = args["UNIT"] + "_IO1"
                self.pin_manager.configurePin(args["RECEIVE"]["PAD"], "RECEIVE", type)
            return "success"

        else:
            return "failure"

    def __call__(self):
        pass






