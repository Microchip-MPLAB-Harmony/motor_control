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

import os

global mcPmsmFocInstanceName

# Execute file for motor module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_MotorParameter.py"  )

# Execute file for inverter module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_Inverter.py"  )

# Execute file for Analog interface module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_AnalogInterface.py"  )

# Execute file for Current Measurement and Diagnosis module
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_CurrentMeasurement.py"  )

# Execute file for Digital interface module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_DigitalInterface.py" )

# Execute file for motor control and diagnosis module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_MotorControl.py"  )

# Execute file for position meaurement and diagnosis module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_PositionMeasurement.py" )

# Execute file for position interface  module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_PositionInterface.py"  )

# Execute file for PWM interface module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_PwmInterface.py" )

# Execute file for start-up module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_Startup.py"   )

# Execute file for data monitoring module 
execfile(Variables.get("__CSP_DIR") + "/../motor_control/algorithms/pmsm_foc/config/mcPmsmFoc_DataMonitoring.py"   )




#=========================================================================================================#
#                                       CALLBACK FUCNTIONS                                                #
#=========================================================================================================#
def mcPmsmFocCodeGenUpdate(symbol, event):
    component = symbol.getComponent()
    component.getSymbolByID("MCPMSMFOC_POS_PLL_HEADER").setEnabled(False)
    component.getSymbolByID("MCPMSMFOC_POS_PLL_SOURCE").setEnabled(False)
    component.getSymbolByID("MCPMSMFOC_POS_ENCODER_HEADER").setEnabled(False)
    component.getSymbolByID("MCPMSMFOC_POS_ENCODER_SOURCE").setEnabled(False)

    symObj = event["symbol"]
    key = symObj.getSelectedKey()

    if key == "SENSORLESS_PLL": #PLL
        component.getSymbolByID("MCPMSMFOC_POS_PLL_HEADER").setEnabled(True)
        component.getSymbolByID("MCPMSMFOC_POS_PLL_SOURCE").setEnabled(True)
    elif key == "SENSORED_ENCODER":  #Encoder
        component.getSymbolByID("MCPMSMFOC_POS_ENCODER_HEADER").setEnabled(True)
        component.getSymbolByID("MCPMSMFOC_POS_ENCODER_SOURCE").setEnabled(True)


def mcPmsmFocSpeedRefVisible(symbol, event):
    component = symbol.getComponent()
    if component.getSymbolValue("MCPMSMFOC_SPEED_REF") == "Potentiometer Analog Input":
        symbol.setVisible(False)
    else:
        symbol.setVisible(True)
    symbol.setMax(component.getSymbolValue("MCPMSMFOC_RATED_SPEED"))




