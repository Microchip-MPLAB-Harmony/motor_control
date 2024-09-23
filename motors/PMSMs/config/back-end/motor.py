
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
import sys

"""
Add library to system path
"""
module_root = Variables.get("__MODULE_ROOT")
utils_path = os.path.join( module_root, '..' , '..', 'libs')
sys.path.insert(0, utils_path)

# Get the directory path
dir_path = os.path.join(Module.getPath(), "config", "back-end", "modules")

# Iterate through files in the directory
for filename in os.listdir(dir_path):
    if filename.endswith(".py"):
        # Execute the Python file
        execfile(os.path.join(dir_path, filename))

#=========================================================================================================#
#                                       PMSM FOC COMPONENT                                                #
#=========================================================================================================#
def instantiateComponent(component):
    global motor_class
    motor_class = mcMotI_MotorParametersClass(component)
    motor_class()

def handleMessage(message_id, args):
    return motor_class.handle_message( message_id, args)

