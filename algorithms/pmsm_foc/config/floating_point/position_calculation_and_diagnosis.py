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
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

        # Read motor parameters from motor.xml
        path = Module.getPath() + "/algorithms/pmsm_foc/config/floating_point/motor.xml"
        motor_File = open(path, "r")
        motor_Content = ET.fromstring(motor_File.read()) 

        self.motor_List = list()
        self.motor_Parameters = dict()

        for motor in motor_Content.findall("motor"):
            name = motor.attrib["name"]
            self.motor_List.append(motor.attrib["name"])
            self.motor_Parameters[name] = dict()
            for parameter in motor.findall("parameter"):
                param = parameter.attrib["id"]
                self.motor_Parameters[name][param] = parameter.attrib["value"]

    def createSymbols(self):
        # Root node 
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Position Calculation & Diagnosis")

        # Algorithm selection
        processor = Variables.get("__PROCESSOR") 

        self.sym_ALGORITHM = self.component.createKeyValueSetSymbol("MCPMSMFOC_POSITION_CALC_ALGORITHM", self.sym_NODE)
        self.sym_ALGORITHM.setLabel("Select Position Feedback")
        if (("SAMC21" in processor) or all(x in processor for x in ["PIC32CM", "MC"])):
            self.sym_ALGORITHM.addKey("SENSORLESS_ROLO", "0", "Reduced Order Luenberger Observer")    
        else:
            self.sym_ALGORITHM.addKey("SENSORLESS_PLL", "0", "Equation based PLL")
            self.sym_ALGORITHM.addKey("SENSORED_ENCODER", "1", "Quadrature Encoder")
            self.sym_ALGORITHM.addKey("SENSORLESS_ROLO", "2", "Reduced Order Luenberger Observer (Beta)")
            self.sym_ALGORITHM.addKey("SENSORLESS_SMO", "3", "Sliding Mode Observer")
            self.sym_ALGORITHM.addKey("SENSORLESS_ZSMT_HYBRID", "4", "ZSMT Hybrid (Beta)")
            
        self.sym_ALGORITHM.setOutputMode("Key")
        self.sym_ALGORITHM.setDisplayMode("Description")

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
        self.sym_QDEC_PULSE_PER_EREV.setDependencies( self.symbolUpdate, ["MCPMSMFOC_MOTOR_SEL"])
        self.sym_QDEC_PULSE_PER_EREV.setDefaultValue(200)
        
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
        self.sym_PLL_CUTOFF_FREQUENCY.setDefaultValue(10.0)
        
        self.sym_PLL_TUNING_FACTOR = self.component.createFloatSymbol("MCPMSMFOC_ZSMT_HYB_HFI_KEPS", self.sym_ANGLE_TRACKER )
        self.sym_PLL_TUNING_FACTOR.setLabel("Tracking loop tuning factor")
        self.sym_PLL_TUNING_FACTOR.setDefaultValue(0.25)
        
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
        
        self.sym_SWITCHING_GAIN  = self.component.createFloatSymbol("MCPMSMFOC_SWITCHING_FUNCTION_GAIN", self.sym_SWITCHING_FUNCTION )
        self.sym_SWITCHING_GAIN.setLabel("Gain")
        self.sym_SWITCHING_GAIN.setDescription("Gain")
                
        self.sym_BEMF_OBSERVER = self.component.createMenuSymbol("MCPMSMFOC_SMO_BEMF_OBSERVER", self.sym_ALGORITHM )
        self.sym_BEMF_OBSERVER.setLabel("Back EMF Observer")
        self.sym_BEMF_OBSERVER.setDescription("Back EMF Observer")
        self.sym_BEMF_OBSERVER.setVisible(False)
                
        self.sym_POLE_LOCATION  = self.component.createFloatSymbol("MCPMSMFOC_BEMF_OBSERVER_POLE", self.sym_BEMF_OBSERVER )
        self.sym_POLE_LOCATION.setLabel("Pole location")
        self.sym_POLE_LOCATION.setDescription("Pole location")
        
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
            
            self.sym_SM_CURRENT_OBS.setVisible(False)
            self.sym_SWITCHING_FUNCTION.setVisible(False)
            self.sym_BEMF_OBSERVER.setVisible(False)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)
        
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
            
            self.sym_SM_CURRENT_OBS.setVisible(False)
            self.sym_SWITCHING_FUNCTION.setVisible(False)
            self.sym_BEMF_OBSERVER.setVisible(False)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)
            
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
            
            self.sym_SM_CURRENT_OBS.setVisible(False)
            self.sym_SWITCHING_FUNCTION.setVisible(False)
            self.sym_BEMF_OBSERVER.setVisible(False)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(False)  
            
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
            
            self.sym_SM_CURRENT_OBS.setVisible(True)
            self.sym_SWITCHING_FUNCTION.setVisible(True)
            self.sym_BEMF_OBSERVER.setVisible(True)
            self.sym_FLUX_ANGLE_CALCULATION.setVisible(True)   
            
    def symbolUpdate( self, symbol, event ):
        motor = event["symbol"].getValue()
        symbol.setValue( int( self.motor_Parameters[motor]['QE_PULSES_PER_REV'] ))
