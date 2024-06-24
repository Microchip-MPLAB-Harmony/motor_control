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
from device.adc.adc import AdcPeripheralClass

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#

class AnalogFrontEndClass:
    def __init__(self, object_wrapper, analog_circuit_params ):
        self.object_wrapper = object_wrapper
        self.analog_circuit_params = analog_circuit_params
        self.adc_parameters = ( AdcPeripheralClass( self.object_wrapper )).get_adc_data()


    def create_symbols( self ):
        component = self.object_wrapper.get_component()
        root_symbol = component.createMenuSymbol( 'FOC_BOARD_ANALOG_FRONT_END', None )
        root_symbol.setLabel( 'Analog interface ')

        # Create symbol for phase A, phase B, phase C and DC bus current interface
        for symbol_desc in [ 'Phase A current', 'Phase B current', 'Phase C current', 'DC link current' ]:
            modified_symbol_id =  'FOC_BOARD_AFE_' + ( symbol_desc.upper( )).replace( ' ', '_')
            symbol = component.createBooleanSymbol( modified_symbol_id, root_symbol )
            symbol.setLabel( symbol_desc )

            symbol_circuit = component.createMenuSymbol( modified_symbol_id + '_CIRCUIT', symbol )
            symbol_circuit.setLabel( 'Analog Circuit' )
            symbol_circuit.setVisible( False )
            symbol_circuit.setDependencies( self.show_this_symbol, [modified_symbol_id] )

            symbol_gain = component.createFloatSymbol( modified_symbol_id + '_GAIN', symbol_circuit )
            symbol_gain.setLabel( 'Gain ')
            symbol_gain.setDefaultValue( self.analog_circuit_params[symbol_desc]['circuit_param']['opamp_gain'] )
            symbol_gain.setVisible( False )
            symbol_gain.setDependencies( self.show_this_symbol, [modified_symbol_id] )

            symbol_bias = component.createFloatSymbol( modified_symbol_id + '_BIAS', symbol_circuit )
            symbol_bias.setLabel( 'Voltage bias ( in Volts )')
            symbol_bias.setDefaultValue( self.analog_circuit_params[symbol_desc]['circuit_param']['opamp_bias'] )
            symbol_bias.setVisible( False )
            symbol_bias.setDependencies( self.show_this_symbol, [modified_symbol_id] )

            symbol_r_shunt = component.createFloatSymbol( modified_symbol_id + '_RSHUNT', symbol_circuit )
            symbol_r_shunt.setLabel( 'Shunt resistance ( in Ohms )')
            symbol_r_shunt.setDefaultValue( self.analog_circuit_params[symbol_desc]['circuit_param']['shunt_resistor'] )
            symbol_r_shunt.setVisible( False )
            symbol_r_shunt.setDependencies( self.show_this_symbol, [modified_symbol_id] )

            symbol_connector = component.createMenuSymbol( modified_symbol_id + '_CONNECTOR', symbol )
            symbol_connector.setLabel( 'Connector details' )
            symbol_connector.setVisible( False )
            symbol_connector.setDependencies( self.show_this_symbol, [modified_symbol_id] )

            available_instances = self.adc_parameters['analog_interfaces'].keys()
            symbol_adc_instance = component.createComboSymbol( modified_symbol_id + '_ADC_INSTANCE',  symbol_connector, available_instances )
            symbol_adc_instance.setLabel('Adc instance')
            symbol_adc_instance.setDefaultValue( self.analog_circuit_params[symbol_desc]['peripheral']['instance'] )
            symbol_adc_instance.setVisible( False )
            symbol_adc_instance.setDependencies( self.show_this_symbol, [modified_symbol_id] )

            available_channels = self.adc_parameters['analog_interfaces'][symbol_adc_instance.getValue()].keys()
            symbol_adc_channel = component.createComboSymbol( modified_symbol_id + '_ADC_CHANNEL',  symbol_connector, available_channels )
            symbol_adc_channel.setLabel('Adc channel')
            symbol_adc_channel.setDefaultValue( str( self.analog_circuit_params[symbol_desc]['peripheral']['channel'] ))
            symbol_adc_channel.setVisible( False )
            symbol_adc_channel.setDependencies( self.show_this_symbol, [modified_symbol_id] )

            available_pads = self.adc_parameters['analog_interfaces'][symbol_adc_instance.getValue()][symbol_adc_channel.getValue()]
            symbol_adc_pad = component.createComboSymbol( modified_symbol_id + '_ADC_PAD',  symbol_connector, available_pads )
            symbol_adc_pad.setLabel('Adc pad')
            symbol_adc_pad.setDefaultValue( self.analog_circuit_params[symbol_desc]['gpio_config']['pin_number'] )
            symbol_adc_pad.setVisible( False )
            symbol_adc_pad.setDependencies( self.show_this_symbol, [modified_symbol_id] )

        # Create symbol for DC bus voltage
        symbol_dcbus = component.createBooleanSymbol( 'FOC_BOARD_AFE_DC_BUS_VOLTAGE', root_symbol )
        symbol_dcbus.setLabel( 'DC bus voltage' )

        symbol_circuit = component.createMenuSymbol( 'FOC_BOARD_AFE_DC_BUS_VOLTAGE_CIRCUIT', symbol_dcbus )
        symbol_circuit.setLabel( 'Analog Circuit' )
        symbol_circuit.setVisible( False )
        symbol_circuit.setDependencies( self.show_this_symbol, ['FOC_BOARD_AFE_DC_BUS_VOLTAGE'] )

        symbol_top_resistance = component.createFloatSymbol( 'FOC_BOARD_AFE_DC_BUS_VOLTAGE_RTOP', symbol_circuit )
        symbol_top_resistance.setLabel( 'Top resistance ( in Ohms ) ')
        symbol_top_resistance.setVisible( False )
        symbol_top_resistance.setDependencies( self.show_this_symbol, ['FOC_BOARD_AFE_DC_BUS_VOLTAGE'] )

        symbol_bottom_resistance = component.createFloatSymbol( 'FOC_BOARD_AFE_DC_BUS_VOLTAGE_RBOT', symbol_circuit )
        symbol_bottom_resistance.setLabel('Bottom resistance ( in Ohms ) ')
        symbol_bottom_resistance.setVisible( False )
        symbol_bottom_resistance.setDependencies( self.show_this_symbol, ['FOC_BOARD_AFE_DC_BUS_VOLTAGE'] )

        symbol_connector = component.createMenuSymbol('FOC_BOARD_AFE_DC_BUS_VOLTAGE_CONNECTOR', symbol_dcbus )
        symbol_connector.setLabel( 'Connector details' )
        symbol_connector.setVisible( False )
        symbol_connector.setDependencies( self.show_this_symbol, ['FOC_BOARD_AFE_DC_BUS_VOLTAGE'] )

        available_instances = self.adc_parameters['analog_interfaces'].keys()
        symbol_adc_instance = component.createComboSymbol( 'FOC_BOARD_AFE_DC_BUS_VOLTAGE_ADC_INSTANCE',  symbol_connector, available_instances )
        symbol_adc_instance.setLabel('Adc instance')
        symbol_adc_instance.setDefaultValue( self.analog_circuit_params[symbol_desc]['peripheral']['instance'] )
        symbol_adc_instance.setVisible( False )
        symbol_adc_instance.setDependencies( self.show_this_symbol, ['FOC_BOARD_AFE_DC_BUS_VOLTAGE'] )

        available_channels = self.adc_parameters['analog_interfaces'][symbol_adc_instance.getValue()].keys()
        symbol_adc_channel = component.createComboSymbol( 'FOC_BOARD_AFE_DC_BUS_VOLTAGE_ADC_CHANNEL',  symbol_connector, available_channels )
        symbol_adc_channel.setLabel('Adc channel')
        symbol_adc_channel.setDefaultValue( str( self.analog_circuit_params[symbol_desc]['peripheral']['channel'] ))
        symbol_adc_channel.setVisible( False )
        symbol_adc_channel.setDependencies( self.show_this_symbol, ['FOC_BOARD_AFE_DC_BUS_VOLTAGE'] )

        available_pads = self.adc_parameters['analog_interfaces'][symbol_adc_instance.getValue()][symbol_adc_channel.getValue()]
        symbol_adc_pad = component.createComboSymbol( 'FOC_BOARD_AFE_DC_BUS_VOLTAGE_ADC_PAD',  symbol_connector, available_pads )
        symbol_adc_pad.setLabel('Adc pad')
        symbol_adc_pad.setDefaultValue( self.analog_circuit_params[symbol_desc]['gpio_config']['pin_number'] )
        symbol_adc_pad.setVisible( False )
        symbol_adc_pad.setDependencies( self.show_this_symbol, ['FOC_BOARD_AFE_DC_BUS_VOLTAGE'] )

    def show_this_symbol( self, symbol, event ):
        # Make the symbol visible based on event symbol values.
        symbol.setVisible( event['value'] )

    def __call__(self):
        # Create analog front end symbols
        self.create_symbols()

        # Send the information to connected component
        self.send_message()