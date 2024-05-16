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
import os.path

#---------------------------------------------------------------------------------------#
#                                Global Variables                                       #
#---------------------------------------------------------------------------------------#
autoConnectTable = []

#---------------------------------------------------------------------------------------#
#                                   Classes                                             #
#---------------------------------------------------------------------------------------#
class mcAniI_AnalogInterfaceClass:
    def __init__(self, component, pin_manager ):
        self.component = component
        self.pin_manager = pin_manager

        # Instantiate analog interface class
        self.device = mcDevI_AnalogInterfaceClass(component)
        self.information = self.device.information
        self.name = self.device.name
        self.id = self.device.id

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def createAnalogGroup(self, identifier, description, signal_name, group):
        # Internal function to update pin interface
        def updateInterface(symbol, event):

            # Update the message to be sent
            if unit.getValue() != "** Select **" and channel.getValue() != "** Select **" and pad.getValue() != "** Select **":

                # Remove old pad from the list
                self.pin_manager.removePinFromList(old_pad.getValue())
                old_pad.setValue(pad.getValue())

                # Add new pad to the list
                self.pin_manager.addPinToList(pad.getValue())

                args = {
                        "ID": name.getValue(),
                        "UNIT": unit.getValue(),
                        "CHANNEL": channel.getValue(),
                        "PAD": pad.getValue()
                        }

                # Send the message to custom BSP
                status = Database.sendMessage("cstom_mc_bsp", "MCPMSMFOC_ANALOG_PAD_SET", args)

        # Internal function to update pad list based on ADC unit and channel
        def updatePadList(symbol, event):
            if unit.getValue() != "** Select **" and channel.getValue() != "** Select **":
                new_list = sorted(self.information[unit.getValue()][channel.getValue()])

                for entry in new_list:
                    if entry in self.pin_manager.getUsedPinList() and entry != pad.getValue():
                        new_list.remove(entry)

                symbol.setRange(["** Select **"] + new_list )

        # Internal function to update channel list based on ADC unit
        def updateChannelList(symbol, event):
            if unit.getValue() != "** Select **":
                channel_list = sorted([int(x) for x in self.information[event["value"]].keys()])
                channel_list = ["** Select **"] + [str(x) for x in channel_list]

                symbol.setRange( channel_list)

        # Update ADC PLIBs based on unit, channels and other default configuration information
        def updatePLIB(symbol, event):
            if (
                unit.getValue() != "** Select **" and channel.getValue() != "** Select **"
               ):

                # Disable old interface
                if (
                     old_unit.getValue() != "** Select **" and old_channel.getValue() != "** Select **"
                   ):
                    args = {
                        "enable": False,
                        "id" : name.getValue(),
                        "instance" : old_unit.getValue(),
                        "channel"  : old_channel.getValue(),
                    }
                    Database.sendMessage( ( id.getValue()).lower(), "SET_ADC_CONFIG_PARAMS", args)

                # Configure new channel
                if self.name == "ADC" and ( self.id == "U2500" or self.id == "U2247"):
                    if (
                        unit.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT")
                    ):
                        enable_eoc_interrupt = True
                        enable_slave_mode = False
                    else:
                        enable_eoc_interrupt = False
                        enable_slave_mode = True

                else:
                    if (
                        unit.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT")  and
                        channel.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_CHANNEL")
                    ):
                        enable_eoc_interrupt = True
                        enable_slave_mode = False
                    else:
                        enable_eoc_interrupt = False
                        enable_slave_mode = True

                # Update configuration data for the analog interface
                trigger = self.numericFilter(global_ADC_TRIGGER.getValue())

                args = {
                        "enable": True,
                        "id" : name.getValue(),
                        "instance" : unit.getValue(),
                        "channel"  : channel.getValue(),
                        "resolution" : self.device.resolution[0],
                        "mode": "default",
                        "reference": "default",
                        "conversion_time" : 1,
                        "trigger" : trigger,
                        "result_alignment" : "default",
                        "enable_eoc_event" : False,
                        "enable_eoc_interrupt" : enable_eoc_interrupt,
                        "enable_slave_mode" : enable_slave_mode,
                        "enable_dma_sequence" :False
                    }

                Database.sendMessage( ( id.getValue()).lower(), "SET_ADC_CONFIG_PARAMS", args)

                old_unit.setValue(unit.getValue())
                old_channel.setValue(channel.getValue())

        # Update connected PLIBs
        def updateConnectedPLibs(symbol, event):
            if ( self.name == "ADCHS" ) and ( self.id == "02508"):
                # Activate and connect
                res = Database.activateComponents(["adchs"])

                autoComponentIDTable = [[ self.component.getID(), "pmsmfoc_ADC", "adchs", "ADCHS_ADC"]]
                res = Database.connectDependencies(autoComponentIDTable)

            else:
                # Remove old peripheral from the list
                if len(self.connectedPLibs) == 4 and symbol.getValue() != event["value"]:
                    self.connectedPLibs.remove(symbol.getValue().lower())

                    # De-activate the peripheral if no analog channel uses it
                    if symbol.getValue().lower() not in self.connectedPLibs:
                        res = Database.deactivateComponents([symbol.getValue().lower()])

                # Update ADC peripherals being used
                symbol.setValue(event["value"].lower())
                self.connectedPLibs.append(event["value"].lower())

                # Activate and connect
                res = Database.activateComponents([event["value"].lower()])

                autoComponentIDTable = [[ self.component.getID(), "pmsmfoc_ADC", event["value"].lower(), str(event["value"].upper()) + "_ADC"]]
                res = Database.connectDependencies(autoComponentIDTable)

        # Node symbol
        node_symbol = identifier + "_" + "NODE"
        node = self.component.createMenuSymbol(node_symbol, group)
        node.setLabel(description)

        # Signal name
        name_symbol = identifier + "_" + "NAME"
        name =  self.component.createStringSymbol(name_symbol, node )
        name.setLabel("Signal Name")
        name.setDefaultValue(signal_name)
        name.setReadOnly(True)

        # Signal unit
        unit_symbol = identifier + "_" + "UNIT"
        units = ["** Select **"] + sorted(self.information.keys())
        unit = self.component.createComboSymbol(unit_symbol, node, units)
        unit.setLabel("ADC unit")
        unit.setDefaultValue("** Select **")

        old_unit_symbol = identifier + "_OLD_" + "UNIT"
        old_unit = self.component.createStringSymbol(old_unit_symbol, node)
        old_unit.setLabel("Old ADC unit")
        old_unit.setVisible(False)
        old_unit.setDefaultValue("** Select **")

        # Signal id
        id_symbol = identifier + "_" + "PERIPHERAL_ID"
        id = self.component.createStringSymbol(id_symbol, None)
        id.setLabel("Peripheral ID")
        id.setVisible(False)
        id.setDependencies(updateConnectedPLibs, [unit_symbol])

        if ( self.name == "ADCHS" ) and ( self.id == "02508"):
            id.setDefaultValue("adchs")
        else:
            id.setDefaultValue((unit.getValue()).lower())

        channel_map = {}
        for key, value in self.information.items():
            int_list = sorted([int(x) for x in value.keys()])
            channel_map[key] = ["** Select **"] + [str(x) for x in int_list]

        # Signal channel
        channel_symbol = identifier + "_" + "CHANNEL"
        channels = ["** Select **"]
        channel = self.component.createComboSymbol(channel_symbol, node, channels)
        channel.setLabel("ADC channel")
        channel.setDefaultValue("** Select **")
        channel.setDependencies(updateChannelList, [unit_symbol])

        old_channel_symbol = identifier + "_OLD_" + "CHANNEL"
        old_channel = self.component.createStringSymbol(old_channel_symbol, node)
        old_channel.setLabel("Old ADC channel")
        old_channel.setVisible(False)
        old_channel.setDefaultValue("** Select **")

        # Signal pad
        pad_symbol = identifier + "_" + "PAD"
        pad = self.component.createComboSymbol(pad_symbol, node, ["** Select **"])
        pad.setLabel("Pad")
        pad.setDefaultValue("** Select **")
        pad.setVisible(False)
        pad.setDependencies(updatePadList, [unit_symbol, channel_symbol, "MCPMSMFOC_USED_PIN_LIST"])

        old_pad_symbol = identifier + "_" + "OLD_PAD"
        old_pad = self.component.createStringSymbol(old_pad_symbol, node)
        old_pad.setLabel("Old Pad")
        old_pad.setDefaultValue("** Select **")
        old_pad.setVisible(False)


        # Signal callback
        callback_symbol = identifier + "_" + "PIN_UPDATE_CALLBACK"
        callback = self.component.createMenuSymbol(callback_symbol, None)
        callback.setLabel("Pin manager update callback function")
        callback.setDependencies(updateInterface, [pad_symbol])
        callback.setVisible(False)

        # Signal callback
        callback_symbol = identifier + "_" + "PLIB_UPDATE_CALLBACK"
        callback = self.component.createMenuSymbol(callback_symbol, None)
        callback.setLabel("PLIB update interface function")
        callback.setDependencies(updatePLIB, [unit_symbol, channel_symbol])
        callback.setVisible(False)

        # Interrupt symbol
        interrupt_symbol = identifier + "_" + "EOC_INTERRUPT_ENABLE"
        interrupt_enable = self.component.createBooleanSymbol( interrupt_symbol, node )
        interrupt_enable.setLabel("Enable EOC interrupt")
        interrupt_enable.setVisible(False)
        if unit.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT"):
            interrupt_enable.setDefaultValue(True)
        else:
            interrupt_enable.setDefaultValue(False)

        # Slave mode symbol
        slave_mode_symbol = identifier + "_" + "SLAVE_MODE_ENABLE"
        slave_mode_enable = self.component.createBooleanSymbol( slave_mode_symbol, node )
        slave_mode_enable.setLabel("Slave mode enable")
        slave_mode_enable.setVisible(False)
        if not unit.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT"):
            slave_mode_enable.setDefaultValue(True)
        else:
            slave_mode_enable.setDefaultValue(False)

    def createSymbols( self ):
        # Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None )
        self.sym_NODE.setLabel("Analog Interface")

        # ____________________________________________ Group 01 ___________________________________________________#
        self.sym_GROUP_01 = self.component.createMenuSymbol(None, self.sym_NODE )
        self.sym_GROUP_01.setLabel("Group 01 Signals")

        self.createAnalogGroup("MCPMSMFOC_PHASE_CURRENT_IA", "Phase A Current", "IA", self.sym_GROUP_01)
        self.createAnalogGroup("MCPMSMFOC_PHASE_CURRENT_IB", "Phase B Current", "IB", self.sym_GROUP_01)

        # ____________________________________________ Group 01 ___________________________________________________#
        self.sym_GROUP_02 = self.component.createMenuSymbol(None, self.sym_NODE )
        self.sym_GROUP_02.setLabel("Group 02 Signals")

        self.createAnalogGroup("MCPMSMFOC_BUS_VOLTAGE_VDC", "DC Bus Voltage", "VDC", self.sym_GROUP_02)
        self.createAnalogGroup("MCPMSMFOC_POTENTIOMETER_VPOT", "Potentiometer", "VPOT", self.sym_GROUP_02)

    def setDatabaseSymbol(self, namespace, id, value):
        status = Database.setSymbolValue(namespace, id, value)

        if( status == False):
            print("Checkpoint. The symbol " + id + " could not be updated")

    def onAttachmentConnected(self, source, target):
        pass

    def onAttachmentDisconnected(self, source, target):
        pass

    def handleMessage(self, ID, information ):
        if( "BSP_ANALOG_INTERFACE" == ID ) and ( None != information):
            print('Analog message', information)
            # Set unit and channel symbol for phase A current
            instance = next(iter(information[u'IA']))
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT", instance)

            channel = str(information['IA'][instance]['channel'])
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_CHANNEL", channel)

            # Set unit and channel symbol for phase B current
            instance = next(iter(information['IB']))
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IB_UNIT", instance)

            channel = str(information['IB'][instance]['channel'])
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IB_CHANNEL", channel)

            # Set unit and channel symbol for DC bus voltage
            instance = next(iter(information['VDC']))
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT", instance)

            channel = str(information['VDC'][instance]['channel'])
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_BUS_VOLTAGE_VDC_CHANNEL", channel)

            # Set unit and channel symbol for potentiometer
            instance = next(iter(information['VPOT']))
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_POTENTIOMETER_VPOT_UNIT", instance)

            channel = str(information['VPOT'][instance]['channel'])
            self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_POTENTIOMETER_VPOT_CHANNEL", channel)

    def __call__(self):
        self.createSymbols()
        self.connectedPLibs = []