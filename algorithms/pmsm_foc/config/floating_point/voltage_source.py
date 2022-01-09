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


#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcSrcI_VoltageSourceClass:
    def __init__( self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

    def setValues(self):
        self.information = Database.sendMessage("bsp", "MCPMSMFOC_VOLTAGE_SOURCE", {})
    
    def createSymbols(self):
        # Root Node 
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Voltage source")

        # 
        self.sym_VOLTAGE = self.component.createFloatSymbol("MCPMSMFOC_VOLTAGE_MAGNITUDE", self.sym_NODE )
        self.sym_VOLTAGE.setLabel("Voltage magnitude")
        try:
            self.sym_VOLTAGE.setDefaultValue(self.information["VDC"])
        except:
            self.sym_VOLTAGE.setDefaultValue(24.0)


        # Capacitor value


    def handleMessage(self, ID, information):
        if( ID == "BSP_VOLTAGE_SOURCE"):
            if None != information:
                self.sym_VOLTAGE.setValue(float(information["VDC"]))
                
    def __call__(self):
        self.setValues()
        self.createSymbols()
    
        

