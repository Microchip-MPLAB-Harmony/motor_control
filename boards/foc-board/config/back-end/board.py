# coding: utf-8
"""*****************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#--------------------------------------------------------------------------------------------#
#                             Import                                                         #
#--------------------------------------------------------------------------------------------#
import sys
import os
import json
import xml.etree.ElementTree as ET

# Add the folder path to the system path
sys.path.append( os.path.join( Module.getPath(), '..', 'libraries' ))
sys.path.append( os.path.join( Module.getPath(), 'config', 'back-end' ))

from modules.board_data import BoardAdapter
from modules.foc_board_manager import FocBoardManager

#--------------------------------------------------------------------------------------------#
#                             CLASSES                                                        #
#--------------------------------------------------------------------------------------------#

class HarmonyObjectWrapper(BoardAdapter):
    def __init__(self, component):
        # Update component object handler
        self.component = component

        # Get supported board parameters
        self.board_params = self.get_board_params_from_files()

        # Initialize board adapter superclass
        BoardAdapter.__init__(self, self.board_params)

        # Set the default board parameters
        self.update_board_parameters('MCLV-48V-300W')

    def get_atdf_object(self):
        return ATDF

    def get_database_object(self):
        return Database

    def get_module_object(self):
        return Module

    def get_component(self):
        return self.component

    def get_board_params_from_files(self):
        supported_boards = {}
        directory_path = os.path.join(Module.getPath(), "config", "ref-boards")

        # Traverse through the configuration folder
        for file_name in os.listdir(directory_path):
            if file_name.endswith('.json'):
                file_path = os.path.join(directory_path, file_name)
                try:
                    with open(file_path, 'r') as json_file:
                        data = json.load(json_file)
                        if data:  # Check if JSON data is not empty
                            root_key = next(iter(data.keys()))  # Get the first key
                            supported_boards.update(data)
                except ValueError as e:
                    print("Error parsing JSON file {}: {}".format(file_path, e))
        return supported_boards

#--------------------------------------------------------------------------------------------#
#                             INSTANTIATION                                                  #
#--------------------------------------------------------------------------------------------#
def instantiateComponent(bsp_component):
    # Create object_wrapper class object
    object_wrapper = HarmonyObjectWrapper(bsp_component)
    supported_boards = object_wrapper.board_params

    global bsp
    bsp = FocBoardManager(object_wrapper, supported_boards['MCLV-48V-300W'])
    bsp(bsp_component)

#--------------------------------------------------------------------------------------------#
#                             MESSAGE HANDLING                                               #
#--------------------------------------------------------------------------------------------#
def handleMessage(id, args):
    bsp.handle_message(id, args)