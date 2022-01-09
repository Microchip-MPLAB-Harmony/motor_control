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
class mcRpoI_PositionCalculationAndDiagnosis:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

    def createSymbols(self):
        # Root node 
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Position Calculation & Diagnosis")

        # Algorithm selection
        processor = Variables.get("__PROCESSOR") 

        self.sym_ALGORITHM = self.component.createKeyValueSetSymbol("MCPMSMFOC_POSITION_CALC_ALGORITHM", self.sym_NODE)
        self.sym_ALGORITHM.setLabel("Select Position Feedback")
        if (("SAMC21" in processor) or all(x in processor for x in ["PIC32CM", "MC"])):
            self.sym_ALGORITHM.addKey("SENSORLESS_ROLO", "0", "Reduced Order Luenberger Observer")    
        else:
            self.sym_ALGORITHM.addKey("SENSORLESS_PLL", "0", "Equation based PLL")
            self.sym_ALGORITHM.addKey("SENSORED_ENCODER", "1", "Quadrature Encoder")
            self.sym_ALGORITHM.addKey("SENSORLESS_ROLO", "1", "Reduced Order Luenberger Observer (Beta)")
            self.sym_ALGORITHM.addKey("SENSORLESS_SMO", "2", "Sliding Mode Observer (Beta)")
        self.sym_ALGORITHM.setOutputMode("Key")
        self.sym_ALGORITHM.setDisplayMode("Description")

        self.sym_ED_FILTER = self.component.createMenuSymbol("MCPMSMFOC_ED_FILTER", self.sym_ALGORITHM)
        self.sym_ED_FILTER.setLabel("Ed Filter")
        self.sym_ED_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
        

        self.sym_ED_FILTER_PARAMETER = self.component.createFloatSymbol("MCPMSMFOC_ED_FILTER_PARAMETER", self.sym_ED_FILTER )
        self.sym_ED_FILTER_PARAMETER.setLabel("Filter Parameter")
        self.sym_ED_FILTER_PARAMETER.setDefaultValue(0.0183)

        self.sym_EQ_FILTER = self.component.createMenuSymbol("MCPMSMFOC_EQ_FILTER", self.sym_ALGORITHM)
        self.sym_EQ_FILTER.setLabel("Eq Filter")
        self.sym_EQ_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
       
        self.sym_EQ_FILTER_PARAMETER = self.component.createFloatSymbol("MCPMSMFOC_EQ_FILTER_PARAMETER", self.sym_EQ_FILTER )
        self.sym_EQ_FILTER_PARAMETER.setLabel("Filter Parameter")
        self.sym_EQ_FILTER_PARAMETER.setDefaultValue(0.0183)

        self.sym_SPEED_FILTER = self.component.createMenuSymbol("MCPMSMFOC_SPEED_FILTER", self.sym_ALGORITHM)
        self.sym_SPEED_FILTER.setLabel("Speed Filter")
        self.sym_SPEED_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
       
        self.sym_SPEED_FILTER_PARAMETER = self.component.createFloatSymbol("MCPMSMFOC_SPEED_FILTER_PARAMETER", self.sym_SPEED_FILTER )
        self.sym_SPEED_FILTER_PARAMETER.setLabel("Filter Parameter")
        self.sym_SPEED_FILTER_PARAMETER.setDefaultValue(0.0053)

        self.sym_NOISE_FILTER = self.component.createMenuSymbol("MCPMSMFOC_ENCODER_DNF", self.sym_ALGORITHM)
        self.sym_NOISE_FILTER.setLabel("Digital Noise Filter")
        self.sym_NOISE_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
       
        self.sym_NOISE_FILTER_COUNT = self.component.createFloatSymbol("MCPMSMFOC_ENCODER_DNF_COUNT", self.sym_NOISE_FILTER )
        self.sym_NOISE_FILTER_COUNT.setLabel("Filter Count")
        self.sym_NOISE_FILTER_COUNT.setDefaultValue(4)

        self.sym_QDEC = self.component.createMenuSymbol("MCPMSMFOC_ENCODER_QDEC", self.sym_ALGORITHM)
        self.sym_QDEC.setLabel("Decoder")
        self.sym_QDEC.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
       
        self.sym_QDEC_PULSE_PER_EREV = self.component.createIntegerSymbol("MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", self.sym_QDEC )
        self.sym_QDEC_PULSE_PER_EREV.setLabel("Pulse Per electrical rotation")
        self.sym_QDEC_PULSE_PER_EREV.setDefaultValue(200)


    def showAlgorithmDependentSymbols(self, symbol, event):
        if "SENSORLESS_PLL" ==  event["symbol"].getSelectedKey():
            self.sym_ED_FILTER.setVisible(True)
            self.sym_EQ_FILTER.setVisible(True)
            self.sym_SPEED_FILTER.setVisible(True)
            self.sym_NOISE_FILTER.setVisible(False)
            self.sym_QDEC.setVisible(False)
        
        elif "SENSORED_ENCODER" ==  event["symbol"].getSelectedKey():
            self.sym_ED_FILTER.setVisible(False)
            self.sym_EQ_FILTER.setVisible(False)
            self.sym_SPEED_FILTER.setVisible(False)
            self.sym_NOISE_FILTER.setVisible(True)
            self.sym_QDEC.setVisible(True)
        
