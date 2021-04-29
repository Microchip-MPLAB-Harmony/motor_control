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

"""*****************************************************************************
* File Name: mcPmsmFoc_DigitalInterfaceClass.py
*
* Description:
* The file comprises of back-end code for digital interface block.
*
*****************************************************************************"""

#----------------------------------------------------------------------------------#
#                               GLOBAL VARIABLES                                   # 
#----------------------------------------------------------------------------------#
global availablePinDictionary

#----------------------------------------------------------------------------------#
#                           SUPPORTED MOTOR PARAMETERS                             # 
#----------------------------------------------------------------------------------#

#board and PIM specific parameters
mcPmsmFocBoardPimParamDict =  {'MCLV2' :  {
                                           'PIC32MK': {
                                                        'START_STOP_SWITCH'    : 'RG1',
                                                        'DIRECTION_SWITCH'     : 'RC7',
                                                        'DIRECTION_LED'        : 'RF5',
                                                        'FAULT_LED'            : 'RG15',
                                                      },
                                            'SAME70': {
                                                        'START_STOP_SWITCH'    : 'PC3',
                                                        'DIRECTION_SWITCH'     : 'PC1',
                                                        'DIRECTION_LED'        : 'PC23',
                                                        'FAULT_LED'            : 'PA24',
                                                      },
                                            'SAME54': {
                                                        'START_STOP_SWITCH'    : 'PD09',
                                                        'DIRECTION_SWITCH'     : 'PD10',
                                                        'DIRECTION_LED'        : 'PB26',
                                                        'FAULT_LED'            : 'PB27',
                                                      },
                                            'SAMC21': {
                                                        'START_STOP_SWITCH'    : 'PB16',
                                                        'DIRECTION_SWITCH'     : 'PB31',
                                                        'DIRECTION_LED'        : 'PB12',
                                                        'FAULT_LED'            : 'PB13',
                                                      },
                                            'PIC32CMMC00': {
                                                        'START_STOP_SWITCH'    : 'PB22',
                                                        'DIRECTION_SWITCH'     : 'PB23',
                                                        'DIRECTION_LED'        : 'PA24',
                                                        'FAULT_LED'            : 'PA25',
                                                      },
                                            'DEFAULT': {
                                                        'START_STOP_SWITCH'    : 'PD09',
                                                        'DIRECTION_SWITCH'     : 'PD10',
                                                        'DIRECTION_LED'        : 'PB26',
                                                        'FAULT_LED'            : 'PB27',
                                                      },
                                          },
                            'Custom' :  {
                                           'PIC32MK': {
                                                        'START_STOP_SWITCH'    : 'RG1',
                                                        'DIRECTION_SWITCH'     : 'RC7',
                                                        'DIRECTION_LED'        : 'RF5',
                                                        'FAULT_LED'            : 'RG15',
                                                      },
                                            'SAME70': {
                                                        'START_STOP_SWITCH'    : 'PC3',
                                                        'DIRECTION_SWITCH'     : 'PC1',
                                                        'DIRECTION_LED'        : 'PC23',
                                                        'FAULT_LED'            : 'PA24',
                                                      },
                                            'SAME54': {
                                                        'START_STOP_SWITCH'    : 'PD09',
                                                        'DIRECTION_SWITCH'     : 'PD10',
                                                        'DIRECTION_LED'        : 'PB26',
                                                        'FAULT_LED'            : 'PB27',
                                                      },
                                            'SAMC21': {
                                                        'START_STOP_SWITCH'    : 'PB16',
                                                        'DIRECTION_SWITCH'     : 'PB31',
                                                        'DIRECTION_LED'        : 'PB12',
                                                        'FAULT_LED'            : 'PB13',
                                                      },
                                            'PIC32CMMC00': {
                                                        'START_STOP_SWITCH'    : 'PB16',
                                                        'DIRECTION_SWITCH'     : 'PB31',
                                                        'DIRECTION_LED'        : 'PB12',
                                                        'FAULT_LED'            : 'PB13',
                                                      },
                                            'DEFAULT': {
                                                        'START_STOP_SWITCH'    : 'PD09',
                                                        'DIRECTION_SWITCH'     : 'PD10',
                                                        'DIRECTION_LED'        : 'PB26',
                                                        'FAULT_LED'            : 'PB27',
                                                      },
                                          },
                            'MCHV3' :     {
                                            'PIC32MK': {
                                                        'START_STOP_SWITCH'    : 'RD8',
                                                        'DIRECTION_SWITCH'     : 'RC7',
                                                        'DIRECTION_LED'        : 'RF5',
                                                        'FAULT_LED'            : 'RG15',
                                                       },
                                            'SAME70':  {
                                                        'START_STOP_SWITCH'    : 'PE2',
                                                        'DIRECTION_SWITCH'     : 'PC1',
                                                        'DIRECTION_LED'        : 'PC23',
                                                        'FAULT_LED'            : 'PC23',
                                                       },
                                            'SAME54':  {
                                                        'START_STOP_SWITCH'    : 'PD08',
                                                        'DIRECTION_SWITCH'     : 'PD10',
                                                        'DIRECTION_LED'        : 'PB26',
                                                        'FAULT_LED'            : 'PB27',
                                                       },
                                            'SAMC21': {
                                                        'START_STOP_SWITCH'    : 'PB16',
                                                        'DIRECTION_SWITCH'     : 'PB31',
                                                        'DIRECTION_LED'        : 'PB12',
                                                        'FAULT_LED'            : 'PB13',
                                                      },
                                            'PIC32CMMC00': {
                                                        'START_STOP_SWITCH'    : 'PB16',
                                                        'DIRECTION_SWITCH'     : 'PB31',
                                                        'DIRECTION_LED'        : 'PB12',
                                                        'FAULT_LED'            : 'PB13',
                                                      },
                                            'DEFAULT':  {
                                                        'START_STOP_SWITCH'    : 'PD08',
                                                        'DIRECTION_SWITCH'     : 'PD10',
                                                        'DIRECTION_LED'        : 'PB26',
                                                        'FAULT_LED'            : 'PB27',
                                                       },
                                          }
                         }

