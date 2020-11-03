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
* File Name: mcPmsmFoc_AnalogInterfaceClass.py
*
* Description:
* The file comprises of back-end code for Analog interface block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                               GLOBAL VARIABLES                                   # 
#----------------------------------------------------------------------------------#
# ADC dictionary used to send message to ADC PLIB
adcChDict = {}

#----------------------------------------------------------------------------------#
#                           SUPPORTED MOTOR PARAMETERS                             # 
#----------------------------------------------------------------------------------#
# ADC channels per board per device
mcAnaI_DefaultPararameterDict = { 'MCLV2'  : {

                                        'PIC32MK' :    {    'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 24,
                                                            'PHASE_V'       : 4,
                                                            'PHASE_V_CH'    : 9,
                                                            'VDC'           : 7,
                                                            'VDC_CH'        : 10,
                                                            'POT'           : 7,
                                                            'POT_CH'        : 15,
                                                            'RESOLUTION'    : ["12", "10", "8", "6"],
                                                            'MAX_CHANNELS'  : 47,
                                                            'TRIGGER'       : 1,
                                                       },
                                        'SAME70' :     {    'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 0,
                                                            'PHASE_V'       : 0,
                                                            'PHASE_V_CH'    : 6,
                                                            'VDC'           : 0,
                                                            'VDC_CH'        : 7,
                                                            'POT'           : 0,
                                                            'POT_CH'        : 10,
                                                            'RESOLUTION'    : ["12", "13", "14", "15", "16"],
                                                            'MAX_CHANNELS'  : 12,
                                                            'TRIGGER'       : 0,
                                                       },
                                        'SAME54' :     {    'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 0,
                                                            'PHASE_V'       : 1,
                                                            'PHASE_V_CH'    : 0,
                                                            'VDC'           : 1,
                                                            'VDC_CH'        : 14,
                                                            'POT'           : 0,
                                                            'POT_CH'        : 6,
                                                            'RESOLUTION'    : ["12", "16", "10", "8"],
                                                            'MAX_CHANNELS'  : 24,
                                                            'TRIGGER'       : 0,
                                                       },
                                        'DEFAULT' :     {   'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 0,
                                                            'PHASE_V'       : 1,
                                                            'PHASE_V_CH'    : 0,
                                                            'VDC'           : 1,
                                                            'VDC_CH'        : 14,
                                                            'POT'           : 0,
                                                            'POT_CH'        : 6,
                                                            'RESOLUTION'    : ["12", "16", "10", "8"],
                                                            'MAX_CHANNELS'  : 47,
                                                            'TRIGGER'       : 0,
                                                       },
                                    },
                            'MCHV3'  : {

                                        'PIC32MK' :     {   'PHASE_U'       : 3,
                                                            'PHASE_U_CH'    : 8,
                                                            'PHASE_V'       : 1,
                                                            'PHASE_V_CH'    : 4,
                                                            'VDC'           : 7,
                                                            'VDC_CH'        : 10,
                                                            'POT'           : 7,
                                                            'POT_CH'        : 15,
                                                            'RESOLUTION'    : 12,
                                                            'MAX_CHANNELS'  : 47,
                                                            'TRIGGER'       : 1
                                                          },

                                        'SAME70' :     {    'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 0,
                                                            'PHASE_V'       : 0,
                                                            'PHASE_V_CH'    : 6,
                                                            'VDC'           : 0,
                                                            'VDC_CH'        : 7,
                                                            'POT'           : 0,
                                                            'POT_CH'        : 10,
                                                            'RESOLUTION'    : ["12", "13", "14", "15", "16"],
                                                            'MAX_CHANNELS'  : 12,
                                                            'TRIGGER'       : 0,
                                                          },
                                        'SAME54' :     {    'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 0,
                                                            'PHASE_V'       : 1,
                                                            'PHASE_V_CH'    : 0,
                                                            'VDC'           : 1,
                                                            'VDC_CH'        : 14,
                                                            'POT'           : 0,
                                                            'POT_CH'        : 6,
                                                            'RESOLUTION'    : ["12", "10", "8", "6"],
                                                            'MAX_CHANNELS'  : 24,
                                                            'TRIGGER'       : 0,
                                                          },
                                        'DEFAULT' :     {    'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 0,
                                                            'PHASE_V'       : 1,
                                                            'PHASE_V_CH'    : 0,
                                                            'VDC'           : 1,
                                                            'VDC_CH'        : 14,
                                                            'POT'           : 0,
                                                            'POT_CH'        : 6,
                                                            'RESOLUTION'    : ["12", "16", "10", "8"],
                                                            'MAX_CHANNELS'  : 47,
                                                            'TRIGGER'       : 0,
                                                       },
                                    },
                        }

