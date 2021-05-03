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
* File Name: mcPmsmFoc_InvereterClass.py
*
* Description:
* The file comprises of back-end code for VSI block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                             GLOBAL VARIABLES                                     # 
#----------------------------------------------------------------------------------#

#----------------------------------------------------------------------------------#
#                        SUPPORTED MOTOR PARAMETERS                                # 
#----------------------------------------------------------------------------------#

#Board parameters
mcVsi_DefaultPararameterDict = {'MCLV2' :  { 'MAX_CURRENT'          : 4.4,
                                             'DC_BUS_VOLT'          : 24,
                                             'DC_BUS_RTOP'          : 30.0,
                                             'DC_BUS_RBOTTOM'       : 2.0,
                                             'DC_BUS_RATIO'         : 0.0625,
                                             'OPAMP_GAIN'           : 15,
                                             'OPAMP_OFFSET'         : 1.65,
                                             'OPAMP_SHUNT_R'        : 0.025
                                           },
                                'MCHV3' :  { 'MAX_CURRENT'          : 16.4,
                                             'DC_BUS_VOLT'          : 400,
                                             'DC_BUS_RTOP'          : 285.0,
                                             'DC_BUS_RBOTTOM'       : 2.2,                                             
                                             'DC_BUS_RATIO'         : 0.00766,
                                             'OPAMP_GAIN'           : 10.06,
                                             'OPAMP_OFFSET'         : 1.65,
                                             'OPAMP_SHUNT_R'        : 0.01                                             
                                           }
                          }

mcVsi_DefaultBoard = 'MCLV2'

#----------------------------------------------------------------------------------#
#                             INVERTER CLASS FUNCTIONS                             # 
#----------------------------------------------------------------------------------#

def mcVsi_CreateMHCSymbols( mcPmsmFocComponent ):
   
    # Symbol for DC link voltage 
    global mcVsi_DcLinkVoltageInVolts
    mcVsi_DcLinkVoltageInVolts = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_VOLT", mcVsi_SelectedBoard)
    mcVsi_DcLinkVoltageInVolts.setLabel("DC Bus Voltage (V)")
    mcVsi_DcLinkVoltageInVolts.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['DC_BUS_VOLT']))

    global mcVsi_DcBusTopResistor
    mcVsi_DcBusTopResistor = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_RTOP", mcVsi_SelectedBoard)
    mcVsi_DcBusTopResistor.setLabel("DC Bus Top Resistor (ohm)")
    mcVsi_DcBusTopResistor.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['DC_BUS_RTOP']))    

    global mcVsi_DcBusBottomResistor
    mcVsi_DcBusBottomResistor = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_RBOTTOM", mcVsi_SelectedBoard)
    mcVsi_DcBusBottomResistor.setLabel("DC Bus Bottom Resistor (ohm)")    
    mcVsi_DcBusBottomResistor.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['DC_BUS_RBOTTOM']))

    # Symbol for voltage conversion factor 
    global mcVsi_DcBusDividerRatio
    mcVsi_DcBusDividerRatio = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_RATIO", mcVsi_SelectedBoard)
    mcVsi_DcBusDividerRatio.setLabel("DC Bus Voltage Divider Ratio")
    mcVsi_DcBusDividerRatio.setReadOnly(True)
    mcVsi_DcBusDividerRatio.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['DC_BUS_RATIO']))
    mcVsi_DcBusDividerRatio.setDependencies(mcPmsmFocVoltDivRatio, ["MCPMSMFOC_DC_BUS_RTOP", "MCPMSMFOC_DC_BUS_RBOTTOM"])

    mcVsi_PhaseUCurrent = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_IU", mcVsi_SelectedBoard)
    mcVsi_PhaseUCurrent.setLabel("Phase U Current OPAMP")

    opampSel = ["EXTERNAL OPAMP", "INTERNAL OPAMP"]
    mcVsi_IuOpamp = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_IU_OPAMP", mcVsi_PhaseUCurrent, opampSel)
    mcVsi_IuOpamp.setLabel("Phase U Current OPAMP")
    mcVsi_IuOpamp.setReadOnly(True)

    global mcVsi_IuOpampGain
    mcVsi_IuOpampGain = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IU_OPAMP_GAIN", mcVsi_PhaseUCurrent)
    mcVsi_IuOpampGain.setLabel("Phase U Current OPAMP Gain")
    mcVsi_IuOpampGain.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['OPAMP_GAIN']))    

    global mcVsi_IuOpampOffset
    mcVsi_IuOpampOffset = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IU_OPAMP_OFFSET", mcVsi_PhaseUCurrent)
    mcVsi_IuOpampOffset.setLabel("Phase U Current OPAMP Offset")
    mcVsi_IuOpampOffset.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['OPAMP_OFFSET']))        

    global mcVsi_IuOpampShuntR
    mcVsi_IuOpampShuntR = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IU_OPAMP_SHUNT_R", mcVsi_PhaseUCurrent)
    mcVsi_IuOpampShuntR.setLabel("Phase U Current OPAMP Shunt R (ohm)")
    mcVsi_IuOpampShuntR.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['OPAMP_SHUNT_R']))

    mcVsi_PhaseVCurrent = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_IV", mcVsi_SelectedBoard)
    mcVsi_PhaseVCurrent.setLabel("Phase V Current OPAMP")

    opampSel = ["EXTERNAL OPAMP", "INTERNAL OPAMP"]
    mcVsi_IvOpamp = mcPmsmFocComponent.createComboSymbol("MCPMSMFOC_IV_OPAMP", mcVsi_PhaseVCurrent, opampSel)
    mcVsi_IvOpamp.setLabel("Phase V Current OPAMP")
    mcVsi_IvOpamp.setReadOnly(True)    

    global mcVsi_IvOpampGain
    mcVsi_IvOpampGain = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IV_OPAMP_GAIN", mcVsi_PhaseVCurrent)
    mcVsi_IvOpampGain.setLabel("Phase V Current OPAMP Gain")
    mcVsi_IvOpampGain.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['OPAMP_GAIN']))        

    global mcVsi_IvOpampOffset
    mcVsi_IvOpampOffset = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IV_OPAMP_OFFSET", mcVsi_PhaseVCurrent)
    mcVsi_IvOpampOffset.setLabel("Phase V Current OPAMP Offset")
    mcVsi_IvOpampOffset.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['OPAMP_OFFSET']))        

    global mcVsi_IvOpampShuntR
    mcVsi_IvOpampShuntR = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_IV_OPAMP_SHUNT_R", mcVsi_PhaseVCurrent)
    mcVsi_IvOpampShuntR.setLabel("Phase V Current OPAMP Shunt R (ohm)")
    mcVsi_IvOpampShuntR.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['OPAMP_SHUNT_R']))

    # Symbol for maximum inverter current
    global mcVsi_MaximumCurrentInAmpsRms
    mcVsi_MaximumCurrentInAmpsRms = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_CURRENT", mcVsi_SelectedBoard)
    mcVsi_MaximumCurrentInAmpsRms.setLabel("Max Board Current (A)")
    mcVsi_MaximumCurrentInAmpsRms.setReadOnly(True)
    mcVsi_MaximumCurrentInAmpsRms.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['MAX_CURRENT']))
    mcVsi_MaximumCurrentInAmpsRms.setDependencies(mcPmsmFocBoardCurrent, ["MCPMSMFOC_IU_OPAMP_GAIN", "MCPMSMFOC_IU_OPAMP_OFFSET", "MCPMSMFOC_IU_OPAMP_SHUNT_R"])

    # Initialize callback function to update board parameters 
    mcVsi_BoardDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_INVERTER_MENU", mcVsi_SelectedBoard )
    mcVsi_BoardDependency.setVisible(False)
    mcVsi_BoardDependency.setDependencies(mcVsi_UpdateSymbols, ["MCPMSMFOC_BOARD_SEL"])
            