#=========================================================================================================#
#                                       PMSM FOC COMPONENT                                                #
#=========================================================================================================#
def instantiateComponent(mcPmsmFocComponent): 
    
    Log.writeInfoMessage("Running PMSM FOC")

    mcPmsmFocInstanceName = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_INSTANCE_NAME", None)
    mcPmsmFocInstanceName.setVisible(False)
    mcPmsmFocInstanceName.setDefaultValue(mcPmsmFocComponent.getID().upper())

   
    #-----------------------------------------------------------------------------------------------------#
    #                                       MOTOR PARAMATERS                                              #
    #-----------------------------------------------------------------------------------------------------#
    mcMotI_MotorParameters( mcPmsmFocComponent)
  
    #-----------------------------------------------------------------------------------------------------#
    #                                        VSI BLOCK                                                    #
    #-----------------------------------------------------------------------------------------------------#    
    # Root node 
    global mcVsi_RootNode
    mcVsi_RootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_BOARD_CONF", None)
    mcVsi_RootNode.setLabel("Board Parameters")

    # Symbol for development board selection 
    global mcVsi_SelectedBoard
    mcVsi_SelectedBoard = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_BOARD_SEL", mcVsi_RootNode)
    mcVsi_SelectedBoard.setLabel("Select Board")
    mcVsi_SelectedBoard.addKey("Custom", "0", "Custom Board")
    mcVsi_SelectedBoard.addKey("MCLV2", "1", "MCLV2 - Low Voltage Board")
    mcVsi_SelectedBoard.addKey("MCHV3", "2", "MCHV3 - High Voltage Board")
    mcVsi_SelectedBoard.setDefaultValue(1)

    mcVsiI_VoltageSourceInverter( mcPmsmFocComponent )


    #-----------------------------------------------------------------------------------------------------#
    #                                       PWM INTERFACE                                                 #
    # ----------------------------------------------------------------------------------------------------# 
    mcPwmI_PwmInterface(mcPmsmFocComponent )

    #-----------------------------------------------------------------------------------------------------#
    #                                      ANALOG INTERFACE                                               #
    # ----------------------------------------------------------------------------------------------------# 
    mcAnII_AnalogInterface( mcPmsmFocComponent)

    #-----------------------------------------------------------------------------------------------------#
    #                                       DIGITAL INTERFACE                                       #
    #-----------------------------------------------------------------------------------------------------#
    mcDiII_DigitalInterface( mcPmsmFocComponent )
        
    #-----------------------------------------------------------------------------------------------------#
    #                                ROTOR POSITION MEASUREMENT & DIAGNOSIS                               #
    #-----------------------------------------------------------------------------------------------------#
    global mcPmsmFocAlgoMenu
    mcPmsmFocAlgoMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_ALGO_CONF", None)
    mcPmsmFocAlgoMenu.setLabel("Control Strategy")

    mcPoMI_PositionMeasurement( mcPmsmFocComponent)

    #-----------------------------------------------------------------------------------------------------#
    #                                      POSITION INTERFACE                                             #
    # ----------------------------------------------------------------------------------------------------# 
    mcPoII_PositionInterface(mcPmsmFocComponent)


    #-----------------------------------------------------------------------------------------------------#
    #                                    CURRENT MEASUREMENT & DIAGNOSIS                                  #
    #-----------------------------------------------------------------------------------------------------#
    mcCuMI_CurrentMeasurement( mcPmsmFocComponent )
  
    #-----------------------------------------------------------------------------------------------------#
    #                                       MOTOR CONTROL & DIAGNOSIS                                     #
    #-----------------------------------------------------------------------------------------------------#
    global mcPmsmFocCtrlMenu
    mcPmsmFocCtrlMenu = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_CTRL_CONF", None)
    mcPmsmFocCtrlMenu.setLabel("Control Parameters")
    
    mcMoCI_MotorControl( mcPmsmFocComponent )
   

    #-----------------------------------------------------------------------------------------------------#
    #                                         STARTUP CONFIGURATOR                                        #
    #-----------------------------------------------------------------------------------------------------#
    mcStCI_StartupConfigurator( mcPmsmFocComponent )

    #-----------------------------------------------------------------------------------------------------#
    #                                          DATA MONITORING                                            #
    #-----------------------------------------------------------------------------------------------------#
    mcDaMI_DataMonitoring( mcPmsmFocComponent )
    
    #=====================================================================================================#
    #                                            CODE GENERATION                                          #
    #=====================================================================================================#
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


#=========================================================================================================#
#                                         DEPENDENCY                                                      #
#=========================================================================================================#
def onAttachmentConnected( source, target ):
    # ADC Peripheral 
    mcAnII_OnAttachmentConnected( source, target )

    # PWM Peripheral
    mcPwm_onAttachmentConnected( source, target )

    # QEI Peripheral
    mcPosI_OnAttachmentConnected( source, target )

    # X2C Scope 
    mcDaMI_OnAttachmentConnected( source, target )

    
    
def onAttachmentDisconnected( source, target ):
    # ADC Peripheral
    mcAnII_OnAttachmentDisconnected( source, target )

    # PWM Peripheral 
    mcPwm_onAttachmentDisconnected( source, target )

    # QEI Peripheral
    mcPosI_OnAttachmentDisconnected( source, target )

    # X2C Scope 
    mcDaMI_OnAttachmentDisconnected( source, target )

