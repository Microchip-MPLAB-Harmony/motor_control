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
class mcPwmI_PwmInterfaceClass:
    """
    Description:
    This is initilaization function
    """ 
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

        if "SAME70" in MCU: 
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

        if "SAME54" in MCU: 
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

        elif "PIC32MK" in MCU:
            # currentPath = os.path.dirname(os.path.abspath(inspect.stack()[0][1]))
            currentPath = "D:/Release/csp/peripheral/gpio_02467"
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

        #------------------------------------ Channel Configuration -----------------------------------------# 
        self.sym_PWM = self.component.createMenuSymbol("MCPMSMFOC_PWM_MENU", self.sym_NODE )
        self.sym_PWM.setLabel("Channel Configuration")
        
        # PWM instance 
        available = sorted(self.function_Map.keys())
        self.sym_INSTANCE = self.component.createComboSymbol("MCPMSMFOC_PWM_INSTANCE", self.sym_PWM, available )
        self.sym_INSTANCE.setLabel("Select Instance")

        # PWM Period
        self.sym_PWM_FREQ = self.component.createFloatSymbol("MCPMSMFOC_PWM_FREQUENCY", self.sym_PWM )
        self.sym_PWM_FREQ.setLabel("PWM Frequency (Hz)")
        self.sym_PWM_FREQ.setDefaultValue(20000.0)

        # PWM Period
        self.sym_DEAD_TIME = self.component.createFloatSymbol("MCPMSMFOC_PWM_DEAD_TIME", self.sym_PWM )
        self.sym_DEAD_TIME.setLabel("Dead time (uS)")
        self.sym_DEAD_TIME.setDefaultValue(1.0)
        
        # PWM Channel A
        self.sym_PWMA = mcFun_AdvancedComboSymbol( "PWM A", "PWM_A", self.component)
        self.sym_PWMA.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)

        # PWM Channel B
        self.sym_PWMB = mcFun_AdvancedComboSymbol( "PWM B", "PWM_B", self.component)
        self.sym_PWMB.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)

        # PWM Channel C
        self.sym_PWMC = mcFun_AdvancedComboSymbol( "PWM C", "PWM_C", self.component)
        self.sym_PWMC.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)


        #------------------------------------ Fault Configuration -----------------------------------------# 
        self.sym_FAULT = self.component.createMenuSymbol("MCPMSMFOC_PWM_FAULT_", self.sym_NODE )
        self.sym_FAULT.setLabel("Fault Configuration")

        # Fault selection
        fault = ['Fault 01', 'Fault 02', 'Fault 03']
        self.sym_FAULT_SELECT = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_SELECT", self.sym_FAULT, fault )
        self.sym_FAULT_SELECT.setLabel("Select Fault")
        
        # Fault polarity
        state = ['Active Low', 'Active High']
        self.sym_FAULT_STATE = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_STATE", self.sym_FAULT, state )
        self.sym_FAULT_STATE.setLabel("Fault Polarity")
        
        # Fault recovery
        mode = ['Recoverable', 'Non-Recoverable']
        self.sym_FAULT_TYPE = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_TYPE", self.sym_FAULT, mode )
        self.sym_FAULT_TYPE.setLabel("Fault Mode")

        # Fault digital filter
        self.sym_FAULT_FILTER = self.component.createIntegerSymbol("MCPMSMFOC_PWM_FAULT_FILTER", self.sym_FAULT )
        self.sym_FAULT_FILTER.setLabel("Fault Filter")
        self.sym_FAULT_FILTER.setDefaultValue(2)

        # PLIB update symbol
        self.sym_PLIB_UPDATE = self.component.createMenuSymbol( None, None)
        self.sym_PLIB_UPDATE.setLabel("Signal B Configuration")
        self.sym_PLIB_UPDATE.setVisible(False)
        self.sym_PLIB_UPDATE.setDependencies(self.updatePLIB, ["MCPMSMFOC_PWM_INSTANCE_",
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
    
    def setSymbolValues(self):
        information = Database.sendMessage("bsp", "MCPMSMFOC_READ_PWMI_INFORMATION", {})
        if( None != information ):
            self.sym_INSTANCE.setValue(str(information["PWM_AH"]["FUNCTION"][0][0]))
            self.sym_PWMA.setValue("Channel" + " " + str(information["PWM_AH"]["FUNCTION"][0][1]))
            self.sym_PWMB.setValue("Channel" + " " + str(information["PWM_BH"]["FUNCTION"][0][1]))
            self.sym_PWMC.setValue("Channel" + " " + str(information["PWM_CH"]["FUNCTION"][0][1]))

    def updateSymbolValues(self, information):
        if( None != information ):
            self.sym_INSTANCE.setValue(str(information["PWM_AH"][0][0]))
            self.sym_PWMA.setValue("Channel" + " " + str(information["PWM_AH"]["FUNCTION"][0][1]))
            self.sym_PWMB.setValue("Channel" + " " + str(information["PWM_BH"]["FUNCTION"][0][1]))
            self.sym_PWMC.setValue("Channel" + " " + str(information["PWM_CH"]["FUNCTION"][0][1]))

    def handleMessage(self, ID, information ):

        if( "MCBSP_SEND_PWMI_INFORMATION" == ID ):
            if( None != information ):
                self.sym_INSTANCE.setValue(str(information["PWM_AH"][0]))
                self.sym_PWMA.setValue("Channel" + " " + str(information["PWM_AH"]["FUNCTION"][0][1]))
                self.sym_PWMB.setValue("Channel" + " " + str(information["PWM_BH"]["FUNCTION"][0][1]))
                self.sym_PWMC.setValue("Channel" + " " + str(information["PWM_CH"]["FUNCTION"][0][1]))
    
    def updatePLIB(self, event, symbol):
        message = dict()
        message['PWM_FREQ'     ]  =  self.sym_PWM_FREQ.getValue()
        message['PWM_PH_U'     ]  =  int(self.numericFilter(self.sym_PWMA.getValue()))
        message['PWM_PH_V'     ]  =  int(self.numericFilter(self.sym_PWMB.getValue()))
        message['PWM_PH_W'     ]  =  int(self.numericFilter(self.sym_PWMC.getValue()))
        message['PWM_DEAD_TIME']  =  self.sym_DEAD_TIME.getValue()
        message['PWM_FAULT'    ]  =  self.sym_FAULT_SELECT.getValue()

        
        # Get PLIB id
        plib_Id = self.sym_PWM_MODULE.getValue()
        if ( "None" != plib_Id ):
            Database.sendMessage(plib_Id, "PMSM_FOC_PWM_CONF", message)

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
        message['PWM_FAULT'    ]  =  self.sym_FAULT_SELECT.getValue()

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
       


    
        