# Callback Functions 
def mcVsi_UpdateSymbols( symbol, event):
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    if board_key in mcVsi_DefaultPararameterDict.keys():
        #mcVsi_MaximumCurrentInAmpsRms.setValue(float(mcVsi_DefaultPararameterDict[board_key]['MAX_CURRENT']))
        mcVsi_DcLinkVoltageInVolts.setValue(float(mcVsi_DefaultPararameterDict[board_key]['DC_BUS_VOLT']))
        #mcVsi_DcBusDividerRatio.setValue(float(mcVsi_DefaultPararameterDict[board_key]['DC_BUS_RATIO']))
        mcVsi_DcBusTopResistor.setValue(float(mcVsi_DefaultPararameterDict[board_key]['DC_BUS_RTOP']))
        mcVsi_DcBusBottomResistor.setValue(float(mcVsi_DefaultPararameterDict[board_key]['DC_BUS_RBOTTOM']))
        mcVsi_IuOpampGain.setValue(float(mcVsi_DefaultPararameterDict[board_key]['OPAMP_GAIN']))
        mcVsi_IuOpampOffset.setValue(float(mcVsi_DefaultPararameterDict[board_key]['OPAMP_OFFSET']))
        mcVsi_IuOpampShuntR.setValue(float(mcVsi_DefaultPararameterDict[board_key]['OPAMP_SHUNT_R']))
        mcVsi_IvOpampGain.setValue(float(mcVsi_DefaultPararameterDict[board_key]['OPAMP_GAIN']))
        mcVsi_IvOpampOffset.setValue(float(mcVsi_DefaultPararameterDict[board_key]['OPAMP_OFFSET']))
        mcVsi_IvOpampShuntR.setValue(float(mcVsi_DefaultPararameterDict[board_key]['OPAMP_SHUNT_R']))        
        mcVsi_CurrentSenseResitor.setValue(float(mcVsi_DefaultPararameterDict[board_key]['SHUNT_RESISTANCE']))
        mcVsi_CurrentSenseGain.setValue(float(mcVsi_DefaultPararameterDict[board_key]['CURRENT_AMPLIFIER_GAIN']))

def mcPmsmFocVoltDivRatio(symbol, event):
    topR = mcVsi_DcBusTopResistor.getValue()
    bottomR = mcVsi_DcBusBottomResistor.getValue()
    ratio = (bottomR / (bottomR + topR))
    symbol.setValue(ratio)

def mcPmsmFocBoardCurrent(symbol, event):
    current = (3.3 - mcVsi_IuOpampOffset.getValue()) /(mcVsi_IuOpampGain.getValue() * mcVsi_IuOpampShuntR.getValue())
    symbol.setValue(current)

def mcVsiI_VoltageSourceInverter( mcPmsmFocComponent):
    #Create MHC symbols for voltage source inverter block 
    mcVsi_CreateMHCSymbols( mcPmsmFocComponent )


    