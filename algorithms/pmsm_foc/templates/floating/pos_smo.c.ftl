/*******************************************************************************
  Rotor Position Source File

  Company:
    Microchip Technology Inc.

  File Name:
    mc_rotor_position.c

  Summary:
    This file contains functions to get the rotor position of a motor

  Description:
    This file contains functions to get the rotor position of a motor
 *******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2021 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


/*******************************************************************************
 Interface Functions 
 *******************************************************************************/
#include "mc_rotor_position.h"
#include <math.h>

/*******************************************************************************
Constants
 *******************************************************************************/
/**
 * Constant value of PI
 */
#define CONSTANT_Pi   (float)(3.14159265358979323846)   

/**
 * Constant value of 2PI
 */
#define CONSTANT_2Pi   (float)(2.0f * CONSTANT_Pi )   

/**
 * Constant value of PI/4
 */
#define CONSTANT_PiBy4  (float)( CONSTANT_Pi / 4.0 )

/**
 * Constant value of 3PI/4
 */
#define CONSTANT_3PiBy4  (float)( 3.0 * CONSTANT_PiBy4 )

/**
 * Speed calculation FIFO buffer size 
 */
#define CONSTANT_SpeedFifoBufferSize   (41u)

/**
 * Constant value for 1/1ms
 */
#define CONSTANT_1By1ms   (float)1000.0

/**
 * Zero boundary 
 */
#define CONSTANT_Epsilon   1E-31

/**
 * 
 */
#define CONFIG_ApproxInvTanCalcEnable 1u  

/**
 * 
 */
#define CONFIG_BemfFilterEnable 0u  /* Is dynamic BEMF filter enabled? */

/**
 * 
 */
#define RL_EPSILON_F ((float)0.00000001)  /* small float value for zero-check */

/**
 * Constant value of RsTs/Ls
 */
#define CONSTANT_RsTsByLs (float)(((double)CONFIG_SmoMotorPerPhaseResistanceInOhm * (double)CONFIG_SmoAlgorithmCycleTimeInSec )/ CONFIG_SmoMotorPerPhaseInductanceInHenry )

/**
 * Constant value of exp( -RsTs/Ls )
 */
#define CONSTANT_ExpOfMinusRsTsByLs (float)(exp(-CONSTANT_RsTsByLs))

/*******************************************************************************
 Private data-types 
 *******************************************************************************/
typedef struct _tmcRpo_StateVariables_s
{
    uint8_t state;

    float IalphaHat;
    float IbetaHat;
    float EalphaHat;
    float EbetaHat;
    float Balpha;  
    float Bbeta; 

    float zTH;  
    float dTH;  

    float WeHat;
    float WmHat; 
    float WeRaw;  
    float SUMdTH;
    uint16_t cntFIFO;
    float FIFOdTH[CONSTANT_SpeedFifoBufferSize]; 
    
}tmcRpo_StateVariables_s;

typedef struct _tmcRpo_Parameters_s 
{
    float wcSpeedFil;
    float Ts;
    float rs;
    float ls;
    float P;
    float speedRefTime;
    float oneMinusExpRsLsByTs;
    float boundaryI;
    float m;
    float lambda;
    float speedRefCnt;
    float cnt1ms;
    float mdbi;
    float wcTs;
    float oneMinusWcTs;
    float eleRadPsToMecRPM;
    float aIObs;
    float b1IObs;
    float b2IObs;
    float b3IObs;
    float a1BEMFobs;
    float a2BEMFobs;
    float b1BEMFobs;
    float b2BEMFobs; 
}tmcRpo_Parameters_s;


/*******************************************************************************
Private data 
 *******************************************************************************/
static tmcRpo_InputPorts_s mcRpo_InputPorts_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_OutputPorts_s mcRpo_OutputPorts_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_Parameters_s mcRpo_Parameters_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_StateVariables_s mcRpo_StateVariables_mas[ROTOR_POSITION_INSTANCES];

/*******************************************************************************
Interface variables 
 *******************************************************************************/
tmcRpo_ConfigParameters_s mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES] = 
{
    ROTOR_POSITION_MODULE_A_CONFIG,
#if( 2u == ROTOR_POSITION_INSTANCES )
    ROTOR_POSITION_MODULE_B_CONFIG
#endif
};

/*******************************************************************************
Private functions 
 *******************************************************************************/

static tStd_ReturnType_e mcRpo_AssertionFailedReaction( const char * message )
{
    /* ToDo: Decide appropriate reaction function */
     return returnType_Failed;
}


#define ASSERT( expression, message ) { if(!expression)mcRpo_AssertionFailedReaction(message);}

