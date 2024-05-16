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

# Package imports
import os
import sys


"""
Execute all Python files in the given directory.
"""
# Get the directory path
dir_path = os.path.join(Module.getPath(), "algorithms", "pmsm_foc", "config", "floating_point")

# Iterate through files in the directory
for filename in os.listdir(dir_path):
    if filename.endswith(".py"):
        # Execute the Python file
        execfile(os.path.join(dir_path, filename))

"""
Execute all Python files for device abstraction
"""
# Get the directory path
dir_path = os.path.join(Module.getPath(), "device_abstraction")

# Iterate through files in the directory
for filename in os.listdir(dir_path):
    if filename.endswith(".py"):
        # Execute the Python file
        execfile(os.path.join(dir_path, filename))

"""
Description:
This function instantiates the PMSM FOC Component

"""
def instantiateComponent(mcPmsmFocComponent):

    Log.writeInfoMessage("Running PMSM FOC")

    module_root = Variables.get("__MODULE_ROOT")
    utils_path = os.path.join( module_root, 'libs')
    sys.path.insert(0, utils_path)

    import yaml

    mcPmsmFocInstanceName = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_INSTANCE_NAME", None)
    mcPmsmFocInstanceName.setVisible(False)
    mcPmsmFocInstanceName.setDefaultValue(mcPmsmFocComponent.getID().upper())

    global pin_manager
    pin_manager = mcPmaI_PinManagementClass(mcPmsmFocComponent)
    pin_manager()

    global dev_board
    dev_board = mcBrdI_BoardClass(mcPmsmFocComponent)
    dev_board()

    global default_blocks
    default_blocks = mcSysI_SystemClass(mcPmsmFocComponent)
    default_blocks()

    global voltage_Source
    voltage_Source = mcSrcI_VoltageSourceClass(mcPmsmFocComponent)
    voltage_Source()

    global analog_Frontend
    analog_Frontend = mcAnf_AnalogFrontEndClass(mcPmsmFocComponent)
    analog_Frontend()

    motor_Parameter = mcMotI_MotorParametersClass(mcPmsmFocComponent)
    motor_Parameter()

    global digital_Interface
    digital_Interface = mcFocI_DigitalInterfaceClass(mcPmsmFocComponent, pin_manager)
    digital_Interface()

    global analog_Interface
    analog_Interface = mcAniI_AnalogInterfaceClass(mcPmsmFocComponent, pin_manager)
    analog_Interface()

    global position_Interface
    position_Interface = mcFocI_PositionInterfaceClass(mcPmsmFocComponent, pin_manager)
    position_Interface()

    global pwm_Interface
    pwm_Interface = mcPwmI_PwmInterfaceClass(mcPmsmFocComponent, pin_manager)
    pwm_Interface()


    # global event_System
    # event_System = mcEvtI_EventSystemClass(mcPmsmFocComponent)
    # event_System()

    global data_Monitoring
    data_Monitoring = mcFocI_DataMonitoringClass(mcPmsmFocComponent, pin_manager)
    data_Monitoring()

    startup_Configurator = mcSupI_StartupConfigurator(mcPmsmFocComponent)
    startup_Configurator()

    motor_Control = mcMocI_MotorControlAndDiagnosis(mcPmsmFocComponent)
    motor_Control.createSymbols()

    position_Calculation = mcRpoI_PositionCalculationAndDiagnosis(mcPmsmFocComponent)
    position_Calculation.createSymbols()

    output_Stage = mcOstI_OutputStageAndDiagnosis(mcPmsmFocComponent)
    output_Stage()

    current_Measurement = mcCurI_CurrentMeasurementAndDiagnosis(mcPmsmFocComponent)
    current_Measurement()

    voltage_Measurement = mcVolI_VoltageMeasurementAndDiagnosis(mcPmsmFocComponent)
    voltage_Measurement()


    mcGen_GenerateCode(mcPmsmFocComponent)



"""
Description:
This function performs tasks when the corresponding modules are connected

"""
def onAttachmentConnected( source, target ):
    # ADC Peripheral
    analog_Interface.onAttachmentConnected( source, target )

    # PWM Peripheral
    pwm_Interface.onAttachmentConnected( source, target )

    # # Event system
    # event_System.onAttachmentConnected(source, target)

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

    # # Event system
    # event_System.onAttachmentDisconnected(source, target)

    # QEI Peripheral
    position_Interface.onAttachmentDisconnected( source, target )

    # X2C Scope
    data_Monitoring.onAttachmentDisconnected( source, target )

"""
Description:
This function handles the messages from other Harmony component

"""
def handleMessage( ID, message):

    # Develpment boards
    dev_board.handleMessage( ID, message)

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
    if(( ID == "X2CSCOPE_DATA_MONITORING") or ( ID == "BSP_DATA_MONITORING")):
        return data_Monitoring.handleMessage( ID, message )


"""
Description:
This function is called after the PMSM FOC Component is instantiated

"""
def finalizeComponent(mcPmsmFocComponent):
    # Activate and connect the default PWM peripheral
    module = str( Database.getSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_BSP_ID"))
    autoConnectTable = [ module]
    res = Database.activateComponents(autoConnectTable)


    value = Database.getSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_FOC_X2C_ENABLE")
    Database.setSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_FOC_X2C_ENABLE", value)    
    
    # Set default algorithms
    value = Database.getSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_POSITION_CALC_ALGORITHM")
    Database.setSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_POSITION_CALC_ALGORITHM", value)

    # Set default motor
    value = Database.getSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_MOTOR_SEL")
    Database.setSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_MOTOR_SEL", value)

    # Set default board
    value = Database.getSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_BOARD_SEL")
    Database.setSymbolValue(mcPmsmFocComponent.getID(), "MCPMSMFOC_BOARD_SEL", value)

    Database.sendMessage("bsp", "MCPMSMFOC_READ_BOARD_INFORMATION", {})
