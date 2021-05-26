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
* File Name: mcPmsmFoc_BoardClass.py
*
* Description:
* The file comprises of back-end code for board block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                             GLOBAL VARIABLES                                     # 
#----------------------------------------------------------------------------------#

pwmDict = {}

# PWM channels per board per device
mcPwmI_DefaultPararameterDict = {'MCLV2' : {
                                    'PIC32MK':   { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '1',
                                                    'PWM_PH_V' : '2',
                                                    'PWM_PH_W' : '3',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FLT15',
                                                },
                                    'SAME70':    { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FAULT_PWM_ID2',
                                                },
                                    'SAME54':    { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'EIC_CHANNEL_2',
                                                },
                                    'DEFAULT':    { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FAULT_PWM_ID2',
                                                },
                                    },
                                'Custom' : {
                                    'PIC32MK':   { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '1',
                                                    'PWM_PH_V' : '2',
                                                    'PWM_PH_W' : '3',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FLT15',
                                                },
                                    'SAME70':    { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FAULT_PWM_ID2',
                                                },
                                    'SAME54':    { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'EIC_CHANNEL_2',
                                                },
                                    'DEFAULT':    { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FAULT_PWM_ID2',
                                                },
                                    },           
                         'MCHV3'  : {
                                    'PIC32MK':  {  'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '1',
                                                    'PWM_PH_V' : '2',
                                                    'PWM_PH_W' : '3',
                                                    'PWM_DEAD_TIME': '2',
                                                    'PWM_FAULT': 'FLT15',
                                                },

                                    'SAME70':   {  'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '2',
                                                    'PWM_FAULT': 'FAULT_PWM_ID2',
                                                },
                                    'SAME54':   {   'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '2',
                                                    'PWM_FAULT': 'FAULT_PWM_ID2',
                                                },
                                    'DEFAULT':   {   'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '0',
                                                    'PWM_PH_V' : '1',
                                                    'PWM_PH_W' : '2',
                                                    'PWM_DEAD_TIME': '2',
                                                    'PWM_FAULT': 'FAULT_PWM_ID2',
                                                },

                                    }
                        }
mcPwm_DefaultDevelopmentBoard = 'MCLV2'
global mcPwm_MicrocontrollerSeries
mcPwm_MicrocontrollerSeries   =  ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")

global eicFaultVal
#----------------------------------------------------------------------------------#
#                             PWM INTERFACE CLASS                                  # 
#----------------------------------------------------------------------------------#      
        
