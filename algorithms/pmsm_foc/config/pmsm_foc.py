# coding: utf-8
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

###################################################################################################
########################### Global variables   #################################
###################################################################################################

import os

global mcPmsmFocInstanceName
global mcPmsmFocSeries
global mcPmsmFocAdc
global mcPmsmFocPWM
global mcPmsmFocEncoder

global mcPmsmFocSym_start_button
global mcPmsmFocSym_dir_button
global mcPmsmFocSym_dir_led
global mcPmsmFocSym_fault_led

global mcPmsmFocSym_max_board_current
global mcPmsmFocSym_dc_bus_volt
global mcPmsmFocSym_dc_bus_ratio

global mcPmsmFocSym_ph_res
global mcPmsmFocSym_ph_ld
global mcPmsmFocSym_ph_lq
global mcPmsmFocSym_pole_pairs
global mcPmsmFocSym_bemf_const
global mcPmsmFocSym_rated_speed
global mcPmsmFocSym_max_speed
global mcPmsmFocSym_max_fw_current
global mcPmsmFocSym_max_motor_current
global mcPmsmFocDeadTime


# Motor parameters
mcPmsmFocMotorParamDict = {'LONG_HURST' : { 'R'           : 0.285,
                                            'LD'          : 0.00032,
                                            'LQ'          : 0.00032,
                                            'BEMF_CONST'  : 7.24,
                                            'POLE_PAIRS'  : 5,
                                            'RATED_SPEED' : 2804,
                                            'MAX_SPEED'   : 3500,
                                            'MAX_FW_CURRENT' : -2.0,
                                            'QE_PULSES_PER_REV' : 250,
                                            'MAX_MOTOR_CURRENT' : 4.0 ,
                                            'MOTOR_CONNECTION'  : "STAR",
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
                                              'MOTOR_CONNECTION'  : "STAR",
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
                                              'MOTOR_CONNECTION'  : "STAR",
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

# PI controller Parameters
mcPmsmFocCurrentPIDict = { 'MCLV2' :       {'KP' : 0.02,
                                            'KI' : 0.000099
                                            },
                           'MCHV3' :       {'KP' : 0.02,
                                            'KI' : 0.000099
                                           },
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
                                                            'RESOLUTION'    : 12,
                                                            'TRIGGER'       : 1,
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
                                                            'RESOLUTION'    : 12,
                                                            'TRIGGER'       : 1
                                                          },
                                    },
                        }
# ADC dictionary used to send message to ADC PLIB
adcChDict = {}

# PWM channels per board per device
mcPmsmFocMclv2PwmDict = {'MCLV2' : {
                                    'PIC32MK':   { 'PWM_FREQ' : 20000,
                                                    'PWM_PH_U' : '1',
                                                    'PWM_PH_V' : '2',
                                                    'PWM_PH_W' : '3',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FLT15',
                                                },
                                    },
                         'MCHV3'  : {
                                    'PIC32MK':   { 'PWM_FREQ' : 10000,
                                                    'PWM_PH_U' : '1',
                                                    'PWM_PH_V' : '2',
                                                    'PWM_PH_W' : '3',
                                                    'PWM_DEAD_TIME': '1',
                                                    'PWM_FAULT': 'FLT15',
                                                },

                                    }
                        }

#PWM dictionary used to send message to PWM PLIB
pwmDict = {}

#Encoder dictionary used to send message to Encoder plib
encoderDict = {}


global sort_alphanumeric

def sort_alphanumeric(l):
    import re
    convert = lambda text: int(text) if text.isdigit() else text.lower()
    alphanum_key = lambda key: [ convert(c) for c in re.split('([0-9]+)', key) ]
    return sorted(l, key = alphanum_key)
###################################################################################################
########################### Callback Functions   #################################
###################################################################################################
def mcPmsmFocCodeGenUpdate(symbol, event):
    component = symbol.getComponent()
    component.getSymbolByID("MCPMSMFOC_POS_PLL_HEADER").setEnabled(False)
    component.getSymbolByID("MCPMSMFOC_POS_PLL_SOURCE").setEnabled(False)
    component.getSymbolByID("MCPMSMFOC_POS_ENCODER_HEADER").setEnabled(False)
    component.getSymbolByID("MCPMSMFOC_POS_ENCODER_SOURCE").setEnabled(False)

    if event["value"] == 0: #PLL
        component.getSymbolByID("MCPMSMFOC_POS_PLL_HEADER").setEnabled(True)
        component.getSymbolByID("MCPMSMFOC_POS_PLL_SOURCE").setEnabled(True)
    elif event["value"] == 1:  #Encoder
        component.getSymbolByID("MCPMSMFOC_POS_ENCODER_HEADER").setEnabled(True)
        component.getSymbolByID("MCPMSMFOC_POS_ENCODER_SOURCE").setEnabled(True)


