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

global templatePath
templatePath = "/algorithms/pmsm_foc/templates/fixed/"

global zsmtLibraryPath
zsmtLibraryPath = Module.getPath()+"../mc_zsmt_libraries/"


def mcGen_GenerateCodeUpdate(symbol, event):
    component = symbol.getComponent()
    
    if ( str( event["id"] ) == "MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM"):
       
        # ToDO: Check 
        if ( ( str( event["value"] ) == "INITIAL_POSITION_DETECTION" ) or ( event["value"]  == 1 )) :
            component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(True)
            # component.getSymbolByID("MCPMSMFOC_IPD_SOURCE").setEnabled(True)
        else:
            component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(False)
            # component.getSymbolByID("MCPMSMFOC_IPD_SOURCE").setEnabled(False)
                        
    elif ( str( event["id"]) == "MCPMSMFOC_POSITION_CALC_ALGORITHM"):  
        symObj = event["symbol"]
        key = (symObj.getSelectedKey()).lower()
        modulePath = templatePath + "Field_Oriented_Control/"
      
        for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
            for filename in files:
                if (filename.startswith("opt_rpo")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False) 
                        
        for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
            for filename in files:
                if (filename.startswith("opt_rpo")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False) 
            
    elif  ( str( event["id"] ) == "MCPMSMFOC_FOC_X2C_ENABLE"):
        if (True == event["value"]):
            # Delete all the QSpin generated files for field oriented control module
            # Disable all QSpin files for field oriented control module
            modulePath = templatePath + "Field_Oriented_Control/"
            
            for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
                for filename in files:
                    if (".h" in filename and (filename.startswith("mc_") or filename.startswith("opt_rpo"))):
                         component.getSymbolByID(str(filename)).setEnabled(False)  
                         
            for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
                for filename in files:
                    if (".c" in filename and (filename.startswith("mc_") or filename.startswith("opt_rpo"))):
                        component.getSymbolByID(str(filename)).setEnabled(False)                                    
                                      
            # Enable all X2C files for field oriented control module 
            for root, dirs, files in os.walk(Module.getPath() + modulePath + "X2CCode"):
                for filename in files:
                    component.getSymbolByID(str(filename)).setEnabled(True)
                    
            # component.getSymbolByID("MCPMSMFOC_IPD_SOURCE").setEnabled(False)                                   
            component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(False)
            
            # Enable 
            component.getSymbolByID(str("opt_foc.h.ftl")).setEnabled(False) 
            component.getSymbolByID(str("opt_foc.c.ftl")).setEnabled(False) 
            component.getSymbolByID(str("opt_foc_x2cmodel.h.ftl")).setEnabled(True) 
            component.getSymbolByID(str("opt_foc_x2cmodel.c.ftl")).setEnabled(True) 
        else:
            symObj = component.getSymbolByID("MCPMSMFOC_POSITION_CALC_ALGORITHM")
            key = (symObj.getSelectedKey()).lower()
        
            modulePath = templatePath + "Field_Oriented_Control/"
              
            for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc" ):
                for filename in files:
                    if (".h" in filename ):
                        if filename.startswith("mc_"):
                            component.getSymbolByID(str(filename)).setEnabled(True)
                        elif filename.startswith("opt_rpo"):
                            if key in filename:
                                component.getSymbolByID(filename).setEnabled(True)
                            else:
                                component.getSymbolByID(filename).setEnabled(False)
                    
            for root, dirs, files in os.walk(Module.getPath() + modulePath + "src" ):
                for filename in files:
                    if (".c" in filename ):
                        if filename.startswith("mc_"):
                            component.getSymbolByID(str(filename)).setEnabled(True)
                        elif filename.startswith("opt_rpo"):
                            if key in filename:
                                component.getSymbolByID(filename).setEnabled(True)
                            else:
                                component.getSymbolByID(filename).setEnabled(False) 
                                                    
            for root, dirs, files in os.walk(Module.getPath() + modulePath + "X2CCode"):
                for filename in files:
                    component.getSymbolByID(str(filename)).setEnabled(False)
                           
            # component.getSymbolByID("MCPMSMFOC_IPD_SOURCE").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(True)
            
            # Disable 
            component.getSymbolByID(str("opt_foc.h.ftl")).setEnabled(True) 
            component.getSymbolByID(str("opt_foc.c.ftl")).setEnabled(True) 
            component.getSymbolByID(str("opt_foc_x2cmodel.h.ftl")).setEnabled(False) 
            component.getSymbolByID(str("opt_foc_x2cmodel.c.ftl")).setEnabled(False) 

            
