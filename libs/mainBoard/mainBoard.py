import sys
from os import path
from copy import deepcopy
from utils.connectorSpec import getConnectorPinNumberFromSignal
from utils.deviceSpec import getDeviceFunctionListByPinId, getDevicePinMap

shdMainBoardHelp = 'shdMainBoardHelpKeyword'

class MainBoard:
    def __init__(self, yamlFileName, Database, ATDF):
        self.__currentConfig = {}
        for item in sys.path:
            if "shd\\boards" in item:
                boardYamlFile = path.join(item, yamlFileName)
                break
        else:
            return None

        if not path.isfile(boardYamlFile):
            return None

        self.__db = Database
        self.__atdf = ATDF
        self.__symbolNamesByPinId = {}
        self.__devicePinMap = getDevicePinMap(self.__db, ATDF)
        
        import yaml
        with open(boardYamlFile, 'r') as file:
            self.__defaultConfig = yaml.safe_load(file)
            self.__currentConfig = deepcopy(self.__defaultConfig)
            self.__componentID = "mainBoard_" + self.__defaultConfig['config'].split(".")[0].upper() 

    def __str__(self):
        return "{}".format(self.__currentConfig)

    def __clearPinConfig(self, pinControl):
        pinNumber = self.__devicePinMap.get(pinControl.get('pinId'))

        for key, value in pinControl.items():
            if key == 'pinId':
                continue
            
            params = dict()
            params.setdefault('pinNumber', pinNumber)
            params.setdefault('setting', key)
            # print("CHRIS dbg >> send Message PIN_CLEAR_CONFIG_VALUE : {}".format(params))
            self.__db.sendMessage("core", "PIN_CLEAR_CONFIG_VALUE", params)
        
    def __setPinConfig(self, pinControl):
        pinId = pinControl.get('pinId')
        pinNumber = self.__devicePinMap.get(pinId)

        # Get function values list from the pinNumber
        functionList = getDeviceFunctionListByPinId(self.__atdf, pinId)
        # print("CHRIS dbg: functionList {}".format(functionList))

        # Sort dictionary by key to set function as first setting
        sortedKeys = sorted(pinControl.keys())
        sortedPinControl = {key:pinControl[key] for key in sortedKeys}
        
        for key, value in sortedPinControl.items():
            if key == 'pinId':
                continue
            
            if key == 'function':
                for functionIndex in range(len(functionList)):
                    if value in functionList[functionIndex]:
                        value = functionList[functionIndex]
                        break
                        
            if key in ['function', 'name', 'pinId']:
                value = value.upper()
            elif type(value).__name__ == 'bool':
                if key in ['pull up', 'pull down', 'open drain']:
                    value = "True" if value else "False"
            else:
                value = value.title()
                
            # print("CHRIS dbg: set {} value:{}".format(symbolName, value))
            # Don't set any value in case of direction: input
            if key == 'direction' and value == 'In':
                continue

            params = dict()
            params.setdefault('pinNumber', pinNumber)
            params.setdefault('setting', key)
            params.setdefault('value', value)
            # print("CHRIS dbg >> send Message PIN_SET_CONFIG_VALUE : {}".format(params))
            self.__db.sendMessage("core", "PIN_SET_CONFIG_VALUE", params)

    def __showSymbol(self, symbol, event):
        eventSymbolID = event['id']
        eventValue = event['value']
        if "CSASGPIO" in eventSymbolID:
            global mainBoard
            connectorName = self.getConnectorNameFromSymbolName(eventSymbolID)
            newPinControl = {"spi":{"cs":{"function": "GPIO","direction": "out","latch": "high"}}}
            if eventValue == True:
                # Update the pin function
                self.updatePinControlByConnector(connectorName, newPinControl)
            else:
                # Restore the pin function by default
                self.restorePinControlByConnector(connectorName, newPinControl)
                
            # Set Pin configuration
            spiPinControlList = self.getPinControlListByConnectorSignal(connectorName, 'spi')
            for spiPinControl in spiPinControlList:
                if 'cs' in spiPinControl['name'].lower():
                    self.__clearPinConfig(spiPinControl)
                    self.__setPinConfig(spiPinControl)
                    newLabel = self.__updateFunctionInSymbolLabel(spiPinControl['function'], symbol.getLabel())
                    symbol.setLabel(newLabel)
        else:
            symbol.setVisible(eventValue)

    def __setPinEnableCallback(self, symbol, event):
        srcSymbolSplit = event["id"].split('_')
        if "COMPONENT" in event["id"]:
            componentIndex = int(srcSymbolSplit[-1])
            pinControlList = self.getPinControlListByComponent(componentIndex)
        else:
            connectorSignal = srcSymbolSplit[-1].lower()
            connectorName = srcSymbolSplit[-2].replace("-"," ")
            pinControlList = self.getPinControlListByConnectorSignal(connectorName, connectorSignal)

        for pinControl in pinControlList:
            if event["value"] is True:
                self.__setPinConfig(pinControl)
            else:
                self.__clearPinConfig(pinControl)

    def __getSymbolLabel(self, name, function, subSignal, pinNumber, pinId):
        if subSignal is None:
            return "{}:{}:Pin[{}]:{}".format(name, function, pinNumber, pinId)
        else:
            return "{}:{}:{}:Pin[{}]:{}".format(name, function, subSignal, pinNumber, pinId)
        
    def __updateFunctionInSymbolLabel(self, function, label):
        labelSplit = label.split(":")
        labelSplit[1] = function
        return ":".join(labelSplit)
        
    def getName(self):
        return self.__currentConfig.get('name')
    
    def getDocumentation(self):
        return self.__currentConfig.get('documentation')

    def isPinSignal(self, pinCtrl):
        if pinCtrl.get('pinId') != None:
            return True
        else:
            return False

    def getComponentList(self):
        componentList = []
        index = 0
        for component in self.__currentConfig['components']:
            componentList.append((index, component['name'], component['description']))
            index = index + 1
            
        return componentList
                
    def getDescriptionListByComponent(self, componentIndex):
        if componentIndex >= len(self.__currentConfig['components']):
            return None
        
        pinList = []
        pinControl = self.__currentConfig['components'][componentIndex]['pinctrl']
        index = 0
        if self.isPinSignal(pinControl):
            # Single pin signal
            pinList.append((index, pinControl.get('function'), pinControl.get('pinId')))
            index = index + 1
        else:
            for key, value in pinControl.items():
                # Multi pin signal
                pinList.append((index, value.get('function'), value.get('pinId')))
                index = index + 1

        return pinList 

    def getPinControlListByComponent(self, componentIndex):
        if componentIndex >= len(self.__currentConfig['components']):
            return None
        
        pinList = []
        pinControl = self.__currentConfig['components'][componentIndex]['pinctrl']
        if self.isPinSignal(pinControl):
            # Single pin signal
            pinList.append(pinControl)
        else:
            for key, value in pinControl.items():
                # Multi pin signal
                pinList.append(value)

        return pinList     
            
    def getConnectorList(self):
        connectorList = []
        index = 0
        for connector in self.__currentConfig['connectors']:
            connectorList.append((index, connector['name'], connector['description']))
            index = index + 1
            
        return connectorList  

    def getConnectorNameByIndex(self, connectorIndex):
        if connectorIndex >= len(self.__currentConfig['connectors']):
            return None

        return self.__currentConfig['connectors']['name']

    def getSignalListByConnector(self, connectorIndex):
        if connectorIndex >= len(self.__currentConfig['connectors']):
            return None
        
        signalList = []
        signalControl = self.__currentConfig['connectors'][connectorIndex]['pinctrl']
        for signal in signalControl:
            signalList.append(signal)
        
        return signalList
            
    def getSignalListByConnectorName(self, connectorName):
        signalList = []
        for connector in self.__currentConfig['connectors']:
            if connector['name'] == connectorName:
                signalControl = connector['pinctrl']
                for signal in signalControl:
                    signalList.append(signal)
                
                return signalList
        else:
            return None
            
    def getDescriptionListByConnectorSignal(self, connectorName, connectorSignal):
        pinControlList = []
        for connector in self.__currentConfig['connectors']:
            if connector['name'] == connectorName:
                signalControl = connector['pinctrl'].get(connectorSignal)
                if signalControl != None:
                    if self.isPinSignal(signalControl):
                        # Single pin signal
                        pinNumber = getConnectorPinNumberFromSignal(connector.get("compatible"), signalPin=connectorSignal)
                        data = (signalControl['name'], signalControl['function'], pinNumber, signalControl['pinId'])
                        pinControlList.append(data)
                    else:
                        for subSignal, pinControl in signalControl.items():
                            # Multi pin signal
                            pinNumber = getConnectorPinNumberFromSignal(connector.get("compatible"), signalGroup=connectorSignal, signalPin=subSignal)
                            data = (pinControl['name'], pinControl['function'], subSignal.upper(), pinNumber, pinControl['pinId'])
                            pinControlList.append(data)
                
                return pinControlList
        else:
            return None
            
    def getPinControlListByConnectorSignal(self, connectorName, connectorSignal):
        pinControlList = []
        for connector in self.__currentConfig['connectors']:
            if connector['name'] == connectorName:
                signalControl = connector['pinctrl'].get(connectorSignal)
                if signalControl != None:
                    if self.isPinSignal(signalControl):
                        # Single pin signal
                        pinControlList.append(signalControl)
                    else:
                        for signal, pinControl in signalControl.items():
                            # Multi pin signal
                            pinControlList.append(pinControl)
                
                return pinControlList
        else:
            return None

    def updatePinControlByConnector(self, connectorName, newPinControl):
        for connector in self.__currentConfig['connectors']:
            if connector['name'] == connectorName:
                pinControlCurrent = connector['pinctrl']
                break

        for signal, newConfig in newPinControl.items():
            if newConfig.get('name') != None:
                # Single Pin
                pinCtrl = newConfig
                for key in newConfig:
                    pinControlCurrent[signal][key] = newConfig[key]
            else:
                # Multi Pin
                for subSignal, newSubConfig in newConfig.items():
                    pinCtrl = newSubConfig
                    for key in newSubConfig:
                        pinControlCurrent[signal][subSignal][key] = newSubConfig[key]   

    def restorePinControlByConnector(self, connectorName, pinControl):
        connectorIndex = 0
        for connector in self.__currentConfig['connectors']:
            if connector['name'] == connectorName:
                pinControlCurrent = connector['pinctrl']
                break
            else:
                connectorIndex = connectorIndex + 1
                
        pinControlDefault = self.__defaultConfig['connectors'][connectorIndex]['pinctrl']
        
        for signal in pinControl:
            defaultSignal = pinControlDefault.get(signal)
            if defaultSignal != None:
                pinControlCurrent[signal] = deepcopy(defaultSignal)
                
    def createConfigurationSymbols(self, boardComponent):
        shdBoardName = boardComponent.createStringSymbol("SHD_MAINBOARD_NAME", None)
        shdBoardName.setLabel("Board Name")
        shdBoardName.setDefaultValue(self.__currentConfig.get('name'))
        shdBoardName.setReadOnly(True)
        shdBoardName.setHelp(shdMainBoardHelp)
        
        shdOnBoardComponentList = boardComponent.createMenuSymbol("SHD_MAINBOARD_ONBOARD_COMPONENTS", None)
        shdOnBoardComponentList.setLabel("On Board Components")
        shdOnBoardComponentList.setDescription("List of on-board HW components")
        shdOnBoardComponentList.setVisible(False)
        shdOnBoardComponentList.setHelp(shdMainBoardHelp)

        # Create the configuration of ON-BOARD COMPONENTS
        componentDependencies = []
        componentList = self.getComponentList()
        for component in componentList:
            componentIndex, label, description = component
            componentSymbolName = "SHD_MAINBOARD_COMPONENT_{}".format(componentIndex)
            shdComponent = boardComponent.createBooleanSymbol(componentSymbolName, None)
            shdComponent.setLabel(label)
            shdComponent.setDescription(description)
            shdComponent.setDefaultValue(False)
            shdComponent.setVisible(True)
            shdComponent.setHelp(shdMainBoardHelp)

            pinControlList = self.getDescriptionListByComponent(componentIndex)
            # print("CHRIS dbg >> pinControlList: {}".format(pinControlList))
            for pinControl in pinControlList:
                # print("CHRIS dbg >> pinControl: {}".format(pinControl))
                pinControlIndex, function, pinId = pinControl
                symbolName = "{}_{}".format(componentSymbolName, pinControlIndex)
                shdConfigComment = boardComponent.createCommentSymbol(symbolName, shdComponent)
                shdConfigComment.setLabel(function.upper() + ": " + pinId.upper())
                shdConfigComment.setVisible(False)
                shdConfigComment.setDependencies(self.__showSymbol, [componentSymbolName])
            
            componentDependencies.append(componentSymbolName)

        shdOnBoardComponentList.setDependencies(self.__setPinEnableCallback, componentDependencies)

        # Create the configuration of EXTERNAL CONNECTORS
        shdConnectorList = boardComponent.createMenuSymbol("SHD_MAINBOARD_CONNECTOR_LIST", None)
        shdConnectorList.setLabel("External Connectors")
        shdConnectorList.setDescription("List of external connectors")
        shdConnectorList.setVisible(True)
        shdConnectorList.setHelp(shdMainBoardHelp)

        boardConnectorList = self.getConnectorList()
        for connector in boardConnectorList:
            connectorDependencies = []
            conIndex, conName, conDescription = connector
            connectorSymbolName = self.getConnectorSymbolName(conName)
            shdConnectorSymbol = boardComponent.createMenuSymbol(connectorSymbolName, shdConnectorList)
            shdConnectorSymbol.setLabel(conName)
            shdConnectorSymbol.setDescription(conDescription)
            shdConnectorSymbol.setVisible(True)
            shdConnectorSymbol.setHelp(shdMainBoardHelp)

            signalList = self.getSignalListByConnector(conIndex)
            for signal in signalList:
                connectorSignalName = self.getConnectorSignalSymbolName(conName, signal)
                shdConSignalSymbol = boardComponent.createBooleanSymbol(connectorSignalName, shdConnectorSymbol)
                shdConSignalSymbol.setLabel(signal.upper())
                shdConSignalSymbol.setDescription("Enable {} : {}".format(conName, signal.upper()))
                shdConSignalSymbol.setDefaultValue(False)
                shdConSignalSymbol.setHelp(shdMainBoardHelp)
                
                pinDescriptionList = self.getDescriptionListByConnectorSignal(conName, signal)
                for pinDescription in pinDescriptionList:
                    spiCSdetected = False
                    # Check if single signal or signal group
                    if len(pinDescription) == 4:
                        name, function, pinNumber, pinId = pinDescription
                        label = self.__getSymbolLabel(name, function, None, pinNumber, pinId)
                    else:
                        name, function, subSignal, pinNumber, pinId = pinDescription
                        label = self.__getSymbolLabel(name, function, subSignal, pinNumber, pinId)
                        if subSignal.lower() == 'cs':
                            # Handle SPI CS exception
                            spiCSdetected = True
                        
                    shdConPinControlSymbolName = self.getConnectorSignalPinSymbolName(conName, signal, pinId)
                    # Store the Symbol name to be used in click Boards connection events
                    self.__symbolNamesByPinId[pinId] = shdConPinControlSymbolName

                    # print("CHRIS dbg >> conPinControlName: ", conPinControlName)
                    shdConPinControlSymbol = boardComponent.createCommentSymbol(shdConPinControlSymbolName, shdConSignalSymbol)
                    shdConPinControlSymbol.setLabel(label)
                    shdConPinControlSymbol.setVisible(False)
                    shdConPinControlSymbol.setHelp(shdMainBoardHelp)

                    # Check SPI CS exception. It could be handled as GPIO. Add configuration option.
                    if spiCSdetected == True:
                        shdSpiCSConfigSymbolName = "{}_{}".format(shdConPinControlSymbolName, "CSASGPIO")
                        shdSpiCSConfigSymbol = boardComponent.createBooleanSymbol(shdSpiCSConfigSymbolName, shdConPinControlSymbol)
                        shdSpiCSConfigSymbol.setLabel("Drive CS signal as GPIO")
                        shdSpiCSConfigSymbol.setDescription("Drive CS signal as GPIO")
                        shdSpiCSConfigSymbol.setDefaultValue(False)
                        shdSpiCSConfigSymbol.setHelp(shdMainBoardHelp)

                        shdConPinControlSymbol.setDependencies(self.__showSymbol, [connectorSignalName, shdSpiCSConfigSymbolName])

                    else:
                        shdConPinControlSymbol.setDependencies(self.__showSymbol, [connectorSignalName])
                        
                connectorDependencies.append(connectorSignalName)

            shdConnectorSymbol.setDependencies(self.__setPinEnableCallback, connectorDependencies)

        # print("CHRIS dbg >> shdSymbolNamesByPinId: ", shdSymbolNamesByPinId)

    def getConnectorSymbolName(self, connectorName):
        return "SHD_MAINBOARD_CONNECTOR_{}".format(connectorName.replace(" ","-"))

    def getConnectorNameFromSymbolName(self, connectorSymbolName):
        return connectorSymbolName.split("_")[3].replace("-", " ")

    def getConnectorSignalSymbolName(self, connectorName, signalName):
        connectorSymbolName = self.getConnectorSymbolName(connectorName)
        return "{}_{}".format(connectorSymbolName, signalName.upper())

    def getConnectorSignalPinSymbolName(self, connectorName, signalName, pinId):
        connectorSignalName = self.getConnectorSignalSymbolName(connectorName, signalName)
        return "{}_{}".format(connectorSignalName, pinId.upper())

    def connectClickBoard(self, connectorName, clickBoardPinCtrl):
        # print("SHD configureConnector connectorName: {}, pinCtrl: {}".format(connectorName, clickBoardPinCtrl))
        board = self.__db.getComponentByID(self.__componentID)
        
        # Update Pin Control of the Main Board by Connector
        self.updatePinControlByConnector(connectorName, clickBoardPinCtrl)

        # Update Configuration Options by Connector
        signalList = self.getSignalListByConnectorName(connectorName)
        for signal in signalList:
            # Enable signals
            connectorSignalName = self.getConnectorSignalSymbolName(connectorName, signal)
            signalSymbol = board.getSymbolByID(connectorSignalName)
            if clickBoardPinCtrl.get(signal) != None:
                # print("CHRIS dbg: Enable symbol: {}".format(connectorSignalName))
                signalSymbol.setValue(True)
                
                # Update Symbol label
                pinDescriptionList = self.getDescriptionListByConnectorSignal(connectorName, signal)
                for pinDescription in pinDescriptionList:
                    if len(pinDescription) == 4:
                        name, function, pinNumber, pinId = pinDescription
                        label = self.__getSymbolLabel(name, function, None, pinNumber, pinId)
                    else:
                        name, function, subSignal, pinNumber, pinId = pinDescription
                        label = self.__getSymbolLabel(name, function, subSignal, pinNumber, pinId)
                        # Handle SPI CS exception (configuration option is not allowed)
                        if subSignal.lower() == 'cs':
                            shdSpiCSConfigSymbolName = "{}_{}".format(self.__symbolNamesByPinId[pinId], "CSASGPIO")
                            signalSpiCsPinSymbol = board.getSymbolByID(shdSpiCSConfigSymbolName)
                            signalSpiCsPinSymbol.setVisible(False)
                            # print("CHRIS dbg >> CS set Visible: {}".format(shdSpiCSConfigSymbolName))

                    signalPinSymbol = board.getSymbolByID(self.__symbolNamesByPinId[pinId])
                    signalPinSymbol.setLabel(label)

            else:
                # print("CHRIS dbg: Disable symbol: {}".format(connectorSignalName))
                signalSymbol.setValue(False)
                signalSymbol.setVisible(False)

            signalSymbol.setReadOnly(True)
            
    def disconnectClickBoard(self, connectorName, clickBoardPinCtrl):
        # print("SHD restoreConnections connectorName: {}, pinCtrl: {}".format(connectorName, clickBoardPinCtrl))
        board = self.__db.getComponentByID(self.__componentID)
        
        # Restore Pin Control by default of the Main Board by Connector
        self.restorePinControlByConnector(connectorName, clickBoardPinCtrl)

        # Update Configuration Options by Connector
        signalList = self.getSignalListByConnectorName(connectorName)
        for signal in signalList:
            connectorSignalName = self.getConnectorSignalSymbolName(connectorName, signal)
            signalSymbol = board.getSymbolByID(connectorSignalName)
            signalSymbol.clearValue()
            signalSymbol.setReadOnly(False)
            signalSymbol.setVisible(True)
            
            # Update Symbol label
            pinDescriptionList = self.getDescriptionListByConnectorSignal(connectorName, signal)
            for pinDescription in pinDescriptionList:
                if len(pinDescription) == 4:
                    name, function, pinNumber, pinId = pinDescription
                    label = self.__getSymbolLabel(name, function, None, pinNumber, pinId)
                else:
                    name, function, subSignal, pinNumber, pinId = pinDescription
                    label = self.__getSymbolLabel(name, function, subSignal, pinNumber, pinId)
                    # Handle SPI CS exception (configuration option is not allowed)
                    if subSignal.lower() == 'cs':
                        shdSpiCSConfigSymbolName = "{}_{}".format(self.__symbolNamesByPinId[pinId], "CSASGPIO")
                        signalSpiCsPinSymbol = board.getSymbolByID(shdSpiCSConfigSymbolName)
                        signalSpiCsPinSymbol.setVisible(True)

                signalPinSymbol = board.getSymbolByID(self.__symbolNamesByPinId[pinId])
                signalPinSymbol.setLabel(label)
                


        












        