# Display selected motor parameters
def mcPmsmFocMotorParamSet(symbol, event):
    motor_key = event["symbol"].getKeyForValue(str(event["value"]))
    component = mcPmsmFocInstanceName.getValue().lower()
    if motor_key in mcPmsmFocMotorParamDict.keys():
        mcPmsmFocSym_ph_res.setValue(float(mcPmsmFocMotorParamDict[motor_key]['R']))
        mcPmsmFocSym_ph_ld.setValue(float(mcPmsmFocMotorParamDict[motor_key]['LD']))
        mcPmsmFocSym_ph_lq.setValue(float(mcPmsmFocMotorParamDict[motor_key]['LQ']))
        mcPmsmFocSym_pole_pairs.setValue(float(mcPmsmFocMotorParamDict[motor_key]['POLE_PAIRS']))
        mcPmsmFocSym_bemf_const.setValue(float(mcPmsmFocMotorParamDict[motor_key]['BEMF_CONST']))
        mcPmsmFocSym_rated_speed.setValue(float(mcPmsmFocMotorParamDict[motor_key]['RATED_SPEED']))
        mcPmsmFocSym_max_speed.setValue(float(mcPmsmFocMotorParamDict[motor_key]['MAX_SPEED']))
        mcPmsmFocSym_max_fw_current.setValue(float(mcPmsmFocMotorParamDict[motor_key]['MAX_FW_CURRENT']))
        Database.setSymbolValue(component, "MCPMSMFOC_QE_PULSES_PER_REV", int(mcPmsmFocMotorParamDict[motor_key]['QE_PULSES_PER_REV']))
        mcPmsmFocSym_max_motor_current.setValue(float(mcPmsmFocMotorParamDict[motor_key]['MAX_MOTOR_CURRENT']))
        mcPmsmFocSym_connection.setSelectedKey(mcPmsmFocMotorParamDict[motor_key]['MOTOR_CONNECTION'])

