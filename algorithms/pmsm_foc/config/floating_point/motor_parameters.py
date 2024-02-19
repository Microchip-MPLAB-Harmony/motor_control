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
import xml.etree.ElementTree as ET
import os

#----------------------------------------------------------------------------------#
#                        SUPPORTED MOTOR PARAMETERS                                #
#----------------------------------------------------------------------------------#

#----------------------------------------------------------------------------------#
#                             MOTOR CLASS  FUNCTIONS                               #
#----------------------------------------------------------------------------------#
class mcMotI_MotorParametersClass:
    def __init__(self, component):
        self.component = component

        # Motor bench motor parameter files
        motor_folder_path = os.path.join(Module.getPath(), 'algorithms', 'pmsm_foc', 'motors')
        self.motors = {}
        for root, _, files in os.walk(motor_folder_path):
            for filename in files:
                if filename.endswith('.xml'):
                    # Extract motor data
                    # Load the XML file
                    xml_file_path = os.path.join(str(root), str(filename))
                    try:
                        tree = ET.parse(xml_file_path)
                        node = tree.getroot()

                        # Now you can extract data from the current XML file
                        manufacturer_name = node.find('.//mfrMotorName').text
                        if manufacturer_name not in self.motors:
                            self.motors[manufacturer_name] = {}

                        # Extracting motor parameters
                        parameters = node.find('.//motorParameters')
                        for param in parameters:
                            active_elem = param.find('active')
                            if active_elem is not None:
                                self.motors[manufacturer_name][param.tag] = active_elem.text
                            else:
                                print("Warning: 'active' element not found in parameter:", param.tag)

                        # Extracting nameplate parameters
                        nameplate = node.find('.//nameplate')
                        if nameplate is not None:
                            for child in nameplate:
                                self.motors[manufacturer_name][child.tag] = child.text
                        else:
                            print("Warning: 'nameplate' element not found in file:", filename)

                        # Check if sensors are present in the motor
                        sensors_element = node.find('.//sensors')
                        if sensors_element is not None:
                            optical_encoder = sensors_element.find('opticalEncoder')
                            if optical_encoder is not None:
                                self.motors[manufacturer_name]['optical_encoder'] = {}
                                index_pulse_present = optical_encoder.find('indexPulsePresent')
                                pulse_per_rotation = optical_encoder.find('pulsePerRotation')
                                if index_pulse_present is not None:
                                    self.motors[manufacturer_name]['optical_encoder']['index_pulse_present'] = index_pulse_present.text
                                if pulse_per_rotation is not None:
                                    self.motors[manufacturer_name]['optical_encoder']['pulse_per_rotation'] = pulse_per_rotation.text
                            else:
                                print("Warning: 'opticalEncoder' element not found in file:", filename)
                        else:
                            print("Warning: 'sensors' element not found in file:", filename)

                        # Extracting other parameters
                        other = node.find('.//other')
                        if other is not None:
                            for child in other:
                                self.motors[manufacturer_name][child.tag] = child.text
                        else:
                            print("Warning: 'nameplate' element not found in file:", filename)
                    except:
                        print("Warning: Motor file cannot be parsed", xml_file_path, filename)

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
        # Get the numeric value
        res_value = self.numeric_value_get(res_str)

        # Return resistance value
        return res_value

    def inductance_in_henry_get(self, ind_str):
        # Get the numeric value
        ind_value = self.numeric_value_get(ind_str)

        # Return resistance value
        return ind_value

    def speed_in_rpm_get(self, rad_per_sec_str):
        # Get the numeric value
        rpm_value = self.numeric_value_get(rad_per_sec_str)

        rpm_value = 30 * rpm_value / math.pi
        return rpm_value

    def speed_in_rad_per_sec_get(self, rpm_str):
        # Get the numeric value
        rad_per_sec_value = self.numeric_value_get(rpm_str)

        rad_per_sec_value = math.pi * rad_per_sec_value / 30
        return rad_per_sec_value

    def bemf_const_vpeak_per_krpm_get(self, bemf_vrms_sec_per_rad):
        bemf_const_vpeak_per_krpm_get = self.numeric_value_get(bemf_vrms_sec_per_rad)

        # ToDO: Calculate back EMF constant value
        bemf_const_vpeak_per_krpm_get *= (( math.sqrt(3.0/2.0) * math.pi * 1000.0 )/ 30.0 )

        # Convert RMS voltage to peak voltage (for sinusoidal signal)
        return bemf_const_vpeak_per_krpm_get

    def bemf_const_vrms_sec_per_rad_get(self, bemf_vpeak_per_krpm):
        bemf_const_vrms_sec_per_rad_get = self.numeric_value_get(bemf_vpeak_per_krpm)

        # ToDO: Calculate back EMF constant value
        bemf_const_vrms_sec_per_rad_get *= (30.0/ ( math.sqrt(3.0/2.0) * math.pi * 1000.0 ))

        # Convert RMS voltage to peak voltage (for sinusoidal signal)
        return bemf_const_vrms_sec_per_rad_get

    def create_symbols(self):
        '''
            Motor Parameters symbol structure
        '''
        # Root Node
        self.sym_NODE = self.component.createMenuSymbol("MCPMSMFOC_MOTOR_CONFIG", None)
        self.sym_NODE.setLabel("Motor Configuration")

        # Motor selection symbol
        motor_list = ['Custom'] + self.motors.keys()
        self.sym_SELECT_MOTOR = self.component.createComboSymbol("MCPMSMFOC_MOTOR_SEL", self.sym_NODE, motor_list )
        self.sym_SELECT_MOTOR.setLabel("Selected Motor")
        default_motor = self.sym_SELECT_MOTOR.getValue()

        self.sym_STORE_CUSTOM_FILE_NAME = self.component.createStringSymbol("MCPMSMFOC_CUSTOM_MOTOR_FILE_NAME", self.sym_SELECT_MOTOR)
        self.sym_STORE_CUSTOM_FILE_NAME.setLabel('Custom motor name')
        self.sym_STORE_CUSTOM_FILE_NAME.setDependencies(self.make_symbol_visible, ['MCPMSMFOC_MOTOR_SEL'])

        # Motor connection type symbol
        self.sym_POLARITY = self.component.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_CONNECTION", self.sym_SELECT_MOTOR)
        self.sym_POLARITY.setLabel("Motor Connection")
        self.sym_POLARITY.addKey("STAR", "0", "STAR")
        self.sym_POLARITY.addKey("DELTA", "1", "DELTA")
        self.sym_POLARITY.setOutputMode("Key")
        self.sym_POLARITY.setDisplayMode("Description")
        try:
            self.sym_POLARITY.setSelectedKey(self.motors[default_motor]['connection'])
        except:
            print("Warning: The connection type is not indicated in the file", default_motor)

        # Motor line-line resistance
        if 'Custom' == default_motor:
            res = 0.0
        else:
            res = self.resistance_in_ohms_get(self.motors[default_motor]['Rs'])
        self.sym_RS = self.component.createFloatSymbol("MCPMSMFOC_R", self.sym_SELECT_MOTOR)
        self.sym_RS.setLabel("Resistance (ohms)")
        self.sym_RS.setDefaultValue(res)

        # Motor direct axis inductance
        if 'Custom' == default_motor:
            Ld = 0.0
        else:
            Ld = self.inductance_in_henry_get(self.motors[default_motor]['Ld'])

        self.sym_LD = self.component.createFloatSymbol("MCPMSMFOC_LD", self.sym_SELECT_MOTOR)
        self.sym_LD.setLabel("Direct-axis inductance Ld (Henry)")
        self.sym_LD.setDefaultValue(Ld)

        # Motor quadrature axis inductance
        if 'Custom' == default_motor:
            Lq = 0.0
        else:
            Lq = self.inductance_in_henry_get(self.motors[default_motor]['Lq'])

        self.sym_LQ = self.component.createFloatSymbol("MCPMSMFOC_LQ", self.sym_SELECT_MOTOR)
        self.sym_LQ.setLabel("Quadrature-axis inductance Lq (Henry)")
        self.sym_LQ.setDefaultValue(Lq)

        # Motor pole pairs
        if 'Custom' == default_motor:
            pole_pairs = 0
        else:
            pole_pairs = self.numeric_value_get(self.motors[default_motor]['polePairs'])

        self.sym_ZP = self.component.createFloatSymbol("MCPMSMFOC_POLE_PAIRS", self.sym_SELECT_MOTOR)
        self.sym_ZP.setLabel("Pole pairs")
        self.sym_ZP.setDefaultValue(pole_pairs)

        # Motor back emf constant
        if 'Custom' == default_motor:
            Ke = 0.0
        else:
            Ke = self.bemf_const_vpeak_per_krpm_get(self.motors[default_motor]['Ke'])

        self.sym_KE = self.component.createFloatSymbol("MCPMSMFOC_BEMF_CONST", self.sym_SELECT_MOTOR)
        self.sym_KE.setLabel("Back EMF Constant (Vrms/KRPM line-line)")
        self.sym_KE.setDefaultValue(Ke)

        # Motor rated speed
        if 'Custom' == default_motor:
            rated_speed = 0
        else:
            rated_speed = self.speed_in_rpm_get(self.motors[default_motor]['namePlateBaseSpeed'])

        self.sym_N_RATED = self.component.createFloatSymbol("MCPMSMFOC_RATED_SPEED", self.sym_SELECT_MOTOR)
        self.sym_N_RATED.setLabel("Base mechanical speed (RPM)")
        self.sym_N_RATED.setDefaultValue(rated_speed)

        # Motor maximum speed
        if 'Custom' == default_motor:
            max_speed = 0
        else:
            max_speed = self.speed_in_rpm_get(self.motors[default_motor]['namePlateRatedSpeed'])

        self.sym_N_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_SPEED", self.sym_SELECT_MOTOR)
        self.sym_N_MAX.setLabel("Maximum mechanical speed (RPM)")
        self.sym_N_MAX.setDefaultValue(max_speed)

        # Motor maximum current
        if 'Custom' == default_motor:
            i_max = 0
        else:
            i_max = self.numeric_value_get(self.motors[default_motor]['namePlateRatedCurrentContinuous'])

        self.sym_I_MAX = self.component.createFloatSymbol("MCPMSMFOC_MAX_MOTOR_CURRENT", self.sym_SELECT_MOTOR)
        self.sym_I_MAX.setLabel("Rated continuous current (A)")
        self.sym_I_MAX.setDefaultValue(i_max)

        # Motor viscous damping coefficient
        if 'Custom' == default_motor:
            damping_coefficient = 0
        else:
            damping_coefficient = self.numeric_value_get(self.motors[default_motor]['B'])

        self.sym_B = self.component.createFloatSymbol("MCPMSMFOC_VISCOUS_DAMPING", self.sym_SELECT_MOTOR)
        self.sym_B.setLabel("Viscous damping coefficient (N-m /(rad/s))")
        self.sym_B.setDefaultValue(damping_coefficient)

        # Motor frictional constant
        if 'Custom' == default_motor:
            friction_const = 0
        else:
            friction_const = self.numeric_value_get(self.motors[default_motor]['Tf'])

        self.sym_TF = self.component.createFloatSymbol("MCPMSMFOC_FRICTION_TORQUE", self.sym_SELECT_MOTOR)
        self.sym_TF.setLabel("Constant frictional torque (N-m))")
        self.sym_TF.setDefaultValue(friction_const)

        # Motor inertia
        if 'Custom' == default_motor:
            inertia_val = 0
        else:
            inertia_val = self.numeric_value_get(self.motors[default_motor]['Tf'])

        self.sym_J = self.component.createFloatSymbol("MCPMSMFOC_ROTOR_INERTIA", self.sym_SELECT_MOTOR)
        self.sym_J.setLabel("Rotor inertia (N-m /(rad/s^2))")
        self.sym_J.setDefaultValue(inertia_val)

        # Motor inertia
        if 'Custom' == default_motor:
            rated_voltage = 0
        else:
            rated_voltage = self.numeric_value_get(self.motors[default_motor]['rated_voltage'])

        self.sym_RATED_VOLTAGE = self.component.createFloatSymbol("MCPMSMFOC_RATED_VOLTAGE", self.sym_SELECT_MOTOR)
        self.sym_RATED_VOLTAGE.setLabel("Rated voltage (V)")
        self.sym_RATED_VOLTAGE.setDefaultValue(rated_voltage)

        # Initialize callback functions
        self.sym_DEPENDNCIES = self.component.createStringSymbol("MCPMSMFOC_MOTOR_PARAMS", self.sym_SELECT_MOTOR)
        self.sym_DEPENDNCIES.setVisible(False)
        self.sym_DEPENDNCIES.setDependencies( self.motor_parameters_update, ["MCPMSMFOC_MOTOR_SEL"])

        # Saving the new board data
        self.sym_SAVE_CUSTOM_BOARD = self.component.createBooleanSymbol("MCPMSMFOC_CUSTOM_MOTOR_SAVE", self.sym_SELECT_MOTOR)
        self.sym_SAVE_CUSTOM_BOARD.setLabel('Save custom board data')
        self.sym_SAVE_CUSTOM_BOARD.setVisible(False)
        self.sym_SAVE_CUSTOM_BOARD.setDependencies(self.create_custom_motor_file, ['MCPMSMFOC_MOTOR_SEL', 'MCPMSMFOC_CUSTOM_MOTOR_SAVE'])

        self.sym_WARNING = self.component.createStringSymbol("MCPMSMFOC_CUSTOM_MOTOR_WARNING", self.sym_SAVE_CUSTOM_BOARD)
        self.sym_WARNING.setLabel('Warning Status')
        self.sym_WARNING.setDefaultValue('No warnings yet')
        self.sym_WARNING.setVisible(True)

    def create_custom_motor_file(self, symbol, event):
        if event['id'] == 'MCPMSMFOC_MOTOR_SEL':
            if event['symbol'].getValue() == 'Custom':
                symbol.setVisible(True)
            else:
                symbol.setVisible(False)
        elif event['id'] == 'MCPMSMFOC_CUSTOM_MOTOR_SAVE':
            if event['value'] == True:
                # Get file name
                custom_motor_name = self.sym_STORE_CUSTOM_FILE_NAME.getValue()
                if custom_motor_name != '':
                    input_file = os.path.join(Module.getPath(), 'algorithms', 'pmsm_foc', 'motors', 'templates', 'custom_motor.xml.template')

                    prospective_out_file = os.path.join(Module.getPath(), 'algorithms', 'pmsm_foc', 'motors', 'custom-motors', custom_motor_name + '.xml')
                    if os.path.exists(prospective_out_file):
                        self.sym_WARNING.setValue('The motor file already exists. Change motor name and re-enable')
                        return

                    # Parse the XML template file
                    tree = ET.parse(input_file)
                    node = tree.getroot()

                    # Find the tag to update
                    tag = node.find('.//mfrCompanyName')

                    # Update the tag with the new value
                    if tag is not None:
                        tag.text = custom_motor_name
                    else:
                        print("Tag '{}' not found in the XML file.".format(tag))
                        return

                    # Find the tag to update
                    tag = node.find('.//mfrMotorName')

                    # Update the tag with the new value
                    if tag is not None:
                        tag.text =  '-'
                    else:
                        print("Tag '{}' not found in the XML file.".format(tag))
                        return

                    # Find the tag to update
                    tag = node.find('.//mfrPartNumber')

                    # Update the tag with the new value
                    if tag is not None:
                        tag.text =  '-'
                    else:
                        print("Tag '{}' not found in the XML file.".format(tag))
                        return

                    # Find the tag to update
                    tag = node.find('.//mfrAdditionalInfo')

                    # Update the tag with the new value
                    if tag is not None:
                        tag.text =  '-'
                    else:
                        print("Tag '{}' not found in the XML file.".format(tag))
                        return

                    # Find the tag to update
                    tag = node.find('.//mchpDirectPartNumber')

                    # Update the tag with the new value
                    if tag is not None:
                        tag.text = '-'
                    else:
                        print("Tag '{}' not found in the XML file.".format(tag))
                        return

                    # Update nameplate parameters
                    nameplate_dict = {
                        'connection': str(self.sym_POLARITY.getValue()),
                        'namePlateRatedCurrentContinuous': str(self.sym_I_MAX.getValue()) + ' ' + 'A',
                        'namePlateRatedPeakCurrent': str(self.sym_I_MAX.getValue()) + ' ' + 'A',
                        'namePlateRatedVoltage': str(self.sym_RATED_VOLTAGE.getValue()) + ' ' + 'V',
                        'namePlateBaseSpeed':  str(self.sym_N_RATED.getValue()) + ' ' + 'rad/s',
                        'namePlateRatedSpeed': str(self.sym_N_MAX.getValue()) + ' ' + 'rad/s',
                    }

                    nameplate_parameters = node.find('.//nameplate')
                    if nameplate_parameters is not None:
                        for param_id, param_value in nameplate_dict.items():
                            active_element = nameplate_parameters.find("./{}".format(param_id))
                            if active_element is not None:
                                active_element.text = str(param_value)
                            else:
                                print("active tag not found under {}".format(param_id))
                    else:
                        print("<nameplate Parameters> not found in the XML file.")

                    # Update sensor parameters
                    # Update others parameters
                    other_params_dict = {
                        'fullscaleBaseRatio':str(0.0) + ' ' + 'one',
                        'polePairs': str(self.sym_ZP.getValue()) + ' ' + 'one',
                    }
                    other_parameters = node.find('.//other')
                    if other_parameters is not None:
                        for param_id, param_value in other_params_dict.items():
                            active_element = other_parameters.find("./{}".format(param_id))
                            if active_element is not None:
                                active_element.text = str(param_value)
                            else:
                                print("active tag not found under {}".format(param_id))
                    else:
                        print("<other Parameters> not found in the XML file.")

                    # Update motor parameters
                    motor_parameters_dict = {
                        'Rs': str(self.sym_RS.getValue()) + ' ' + 'Ohm',
                        'Ld': str(self.sym_LD.getValue()) + ' ' + 'H',
                        'Lq': str(self.sym_LQ.getValue()) + ' ' + 'H',
                        'Ke': str(self.sym_KE.getValue()) + ' ' + 'V/rad/s',
                        'B':  str(self.sym_B.getValue()) + ' ' + 'one',
                        'Tf': str(self.sym_TF.getValue()) + ' ' + 'one',
                        'J':  str(self.sym_J.getValue()) + ' ' + 'one',
                    }

                    motor_parameters = node.find('.//motorParameters')
                    if motor_parameters is not None:
                        for param_id, param_value in motor_parameters_dict.items():
                            active_element = motor_parameters.find("./{}/active".format(param_id))
                            if active_element is not None:
                                active_element.text = str(param_value)
                            else:
                                print("active tag not found under {}".format(param_id))
                    else:
                        print("<motorParameters> not found in the XML file.")

                    # Generate output filename based on current timestamp
                    output_file = os.path.join(Module.getPath(), 'algorithms', 'pmsm_foc', 'motors', 'custom-motors', custom_motor_name + ".xml")

                    # Write the modified XML to the output file
                    tree.write(output_file, encoding="utf-8", xml_declaration=True)
                    print("Output file '{}' created successfully.".format(output_file))

    def make_symbol_visible(self, symbol, event):
        if event["symbol"].getValue() == 'Custom':
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def motor_parameters_update( self, symbol, event ):
        selected_motor = event["symbol"].getValue()
        if selected_motor != 'Custom':
            self.sym_RS.setValue(self.resistance_in_ohms_get(self.motors[selected_motor]['Rs']))
            self.sym_LD.setValue(self.inductance_in_henry_get(self.motors[selected_motor]['Ld']))
            self.sym_LQ.setValue(self.inductance_in_henry_get(self.motors[selected_motor]['Lq']))
            self.sym_KE.setValue(self.bemf_const_vpeak_per_krpm_get(self.motors[selected_motor]['Ke']))
            self.sym_ZP.setValue(self.numeric_value_get(self.motors[selected_motor]['polePairs']))
            self.sym_N_RATED.setValue(self.speed_in_rpm_get(self.motors[selected_motor]['namePlateBaseSpeed']))
            self.sym_N_MAX.setValue(self.speed_in_rpm_get(self.motors[selected_motor]['namePlateRatedSpeed']))
            self.sym_I_MAX.setValue(self.numeric_value_get(self.motors[selected_motor]['namePlateRatedCurrentContinuous']))
            self.sym_B.setValue(self.speed_in_rpm_get(self.motors[selected_motor]['B']))
            self.sym_TF.setValue(self.numeric_value_get(self.motors[selected_motor]['Tf']))
            self.sym_J.setValue(self.numeric_value_get(self.motors[selected_motor]['J']))
            self.sym_RATED_VOLTAGE.setValue(self.numeric_value_get(self.motors[selected_motor]['namePlateRatedVoltage']))
            try:
                self.sym_POLARITY.setSelectedKey(self.motors[selected_motor]['connection'])
            except:
                print("Warning: The connection type is not indicated in the file", selected_motor)

            # Update sensor parameters
            if 'optical_encoder' in self.motors[selected_motor].keys():
                encoder_count_per_rot = self.numeric_value_get(self.motors[selected_motor]['optical_encoder']['pulse_per_rotation'])
                Database.setSymbolValue('pmsm_foc', "MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", int(encoder_count_per_rot))
        else:
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

    def __call__( self ):

        # Create MHC symbols for Motor parameters
        self.create_symbols()



