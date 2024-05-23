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
import os.path
import xml.etree.ElementTree as ET

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 CLASSES                                               #
#---------------------------------------------------------------------------------------#
class mcFocI_DataMonitoringClass:
    def __init__(self, component, pin_manager):
        self.component = component
        self.pin_manager = pin_manager

        # Instantiate analog interface class
        device = mcDevI_DataMonitorClass(component)
        self.information = device.information
        self.physical_ports = device.physical_ports


    def createSymbols(self):
        # Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Data Monitoring")

        # Data communication Enable
        self.sym_PROTOCOL = self.component.createBooleanSymbol("MCPMSMFOC_DATA_MONITOR_ENABLE", self.sym_NODE)
        self.sym_PROTOCOL.setLabel("Enable data monitoring")

        self.sym_PROTOCOL.setDefaultValue(False)

        self.sym_PROTOCOL.setDependencies(self.updateInstance, ["MCPMSMFOC_DATA_MONITOR_ENABLE"])

        #
        # protocols = ['X2C Scope', 'XCP' ]
        protocols = ['X2C Scope', 'X2C Model']
        self.sym_PROTOCOL = self.component.createComboSymbol("MCPMSMFOC_DATA_MONITOR_PROTOCOL", self.sym_NODE, protocols)
        self.sym_PROTOCOL.setLabel("Protocol")
        self.sym_PROTOCOL.setVisible(False)
        self.sym_PROTOCOL.setReadOnly(True)
        self.sym_PROTOCOL.setDependencies( self.showThisSymbol, ['MCPMSMFOC_DATA_MONITOR_ENABLE'])

        self.sym_PHYSICAL_PORT = self.component.createComboSymbol("MCPMSMFOC_DATA_MONITOR_PHYSICAL_PORT", self.sym_PROTOCOL, self.physical_ports)
        self.sym_PHYSICAL_PORT.setLabel("Physical Port")
        self.sym_PHYSICAL_PORT.setVisible(False)

        units = ["** Select **"] + sorted(self.information.keys())
        self.sym_PERIPHERAL = self.component.createComboSymbol("MCPMSMFOC_DATA_MONITOR_PERIPHERAL", self.sym_PROTOCOL, units)
        self.sym_PERIPHERAL.setLabel("Peripheral")

        channel_map = {}
        for unit in self.information.keys():
            channels = []
            for group in ["TRANSMIT", "RECEIVE"]:
                channels = self.information.get(unit, {}).get(group, {})
            channel_map[unit] = ["** Select **"] + channels.keys()

        self.sym_RECEIVE_CHANNEL = self.component.createComboSymbol("MCPMSMFOC_DEBUG_RX_CHANNEL", self.sym_PERIPHERAL, ["** Select **"])
        self.sym_RECEIVE_CHANNEL.setLabel( "Receive Channel")
        self.sym_RECEIVE_CHANNEL.setVisible(False)
        self.sym_RECEIVE_CHANNEL.setDefaultValue("** Select **")

        self.sym_OLD_RECEIVE_PAD = self.component.createStringSymbol("MCPMSMFOC_DATA_MONITOR_OLD_RECEIVE_PAD", self.sym_PERIPHERAL)
        self.sym_OLD_RECEIVE_PAD.setLabel("Old Receive pad")
        self.sym_OLD_RECEIVE_PAD.setVisible(False)

        self.sym_RECEIVE_PAD = self.component.createComboSymbol("MCPMSMFOC_DATA_MONITOR_RECEIVE_PAD", self.sym_PERIPHERAL, ["** Select **"])
        self.sym_RECEIVE_PAD.setLabel("Receive pad")
        self.sym_RECEIVE_PAD.setVisible(False)
        self.sym_RECEIVE_PAD.setDependencies(self.updateRxPadList, ["MCPMSMFOC_DATA_MONITOR_PERIPHERAL", "MCPMSMFOC_DATA_MONITOR_RECEIVE_PAD", "MCPMSMFOC_USED_PIN_LIST"])

        self.sym_TRANSMIT_CHANNEL = self.component.createComboSymbol("MCPMSMFOC_DEBUG_X_CHANNEL", self.sym_PERIPHERAL, ["** Select **"])
        self.sym_TRANSMIT_CHANNEL.setLabel( "Receive Channel")
        self.sym_TRANSMIT_CHANNEL.setVisible(False)
        self.sym_TRANSMIT_CHANNEL.setDefaultValue("** Select **")

        self.sym_OLD_TRANSMIT_PAD = self.component.createStringSymbol("MCPMSMFOC_DATA_MONITOR_OLD_TRANSMIT_PAD", self.sym_PERIPHERAL)
        self.sym_OLD_TRANSMIT_PAD.setLabel("Old Transmit pad")
        self.sym_OLD_TRANSMIT_PAD.setVisible(False)

        self.sym_TRANSMIT_PAD = self.component.createComboSymbol("MCPMSMFOC_DATA_MONITOR_TRANSMIT_PAD", self.sym_PERIPHERAL, ["** Select **"])
        self.sym_TRANSMIT_PAD.setLabel("Transmit pad")
        self.sym_TRANSMIT_PAD.setVisible(False)
        self.sym_TRANSMIT_PAD.setDependencies(self.updateTxPadList, ["MCPMSMFOC_DATA_MONITOR_PERIPHERAL", "MCPMSMFOC_DATA_MONITOR_TRANSMIT_PAD", "MCPMSMFOC_USED_PIN_LIST"])
        self.sym_DATA_MONITOR_CALLBACK = self.component.createMenuSymbol(None, None)
        self.sym_DATA_MONITOR_CALLBACK.setLabel("Data monitoring callback")
        self.sym_DATA_MONITOR_CALLBACK.setDependencies(self.updateCommInterface, ["MCPMSMFOC_DATA_MONITOR_PERIPHERAL",
                                                                      "MCPMSMFOC_DEBUG_TX_CHANNEL",
                                                                      "MCPMSMFOC_DEBUG_RX_CHANNEL",
                                                                      "MCPMSMFOC_DATA_MONITOR_RECEIVE_PAD",
                                                                      "MCPMSMFOC_DATA_MONITOR_TRANSMIT_PAD"])
        self.sym_DATA_MONITOR_CALLBACK.setVisible(False)


        self.sym_X2CSCOPE = self.component.createStringSymbol("MCPMSMFOC_X2CScope", None)
        self.sym_X2CSCOPE.setVisible(False)


    def updateTxPadList(self, symbol, event):
        if("** Select **" != self.sym_PERIPHERAL.getValue()):
            # Remove old pin from used pin list
            self.pin_manager.removePinFromList(self.sym_OLD_TRANSMIT_PAD.getValue())
            self.sym_OLD_TRANSMIT_PAD.setValue(self.sym_TRANSMIT_PAD.getValue())

            # Add new used pi to the list
            self.pin_manager.addPinToList(self.sym_TRANSMIT_PAD.getValue())

            pad_list = sorted(self.information[self.sym_PERIPHERAL.getValue()]["TRANSMIT"]["CHANNEL"])

            # Use list comprehension to create a new list that filters elements
            pad_list = [entry for entry in pad_list if entry not in self.pin_manager.getUsedPinList() or entry == self.sym_TRANSMIT_PAD.getValue()]

            symbol.setRange(["** Select **"] + pad_list)


    def updateRxPadList(self, symbol, event):
        if("** Select **" != self.sym_PERIPHERAL.getValue()):
            # Remove old pin from used pin list
            self.pin_manager.removePinFromList(self.sym_OLD_RECEIVE_PAD.getValue())
            self.sym_OLD_RECEIVE_PAD.setValue(self.sym_RECEIVE_PAD.getValue())

            # Add new used pi to the list
            self.pin_manager.addPinToList(self.sym_RECEIVE_PAD.getValue())

            pad_list = sorted(self.information[self.sym_PERIPHERAL.getValue()]["RECEIVE"]["CHANNEL"])

            # Use list comprehension to create a new list that filters elements
            pad_list = [entry for entry in pad_list if entry not in self.pin_manager.getUsedPinList() or entry == self.sym_RECEIVE_PAD.getValue()]

            symbol.setRange(["** Select **"] + pad_list)


    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def stringReplace( self, my_String ):
        # my_String = my_String.replace("RP","R")
        return my_String

    def updateCommInterface(self, symbol, event):
        # Update the message to be sent
        unit = self.sym_PERIPHERAL.getValue()
        receive = self.stringReplace(self.sym_RECEIVE_PAD.getValue())
        transmit = self.stringReplace(self.sym_TRANSMIT_PAD.getValue())

        if unit != "** Select **":
            # and receive != "** Select **" and transmit != "** Select **":
            args = {
                        "UNIT": unit,
                        "RECEIVE": { "PAD": receive },
                        "TRANSMIT": { "PAD":  transmit }
                    }

            # Send the message to custom BSP
            module = str( Database.getSymbolValue(self.component.getID(), "MCPMSMFOC_FOC_X2C_ID"))
            Database.sendMessage(module, "X2CSCOPE_CONFIGURATION", args)
            # Database.sendMessage("custom_mc_board", "MCPMSMFOC_DEBUG_PAD_SET", args)

    def updateInstance(self, symbol, event):
        if symbol.getValue() == True:
            # Make X2C enable as readonly
            event["source"].getSymbolByID("MCPMSMFOC_FOC_X2C_ENABLE").setReadOnly(False)
            symbol.getComponent().setDependencyEnabled("pmsmfoc_X2CSCOPE", True)


            # Activate and connect the default  module for data control and monitoring
            module = str( Database.getSymbolValue(self.component.getID(), "MCPMSMFOC_FOC_X2C_ID"))
            autoConnectTable = [ module]
            res = Database.activateComponents(autoConnectTable)

            autoComponentIDTable = [[ self.component.getID(), "pmsmfoc_X2CSCOPE","X2CScope", "x2cScope_Scope"]]
            res = Database.connectDependencies(autoComponentIDTable)
        else:

            # Make X2C enable as readonly
            event["source"].getSymbolByID("MCPMSMFOC_FOC_X2C_ENABLE").setReadOnly(True)
            symbol.getComponent().setDependencyEnabled("pmsmfoc_X2CSCOPE", False)


            # Deactivate and connect the default  module for data control and monitoring
            module = str( Database.getSymbolValue(self.component.getID(), "MCPMSMFOC_FOC_X2C_ID"))
            autoConnectTable = [ module]
            res = Database.deactivateComponents(autoConnectTable)

    def showThisSymbol(self, symbol, event):
        if True == (event["symbol"]).getValue():
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def handleMessage(self, ID, information):
        if( ID == "BSP_DATA_MONITORING"):
            # Enable X2C Scope
            instance = next(iter(information))
            Database.setSymbolValue("pmsm_foc", "MCPMSMFOC_DATA_MONITOR_ENABLE", True )
            Database.setSymbolValue("pmsm_foc", "MCPMSMFOC_DATA_MONITOR_PERIPHERAL", instance)

            return {}

        if( ID == "X2CSCOPE_DATA_MONITORING"):
            instance = self.sym_PERIPHERAL.getValue()
            tx_channel = self.sym_TRANSMIT_CHANNEL.getValue()
            rx_channel = self.sym_RECEIVE_CHANNEL.getValue()
            data_monitoring_params = { 
                                        instance: { 
                                                    'transmit' : {
                                                                    'channel': tx_channel, 
                                                                    'pad':''
                                                                },
                                                    'receive' :  {
                                                                    'channel': rx_channel, 
                                                                    'pad':''
                                                                }
                                                    }
                                        }
            return data_monitoring_params
  
    def onAttachmentConnected(self, source, target):
        if (source["id"] == "pmsmfoc_X2CSCOPE"):
            self.sym_X2CSCOPE.setValue( target["component"].getID())

            # Get the X2C Communication peripheral
            # commPeripheral = Database.getSymbolValue("X2CScope", "X2C_COMM_INSTANCE")
            #
            # # Activate and connect peripheral
            # autoConnectTable = [commPeripheral]
            # res = Database.activateComponents(autoConnectTable)
            #
            # autoComponentIDTable = [[ target["component"].getID(), "x2cScopeUartDependency", commPeripheral.lower(), commPeripheral.upper() + "_UART"]]
            # res = Database.connectDependencies(autoComponentIDTable)


    def onAttachmentDisconnected(self, source, target):
        if (source["id"] == "pmsmfoc_X2CSCOPE"):
            self.sym_X2CSCOPE.setValue("None")

    def __call__(self):
        self.createSymbols()