mcAnaI_DefaultAdcResolution  = 12

mcAnI_DefaultDevelopmentBoard = 'MCLV2'
global mcAnI_MicrocontrollerSeries
mcAnI_MicrocontrollerSeries   =  ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")

#-------------------------------------------------------------------------------------------#
#                                     LOCAL FUNCTIONS                                       #
#-------------------------------------------------------------------------------------------#  
def mcAnI_CreateMHCSymbols( mcPmsmFocComponent):   

    global mcAnI_MicrocontrollerSeries
    board = mcVsi_SelectedBoard.getSelectedKey()
    if mcAnI_MicrocontrollerSeries not in mcPmsmFocBoardPimParamDict[board].keys():
        mcAnI_MicrocontrollerSeries = 'DEFAULT'

    # Symbol for ADC unit 0 PLIB 
    global mcAnI_Adc0Plib
    mcAnI_Adc0Plib = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_ADCPLIB", None)
    mcAnI_Adc0Plib.setVisible(False)
    mcAnI_Adc0Plib.setDefaultValue("None")

    global mcAnI_Adc1Plib
    mcAnI_Adc1Plib = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_ADCPLIB1", None)
    mcAnI_Adc1Plib .setVisible(False)
    mcAnI_Adc1Plib .setDefaultValue("None")

    # Root node  
    mcAnI_RootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_ADC_MENU", None)
    mcAnI_RootNode.setLabel("ADC Configurations")
        
    if ("PIC32MK" == mcAnI_MicrocontrollerSeries):
        resolution = ["12", "10", "8", "6"]
        maxChannels = 47
    elif ("SAME70" == mcAnI_MicrocontrollerSeries):
        resolution = ["12", "13", "14", "15", "16"]
        maxChannels = 12
    elif ("SAME54" == mcAnI_MicrocontrollerSeries):
        resolution = ["12", "16", "10", "8"]
        maxChannels = 24
    else:
        resolution = ["12", "16", "10", "8"]
        maxChannels = 12       

    mcAnI_AdcResolution = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_ADC_RESOLUTION", mcAnI_RootNode, resolution)
    mcAnI_AdcResolution.setLabel("Select ADC Resolution")
    mcAnI_AdcResolution.setReadOnly(True)

    global mcAnI_AdcMaximumValue    
    mcAnI_AdcMaximumValue = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_ADC_MAX", mcAnI_RootNode)
    mcAnI_AdcMaximumValue.setVisible(False)
    mcAnI_AdcMaximumValue.setValue(4095)
    
    global mcAnI_AdcUnitForIu
    mcAnI_AdcUnitForIu = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEU_MODULE", mcAnI_RootNode)
    mcAnI_AdcUnitForIu.setLabel("Phase U ADC Module")
    mcAnI_AdcUnitForIu.setMin(0)
    mcAnI_AdcUnitForIu.setMax(7)
    mcAnI_AdcUnitForIu.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['PHASE_U']))


    global mcAnI_AdcChannelForIu 
    mcAnI_AdcChannelForIu = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEU_CH", mcAnI_AdcUnitForIu)
    mcAnI_AdcChannelForIu.setLabel("Phase U Channel Number")
    mcAnI_AdcChannelForIu.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['PHASE_U_CH']))
    mcAnI_AdcChannelForIu.setMin(-1)
    mcAnI_AdcChannelForIu.setMax(maxChannels - 1)

    global mcAnI_AdcUnitForIv
    mcAnI_AdcUnitForIv = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEV_MODULE", mcAnI_RootNode)
    mcAnI_AdcUnitForIv.setLabel("Phase V ADC Module")
    mcAnI_AdcUnitForIv.setMin(0)
    mcAnI_AdcUnitForIv.setMax(7)
    mcAnI_AdcUnitForIv.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['PHASE_V']))

    global mcAnI_AdcChannelForIv
    mcAnI_AdcChannelForIv = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEV_CH", mcAnI_AdcUnitForIv)
    mcAnI_AdcChannelForIv.setLabel("Phase V Channel Number")
    mcAnI_AdcChannelForIv.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['PHASE_V_CH']))
    mcAnI_AdcChannelForIv.setMin(-1)
    mcAnI_AdcChannelForIv.setMax(maxChannels - 1)

    global mcAnI_AdcUnitForPot
    mcAnI_AdcUnitForPot = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_POT_MODULE", mcAnI_RootNode)
    mcAnI_AdcUnitForPot.setLabel("Potentiometer ADC Module")
    mcAnI_AdcUnitForPot.setMin(0)
    mcAnI_AdcUnitForPot.setMax(7)
    mcAnI_AdcUnitForPot.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['POT']))

    global mcAnI_AdcChannelForPot
    mcAnI_AdcChannelForPot = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_POT_CH",mcAnI_AdcUnitForPot)
    mcAnI_AdcChannelForPot.setLabel("Potentiometer channel number")
    mcAnI_AdcChannelForPot.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['POT_CH']))
    mcAnI_AdcChannelForPot.setMin(-1)
    mcAnI_AdcChannelForPot.setMax(maxChannels - 1)

    global mcAnI_AdcUnitForVdc
    mcAnI_AdcUnitForVdc = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_DCBUSV_MODULE", mcAnI_RootNode)
    mcAnI_AdcUnitForVdc.setLabel("DC Bus Voltage ADC Module")
    mcAnI_AdcUnitForVdc.setMin(0)
    mcAnI_AdcUnitForVdc.setMax(7)
    mcAnI_AdcUnitForVdc.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['VDC']))

    global mcAnI_AdcChannelForVdc
    mcAnI_AdcChannelForVdc = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_DCBUSV_CH", mcAnI_AdcUnitForVdc)
    mcAnI_AdcChannelForVdc.setLabel("DC Bus Voltage channel number")
    mcAnI_AdcChannelForVdc.setDefaultValue(int(mcAnaI_DefaultPararameterDict[mcAnI_DefaultDevelopmentBoard][mcAnI_MicrocontrollerSeries]['VDC_CH']))
    mcAnI_AdcChannelForVdc.setMin(-1)
    mcAnI_AdcChannelForVdc.setMax(maxChannels - 1)

    # Initialize callback functions
    mcAnI_BoardDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_BOARD_PARAMS____", None)
    mcAnI_BoardDependency.setVisible(False)
    mcAnI_BoardDependency.setDependencies(mcAnI_UpdateSymbols, ["MCPMSMFOC_BOARD_SEL"])

    global mcAnI_Dependency
    mcAnI_Dependency = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_ADC_BOARD_DEP", mcAnI_RootNode)
    mcAnI_Dependency.setVisible(False)
    mcAnI_Dependency.setDefaultValue( False )

    global mcAnI_PeripheralDependency
    mcAnI_PeripheralDependency = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_ADC_DEP", None)
    mcAnI_PeripheralDependency.setVisible(False)
    mcAnI_PeripheralDependency.setDependencies(mcAnI_UpdatePeripheralLibrary, ["MCPMSMFOC_ADC_BOARD_DEP"
                                                                  "MCPMSMFOC_PWM_PH_U", 
                                                                  "MCPMSMFOC_PHASEU_MODULE",
                                                                  "MCPMSMFOC_ADC_RESOLUTION", 
                                                                  "MCPMSMFOC_PHASEU_CH",
                                                                  "MCPMSMFOC_PHASEV_MODULE", 
                                                                  "MCPMSMFOC_PHASEV_CH", 
                                                                  "MCPMSMFOC_POT_MODULE", 
                                                                  "MCPMSMFOC_DCBUSV_MODULE", 
                                                                  "MCPMSMFOC_POT_CH", 
                                                                  "MCPMSMFOC_DCBUSV_CH"])

    # Set ADC dependency to true
    mcAnI_PeripheralDependency.setValue(True)


