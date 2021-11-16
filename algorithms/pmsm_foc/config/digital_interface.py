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
import inspect
import xml.etree.ElementTree as ET
import os.path

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcFocI_DigitalInterfaceClass:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component
        
        # Get list of function_Maps 
        self.function_Map = list()
        if "SAME54" in MCU:
            pins =  ATDF.getNode("/avr-tools-device-file/pinouts/pinout@[name=\"SAMD51P\"]").getChildren()
            for pin in pins:
                pad = pin.getAttribute("pad")
                if pad.startswith("P"):
                    self.function_Map.append(pad)  

        elif "SAME70" in MCU:
            pins =  ATDF.getNode("/avr-tools-device-file/pinouts/pinout@[name=\"LQFP144\"]").getChildren()

            for pin in pins:
                pad = pin.getAttribute("pad")
                if pad.startswith("P"):
                    self.function_Map.append(pad)  
       
        elif "PIC32MK" in MCU:
            # currentPath = os.path.dirname(os.path.abspath(inspect.stack()[0][1]))
            currentPath = "D:/Release/csp/peripheral/function_Map_02467"
            deviceXmlPath = os.path.join(currentPath, "plugin/pin_xml/components/" + Variables.get("__PROCESSOR") + ".xml")
            deviceXmlTree = ET.parse(deviceXmlPath)
            deviceXmlRoot = deviceXmlTree.getroot()
            pinoutXmlName = deviceXmlRoot.get("pins")
            pinoutXmlPath = os.path.join(currentPath, "plugin/pin_xml/pins/" + pinoutXmlName + ".xml")
            pinoutXmlPath = os.path.normpath(pinoutXmlPath)

            pinFileContent = ET.fromstring((open(pinoutXmlPath, "r")).read())
            for item in pinFileContent.findall("pins/pin"):
                if item.attrib["name"].startswith("R"):
                    self.function_Map.append(item.attrib["name"]) 

        self.function_Map.sort()   

    def setSymbolValues(self):
        information = Database.sendMessage("bsp", "MCPMSMFOC_READ_DII_INFORMATION", {})
        print("INFO:", information)
        if None != information:
            index = 0
            for button in information["BUTTONS"].keys():
                self.sym_BUTTON_INDEX[index].setVisible(True)
                self.sym_BUTTON_PIN[index].setValue(information["BUTTONS"][button]["PAD"])
                index += 1
            
            index = 0
            for led in information["LEDS"].keys():
                self.sym_LED_INDEX[index].setVisible(True)
                self.sym_LED_PIN[index].setValue(information["LEDS"][led]["PAD"])
                index += 1

    def createSymbols(self):   
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Digital Interface")
        
        max_NUMBER_OF_BUTTONS = 10
        self.sym_BUTTON_INDEX = dict()
        self.sym_BUTTON_NAME = dict()
        self.sym_BUTTON_PIN = dict()
        self.sym_BUTTON_FUNCTION = dict()

        self.sym_BUTTON_NODE = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_BUTTON_NODE.setLabel("Buttons")
        for index in range(max_NUMBER_OF_BUTTONS):
            self.sym_BUTTON_INDEX[index] = self.component.createMenuSymbol(None, self.sym_BUTTON_NODE)
            self.sym_BUTTON_INDEX[index].setLabel("Button"+ " " + str(index))
            self.sym_BUTTON_INDEX[index].setVisible(False)
                
            self.sym_BUTTON_NAME[index]  = self.component.createStringSymbol("MCPMSMFOC_BUTTON_"+ str(index)+"_NAME", self.sym_BUTTON_INDEX[index])
            self.sym_BUTTON_NAME[index].setLabel("Name")
            self.sym_BUTTON_NAME[index].setDefaultValue("Button"+ " " + str(index))

            self.sym_BUTTON_PIN[index]  = self.component.createComboSymbol("MCPMSMFOC_BUTTON_"+ str(index)+"_NUMBER", self.sym_BUTTON_INDEX[index], self.function_Map)
            self.sym_BUTTON_PIN[index].setLabel("Pin Number")

            functions = ["Start/Stop", "Start", "Stop", "Direction Toggle", "Custom"]
            self.sym_BUTTON_FUNCTION[index]  = self.component.createComboSymbol("MCPMSMFOC_BUTTON_"+ str(index)+ "_FUNCTION", self.sym_BUTTON_INDEX[index], functions)
            self.sym_BUTTON_FUNCTION[index].setLabel("Function")

        max_NUMBER_OF_LEDS = 10
        self.sym_LED_INDEX = dict()
        self.sym_LED_NAME = dict()
        self.sym_LED_PIN = dict()
        self.sym_LED_FUNCTION = dict()

        self.sym_LED_NODE = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_LED_NODE.setLabel("Leds")

        for index in range(max_NUMBER_OF_LEDS):             
            self.sym_LED_INDEX[index] = self.component.createMenuSymbol(None, self.sym_LED_NODE)
            self.sym_LED_INDEX[index].setLabel("Led"+ " " + str(index))
            self.sym_LED_INDEX[index].setVisible(False)
            
            self.sym_LED_NAME[index] = self.component.createStringSymbol("MCPMSMFOC_LED_"+ str(index)+"_NAME", self.sym_LED_INDEX[index])
            self.sym_LED_NAME[index].setLabel("Name")
            self.sym_LED_NAME[index].setDefaultValue("Led"+ " " + str(index))

            self.sym_LED_PIN[index] = self.component.createComboSymbol("MCPMSMFOC_LED_"+ str(index)+"_NUMBER", self.sym_LED_INDEX[index], self.function_Map)
            self.sym_LED_PIN[index].setLabel("Pin Number")

            functions = ["Fault indication", "Direction indication", "Custom"]
            self.sym_LED_FUNCTION[index] = self.component.createComboSymbol("MCPMSMFOC_LED_"+ str(index)+"_FUNCTION", self.sym_LED_INDEX[index], functions)
            self.sym_LED_FUNCTION[index].setLabel("Function")

                
    def handleMessage(self, ID, information):
        print(information)
        if None != information:
            index = 0
            for button in information["BUTTONS"].keys():
                self.sym_BUTTON_INDEX[index].setVisible(True)
                self.sym_BUTTON_PIN[index].setValue(information["BUTTONS"][button]["PAD"])
                index += 1
            
            index = 0
            for led in information["LEDS"].keys():
                self.sym_LED_INDEX[index].setVisible(True)
                self.sym_LED_PIN[index].setValue(information["LEDS"][led]["PAD"])
                index += 1

    def __call__(self):
        self.createSymbols()
        self.setSymbolValues()