/*! \brief Determine coefficients 
 * 
 * Details.
 * Determine coefficients 
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpo_DeteremineCoefficients(uint8_t Id, float We )
{
    float tmp1;
    float tmp2;
    float angle, sine, cosine;

    if((CONSTANT_Epsilon < We) || (-CONSTANT_Epsilon > We))
    {  
       
    }
    else if( CONSTANT_Epsilon > We )  
    {
         We = CONSTANT_Epsilon;
    }
    else
    {
        We = -CONSTANT_Epsilon;
    }
    
    angle = We * mcRpo_Parameters_mas[0u].Ts;
    mcLib_SinCosCalc( angle, &sine, &cosine);
       
    mcRpo_Parameters_mas[Id].a1BEMFobs = cosine;
    mcRpo_Parameters_mas[Id].a2BEMFobs = sine;
    tmp1 = 1.0 -  mcRpo_Parameters_mas[Id].a1BEMFobs;
    tmp2 = mcRpo_Parameters_mas[Id].lambda / We;
    mcRpo_Parameters_mas[Id].b1BEMFobs = ((tmp2 * mcRpo_Parameters_mas[Id].a2BEMFobs) + tmp1) * mcRpo_Parameters_mas[Id].ls;
    mcRpo_Parameters_mas[Id].b2BEMFobs = ( mcRpo_Parameters_mas[Id].a2BEMFobs - (tmp2 * tmp1)) * mcRpo_Parameters_mas[Id].ls;    
}

/*! \brief Inverse tangent calculation
 * 
 * Details.
 * Inverse tangent calculation
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

float mcRpoI_InverseTangent( float y, float x )
{
     float r, angle, abs_y;
        
     abs_y = ( 0.0f > y ) ? -y:y;
        
     if ( x < 0.0f )
     {
          r = (x + abs_y) / (abs_y - x);
	angle = CONSTANT_3PiBy4;
     }
     else
     {
	r = (x - abs_y) / (x + abs_y);
	angle = CONSTANT_PiBy4;
     }
     angle += (0.1963f * r * r - 0.9817f) * r;
     if ( y < 0.0f )
     {
          return( -angle );     // negate if in quad III or IV
     }
     else
     {
          return( angle );
     }
}

/*! \brief Rotor position calculation
 * 
 * Details.
 * Rotor position calculation
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpo_RotorPositionCalculate( uint8_t  Id   )
{
    float tmp1;
    
    /* TH cal. */
#if CONFIG_ApproxInvTanCalcEnable
    tmp1 = mcRpoI_InverseTangent(mcRpo_StateVariables_mas[Id].EbetaHat, mcRpo_StateVariables_mas[Id].EalphaHat);  
#else
    tmp1 = atan2f( mcRpo_StateVariables_mas[Id].EbetaHat, mcRpo_StateVariables_mas[Id].EalphaHat );   
#endif    

    /* Return value of atan2f locates in [-pi, pi]. */
    if( 0.0 < mcRpo_StateVariables_mas[Id].WeHat)
    {
        tmp1 = tmp1 - (float)M_PI_2;
    } 
    else
    {
        tmp1 = tmp1 + (float)M_PI_2;
    }
    
    if(0.0 > tmp1)
    {
        *mcRpo_OutputPorts_mas[Id].angle = tmp1 + CONSTANT_2Pi;
    } 
    else if(CONSTANT_2Pi < tmp1)
    {
         *mcRpo_OutputPorts_mas[Id].angle = tmp1 - CONSTANT_2Pi;
    } 
    else
    {
        *mcRpo_OutputPorts_mas[Id].angle = tmp1;
    }    
    
    /* dTH cal. */
    tmp1 = ( *mcRpo_OutputPorts_mas[Id].angle) - (mcRpo_StateVariables_mas[Id].zTH);   
    if(-CONSTANT_Pi > tmp1)
    {
        mcRpo_StateVariables_mas[Id].dTH = tmp1 + CONSTANT_2Pi;
    } 
    else if( CONSTANT_Pi < tmp1)
    {
        mcRpo_StateVariables_mas[Id].dTH = tmp1 - CONSTANT_2Pi;
    } else
    {
        mcRpo_StateVariables_mas[Id].dTH = tmp1;
    }
          
    /* Latch TH */
    mcRpo_StateVariables_mas[Id].zTH =  *mcRpo_OutputPorts_mas[Id].angle;
}

/*! \brief Rotor speed calculation
 * 
 * Details.
 * Rotor speed calculation
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */

