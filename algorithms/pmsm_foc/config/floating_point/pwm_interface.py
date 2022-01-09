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

        # PWM Period
        self.sym_PWM_FREQ = self.component.createFloatSymbol("MCPMSMFOC_PWM_FREQUENCY", self.sym_PWM )
        self.sym_PWM_FREQ.setLabel("PWM Frequency (Hz)")
        self.sym_PWM_FREQ.setDefaultValue(20000.0)

        # PWM Period
        self.sym_DEAD_TIME = self.component.createFloatSymbol("MCPMSMFOC_PWM_DEAD_TIME", self.sym_PWM )
        self.sym_DEAD_TIME.setLabel("Dead time (uS)")
        self.sym_DEAD_TIME.setDefaultValue(1.0)
        
        # PWM Channel A
        global global_ADC_TRIGGER
        self.sym_PWMA = mcFun_AdvancedComboSymbol( "PWM A", "PWM_A", self.component)
        self.sym_PWMA.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)
        self.sym_PWMA.setDefaultValue("Channel 0")
        global_ADC_TRIGGER = self.sym_PWMA.getFinalSymbol()

        # PWM Channel B
        self.sym_PWMB = mcFun_AdvancedComboSymbol( "PWM B", "PWM_B", self.component)
        self.sym_PWMB.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)
        self.sym_PWMB.setDefaultValue("Channel 1")

        # PWM Channel C
        self.sym_PWMC = mcFun_AdvancedComboSymbol( "PWM C", "PWM_C", self.component)
        self.sym_PWMC.createComboSymbol(self.sym_INSTANCE, self.sym_PWM, self.function_Map)
        self.sym_PWMC.setDefaultValue("Channel 2")


        #------------------------------------ Fault Configuration -----------------------------------------# 
        self.sym_FAULT = self.component.createMenuSymbol("MCPMSMFOC_PWM_FAULT_", self.sym_NODE )
        self.sym_FAULT.setLabel("Fault Configuration")

        # Fault selection
        fault = ['External Pin']
        self.sym_FAULT_SELECT = self.component.createComboSymbol("MCPMSMFOC_PWM_FAULT_SELECT", self.sym_FAULT, fault )
        self.sym_FAULT_SELECT.setLabel("Fault Input")

        global global_PWM_FAULT
        global_PWM_FAULT = self.sym_FAULT_SELECT
        
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
    
    def setSymbolValues(self):
        information = Database.sendMessage("bsp", "MCPMSMFOC_READ_PWMI_INFORMATION", {})
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
        if( "MCBSP_SEND_PWMI_INFORMATION" == ID ):
            if( None != information ):
                self.sym_INSTANCE.setValue(str(information["PWM_AH"]["FUNCTION"][0][0]))
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
       


    
        