# Send message to ADC PLIB when ADC channels are changed
def mcAnI_UpdatePeripheralLibrary(symbol, event):
    component = symbol.getComponent()
    adcChDict['PHASE_U'   ]   =   (component.getSymbolValue("MCPMSMFOC_PHASEU_MODULE"  ))
    adcChDict['PHASE_U_CH']   =   (component.getSymbolValue("MCPMSMFOC_PHASEU_CH"      ))
    adcChDict['PHASE_V'   ]   =   (component.getSymbolValue("MCPMSMFOC_PHASEV_MODULE"  ))
    adcChDict['PHASE_V_CH']   =   (component.getSymbolValue("MCPMSMFOC_PHASEV_CH"      ))
    adcChDict['POT'       ]   =   (component.getSymbolValue("MCPMSMFOC_POT_MODULE"     ))
    adcChDict['POT_CH'    ]   =   (component.getSymbolValue("MCPMSMFOC_POT_CH"         ))
    adcChDict['VDC'       ]   =   (component.getSymbolValue("MCPMSMFOC_DCBUSV_MODULE"  ))
    adcChDict['VDC_CH'    ]   =   (component.getSymbolValue("MCPMSMFOC_DCBUSV_CH"      ))
    adcChDict['RESOLUTION']   =   (component.getSymbolValue("MCPMSMFOC_ADC_RESOLUTION" ))
    adcChDict['TRIGGER'   ]   =   (component.getSymbolValue("MCPMSMFOC_PWM_PH_U"       ))

    mcAnI_AdcMaximumValue.setValue(pow(2,int(adcChDict['RESOLUTION'])) - 1)
    if (component.getSymbolValue("MCPMSMFOC_ADC_BOARD_DEP") == False):
        Database.sendMessage(mcAnI_Adc0Plib.getValue().lower(), "PMSM_FOC_ADC_CH_CONF", adcChDict)
        if (mcAnI_Adc1Plib  != "None"):
            Database.sendMessage(mcAnI_Adc1Plib.getValue().lower(), "PMSM_FOC_ADC_CH_CONF", adcChDict)


