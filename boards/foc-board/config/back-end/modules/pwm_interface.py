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
#                                           IMPORT                                      #
#---------------------------------------------------------------------------------------#
# Import the module from the specified folder
from device.pwm.pwm import PwmPeripheral

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#

class PwmConfiguration(PwmPeripheral):
    def __init__(self, object_wrapper):
        PwmPeripheral.__init__(self, object_wrapper)
        self.object_wrapper = object_wrapper

        self.read_configuration_file()

    def read_configuration_file(self):
        self.information = {}

        for inverter in self.object_wrapper.components['Inverter']:
            instance = inverter.parameters['peripheral']['instance']
            self.information.setdefault(instance, {})
            peripheral = inverter.parameters['peripheral']
            gpio_pins = inverter.parameters['gpio_pins']

            channels = peripheral['channels']
            for phase, phase_info in channels.items():
                for side, side_info in [('low', 'low_side'), ('high', 'high_side')]:
                    channel = phase_info
                    pad = gpio_pins[phase][side_info]['gpio_config']['pin_number']
                    self.information[instance].setdefault(phase, {}).setdefault(side, {})["channel"] = channel
                    self.information[instance][phase][side]["pad"] = pad

            pad = gpio_pins['fault']['gpio_config']['pin_number']

            # Determine fault channel available for the instance and pad
            channel = self.fault_channel_get( instance, pad )
            self.information[instance]["fault_sources"] = {"channel": channel, "pad": pad}

    def handle_message(self, id,  message):
        if id == "MCPMSMFOC_PWM_INTERFACE":
            return self.information

    def update_information(self):
        self.read_configuration_file()
        self.update_pin_settings()
        self.send_information()

    def send_information(self):
        Database = self.object_wrapper.get_database_object()
        Database.sendMessage("pmsm_foc","BSP_PWM_INTERFACE", self.information )

    def update_pin_settings(self):
        for instance, phases in self.information.items():
            for phase, phase_dict in phases.items():
                if phase == 'fault_sources':
                    name = 'PWM_FAULT'
                    self.set_fault_source(name, instance, channel, phase_dict['pad'])
                else:
                    for side, channel_info in phase_dict.items():
                        channel = channel_info['channel']
                        pad = channel_info['pad']
                        pin_name_suffix = 'L' if side == 'low' else 'H'
                        pin_name = phase.upper() + '_PWM' + pin_name_suffix

                        if side == 'low':
                            self.set_low_side_pwm_pin(pin_name, instance, channel, pad)
                        elif side == 'high':
                            self.set_high_side_pwm_pin(pin_name, instance, channel, pad)

    def show_this_symbol( self, symbol, event ):
        # Make the symbol visible based on event symbol values.
        symbol.setVisible( event['value'] )

    def create_symbols( self ):
        component = self.object_wrapper.get_component()
        root_symbol = component.createMenuSymbol( None, None )
        root_symbol.setLabel( 'Inverter interface ')

        symbol_inverter = component.createBooleanSymbol('FOC_BOARD_INVERTER_INTERFACE', root_symbol )
        symbol_inverter.setLabel( 'Enable inverter interface ')

        available_instances = ['PWM1']
        symbol_instance = component.createComboSymbol('FOC_BOARD_PWM_INSTANCE', symbol_inverter, available_instances )
        symbol_instance.setLabel('Instance')
        symbol_instance.setVisible(False)
        symbol_instance.setDependencies( self.show_this_symbol, ['FOC_BOARD_INVERTER_INTERFACE'] )

        for phase_name in ['Phase A', 'Phase B', 'Phase C']:
            available_instances = ['1']
            modified_symbol_id = 'FOC_BOARD_PWM_' + (phase_name.upper()).replace( ' ', '_')
            symbol_channel = component.createComboSymbol( modified_symbol_id + '_CHANNEL', symbol_instance, available_instances )
            symbol_channel.setLabel( phase_name + ' ' + 'channel')
            symbol_channel.setVisible(False)
            symbol_channel.setDependencies( self.show_this_symbol, ['FOC_BOARD_INVERTER_INTERFACE'] )

            available_pads = ['PA10']
            symbol_high_side = component.createComboSymbol( modified_symbol_id + '_HS_PAD', symbol_channel, available_pads )
            symbol_high_side.setLabel( phase_name + ' ' + 'high side pad')
            symbol_high_side.setVisible(False)
            symbol_high_side.setDependencies( self.show_this_symbol, ['FOC_BOARD_INVERTER_INTERFACE'] )

            available_pads = ['PA9']
            symbol_low_side = component.createComboSymbol( modified_symbol_id + '_LS_PAD', symbol_channel, available_pads )
            symbol_low_side.setLabel( phase_name + ' ' + 'low side pad')
            symbol_low_side.setVisible(False)
            symbol_low_side.setDependencies( self.show_this_symbol, ['FOC_BOARD_INVERTER_INTERFACE'] )

    def __call__(self):
        self.create_symbols()
        self.update_pin_settings()
        self.send_information()


class VoltageSourceClass:
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper

        self.read_configuration_file()

    def read_configuration_file(self):
        self.information = {}

        for inverter in self.object_wrapper.components['Inverter']:
            self.information["VDC"] = inverter.parameters["voltage_rating"]

    def update_information(self):
        self.read_configuration_file()
        self.send_message()

    def handle_message(self, id,  message):
       if( id == "MCPMSMFOC_VOLTAGE_SOURCE"):
           return self.information

    def send_message( self ):
        Database = self.object_wrapper.get_database_object()
        Database.sendMessage("pmsm_foc", "BSP_VOLTAGE_SOURCE", self.information)

    def create_symbols(self):
        component = self.object_wrapper.get_component()
        root_symbol = component.createMenuSymbol( 'FOC_BOARD_VOLTAGE_SOURCE', None )
        root_symbol.setLabel( 'Voltage source')

        symbol = component.createFloatSymbol('FOC_BOARD_VOLTAGE_SOURCE_MAXIMUM', root_symbol )
        symbol.setLabel('Maximum bus voltage (  in Volts )')

        symbol = component.createFloatSymbol('FOC_BOARD_VOLTAGE_SOURCE_MINIMUM', root_symbol )
        symbol.setLabel('Minimum bus voltage  (  in Volts )')

    def __call__(self):
        self.create_symbols()
        self.send_message()