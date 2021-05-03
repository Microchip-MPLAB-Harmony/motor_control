/*******************************************************************************
 Ramp Profiler

  Company:
    Microchip Technology Inc.

  File Name:
    mc_ramp_profiler.c

  Summary:
  This files contains functions regarding ramp profiling for reference signal

  Description:
  This files contains functions regarding ramp profiling for reference signal
 
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

/*******************************************************************************
Headers inclusions
*******************************************************************************/
#include "math.h"
#include "mc_ramp_profiler.h"

/*******************************************************************************
 Macros
 *******************************************************************************/
#define RPM_TO_RAD_PER_SEC  (float)( 2.0f * NUM_POLE_PAIRS * M_PI / 60.0f )
#define RPM_TO_INTERNAL_UNITS (float)( K_SPEED * RPM_TO_RAD_PER_SEC )

/*******************************************************************************
 Private data-types  
 *******************************************************************************/
typedef struct _tmcRmp_ReferenceSpeedGenerator_s
{
    tmcRmp_ReferenceProfile_e profileType;
    int16_t inputValueInInternalUnits; 
    int16_t finalValueInInternalUnits;
    int16_t initialValueInInternalUnits;
    int16_t rampRateValue;
    int16_t rampRateShift;
    int16_t currentValueInInternalUnits;	 
    uint32_t rampProfileCounter;
}tmcRmp_ReferenceSpeedGenerator_s;

/*******************************************************************************
Private global variables
*******************************************************************************/
tmcRmp_ReferenceSpeedGenerator_s mcRmp_ReferenceSpeed_mds;

/******************************************************************************
Safety variables
******************************************************************************/


/*******************************************************************************
Functions (private and public)
*******************************************************************************/

/*******************************************************************************
 * Interface Functions
*******************************************************************************/

/* !\brief Initialize ramp profiler
 * 
 * Details.
 * Initialize ramp profiler
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */

void mcRmpI_ReferenceProfileInit( tmcRmp_ReferenceSpeed_s * rampProfile)
{
    
     mcRmp_ReferenceSpeed_mds.profileType = rampProfile->profileType;
     if( referenceProfile_Sigmoid == rampProfile->profileType )
     {
	/* ToDO: */
     }
     else if( referenceProfile_Linear == rampProfile->profileType )
     {
          float f32a;
               
          /* Ramp rate in RPM per second*/
          f32a = ( rampProfile->finalValue - rampProfile->initialValue ) / rampProfile->rampTimeInSec;
               
          /* Ramp rate in internal units per second */
          f32a *= rampProfile->realToInternalUnits;
          
          /* Ramp rate in internal units per sampling period */
          f32a *= CURRENT_CONTROL_SAMPLING_TIME;
          
          mcRmp_ReferenceSpeed_mds.rampRateShift = 0;
                              
          while( ( f32a < 16384.0f ) && (mcRmp_ReferenceSpeed_mds.rampRateShift < 14u ))
          {
               f32a *= 2.0f;
               mcRmp_ReferenceSpeed_mds.rampRateShift++;
          }
          mcRmp_ReferenceSpeed_mds.rampRateValue = f32a;
     }
     else 
     {
          
     }

     mcRmp_ReferenceSpeed_mds.inputValueInInternalUnits =  rampProfile->defaultValue * rampProfile->realToInternalUnits;
     mcRmp_ReferenceSpeed_mds.finalValueInInternalUnits =  rampProfile->minimumValue * rampProfile->realToInternalUnits;;
     mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits =  rampProfile->minimumValue * rampProfile->realToInternalUnits;;
}

void mcRmpI_ReferenceProfileInputCommand( int16_t commandRpm)
{
     mcRmp_ReferenceSpeed_mds.inputValueInInternalUnits = commandRpm;
}


int16_t mcRmpI_ReferenceProfileGenerate( void )
{
    /* Scale the input RPM to internal units */
    switch(mcRmp_ReferenceSpeed_mds.profileType)
    {
          case referenceProfile_Step:
          {
	   mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits = mcRmp_ReferenceSpeed_mds.inputValueInInternalUnits;
          }
          break;
		
          case referenceProfile_Linear:
          {
               int32_t s32a;
               
	     /* Update reference input if there has been a change */
	     if( mcRmp_ReferenceSpeed_mds.finalValueInInternalUnits != mcRmp_ReferenceSpeed_mds.inputValueInInternalUnits )
	     {                
	          mcRmp_ReferenceSpeed_mds.finalValueInInternalUnits = mcRmp_ReferenceSpeed_mds.inputValueInInternalUnits;
	          mcRmp_ReferenceSpeed_mds.initialValueInInternalUnits = mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits;
	          mcRmp_ReferenceSpeed_mds.rampProfileCounter = 0u;
	     }
			
	     /* Generate linear reference  */
               if( mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits < mcRmp_ReferenceSpeed_mds.finalValueInInternalUnits)
               {
                    mcRmp_ReferenceSpeed_mds.rampProfileCounter++;
                    s32a = mcRmp_ReferenceSpeed_mds.rampProfileCounter * mcRmp_ReferenceSpeed_mds.rampRateValue;
                    s32a >>= mcRmp_ReferenceSpeed_mds.rampRateShift; 
                    mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits = mcRmp_ReferenceSpeed_mds.initialValueInInternalUnits + s32a;
               }
               else if( mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits > mcRmp_ReferenceSpeed_mds.finalValueInInternalUnits)
               {
                    mcRmp_ReferenceSpeed_mds.rampProfileCounter++;
                    s32a = mcRmp_ReferenceSpeed_mds.rampProfileCounter * mcRmp_ReferenceSpeed_mds.rampRateValue;
                    s32a >>= mcRmp_ReferenceSpeed_mds.rampRateShift; 
                    mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits = mcRmp_ReferenceSpeed_mds.initialValueInInternalUnits - s32a;
               }
               else 
               {
                    mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits = mcRmp_ReferenceSpeed_mds.finalValueInInternalUnits;
               }			
	}
	break;
		
	case referenceProfile_Sigmoid:
	{
	    /* ToDO: */ 
	}
	break;
		
	default:
	{
			
	}
	break;
    }
    return mcRmp_ReferenceSpeed_mds.currentValueInInternalUnits;
}