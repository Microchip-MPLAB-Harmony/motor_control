#---------------------------------------------------------------------------------------#
#                                   Imports                                             #
#---------------------------------------------------------------------------------------#
from device.gpio import pin_manager_pic32mk
import os
import xml.etree.ElementTree as ET

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class AdapterService:
    def __init__(self, object_wrapper):
        # Get ATDF object
        self.object_wrapper = object_wrapper

        # Get ATDF object
        ATDF = object_wrapper.get_atdf_object()
        Variables = object_wrapper.get_variable_object()

        for module in ATDF.getNode("/avr-tools-device-file/modules").getChildren():
            if module.getAttribute("name") == "GPIO":
                GPIO = module.getAttribute("name").lower() + "_" + module.getAttribute("id").lower()
                break

        currentPath = Variables.get("__CSP_DIR") + "/peripheral/" + GPIO
        deviceXmlPath = os.path.join(currentPath, "plugin/pin_xml/components/" + Variables.get("__PROCESSOR") + ".xml")
        deviceXmlTree = ET.parse(deviceXmlPath)
        deviceXmlRoot = deviceXmlTree.getroot()
        pinoutXmlName = deviceXmlRoot.get("pins")
        pinoutXmlPath = os.path.join(currentPath, "plugin/pin_xml/pins/" + pinoutXmlName + ".xml")
        pinoutXmlPath = os.path.normpath(pinoutXmlPath)

        pinFileContent = ET.fromstring((open(pinoutXmlPath, "r")).read())

        # Get list of function_Maps
        self.gpio_data = []
        for item in pinFileContent.findall("pins/pin"):
            if item.attrib["name"].startswith("R"):
                self.gpio_data.append(item.attrib["name"])

    def get_gpio_data(self):
        return self.gpio_data

    def set_led_pin(self, name, pad):
        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
        pin_manager_module.configureLed(pad, name, "GPIO")

    def set_button_pin(self, name, pad):
        pin_manager_module = pin_manager_pic32mk.PinManager(self.object_wrapper)
        pin_manager_module.configureButton(pad, name, "GPIO")