mcDiI_DefaultDevelopmentBoard = 'MCLV2'
global mcDiI_MicrocontrollerSeries
mcDiI_MicrocontrollerSeries   =  ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")

#----------------------------------------------------------------------------------#
#                           DIGITAL INTERFACE FUNCTIONS                            # 
#----------------------------------------------------------------------------------#

def sort_alphanumeric(l):
    import re
    convert = lambda text: int(text) if text.isdigit() else text.lower()
    alphanum_key = lambda key: [ convert(c) for c in re.split('([0-9]+)', key) ]
    return sorted(l, key = alphanum_key)

def mcDiI_CreateMHCSymbols( mcPmsmFocComponent ):
    global mcDiI_MicrocontrollerSeries
    board = mcVsi_SelectedBoard.getSelectedKey()
    if str(mcDiI_MicrocontrollerSeries) not in mcPmsmFocBoardPimParamDict[board].keys():
        mcDiI_MicrocontrollerSeries = 'DEFAULT' 

    availablePinDictionary = {}
    availablePinDictionary= Database.sendMessage("core", "PIN_LIST", availablePinDictionary)

    global mcDiI_StartStopButton
    mcDiI_StartStopButton = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_START_BUTTON", mcVsi_RootNode)
    mcDiI_StartStopButton.setLabel("Start/Stop Switch")
    mcDiI_StartStopButton.setOutputMode("Key")
    mcDiI_StartStopButton.setDisplayMode("Key")

    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcDiI_StartStopButton.addKey(pad, str(i), pad)
        i = i+1
    mcDiI_StartStopButton.setSelectedKey(str(mcPmsmFocBoardPimParamDict[mcDiI_DefaultDevelopmentBoard][mcDiI_MicrocontrollerSeries]['START_STOP_SWITCH']))

    global mcDiI_DirectionButton
    mcDiI_DirectionButton = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_DIRECTION_BUTTON", mcVsi_RootNode)
    mcDiI_DirectionButton.setLabel("Direction Toggle Switch")
    mcDiI_DirectionButton.setOutputMode("Key")
    mcDiI_DirectionButton.setDisplayMode("Key")
    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcDiI_DirectionButton.addKey(pad, str(i), pad)
        i = i+1
    mcDiI_DirectionButton.setSelectedKey(str(mcPmsmFocBoardPimParamDict[mcDiI_DefaultDevelopmentBoard][mcDiI_MicrocontrollerSeries]['DIRECTION_SWITCH']))
    mcDiI_DirectionButton.setDependencies(mcPmsmFocDirChngHide, ["MCPMSMFOC_BOARD_SEL"])

    global mcDiI_DirectionStatusLed
    mcDiI_DirectionStatusLed = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_DIRECTION_LED", mcVsi_RootNode)
    mcDiI_DirectionStatusLed.setLabel("Direction LED")
    mcDiI_DirectionStatusLed.setOutputMode("Key")
    mcDiI_DirectionStatusLed.setDisplayMode("Key")
    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcDiI_DirectionStatusLed.addKey(pad, str(i), pad)
        i = i+1
    mcDiI_DirectionStatusLed.setSelectedKey(str(mcPmsmFocBoardPimParamDict[mcDiI_DefaultDevelopmentBoard][mcDiI_MicrocontrollerSeries]['DIRECTION_LED']))
    mcDiI_DirectionStatusLed.setDependencies(mcPmsmFocDirChngHide, ["MCPMSMFOC_BOARD_SEL"])

    global mcDiI_FaultStatusLed
    mcDiI_FaultStatusLed = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_FAULT_LED", mcVsi_RootNode)
    mcDiI_FaultStatusLed.setLabel("Fault LED")
    mcDiI_FaultStatusLed.setOutputMode("Key")
    mcDiI_FaultStatusLed.setDisplayMode("Key")
    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcDiI_FaultStatusLed.addKey(pad, str(i), pad)
        i = i+1
    mcDiI_FaultStatusLed.setSelectedKey(str(mcPmsmFocBoardPimParamDict[mcDiI_DefaultDevelopmentBoard][mcDiI_MicrocontrollerSeries]['FAULT_LED']))

    mcDiI_PinComment = mcPmsmFocComponent.createCommentSymbol("MCPMSMFOC_PIN_COMMENT", mcVsi_RootNode)
    mcDiI_PinComment.setLabel("**** Configure above selected pins in the Pin Manager ****")

    # Initialize callback function
    mcDiI_BoardDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_BOARD_PARAMS", mcVsi_RootNode)
    mcDiI_BoardDependency.setVisible(False)
    mcDiI_BoardDependency.setDependencies( mcDiI_UpdateSymbols, ["MCPMSMFOC_BOARD_SEL"])


