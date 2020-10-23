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

"""*****************************************************************************
* File Name: mcPmsmFoc_MotorParameter.py
*
* Description:
* The file comprises of back-end code for motor block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                             GLOBAL VARIABLES                                     # 
#----------------------------------------------------------------------------------#

#----------------------------------------------------------------------------------#
#                        SUPPORTED MOTOR PARAMETERS                                # 
#----------------------------------------------------------------------------------#
mcMotC_DefaultPararameterDict = {'LONG_HURST' :   { 'R'                 : 0.285,
                                              'LD'                : 0.00032,
                                              'LQ'                : 0.00032,
                                              'BEMF_CONST'        : 7.24,
                                              'POLE_PAIRS'        : 5,
                                              'RATED_SPEED'       : 2804,
                                              'MAX_SPEED'         : 3500,
                                              'MAX_FW_CURRENT'    : -2.0,
                                              'QE_PULSES_PER_REV' : 250,
                                              'MAX_MOTOR_CURRENT' : 4.0 ,
                                              'MOTOR_CONNECTION'  : "STAR",
                                            },
                            'SMALL_HURST' : { 'R'                 : 2.10,
                                              'LD'                : 0.000192,
                                              'LQ'                : 0.000192,
                                              'BEMF_CONST'        : 7.24,
                                              'POLE_PAIRS'        : 5,
                                              'RATED_SPEED'       : 2054,
                                              'MAX_SPEED'         : 4000,
                                              'MAX_FW_CURRENT'    : -2.0,
                                              'QE_PULSES_PER_REV' : 0,
                                              'MAX_MOTOR_CURRENT' : 4.0 ,
                                              'MOTOR_CONNECTION'  : "STAR",
                                            },
                            'LEADSHINE' :   { 'R'                 : 1.39,
                                              'LD'                : 0.00253,
                                              'LQ'                : 0.00253,
                                              'BEMF_CONST'        : 44.38,
                                              'POLE_PAIRS'        : 5,
                                              'RATED_SPEED'       : 3000,
                                              'MAX_SPEED'         : 5000,
                                              'MAX_FW_CURRENT'    : -2.0,
                                              'QE_PULSES_PER_REV' : 2500,
                                              'MAX_MOTOR_CURRENT' : 4.0 ,
                                              'MOTOR_CONNECTION'  : "STAR",
                                            },
                          }

#----------------------------------------------------------------------------------#
#                             MOTOR CLASS  FUNCTIONS                               # 
#----------------------------------------------------------------------------------#

def mcMot_CreateMHCSymbols( mcPmsmFocComponent ):
    '''
        Motor Parameters symbol structure 
                                    
    '''
    # Root Node symbol
    mcMot_RootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_MOTOR_CONF", None)
    mcMot_RootNode.setLabel("Motor Parameters")

    # Motor selection symbol
    global mcMot_SelectedMotor
    mcMot_SelectedMotor = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_SEL", mcMot_RootNode )
    mcMot_SelectedMotor.setLabel("Select Motor")
    mcMot_SelectedMotor.addKey("CUSTOM", "0", "Custom")
    mcMot_SelectedMotor.addKey("LONG_HURST", "1", "Hurst DMA0204024B101 (with Hall, with Quadrature Encoder) (LV)")
    mcMot_SelectedMotor.addKey("SMALL_HURST", "2", "Hurst DMB0224C10002 (with Hall, without Quadrature Encoder)  (LV)")
    mcMot_SelectedMotor.addKey("LEADSHINE", "3", "Leadshine EL5-M0400-1-24 (with Hall, with Quadrature Encoder)  (HV)")
    mcMot_SelectedMotor.setOutputMode("Key")
    mcMot_SelectedMotor.setDisplayMode("Description")
    mcMot_SelectedMotor.setDefaultValue(1)   # Long hurst

    # Motor connection type symbol
    global mcMot_WindingConnection
    mcMot_WindingConnection = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_MOTOR_CONNECTION", mcMot_SelectedMotor)
    mcMot_WindingConnection.setLabel("Motor Connection")
    mcMot_WindingConnection.addKey("STAR", "0", "STAR")
    mcMot_WindingConnection.addKey("DELTA", "1", "DELTA")
    mcMot_WindingConnection.setOutputMode("Key")
    mcMot_WindingConnection.setDisplayMode("Description")
    mcMot_WindingConnection.setSelectedKey(mcMotC_DefaultPararameterDict['LONG_HURST']['MOTOR_CONNECTION'])
        
    # Motor line-line resistance 
    global mcMot_ResistanceInOhm
    mcMot_ResistanceInOhm = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_R", mcMot_SelectedMotor)
    mcMot_ResistanceInOhm.setLabel("Phase Resistance (ohms)")
    mcMot_ResistanceInOhm.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['R']))

    # Motor direct axis inductance 
    global mcMot_DaxisInductanceInHenry
    mcMot_DaxisInductanceInHenry = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LD", mcMot_SelectedMotor)
    mcMot_DaxisInductanceInHenry.setLabel("Phase Direct Axis Inductance Ld (Henry)")
    mcMot_DaxisInductanceInHenry.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['LD']))

    # Motor quadrature axis inductance 
    global mcMot_QaxisInductanceInHenry
    mcMot_QaxisInductanceInHenry = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LQ", mcMot_SelectedMotor)
    mcMot_QaxisInductanceInHenry.setLabel("Phase Quadrature Axis Inductance Lq (Henry)")
    mcMot_QaxisInductanceInHenry.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['LQ']))

    # Motor pole pairs
    global mcMot_NumberOfPolePairs
    mcMot_NumberOfPolePairs = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_POLE_PAIRS", mcMot_SelectedMotor)
    mcMot_NumberOfPolePairs.setLabel("Motor Pole Pairs")
    mcMot_NumberOfPolePairs.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['POLE_PAIRS']))
        
    # Motor back emf constant
    global mcMot_BemfConstantInVppPerKrpm
    mcMot_BemfConstantInVppPerKrpm = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_BEMF_CONST", mcMot_SelectedMotor)
    mcMot_BemfConstantInVppPerKrpm.setLabel("Motor BEMF Constant (Vpk L-L/KRPM)")
    mcMot_BemfConstantInVppPerKrpm.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['BEMF_CONST']))

    # Motor rated speed 
    global mcMot_RatedSpeedInRpm
    mcMot_RatedSpeedInRpm = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_RATED_SPEED", mcMot_SelectedMotor)
    mcMot_RatedSpeedInRpm.setLabel("Motor Rated Speed (RPM)")
    mcMot_RatedSpeedInRpm.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['RATED_SPEED']))
        
    # Motor maximum speed 
    global mcMot_MaximumSpeedInRpm
    mcMot_MaximumSpeedInRpm = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_SPEED", mcMot_SelectedMotor)
    mcMot_MaximumSpeedInRpm.setLabel("Motor Max Speed (RPM)")
    mcMot_MaximumSpeedInRpm.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['MAX_SPEED']))

    # Motor maximum current
    global mcMot_MaximumCurrentInAmps  
    mcMot_MaximumCurrentInAmps = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_MOTOR_CURRENT", mcMot_SelectedMotor)
    mcMot_MaximumCurrentInAmps.setLabel("Max Motor Current (A)")
    mcMot_MaximumCurrentInAmps.setDefaultValue(float(mcMotC_DefaultPararameterDict['LONG_HURST']['MAX_MOTOR_CURRENT']))

    # Initialize callback functions 
    global mcMot_MotorDependency
    mcMot_MotorDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_MOTOR_PARAMS", mcMot_SelectedMotor)
    mcMot_MotorDependency.setVisible(False)
    mcMot_MotorDependency.setDependencies( mcMot_SymbolUpdate, ["MCPMSMFOC_MOTOR_SEL"])
 

def mcMot_SymbolUpdate( symbol, event ):
    motor = event["symbol"].getKeyForValue(str(event["value"]))
    if motor in mcMotC_DefaultPararameterDict.keys():
        mcMot_ResistanceInOhm.setValue( float( mcMotC_DefaultPararameterDict[motor]['R'] ))
        mcMot_DaxisInductanceInHenry.setValue( float( mcMotC_DefaultPararameterDict[motor]['LD'] ))
        mcMot_QaxisInductanceInHenry.setValue( float( mcMotC_DefaultPararameterDict[motor]['LQ' ] ))
        mcMot_BemfConstantInVppPerKrpm.setValue( float( mcMotC_DefaultPararameterDict[motor]['BEMF_CONST' ] ))
        mcMot_NumberOfPolePairs.setValue( float( mcMotC_DefaultPararameterDict[motor]['POLE_PAIRS' ] ))
        mcMot_RatedSpeedInRpm.setValue( float( mcMotC_DefaultPararameterDict[motor]['RATED_SPEED' ] ))
        mcMot_MaximumSpeedInRpm.setValue( float( mcMotC_DefaultPararameterDict[motor]['MAX_SPEED' ] ))
        mcMot_MaximumCurrentInAmps.setValue( float( mcMotC_DefaultPararameterDict[motor]['MAX_MOTOR_CURRENT' ] ))
        mcMot_WindingConnection.setSelectedKey(  mcMotC_DefaultPararameterDict[motor]['MOTOR_CONNECTION'])

def mcMotI_MotorParameters( mcPmsmFocComponent ):
    
    # Create MHC symbols for Motor parameters 
    mcMot_CreateMHCSymbols( mcPmsmFocComponent)



