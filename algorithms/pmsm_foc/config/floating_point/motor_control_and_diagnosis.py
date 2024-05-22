# coding: utf-8
"""*****************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

#---------------------------------------------------------------------------------------#
#                                     IMPORT                                            #
#---------------------------------------------------------------------------------------#

# PI controller Parameters
mcMotC_SpeedPiPararameterDictFloating =  {    'dsPICDEM MCLV-2' :   { 'KP' : 0.005,
                                                    'KI' : 0.002,
                                                    'KC' : 0.5
                                                   },
                                      'Custom' :   { 'KP' : 0.005,
                                                     'KI' : 0.00002,
                                                     'KC' : 0.5
                                                   },
                                      'dsPICDEM MCHV-3' :   { 'KP' : 0.0006,
                                                    'KI' : 0.015,
                                                    'KC' : 0.5
                                                  },
                                 }


#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcMocI_MotorControlAndDiagnosis:
    def __init__(self, component):
        self.component = component

        self.architecture = ATDF.getNode("/avr-tools-device-file/devices/device").getAttribute("architecture")


    def createSymbols(self):

        # Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Motor Control and Diagnosis")

        # Model based code enable switch
        self.sym_X2C_ENABLE = self.component.createBooleanSymbol("MCPMSMFOC_FOC_X2C_ENABLE", self.sym_NODE )
        self.sym_X2C_ENABLE.setLabel("Enable X2C model based generation ")
        self.sym_X2C_ENABLE.setDefaultValue(False)
        self.sym_X2C_ENABLE.setDependencies(self.updateProjectGraph, ["MCPMSMFOC_FOC_X2C_ENABLE"])

        self.sym_X2C_ID = self.component.createStringSymbol("MCPMSMFOC_FOC_X2C_ID", None)
        self.sym_X2C_ID.setLabel("Peripheral ID")
        self.sym_X2C_ID.setVisible(False)
        self.sym_X2C_ID.setDefaultValue("X2CScope")
        self.sym_X2C_ID.setDependencies(self.updatePeripheralInstance, ["MCPMSMFOC_FOC_X2C_ENABLE"] )

        # Control strategy
        self.sym_CONTROL_TYPE = self.component.createKeyValueSetSymbol("MCPMSMFOC_CONTROL_TYPE", self.sym_NODE )
        self.sym_CONTROL_TYPE.setLabel("Control type")
        self.sym_CONTROL_TYPE.addKey("SPEED_LOOP", "0", "Speed control")
        self.sym_CONTROL_TYPE.addKey("TORQUE_LOOP", "1", "Torque control")
        self.sym_CONTROL_TYPE.addKey("OPEN_LOOP", "2", "Open loop control")
        self.sym_CONTROL_TYPE.addKey("POSITION_LOOP", "3", "Position control")
        self.sym_CONTROL_TYPE.setOutputMode("Key")
        self.sym_CONTROL_TYPE.setDisplayMode("Description")


        # --------------------- Reference source -----------------------------------------#
        self.sym_INPUT_SOURCE = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_INPUT_SOURCE.setLabel("Reference source")

        input_Mode = ["From potentiometer", "From API"]
        self.sym_INPUT = self.component.createComboSymbol("MCPMSMFOC_REF_INPUT", self.sym_INPUT_SOURCE, input_Mode)
        self.sym_INPUT.setLabel("Select reference input")

        self.sym_MIN_INPUT = self.component.createFloatSymbol("MCPMSMFOC_MIN_REF_INPUT", self.sym_INPUT_SOURCE)
        self.sym_MIN_INPUT.setLabel("Minimum reference value")
        self.sym_MIN_INPUT.setDefaultValue(500)
        self.sym_MIN_INPUT.setDependencies(self.setMinimum, ["MCPMSMFOC_CONTROL_TYPE"])

        self.sym_MAX_INPUT = self.component.createFloatSymbol("MCPMSMFOC_MAX_REF_INPUT", self.sym_INPUT_SOURCE)
        self.sym_MAX_INPUT.setLabel("Maximum reference value")
        self.sym_MAX_INPUT.setDefaultValue(3000)
        self.sym_MAX_INPUT.setDependencies(self.setMaximum, ["MCPMSMFOC_CONTROL_TYPE"])

        # --------------------- Ramp Profiler -----------------------------------------#
        self.sym_RAMP_PROFILER = self.component.createMenuSymbol(None, self.sym_NODE)
        self.sym_RAMP_PROFILER.setLabel("Ramp Profiler")

        # supported_Profiles = ["Step", "Linear", "Pulse", "S-Curve", "Sine Sweep"]
        supported_Profiles = ["Linear", "Step"]
        self.sym_RAMP_PROFILES = self.component.createComboSymbol( "MCPMSMFOC_RAMP_PROFILES", self.sym_RAMP_PROFILER, supported_Profiles)
        self.sym_RAMP_PROFILES.setLabel("Profile")

        self.sym_RAMP_PROILE_MAX_SPEED = self.component.createFloatSymbol("MCPMSMFOC_RAMP_PROFILER_MAX_SPEED", self.sym_RAMP_PROFILER)
        self.sym_RAMP_PROILE_MAX_SPEED.setLabel("Ramp rate ( RPM/ s) ")
        self.sym_RAMP_PROILE_MAX_SPEED.setDefaultValue(300)
        self.sym_RAMP_PROILE_MAX_SPEED.setVisible(True)
        self.sym_RAMP_PROILE_MAX_SPEED.setDependencies( self.showRampProfilerSymbol, ["MCPMSMFOC_RAMP_PROFILES"])

        self.sym_RAMP_PROILE_MAX_ACCEL = self.component.createFloatSymbol("MCPMSMFOC_RAMP_PROFILER_MAX_ACCEL", self.sym_RAMP_PROFILER)
        self.sym_RAMP_PROILE_MAX_ACCEL.setLabel("Maximum acceleration (RPM/s)")
        self.sym_RAMP_PROILE_MAX_ACCEL.setDefaultValue(100)
        self.sym_RAMP_PROILE_MAX_ACCEL.setVisible(False)
        self.sym_RAMP_PROILE_MAX_ACCEL.setDependencies( self.showRampProfilerSymbol, ["MCPMSMFOC_RAMP_PROFILES"])


        # -------------------------------- Position PID Controller ---------------------#
        self.sym_POSITION_PID = self.component.createMenuSymbol("MCPMSMFOC_POSITION_PID", self.sym_NODE)
        self.sym_POSITION_PID.setLabel("Position controller")
        self.sym_POSITION_PID.setVisible(True)
        self.sym_POSITION_PID.setDependencies( self.showControllers, ["MCPMSMFOC_CONTROL_TYPE"])

        anti_windup_Techniques = ["Back Calculation", "Integral Clamp"]
        self.sym_POSITION_PID_AW = self.component.createComboSymbol("MCPMSMFOC_POSITION_PID_AW", self.sym_POSITION_PID, anti_windup_Techniques)
        self.sym_POSITION_PID_AW.setLabel("Anti-windup")

        self.sym_POSITION_PID_KP = self.component.createFloatSymbol("MCPMSMFOC_POSITION_PID_KP", self.sym_POSITION_PID)
        self.sym_POSITION_PID_KP.setLabel("Kp")

        self.sym_POSITION_PID_KI = self.component.createFloatSymbol("MCPMSMFOC_POSITION_PID_KI", self.sym_POSITION_PID)
        self.sym_POSITION_PID_KI.setLabel("Ki")

        # self.sym_POSITION_PID_KV = self.component.createFloatSymbol("MCPMSMFOC_POSITION_PID_KV", self.sym_POSITION_PID)
        # self.sym_POSITION_PID_KV.setLabel("Kv")

        self.sym_POSITION_PID_KC = self.component.createFloatSymbol("MCPMSMFOC_POSITION_PID_KC", self.sym_POSITION_PID)
        self.sym_POSITION_PID_KC.setLabel("Kc")
        self.sym_POSITION_PID_KC.setVisible(True)
        self.sym_POSITION_PID_KC.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_POSITION_PID_AW"])

        self.sym_POSITION_PID_YIMAX = self.component.createFloatSymbol("MCPMSMFOC_POSITION_PID_YIMAX", self.sym_POSITION_PID)
        self.sym_POSITION_PID_YIMAX.setLabel("Maximum integral")
        self.sym_POSITION_PID_YIMAX.setVisible(False)
        self.sym_POSITION_PID_YIMAX.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_POSITION_PID_AW"])

        self.sym_POSITION_PID_KI = self.component.createFloatSymbol("MCPMSMFOC_POSITION_PID_YMAX", self.sym_POSITION_PID)
        self.sym_POSITION_PID_KI.setLabel("Maximum output")

        # -------------------------------- Speed PID Controller ------------------------#
        self.sym_SPEED_PID = self.component.createMenuSymbol("MCPMSMFOC_SPEED_PID", self.sym_NODE)
        self.sym_SPEED_PID.setLabel("Speed controller")
        self.sym_SPEED_PID.setVisible(True)
        self.sym_SPEED_PID.setDependencies( self.showControllers, ["MCPMSMFOC_CONTROL_TYPE"])

        anti_windup_Techniques = ["Back Calculation", "Integral Clamp"]
        self.sym_SPEED_PID_AW = self.component.createComboSymbol("MCPMSMFOC_SPEED_PID_AW", self.sym_SPEED_PID, anti_windup_Techniques)
        self.sym_SPEED_PID_AW.setLabel("Anti-windup")

        self.sym_SPEED_PID_KP = self.component.createFloatSymbol("MCPMSMFOC_SPEED_PID_KP", self.sym_SPEED_PID)
        self.sym_SPEED_PID_KP.setLabel("Kp")
        self.sym_SPEED_PID_KP.setDefaultValue(mcMotC_SpeedPiPararameterDictFloating["dsPICDEM MCLV-2"]["KP"])


        self.sym_SPEED_PID_KI = self.component.createFloatSymbol("MCPMSMFOC_SPEED_PID_KI", self.sym_SPEED_PID)
        self.sym_SPEED_PID_KI.setLabel("Ki")
        self.sym_SPEED_PID_KI.setDefaultValue(mcMotC_SpeedPiPararameterDictFloating["dsPICDEM MCLV-2"]["KI"])

        # self.sym_SPEED_PID_KV = self.component.createFloatSymbol("MCPMSMFOC_SPEED_PID_KV", self.sym_SPEED_PID)
        # self.sym_SPEED_PID_KV.setLabel("Kv")

        self.sym_SPEED_PID_KC = self.component.createFloatSymbol("MCPMSMFOC_SPEED_PID_KC", self.sym_SPEED_PID)
        self.sym_SPEED_PID_KC.setLabel("Kc")
        self.sym_SPEED_PID_KC.setDefaultValue(mcMotC_SpeedPiPararameterDictFloating["dsPICDEM MCLV-2"]["KC"])
        self.sym_SPEED_PID_KC.setVisible(True)
        self.sym_SPEED_PID_KC.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_SPEED_PID_AW"])

        self.sym_SPEED_PID_YIMAX = self.component.createFloatSymbol("MCPMSMFOC_SPEED_PID_YIMAX", self.sym_SPEED_PID)
        self.sym_SPEED_PID_YIMAX.setLabel("Maximum integral")
        self.sym_SPEED_PID_YIMAX.setVisible(False)
        self.sym_SPEED_PID_YIMAX.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_SPEED_PID_AW"])

        self.sym_SPEED_PID_YMAX = self.component.createFloatSymbol("MCPMSMFOC_SPEED_PID_YMAX", self.sym_SPEED_PID)
        self.sym_SPEED_PID_YMAX.setLabel("Maximum output")
        self.sym_SPEED_PID_YMAX.setDefaultValue(3.0)



        # ------------------------------------ Id PID Controller -----------------------#

        self.sym_ID_PID = self.component.createMenuSymbol("MCPMSMFOC_ID_PID", self.sym_NODE)
        self.sym_ID_PID.setLabel("D-axis current controller")
        self.sym_ID_PID.setVisible(True)
        self.sym_ID_PID.setDependencies( self.showControllers, ["MCPMSMFOC_CONTROL_TYPE"])

        anti_windup_Techniques = ["Back Calculation", "Integral Clamp"]
        self.sym_ID_PID_AW = self.component.createComboSymbol("MCPMSMFOC_ID_PID_AW", self.sym_ID_PID, anti_windup_Techniques)
        self.sym_ID_PID_AW.setLabel("Anti-windup")

        self.sym_ID_PID_KP = self.component.createFloatSymbol("MCPMSMFOC_ID_PID_KP", self.sym_ID_PID)
        self.sym_ID_PID_KP.setLabel("Kp")
        self.sym_ID_PID_KP.setDefaultValue(self.initCurrentLoopKp(self.component))
        self.sym_ID_PID_KP.setDependencies(self.calculateCurrentLoopKp, ["MCPMSMFOC_LD",
                                                                                                               "MCPMSMFOC_LQ",
                                                                                                               "MCPMSMFOC_VOLTAGE_MAGNITUDE",
                                                                                                               "MCPMSMFOC_MOTOR_CONNECTION"])


        self.sym_ID_PID_KI = self.component.createFloatSymbol("MCPMSMFOC_ID_PID_KI", self.sym_ID_PID)
        self.sym_ID_PID_KI.setLabel("Ki")
        self.sym_ID_PID_KI.setDefaultValue(self.initCurrentLoopKi(self.component))
        self.sym_ID_PID_KI.setDependencies(self.calculateCurrentLoopKi, ["MCPMSMFOC_LD",
                                                                                                               "MCPMSMFOC_LQ",
                                                                                                               "MCPMSMFOC_VOLTAGE_MAGNITUDE",
                                                                                                               "MCPMSMFOC_MOTOR_CONNECTION",
                                                                                                               "MCPMSMFOC_PWM_FREQUENCY"])

        # self.sym_ID_PID_KV = self.component.createFloatSymbol("MCPMSMFOC_ID_PID_KV", self.sym_ID_PID)
        # self.sym_ID_PID_KV.setLabel("Kv")

        self.sym_ID_PID_KC = self.component.createFloatSymbol("MCPMSMFOC_ID_PID_KC", self.sym_ID_PID)
        self.sym_ID_PID_KC.setLabel("Kc")
        self.sym_ID_PID_KC.setDefaultValue(0.5)
        self.sym_ID_PID_KC.setVisible(True)
        self.sym_ID_PID_KC.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_ID_PID_AW"])

        self.sym_ID_PID_YIMAX = self.component.createFloatSymbol("MCPMSMFOC_ID_PID_YIMAX", self.sym_ID_PID)
        self.sym_ID_PID_YIMAX.setLabel("Maximum integral")
        self.sym_ID_PID_YIMAX.setVisible(False)
        self.sym_ID_PID_YIMAX.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_ID_PID_AW"])

        self.sym_ID_PID_YMAX = self.component.createFloatSymbol("MCPMSMFOC_ID_PID_YMAX", self.sym_ID_PID)
        self.sym_ID_PID_YMAX.setLabel("Maximum output")
        self.sym_ID_PID_YMAX.setDefaultValue(0.98)


        # ------------------------------------ Iq PID Controller -----------------------#
        self.sym_IQ_PID = self.component.createMenuSymbol("MCPMSMFOC_IQ_PID", self.sym_NODE)
        self.sym_IQ_PID.setLabel("Q-axis current controller")
        self.sym_IQ_PID.setVisible(True)
        self.sym_IQ_PID.setDependencies( self.showControllers, ["MCPMSMFOC_CONTROL_TYPE"])

        anti_windup_Techniques = ["Back Calculation", "Integral Clamp"]
        self.sym_IQ_PID_AW = self.component.createComboSymbol("MCPMSMFOC_IQ_PID_AW", self.sym_IQ_PID, anti_windup_Techniques)
        self.sym_IQ_PID_AW.setLabel("Anti-windup")

        self.sym_IQ_PID_KP = self.component.createFloatSymbol("MCPMSMFOC_IQ_PID_KP", self.sym_IQ_PID)
        self.sym_IQ_PID_KP.setLabel("Kp")
        self.sym_IQ_PID_KP.setDefaultValue(self.initCurrentLoopKp(self.component))
        self.sym_IQ_PID_KP.setDependencies(self.calculateCurrentLoopKp, ["MCPMSMFOC_LD",
                                                                                                               "MCPMSMFOC_LQ",
                                                                                                               "MCPMSMFOC_RATED_SPEED"])

        self.sym_IQ_PID_KI = self.component.createFloatSymbol("MCPMSMFOC_IQ_PID_KI", self.sym_IQ_PID)
        self.sym_IQ_PID_KI.setLabel("Ki")
        self.sym_IQ_PID_KI.setDefaultValue(self.initCurrentLoopKi(self.component))
        self.sym_IQ_PID_KI.setDependencies(self.calculateCurrentLoopKi, ["MCPMSMFOC_R",
                                                                                                               "MCPMSMFOC_RATED_SPEED"])

        # self.sym_IQ_PID_KV = self.component.createFloatSymbol("MCPMSMFOC_IQ_PID_KV", self.sym_IQ_PID)
        # self.sym_IQ_PID_KV.setLabel("Kv")

        self.sym_IQ_PID_KC = self.component.createFloatSymbol("MCPMSMFOC_IQ_PID_KC", self.sym_IQ_PID)
        self.sym_IQ_PID_KC.setLabel("Kc")
        self.sym_IQ_PID_KC.setDefaultValue(0.5)
        self.sym_IQ_PID_KC.setVisible(True)
        self.sym_IQ_PID_KC.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_IQ_PID_AW"])

        self.sym_IQ_PID_YIMAX = self.component.createFloatSymbol("MCPMSMFOC_IQ_PID_YIMAX", self.sym_IQ_PID)
        self.sym_IQ_PID_YIMAX.setLabel("Maximum integral")
        self.sym_IQ_PID_YIMAX.setVisible(False)
        self.sym_IQ_PID_YIMAX.setDependencies(self.showSymbolForAntiWindup, ["MCPMSMFOC_IQ_PID_AW"])

        self.sym_IQ_PID_YMAX = self.component.createFloatSymbol("MCPMSMFOC_IQ_PID_YMAX", self.sym_IQ_PID)
        self.sym_IQ_PID_YMAX.setLabel("Maximum output")
        self.sym_IQ_PID_YMAX.setDefaultValue(0.98)


        # ----------------------------------- Field Weakening and MTPA -----------------#
        self.sym_FW_AND_MTPA = self.component.createMenuSymbol("MCPMSMFOC_FW_AND_MTPA", self.sym_NODE)
        self.sym_FW_AND_MTPA.setLabel("Field Weakening and MTPA")

        self.sym_FW = self.component.createBooleanSymbol("MCPMSMFOC_ENABLE_FW", self.sym_FW_AND_MTPA)
        self.sym_FW.setLabel("Enable field weakening")
        if self.architecture == "CORTEX-M0PLUS":
            self.sym_FW.setReadOnly(True)


        self.sym_FW_IMAX = self.component.createFloatSymbol("MCPMSMFOC_FW_MAX_NEGATIVE_ID", self.sym_FW)
        self.sym_FW_IMAX.setLabel("Max Negative Current")
        self.sym_FW_IMAX.setMax(100)
        self.sym_FW_IMAX.setMin(-100.0)
        self.sym_FW_IMAX.setVisible(False)
        self.sym_FW_IMAX.setDependencies(self.showThisSymbol, ["MCPMSMFOC_ENABLE_FW"])

        # self.sym_FW_TUNING = self.component.createFloatSymbol("MCPMSMFOC_FW_TUNING_PARAMETER", self.sym_FW)
        # self.sym_FW_TUNING.setLabel("Tuning Parameter")
        # self.sym_FW_TUNING.setDefaultValue(1.0)
        # self.sym_FW_TUNING.setMax(1.1)
        # self.sym_FW_TUNING.setMin(0.90)
        # self.sym_FW_TUNING.setVisible(False)
        # self.sym_FW_TUNING.setDependencies(self.showThisSymbol, ["MCPMSMFOC_ENABLE_FW"])

        self.sym_MTPA = self.component.createBooleanSymbol("MCPMSMFOC_ENABLE_MTPA", self.sym_FW_AND_MTPA)
        self.sym_MTPA.setLabel("Enable MTPA")

        #
        # self.sym_MTPA_TUNING = self.component.createFloatSymbol("MCPMSMFOC_MTPA_TUNING_PARAMETER", self.sym_MTPA)
        # self.sym_MTPA_TUNING.setLabel("Tuning Parameter")
        # self.sym_MTPA_TUNING.setDefaultValue(1.0)
        # self.sym_MTPA_TUNING.setMax(1.1)
        # self.sym_MTPA_TUNING.setMin(0.90)
        # self.sym_MTPA_TUNING.setVisible(False)
        # self.sym_MTPA_TUNING.setDependencies(self.showThisSymbol, ["MCPMSMFOC_ENABLE_MTPA"])

        # --------------------------------------- PWM Modulator ------------------------#
        self.sym_PWM_MODULATOR = self.component.createMenuSymbol("MCPMSMFOC_PWM_MODULATOR", self.sym_NODE)
        self.sym_PWM_MODULATOR.setLabel("PWM Modulator")

        # Over-modulation enable
        self.sym_OVER_MODULATION = self.component.createBooleanSymbol("MCPMSMFOC_OVER_MODULATION", self.sym_PWM_MODULATOR)
        self.sym_OVER_MODULATION.setLabel("Enable over modulation")
        if self.architecture == "CORTEX-M0PLUS":
            self.sym_OVER_MODULATION.setReadOnly(True)


        # Modulation technique
        # pwm_Techniques = ["Normal SVPWM", "Bus Clamped SVPWM"]
        pwm_Techniques = ["Normal SVPWM"]
        self.sym_MODULATION_TECHNIQUE = self.component.createComboSymbol("MCPMSMFOC_MODULATION_TECHNIQUE", self.sym_PWM_MODULATOR, pwm_Techniques)
        self.sym_MODULATION_TECHNIQUE.setLabel("Modulation Technique")

        # Modulation technique
        # self.sym_SPACE_VECTOR_LIMIT = self.component.createFloatSymbol("MCPMSMFOC_SPACE_VECTOR_LIMIT", self.sym_PWM_MODULATOR)
        # self.sym_SPACE_VECTOR_LIMIT.setLabel("Space Vector Limit (%)")
        # self.sym_SPACE_VECTOR_LIMIT.setDefaultValue(98)

        # --------------------------------------- Decoupling network  ------------------------#
        self.sym_DECOUPLING_NETWORK = self.component.createMenuSymbol("MCPMSMFOC_DECOUPLING_NETWORK", self.sym_NODE)
        self.sym_DECOUPLING_NETWORK.setLabel("Decoupling Network")

        # Over-modulation enable
        self.sym_DECOUPLING_ENABLE = self.component.createBooleanSymbol("MCPMSMFOC_ENABLE_DECOUPLING", self.sym_DECOUPLING_NETWORK)
        self.sym_DECOUPLING_ENABLE.setLabel("Enable Inductive Decoupling")

    def showRampProfilerSymbol(self, symbol, event):
        if "Step" == event["symbol"].getValue():
            self.sym_RAMP_PROILE_MAX_SPEED.setVisible(False)
            self.sym_RAMP_PROILE_MAX_ACCEL.setVisible(False)

        elif "Linear" == event["symbol"].getValue():
            self.sym_RAMP_PROILE_MAX_SPEED.setVisible(True)
            self.sym_RAMP_PROILE_MAX_ACCEL.setVisible(False)

        elif "S-Curve" == event["symbol"].getValue():
            self.sym_RAMP_PROILE_MAX_SPEED.setVisible(True)
            self.sym_RAMP_PROILE_MAX_ACCEL.setVisible(True)

    def showSymbolForAntiWindup(self, symbol, event):
        if "Back Calculation" == event["symbol"].getValue():
            self.sym_POSITION_PID_KC.setVisible(True)
            self.sym_POSITION_PID_YIMAX.setVisible(False)
            self.sym_SPEED_PID_KC.setVisible(True)
            self.sym_SPEED_PID_YIMAX.setVisible(False)
            self.sym_ID_PID_KC.setVisible(True)
            self.sym_ID_PID_YIMAX.setVisible(False)
            self.sym_IQ_PID_KC.setVisible(True)
            self.sym_IQ_PID_YIMAX.setVisible(False)

        elif "Integral Clamp" == event["symbol"].getValue():
            self.sym_POSITION_PID_KC.setVisible(False)
            self.sym_POSITION_PID_YIMAX.setVisible(True)
            self.sym_SPEED_PID_KC.setVisible(False)
            self.sym_SPEED_PID_YIMAX.setVisible(True)
            self.sym_ID_PID_KC.setVisible(False)
            self.sym_ID_PID_YIMAX.setVisible(True)
            self.sym_IQ_PID_KC.setVisible(False)
            self.sym_IQ_PID_YIMAX.setVisible(True)


    def showControllers(self, symbol, event):
        if "POSITION_LOOP" == event["symbol"].getSelectedKey():
            self.sym_POSITION_PID.setVisible(True)
            self.sym_SPEED_PID.setVisible(True)
            self.sym_ID_PID.setVisible(True)
            self.sym_IQ_PID.setVisible(True)
        elif "SPEED_LOOP" == event["symbol"].getSelectedKey():
            self.sym_POSITION_PID.setVisible(False)
            self.sym_SPEED_PID.setVisible(True)
            self.sym_ID_PID.setVisible(True)
            self.sym_IQ_PID.setVisible(True)
        else:
            self.sym_POSITION_PID.setVisible(False)
            self.sym_SPEED_PID.setVisible(False)
            self.sym_ID_PID.setVisible(True)
            self.sym_IQ_PID.setVisible(True)

    def setMinimum(self, symbol, event):
        if "TORQUE_LOOP" == event["symbol"].getSelectedKey():
            symbol.setValue(0.15)
        elif "SPEED_LOOP" == event["symbol"].getSelectedKey():
            symbol.setValue(500)
        elif "POSITION_LOOP" == event["symbol"].getSelectedKey():
            symbol.setValue(360)
        else:
            symbol.setValue(50)

    def setMaximum(self, symbol, event):
        if "TORQUE_LOOP" == event["symbol"].getSelectedKey():
            symbol.setValue(0.25)
        elif "SPEED_LOOP" == event["symbol"].getSelectedKey():
            symbol.setValue(3000)
        elif "POSITION_LOOP" == event["symbol"].getSelectedKey():
            symbol.setValue(360)
        else:
            symbol.setValue(500)

    def showThisSymbol(self, symbol, event):
        if True == event["symbol"].getValue():
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)


    def detCurrentPIParameters(self, symbol, event):
        component = symbol.getComponent()
        board = component.getSymbolByID("MCPMSMFOC_BOARD_SEL").getSelectedKey()
        Rs = component.getSymbolValue("MCPMSMFOC_R")
        Ld = component.getSymbolValue("MCPMSMFOC_LD")
        Lq = component.getSymbolValue("MCPMSMFOC_LQ")
        connection = component.getSymbolByID("MCPMSMFOC_MOTOR_CONNECTION").getSelectedKey()
        if (connection == "STAR"):
            max_volt = component.getSymbolValue("MCPMSMFOC_VOLTAGE_MAGNITUDE") / 1.732
        else:
            max_volt = component.getSymbolValue("MCPMSMFOC_VOLTAGE_MAGNITUDE")
        bandwidth = component.getSymbolValue("MCPMSMFOC_CL_BANDWIDTH")

        bandwidth = 2000

        Ls = (Ld+Lq)/2
        Kp = (bandwidth * Ls) / max_volt
        Ts = 1.0 / component.getSymbolValue("MCPMSMFOC_PWM_FREQUENCY")
        Ki = (bandwidth * Rs * Ts) / max_volt

    def calculateCurrentLoopKp(self, symbol, event):

        component = symbol.getComponent()
        Ld = component.getSymbolValue("MCPMSMFOC_LD")
        Lq = component.getSymbolValue("MCPMSMFOC_LQ")

        # Set the bandwidthof PI controller to 10% of the electrical speed
        zp = component.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
        bandwidth = 0.1 * (2 * zp /60) * component.getSymbolValue("MCPMSMFOC_RATED_SPEED")

        Ls = (Ld + Lq)/2

        symbol.setValue(bandwidth * Ls)


    def calculateCurrentLoopKi(self, symbol, event):
        component = symbol.getComponent()
        Rs = component.getSymbolValue("MCPMSMFOC_R")

        # Set the bandwidthof PI controller to 10% of the electrical speed
        zp = component.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
        bandwidth = 0.1 * (2 * zp /60) * component.getSymbolValue("MCPMSMFOC_RATED_SPEED")

        symbol.setValue(bandwidth * Rs)

    def initCurrentLoopKp(self, component):
        # Ld = component.getSymbolValue("MCPMSMFOC_LD")
        # Lq = component.getSymbolValue("MCPMSMFOC_LQ")
        #
        # # Set the bandwidthof PI controller to 10% of the electrical speed
        # zp = component.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
        # bandwidth = 0.1 * (2 * zp /60) * component.getSymbolValue("MCPMSMFOC_RATED_SPEED")
        #
        # Ls = (Ld + Lq)/2
        # Kp = Ls * bandwidth
        # return Kp
        return 0.0


    def initCurrentLoopKi(self, component):
        # Rs = component.getSymbolValue("MCPMSMFOC_R")
        #
        # # Set the bandwidthof PI controller to 10% of the electrical speed
        # zp = component.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
        # bandwidth = 0.1 * (2 * zp /60) * component.getSymbolValue("MCPMSMFOC_RATED_SPEED")
        #
        # Ki = Rs * bandwidth
        #
        # return Ki
        return 0.0

    def updateProjectGraph(self, symbol, event):
        if symbol.getValue() == True:
            # Get all the connected Harmony components
            listOfComps = Database.getActiveComponentIDs()

            for comp in listOfComps:
                if comp == "X2CScope":
                    # Deactivate component
                    Database.deactivateComponents([comp])

                elif comp == "X2C Model":
                    # X2C Model is found
                    modelFound = 1

            if modelFound == 0:
                # Instantiate and connect
                Database.activateComponents(["X2C Model"])

    def updatePeripheralInstance(self, symbol, event):
        status = Database.getSymbolValue(self.component.getID(), "MCPMSMFOC_DATA_MONITOR_ENABLE")

        if status == True:
            # Determine peripheral ID.
            if( True == event["value"]):
                autoComponentIDTable = [symbol.getValue()]
                res = Database.deactivateComponents(autoComponentIDTable)

                symbol.setValue("X2C Model")


                # Activate and connect the default PWM peripheral
                res = Database.activateComponents(["X2C Model"])
                autoComponentIDTable = [[ self.component.getID(), "pmsmfoc_X2CSCOPE", "X2C Model", "x2cModel" ]]
                res = Database.connectDependencies(autoComponentIDTable)
            else:
                autoComponentIDTable = [symbol.getValue()]
                res = Database.deactivateComponents(autoComponentIDTable)

                symbol.setValue("X2CScope")

                # Activate and connect the default PWM peripheral
                res = Database.activateComponents(["X2CScope"])
                autoComponentIDTable = [[ self.component.getID(), "pmsmfoc_X2CSCOPE", "X2CScope", "x2cScope_Scope" ]]
                res = Database.connectDependencies(autoComponentIDTable)

    def __call__(self):
        self.detPositionPIParameters()
        self.detSpeedPIParameters()
        self.detPositionPIParameters()
        self.createSymbols()








