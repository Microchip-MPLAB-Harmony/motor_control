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
* File Name: mcPmsmFoc_Startup.py
*
* Description:
* The file comprises of back-end code for motor startup.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                             GLOBAL VARIABLES                                     # 
#----------------------------------------------------------------------------------#



#----------------------------------------------------------------------------------#
#                               CallBack Functions                                 #
#----------------------------------------------------------------------------------#



    
#----------------------------------------------------------------------------------#
#                             STARTUP CLASS FUNCTIONS                             # 
#----------------------------------------------------------------------------------#

def mcStC_CreateMHCSymbols( mcPmsmFocComponent):
    mcStC_RootNode = mcPmsmFocComponent.createMenuSymbol("MCPMSMFOC_STARTUP", mcPmsmFocCtrlMenu)
    mcStC_RootNode.setLabel("Startup Parameters")

    if((("SAMC21" not in Variables.get("__PROCESSOR")) and ("PIC32CM" not in Variables.get("__PROCESSOR")))):
        mcFlyingStart_CreateMHCSymbols(mcPmsmFocComponent, mcStC_RootNode)

    mcStC_ForceAlignAxis = mcPmsmFocComponent.createKeyValueSetSymbol("MCPMSMFOC_ALIGNMENT", mcStC_RootNode)
    mcStC_ForceAlignAxis.setLabel("Select Alignment Axis")
    mcStC_ForceAlignAxis.addKey("Q_AXIS", "0", "Q Axis")
    mcStC_ForceAlignAxis.addKey("D_AXIS", "1", "D Axis")
    #mcStC_ForceAlignAxis.addKey("IPD", "2", "Initial Position Detection")
    mcStC_ForceAlignAxis.setOutputMode("Key")
    mcStC_ForceAlignAxis.setDisplayMode("Description")

    mcStC_AlignmentTime = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_LOCK_TIME", mcStC_RootNode)
    mcStC_AlignmentTime.setLabel("Alignment Lock Time (sec)")
    mcStC_AlignmentTime.setDefaultValue(2)

    mcStC_OpenLoopRampTime = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_RAMP_TIME", mcStC_RootNode)
    mcStC_OpenLoopRampTime.setLabel("Open Loop Ramp Time (sec)")
    mcStC_OpenLoopRampTime.setDefaultValue(5)
    #mcStC_OpenLoopRampTime.setDependencies(mcPmsmFocEncoderHide, ["MCPMSMFOC_POSITION_FB"])

    mcStC_OpenLoopEndSpeed = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_END_SPEED", mcStC_RootNode)
    mcStC_OpenLoopEndSpeed.setLabel("Open Loop End Speed (RPM)")
    mcStC_OpenLoopEndSpeed.setDefaultValue(500)
    #mcStC_OpenLoopEndSpeed.setDependencies(mcPmsmFocEncoderHide, ["MCPMSMFOC_POSITION_FB"])
        
    mcStC_OpenLoopRefCurrent = mcPmsmFocComponent.createFloatSymbol("MCPMSMFOC_OL_IQ_REF", mcStC_RootNode)
    mcStC_OpenLoopRefCurrent.setLabel("Open Loop Ref Quadrature Current (A)")
    mcStC_OpenLoopRefCurrent.setDefaultValue(0.4)

def mcPmsmFocEncoderHide(symbol, event):
    symObj = event["symbol"]
    key = symObj.getSelectedKey()
    if(key == "SENSORED_ENCODER"):
        symbol.setVisible(False)
    else:
        symbol.setVisible(True)


def mcStCI_StartupConfigurator( mcPmsmFocComponent ):
    # Create MHC Symbols 
    mcStC_CreateMHCSymbols( mcPmsmFocComponent )