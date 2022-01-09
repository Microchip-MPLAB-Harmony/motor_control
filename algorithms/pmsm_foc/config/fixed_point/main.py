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
global mcPmsmFocSeries

# Execute file for motor module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_MotorParameter.py"  )

# Execute file for inverter module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_Inverter.py"  )

# Execute file for Analog interface module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_AnalogInterface.py"  )

# Execute file for Current Measurement and Diagnosis module
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_CurrentMeasurement.py"  )

# Execute file for Digital interface module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_DigitalInterface.py" )

# Execute file for motor control and diagnosis module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_MotorControl.py"  )

# Execute file for position meaurement and diagnosis module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_PositionMeasurement.py" )

# Execute file for position interface  module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_PositionInterface.py"  )

# Execute file for PWM interface module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_PwmInterface.py" )

# Execute file for start-up module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_Startup.py"   )

# Execute file for data monitoring module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_DataMonitoring.py"   )

# Execute file for Flying Start module 
execfile(Module.getPath() + "/algorithms/pmsm_foc/config/fixed_point/mcPmsmFoc_FlyingStart.py"   )


#=========================================================================================================#
#                                       CALLBACK FUCNTIONS                                                #
#=========================================================================================================#

def mcPmsmFocCodeGenUpdate(symbol, event):
    component = symbol.getComponent()
    if (event["id"] == "MCPMSMFOC_POSITION_FB"):
        symObj = event["symbol"]
        key = symObj.getSelectedKey()

        if(key == "SENSORED_ENCODER"):
            component.getSymbolByID("MCPMSMFOC_POS_ENCODER_HEADER").setEnabled(True)    
            component.getSymbolByID("MCPMSMFOC_POS_ENCODER_SOURCE").setEnabled(True)            
        else:
            component.getSymbolByID("MCPMSMFOC_POS_ENCODER_HEADER").setEnabled(False)    
            component.getSymbolByID("MCPMSMFOC_POS_ENCODER_SOURCE").setEnabled(False)

        if(key == "SENSORLESS_PLL"):
            component.getSymbolByID("MCPMSMFOC_POS_PLL_HEADER").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_POS_PLL_SOURCE").setEnabled(True)
        else:
            component.getSymbolByID("MCPMSMFOC_POS_PLL_HEADER").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_POS_PLL_SOURCE").setEnabled(False)

        if(key == "SENSORLESS_ROLO"):
            component.getSymbolByID("MCPMSMFOC_POS_ROLO_HEADER").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_POS_ROLO_SOURCE").setEnabled(True)
        else:
            component.getSymbolByID("MCPMSMFOC_POS_ROLO_HEADER").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_POS_ROLO_SOURCE").setEnabled(False)

        if(key == "SENSORLESS_SMO"):
            component.getSymbolByID("MCPMSMFOC_POS_SMO_HEADER").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_POS_SMO_SOURCE").setEnabled(True)
        else:
            component.getSymbolByID("MCPMSMFOC_POS_SMO_HEADER").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_POS_SMO_SOURCE").setEnabled(False)
			
			
    elif (event["id"] == "MCPMSMFOC_FLYING_START_CODE_TYPE"):
        if event["value"] == 1:
            if(component.getSymbolByID("MCPMSMFOC_FLYING_START").getValue() == True):
                component.getSymbolByID("MCPMSMFOC_FLYING_START_HEADER").setEnabled(True)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_SOURCE").setEnabled(True)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_LIB").setEnabled(False)
                
            else:
                component.getSymbolByID("MCPMSMFOC_FLYING_START_HEADER").setEnabled(False)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_SOURCE").setEnabled(False)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_LIB").setEnabled(False)                
                
        else:
            if(component.getSymbolByID("MCPMSMFOC_FLYING_START").getValue() == True):
                component.getSymbolByID("MCPMSMFOC_FLYING_START_HEADER").setEnabled(True)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_SOURCE").setEnabled(False)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_LIB").setEnabled(True)
                
            else:
                component.getSymbolByID("MCPMSMFOC_FLYING_START_HEADER").setEnabled(False)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_SOURCE").setEnabled(False)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_LIB").setEnabled(False)
                
    elif (event["id"] == "MCPMSMFOC_FLYING_START"):
        if event["value"] == True:
            if(component.getSymbolByID("MCPMSMFOC_FLYING_START_CODE_TYPE").getValue() == 1):
                component.getSymbolByID("MCPMSMFOC_FLYING_START_HEADER").setEnabled(True)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_SOURCE").setEnabled(True)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_LIB").setEnabled(False)
                
            else:
                component.getSymbolByID("MCPMSMFOC_FLYING_START_HEADER").setEnabled(True)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_SOURCE").setEnabled(False)
                component.getSymbolByID("MCPMSMFOC_FLYING_START_LIB").setEnabled(True)
                
        else:
            component.getSymbolByID("MCPMSMFOC_FLYING_START_HEADER").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_FLYING_START_SOURCE").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_FLYING_START_LIB").setEnabled(False)

    if (event["id"] == "MCPMSMFOC_REF_INPUT"):
        symObj = event["symbol"]
        key = symObj.getSelectedKey()
        if(key == "INPUT_FROM_API"):
            component.getSymbolByID("MCPMSMFOC_RAMP_PROFILER_HEADER").setEnabled(True)    
            component.getSymbolByID("MCPMSMFOC_RAM_PROFILER_SOURCE").setEnabled(True)            
        else:
            component.getSymbolByID("MCPMSMFOC_RAMP_PROFILER_HEADER").setEnabled(False)    
            component.getSymbolByID("MCPMSMFOC_RAM_PROFILER_SOURCE").setEnabled(False)
            

            


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

    global mcPmsmFocSeries
    mcPmsmFocSeries = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_SERIES", None)
    mcPmsmFocSeries.setVisible(False)
    mcPmsmFocSeries.setDefaultValue(ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("series"))
 
    global mcPmsmFocArch
    mcPmsmFocArch = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_ARCH", None)
    mcPmsmFocArch.setVisible(False)
    mcPmsmFocArch.setDefaultValue(ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("architecture")) 
   
  
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
#                                       MOTOR PARAMATERS                                              #
#-----------------------------------------------------------------------------------------------------#
    mcMotI_MotorParameters( mcPmsmFocComponent)


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
    if(("PIC32CM" in Variables.get("__PROCESSOR")) or ( "SAMC21" in Variables.get("__PROCESSOR"))):
        templatePath = "/algorithms/pmsm_foc/templates/fixed/"
        mcPmsmFocSystemDefFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_DEF", None)
        mcPmsmFocSystemDefFile.setType("STRING")
        mcPmsmFocSystemDefFile.setOutputName("core.LIST_SYSTEM_DEFINITIONS_H_INCLUDES")
        mcPmsmFocSystemDefFile.setSourcePath(templatePath + "system/definitions.h.ftl")
        mcPmsmFocSystemDefFile.setMarkup(True)

        mcPmsmFocSystemInitFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_INIT", None)
        mcPmsmFocSystemInitFile.setType("STRING")
        mcPmsmFocSystemInitFile.setOutputName("core.LIST_SYSTEM_INIT_C_INITIALIZE_MIDDLEWARE")
        mcPmsmFocSystemInitFile.setSourcePath(templatePath + "system/initialization.c.ftl")
        mcPmsmFocSystemInitFile.setMarkup(True)

        mcPmsmFocRampProfilerHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_RAMP_PROFILER_HEADER", None)
        mcPmsmFocRampProfilerHeaderFile.setSourcePath(templatePath + "ramp_profiler.h.ftl")
        mcPmsmFocRampProfilerHeaderFile.setOutputName("mc_ramp_profiler.h")
        mcPmsmFocRampProfilerHeaderFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocRampProfilerHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocRampProfilerHeaderFile.setType("HEADER")
        mcPmsmFocRampProfilerHeaderFile.setMarkup(True)

        mcPmsmFocRampProfilerSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_RAMP_PROFILER_SOURCE", None)
        mcPmsmFocRampProfilerSourceFile.setSourcePath(templatePath + "ramp_profiler.c.ftl")
        mcPmsmFocRampProfilerSourceFile.setOutputName("mc_ramp_profiler.c")
        mcPmsmFocRampProfilerSourceFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocRampProfilerSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocRampProfilerSourceFile.setType("HEADER")
        mcPmsmFocRampProfilerSourceFile.setMarkup(True)
        
    else:
        templatePath = "/algorithms/pmsm_foc/templates/floating/"
    
        # Included in the if condition to avoid interference
        mcPmsmFocCodeGen = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_CODE_GEN", None)
        mcPmsmFocCodeGen.setVisible(False)
        mcPmsmFocCodeGen.setDependencies(mcPmsmFocCodeGenUpdate, ["MCPMSMFOC_POSITION_FB","MCPMSMFOC_FLYING_START","MCPMSMFOC_FLYING_START_CODE_TYPE"])
        
        mcPmsmFocSystemDefFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_DEF", None)
        mcPmsmFocSystemDefFile.setType("STRING")
        mcPmsmFocSystemDefFile.setOutputName("core.LIST_SYSTEM_DEFINITIONS_H_INCLUDES")
        mcPmsmFocSystemDefFile.setSourcePath(templatePath + "system/definitions.h.ftl")
        mcPmsmFocSystemDefFile.setMarkup(True)

        mcPmsmFocSystemInitFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_INIT", None)
        mcPmsmFocSystemInitFile.setType("STRING")
        mcPmsmFocSystemInitFile.setOutputName("core.LIST_SYSTEM_INIT_C_INITIALIZE_MIDDLEWARE")
        mcPmsmFocSystemInitFile.setSourcePath(templatePath + "system/initialization.c.ftl")
        mcPmsmFocSystemInitFile.setMarkup(True)

        mcPmsmFocPosPllSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_PLL_SOURCE", None)
        mcPmsmFocPosPllSourceFile.setSourcePath(templatePath + "pos_pll.c.ftl")
        mcPmsmFocPosPllSourceFile.setOutputName("mc_rotor_position.c")
        mcPmsmFocPosPllSourceFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosPllSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosPllSourceFile.setType("SOURCE")
        mcPmsmFocPosPllSourceFile.setMarkup(True)

       
        mcPmsmFocPosPllHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_PLL_HEADER", None)
        mcPmsmFocPosPllHeaderFile.setSourcePath(templatePath + "pos_pll.h.ftl")
        mcPmsmFocPosPllHeaderFile.setOutputName("mc_rotor_position.h")
        mcPmsmFocPosPllHeaderFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosPllHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosPllHeaderFile.setType("HEADER")
        mcPmsmFocPosPllHeaderFile.setMarkup(True)

        mcPmsmFocPosRoloSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_ROLO_SOURCE", None)
        mcPmsmFocPosRoloSourceFile.setSourcePath(templatePath + "pos_rolo.c.ftl")
        mcPmsmFocPosRoloSourceFile.setOutputName("mc_rotor_position.c")
        mcPmsmFocPosRoloSourceFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosRoloSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosRoloSourceFile.setType("SOURCE")
        mcPmsmFocPosRoloSourceFile.setMarkup(True)

        mcPmsmFocPosRoloHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_ROLO_HEADER", None)
        mcPmsmFocPosRoloHeaderFile.setSourcePath(templatePath + "pos_rolo.h.ftl")
        mcPmsmFocPosRoloHeaderFile.setOutputName("mc_rotor_position.h")
        mcPmsmFocPosRoloHeaderFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosRoloHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosRoloHeaderFile.setType("HEADER")
        mcPmsmFocPosRoloHeaderFile.setMarkup(True)	

        mcPmsmFocPosSmoSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_SMO_SOURCE", None)
        mcPmsmFocPosSmoSourceFile.setSourcePath(templatePath + "pos_smo.c.ftl")
        mcPmsmFocPosSmoSourceFile.setOutputName("mc_rotor_position.c")
        mcPmsmFocPosSmoSourceFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosSmoSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosSmoSourceFile.setType("SOURCE")
        mcPmsmFocPosSmoSourceFile.setMarkup(True)

        mcPmsmFocPosSmoHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_SMO_HEADER", None)
        mcPmsmFocPosSmoHeaderFile.setSourcePath(templatePath + "pos_smo.h.ftl")
        mcPmsmFocPosSmoHeaderFile.setOutputName("mc_rotor_position.h")
        mcPmsmFocPosSmoHeaderFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosSmoHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosSmoHeaderFile.setType("HEADER")
        mcPmsmFocPosSmoHeaderFile.setMarkup(True)

        mcPmsmFocPosEncSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_ENCODER_SOURCE", None)
        mcPmsmFocPosEncSourceFile.setSourcePath(templatePath + "pos_encoder.c.ftl")
        mcPmsmFocPosEncSourceFile.setOutputName("mc_rotor_position.c")
        mcPmsmFocPosEncSourceFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosEncSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosEncSourceFile.setType("SOURCE")
        mcPmsmFocPosEncSourceFile.setMarkup(True)

        mcPmsmFocPosEncHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_POS_ENCODER_HEADER", None)
        mcPmsmFocPosEncHeaderFile.setSourcePath(templatePath + "pos_encoder.h.ftl")
        mcPmsmFocPosEncHeaderFile.setOutputName("mc_rotor_position.h")
        mcPmsmFocPosEncHeaderFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosEncHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosEncHeaderFile.setType("HEADER")
        mcPmsmFocPosEncHeaderFile.setMarkup(True)


        mcPmsmFocPosFlyingStartHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_FLYING_START_HEADER", None)
        mcPmsmFocPosFlyingStartHeaderFile.setSourcePath(templatePath + "flyingstart.h")
        mcPmsmFocPosFlyingStartHeaderFile.setOutputName("mc_flyingstart.h")
        mcPmsmFocPosFlyingStartHeaderFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosFlyingStartHeaderFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosFlyingStartHeaderFile.setType("HEADER")
        mcPmsmFocPosFlyingStartHeaderFile.setMarkup(True)
        mcPmsmFocPosFlyingStartHeaderFile.setEnabled(False)
    

        mcPmsmFocPosFlyingStartSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_FLYING_START_SOURCE", None)
        mcPmsmFocPosFlyingStartSourceFile.setSourcePath("../mc_src_flying_start/src/mc_flyingstart.c")
        mcPmsmFocPosFlyingStartSourceFile.setOutputName("mc_flyingstart.c")
        mcPmsmFocPosFlyingStartSourceFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosFlyingStartSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
        mcPmsmFocPosFlyingStartSourceFile.setType("SOURCE")
        mcPmsmFocPosFlyingStartSourceFile.setMarkup(True)
        mcPmsmFocPosFlyingStartSourceFile.setEnabled(False)
        
        mcPmsmFocPosFlyingStartLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_FLYING_START_LIB", None)
        if(("SAMD5" in Variables.get("__PROCESSOR")) or ("SAME5" in Variables.get("__PROCESSOR"))):
            mcPmsmFocPosFlyingStartLibraryFile.setSourcePath("/algorithms/pmsm_foc/lib/flying_start/lib_SAM_D5x_E5x_MC_FLYINGSTART.X.a")
        elif(("SAME7" in Variables.get("__PROCESSOR")) or ("SAMV7" in Variables.get("__PROCESSOR")) or ("SAMS7" in Variables.get("__PROCESSOR"))):
            mcPmsmFocPosFlyingStartLibraryFile.setSourcePath("/algorithms/pmsm_foc/lib/flying_start/lib_SAM_E7x_S7x_V7x_MC_FLYINGSTART.X.a")
        elif("PIC32MK" in Variables.get("__PROCESSOR")):
            mcPmsmFocPosFlyingStartLibraryFile.setSourcePath("/algorithms/pmsm_foc/lib/flying_start/lib_PIC32MK_MC_FLYINGSTART.X.a")
        mcPmsmFocPosFlyingStartLibraryFile.setOutputName("lib_mc_flyingstart.a")
        mcPmsmFocPosFlyingStartLibraryFile.setDestPath("motor_control/pmsm_foc/")
        mcPmsmFocPosFlyingStartLibraryFile.setEnabled(False)
   
   

    for root, dirs, files in os.walk(Module.getPath()+ templatePath ):
        for filename in files:
            if (".c" in filename and "mc_" in filename):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(templatePath + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("motor_control/pmsm_foc/")
                mcPmsmFocSourceFile.setProjectPath("config/" + configName +"/motor_control/pmsm_foc/")
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)

            if (".h" in filename and "mc_" in filename):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath( templatePath + filename)
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

    #Configure EVSYS for SAME54
    if mcPmsmFocSeries.getValue() == "SAME54" or mcPmsmFocSeries.getValue() == "SAMC21" or mcPmsmFocSeries.getValue() == "PIC32CMMC00":
        mcEvsysDependencySAME54Connected()

    # Instantiate DIVAS for SAMC21 and PIC32CM
    if mcPmsmFocSeries.getValue() == "SAMC21" or mcPmsmFocSeries.getValue() == "PIC32CMMC00":
        divasComponent = ["divas"]
        Database.activateComponents(divasComponent)


