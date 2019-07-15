# coding: utf-8
"""*****************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

###################################################################################################
########################### Global variables   #################################
###################################################################################################

import os

global mcPmsmFocInstanceName
global mcPmsmFocSeries
global mcPmsmFocAdc
global mcPmsmFocPWM
global mcPmsmFocQdec

global mcPmsmFocSym_start_button
global mcPmsmFocSym_dir_button
global mcPmsmFocSym_dir_led
global mcPmsmFocSym_fault_led

# Motor parameters
mcPmsmFocMotorParamDict = {'LONG_HURST' : { 'R'           : 0.285,
                                            'LD'          : 0.00032,
                                            'LQ'          : 0.00032,
                                            'BEMF_CONST'  : 7.24,
                                            'POLE_PAIRS'  : 5,
                                            'RATED_SPEED' : 2804,
                                            'MAX_SPEED'   : 3644,
                                            'MAX_FW_CURRENT' : -2.0,
                                            'QE_PULSES_PER_REV' : 1000,
                                            'MAX_MOTOR_CURRENT' : 4.0 ,
                                            },
                            'SMALL_HURST' : { 'R'           : 2.10,
                                              'LD'          : 0.000192,
                                              'LQ'          : 0.000192,
                                              'BEMF_CONST'  : 7.24,
                                              'POLE_PAIRS'  : 5,
                                              'RATED_SPEED' : 2054,
                                              'MAX_SPEED'   : 4000,
                                              'MAX_FW_CURRENT' : -2.0,
                                              'QE_PULSES_PER_REV' : 0,
                                              'MAX_MOTOR_CURRENT' : 4.0 ,
                                            },
                            'LEADSHINE' : {   'R'           : 1.39,
                                              'LD'          : 0.00253,
                                              'LQ'          : 0.00253,
                                              'BEMF_CONST'  :44.38,
                                              'POLE_PAIRS'  : 5,
                                              'RATED_SPEED' : 3000,
                                              'MAX_SPEED'   : 5000,
                                              'MAX_FW_CURRENT' : -2.0,
                                              'QE_PULSES_PER_REV' : 2500,
                                              'MAX_MOTOR_CURRENT' : 4.0 ,
                                          },
                          }

#Board parameters
mcPmsmFocBoardParamDict = {'MCLV2' :       { 'MAX_CURRENT'         : 4.4,
                                            'DC_BUS_VOLT'          : 24,
                                            'DC_BUS_RATIO'         : 0.0625,
                                            'START_STOP_SWITCH'    : 'RG1',
                                            'DIRECTION_SWITCH'     : 'RC7',
                                            'DIRECTION_LED'        : 'RF5',
                                            'FAULT_LED'            : 'RG15',
                                           },
                            'MCHV3' :     { 'MAX_CURRENT'          : 16.4,
                                            'DC_BUS_VOLT'          : 400,
                                            'DC_BUS_RATIO'         : 0.00766,
                                            'START_STOP_SWITCH'    : 'RG1',
                                            'DIRECTION_SWITCH'     : 'RC7',
                                            'DIRECTION_LED'        : 'RF5',
                                            'FAULT_LED'            : 'RG15',
                                          }
                         }

# ADC channels per board per device
mcPmsmFocMclv2ADCDict = { 'MCLV2'  : {

                                        'PIC32MK' :     {   'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 24,
                                                            'PHASE_V'       : 4,
                                                            'PHASE_V_CH'    : 9,
                                                            'VDC'           : 7,
                                                            'VDC_CH'        : 10,
                                                            'POT'           : 7,
                                                            'POT_CH'        : 15,
                                                            'RESOLUTION'    : 12
                                                          },
                                    },
                            'MCHV3'  : {

                                        'PIC32MK' :     {   'PHASE_U'       : 0,
                                                            'PHASE_U_CH'    : 24,
                                                            'PHASE_V'       : 4,
                                                            'PHASE_V_CH'    : 9,
                                                            'VDC'           : 7,
                                                            'VDC_CH'        : 10,
                                                            'POT'           : 7,
                                                            'POT_CH'        : 15,
                                                            'RESOLUTION'    : 12
                                                          },
                                    },
                        }
# ADC dictionary used to send message to ADC PLIB
adcChDict = {}

# PWM channels per board per device
mcPmsmFocMclv2PwmDict = {'MCLV2' : {
                                    'PIC32MK':   { 'PWM_FREQ' : '20000',
                                                    'PWM_PH_U' : '1',
                                                    'PWM_PH_V' : '2',
                                                    'PWM_PH_W' : '3',
                                                    'PWM_FAULT': 'FLT15',
                                                },
                                    },
                         'MCHV3'  : {
                                    'PIC32MK':   { 'PWM_FREQ' : '20000',
                                                    'PWM_PH_U' : '1',
                                                    'PWM_PH_V' : '2',
                                                    'PWM_PH_W' : '3',
                                                    'PWM_FAULT': 'FLT15',
                                                },

                                    }
                        }

#PWM dictionary used to send message to PWM PLIB
pwmDict = {}


global sort_alphanumeric

def sort_alphanumeric(l):
    import re
    convert = lambda text: int(text) if text.isdigit() else text.lower()
    alphanum_key = lambda key: [ convert(c) for c in re.split('([0-9]+)', key) ]
    return sorted(l, key = alphanum_key)
###################################################################################################
########################### Callback Functions   #################################
###################################################################################################
# Display selected motor parameters
def mcPmsmFocMotorParamSet(symbol, event):
    motor_key = event["symbol"].getKeyForValue(str(event["value"]))
    component = str(symbol.getComponent()).lower()
    if motor_key in mcPmsmFocMotorParamDict.keys():
        Database.setSymbolValue(component, "MCPMSMFOC_R", float(mcPmsmFocMotorParamDict[motor_key]['R']))
        Database.setSymbolValue(component, "MCPMSMFOC_LD", float(mcPmsmFocMotorParamDict[motor_key]['LD']))
        Database.setSymbolValue(component, "MCPMSMFOC_LQ", float(mcPmsmFocMotorParamDict[motor_key]['LQ']))
        Database.setSymbolValue(component, "MCPMSMFOC_POLE_PAIRS", float(mcPmsmFocMotorParamDict[motor_key]['POLE_PAIRS']))
        Database.setSymbolValue(component, "MCPMSMFOC_BEMF_CONST", float(mcPmsmFocMotorParamDict[motor_key]['BEMF_CONST']))
        Database.setSymbolValue(component, "MCPMSMFOC_RATED_SPEED", float(mcPmsmFocMotorParamDict[motor_key]['RATED_SPEED']))
        Database.setSymbolValue(component, "MCPMSMFOC_MAX_SPEED", float(mcPmsmFocMotorParamDict[motor_key]['MAX_SPEED']))
        Database.setSymbolValue(component, "MCPMSMFOC_MAX_FW_CURRENT", float(mcPmsmFocMotorParamDict[motor_key]['MAX_FW_CURRENT']))
        Database.setSymbolValue(component, "MCPMSMFOC_QE_PULSES_PER_REV", float(mcPmsmFocMotorParamDict[motor_key]['QE_PULSES_PER_REV']))
        Database.setSymbolValue(component, "MCPMSMFOC_MAX_MOTOR_CURRENT", float(mcPmsmFocMotorParamDict[motor_key]['MAX_MOTOR_CURRENT']))

# Display selected board parameters
def mcPmsmFocBoardParamSet(symbol, event):
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    component = mcPmsmFocInstanceName.getValue().lower()
    series = mcPmsmFocSeries.getValue()
    if board_key in mcPmsmFocBoardParamDict.keys():

        Database.setSymbolValue(component, "MCPMSMFOC_MAX_CURRENT", float(mcPmsmFocBoardParamDict[board_key]['MAX_CURRENT']))
        Database.setSymbolValue(component, "MCPMSMFOC_DC_BUS_VOLT", float(mcPmsmFocBoardParamDict[board_key]['DC_BUS_VOLT']))
        Database.setSymbolValue(component, "MCPMSMFOC_DC_BUS_RATIO", float(mcPmsmFocBoardParamDict[board_key]['DC_BUS_RATIO']))

        mcPmsmFocSym_start_button.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['START_STOP_SWITCH']))
        mcPmsmFocSym_dir_button.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['DIRECTION_SWITCH']))
        mcPmsmFocSym_dir_led.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['DIRECTION_LED']))
        mcPmsmFocSym_fault_led.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['FAULT_LED']))

        #PWM
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_FREQ", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_FREQ']))
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_PH_U", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_PH_U']))
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_PH_V", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_PH_V']))
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_PH_W", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_PH_W']))
        mcPmsmFocPwmFault.setSelectedKey((mcPmsmFocMclv2PwmDict[board_key][series]['PWM_FAULT']))

        #ADC
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEU_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_U']))
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEU_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_U_CH']))
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEV_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_V']))
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEV_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_V_CH']))
        Database.setSymbolValue(component, "MCPMSMFOC_POT_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['POT']))
        Database.setSymbolValue(component, "MCPMSMFOC_POT_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['POT_CH']))
        Database.setSymbolValue(component, "MCPMSMFOC_DCBUSV_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['VDC']))
        Database.setSymbolValue(component, "MCPMSMFOC_DCBUSV_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['VDC_CH']))

def mcPmsmFocEncoderVisibility(symbol, event):
    if(event["value"] == 1):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

def mcPmsmFocEncoderHide(symbol, event):
    if(event["value"] == 1):
        symbol.setVisible(False)
    else:
        symbol.setVisible(True)

# Send message to ADC PLIB when ADC channels are changed
def mcPmsmFocADCChanDep(symbol, event):
    component = symbol.getComponent()
    adcChDict['PHASE_U'] = (component.getSymbolValue("MCPMSMFOC_PHASEU_MODULE"))
    adcChDict['PHASE_U_CH'] = (component.getSymbolValue("MCPMSMFOC_PHASEU_CH"))
    adcChDict['PHASE_V'] = (component.getSymbolValue("MCPMSMFOC_PHASEV_MODULE"))
    adcChDict['PHASE_V_CH'] = (component.getSymbolValue("MCPMSMFOC_PHASEV_CH"))
    adcChDict['POT'] = (component.getSymbolValue("MCPMSMFOC_POT_MODULE"))
    adcChDict['POT_CH'] = (component.getSymbolValue("MCPMSMFOC_POT_CH"))
    adcChDict['VDC'] = (component.getSymbolValue("MCPMSMFOC_DCBUSV_MODULE"))
    adcChDict['VDC_CH'] = (component.getSymbolValue("MCPMSMFOC_DCBUSV_CH"))
    adcChDict['RESOLUTION'] = (component.getSymbolValue("MCPMSMFOC_ADC_RESOLUTION"))
    mcPmsmFocADCMax.setValue(pow(2,int(adcChDict['RESOLUTION'])) - 1)
    Database.sendMessage(mcPmsmFocAdc.getValue().lower(), "PMSM_FOC_ADC_CH_CONF", adcChDict)

#Send message to PWM PLIB when PWM channels are changed
def mcPmsmFocPwmPlibDep(symbol, event):
    global mcPmsmFocPwmFault
    component = symbol.getComponent()
    pwmDict['PWM_FREQ'] = (component.getSymbolValue("MCPMSMFOC_PWM_FREQ"))
    pwmDict['PWM_PH_U'] = (component.getSymbolValue("MCPMSMFOC_PWM_PH_U"))
    pwmDict['PWM_PH_V'] = (component.getSymbolValue("MCPMSMFOC_PWM_PH_V"))
    pwmDict['PWM_PH_W'] = (component.getSymbolValue("MCPMSMFOC_PWM_PH_W"))
    pwmDict['PWM_FAULT'] = (mcPmsmFocPwmFault.getSelectedKey())
    Database.sendMessage(mcPmsmFocPWM.getValue().lower(), "PMSM_FOC_PWM_CONF", pwmDict)

###################################################################################################
########################### Dependency   #################################
###################################################################################################

def onAttachmentConnected(source, target):
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    connectID = source["id"]
    targetID = target["id"]

    series = mcPmsmFocSeries.getValue()
    global mcPmsmFocPwmFault

    adcChDict['PHASE_U'] = (localComponent.getSymbolValue("MCPMSMFOC_PHASEU_MODULE"))
    adcChDict['PHASE_U_CH'] = (localComponent.getSymbolValue("MCPMSMFOC_PHASEU_CH"))
    adcChDict['PHASE_V'] = (localComponent.getSymbolValue("MCPMSMFOC_PHASEV_MODULE"))
    adcChDict['PHASE_V_CH'] = (localComponent.getSymbolValue("MCPMSMFOC_PHASEV_CH"))
    adcChDict['POT'] = (localComponent.getSymbolValue("MCPMSMFOC_POT_MODULE"))
    adcChDict['POT_CH'] = (localComponent.getSymbolValue("MCPMSMFOC_POT_CH"))
    adcChDict['VDC'] = (localComponent.getSymbolValue("MCPMSMFOC_DCBUSV_MODULE"))
    adcChDict['VDC_CH'] = (localComponent.getSymbolValue("MCPMSMFOC_DCBUSV_CH"))
    adcChDict['RESOLUTION'] = (localComponent.getSymbolValue("MCPMSMFOC_ADC_RESOLUTION"))

    pwmDict['PWM_FREQ'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_FREQ"))
    pwmDict['PWM_PH_U'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_U"))
    pwmDict['PWM_PH_V'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_V"))
    pwmDict['PWM_PH_W'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_W"))
    pwmDict['PWM_FAULT'] = (mcPmsmFocPwmFault.getSelectedKey())

    if (connectID == "ADC"):
        Database.sendMessage(remoteID, "PMSM_FOC_ADC_CH_CONF", adcChDict)
        mcPmsmFocAdc.setValue(remoteID)

    if (connectID == "PWM"):
        Database.sendMessage(remoteID, "PMSM_FOC_PWM_CONF", pwmDict)
        mcPmsmFocPWM.setValue(remoteID)
###################################################################################################
########################### Component   #################################
###################################################################################################
def instantiateComponent(mcPmsmFocComponent):
    global mcPmsmFocSeries
    global mcPmsmFocInstanceName
    global mcPmsmFocAdc
    global mcPmsmFocPWM
    global mcPmsmFocQdec

    Log.writeInfoMessage("Running PMSM FOC")

    mcPmsmFocInstanceName = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_INSTANCE_NAME", None)
    mcPmsmFocInstanceName.setVisible(False)
    mcPmsmFocInstanceName.setDefaultValue(mcPmsmFocComponent.getID().upper())

    mcPmsmFocSeries = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_SERIES", None)
    mcPmsmFocSeries.setVisible(False)
    series = ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")
    mcPmsmFocSeries.setDefaultValue(series)

    mcPmsmFocAdc = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_ADCPLIB", None)
    mcPmsmFocAdc.setVisible(False)

    mcPmsmFocPWM = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_PWMPLIB", None)
    mcPmsmFocPWM.setVisible(False)

    mcPmsmFocQdec = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_QDECPLIB", None)
    mcPmsmFocQdec.setVisible(False)

########################### PLIB   #################################
    mcPmsmFocPwmMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_PWM", None)
    mcPmsmFocPwmMenu.setLabel("PWM Configurations")

    mcPmsmFocPwmFreq = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_FREQ", mcPmsmFocPwmMenu)
    mcPmsmFocPwmFreq.setLabel("PWM Frequency (Hz)")
    mcPmsmFocPwmFreq.setDefaultValue(20000)
    mcPmsmFocPwmFreq.setMin(4000)
    mcPmsmFocPwmFreq.setMax(100000)
    mcPmsmFocPwmFreq.setDefaultValue(int(mcPmsmFocMclv2PwmDict['MCLV2'][mcPmsmFocSeries.getValue()]['PWM_FREQ']))

    phNames = "UVW"
    for ph in phNames:
        mcPmsmFocPwmCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_PH_"+str(ph), mcPmsmFocPwmMenu)
        mcPmsmFocPwmCh.setLabel("PWM Phase " + str(ph) + " Channel")
        mcPmsmFocPwmCh.setDefaultValue(int(mcPmsmFocMclv2PwmDict['MCLV2'][mcPmsmFocSeries.getValue()]['PWM_PH_'+str(ph)]))

    global mcPmsmFocPwmFault
    mcPmsmFocPwmFault = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_PWM_FAULT", mcPmsmFocPwmMenu)
    mcPmsmFocPwmFault.setLabel("PWM Fault")
    if "PIC32MK" in Variables.get("__PROCESSOR"):
        node = ATDF.getNode("/avr-tools-device-file/modules/module@[name=\"MCPWM\"]/value-group@[name=\"IOCON1__FLTSRC\"]")
        valueNodes = (node.getChildren())
        for fault in reversed(valueNodes):
            mcPmsmFocPwmFault.addKey(fault.getAttribute("caption"), fault.getAttribute("value"),
                fault.getAttribute("caption"))
    mcPmsmFocPwmFault.setSelectedKey((mcPmsmFocMclv2PwmDict['MCLV2'][mcPmsmFocSeries.getValue()]['PWM_FAULT']))

    mcPmsmFocPWMDep = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_DEP", None)
    mcPmsmFocPWMDep.setVisible(False)
    mcPmsmFocPWMDep.setDependencies(mcPmsmFocPwmPlibDep, ["MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_PWM_PH_U",
        "MCPMSMFOC_PWM_PH_V", "MCPMSMFOC_PWM_PH_W", "MCPMSMFOC_PWM_FAULT"])

########################### PLIB Configurations#################################
    mcPmsmFocADCMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_ADC_MENU", None)
    mcPmsmFocADCMenu.setLabel("ADC Channels")

    resolution = ["12", "10", "8", "6"]
    mcPmsmFocADCResolution = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_ADC_RESOLUTION", mcPmsmFocADCMenu, resolution)
    mcPmsmFocADCResolution.setLabel("Select ADC Resolution")

    global mcPmsmFocADCMax
    mcPmsmFocADCMax = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_ADC_MAX", mcPmsmFocADCMenu)
    mcPmsmFocADCMax.setVisible(False)
    mcPmsmFocADCMax.setValue(4095)

    mcPmsmFocPhaseU = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEU_MODULE", mcPmsmFocADCMenu)
    mcPmsmFocPhaseU.setLabel("Phase U ADC Module")
    mcPmsmFocPhaseU.setMin(0)
    mcPmsmFocPhaseU.setMax(7)
    mcPmsmFocPhaseU.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['PHASE_U']))

    mcPmsmFocPhaseUCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEU_CH", mcPmsmFocPhaseU)
    mcPmsmFocPhaseUCh.setLabel("Phase U Channel Number")
    mcPmsmFocPhaseUCh.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['PHASE_U_CH']))

    mcPmsmFocPhaseV = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEV_MODULE", mcPmsmFocADCMenu)
    mcPmsmFocPhaseV.setLabel("Phase V ADC Module")
    mcPmsmFocPhaseV.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['PHASE_V']))

    mcPmsmFocPhaseVCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEV_CH", mcPmsmFocPhaseV)
    mcPmsmFocPhaseVCh.setLabel("Phase V Channel Number")
    mcPmsmFocPhaseVCh.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['PHASE_V_CH']))

    mcPmsmFocPot = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_POT_MODULE", mcPmsmFocADCMenu)
    mcPmsmFocPot.setLabel("Potentiometer ADC Module")
    mcPmsmFocPot.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['POT']))

    mcPmsmFocPotCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_POT_CH", mcPmsmFocPot)
    mcPmsmFocPotCh.setLabel("Potentiometer channel number")
    mcPmsmFocPotCh.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['POT_CH']))

    mcPmsmFocDCBusV = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_DCBUSV_MODULE", mcPmsmFocADCMenu)
    mcPmsmFocDCBusV.setLabel("DC Bus Voltage ADC Module")
    mcPmsmFocDCBusV.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['VDC']))

    mcPmsmFocDCBusVCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_DCBUSV_CH", mcPmsmFocDCBusV)
    mcPmsmFocDCBusVCh.setLabel("DC Bus Voltage channel number")
    mcPmsmFocDCBusVCh.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['VDC_CH']))

    mcPmsmFocADCDep = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_ADC_DEP", None)
    mcPmsmFocADCDep.setVisible(False)
    mcPmsmFocADCDep.setDependencies(mcPmsmFocADCChanDep, ["MCPMSMFOC_PHASEU_MODULE", "MCPMSMFOC_ADC_RESOLUTION", "MCPMSMFOC_PHASEU_CH",
    "MCPMSMFOC_PHASEV_MODULE", "MCPMSMFOC_PHASEV_CH", "MCPMSMFOC_POT_MODULE", "MCPMSMFOC_DCBUSV_MODULE", "MCPMSMFOC_POT_CH", "MCPMSMFOC_DCBUSV_CH"])

########################### Control Strategy   #################################

    mcPmsmFocAlgoMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_ALGO_CONF", None)
    mcPmsmFocAlgoMenu.setLabel("Control Strategy")

    mcPmsmFocSym_position_fb = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_POSITION_FB", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_position_fb.setLabel("Select Position Feedback")
    mcPmsmFocSym_position_fb.addKey("SENSORLESS_PLL", "0", "SENSORLESS - PLL Estimator")
    mcPmsmFocSym_position_fb.addKey("SENSORED_ENCODER", "1", "SENSOR - Quadrature Encoder")
    #mcPmsmFocSym_position_fb.addKey("SENSORLESS_ROLO", "1", "SENSORLESS - Luenberger Observer")
    #mcPmsmFocSym_position_fb.addKey("SENSORLESS_SMO", "2", "SENSORLESS - Sliding Mode Observer")
    mcPmsmFocSym_position_fb.setOutputMode("Key")
    mcPmsmFocSym_position_fb.setDisplayMode("Description")

    mcPmsmFocSym_alignment_method = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_ALIGNMENT_METHOD", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_alignment_method.setLabel("Select Startup Alignment Method")
    mcPmsmFocSym_alignment_method.addKey("NO_ALIGNMENT", "0", "No Alignment")
    mcPmsmFocSym_alignment_method.addKey("FORCED_ALIGNMENT", "1", "Forced Alignment")
    #mcPmsmFocSym_alignment_method.addKey("IPD", "2", "Initial Position Detection")
    mcPmsmFocSym_alignment_method.setDefaultValue(1)
    mcPmsmFocSym_alignment_method.setOutputMode("Value")
    mcPmsmFocSym_alignment_method.setDisplayMode("Description")

    mcPmsmFocSym_alignment = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_ALIGNMENT", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_alignment.setLabel("Select Alignment Axis")
    mcPmsmFocSym_alignment.addKey("Q_AXIS", "0", "Q Axis")
    mcPmsmFocSym_alignment.addKey("D_AXIS", "1", "D Axis")
    mcPmsmFocSym_alignment.setOutputMode("Value")
    mcPmsmFocSym_alignment.setDisplayMode("Description")

    mcPmsmFocSym_curr_meas = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_CURRENT_MEAS", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_curr_meas.setLabel("Select Current Measurement Method")
    mcPmsmFocSym_curr_meas.addKey("DUAL_SHUNT", "0", "Dual Shunt Current")
    #mcPmsmFocSym_curr_meas.addKey("SINGLE_SHUNT", "0", "Single Shunt Current")
    mcPmsmFocSym_curr_meas.setOutputMode("Value")
    mcPmsmFocSym_curr_meas.setDisplayMode("Description")

    mcPmsmFocSym_open_loop = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_OPEN_LOOP", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_open_loop.setLabel("Run in Open Loop?")
    mcPmsmFocSym_open_loop.setDependencies(mcPmsmFocEncoderHide, ["MCPMSMFOC_POSITION_FB"])

    mcPmsmFocSym_torque_mode = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_TORQUE_MODE", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_torque_mode.setLabel("Run in Torque Mode?")

    mcPmsmFocSym_field_weakening = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_FIELD_WEAKENING", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_field_weakening.setLabel("Enable Field Weakening?")

########################### Motor Parameters   #################################

    mcPmsmFocMotorMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_MOTOR_CONF", None)
    mcPmsmFocMotorMenu.setLabel("Motor Parameters")

    mcPmsmFocSym_motor = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_SEL", mcPmsmFocMotorMenu)
    mcPmsmFocSym_motor.setLabel("Select Motor")
    mcPmsmFocSym_motor.addKey("CUSTOM", "0", "Custom")
    mcPmsmFocSym_motor.addKey("LONG_HURST", "1", "Long Hurst")
    mcPmsmFocSym_motor.addKey("SMALL_HURST", "2", "Small Hurst")
    mcPmsmFocSym_motor.addKey("LEADSHINE", "3", "Leadshine")
    mcPmsmFocSym_motor.setOutputMode("Key")
    mcPmsmFocSym_motor.setDisplayMode("Description")
    mcPmsmFocSym_motor.setDefaultValue(1)   # Long hurst

    mcPmsmFocSym_ph_res = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_R", mcPmsmFocSym_motor)
    mcPmsmFocSym_ph_res.setLabel("Phase Resistance (ohms)")
    mcPmsmFocSym_ph_res.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['R']))

    mcPmsmFocSym_ph_ld = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LD", mcPmsmFocSym_motor)
    mcPmsmFocSym_ph_ld.setLabel("Phase Direct Axis Inductance Ld (Henry)")
    mcPmsmFocSym_ph_ld.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['LD']))

    mcPmsmFocSym_ph_lq = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LQ", mcPmsmFocSym_motor)
    mcPmsmFocSym_ph_lq.setLabel("Phase Quadrature Axis Inductance Lq (Henry)")
    mcPmsmFocSym_ph_lq.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['LQ']))

    mcPmsmFocSym_pole_pairs = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_POLE_PAIRS", mcPmsmFocSym_motor)
    mcPmsmFocSym_pole_pairs.setLabel("Motor Pole Pairs")
    mcPmsmFocSym_pole_pairs.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['POLE_PAIRS']))

    mcPmsmFocSym_bemf_const = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_BEMF_CONST", mcPmsmFocSym_motor)
    mcPmsmFocSym_bemf_const.setLabel("Motor BEMF Constant (Vpk L-L/KRPM)")
    mcPmsmFocSym_bemf_const.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['BEMF_CONST']))

    mcPmsmFocSym_rated_speed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_RATED_SPEED", mcPmsmFocSym_motor)
    mcPmsmFocSym_rated_speed.setLabel("Motor Rated Speed (RPM)")
    mcPmsmFocSym_rated_speed.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['RATED_SPEED']))

    mcPmsmFocSym_max_speed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_SPEED", mcPmsmFocSym_motor)
    mcPmsmFocSym_max_speed.setLabel("Motor Max Speed (RPM)")
    mcPmsmFocSym_max_speed.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['MAX_SPEED']))

    mcPmsmFocSym_max_fw_current = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_FW_CURRENT", mcPmsmFocSym_motor)
    mcPmsmFocSym_max_fw_current.setLabel("Motor Max Field Waekning Negative Current (A)")
    mcPmsmFocSym_max_fw_current.setMin(-1000.0)
    mcPmsmFocSym_max_fw_current.setMax(1000.0)
    mcPmsmFocSym_max_fw_current.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['MAX_FW_CURRENT']))

    mcPmsmFocSym_qe_pulses_per_rev = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_QE_PULSES_PER_REV", mcPmsmFocSym_motor)
    mcPmsmFocSym_qe_pulses_per_rev.setLabel("Encoder Pulses Per Revolution")
    mcPmsmFocSym_qe_pulses_per_rev.setVisible(False)
    mcPmsmFocSym_qe_pulses_per_rev.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['QE_PULSES_PER_REV']))
    mcPmsmFocSym_qe_pulses_per_rev.setDependencies(mcPmsmFocEncoderVisibility, ["MCPMSMFOC_POSITION_FB"])

    mcPmsmFocSym_max_motor_current = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_MOTOR_CURRENT", mcPmsmFocSym_motor)
    mcPmsmFocSym_max_motor_current.setLabel("Max Motor Current (A)")
    mcPmsmFocSym_max_motor_current.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['MAX_MOTOR_CURRENT']))

    mcPmsmFocSym_motor_params = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_MOTOR_PARAMS", mcPmsmFocSym_motor)
    mcPmsmFocSym_motor_params.setVisible(False)
    mcPmsmFocSym_motor_params.setDependencies(mcPmsmFocMotorParamSet, ["MCPMSMFOC_MOTOR_SEL"])

########################### Board Parameters   #################################

    mcPmsmFocBoardMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_BOARD_CONF", None)
    mcPmsmFocBoardMenu.setLabel("Board Parameters")

    mcPmsmFocSym_board = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_BOARD_SEL", mcPmsmFocBoardMenu)
    mcPmsmFocSym_board.setLabel("Select Board")
    mcPmsmFocSym_board.addKey("Custom", "0", "Custom Board")
    mcPmsmFocSym_board.addKey("MCLV2", "1", "MCLV2 - Low Voltage Board")
    mcPmsmFocSym_board.addKey("MCHV3", "2", "MCHV3 - High Voltage Board")
    mcPmsmFocSym_board.setDefaultValue(1)   #MCLV2

    mcPmsmFocSym_max_board_current = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_CURRENT", mcPmsmFocSym_board)
    mcPmsmFocSym_max_board_current.setLabel("Max Board Current (A)")
    mcPmsmFocSym_max_board_current.setDefaultValue(float(mcPmsmFocBoardParamDict['MCLV2']['MAX_CURRENT']))

    mcPmsmFocSym_dc_bus_volt = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_VOLT", mcPmsmFocSym_board)
    mcPmsmFocSym_dc_bus_volt.setLabel("DC Bus Voltage (V)")
    mcPmsmFocSym_dc_bus_volt.setDefaultValue(float(mcPmsmFocBoardParamDict['MCLV2']['DC_BUS_VOLT']))

    mcPmsmFocSym_dc_bus_ratio = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_RATIO", mcPmsmFocSym_board)
    mcPmsmFocSym_dc_bus_ratio.setLabel("DC Bus Voltage Divider Ratio")
    mcPmsmFocSym_dc_bus_ratio.setDefaultValue(float(mcPmsmFocBoardParamDict['MCLV2']['DC_BUS_RATIO']))

    availablePinDictionary = {}

    # Send message to core to get available pins
    availablePinDictionary = Database.sendMessage("core", "PIN_LIST", availablePinDictionary)

    global mcPmsmFocSym_start_button
    mcPmsmFocSym_start_button = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_START_BUTTON", mcPmsmFocSym_board)
    mcPmsmFocSym_start_button.setLabel("Start/Stop Switch")
    mcPmsmFocSym_start_button.setOutputMode("Key")
    mcPmsmFocSym_start_button.setDisplayMode("Key")
    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcPmsmFocSym_start_button.addKey(pad, str(i), pad)
        i = i+1
    mcPmsmFocSym_start_button.setSelectedKey(str(mcPmsmFocBoardParamDict['MCLV2']['START_STOP_SWITCH']))

    global mcPmsmFocSym_dir_button
    mcPmsmFocSym_dir_button = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_DIRECTION_BUTTON", mcPmsmFocSym_board)
    mcPmsmFocSym_dir_button.setLabel("Direction Toggle Switch")
    mcPmsmFocSym_dir_button.setOutputMode("Key")
    mcPmsmFocSym_dir_button.setDisplayMode("Key")
    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcPmsmFocSym_dir_button.addKey(pad, str(i), pad)
        i = i+1
    mcPmsmFocSym_dir_button.setSelectedKey(str(mcPmsmFocBoardParamDict['MCLV2']['DIRECTION_SWITCH']))

    global mcPmsmFocSym_dir_led
    mcPmsmFocSym_dir_led = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_DIRECTION_LED", mcPmsmFocSym_board)
    mcPmsmFocSym_dir_led.setLabel("Direction LED")
    mcPmsmFocSym_dir_led.setOutputMode("Key")
    mcPmsmFocSym_dir_led.setDisplayMode("Key")
    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcPmsmFocSym_dir_led.addKey(pad, str(i), pad)
        i = i+1
    mcPmsmFocSym_dir_led.setSelectedKey(str(mcPmsmFocBoardParamDict['MCLV2']['DIRECTION_LED']))

    global mcPmsmFocSym_fault_led
    mcPmsmFocSym_fault_led = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_FAULT_LED", mcPmsmFocSym_board)
    mcPmsmFocSym_fault_led.setLabel("Fault LED")
    mcPmsmFocSym_fault_led.setOutputMode("Key")
    mcPmsmFocSym_fault_led.setDisplayMode("Key")
    i = 0
    for pad in sort_alphanumeric(availablePinDictionary.values()):
        mcPmsmFocSym_fault_led.addKey(pad, str(i), pad)
        i = i+1
    mcPmsmFocSym_fault_led.setSelectedKey(str(mcPmsmFocBoardParamDict['MCLV2']['FAULT_LED']))

    mcPmsmFocSym_pin_comment = mcPmsmFocComponent.createCommentSymbol("MCPMSMFOC_PIN_COMMENT", mcPmsmFocSym_board)
    mcPmsmFocSym_pin_comment.setLabel("**** Configure pins in the Pin Manager ****")

    mcPmsmFocSym_board_params = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_BOARD_PARAMS", mcPmsmFocSym_board)
    mcPmsmFocSym_board_params.setVisible(False)
    mcPmsmFocSym_board_params.setDependencies(mcPmsmFocBoardParamSet, ["MCPMSMFOC_BOARD_SEL"])

########################### Control Parameters   #################################

    mcPmsmFocCtrlMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_CTRL_CONF", None)
    mcPmsmFocCtrlMenu.setLabel("Control Parameters")

    mcPmsmFocStartupMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_STARTUP", mcPmsmFocCtrlMenu)
    mcPmsmFocStartupMenu.setLabel("Startup Parameters")

    mcPmsmFocSym_lock_time = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LOCK_TIME", mcPmsmFocStartupMenu)
    mcPmsmFocSym_lock_time.setLabel("Alignment Lock Time (sec)")
    mcPmsmFocSym_lock_time.setDefaultValue(2)

    mcPmsmFocSym_open_loop_ramp_time = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_RAMP_TIME", mcPmsmFocStartupMenu)
    mcPmsmFocSym_open_loop_ramp_time.setLabel("Open Loop Ramp Time (sec)")
    mcPmsmFocSym_open_loop_ramp_time.setDefaultValue(5)

    mcPmsmFocSym_ol_end_speed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_END_SPEED", mcPmsmFocStartupMenu)
    mcPmsmFocSym_ol_end_speed.setLabel("Open Loop End Speed (RPM)")
    mcPmsmFocSym_ol_end_speed.setDefaultValue(500)

    mcPmsmFocSym_ol_iq_ref = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_IQ_REF", mcPmsmFocStartupMenu)
    mcPmsmFocSym_ol_iq_ref.setLabel("Open Loop Ref Quadrature Current (A)")
    mcPmsmFocSym_ol_iq_ref.setDefaultValue(0.4)

    mcPmsmFocIdPIMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Id_Menu", mcPmsmFocCtrlMenu)
    mcPmsmFocIdPIMenu.setLabel("Direct current (Id) PI Parameters")

    mcPmsmFocSym_Id_Kp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KP", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_Kp.setLabel("Kp")
    mcPmsmFocSym_Id_Kp.setDefaultValue(0.02)

    mcPmsmFocSym_Id_Ki = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KI", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_Ki.setLabel("Ki")
    mcPmsmFocSym_Id_Ki.setDefaultValue(0.00005)

    mcPmsmFocSym_Id_Kc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KC", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_Kc.setLabel("Kc")
    mcPmsmFocSym_Id_Kc.setDefaultValue(0.5)

    mcPmsmFocSym_Id_out_max = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_OUT_MAX", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_out_max.setLabel("Max Output")
    mcPmsmFocSym_Id_out_max.setDefaultValue(0.999)

    mcPmsmFocIqPIMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Iq_Menu", mcPmsmFocCtrlMenu)
    mcPmsmFocIqPIMenu.setLabel("Quadrature current (Iq) PI Parameters")

    mcPmsmFocSym_Iq_Kp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KP", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_Kp.setLabel("Kp")
    mcPmsmFocSym_Iq_Kp.setDefaultValue(0.02)

    mcPmsmFocSym_Iq_Ki = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KI", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_Ki.setLabel("Ki")
    mcPmsmFocSym_Iq_Ki.setDefaultValue(0.00005)

    mcPmsmFocSym_Iq_Kc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KC", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_Kc.setLabel("Kc")
    mcPmsmFocSym_Iq_Kc.setDefaultValue(0.5)

    mcPmsmFocSym_Iq_out_max = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_OUT_MAX", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_out_max.setLabel("Max Output")
    mcPmsmFocSym_Iq_out_max.setDefaultValue(0.999)

    mcPmsmFocSpeedPIMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Speed_Menu", mcPmsmFocCtrlMenu)
    mcPmsmFocSpeedPIMenu.setLabel("Speed PI Parameters")

    mcPmsmFocSym_speed_Kp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KP", mcPmsmFocSpeedPIMenu)
    mcPmsmFocSym_speed_Kp.setLabel("Kp")
    mcPmsmFocSym_speed_Kp.setDefaultValue(0.005)

    mcPmsmFocSym_speed_Ki = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KI", mcPmsmFocSpeedPIMenu)
    mcPmsmFocSym_speed_Ki.setLabel("Ki")
    mcPmsmFocSym_speed_Ki.setDefaultValue(0.000020)

    mcPmsmFocSym_speed_Kc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KC", mcPmsmFocSpeedPIMenu)
    mcPmsmFocSym_speed_Kc.setLabel("Kc")
    mcPmsmFocSym_speed_Kc.setDefaultValue(0.5)

    mcPmsmFocSym_speed_out_max = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_OUT_MAX", mcPmsmFocSpeedPIMenu)
    mcPmsmFocSym_speed_out_max.setLabel("Max Output")
    mcPmsmFocSym_speed_out_max.setDefaultValue(mcPmsmFocSym_max_board_current.getValue())

###################################################################################################
########################### Code Generation   #################################
###################################################################################################
    configName = Variables.get("__CONFIGURATION_NAME")

    mcPmsmFocSystemDefFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_DEF", None)
    mcPmsmFocSystemDefFile.setType("STRING")
    mcPmsmFocSystemDefFile.setOutputName("core.LIST_SYSTEM_DEFINITIONS_H_INCLUDES")
    mcPmsmFocSystemDefFile.setSourcePath("/algorithms/pmsm_foc/templates/system/definitions.h.ftl")
    mcPmsmFocSystemDefFile.setMarkup(True)

    mcPmsmFocSystemInitFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_INIT", None)
    mcPmsmFocSystemInitFile.setType("STRING")
    mcPmsmFocSystemInitFile.setOutputName("core.LIST_SYSTEM_INIT_C_INITIALIZE_MIDDLEWARE")
    mcPmsmFocSystemInitFile.setSourcePath("/algorithms/pmsm_foc/templates/system/initialization.c.ftl")
    mcPmsmFocSystemInitFile.setMarkup(True)

    mcPmsmFocPosSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POSCFILE", None)
    mcPmsmFocPosSourceFile.setSourcePath("/algorithms/pmsm_foc/templates/pos_pll.c.ftl")
    mcPmsmFocPosSourceFile.setOutputName("mc_rotorposition.c")
    mcPmsmFocPosSourceFile.setDestPath("motor_control/pmsm_foc/")
    mcPmsmFocPosSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
    mcPmsmFocPosSourceFile.setType("SOURCE")
    mcPmsmFocPosSourceFile.setMarkup(True)

    mcPmsmFocPosHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POSHFILE", None)
    mcPmsmFocPosHeaderFile.setSourcePath("/algorithms/pmsm_foc/templates/pos_pll.h.ftl")
    mcPmsmFocPosHeaderFile.setOutputName("mc_rotorposition.h")
    mcPmsmFocPosHeaderFile.setDestPath("motor_control/pmsm_foc/")
    mcPmsmFocPosHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
    mcPmsmFocPosHeaderFile.setType("HEADER")
    mcPmsmFocPosHeaderFile.setMarkup(True)

    for root, dirs, files in os.walk(Module.getPath()+"/algorithms/pmsm_foc/templates/"):
        for filename in files:
            if (".c" in filename and "mc_" in filename):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath("/algorithms/pmsm_foc/templates/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("motor_control/pmsm_foc/")
                mcPmsmFocSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)

            if (".h" in filename and "mc_" in filename):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath("/algorithms/pmsm_foc/templates/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("motor_control/pmsm_foc/")
                mcPmsmFocHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)