def mcAnI_UpdateSymbols( symbol, event ):
    global mcAnI_MicrocontrollerSeries
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    if mcAnI_MicrocontrollerSeries not in mcPmsmFocBoardPimParamDict[board_key].keys():
        mcAnI_MicrocontrollerSeries = 'DEFAULT'
    if board_key in mcAnaI_DefaultPararameterDict.keys():    
    
        # Set ADC board dependency to True 
        mcAnI_Dependency.setValue(True)
           
        # Update default phase current U channel from dictionary 
        mcAnI_AdcUnitForIu.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['PHASE_U']         ))
        mcAnI_AdcChannelForIu.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['PHASE_U_CH']    ))

        # Update default phase current V channel from dictionary 
        mcAnI_AdcUnitForIv.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['PHASE_V']         ))
        mcAnI_AdcChannelForIv.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['PHASE_V_CH']    ))

        # Update default potentiometer channel from dictionary 
        mcAnI_AdcUnitForPot.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['POT']            ))
        mcAnI_AdcChannelForPot.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['POT_CH']       ))

        # Update default DC link voltage channel from dictionary 
        mcAnI_AdcUnitForVdc.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['VDC']            ))
        mcAnI_AdcChannelForVdc.setValue( int(mcAnaI_DefaultPararameterDict[board_key][mcAnI_MicrocontrollerSeries]['VDC_CH']       ))
            
        # Set ADC Board dependency to False 
        mcAnI_Dependency.setValue(False)

        mcAnI_UpdatePeripheralLibrary( symbol,event)

