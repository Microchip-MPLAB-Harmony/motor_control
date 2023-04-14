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

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcVolI_VoltageMeasurementAndDiagnosis:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

    def createSymbols(self):
        #Root node 
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Voltage measurement & diagnosis")

        # Voltage Scaling 
        self.sym_SCALING = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_SCALING.setLabel("Voltage scaling")
        
        supported_Formats = ["Real"]
        self.sym_SCALING_FORMAT = self.component.createComboSymbol("MCPMSMFOC_VOLTAGE_SCALING_FORMAT", self.sym_SCALING, supported_Formats )
        self.sym_SCALING_FORMAT.setLabel("Format")

        self.sym_SCALING_FACTOR = self.component.createFloatSymbol("MCPMSMFOC_VOLTAGE_SCALING_FACTORT", self.sym_SCALING )
        self.sym_SCALING_FACTOR.setLabel("Scaling factor")
        self.sym_SCALING_FACTOR.setDefaultValue(0.0625)
        self.sym_SCALING_FACTOR.setDependencies(self.scalingFactorCalculate, ["MCPMSMFOC_ANALOG_FRONT_END_VDC_TOP_RES", "MCPMSMFOC_ANALOG_FRONT_END_VDC_BOTTOM_RES"])
        self.sym_SCALING_FACTOR.setReadOnly(True)

        self.sym_ADC_TO_VOLTS = self.component.createFloatSymbol("MCPMSMFOC_ADC_TO_VOLTS_FACTORT", self.sym_SCALING )
        self.sym_ADC_TO_VOLTS.setLabel("Conversion factor")
        self.sym_ADC_TO_VOLTS.setDefaultValue(0.0625)
        self.sym_ADC_TO_VOLTS.setDependencies(self.adcToVoltsCalculate, ["MCPMSMFOC_VOLTAGE_SCALING_FACTORT"])
        self.sym_ADC_TO_VOLTS.setReadOnly(True)

        # Diagnosis
        self.sym_PROCESSING = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_PROCESSING.setLabel("Processing")

        self.sym_VOLTAGE_FILTER = self.component.createFloatSymbol("MCPMSMFOC_VOLTAGE_PROCESSING", self.sym_PROCESSING)
        self.sym_VOLTAGE_FILTER.setLabel(" Filter Parameter")
        self.sym_VOLTAGE_FILTER.setDefaultValue(0.5)

        # Diagnosis
        self.sym_DIAGNOSIS = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_DIAGNOSIS.setLabel("Diagnosis")

        self.sym_OVER_VOLTAGE = self.component.createBooleanSymbol("MCPMSMFOC_OVER_VOLTAGE", self.sym_DIAGNOSIS)
        self.sym_OVER_VOLTAGE.setLabel("Enable over voltage diagnosis")
        self.sym_OVER_VOLTAGE.setReadOnly(True)

        self.sym_OVER_VOLTAGE_LIMIT = self.component.createFloatSymbol("MCPMSMFOC_OVER_VOLTAGE_LIMIT", self.sym_OVER_VOLTAGE)
        self.sym_OVER_VOLTAGE_LIMIT.setLabel("Over voltage limit (V)")
        self.sym_OVER_VOLTAGE_LIMIT.setVisible(False)
        self.sym_OVER_VOLTAGE_LIMIT.setDependencies(self.showThisSymbol, ["MCPMSMFOC_OVER_VOLTAGE"])

        self.sym_OVER_VOLTAGE_DEBOUNCE = self.component.createFloatSymbol("MCPMSMFOC_OVER_VOLTAGE_DEBOUNCE", self.sym_OVER_VOLTAGE)
        self.sym_OVER_VOLTAGE_DEBOUNCE.setLabel("Debounce time (ms)")
        self.sym_OVER_VOLTAGE_DEBOUNCE.setVisible(False)
        self.sym_OVER_VOLTAGE_DEBOUNCE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_OVER_VOLTAGE"])

        fault_Types = ["Recoverable", "Non-recoverable"]
        self.sym_OVER_VOLTAGE_FAULT_TYPE = self.component.createComboSymbol("MCPMSMFOC_OVER_VOLTAGE_FAULT_TYPE", self.sym_OVER_VOLTAGE, fault_Types)
        self.sym_OVER_VOLTAGE_FAULT_TYPE.setLabel("Fault type")
        self.sym_OVER_VOLTAGE_FAULT_TYPE.setVisible(False)
        self.sym_OVER_VOLTAGE_FAULT_TYPE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_OVER_VOLTAGE"])

        self.sym_UNDER_VOLTAGE = self.component.createBooleanSymbol("MCPMSMFOC_UNDER_VOLTAGE", self.sym_DIAGNOSIS)
        self.sym_UNDER_VOLTAGE.setLabel("Enable under voltage diagnosis")
        self.sym_UNDER_VOLTAGE.setReadOnly(True)

        self.sym_UNDER_VOLTAGE_LIMIT = self.component.createFloatSymbol("MCPMSMFOC_UNDER_VOLTAGE_LIMIT", self.sym_UNDER_VOLTAGE)
        self.sym_UNDER_VOLTAGE_LIMIT.setLabel("Under voltage limit (V)")
        self.sym_UNDER_VOLTAGE_LIMIT.setVisible(False)
        self.sym_UNDER_VOLTAGE_LIMIT.setDependencies(self.showThisSymbol, ["MCPMSMFOC_UNDER_VOLTAGE"])

        self.sym_UNDER_VOLTAGE_DEBOUNCE = self.component.createFloatSymbol("MCPMSMFOC_UNDER_VOLTAGE_DEBOUNCE", self.sym_UNDER_VOLTAGE)
        self.sym_UNDER_VOLTAGE_DEBOUNCE.setLabel("Debounce time (ms)")
        self.sym_UNDER_VOLTAGE_DEBOUNCE.setVisible(False)
        self.sym_UNDER_VOLTAGE_DEBOUNCE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_UNDER_VOLTAGE"])

        fault_Types = ["Recoverable", "Non-recoverable"]
        self.sym_UNDER_VOLTAGE_FAULT_TYPE = self.component.createComboSymbol("MCPMSMFOC_UNDER_VOLTAGE_FAULT_TYPE", self.sym_UNDER_VOLTAGE, fault_Types)
        self.sym_UNDER_VOLTAGE_FAULT_TYPE.setLabel("Fault type")
        self.sym_UNDER_VOLTAGE_FAULT_TYPE.setVisible(False)
        self.sym_UNDER_VOLTAGE_FAULT_TYPE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_UNDER_VOLTAGE"])
        
    def showThisSymbol(self, symbol, event):
        if True == event["symbol"].getValue():
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def scalingFactorCalculate(self, symbol, event):
        component = symbol.getComponent()
        Rb = component.getSymbolByID("MCPMSMFOC_ANALOG_FRONT_END_VDC_BOTTOM_RES").getValue()
        Rt = component.getSymbolByID("MCPMSMFOC_ANALOG_FRONT_END_VDC_TOP_RES").getValue()
        try:
            symbol.setValue(Rb/(Rb + Rt))
        except:
            symbol.setValue(0.0) 

    def adcToVoltsCalculate(self, symbol, event):
        symbol.setValue(3.3 /( event["value"] * 4095 ))

    def __call__(self):
        self.createSymbols()


