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
* File Name: mcPmsmFoc_PositionMeasurementClass.py
*
* Description:
* The file comprises of back-end code for digital interface block.
*
*****************************************************************************"""

#----------------------------------------------------------------------------------#
#                               GLOBAL VARIABLES                                   # 
#----------------------------------------------------------------------------------#

#Board parameters
mcPoM_DefaultPararameterDict = {'MCLV2' :  { 'PLL_ED_FILTER'          : 0.0183,
                                             'PLL_EQ_FILTER'          : 0.0183,
                                             'PLL_SPEED_FILTER'       : 0.0053,
                                           },
                                'MCHV3' :  { 'PLL_ED_FILTER'          : 0.122,
                                             'PLL_EQ_FILTER'          : 0.122,
                                             'PLL_SPEED_FILTER'       : 0.122,                                         
                                           }
                          }

mcPoM_DefaultBoard = 'MCLV2'
#----------------------------------------------------------------------------------#
#                               SUPPORTED BOARDS                                   # 
#----------------------------------------------------------------------------------#


#----------------------------------------------------------------------------------#
#                          POSITION INTERFACE FUNCTIONS                            # 
#----------------------------------------------------------------------------------#
def mcPoM_CreateMHCSymbols( mcPmsmFocComponent ):

    processor = Variables.get("__PROCESSOR") 

    global mcPoM_AlgorithmSelection
    mcPoM_AlgorithmSelection = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_POSITION_FB", mcPmsmFocAlgoMenu)
    mcPoM_AlgorithmSelection.setLabel("Select Position Feedback")
    if (("SAMC21" in processor) or all(x in processor for x in ["PIC32CM", "MC"])):
        mcPoM_AlgorithmSelection.addKey("SENSORLESS_ROLO", "0", "SENSORLESS - Luenberger Observer")    
    else:
        mcPoM_AlgorithmSelection.addKey("SENSORLESS_PLL", "0", "SENSORLESS - PLL Estimator")
        mcPoM_AlgorithmSelection.addKey("SENSORED_ENCODER", "1", "SENSOR - Quadrature Encoder")
        #mcPoM_AlgorithmSelection.addKey("SENSORLESS_ROLO", "1", "SENSORLESS - Luenberger Observer")
        #mcPoM_AlgorithmSelection.addKey("SENSORLESS_SMO", "2", "SENSORLESS - Sliding Mode Observer")
    mcPoM_AlgorithmSelection.setOutputMode("Key")
    mcPoM_AlgorithmSelection.setDisplayMode("Description")

    # PLL Paramaeters
    mcPoM_PLL = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_PLL", None)
    mcPoM_PLL.setLabel("PLL Configurations")
    mcPoM_PLL.setDependencies(mcPmsmFocPLLVisible, ["MCPMSMFOC_POSITION_FB"])

    global mcPoM_PLLEqFilter
    mcPoM_PLLEqFilter = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_PLL_EQ_FILTER", mcPoM_PLL)
    mcPoM_PLLEqFilter.setLabel("Eq Filter")
    mcPoM_PLLEqFilter.setMin(0)
    mcPoM_PLLEqFilter.setMax(1)
    mcPoM_PLLEqFilter.setDefaultValue(mcPoM_DefaultPararameterDict[mcPoM_DefaultBoard]['PLL_EQ_FILTER'])

    global mcPoM_PLLEdFilter
    mcPoM_PLLEdFilter = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_PLL_ED_FILTER", mcPoM_PLL)
    mcPoM_PLLEdFilter.setLabel("Ed Filter")
    mcPoM_PLLEdFilter.setMin(0)
    mcPoM_PLLEdFilter.setMax(1)    
    mcPoM_PLLEdFilter.setDefaultValue(mcPoM_DefaultPararameterDict[mcPoM_DefaultBoard]['PLL_ED_FILTER'])

    global mcPoM_PLLSpeedFilter
    mcPoM_PLLSpeedFilter = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_PLL_SPEED_FILTER", mcPoM_PLL)
    mcPoM_PLLSpeedFilter.setLabel("Speed Filter")
    mcPoM_PLLSpeedFilter.setMin(0)
    mcPoM_PLLSpeedFilter.setMax(1)    
    mcPoM_PLLSpeedFilter.setDefaultValue(mcPoM_DefaultPararameterDict[mcPoM_DefaultBoard]['PLL_SPEED_FILTER'])

    # Initialize callback function to update board parameters 
    mcPoM_BoardDependency = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_POSITION_MENU", None )
    mcPoM_BoardDependency.setVisible(False)
    mcPoM_BoardDependency.setDependencies(mcPom_UpdateSymbols, ["MCPMSMFOC_BOARD_SEL"])
            
# Callback Functions 
def mcPom_UpdateSymbols( symbol, event):
    board_key = event["symbol"].getKeyForValue(str(event["value"]))
    if board_key in mcVsi_DefaultPararameterDict.keys():
        mcPoM_PLLEqFilter.setValue(float(mcPoM_DefaultPararameterDict[board_key]['PLL_EQ_FILTER']))
        mcPoM_PLLEdFilter.setValue(float(mcPoM_DefaultPararameterDict[board_key]['PLL_ED_FILTER']))
        mcPoM_PLLSpeedFilter.setValue(float(mcPoM_DefaultPararameterDict[board_key]['PLL_SPEED_FILTER']))


def mcPmsmFocPLLVisible(symbol, event):
    symObj = event["symbol"]
    if symObj.getSelectedKey() == "SENSORLESS_PLL":
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)


def mcPoMI_PositionMeasurement( mcPmsmFocComponent ):
    mcPoM_CreateMHCSymbols( mcPmsmFocComponent )
    