# Display selected board parameters
def mcPmsmFocBoardParamSet(symbol, event):
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    component = mcPmsmFocInstanceName.getValue().lower()
    series = mcPmsmFocSeries.getValue()
    if board_key in mcPmsmFocBoardParamDict.keys():

        mcPmsmFocSym_max_board_current.setValue(float(mcPmsmFocBoardParamDict[board_key]['MAX_CURRENT']))
        mcPmsmFocSym_dc_bus_volt.setValue(float(mcPmsmFocBoardParamDict[board_key]['DC_BUS_VOLT']))
        mcPmsmFocSym_dc_bus_ratio.setValue(float(mcPmsmFocBoardParamDict[board_key]['DC_BUS_RATIO']))

        mcPmsmFocSym_start_button.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['START_STOP_SWITCH']))
        mcPmsmFocSym_dir_button.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['DIRECTION_SWITCH']))
        mcPmsmFocSym_dir_led.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['DIRECTION_LED']))
        mcPmsmFocSym_fault_led.setSelectedKey((mcPmsmFocBoardParamDict[board_key]['FAULT_LED']))

        #PWM
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_BOARD_DEP", True)
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_FREQ", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_FREQ']))
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_PH_U", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_PH_U']))
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_PH_V", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_PH_V']))
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_PH_W", int(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_PH_W']))
        mcPmsmFocDeadTime.setValue(float(mcPmsmFocMclv2PwmDict[board_key][series]['PWM_DEAD_TIME']))
        mcPmsmFocPwmFault.setSelectedKey((mcPmsmFocMclv2PwmDict[board_key][series]['PWM_FAULT']))
        Database.setSymbolValue(component, "MCPMSMFOC_PWM_BOARD_DEP", False)

        #ADC
        Database.setSymbolValue(component, "MCPMSMFOC_ADC_BOARD_DEP", True)
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEU_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_U']))
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEU_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_U_CH']))
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEV_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_V']))
        Database.setSymbolValue(component, "MCPMSMFOC_PHASEV_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['PHASE_V_CH']))
        Database.setSymbolValue(component, "MCPMSMFOC_POT_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['POT']))
        Database.setSymbolValue(component, "MCPMSMFOC_POT_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['POT_CH']))
        Database.setSymbolValue(component, "MCPMSMFOC_DCBUSV_MODULE", int(mcPmsmFocMclv2ADCDict[board_key][series]['VDC']))
        Database.setSymbolValue(component, "MCPMSMFOC_DCBUSV_CH", int(mcPmsmFocMclv2ADCDict[board_key][series]['VDC_CH']))
        Database.setSymbolValue(component, "MCPMSMFOC_ADC_BOARD_DEP", True)

def mcPmsmFocEncoderVisibility(symbol, event):
    if(event["value"] == 1):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

def mcPmsmFocEncoderHide(symbol, event):
    component = symbol.getComponent()
    if(event["value"] == 1):
        symbol.setVisible(False)
        component.setDependencyEnabled("QDEC", True)
    else:
        symbol.setVisible(True)
        component.setDependencyEnabled("QDEC", False)

def mcPmsmFocVisibleOnTrue(symbol, event):
    symbol.setVisible(event["value"])

def mcPmsmFocSpeedRefVisible(symbol, event):
    component = symbol.getComponent()
    if component.getSymbolValue("MCPMSMFOC_SPEED_REF") == "Potentiometer Analog Input":
        symbol.setVisible(False)
    else:
        symbol.setVisible(True)
    symbol.setMax(component.getSymbolValue("MCPMSMFOC_RATED_SPEED"))

def mcPmsmFocFWMax(symbol, event):
    component = symbol.getComponent()
    motorCurrent = component.getSymbolValue("MCPMSMFOC_MAX_MOTOR_CURRENT")
    symbol.setMin(-motorCurrent)
    fw = component.getSymbolValue("MCPMSMFOC_FIELD_WEAKENING")
    symbol.setVisible((fw))

def mcPmsmFocPIValueChange(symbol, event):
    if(event["value"] == 1): #encoder
        symbol.setValue(0.000005)
    else:
        symbol.setValue(0.000099)

def mcPmsmFocCurrentKpCalc(symbol, event):
    component = symbol.getComponent()
    board = component.getSymbolByID("MCPMSMFOC_BOARD_SEL").getSelectedKey()
    ld = component.getSymbolValue("MCPMSMFOC_LD")
    lq = component.getSymbolValue("MCPMSMFOC_LQ")
    connection = component.getSymbolByID("MCPMSMFOC_MOTOR_CONNECTION").getSelectedKey()
    if (connection == "STAR"):
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT") / 1.713
    else:
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT")
    bandwidth = component.getSymbolValue("MCPMSMFOC_CL_BANDWIDTH")
    autoCalc = component.getSymbolValue("MCPMSMFOC_CL_AUTOCALCULATE")
    l = (ld+lq)/2
    kp = symbol.getValue()

    if autoCalc == True:
        kp = (bandwidth * l) / max_volt
    else:
        if board in mcPmsmFocBoardParamDict.keys():
            kp = mcPmsmFocCurrentPIDict[board]['KP']
    symbol.setValue(kp)


def mcPmsmFocCurrentKiCalc(symbol, event):
    component = symbol.getComponent()
    board = component.getSymbolByID("MCPMSMFOC_BOARD_SEL").getSelectedKey()
    r = component.getSymbolValue("MCPMSMFOC_R")
    connection = component.getSymbolByID("MCPMSMFOC_MOTOR_CONNECTION").getSelectedKey()
    if (connection == "STAR"):
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT") / 1.713
    else:
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT")
    pwm_time = 1.0 / component.getSymbolValue("MCPMSMFOC_PWM_FREQ")
    bandwidth = component.getSymbolValue("MCPMSMFOC_CL_BANDWIDTH")
    autoCalc = component.getSymbolValue("MCPMSMFOC_CL_AUTOCALCULATE")
    ki = symbol.getValue()
    if autoCalc == True:
        ki = (bandwidth * r * pwm_time) / max_volt
    else:
        if board in mcPmsmFocBoardParamDict.keys():
            ki = mcPmsmFocCurrentPIDict[board]['KI']
    symbol.setValue(ki)

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
    adcChDict['TRIGGER'] = (component.getSymbolValue("MCPMSMFOC_PWM_PH_U"))
    mcPmsmFocADCMax.setValue(pow(2,int(adcChDict['RESOLUTION'])) - 1)
    if (component.getSymbolValue("MCPMSMFOC_ADC_BOARD_DEP") == False):
        Database.sendMessage(mcPmsmFocAdc.getValue().lower(), "PMSM_FOC_ADC_CH_CONF", adcChDict)

#Send message to PWM PLIB when PWM channels are changed
def mcPmsmFocPwmPlibDep(symbol, event):
    global mcPmsmFocPwmFault
    component = symbol.getComponent()
    pwmDict['PWM_FREQ'] = (component.getSymbolValue("MCPMSMFOC_PWM_FREQ"))
    pwmDict['PWM_PH_U'] = (component.getSymbolValue("MCPMSMFOC_PWM_PH_U"))
    pwmDict['PWM_PH_V'] = (component.getSymbolValue("MCPMSMFOC_PWM_PH_V"))
    pwmDict['PWM_PH_W'] = (component.getSymbolValue("MCPMSMFOC_PWM_PH_W"))
    pwmDict['PWM_DEAD_TIME'] = (component.getSymbolValue("MCPMSMFOC_PWM_DEAD_TIME"))
    pwmDict['PWM_FAULT'] = (mcPmsmFocPwmFault.getSelectedKey())
    if (component.getSymbolValue("MCPMSMFOC_PWM_BOARD_DEP") == False):
        print("****************************************************")
        Database.sendMessage(mcPmsmFocPWM.getValue().lower(), "PMSM_FOC_PWM_CONF", pwmDict)

#Send message to Encoder PLIB when encoder configurations are changed
def mcPmsmFocEncoderPlibDep(symbol, event):
    component = symbol.getComponent()
    pulses = (float(component.getSymbolValue("MCPMSMFOC_QE_PULSES_PER_REV")) * 4) / component.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
    encoderDict['PULSES_PER_REV'] = pulses
    Database.sendMessage(mcPmsmFocEncoder.getValue().lower(), "PMSM_FOC_ENCODER_CONF", encoderDict)
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
    adcChDict['TRIGGER'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_U"))

    pwmDict['PWM_FREQ'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_FREQ"))
    pwmDict['PWM_PH_U'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_U"))
    pwmDict['PWM_PH_V'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_V"))
    pwmDict['PWM_PH_W'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_PH_W"))
    pwmDict['PWM_DEAD_TIME'] = (localComponent.getSymbolValue("MCPMSMFOC_PWM_DEAD_TIME"))
    pwmDict['PWM_FAULT'] = (mcPmsmFocPwmFault.getSelectedKey())

    pulses = (float(localComponent.getSymbolValue("MCPMSMFOC_QE_PULSES_PER_REV")) * 4) / localComponent.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
    encoderDict['PULSES_PER_REV'] = pulses

    if (connectID == "ADC"):
        Database.sendMessage(remoteID, "PMSM_FOC_ADC_CH_CONF", adcChDict)
        mcPmsmFocAdc.setValue(remoteID)

    if (connectID == "PWM"):
        Database.sendMessage(remoteID, "PMSM_FOC_PWM_CONF", pwmDict)
        mcPmsmFocPWM.setValue(remoteID)

    if (connectID == "QDEC"):
        Database.sendMessage(remoteID, "PMSM_FOC_ENCODER_CONF", encoderDict)
        mcPmsmFocEncoder.setValue(remoteID)

def onAttachmentDisconnected(source, target):
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    connectID = source["id"]
    targetID = target["id"]

    if (connectID == "ADC"):
        mcPmsmFocAdc.setValue("None")

    if (connectID == "PWM"):
        mcPmsmFocPWM.setValue("None")

    if (connectID == "QDEC"):
        mcPmsmFocEncoder.setValue("None")

###################################################################################################
########################### Component   #################################
###################################################################################################
def instantiateComponent(mcPmsmFocComponent):
    global mcPmsmFocSeries
    global mcPmsmFocInstanceName
    global mcPmsmFocAdc
    global mcPmsmFocPWM
    global mcPmsmFocEncoder

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

    mcPmsmFocEncoder = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_ENCODERPLIB", None)
    mcPmsmFocEncoder.setVisible(False)

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

    global mcPmsmFocDeadTime
    mcPmsmFocDeadTime = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_PWM_DEAD_TIME", mcPmsmFocPwmMenu)
    mcPmsmFocDeadTime.setLabel("Dead Time (uS)")
    mcPmsmFocDeadTime.setDefaultValue(float(mcPmsmFocMclv2PwmDict['MCLV2'][mcPmsmFocSeries.getValue()]['PWM_DEAD_TIME']))
    mcPmsmFocDeadTime.setMin(0.1)
    mcPmsmFocDeadTime.setMax(10)

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

    msPmsmFocPwmBoardDep = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_PWM_BOARD_DEP", mcPmsmFocPwmMenu)
    msPmsmFocPwmBoardDep.setVisible(False)
    msPmsmFocPwmBoardDep.setDefaultValue(False)

    mcPmsmFocPWMDep = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PWM_DEP", None)
    mcPmsmFocPWMDep.setVisible(False)
    mcPmsmFocPWMDep.setDependencies(mcPmsmFocPwmPlibDep, ["MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_PWM_PH_U",
        "MCPMSMFOC_PWM_PH_V", "MCPMSMFOC_PWM_PH_W", "MCPMSMFOC_PWM_FAULT", "MCPMSMFOC_PWM_DEAD_TIME", "MCPMSMFOC_PWM_BOARD_DEP"])

########################### ADC Configurations#################################
    mcPmsmFocADCMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_ADC_MENU", None)
    mcPmsmFocADCMenu.setLabel("ADC Configurations")

    resolution = ["12", "10", "8", "6"]
    mcPmsmFocADCResolution = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_ADC_RESOLUTION", mcPmsmFocADCMenu, resolution)
    mcPmsmFocADCResolution.setLabel("Select ADC Resolution")
    mcPmsmFocADCResolution.setReadOnly(False)

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
    mcPmsmFocPhaseV.setMin(0)
    mcPmsmFocPhaseV.setMax(7)
    mcPmsmFocPhaseV.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['PHASE_V']))

    mcPmsmFocPhaseVCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_PHASEV_CH", mcPmsmFocPhaseV)
    mcPmsmFocPhaseVCh.setLabel("Phase V Channel Number")
    mcPmsmFocPhaseVCh.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['PHASE_V_CH']))

    mcPmsmFocPot = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_POT_MODULE", mcPmsmFocADCMenu)
    mcPmsmFocPot.setLabel("Potentiometer ADC Module")
    mcPmsmFocPot.setMin(0)
    mcPmsmFocPot.setMax(7)
    mcPmsmFocPot.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['POT']))

    mcPmsmFocPotCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_POT_CH", mcPmsmFocPot)
    mcPmsmFocPotCh.setLabel("Potentiometer channel number")
    mcPmsmFocPotCh.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['POT_CH']))

    mcPmsmFocDCBusV = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_DCBUSV_MODULE", mcPmsmFocADCMenu)
    mcPmsmFocDCBusV.setLabel("DC Bus Voltage ADC Module")
    mcPmsmFocDCBusV.setMin(0)
    mcPmsmFocDCBusV.setMax(7)
    mcPmsmFocDCBusV.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['VDC']))

    mcPmsmFocDCBusVCh = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_DCBUSV_CH", mcPmsmFocDCBusV)
    mcPmsmFocDCBusVCh.setLabel("DC Bus Voltage channel number")
    mcPmsmFocDCBusVCh.setDefaultValue(int(mcPmsmFocMclv2ADCDict['MCLV2'][mcPmsmFocSeries.getValue()]['VDC_CH']))

    msPmsmFocAdcBoardDep = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_ADC_BOARD_DEP", mcPmsmFocADCMenu)
    msPmsmFocAdcBoardDep.setVisible(False)
    msPmsmFocAdcBoardDep.setDefaultValue(False)

    mcPmsmFocADCDep = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_ADC_DEP", None)
    mcPmsmFocADCDep.setVisible(False)
    mcPmsmFocADCDep.setDependencies(mcPmsmFocADCChanDep, ["MCPMSMFOC_ADC_BOARD_DEP", "MCPMSMFOC_PWM_PH_U", "MCPMSMFOC_PHASEU_MODULE", "MCPMSMFOC_ADC_RESOLUTION", "MCPMSMFOC_PHASEU_CH",
    "MCPMSMFOC_PHASEV_MODULE", "MCPMSMFOC_PHASEV_CH", "MCPMSMFOC_POT_MODULE", "MCPMSMFOC_DCBUSV_MODULE", "MCPMSMFOC_POT_CH", "MCPMSMFOC_DCBUSV_CH"])

