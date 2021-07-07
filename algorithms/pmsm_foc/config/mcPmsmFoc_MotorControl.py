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
mcMotC_CurrentPiPararameterDictFixed =  {    'MCLV2' :   { 'KP' : 0.71,
                                                      'KI' : 917
                                                    },
                                        'Custom' :   { 'KP' : 0.71,
                                                       'KI' : 917
                                                    },            
                                        'MCHV3' :   { 'KP' : 6.1,
                                                      'KI' : 469
                                                    },
                                   }
mcMotC_CurrentPiPararameterDictFloating =  {    'MCLV2' :   { 'KP' : 0.02,
                                                      'KI' : 0.0002
                                           },
                                        'Custom' :   { 'KP' : 0.02,
                                                       'KI' : 0.000099
                                                    },            
                                        'MCHV3' :   { 'KP' : 0.02,
                                                      'KI' : 0.000099
                                                    },
                                   }

mcMotC_SpeedPiPararameterDictFixed =  {    'MCLV2' :   { 'KP' : 0.001,
                                                    'KI' : 0.03,
                                                   
                                                  },
                                      'Custom' :   { 'KP' : 0.001,
                                                     'KI' : 0.03,
                                                   
                                                  },
                                      'MCHV3' :   { 'KP' : 0.001,
                                                    'KI' : 0.03,
                                                  },
                                 }  

mcMotC_SpeedPiPararameterDictFloating =  {    'MCLV2' :   { 'KP' : 0.002,
                                                    'KI' : 0.00002
                                                   },
                                      'Custom' :   { 'KP' : 0.005,
                                                     'KI' : 0.000002
                                                   },
                                      'MCHV3' :   { 'KP' : 0.005,
                                                    'KI' : 0.000002
                                                  },
                                 }                                  

mcMotC_FieldWeakeningParameter =   {    'LONG_HURST' : 
                                                    { 
                                                      'MAX_FW_CURRENT'    : -2.5,
                                                      'MAX_MOTOR_CURRENT' : 4.0
                                              
                                                    },
                                        'SMALL_HURST' : 
                                                    { 
                                                      'MAX_FW_CURRENT'    : -2.0,
                                                      'MAX_MOTOR_CURRENT' : 4.0
                                                   },
                                       'LEADSHINE' :
                                                   { 
                                                      'MAX_FW_CURRENT'    : -2.0,
                                                      'MAX_MOTOR_CURRENT' : 4.0
                                                   },
                          }

mcMoC_DefaultMotor = 'LONG_HURST'
mcMOC_DefaultBoard = 'MCLV2'

global mcMoC_MicrocontrollerSeries
mcMoC_MicrocontrollerSeries   =  ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series")

#Select PI Controller parameter table 
if(('PIC32CMMC00' == mcMoC_MicrocontrollerSeries) or ( 'SAMC21' == mcMoC_MicrocontrollerSeries)):
    mcMotC_CurrentPiPararameterDict = mcMotC_CurrentPiPararameterDictFixed
    mcMotC_SpeedPiPararameterDict = mcMotC_SpeedPiPararameterDictFixed
else:
    mcMotC_CurrentPiPararameterDict = mcMotC_CurrentPiPararameterDictFloating
    mcMotC_SpeedPiPararameterDict = mcMotC_SpeedPiPararameterDictFloating

