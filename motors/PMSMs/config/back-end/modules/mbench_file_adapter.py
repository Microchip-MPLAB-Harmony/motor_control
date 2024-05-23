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
#                        SUPPORTED MOTOR PARAMETERS                                #
#----------------------------------------------------------------------------------#
import xml.etree.ElementTree as ET
class MotorBenchFileAdapter:
    def __init__(self):
        pass

    def get_first_element(self, input_xml_file):
        # Read XML content from file
        with open(input_xml_file, 'r') as file:
            xml_content = file.read()

        # Parse XML content
        root = ET.fromstring(xml_content)

        # Return the first child element
        return next(root.iter())

    def adapter_service(self, input_xml_file ):
        yaml_data = {}
        try:
            # Parse the XML file
            tree = ET.parse(input_xml_file)
            root = tree.getroot()

            # Find the first motor state tag
            motor_state = self.get_first_element(input_xml_file)
            motor_parameters = root.find('motorParameters')

            if motor_state is None or motor_parameters is None:
                print("Warning: Motor state or parameters not found in {}".format(input_xml_file))
                return

            meta_data = {
                'creator': 'Harmony QSpin',
                'microchip_name': motor_state.findtext('.//handle', default=''),
                'manufacturer_name': motor_state.findtext('.//mfrCompanyName', default=''),
                'manufacturer_motor_name': motor_state.findtext('.//mfrMotorName', default=''),
                'manufacturer_part_no': motor_state.findtext('.//mfrPartNumber', default='')
            }

            # Convert speed to rpm
            pole_pairs = int(float(motor_state.findtext('.//other/polePairs', default='0 one').split()[0]))
            nominal_rpm = float(motor_state.findtext('.//nameplate/namePlateBaseSpeed', default='0 rad/s').split()[0])
            nominal_rpm = nominal_rpm * 30/ ( pole_pairs * math.pi )
            maximum_rpm = float(motor_state.findtext('.//nameplate/namePlateRatedSpeed', default='0 rad/s').split()[0])
            maximum_rpm = maximum_rpm * 30/ ( pole_pairs * math.pi )

            name_plate_parameters = {
                'connection_type': motor_state.findtext('.//nameplate/connection', default='').strip("'"),
                'pole_pairs': int(float(motor_state.findtext('.//other/polePairs', default='0 one').split()[0])),
                'velocity': {
                    'nominal': float(motor_state.findtext('.//nameplate/namePlateBaseSpeed', default='0 rad/s').split()[0]),
                    'maximum': float(motor_state.findtext('.//nameplate/namePlateRatedSpeed', default='0 rad/s').split()[0])
                },
                'current': {
                    'maximum': {
                        'continuous': float(motor_state.findtext('.//nameplate/namePlateRatedCurrentContinuous', default='0 A').split()[0])
                    }
                },
                'voltage': {
                    'nominal': float(motor_state.findtext('.//nameplate/namePlateRatedVoltage', default='24 V').split()[0])
                }
            }

            # Convert Ke from V-s/ rad   to   V(line-line)/ kRPM
            ke = float(motor_parameters.findtext('.//Ke/active', default='0 V/rad/s').split()[0])
            ke_in_vll_per_krpm = ke/0.007797
            electrical_parameters = {
                'R': float(motor_parameters.findtext('.//Rs/active', default='0 Ω').split()[0]),
                'Lq': float(motor_parameters.findtext('.//Lq/active', default='0 H').split()[0]),
                'Ld': float(motor_parameters.findtext('.//Ld/active', default='0 H').split()[0]),
                'L': (float(motor_parameters.findtext('.//Ld/active', default='0 H').split()[0]) +
                      float(motor_parameters.findtext('.//Lq/active', default='0 H').split()[0])) / 2,
                'Ke': ke_in_vll_per_krpm
            }

            mechanical_parameters = {
                'J': float(motor_parameters.findtext('.//J/active', default='0 one').split()[0]),
                'B': float(motor_parameters.findtext('.//B/active', default='0 one').split()[0]),
                'Tfr': float(motor_parameters.findtext('.//Tf/active', default='0 one').split()[0])
            }

            yaml_data = {
                'motor': {
                    'meta_data': meta_data,
                    'parameters': {
                        'name_plate_parameters': name_plate_parameters,
                        'electrical_parameters': electrical_parameters,
                        'mechanical_parameters': mechanical_parameters
                    }
                }
            }

            # Write the extracted information to the YAML file
            # with open(output_yaml_file, 'w') as file:
                # yaml.dump(yaml_data, file, default_flow_style=False)
            # print("Output YAML file '{}' created successfully.".format(output_yaml_file))

        except Exception as e:
            print("Warning: Motor file cannot be parsed: {}, Error: {}".format(input_xml_file, e))

        return yaml_data