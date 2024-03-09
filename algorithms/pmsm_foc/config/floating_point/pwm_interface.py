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
#                                     Import                                            #
#---------------------------------------------------------------------------------------#
import os.path

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 Global variables                                      #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                     Classes                                           #
#---------------------------------------------------------------------------------------#

class mcPwmI_PwmInterfaceClass:
    """
    Description:
    This is initilaization function
    """
    def __init__(self, component, pin_manager):
        self.component = component
        self.pin_manager = pin_manager

        # Instantiate analog interface class
        device = mcDevI_PwmInterfaceClass(component)
        self.information = device.information
        self.name = device.name
        self.id = device.id
        self.fault_sources = device.externalFaultSources

        # ToDO: Check if the implementation can be optimized
        self.event_System = mcEvtI_EventSystemClass(component)
        self.event_System()

    """
    Description:
    Create pin symbols for PWM
    """
    def createPwmGroupSymbols(self, channel_name, channel_label):
        def updateChannelList( symbol, event):
            if self.sym_INSTANCE.getValue() != "** Select **":
                channel_list = ["** Select **"] + sorted(self.information[event["value"]].keys())
                symbol.setRange(channel_list)

        def updateHighSidePadList(symbol, event):
            if self.sym_INSTANCE.getValue() != "** Select **" and event["value"] != "** Select **":

                # Remove old pad from the list
                self.pin_manager.removePinFromList(old_hs_pad.getValue())
                old_hs_pad.setValue(hs_pad.getValue())

                # Add new pad to the list
                self.pin_manager.addPinToList(hs_pad.getValue())

                pad_list = ["** Select **"]
                if self.sym_INSTANCE.getValue() != "** Select **" and channel.getValue() != "** Select **":
                    pad_list += sorted(self.information[self.sym_INSTANCE.getValue()][channel.getValue()]["high"])

                # Use list comprehension to create a new list that filters elements
                pad_list = [entry for entry in pad_list if entry not in self.pin_manager.getUsedPinList() or entry == hs_pad.getValue()]

                value = symbol.getValue()
                symbol.setRange(pad_list)
                symbol.setValue(value)


        def updateLowSidePadList(symbol, event):
            if self.sym_INSTANCE.getValue() != "** Select **" and  event["value"] != "** Select **":
                # Remove old pad from the list
                self.pin_manager.removePinFromList(old_ls_pad.getValue())
                old_ls_pad.setValue(ls_pad.getValue())

                # Add new pad to the list
                self.pin_manager.addPinToList(ls_pad.getValue())

                pad_list = ["** Select **"]
                if self.sym_INSTANCE.getValue() != "** Select **" and channel.getValue() != "** Select **":
                    pad_list += sorted(self.information[self.sym_INSTANCE.getValue()][channel.getValue()]["low"])

                # Use list comprehension to create a new list that filters elements
                pad_list = [entry for entry in pad_list if entry not in self.pin_manager.getUsedPinList() or entry == ls_pad.getValue()]

                value = symbol.getValue()
                symbol.setRange(pad_list)
                symbol.setValue(value)


        # Create the PWM channel symbol
        channel_symbol_id = "MCPMSMFOC_PWM_" + channel_name + "_CHANNEL"
        channel = self.component.createComboSymbol( channel_symbol_id, self.sym_PWM, ["** Select **"])
        channel.setLabel(channel_label + " Channel")
        channel.setDefaultValue("** Select **")
        channel.setDependencies(updateChannelList, ["MCPMSMFOC_PWM_INSTANCE"])

        # Create the old PWM symbols
        old_hs_pad_symbol = "MCPMSMFOC_OLD_PWM_" + channel_name + "H_PAD"
        old_hs_pad = self.component.createStringSymbol(old_hs_pad_symbol, channel)
        old_hs_pad.setLabel("Old PWM" + channel_name + "H")
        old_hs_pad.setDefaultValue("** Select **")
        old_hs_pad.setVisible(False)

        # Create the PWMH symbol
        hs_pad_symbol = "MCPMSMFOC_PWM_" + channel_name + "H_PAD"
        hs_pad = self.component.createComboSymbol(hs_pad_symbol, channel, ["** Select **"])
        hs_pad.setLabel("PWM" + channel_name + "H")
        hs_pad.setDefaultValue("** Select **")
        hs_pad.setVisible(False)
        hs_pad.setDependencies(updateHighSidePadList, [channel_symbol_id, hs_pad_symbol, "MCPMSMFOC_USED_PIN_LIST"])

        old_ls_pad_symbol = "MCPMSMFOC_OLD_PWM_" + channel_name + "L_PAD"
        old_ls_pad = self.component.createStringSymbol(old_ls_pad_symbol, channel)
        old_ls_pad.setLabel("Old PWM" + channel_name + "L")
        old_ls_pad.setDefaultValue("** Select **")
        old_ls_pad.setVisible(False)

        # Create the PWML symbol
        ls_pad_symbol = "MCPMSMFOC_PWM_" + channel_name + "L_PAD"
        ls_pad = self.component.createComboSymbol( ls_pad_symbol, channel, ["** Select **"])
        ls_pad.setLabel("PWM" + channel_name + "L")
        ls_pad.setDefaultValue("** Select **")
        ls_pad.setVisible(False)
        ls_pad.setDependencies(updateLowSidePadList, [channel_symbol_id, ls_pad_symbol, "MCPMSMFOC_USED_PIN_LIST"])

        return channel

    """
    Description:
    This function creates MHC symbols for PWM interface module
    """
    def createSymbols(self):

        #Root note
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("PWM Interface")


        # ------------------------------------ PWM PLIB -----------------------------------------------------#
        self.sym_PWM_MODULE = self.component.createStringSymbol("MCPMSMFOC_PWMPLIB", None)
        self.sym_PWM_MODULE.setVisible(False)
        self.sym_PWM_MODULE.setDefaultValue("None")

        global global_PWM_MODULE
        global_PWM_MODULE = self.sym_PWM_MODULE

        #------------------------------------ Channel Configuration -----------------------------------------#
        self.sym_PWM = self.component.createMenuSymbol("MCPMSMFOC_PWM_MENU", self.sym_NODE )
        self.sym_PWM.setLabel("Channel Configuration")

        # PWM instance
        units = ["** Select **"] + sorted(self.information.keys())
        self.sym_INSTANCE = self.component.createComboSymbol("MCPMSMFOC_PWM_INSTANCE", self.sym_PWM, units )
        self.sym_INSTANCE.setLabel("Select Instance")
        self.sym_INSTANCE.setDefaultValue("** Select **")

        self.sym_INSTANCE_ID = self.component.createStringSymbol("MCPMSMFOC_PWM_PERIPHERAL_ID", None)
        self.sym_INSTANCE_ID.setLabel("Peripheral ID")
        self.sym_INSTANCE_ID.setVisible(False)
        self.sym_INSTANCE_ID.setDefaultValue((self.sym_INSTANCE.getValue()).lower())
        self.sym_INSTANCE_ID.setDependencies(self.updatePeripheralInstance, ["MCPMSMFOC_PWM_INSTANCE"] )

        # PWM Period
        self.sym_PWM_FREQ = self.component.createFloatSymbol("MCPMSMFOC_PWM_FREQUENCY", self.sym_PWM )
        self.sym_PWM_FREQ.setLabel("PWM Frequency (Hz)")
        self.sym_PWM_FREQ.setDefaultValue(20000.0)

         # PWM Period
        self.sym_PWM_PERIOD = self.component.createFloatSymbol("MCPMSMFOC_PWM_PERIOD", self.sym_PWM )
        self.sym_PWM_PERIOD.setLabel("PWM Period (in Seconds)")
        self.sym_PWM_PERIOD.setDefaultValue(0.000050)
        self.sym_PWM_PERIOD.setReadOnly(True)
        self.sym_PWM_PERIOD.setDependencies(self.updatePwmPeriod, ["MCPMSMFOC_PWM_FREQUENCY"])

        # PWM Period
        self.sym_DEAD_TIME = self.component.createFloatSymbol("MCPMSMFOC_PWM_DEAD_TIME", self.sym_PWM )
        self.sym_DEAD_TIME.setLabel("Dead time (uS)")
        self.sym_DEAD_TIME.setDefaultValue(0.64)

        # Channel map
        channel_map = {}
        for key, value in self.information.items():
            int_list = sorted([int(x) for x in value.keys()])
            channel_map[key] = ["** Select **"] + [str(x) for x in int_list]

        # PWM Channel A
        global global_ADC_TRIGGER

        # Create symbols for PWM Channel A
        global_ADC_TRIGGER = self.createPwmGroupSymbols("A", "Phase A")

        # Create symbols for PWM Channel B
        self.createPwmGroupSymbols("B", "Phase B")

        # Create symbols for PWM Channel C
        self.createPwmGroupSymbols("C", "Phase C")


        #------------------------------------ Fault Configuration -----------------------------------------#
        self.sym_FAULT = self.component.createMenuSymbol("MCPMSMFOC_PWM_FAULT_", self.sym_NODE )
        self.sym_FAULT.setLabel("Fault Configuration")

        # Fault selection
        fault = ['External Pin']
        self.sym_FAULT_SELECT = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_SELECT", self.sym_FAULT, fault )
        self.sym_FAULT_SELECT.setLabel("Fault Type")

        fault_sources = ["** Select **"] + ["None"] + self.fault_sources
        self.sym_FAULT_SOURCE = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_SOURCE", self.sym_FAULT_SELECT, fault_sources )
        self.sym_FAULT_SOURCE.setLabel("Fault Source")

        # Fault polarity
        state = ['Active Low', 'Active High']
        self.sym_FAULT_STATE = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_STATE", self.sym_FAULT_SELECT, state )
        self.sym_FAULT_STATE.setLabel("Fault Polarity")
        self.sym_FAULT_STATE.setVisible(False)


        # Fault recovery
        mode = ['Non-Recoverable', 'Recoverable']
        self.sym_FAULT_TYPE = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_TYPE", self.sym_FAULT, mode )
        self.sym_FAULT_TYPE.setLabel("Fault Mode")
        self.sym_FAULT_TYPE.setVisible(False)
        self.sym_FAULT_TYPE.setReadOnly(True)

        # Fault digital filter
        self.sym_FAULT_FILTER = self.component.createIntegerSymbol("MCPMSMFOC_PWM_FAULT_FILTER", self.sym_FAULT )
        self.sym_FAULT_FILTER.setLabel("Fault Filter")
        self.sym_FAULT_FILTER.setDefaultValue(2)
        self.sym_FAULT_FILTER.setReadOnly(True)
        self.sym_FAULT_FILTER.setVisible(False)

        # PLIB update symbol
        self.sym_PLIB_UPDATE = self.component.createMenuSymbol( None, None)
        self.sym_PLIB_UPDATE.setLabel("Signal B Configuration")
        self.sym_PLIB_UPDATE.setVisible(False)
        self.sym_PLIB_UPDATE.setDependencies(self.updatePLIB, ["MCPMSMFOC_PWM_INSTANCE",
                                                               "MCPMSMFOC_PWM_FREQUENCY",
                                                               "MCPMSMFOC_PWM_DEAD_TIME",
                                                               "MCPMSMFOC_PWM_FAULT_SOURCE",
                                                               "MCPMSMFOC_PWM_FAULT_STATE",
                                                               "MCPMSMFOC_PWM_FAULT_TYPE",
                                                               "MCPMSMFOC_PWM_FAULT_FILTER",
                                                               "MCPMSMFOC_PWM_A_CHANNEL",
                                                               "MCPMSMFOC_PWM_B_CHANNEL",
                                                               "MCPMSMFOC_PWM_C_CHANNEL",
                                                               ])

        # PLIB update symbol
        self.sym_INTERFACE_CALLBACK = self.component.createMenuSymbol( None, None)
        self.sym_INTERFACE_CALLBACK.setLabel("Interface update callback")
        self.sym_INTERFACE_CALLBACK.setVisible(False)
        self.sym_INTERFACE_CALLBACK.setDependencies(self.updateInverterInterface, ["MCPMSMFOC_PWM_INSTANCE",
                                                               "MCPMSMFOC_PWM_AH_PAD",
                                                               "MCPMSMFOC_PWM_BH_PAD",
                                                               "MCPMSMFOC_PWM_CH_PAD",
                                                               "MCPMSMFOC_PWM_AL_PAD",
                                                               "MCPMSMFOC_PWM_BL_PAD",
                                                               "MCPMSMFOC_PWM_CL_PAD",
                                                               "MCPMSMFOC_PWM_A_CHANNEL",
                                                               "MCPMSMFOC_PWM_B_CHANNEL",
                                                               "MCPMSMFOC_PWM_C_CHANNEL",
                                                               ])

    def updateInverterInterface(self, symbol, event):

        # Update the message to BSP
        unit = self.sym_INSTANCE.getValue()
        channel_a = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_A_CHANNEL")
        pad_ah = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_AH_PAD")
        pad_al = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_AL_PAD")

        channel_b = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_B_CHANNEL")
        pad_bh = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_BH_PAD")
        pad_bl = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_BL_PAD")

        channel_c = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_C_CHANNEL")
        pad_ch = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_CH_PAD")
        pad_cl = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_CL_PAD")

        PWMAH = {"CHANNEL": channel_a, "PAD": pad_ah }
        PWMAL = {"CHANNEL": channel_a, "PAD": pad_al }
        PWMBH = {"CHANNEL": channel_b, "PAD": pad_bh }
        PWMBL = {"CHANNEL": channel_b, "PAD": pad_bl }
        PWMCH = {"CHANNEL": channel_c, "PAD": pad_ch }
        PWMCL = {"CHANNEL": channel_c, "PAD": pad_cl }

        if (
            unit != "** Select **"
            and all( pwm["CHANNEL"] != "** Select **" for pwm in [PWMAH, PWMAL, PWMBH, PWMBL, PWMCH, PWMCL])
            and all( pwm["PAD"] != "** Select **" for pwm in [PWMAH, PWMAL, PWMBH, PWMBL, PWMCH, PWMCL])
        ):
            args = {
                "UNIT": unit,
                "PWMAH": PWMAH,
                "PWMAL": PWMAL,
                "PWMBH": PWMBH,
                "PWMBL": PWMBL,
                "PWMCH": PWMCH,
                "PWMCL": PWMCL,
            }

            Database.sendMessage("cstom_mc_bsp", "MCPMSMFOC_PWM_INTERFACE_SET", args)


    def setDatabaseSymbol(self, namespace, id, value):
        status = Database.setSymbolValue(namespace, id, value)

        if( status == False):
            print("Checkpoint. The symbol " + id + " could not be updated")

    def handleMessage(self, ID, information ):
        if( "BSP_PWM_INTERFACE" == ID ):
            if( None != information ):                # Set PWM peripheral
                instance = next(iter(information))
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_INSTANCE", instance)

                # Set channel and pad values for PWM phase A
                print('PWM information', information)
                channel = str(information[instance]['phase_a']['high']['channel'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_A_CHANNEL", channel)

                pad = str(information[instance]['phase_a']['high']['pad'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_AH_PAD", pad)

                pad = str(information[instance]['phase_a']['low']['pad'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_AL_PAD", pad)

                # Set channel and pad values for PWM phase B
                channel = str(information[instance]['phase_b']['high']['channel'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_B_CHANNEL", channel)

                pad = str(information[instance]['phase_b']['high']['pad'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_BH_PAD", pad)

                pad = str(information[instance]['phase_b']['low']['pad'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_BL_PAD", pad)

                # Set channel and pad values for PWM phase C
                channel = str(information[instance]['phase_c']['high']['channel'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_C_CHANNEL", channel)

                pad = str(information[instance]['phase_c']['high']['pad'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_CH_PAD", pad)

                pad = str(information[instance]['phase_c']['low']['pad'])
                self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_CL_PAD", pad)

                # Set fault pin
                # value = str(information["FAULT"]["FUNCTION"][0][1])
                # self.setDatabaseSymbol("pmsm_foc", "MCPMSMFOC_PWM_FAULT_SOURCE", value)


    def updatePwmPeriod(self, symbol, event):
        period = 1.0 / event["value"]
        symbol.setValue( period )

    def updatePLIB(self, event, symbol):
        channel_a = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_A_CHANNEL")
        channel_b = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_B_CHANNEL")
        channel_c = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_C_CHANNEL")
        fault_source = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_FAULT_SOURCE")

        if (    "** Select **" != channel_a
            and "** Select **" != channel_b
            and "** Select **" != channel_c
            # and "** Select **" != fault_source
           ):
                message = dict()
                message['PWM_FREQ'     ]  =  self.sym_PWM_FREQ.getValue()
                message['PWM_PH_U'     ]  =  int(self.numericFilter(channel_a))
                message['PWM_PH_V'     ]  =  int(self.numericFilter(channel_b))
                message['PWM_PH_W'     ]  =  int(self.numericFilter(channel_c))
                message['PWM_DEAD_TIME']  =  self.sym_DEAD_TIME.getValue()
                message['PWM_FAULT'    ]  =  fault_source

                # Get PLIB id
                plib_Id = (self.sym_INSTANCE.getValue()).lower()
                Database.sendMessage(plib_Id, "PMSM_FOC_PWM_CONF", message)

                self.event_System.setConfiguration(fault_source)

    def updatePeripheralInstance(self, symbol, event):
        if( (symbol.getValue()).lower() != event["value"].lower()):
            # De-activate existing dependencies
            autoComponentIDTable = [(symbol.getValue()).lower()]
            res = Database.deactivateComponents(autoComponentIDTable)

            # Set new dependency
            symbol.setValue(event["value"].lower())

             # Activate and connect the default PWM peripheral
            autoConnectTable = [event["value"].lower()]
            res = Database.activateComponents(autoConnectTable)

            autoComponentIDTable = [[ self.component.getID(), "pmsmfoc_PWM", event["value"].lower(), str(event["value"].upper()) + "_PWM"]]
            res = Database.connectDependencies(autoComponentIDTable)

    """
    Description:
    This function performs tasks when PWM module is connected
    """
    def onAttachmentConnected(self, source, target):
        pass

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    """
    Description:
    This function performs tasks when PWM module is disconnected
    """
    def onAttachmentDisconnected( self, source, target):
        pass


    def __call__(self):
        self.createSymbols()
