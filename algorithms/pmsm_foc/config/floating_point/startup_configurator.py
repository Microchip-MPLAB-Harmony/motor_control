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

#---------------------------------------------------------------------------------------#
#                                 GLOBAL VARIABLES                                      #
#---------------------------------------------------------------------------------------#
class mcSupI_StartupConfigurator:
    def __init__(self, algorithm, component):
        self.algorithm = algorithm
        self.component = component

    def createSymbols(self):
        #Root node
        self.sym_NODE = self.component.createMenuSymbol(None, None)
        self.sym_NODE.setLabel("Start-up Configurator")

        # Symbols for start up configuration
        self.sym_STARTUP = self.component.createMenuSymbol( None, self.sym_NODE )
        self.sym_STARTUP.setLabel("Start-up")

        self.sym_ALIGN = self.component.createBooleanSymbol( "MCPMSMFOC_ENABLE_ALIGN_OR_DETECT", self.sym_STARTUP )
        self.sym_ALIGN.setLabel("Field Alignment/ Detection")
        self.sym_ALIGN.setDefaultValue(True)

        self.sym_ALGORITHM = self.component.createKeyValueSetSymbol("MCPMSMFOC_ALIGN_OR_DETECT_AXIS", self.sym_ALIGN )
        self.sym_ALGORITHM.setLabel("Select algorithm")
        self.sym_ALGORITHM.addKey("Q_AXIS", "0", "Force Q-axis alignment")
        self.sym_ALGORITHM.addKey("D_AXIS", "1", "Force D-axis alignment")
        self.sym_ALGORITHM.addKey("IPD", "2", "Initial Position Detection")
        self.sym_ALGORITHM.setOutputMode("Key")
        self.sym_ALGORITHM.setDisplayMode("Description")
        self.sym_ALGORITHM.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_ALIGN_OR_DETECT'])

        self.sym_PARAMETERS = self.component.createMenuSymbol("MCPMSMFOC_CONFIG_PARAMETERS", self.sym_ALGORITHM)
        self.sym_PARAMETERS.setVisible(False)
        self.sym_PARAMETERS.setDependencies(self.showAlgorithmDependentSymbols, ["MCPMSMFOC_ALIGN_OR_DETECT_AXIS"])

        self.sym_CURRENT = self.component.createFloatSymbol( "MCPMSMFOC_STARTUP_CURRENT", self.sym_ALGORITHM )
        self.sym_CURRENT.setLabel("Alignment current")
        self.sym_CURRENT.setDefaultValue(0.4)
        # self.sym_CURRENT.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_ALIGN_OR_DETECT'])

        self.sym_TIME = self.component.createFloatSymbol( "MCPMSMFOC_STARTUP_TIME", self.sym_ALGORITHM )
        self.sym_TIME.setLabel("Alignment time")
        self.sym_TIME.setDefaultValue(2)
        # self.sym_TIME.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_ALIGN_OR_DETECT'])

        self.sym_PULSE_AMPLITUDE = self.component.createFloatSymbol( "MCPMSMFOC_IPD_PULSE_AMPLITUDE", self.sym_ALGORITHM )
        self.sym_PULSE_AMPLITUDE.setLabel("Pulse Amplitude (in volts)")
        self.sym_PULSE_AMPLITUDE.setDefaultValue(5)
        self.sym_PULSE_AMPLITUDE.setVisible(False)

        self.sym_PULSE_DURATION = self.component.createFloatSymbol( "MCPMSMFOC_IPD_PULSE_DURATION", self.sym_ALGORITHM )
        self.sym_PULSE_DURATION.setLabel("Pulse Duration (in seconds )")
        self.sym_PULSE_DURATION.setDefaultValue(0.0002)
        self.sym_PULSE_DURATION.setVisible(False)

        self.sym_PULSE_PERIOD = self.component.createFloatSymbol( "MCPMSMFOC_IPD_PULSE_PERIOD", self.sym_ALGORITHM )
        self.sym_PULSE_PERIOD.setLabel("Pulse Period (in seconds )")
        self.sym_PULSE_PERIOD.setDefaultValue(0.0055)
        self.sym_PULSE_PERIOD.setVisible(False)

        # Open loop startup
        self.sym_OL_RAMP = self.component.createBooleanSymbol( "MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP", self.sym_STARTUP )
        self.sym_OL_RAMP.setLabel("Open loop speed ramp")
        self.sym_OL_RAMP.setDefaultValue(True)

        self.sym_OL_ENDSPEED = self.component.createFloatSymbol( "MCPMSMFOC_OPEN_LOOP_END_SPEED", self.sym_OL_RAMP )
        self.sym_OL_ENDSPEED.setLabel("Open loop end-speed (RPM)")
        self.sym_OL_ENDSPEED.setDefaultValue(500)
        self.sym_OL_ENDSPEED.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP'])

        self.sym_OL_RAMP_TIME = self.component.createFloatSymbol( "MCPMSMFOC_OPEN_LOOP_RAMP_TIME", self.sym_OL_RAMP )
        self.sym_OL_RAMP_TIME.setLabel("Ramp time (s)")
        self.sym_OL_RAMP_TIME.setDefaultValue(5)
        self.sym_OL_RAMP_TIME.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP'])

        self.sym_OL_STAB_TIME = self.component.createFloatSymbol( "MCPMSMFOC_OPEN_LOOP_STAB_TIME", self.sym_OL_RAMP )
        self.sym_OL_STAB_TIME.setLabel("Stabilization time (s)")
        self.sym_OL_STAB_TIME.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_OPEN_LOOP_STARTUP'])
        self.sym_OL_STAB_TIME.setDefaultValue(2)


        # Symbols for flying start configuration
        self.sym_FLYING = self.component.createBooleanSymbol( "MCPMSMFOC_ENABLE_FLYING_START", self.sym_NODE )
        self.sym_FLYING.setLabel("Flying Start")
        self.sym_FLYING.setDefaultValue(False)

        # Enable flying start after functional test
        self.sym_FLYING.setReadOnly(False)

        self.sym_DETECT_TIME = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_DETECTION_TIME", self.sym_FLYING )
        self.sym_DETECT_TIME.setLabel("Detection Time")
        self.sym_DETECT_TIME.setDefaultValue(2)
        self.sym_DETECT_TIME.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_DETECT_TIME.setVisible(True)

        self.sym_MIN_SPEED = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_MINIMUM_SPEED", self.sym_FLYING )
        self.sym_MIN_SPEED.setLabel("Minimum speed (RPM)")
        self.sym_MIN_SPEED.setDefaultValue(500)
        self.sym_MIN_SPEED.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_MIN_SPEED.setVisible(True)

        self.sym_FADEOUT_TIME = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_FADEOUT_TIME", self.sym_FLYING )
        self.sym_FADEOUT_TIME.setLabel("Passive Braking time (s)")
        self.sym_FADEOUT_TIME.setDefaultValue(2)

        self.sym_FADEOUT_BURST_PERIOD = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_FADEOUT_BURST_PERIOD", self.sym_FLYING )
        self.sym_FADEOUT_BURST_PERIOD.setLabel("Fade-out burst period")
        self.sym_FADEOUT_BURST_PERIOD.setDefaultValue(0.02)

        self.sym_ADVANCED = self.component.createMenuSymbol( "MCPMSMFOC_FLY_START_ADVANCED", self.sym_FLYING )
        self.sym_ADVANCED.setLabel("Advanced Configuration")
        self.sym_ADVANCED.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_ADVANCED.setVisible(True)

        self.sym_REGENERATIVE_BRAKE = self.component.createBooleanSymbol( "MCPMSMFOC_ENABLE_REGEN_BRAKE", self.sym_ADVANCED )
        self.sym_REGENERATIVE_BRAKE.setLabel("Regenerative Braking")
        self.sym_REGENERATIVE_BRAKE.setDefaultValue(False)
        self.sym_REGENERATIVE_BRAKE.setDependencies( self.showThisSymbol, ['MCPMSMFOC_FLY_START_ADVANCED'])


        self.sym_PEAK_BRAKE_CURRENT = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_PEAK_BRAKE_CURRENT", self.sym_REGENERATIVE_BRAKE )
        self.sym_PEAK_BRAKE_CURRENT.setLabel("Peak braking current (A)")
        self.sym_PEAK_BRAKE_CURRENT.setDefaultValue(0.2)
        self.sym_PEAK_BRAKE_CURRENT.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_REGEN_BRAKE'])

        self.sym_BRAKE_RAMP_TIME = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_BRAKE_RAMP_TIME", self.sym_REGENERATIVE_BRAKE )
        self.sym_BRAKE_RAMP_TIME.setLabel("Braking ramp time (s)")
        self.sym_BRAKE_RAMP_TIME.setDefaultValue(2)
        self.sym_BRAKE_RAMP_TIME.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_REGEN_BRAKE'])

    def showAlgorithmDependentSymbols(self, symbol, event):
        if "IPD" ==  event["symbol"].getSelectedKey():
            self.sym_CURRENT.setVisible(False)
            self.sym_TIME.setVisible(False)
            self.sym_PULSE_AMPLITUDE.setVisible(True)
            self.sym_PULSE_DURATION.setVisible(True)
            self.sym_PULSE_PERIOD.setVisible(True)

        else:
            self.sym_CURRENT.setVisible(True)
            self.sym_TIME.setVisible(True)
            self.sym_PULSE_AMPLITUDE.setVisible(False)
            self.sym_PULSE_DURATION.setVisible(False)
            self.sym_PULSE_PERIOD.setVisible(False)

    def showThisSymbol(self, symbol, event):
        print( "Check point", event['value'])
        if True == event["value"]:
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

    def detControlParam(self):
        self.Kp = 0.1
        self.Ki = 0.2
        self.Kc = 0.5

    def __call__(self):
        # Determine PI controller parameters
        self.detControlParam()

        # Create symbols
        self.createSymbols()
