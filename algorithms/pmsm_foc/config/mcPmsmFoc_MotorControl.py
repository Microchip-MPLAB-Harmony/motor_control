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
* File Name: mcPmsmFoc_MotorControlClass.py
*
* Description:
* The file comprises of back-end code for Motor Control and Diagnosis block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                             GLOBAL VARIABLES                                     # 
#----------------------------------------------------------------------------------#
                                   
# PI controller Parameters
mcMotC_CurrentPiPararameterDict =  {    'MCLV2' :   { 'KP' : 0.02,
                                                      'KI' : 0.000099
                                                    },
                                        'MCHV3' :   { 'KP' : 0.02,
                                                      'KI' : 0.000099
                                                    },
                                   }

mcMotC_SpeedPiPararameterDict =  {    'MCLV2' :   { 'KP' : 0.005,
                                                    'KI' : 0.00002
                                                  },
                                      'MCHV3' :   { 'KP' : 0.005,
                                                    'KI' : 0.00002
                                                  },
                                 }                                   

mcMotC_FieldWeakeningParameter =   {    'LONG_HURST' : 
                                                    { 
                                                      'MAX_FW_CURRENT'    : -2.0,
                                                      'MAX_MOTOR_CURRENT' : 4.0 ,
                                              
                                                    },
                                        'SMALL_HURST' : 
                                                    { 
                                                      'MAX_FW_CURRENT'    : -2.0,
                                                      'MAX_MOTOR_CURRENT' : 4.0 ,
                                                   },
                                       'LEADSHINE' :
                                                   { 
                                                      'MAX_FW_CURRENT'    : -2.0,
                                                      'MAX_MOTOR_CURRENT' : 4.0 ,
                                                   },
                          }

mcMoC_DefaultMotor = 'LONG_HURST'

