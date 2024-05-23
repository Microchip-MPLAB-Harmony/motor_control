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
#                                 Imports                                               #
#---------------------------------------------------------------------------------------#
import os.path
import xml.etree.ElementTree as ET
import json


#---------------------------------------------------------------------------------------#
#                                Global Variables                                       #
#---------------------------------------------------------------------------------------#
# Get the MCU and name from ATDF once
global MCU
MCU =  ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")
name =  ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("name")

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                   Classes                                             #
#---------------------------------------------------------------------------------------#
class mcBrdI_BoardClass:
    def __init__(self, component ):
        self.component = component

        self.information = {}
        self.information = self.get_supported_boards_from_bsp()

    def get_supported_boards_from_bsp(self):
        supported_boards = {}

        # Open and parse the BSP file
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
                    config_folder_path = os.path.join( Variables.get("__BSP_DIR"),'boards', board_config_folder, "config", "boards")

                    # Traverse through the configuration folder
                    for root, _, files in os.walk(config_folder_path):
                        for file_name in files:
                            if file_name.endswith('.json'):
                                file_path = os.path.join(root, file_name)
                                try:
                                    with open(file_path, 'r') as json_file:
                                        data = json.load(json_file)
                                        if data:  # Check if JSON data is not empty
                                            root_key = next(iter(data.keys()))  # Get the first key

                                            bsp_id = 'BSP_' + board_name.replace(' ', '_')
                                            if bsp_id not in supported_boards.keys():
                                                supported_boards[bsp_id] = []
                                            supported_boards[bsp_id].append(root_key)

                                except ValueError as e:
                                    print("Error parsing JSON file {}: {}".format(file_path, e))

        print('Print supported boards', supported_boards)
        return supported_boards

    def createSymbols( self ):
        sym_BOARD_NODE = self.component.createBooleanSymbol("MCPMSMFOC_DEVELOPER_MODE", None)
        sym_BOARD_NODE.setLabel("Enable developer mode")
        sym_BOARD_NODE.setVisible(True)

        sym_BOARD_NODE = self.component.createMenuSymbol("MCPMSMFOC_BOARD_CONF", None)
        sym_BOARD_NODE.setLabel("Board Configuration")
        sym_BOARD_NODE.setVisible(True)

        global sym_SELECTED_BOARD
        sym_SELECTED_BOARD = self.component.createKeyValueSetSymbol("MCPMSMFOC_BOARD_SEL", sym_BOARD_NODE )
        sym_SELECTED_BOARD.setLabel("Development board")
        sym_SELECTED_BOARD.addKey("CUSTOM", "0", "Custom")

        index = 0
        for board_list in self.information.values():
            for board in board_list:
                index = index + 1
                sym_SELECTED_BOARD.addKey(board, str(index), board)

        sym_SELECTED_BOARD.setOutputMode("Key")
        sym_SELECTED_BOARD.setDisplayMode("Description")
        sym_SELECTED_BOARD.setDefaultValue(0)
        sym_SELECTED_BOARD.setDependencies( self.mcPmsmFoc_SelectBoard, ["MCPMSMFOC_BOARD_SEL"])

        sym_BSP_ID = self.component.createStringSymbol("MCPMSMFOC_BSP_ID", None)
        sym_BSP_ID.setLabel("BSP ID")
        sym_BSP_ID.setVisible(False)

        if sym_SELECTED_BOARD.getSelectedKey() == "CUSTOM":
            sym_BSP_ID.setDefaultValue("custom_mc_board")

        else:
            for bsp_id, board_list in self.information.items():
                if sym_SELECTED_BOARD.getSelectedKey() in board_list:
                    sym_BSP_ID.setDefaultValue(bsp_id)

        sym_BSP_ID.setDependencies(self.updateBspId, ["MCPMSMFOC_BOARD_SEL"] )



    def updateBspId(self, symbol, event):
        # Deactivate the older BSP and connect the selected one
        old_bsp_id = symbol.getValue()

        if event["symbol"].getSelectedKey() == "CUSTOM":
            symbol.setValue("custom_mc_board")
        else:
            for bsp_id, board_list in self.information.items():
                if event["symbol"].getSelectedKey() in board_list:
                    symbol.setValue(bsp_id)

        # Deactivate old BSP
        if old_bsp_id != symbol.getValue():
            # Deactivate old BSP
            autoConnectTable = [old_bsp_id]
            res = Database.deactivateComponents(autoConnectTable)

        # Activate and connect the default PWM peripheral
        module = str( Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_BSP_ID"))
        autoConnectTable = [ module]
        res = Database.activateComponents(autoConnectTable)

    """
    Description:
    This function shall be called when the selected board is changed

    """
    def mcPmsmFoc_SelectBoard( self, symbol, event):
        message = dict()
        message["SELECTED_BOARD"] = symbol.getSelectedKey()
        Database.sendMessage("bsp", "MCPMSMFOC_SELECTED_BOARD", message )


    def handleMessage(self, ID, information ):
        if "MCBSP_SEND_BOARD_DATA" == ID:
            sym_SELECTED_BOARD.setSelectedKey(information["NAME"])

    def __call__(self):
        self.createSymbols()