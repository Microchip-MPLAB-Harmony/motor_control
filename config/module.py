def loadModule():

###############################################################################
# Placeholder to find which devices support motor control.
# Mandatory peripherals are ADC ( 4 channels with simulateneous sampling feature)
# and PWM (3 complementary outputs with dead time)
# For PIC32MK, can search for "MC" in peripheral name.
# For SAM devices, find peripherals as well as whether pinouts are available.
    processor = Variables.get("__PROCESSOR")
    print(processor)

    periphNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals")
    modules = periphNode.getChildren()

    pwmPresent = False
    adcPresent = False
    encoderPresent = False

    for module in range (0, len(modules)):
        if ("PWM" or "MCPWM" or "TCC" in modules[module].getAttribute("name")):
            pwmPresent = True
        if ("ADC" or "ADCHS" or "AFEC" in modules[module].getAttribute("name")):
            adcPresent = True
        if ("QEI" or "PDEC" in modules[module].getAttribute("name")):
            encoderPresent = True
###############################################################################

    if all(x in processor for x in ["PIC32MK", "MC"]) or ("SAME70" in processor):
        mcPmsmFocComponent = Module.CreateComponent("pmsm_foc",
                                                 "PMSM FOC",
                                                 "/Motor Control/", "algorithms/pmsm_foc/config/pmsm_foc.py")
        mcPmsmFocComponent.setDisplayType("Motor Control Algorithm")
        mcPmsmFocComponent.addMultiDependency("pmsmfoc_ADC", "ADC", "ADC", True)
        mcPmsmFocComponent.addDependency("pmsmfoc_PWM", "PWM", False, True)
        mcPmsmFocComponent.addDependency("pmsmfoc_QDEC", "QDEC", False, True)
        mcPmsmFocComponent.setDependencyEnabled("pmsmfoc_QDEC", False)
