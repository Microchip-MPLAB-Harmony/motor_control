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
class AnalogGroup:
    used_adc_interfaces = []
    def __init__(self, parent, identifier, description, signal_name, group):
        self.parent = parent
        self.identifier = identifier
        self.description = description
        self.signal_name = signal_name
        self.group = group

        self.createAnalogGroup()

    def numericFilter(self, input_string):
        numeric_filter = filter(str.isdigit, str(input_string))
        return "".join(numeric_filter)

    def reset_used_interfaces_list(self):
        AnalogGroup.used_adc_interfaces = []

    # Internal function to update pin interface
    def updateInterface(self, symbol, event):
        # Update the message to be sent
        if self.unit.getValue() != "** Select **" and self.channel.getValue() != "** Select **" and self.pad.getValue() != "** Select **":
            # Remove old pad from the list
            self.parent.pin_manager.removePinFromList(self.old_pad.getValue())
            self.old_pad.setValue(self.pad.getValue())

            # Add new pad to the list
            self.parent.pin_manager.addPinToList(self.pad.getValue())

            args = {
                "ID": self.name.getValue(),
                "UNIT": self.unit.getValue(),
                "CHANNEL": self.channel.getValue(),
                "PAD": self.pad.getValue()
            }

            # Send the message to custom BSP
            status = Database.sendMessage("custom_mc_board", "MCPMSMFOC_ANALOG_PAD_SET", args)

    # Internal function to update pad list based on ADC unit and channel
    def updatePadList(self, symbol, event):
        if self.unit.getValue() != "** Select **" and self.channel.getValue() != "** Select **":
            new_list = sorted(self.parent.information[self.unit.getValue()][self.channel.getValue()])

            for entry in new_list:
                if entry in self.parent.pin_manager.getUsedPinList() and entry != self.pad.getValue():
                    new_list.remove(entry)

            symbol.setRange(["** Select **"] + new_list)

    # Internal function to update channel list based on ADC unit
    def updateChannelList(self, symbol, event):
        if self.unit.getValue() != "** Select **":
            channel_list = sorted([int(x) for x in self.parent.information[event["value"]].keys()])
            channel_list = ["** Select **"] + [str(x) for x in channel_list]

            symbol.setRange(channel_list)

    # Update ADC PLIBs based on unit, channels, and other default configuration information
    def updatePLIB(self, symbol, event):
        if str(self.unit.getValue()) != "** Select **" and str(self.channel.getValue()) != "** Select **":
            new_adc_interface = {'unit': self.unit.getValue(), 'channel': str(self.channel.getValue())}
            if new_adc_interface not in AnalogGroup.used_adc_interfaces:
                AnalogGroup.used_adc_interfaces.append(new_adc_interface)

            if new_adc_interface in AnalogGroup.used_adc_interfaces:
                print('Warning!! The interface is already in use')

            # Disable old interface
            if self.old_unit.getValue() != "** Select **" and self.old_channel.getValue() != "** Select **":
                args = {
                    "enable": False,
                    "id": self.name.getValue(),
                    "instance": self.old_unit.getValue(),
                    "channel": self.old_channel.getValue(),
                }

                Database.sendMessage((self.id.getValue()).lower(), "SET_ADC_CONFIG_PARAMS", args)

            # Configure new channel
            if self.parent.name == "ADC" and (self.parent.id == "U2500" or self.parent.id == "U2247"):
                if self.unit.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT"):
                    enable_eoc_interrupt = True
                    enable_slave_mode = False
                else:
                    enable_eoc_interrupt = False
                    enable_slave_mode = True
            else:
                if (self.unit.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT") and
                        self.channel.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_CHANNEL")):
                    enable_eoc_interrupt = True
                    enable_slave_mode = False
                else:
                    enable_eoc_interrupt = False
                    enable_slave_mode = True

            # Update configuration data for the analog interface
            trigger = self.numericFilter(global_ADC_TRIGGER.getValue())

            args = {
                "enable": True,
                "id": self.name.getValue(),
                "instance": self.unit.getValue(),
                "channel": self.channel.getValue(),
                "resolution": self.parent.device.resolution[0],
                "mode": "default",
                "reference": "default",
                "conversion_time": 1.6,
                "trigger": trigger,
                "result_alignment": "default",
                "enable_eoc_event": False,
                "enable_eoc_interrupt": enable_eoc_interrupt,
                "enable_slave_mode": enable_slave_mode,
                "enable_dma_sequence": False
            }

            Database.sendMessage((self.id.getValue()).lower(), "SET_ADC_CONFIG_PARAMS", args)

            self.old_unit.setValue(self.unit.getValue())
            self.old_channel.setValue(self.channel.getValue())

    # Update ADC PLIBs based on unit, channels, and other default configuration information
    def resetPLIB(self):
        # Reset PLIB
        if self.old_unit.getValue() != "** Select **" and self.old_channel.getValue() != "** Select **":
            args = {
                    "enable": False,
                    "id": self.name.getValue(),
                    "instance": self.old_unit.getValue(),
                    "channel": self.old_channel.getValue(),
            }

            Database.sendMessage((self.id.getValue()).lower(), "SET_ADC_CONFIG_PARAMS", args)

        if self.unit.getValue() != "** Select **" and self.channel.getValue() != "** Select **":
            args = {
                    "enable": False,
                    "id": self.name.getValue(),
                    "instance": self.unit.getValue(),
                    "channel": self.channel.getValue(),
            }

            Database.sendMessage((self.id.getValue()).lower(), "SET_ADC_CONFIG_PARAMS", args )

        self.old_unit.setValue("** Select **" )
        self.old_channel.setValue("** Select **")
        self.unit.setValue("** Select **")
        self.channel.setValue("** Select **")

    # Update connected PLIBs
    def updateConnectedPLibs(self, symbol, event):
        if self.parent.name == "ADCHS" and self.parent.id == "02508":
            # Activate and connect
            res = Database.activateComponents(["adchs"])

            autoComponentIDTable = [[self.parent.component.getID(), "pmsmfoc_ADC", "adchs", "ADCHS_ADC"]]
            res = Database.connectDependencies(autoComponentIDTable)
        else:
            # Remove old peripheral from the list
            if len(self.parent.connectedPLibs) == 4 and symbol.getValue() != event["value"]:
                if symbol.getValue().lower() in self.parent.connectedPLibs:
                    self.parent.connectedPLibs.remove(symbol.getValue().lower())

                # De-activate the peripheral if no analog channel uses it
                if symbol.getValue().lower() not in self.parent.connectedPLibs:
                    res = Database.deactivateComponents([symbol.getValue().lower()])

            # Update ADC peripherals being used
            symbol.setValue(event["value"].lower())
            self.parent.connectedPLibs.append(event["value"].lower())

            # Activate and connect
            res = Database.activateComponents([event["value"].lower()])

            autoComponentIDTable = [[self.parent.component.getID(), "pmsmfoc_ADC", event["value"].lower(), str(event["value"].upper()) + "_ADC"]]
            res = Database.connectDependencies(autoComponentIDTable)

    def createAnalogGroup(self):
        # Node symbol
        node_symbol = self.identifier + "_" + "NODE"
        node = self.parent.component.createMenuSymbol(node_symbol, self.group)
        node.setLabel(self.description)

        # Signal name
        name_symbol = self.identifier + "_" + "NAME"
        self.name = self.parent.component.createStringSymbol(name_symbol, node)
        self.name.setLabel("Signal Name")
        self.name.setDefaultValue(self.signal_name)
        self.name.setReadOnly(True)

        # Signal unit
        unit_symbol = self.identifier + "_" + "UNIT"
        units = ["** Select **"] + sorted(self.parent.information.keys())
        self.unit = self.parent.component.createComboSymbol(unit_symbol, node, units)
        self.unit.setLabel("ADC unit")
        self.unit.setDefaultValue("** Select **")

        old_unit_symbol = self.identifier + "_OLD_" + "UNIT"
        self.old_unit = self.parent.component.createStringSymbol(old_unit_symbol, node)
        self.old_unit.setLabel("Old ADC unit")
        # self.old_unit.setVisible(False)
        self.old_unit.setDefaultValue("** Select **")

        # Signal id
        id_symbol = self.identifier + "_" + "PERIPHERAL_ID"
        self.id = self.parent.component.createStringSymbol(id_symbol, None)
        self.id.setLabel("Peripheral ID")
        self.id.setVisible(False)
        self.id.setDependencies(self.updateConnectedPLibs, [unit_symbol])

        if self.parent.name == "ADCHS" and self.parent.id == "02508":
            self.id.setDefaultValue("adchs")
        else:
            self.id.setDefaultValue((self.unit.getValue()).lower())

        channel_map = {}
        for key, value in self.parent.information.items():
            int_list = sorted([int(x) for x in value.keys()])
            channel_map[key] = ["** Select **"] + [str(x) for x in int_list]

        # Signal channel
        channel_symbol = self.identifier + "_" + "CHANNEL"
        channels = ["** Select **"]
        self.channel = self.parent.component.createComboSymbol(channel_symbol, node, channels)
        self.channel.setLabel("ADC channel")
        self.channel.setDefaultValue("** Select **")
        self.channel.setDependencies(self.updateChannelList, [unit_symbol])

        old_channel_symbol = self.identifier + "_OLD_" + "CHANNEL"
        self.old_channel = self.parent.component.createStringSymbol(old_channel_symbol, node)
        self.old_channel.setLabel("Old ADC channel")
        # self.old_channel.setVisible(False)
        self.old_channel.setDefaultValue("** Select **")

        # Signal pad
        pad_symbol = self.identifier + "_" + "PAD"
        self.pad = self.parent.component.createComboSymbol(pad_symbol, node, ["** Select **"])
        self.pad.setLabel("Pad")
        self.pad.setDefaultValue("** Select **")
        self.pad.setVisible(False)
        self.pad.setDependencies(self.updatePadList, [unit_symbol, channel_symbol, "MCPMSMFOC_USED_PIN_LIST"])

        old_pad_symbol = self.identifier + "_" + "OLD_PAD"
        self.old_pad = self.parent.component.createStringSymbol(old_pad_symbol, node)
        self.old_pad.setLabel("Old Pad")
        self.old_pad.setDefaultValue("** Select **")
        self.old_pad.setVisible(False)

        # Signal callback
        callback_symbol = self.identifier + "_" + "PIN_UPDATE_CALLBACK"
        callback = self.parent.component.createMenuSymbol(callback_symbol, None)
        callback.setLabel("Pin manager update callback function")
        callback.setDependencies(self.updateInterface, [pad_symbol])
        callback.setVisible(False)

        # Signal callback
        callback_symbol = self.identifier + "_" + "PLIB_UPDATE_CALLBACK"
        callback = self.parent.component.createMenuSymbol(callback_symbol, None)
        callback.setLabel("PLIB update interface function")
        callback.setDependencies(self.updatePLIB, [unit_symbol, channel_symbol])
        callback.setVisible(False)

        # Interrupt symbol
        interrupt_symbol = self.identifier + "_" + "EOC_INTERRUPT_ENABLE"
        interrupt_enable = self.parent.component.createBooleanSymbol(interrupt_symbol, node)
        interrupt_enable.setLabel("Enable EOC interrupt")
        interrupt_enable.setVisible(False)
        if self.unit.getValue() == Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT"):
            interrupt_enable.setDefaultValue(True)
        else:
            interrupt_enable.setDefaultValue(False)

        # Slave mode symbol
        slave_mode_symbol = self.identifier + "_" + "SLAVE_MODE_ENABLE"
        slave_mode_enable = self.parent.component.createBooleanSymbol(slave_mode_symbol, node)
        slave_mode_enable.setLabel("Slave mode enable")
        slave_mode_enable.setVisible(False)
        if self.unit.getValue() != Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT"):
            slave_mode_enable.setDefaultValue(True)
        else:
            slave_mode_enable.setDefaultValue(False)

class mcAniI_AnalogInterfaceClass:
    def __init__(self, component, pin_manager):
        self.component = component
        self.pin_manager = pin_manager

        # Instantiate analog interface class
        self.device = mcDevI_AnalogInterfaceClass(component)
        self.information = self.device.information
        self.name = self.device.name
        self.id = self.device.id
        self.bsp_information = {}

    def createSymbols(self):
        # Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Analog Interface")

        # ____________________________________________ Group 01 ___________________________________________________#
        self.sym_GROUP_01 = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_GROUP_01.setLabel("Group 01 Signals")
        self.analog_groups = []

        self.analog_groups.append(AnalogGroup(self, "MCPMSMFOC_PHASE_CURRENT_IA", "Phase A Current", "IA", self.sym_GROUP_01))
        self.analog_groups.append(AnalogGroup(self, "MCPMSMFOC_PHASE_CURRENT_IB", "Phase B Current", "IB", self.sym_GROUP_01))

        # ____________________________________________ Group 02 ___________________________________________________#
        self.sym_GROUP_02 = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_GROUP_02.setLabel("Group 02 Signals")

        self.analog_groups.append(AnalogGroup(self, "MCPMSMFOC_BUS_VOLTAGE_VDC", "DC Bus Voltage", "VDC", self.sym_GROUP_02))
        self.analog_groups.append(AnalogGroup(self, "MCPMSMFOC_POTENTIOMETER_VPOT", "Potentiometer", "VPOT", self.sym_GROUP_02))

    def setDatabaseSymbol(self, namespace, id, value):
        status = Database.setSymbolValue(namespace, id, value)

        if not status:
            print("Checkpoint. The symbol " + id + " could not be updated")

    def onAttachmentConnected(self, source, target):
        pass

    def onAttachmentDisconnected(self, source, target):
        pass

    def handleMessage(self, ID, information):
        if "BSP_ANALOG_INTERFACE" == ID and information is not None:
            if self.bsp_information == information:
                return
            self.bsp_information = information

            # Reset all analog groups
            for analog_group in self.analog_groups:
                analog_group.resetPLIB()
            analog_group.reset_used_interfaces_list()

            # Set unit and channel symbol for phase A current
            instance = next(iter(information['IA']))
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