def mcPwm_CreateMHCSymbols( mcPmsmFocComponent ):
    global mcPwm_MicrocontrollerSeries
    board = mcVsi_SelectedBoard.getSelectedKey()
    if mcPwm_MicrocontrollerSeries not in mcPmsmFocBoardPimParamDict[board].keys():
        mcPwm_MicrocontrollerSeries = 'DEFAULT'     
    '''
        PWM Interface symbol structure 
    '''
    # Root Node symbol
    mcPwm_RootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_PWM", None )
    mcPwm_RootNode.setLabel("PWM Configurations")
    
    # PWM Frequency symbol
    global mcPwm_PwmFrequency
    mcPwm_PwmFrequency = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_FREQ", mcPwm_RootNode)
    mcPwm_PwmFrequency.setLabel("PWM Frequency (Hz)")
    mcPwm_PwmFrequency.setDefaultValue(20000)
    mcPwm_PwmFrequency.setMin(4000)
    mcPwm_PwmFrequency.setMax(100000)
    mcPwm_PwmFrequency.setDefaultValue(int(mcPwmI_DefaultPararameterDict[mcPwm_DefaultDevelopmentBoard][mcPwm_MicrocontrollerSeries]['PWM_FREQ']))

    # PWM Phase U Channel 
    global mcPwm_PwmChannelU
    mcPwm_PwmChannelU = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_PH_U", mcPwm_RootNode)
    mcPwm_PwmChannelU.setLabel("PWM Phase U Channel")
    mcPwm_PwmChannelU.setDefaultValue(int(mcPwmI_DefaultPararameterDict[mcPwm_DefaultDevelopmentBoard][mcPwm_MicrocontrollerSeries]['PWM_PH_U']))
    mcPwm_PwmChannelU.setMin(0)

    # PWM Phase V Channel 
    global mcPwm_PwmChannelV
    mcPwm_PwmChannelV = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_PH_V", mcPwm_RootNode)
    mcPwm_PwmChannelV.setLabel("PWM Phase V Channel")
    mcPwm_PwmChannelV.setDefaultValue(int(mcPwmI_DefaultPararameterDict[mcPwm_DefaultDevelopmentBoard][mcPwm_MicrocontrollerSeries]['PWM_PH_V']))
    mcPwm_PwmChannelV.setMin(0)

    # PWM Phase W Channel 
    global mcPwm_PwmChannelW
    mcPwm_PwmChannelW = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_PH_W", mcPwm_RootNode)
    mcPwm_PwmChannelW.setLabel("PWM Phase W Channel")
    mcPwm_PwmChannelW.setDefaultValue(int(mcPwmI_DefaultPararameterDict[mcPwm_DefaultDevelopmentBoard][mcPwm_MicrocontrollerSeries]['PWM_PH_W']))
    mcPwm_PwmChannelW.setMin(0)

    # PWM Dead time
    global mcPwm_PwmDeadTime
    mcPwm_PwmDeadTime = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_PWM_DEAD_TIME", mcPwm_RootNode)
    mcPwm_PwmDeadTime.setLabel("Dead Time (uS)")
    mcPwm_PwmDeadTime.setDefaultValue(float(mcPwmI_DefaultPararameterDict[mcPwm_DefaultDevelopmentBoard][mcPwm_MicrocontrollerSeries]['PWM_DEAD_TIME']))
    mcPwm_PwmDeadTime.setMin(0.1)
    mcPwm_PwmDeadTime.setMax(10)

    # PWM Fault
    global mcPwm_PwmFault
    mcPwm_PwmFault = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_PWM_FAULT", mcPwm_RootNode )
    mcPwm_PwmFault.setLabel("PWM Fault")
    
    series = ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")

    if ( 'SAME54' == series ):
        node  = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals/module@[name=\"EIC\"]/instance@[name=\"EIC\"]/parameters" ) 
        values = node.getChildren() 

        for index in range(0, len(values)):
            if( "EXTINT_NUM" == str(values[index].getAttribute("name")) ):
                maxChannels = values[index].getAttribute("value")
                for channel in range(0, int(maxChannels)):
                    mcPwm_PwmFault.addKey("EIC_CHANNEL_"+str(channel), str(channel), "EIC Channel"+ " "+str(channel))
    elif( 'SAME70' == series ):    
        node = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals/module@[name=\"PWM\"]/instance@[name=\"PWM0\"]/parameters")
        values = node.getChildren()
        for param in range(0, len(values)):
            if "FAULT" in values[param].getAttribute("name"):
                mcPwm_PwmFault.addKey(values[param].getAttribute("name"), values[param].getAttribute("value"), values[param].getAttribute("caption"))

    elif( 'PIC32MK' == series ):
        node = ATDF.getNode("/avr-tools-device-file/modules/module@[name=\"MCPWM\"]/value-group@[name=\"IOCON1__FLTSRC\"]")
        values = (node.getChildren())
        for fault in reversed(values):
            mcPwm_PwmFault.addKey(fault.getAttribute("caption"), fault.getAttribute("value"),
                fault.getAttribute("caption"))

    mcPwm_PwmFault.setDisplayMode("Description")
    mcPwm_PwmFault.setSelectedKey((mcPwmI_DefaultPararameterDict['MCLV2'][ mcPwm_MicrocontrollerSeries]['PWM_FAULT']))

    # Call back function for EIC Channel update for PWM Fault
    mcPwm_PwmFaultDependency = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_EIC_DEP", mcPwm_RootNode)
    mcPwm_PwmFaultDependency.setVisible(False)
    mcPwm_PwmFaultDependency.setDependencies(mcPwm_PwmFaultHandler, ["MCPMSMFOC_PWM_FAULT"])


    # PWM PLIB
    global mcPwm_Plib
    mcPwm_Plib = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_PWMPLIB", None)
    mcPwm_Plib.setVisible(False)
    mcPwm_Plib.setDefaultValue("None")
    
    # PWM Board dependency
    global mcPwm_SomeFlag
    mcPwm_SomeFlag = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_PWM_BOARD_DEP", mcPwm_RootNode)
    mcPwm_SomeFlag.setVisible(False)
    mcPwm_SomeFlag.setDefaultValue(False)

    mcPwm_BoardDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_BOARD_PARAMS__", mcPwm_RootNode)
    mcPwm_BoardDependency.setVisible(False)
    mcPwm_BoardDependency.setDependencies(mcPwm_UpdateSymbols, ["MCPMSMFOC_BOARD_SEL"])

    # Initialize callback functions to update PWM PLIB
    mcPwm_PLibDependency = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_DEP", None)
    mcPwm_PLibDependency.setVisible(False)
    mcPwm_PLibDependency.setDependencies( mcPwm_UpdatePLib, ["MCPMSMFOC_PWM_FREQ", 
                                                             "MCPMSMFOC_PWM_PH_U",
                                                             "MCPMSMFOC_PWM_PH_V", 
                                                             "MCPMSMFOC_PWM_PH_W", 
                                                             "MCPMSMFOC_PWM_FAULT", 
                                                             "MCPMSMFOC_PWM_DEAD_TIME",
                                                             "MCPMSMFOC_PWM_BOARD_DEP"])
    