######################################### Encoder ##############################
    mcPmsmFocEncoderMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_ENCODER", None)
    mcPmsmFocEncoderMenu.setLabel("Encoder Configurations")
    mcPmsmFocEncoderMenu.setVisible(False)

    mcPmsmFocSym_qe_pulses_per_rev = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_QE_PULSES_PER_REV", mcPmsmFocEncoderMenu)
    mcPmsmFocSym_qe_pulses_per_rev.setLabel("Encoder Pulses Per Revolution")
    mcPmsmFocSym_qe_pulses_per_rev.setVisible(True)
    mcPmsmFocSym_qe_pulses_per_rev.setMin(0)
    mcPmsmFocSym_qe_pulses_per_rev.setDefaultValue(int(mcPmsmFocMotorParamDict['LONG_HURST']['QE_PULSES_PER_REV']))

    mcPmsmFocEncoderDep = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_ENCODER_DEP", None)
    mcPmsmFocEncoderDep.setVisible(False)
    mcPmsmFocEncoderDep.setDependencies(mcPmsmFocEncoderPlibDep, ["MCPMSMFOC_QE_PULSES_PER_REV"])

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

    mcPmsmFocSym_curr_meas = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_CURRENT_MEAS", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_curr_meas.setLabel("Select Current Measurement Method")
    mcPmsmFocSym_curr_meas.addKey("DUAL_SHUNT", "0", "Dual Shunt")
    #mcPmsmFocSym_curr_meas.addKey("SINGLE_SHUNT", "0", "Single Shunt")
    mcPmsmFocSym_curr_meas.setOutputMode("Value")
    mcPmsmFocSym_curr_meas.setDisplayMode("Description")

    mcPmsmFocSym_open_loop = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_OPEN_LOOP", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_open_loop.setLabel("Run in Open Loop?")
    mcPmsmFocSym_open_loop.setDependencies(mcPmsmFocEncoderHide, ["MCPMSMFOC_POSITION_FB"])

    mcPmsmFocSym_torque_mode = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_TORQUE_MODE", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_torque_mode.setLabel("Run in Torque Control?")

    mcPmsmFocSym_end_torque = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_END_TORQUE", mcPmsmFocSym_torque_mode)
    mcPmsmFocSym_end_torque.setLabel("Ref. Quadrature Current (A)")
    mcPmsmFocSym_end_torque.setDefaultValue(0.2)
    mcPmsmFocSym_end_torque.setVisible(False)
    mcPmsmFocSym_end_torque.setDependencies(mcPmsmFocVisibleOnTrue, ["MCPMSMFOC_TORQUE_MODE"])

    mcPmsmFocSym_field_weakening = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_FIELD_WEAKENING", mcPmsmFocAlgoMenu)
    mcPmsmFocSym_field_weakening.setLabel("Enable Field Weakening?")

    global mcPmsmFocSym_max_fw_current
    mcPmsmFocSym_max_fw_current = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_FW_CURRENT", mcPmsmFocSym_field_weakening)
    mcPmsmFocSym_max_fw_current.setLabel("Motor Max Field Weakning Negative Current (A)")
    mcPmsmFocSym_max_fw_current.setVisible(False)
    mcPmsmFocSym_max_fw_current.setMin(-4.0)
    mcPmsmFocSym_max_fw_current.setMax(0.0)
    mcPmsmFocSym_max_fw_current.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['MAX_FW_CURRENT']))

    mcPmsmFocEncoderMenu.setDependencies(mcPmsmFocEncoderVisibility, ["MCPMSMFOC_POSITION_FB"])
