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
from device.gpio import pin_manager

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                 Classes                                               #
#---------------------------------------------------------------------------------------#

class AdapterService:
    """
        This function shall read QDEC IP data from device files and convert to following uniform format.
        QDEC:
        {
        'qdec_interface': {
                            'instance': {
                                            'channel': {
                                                           'qea': [ pad list for high channels],
                                                           'qeb': [ pad list for low channels],
                                                           'idx': [ pad list for low channels]
                                                        }

                                        }
                            }
        }
    """
    def __init__(self, object_wrapper):
        self.object_wrapper = object_wrapper

        self.qdec_data = {
                            'qdec_interface': {}
                         }
        self.adapter()

    def adapter(self):
        # Define the module path in the ATDF file
        module_path = "/avr-tools-device-file/devices/device/peripherals/module@[name=\"PDEC\"]"

        # Get all modules related to PDEC
        ATDF = self.object_wrapper.get_atdf_object()

        modules = ATDF.getNode(module_path).getChildren()

        # Iterate through the modules
        qdec_interface = {}
        for module in modules:
            instance = module.getAttribute("name")

            # Define the channel path for the current module
            channel_path = module_path + "/instance@[name=\"" + instance + "\"]/signals"

            # Get all channels for the current module
            channels = ATDF.getNode(channel_path).getChildren()

            # Initialize a sub-dictionary for the current instance
            qdec_interface[instance] = {}

            # Iterate through the channels
            for channel in channels:
                pad = channel.getAttribute("pad")
                index = channel.getAttribute("index")

                # Append the pad to the appropriate list based on the index
                if index == "0":
                    if index not in qdec_interface[instance]:
                        qdec_interface[instance][index] = {'qea':[], 'qeb':[], 'idx': []}
                    qdec_interface[instance][index]["qea"].append(pad)
                elif index == "1":
                    if index not in qdec_interface[instance]:
                        qdec_interface[instance][index] = {'qea':[], 'qeb':[], 'idx': []}
                    qdec_interface[instance][index]["qeb"].append(pad)
                elif index == "2":
                    if index not in qdec_interface[instance]:
                        qdec_interface[instance][index] = {'qea':[], 'qeb':[], 'idx': []}
                    qdec_interface[instance][index]["idx"].append(pad)

            self.qdec_data['qdec_interface'] = qdec_interface

    def get_qdec_data(self):
        return self.qdec_data

    def set_qdec_pin(self, name, instance, channel, qea_pad, qeb_pad ):
        pin_manager_module = pin_manager.PinManager(self.object_wrapper)

        mode = instance + "_QDI0"
        pin_manager_module.configurePin( qea_pad, name + "_QEA", mode)

        mode = instance + "_QDI1"
        pin_manager_module.configurePin( qeb_pad, name + "_QEB", mode)