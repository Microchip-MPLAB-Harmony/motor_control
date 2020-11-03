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
* File Name: mcPmsmFoc_DigitalInterfaceClass.py
*
* Description:
* The file comprises of back-end code for digital interface block.
*
*****************************************************************************"""

#----------------------------------------------------------------------------------#
#                               GLOBAL VARIABLES                                   # 
#----------------------------------------------------------------------------------#
#Encoder dictionary used to send message to Encoder plib
encoderDict = {}

#----------------------------------------------------------------------------------#
#                               SUPPORTED BOARDS                                   # 
#----------------------------------------------------------------------------------#
mcPosI_DefaultPararameterDict = {
                                 'LONG_HURST' : { 
                                                   'QE_PULSES_PER_REV' : 250,
                                                },
                                 'SMALL_HURST': { 
                                                   'QE_PULSES_PER_REV' : 0,
                                                },
                                 'LEADSHINE' :  { 
                                                   'QE_PULSES_PER_REV' : 2500,
                                                },
                                }


#----------------------------------------------------------------------------------#
#                          POSITION INTERFACE FUNCTIONS                            # 
#----------------------------------------------------------------------------------#
      
def mcPoI_CreateMHCSymbols( mcPmsmFocComponent ):
    mcPoI_RootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_ENCODER", mcPoM_AlgorithmSelection)
    mcPoI_RootNode.setLabel("Encoder Configurations")
    mcPoI_RootNode.setVisible(False)
    mcPoI_RootNode.setDependencies( mcPmsmFocEncoderVisible, ["MCPMSMFOC_POSITION_FB"])
    
    #ToDo: Place in appropriate file
    global mcPoI_PulsedPerRevolution
    mcPoI_PulsedPerRevolution = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_QE_PULSES_PER_REV", mcPoI_RootNode)
    mcPoI_PulsedPerRevolution.setLabel("Encoder Pulses Per Revolution")
    mcPoI_PulsedPerRevolution.setVisible(True)
    mcPoI_PulsedPerRevolution.setMin(0)
    mcPoI_PulsedPerRevolution.setDefaultValue(int(mcPosI_DefaultPararameterDict['LONG_HURST']['QE_PULSES_PER_REV']))

    # Encoder PLIB
    global mcPoI_EncoderPLib
    mcPoI_EncoderPLib = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_ENCODERPLIB", None)
    mcPoI_EncoderPLib.setVisible(False)

    # Initilaize callback functions for board dependency
    mcPoI_BoardDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_ENCODER_BOARD_DEP", None)
    mcPoI_BoardDependency.setVisible(False)
    mcPoI_BoardDependency.setDependencies( mcPoI_UpdateSymbols, ["MCPMSMFOC_MOTOR_SEL"])
            
    # Initialize callback functions 
    mcPoI_Dependency = mcPmsmFocComponent.createIntegerSymbol("MCPMSMFOC_ENCODER_DEP", None)
    mcPoI_Dependency.setVisible(False)
    mcPoI_Dependency.setDependencies( mcPmsmFocEncoderPlibDep, ["MCPMSMFOC_QE_PULSES_PER_REV"])
   

def mcPoI_UpdateSymbols( symbol, event ):
    motor = event["symbol"].getKeyForValue(str(event["value"]))
    if motor in mcPosI_DefaultPararameterDict.keys():
        mcPoI_PulsedPerRevolution.setValue(mcPosI_DefaultPararameterDict[motor]['QE_PULSES_PER_REV'])

def mcPmsmFocEncoderVisible( symbol, event):
    component = symbol.getComponent()
    if(event["value"] == 1):
        symbol.setVisible(False)
        component.setDependencyEnabled("pmsmfoc_QDEC", True)
        symbol.setVisible(True)
    else:
        symbol.setVisible(True)
        component.setDependencyEnabled("pmsmfoc_QDEC", False)
        symbol.setVisible(False)

#Send message to Encoder PLIB when encoder configurations are changed
def mcPmsmFocEncoderPlibDep(symbol, event ):
    component = symbol.getComponent()
    pulses = (float(component.getSymbolValue("MCPMSMFOC_QE_PULSES_PER_REV")) * 4) / component.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
    encoderDict['PULSES_PER_REV'] = pulses
    Database.sendMessage(mcPoI_EncoderPLib.getValue().lower(), "PMSM_FOC_ENCODER_CONF", encoderDict)

def mcPosI_OnAttachmentConnected( source, target): 
    localComponent = source["component"]
    remoteComponent = target["component"]
    remoteID = remoteComponent.getID()
    connectID = source["id"]
    
    pulses = (float(localComponent.getSymbolValue("MCPMSMFOC_QE_PULSES_PER_REV")) * 4) / localComponent.getSymbolValue("MCPMSMFOC_POLE_PAIRS")
    encoderDict['PULSES_PER_REV'] = pulses

    if (connectID == "pmsmfoc_QDEC"):
        Database.sendMessage(remoteID, "PMSM_FOC_ENCODER_CONF", encoderDict)
        mcPoI_EncoderPLib.setValue(remoteID)

        if mcPmsmFocSeries.getValue() == "SAME54":
            Database.setSymbolValue("pdec", "PDEC_FILTER", 0)


            
            
def mcPosI_OnAttachmentDisconnected( source, target):
    if (source["id"] == "pmsmfoc_QDEC"):
        mcPoI_EncoderPLib.setValue("None")


def mcPoII_PositionInterface( mcPmsmFocComponent ):
    mcPoI_CreateMHCSymbols( mcPmsmFocComponent )
