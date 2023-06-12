/*******************************************************************************
 Key Manager source file

  Company:
  Microchip Technology Inc.

  File Name:
  mc_key_manager.c

  Summary:
  Key manager source file

  Description:
  Key manager source file

 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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


/*******************************************************************************
Headers inclusions
 *******************************************************************************/
#include "mc_key_manager.h"

/*******************************************************************************
 * Constants
 *******************************************************************************/
#define IPD_ALGORITHM_KEY        "GET_THE_KEY_FROM_LOCAL_SALES"
#define ZSMT_ALGORITHM_KEY     "GET_THE_KEY_FROM_LOCAL_SALES"

/*******************************************************************************
 Private data-types
 *******************************************************************************/

/*******************************************************************************
 Private variables
 *******************************************************************************/

/*******************************************************************************
 Interface variables
 *******************************************************************************/
tmcKey_Keys_s mcKeyI_AlgorithmKeys_gds;

/*******************************************************************************
 Private Functions
 *******************************************************************************/

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
__attribute__((noinline)) char * mcKeyI_ValidationKeyGet( const tmcKey_IPs_s ip)
{
     /** Return validation key  */
     return mcKeyI_AlgorithmKeys_gds.Keys[(uint8_t)ip];
}

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
void mcKeyI_KeyManagerInit(void)
{
     char * result;

     /** Initialize IPD key  */
     result = strcpy(mcKeyI_AlgorithmKeys_gds.Keys[(uint8_t)KEY_IPD], IPD_ALGORITHM_KEY );

     /** Initialize ZSMT key  */
    result = strcpy(mcKeyI_AlgorithmKeys_gds.Keys[(uint8_t)KEY_ZSMT], ZSMT_ALGORITHM_KEY );

    if( NULL != result )
    {
        /** ToDO: */
    }

}

