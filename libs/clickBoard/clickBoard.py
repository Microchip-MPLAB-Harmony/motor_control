import sys
from os import path
from copy import deepcopy
from utils.connectorSpec import getConnectorPinNumberFromSignal, getConnectorSignalMapMikroBUSXplainPro

shdClickBoardHelp = 'SHDClickBoardHelp'

class ClickBoard:
    def __init__(self, yamlFileName):
        self.__currentConfig = {}
        self.__hwAdaptatorComponent = None
        for item in sys.path:
            if "shd\\clickBoards" in item:
                boardYamlFile = path.join(item, yamlFileName)
                break
        else:
            return None

        if not path.isfile(boardYamlFile):
            return None
        
        import yaml
        with open(boardYamlFile, 'r') as file:
            self.__defaultConfig = yaml.safe_load(file)
            self.__currentConfig = deepcopy(self.__defaultConfig)

    def __str__(self):
        return "{}".format(self.__currentConfig)

    def getName(self):
        return self.__currentConfig.get('name')

    def getDescription(self):
        return self.__currentConfig.get('description')

    def getDocumentation(self):
        return self.__currentConfig.get('documentation')

    def getConnectorCompatible(self):
        return self.__currentConfig.get('compatible')

    def getConnections(self):
        return self.__currentConfig.get('supported')

    def getPinDescriptionList(self):
        boardName = self.__currentConfig['name'].replace(" ", "").upper()
        pinList = []
        index = 0
        for key, value in self.__currentConfig['supported'].items():
            signalName = value.get('name')
            if signalName != None:
                # Single pin signal
                pinNumber = getConnectorPinNumberFromSignal(self.__currentConfig['compatible'], signalPin=key)
                name = "SHD_CLICK_{}_{}".format(boardName, index)
                description = "Pin {} ({}): {}".format(pinNumber, key.upper(), signalName)
                pinList.append((pinNumber, name, description))
                index = index + 1
            else:
                # Multi pin signal
                for subKey, subValue in value.items():
                    subSignalName = subValue.get('name')
                    pinNumber = getConnectorPinNumberFromSignal(self.__currentConfig['compatible'], signalGroup=key, signalPin=subKey)
                    name = "SHD_CLICK_{}_{}".format(boardName, index)
                    description = "Pin {} ({}_{}): {}".format(pinNumber, key.upper(), subKey.upper(), subSignalName)
                    pinList.append((pinNumber, name, description))
                    index = index + 1

        pinList.sort()
        
        return pinList

    def convertFromMikroBusToXplainProBoard(self):
        if self.__currentConfig['compatible'] == 'mikrobus':
            self.__currentConfig['compatible'] = 'xplainpro'
            # Rename Signals
            signalMapRename = getConnectorSignalMapMikroBUSXplainPro()
            signalSupport = self.__currentConfig['supported']

            for key, value in signalSupport.items():
                newKey = signalMapRename.get(key)
                if newKey != None:
                    signalSupport.setdefault(newKey, value)
                    del signalSupport[key]

    def restoreFromXplainProToMikroBusBoard(self):
        if self.__currentConfig['compatible'] == 'xplainpro':
            self.__currentConfig = deepcopy(self.__defaultConfig)

    def __useHwAdaptorBoard(self, symbol, event):
        boardComponent = event['source']
        useHwAdaptationBoard = event['value']
        if useHwAdaptationBoard == True:
            self.convertFromMikroBusToXplainProBoard()
        else:
            self.restoreFromXplainProToMikroBusBoard()
            
        # Update Pin description in Configuration options
        sourceComp = event['source']
        pinDescriptionList = self.getPinDescriptionList()
        for pinDesc in pinDescriptionList:
            pinNumber, symbolName, symbolDescription = pinDesc
            symbol = sourceComp.getSymbolByID(symbolName)
            symbol.setLabel(symbolDescription)

        # Handle Component Dependency
        if useHwAdaptationBoard:
            # Show Xplain Pro dependency
            boardComponent.setDependencyEnabled("xplainpro", True)
            boardComponent.setDependencyEnabled("mikrobus", False)
        else:
            # Show mikroBUS dependency
            boardComponent.setDependencyEnabled("xplainpro", False)
            boardComponent.setDependencyEnabled("mikrobus", True)
        
    def createConfigurationSymbols(self, boardComponent):
        if self.__defaultConfig['compatible'] == 'mikrobus':
            shdClickBoardUseHWAdaptorSymbol = boardComponent.createBooleanSymbol("SHD_CLICK_USE_HW_ADAPTOR", None)
            shdClickBoardUseHWAdaptorSymbol.setLabel("Use mikroBUS Xplained Pro adapter board")
            shdClickBoardUseHWAdaptorSymbol.setDescription("https://www.microchip.com/en-us/development-tool/ATMBUSADAPTER-XPRO")
            shdClickBoardUseHWAdaptorSymbol.setDefaultValue(False)
            shdClickBoardUseHWAdaptorSymbol.setHelp(shdClickBoardHelp)
            self.__hwAdaptatorComponent = shdClickBoardUseHWAdaptorSymbol

        shdClickBoardNameSymbol = boardComponent.createStringSymbol("SHD_CLICK_" + self.__currentConfig.get('name').upper(), None)
        shdClickBoardNameSymbol.setLabel("Click Board Name")
        shdClickBoardNameSymbol.setDefaultValue(self.__currentConfig.get('name'))
        shdClickBoardNameSymbol.setReadOnly(True)
        shdClickBoardNameSymbol.setHelp(shdClickBoardHelp)
        shdClickBoardNameSymbol.setDependencies(self.__useHwAdaptorBoard, ["SHD_CLICK_USE_HW_ADAPTOR"])

        shdClickBoardDocSymbol = boardComponent.createStringSymbol("SHD_CLICK_" + self.__currentConfig.get('name').upper() + "_DOC", None)
        shdClickBoardDocSymbol.setLabel("Doc link")
        shdClickBoardDocSymbol.setDefaultValue(self.getDocumentation())
        shdClickBoardDocSymbol.setReadOnly(True)
        shdClickBoardDocSymbol.setHelp(shdClickBoardHelp)

        pinDescriptionList = self.getPinDescriptionList()
        for pinDesc in pinDescriptionList:
            pinNumber, symbolName, symbolDescription = pinDesc
            shdClickBoardSignalSymbol = boardComponent.createCommentSymbol(symbolName, None)
            shdClickBoardSignalSymbol.setLabel(symbolDescription)

    def connect(self):
        if (self.__hwAdaptatorComponent != None):
            self.__hwAdaptatorComponent.setVisible(False)

    def disconnect(self):
        if (self.__hwAdaptatorComponent != None):
            self.__hwAdaptatorComponent.setVisible(True)
            