void mcRpo_RotorSpeedCalculate(  uint8_t  Id )
{
    float tmp1;
    uint16_t tmp2;
    
    /* Update FIFO. */
    tmp1 = mcRpo_StateVariables_mas[Id].dTH;
    tmp2 = mcRpo_StateVariables_mas[Id].cntFIFO;
    mcRpo_StateVariables_mas[Id].FIFOdTH[tmp2] = tmp1;
    
    if(mcRpo_Parameters_mas[Id].cnt1ms > tmp2)
    {
        (mcRpo_StateVariables_mas[Id].cntFIFO)++;
    } 
    else
    {
        mcRpo_StateVariables_mas[Id].cntFIFO = 0u;
    }
    
    /* Accumulate dTH for 1ms. */
    tmp2 = mcRpo_StateVariables_mas[Id].cntFIFO;
    mcRpo_StateVariables_mas[Id].SUMdTH +=  tmp1 - mcRpo_StateVariables_mas[Id].FIFOdTH[tmp2];
    
    /* Cal. electric angular speed @ rad/s. */
    mcRpo_StateVariables_mas[Id].WeRaw = mcRpo_StateVariables_mas[Id].SUMdTH * CONSTANT_1By1ms;
    
    /* LPF */
    mcRpo_StateVariables_mas[Id].WeHat = (( mcRpo_Parameters_mas[Id].oneMinusWcTs) 
                                                                  *  ( mcRpo_StateVariables_mas[Id].WeHat)) + ((mcRpo_Parameters_mas[Id].wcTs)
                                                                  * (mcRpo_StateVariables_mas[Id].WeRaw));

    *mcRpo_OutputPorts_mas[Id].speed = mcRpo_StateVariables_mas[Id].WeHat;
  
}

/*******************************************************************************
 Interface Functions 
 *******************************************************************************/

/*! \brief Sliding mode observer ( SMO ) initialization
 * 
 * Details.
 * Sliding mode observer ( SMO )  initialization
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( tmcRpo_ConfigParameters_s * const smoParam )
{
    float tmp1;
    tmcRpo_Parameters_s * pParam;
    
    /* Check if the configuration parameters data has valid address */
    ASSERT(( NULL != smoParam ), "Configuration parameters points to NULL address ");
        
    /* Initialize input ports */
    ASSERT((      ( NULL != smoParam->inPort.ialpha ) && (NULL != smoParam->inPort.ibeta) 
                     && ( NULL != smoParam->inPort.ualpha) && (NULL != smoParam->inPort.ubeta ) 
                     && ( NULL != smoParam->inPort.umax )),  "Input ports are not assigned properly");
    mcRpo_InputPorts_mas[smoParam->Id] = smoParam->inPort;
    
     /* Initialize output ports */
    ASSERT((      ( NULL != smoParam->outPort.angle ) && (NULL != smoParam->outPort.speed) 
                     && ( NULL != smoParam->outPort.accel ) ), "Output ports are not assigned properly");
        
    mcRpo_OutputPorts_mas[smoParam->Id] = smoParam->outPort;
    
   
     /* Update and calculate independent and dependent parameters respectively */
#if( ENABLE  == DEVELOPER_MODE )    
    pParam = &mcRpo_Parameters_mas[smoParam->Id];
    pParam->rs =  smoParam->userParam.rs;
    pParam->ls =  smoParam->userParam.ls;
    pParam->P =  smoParam->userParam.P;
    pParam->wcSpeedFil =  smoParam->userParam.wcSpeedFil;
    pParam->Ts =  smoParam->userParam.Ts;
    pParam->speedRefTime =  smoParam->userParam.speedRefTime;
    pParam->oneMinusExpRsLsByTs = (float)( exp( -( pParam->rs * pParam->Ts ) /  pParam->ls ));
    
    pParam->boundaryI  =  smoParam->userParam.boundaryI;
    pParam->m  =  smoParam->userParam.m;
    pParam->lambda  =  smoParam->userParam.lambda;
    pParam->speedRefCnt  =  (uint16_t)( smoParam->userParam.speedRefTime / smoParam->userParam.Ts );
    pParam->cnt1ms  =  (uint16_t)( 0.001 / smoParam->userParam.Ts );
    
    ASSERT((  CONSTANT_Epsilon < smoParam->userParam.boundaryI ), "Division by zero " ); 
    pParam->mdbi  =  (float)(smoParam->userParam.m / smoParam->userParam.boundaryI);
    pParam->wcTs =  (float)(smoParam->userParam.wcSpeedFil * pParam->Ts);
    pParam->oneMinusWcTs  =  (float)(1.0 - pParam->wcTs);
    tmp1  =  (float)(1.0 / smoParam->userParam.P);  
    pParam->eleRadPsToMecRPM =  (float)(tmp1 * 60.0 / CONSTANT_2Pi );
    tmp1  =  pParam->oneMinusExpRsLsByTs;
    pParam->aIObs   =  tmp1;
    ASSERT((  CONSTANT_Epsilon < smoParam->userParam.rs ), "Division by zero " ); 
    pParam->b1IObs  =  (tmp1 - 1.0) / smoParam->userParam.rs;
    pParam->b2IObs  = -pParam->b1IObs;
    pParam->b3IObs  =  smoParam->userParam.ls * pParam->b2IObs;   
