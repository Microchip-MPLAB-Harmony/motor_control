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

#----------------------------------------------------------------------------------#
#                            SUPPORTED MOTOR PARAMETERS                            # 
#----------------------------------------------------------------------------------#
                                   
                                   # FlyingStart PI controller Parameters
mcFlyingStart_DefaultPiPararameterDict =  {    'MCLV2' : { 'SMALL_HURST' :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             },
                                                           'LONG_HURST'  :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             },
                                                           'LEADSHINE'   :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             }                  
                                                         },
                                               'Custom' : { 'SMALL_HURST' :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             },
                                                           'LONG_HURST'  :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             },
                                                           'LEADSHINE'   :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             }                  
                                                         },             
                                               'MCHV3' : { 'SMALL_HURST' :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             },
                                                           'LONG_HURST'  :   { 'KP' : 0.2,
                                                                               'KI' : 0.00099
                                                                             },
                                                           'LEADSHINE'   :   { 'KP' : 0.2,
                                                                               'KI' : 0.0099
                                                                             }
                                                         }
                                          }
                                   
                            


#------------------------------------------------------------------------------------#
#                     FlyingStart CallBack Functions                                 #
#------------------------------------------------------------------------------------#
def mcPmsmFocCodeTypeCommentCallback(symbol, event):
    component = symbol.getComponent()
    if((component.getSymbolByID("MCPMSMFOC_FLYING_START_CODE_TYPE").getValue() == 1) and (component.getSymbolByID("MCPMSMFOC_FLYING_START").getValue() == True)):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)


def mcPmsmFocFlyingStartCurrentKpCalc( symbol, event):
    component = symbol.getComponent()
    board = component.getSymbolByID("MCPMSMFOC_BOARD_SEL").getSelectedKey()
    motor = component.getSymbolByID("MCPMSMFOC_MOTOR_SEL").getSelectedKey()
    ld = component.getSymbolValue("MCPMSMFOC_LD")
    lq = component.getSymbolValue("MCPMSMFOC_LQ")
    connection = component.getSymbolByID("MCPMSMFOC_MOTOR_CONNECTION").getSelectedKey()
    if (connection == "STAR"):
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT") / 1.732
    else:
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT")
    bandwidth = component.getSymbolValue("MCPMSMFOC_FLYING_START_CL_BANDWIDTH")
    autoCalc = component.getSymbolValue("MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE")
    l = (ld+lq)/2
    kp = symbol.getValue()

    if autoCalc == True:
        kp = (bandwidth * l) / max_volt
    else:
        if board in mcFlyingStart_DefaultPiPararameterDict.keys():
            kp = mcFlyingStart_DefaultPiPararameterDict[board][motor]['KP']
    symbol.setValue(kp)
    
def mcPmsmFocFlyingStartCurrentKiCalc( symbol, event):
    component = symbol.getComponent()
    board = component.getSymbolByID("MCPMSMFOC_BOARD_SEL").getSelectedKey()
    motor = component.getSymbolByID("MCPMSMFOC_MOTOR_SEL").getSelectedKey()
    r = component.getSymbolValue("MCPMSMFOC_R")
    connection = component.getSymbolByID("MCPMSMFOC_MOTOR_CONNECTION").getSelectedKey()
    if (connection == "STAR"):
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT") / 1.732
    else:
        max_volt = component.getSymbolValue("MCPMSMFOC_DC_BUS_VOLT")

    pwm_time = 1.0 / component.getSymbolValue("MCPMSMFOC_PWM_FREQ")
    bandwidth = component.getSymbolValue("MCPMSMFOC_FLYING_START_CL_BANDWIDTH")
    autoCalc = component.getSymbolValue("MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE")
    ki = symbol.getValue()
    if autoCalc == True:
        ki = (bandwidth * r * pwm_time) / max_volt
    else:
        if board in mcFlyingStart_DefaultPiPararameterDict.keys():
            ki = mcFlyingStart_DefaultPiPararameterDict[board][motor]['KI']
    symbol.setValue(ki)    

def mcPmsmFocFlyingStartPIControllerSymbolVisibility(component, condition):
    if (condition == True):
        symbol = component.getSymbolByID("MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE")
        symbol.setVisible(True)                
        symbol = component.getSymbolByID("MCPMSMFOC_FLYING_START_Id_Menu")
        symbol.setVisible(True)
        symbol = component.getSymbolByID("MCPMSMFOC_FLYING_START_Iq_Menu")
        symbol.setVisible(True)        
    else:
        symbol = component.getSymbolByID("MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE")
        symbol.setVisible(False)                
        symbol = component.getSymbolByID("MCPMSMFOC_FLYING_START_Id_Menu")
        symbol.setVisible(False)
        symbol = component.getSymbolByID("MCPMSMFOC_FLYING_START_Iq_Menu")
        symbol.setVisible(False)
    
    

