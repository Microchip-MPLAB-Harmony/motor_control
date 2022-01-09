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


#---------------------------------------------------------------------------------------#
#                                Global Variables                                       #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                   Classes                                             #
#---------------------------------------------------------------------------------------#
class mcAniI_AnalogInterfaceClass:
    def __init__(self, algorithm, component ):
        self.algorithm = algorithm
        self.component = component
        
        self.function_Map  = dict()
        if "SAME70" in MCU: 
            unit_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"AFEC\"]"
            units = ATDF.getNode(unit_path).getChildren()

            for unit in units:
                key = unit.getAttribute("name")
                channel_Path = unit_path + "/instance@[name=\"" + key + "\"]/signals"
                channels = ATDF.getNode(channel_Path).getChildren()
                self.function_Map[key] = list()
                for channel in channels:
                    if( (None != channel.getAttribute("index")) and ("AD" == channel.getAttribute("group"))):
                        self.function_Map[key].append( "Channel" + " " + str(channel.getAttribute("index")))

        elif "SAME54" in MCU: 
            unit_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"ADC\"]"
            units = ATDF.getNode(unit_path).getChildren()

            for unit in units:
                key = unit.getAttribute("name")
                channel_Path = unit_path + "/instance@[name=\"" + key + "\"]/signals"
                channels = ATDF.getNode(channel_Path).getChildren()
                function_Set = set()
                self.function_Map[key] = list()
                for channel in channels:
                    if( "AIN" in channel.getAttribute("group")):
                        function_Set.add(int(channel.getAttribute("index")))

                function_Set = sorted(function_Set)
                self.function_Map[key] = ["Channel" + " " + str(element) for element in list(function_Set)]

  
    def adchsATDFRegisterPath(self, ModuleName, RegisterName):
        labelPath = str('/avr-tools-device-file/modules/module@[name="' 
                       + ModuleName + '"]/register-group@[name="' 
                       + ModuleName + '"]/register@[name="' 
                       + RegisterName + '"]')
        return labelPath

    def adchsATDFRegisterBitfieldPath(self, ModuleName, RegisterName, BitfieldName):
        labelPath = str('/avr-tools-device-file/modules/module@[name="' +
            ModuleName + '"]/register-group@[name="' + ModuleName +
            '"]/register@[name="' + RegisterName + '"]/bitfield@[name="'
            + BitfieldName +'"]')
        return labelPath

    def adchsATDFValueGroupPath(self, ModuleName, ValueGroupName):
        value_groupPath = str('/avr-tools-device-file/modules/module@[name="'
            + ModuleName + '"]/value-group@[name="' + ValueGroupName + '"]')
        return value_groupPath

    def adchsATDFValueGroupValuePath(self, ModuleName, ValueGroupName, ValueString):
        valuePath = str('/avr-tools-device-file/modules/module@[name="' + ModuleName
            + '"]/value-group@[name="' + ValueGroupName + '"]/value@[value="' +
            ValueString + '"]')
        return valuePath

    def createSymbols( self ):
        # Root node 
        self.sym_NODE = self.component.createMenuSymbol(None, None )
        self.sym_NODE.setLabel("Analog Interface")

        #________________________________________ Peripheral Libraries_____________________________________________#
        self.sym_ANALOG_MODULE_01 = self.component.createStringSymbol("MCPMSMFOC_ADC_MODULE_01", None)
        self.sym_ANALOG_MODULE_01.setVisible(False)
        self.sym_ANALOG_MODULE_01.setDefaultValue("None")

        global global_ADC_MODULE
        global_ADC_MODULE = self.sym_ANALOG_MODULE_01

    
        self.sym_ANALOG_MODULE_02 = self.component.createStringSymbol("MCPMSMFOC_ADC_MODULE_02", None)
        self.sym_ANALOG_MODULE_02.setVisible(False)
        self.sym_ANALOG_MODULE_02.setDefaultValue("None")

        if ("SAME70" == MCU ):
            resolution = ["12", "13", "14", "15", "16"]
        elif ("SAME54" == MCU ):
            resolution = ["12", "16", "10", "8"]
        else:
            resolution = ["12", "16", "10", "8"]

        self.sym_RESOLUTION = self.component.createComboSymbol( "MCPMSMFOC_ADC_RESOLUTION", None, resolution )
        self.sym_RESOLUTION.setLabel("Resolution")
        self.sym_RESOLUTION.setVisible(False)
            
        # ____________________________________________ Group 01 ___________________________________________________#  
        self.sym_GROUP_01 = self.component.createMenuSymbol(None, self.sym_NODE )
        self.sym_GROUP_01.setLabel("Group 01 Signals")

        # Phase A current 
        self.sym_IA = self.component.createMenuSymbol("MCPMSMFOC_PHASE_CURRENT_IA_NODE", self.sym_GROUP_01)
        self.sym_IA.setLabel("Signal A Configuration")

        self.sym_IA_NAME =  self.component.createStringSymbol("MCPMSMFOC_PHASE_CURRENT_IA_NAME", self.sym_IA )
        self.sym_IA_NAME.setLabel("Signal Name")
        self.sym_IA_NAME.setDefaultValue("IaSens")
        self.sym_IA_NAME.setReadOnly(True)

        self.sym_IA_UNIT = self.component.createComboSymbol("MCPMSMFOC_PHASE_CURRENT_IA_UNIT", self.sym_IA, sorted(self.function_Map.keys()))
        self.sym_IA_UNIT.setLabel("ADC unit")

        self.sym_IA_CHANNEL = mcFun_AdvancedComboSymbol("ADC channel", "PHASE_CURRENT_IA", self.component)
        self.sym_IA_CHANNEL.createComboSymbol( self.sym_IA_UNIT, self.sym_IA, self.function_Map )
        self.sym_IA_CHANNEL.setDefaultValue("Channel 0")

        # Phase B current 
        self.sym_IB = self.component.createMenuSymbol("MCPMSMFOC_PHASE_CURRENT_IB_NODE", self.sym_GROUP_01)
        self.sym_IB.setLabel("Signal B Configuration")

        self.sym_IB_NAME =  self.component.createStringSymbol("MCPMSMFOC_PHASE_CURRENT_IB_NAME", self.sym_IB)
        self.sym_IB_NAME.setLabel("Signal Name")
        self.sym_IB_NAME.setDefaultValue("IbSens")
        self.sym_IB_NAME.setReadOnly(True)
        
        self.sym_IB_UNIT = self.component.createComboSymbol("MCPMSMFOC_PHASE_CURRENT_IB_UNIT", self.sym_IB,  sorted(self.function_Map.keys()))
        self.sym_IB_UNIT.setLabel("ADC unit")

        self.sym_IB_CHANNEL = mcFun_AdvancedComboSymbol("ADC channel", "PHASE_CURRENT_IB", self.component)
        self.sym_IB_CHANNEL.createComboSymbol( self.sym_IB_UNIT, self.sym_IB, self.function_Map )
        self.sym_IB_CHANNEL.setDefaultValue("Channel 0")

        # Phase C current 
        self.sym_IDC = self.component.createMenuSymbol("MCPMSMFOC_DC_BUS_CURRENT_IDC_NODE", self.sym_GROUP_01)
        self.sym_IDC.setLabel("DC bus current")
        self.sym_IDC.setVisible(False)
        
        self.sym_IDC_UNIT = self.component.createComboSymbol("MCPMSMFOC_DC_BUS_CURRENT_UNIT", self.sym_IDC,  sorted(self.function_Map.keys()))
        self.sym_IDC_UNIT.setLabel("ADC unit")

        self.sym_IDC_CHANNEL = mcFun_AdvancedComboSymbol("ADC channel", "DC_BUS_CURRENT_B", self.component)
        self.sym_IDC_CHANNEL.createComboSymbol( self.sym_IDC_UNIT, self.sym_IDC, self.function_Map )
        self.sym_IDC_CHANNEL.setDefaultValue("Channel 0")

        # ____________________________________________ Group 02 ___________________________________________________#  

        self.sym_GROUP_02 = self.component.createMenuSymbol(None, self.sym_NODE )
        self.sym_GROUP_02.setLabel("Group 02 Signals")

        # Phase A current 
        self.sym_VDC = self.component.createMenuSymbol("MCPMSMFOC_BUS_VOLTAGE_VDC_NODE", self.sym_GROUP_02)
        self.sym_VDC.setLabel("Signal A Configuration")

        self.sym_VDC_NAME =  self.component.createStringSymbol("MCPMSMFOC_BUS_VOLTAGE_VDC_NAME", self.sym_VDC )
        self.sym_VDC_NAME.setLabel("Signal Name")
        self.sym_VDC_NAME.setDefaultValue("VdcSens")
        self.sym_VDC_NAME.setReadOnly(True)

        self.sym_VDC_UNIT = self.component.createComboSymbol("MCPMSMFOC_BUS_VOLTAGE_VDC_UNIT", self.sym_VDC,  sorted(self.function_Map.keys()))
        self.sym_VDC_UNIT.setLabel("ADC unit")

        self.sym_VDC_CHANNEL = mcFun_AdvancedComboSymbol("ADC channel", "BUS_VOLTAGE_VDC", self.component)
        self.sym_VDC_CHANNEL.createComboSymbol( self.sym_VDC_UNIT, self.sym_VDC, self.function_Map )
        self.sym_VDC_CHANNEL.setDefaultValue("Channel 0")

        # Potentiometer
        self.sym_VPOT = self.component.createMenuSymbol("MCPMSMFOC_POTENTIOMETER_VPOT_NODE", self.sym_GROUP_02)
        self.sym_VPOT.setLabel("Signal B Configuration")

        self.sym_VPOT_NAME =  self.component.createStringSymbol("MCPMSMFOC_POTENTIOMETER_VPOT_NAME", self.sym_VPOT)
        self.sym_VPOT_NAME.setLabel("Signal Name")
        self.sym_VPOT_NAME.setDefaultValue("VpotSens")
        self.sym_VPOT_NAME.setReadOnly(True)
        
        self.sym_VPOT_UNIT = self.component.createComboSymbol("MCPMSMFOC_POTENTIOMETER_VPOT_UNIT", self.sym_VPOT,  sorted(self.function_Map.keys()))
        self.sym_VPOT_UNIT.setLabel("ADC unit")

        self.sym_VPOT_CHANNEL = mcFun_AdvancedComboSymbol("ADC channel", "POTENTIOMETER_VPOT", self.component)
        self.sym_VPOT_CHANNEL.createComboSymbol( self.sym_VPOT_UNIT, self.sym_VPOT, self.function_Map )
        self.sym_VPOT_CHANNEL.setDefaultValue("Channel 0")

        # PLIB update symbol
        self.sym_PLIB_UPDATE = self.component.createMenuSymbol( None, None)
        self.sym_PLIB_UPDATE.setLabel("Signal B Configuration")
        self.sym_PLIB_UPDATE.setVisible(False)
        self.sym_PLIB_UPDATE.setDependencies(self.updateAbstractionLayer, ["MCPMSMFOC_PHASE_CURRENT_IA_UNIT",
                                                               "MCPMSMFOC_PHASE_CURRENT_IB_UNIT",
                                                               "MCPMSMFOC_DC_BUS_CURRENT_UNIT",
                                                               "MCPMSMFOC_BUS_VOLTAGE_VDC_NAME",
                                                               "MCPMSMFOC_POTENTIOMETER_VPOT_UNIT",
                                                               self.sym_IA_CHANNEL.getSymbolID(),
                                                               self.sym_IB_CHANNEL.getSymbolID(),
                                                               self.sym_IDC_CHANNEL.getSymbolID(),
                                                               self.sym_VDC_CHANNEL.getSymbolID(),
                                                               self.sym_VPOT_CHANNEL.getSymbolID()
                                                               ])

    
    def setSymbolValues(self):
        
        information = Database.sendMessage("bsp", "MCPMSMFOC_READ_ANI_INFORMATION", {})
     
        if( None != information):
            # Phase A current 
            self.sym_IA_UNIT.setValue(information["IA"]["FUNCTION"][0][0])
            self.sym_IA_CHANNEL.setValue("Channel" + " " + information["IA"]["FUNCTION"][0][1])

            # Phase B current 
            self.sym_IB_UNIT.setValue(information["IB"]["FUNCTION"][0][0])
            self.sym_IB_CHANNEL.setValue("Channel" + " " + information["IB"]["FUNCTION"][0][1])
            
            # DC bus current 
            self.sym_IDC_UNIT.setValue(information["IDC"]["FUNCTION"][0][0])
            self.sym_IDC_CHANNEL.setValue("Channel" + " " + information["IDC"]["FUNCTION"][0][1])

            # DC bus voltage 
            self.sym_VDC_UNIT.setValue(information["VDC"]["FUNCTION"][0][0])
            self.sym_VDC_CHANNEL.setValue("Channel" + " " + information["VDC"]["FUNCTION"][0][1])  
        
            # Get the possible analog interfaces for Vpot 
            self.sym_VPOT_UNIT.setValue(information["VPOT"]["FUNCTION"][0][0])
            self.sym_VPOT_CHANNEL.setValue("Channel" + " " + information["VPOT"]["FUNCTION"][0][1])  

    def handleMessage(self, ID, information ):   
        if( "BSP_ANALOG_INTERFACE" == ID ) and ( None != information):
            print(information)
            # Phase A current 
            self.sym_IA_UNIT.setValue(information["IA"]["FUNCTION"][0][0])
            self.sym_IA_CHANNEL.setValue("Channel" + " " + information["IA"]["FUNCTION"][0][1])

            # Phase B current 
            self.sym_IB_UNIT.setValue(information["IB"]["FUNCTION"][0][0])
            self.sym_IB_CHANNEL.setValue("Channel" + " " + information["IB"]["FUNCTION"][0][1])

            # DC bus current 
            self.sym_IDC_UNIT.setValue(information["IDC"]["FUNCTION"][0][0])
            self.sym_IDC_CHANNEL.setValue("Channel" + " " + information["IDC"]["FUNCTION"][0][1])

            # DC bus voltage 
            self.sym_VDC_UNIT.setValue(information["VDC"]["FUNCTION"][0][0])
            self.sym_VDC_CHANNEL.setValue("Channel" + " " + information["VDC"]["FUNCTION"][0][1])  
        
            # Get the possible analog interfaces for Vpot 
            self.sym_VPOT_UNIT.setValue(information["VPOT"]["FUNCTION"][0][0])
            self.sym_VPOT_CHANNEL.setValue("Channel" + " " + information["VPOT"]["FUNCTION"][0][1])  

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def updateAbstractionLayer(self, symbol, event):
        message = {}  

        trigger = global_ADC_TRIGGER.getValue()
                      
        message['PHASE_U'   ] = int(self.numericFilter(self.sym_IA_UNIT.getValue()      ))
        message['PHASE_U_CH'] = int(self.numericFilter(self.sym_IA_CHANNEL.getValue()   ))
        message['PHASE_V'   ] = int(self.numericFilter(self.sym_IB_UNIT.getValue()      ))
        message['PHASE_V_CH'] = int(self.numericFilter(self.sym_IB_CHANNEL.getValue()   ))
        message['POT'       ] = int(self.numericFilter(self.sym_VPOT_UNIT.getValue()    ))
        message['POT_CH'    ] = int(self.numericFilter(self.sym_VPOT_CHANNEL.getValue() ))
        message['VDC'       ] = int(self.numericFilter(self.sym_VDC_UNIT.getValue()     ))
        message['VDC_CH'    ] = int(self.numericFilter(self.sym_VDC_CHANNEL.getValue()  ))
        message['RESOLUTION'] = int(self.numericFilter(self.sym_RESOLUTION.getValue()   ))
        message['TRIGGER'   ] = self.numericFilter(trigger                          )
           
        plib01_Id = self.sym_ANALOG_MODULE_01.getValue()
        if(plib01_Id != "None" ):
            Database.sendMessage( plib01_Id, "PMSM_FOC_ADC_CH_CONF", message)

        plib02_Id = self.sym_ANALOG_MODULE_02.getValue()
        if(plib02_Id != "None" ):
            Database.sendMessage( plib02_Id, "PMSM_FOC_ADC_CH_CONF", message)
            

    def onAttachmentConnected(self, source, target):
        message = {}
 
        localComponent = source["component"]
        remoteComponent = target["component"]
        remoteID = remoteComponent.getID()
        connectID = source["id"]
        targetID = target["id"]

        trigger = localComponent.getSymbolValue("MCPMSMFOC_PWM_INSTANCE_PWM_A_FINAL")
                      
        message['PHASE_U'   ] = int(self.numericFilter(self.sym_IA_UNIT.getValue()      ))
        message['PHASE_U_CH'] = int(self.numericFilter(self.sym_IA_CHANNEL.getValue()   ))
        message['PHASE_V'   ] = int(self.numericFilter(self.sym_IB_UNIT.getValue()      ))
        message['PHASE_V_CH'] = int(self.numericFilter(self.sym_IB_CHANNEL.getValue()   ))
        message['POT'       ] = int(self.numericFilter(self.sym_VPOT_UNIT.getValue()    ))
        message['POT_CH'    ] = int(self.numericFilter(self.sym_VPOT_CHANNEL.getValue() ))
        message['VDC'       ] = int(self.numericFilter(self.sym_VDC_UNIT.getValue()     ))
        message['VDC_CH'    ] = int(self.numericFilter(self.sym_VDC_CHANNEL.getValue()  ))
        message['RESOLUTION'] = int(self.numericFilter(self.sym_RESOLUTION.getValue()   ))
        message['TRIGGER'   ] = self.numericFilter(trigger                          )
    
        if ( connectID == "pmsmfoc_ADC" ):
            instanceNum = (filter(str.isdigit,str(remoteID)))
            if (instanceNum == str(0) or instanceNum == ""):
                self.sym_ANALOG_MODULE_01.setValue(remoteID)
            else:
                self.sym_ANALOG_MODULE_02.setValue(remoteID)
    
            Database.sendMessage(remoteID, "PMSM_FOC_ADC_CH_CONF", message)

    """
    Description:
    This function performs tasks on ADC modules de-attachment

    """
    def onAttachmentDisconnected( self, source, target):
        if ( source["id"] == "pmsmfoc_ADC"):
            self.sym_ANALOG_MODULE_01.setValue("None")
            self.sym_ANALOG_MODULE_02.setValue("None")

    def __call__(self):
        self.createSymbols()
        self.setSymbolValues()


            
    



