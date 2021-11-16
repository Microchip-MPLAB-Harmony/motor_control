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
#                                           IMPORT                                      #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcAnf_AnalogFrontEndClass:
    def __init__( self, algorithm, component):
        self.algorithm = algorithm
        self.component = component
    
    def setSymbolDefaults(self):
        
        bsp_Active_Status = True
        if( bsp_Active_Status == True):
            self.afe_Information = Database.sendMessage("bsp", "MCPMSMFOC_READ_AFE_INFORMATION", {})
            
    def handleMessage(self, ID, information):
        if( ID == "MCPMSMFOC_SEND_AFE_INFORMATION"):
            if None != information:
                # self.sym_NODE_IA_OPAMP.setValue("External op-amp")
                self.sym_NODE_IA_GAIN.setValue(float(information["IA"]["GAIN"]))
                self.sym_NODE_IA_OFFSET.setValue(float(information["IA"]["OFFSET"]))
                self.sym_NODE_IA_SHUNT.setValue(float(information["IA"]["SHUNT"]))

                # self.sym_NODE_IB_OPAMP.setValue("External op-amp")
                self.sym_NODE_IB_GAIN.setValue(float(information["IB"]["GAIN"]))
                self.sym_NODE_IB_OFFSET.setValue(float(information["IB"]["OFFSET"]))
                self.sym_NODE_IB_SHUNT.setValue(float(information["IB"]["SHUNT"]))

                # self.sym_NODE_IDC_OPAMP.setValue("External op-amp")
                self.sym_NODE_IDC_GAIN.setValue(float(information["IDC"]["GAIN"]))
                self.sym_NODE_IDC_OFFSET.setValue(float(information["IDC"]["OFFSET"]))
                self.sym_NODE_IDC_SHUNT.setValue(float(information["IDC"]["SHUNT"]))

                self.sym_NODE_VDC_TOP.setValue(float(information["VDC"]["TOP"]))
                self.sym_NODE_VDC_BOTTOM.setValue(float(information["VDC"]["BOTTOM"]))

                ratio = self.information["VDC"]["BOTTOM"]/(self.information["VDC"]["BOTTOM"] + self.information["VDC"]["TOP"])
                self.sym_VOLTAGE_RATIO.setValue(float(ratio))
               
    
    def createSymbols(self):
        # Root Node 
        self.sym_NODE = self.component.createMenuSymbol(None, None )
        self.sym_NODE.setLabel("Analog Front End")

        # Current measurement
        self.sym_NODE_IA = self.component.createMenuSymbol("MCPMSMFOC_ANALOG_FRONT_END_IA", self.sym_NODE)
        self.sym_NODE_IA.setLabel("Phase A current")
        
        available = [ "External op-amp", "Internal op-amp"]
        self.sym_NODE_IA_OPAMP = self.component.createComboSymbol("MCPMSMFOC_ANALOG_FRONT_END_IA_OPAMP", self.sym_NODE_IA, available)
        self.sym_NODE_IA_OPAMP.setLabel("Op-amp")
       
        self.sym_NODE_IA_GAIN = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN", self.sym_NODE_IA)
        self.sym_NODE_IA_GAIN.setLabel("Gain")

        try:
            self.sym_NODE_IA_GAIN.setDefaultValue(float(self.afe_Information["IA"]["GAIN"]))
        except:
            pass


        self.sym_NODE_IA_OFFSET = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IA_OFFSET", self.sym_NODE_IA)
        self.sym_NODE_IA_OFFSET.setLabel("Offset")
        try:
            self.sym_NODE_IA_OFFSET.setDefaultValue(float(self.afe_Information["IA"]["OFFSET"]))
        except:
            pass


        self.sym_NODE_IA_SHUNT = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT", self.sym_NODE_IA)
        self.sym_NODE_IA_SHUNT.setLabel("Shunt resistance (ohm)")

        try:
            self.sym_NODE_IA_SHUNT.setDefaultValue(float(self.afe_Information["IA"]["SHUNT"])) 
        except:
            pass


        # Current measurement
        self.sym_NODE_IB = self.component.createMenuSymbol("MCPMSMFOC_ANALOG_FRONT_END_IB", self.sym_NODE)
        self.sym_NODE_IB.setLabel("Phase B current")
        
        available = [ "External op-amp", "Internal op-amp"]
        self.sym_NODE_IB_OPAMP = self.component.createComboSymbol("MCPMSMFOC_ANALOG_FRONT_END_IB_OPAMP", self.sym_NODE_IB, available)
        self.sym_NODE_IB_OPAMP.setLabel("Op-amp")

        self.sym_NODE_IB_GAIN = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IB_GAIN", self.sym_NODE_IB)
        self.sym_NODE_IB_GAIN.setLabel("Gain")

        try:
            self.sym_NODE_IB_GAIN.setDefaultValue(float(self.afe_Information["IB"]["GAIN"]))
        except:
            pass

        self.sym_NODE_IB_OFFSET = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IB_OFFSET", self.sym_NODE_IB)
        self.sym_NODE_IB_OFFSET.setLabel("Offset")

        try:
            self.sym_NODE_IB_OFFSET.setDefaultValue(float(self.afe_Information["IB"]["OFFSET"]))
        except:
            pass

        self.sym_NODE_IB_SHUNT = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IB_SHUNT", self.sym_NODE_IB)
        self.sym_NODE_IB_SHUNT.setLabel("Shunt resistance (ohm)")
        try:
            self.sym_NODE_IB_SHUNT.setDefaultValue(float(self.afe_Information["IB"]["SHUNT"])) 
        except:
            pass


         # Current measurement
        self.sym_NODE_IDC = self.component.createMenuSymbol("MCPMSMFOC_ANALOG_FRONT_END_IDC", self.sym_NODE)
        self.sym_NODE_IDC.setLabel("DC bus current")
        
        available = [ "External op-amp", "Internal op-amp"]
        self.sym_NODE_IDC_OPAMP = self.component.createComboSymbol("MCPMSMFOC_ANALOG_FRONT_END_IDC_OPAMP", self.sym_NODE_IDC, available)
        self.sym_NODE_IDC_OPAMP.setLabel("Op-amp")

        self.sym_NODE_IDC_GAIN = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IDC_GAIN", self.sym_NODE_IDC)
        self.sym_NODE_IDC_GAIN.setLabel("Gain")

        try:
            self.sym_NODE_IDC_GAIN.setDefaultValue(float(self.afe_Information["IDC"]["GAIN"]))
        except:
            pass

        self.sym_NODE_IDC_OFFSET = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IDC_OFFSET", self.sym_NODE_IDC)
        self.sym_NODE_IDC_OFFSET.setLabel("Offset")

        try:
            self.sym_NODE_IDC_OFFSET.setDefaultValue(float(self.afe_Information["IDC"]["OFFSET"]))
        except:
            pass

        self.sym_NODE_IDC_SHUNT = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_IDC_SHUNT", self.sym_NODE_IDC)
        self.sym_NODE_IDC_SHUNT.setLabel("Shunt resistance (ohm)")

        try:
            self.sym_NODE_IDC_SHUNT.setDefaultValue(float(self.afe_Information["IDC"]["SHUNT"]))
        except:
            pass

        # Voltage measurement
        self.sym_NODE_VDC = self.component.createMenuSymbol("MCPMSMFOC_ANALOG_FRONT_END_VDC", self.sym_NODE)
        self.sym_NODE_VDC.setLabel("DC bus voltage")
        
        self.sym_NODE_VDC_TOP = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_VDC_TOP_RES", self.sym_NODE_VDC)
        self.sym_NODE_VDC_TOP.setLabel("Top resistance")
        try:
            self.sym_NODE_VDC_TOP.setDefaultValue(float(self.afe_Information["VDC"]["TOP"]))
        except:
            pass

        self.sym_NODE_VDC_BOTTOM = self.component.createFloatSymbol("MCPMSMFOC_ANALOG_FRONT_END_VDC_BOTTOM_RES", self.sym_NODE_VDC)
        self.sym_NODE_VDC_BOTTOM.setLabel("Bottom resistance")
        try:
            self.sym_NODE_VDC_BOTTOM.setDefaultValue(float(self.afe_Information["VDC"]["BOTTOM"]))
        except:
            pass

        self.sym_VOLTAGE_RATIO = self.component.createFloatSymbol("MCPMSMFOC_DC_BUS_RATIO", self.sym_NODE_VDC)
        self.sym_VOLTAGE_RATIO.setLabel("DC Bus Voltage Divider Ratio")
        try:
            ratio = float(self.afe_Information["VDC"]["BOTTOM"])/(float(self.afe_Information["VDC"]["BOTTOM"])  + float(self.afe_Information["VDC"]["TOP"]))
            self.sym_VOLTAGE_RATIO.setDefaultValue(ratio)
        except:
            pass

        self.sym_VOLTAGE_RATIO.setDependencies(self.detVoltageDividerRatio, ["MCPMSMFOC_ANALOG_FRONT_END_VDC_TOP_RES", "MCPMSMFOC_ANALOG_FRONT_END_VDC_BOTTOM_RES"])

       
    def detVoltageDividerRatio(self, symbol, event):
        component = symbol.getComponent()
        Rb = component.getSymbolByID("MCPMSMFOC_ANALOG_FRONT_END_VDC_BOTTOM_RES").getValue()
        Rt = component.getSymbolByID("MCPMSMFOC_ANALOG_FRONT_END_VDC_TOP_RES").getValue()
        try:
            symbol.setValue(Rb/(Rb + Rt))
        except:
            symbol.setValue(0.0) 


    def __call__(self):
        self.setSymbolDefaults()
        self.createSymbols()


