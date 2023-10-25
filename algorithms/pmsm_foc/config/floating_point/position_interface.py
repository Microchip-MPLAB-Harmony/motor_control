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

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcFocI_PositionInterfaceClass:
    def __init__(self, component, pin_manager):
        self.component = component
        self.pin_manager = pin_manager

        # Instantiate analog interface class
        device = mcDevI_PositionInterfaceClass(component)
        self.information = device.information

    def createSymbols(self):
        # Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Position Interface")
        # self.sym_NODE.setVisible(False)
        self.sym_NODE.setDependencies(self.encoderDependency, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])

        # Root node
        self.sym_ENCODER = self.component.createMenuSymbol("MCPMSMFOC_ENCODER_", self.sym_NODE )
        self.sym_ENCODER.setLabel("Encoder Connections")

        # Peripheral selection
        units = ["** Select **"] + sorted(self.information.keys())
        self.sym_PERIPHERAL = self.component.createComboSymbol("MCPMSMFOC_ENCODER_PERIPHERAL", self.sym_ENCODER, units )
        self.sym_PERIPHERAL.setLabel("Select instance")
        self.sym_PERIPHERAL.setDefaultValue("** Select **")

        self.sym_PERIPHERAL_ID = self.component.createStringSymbol("MCPMSMFOC_ENCODER_PERIPHERAL_ID", None)
        self.sym_PERIPHERAL_ID.setLabel("Peripheral ID")
        self.sym_PERIPHERAL_ID.setVisible(False)
        self.sym_PERIPHERAL_ID.setDefaultValue((self.sym_PERIPHERAL.getValue()).lower())
        self.sym_PERIPHERAL_ID.setDependencies(self.updatePeripheralInstance, ["MCPMSMFOC_ENCODER_PERIPHERAL"] )

        self.sym_OLD_QEA_PAD = self.component.createStringSymbol("MCPMSMFOC_ENCODER_OLD_QEA_PAD", self.sym_PERIPHERAL)
        self.sym_OLD_QEA_PAD.setLabel("Old QEA Pad")
        self.sym_OLD_QEA_PAD.setVisible(False)

        self.sym_QEA_PAD = self.component.createComboSymbol("MCPMSMFOC_ENCODER_QEA_PAD", self.sym_PERIPHERAL, ["** Select **"])
        self.sym_QEA_PAD.setLabel("QEA Pad")
        self.sym_QEA_PAD.setDependencies(self.updateQEAPadList, ["MCPMSMFOC_ENCODER_PERIPHERAL", "MCPMSMFOC_ENCODER_QEA_PAD", "MCPMSMFOC_USED_PIN_LIST"])

        self.sym_OLD_QEB_PAD = self.component.createStringSymbol("MCPMSMFOC_ENCODER_OLD_QEB_PAD", self.sym_PERIPHERAL)
        self.sym_OLD_QEB_PAD.setLabel("Old QEB Pad")
        self.sym_OLD_QEB_PAD.setVisible(False)

        self.sym_QEB_PAD = self.component.createComboSymbol("MCPMSMFOC_ENCODER_QEB_PAD", self.sym_PERIPHERAL,  ["** Select **"])
        self.sym_QEB_PAD.setLabel("QEB Pad")
        self.sym_QEB_PAD.setDependencies(self.updateQEBPadList, ["MCPMSMFOC_ENCODER_PERIPHERAL", "MCPMSMFOC_ENCODER_QEB_PAD", "MCPMSMFOC_USED_PIN_LIST"])

        self.sym_ENCODER_MODULE = self.component.createStringSymbol("MCPMSMFOC_ENCODERPLIB", None)
        self.sym_ENCODER_MODULE.setVisible(False)


        # PLIB update symbol
        self.sym_PLIB_UPDATE = self.component.createMenuSymbol( None, None)
        self.sym_PLIB_UPDATE.setLabel("Signal B Configuration")
        self.sym_PLIB_UPDATE.setVisible(False)
        self.sym_PLIB_UPDATE.setDependencies(self.updatePLIB, ["MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV",
                                                               "MCPMSMFOC_ENCODER_PERIPHERAL",
                                                               'MCPMSMFOC_ENCODER_QEA_PAD',
                                                               'MCPMSMFOC_ENCODER_QEB_PAD',
                                                               "MCPMSMFOC_QEA_CHANNEL",
                                                               "MCPMSMFOC_QEB_CHANNEL"
                                                               ])

        # Pad update callback
        self.sym_ENCODER_CALLBACK = self.component.createMenuSymbol(None, None)
        self.sym_ENCODER_CALLBACK.setLabel("Position interface update callback")
        self.sym_ENCODER_CALLBACK.setDependencies(self.updateEncoderInterface, ["MCPMSMFOC_ENCODER_PERIPHERAL",
                                                               'MCPMSMFOC_ENCODER_QEA_PAD',
                                                               'MCPMSMFOC_ENCODER_QEB_PAD'])
        self.sym_ENCODER_CALLBACK.setVisible(False)

    def updateEncoderInterface(self, symbol, event):
        # Update custom bsp message
        unit = self.sym_PERIPHERAL.getValue()
        QEA = self.sym_QEA_PAD.getValue()
        QEB = self.sym_QEB_PAD.getValue()

        # Get the index
        index = ""
        if unit != "** Select **" and QEA != "** Select **" and QEB != "** Select **":
            for key, pad_list in self.information[unit]["QEA"].items():
                if QEA in pad_list:
                    index = key


        if unit != "** Select **" and QEA != "** Select **" and QEB != "** Select **":
            args = {
                    "UNIT": unit,
                    "QEA": {"CHANNEL": index, "PAD": QEA },
                    "QEB": {"CHANNEL": index, "PAD": QEB }
                }
            Database.sendMessage("cstom_mc_bsp", "MCPMSMFOC_POSITION_INTERFACE_SET", args)

    def showThisSymbol(self, symbol, event):
        if True == (event["symbol"]).getValue():
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def updatePLIB(self, symbol, event):
        message = {}
        component = symbol.getComponent()
        pulses = float(component.getSymbolValue("MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV"))
        message['PULSES_PER_REV'] = pulses

        Database.sendMessage(self.sym_ENCODER_MODULE.getValue().lower(), "PMSM_FOC_ENCODER_CONF", message )

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

            autoComponentIDTable = [[ self.component.getID(), "pmsmfoc_QDEC", event["value"].lower(), str(event["value"].upper()) + "_QDEC"]]
            res = Database.connectDependencies(autoComponentIDTable)

    """
    Description:
    This function shows the rotor position algorithm parameters depending upon the selected
    algorithm
    """
    def encoderDependency(self, symbol, event):
        symObj = event["symbol"]
        if symObj.getSelectedKey() == "SENSORED_ENCODER":
            symbol.setVisible(False)
            # symbol.getComponent().setDependencyEnabled("pmsmfoc_QDEC", True)
            symbol.setVisible(True)
        else:
            symbol.setVisible(True)
            # symbol.getComponent().setDependencyEnabled("pmsmfoc_QDEC", False)
            symbol.setVisible(False)

    def updateQEAPadList(self, symbol, event):
        if self.sym_PERIPHERAL != "** Select **":
            # Remove old pin from used pin list
            self.pin_manager.removePinFromList(self.sym_OLD_QEA_PAD.getValue())
            self.sym_OLD_QEA_PAD.setValue(self.sym_QEA_PAD.getValue())

            # Add new used pi to the list
            self.pin_manager.addPinToList(self.sym_QEA_PAD.getValue())

            combined_pad_list = []

            if self.sym_PERIPHERAL.getValue() != "** Select **":
                for pad_list in self.information[self.sym_PERIPHERAL.getValue()]["QEA"].values():
                    combined_pad_list.extend(pad_list)

            combined_pad_list = sorted(combined_pad_list)

            # Use list comprehension to create a new list that filters elements
            combined_pad_list = [entry for entry in combined_pad_list if entry not in self.pin_manager.getUsedPinList() or entry == self.sym_QEA_PAD.getValue()]

            value = symbol.getValue()
            symbol.setRange(["** Select **"] + combined_pad_list)
            symbol.setValue(value)



    def updateQEBPadList(self, symbol, event):
        if self.sym_PERIPHERAL != "** Select **":
            # Remove old pin from used pin list
            self.pin_manager.removePinFromList(self.sym_OLD_QEB_PAD.getValue())
            self.sym_OLD_QEB_PAD.setValue(self.sym_QEB_PAD.getValue())

            # Add new used pi to the list
            self.pin_manager.addPinToList(self.sym_QEB_PAD.getValue())

            combined_pad_list = []

            if self.sym_PERIPHERAL.getValue() != "** Select **":
                for pad_list in self.information[self.sym_PERIPHERAL.getValue()]["QEB"].values():
                    combined_pad_list.extend(pad_list)

            combined_pad_list = sorted(combined_pad_list)

            # Use list comprehension to create a new list that filters elements
            combined_pad_list = [entry for entry in combined_pad_list if entry not in self.pin_manager.getUsedPinList() or entry == self.sym_QEB_PAD.getValue()]

            value = symbol.getValue()
            symbol.setRange(["** Select **"] + combined_pad_list)
            symbol.setValue(value)


    def handleMessage(self, ID, information ):
        if( "BSP_POSITION_INTERFACE" == ID ):
            if( None != information ):
                if information["QEA"]["FUNCTION"][0][0] == information["QEB"]["FUNCTION"][0][0]:
                    self.sym_PERIPHERAL.setValue(information["QEA"]["FUNCTION"][0][0])

                self.sym_QEA_PAD.setValue(information["QEA"]["FUNCTION"][0][1])
                self.sym_QEB_PAD.setValue(information["QEB"]["FUNCTION"][0][1])

    def onAttachmentConnected(self, source, target):
        message = dict()
        localComponent = source["component"]
        remoteComponent = target["component"]
        remoteID = remoteComponent.getID()
        connectID = source["id"]

        pulses = float(localComponent.getSymbolValue("MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV"))
        message['PULSES_PER_REV'] = pulses

        if (connectID == "pmsmfoc_QDEC"):
            Database.sendMessage(remoteID, "PMSM_FOC_ENCODER_CONF", message )
            self.sym_ENCODER_MODULE.setValue(remoteID)

    def onAttachmentDisconnected(self, source, target):
        if (source["id"] == "pmsmfoc_QDEC"):
            self.sym_ENCODER_MODULE.setValue("None")

    def __call__(self):
        if self.information:
            self.createSymbols()