def mcEvsysDependencySAME54Connected():
    pwmInstance = mcPwm_Plib.getValue().upper()
    adcInstance = mcAnI_Adc0Plib.getValue().upper()
    eic = filter(str.isdigit, str(mcPwm_PwmFault.getValue()))
    generator0 = generator1 = user0 = user1 = 0

    if (pwmInstance != "NONE") and (adcInstance != "NONE"):
        #EVSYS channel 0 = TCC overflow to ADC Start
        #EVSYS channel 1 = EIC fault pin to TCC event 1 fault
        Database.setSymbolValue("evsys", "EVSYS_CHANNEL_0", True)
        Database.setSymbolValue("evsys", "EVSYS_CHANNEL_1", True)
        Database.setSymbolValue("evsys", "EVSYS_CHANNEL_0_EDGE", 1) 
        Database.setSymbolValue("evsys", "EVSYS_CHANNEL_1_EDGE", 1)
        
        #Find event GENERATOR numbers from ATDF
        node = ATDF.getNode("/avr-tools-device-file/devices/device/events/generators")
        generators = []
        sortedGenerators = []
    
        for id in range(0, len(node.getChildren())):
            generators.append(id)
            generators[id] = node.getChildren()[id].getAttribute("name")

        sortedGenerators = sorted(generators)

        for id in range(0, len(sortedGenerators)):
            if str(pwmInstance) + "_OVF" in sortedGenerators[id]:
                generator0 = int(id)
            if "EIC_EXTINT_" + str(eic) in sortedGenerators[id]:
                generator1 = int(id)

        #Find event USER numbers from ATDF
        node = ATDF.getNode("/avr-tools-device-file/devices/device/events/users")
        users = []

        for id in range(0, len(node.getChildren())):
            users.append(id)
            users[id] = node.getChildren()[id].getAttribute("name")   
        for id in range(0, len(node.getChildren())):
            if str(adcInstance) + "_START" in users[id]:
                user0 = int(node.getChildren()[id].getAttribute("index"))
            if str(pwmInstance) + "_EV_1" in users[id]:
                user1 = int(node.getChildren()[id].getAttribute("index"))

        Database.setSymbolValue("evsys", "EVSYS_CHANNEL_0_GENERATOR", int(generator0))
        Database.setSymbolValue("evsys", "EVSYS_CHANNEL_1_GENERATOR", int(generator1))   
        Database.setSymbolValue("evsys", "EVSYS_USER_" + str(user0), 1)
        Database.setSymbolValue("evsys", "EVSYS_USER_" + str(user1), 2)
    
    
def onAttachmentDisconnected( source, target ):
    # ADC Peripheral
    mcAnII_OnAttachmentDisconnected( source, target )

    # PWM Peripheral 
    mcPwm_onAttachmentDisconnected( source, target )

    # QEI Peripheral
    mcPosI_OnAttachmentDisconnected( source, target )

    # X2C Scope 
    mcDaMI_OnAttachmentDisconnected( source, target )
  