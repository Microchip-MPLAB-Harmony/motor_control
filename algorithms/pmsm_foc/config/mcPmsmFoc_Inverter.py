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
                                             'DC_BUS_RATIO'         : 0.0625,
                                           },
                                'MCHV3' :  { 'MAX_CURRENT'          : 16.4,
                                             'DC_BUS_VOLT'          : 400,
                                             'DC_BUS_RATIO'         : 0.00766,
                                           }
                          }

mcVsi_DefaultBoard = 'MCLV2'

#----------------------------------------------------------------------------------#
#                             INVERTER CLASS FUNCTIONS                             # 
#----------------------------------------------------------------------------------#

def mcVsi_CreateMHCSymbols( mcPmsmFocComponent ):


    # Symbol for maximum inverter current
    global mcVsi_MaximumCurrentInAmpsRms
    mcVsi_MaximumCurrentInAmpsRms = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_MAX_CURRENT", mcVsi_SelectedBoard)
    mcVsi_MaximumCurrentInAmpsRms.setLabel("Max Board Current (A)")
    mcVsi_MaximumCurrentInAmpsRms.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['MAX_CURRENT']))

    # Symbol for DC link voltage 
    global mcVsi_DcLinkVoltageInVolts
    mcVsi_DcLinkVoltageInVolts = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_VOLT", mcVsi_SelectedBoard)
    mcVsi_DcLinkVoltageInVolts.setLabel("DC Bus Voltage (V)")
    mcVsi_DcLinkVoltageInVolts.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['DC_BUS_VOLT']))

    # Symbol for voltage conversion factor 
    global mcVsi_DcBusDividerRatio
    mcVsi_DcBusDividerRatio = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_DC_BUS_RATIO", mcVsi_SelectedBoard)
    mcVsi_DcBusDividerRatio.setLabel("DC Bus Voltage Divider Ratio")
    mcVsi_DcBusDividerRatio.setDefaultValue(float(mcVsi_DefaultPararameterDict[mcVsi_DefaultBoard]['DC_BUS_RATIO']))

    # Initialize callback function to update board parameters 
    mcVsi_BoardDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_INVERTER_MENU", mcVsi_SelectedBoard )
    mcVsi_BoardDependency.setVisible(False)
    mcVsi_BoardDependency.setDependencies(mcVsi_UpdateSymbols, ["MCPMSMFOC_BOARD_SEL"])
            
# Callback Functions 
def mcVsi_UpdateSymbols( symbol, event):
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    if board_key in mcVsi_DefaultPararameterDict.keys():
        mcVsi_MaximumCurrentInAmpsRms.setValue(float(mcVsi_DefaultPararameterDict[board_key]['MAX_CURRENT']))
        mcVsi_DcLinkVoltageInVolts.setValue(float(mcVsi_DefaultPararameterDict[board_key]['DC_BUS_VOLT']))
        mcVsi_DcBusDividerRatio.setValue(float(mcVsi_DefaultPararameterDict[board_key]['DC_BUS_RATIO']))

def mcVsiI_VoltageSourceInverter( mcPmsmFocComponent):
    #Create MHC symbols for voltage source inverter block 
    mcVsi_CreateMHCSymbols( mcPmsmFocComponent )


    