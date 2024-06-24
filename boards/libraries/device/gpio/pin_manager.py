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
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class PinManager:
    def __init__(self, object_wrapper):

        self.atdf = object_wrapper.get_atdf_object()
        self.database = object_wrapper.get_database_object()

        # Get pin package details
        packageName = str(self.database.getSymbolValue("core", "COMPONENT_PACKAGE"))

        pinout = ""
        children = (self.atdf.getNode("/avr-tools-device-file/variants")).getChildren()
        for index in range(0, len(children)):
            if packageName in children[index].getAttribute("package"):
                pinout = children[index].getAttribute("pinout")

        self.architecture = self.atdf.getNode("/avr-tools-device-file/devices/device").getAttribute("architecture")

        pins = self.atdf.getNode("/avr-tools-device-file/pinouts/pinout@[name=\"" + pinout + "\"]").getChildren()
        self.pad_to_pin_map = {}
        for pin in pins:
            self.pad_to_pin_map[pin.getAttribute("pad")] = str(pin.getAttribute("position"))

    def setDatabaseSymbol(self, component, id, value ):
        status =  self.database.setSymbolValue(component, id, value)
        if(status == False ):
            print("BSP is unable to set {symbol} with {input}".format(symbol = id, input = value))
        return status

    def getDatabaseSymbol(self, component, id):
        value = self.database.getSymbolValue(component, id)
        return value

    def configureButton(self, pad, name, mode):
        if pad != "** Select **":
            # Iterate and check
            for pin in self.pad_to_pin_map.values():
                if (    name == self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME")
                    and mode == self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE")
                ):

                    # Un-assign pin
                    self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE", "" )
                    self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME", "" )

            # Check the pin status
            pin = self.pad_to_pin_map[pad]
            old_name = self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME")
            old_mode = self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE")

            if old_name == "" and old_mode == "":
                self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME", name )
                self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE", mode )
                self.setDatabaseSymbol("core", "PIN_" + pin + "_INEN", "True")

    def configureLed(self, pad, name, mode):
        if pad != "** Select **":
            # Iterate and check
            for pin in self.pad_to_pin_map.values():
                if (    name == self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME")
                    and mode == self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE")
                ):

                    # Un-assign pin
                    self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE", "" )
                    self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME", "" )

            # Check the pin status
            pin = self.pad_to_pin_map[pad]
            old_name = self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME")
            old_mode = self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE")

            if old_name == "" and old_mode == "":
                self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME", name )
                self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE", mode )
                self.setDatabaseSymbol("core", "PIN_" + pin + "_LAT", "")
                self.setDatabaseSymbol("core", "PIN_" + pin + "_DIR", "Out")

    def configurePin(self, pad, name, mode):
        # Iterate and check if pin name and function has already been assigned
        for pin in self.pad_to_pin_map.values():
            if (    name == self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME")
                or  mode == self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE")
               ):

                # Un-assign pin
                # ToDO: Do not set the core symbols directly. Request the core to
                #       change the symbols by sending the message
                status = self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE", "" )

                # The pin manager shall not be able to modify manual configuration by the user.
                # In that case, the return type will be false. ToDO: Verify.
                if status == False:
                    return "The pin manager is not able to un-assign pin"

                status = self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME", "" )

                # The pin manager shall not be able to modify manual configuration by the user.
                # In that case, the return type will be false. ToDO: Verify.
                if status == False:
                    return "The pin manager is not able to un-assign pin"


        # Check the pin status to be configured
        pin = self.pad_to_pin_map[pad]
        old_name = self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME")
        old_mode = self.getDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE")

        if old_name == "" and old_mode == "":
            status = self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME", name )
            if status == False:
                return "The pin manager is not able to assign pin"
            self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE", mode )
            if status == False:
                return "The pin manager is not able to assign pin"
        else:
            # The pin is already already configured, either manually by user, or by BSP itself.
            return "The pin"+ " " + pad + " " + "is already in use"
        return "Pin is configured successflly"

    def reset_all_pins(self):
        for pin in self.pad_to_pin_map.values():
                # Un-assign pin
                # ToDO: Do not set the core symbols directly. Request the core to
                #       change the symbols by sending the message
                status = self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_TYPE", "" )

                # The pin manager shall not be able to modify manual configuration by the user.
                # In that case, the return type will be false. ToDO: Verify.
                if status == False:
                    return "The pin manager is not able to un-assign pin"

                status = self.setDatabaseSymbol("core", "PIN_" + pin + "_FUNCTION_NAME", "" )

                # The pin manager shall not be able to modify manual configuration by the user.
                # In that case, the return type will be false. ToDO: Verify.
                if status == False:
                    return "The pin manager is not able to un-assign pin"

    def __call__(self):
        print("Log: Pin manager instantiated")