#----------------------------------------------------------------------------------#
#                             GLOBAL VARIABLES                                     # 
#----------------------------------------------------------------------------------#
def mcMoC_CreateMHCSymbols( mcPmsmFocComponent ):

    global mcMoC_Control
    mcMoC_Control = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_CONTROL", mcPmsmFocAlgoMenu)
    mcMoC_Control.setLabel("Select Control")
    mcMoC_Control.addKey("OPEN_LOOP", "0", "Open Loop Control")
    mcMoC_Control.addKey("SPEED_LOOP", "1", "Speed Loop Control")
    mcMoC_Control.addKey("TORQUE_LOOP", "2", "Torque Loop Control")
    #mcMoC_Control.addKey("POSITION_LOOP", "3", "Position Loop Control")
    mcMoC_Control.setOutputMode("Key")
    mcMoC_Control.setDisplayMode("Description")
    mcMoC_Control.setDefaultValue(1)
            
    mcMoC_Ramp = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_RAMP", mcPmsmFocAlgoMenu)
    mcMoC_Ramp.setLabel("Select Ramp Profile")
    mcMoC_Ramp.addKey("STEP", "0", "STEP")
    # mcMoC_Ramp.addKey("LINEAR", "1", "LINEAR")
    # mcMoC_Ramp.addKey("S-CUREVE", "2", "S-CURVE")
    mcMoC_Ramp.setOutputMode("Key")
    mcMoC_Ramp.setDisplayMode("Description")

    mcMoC_RampTime = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_RAMP_TIME", mcMoC_Ramp)
    mcMoC_RampTime.setLabel("Ramp Time (s)")
    mcMoC_RampTime.setDefaultValue(1)
    mcMoC_RampTime.setVisible(False)
    mcMoC_RampTime.setDependencies(mcPmsmFocRamp, ["MCPMSMFOC_RAMP"])

    mcMoC_RampVelocity = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_RAMP_VELOCITY", mcMoC_Ramp)
    mcMoC_RampVelocity.setLabel("Max Ramp Velocity")
    mcMoC_RampVelocity.setDefaultValue(200)
    mcMoC_RampVelocity.setVisible(False)
    mcMoC_RampVelocity.setDependencies(mcPmsmFocRamp, ["MCPMSMFOC_RAMP"])

    global mcMoC_RampAcceleration
    mcMoC_RampAcceleration = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_RAMP_ACCELERATION", mcMoC_Ramp)
    mcMoC_RampAcceleration.setLabel("Max Ramp Acceleration")
    mcMoC_RampAcceleration.setDefaultValue(10)
    mcMoC_RampAcceleration.setVisible(False)
    mcMoC_RampAcceleration.setDependencies(mcPmsmFocRamp, ["MCPMSMFOC_RAMP"])

    # Symbol for reference input
    global mcMoC_RefInput
    RefIp = ["Potentiometer Analog Input", "UI Input"]
    mcMoC_RefInput = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_REF_INPUT", mcMoC_Ramp, RefIp)
    mcMoC_RefInput.setLabel("Select reference input")
    mcMoC_RefInput.setReadOnly(False)

    mcMoC_RefTorque = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_END_TORQUE", mcMoC_Ramp)
    mcMoC_RefTorque.setLabel("Ref. Quadrature Current (A)")
    mcMoC_RefTorque.setDefaultValue(0.2)
    mcMoC_RefTorque.setVisible(False)
    mcMoC_RefTorque.setDependencies(mcPmsmFocTorque, ["MCPMSMFOC_CONTROL", "MCPMSMFOC_REF_INPUT"])

    # Symbol for minimum allowed torque if torque mode is enabled 
    mcMoC_MinTorque = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MIN_TORQUE", mcMoC_Ramp)
    mcMoC_MinTorque.setLabel("Minimum Quadrature Current (A)")
    mcMoC_MinTorque.setDefaultValue(0.15)
    mcMoC_MinTorque.setVisible(False)
    mcMoC_MinTorque.setMin(0)
    mcMoC_MinTorque.setMax(mcMot_MaximumCurrentInAmps.getValue())
    mcMoC_MinTorque.setDependencies(mcPmsmFocTorquePot, ["MCPMSMFOC_CONTROL", "MCPMSMFOC_REF_INPUT"])

    # Symbol for maximum allowed torque if torque mode is enabled 
    mcMoC_MaxTorque = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_TORQUE", mcMoC_Ramp)
    mcMoC_MaxTorque.setLabel("Maximum Quadrature Current (A)")
    mcMoC_MaxTorque.setDefaultValue(0.3)
    mcMoC_MaxTorque.setVisible(False)
    mcMoC_MaxTorque.setMin(0)
    mcMoC_MaxTorque.setMax(mcMot_MaximumCurrentInAmps.getValue())
    mcMoC_MaxTorque.setDependencies(mcPmsmFocTorquePot, ["MCPMSMFOC_CONTROL", "MCPMSMFOC_REF_INPUT"])

    mcMoC_RefSpeed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_END_SPEED", mcMoC_Ramp)
    mcMoC_RefSpeed.setLabel("Ref. Speed (RPM)")
    mcMoC_RefSpeed.setDefaultValue(1000)
    mcMoC_RefSpeed.setMin(0)
    mcMoC_RefSpeed.setVisible(False)
    mcMoC_RefSpeed.setMax(mcMot_MaximumSpeedInRpm.getValue())
    mcMoC_RefSpeed.setDependencies(mcPmsmFocSpeed, ["MCPMSMFOC_CONTROL", "MCPMSMFOC_REF_INPUT"])
    
    if(('PIC32CMMC00' != mcMoC_MicrocontrollerSeries ) and ( 'SAMC21' != mcMoC_MicrocontrollerSeries )):
        # Symbol to enable/ disable filed wekening mode 
        mcMoC_FieldWeakeningEnable = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_FIELD_WEAKENING", mcPmsmFocAlgoMenu)
        mcMoC_FieldWeakeningEnable.setLabel("Enable Field Weakening?")
        mcMoC_FieldWeakeningEnable.setDependencies(mcPmsmFocControl, ["MCPMSMFOC_CONTROL"])

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

    if(('PIC32CMMC00' != mcMoC_MicrocontrollerSeries ) and ( 'SAMC21' != mcMoC_MicrocontrollerSeries )):
        # Symbol to enable/disable current controller auto-parameter calculation
        mcMoC_Autocalculate = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_CL_AUTOCALCULATE", mcMoC_TorqueLoopNode)
        mcMoC_Autocalculate.setLabel("Auto Calculate PI Parameters?")
        
        # Symbol for current PI controller band-width for auto gain calculation
        mcMoC_ControlBandwidth = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_CL_BANDWIDTH", mcMoC_Autocalculate)
        mcMoC_ControlBandwidth.setLabel("Current Loop Bandwidth (rad/s)")
        mcMoC_ControlBandwidth.setValue(2000)
        mcMoC_ControlBandwidth.setVisible(False)
        mcMoC_ControlBandwidth.setDependencies(mcPmsmFocVisibleOnTrue , ["MCPMSMFOC_CL_AUTOCALCULATE"])

    # Current Control anti-windup 
    mcMoc_AntiwindupAlgorithm = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_ANTIWINDUP", mcMoC_TorqueLoopNode)
    mcMoc_AntiwindupAlgorithm.setLabel("Select anti-windup technique")
    if(('PIC32CMMC00' != mcMoC_MicrocontrollerSeries ) and ( 'SAMC21' != mcMoC_MicrocontrollerSeries )):
        mcMoc_AntiwindupAlgorithm.addKey("BACK_CALCULATION", "0", "Back Calculation")
    else:
        mcMoc_AntiwindupAlgorithm.addKey("INTEGRAL_CLAMP", "1", "Integral Clamp")
   
    mcMoc_AntiwindupAlgorithm.setOutputMode("Key")
    mcMoc_AntiwindupAlgorithm.setDisplayMode("Description")

    # D-axis controller root node 
    mcMoC_IdControlNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Id_Menu", mcMoC_TorqueLoopNode)
    mcMoC_IdControlNode.setLabel("Direct current (Id) PI Parameters")

    # Symbol for D axis PI controller proportional gain 
    mcMoC_IdCurrentKp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KP", mcMoC_IdControlNode)
    mcMoC_IdCurrentKp.setLabel("Kp")
    mcMoC_IdCurrentKp.setDefaultValue(mcMotC_CurrentPiPararameterDict[mcMOC_DefaultBoard]['KP'])
    mcMoC_IdCurrentKp.setDependencies(mcPmsmFocCurrentKpCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL", "MCPMSMFOC_MOTOR_CONNECTION"])

    # Symbol for D axis PI controller integral gain 
    mcMoC_IdCurrentKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_ID_KI", mcMoC_IdControlNode)
    mcMoC_IdCurrentKi.setLabel("Ki")
    mcMoC_IdCurrentKi.setDefaultValue(mcMotC_CurrentPiPararameterDict[mcMOC_DefaultBoard]['KI'])
    mcMoC_IdCurrentKi.setDependencies(mcPmsmFocCurrentKiCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL", "MCPMSMFOC_MOTOR_CONNECTION"])

    # Symbol for D axis PI controller back calculation gain 
    if( "BACK_CALCULATION" == mcMoc_AntiwindupAlgorithm.getSelectedKey()):
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
    mcMoC_IqCurrentKp.setDefaultValue(mcMotC_CurrentPiPararameterDict[mcMOC_DefaultBoard]['KP'])
    mcMoC_IqCurrentKp.setDependencies(mcPmsmFocCurrentKpCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL", "MCPMSMFOC_MOTOR_CONNECTION"])

    # Symbol for Q axis PI controller integral gain 
    mcMoC_IqCurrentKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IQ_KI", mcMoC_IqRootNode)
    mcMoC_IqCurrentKi.setLabel("Ki")
    mcMoC_IqCurrentKi.setDefaultValue(mcMotC_CurrentPiPararameterDict[mcMOC_DefaultBoard]['KI'])
    mcMoC_IqCurrentKi.setDependencies( mcPmsmFocCurrentKiCalc, ["MCPMSMFOC_CL_BANDWIDTH", "MCPMSMFOC_CL_AUTOCALCULATE",
        "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL", "MCPMSMFOC_MOTOR_CONNECTION"])
    
    # Symbol for Q axis PI controller back calculation gain 
    if( "BACK_CALCULATION" == mcMoc_AntiwindupAlgorithm.getSelectedKey()):
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

 
    # Current Control anti-windup 
    mcMoc_AntiwindupAlgorithm_ = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_ANTIWINDUP_", mcMoC_SpeedRootNode)
    mcMoc_AntiwindupAlgorithm_.setLabel("Select anti-windup technique")
    if(('PIC32CMMC00' != mcMoC_MicrocontrollerSeries ) and ( 'SAMC21' != mcMoC_MicrocontrollerSeries )):
        mcMoc_AntiwindupAlgorithm_.addKey("BACK_CALCULATION", "0", "Back Calculation")
    else:
        mcMoc_AntiwindupAlgorithm_.addKey("INTEGRAL_CLAMP", "1", "Integral Clamp")
   
    mcMoc_AntiwindupAlgorithm_.setOutputMode("Key")
    mcMoc_AntiwindupAlgorithm_.setDisplayMode("Description")
    # Symbol for speed control root node 
    mcMoC_SpeedNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_Speed_Menu", mcMoC_SpeedRootNode)
    mcMoC_SpeedNode.setLabel("Speed PI Parameters")

    # Symbol for speed controller proportional gain  
    mcMoC_SpeedKp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KP", mcMoC_SpeedNode)
    mcMoC_SpeedKp.setLabel("Kp")
    mcMoC_SpeedKp.setDefaultValue(mcMotC_SpeedPiPararameterDict[mcMOC_DefaultBoard]['KP'])
    mcMoC_SpeedKp.setDependencies(mcPmsmFoc_SpeedKp, ["MCPMSMFOC_BOARD_SEL"])

    # Symbol for speed controller integral gain  
    mcMoC_SpeedKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_SPEED_KI", mcMoC_SpeedNode)
    mcMoC_SpeedKi.setLabel("Ki")
    mcMoC_SpeedKi.setDefaultValue(mcMotC_SpeedPiPararameterDict[mcMOC_DefaultBoard]['KI'])
    mcMoC_SpeedKi.setDependencies(mcPmsmFoc_SpeedKi, ["MCPMSMFOC_BOARD_SEL"]) 
    
    if( "BACK_CALCULATION" == mcMoc_AntiwindupAlgorithm.getSelectedKey()):
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
def mcPmsmFocRamp(symbol, event):
    symObj = event["symbol"]
    ramp = symObj.getSelectedKey()
    if ramp == "STEP":
        symbol.setVisible(False)
    elif ramp == "LINEAR":
        symbol.setVisible(True)
        mcMoC_RampAcceleration.setVisible(False)
    else:
        symbol.setVisible(True)

def mcPmsmFocTorque(symbol, event):    
    control = mcMoC_Control.getSelectedKey()
    input = mcMoC_RefInput.getValue()
    if(control == "TORQUE_LOOP" and input == "UI Input"):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

def mcPmsmFocTorquePot(symbol, event):    
    control = mcMoC_Control.getSelectedKey()
    input = mcMoC_RefInput.getValue()
    if(control == "TORQUE_LOOP" and input == "Potentiometer Analog Input"):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)        

def mcPmsmFocSpeed(symbol, event):      
    control = mcMoC_Control.getSelectedKey()
    input = mcMoC_RefInput.getValue()    
    if(control == "SPEED_LOOP" and input == "UI Input"):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

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
    if event["value"] == 1:
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

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
    if board == "MCHV3":
        symbol.setLabel("Ki (* 0.01) ")
    else:
        symbol.setLabel("Ki")

def mcPmsmFocCurrentKpCalc( symbol, event):
    component = symbol.getComponent()
    board = component.getSymbolByID("MCPMSMFOC_BOARD_SEL").getSelectedKey()
    ld = component.getSymbolValue("MCPMSMFOC_LD")
    lq = component.getSymbolValue("MCPMSMFOC_LQ")
    connection = component.getSymbolByID("MCPMSMFOC_MOTOR_CONNECTION").getSelectedKey()
    if (connection == "STAR"):
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT") / 1.732
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
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT") / 1.732
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



