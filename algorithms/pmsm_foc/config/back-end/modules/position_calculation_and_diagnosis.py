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
import xml.etree.ElementTree as ET
import os

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcRpoI_PositionCalculationAndDiagnosis:
    def __init__(self, component):
        self.component = component

    def createSymbols(self):
        # Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Position Calculation & Diagnosis")

        # Algorithm selection
        processor = Variables.get("__PROCESSOR")

        self.sym_ALGORITHM = self.component.createKeyValueSetSymbol("MCPMSMFOC_POSITION_CALC_ALGORITHM", self.sym_NODE)
        self.sym_ALGORITHM.setLabel("Select Position Feedback")
        if (("SAMC2" in processor) or all(x in processor for x in ["PIC32CM", "MC"])):
            self.sym_ALGORITHM.addKey("SENSORLESS_PLL", "0", "Equation based PLL")
        else:
            self.sym_ALGORITHM.addKey("SENSORLESS_PLL", "0", "Equation based PLL")
            self.sym_ALGORITHM.addKey("SENSORED_ENCODER", "1", "Quadrature Encoder")
            self.sym_ALGORITHM.addKey("SENSORLESS_ROLO", "2", "Reduced Order Luenberger Observer (Beta)")
            self.sym_ALGORITHM.addKey("SENSORLESS_SMO", "3", "Sliding Mode Observer ")
            self.sym_ALGORITHM.addKey("SENSORLESS_ZSMT_HYBRID", "4", "ZSMT Hybrid ")

        self.sym_ALGORITHM.setOutputMode("Key")
        self.sym_ALGORITHM.setDisplayMode("Description")
        self.sym_ALGORITHM.setDependencies( self.getDependentLibrary, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])

        self.sym_ED_FILTER = self.component.createMenuSymbol("MCPMSMFOC_ED_FILTER", self.sym_ALGORITHM)
        self.sym_ED_FILTER.setLabel("Ed Filter")
        self.sym_ED_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
        self.sym_ED_FILTER.setVisible(True)

        self.sym_ED_FILTER_PARAMETER = self.component.createFloatSymbol("MCPMSMFOC_ED_FILTER_PARAMETER", self.sym_ED_FILTER )
        self.sym_ED_FILTER_PARAMETER.setLabel("Filter Parameter")
        self.sym_ED_FILTER_PARAMETER.setDefaultValue(0.183)
        self.sym_ED_FILTER_PARAMETER.setVisible(True)

        self.sym_EQ_FILTER = self.component.createMenuSymbol("MCPMSMFOC_EQ_FILTER", self.sym_ALGORITHM)
        self.sym_EQ_FILTER.setLabel("Eq Filter")
        self.sym_EQ_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
        self.sym_EQ_FILTER.setVisible(True)

        self.sym_EQ_FILTER_PARAMETER = self.component.createFloatSymbol("MCPMSMFOC_EQ_FILTER_PARAMETER", self.sym_EQ_FILTER )
        self.sym_EQ_FILTER_PARAMETER.setLabel("Filter Parameter")
        self.sym_EQ_FILTER_PARAMETER.setDefaultValue(0.183)
        self.sym_EQ_FILTER_PARAMETER.setVisible(True)

        self.sym_SPEED_FILTER = self.component.createMenuSymbol("MCPMSMFOC_SPEED_FILTER", self.sym_ALGORITHM)
        self.sym_SPEED_FILTER.setLabel("Speed Filter")
        self.sym_SPEED_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
        self.sym_SPEED_FILTER.setVisible(True)

        self.sym_SPEED_FILTER_PARAMETER = self.component.createFloatSymbol("MCPMSMFOC_SPEED_FILTER_PARAMETER", self.sym_SPEED_FILTER )
        self.sym_SPEED_FILTER_PARAMETER.setLabel("Filter Parameter")
        self.sym_SPEED_FILTER_PARAMETER.setDefaultValue(0.0053)
        self.sym_SPEED_FILTER_PARAMETER.setVisible(True)

        self.sym_NOISE_FILTER = self.component.createMenuSymbol("MCPMSMFOC_ENCODER_DNF", self.sym_ALGORITHM)
        self.sym_NOISE_FILTER.setLabel("Digital Noise Filter")
        self.sym_NOISE_FILTER.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
        self.sym_NOISE_FILTER.setVisible(False)

        self.sym_NOISE_FILTER_COUNT = self.component.createFloatSymbol("MCPMSMFOC_ENCODER_DNF_COUNT", self.sym_NOISE_FILTER )
        self.sym_NOISE_FILTER_COUNT.setLabel("Filter Count")
        self.sym_NOISE_FILTER_COUNT.setDefaultValue(4)

        self.sym_QDEC = self.component.createMenuSymbol("MCPMSMFOC_ENCODER_QDEC", self.sym_ALGORITHM)
        self.sym_QDEC.setLabel("Decoder")
        self.sym_QDEC.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_POSITION_CALC_ALGORITHM"])
        self.sym_QDEC.setVisible(False)

        self.sym_QDEC_PULSE_PER_EREV = self.component.createIntegerSymbol("MCPMSMFOC_ENCODER_QDEC_PULSE_PER_EREV", self.sym_QDEC )
        self.sym_QDEC_PULSE_PER_EREV.setLabel("Pulse Per electrical rotation")
        # self.sym_QDEC_PULSE_PER_EREV.setDependencies( self.symbolUpdate, ["MCPMSMFOC_MOTOR_SEL"])
        self.sym_QDEC_PULSE_PER_EREV.setDefaultValue(0)

        primaryObservers = ["Pulsed Injection", "Sinusoidal Injection"]
        self.sym_PRIMARY_OBSERVER = self.component.createComboSymbol("MCPMSMFOC_ZSMT_HYB_PRIM_OBS", self.sym_ALGORITHM,  primaryObservers )
        self.sym_PRIMARY_OBSERVER.setLabel("Select Primary Observer")
        self.sym_PRIMARY_OBSERVER.setDescription("Select Primary Observer")
        self.sym_PRIMARY_OBSERVER.setDefaultValue("Pulsed Injection")
        self.sym_PRIMARY_OBSERVER.setVisible(False)
        self.sym_PRIMARY_OBSERVER.setReadOnly(True)

        self.sym_PULSE_AMPLITUDE = self.component.createFloatSymbol("MCPMSMFOC_ZSMT_HYB_HFI_MAGNITUDE", self.sym_PRIMARY_OBSERVER )
        self.sym_PULSE_AMPLITUDE.setLabel("HFI Pulse Amplitude")
        self.sym_PULSE_AMPLITUDE.setDefaultValue(5.0)

        secondaryObservers = ["Classical Observer", "Reduced Order Luenberger", "Sliding Mode"]
        self.sym_SECONDARY_OBSERVER = self.component.createComboSymbol("MCPMSMFOC_ZSMT_HYB_SEC_OBS", self.sym_ALGORITHM,  secondaryObservers )
        self.sym_SECONDARY_OBSERVER.setLabel("Select Secondary Observer")
        self.sym_SECONDARY_OBSERVER.setDescription("Select Secondary Observer")
        self.sym_SECONDARY_OBSERVER.setDefaultValue("Classical Observer")
        self.sym_SECONDARY_OBSERVER.setVisible(False)
        self.sym_SECONDARY_OBSERVER.setReadOnly(True)

        self.sym_BEMF_FILTER_PARAM = self.component.createFloatSymbol("MCPMSMFOC_ZSMT_HYB_BEMF_FILT_PARAM", self.sym_SECONDARY_OBSERVER )
        self.sym_BEMF_FILTER_PARAM.setLabel("Back EMF Filter Parameters")
        self.sym_BEMF_FILTER_PARAM.setDefaultValue(1.0)

        self.sym_ZSMT_SOFT_SWITCH = self.component.createMenuSymbol("MCPMSMFOC_ZSMT_HYB_SOFT_SWITCH", self.sym_ALGORITHM )
        self.sym_ZSMT_SOFT_SWITCH.setLabel("Soft Switch")
        self.sym_ZSMT_SOFT_SWITCH.setVisible(False)

        self.sym_UPPER_THRESHOLD = self.component.createFloatSymbol("MCPMSMFOC_ZSMT_HYB_UPPER_TH", self.sym_ZSMT_SOFT_SWITCH )
        self.sym_UPPER_THRESHOLD.setLabel("Upper Threshold ( 0-1)")
        self.sym_UPPER_THRESHOLD.setDefaultValue(0.2)

        self.sym_LOWER_THRESHOLD = self.component.createFloatSymbol("MCPMSMFOC_ZSMT_HYB_LOWER_TH", self.sym_ZSMT_SOFT_SWITCH )
        self.sym_LOWER_THRESHOLD.setLabel("Lower Threshold ( 0-1)")
        self.sym_LOWER_THRESHOLD.setDefaultValue(0.1)

        self.sym_ANGLE_TRACKER = self.component.createMenuSymbol("MCPMSMFOC_ZSMT_HYB_ANGLE_TRACKER", self.sym_ALGORITHM )
        self.sym_ANGLE_TRACKER.setLabel("Angle Tracker")
        self.sym_ANGLE_TRACKER.setVisible(False)

        types = ["Type II", "Type III"]
        self.sym_PLL_TRACKING_LOOP_TYPE = self.component.createComboSymbol("MCPMSMFOC_ZSMT_HYB_PLL_TRACKING_LOOP_TYPE", self.sym_ANGLE_TRACKER, types )
        self.sym_PLL_TRACKING_LOOP_TYPE.setLabel("Tracking loop type")

        self.sym_PLL_CUTOFF_FREQUENCY = self.component.createFloatSymbol("MCPMSMFOC_ZSMT_HYB_ANGLE_TRACK_F0", self.sym_ANGLE_TRACKER )
        self.sym_PLL_CUTOFF_FREQUENCY.setLabel("Tracking loop cut-off frequency")
        self.sym_PLL_CUTOFF_FREQUENCY.setDependencies(self.default_hfi_pll_cutoff_freq, ['MCPMSMFOC_RATED_SPEED'])
   
        self.sym_PLL_TUNING_FACTOR = self.component.createFloatSymbol("MCPMSMFOC_ZSMT_HYB_HFI_KEPS", self.sym_ANGLE_TRACKER )
        self.sym_PLL_TUNING_FACTOR.setLabel("Tracking loop tuning factor")
        self.sym_PLL_TUNING_FACTOR.setDefaultValue(0.0)
        self.sym_PLL_TUNING_FACTOR.setDependencies(self.peak_hfi_current_estimate, ['MCPMSMFOC_LD'])

        self.sym_IPC = self.component.createMenuSymbol("MCPMSMFOC_IPC_MENU", self.sym_ANGLE_TRACKER )
        self.sym_IPC.setLabel("Initial Position Correction")
    
        self.sym_IPC_PUSLE_AMPLITUDE = self.component.createFloatSymbol("MCPMSMFOC_IPC_PULSE_MAGNITUDE", self.sym_IPC )
        self.sym_IPC_PUSLE_AMPLITUDE.setLabel("IPC pulse amplitude")
        self.sym_IPC_PUSLE_AMPLITUDE.setDefaultValue(self.sym_PULSE_AMPLITUDE.getValue())

        default_pulse_duty = 10 * Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_PERIOD")
        self.sym_IPC_PUSLE_DUTY = self.component.createFloatSymbol("MCPMSMFOC_IPC_PULSE_DUTY", self.sym_IPC )
        self.sym_IPC_PUSLE_DUTY.setLabel("IPC pulse duty (in ms)")
        self.sym_IPC_PUSLE_DUTY.setDefaultValue(default_pulse_duty)

        default_pulse_duration = 10 * default_pulse_duty
        self.sym_IPC_PUSLE_DURATION = self.component.createFloatSymbol("MCPMSMFOC_IPC_PULSE_DURATION", self.sym_IPC )
        self.sym_IPC_PUSLE_DURATION.setLabel("IPC pulse duration (in ms)")
        self.sym_IPC_PUSLE_DURATION.setDefaultValue(default_pulse_duration)

        self.sym_BEMF_ANGLE_TRACKER = self.component.createMenuSymbol("MCPMSMFOC_BEMF_ANGLE_TRACKER", self.sym_ALGORITHM )
        self.sym_BEMF_ANGLE_TRACKER.setLabel("Back EMF ")
        self.sym_BEMF_ANGLE_TRACKER.setVisible(False)

        types = ["Type II", "Type III"]
        self.sym_PLL_TRACKING_LOOP_TYPE = self.component.createComboSymbol("MCPMSMFOC_BEMF_PLL_TRACKING_LOOP_TYPE", self.sym_BEMF_ANGLE_TRACKER, types )
        self.sym_PLL_TRACKING_LOOP_TYPE.setLabel("Tracking loop type")

        self.sym_PLL_CUTOFF_FREQUENCY = self.component.createFloatSymbol("MCPMSMFOC_BEMF_ANGLE_TRACK_F0", self.sym_BEMF_ANGLE_TRACKER )
        self.sym_PLL_CUTOFF_FREQUENCY.setLabel("Tracking loop cut-off frequency")
        self.sym_PLL_CUTOFF_FREQUENCY.setDependencies(self.default_bemf_pll_cutoff_freq, ['MCPMSMFOC_RATED_SPEED'])

        self.sym_PLL_TUNING_FACTOR = self.component.createFloatSymbol("MCPMSMFOC_BEMF_KEPS", self.sym_BEMF_ANGLE_TRACKER )
        self.sym_PLL_TUNING_FACTOR.setLabel("Tracking loop tuning factor")
        self.sym_PLL_TUNING_FACTOR.setDependencies(self.peak_bemf_error_estimate, ['MCPMSMFOC_LD'])


        self.sym_SM_CURRENT_OBS  = self.component.createMenuSymbol("MCPMSMFOC_SMO_CURRENT_OBSERVER", self.sym_ALGORITHM )
        self.sym_SM_CURRENT_OBS.setLabel("Sliding mode current observer")
        self.sym_SM_CURRENT_OBS.setDescription("Sliding mode current observer")
        self.sym_SM_CURRENT_OBS.setVisible(False)


        self.sym_SWITCHING_FUNCTION  = self.component.createMenuSymbol("MCPMSMFOC_SMO_SWITCHING_FUNCTION", self.sym_ALGORITHM )
        self.sym_SWITCHING_FUNCTION.setLabel("Switching Function")
        self.sym_SWITCHING_FUNCTION.setDescription("Switching Function")
        self.sym_SWITCHING_FUNCTION.setVisible(False)

        self.sym_SWITCHING_BOUNDARY  = self.component.createFloatSymbol("MCPMSMFOC_SWITCHING_FUNCTION_BOUNDARY", self.sym_SWITCHING_FUNCTION )
        self.sym_SWITCHING_BOUNDARY.setLabel("Boundary")
        self.sym_SWITCHING_BOUNDARY.setDescription("Boundary")
        self.sym_SWITCHING_BOUNDARY.setDefaultValue(0.5)

        self.sym_SWITCHING_GAIN  = self.component.createFloatSymbol("MCPMSMFOC_SWITCHING_FUNCTION_GAIN", self.sym_SWITCHING_FUNCTION )
        self.sym_SWITCHING_GAIN.setLabel("Gain")
        self.sym_SWITCHING_GAIN.setDescription("Gain")
        self.sym_SWITCHING_GAIN.setDefaultValue(8000)

        self.sym_BEMF_OBSERVER = self.component.createMenuSymbol("MCPMSMFOC_SMO_BEMF_OBSERVER", self.sym_ALGORITHM )
        self.sym_BEMF_OBSERVER.setLabel("Back EMF Observer")
        self.sym_BEMF_OBSERVER.setDescription("Back EMF Observer")
        self.sym_BEMF_OBSERVER.setVisible(False)

        self.sym_POLE_LOCATION  = self.component.createFloatSymbol("MCPMSMFOC_BEMF_OBSERVER_POLE", self.sym_BEMF_OBSERVER )
        self.sym_POLE_LOCATION.setLabel("Pole location")
        self.sym_POLE_LOCATION.setDescription("Pole location")
        self.sym_POLE_LOCATION.setMin(-10000)
        self.sym_POLE_LOCATION.setMax(0)
        self.sym_POLE_LOCATION.setDefaultValue(-2000)

        phaseDetectors = ["Classical PLL", "Modified PLL", "SRF PLL", "ArcTangent"]
        self.sym_FLUX_ANGLE_CALCULATION = self.component.createComboSymbol("MCPMSMFOC_PHASE_DETECTION_ALGORITHM", self.sym_ALGORITHM, phaseDetectors )
        self.sym_FLUX_ANGLE_CALCULATION.setLabel("Flux Angle Calculation")
        self.sym_FLUX_ANGLE_CALCULATION.setDescription("Flux Angle Calculation")
        self.sym_FLUX_ANGLE_CALCULATION.setDefaultValue("SRF PLL")
        self.sym_FLUX_ANGLE_CALCULATION.setReadOnly(True)
        self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)

        self.sym_CUT_OFF_FREQUENCY  = self.component.createFloatSymbol("MCPMSMFOC_PHASE_DETECTION_F0", self.sym_FLUX_ANGLE_CALCULATION )
        self.sym_CUT_OFF_FREQUENCY.setLabel("Cut-off Frequency")
        self.sym_CUT_OFF_FREQUENCY.setDescription("Cut-Off Frequency")
        self.sym_CUT_OFF_FREQUENCY.setDefaultValue(10)

        self.sym_ROLO_OBSERVER = self.component.createMenuSymbol("MCPMSMFOC_ROLO_CURRENT_OBSERVER", self.sym_ALGORITHM )
        self.sym_ROLO_OBSERVER.setLabel("Reduced order luenberger observer")
        self.sym_ROLO_OBSERVER.setDescription("Reduced order luenberger observer")
        self.sym_ROLO_OBSERVER.setVisible(False)

        self.sym_ROLO_POLE_LOCATION  = self.component.createFloatSymbol("MCPMSMFOC_BEMF_OBSERVER_ROLO_POLE", self.sym_ROLO_OBSERVER )
        self.sym_ROLO_POLE_LOCATION.setLabel("Pole location")
        self.sym_ROLO_POLE_LOCATION.setDescription("Pole location")
        self.sym_ROLO_POLE_LOCATION.setMin(-10000)
        self.sym_ROLO_POLE_LOCATION.setMax(0)
        self.sym_ROLO_POLE_LOCATION.setDefaultValue(-2000)

        phaseDetectors = ["Classical PLL", "Modified PLL", "SRF PLL", "ArcTangent"]
        self.sym_ROLO_FLUX_ANGLE_CALCULATION = self.component.createComboSymbol("MCPMSMFOC_ROLO_PHASE_DETECTION_ALGORITHM", self.sym_ALGORITHM, phaseDetectors )
        self.sym_ROLO_FLUX_ANGLE_CALCULATION.setLabel("Flux Angle Calculation")
        self.sym_ROLO_FLUX_ANGLE_CALCULATION.setDescription("Flux Angle Calculation")
        self.sym_ROLO_FLUX_ANGLE_CALCULATION.setDefaultValue("SRF PLL")
        self.sym_ROLO_FLUX_ANGLE_CALCULATION.setReadOnly(True)
        self.sym_ROLO_FLUX_ANGLE_CALCULATION.setVisible(False)

        self.sym_ROLO_CUT_OFF_FREQUENCY  = self.component.createFloatSymbol("MCPMSMFOC_ROLO_PHASE_DETECTION_F0", self.sym_ROLO_FLUX_ANGLE_CALCULATION )
        self.sym_ROLO_CUT_OFF_FREQUENCY.setLabel("Cut-off Frequency")
        self.sym_ROLO_CUT_OFF_FREQUENCY.setDescription("Cut-Off Frequency")
        self.sym_ROLO_CUT_OFF_FREQUENCY.setDefaultValue(10)

    def showAlgorithmDependentSymbols(self, symbol, event):
        if "SENSORLESS_PLL" ==  event["symbol"].getSelectedKey():
            self.sym_ED_FILTER.setVisible(True)
            self.sym_EQ_FILTER.setVisible(True)
            self.sym_SPEED_FILTER.setVisible(True)

            self.sym_NOISE_FILTER.setVisible(False)
            self.sym_QDEC.setVisible(False)

            self.sym_PRIMARY_OBSERVER.setVisible(False)
            self.sym_SECONDARY_OBSERVER.setVisible(False)
            self.sym_ZSMT_SOFT_SWITCH.setVisible(False)
            self.sym_ANGLE_TRACKER.setVisible(False)
            self.sym_BEMF_ANGLE_TRACKER.setVisible(False)

            self.sym_SM_CURRENT_OBS.setVisible(False)
            self.sym_SWITCHING_FUNCTION.setVisible(False)
            self.sym_BEMF_OBSERVER.setVisible(False)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)

            self.sym_ROLO_OBSERVER.setVisible(False)
            self.sym_ROLO_FLUX_ANGLE_CALCULATION.setVisible(False)


        elif "SENSORED_ENCODER" ==  event["symbol"].getSelectedKey():
            self.sym_ED_FILTER.setVisible(False)
            self.sym_EQ_FILTER.setVisible(False)
            self.sym_SPEED_FILTER.setVisible(False)

            self.sym_NOISE_FILTER.setVisible(True)
            self.sym_QDEC.setVisible(True)

            self.sym_PRIMARY_OBSERVER.setVisible(False)
            self.sym_SECONDARY_OBSERVER.setVisible(False)
            self.sym_ZSMT_SOFT_SWITCH.setVisible(False)
            self.sym_ANGLE_TRACKER.setVisible(False)
            self.sym_BEMF_ANGLE_TRACKER.setVisible(False)

            self.sym_SM_CURRENT_OBS.setVisible(False)
            self.sym_SWITCHING_FUNCTION.setVisible(False)
            self.sym_BEMF_OBSERVER.setVisible(False)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)

            self.sym_ROLO_OBSERVER.setVisible(False)
            self.sym_ROLO_FLUX_ANGLE_CALCULATION.setVisible(False)

        elif "SENSORLESS_ZSMT_HYBRID" == event["symbol"].getSelectedKey():
            self.sym_ED_FILTER.setVisible(False)
            self.sym_EQ_FILTER.setVisible(False)
            self.sym_SPEED_FILTER.setVisible(False)

            self.sym_NOISE_FILTER.setVisible(False)
            self.sym_QDEC.setVisible(False)

            self.sym_PRIMARY_OBSERVER.setVisible(True)
            self.sym_SECONDARY_OBSERVER.setVisible(True)
            self.sym_ZSMT_SOFT_SWITCH.setVisible(True)
            self.sym_ANGLE_TRACKER.setVisible(True)
            self.sym_BEMF_ANGLE_TRACKER.setVisible(True)

            self.sym_SM_CURRENT_OBS.setVisible(False)
            self.sym_SWITCHING_FUNCTION.setVisible(False)
            self.sym_BEMF_OBSERVER.setVisible(False)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)

            self.sym_ROLO_OBSERVER.setVisible(False)
            self.sym_ROLO_FLUX_ANGLE_CALCULATION.setVisible(False)

        elif "SENSORLESS_SMO" == event["symbol"].getSelectedKey():
            self.sym_ED_FILTER.setVisible(False)
            self.sym_EQ_FILTER.setVisible(False)
            self.sym_SPEED_FILTER.setVisible(False)

            self.sym_NOISE_FILTER.setVisible(False)
            self.sym_QDEC.setVisible(False)

            self.sym_PRIMARY_OBSERVER.setVisible(False)
            self.sym_SECONDARY_OBSERVER.setVisible(False)
            self.sym_ZSMT_SOFT_SWITCH.setVisible(False)
            self.sym_ANGLE_TRACKER.setVisible(False)
            self.sym_BEMF_ANGLE_TRACKER.setVisible(False)

            self.sym_SM_CURRENT_OBS.setVisible(True)
            self.sym_SWITCHING_FUNCTION.setVisible(True)
            self.sym_BEMF_OBSERVER.setVisible(True)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(True)

            self.sym_ROLO_OBSERVER.setVisible(False)
            self.sym_ROLO_FLUX_ANGLE_CALCULATION.setVisible(False)

        elif "SENSORLESS_ROLO" == event["symbol"].getSelectedKey():
            self.sym_ED_FILTER.setVisible(False)
            self.sym_EQ_FILTER.setVisible(False)
            self.sym_SPEED_FILTER.setVisible(False)

            self.sym_NOISE_FILTER.setVisible(False)
            self.sym_QDEC.setVisible(False)

            self.sym_PRIMARY_OBSERVER.setVisible(False)
            self.sym_SECONDARY_OBSERVER.setVisible(False)
            self.sym_ZSMT_SOFT_SWITCH.setVisible(False)
            self.sym_ANGLE_TRACKER.setVisible(False)
            self.sym_BEMF_ANGLE_TRACKER.setVisible(False)

            self.sym_SM_CURRENT_OBS.setVisible(False)
            self.sym_SWITCHING_FUNCTION.setVisible(False)
            self.sym_BEMF_OBSERVER.setVisible(False)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)

            self.sym_ROLO_OBSERVER.setVisible(True)
            self.sym_ROLO_FLUX_ANGLE_CALCULATION.setVisible(True)

    def peak_hfi_current_estimate(self, symbol, event):
        if event['value'] == 0:
            return
        
        pulse_amplitude = self.sym_PULSE_AMPLITUDE.getValue()
        pulse_duration = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_PWM_PERIOD")
        peak_hfi_current = pulse_amplitude * pulse_duration/ event['value']
        symbol.setValue(peak_hfi_current)

    def peak_bemf_error_estimate(self, symbol, event):
        # To DO: Calculate Keps value from equations
        # For now, it is set to 1
        symbol.setValue(1)
    
    def default_hfi_pll_cutoff_freq(self, symbol, event):
        if event['value'] == 0:
            return
        
        pole_pairs = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_POLE_PAIRS")
        rated_elec_freq_in_hz = event['value'] * pole_pairs / 60.0

        # Set default PLL bandwidth to 10% of rated electrical frequency
        # For HFI PLL, PLL error is twice the theta_error, a factor of 2 is multipled to compensate
        pll_cut_off_freq = 0.2 * rated_elec_freq_in_hz
        symbol.setValue(pll_cut_off_freq)

    def default_bemf_pll_cutoff_freq(self, symbol, event):
        if event['value'] == 0:
            return
        
        pole_pairs = Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_POLE_PAIRS")
        rated_elec_freq_in_hz = event['value'] * pole_pairs / 60.0

        pll_cut_off_freq = 0.1 * rated_elec_freq_in_hz
        symbol.setValue(pll_cut_off_freq)

    def getDependentLibrary(self, symbol, event):
        print('Debug encoder', symbol.getSelectedKey() )
        if "SENSORED_ENCODER" == str(symbol.getSelectedKey()):
            symbol.getComponent().setDependencyEnabled("pmsmfoc_QDEC", True)

            # Activate and connect the default  peripheral for quadrature decoder
            module = str( Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_ENCODER_PERIPHERAL_ID"))
            autoConnectTable = [ module]
            res = Database.activateComponents(autoConnectTable)

            autoComponentIDTable = [[ "pmsm_foc", "pmsmfoc_QDEC", module.lower(), module.upper() + "_QDEC"]]
            res = Database.connectDependencies(autoComponentIDTable)
            
            print( 'Debug encoder', autoComponentIDTable )

        else:
            # Deactivate and connect the default  peripheral for quadrature decoder
            module = str( Database.getSymbolValue("pmsm_foc", "MCPMSMFOC_ENCODER_PERIPHERAL_ID"))
            autoConnectTable = [ module]
            res = Database.deactivateComponents(autoConnectTable)
            print( 'Debug encoder', 'Failed' )

            symbol.getComponent().setDependencyEnabled("pmsmfoc_QDEC", False)

    # def symbolUpdate( self, symbol, event ):
    #     motor = event["symbol"].getValue()
    #     symbol.setValue( int( self.motor_Parameters[motor]['QE_PULSES_PER_REV'] ))
