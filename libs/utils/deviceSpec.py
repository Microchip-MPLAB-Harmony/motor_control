def getDeviceFunctionListByPinId(ATDF, pinId):
    functionList = []
    peripheralList = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals").getChildrenByName("module")
    for module in peripheralList:
        moduleName = module.getAttribute("name")
        if 'PIO' in moduleName:
            continue

        instanceList = module.getChildrenByName("instance")
        for instance in instanceList:
            instanceName = instance.getAttribute("name")
            foundSignal = False
            functionName = "{}_".format(instanceName)
            signalsNodes = instance.getChildrenByName("signals")
            for signalsNode in signalsNodes:
                signalList = signalsNode.getChildrenByName("signal")
                for signal in signalList:
                    if pinId == signal.getAttribute("pad"):
                        if foundSignal:
                            functionName += '/'
                            
                        groupName = signal.getAttribute("group")
                        groupNameSplitted = groupName.split("_")
                        if groupNameSplitted[0] == instanceName:
                            groupName = "_".join(groupNameSplitted[1:])
                            
                        functionName += groupName
                        
                        index = signal.getAttribute("index")
                        if index != None:
                            functionName += index
                            
                        foundSignal = True

                        if "FLEXCOM" in instanceName:
                            functionList.append(functionName)
                            functionName = "{}_".format(instanceName)
                            foundSignal = False

            if foundSignal:
                functionList.append(functionName)

    functionList.append('GPIO')
            
    return sorted(functionList)

def getDevicePinMap(Database, ATDF):
    pinMap = dict()
    # Extract Device Pin Map from ATDF
    packageName = str(Database.getSymbolValue("core", "COMPONENT_PACKAGE"))
    variants = ATDF.getNode("/avr-tools-device-file/variants").getChildren()
    for variant in variants:
        if packageName in variant.getAttribute("package"):
            pinOutName = variant.getAttribute("pinout")

    pinOut = ATDF.getNode("/avr-tools-device-file/pinouts/pinout@[name=\"" + str(pinOutName) + "\"]").getChildren()
    for pin in pinOut:
        pinMap[str(pin.getAttribute("pad"))] = int(pin.getAttribute("position"))

    return pinMap