########################### Motor Parameters   #################################

    mcPmsmFocMotorMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_MOTOR_CONF", None)
    mcPmsmFocMotorMenu.setLabel("Motor Parameters")

    mcPmsmFocSym_motor = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_SEL", mcPmsmFocMotorMenu)
    mcPmsmFocSym_motor.setLabel("Select Motor")
    mcPmsmFocSym_motor.addKey("CUSTOM", "0", "Custom")
    mcPmsmFocSym_motor.addKey("LONG_HURST", "1", "Hurst DMA0204024B101 (with Hall, with Quadrature Encoder) (LV)")
    mcPmsmFocSym_motor.addKey("SMALL_HURST", "2", "Hurst DMB0224C10002 (with Hall, without Quadrature Encoder)  (LV)")
    mcPmsmFocSym_motor.addKey("LEADSHINE", "3", "Leadshine EL5-M0400-1-24 (with Hall, with Quadrature Encoder)  (HV)")
    mcPmsmFocSym_motor.setOutputMode("Key")
    mcPmsmFocSym_motor.setDisplayMode("Description")
    mcPmsmFocSym_motor.setDefaultValue(1)   # Long hurst

    global mcPmsmFocSym_connection
    mcPmsmFocSym_connection = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_CONNECTION", mcPmsmFocSym_motor)
    mcPmsmFocSym_connection.setLabel("Motor Connection")
    mcPmsmFocSym_connection.addKey("STAR", "0", "STAR")
    mcPmsmFocSym_connection.addKey("DELTA", "1", "DELTA")
    mcPmsmFocSym_connection.setOutputMode("Key")
    mcPmsmFocSym_connection.setDisplayMode("Description")
    mcPmsmFocSym_connection.setSelectedKey(mcPmsmFocMotorParamDict['LONG_HURST']['MOTOR_CONNECTION'])

    global mcPmsmFocSym_ph_res
    mcPmsmFocSym_ph_res = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_R", mcPmsmFocSym_motor)
    mcPmsmFocSym_ph_res.setLabel("Phase Resistance (ohms)")
    mcPmsmFocSym_ph_res.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['R']))

    global mcPmsmFocSym_ph_ld
    mcPmsmFocSym_ph_ld = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LD", mcPmsmFocSym_motor)
    mcPmsmFocSym_ph_ld.setLabel("Phase Direct Axis Inductance Ld (Henry)")
    mcPmsmFocSym_ph_ld.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['LD']))

    global mcPmsmFocSym_ph_lq
    mcPmsmFocSym_ph_lq = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LQ", mcPmsmFocSym_motor)
    mcPmsmFocSym_ph_lq.setLabel("Phase Quadrature Axis Inductance Lq (Henry)")
    mcPmsmFocSym_ph_lq.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['LQ']))

    global mcPmsmFocSym_pole_pairs
    mcPmsmFocSym_pole_pairs = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_POLE_PAIRS", mcPmsmFocSym_motor)
    mcPmsmFocSym_pole_pairs.setLabel("Motor Pole Pairs")
    mcPmsmFocSym_pole_pairs.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['POLE_PAIRS']))

    global mcPmsmFocSym_bemf_const
    mcPmsmFocSym_bemf_const = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_BEMF_CONST", mcPmsmFocSym_motor)
    mcPmsmFocSym_bemf_const.setLabel("Motor BEMF Constant (Vpk L-L/KRPM)")
    mcPmsmFocSym_bemf_const.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['BEMF_CONST']))

    global mcPmsmFocSym_rated_speed
    mcPmsmFocSym_rated_speed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_RATED_SPEED", mcPmsmFocSym_motor)
    mcPmsmFocSym_rated_speed.setLabel("Motor Rated Speed (RPM)")
    mcPmsmFocSym_rated_speed.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['RATED_SPEED']))

    global mcPmsmFocSym_max_speed
    mcPmsmFocSym_max_speed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_SPEED", mcPmsmFocSym_motor)
    mcPmsmFocSym_max_speed.setLabel("Motor Max Speed (RPM)")
    mcPmsmFocSym_max_speed.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['MAX_SPEED']))

    global mcPmsmFocSym_max_motor_current
    mcPmsmFocSym_max_motor_current = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_MOTOR_CURRENT", mcPmsmFocSym_motor)
    mcPmsmFocSym_max_motor_current.setLabel("Max Motor Current (A)")
    mcPmsmFocSym_max_motor_current.setDefaultValue(float(mcPmsmFocMotorParamDict['LONG_HURST']['MAX_MOTOR_CURRENT']))

    mcPmsmFocSym_max_fw_current.setDependencies(mcPmsmFocFWMax, ["MCPMSMFOC_MAX_MOTOR_CURRENT", "MCPMSMFOC_FIELD_WEAKENING"])

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
    #mcPmsmFocSym_board.addKey("MCHV3", "2", "MCHV3 - High Voltage Board")
    mcPmsmFocSym_board.setDefaultValue(1)   #MCLV2

    global mcPmsmFocSym_max_board_current
    mcPmsmFocSym_max_board_current = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_CURRENT", mcPmsmFocSym_board)
    mcPmsmFocSym_max_board_current.setLabel("Max Board Current (A)")
    mcPmsmFocSym_max_board_current.setDefaultValue(float(mcPmsmFocBoardParamDict['MCLV2']['MAX_CURRENT']))

    global mcPmsmFocSym_dc_bus_volt
    mcPmsmFocSym_dc_bus_volt = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_VOLT", mcPmsmFocSym_board)
    mcPmsmFocSym_dc_bus_volt.setLabel("DC Bus Voltage (V)")
    mcPmsmFocSym_dc_bus_volt.setDefaultValue(float(mcPmsmFocBoardParamDict['MCLV2']['DC_BUS_VOLT']))

    global mcPmsmFocSym_dc_bus_ratio
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
    mcPmsmFocSym_pin_comment.setLabel("**** Configure above selected pins in the Pin Manager ****")

    mcPmsmFocSym_board_params = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_BOARD_PARAMS", mcPmsmFocSym_board)
    mcPmsmFocSym_board_params.setVisible(False)
    mcPmsmFocSym_board_params.setDependencies(mcPmsmFocBoardParamSet, ["MCPMSMFOC_BOARD_SEL"])

