# coding: utf-8
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

import os

MCU =  ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")

#  Get scripts path 
scriptLocation =  os.path.join(Module.getPath(), "algorithms", "pmsm_foc", "config", "floating_point")

# General Purpose function classes
execfile(os.path.join( scriptLocation, "general_functions.py" ))

# Hardware block Classes
execfile(os.path.join( scriptLocation, "voltage_source.py" ))
execfile(os.path.join( scriptLocation, "analog_frontend.py" ))
execfile(os.path.join( scriptLocation, "motor_parameters.py" ))

# Peripherals block classes
execfile(os.path.join( scriptLocation, "pwm_interface.py" ))
execfile(os.path.join( scriptLocation, "digital_interface.py" ))
execfile(os.path.join( scriptLocation, "analog_interface.py" ))
execfile(os.path.join( scriptLocation, "position_interface.py" ))

# Software module classes 
execfile(os.path.join( scriptLocation, "startup_configurator.py" ))
execfile(os.path.join( scriptLocation, "motor_control_and_diagnosis.py" ))
execfile(os.path.join( scriptLocation, "position_calculation_and_diagnosis.py" ))
execfile(os.path.join( scriptLocation, "output_stage_and_diagnosis.py" ))
execfile(os.path.join( scriptLocation, "current_measurement_and_diagnosis.py" ))
execfile(os.path.join( scriptLocation, "voltage_measurement_and_diagnosis.py" ))

# Data monitoring class
execfile(os.path.join( scriptLocation, "data_monitoring.py" ))

# Event system 
execfile(os.path.join( scriptLocation, "event_system_configuration.py" ))

# Code generation
execfile(os.path.join(scriptLocation, "code_generation.py" ))



#=========================================================================================================#
#                                       CALLBACK FUCNTIONS                                                #
#=========================================================================================================#

def mcPmsmFocSpeedRefVisible(symbol, event):
    component = symbol.getComponent()
    if component.getSymbolValue("MCPMSMFOC_SPEED_REF") == "Potentiometer Analog Input":
        symbol.setVisible(False)
    else:
        symbol.setVisible(True)
    symbol.setMax(component.getSymbolValue("MCPMSMFOC_RATED_SPEED"))




#=========================================================================================================#
#                                       PMSM FOC COMPONENT                                                #
#=========================================================================================================#
"""
Description:
This function instantiates the PMSM FOC Component

"""
def instantiateComponent(mcPmsmFocComponent): 
    
    Log.writeInfoMessage("Running PMSM FOC")

    mcPmsmFocInstanceName = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_INSTANCE_NAME", None)
    mcPmsmFocInstanceName.setVisible(False)
    mcPmsmFocInstanceName.setDefaultValue(mcPmsmFocComponent.getID().upper())
    
    
    #-----------------------------------------------------------------------------------------------------#
    #                                 DEVELOPER MODE                                                                #
    #-----------------------------------------------------------------------------------------------------#  
    sym_BOARD_NODE = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_DEVELOPER_MODE", None)
    sym_BOARD_NODE.setLabel("Enable developer mode")
    sym_BOARD_NODE.setVisible(True)
 
    #-----------------------------------------------------------------------------------------------------#
    #                                 BOARD SELECTION                                                              #
    #-----------------------------------------------------------------------------------------------------#    
    sym_BOARD_NODE = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_BOARD_CONF", None)
    sym_BOARD_NODE.setLabel("Board Configuration")
    sym_BOARD_NODE.setVisible(True)


    global sym_SELECTED_BOARD
    sym_SELECTED_BOARD = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_BOARD_SEL", sym_BOARD_NODE )
    sym_SELECTED_BOARD.setLabel("Development board")
    sym_SELECTED_BOARD.addKey("dsPICDEM MCLV-2", "0", "dsPICDEM MCLV-2")
    sym_SELECTED_BOARD.addKey("dsPICDEM MCHV-3", "1", "dsPICDEM MCHV-3")
    sym_SELECTED_BOARD.addKey("CUSTOM", "2", "Custom")
    sym_SELECTED_BOARD.setOutputMode("Key")
    sym_SELECTED_BOARD.setDisplayMode("Description")
    sym_SELECTED_BOARD.setDefaultValue(0)
    sym_SELECTED_BOARD.setDependencies( mcPmsmFoc_SelectBoard, ["MCPMSMFOC_BOARD_SEL"])
 
    information = Database.sendMessage("bsp", "MCBSP_READ_BOARD_DATA", {})

    #-----------------------------------------------------------------------------------------------------#
    #                                 Hardware blocks                                                     #
    #-----------------------------------------------------------------------------------------------------# 
    global voltage_Source
    voltage_Source = mcSrcI_VoltageSourceClass("Algorithm", mcPmsmFocComponent)
    voltage_Source()


    global analog_Frontend
    analog_Frontend = mcAnf_AnalogFrontEndClass("Algorithm", mcPmsmFocComponent)
    analog_Frontend()

    motor_Parameter = mcMotI_MotorParametersClass("Algorithm", mcPmsmFocComponent)
    motor_Parameter()

    global digital_Interface
    digital_Interface = mcFocI_DigitalInterfaceClass("Algorithm", mcPmsmFocComponent)
    digital_Interface()

    global analog_Interface
    analog_Interface = mcAniI_AnalogInterfaceClass("Algorithm", mcPmsmFocComponent)
    analog_Interface()

    global position_Interface
    position_Interface = mcFocI_PositionInterfaceClass("Algorithm", mcPmsmFocComponent)
    position_Interface()

    global pwm_Interface
    pwm_Interface = mcPwmI_PwmInterfaceClass("Algorithm", mcPmsmFocComponent)
    pwm_Interface()

    global event_System
    event_System = mcEvtI_EventSystemClass()
    event_System()

    global data_Monitoring
    data_Monitoring = mcFocI_DataMonitoringClass("Algorithm", mcPmsmFocComponent)
    data_Monitoring()    

    #-----------------------------------------------------------------------------------------------------#
    #                                 Control blocks                                                      #
    #-----------------------------------------------------------------------------------------------------# 
    startup_Configurator = mcSupI_StartupConfigurator("Algorithm", mcPmsmFocComponent)
    startup_Configurator()

    motor_Control = mcMocI_MotorControlAndDiagnosis("Algorithm", mcPmsmFocComponent)
    motor_Control.createSymbols()

    position_Calculation = mcRpoI_PositionCalculationAndDiagnosis("Algorithm", mcPmsmFocComponent)
    position_Calculation.createSymbols()

    output_Stage = mcOstI_OutputStageAndDiagnosis("Algorithm", mcPmsmFocComponent)
    output_Stage()

    current_Measurement = mcCurI_CurrentMeasurementAndDiagnosis("Algorithm", mcPmsmFocComponent)
    current_Measurement()

    voltage_Measurement = mcVolI_VoltageMeasurementAndDiagnosis("Algorithm", mcPmsmFocComponent)
    voltage_Measurement()

    #-----------------------------------------------------------------------------------------------------#
    #                                 Code generation                                                      #
    #-----------------------------------------------------------------------------------------------------# 
    mcGen_GenerateCode(mcPmsmFocComponent)


