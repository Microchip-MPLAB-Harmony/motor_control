/*******************************************************************************
   Key manager header file

  Company:
    Microchip Technology Inc.

  File Name:
    mc_key_manager.h

  Summary:
   Key manager header file

  Description:
   Key manager header file
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
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
*******************************************************************************/
// DOM-IGNORE-END

#ifndef MCKEY_H    // Guards against multiple inclusion
#define MCKEY_H

/*******************************************************************************
 Header files inclusions
 *******************************************************************************/
#include "mc_types.h"

/*******************************************************************************
Data-types
 *******************************************************************************/
typedef enum
{
    KEY_IPD,
    KEY_ZSMT,
    KEY_MAX
}tmcKey_IPs_s;

typedef struct
{
    char Keys[KEY_MAX][32u];
}tmcKey_Keys_s;

/*******************************************************************************
 * Interface variables
 *******************************************************************************/
extern tmcKey_Keys_s mcKeyI_AlgorithmKeys_gds;

/*******************************************************************************
 Interface Functions
 *******************************************************************************/
/*! \brief Get algorithms key
 *
 * Details.
 * Get algorithms key
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__attribute__((noinline)) char * mcKeyI_ValidationKeyGet( const tmcKey_IPs_s ip);

/*! \brief Algorithms key initialization
 *
 * Details.
 * Algorithms key initialization
 *
 * @param[in]:
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcKeyI_KeyManagerInit(void);

#endif //MCKEY_H

/**
 End of File
*/
