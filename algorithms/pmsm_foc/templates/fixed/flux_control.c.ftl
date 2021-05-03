/*******************************************************************************
 Flux control Functions

  Company:
    Microchip Technology Inc.

  File Name:
    mc_flux_control.c

  Summary:
    Flux Control functions.

  Description:
    This file implements functions for PMSM flux control..
 
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
#include "mc_flux_control.h"

#define RPM_TO_RAD_PER_SEC (float)( 2.0f * M_PI / 60.0f )

/*******************************************************************************
 Private data-types 
*******************************************************************************/
typedef struct tmcFlx_FluxWeakeningParam_s
{ 
    int16_t  Rs;
    int16_t  Ld;
    int16_t  Lq;
    int16_t  Idmin;
    IQ mtpaConstTerm1;
    IQ mtpaConstTerm2;
}tmcFlx_Parameters_s;


/*******************************************************************************
 * Module variables 
*******************************************************************************/
static tmcFlx_InputPorts_s  mcFlx_InputPorts_mas[1u];
static tmcFlx_Parameters_s  mcFlx_Parameters_mas[1u];
static tmcFlx_OutputPorts_s  mcFlx_OutputPorts_mas[1u];

/*******************************************************************************
 * Interface variables 
*******************************************************************************/
int16_t mcFlxI_DaxisReferenceCurrent_gds16;

extern int32_t __aeabi_idiv(int32_t numerator, int32_t denominator);

tmcFlx_ConfigParameters_s mcFlxI_ConfigParameters_gds = FLUX_CONTROL_MODULE_CONFIG;

/*******************************************************************************
 * Local Functions  
*******************************************************************************/

/*! \brief Execute flux weakening Function
 * 
 * Details.
 * Execute Flux weakening function  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlx_FluxWeakening( uint8_t Id )
#else
void mcFlx_FluxWeakening( uint8_t Id  )
#endif 
{
  #if ( 1u == FLUX_WEAKENING )
    int32_t s32a;
    int32_t Uqref;
    int32_t Num;
    int32_t Den;   
    
    if( *mcFlx_InputPorts_mas[Id].Udmax  > *mcFlx_InputPorts_mas[Id].Ud )
    {
        Uqref = mcLib_DetermineAdjSide( *mcFlx_InputPorts_mas[Id].Udmax, *mcFlx_InputPorts_mas[Id].Ud );
    }
    else
    {
        Uqref = 0;
    }
    
    /* Revert the sign of reference q-axis current for negative rotation  */
    s32a = abs(*mcFlx_InputPorts_mas[Id].iq);

    /* Id reference for feed forward control */
    Num  = (int32_t)Uqref;
    Num -= (int32_t)mcLib_MultShiftRight( s32a, mcFlx_Parameters_mas[Id].Rs, SH_BASE_VALUE);
    Num -= (int32_t)(*mcFlx_InputPorts_mas[Id].Es);
    Num *= (int32_t)K_CURRENT;
         
    Den  = (int32_t)mcLib_MultShiftRight( mcFlx_Parameters_mas[Id].Ld, *mcFlx_InputPorts_mas[Id].Wr, SH_BASE_VALUE );
    
    s32a = __aeabi_idiv(Num, Den);   

    /* Limit the reference d axis current */
    if( s32a > 0)
    {
        s32a = 0;
    }
    else if( s32a < (int32_t)mcFlx_Parameters_mas[Id].Idmin )
    {
        s32a = mcFlx_Parameters_mas[Id].Idmin ;
    }
    else
    {
        /* Do nothing */
    }

   *mcFlx_OutputPorts_mas[Id].idref = s32a;
 #endif

}

/*! \brief Execute maximum torque per ampere 
 * 
 * Details.
 * Execute maximum torque per ampere 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
__STATIC_INLINE void mcFlx_MaxTorquePerAmpere( uint8_t Id )
{
    
} 

/*******************************************************************************
 * Interface Functions  
*******************************************************************************/

/*! \brief Initialize flux control 
 * 
 * Details.
 * Initialize flux control  
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcFlxI_FluxControlInit( tmcFlx_ConfigParameters_s * flxParam )
{
    float f32a;

    /* Check if configuration parameters does not point to NULL */
    ASSERT(( NULL != flxParam), "Configuration parameters points to NULL");
    
    /* Check if input ports are initialized properly */
    ASSERT(   ( ( NULL != flxParam->inPort.Ud )  &&  (  NULL != flxParam->inPort.Udmax ) 
                  && ( NULL != flxParam->inPort.Wr )  &&  (  NULL != flxParam->inPort.iq )),
                          "Input Ports are not assigned" );
    
    mcFlx_InputPorts_mas[flxParam->Id] = flxParam->inPort;
    
     /* Check if output ports are initialized properly */
     ASSERT((  NULL != flxParam->outPort.idref ),   "Output Ports are not assigned");
    
     mcFlx_OutputPorts_mas[flxParam->Id] = flxParam->outPort;
     
     /* Update and calculate independent and dependent parameters respectively */
  #if ( 1u == FLUX_WEAKENING )
    /* Initialize parameters for flux weakening */
    f32a = ( K_IMPEDENCE * flxParam->userParam.Rs ) + 0.5f;
    mcFlx_Parameters_mas[flxParam->Id].Rs  =  (int16_t)(  f32a );
    
    f32a = ( K_INDUCTANCE * flxParam->userParam.Ld ) + 0.5f;
    mcFlx_Parameters_mas[flxParam->Id].Ld  =  (int16_t)(  f32a );
    
    f32a = ( K_CURRENT * flxParam->userParam.Idmin ) + 0.5f;
    mcFlx_Parameters_mas[flxParam->Id].Idmin  = (int16_t)( f32a  );

  #endif
  
  #ifndef ISOTROPIC_MOTOR
    /* Initialize parameters for MTPA */
    f32a = ( flxParam->userParam.Ke / ( SQRT3 * 1000.0f * flxParam->userParam.Zp * RPM_TO_RAD_PER_SEC ) ) ;
    f32a = (float)( 0.5 * K_CURRENT * f32a / (flxParam->userParam.Lq - flxParam->userParam.Ld ));
    mcLib_FloatToIQ( f32a, &mcFlx_Parameters_mas[flxParam->Id].mtpaConstTerm1 );
   
    f32a *= f32a;
    mcLib_FloatToIQ( f32a, &mcFlx_Parameters_mas[flxParam->Id].mtpaConstTerm2 );
   
  #endif

}

/*! \brief Execute Flux control 
 * 
 * Details.
 * Execute flux control 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
#ifdef RAM_EXECUTE
void __ramfunc__  mcFlxI_FluxControlRun( uint8_t Id  )
#else
void mcFlxI_FluxControlRun( uint8_t Id  )
#endif
{
    /* Flux for speed above rated speed */
    mcFlx_FluxWeakening( Id );

    /* Flux for maximum torque per ampere */
    mcFlx_MaxTorquePerAmpere( Id );

}

/*! \brief Reset Flux control
 * 
 * Details.
 * Reset Flux control
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcFlx_FluxControlReset(  uint8_t Id )
{
   #if ( 1u == FLUX_WEAKENING )
    
   
   #endif


   #ifdef ISOTROPIC_MOTOR
  
   #endif

   /* Reset output ports */
   *mcFlx_OutputPorts_mas[Id].idref = 0;
}