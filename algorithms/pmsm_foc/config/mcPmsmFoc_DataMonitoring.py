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
* File Name: mcPmsmFoc_DataMonitoring.py
*
* Description:
* The file comprises of back-end code for data monitoring block.
*
*****************************************************************************"""
#----------------------------------------------------------------------------------#
#                               GLOBAL VARIABLES                                   # 
#----------------------------------------------------------------------------------#

#----------------------------------------------------------------------------------#
#                           SUPPORTED MOTOR PARAMETERS                             # 
#----------------------------------------------------------------------------------#

def mcDaM_CreateMHCSymbols( mcPmsmFocComponent ):
    global mcPmsmFocX2CScope
    mcPmsmFocX2CScope = mcPmsmFocComponent.createStringSymbol("MCPMSMFOC_X2CScope", None)
    mcPmsmFocX2CScope.setVisible(False)

def mcDaMI_OnAttachmentConnected( source, target ):
    if (source["id"] == "pmsmfoc_X2CSCOPE"):
        mcPmsmFocX2CScope.setValue( target["component"].getID())

def mcDaMI_OnAttachmentDisconnected( source, target ):
    if (source["id"] == "pmsmfoc_X2CSCOPE"):
        mcPmsmFocX2CScope.setValue("None")

def mcDaMI_DataMonitoring( mcPmsmFocComponent ):
    mcDaM_CreateMHCSymbols( mcPmsmFocComponent )


 