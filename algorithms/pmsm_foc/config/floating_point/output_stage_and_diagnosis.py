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
class mcOstI_OutputStageAndDiagnosis:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

    def createSymbols(self):
        #Root node 
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Output stage & diagnosis")

        # Control to PWM ratio
        # supported_Ratios = ["1:1", "1:2", "1:4"]
        supported_Ratios = ["1:1"]
        self.sym_CONTROL_TO_PWM = self.component.createComboSymbol("MCPMSMFOC_CONTROL_TO_PWM_RATIO", self.sym_NODE, supported_Ratios)
        self.sym_CONTROL_TO_PWM.setLabel("Control to PWM ratio")

        # self.sym_MAXIMUM_RMS_VOLTAGE = self.component.createFloatSymbol("MCPMSMFOC_MAXIMUM_RMS_VOLTAGE", self.sym_NODE)
        # self.sym_MAXIMUM_RMS_VOLTAGE.setLabel("Maximum RMS Voltage")
        # self.sym_MAXIMUM_RMS_VOLTAGE.setDefaultValue(230)
    
    def __call__(self):
        self.createSymbols()
      