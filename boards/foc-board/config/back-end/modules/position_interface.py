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
from device.qdec.qdec import QdecPeripheral

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 Classes                                               #
#---------------------------------------------------------------------------------------#

class PositionInterfaceClass(QdecPeripheral):
    def __init__(self, object_wrapper):
        QdecPeripheral.__init__( self, object_wrapper)
        self.object_wrapper = object_wrapper

        # Read xml data from the path
        self.read_configuration_file()

    '''
        QDEC
           {
                'instance': {
                                'channel': {
                                                'qea': 'pad',
                                                'qeb': 'pad',
                                                'idx': 'pad'
                                            }
                            }

            }
    '''
    def read_configuration_file(self):
        self.information = { }

        for position_interface in self.object_wrapper.components['Position_Interface']:
            instance = position_interface.parameters['peripheral']["instance"]
            channel = position_interface.parameters['peripheral']["channel"]

            if channel == '':
                channel = 'channel'

        qea_pad = position_interface.parameters['gpio_pins']['qea']['gpio_config']['pin_number']
        qeb_pad = position_interface.parameters['gpio_pins']['qeb']['gpio_config']['pin_number']

        self.information[instance] = {
                                        channel: {
                                                    'qea': qea_pad,
                                                    'qeb': qeb_pad,
                                            }
                                     }

    def update_information(self):
        self.read_configuration_file()
        self.send_information()
        self.update_pin_settings()

    def send_information(self):
        print('Position interface..',  self.information )
        Database = self.object_wrapper.get_database_object()
        Database.sendMessage("pmsm_foc", "BSP_POSITION_INTERFACE", self.information)

    def handle_message(self, id, args):
        if "MCPMSMFOC_POSITION_INTERFACE" == id:
            return self.information

    def update_pin_settings(self):
        instance = next(iter(self.information))
        channel = next(iter(self.information[instance]))

        qea_pad = self.information[instance][channel]['qea']
        qeb_pad = self.information[instance][channel]['qeb']

        self.set_qdec_pin('ENCODER', instance, channel, qea_pad, qeb_pad)

    def show_this_symbol( self, symbol, event ):
        # Make the symbol visible based on event symbol values.
        symbol.setVisible( event['value'] )

    def create_symbols( self ):
        component = self.object_wrapper.get_component()
        root_symbol = component.createMenuSymbol( 'FOC_BOARD_POSITION_INTERFACE', None )
        root_symbol.setLabel( 'Position interface ')

        symbol_incr_encoder = component.createBooleanSymbol('FOC_BOARD_INCREMENTAL_ENCODER', root_symbol )
        symbol_incr_encoder.setLabel('Incremental Encoder')

        available_instances = ['QDEC 1']
        symbol_qdec_instance = component.createComboSymbol('FOC_BOARD_QDEC_INSTANCE', root_symbol, available_instances )
        symbol_qdec_instance.setLabel('Instance')
        symbol_qdec_instance.setVisible(False)
        symbol_qdec_instance.setDependencies( self.show_this_symbol, ['FOC_BOARD_INCREMENTAL_ENCODER'] )

        available_pads = ['PA10']
        symbol_qdec_qea = component.createComboSymbol('FOC_BOARD_QDEC_QEA_PAD', root_symbol, available_pads )
        symbol_qdec_qea.setLabel('QEA pad')
        symbol_qdec_qea.setVisible(False)
        symbol_qdec_qea.setDependencies( self.show_this_symbol, ['FOC_BOARD_INCREMENTAL_ENCODER'] )

        available_pads = ['PA9']
        symbol_qdec_qeb = component.createComboSymbol('FOC_BOARD_QDEC_QEB_PAD', root_symbol, available_pads )
        symbol_qdec_qeb.setLabel('QEB pad')
        symbol_qdec_qeb.setVisible(False)
        symbol_qdec_qeb.setDependencies( self.show_this_symbol, ['FOC_BOARD_INCREMENTAL_ENCODER'] )

    def __call__(self):
        self.create_symbols()
        self.update_pin_settings()
        self.send_information()
