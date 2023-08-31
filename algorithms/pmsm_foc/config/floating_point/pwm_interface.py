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
SupportedPWMIps = {
    "PWM" : [
              { "name": "TCC", "id": "U2213"},
              { "name": "PWM", "id": "6343"},
              { "name": "MCPWM", "id": "01477"}
            ]
}

def getPWMIP(modules):
    for module in modules:
        for entry in SupportedPWMIps.get("PWM", []):
            if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                return entry["name"], entry["id"]
    return "",""

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
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

        # Get ADC IP from the ATDF file
        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()
        self.name, self.id = getPWMIP(modules)

        # Create a symbol for ADC IP
        self.IP  = self.component.createStringSymbol("MCPMSMFOC_PWM_IP", None )
        self.IP.setLabel("PWM IP")
        self.IP.setValue( self.name + "_" + self.id)
        self.IP.setVisible(False)

        if ( self.name == "PWM" ) and ( self.id == "6343"):
            module_Path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"PWM\"]"
            node = ATDF.getNode(module_Path)
            inst = node.getChildren()

            self.function_Map = dict()
            for ins in inst:
                key = ins.getAttribute("name")
                self.function_Map[key] = set()
                inst_Path = module_Path + "/instance@[name=\"" + key + "\"]/signals"

                channels =  ATDF.getNode(inst_Path).getChildren()
                for channel in channels:
                    self.function_Map[key].add("Channel" + " " + channel.getAttribute("index"))

                self.function_Map[key] = sorted(list(self.function_Map[key]))

            global global_PWM_FAULT
            global_PWM_FAULT = "FAULT_PWM_ID2"


        elif ( self.name == "TCC" ) and ( self.id == "U2213"):
            module_Path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"TCC\"]"
            node = ATDF.getNode(module_Path)
            inst = node.getChildren()

            self.function_Map = dict()
            for ins in inst:
                key = ins.getAttribute("name")
                self.function_Map[key] = set()
                inst_Path = module_Path + "/instance@[name=\"" + key + "\"]/signals"

                channels =  ATDF.getNode(inst_Path).getChildren()
                for channel in channels:
                    self.function_Map[key].add("Channel" + " " + channel.getAttribute("index"))

                self.function_Map[key] = sorted(list(self.function_Map[key]))

            # PWM fault management
            global global_PWM_FAULT
            global_PWM_FAULT = "EIC_CHANNEL_2"

        elif ( self.name == "MCPWM" ) and ( self.id == "01477"):
            # currentPath = os.path.dirname(os.path.abspath(inspect.stack()[0][1]))
            currentPath = Variables.get("__CSP_DIR") + "/peripheral/gpio_02467"
            deviceXmlPath = os.path.join(currentPath, "plugin/pin_xml/components/" + Variables.get("__PROCESSOR") + ".xml")
            deviceXmlTree = ET.parse(deviceXmlPath)
            deviceXmlRoot = deviceXmlTree.getroot()
            pinoutXmlName = deviceXmlRoot.get("pins")
            pinoutXmlPath = os.path.join(currentPath, "plugin/pin_xml/pins/" + pinoutXmlName + ".xml")
            pinoutXmlPath = os.path.normpath(pinoutXmlPath)


            pinFileContent = ET.fromstring((open(pinoutXmlPath, "r")).read())
            self.function_Map = dict()
            function_Set = set()
            for item in pinFileContent.findall("pins/pin"):
                for function in item.findall("function"):
                    if function.attrib["name"].startswith("PWM"):
                        unit = "MCPWM"
                        channel = self.numericFilter(function.attrib["name"])
                        try:
                            function_Set.add( int(channel) )
                        except:
                            function_Set = set([int(channel)])

            function_List = list(sorted(function_Set))
            self.function_Map[unit] = ["Channel" + " " + str(element) for element in function_List]


            # PWM fault management
            global global_PWM_FAULT
            global_PWM_FAULT = "FLT15"


    """
    Description:
    This function discards alphabets and returns the numbers only
    """
    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def stringReplace( self, my_String ):
        my_String = my_String.replace("RP","R")
        return my_String

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
        available = sorted(self.function_Map.keys())
        self.sym_INSTANCE = self.component.createComboSymbol("MCPMSMFOC_PWM_INSTANCE", self.sym_PWM, available )
        self.sym_INSTANCE.setLabel("Select Instance")
        self.sym_INSTANCE.setDefaultValue(available[0])

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

        # PWM Channel A
        global global_ADC_TRIGGER
        self.sym_PWMA = mcFun_AdvancedComboSymbol( "PWM A", "PWM_A", self.component)
        self.sym_PWMA.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)
        if ( self.name == "MCPWM" ) and ( self.id == "01477"):
            self.sym_PWMA.setDefaultValue("Channel 1")
        else:
            self.sym_PWMA.setDefaultValue("Channel 0")

        global_ADC_TRIGGER = self.sym_PWMA.getFinalSymbol()

        # PWM Channel B
        self.sym_PWMB = mcFun_AdvancedComboSymbol( "PWM B", "PWM_B", self.component)
        self.sym_PWMB.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)
        self.sym_PWMB.setDefaultValue("Channel 1")
        if ( self.name == "MCPWM" ) and ( self.id == "01477"):
            self.sym_PWMB.setDefaultValue("Channel 2")
        else:
            self.sym_PWMB.setDefaultValue("Channel 1")

        # PWM Channel C
        self.sym_PWMC = mcFun_AdvancedComboSymbol( "PWM C", "PWM_C", self.component)
        self.sym_PWMC.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)
        if ( self.name == "MCPWM" ) and ( self.id == "01477"):
            self.sym_PWMC.setDefaultValue("Channel 3")
        else:
            self.sym_PWMC.setDefaultValue("Channel 2")


        #------------------------------------ Fault Configuration -----------------------------------------#
        self.sym_FAULT = self.component.createMenuSymbol("MCPMSMFOC_PWM_FAULT_", self.sym_NODE )
        self.sym_FAULT.setLabel("Fault Configuration")

        # Fault selection
        fault = ['External Pin']
        self.sym_FAULT_SELECT = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_SELECT", self.sym_FAULT, fault )
        self.sym_FAULT_SELECT.setLabel("Fault Input")


        # Fault polarity
        state = ['Active Low', 'Active High']
        self.sym_FAULT_STATE = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_STATE", self.sym_FAULT, state )
        self.sym_FAULT_STATE.setLabel("Fault Polarity")

        # Fault recovery
        mode = ['Non-Recoverable', 'Recoverable']
        self.sym_FAULT_TYPE = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_TYPE", self.sym_FAULT, mode )
        self.sym_FAULT_TYPE.setLabel("Fault Mode")
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
                                                               "MCPMSMFOC_PWM_FAULT_SELECT",
                                                               "MCPMSMFOC_PWM_FAULT_STATE",
                                                               "MCPMSMFOC_PWM_FAULT_TYPE",
                                                               "MCPMSMFOC_PWM_FAULT_FILTER",
                                                               self.sym_PWMA.getSymbolID(),
                                                               self.sym_PWMB.getSymbolID(),
                                                               self.sym_PWMC.getSymbolID(),
                                                               ])

               # Activate and connect the default PWM peripheral


    def setSymbolValues(self):
        information = Database.sendMessage("bsp", "MCPMSMFOC_PWM_INTERFACE", {})
        if( None != information ):
            self.sym_INSTANCE.setValue(str(information["PWM_AH"]["FUNCTION"][0][0]))
            self.sym_PWMA.setValue("Channel" + " " + str(information["PWM_AH"]["FUNCTION"][0][1]))
            self.sym_PWMB.setValue("Channel" + " " + str(information["PWM_BH"]["FUNCTION"][0][1]))
            self.sym_PWMC.setValue("Channel" + " " + str(information["PWM_CH"]["FUNCTION"][0][1]))

    def updateSymbolValues(self, information):
        if( None != information ):
            self.sym_INSTANCE.setValue(str(information["PWM_AH"]["FUNCTION"][0][0]))
            self.sym_PWMA.setValue("Channel" + " " + str(information["PWM_AH"]["FUNCTION"][0][1]))
            self.sym_PWMB.setValue("Channel" + " " + str(information["PWM_BH"]["FUNCTION"][0][1]))
            self.sym_PWMC.setValue("Channel" + " " + str(information["PWM_CH"]["FUNCTION"][0][1]))

    def handleMessage(self, ID, information ):
        if( "BSP_PWM_INTERFACE" == ID ):
            if( None != information ):
                self.sym_INSTANCE.setValue(str(information["PWM_AH"]["FUNCTION"][0][0]))
                self.sym_PWMA.setValue("Channel" + " " + str(information["PWM_AH"]["FUNCTION"][0][1]))
                self.sym_PWMB.setValue("Channel" + " " + str(information["PWM_BH"]["FUNCTION"][0][1]))
                self.sym_PWMC.setValue("Channel" + " " + str(information["PWM_CH"]["FUNCTION"][0][1]))

    def updatePwmPeriod(self, event, symbol):
        symbol.setValue( event["symbol"].getValue())

    def updatePLIB(self, event, symbol):
        message = dict()
        message['PWM_FREQ'     ]  =  self.sym_PWM_FREQ.getValue()
        message['PWM_PH_U'     ]  =  int(self.numericFilter(self.sym_PWMA.getValue()))
        message['PWM_PH_V'     ]  =  int(self.numericFilter(self.sym_PWMB.getValue()))
        message['PWM_PH_W'     ]  =  int(self.numericFilter(self.sym_PWMC.getValue()))
        message['PWM_DEAD_TIME']  =  self.sym_DEAD_TIME.getValue()
        message['PWM_FAULT'    ]  =  global_PWM_FAULT #self.sym_FAULT_SELECT.getValue()


        # Get PLIB id
        plib_Id = self.sym_PWM_MODULE.getValue()
        if ( "None" != plib_Id ):
            Database.sendMessage(plib_Id, "PMSM_FOC_PWM_CONF", message)

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
        message = dict()

        localComponent = source["component"]
        remoteComponent = target["component"]
        remoteID = remoteComponent.getID()
        connectID = source["id"]
        targetID = target["id"]

        message['PWM_FREQ'     ]  =  self.sym_PWM_FREQ.getValue()
        message['PWM_PH_U'     ]  =  int(self.numericFilter(self.sym_PWMA.getValue()))
        message['PWM_PH_V'     ]  =  int(self.numericFilter(self.sym_PWMB.getValue()))
        message['PWM_PH_W'     ]  =  int(self.numericFilter(self.sym_PWMC.getValue()))
        message['PWM_DEAD_TIME']  =  self.sym_DEAD_TIME.getValue()
        message['PWM_FAULT'    ]  =  global_PWM_FAULT #self.sym_FAULT_SELECT.getValue()

        if (connectID == "pmsmfoc_PWM"):
            self.sym_PWM_MODULE.setValue(remoteID)
            Database.sendMessage(remoteID, "PMSM_FOC_PWM_CONF", message)


    """
    Description:
    This function performs tasks when PWM module is disconnected
    """
    def onAttachmentDisconnected( self, source, target):
        if ( source["id"] == "pmsmfoc_PWM"):
            self.sym_PWM_MODULE.setValue("None")


    def __call__(self):
        self.createSymbols()
        self.setSymbolValues()