def mcDiI_UpdateSymbols( symbol, event ):
    global mcDiI_MicrocontrollerSeries
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    if mcDiI_MicrocontrollerSeries not in mcPmsmFocBoardPimParamDict[board_key].keys():
        mcDiI_MicrocontrollerSeries = 'DEFAULT'    
    
    if board_key in mcPmsmFocBoardPimParamDict.keys():
        mcDiI_StartStopButton.setSelectedKey((mcPmsmFocBoardPimParamDict[board_key][mcDiI_MicrocontrollerSeries]['START_STOP_SWITCH']))
        mcDiI_DirectionButton.setSelectedKey((mcPmsmFocBoardPimParamDict[board_key][mcDiI_MicrocontrollerSeries]['DIRECTION_SWITCH']))
        mcDiI_DirectionStatusLed.setSelectedKey((mcPmsmFocBoardPimParamDict[board_key][mcDiI_MicrocontrollerSeries]['DIRECTION_LED']))
        mcDiI_FaultStatusLed.setSelectedKey((mcPmsmFocBoardPimParamDict[board_key][mcDiI_MicrocontrollerSeries]['FAULT_LED']))

def mcPmsmFocDirChngHide(symbol, event):
    symObj = event["symbol"]
    board = symObj.getSelectedKey()
    if board == "MCHV3":
        symbol.setVisible(False)
    else:
        symbol.setVisible(True)

def mcDiII_DigitalInterface( mcPmsmFocComponent ):
    mcDiI_CreateMHCSymbols( mcPmsmFocComponent )