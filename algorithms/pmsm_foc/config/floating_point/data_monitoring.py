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
class mcFocI_DataMonitoringClass:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

    def createSymbols(self):
        # Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Data Monitoring")

        # Data communication Enable
        self.sym_PROTOCOL = self.component.createBooleanSymbol("MCPMSMFOC_DATA_MONITOR_ENABLE", self.sym_NODE)
        self.sym_PROTOCOL.setLabel("Enable data monitoring")

        #
        # protocols = ['X2C Scope', 'XCP' ]
        protocols = ['X2C Scope']
        self.sym_PROTOCOL = self.component.createComboSymbol("MCPMSMFOC_DATA_MONITOR_PROTOCOL", self.sym_NODE, protocols)
        self.sym_PROTOCOL.setLabel("Protocol")
        self.sym_PROTOCOL.setVisible(False)
        self.sym_PROTOCOL.setDependencies( self.showThisSymbol, ['MCPMSMFOC_DATA_MONITOR_ENABLE'])

        self.sym_X2CSCOPE = self.component.createStringSymbol("MCPMSMFOC_X2CScope", None)
        self.sym_X2CSCOPE.setVisible(False)

    def showThisSymbol(self, symbol, event):
        if True == (event["symbol"]).getValue():
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def handleMessage(self, ID, information):
        if( ID == "BSP_DATA_MONITORING"):
           pass

    def onAttachmentConnected(self, source, target):
        if (source["id"] == "pmsmfoc_X2CSCOPE"):
            self.sym_X2CSCOPE.setValue( target["component"].getID())

            # Get the X2C Communication peripheral
            # commPeripheral = Database.getSymbolValue("X2CScope", "X2C_COMM_INSTANCE")
            #
            # # Activate and connect peripheral
            # autoConnectTable = [commPeripheral]
            # res = Database.activateComponents(autoConnectTable)
            #
            # autoComponentIDTable = [[ target["component"].getID(), "x2cScopeUartDependency", commPeripheral.lower(), commPeripheral.upper() + "_UART"]]
            # res = Database.connectDependencies(autoComponentIDTable)


    def onAttachmentDisconnected(self, source, target):
        if (source["id"] == "pmsmfoc_X2CSCOPE"):
            self.sym_X2CSCOPE.setValue("None")

    def __call__(self):
        self.createSymbols()