def mcPwm_PwmFaultHandler( symbol, event ):
    pass

def mcPwm_UpdateSymbols( symbol, event ):
    global mcPwm_MicrocontrollerSeries
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    if mcPwm_MicrocontrollerSeries not in mcPmsmFocBoardPimParamDict[board_key].keys():
        mcPwm_MicrocontrollerSeries = 'DEFAULT'   
        
    if board_key in mcPwmI_DefaultPararameterDict.keys():
        mcPwm_SomeFlag.setValue(True)
        mcPwm_PwmFrequency.setValue(int(mcPwmI_DefaultPararameterDict[board_key][mcPwm_MicrocontrollerSeries]['PWM_FREQ']      ))
        mcPwm_PwmChannelU.setValue(int(mcPwmI_DefaultPararameterDict[board_key][mcPwm_MicrocontrollerSeries]['PWM_PH_U']      ))
        mcPwm_PwmChannelV.setValue(int(mcPwmI_DefaultPararameterDict[board_key][mcPwm_MicrocontrollerSeries]['PWM_PH_V']      ))
        mcPwm_PwmChannelW.setValue(int(mcPwmI_DefaultPararameterDict[board_key][mcPwm_MicrocontrollerSeries]['PWM_PH_W']      ))
        mcPwm_PwmDeadTime.setValue(int(mcPwmI_DefaultPararameterDict[board_key][mcPwm_MicrocontrollerSeries]['PWM_DEAD_TIME'] ))
        mcPwm_PwmFault.setSelectedKey(mcPwmI_DefaultPararameterDict[board_key][mcPwm_MicrocontrollerSeries]['PWM_FAULT'])
        mcPwm_SomeFlag.setValue(False)

