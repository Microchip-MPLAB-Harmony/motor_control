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
* File Name: mcPmsmFoc_MotorParameter.py
*
* Description:
* The file comprises of back-end code for motor block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                                       IMPORT                                     #
#----------------------------------------------------------------------------------#
import xml.etree.ElementTree as ET
import os

#----------------------------------------------------------------------------------#
#                        SUPPORTED MOTOR PARAMETERS                                #
#----------------------------------------------------------------------------------#

#----------------------------------------------------------------------------------#
#                             MOTOR CLASS  FUNCTIONS                               #
#----------------------------------------------------------------------------------#
class mcMotI_MotorParametersClass:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

        # Read motor parameters from motor.xml
        path = Module.getPath() + "/algorithms/pmsm_foc/config/floating_point/motor.xml"
        motor_File = open(path, "r")
        motor_Content = ET.fromstring(motor_File.read())

        self.motor_List = list()
        self.motor_Parameters = dict()

        for motor in motor_Content.findall("motor"):
            name = motor.attrib["name"]
            self.motor_List.append(motor.attrib["name"])
            self.motor_Parameters[name] = dict()
            for parameter in motor.findall("parameter"):
                param = parameter.attrib["id"]
                self.motor_Parameters[name][param] = parameter.attrib["value"]


    def createSymbols(self):
        '''
            Motor Parameters symbol structure

        '''
        # Root Node
        self.sym_NODE = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_CONFIG", None)
        self.sym_NODE.setLabel("Motor Configuration")

        # Motor selection symbol
        self.sym_SELECT_MOTOR = self.component.createComboSymbol("MCPMSMFOC_MOTOR_SEL", self.sym_NODE, self.motor_List )
        self.sym_SELECT_MOTOR.setLabel("Selected Motor")
        default_Motor = self.sym_SELECT_MOTOR.getValue()

        # Motor connection type symbol
        self.sym_POLARITY = self.component.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_CONNECTION", self.sym_SELECT_MOTOR)
        self.sym_POLARITY.setLabel("Motor Connection")
        self.sym_POLARITY.addKey("STAR", "0", "STAR")
        self.sym_POLARITY.addKey("DELTA", "1", "DELTA")
        self.sym_POLARITY.setOutputMode("Key")
        self.sym_POLARITY.setDisplayMode("Description")
        self.sym_POLARITY.setSelectedKey(self.motor_Parameters[default_Motor]['MOTOR_CONNECTION'])

        # Motor line-line resistance
        self.sym_RS = self.component.createFloatSymbol("MCPMSMFOC_R", self.sym_SELECT_MOTOR)
        self.sym_RS.setLabel("Phase Resistance (ohms)")
        self.sym_RS.setDefaultValue(float(self.motor_Parameters[default_Motor]['R']))

        # Motor direct axis inductance
        self.sym_LD = self.component.createFloatSymbol("MCPMSMFOC_LD", self.sym_SELECT_MOTOR)
        self.sym_LD.setLabel("Phase Direct Axis Inductance Ld (Henry)")
        self.sym_LD.setDefaultValue(float(self.motor_Parameters[default_Motor]['LD']))

        # Motor quadrature axis inductance
        self.sym_LQ = self.component.createFloatSymbol("MCPMSMFOC_LQ", self.sym_SELECT_MOTOR)
        self.sym_LQ.setLabel("Phase Quadrature Axis Inductance Lq (Henry)")
        self.sym_LQ.setDefaultValue(float(self.motor_Parameters[default_Motor]['LQ']))

        # Motor pole pairs
        self.sym_ZP = self.component.createFloatSymbol("MCPMSMFOC_POLE_PAIRS", self.sym_SELECT_MOTOR)
        self.sym_ZP.setLabel("Motor Pole Pairs")
        self.sym_ZP.setDefaultValue(float(self.motor_Parameters[default_Motor]['POLE_PAIRS']))

        # Motor back emf constant
        self.sym_KE = self.component.createFloatSymbol("MCPMSMFOC_BEMF_CONST", self.sym_SELECT_MOTOR)
        self.sym_KE.setLabel("Motor BEMF Constant (Vpk L-L/KRPM)")
        self.sym_KE.setDefaultValue(float(self.motor_Parameters[default_Motor]['BEMF_CONST']))

        # Motor rated speed
        self.sym_N_RATED = self.component.createFloatSymbol("MCPMSMFOC_RATED_SPEED", self.sym_SELECT_MOTOR)
        self.sym_N_RATED.setLabel("Motor Rated Speed (RPM)")
        self.sym_N_RATED.setDefaultValue(float(self.motor_Parameters[default_Motor]['RATED_SPEED']))

        # Motor maximum speed
        self.sym_N_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_SPEED", self.sym_SELECT_MOTOR)
        self.sym_N_MAX.setLabel("Motor Max Speed (RPM)")
        self.sym_N_MAX.setDefaultValue(float(self.motor_Parameters[default_Motor]['MAX_SPEED']))

        # Motor maximum current
        self.sym_I_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_MOTOR_CURRENT", self.sym_SELECT_MOTOR)
        self.sym_I_MAX.setLabel("Max Motor Current (A)")
        self.sym_I_MAX.setDefaultValue(float(self.motor_Parameters[default_Motor]['MAX_MOTOR_CURRENT']))

        # Initialize callback functions
        self.sym_DEPENDNCIES = self.component.createStringSymbol("MCPMSMFOC_MOTOR_PARAMS", self.sym_SELECT_MOTOR)
        self.sym_DEPENDNCIES.setVisible(False)
        self.sym_DEPENDNCIES.setDependencies( self.symbolUpdate, ["MCPMSMFOC_MOTOR_SEL"])

    def symbolUpdate( self, symbol, event ):
        motor = event["symbol"].getValue()
        if motor in self.motor_List:
            motor = event["symbol"].getValue()
            self.sym_RS.setValue( float( self.motor_Parameters[motor]['R'] ))
            self.sym_LD.setValue( float( self.motor_Parameters[motor]['LD'] ))
            self.sym_LQ.setValue( float( self.motor_Parameters[motor]['LQ' ] ))
            self.sym_KE.setValue( float( self.motor_Parameters[motor]['BEMF_CONST' ] ))
            self.sym_ZP.setValue( float( self.motor_Parameters[motor]['POLE_PAIRS' ] ))
            self.sym_N_RATED.setValue( float( self.motor_Parameters[motor]['RATED_SPEED' ] ))
            self.sym_N_MAX.setValue( float( self.motor_Parameters[motor]['MAX_SPEED' ] ))
            self.sym_I_MAX.setValue( float( self.motor_Parameters[motor]['MAX_MOTOR_CURRENT' ] ))
            self.sym_POLARITY.setSelectedKey(  self.motor_Parameters[motor]['MOTOR_CONNECTION'])

    def __call__( self ):

        # Create MHC symbols for Motor parameters
        self.createSymbols()



