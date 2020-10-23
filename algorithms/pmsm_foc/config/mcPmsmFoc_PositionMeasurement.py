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


#----------------------------------------------------------------------------------#
#                               SUPPORTED BOARDS                                   # 
#----------------------------------------------------------------------------------#


#----------------------------------------------------------------------------------#
#                          POSITION INTERFACE FUNCTIONS                            # 
#----------------------------------------------------------------------------------#
def mcPoM_CreateMHCSymbols( mcPmsmFocComponent ):

    
    global mcPoM_AlgorithmSelection
    mcPoM_AlgorithmSelection = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_POSITION_FB", mcPmsmFocAlgoMenu)
    mcPoM_AlgorithmSelection.setLabel("Select Position Feedback")
    mcPoM_AlgorithmSelection.addKey("SENSORLESS_PLL", "0", "SENSORLESS - PLL Estimator")
    mcPoM_AlgorithmSelection.addKey("SENSORED_ENCODER", "1", "SENSOR - Quadrature Encoder")
    #mcPoM_AlgorithmSelection.addKey("SENSORLESS_ROLO", "1", "SENSORLESS - Luenberger Observer")
    #mcPoM_AlgorithmSelection.addKey("SENSORLESS_SMO", "2", "SENSORLESS - Sliding Mode Observer")
    mcPoM_AlgorithmSelection.setOutputMode("Key")
    mcPoM_AlgorithmSelection.setDisplayMode("Description")


def mcPoMI_PositionMeasurement( mcPmsmFocComponent ):
    mcPoM_CreateMHCSymbols( mcPmsmFocComponent )
    