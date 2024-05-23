
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

# Get the directory path
dir_path = os.path.join(Module.getPath(), "config", "back-end", "modules")

# Iterate through files in the directory
for filename in os.listdir(dir_path):
    if filename.endswith(".py"):
        # Execute the Python file
        execfile(os.path.join(dir_path, filename))

"""
Execute all Python files for device abstraction
"""
# Get the directory path
dir_path = os.path.join(Module.getPath(), "..", "device_abstraction")

# Iterate through files in the directory
for filename in os.listdir(dir_path):
    if filename.endswith(".py"):
        # Execute the Python file
        execfile(os.path.join(dir_path, filename))

#=========================================================================================================#
#                                       PMSM FOC COMPONENT                                                #
#=========================================================================================================#
def instantiateComponent(component):
    global pin_manager
    pin_manager = mcBspI_PinManager(component)
    pin_manager()

    # global board_Information
    # board_Information = mcBspI_ReadBoardInformation(component)
    # board_Information()

    global analog_Interface
    analog_Interface = mcBspI_AnalogInterfaceClass(component)
    analog_Interface()

    global digital_Interface
    digital_Interface = mcBspI_DigitalInterfaceClass(component)
    digital_Interface()

    global pwm_Interface
    pwm_Interface = mcBspI_PwmInterfaceClass(component)
    pwm_Interface()

    global position_Interface
    position_Interface = mcBspI_PositionInterfaceClass(component)
    position_Interface()

    global data_monitoring
    data_monitoring = mcBspI_DataMonitorClass(component)
    data_monitoring()

def handleMessage(id, args):
    analog_Interface.handleMessage(id, args)
    digital_Interface.handleMessage(id, args)
    pwm_Interface.handleMessage(id, args)
    position_Interface.handleMessage(id, args)
    data_monitoring.handleMessage(id, args)
