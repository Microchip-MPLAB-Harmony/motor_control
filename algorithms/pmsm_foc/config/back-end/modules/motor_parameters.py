# -*- coding: utf-8 -*-

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
* File Name: motor_parameters.py
*
* Description:
* The file comprises of back-end code for motor block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                                       IMPORT                                     #
#----------------------------------------------------------------------------------#
import math
import os
import yaml

#----------------------------------------------------------------------------------#
#                        SUPPORTED MOTOR PARAMETERS                                #
#----------------------------------------------------------------------------------#

#----------------------------------------------------------------------------------#
#                             MOTOR CLASS  FUNCTIONS                               #
#----------------------------------------------------------------------------------#
class mcMotI_MotorParametersClass:
    def __init__(self, component):
        self.component = component
        autoConnectTable = ['motortype_PMSM']
        res = Database.activateComponents(autoConnectTable)

        autoComponentIDTable = [[ 'pmsm_foc', "pmsmfoc_MOTOR", "motortype_PMSM", "PMSM"]]
        res = Database.connectDependencies(autoComponentIDTable)

    def create_symbols(self):
        '''
            Motor Parameters symbol structure
        '''
        # Root Node
        self.sym_NODE = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_CONFIG", None)
        self.sym_NODE.setLabel("Motor Configuration")

        # Motor selection symbol
        self.sym_SELECT_MOTOR = self.component.createStringSymbol("MCPMSMFOC_MOTOR_SEL", self.sym_NODE )
        self.sym_SELECT_MOTOR.setLabel("Selected Motor")
        self.sym_SELECT_MOTOR.setReadOnly(True)

        # Motor connection type symbol
        self.sym_POLARITY = self.component.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_CONNECTION", self.sym_SELECT_MOTOR)
        self.sym_POLARITY.setLabel("Motor Connection")
        self.sym_POLARITY.addKey("STAR", "0", "STAR")
        self.sym_POLARITY.addKey("DELTA", "1", "DELTA")
        self.sym_POLARITY.setOutputMode("Key")
        self.sym_POLARITY.setDisplayMode("Description")
        self.sym_POLARITY.setReadOnly(True)

        self.sym_RS = self.component.createFloatSymbol("MCPMSMFOC_R", self.sym_SELECT_MOTOR)
        self.sym_RS.setLabel("Line-neutral resistance (ohms)")
        self.sym_RS.setDefaultValue(0)
        self.sym_RS.setReadOnly(True)

        self.sym_LD = self.component.createFloatSymbol("MCPMSMFOC_LD", self.sym_SELECT_MOTOR)
        self.sym_LD.setLabel("Line-neutral direct-axis inductance Ld (Henry)")
        self.sym_LD.setDefaultValue(0)
        self.sym_LD.setReadOnly(True)

        self.sym_LQ = self.component.createFloatSymbol("MCPMSMFOC_LQ", self.sym_SELECT_MOTOR)
        self.sym_LQ.setLabel("Line-neutral quadrature-axis inductance Lq (Henry)")
        self.sym_LQ.setDefaultValue(0)
        self.sym_LQ.setReadOnly(True)

        self.sym_ZP = self.component.createFloatSymbol("MCPMSMFOC_POLE_PAIRS", self.sym_SELECT_MOTOR)
        self.sym_ZP.setLabel("Pole pairs")
        self.sym_ZP.setDefaultValue(0)
        self.sym_ZP.setReadOnly(True)

        # Motor back emf constant
        self.sym_KE = self.component.createFloatSymbol("MCPMSMFOC_BEMF_CONST", self.sym_SELECT_MOTOR)
        self.sym_KE.setLabel("Back EMF Constant (Vrms/KRPM line-line)")
        self.sym_KE.setDefaultValue(0)
        self.sym_KE.setReadOnly(True)

        # Motor rated speed
        self.sym_N_RATED = self.component.createFloatSymbol("MCPMSMFOC_RATED_SPEED", self.sym_SELECT_MOTOR)
        self.sym_N_RATED.setLabel("Base mechanical speed (RPM)")
        self.sym_N_RATED.setDefaultValue(0)
        self.sym_N_RATED.setReadOnly(True)

        # Motor maximum speed
        self.sym_N_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_SPEED", self.sym_SELECT_MOTOR)
        self.sym_N_MAX.setLabel("Maximum mechanical speed (RPM)")
        self.sym_N_MAX.setDefaultValue(0)
        self.sym_N_MAX.setReadOnly(True)

        # Motor maximum current
        self.sym_I_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_MOTOR_CURRENT", self.sym_SELECT_MOTOR)
        self.sym_I_MAX.setLabel("Rated continuous current (A)")
        self.sym_I_MAX.setDefaultValue(0)
        self.sym_I_MAX.setReadOnly(True)

        # Motor viscous damping coefficient
        self.sym_B = self.component.createFloatSymbol("MCPMSMFOC_VISCOUS_DAMPING", self.sym_SELECT_MOTOR)
        self.sym_B.setLabel("Viscous damping coefficient (N-m /(rad/s))")
        self.sym_B.setDefaultValue(0)
        self.sym_B.setReadOnly(True)

        # Motor frictional constant
        self.sym_TF = self.component.createFloatSymbol("MCPMSMFOC_FRICTION_TORQUE", self.sym_SELECT_MOTOR)
        self.sym_TF.setLabel("Constant frictional torque (N-m))")
        self.sym_TF.setDefaultValue(0)
        self.sym_TF.setReadOnly(True)

        # Motor inertia
        self.sym_J = self.component.createFloatSymbol("MCPMSMFOC_ROTOR_INERTIA", self.sym_SELECT_MOTOR)
        self.sym_J.setLabel("Rotor inertia (N-m /(rad/s^2))")
        self.sym_J.setDefaultValue(0)
        self.sym_J.setReadOnly(True)

        # Motor inertia
        self.sym_RATED_VOLTAGE = self.component.createFloatSymbol("MCPMSMFOC_RATED_VOLTAGE", self.sym_SELECT_MOTOR)
        self.sym_RATED_VOLTAGE.setLabel("Rated voltage (V)")
        self.sym_RATED_VOLTAGE.setDefaultValue(0)
        self.sym_RATED_VOLTAGE.setReadOnly(True)

    def handle_message(self, id, params ):
        if 'PMSM_PARAMETERS_SET' == id:
            self.sym_SELECT_MOTOR.setValue(params['selected_motor'])
            self.sym_RS.setValue(params['electrical_parameters']['R'])
            self.sym_LD.setValue(params['electrical_parameters']['Ld'])
            self.sym_LQ.setValue(params['electrical_parameters']['Lq'])
            self.sym_KE.setValue(params['electrical_parameters']['Ke'])
            self.sym_ZP.setValue(params['name_plate_parameters']['pole_pairs'])
            self.sym_N_RATED.setValue(params['name_plate_parameters']['velocity']['nominal'])
            self.sym_N_MAX.setValue(params['name_plate_parameters']['velocity']['maximum'])
            self.sym_I_MAX.setValue(params['name_plate_parameters']['current']['maximum']['continuous'])
            self.sym_B.setValue(params['mechanical_parameters']['B'])
            self.sym_TF.setValue(params['mechanical_parameters']['Tfr'])
            self.sym_J.setValue(params['mechanical_parameters']['J'])
            self.sym_RATED_VOLTAGE.setValue(params['name_plate_parameters']['voltage']['nominal'])
            try:
                self.sym_POLARITY.setSelectedKey(params['name_plate_parameters']['connection'])
            except:
                print("Warning: The connection type is not indicated in the file")

            # Update sensor parameters
            if 'sensor_parameters' in params.keys():
                if 'incremental_encoder' in params['sensor_parameters'].keys():
                    encoder_count_per_rot = int(params['sensor_parameters']['incremental_encoder']['pulse_per_rev'])
                    Database.setSymbolValue('pmsm_foc', "MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", int(encoder_count_per_rot ))
                else:
                    Database.setSymbolValue('pmsm_foc', "MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", 0 )

    def __call__( self ):

        # Create MHC symbols for Motor parameters
        self.create_symbols()



