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
        
        self.sym_ALGORITHM = self.component.createKeyValueSetSymbol("MCPMSMFOC_ALIGN_OR_DETECT_ALGORITHM", self.sym_ALIGN )
        self.sym_ALGORITHM.setLabel("Algorithm")
        self.sym_ALGORITHM.addKey("FORCE_ALIGN", "0", "Force align")
        self.sym_ALGORITHM.setOutputMode("Key")
        self.sym_ALGORITHM.setDisplayMode("Description")
        self.sym_ALGORITHM.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_ALIGN_OR_DETECT'])

        self.sym_AXIS = self.component.createKeyValueSetSymbol("MCPMSMFOC_ALIGN_OR_DETECT_AXIS", self.sym_ALIGN )
        self.sym_AXIS.setLabel("Aligment axis")
        self.sym_AXIS.addKey("Q_AXIS", "0", "Q-axis")
        self.sym_AXIS.addKey("D_AXIS", "1", "D-axis")
        # self.sym_AXIS.addKey("IPD", "2", "Initial Position Detection")
        self.sym_AXIS.setOutputMode("Key")
        self.sym_AXIS.setDisplayMode("Description")
        self.sym_AXIS.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_ALIGN_OR_DETECT'])

        self.sym_CURRENT = self.component.createFloatSymbol( "MCPMSMFOC_STARTUP_CURRENT", self.sym_ALIGN )
        self.sym_CURRENT.setLabel("Alignment current")
        self.sym_CURRENT.setDefaultValue(0.2)
        self.sym_CURRENT.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_ALIGN_OR_DETECT'])

        self.sym_TIME = self.component.createFloatSymbol( "MCPMSMFOC_STARTUP_TIME", self.sym_ALIGN )
        self.sym_TIME.setLabel("Alignment time")
        self.sym_TIME.setDefaultValue(2)
        self.sym_TIME.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_ALIGN_OR_DETECT'])

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
        
        # Enable flying start after functional test
        self.sym_FLYING.setReadOnly(True)

        self.sym_DETECT_TIME = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_DETECTION_TIME", self.sym_FLYING )
        self.sym_DETECT_TIME.setLabel("Detection Time")
        self.sym_DETECT_TIME.setDefaultValue(2)
        self.sym_DETECT_TIME.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_DETECT_TIME.setVisible(False)

        self.sym_MIN_SPEED = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_MINIMUM_SPEED", self.sym_FLYING )
        self.sym_MIN_SPEED.setLabel("Minimum speed (RPM)")
        self.sym_MIN_SPEED.setDefaultValue(500)
        self.sym_MIN_SPEED.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_MIN_SPEED.setVisible(False)

        self.sym_FLYING_START_CURRENT = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_CURRENT", self.sym_FLYING )
        self.sym_FLYING_START_CURRENT.setLabel("Current (A)")
        self.sym_FLYING_START_CURRENT.setDefaultValue(0.2)
        self.sym_FLYING_START_CURRENT.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_FLYING_START_CURRENT.setVisible(False)

        self.sym_CONTROLLER = self.component.createMenuSymbol( "MCPMSMFOC_FLY_START_CONTROLLER", self.sym_FLYING )
        self.sym_CONTROLLER.setLabel("Controller Parameters")
        self.sym_CONTROLLER.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_CONTROLLER.setVisible(False)

        self.sym_D_CONTROLLER = self.component.createMenuSymbol( "MCPMSMFOC_FLY_START_D_CONTROLLER", self.sym_CONTROLLER )
        self.sym_D_CONTROLLER.setLabel("D-axis Controller")

        self.sym_D_KP = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_D_CONTROLLER_KP", self.sym_D_CONTROLLER )
        self.sym_D_KP.setLabel("Kp")
        self.sym_D_KP.setDefaultValue(self.Kp)

        
        self.sym_D_KI = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_D_CONTROLLER_KI", self.sym_D_CONTROLLER )
        self.sym_D_KI.setLabel("Ki")
        self.sym_D_KI.setDefaultValue(self.Ki)

        self.sym_D_KC = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_D_CONTROLLER_KC", self.sym_D_CONTROLLER )
        self.sym_D_KC.setLabel("Kc")
        self.sym_D_KC.setDefaultValue(self.Kc)

        self.sym_Q_CONTROLLER = self.component.createMenuSymbol( "MCPMSMFOC_FLY_START_Q_CONTROLLER", self.sym_CONTROLLER )
        self.sym_Q_CONTROLLER.setLabel("Q-axis Controller")

        self.sym_Q_KP = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_Q_CONTROLLER_KP", self.sym_Q_CONTROLLER )
        self.sym_Q_KP.setLabel("Kp")
        self.sym_Q_KP.setDefaultValue(self.Kp)

        self.sym_Q_KI = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_Q_CONTROLLER_KI", self.sym_Q_CONTROLLER )
        self.sym_Q_KI.setLabel("Ki")
        self.sym_Q_KI.setDefaultValue(self.Ki)

        self.sym_Q_KC = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_Q_CONTROLLER_KC", self.sym_Q_CONTROLLER )
        self.sym_Q_KC.setLabel("Kc")
        self.sym_Q_KC.setDefaultValue(self.Kc)

        self.sym_ADVANCED = self.component.createMenuSymbol( "MCPMSMFOC_FLY_START_ADVANCED", self.sym_FLYING )
        self.sym_ADVANCED.setLabel("Advanced Configuration")
        self.sym_ADVANCED.setDependencies( self.showThisSymbol, ['MCPMSMFOC_ENABLE_FLYING_START'])
        self.sym_ADVANCED.setVisible(False)

        self.sym_REGENERATIVE_BRAKE = self.component.createBooleanSymbol( "MCPMSMFOC_ENABLE_REGEN_BRAKE", self.sym_ADVANCED )
        self.sym_REGENERATIVE_BRAKE.setLabel("Regenerative Braking")
        
        self.sym_NULL_VECTOR_TIME = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_NULL_VECTOR_TIME", self.sym_ADVANCED )
        self.sym_NULL_VECTOR_TIME.setLabel("Null vector braking time (s)")
        self.sym_NULL_VECTOR_TIME.setDefaultValue(2)

        self.sym_PEAK_BRAKE_CURRENT = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_PEAK_BRAKE_CURRENT", self.sym_ADVANCED )
        self.sym_PEAK_BRAKE_CURRENT.setLabel("Peak braking current (A)")
        self.sym_PEAK_BRAKE_CURRENT.setDefaultValue(0.2)

        self.sym_BRAKE_RAMP_TIME = self.component.createFloatSymbol( "MCPMSMFOC_FLY_START_BRAKE_RAMP_TIME", self.sym_ADVANCED )
        self.sym_BRAKE_RAMP_TIME.setLabel("Braking ramp time (s)")
        self.sym_BRAKE_RAMP_TIME.setDefaultValue(2)


    def showThisSymbol(self, symbol, event):
       
        if True == event["symbol"].getValue():
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