def mcPmsmFocFlyingStartVisibility(symbol, event):
    if (event["id"] == "MCPMSMFOC_POSITION_FB"):
        symObj = event["symbol"]
        key = symObj.getSelectedKey()
        if(key == "SENSORED_ENCODER"):
            symbol.setVisible(False)
            symbol.setValue(False)
        else:
            symbol.setVisible(True)
    else:
        if event["value"] == True:
            symbol.setVisible(False)
            symbol.setValue(False)
        else:
            symbol.setVisible(True)


def mcPmsmFocIntermFlyingStartVisibility(symbol, event):
    global mcFlyingStart_Enable
    component = symbol.getComponent()
    if (event["id"] == "MCPMSMFOC_POSITION_FB"):
        symObj = event["symbol"]
        key = symObj.getSelectedKey()
        if(key == "SENSORED_ENCODER"):
            symbol.setValue(False) #disable Flying Start Startup feature when operating in sensored mode
            Log.writeInfoMessage("FlyingStart Disabled")
        else:
            if(component.getSymbolValue("MCPMSMFOC_FLYING_START") == True):
                symbol.setValue(True)
                Log.writeInfoMessage("FlyingStart Enabled")
            else:
                symbol.setValue(False)
                Log.writeInfoMessage("FlyingStart Disabled")
    elif (event["id"] == "MCPMSMFOC_FLYING_START"):
        if event["value"] == True:
            symbol.setValue(True) #enable Flying Start if Flying Start boolean input is enabled
            Log.writeInfoMessage("FlyingStart Enabled")
        else:
            symbol.setValue(False) #disable Flying Start Startup if FlyingStart boolean input is disabled
            Log.writeInfoMessage("FlyingStart Disabled")
    elif (event["id"] == "MCPMSMFOC_OPEN_LOOP"): #disable Flying Start Startup feature when open loop mode is enabled
        if event["value"] == True:
            symbol.setValue(False)
        else:
            if(component.getSymbolValue("MCPMSMFOC_FLYING_START") == True):
                symbol.setValue(True)
            else:
                symbol.setValue(False)
            
            
