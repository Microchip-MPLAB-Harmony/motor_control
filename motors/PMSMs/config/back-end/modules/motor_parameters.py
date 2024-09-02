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
#                             MOTOR CLASS  FUNCTIONS                               #
#----------------------------------------------------------------------------------#
class mcMotI_MotorParametersClass:
    def __init__(self, component):
        self.component = component

        # Motor bench motor parameter files
        motor_folder_path = os.path.join(Module.getPath(), 'config', 'sample-motors')
        self.motors = {}

        for root, _, files in os.walk(os.path.join(motor_folder_path )):
            for filename in files:
                if filename.endswith('.yaml'):
                    # Load the YAML file
                    yaml_file_path = os.path.join(root, filename)
                    try:
                        with open(yaml_file_path, 'r') as file:
                            yaml_data = yaml.safe_load(file)

                        # Extract motor data
                        meta_data = yaml_data.get('motor', {}).get('meta_data', {})
                        manufacturer_motor_name = meta_data.get('manufacturer_motor_name', 'Unknown')
                        if manufacturer_motor_name not in self.motors:
                            try:
                                 self.motors[manufacturer_motor_name] = yaml_data['motor']
                            except Exception as e:
                                print("Warning: Motor file cannot be parsed: {}, {}, Error: {}".format(yaml_file_path, filename, e))
                    except Exception as e:
                         print("Warning: Motor data not extracted successfully: {}, {}, Error: {}".format(yaml_file_path, filename, e))

    def create_symbols(self):
        '''
            Motor Parameters symbol structure
        '''
        # Motor selection symbol
        motor_list = ['Custom'] + self.motors.keys()
        self.sym_SELECT_MOTOR = self.component.createComboSymbol("MCPMSMFOC_MOTOR_SEL", None, motor_list )
        self.sym_SELECT_MOTOR.setLabel("Selected Motor")
        default_motor = self.sym_SELECT_MOTOR.getValue()


        # Saving the new board
        self.sym_METADATA_MENU = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_METADATA_MENU",  self.sym_SELECT_MOTOR )
        self.sym_METADATA_MENU.setLabel("Metadata")

        self.sym_METADATA_NAME = self.component.createStringSymbol("MCPMSMFOC_METADATA_MOTOR_FILE_NAME", self.sym_METADATA_MENU)
        self.sym_METADATA_NAME.setLabel('Microchip motor name')
        self.sym_METADATA_NAME.setDependencies(self.make_read_only, ['MCPMSMFOC_MOTOR_SEL'])

        self.sym_METADATA_MANUFACTURER_NAME = self.component.createStringSymbol("MCPMSMFOC_METADATA_MOTOR_NAME_MANUFACTURER", self.sym_METADATA_MENU)
        self.sym_METADATA_MANUFACTURER_NAME.setLabel('Manufaturer motor name')
        self.sym_METADATA_MANUFACTURER_NAME.setDependencies(self.make_read_only, ['MCPMSMFOC_MOTOR_SEL'])

        self.sym_METADATA_MANUFACTURER = self.component.createStringSymbol("MCPMSMFOC_METADATA_MOTOR_MANUFACTURER", self.sym_METADATA_MENU)
        self.sym_METADATA_MANUFACTURER.setLabel('Manufaturer name')
        self.sym_METADATA_MANUFACTURER.setDependencies(self.make_read_only, ['MCPMSMFOC_MOTOR_SEL'])

        self.sym_METADATA_PART_NO = self.component.createStringSymbol("MCPMSMFOC_METADATA_MOTOR_PART_NO", self.sym_METADATA_MENU)
        self.sym_METADATA_PART_NO.setLabel('Manufaturer part number')
        self.sym_METADATA_PART_NO.setDependencies(self.make_read_only, ['MCPMSMFOC_MOTOR_SEL'])

        self.sym_WARNING = self.component.createCommentSymbol("MCPMSMFOC_CUSTOM_MOTOR_WARNING", self.sym_METADATA_MENU )
        self.sym_WARNING.setLabel('No Warning')
        self.sym_WARNING.setVisible(False)

        #   Custom motor parameters
        self.sym_CUSTOM_MOTOR_PARAMS = self.component.createStringSymbol("MCPMSMFOC_CUSTOM_MOTOR_PARAMS", self.sym_METADATA_MENU )
        self.sym_CUSTOM_MOTOR_PARAMS.setLabel('Custom motor parameters')
        self.sym_CUSTOM_MOTOR_PARAMS.setDefaultValue('')
        self.sym_CUSTOM_MOTOR_PARAMS.setVisible(False)
        self.sym_CUSTOM_MOTOR_PARAMS.setReadOnly(True)
        self.sym_CUSTOM_MOTOR_PARAMS.setDependencies(self.update_motor_list, ['MCPMSMFOC_CUSTOM_MOTOR_PARAMS'])

        self.sym_NAME_PLATE_PARAMS = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_NAME_PLATE_PARAMS",  self.sym_SELECT_MOTOR )
        self.sym_NAME_PLATE_PARAMS.setLabel("Nameplate Parameters")

        # Motor connection type symbol
        self.sym_POLARITY = self.component.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_CONNECTION", self.sym_NAME_PLATE_PARAMS)
        self.sym_POLARITY.setLabel("Motor Connection")
        self.sym_POLARITY.addKey("STAR", "0", "STAR")
        self.sym_POLARITY.addKey("DELTA", "1", "DELTA")
        self.sym_POLARITY.setOutputMode("Key")
        self.sym_POLARITY.setDisplayMode("Description")
        try:
            self.sym_POLARITY.setSelectedKey(self.motors[default_motor]['connection'])
        except:
            print("Warning: The connection type is not indicated in the file", default_motor)

        self.sym_POLARITY.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_MOTOR_CONNECTION"])

        # Motor pole pairs
        if 'Custom' == default_motor:
            pole_pairs = 0
        else:
            pole_pairs = self.numeric_value_get(self.motors[default_motor]['polePairs'])

        self.sym_ZP = self.component.createFloatSymbol("MCPMSMFOC_POLE_PAIRS", self.sym_NAME_PLATE_PARAMS)
        self.sym_ZP.setLabel("Pole pairs")
        self.sym_ZP.setDefaultValue(pole_pairs)
        self.sym_ZP.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_POLE_PAIRS"])

        # Motor rated speed
        if 'Custom' == default_motor:
            rated_speed = 0
        else:
            rated_speed = self.speed_in_rpm_get(self.motors[default_motor]['namePlateBaseSpeed'])

        self.sym_N_RATED = self.component.createFloatSymbol("MCPMSMFOC_RATED_SPEED", self.sym_NAME_PLATE_PARAMS)
        self.sym_N_RATED.setLabel("Base mechanical speed (RPM)")
        self.sym_N_RATED.setDefaultValue(rated_speed)
        self.sym_N_RATED.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_RATED_SPEED"])

        # Motor maximum speed
        if 'Custom' == default_motor:
            max_speed = 0
        else:
            max_speed = self.speed_in_rpm_get(self.motors[default_motor]['namePlateRatedSpeed'])

        self.sym_N_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_SPEED", self.sym_NAME_PLATE_PARAMS)
        self.sym_N_MAX.setLabel("Maximum mechanical speed (RPM)")
        self.sym_N_MAX.setDefaultValue(max_speed)
        self.sym_N_MAX.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_MAX_SPEED"])

        # Motor maximum current
        if 'Custom' == default_motor:
            i_max = 0
        else:
            i_max = self.numeric_value_get(self.motors[default_motor]['namePlateRatedCurrentContinuous'])

        self.sym_I_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_MOTOR_CURRENT", self.sym_NAME_PLATE_PARAMS)
        self.sym_I_MAX.setLabel("Rated continuous current (A)")
        self.sym_I_MAX.setDefaultValue(i_max)
        self.sym_I_MAX.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_MAX_MOTOR_CURRENT"])

        # Motor line-line resistance
        if 'Custom' == default_motor:
            res = 0.0
        else:
            res = self.resistance_in_ohms_get(self.motors[default_motor]['R'])

        # Motor inertia
        if 'Custom' == default_motor:
            rated_voltage = 0
        else:
            rated_voltage = self.numeric_value_get(self.motors[default_motor]['rated_voltage'])

        self.sym_RATED_VOLTAGE = self.component.createFloatSymbol("MCPMSMFOC_RATED_VOLTAGE", self.sym_NAME_PLATE_PARAMS)
        self.sym_RATED_VOLTAGE.setLabel("Rated voltage (V)")
        self.sym_RATED_VOLTAGE.setDefaultValue(rated_voltage)
        self.sym_RATED_VOLTAGE.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_RATED_VOLTAGE"])

        self.sym_ELECTRICAL_PARAMS = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_ELECTRICAL_PARAMS",  self.sym_SELECT_MOTOR )
        self.sym_ELECTRICAL_PARAMS.setLabel("Electrical Parameters")

        self.sym_RS = self.component.createFloatSymbol("MCPMSMFOC_R", self.sym_ELECTRICAL_PARAMS)
        self.sym_RS.setLabel("Resistance (ohms)")
        self.sym_RS.setDefaultValue(res)
        self.sym_RS.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_R"])

        # Motor direct axis inductance
        if 'Custom' == default_motor:
            Ld = 0.0
        else:
            Ld = self.inductance_in_henry_get(self.motors[default_motor]['Ld'])

        self.sym_LD = self.component.createFloatSymbol("MCPMSMFOC_LD", self.sym_ELECTRICAL_PARAMS)
        self.sym_LD.setLabel("Direct-axis inductance Ld (Henry)")
        self.sym_LD.setDefaultValue(Ld)
        self.sym_LD.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_LD"])

        # Motor quadrature axis inductance
        if 'Custom' == default_motor:
            Lq = 0.0
        else:
            Lq = self.inductance_in_henry_get(self.motors[default_motor]['Lq'])

        self.sym_LQ = self.component.createFloatSymbol("MCPMSMFOC_LQ", self.sym_ELECTRICAL_PARAMS)
        self.sym_LQ.setLabel("Quadrature-axis inductance Lq (Henry)")
        self.sym_LQ.setDefaultValue(Lq)
        self.sym_LQ.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_LQ"])

        # Motor back emf constant
        if 'Custom' == default_motor:
            Ke = 0.0
        else:
            Ke = self.bemf_const_vpeak_per_krpm_get(self.motors[default_motor]['Ke'])

        self.sym_KE = self.component.createFloatSymbol("MCPMSMFOC_BEMF_CONST", self.sym_ELECTRICAL_PARAMS)
        self.sym_KE.setLabel("Back EMF Constant (Vrms/KRPM line-line)")
        self.sym_KE.setDefaultValue(Ke)
        self.sym_KE.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_BEMF_CONST"])

        self.sym_MECHANICAL_PARAMS = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_MECHANICAL_PARAMS",  self.sym_SELECT_MOTOR )
        self.sym_MECHANICAL_PARAMS.setLabel("Mechanical Parameters")

        # Motor viscous damping coefficient
        if 'Custom' == default_motor:
            damping_coefficient = 0
        else:
            damping_coefficient = self.numeric_value_get(self.motors[default_motor]['B'])

        self.sym_B = self.component.createFloatSymbol("MCPMSMFOC_VISCOUS_DAMPING", self.sym_MECHANICAL_PARAMS)
        self.sym_B.setLabel("Viscous damping coefficient (N-m /(rad/s))")
        self.sym_B.setDefaultValue(damping_coefficient)
        self.sym_B.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_VISCOUS_DAMPING"])

        # Motor frictional constant
        if 'Custom' == default_motor:
            friction_const = 0
        else:
            friction_const = self.numeric_value_get(self.motors[default_motor]['Tfr'])

        self.sym_TF = self.component.createFloatSymbol("MCPMSMFOC_FRICTION_TORQUE", self.sym_MECHANICAL_PARAMS)
        self.sym_TF.setLabel("Constant frictional torque (N-m))")
        self.sym_TF.setDefaultValue(friction_const)
        self.sym_TF.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_FRICTION_TORQUE"])

        # Motor inertia
        if 'Custom' == default_motor:
            inertia_val = 0
        else:
            inertia_val = self.numeric_value_get(self.motors[default_motor]['Tf'])

        self.sym_J = self.component.createFloatSymbol("MCPMSMFOC_ROTOR_INERTIA", self.sym_MECHANICAL_PARAMS)
        self.sym_J.setLabel("Rotor inertia (N-m /(rad/s^2))")
        self.sym_J.setDefaultValue(inertia_val)
        self.sym_J.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_ROTOR_INERTIA"])

        self.sym_SENSOR_PARAMS = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_SENSOR_PARAMS",  self.sym_SELECT_MOTOR )
        self.sym_SENSOR_PARAMS.setLabel("Sensor Parameters")

        sensor_types = ['None', 'Incremental Encoder', 'Inductive Sensor', 'Hall Sensor']
        self.sym_SENSOR_SEL = self.component.createComboSymbol("MCPMSMFOC_MOTOR_SENSOR_SEL", self.sym_SENSOR_PARAMS, sensor_types )
        self.sym_SENSOR_SEL.setLabel("Selected Sensor")
        self.sym_SENSOR_SEL.setDefaultValue("Incremental Encoder")
        self.sym_SENSOR_SEL.setReadOnly(True)

        self.sym_ENCODER_INDEX = self.component.createBooleanSymbol("MCPMSMFOC_MOTOR_SENSOR_ENCODER_INDEX_PRESENT", self.sym_SENSOR_SEL )
        self.sym_ENCODER_INDEX.setLabel("Index pulse present ?")
        self.sym_ENCODER_INDEX.setDefaultValue(False)
        self.sym_ENCODER_INDEX.setReadOnly(True)

        self.sym_ENCODER_PPR = self.component.createIntegerSymbol("MCPMSMFOC_MOTOR_SENSOR_ENCODER_PPR", self.sym_SENSOR_SEL )
        self.sym_ENCODER_PPR.setLabel("Pulse per revolution")
        self.sym_ENCODER_PPR.setDefaultValue(0)
        self.sym_ENCODER_PPR.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_MOTOR_SENSOR_ENCODER_PPR"])

        # Initialize callback functions
        self.sym_DEPENDNCIES = self.component.createStringSymbol("MCPMSMFOC_MOTOR_PARAMS", self.sym_SELECT_MOTOR)
        self.sym_DEPENDNCIES.setVisible(False)
        self.sym_DEPENDNCIES.setDependencies( self.motor_change_update, ["MCPMSMFOC_MOTOR_SEL"])

        # Saving the new board
        self.sym_MBENCH_IMPORT_MENU = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_MBENCH_IMPORT_MENU",  self.sym_SELECT_MOTOR )
        self.sym_MBENCH_IMPORT_MENU.setLabel("Motor Bench")
        self.sym_MBENCH_IMPORT_MENU.setVisible(False)

        self.sym_MBENCH_FILE_PATH = self.component.createStringSymbol("MCPMSMFOC_MOTOR_MBENCH_FILE_PATH",  self.sym_MBENCH_IMPORT_MENU )
        self.sym_MBENCH_FILE_PATH.setLabel("Motor bench file path")

        self.sym_MBENCH_FILE_CONVERT = self.component.createBooleanSymbol("MCPMSMFOC_MOTOR_MBENCH_FILE_CONVERT",  self.sym_MBENCH_IMPORT_MENU )
        self.sym_MBENCH_FILE_PATH.setLabel("Import motor bench file")
        self.sym_MBENCH_FILE_PATH.setDependencies(self.motor_bench_file_import, ['MCPMSMFOC_MOTOR_MBENCH_FILE_CONVERT'])

    def get_yaml_file_path_from_xml_path(self, xml_file_path):
        # Assuming the YAML file should have the same base name as the XML file, but with a .yaml extension
        base_name = os.path.splitext(xml_file_path)[0]
        yaml_file_path = base_name + '.yaml'
        return yaml_file_path

    def motor_bench_file_import(self, symbol, event):
        xml_file_path = self.sym_MBENCH_FILE_PATH.getValue()
        yaml_file_path = self.get_yaml_file_path_from_xml_path(xml_file_path)
        try:
            # self.convert_xml_to_yaml(xml_file_path, yaml_file_path)
            adapter = MotorBenchFileAdapter()
            yaml_data = adapter.adapter_service(xml_file_path )
        except Exception as e:
            print("Warning: XML adapter failed: Error: {}".format(e ))

        try:
            if yaml_data != {}:
                # Extract motor data
                meta_data = yaml_data.get('motor', {}).get('meta_data', {})
                manufacturer_name = meta_data.get('manufacturer_motor_name', 'Unknown')
                if manufacturer_name not in self.motors:
                    try:
                        self.motors[manufacturer_name] = yaml_data['motor']
                    except Exception as e:
                        print("Warning: Motor file cannot be parsed: {}, Error: {}".format(yaml_file_path, e))
        except Exception as e:
            print("Warning: Motor data not extracted successfully: {}, Error: {}".format(yaml_file_path, e ))

        if  self.sym_CUSTOM_MOTOR_PARAMS.getValue() != '':
            existing_custom_motors = eval(self.sym_CUSTOM_MOTOR_PARAMS.getValue())
        else:
            existing_custom_motors = {}

        new_custom_motor = {manufacturer_name: yaml_data['motor']}
        existing_custom_motors.update(new_custom_motor)
        self.sym_CUSTOM_MOTOR_PARAMS.setValue(str(existing_custom_motors))

    def save_custom_motor_params( self ):
        self.sym_WARNING.setVisible(False)
        custom_motor_name = str(self.sym_METADATA_NAME.getValue())
        if  self.sym_CUSTOM_MOTOR_PARAMS.getValue() != '':
            existing_custom_motors = eval(self.sym_CUSTOM_MOTOR_PARAMS.getValue())
        else:
            existing_custom_motors = {}

        if custom_motor_name  in existing_custom_motors:
            self.sym_WARNING.setVisible(True)
            self.sym_WARNING.setLabel('The motor already exists. Change motor name and save again')
            return

        if custom_motor_name != ''  and custom_motor_name:
            input_file = os.path.join(Module.getPath(), 'config', 'sample-motors', 'templates', 'custom_motor.yaml.template')

            prospective_out_file = os.path.join(Module.getPath(), 'config', 'sample-motors', 'custom-motors', custom_motor_name + '.yaml')
            if os.path.exists(prospective_out_file):
                self.sym_WARNING.setVisible(True)
                self.sym_WARNING.setLabel('The motor file already exists. Change motor name and re-enable')
                return

            self.sym_WARNING.setVisible(False)
            self.sym_WARNING.setLabel('No Warning')

            # Load the YAML template file
            with open(input_file, 'r') as file:
                yaml_data = yaml.safe_load(file)

            # Update the YAML data with the new values
            yaml_data['motor']['meta_data'] = {
                'microchip_name': custom_motor_name,
                'manufacturer_name': str(self.sym_METADATA_MANUFACTURER.getValue()),
                'manufacturer_motor_name': str(self.sym_METADATA_MANUFACTURER_NAME.getValue()),
                'manufacturer_part_no': str(self.sym_METADATA_PART_NO.getValue()),
            }

            # Update nameplate parameters
            if '0' == str(self.sym_POLARITY.getValue()):
                connection_type = 'STAR'
            elif '1' == str(self.sym_POLARITY.getValue()):
                connection_type = 'DELTA'

            yaml_data['motor']['parameters']['name_plate_parameters'] = {
                'connection_type': connection_type,
                'pole_pairs': self.sym_ZP.getValue(),
                'velocity': {
                    'nominal': self.sym_N_RATED.getValue(),
                    'maximum': self.sym_N_MAX.getValue()
                },
                'current': {
                    'maximum': {
                        'continuous': self.sym_I_MAX.getValue()
                    }
                }
            }

            # Update electrical parameters
            yaml_data['motor']['parameters']['electrical_parameters'] = {
                'R':     self.sym_RS.getValue(),
                'Lq':    self.sym_LQ.getValue(),
                'Ld':    self.sym_LD.getValue(),
                 'L':  (( self.sym_LD.getValue() + self.sym_LQ.getValue()) / 2),  # Assuming L is the average of Ld and Lq
                 'Ke':    self.sym_KE.getValue(),
            }

            # Update mechanical parameters
            yaml_data['motor']['parameters']['mechanical_parameters'] = {
                'J': self.sym_J.getValue(),
                'B': self.sym_B.getValue(),
                'Tfr': self.sym_TF.getValue(),
            }
            if 'Incremental Encoder' == self.sym_SENSOR_SEL.getValue():
                yaml_data['motor']['parameters']['sensor_parameters'] = {
                    'incremental_encoder':  {
                        'index_pulse_present': self.sym_ENCODER_INDEX.getValue(),
                        'pulse_per_rev': self.sym_ENCODER_PPR.getValue(),
                    }
                }

            new_custom_motor = { custom_motor_name: yaml_data['motor'] }
            existing_custom_motors.update(new_custom_motor)
            self.sym_CUSTOM_MOTOR_PARAMS.setValue(str(existing_custom_motors))

    def numeric_value_get(self, value_str):
        # Split the string by whitespace to separate the numeric value from the unit
        parts = value_str.split()

        # Extract the numeric part
        numeric_part = parts[0]

        # Convert the numeric part to a regular string and remove any non-numeric characters
        numeric_part = ''.join(c for c in str(numeric_part) if c.isdigit() or c == '.')

        # Convert to float
        numeric_value = float(numeric_part)

        return numeric_value

    def resistance_in_ohms_get(self, res_str):
        # Return resistance value
        return res_str

    def inductance_in_henry_get(self, ind_str):
        # Return resistance value
        return ind_str

    def speed_in_rpm_get(self, rad_per_sec_value):
        rpm_value = 30 * rad_per_sec_value / math.pi
        return rpm_value

    def speed_in_rad_per_sec_get(self, rpm_value):
        rad_per_sec_value = math.pi * rpm_value / 30
        return rad_per_sec_value

    def bemf_const_vpeak_per_krpm_get(self, bemf_vrms_sec_per_rad):
        # ToDO: Calculate back EMF constant value
        bemf_const_vpeak_per_krpm_get = bemf_vrms_sec_per_rad * (( math.sqrt(3.0/2.0) * math.pi * 1000.0 )/ 30.0 )

        # Convert RMS voltage to peak voltage (for sinusoidal signal)
        return bemf_const_vpeak_per_krpm_get

    def bemf_const_vrms_sec_per_rad_get(self, bemf_vpeak_per_krpm):
        # ToDO: Calculate back EMF constant value
        bemf_const_vrms_sec_per_rad_get = bemf_vpeak_per_krpm * (30.0/ ( math.sqrt(3.0/2.0) * math.pi * 1000.0 ))

        # Convert RMS voltage to peak voltage (for sinusoidal signal)
        return bemf_const_vrms_sec_per_rad_get

    def make_read_only( self, symbol, event):
        if event["value"] != 'Custom':
            symbol.setReadOnly(True)
        else:
            symbol.setReadOnly(False)

    def make_symbol_visible(self, symbol, event):
        if event["value"] == 'Custom':
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def motor_parameters_update(self, symbol, event):
        message = {
            'selected_motor':  self.sym_SELECT_MOTOR.getValue(),
            'electrical_parameters': {
                'R': self.sym_RS.getValue(),
                'Ld': self.sym_LD.getValue(),
                'Lq': self.sym_LQ.getValue(),
                'Ke': self.sym_KE.getValue()
            },
            'name_plate_parameters': {
                'pole_pairs': self.sym_ZP.getValue(),
                'velocity': {
                    'nominal': self.sym_N_RATED.getValue(),
                    'maximum': self.sym_N_MAX.getValue()
                },
                'current': {
                    'maximum': {
                        'continuous': self.sym_I_MAX.getValue()
                    }
                },
                'voltage': {
                    'nominal': self.sym_RATED_VOLTAGE.getValue()
                },
                'connection': self.sym_POLARITY.getSelectedKey()
            },
            'mechanical_parameters': {
                'B': self.sym_B.getValue(),
                'Tfr': self.sym_TF.getValue(),
                'J': self.sym_J.getValue(),
                'sensor_parameters': {
                    'incremental_encoder': {
                        'pulse_per_rev': self.sym_ENCODER_PPR.getValue()
                    }
                }
            }
        }
        Database.sendMessage('pmsm_foc', 'PMSM_PARAMETERS_SET', message)


    def motor_change_update( self, symbol, event ):
        selected_motor = event["symbol"].getValue()
        if selected_motor != 'Custom':
            meta_data = self.motors[selected_motor]['meta_data']
            self.sym_METADATA_NAME.setValue(meta_data['microchip_name'])
            self.sym_METADATA_MANUFACTURER.setValue(meta_data['manufacturer_name'])
            self.sym_METADATA_MANUFACTURER_NAME.setValue(meta_data['manufacturer_motor_name'])
            self.sym_METADATA_PART_NO.setValue(meta_data['manufacturer_part_no'])

            params = self.motors[selected_motor]['parameters']
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
                print("Warning: The connection type is not indicated in the file", selected_motor)

            # Update sensor parameters
            if 'sensor_parameters' in params.keys():
                if 'incremental_encoder' in params['sensor_parameters'].keys():
                    self.sym_ENCODER_PPR.setValue( params['sensor_parameters']['incremental_encoder']['pulse_per_rev'])
                    encoder_count_per_rot = int(params['sensor_parameters']['incremental_encoder']['pulse_per_rev'])
                    pole_pairs = params['name_plate_parameters']['pole_pairs']
                    encoder_count_per_elec_rot = encoder_count_per_rot/ pole_pairs
                    Database.setSymbolValue('pmsm_foc', "MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", int(encoder_count_per_elec_rot ))
            else:
                    self.sym_ENCODER_PPR.setValue( 0 )
                    Database.setSymbolValue('pmsm_foc', "MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", 0 )

            # Merging params dictionary with a new key-value pair
            message = params.copy()
            message.update({'selected_motor': selected_motor })

            Database.sendMessage('pmsm_foc', 'PMSM_PARAMETERS_SET', message)

        else:
            self.sym_METADATA_NAME.setValue('')
            self.sym_METADATA_MANUFACTURER.setValue('')
            self.sym_METADATA_MANUFACTURER_NAME.setValue('')
            self.sym_METADATA_PART_NO.setValue('')
            self.sym_RS.setValue(0.0)
            self.sym_LD.setValue(0.0)
            self.sym_LQ.setValue(0.0)
            self.sym_KE.setValue(0.0)
            self.sym_ZP.setValue(0.0)
            self.sym_N_RATED.setValue(0.0)
            self.sym_N_MAX.setValue(0.0)
            self.sym_I_MAX.setValue(0.0)
            self.sym_B.setValue(0.0)
            self.sym_TF.setValue(0.0)
            self.sym_J.setValue(0.0)
            self.sym_RATED_VOLTAGE.setValue(0.0)
            try:
                self.sym_POLARITY.setSelectedKey('STAR')
            except:
                print("Warning: The connection type is not indicated in the file", selected_motor)

            # Update sensor parameters
            Database.setSymbolValue('pmsm_foc', "MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", 0)

    def update_motor_list(self, symbol, event):
        # Update motor parameters
        if symbol.getValue != '':
            custom_motors = eval(symbol.getValue())
        else:
            custom_motors = {}

        self.motors.update(custom_motors)
        self.sym_SELECT_MOTOR.setRange( ['Custom'] + self.motors.keys())

    def handle_message( self, message_id, args ):
        if message_id == 'MESSAGE_FROM_QSPIN_GUI':
            if args['custom_motor_set'] == True:
                self.save_custom_motor_params()

    def __call__( self ):

        # Create MHC symbols for Motor parameters
        self.create_symbols()



