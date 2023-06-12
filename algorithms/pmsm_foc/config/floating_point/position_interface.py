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
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcFocI_PositionInterfaceClass:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

        # Read position interfaces from ATDF file
        self.mapForQea = dict()
        self.mapForQeb = dict()

        if "SAME70" in MCU:
            module_Path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"TC\"]"
            modules = ATDF.getNode(module_Path).getChildren()

            self.instance_List = list()
            self.function_Map = dict()
            self.function_Map["QEA"] = dict()
            self.function_Map["QEB"] = dict()

            for module in modules:
                key = module.getAttribute("name")
                self.instance_List.append(key)
                channel_Path = module_Path + "/instance@[name=\"" + key + "\"]/signals"
                channels = ATDF.getNode(channel_Path).getChildren()

                self.function_Map["QEA"][key] = list()
                self.function_Map["QEB"][key] = list()

                for channel in channels:
                    if "TIOA" == channel.getAttribute("group"):
                        self.function_Map["QEA"][key].append(str(channel.getAttribute("pad")))
                    if "TIOB" == channel.getAttribute("group"):
                        self.function_Map["QEB"][key].append(str(channel.getAttribute("pad")))

            self.instance_List.sort()

        elif "SAME54" in MCU:
            module_Path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"PDEC\"]"
            modules = ATDF.getNode(module_Path).getChildren()

            self.instance_List = list()
            self.function_Map = dict()
            self.function_Map["QEA"] = dict()
            self.function_Map["QEB"] = dict()

            for module in modules:
                key = module.getAttribute("name")
                self.instance_List.append(key)
                channel_Path = module_Path + "/instance@[name=\"" + key + "\"]/signals"
                channels = ATDF.getNode(channel_Path).getChildren()
                self.function_Map["QEA"][key] = list()
                self.function_Map["QEB"][key] = list()

                for channel in channels:
                    if "0" == channel.getAttribute("index"):
                        self.function_Map["QEA"][key].append(str(channel.getAttribute("pad")))
                    if "1" == channel.getAttribute("index"):
                        self.function_Map["QEB"][key].append(str(channel.getAttribute("pad")))

            self.instance_List.sort()

        elif "PIC32MK" in MCU:
            # Pin to quadrature decoder mapping
            currentPath = Variables.get("__CSP_DIR") + "/peripheral/gpio_02467"
            deviceXmlPath = os.path.join(currentPath, "plugin/pin_xml/components/" + Variables.get("__PROCESSOR") + ".xml")
            deviceXmlTree = ET.parse(deviceXmlPath)
            deviceXmlRoot = deviceXmlTree.getroot()
            pinoutXmlName = deviceXmlRoot.get("pins")
            pinoutXmlPath = os.path.join(currentPath, "plugin/pin_xml/pins/" + pinoutXmlName + ".xml")
            pinoutXmlPath = os.path.normpath(pinoutXmlPath)

            familiesXmlName = deviceXmlRoot.get("families")
            familiesXmlPath = os.path.join(currentPath, "plugin/pin_xml/families/" + familiesXmlName + ".xml")
            familiesXmlPath = os.path.normpath(familiesXmlPath)

            pinFileContent = ET.fromstring((open(familiesXmlPath, "r")).read())

            self.function_Map = {'QEA': {}, 'QEB':{}}
            self.instance_List = set()
            for group in pinFileContent.findall("groups/group"):
                for function in group.findall("function"):
                    if function.attrib["name"].startswith("QEA"):
                        for pin in group.findall("pin"):
                            channel = self.numericFilter(function.attrib["name"])
                            unit = "QEI" + channel
                            pad = self.stringReplace(pin.attrib["name"])

                            try:
                                self.function_Map["QEA"][unit].append( pad )
                            except:
                                self.function_Map["QEA"][unit] = list()
                                self.function_Map["QEA"][unit] = [pad]

                            self.instance_List.add(unit)

                    if function.attrib["name"].startswith("QEB"):
                        for pin in group.findall("pin"):
                            channel = self.numericFilter(function.attrib["name"])
                            unit = "QEI" + channel
                            pad = self.stringReplace(pin.attrib["name"])

                            try:
                                self.function_Map["QEB"][unit].append(pad)
                            except:
                                self.function_Map["QEB"][unit] = list()
                                self.function_Map["QEB"][unit] = [pad]

                            self.instance_List.add(unit)

            self.instance_List = list(self.instance_List)

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def stringReplace( self, my_String ):
        my_String = my_String.replace("RP","R")
        return my_String

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
        self.sym_PERIPHERAL = self.component.createComboSymbol("MCPMSMFOC_ENCODER_PERIPHERAL", self.sym_ENCODER, self.instance_List)
        self.sym_PERIPHERAL.setLabel("Select instance")

        self.sym_PERIPHERAL_ID = self.component.createStringSymbol("MCPMSMFOC_ENCODER_PERIPHERAL_ID", None)
        self.sym_PERIPHERAL_ID.setLabel("Peripheral ID")
        self.sym_PERIPHERAL_ID.setVisible(False)
        self.sym_PERIPHERAL_ID.setDefaultValue((self.sym_PERIPHERAL.getValue()).lower())
        self.sym_PERIPHERAL_ID.setDependencies(self.updatePeripheralInstance, ["MCPMSMFOC_ENCODER_PERIPHERAL"] )

        # QEA
        self.sym_QEA = mcFun_AdvancedComboSymbol("QEA", "QEA", self.component)
        self.sym_QEA.createComboSymbol(self.sym_PERIPHERAL, self.sym_ENCODER, self.function_Map["QEA"])

        self.sym_QEB = mcFun_AdvancedComboSymbol("QEB", "QEB", self.component)
        self.sym_QEB.createComboSymbol(self.sym_PERIPHERAL, self.sym_ENCODER, self.function_Map["QEB"])

        self.sym_ENCODER_MODULE = self.component.createStringSymbol("MCPMSMFOC_ENCODERPLIB", None)
        self.sym_ENCODER_MODULE.setVisible(False)


        # PLIB update symbol
        self.sym_PLIB_UPDATE = self.component.createMenuSymbol( None, None)
        self.sym_PLIB_UPDATE.setLabel("Signal B Configuration")
        self.sym_PLIB_UPDATE.setVisible(False)
        self.sym_PLIB_UPDATE.setDependencies(self.updatePLIB, ["MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV",
                                                               "MCPMSMFOC_ENCODER_PERIPHERAL",
                                                               self.sym_QEA.getSymbolID(),
                                                               self.sym_QEB.getSymbolID()
                                                               ])

    def setSymbolValues(self):
        information = Database.sendMessage("bsp", "MCPMSMFOC_POSITION_INTERFACE", {})
        if( None != information ):
            if information["QEA"]["FUNCTION"][0][0] == information["QEB"]["FUNCTION"][0][0]:
                self.sym_PERIPHERAL.setValue(information["QEA"]["FUNCTION"][0][0])

            self.sym_QEA.setValue(information["QEA"]["FUNCTION"][0][1])
            self.sym_QEB.setValue(information["QEB"]["FUNCTION"][0][1])

    def updateSymbolValues(self, information):
        if( None != information ):
            if information["QEA"]["FUNCTION"][0][0] == information["QEB"]["FUNCTION"][0][0]:
                self.sym_PERIPHERAL.setValue(information["QEA"]["FUNCTION"][0][0])

            self.sym_QEA.setValue(information["QEA"]["FUNCTION"][0][1])
            self.sym_QEB.setValue(information["QEB"]["FUNCTION"][0][1])

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

    def handleMessage(self, ID, information ):
        if( "BSP_POSITION_INTERFACE" == ID ):
             if( None != information ):
                if information["QEA"]["FUNCTION"][0][0] == information["QEB"]["FUNCTION"][0][0]:
                    self.sym_PERIPHERAL.setValue(information["QEA"]["FUNCTION"][0][0])

                self.sym_QEA.setValue(information["QEA"]["FUNCTION"][0][1])
                self.sym_QEB.setValue(information["QEB"]["FUNCTION"][0][1])




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
        self.createSymbols()
        self.setSymbolValues()

