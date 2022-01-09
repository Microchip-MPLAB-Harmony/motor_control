
"""*****************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

"""*****************************************************************************
* File Name: general_functions.py
*
* Description:
* General functions 
*
*****************************************************************************"""
class mcFun_AdvancedComboSymbol:
    def __init__(self, description, Id, component ):
        self.description = description
        self.component = component
        self.Id = Id

    def numericFilter( self, input_String ):
        numeric_filter = filter(str.isdigit, str(input_String))
        return "".join(numeric_filter)

    def createComboSymbol( self, dependency, root, data ):
        self.data = data
        self.dependency = dependency
        self.symbol = {}
        self.depend = {}

        name = self.dependency.getID() + "_" + self.Id + "_FINAL"
        self.final = self.component.createStringSymbol(name, root )
        self.final.setLabel("Final value")
        self.final.setVisible(False)

        for key in self.data.keys():
            name = self.dependency.getID() + "_" + self.Id + "_" + str( key )  
            self.symbol[key] = self.component.createComboSymbol(name, root, self.data[key] )
            self.symbol[key].setLabel(self.description)
            self.symbol[key].setDependencies( self.showComboSymbol, [self.dependency.getID()])
            if( self.dependency.getValue() == str( key ) ):
                self.symbol[key].setVisible(True)
            else:
                self.symbol[key].setVisible(False)

            self.depend[key] = self.component.createStringSymbol( None, None )
            self.depend[key].setLabel("Callback function")
            self.depend[key].setVisible(False)
            self.depend[key].setDependencies( self.callbackFunction, [name])

        
    def setDefaultValue( self, value ):
        instance = self.dependency.getValue()

        for key in self.data.keys():
            if( key == instance ):
                self.symbol[key].setDefaultValue(value)
                
        
        self.final.setDefaultValue(self.numericFilter(value))

    def setReadOnly(self, value ):
        pass

    def setValue( self, value ):
        instance = self.dependency.getValue()
        for key in self.data.keys():
            if( key == instance ):
                self.symbol[key].setValue(value )
        
        self.final.setValue(self.numericFilter(value))

    def getFinalSymbol(self):
        return self.final
    
    def getValue_( self ):
        return self.final.getValue()

    def getValue( self ):
        instance = self.dependency.getValue()
        for key in self.data.keys():
            if( key == instance ):
                return self.symbol[key].getValue( )

    def getSymbolID(self):
        ID = self.dependency.getID() + "_" + self.Id + "_FINAL"
        return ID
    
    def showComboSymbol( self, symbol, event ):
        symbol_Id = symbol.getID()  
        if( event["symbol"].getValue() in symbol_Id ):
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def callbackFunction(self, symbol, event):
        self.final.setValue(self.numericFilter(self.getValue()))