#-------------------------------------------------------------------------------------------#
#                                 INTERFACE FUNCTIONS                                       #
#-------------------------------------------------------------------------------------------#        
def mcAnII_OnAttachmentConnected( source, target):
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    connectID = source["id"]
    targetID = target["id"]

    dict = {}
              
    adcChDict['PHASE_U'   ]   =   (localComponent.getSymbolValue("MCPMSMFOC_PHASEU_MODULE" ))
    adcChDict['PHASE_U_CH']   =   (localComponent.getSymbolValue("MCPMSMFOC_PHASEU_CH"     ))
    adcChDict['PHASE_V'   ]   =   (localComponent.getSymbolValue("MCPMSMFOC_PHASEV_MODULE" ))
    adcChDict['PHASE_V_CH']   =   (localComponent.getSymbolValue("MCPMSMFOC_PHASEV_CH"     ))
    adcChDict['POT'       ]   =   (localComponent.getSymbolValue("MCPMSMFOC_POT_MODULE"    ))
    adcChDict['POT_CH'    ]   =   (localComponent.getSymbolValue("MCPMSMFOC_POT_CH"        ))
    adcChDict['VDC'       ]   =   (localComponent.getSymbolValue("MCPMSMFOC_DCBUSV_MODULE" ))
    adcChDict['VDC_CH'    ]   =   (localComponent.getSymbolValue("MCPMSMFOC_DCBUSV_CH"     ))
    adcChDict['RESOLUTION']   =   (localComponent.getSymbolValue("MCPMSMFOC_ADC_RESOLUTION"))
    adcChDict['TRIGGER'   ]   =   (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_U"      ))

    if ( connectID == "pmsmfoc_ADC" ):
        instanceNum = (filter(str.isdigit,str(remoteID)))
        if (instanceNum == str(0) or instanceNum == ""):
            mcAnI_Adc0Plib.setValue(remoteID)
        else:
            mcAnI_Adc1Plib.setValue(remoteID)
                
        dict = Database.sendMessage(remoteID, "PMSM_FOC_ADC_CH_CONF", adcChDict)
           
        # Set the max num of channels
        adcMaxCh = dict['ADC_MAX_CH']
        adcMaxModules = dict['ADC_MAX_MODULES']
        localComponent.getSymbolByID("MCPMSMFOC_PHASEU_CH"    ).setMax(adcMaxCh - 1     )
        localComponent.getSymbolByID("MCPMSMFOC_PHASEV_CH"    ).setMax(adcMaxCh - 1     )
        localComponent.getSymbolByID("MCPMSMFOC_DCBUSV_CH"    ).setMax(adcMaxCh - 1     )
        localComponent.getSymbolByID("MCPMSMFOC_POT_CH"       ).setMax(adcMaxCh - 1     )
        localComponent.getSymbolByID("MCPMSMFOC_PHASEU_MODULE").setMax(adcMaxModules - 1)
        localComponent.getSymbolByID("MCPMSMFOC_PHASEV_MODULE").setMax(adcMaxModules - 1)
        localComponent.getSymbolByID("MCPMSMFOC_POT_MODULE"   ).setMax(adcMaxModules - 1)
        localComponent.getSymbolByID("MCPMSMFOC_DCBUSV_MODULE").setMax(adcMaxModules - 1)

def mcAnII_OnAttachmentDisconnected( source, target):
    if ( source["id"] == "pmsmfoc_ADC"):
        mcAnI_Adc0Plib.setValue("None")
        mcAnI_Adc1Plib.setValue("None")

def mcAnII_AnalogInterface( mcPmsmFocComponent ):
    #Create MHC Symbols for Analog interface module
    mcAnI_CreateMHCSymbols( mcPmsmFocComponent)

        

        