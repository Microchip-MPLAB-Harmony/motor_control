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
#                                 Imports                                               #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                Global Variables                                       #
#---------------------------------------------------------------------------------------#
autoConnectTable = []

#---------------------------------------------------------------------------------------#
#                                 Suppoted IPs                                          #
#---------------------------------------------------------------------------------------#
SupportedEVSYSIps = {
    "EVSYS" : [
                 { "name": "EVSYS", "id": "U2504"},
                 { "name": "EVSYS", "id": "U2256"}
              ]
}

def getEVSYSIP(modules):
    for module in modules:
        for entry in SupportedEVSYSIps.get("EVSYS", []):
            if ( entry["name"] == module.getAttribute("name") and entry["id"] == module.getAttribute("id") ):
                return entry["name"], entry["id"]
    return "",""

#---------------------------------------------------------------------------------------#
#                               Global Variables                                        #
#---------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------#
#                                     Class                                             #
#---------------------------------------------------------------------------------------#
class mcEvtI_EventSystemClass:
    def __init__(self, component ):
        self.component = component

        # Get ADC IP from the ATDF file
        periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
        modules = periphNode.getChildren()

        self.name, self.id = getEVSYSIP(modules)

        # Create a symbol for ADC IP
        self.IP  = self.component.createStringSymbol("MCPMSMFOC_EVSYS_IP", None )
        self.IP.setLabel("EVSYS IP")

        self.IP.setVisible(False)
        self.IP.setValue( self.name + "_" + self.id)


        self.eic_channel = ""
        self.eic_eo_symbol = ""
        self.eic_config_sense = ""


    def createSymbols( self ):
        pass

    def setConfiguration(self, fault_source):
        if ( self.name == "EVSYS" ) and (( self.id == "U2504") or ( self.id == "U2256" )):
            pwmInstance = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_INSTANCE")
            adcInstance = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PHASE_CURRENT_IA_UNIT")
            eic = filter(str.isdigit, str( fault_source))
            generator0 = generator1 = user0 = user1 = 0

            if( fault_source != "** Not Selected **"):
                if "eic" not in Database.getActiveComponentIDs():
                    # Activate EIC component
                    res = Database.activateComponents(["eic"])
                else:
                    res = True

            if res == True:
                # Disable old EIC channels
                Database.setSymbolValue("eic", self.eic_channel, False)
                Database.setSymbolValue("eic", self.eic_eo_symbol, False)
                Database.setSymbolValue("eic", self.eic_config_sense, 0)

                # Enable the EIC channel
                self.eic_channel = "EIC_CHAN_" + eic
                Database.setSymbolValue("eic", self.eic_channel, True)

                # Enable event output
                self.eic_eo_symbol = "EIC_EXTINTEO_" + eic
                Database.setSymbolValue("eic", self.eic_eo_symbol, True)

                #
                self.eic_config_sense = "EIC_CONFIG_SENSE_" + eic
                Database.setSymbolValue("eic", self.eic_config_sense, 2)

            else:
                print("EIC Component could not be activated")


            if (pwmInstance != "NONE") and (adcInstance != "NONE"):
                #EVSYS channel 0 = TCC overflow to ADC Start
                #EVSYS channel 1 = EIC fault pin to TCC event 1 fault
                Database.setSymbolValue("evsys", "EVSYS_CHANNEL_0", True)
                Database.setSymbolValue("evsys", "EVSYS_CHANNEL_1", True)
                Database.setSymbolValue("evsys", "EVSYS_CHANNEL_0_EDGE", 1)
                Database.setSymbolValue("evsys", "EVSYS_CHANNEL_1_EDGE", 1)

                #Find event GENERATOR numbers from ATDF
                node = ATDF.getNode("/avr-tools-device-file/devices/device/events/generators")
                generators = []
                sortedGenerators = []

                for id in range(0, len(node.getChildren())):
                    generators.append(id)
                    generators[id] = node.getChildren()[id].getAttribute("name")

                sortedGenerators = sorted(generators)


                for id in range(0, len(sortedGenerators)):
                    if str(pwmInstance) + "_OVF" == sortedGenerators[id]:
                        generator0 = int(id)
                    if "EIC_EXTINT_" + str(eic) == sortedGenerators[id]:
                        generator1 = int(id)


                #Find event USER numbers from ATDF
                node = ATDF.getNode("/avr-tools-device-file/devices/device/events/users")
                users = []

                for id in range(0, len(node.getChildren())):
                    users.append(id)
                    users[id] = node.getChildren()[id].getAttribute("name")
                for id in range(0, len(node.getChildren())):
                    if str(adcInstance) + "_START" in users[id]:
                        user0 = int(node.getChildren()[id].getAttribute("index"))
                    if str(pwmInstance) + "_EV_1" in users[id]:
                        user1 = int(node.getChildren()[id].getAttribute("index"))

                Database.setSymbolValue("evsys", "EVSYS_CHANNEL_0_GENERATOR", int(generator0))
                Database.setSymbolValue("evsys", "EVSYS_CHANNEL_1_GENERATOR", int(generator1))
                Database.setSymbolValue("evsys", "EVSYS_USER_" + str(user0), 1)
                Database.setSymbolValue("evsys", "EVSYS_USER_" + str(user1), 2)


    def updatePLIB(self, symbol, event):
        pass

    def onAttachmentConnected(self, source, target):
        pass

    """
    Description:
    This function performs tasks on ADC modules de-attachment

    """
    def onAttachmentDisconnected( self, source, target):
        pass

    def __call__(self):
        self.createSymbols()