#=========================================================================================================#
#                                         CALLBACK FUNCTIONS                                              #
#=========================================================================================================# 
"""
Description:
This function shall be called when the selected board is changed

"""
def mcPmsmFoc_SelectBoard( symbol, event):
    message = dict()
    message["SELECTED_BOARD"] = symbol.getSelectedKey()
    Database.sendMessage("bsp", "MCPMSMFOC_SELECTED_BOARD", message )

"""
Description:
This function performs tasks when the corresponding modules are connected 

"""
def onAttachmentConnected( source, target ):
    # ADC Peripheral 
    analog_Interface.onAttachmentConnected( source, target )

    # PWM Peripheral
    pwm_Interface.onAttachmentConnected( source, target )

    # Event system 
    event_System.onAttachmentConnected(source, target)

    # QEI Peripheral
    position_Interface.onAttachmentConnected( source, target )

    # X2C Scope 
    data_Monitoring.onAttachmentConnected( source, target )

    
"""
Description:
This function performs tasks when the corresponding modules are disconnected 

"""
def onAttachmentDisconnected( source, target ):
    # ADC Peripheral
    analog_Interface.onAttachmentDisconnected( source, target )

    # PWM Peripheral 
    pwm_Interface.onAttachmentDisconnected( source, target )

    # Event system 
    event_System.onAttachmentDisconnected(source, target)

    # QEI Peripheral
    position_Interface.onAttachmentDisconnected( source, target )

    # X2C Scope 
    data_Monitoring.onAttachmentDisconnected( source, target )

#=========================================================================================================#
#                                         MESSAGE HANDLING                                                #
#=========================================================================================================#
def handleMessage( ID, message):

    if "MCBSP_SEND_BOARD_DATA" == ID:
        if "dsPICDEM MCLV-2" == message["NAME"]:
            sym_SELECTED_BOARD.setSelectedKey("MCLV2")
        elif "dsPICDEM MCHV-3" == message["NAME"]:
            sym_SELECTED_BOARD.setSelectedKey("MCHV3")
        else:
            sym_SELECTED_BOARD.setSelectedKey("CUSTOM")
    
    # Voltage source
    voltage_Source.handleMessage( ID, message )
    
    # Analog front end
    analog_Frontend.handleMessage( ID, message )

    # ADC Peripheral
    analog_Interface.handleMessage( ID, message )

    # ADC Peripheral
    digital_Interface.handleMessage( ID, message )

    # PWM Peripheral 
    pwm_Interface.handleMessage( ID, message )

    # QEI Peripheral
    position_Interface.handleMessage( ID, message )

    # X2C Scope 
    data_Monitoring.handleMessage( ID, message )
    
  