def mcGen_GenerateCode(mcPmsmFocComponent):
    coreComponent = Database.getComponentByID("core")
    configName = Variables.get("__CONFIGURATION_NAME")

    #-----------------------------------------------------------------------------------------------------------------------
    #     Main File
    #-----------------------------------------------------------------------------------------------------------------------   
    # Disable default main file and generate from ftl file 
    coreComponent.getSymbolByID("CoreMainFile").setValue(False)
    mainSourceFile = mcPmsmFocComponent.createFileSymbol("MAIN_MOTOR_CONTROL_C", None)
    mainSourceFile.setSourcePath(templatePath + "main.c.ftl")
    mainSourceFile.setOutputName("main.c")
    mainSourceFile.setMarkup(True)
    mainSourceFile.setOverwrite(False)
    mainSourceFile.setDestPath("../../")
    mainSourceFile.setProjectPath("")
    mainSourceFile.setType("SOURCE")
        
    #-----------------------------------------------------------------------------------------------------------------------
    #     Application source and header file
    #-----------------------------------------------------------------------------------------------------------------------
    filename = "mc_application.c.ftl"
    projectPath = "config/" + configName + "/QSpin"
    
    # Include directory 
    appIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    appIncludeDirectory.setCategory("C32")
    appIncludeDirectory.setKey("extra-include-directories")
    appIncludeDirectory.setValue("../src/" + projectPath)
    appIncludeDirectory.setAppend(True, ";")
        
    appSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
    appSourceFile.setSourcePath(templatePath + filename)
    if (filename.endswith(".ftl")):
        filename = filename[:-4]
    appSourceFile.setOutputName(filename)
    appSourceFile.setDestPath("QSpin")
    appSourceFile.setProjectPath(projectPath)
    appSourceFile.setType("SOURCE")
    appSourceFile.setMarkup(True)
                
    filename = "mc_application.h.ftl"
    projectPath = "config/" + configName + "/QSpin"
    appHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
    appHeaderFile.setSourcePath(templatePath + filename)
    if (filename.endswith(".ftl")):
        filename = filename[:-4]
    appHeaderFile.setOutputName(filename)
    appHeaderFile.setDestPath("QSpin")
    appHeaderFile.setProjectPath(projectPath)
    appHeaderFile.setType("HEADER")
    appHeaderFile.setMarkup(True)
    #-----------------------------------------------------------------------------------------------------------------------
    #     Types File
    #-----------------------------------------------------------------------------------------------------------------------
    filename = "mc_types.h.ftl"
    projectPath = "config/" + configName + "/QSpin"
    appHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
    appHeaderFile.setSourcePath(templatePath + filename)
    if (filename.endswith(".ftl")):
        filename = filename[:-4]
    appHeaderFile.setOutputName(filename)
    appHeaderFile.setDestPath("QSpin")
    appHeaderFile.setProjectPath(projectPath)
    appHeaderFile.setType("HEADER")
    appHeaderFile.setMarkup(True)
        
    #-----------------------------------------------------------------------------------------------------------------------
    #     Field Oriented Control module code generation
    #-----------------------------------------------------------------------------------------------------------------------
    modulePath = templatePath + "Field_Oriented_Control/"
    projectPath = "config/" + configName + "/QSpin/Field_Oriented_Control/"
    
    focIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    focIncludeDirectory.setCategory("C32")
    focIncludeDirectory.setKey("extra-include-directories")
    focIncludeDirectory.setValue("../src/" + projectPath + "inc")
    focIncludeDirectory.setAppend(True, ";")
    
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename):
                if filename.startswith("mc_"):
                    mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                    if (filename.endswith(".ftl")):
                        filename = filename[:-4]
                    mcPmsmFocSourceFile.setOutputName(filename)
                    mcPmsmFocSourceFile.setDestPath("QSpin/Field_Oriented_Control/src")
                    mcPmsmFocSourceFile.setProjectPath(projectPath + "src")
                    mcPmsmFocSourceFile.setType("SOURCE")
                    mcPmsmFocSourceFile.setMarkup(True)
                    
                elif filename.startswith("opt_rpo"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "src/" + filename)
                    mcPmsmFocHeaderFile.setOutputName("mc_rotor_position_calculation.c")
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control/src")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath + "src")
                    mcPmsmFocHeaderFile.setType("SOURCE")
                    mcPmsmFocHeaderFile.setMarkup(True)
                    
                elif filename.startswith("opt_foc"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "src/" + filename)
                    mcPmsmFocHeaderFile.setOutputName("mc_field_oriented_control.c")
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control/src")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath + "src")
                    mcPmsmFocHeaderFile.setType("SOURCE")
                    mcPmsmFocHeaderFile.setMarkup(True)
                
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename):
                if filename.startswith("mc_"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    if (filename.endswith(".ftl")):
                        filename = filename[:-4]
                    mcPmsmFocHeaderFile.setOutputName(filename)
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control/inc")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath + "inc")
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)
                    
                elif filename.startswith("opt_rpo"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    mcPmsmFocHeaderFile.setOutputName("mc_rotor_position_calculation.h")
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control/inc")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath + "inc")
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)
                    
                elif filename.startswith("opt_foc"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    mcPmsmFocHeaderFile.setOutputName("mc_field_oriented_control.h")
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control/inc")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath + "inc")
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)
     
    # ipdSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_IPD_SOURCE", None)
    # ipdSourceFile.setSourcePath(modulePath + "src/" + "opt_ipd.c.ftl")
    # ipdSourceFile.setOutputName("mc_initial_position_detection.c")
    # ipdSourceFile.setDestPath("QSpin/Field_Oriented_Control/src")
    # ipdSourceFile.setProjectPath(projectPath + "src")
    # ipdSourceFile.setType("SOURCE")
    # ipdSourceFile.setMarkup(True)

    ipdHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_IPD_HEADER", None)
    ipdHeaderFile.setSourcePath(modulePath + "inc/" + "opt_ipd.h.ftl")
    ipdHeaderFile.setOutputName("mc_initial_position_detection.h")
    ipdHeaderFile.setDestPath("QSpin/Field_Oriented_Control/inc")
    ipdHeaderFile.setProjectPath(projectPath + "inc")
    ipdHeaderFile.setType("HEADER")
    ipdHeaderFile.setMarkup(True)
    
    if os.path.exists(zsmtLibraryPath):
        if( ("SAME7" in Variables.get("__PROCESSOR")) or ("SAMS7" in Variables.get("__PROCESSOR")) or ("SAMV7" in Variables.get("__PROCESSOR"))):      
            zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_LIB_SAME70_A", None)
            zsmtLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM7-ATSAM_MCHP_ZSMT.a")
            zsmtLibraryFile.setOutputName("libCortexM7-ATSAM_MCHP_ZSMT.a")
            zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")     
            
            ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_LIB_SAME70_A", None)
            ipdLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM7-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setOutputName("libCortexM7-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")         
        
        elif( ("PIC32CM" in Variables.get("__PROCESSOR")) or ("SAMD2" in Variables.get("__PROCESSOR")) or ("SAMC2" in Variables.get("__PROCESSOR")) or ("SAML2" in Variables.get("__PROCESSOR"))):               
            zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_A_PIC32MK_A", None)
            zsmtLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM0Plus-ATSAM_MCHP_ZSMT.a")
            zsmtLibraryFile.setOutputName("libCortexM0Plus-ATSAM_MCHP_ZSMT.a")
            zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")        
            
            ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_A_PIC32MK_A", None)
            ipdLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM0Plus-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setOutputName("libCortexM0Plus-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")        
    
        elif( ("SAMD5" in Variables.get("__PROCESSOR")) or ("SAME5" in Variables.get("__PROCESSOR"))):
            zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_LIB_SAME54_A", None)
            zsmtLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM4-ATSAM_MCHP_ZSMT.a")
            zsmtLibraryFile.setOutputName("libCortexM4-ATSAM_MCHP_ZSMT.a")
            zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")        
            
            ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_LIB_SAME54_A", None)
            ipdLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM4-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setOutputName("libCortexM4-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")       
    
        elif("PIC32MX" in Variables.get("__PROCESSOR")):
            zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_A_PIC32MX_A", None)
            zsmtLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libPIC32MX_MCHP.a")
            zsmtLibraryFile.setOutputName("libPIC32MX_MCHP_ZSMT.a")
            zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")
            
            ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_LIB_SAME54_A", None)
            ipdLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM4-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setOutputName("libCortexM4-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")  
    
        elif("PIC32MZ" in Variables.get("__PROCESSOR")):              
            zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_A_PIC32MK_A", None)
            zsmtLibraryFile.setSourcePath("../../x2c_installer_files/Library/MCH_ZSMT/Controller/lib/libPIC32MK_MCHP_ZSMT.a")
            zsmtLibraryFile.setOutputName("libPIC32MK_MCHP_ZSMT.a")
            zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/") 
            
            ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_LIB_SAME54_A", None)
            ipdLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libCortexM4-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setOutputName("libCortexM4-ATSAM_MCHP_IPD.a")
            ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/")        
    
        elif("PIC32MK" in Variables.get("__PROCESSOR")):
            zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_A_PIC32MK_A", None)
            zsmtLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libPIC32MK_MCHP_ZSMT.a")
            zsmtLibraryFile.setOutputName("libPIC32MK_MCHP_ZSMT.a")
            zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/") 
            
            ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_A_PIC32MK_A", None)
            ipdLibraryFile.setSourcePath("../mc_zsmt_libraries/Harmony/lib/libPIC32MK_MCHP_IPD.a")
            ipdLibraryFile.setOutputName("libPIC32MK_MCHP_IPD.a")
            ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/lib/") 
            
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "X2CCode"):
        for filename in files:
            x2cModelFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
            x2cModelFile.setSourcePath(modulePath + "X2CCode/" + filename)
            if (filename.endswith(".ftl")):
                filename = filename[:-4]
            x2cModelFile.setOutputName(filename)
            x2cModelFile.setDestPath("/X2CCode/")
            x2cModelFile.setProjectPath("config/" + configName + "/X2CCode/")
            x2cModelFile.setType("IMPORTANT")
            x2cModelFile.setMarkup(True)
                
    #-----------------------------------------------------------------------------------------------------------------------
    #     Current Calculation module code generation
    #-----------------------------------------------------------------------------------------------------------------------
    modulePath = templatePath + "Current_Calculation/"
    projectPath = "config/" + configName + "/QSpin/Current_Calculation/"
    
    curIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    curIncludeDirectory.setCategory("C32")
    curIncludeDirectory.setKey("extra-include-directories")
    curIncludeDirectory.setValue("../src/" + projectPath + "inc")
    curIncludeDirectory.setAppend(True, ";")
    
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Current_Calculation/src")
                mcPmsmFocSourceFile.setProjectPath(projectPath + "src")
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)
                
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename and filename.startswith("mc_")):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("QSpin/Current_Calculation/inc")
                mcPmsmFocHeaderFile.setProjectPath(projectPath + "inc")
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)
                
    #-----------------------------------------------------------------------------------------------------------------------
    #     Voltage Calculation module code generation
    #-----------------------------------------------------------------------------------------------------------------------
    modulePath = templatePath + "Voltage_Calculation/"
    projectPath = "config/" + configName + "/QSpin/Voltage_Calculation/"
    
    volIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    volIncludeDirectory.setCategory("C32")
    volIncludeDirectory.setKey("extra-include-directories")
    volIncludeDirectory.setValue("../src/" + projectPath + "inc")
    volIncludeDirectory.setAppend(True, ";")
    
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Voltage_Calculation/src")
                mcPmsmFocSourceFile.setProjectPath(projectPath + "src")
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)
                
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename and filename.startswith("mc_")):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("QSpin/Voltage_Calculation/inc")
                mcPmsmFocHeaderFile.setProjectPath(projectPath + "inc")
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)
                
    #-----------------------------------------------------------------------------------------------------------------------
    #     Utilities module code generation
    #-----------------------------------------------------------------------------------------------------------------------\    
    # Include directory    
    modulePath = templatePath + "Utilities/"
    projectPath = "config/" + configName + "/QSpin/Utilities/"
    
    utilIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    utilIncludeDirectory.setCategory("C32")
    utilIncludeDirectory.setKey("extra-include-directories")
    utilIncludeDirectory.setValue("../src/" + projectPath + "inc")
    utilIncludeDirectory.setAppend(True, ";")
    
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Utilities/src")
                mcPmsmFocSourceFile.setProjectPath(projectPath + "src")
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)
                
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename and filename.startswith("mc_")):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("QSpin/Utilities/inc")
                mcPmsmFocHeaderFile.setProjectPath(projectPath + "inc")
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)
                
    #-----------------------------------------------------------------------------------------------------------------------
    #     Hardware abstraction code generation
    #-----------------------------------------------------------------------------------------------------------------------
    modulePath = templatePath + "Hardware_Abstraction/"
    projectPath = "config/" + configName + "/QSpin/Hardware_Abstraction/"
    
    # Include directory 
    halIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    halIncludeDirectory.setCategory("C32")
    halIncludeDirectory.setKey("extra-include-directories")
    halIncludeDirectory.setValue("../src/" + projectPath + "inc")
    halIncludeDirectory.setAppend(True, ";")
    
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Hardware_Abstraction/src")
                mcPmsmFocSourceFile.setProjectPath(projectPath + "src")
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)
                
    for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename and filename.startswith("mc_")):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("QSpin/Hardware_Abstraction/inc")
                mcPmsmFocHeaderFile.setProjectPath(projectPath + "inc")
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)
                
    # Included in the if condition to avoid interference
    mcPmsmFocCodeGen = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_CODE_GEN", None)
    mcPmsmFocCodeGen.setVisible(False)
    mcPmsmFocCodeGen.setDependencies(mcGen_GenerateCodeUpdate,
                                                             ["MCPMSMFOC_POSITION_CALC_ALGORITHM",
                                                              "MCPMSMFOC_FLYING_START",
                                                              "MCPMSMFOC_FLYING_START_CODE_TYPE",
                                                              "MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM",
                                                              "MCPMSMFOC_FOC_X2C_ENABLE",
    ])
    
