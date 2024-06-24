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

import os
import json
import xml.etree.ElementTree as ET

#---------------------------------------------------------------------------------------#
#                                 Global variables                                      #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 Private Functions                                     #
#---------------------------------------------------------------------------------------#
class ButtonClass:
    def __init__(self, name, parameters):
        self.name = name
        self.parameters = parameters

    def assign_pad(self, pad):
        self.parameters["pad"] = pad

    def __call__(self):
        # ToDO: Put appropriate function later
        pass

class LedClass:
    def __init__(self, name, parameters):
        self.name = name
        self.parameters = parameters

    def assign_pad(self, pad):
        # ToDO: Put appropriate function later
        pass

    def __call__(self):
        # ToDO: Put appropriate function later
        pass

class AnalogClass:
    def __init__(self, name, parameters):
        self.name = name
        self.parameters = parameters

    def assign_pad(self, pad):
        # ToDO: Put appropriate function later
        pass

    def __call__(self):
        # ToDO: Put appropriate function later
        pass

class InverterClass:
    def __init__(self, name, parameters):
        self.name = name
        self.parameters = parameters

    def assign_pad(self, pad):
        # ToDO: Put appropriate function later
        pass

    def __call__(self):
        # ToDO: Put appropriate function later
        pass


class CommInterfaceClass:
    def __init__(self, name, parameters):
        self.name = name
        self.parameters = parameters

    def assign_pad(self, pad):
        # ToDO: Put appropriate function later
        pass

    def __call__(self):
        # ToDO: Put appropriate function later
        pass

class PositionSensorClass:
    def __init__(self, name, parameters):
        self.name = name
        self.parameters = parameters

    def assign_pad(self, pad):
        # ToDO: Put appropriate function later
        pass

    def __call__(self):
        # ToDO: Put appropriate function later
        pass

#---------------------------------------------------------------------------------------#
#                                 Interface fuctions                                    #
#---------------------------------------------------------------------------------------#
class BoardParameters:
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper

    def get_board_params(self):
        supported_boards = {}

        # Open and parse the BSP file
        Variables = self.object_wrapper.get_variable_object()
        bsp_file_path = os.path.join(Variables.get("__BSP_DIR"), "boards", "module.xml")
        with open(bsp_file_path, "r") as bsp_file:
            bsp_content = ET.fromstring(bsp_file.read())

        # Extract relevant information from the BSP content
        for board in bsp_content.iter("Board"):
            if board.attrib.get('processor') == Variables.get("__PROCESSOR"):
                board_name = board.attrib.get('name', '')
                board_config_folder = board.attrib.get('config', '')

                # Check if the board is an MC Board
                if 'MC Board' in board_name:
                    Module = self.object_wrapper.get_module_object()
                    config_folder_path = os.path.join(Module.getPath(), board_config_folder, "config", "boards")

                    # Traverse through the configuration folder
                    for root, _, files in os.walk(config_folder_path):
                        for file_name in files:
                            if file_name.endswith('.json'):
                                file_path = os.path.join(root, file_name)
                                with open(file_path, 'r') as json_file:
                                    data = json.load(json_file)
                                    if data:  # Check if JSON data is not empty
                                        supported_boards.update(data)

        return supported_boards

class BoardAdapter:
    def __init__(self, board_params):
        self.board_params = board_params

        self.components = {
            'Buttons': [],
            'Leds': [],
            'Analog_Circuits': [],
            'Position_Interface':[],
            'Inverter': [],
            'Communication': []
        }

        # Initialize components lists
        for component_type, component_list in self.components.items():
            setattr(self, component_type.lower(), component_list)

    def update_board_parameters(self, selected_board ):
        # Delete all previously created objects
        for component_list in self.components.values():
            del component_list[:]

        board_parameters = self.board_params[selected_board]

        # Create objects for buttons
        if 'Buttons' in board_parameters.keys():
            for name, parameters in board_parameters['Buttons'].items():
                # Create an object
                self.components['Buttons'].append(ButtonClass(name, parameters))

        # Create objects for leds
        if 'Leds' in board_parameters.keys():
            for name, parameters in board_parameters['Leds'].items():
                # Create an object
                self.components['Leds'].append(LedClass(name, parameters))

        # Create objects for analog circuits
        if 'Analog_Circuits' in board_parameters.keys():
            for name, parameters in board_parameters['Analog_Circuits'].items():
                # Create an object
                self.components['Analog_Circuits'].append(AnalogClass(name, parameters))

        # Create objects for position interface
        if 'Position_Interface' in board_parameters.keys():
            for name, parameters in board_parameters['Position_Interface'].items():
                # Create an object
                self.components['Position_Interface'].append(PositionSensorClass(name, parameters))

        # Create objects for inverter
        if 'Inverter' in board_parameters.keys():
            for name, parameters in board_parameters['Inverter'].items():
                # Create an object
                self.components['Inverter'].append(InverterClass(name, parameters))

        # Create objects for communication peripherals
        if 'Communication' in board_parameters.keys():
            for name, parameters in board_parameters['Communication'].items():
                # Create an object
                self.components['Communication'].append(CommInterfaceClass(name, parameters))

    def __call__(self):
        # No code at the moment
        pass

