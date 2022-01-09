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
#include "mc_ramp_profiler.h"

/*******************************************************************************
 Constants 
 *******************************************************************************/
#if (( CONTROL_LOOP == SPEED_LOOP ) ||  ( CONTROL_LOOP == OPEN_LOOP ) )

/**
 * Constant value of PI
 */
#define CONSTANT_Pi                                (float)3.14159265358979323846

/**
 * RPM to Rad Per Second Conversion factor
 */
#define CONSTANT_RpmToRadPerSec        (float)( 2.0f * CONFIG_RmpNumberOfPolePairs * CONSTANT_Pi / 60.0f )


/**
 * Final Speed for Ramp Profiler 
 */
#define CONSTANT_RampProfileRampPerSec  (float)( CONFIG_RampProfileRampPerSec  * CONSTANT_RpmToRadPerSec )


/**
 * Default Speed for Ramp Profiler 
 */
#define CONSTANT_RampProfileDefaultValue   (float)( CONFIG_RampProfileDefaultValue  * CONSTANT_RpmToRadPerSec )

#endif


#if ( CONTROL_LOOP == POSITION_LOOP ) 

/**
 * Constant value of PI
 */
#define CONSTANT_Pi                                (float)3.14159265358979323846

/**
 * RPM to Rad Per Second Conversion factor
 */
#define CONSTANT_RpmToRadPerSec        (float)( 2.0f * CONFIG_RmpNumberOfPolePairs * CONSTANT_Pi / 60.0f )


/**
 * Final Speed for Ramp Profiler 
 */
#define CONSTANT_RampProfileRampPerSec  (float)( CONFIG_RampProfileRampPerSec  * CONSTANT_RpmToRadPerSec )


/**
 * Default Speed for Ramp Profiler 
 */
#define CONSTANT_RampProfileDefaultValue   (float)( CONFIG_RampProfileDefaultValue  * CONSTANT_RpmToRadPerSec )

#endif

/*******************************************************************************
 Private data-types  
 *******************************************************************************/
typedef struct _tmcRmp_ReferenceGenerator_s
{
    tmcRmp_ReferenceProfile_e profileType;
    float inputValue; 
    float currentValue;
    float defaultValue;
    float rampPerSamplingPeriod;
}tmcRmp_ReferenceGenerator_s;

/*******************************************************************************
Private global variables
*******************************************************************************/
static tmcRmp_ReferenceGenerator_s mcRmp_StateVariables_mds;

/******************************************************************************
Safety variables
******************************************************************************/


/*******************************************************************************
Functions (private and public)
*******************************************************************************/
tmcRmp_RampProfilerConfig_s mcRmpI_RampProfilerConfig_mds =  RAMP_PROFILER_MODULE_CONFIG_A;

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

void mcRmpI_ReferenceProfileInit( tmcRmp_RampProfilerConfig_s * pParam )
{
#if( ENABLE == DEVELOPER_MODE )    
     mcRmp_StateVariables_mds.profileType = pParam->profileType;
     if( referenceProfile_Linear == pParam->profileType )
     {    
         float f32a;
         
         f32a = pParam->rampPerSec * pParam->samplingTimeInSec;
         
          /* Ramp rate in internal units per sampling period */
          mcRmp_StateVariables_mds.rampPerSamplingPeriod = f32a * CONSTANT_RpmToRadPerSec;

     }
     else 
     {
          
     }

     mcRmp_StateVariables_mds.defaultValue =  pParam->defaultValue * CONSTANT_RpmToRadPerSec;
     mcRmp_StateVariables_mds.inputValue =  pParam->defaultValue * CONSTANT_RpmToRadPerSec;
     mcRmp_StateVariables_mds.currentValue =  0.0f;
#else 
     mcRmp_StateVariables_mds.profileType = CONSTANT_RampProfileType;
     if( referenceProfile_Linear == mcRmp_StateVariables_mds.profileType )
     {                                 
          /* Ramp rate in internal units per sampling period */
          mcRmp_StateVariables_mds.rampPerSamplingPeriod = CONSTANT_RampProfileRampPerSec * CONFIG_RampProfilerSamplingTime;

     }
     else 
     {
          
     }
     mcRmp_StateVariables_mds.defaultValue =  CONSTANT_RampProfileDefaultValue;
     mcRmp_StateVariables_mds.inputValue =  CONSTANT_RampProfileDefaultValue;
     mcRmp_StateVariables_mds.currentValue =  0.0f;
     
#endif 
}

void mcRmpI_ReferenceProfileInputCommand( int16_t commandValue )
{
     mcRmp_StateVariables_mds.inputValue = commandValue;
}


int16_t mcRmpI_ReferenceProfileGenerate( void )
{
    /* Scale the input RPM to internal units */
    switch(mcRmp_StateVariables_mds.profileType)
    {
          case referenceProfile_Step:
          {
	          mcRmp_StateVariables_mds.currentValue = mcRmp_StateVariables_mds.inputValue;
          }
          break;
		
          case referenceProfile_Linear:
          {
               int32_t s32a;
                              
	     /* Update reference input if there has been a change */
               s32a = 2.0f * ( mcRmp_StateVariables_mds.inputValue - mcRmp_StateVariables_mds.currentValue );
	     if( s32a > mcRmp_StateVariables_mds.rampPerSamplingPeriod )
	     {                
	          mcRmp_StateVariables_mds.currentValue += mcRmp_StateVariables_mds.rampPerSamplingPeriod;
	     }
          else if( s32a < -mcRmp_StateVariables_mds.rampPerSamplingPeriod )
          {
               mcRmp_StateVariables_mds.currentValue -= mcRmp_StateVariables_mds.rampPerSamplingPeriod;
          }
          else 
          {
               /* Do nothing */
          }		
	}
	break;
				
	default:
	{
			
	}
	break;
    }
    return mcRmp_StateVariables_mds.currentValue;
}

/* !\brief Reset ramp profiler
 * 
 * Details.
 * Reset ramp profiler
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return: None
 */

void mcRmpI_ReferenceProfileReset( void )
{
    mcRmp_StateVariables_mds.currentValue = 0.0f;
    mcRmp_StateVariables_mds.inputValue = mcRmp_StateVariables_mds.defaultValue;
}