########################### Control Parameters   #################################

    mcPmsmFocCtrlMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_CTRL_CONF", None)
    mcPmsmFocCtrlMenu.setLabel("Control Parameters")

    mcPmsmFocStartupMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_STARTUP", mcPmsmFocCtrlMenu)
    mcPmsmFocStartupMenu.setLabel("Startup Parameters")

    mcPmsmFocSym_alignment_method = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_ALIGNMENT_METHOD", mcPmsmFocStartupMenu)
    mcPmsmFocSym_alignment_method.setLabel("Select Startup Alignment Method")
    mcPmsmFocSym_alignment_method.addKey("NO_ALIGNMENT", "0", "No Alignment")
    mcPmsmFocSym_alignment_method.addKey("FORCED_ALIGNMENT", "1", "Forced Alignment")
    #mcPmsmFocSym_alignment_method.addKey("IPD", "2", "Initial Position Detection")
    mcPmsmFocSym_alignment_method.setDefaultValue(1)
    mcPmsmFocSym_alignment_method.setOutputMode("Value")
    mcPmsmFocSym_alignment_method.setDisplayMode("Description")

    mcPmsmFocSym_alignment = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_ALIGNMENT", mcPmsmFocStartupMenu)
    mcPmsmFocSym_alignment.setLabel("Select Alignment Axis")
    mcPmsmFocSym_alignment.addKey("Q_AXIS", "0", "Q Axis")
    mcPmsmFocSym_alignment.addKey("D_AXIS", "1", "D Axis")
    mcPmsmFocSym_alignment.setOutputMode("Value")
    mcPmsmFocSym_alignment.setDisplayMode("Description")
    mcPmsmFocSym_alignment.setDependencies(mcPmsmFocEncoderHide, ["MCPMSMFOC_POSITION_FB"])

    mcPmsmFocSym_lock_time = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LOCK_TIME", mcPmsmFocStartupMenu)
    mcPmsmFocSym_lock_time.setLabel("Alignment Lock Time (sec)")
    mcPmsmFocSym_lock_time.setDefaultValue(2)

    mcPmsmFocSym_open_loop_ramp_time = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_RAMP_TIME", mcPmsmFocStartupMenu)
    mcPmsmFocSym_open_loop_ramp_time.setLabel("Open Loop Ramp Time (sec)")
    mcPmsmFocSym_open_loop_ramp_time.setDefaultValue(5)
    mcPmsmFocSym_open_loop_ramp_time.setDependencies(mcPmsmFocEncoderHide, ["MCPMSMFOC_POSITION_FB"])

    mcPmsmFocSym_ol_end_speed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_END_SPEED", mcPmsmFocStartupMenu)
    mcPmsmFocSym_ol_end_speed.setLabel("Open Loop End Speed (RPM)")
    mcPmsmFocSym_ol_end_speed.setDefaultValue(500)
    mcPmsmFocSym_ol_end_speed.setDependencies(mcPmsmFocEncoderHide, ["MCPMSMFOC_POSITION_FB"])

    mcPmsmFocSym_ol_iq_ref = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_IQ_REF", mcPmsmFocStartupMenu)
    mcPmsmFocSym_ol_iq_ref.setLabel("Open Loop Ref Quadrature Current (A)")
    mcPmsmFocSym_ol_iq_ref.setDefaultValue(0.4)

    mcPmsmFocCurrentLoopMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_CURRENT_LOOP", mcPmsmFocCtrlMenu)
    mcPmsmFocCurrentLoopMenu.setLabel("Current Loop")

    mcPmsmFocSym_CL_AutoCalculate = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_CL_AUTOCALCULATE", mcPmsmFocCurrentLoopMenu)
    mcPmsmFocSym_CL_AutoCalculate.setLabel("Auto Calcualte PI Parameters?")

    mcPmsmFocSym_CL_Bandwidth = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_CL_BANDWIDTH", mcPmsmFocSym_CL_AutoCalculate)
    mcPmsmFocSym_CL_Bandwidth.setLabel("Current Loop Bandwidth (rad/s)")
    mcPmsmFocSym_CL_Bandwidth.setValue(2000)
    mcPmsmFocSym_CL_Bandwidth.setVisible(False)
    mcPmsmFocSym_CL_Bandwidth.setDependencies(mcPmsmFocVisibleOnTrue , ["MCPMSMFOC_CL_AUTOCALCULATE"])

    mcPmsmFocIdPIMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Id_Menu", mcPmsmFocCurrentLoopMenu)
    mcPmsmFocIdPIMenu.setLabel("Direct current (Id) PI Parameters")

    mcPmsmFocSym_Id_Kp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KP", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_Kp.setLabel("Kp")
    mcPmsmFocSym_Id_Kp.setDefaultValue(0.02)
    mcPmsmFocSym_Id_Kp.setDependencies(mcPmsmFocCurrentKpCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    mcPmsmFocSym_Id_Ki = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KI", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_Ki.setLabel("Ki")
    mcPmsmFocSym_Id_Ki.setDefaultValue(0.000099)
    mcPmsmFocSym_Id_Ki.setDependencies(mcPmsmFocCurrentKiCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    mcPmsmFocSym_Id_Kc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KC", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_Kc.setLabel("Kc")
    mcPmsmFocSym_Id_Kc.setDefaultValue(0.5)

    mcPmsmFocSym_Id_out_max = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_OUT_MAX", mcPmsmFocIdPIMenu)
    mcPmsmFocSym_Id_out_max.setLabel("Max Output")
    mcPmsmFocSym_Id_out_max.setDefaultValue(0.98)

    mcPmsmFocIqPIMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Iq_Menu", mcPmsmFocCurrentLoopMenu)
    mcPmsmFocIqPIMenu.setLabel("Quadrature current (Iq) PI Parameters")

    mcPmsmFocSym_Iq_Kp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KP", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_Kp.setLabel("Kp")
    mcPmsmFocSym_Iq_Kp.setDefaultValue(0.02)
    mcPmsmFocSym_Iq_Kp.setDependencies(mcPmsmFocCurrentKpCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    mcPmsmFocSym_Iq_Ki = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KI", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_Ki.setLabel("Ki")
    mcPmsmFocSym_Iq_Ki.setDefaultValue(0.000099)
    mcPmsmFocSym_Iq_Ki.setDependencies(mcPmsmFocCurrentKiCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    mcPmsmFocSym_Iq_Kc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KC", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_Kc.setLabel("Kc")
    mcPmsmFocSym_Iq_Kc.setDefaultValue(0.5)

    mcPmsmFocSym_Iq_out_max = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_OUT_MAX", mcPmsmFocIqPIMenu)
    mcPmsmFocSym_Iq_out_max.setLabel("Max Output")
    mcPmsmFocSym_Iq_out_max.setDefaultValue(0.98)

    mcPmsmFocSpeedMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_SPEED", mcPmsmFocCtrlMenu)
    mcPmsmFocSpeedMenu.setLabel("Speed Loop")

    speedRefIp = ["Potentiometer Analog Input", "UI Input"]
    mcPmsmFocSpeedRefIp = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_SPEED_REF_INPUT", mcPmsmFocSpeedMenu, speedRefIp)
    mcPmsmFocSpeedRefIp.setLabel("Select Speed Ref Input")
    mcPmsmFocSpeedRefIp.setReadOnly(True)

    mcPmsmFocSpeedRef = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_REF", mcPmsmFocSpeedRefIp)
    mcPmsmFocSpeedRef.setLabel("Speed Reference (RPM)")
    mcPmsmFocSpeedRef.setVisible(False)
    mcPmsmFocSpeedRef.setDefaultValue(2000)
    mcPmsmFocSpeedRef.setMax(mcPmsmFocSym_rated_speed.getValue())
    mcPmsmFocSpeedRef.setDependencies(mcPmsmFocSpeedRefVisible, ["MCPMSMFOC_SPEED_REF_INPUT", "MCPMSMFOC_RATED_SPEED"])


    mcPmsmFocSpeedPIMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Speed_Menu", mcPmsmFocSpeedMenu)
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
    mcPmsmFocSym_speed_out_max.setLabel("Max Output (A)")
    mcPmsmFocSym_speed_out_max.setDefaultValue(mcPmsmFocSym_max_board_current.getValue())

###################################################################################################
########################### Code Generation   #################################
###################################################################################################
    configName = Variables.get("__CONFIGURATION_NAME")

    mcPmsmFocCodeGen = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_CODE_GEN", None)
    mcPmsmFocCodeGen.setVisible(False)
    mcPmsmFocCodeGen.setDependencies(mcPmsmFocCodeGenUpdate, ["MCPMSMFOC_POSITION_FB"])

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

    mcPmsmFocPosPllSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_PLL_SOURCE", None)
    mcPmsmFocPosPllSourceFile.setSourcePath("/algorithms/pmsm_foc/templates/pos_pll.c.ftl")
    mcPmsmFocPosPllSourceFile.setOutputName("mc_rotorposition.c")
    mcPmsmFocPosPllSourceFile.setDestPath("motor_control/pmsm_foc/")
    mcPmsmFocPosPllSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
    mcPmsmFocPosPllSourceFile.setType("SOURCE")
    mcPmsmFocPosPllSourceFile.setMarkup(True)

    mcPmsmFocPosPllHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_PLL_HEADER", None)
    mcPmsmFocPosPllHeaderFile.setSourcePath("/algorithms/pmsm_foc/templates/pos_pll.h.ftl")
    mcPmsmFocPosPllHeaderFile.setOutputName("mc_rotorposition.h")
    mcPmsmFocPosPllHeaderFile.setDestPath("motor_control/pmsm_foc/")
    mcPmsmFocPosPllHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
    mcPmsmFocPosPllHeaderFile.setType("HEADER")
    mcPmsmFocPosPllHeaderFile.setMarkup(True)

    mcPmsmFocPosEncSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_ENCODER_SOURCE", None)
    mcPmsmFocPosEncSourceFile.setSourcePath("/algorithms/pmsm_foc/templates/pos_encoder.c.ftl")
    mcPmsmFocPosEncSourceFile.setOutputName("mc_rotorposition.c")
    mcPmsmFocPosEncSourceFile.setDestPath("motor_control/pmsm_foc/")
    mcPmsmFocPosEncSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
    mcPmsmFocPosEncSourceFile.setType("SOURCE")
    mcPmsmFocPosEncSourceFile.setMarkup(True)

    mcPmsmFocPosEncHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_ENCODER_HEADER", None)
    mcPmsmFocPosEncHeaderFile.setSourcePath("/algorithms/pmsm_foc/templates/pos_encoder.h.ftl")
    mcPmsmFocPosEncHeaderFile.setOutputName("mc_rotorposition.h")
    mcPmsmFocPosEncHeaderFile.setDestPath("motor_control/pmsm_foc/")
    mcPmsmFocPosEncHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
    mcPmsmFocPosEncHeaderFile.setType("HEADER")
    mcPmsmFocPosEncHeaderFile.setMarkup(True)

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