#else 
    pParam = &mcRpo_Parameters_mas[smoParam->Id];
    pParam->rs =  CONFIG_SmoMotorPerPhaseResistanceInOhm;
    pParam->ls =  CONFIG_SmoMotorPerPhaseInductanceInHenry;
    pParam->P =  CONFIG_SmoMotorPolePairs;
    pParam->wcSpeedFil =  CONFIG_SmoSpeedFilterCornerFrequency;
    pParam->Ts =  CONFIG_SmoAlgorithmCycleTimeInSec;
    pParam->speedRefTime =  CONFIG_SmoSpeedReferenceTimeInSec;
    pParam->oneMinusExpRsLsByTs = CONSTANT_ExpOfMinusRsTsByLs;
    
    pParam->boundaryI  =  CONFIG_SmoSwitchingFunctionBoundary;
    pParam->m  =  CONFIG_SmoSwitchingFunctionGain;
    pParam->lambda  =  CONFIG_SmoEigenValuesPosition;
    pParam->speedRefCnt  =  (uint16_t)( smoParam->userParam.speedRefTime / smoParam->userParam.Ts );
    pParam->cnt1ms  =  (uint16_t)( 0.001 / smoParam->userParam.Ts );
    pParam->mdbi  =  (float)(smoParam->userParam.m / smoParam->userParam.boundaryI);
    pParam->wcTs =  (float)(smoParam->userParam.wcSpeedFil * pParam->Ts);
    pParam->oneMinusWcTs  =  (float)(1.0 - pParam->wcTs);
    tmp1  =  (float)(1.0 / smoParam->userParam.P);  
    pParam->eleRadPsToMecRPM =  (float)(tmp1 * 60.0 / CONSTANT_2Pi );
    tmp1  =  CONSTANT_ExpOfMinusRsTsByLs;
    pParam->aIObs   =  tmp1;
    pParam->b1IObs  =  (tmp1 - 1.0) / smoParam->userParam.rs;
    pParam->b2IObs  = -pParam->b1IObs;
    pParam->b3IObs  =  smoParam->userParam.ls * pParam->b2IObs;
#endif 

    return returnType_Passed;
}