#----------------------------------------------------------------------------------#
#                             GLOBAL VARIABLES                                     # 
#----------------------------------------------------------------------------------#
def mcMoC_CreateMHCSymbols( mcPmsmFocComponent ):
            
    # Symbol for open loop mode enable/ disable 
    mcMoC_OpenLoopEnable = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_OPEN_LOOP", mcPmsmFocAlgoMenu)
    mcMoC_OpenLoopEnable.setLabel("Run in Open Loop?")
    mcMoC_OpenLoopEnable.setDependencies(mcPmsmFocOpenloop, ["MCPMSMFOC_POSITION_FB", "MCPMSMFOC_TORQUE_MODE", "MCPMSMFOC_FIELD_WEAKENING"])
    
    # Symbol for torque mode enable/disable
    mcMoC_TorqueModeEnable = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_TORQUE_MODE", mcPmsmFocAlgoMenu)
    mcMoC_TorqueModeEnable.setLabel("Run in Torque Control?")
    mcMoC_TorqueModeEnable.setDependencies(mcPmsmFocControl, ["MCPMSMFOC_OPEN_LOOP", "MCPMSMFOC_FIELD_WEAKENING"])
    
    # Symbol for maximum allowed torque if torque mode is enabled 
    mcMoC_MaximumTorque = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_END_TORQUE", mcMoC_TorqueModeEnable)
    mcMoC_MaximumTorque.setLabel("Ref. Quadrature Current (A)")
    mcMoC_MaximumTorque.setDefaultValue(0.2)
    mcMoC_MaximumTorque.setVisible(False)
    mcMoC_MaximumTorque.setDependencies(mcPmsmFocVisibleOnTrue, ["MCPMSMFOC_TORQUE_MODE"])
    
    # Symbol to enable/ disable filed wekening mode 
    mcMoC_FieldWeakeningEnable = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_FIELD_WEAKENING", mcPmsmFocAlgoMenu)
    mcMoC_FieldWeakeningEnable.setLabel("Enable Field Weakening?")
    mcMoC_FieldWeakeningEnable.setDependencies(mcPmsmFocControl, ["MCPMSMFOC_OPEN_LOOP", "MCPMSMFOC_TORQUE_MODE"])

    # Symbol for maximum negative  field weakening current
    mcMoC_FieldWeakeningCurrent = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_FW_CURRENT", mcMoC_FieldWeakeningEnable)
    mcMoC_FieldWeakeningCurrent.setLabel("Motor Max Field Weakning Negative Current (A)")
    mcMoC_FieldWeakeningCurrent.setVisible(False)
    mcMoC_FieldWeakeningCurrent.setMin(-4.0)
    mcMoC_FieldWeakeningCurrent.setMax(0.0)      
    mcMoC_FieldWeakeningCurrent.setDefaultValue(float(mcMotC_FieldWeakeningParameter[mcMoC_DefaultMotor]['MAX_FW_CURRENT']))
    mcMoC_FieldWeakeningCurrent.setDependencies(mcPmsmFocFWMax, ["MCPMSMFOC_MAX_MOTOR_CURRENT", "MCPMSMFOC_FIELD_WEAKENING"])
    
    # Current control loop root node  
    mcMoC_TorqueLoopNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_CURRENT_LOOP", mcPmsmFocCtrlMenu)
    mcMoC_TorqueLoopNode.setLabel("Current Loop")
    
    # Symbol to enable/disable current controller auto-parameter calculation
    mcMoC_Autocalculate = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_CL_AUTOCALCULATE", mcMoC_TorqueLoopNode)
    mcMoC_Autocalculate.setLabel("Auto Calcualte PI Parameters?")
    
    # Symbol for current PI controller band-width for auto gain calculation
    mcMoC_ControlBandwidth = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_CL_BANDWIDTH", mcMoC_Autocalculate)
    mcMoC_ControlBandwidth.setLabel("Current Loop Bandwidth (rad/s)")
    mcMoC_ControlBandwidth.setValue(2000)
    mcMoC_ControlBandwidth.setVisible(False)
    mcMoC_ControlBandwidth.setDependencies(mcPmsmFocVisibleOnTrue , ["MCPMSMFOC_CL_AUTOCALCULATE"])

    # D-axis controller root node 
    mcMoC_IdControlNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Id_Menu", mcMoC_TorqueLoopNode)
    mcMoC_IdControlNode.setLabel("Direct current (Id) PI Parameters")

    # Symbol for D axis PI controller proportional gain 
    mcMoC_IdCurrentKp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KP", mcMoC_IdControlNode)
    mcMoC_IdCurrentKp.setLabel("Kp")
    mcMoC_IdCurrentKp.setDefaultValue(0.02)
    mcMoC_IdCurrentKp.setDependencies(mcPmsmFocCurrentKpCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    # Symbol for D axis PI controller integral gain 
    mcMoC_IdCurrentKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KI", mcMoC_IdControlNode)
    mcMoC_IdCurrentKi.setLabel("Ki")
    mcMoC_IdCurrentKi.setDefaultValue(0.000099)
    mcMoC_IdCurrentKi.setDependencies(mcPmsmFocCurrentKiCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    # Symbol for D axis PI controller back calculation gain 
    mcMoC_IdCurrentKc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KC", mcMoC_IdControlNode)
    mcMoC_IdCurrentKc.setLabel("Kc")
    mcMoC_IdCurrentKc.setDefaultValue(0.5)
    
    # Symbol for D axis PI controller maximum output
    mcMoC_IdCurrentYmax = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_OUT_MAX", mcMoC_IdControlNode)
    mcMoC_IdCurrentYmax.setLabel("Max Output")
    mcMoC_IdCurrentYmax.setDefaultValue(0.98)

    # Current control loop root node 
    mcMoC_IqRootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Iq_Menu", mcMoC_TorqueLoopNode)
    mcMoC_IqRootNode.setLabel("Quadrature current (Iq) PI Parameters")

    # Symbol for Q axis PI controller proportional gain 
    mcMoC_IqCurrentKp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KP", mcMoC_IqRootNode)
    mcMoC_IqCurrentKp.setLabel("Kp")
    mcMoC_IqCurrentKp.setDefaultValue(0.02)
    mcMoC_IqCurrentKp.setDependencies(mcPmsmFocCurrentKpCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    # Symbol for Q axis PI controller integral gain 
    mcMoC_IqCurrentKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KI", mcMoC_IqRootNode)
    mcMoC_IqCurrentKi.setLabel("Ki")
    mcMoC_IqCurrentKi.setDefaultValue(0.000099)
    mcMoC_IqCurrentKi.setDependencies( mcPmsmFocCurrentKiCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])
    
    # Symbol for Q axis PI controller back calculation gain 
    mcMoC_IqCurrentKc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KC", mcMoC_IqRootNode)
    mcMoC_IqCurrentKc.setLabel("Kc")
    mcMoC_IqCurrentKc.setDefaultValue(0.5)
    
    # Symbol for Q axis PI controller maximum output  
    mcMoC_IqCurrentYmax = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_OUT_MAX", mcMoC_IqRootNode)
    mcMoC_IqCurrentYmax.setLabel("Max Output")
    mcMoC_IqCurrentYmax.setDefaultValue(0.98)

    # Symbol for speed control root node 
    mcMoC_SpeedRootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_SPEED", mcPmsmFocCtrlMenu)
    mcMoC_SpeedRootNode.setLabel("Speed Loop")

    # Symbol for speed reference input
    speedRefIp = ["Potentiometer Analog Input", "UI Input"]
    smcMoC_SpeedInput = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_SPEED_REF_INPUT", mcMoC_SpeedRootNode, speedRefIp)
    smcMoC_SpeedInput.setLabel("Select Speed reference input")
    smcMoC_SpeedInput.setReadOnly(True)
    
    # Symbol for speed control root node 
    mcMoC_SpeedNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Speed_Menu", mcMoC_SpeedRootNode)
    mcMoC_SpeedNode.setLabel("Speed PI Parameters")

    # Symbol for speed controller proportional gain  
    mcMoC_SpeedKp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KP", mcMoC_SpeedNode)
    mcMoC_SpeedKp.setLabel("Kp")
    mcMoC_SpeedKp.setDefaultValue(0.005)
    mcMoC_SpeedKp.setDependencies(mcPmsmFoc_SpeedKp, ["MCPMSMFOC_BOARD_SEL"])

    # Symbol for speed controller integral gain  
    mcMoC_SpeedKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KI", mcMoC_SpeedNode)
    mcMoC_SpeedKi.setLabel("Ki")
    mcMoC_SpeedKi.setDefaultValue(0.000020)
    mcMoC_SpeedKi.setDependencies(mcPmsmFoc_SpeedKi, ["MCPMSMFOC_BOARD_SEL"])    
    
    # Symbol for speed controller back calculation gain  
    mcMoC_SpeedKc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KC", mcMoC_SpeedNode)
    mcMoC_SpeedKc.setLabel("Kc")
    mcMoC_SpeedKc.setDefaultValue(0.5)
    
    # Symbol for speed controller maximum output 
    mcMoC_SpeedYmax = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_OUT_MAX", mcMoC_SpeedNode)
    mcMoC_SpeedYmax.setLabel("Max Output (A)")
    mcMoC_SpeedYmax.setDefaultValue(mcMotC_FieldWeakeningParameter[mcMoC_DefaultMotor]['MAX_MOTOR_CURRENT'])


#----------------------------------------------------------------------------------#
#                             CALLBACKS                                     # 
#----------------------------------------------------------------------------------#

# Callback Functions 
def mcPmsmFocPIValueChange( symbol, event):
    if(event["value"] == 1): #encoder
        symbol.setValue(0.000005)
    else:
        symbol.setValue(0.000099)

def mcPmsmFocVisibleOnTrue(symbol, event):
    symbol.setVisible(event["value"])

def mcPmsmFocOpenloop(symbol, event):
    component = symbol.getComponent()
    if (event["id"] == "MCPMSMFOC_POSITION_FB"):
        symObj = event["symbol"]
        key = symObj.getSelectedKey()
        if(key == "SENSORED_ENCODER"):
            symbol.setVisible(False)
        else:
            symbol.setVisible(True)
    else:
        if event["value"] == True:
            symbol.setVisible(False)
        else:
            if (mcPoM_AlgorithmSelection.getSelectedKey() != "SENSORED_ENCODER"):
                symbol.setVisible(True)        

def mcPmsmFocControl(symbol, event):
    if event["value"] == True:
        symbol.setVisible(False)
    else:
        symbol.setVisible(True)

def mcPmsmFocFWMax(symbol, event):
    component = symbol.getComponent()
    motorCurrent = component.getSymbolValue("MCPMSMFOC_MAX_MOTOR_CURRENT")
    symbol.setMin(-motorCurrent)
    fw = component.getSymbolValue("MCPMSMFOC_FIELD_WEAKENING")
    symbol.setVisible((fw))

def mcPmsmFoc_SpeedKp(symbol, event):
    symObj = event["symbol"]
    board = symObj.getSelectedKey()
    symbol.setValue(mcMotC_SpeedPiPararameterDict[board]['KP'])

def mcPmsmFoc_SpeedKi(symbol, event):
    symObj = event["symbol"]
    board = symObj.getSelectedKey()
    symbol.setValue(mcMotC_SpeedPiPararameterDict[board]['KI'])

def mcPmsmFocCurrentKpCalc( symbol, event):
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
        if board in mcMotC_CurrentPiPararameterDict.keys():
            kp = mcMotC_CurrentPiPararameterDict[board]['KP']
    symbol.setValue(kp)


def mcPmsmFocCurrentKiCalc( symbol, event):
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
        if board in mcMotC_CurrentPiPararameterDict.keys():
            ki = mcMotC_CurrentPiPararameterDict[board]['KI']
    symbol.setValue(ki)


def mcMoCI_MotorControl( mcPmsmFocComponent ):
    # Create MHC Symbols 
    mcMoC_CreateMHCSymbols( mcPmsmFocComponent)



