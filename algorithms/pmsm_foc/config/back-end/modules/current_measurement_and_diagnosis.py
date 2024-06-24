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
class mcCurI_CurrentMeasurementAndDiagnosis:
    def __init__(self, component):
        self.component = component

    def createSymbols(self):
        #Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Current measurement & diagnosis")

        supported_Algorithms = ['Dual-shunt', 'Single-shunt']
        self.sym_ALGORITHM = self.component.createComboSymbol("MCPMSMFOC_CURRENT_MEAS_ALGORITHM", self.sym_NODE, supported_Algorithms)
        self.sym_ALGORITHM.setLabel("Select algorithm")
        self.sym_ALGORITHM.setVisible(False)
        self.sym_ALGORITHM.setReadOnly(True)

        # Current Offset
        self.sym_OFFSET = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_OFFSET.setLabel("Offset correction")

        supported_Algorithms = ["Static", "Dynamic"]
        self.sym_OFFSET_ALGORITHM = self.component.createComboSymbol("MCPMSMFOC_OFFSET_CORRECTION_ALGORITHM", self.sym_OFFSET, supported_Algorithms)
        self.sym_OFFSET_ALGORITHM.setLabel("Select algorithm")
        self.sym_OFFSET_ALGORITHM.setReadOnly(True)

        self.sym_OFFSET_SAMPLES = self.component.createIntegerSymbol("MCPMSMFOC_OFFSET_CORRECTION_SAMPLE", self.sym_OFFSET)
        self.sym_OFFSET_SAMPLES.setLabel("Number of samples")
        self.sym_OFFSET_SAMPLES.setDefaultValue(1024)
        self.sym_OFFSET_SAMPLES.setReadOnly(True)

        # Current Scaling
        self.sym_SCALING = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_SCALING.setLabel("Current scaling")

        supported_Formats = ["Real"]
        self.sym_SCALING_FORMAT = self.component.createComboSymbol("MCPMSMFOC_CURRENT_SCALING_FORMAT", self.sym_SCALING, supported_Formats )
        self.sym_SCALING_FORMAT.setLabel("Format")

        self.sym_SCALING_FACTOR = self.component.createFloatSymbol("MCPMSMFOC_CURRENT_SCALING_FACTORT", self.sym_SCALING )
        self.sym_SCALING_FACTOR.setLabel("Scaling factor")
        self.sym_SCALING_FACTOR.setDefaultValue(0.0625)
        self.sym_SCALING_FACTOR.setDependencies(self.scalingFactorCalculate, ["MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN", "MCPMSMFOC_ANALOG_FRONT_END_IA_OFFSET", "MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT"])
        self.sym_SCALING_FACTOR.setReadOnly(True)

        # Diagnosis
        self.sym_DIAGNOSIS = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_DIAGNOSIS.setLabel("Diagnosis")

        self.sym_CURRENT_OOR = self.component.createBooleanSymbol("MCPMSMFOC_CURRENT_OOR", self.sym_DIAGNOSIS)
        self.sym_CURRENT_OOR.setLabel("Enable current range diagnosis")
        self.sym_CURRENT_OOR.setReadOnly(True)


        self.sym_CURRENT_OOR_MAXIMUM = self.component.createFloatSymbol("MCPMSMFOC_CURRENT_OOR_MAXIMUM", self.sym_CURRENT_OOR)
        self.sym_CURRENT_OOR_MAXIMUM.setLabel("Maximum current")
        self.sym_CURRENT_OOR_MAXIMUM.setVisible(False)
        self.sym_CURRENT_OOR_MAXIMUM.setDependencies(self.showThisSymbol, ["MCPMSMFOC_CURRENT_OOR"])

        self.sym_CURRENT_OOR_DEBOUNCE = self.component.createFloatSymbol("MCPMSMFOC_CURRENT_OOR_DEBOUNCE", self.sym_CURRENT_OOR)
        self.sym_CURRENT_OOR_DEBOUNCE.setLabel("Debounce time (ms)")
        self.sym_CURRENT_OOR_DEBOUNCE.setVisible(False)
        self.sym_CURRENT_OOR_DEBOUNCE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_CURRENT_OOR"])

        fault_Types = ["Recoverable", "Non-recoverable"]
        self.sym_CURRENT_OOR_FAULT_TYPE = self.component.createComboSymbol("MCPMSMFOC_CURRENT_OOR_FAULT_TYPE", self.sym_CURRENT_OOR, fault_Types)
        self.sym_CURRENT_OOR_FAULT_TYPE.setLabel("Fault type")
        self.sym_CURRENT_OOR_FAULT_TYPE.setVisible(False)
        self.sym_CURRENT_OOR_FAULT_TYPE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_CURRENT_OOR"])

        self.sym_OFFSET_OOR = self.component.createBooleanSymbol("MCPMSMFOC_OFFSET_OOR", self.sym_DIAGNOSIS)
        self.sym_OFFSET_OOR.setLabel("Enable Offset range diagnosis")
        self.sym_OFFSET_OOR.setReadOnly(True)

        self.sym_OFFSET_OOR_MAXIMUM = self.component.createFloatSymbol("MCPMSMFOC_OFFSET_OOR_MAXIMUM", self.sym_OFFSET_OOR)
        self.sym_OFFSET_OOR_MAXIMUM.setLabel("Maximum Offset")
        self.sym_OFFSET_OOR_MAXIMUM.setVisible(False)
        self.sym_OFFSET_OOR_MAXIMUM.setDependencies(self.showThisSymbol, ["MCPMSMFOC_OFFSET_OOR"])

        self.sym_OFFSET_OOR_MINIMUM = self.component.createFloatSymbol("MCPMSMFOC_OFFSET_OOR_MINIMUM", self.sym_OFFSET_OOR)
        self.sym_OFFSET_OOR_MINIMUM.setLabel("Minimum Offset")
        self.sym_OFFSET_OOR_MINIMUM.setVisible(False)
        self.sym_OFFSET_OOR_MINIMUM.setDependencies(self.showThisSymbol, ["MCPMSMFOC_OFFSET_OOR"])

        self.sym_OFFSET_OOR_DEBOUNCE = self.component.createFloatSymbol("MCPMSMFOC_OFFSET_OOR_DEBOUNCE", self.sym_OFFSET_OOR)
        self.sym_OFFSET_OOR_DEBOUNCE.setLabel("Debounce time (ms)")
        self.sym_OFFSET_OOR_DEBOUNCE.setVisible(False)
        self.sym_OFFSET_OOR_DEBOUNCE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_OFFSET_OOR"])

        fault_Types = ["Recoverable", "Non-recoverable"]
        self.sym_OFFSET_OOR_FAULT_TYPE = self.component.createComboSymbol("MCPMSMFOC_OFFSET_OOR_FAULT_TYPE", self.sym_OFFSET_OOR, fault_Types)
        self.sym_OFFSET_OOR_FAULT_TYPE.setLabel("Fault type")
        self.sym_OFFSET_OOR_FAULT_TYPE.setVisible(False)
        self.sym_OFFSET_OOR_FAULT_TYPE.setDependencies(self.showThisSymbol, ["MCPMSMFOC_OFFSET_OOR"])

    def scalingFactorCalculate(self, symbol, event):
        component = symbol.getComponent()
        Gain = component.getSymbolByID("MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN").getValue()
        Offset = component.getSymbolByID("MCPMSMFOC_ANALOG_FRONT_END_IA_OFFSET").getValue()
        Shunt = component.getSymbolByID("MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT").getValue()
        try:
            symbol.setValue((3.30 - Offset)/ (Gain * 2048 *Shunt ))
        except:
            symbol.setValue(0.0)

    def showThisSymbol(self, symbol, event):
        if True == event["symbol"].getValue():
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def __call__(self):
        self.createSymbols()


