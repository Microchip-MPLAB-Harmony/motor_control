# coding: utf-8
"""
****************************************************************************** 
Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
** Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
** THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
** IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
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
# Import the module from the specified folder
from device.uart.uart import UartPeripheral

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#

class DataMonitorClass(UartPeripheral):
    def __init__(self, object_wrapper):
        UartPeripheral.__init__( self, object_wrapper)

        self.object_wrapper = object_wrapper

        # Data monitoring information format
        '''
           {
                'instance': {
                                transmit: {
                                            channel: '',
                                            pad: ''
                                        },
                                receive: {
                                            channel: '',
                                            pad: ''
                                        }
                            }
           }

        '''
        self.information = {}

        # Read xml data from the path
        self.read_configuration_file()

    def read_configuration_file(self):

        for comm_interface in self.object_wrapper.components['Communication']:
            if comm_interface.parameters["type"] == "two_wired_uart":
                instance = comm_interface.parameters['peripheral']['instance']

                transmit_channel = comm_interface.parameters['peripheral']['transmit_channel']
                transmit_pad = comm_interface.parameters['gpio_pins']['transmit']['gpio_config']['pin_number']

                receive_channel = comm_interface.parameters['peripheral']['receive_channel']
                receive_pad = comm_interface.parameters['gpio_pins']['receive']['gpio_config']['pin_number']

                self.information.setdefault(instance, {}).setdefault('transmit', {})['channel'] = transmit_channel
                self.information.setdefault(instance, {}).setdefault('transmit', {})['pad'] = transmit_pad

                self.information.setdefault(instance, {}).setdefault('receive', {})['channel'] = receive_channel
                self.information.setdefault(instance, {}).setdefault('receive', {})['pad'] = receive_pad

    def update_information(self):
        self.read_configuration_file()
        # Send message
        self.send_information()
        self.update_pin_settings()

    def setDatabaseSymbol(self, nameSpace, ID, value):
        Database = self.object_wrapper.get_database_object()
        status = Database.setSymbolValue(nameSpace, ID, value)
        if(status == False):
            print("BSP is unable to set {symbol} with {input}".format(symbol=ID, input=value))

    def update_pin_settings(self):
        instance = next(iter(self.information))

        transmit_channel = self.information[instance]['transmit']['channel']
        transmit_pad = self.information[instance]['transmit']['pad']

        self.set_uart_transmit_pin('TRANSMIT', instance, transmit_channel, transmit_pad)

        receive_channel = self.information[instance]['receive']['channel']
        receive_pad = self.information[instance]['receive']['pad']

        self.set_uart_receive_pin('RECEIVE', instance, receive_channel, receive_pad)


    def send_information(self):
        Database = self.object_wrapper.get_database_object()
        Database.sendMessage("X2CScope", "BSP_DATA_MONITORING", self.information)
        Database.sendMessage("pmsm_foc", "BSP_DATA_MONITORING", self.information)

    def handle_message(self, ID, information):
        if(ID == "X2CSCOPE_DATA_MONITORING"):
            return self.information

    def show_this_symbol( self, symbol, event ):
        # Make the symbol visible based on event symbol values.
        symbol.setVisible( event['value'] )
        
    def create_symbols( self ):
        component = self.object_wrapper.get_component()
        root_symbol = component.createMenuSymbol( 'FOC_BOARD_DEBUG_INTERFACE', None )
        root_symbol.setLabel( 'Debug interface ')
        
        symbol_uart_interface = component.createBooleanSymbol('FOC_BOARD_DEBUG_UART_INTERFACE', root_symbol )
        symbol_uart_interface.setLabel('Debug UART interface')
        
        available_instances = ['UART1']
        symbol_instance = component.createComboSymbol('FOC_BOARD_DEBUG_UART_INSTANCE', root_symbol, available_instances )
        symbol_instance.setLabel('Instance')
        symbol_instance.setVisible(False)
        symbol_instance.setDependencies( self.show_this_symbol, ['FOC_BOARD_DEBUG_UART_INTERFACE'] )

        available_pads = ['PA10']
        symbol_transmit = component.createComboSymbol('FOC_BOARD_DEBUG_UART_TRANSMIT', root_symbol, available_pads )
        symbol_transmit.setLabel('QEA pad')
        symbol_transmit.setVisible(False)
        symbol_transmit.setDependencies( self.show_this_symbol, ['FOC_BOARD_DEBUG_UART_INTERFACE'] )

        available_pads = ['PA9']
        symbol_receive = component.createComboSymbol('FOC_BOARD_DEBUG_UART_RECEIVE', root_symbol, available_pads )
        symbol_receive.setLabel('QEB pad')
        symbol_receive.setVisible(False)
        symbol_receive.setDependencies( self.show_this_symbol, ['FOC_BOARD_DEBUG_UART_INTERFACE'] )
        
    def __call__(self):
        self.create_symbols()
        self.update_pin_settings()
        self.send_information()
