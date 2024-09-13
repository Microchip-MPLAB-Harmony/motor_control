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
templatePath = "/algorithms/pmsm_foc/templates/floating/"

processor = Variables.get("__PROCESSOR")
if (("SAMC2" in processor) or all(x in processor for x in ["PIC32CM", "MC"])):
    templatePath = "/config/templates/fixed/"
else:
    templatePath = "/config/templates/floating/"

def mcGen_GenerateCodeUpdate(symbol, event):
    component = symbol.getComponent()
    if ( str( event["id"] ) == "MCPMSMFOC_ENABLE_FLYING_START"):
        if event["value"] == True: # Flying start
            component.getSymbolByID("opt_flying_start.h.ftl").setEnabled(True)
            component.getSymbolByID("opt_flying_start.c.ftl").setEnabled(True)
        else:
            component.getSymbolByID("opt_flying_start.h.ftl").setEnabled(False)
            component.getSymbolByID("opt_flying_start.c.ftl").setEnabled(False)

    elif ( str( event["id"] ) == "MCPMSMFOC_ALIGN_OR_DETECT_AXIS"):
        if event["value"] == 2 or event['value'] != 'IPD': # Initial position detection
            component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_IPD_LIB").setEnabled(True)
        else:
            component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_IPD_LIB").setEnabled(False)

    elif ( str( event["id"] ) == "MCPMSMFOC_CONTROL_TYPE"):
        if event["value"] in [3, 'POSITION_LOOP']:
            component.getSymbolByID(str("opt_position_control.c.ftl")).setEnabled(True)
            component.getSymbolByID(str("opt_position_control.h.ftl")).setEnabled(True)
        else:
            component.getSymbolByID(str("opt_position_control.c.ftl")).setEnabled(False)
            component.getSymbolByID(str("opt_position_control.h.ftl")).setEnabled(False)

    elif ( str( event["id"]) == "MCPMSMFOC_POSITION_CALC_ALGORITHM"):
        symObj = event["symbol"]
        key = (symObj.getSelectedKey()).lower()
        modulePath = templatePath + "Field_Oriented_Control/"

        for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
            for filename in files:
                if (filename.startswith("opt_rpo")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False)

        for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
            for filename in files:
                if (filename.startswith("opt_rpo")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False)

        modulePath = templatePath + "Parameters/"

        for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
            for filename in files:
                if (filename.startswith("opt_rpo")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False)

        for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
            for filename in files:
                if (filename.startswith("opt_rpo")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False)


        modulePath = templatePath + "Rotor_Position_Calculation/"

        for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
            for filename in files:
                if (filename.startswith("opt_rpo_sensored")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False)

        for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
            for filename in files:
                if (filename.startswith("opt_rpo_sensored")):
                    if key in filename:
                        component.getSymbolByID(filename).setEnabled(True)
                    else:
                        component.getSymbolByID(filename).setEnabled(False)


        if "sensorless_smo" in key:
            component.getSymbolByID("MCPMSMFOC_SMO_LIB_A").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_ZSMT_LIB").setEnabled(False)

        elif "sensorless_zsmt" in key:
            # component.getSymbolByID("MCPMSMFOC_ENABLE_ALIGN_OR_DETECT").setValue(False)
            # component.getSymbolByID("MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP").setValue(False)
            # component.getSymbolByID("mc_open_loop_startup.h.ftl").setEnabled(False)
            # component.getSymbolByID("mc_open_loop_startup.c.ftl").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_ZSMT_LIB").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_SMO_LIB_A").setEnabled(False)
        else:
            # component.getSymbolByID("MCPMSMFOC_ENABLE_ALIGN_OR_DETECT").setValue(True)
            # component.getSymbolByID("MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP").setValue(True)
            # component.getSymbolByID("mc_open_loop_startup.c.ftl").setEnabled(True)
            # component.getSymbolByID("mc_open_loop_startup.h.ftl").setEnabled(True)
            component.getSymbolByID("MCPMSMFOC_ZSMT_LIB").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_SMO_LIB_A").setEnabled(False)

    elif  ( str( event["id"] ) == "MCPMSMFOC_FOC_X2C_ENABLE"):
        if (True == event["value"]):
            # Delete all the QSpin generated files for field oriented control module
            # Disable all QSpin files for field oriented control module
            modulePath = templatePath + "Field_Oriented_Control/"

            for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
                for filename in files:
                    if (".h" in filename and (filename.startswith("mc_") or filename.startswith("opt_rpo"))):
                        component.getSymbolByID(str(filename)).setEnabled(False)

            for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
                for filename in files:
                    if (".c" in filename and (filename.startswith("mc_") or filename.startswith("opt_rpo"))):
                        component.getSymbolByID(str(filename)).setEnabled(False)

            # Enable all X2C files for field oriented control module
            for _, _, files in os.walk(Module.getPath() + modulePath + "X2Cmodel"):
                for filename in files:
                    component.getSymbolByID(str(filename)).setEnabled(True)

            # component.getSymbolByID("MCPMSMFOC_IPD_SOURCE").setEnabled(False)
            component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(False)

            # Enable
            component.getSymbolByID(str("opt_foc.h.ftl")).setEnabled(False)
            component.getSymbolByID(str("opt_foc.c.ftl")).setEnabled(False)
            component.getSymbolByID(str("opt_foc_x2cmodel.h.ftl")).setEnabled(True)
            component.getSymbolByID(str("opt_foc_x2cmodel.c.ftl")).setEnabled(True)

            # Enable mc_motor.c and mc_motor.h files
            component.getSymbolByID(str("mc_motor.h.ftl")).setEnabled(True)
            component.getSymbolByID(str("mc_motor.c.ftl")).setEnabled(True)

        else:
            symObj = component.getSymbolByID("MCPMSMFOC_POSITION_CALC_ALGORITHM")
            key = (symObj.getSelectedKey()).lower()

            modulePath = templatePath + "Field_Oriented_Control/"

            for _, _, files in os.walk(Module.getPath() + modulePath + "inc" ):
                for filename in files:
                    if (".h" in filename ):
                        if filename.startswith("mc_"):
                            component.getSymbolByID(str(filename)).setEnabled(True)
                        elif filename.startswith("opt_rpo"):
                            if key in filename:
                                component.getSymbolByID(filename).setEnabled(True)
                            else:
                                component.getSymbolByID(filename).setEnabled(False)

            for _, _, files in os.walk(Module.getPath() + modulePath + "src" ):
                for filename in files:
                    if (".c" in filename ):
                        if filename.startswith("mc_"):
                            component.getSymbolByID(str(filename)).setEnabled(True)
                        elif filename.startswith("opt_rpo"):
                            if key in filename:
                                component.getSymbolByID(filename).setEnabled(True)
                            else:
                                component.getSymbolByID(filename).setEnabled(False)

            for _, _, files in os.walk(Module.getPath() + modulePath + "X2Cmodel"):
                for filename in files:
                    component.getSymbolByID(str(filename)).setEnabled(False)

            # component.getSymbolByID("MCPMSMFOC_IPD_SOURCE").setEnabled(True)
            # component.getSymbolByID("MCPMSMFOC_IPD_HEADER").setEnabled(True)

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

    filename = "mc_userparams.h.ftl"
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
    #     Application source and header file
    #-----------------------------------------------------------------------------------------------------------------------
    filename = "mc_key_manager.c.ftl"
    projectPath = "config/" + configName + "/QSpin"

    keySourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
    keySourceFile.setSourcePath(templatePath + filename)
    if (filename.endswith(".ftl")):
        filename = filename[:-4]
    keySourceFile.setOutputName(filename)
    keySourceFile.setDestPath("QSpin")
    keySourceFile.setProjectPath(projectPath)
    keySourceFile.setType("SOURCE")
    keySourceFile.setMarkup(True)

    filename = "mc_key_manager.h.ftl"
    projectPath = "config/" + configName + "/QSpin"
    keyHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
    keyHeaderFile.setSourcePath(templatePath + filename)
    if (filename.endswith(".ftl")):
        filename = filename[:-4]
    keyHeaderFile.setOutputName(filename)
    keyHeaderFile.setDestPath("QSpin")
    keyHeaderFile.setProjectPath(projectPath)
    keyHeaderFile.setType("HEADER")
    keyHeaderFile.setMarkup(True)

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
    focIncludeDirectory.setValue("../src/" + projectPath)
    focIncludeDirectory.setAppend(True, ";")

    for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename):
                if filename.startswith("mc_"):
                    mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                    if (filename.endswith(".ftl")):
                        filename = filename[:-4]
                    mcPmsmFocSourceFile.setOutputName(filename)
                    mcPmsmFocSourceFile.setDestPath("QSpin/Field_Oriented_Control")
                    mcPmsmFocSourceFile.setProjectPath(projectPath)
                    mcPmsmFocSourceFile.setType("SOURCE")
                    mcPmsmFocSourceFile.setMarkup(True)

                elif filename.startswith("opt_rpo"):
                    mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                    mcPmsmFocSourceFile.setOutputName("mc_rotor_position_calculation.c")
                    mcPmsmFocSourceFile.setDestPath("QSpin/Field_Oriented_Control")
                    mcPmsmFocSourceFile.setProjectPath(projectPath)
                    mcPmsmFocSourceFile.setType("SOURCE")
                    mcPmsmFocSourceFile.setMarkup(True)
                    mcPmsmFocSourceFile.setEnabled(False)

                elif filename.startswith("opt_foc"):
                    mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                    mcPmsmFocSourceFile.setOutputName("mc_field_oriented_control.c")
                    mcPmsmFocSourceFile.setDestPath("QSpin/Field_Oriented_Control")
                    mcPmsmFocSourceFile.setProjectPath(projectPath)
                    mcPmsmFocSourceFile.setType("SOURCE")
                    mcPmsmFocSourceFile.setMarkup(True)
                    mcPmsmFocSourceFile.setEnabled(False)

        mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str('opt_flying_start.c.ftl'), None)
        mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + str('opt_flying_start.c.ftl'))
        mcPmsmFocSourceFile.setOutputName("mc_flying_start.c")
        mcPmsmFocSourceFile.setDestPath("QSpin/Field_Oriented_Control")
        mcPmsmFocSourceFile.setProjectPath(projectPath)
        mcPmsmFocSourceFile.setType("SOURCE")
        mcPmsmFocSourceFile.setMarkup(True)
        mcPmsmFocSourceFile.setEnabled(False)

    for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename):
                if filename.startswith("mc_"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    if (filename.endswith(".ftl")):
                        filename = filename[:-4]
                    mcPmsmFocHeaderFile.setOutputName(filename)
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath)
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)

                elif filename.startswith("opt_rpo"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    mcPmsmFocHeaderFile.setOutputName("mc_rotor_position_calculation.h")
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath)
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)
                    mcPmsmFocHeaderFile.setEnabled(False)

                elif filename.startswith("opt_foc"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    mcPmsmFocHeaderFile.setOutputName("mc_field_oriented_control.h")
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control/")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath)
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)
                    mcPmsmFocHeaderFile.setEnabled(False)

        mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str('opt_flying_start.h.ftl'), None)
        mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + str('opt_flying_start.h.ftl'))
        mcPmsmFocHeaderFile.setOutputName("mc_flying_start.h")
        mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control")
        mcPmsmFocHeaderFile.setProjectPath(projectPath)
        mcPmsmFocHeaderFile.setType("HEADER")
        mcPmsmFocHeaderFile.setMarkup(True)
        mcPmsmFocHeaderFile.setEnabled(False)

    # Position control files
    filename = "opt_position_control.h.ftl"
    modulePath = templatePath + "Field_Oriented_Control/"
    projectPath = "config/" + configName + "/QSpin/Field_Oriented_Control/"

    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol( filename, None)
    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
    mcPmsmFocHeaderFile.setOutputName("mc_position_control.h")
    mcPmsmFocHeaderFile.setDestPath("QSpin/Field_Oriented_Control")
    mcPmsmFocHeaderFile.setProjectPath(projectPath)
    mcPmsmFocHeaderFile.setType("HEADER")
    mcPmsmFocHeaderFile.setMarkup(True)
    mcPmsmFocHeaderFile.setEnabled(False)

    filename = "opt_position_control.c.ftl"
    mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol( filename, None)
    mcPmsmFocSourceFile.setSourcePath( modulePath + "src/" + filename)
    mcPmsmFocSourceFile.setOutputName("mc_position_control.c")
    mcPmsmFocSourceFile.setDestPath("QSpin/Field_Oriented_Control/")
    mcPmsmFocSourceFile.setProjectPath(projectPath)
    mcPmsmFocSourceFile.setType("SOURCE")
    mcPmsmFocSourceFile.setMarkup(True)
    mcPmsmFocSourceFile.setEnabled(False)

    if( ("SAME7" in Variables.get("__PROCESSOR")) or ("SAMS7" in Variables.get("__PROCESSOR")) or ("SAMV7" in Variables.get("__PROCESSOR"))):
        smoLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_SMO_LIB_A", None)
        smoLibraryFile.setSourcePath( modulePath + "lib/CortexM7-ATSAM_MCHP_ZSMT.a")
        smoLibraryFile.setOutputName("libCortexM7-ATSAM_SMO_ZSMT.a")
        smoLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        smoLibraryFile.setEnabled(False)

    elif( ("SAMD5" in Variables.get("__PROCESSOR")) or ("SAME5" in Variables.get("__PROCESSOR"))):
        smoLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_SMO_LIB_A", None)
        smoLibraryFile.setSourcePath( modulePath + "lib/libCortexM4-ATSAM_MCHP_SMO.a")
        smoLibraryFile.setOutputName("libCortexM4-ATSAM_MCHP_SMO.a")
        smoLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        smoLibraryFile.setEnabled(False)

    elif("PIC32MK" in Variables.get("__PROCESSOR")):
        smoLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_SMO_LIB_A", None)
        smoLibraryFile.setSourcePath( modulePath + "lib/libPIC32MK_MCHP_SMO.a")
        smoLibraryFile.setOutputName("libPIC32MK_MCHP_SMO.a")
        smoLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        smoLibraryFile.setEnabled(False)

    # ipdSourceFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_IPD_SOURCE", None)
    # ipdSourceFile.setSourcePath(modulePath + "src/" + "opt_ipd.c.ftl")
    # ipdSourceFile.setOutputName("mc_initial_position_detection.c")
    # ipdSourceFile.setDestPath("QSpin/Field_Oriented_Control")
    # ipdSourceFile.setProjectPath(projectPath)
    # ipdSourceFile.setType("SOURCE")
    # ipdSourceFile.setMarkup(True)

    ipdHeaderFile = mcPmsmFocComponent.createFileSymbol("MCPMSMFOC_IPD_HEADER", None)
    ipdHeaderFile.setSourcePath(modulePath + "inc/" + "opt_ipd.h.ftl")
    ipdHeaderFile.setOutputName("mc_initial_position_detection.h")
    ipdHeaderFile.setDestPath("QSpin/Field_Oriented_Control")
    ipdHeaderFile.setProjectPath(projectPath)
    ipdHeaderFile.setType("HEADER")
    ipdHeaderFile.setMarkup(True)
    ipdHeaderFile.setEnabled(False)

    if( ("SAME7" in Variables.get("__PROCESSOR")) or ("SAMS7" in Variables.get("__PROCESSOR")) or ("SAMV7" in Variables.get("__PROCESSOR"))):
        zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_LIB", None)
        zsmtLibraryFile.setSourcePath(modulePath + "lib/libCortexM7-ATSAM_MCHP_ZSMT.a")
        zsmtLibraryFile.setOutputName("libCortexM7-ATSAM_MCHP_ZSMT.a")
        zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        zsmtLibraryFile.setEnabled(False)

        ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_LIB", None)
        ipdLibraryFile.setSourcePath(modulePath + "lib/libCortexM7-ATSAM_MCHP_IPD.a")
        ipdLibraryFile.setOutputName("libCortexM7-ATSAM_MCHP_IPD.a")
        ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        ipdLibraryFile.setEnabled(False)


    elif("SAME5" in Variables.get("__PROCESSOR")):
        zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_LIB", None)
        zsmtLibraryFile.setSourcePath(modulePath + "lib/libCortexM4-ATSAM_MCHP_ZSMT.a")
        zsmtLibraryFile.setOutputName("libCortexM4-ATSAM_MCHP_ZSMT.a")
        zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        zsmtLibraryFile.setEnabled(False)

        ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_LIB", None)
        ipdLibraryFile.setSourcePath(modulePath + "lib/libCortexM4-ATSAM_MCHP_IPD.a")
        ipdLibraryFile.setOutputName("libCortexM4-ATSAM_MCHP_IPD.a")
        ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        ipdLibraryFile.setEnabled(False)

    elif( "PIC32MK" in Variables.get("__PROCESSOR")):
        zsmtLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_ZSMT_LIB", None)
        zsmtLibraryFile.setSourcePath(modulePath + "lib/libPIC32MK_MCHP_ZSMT.a")
        zsmtLibraryFile.setOutputName("libPIC32MK_MCHP_ZSMT.a")
        zsmtLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        zsmtLibraryFile.setEnabled(False)

        ipdLibraryFile = mcPmsmFocComponent.createLibrarySymbol("MCPMSMFOC_IPD_LIB", None)
        ipdLibraryFile.setSourcePath(modulePath + "lib/libPIC32MK_MCHP_IPD.a")
        ipdLibraryFile.setOutputName("libPIC32MK_MCHP_IPD.a")
        ipdLibraryFile.setDestPath("/QSpin/Field_Oriented_Control/")
        ipdLibraryFile.setEnabled(False)

    for _, _, files in os.walk(Module.getPath() + modulePath + "X2Cmodel"):
        for filename in files:
            x2cModelFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
            x2cModelFile.setSourcePath(modulePath + "X2Cmodel/" + filename)
            if (filename.endswith(".ftl")):
                filename = filename[:-4]
            x2cModelFile.setOutputName(filename)
            x2cModelFile.setDestPath("/X2Cmodel/")
            x2cModelFile.setProjectPath("config/" + configName + "/X2Cmodel/")
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
    curIncludeDirectory.setValue("../src/" + projectPath)
    curIncludeDirectory.setAppend(True, ";")

    for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Current_Calculation/")
                mcPmsmFocSourceFile.setProjectPath(projectPath )
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)

    for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename and filename.startswith("mc_")):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("QSpin/Current_Calculation")
                mcPmsmFocHeaderFile.setProjectPath(projectPath)
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
    volIncludeDirectory.setValue("../src/" + projectPath )
    volIncludeDirectory.setAppend(True, ";")

    for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Voltage_Calculation")
                mcPmsmFocSourceFile.setProjectPath(projectPath )
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)

    for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename and filename.startswith("mc_")):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("QSpin/Voltage_Calculation/")
                mcPmsmFocHeaderFile.setProjectPath(projectPath)
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)

    #-----------------------------------------------------------------------------------------------------------------------
    #     Rotor Position Calculation module code generation
    #-----------------------------------------------------------------------------------------------------------------------
    modulePath = templatePath + "Rotor_Position_Calculation/"
    projectPath = "config/" + configName + "/QSpin/Rotor_Position_Calculation/"

    rpcIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    rpcIncludeDirectory.setCategory("C32")
    rpcIncludeDirectory.setKey("extra-include-directories")
    rpcIncludeDirectory.setValue("../src/" + projectPath )
    rpcIncludeDirectory.setAppend(True, ";")


    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Rotor_Position_Calculation")
                mcPmsmFocSourceFile.setProjectPath(projectPath )
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)

            if (".c" in filename and filename.startswith("opt_rpo_sensored")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                mcPmsmFocSourceFile.setOutputName("mc_rotor_position_calculation.c")
                mcPmsmFocSourceFile.setDestPath("QSpin/Rotor_Position_Calculation")
                mcPmsmFocSourceFile.setProjectPath(projectPath)
                mcPmsmFocSourceFile.setType("SOURCE")
                mcPmsmFocSourceFile.setMarkup(True)
                mcPmsmFocSourceFile.setEnabled(False)

    for root, dirs, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:

            if (".h" in filename and filename.startswith("mc_")):
                mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocHeaderFile.setOutputName(filename)
                mcPmsmFocHeaderFile.setDestPath("QSpin/Rotor_Position_Calculation/")
                mcPmsmFocHeaderFile.setProjectPath(projectPath)
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)

            if (".h" in filename and filename.startswith("opt_rpo_sensored")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "inc/" + filename)
                mcPmsmFocSourceFile.setOutputName("mc_rotor_position_calculation.h")
                mcPmsmFocSourceFile.setDestPath("QSpin/Rotor_Position_Calculation")
                mcPmsmFocSourceFile.setProjectPath(projectPath)
                mcPmsmFocSourceFile.setType("HEADER")
                mcPmsmFocSourceFile.setMarkup(True)
                mcPmsmFocSourceFile.setEnabled(False)

    #-----------------------------------------------------------------------------------------------------------------------
    #     Utilities module code generation
    #-----------------------------------------------------------------------------------------------------------------------\
    # Include directory
    modulePath = templatePath + "Utilities/"
    projectPath = "config/" + configName + "/QSpin/Utilities/"

    utilIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    utilIncludeDirectory.setCategory("C32")
    utilIncludeDirectory.setKey("extra-include-directories")
    utilIncludeDirectory.setValue("../src/" + projectPath )
    utilIncludeDirectory.setAppend(True, ";")

    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Utilities/")
                mcPmsmFocSourceFile.setProjectPath(projectPath )
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
                mcPmsmFocHeaderFile.setDestPath("QSpin/Utilities/")
                mcPmsmFocHeaderFile.setProjectPath(projectPath )
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
    halIncludeDirectory.setValue("../src/" + projectPath)
    halIncludeDirectory.setAppend(True, ";")

    for root, dirs, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename and filename.startswith("mc_")):
                mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                if (filename.endswith(".ftl")):
                    filename = filename[:-4]
                mcPmsmFocSourceFile.setOutputName(filename)
                mcPmsmFocSourceFile.setDestPath("QSpin/Hardware_Abstraction")
                mcPmsmFocSourceFile.setProjectPath(projectPath)
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
                mcPmsmFocHeaderFile.setDestPath("QSpin/Hardware_Abstraction")
                mcPmsmFocHeaderFile.setProjectPath(projectPath)
                mcPmsmFocHeaderFile.setType("HEADER")
                mcPmsmFocHeaderFile.setMarkup(True)

    #-----------------------------------------------------------------------------------------------------------------------
    #     Module Parameters
    #-----------------------------------------------------------------------------------------------------------------------
    modulePath = templatePath + "Parameters/"
    projectPath = "config/" + configName + "/QSpin/Parameters/"

    # Include directory
    paramIncludeDirectory = mcPmsmFocComponent.createSettingSymbol(None, None)
    paramIncludeDirectory.setCategory("C32")
    paramIncludeDirectory.setKey("extra-include-directories")
    paramIncludeDirectory.setValue("../src/" + projectPath)
    paramIncludeDirectory.setAppend(True, ";")

    for _, _, files in os.walk(Module.getPath() + modulePath + "src"):
        for filename in files:
            if (".c" in filename):
                if filename.startswith("mc_"):
                    mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                    if (filename.endswith(".ftl")):
                        filename = filename[:-4]
                    mcPmsmFocSourceFile.setOutputName(filename)
                    mcPmsmFocSourceFile.setDestPath("QSpin/Parameters")
                    mcPmsmFocSourceFile.setProjectPath(projectPath)
                    mcPmsmFocSourceFile.setType("SOURCE")
                    mcPmsmFocSourceFile.setMarkup(True)

                elif filename.startswith("opt_rpo"):
                    mcPmsmFocSourceFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocSourceFile.setSourcePath(modulePath + "src/" + filename)
                    mcPmsmFocSourceFile.setOutputName("mc_rotor_position_parameters.c")
                    mcPmsmFocSourceFile.setDestPath("QSpin/Parameters")
                    mcPmsmFocSourceFile.setProjectPath(projectPath)
                    mcPmsmFocSourceFile.setType("SOURCE")
                    mcPmsmFocSourceFile.setMarkup(True)
                    mcPmsmFocSourceFile.setEnabled(False)

    for _, _, files in os.walk(Module.getPath() + modulePath + "inc"):
        for filename in files:
            if (".h" in filename):
                if filename.startswith("mc_"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    if (filename.endswith(".ftl")):
                        filename = filename[:-4]
                    mcPmsmFocHeaderFile.setOutputName(filename)
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Parameters")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath)
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)

                elif filename.startswith("opt_rpo"):
                    mcPmsmFocHeaderFile = mcPmsmFocComponent.createFileSymbol(str(filename), None)
                    mcPmsmFocHeaderFile.setSourcePath(modulePath + "inc/" + filename)
                    mcPmsmFocHeaderFile.setOutputName("mc_rotor_position_parameters.h")
                    mcPmsmFocHeaderFile.setDestPath("QSpin/Parameters")
                    mcPmsmFocHeaderFile.setProjectPath(projectPath)
                    mcPmsmFocHeaderFile.setType("HEADER")
                    mcPmsmFocHeaderFile.setMarkup(True)
                    mcPmsmFocHeaderFile.setEnabled(False)


    processor = Variables.get("__PROCESSOR")
    if (("SAMC2" in processor) or all(x in processor for x in ["PIC32CM", "MC"])):
        # Symbol to enable "use indirect calls" option from xc32-gcc settings
        xc32_use_indirect_calls = mcPmsmFocComponent.createSettingSymbol("XC32_USE_INDIRECT_CALLS", None)
        xc32_use_indirect_calls.setCategory("C32")
        xc32_use_indirect_calls.setKey("use-indirect-calls")
        xc32_use_indirect_calls.setValue("true")

    # Included in the if condition to avoid interference
    mcPmsmFocCodeGen = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_CODE_GEN", None)
    mcPmsmFocCodeGen.setVisible(False)
    mcPmsmFocCodeGen.setDependencies(mcGen_GenerateCodeUpdate,
                                                             ["MCPMSMFOC_POSITION_CALC_ALGORITHM",
                                                              "MCPMSMFOC_ENABLE_FLYING_START",
                                                              "MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM",
                                                              "MCPMSMFOC_ALIGN_OR_DETECT_AXIS",
                                                              "MCPMSMFOC_FOC_X2C_ENABLE",
                                                              "MCPMSMFOC_CONTROL_TYPE",
    ])

