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
from modules.pwm_interface import VoltageSourceClass
from modules.analog_frontend import AnalogFrontEndClass
from modules.position_interface import PositionInterfaceClass
from modules.pwm_interface import PwmConfiguration
from modules.data_monitoring import DataMonitorClass
from device.gpio.pin_manager import PinManager

#--------------------------------------------------------------------------------------------#
#                             CLASSES                                                        #
#--------------------------------------------------------------------------------------------#

class FocBoardManager:
    def __init__(self, object_wrapper, board_params ):
        # Update object_wrapper interface handler
        self.object_wrapper = object_wrapper

        # Create board information object
        print('Board parameters', board_params )
        self.analog_frontend = AnalogFrontEndClass( object_wrapper,  board_params['Analog_Circuits'] )

        # Create position interface class
        #self.position_interface = PositionInterfaceClass(object_wrapper,  board_params['Position_Interface'])

        # Create board information object
       # self.pwm_interface = PwmConfiguration(object_wrapper,  board_params['Inverter'])

        # Create board information object
       #self.data_monitor = DataMonitorClass(object_wrapper,  board_params['Communication'])

    def create_symbols(self):
        # MHC Symbols
        board_List =  self.object_wrapper.board_params.keys()

        component = self.object_wrapper.get_component()
        self.selected_board = component.createStringSymbol("BSP_BOARD_SEL", None )
        self.selected_board.setLabel("Development Board")
        self.selected_board.setDefaultValue('Custom')
       # self.selected_board.setDependencies( self.update_board, ["BSP_BOARD_SEL"] )


    def __call__(self, bspComponent):
        # Create BSP symbols
        self.create_symbols()

        # Position interface information
     #  self.position_interface()

        # # PWM interface information
    #    self.pwm_interface()

        # Analog front-end information
        self.analog_frontend()

        # Data monitoring interface
     #   self.data_monitor()