def mcFlyingStart_CreateMHCSymbols(mcPmsmFocComponent, mcFlyingStartRootNode):      
    mcFlyingStart_Comment = mcPmsmFocComponent.createCommentSymbol("MCPMSMFOC_FLYING_START_COMMENT", mcFlyingStartRootNode)
    mcFlyingStart_Comment.setLabel("**** Flying Start Recommended only for high inertia load ****")
    mcFlyingStart_Comment.setDependencies(mcPmsmFocFlyingStartVisibility,["MCPMSMFOC_POSITION_FB","MCPMSMFOC_OPEN_LOOP"])
    mcFlyingStart_Enable = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_FLYING_START",mcFlyingStartRootNode)
    mcFlyingStart_Enable.setLabel("Enable Flying Start?")
    mcFlyingStart_Enable.setDependencies(mcPmsmFocFlyingStartVisibility,["MCPMSMFOC_POSITION_FB","MCPMSMFOC_OPEN_LOOP"])
    
    mcFlyingStart_IntermediateEnable = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_INTERM_FLYING_START",mcFlyingStartRootNode)
    mcFlyingStart_IntermediateEnable.setVisible(False)
    mcFlyingStart_IntermediateEnable.setDependencies(mcPmsmFocIntermFlyingStartVisibility,["MCPMSMFOC_POSITION_FB","MCPMSMFOC_OPEN_LOOP","MCPMSMFOC_FLYING_START"])
    
    # Symbol to enable/disable Source File Selection

    mcFlyingStart_CodeType = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_FLYING_START_CODE_TYPE", mcFlyingStart_Enable)
    mcFlyingStart_CodeType.setLabel("Code Format For Flying Start")
    mcFlyingStart_CodeType.addKey("Library File", "0", "Library_File")
    mcFlyingStart_CodeType.addKey("Source File", "1", "Source_File")
    mcFlyingStart_CodeType.setVisible(False)
    mcFlyingStart_CodeType.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])
    
    mcFlyingStart_CodeTypeComment = mcPmsmFocComponent.createCommentSymbol("MCPMSMFOC_FLYING_START_CODE_TYPE_COMMENT", mcFlyingStart_Enable)
    mcFlyingStart_CodeTypeComment.setLabel("** To access source file, contact local Sales Office at https://www.microchip.com/salesdirectory **")
    mcFlyingStart_CodeTypeComment.setVisible(False)
    mcFlyingStart_CodeTypeComment.setDependencies(mcPmsmFocCodeTypeCommentCallback,["MCPMSMFOC_FLYING_START_CODE_TYPE","MCPMSMFOC_FLYING_START"]) 
    
    
    # Symbol to enable/disable current controller auto-parameter calculation
    mcFlyingStart_Autocalculate = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE", mcFlyingStart_Enable)
    mcFlyingStart_Autocalculate.setLabel("Auto Calculate Flying Start PI Parameters?")
    mcFlyingStart_Autocalculate.setVisible(False)
    mcFlyingStart_Autocalculate.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])

    # Symbol for FlyingStart mode current PI controller band-width for auto gain calculation
    mcFlyingStart_ControlBandwidth = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_CL_BANDWIDTH", mcFlyingStart_Autocalculate)
    mcFlyingStart_ControlBandwidth.setLabel("Current Loop Bandwidth (rad/s)")
    mcFlyingStart_ControlBandwidth.setValue(2000)
    mcFlyingStart_ControlBandwidth.setVisible(False)
    mcFlyingStart_ControlBandwidth.setDependencies(mcPmsmFocVisibleOnTrue , ["MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE"])    
    
    # FlyingStart mode D-axis controller root node 
    mcFlyingStart_IdControlNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_FLYING_START_Id_Menu", mcFlyingStart_Enable)
    mcFlyingStart_IdControlNode.setLabel("Flying Start mode Direct current (Id) PI Parameters")
    mcFlyingStart_IdControlNode.setVisible(False)
    mcFlyingStart_IdControlNode.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])

    # Symbol for mode FlyingStart D axis PI controller proportional gain 
    mcFlyingStart_IdCurrentKp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_ID_KP", mcFlyingStart_IdControlNode)
    mcFlyingStart_IdCurrentKp.setLabel("Kp")
    mcFlyingStart_IdCurrentKp.setDefaultValue(0.2)
    mcFlyingStart_IdCurrentKp.setDependencies(mcPmsmFocFlyingStartCurrentKpCalc, ["MCPMSMFOC_FLYING_START_CL_BANDWIDTH", "MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE",
       "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    # Symbol for D axis PI controller integral gain 
    mcFlyingStart_IdCurrentKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_ID_KI", mcFlyingStart_IdControlNode)
    mcFlyingStart_IdCurrentKi.setLabel("Ki")
    mcFlyingStart_IdCurrentKi.setDefaultValue(0.00099)
    mcFlyingStart_IdCurrentKi.setDependencies(mcPmsmFocFlyingStartCurrentKiCalc, ["MCPMSMFOC_FLYING_START_CL_BANDWIDTH", "MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE",
      "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    # Symbol for D axis PI controller back calculation gain 
    mcFlyingStart_IdCurrentKc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_ID_KC", mcFlyingStart_IdControlNode)
    mcFlyingStart_IdCurrentKc.setLabel("Kc")
    mcFlyingStart_IdCurrentKc.setDefaultValue(0.5)    

    # FlyingStart Q-axis controller root node 
    mcFlyingStart_IqControlNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_FLYING_START_Iq_Menu", mcFlyingStart_Enable)
    mcFlyingStart_IqControlNode.setLabel("Flying Start mode Quadrature current (Iq) PI Parameters")
    mcFlyingStart_IqControlNode.setVisible(False)
    mcFlyingStart_IqControlNode.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])    

    # Symbol for FlyingStart Q axis PI controller proportional gain 
    mcFlyingStart_IqCurrentKp = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_IQ_KP", mcFlyingStart_IqControlNode)
    mcFlyingStart_IqCurrentKp.setLabel("Kp")
    mcFlyingStart_IqCurrentKp.setDefaultValue(0.2)
    mcFlyingStart_IqCurrentKp.setDependencies(mcPmsmFocFlyingStartCurrentKpCalc, ["MCPMSMFOC_FLYING_START_CL_BANDWIDTH", "MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE",
       "MCPMSMFOC_LD", "MCPMSMFOC_LQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    # Symbol for Q axis PI controller integral gain 
    mcFlyingStart_IqCurrentKi = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_IQ_KI", mcFlyingStart_IqControlNode)
    mcFlyingStart_IqCurrentKi.setLabel("Ki")
    mcFlyingStart_IqCurrentKi.setDefaultValue(0.00099)
    mcFlyingStart_IqCurrentKi.setDependencies(mcPmsmFocFlyingStartCurrentKiCalc, ["MCPMSMFOC_FLYING_START_CL_BANDWIDTH", "MCPMSMFOC_FLYING_START_CL_AUTOCALCULATE",
       "MCPMSMFOC_R", "MCPMSMFOC_PWM_FREQ", "MCPMSMFOC_DC_BUS_VOLT", "MCPMSMFOC_BOARD_SEL"])

    # Symbol for Q axis PI controller back calculation gain 
    mcFlyingStart_IqCurrentKc = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_IQ_KC", mcFlyingStart_IqControlNode)
    mcFlyingStart_IqCurrentKc.setLabel("Kc")
    mcFlyingStart_IqCurrentKc.setDefaultValue(0.5)        
    
    # Symbol for FlyingStart Time if FlyingStart Mode is enabled
    mcFlyingStart_Time = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_TIME",mcFlyingStart_Enable)
    mcFlyingStart_Time.setLabel("Flying Start Detect Duration (sec)")
    mcFlyingStart_Time.setDefaultValue(0.4)
    mcFlyingStart_Time.setVisible(False)
    mcFlyingStart_Time.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])
    
    # Symbol for Minimum FlyingStart Speed if FlyingStart Mode is enabled
    mcFlyingStart_Speed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_SPEED",mcFlyingStart_Enable)
    mcFlyingStart_Speed.setLabel("Minimum Flying Start Speed (RPM)")
    mcFlyingStart_Speed.setDefaultValue(500)
    mcFlyingStart_Speed.setVisible(False)
    mcFlyingStart_Speed.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])

    # Symbol for FlyingStart Startup Current if FlyingStart Mode is enabled
    mcFlyingStart_StartupCurrent = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_STARTUP_CURRENT",mcFlyingStart_Enable)
    mcFlyingStart_StartupCurrent.setLabel("Flying Start Current (A)")
    mcFlyingStart_StartupCurrent.setDefaultValue(0.4)
    mcFlyingStart_StartupCurrent.setVisible(False)
    mcFlyingStart_StartupCurrent.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])

    # Symbol for FlyingStart Null Braking Time if FlyingStart Mode is enabled
    mcFlyingStart_NullBrakingTime = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_NULL_BRAKING_TIME",mcFlyingStart_Enable)
    mcFlyingStart_NullBrakingTime.setLabel("Null Vector Braking Duration(sec)")
    mcFlyingStart_NullBrakingTime.setDefaultValue(2)
    mcFlyingStart_NullBrakingTime.setVisible(False)
    mcFlyingStart_NullBrakingTime.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])   

    # Symbol for Enabling Regenerative Braking if FlyingStart Mode is enabled
    mcFlyingStart_RegenerativeBrakingEnable = mcPmsmFocComponent.createBooleanSymbol("MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_ENABLE",mcFlyingStart_Enable)
    mcFlyingStart_RegenerativeBrakingEnable.setLabel("Use Regenerative Braking?")
    mcFlyingStart_RegenerativeBrakingEnable.setVisible(False)
    mcFlyingStart_RegenerativeBrakingEnable.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START"])    
    
    # Symbol for FlyingStart Regenerative Braking Current if FlyingStart Mode is enabled
    mcFlyingStart_RegenBrakingCurrent = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_CURRENT",mcFlyingStart_RegenerativeBrakingEnable)
    mcFlyingStart_RegenBrakingCurrent.setLabel("Peak Regenerative Braking Current (A)")
    mcFlyingStart_RegenBrakingCurrent.setDefaultValue(0.4)
    mcFlyingStart_RegenBrakingCurrent.setVisible(False)
    mcFlyingStart_RegenBrakingCurrent.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_ENABLE"])
    
    # Symbol for FlyingStart Regenerative Braking Ramp Time if FlyingStart Mode is enabled
    mcFlyingStart_RegenBrakingRampTime = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_RAMP_TIME",mcFlyingStart_RegenerativeBrakingEnable)
    mcFlyingStart_RegenBrakingRampTime.setLabel("Regenerative Braking Ramp Duration(sec)")
    mcFlyingStart_RegenBrakingRampTime.setDefaultValue(1)
    mcFlyingStart_RegenBrakingRampTime.setVisible(False)
    mcFlyingStart_RegenBrakingRampTime.setDependencies(mcPmsmFocVisibleOnTrue,["MCPMSMFOC_FLYING_START_REGENERATIVE_BRAKING_ENABLE"])                 
    