def mcPwm_UpdatePLib( symbol, event):
    global eicFaultVal
    component = symbol.getComponent()
    pwmDict['PWM_FREQ'     ]  =  (component.getSymbolValue("MCPMSMFOC_PWM_FREQ"      ))
    pwmDict['PWM_PH_U'     ]  =  (component.getSymbolValue("MCPMSMFOC_PWM_PH_U"      ))
    pwmDict['PWM_PH_V'     ]  =  (component.getSymbolValue("MCPMSMFOC_PWM_PH_V"      ))
    pwmDict['PWM_PH_W'     ]  =  (component.getSymbolValue("MCPMSMFOC_PWM_PH_W"      ))
    pwmDict['PWM_DEAD_TIME']  =  (component.getSymbolValue("MCPMSMFOC_PWM_DEAD_TIME" ))
    pwmDict['PWM_FAULT'    ]  =  (mcPwm_PwmFault.getSelectedKey())
    
    if (component.getSymbolValue("MCPMSMFOC_PWM_BOARD_DEP") == False):
        Database.sendMessage(mcPwm_Plib.getValue().lower(), "PMSM_FOC_PWM_CONF", pwmDict)
    if (event["id"] == "MCPMSMFOC_PWM_FAULT") and ("EIC" in mcPwm_PwmFault.getSelectedKey()):
        fault = filter(str.isdigit,str(mcPwm_PwmFault.getSelectedKey()))
        if fault != eicFaultVal:
            #Enable EIC channel
            Database.setSymbolValue("eic", "EIC_CHAN_" + str(fault), True)
            Database.setSymbolValue("eic", "EIC_EXTINTEO_" + str(fault), True)
            Database.setSymbolValue("eic", "EIC_DEBOUNCEN_" + str(fault), True)
            Database.setSymbolValue("eic", "EIC_CONFIG_SENSE_" + str(fault), 2) 

            #Disbale previously selected EIC channel
            Database.setSymbolValue("eic", "EIC_CHAN_" + str(eicFaultVal), False)
            Database.setSymbolValue("eic", "EIC_EXTINTEO_" + str(eicFaultVal), False)
            Database.setSymbolValue("eic", "EIC_DEBOUNCEN_" + str(eicFaultVal), False)
            Database.setSymbolValue("eic", "EIC_CONFIG_SENSE_" + str(eicFaultVal), 0)     

    
def mcPwm_onAttachmentConnected(source, target):
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    connectID = source["id"]
    targetID = target["id"]

    dict = {}
    global mcPwm_MicrocontrollerSeries
    global eicFaultVal

    pwmDict['PWM_FREQ'     ]  =  (localComponent.getSymbolValue("MCPMSMFOC_PWM_FREQ"      ))
    pwmDict['PWM_PH_U'     ]  =  (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_U"      ))
    pwmDict['PWM_PH_V'     ]  =  (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_V"      ))
    pwmDict['PWM_PH_W'     ]  =  (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_W"      ))
    pwmDict['PWM_DEAD_TIME']  =  (localComponent.getSymbolValue("MCPMSMFOC_PWM_DEAD_TIME" ))
    pwmDict['PWM_FAULT'    ]  =  (mcPwm_PwmFault.getSelectedKey())

   
    if (connectID == "pmsmfoc_PWM"):
        mcPwm_Plib.setValue(remoteID)
        dict = Database.sendMessage(remoteID, "PMSM_FOC_PWM_CONF", pwmDict)
        
        #set the max number of Channels
        pwmMaxCh = dict['PWM_MAX_CH']
        localComponent.getSymbolByID("MCPMSMFOC_PWM_PH_U").setMax(pwmMaxCh - 1)
        localComponent.getSymbolByID("MCPMSMFOC_PWM_PH_V").setMax(pwmMaxCh - 1)
        localComponent.getSymbolByID("MCPMSMFOC_PWM_PH_W").setMax(pwmMaxCh - 1)
        
        #Activate EIC component for PWM fault for SAME54 device
        if mcPwm_MicrocontrollerSeries == "SAME54":
            faultComponent = ["eic"]
            Database.activateComponents(faultComponent)
            eicFaultVal = filter(str.isdigit,str(mcPwm_PwmFault.getSelectedKey()))
            Database.setSymbolValue("eic", "EIC_CHAN_" + str(eicFaultVal), True)
            Database.setSymbolValue("eic", "EIC_EXTINTEO_" + str(eicFaultVal), True)
            Database.setSymbolValue("eic", "EIC_DEBOUNCEN_" + str(eicFaultVal), True)
            Database.setSymbolValue("eic", "EIC_CONFIG_SENSE_" + str(eicFaultVal), 2)

        
def mcPwm_onAttachmentDisconnected( source, target):
    if ( source["id"] == "pmsmfoc_PWM"):
        mcPwm_Plib.setValue("None")

def mcPwmI_PwmInterface( mcPmsmFocComponent ):
    # Create MHC symbols 
    mcPwm_CreateMHCSymbols( mcPmsmFocComponent)
    

    