/*! \brief Sliding mode observer ( SMO ) trigger
 * 
 * Details.
 * Sliding mode observer ( SMO )  trigger
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationTrigger( uint8_t  Id  )
{
    mcRpo_StateVariables_mas[Id].state = 1u;
}

/*! \brief Sliding mode observer ( SMO ) execution
 * 
 * Details.
 * Sliding mode observer ( SMO )  execution
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( uint8_t  Id )
{  
    if(mcRpo_StateVariables_mas[Id].state)
    {       
        float zEalphaHat;
        float temp;

        temp = (*mcRpo_InputPorts_mas[Id].ialpha ) - mcRpo_StateVariables_mas[Id].IalphaHat;

        if(mcRpo_Parameters_mas[Id].boundaryI < temp)
        {  
            /* Itilde is above boundary layer. */
            mcRpo_StateVariables_mas[Id].Balpha = mcRpo_Parameters_mas[Id].m;
        } 
        else if(-mcRpo_Parameters_mas[Id].boundaryI > temp)
        {  
            /* Itilde is below boundary layer. */
            mcRpo_StateVariables_mas[Id].Balpha = -mcRpo_Parameters_mas[Id].m;
        } 
        else
        {  
            /* Itilde is inside boundary layer. */
            mcRpo_StateVariables_mas[Id].Balpha = temp * mcRpo_Parameters_mas[Id].mdbi;
        }
        temp = (*mcRpo_InputPorts_mas[Id].ualpha ) * (*mcRpo_InputPorts_mas[Id].umax ) ;
        temp *= ( mcRpo_Parameters_mas[Id].b2IObs ); 
        temp +=  ( mcRpo_Parameters_mas[Id].aIObs * mcRpo_StateVariables_mas[Id].IalphaHat); 
        temp += ( mcRpo_Parameters_mas[Id].b1IObs * mcRpo_StateVariables_mas[Id].EalphaHat );
        temp += ( mcRpo_Parameters_mas[Id].b3IObs * mcRpo_StateVariables_mas[Id].Balpha);
        mcRpo_StateVariables_mas[Id].IalphaHat = temp;

        temp = (*mcRpo_InputPorts_mas[Id].ibeta ) - mcRpo_StateVariables_mas[Id].IbetaHat;

        if(mcRpo_Parameters_mas[Id].boundaryI < temp)
        {  
            /* Itilde is above boundary layer. */
            mcRpo_StateVariables_mas[Id].Bbeta = mcRpo_Parameters_mas[Id].m;
        } 
        else if(-mcRpo_Parameters_mas[Id].boundaryI > temp )
        {  
            /* Itilde is below boundary layer. */
            mcRpo_StateVariables_mas[Id].Bbeta = -mcRpo_Parameters_mas[Id].m;
        } 
        else
        {  
            /* Itilde is inside boundary layer. */
            mcRpo_StateVariables_mas[Id].Bbeta = temp * mcRpo_Parameters_mas[Id].mdbi;
        }
        temp = (*mcRpo_InputPorts_mas[Id].ubeta ) * (*mcRpo_InputPorts_mas[Id].umax ) ;
        temp *= ( mcRpo_Parameters_mas[Id].b2IObs );
        temp +=  ( mcRpo_Parameters_mas[Id].aIObs * mcRpo_StateVariables_mas[Id].IbetaHat); 
        temp += ( mcRpo_Parameters_mas[Id].b1IObs * mcRpo_StateVariables_mas[Id].EbetaHat ); 
        temp += ( mcRpo_Parameters_mas[Id].b3IObs * mcRpo_StateVariables_mas[Id].Bbeta);
        mcRpo_StateVariables_mas[Id].IbetaHat  = temp;
        
        /* Estimate Ibeta. */  
        zEalphaHat = mcRpo_StateVariables_mas[Id].EalphaHat;  /* Latch last EalphaHat. */
        mcRpo_DeteremineCoefficients( Id, mcRpo_StateVariables_mas[Id].WeHat);

        
        temp =  ( mcRpo_Parameters_mas[Id].a1BEMFobs *  mcRpo_StateVariables_mas[Id].EalphaHat); 
        temp -= ( mcRpo_Parameters_mas[Id].a2BEMFobs * mcRpo_StateVariables_mas[Id].EbetaHat ); 
        temp += ( mcRpo_Parameters_mas[Id].b1BEMFobs * mcRpo_StateVariables_mas[Id].Balpha );
        temp += ( mcRpo_Parameters_mas[Id].b2BEMFobs * mcRpo_StateVariables_mas[Id].Bbeta );
        mcRpo_StateVariables_mas[Id].EalphaHat = temp;

        temp =  ( mcRpo_Parameters_mas[Id].a1BEMFobs *  mcRpo_StateVariables_mas[Id].EbetaHat); 
        temp += ( mcRpo_Parameters_mas[Id].a2BEMFobs * zEalphaHat ); 
        temp += ( mcRpo_Parameters_mas[Id].b1BEMFobs * mcRpo_StateVariables_mas[Id].Bbeta ); 
        temp -= ( mcRpo_Parameters_mas[Id].b2BEMFobs * mcRpo_StateVariables_mas[Id].Balpha );
        mcRpo_StateVariables_mas[Id].EbetaHat = temp;
        
        /* Rotor position calculation */
        mcRpo_RotorPositionCalculate(Id);    
        
        /* Rotor speed calculation */
        mcRpo_RotorSpeedCalculate(Id);    
    }   
}


/*! \brief Sliding mode observer ( SMO ) reset
 * 
 * Details.
 * Sliding mode observer ( SMO )  reset
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void     mcRpoI_RotorPositionCalculationReset( uint8_t  Id )
{
    uint16_t tmp;
    
    mcRpo_StateVariables_mas[Id].cntFIFO = 0u;
    
    for(tmp=0u; mcRpo_Parameters_mas[Id].cnt1ms >= tmp; tmp++)
    {
        mcRpo_StateVariables_mas[Id].FIFOdTH[tmp] = 0.0f;
    }
    mcRpo_StateVariables_mas[Id].state = 0u;
    mcRpo_StateVariables_mas[Id].IalphaHat  = 0.0f;
    mcRpo_StateVariables_mas[Id].IbetaHat   = 0.0f;
    mcRpo_StateVariables_mas[Id].EalphaHat  = 0.0f;
    mcRpo_StateVariables_mas[Id].EbetaHat   = 0.0f;
}

/* End of file */
