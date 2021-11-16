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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "mc_rotor_position.h"

/*******************************************************************************
 Constants
 *******************************************************************************/
/**
 * Speed calculation FIFO buffer size
 */
#define CONSTANT_SpeedFifoBufferCount   (41u)

/**
 * Constant value of 1/ 1000 for milli-second  to second conversion
 */
#define CONSTANT_1By1ms    (float)1000.0

/**
 * Constant value of PI
 */
#define CONSTANT_Pi    (float)( 3.14159265358979323846 )


/**
 * Constant value of 2PI
 */
#define CONSTANT_2Pi    (float)( 2.0f * CONSTANT_Pi )

/**
 * Constant value of PI/4
 */
#define CONSTANT_PiBy2    (float)( CONSTANT_Pi / 2.0 )

/**
 * Constant value of PI/4
 */
#define CONSTANT_PiBy4    (float)( CONSTANT_Pi / 4.0 )

/**
 * Constant value of 3PI/4 
 */
#define CONSTANT_3PiBy4    (float)( 3.0 * CONSTANT_Pi / 4.0 )

/**
 *  Constant value for ( 1 - HGain )
 */
#define CONSTANT_1MinusHGain     (float)( 1.0f - CONFIG_RoloHGain  )

/**
 *  Constant value for ( HGain * Ls / Ts )
 */
#define CONSTANT_HLsByTs   (float)( CONFIG_RoloHGain * CONFIG_MotorPerPhaseInductanceInHenry / CONFIG_RoloAlgorithmCycleTime )

/**
 * Constant value for (  HGain * Ls / Ts - Rs )
 */
#define CONSTANT_HLsByTsMinusRs   (float)( CONSTANT_HLsByTs - CONFIG_MotorPerPhaseResistanceInOhm   )

/**
 * Constant value of ( WcTs )
 */
#define CONSTANT_WcTs (float)(CONFIG_RoloSpeedFilterCornerFrequency* CONFIG_RoloAlgorithmCycleTime )

/**
 * Constant value of ( WcTs )
 */
#define CONSTANT_OneMinusWcTs (float)( 1.0f - CONSTANT_WcTs )

 /**
 * Constant value of ( WcTs )
 */
#define CONSTANT_NumberOfSamplesIn1ms   (float)( 0.001f / CONFIG_RoloAlgorithmCycleTime )

/*******************************************************************************
 Private data-types  
 *******************************************************************************/

/*! \brief Brief description.
 *   This structure holds value of external parameters required by the ROLO.
 *
 *  This structure comprises of external parameters required to execute ROLO.
 *  
 */
typedef struct _tmcRpo_Parameters_s
{
   float Rs;
   float Ls;
   float H;
   float Ts;      
   float oneMinusH; 
   float HLsByTs;
   float HLsByTsMinusRs;
   float Wc;
   float WcTs;
   float oneMinusWcTs;
   uint16_t cnt1ms;
}tmcRpo_Parameters_s;


/*! \brief Brief description.
 *         This structure holds value of state variables of ROLO.
 *
 *  This structure holds value of state variables of ROLO.
 *  
 */
typedef struct _tmcRpo_StateVariables_s
{
    float Za;
    float Zb;
    float Ea;
    float Eb;
    float zTH;  
    float dTH;  
    float WeHat;
    float WeRaw;  
    float SUMdTH;
    float FIFOdTH[CONSTANT_SpeedFifoBufferCount]; 
    uint16_t cntFIFO;
}tmcRpo_StateVariables_s;


/*******************************************************************************
 Private variables  
 *******************************************************************************/
static tmcRpo_InputPorts_s mcRpo_InputPorts_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_OutputPorts_s mcRpo_OutputPorts_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_StateVariables_s mcRpo_StateVariables_mas[ROTOR_POSITION_INSTANCES];
static tmcRpo_Parameters_s mcRpo_Parameters_mas[ROTOR_POSITION_INSTANCES];

/*******************************************************************************
 Global variables  
 *******************************************************************************/
tmcRpo_ConfigParameters_s  mcRpoI_ConfigParameters_gas[ROTOR_POSITION_INSTANCES] = 
{
    ROTOR_POSITION_MODULE_A_CONFIG,
#if( 2u == ROTOR_POSITION_INSTANCES )
    ROTOR_POSITION_MODULE_B_CONFIG
#endif
};


/*******************************************************************************
 Private Functions  
 *******************************************************************************/
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
    

/*! \brief Phase Calculation
 *
 * 
 * 
 */
void mcRpo_RotorPositionCalculate(  tmcRpo_StateVariables_s  * const pState,
                                                        tmcRpo_OutputPorts_s * const pOutput 
                                                     )
{  
    float tmp1 = 0.0f;
    
    tmp1  = mcRpoI_InverseTangent( pState->Eb, pState->Ea );    
       
    if( 0.0 < pState->WeHat)
    {
        *pOutput->angle = tmp1 - (float)CONSTANT_PiBy2;
    } 
    else
    {
        *pOutput->angle = tmp1 + (float)CONSTANT_PiBy2;
    }
    
    mcLib_WrapAngleTo2Pi( pOutput->angle); 
    
    /* dTH cal. */
    tmp1 = (*pOutput->angle) - (pState->zTH);   
    if(-CONSTANT_Pi > tmp1)
    {
        pState->dTH = tmp1 + CONSTANT_2Pi;
    } 
    else if(CONSTANT_Pi < tmp1)
    {
        pState->dTH = tmp1 - CONSTANT_2Pi;
    } else
    {
        pState->dTH = tmp1;
    }
          
    /* Latch TH */
    pState->zTH = *pOutput->angle;
    
}

/*! \brief Speed Calculation
 *
 * 
 * 
 */
void mcRpo_RotorSpeedCalculate( tmcRpo_Parameters_s    * const pParam,
                                                    tmcRpo_StateVariables_s  * const pState,
                                                    tmcRpo_OutputPorts_s * const pOutput 
                                                   )
{ 
    float tmp1;
    uint16_t tmp2;
    
    /* Update FIFO. */
    tmp1 = pState->dTH;
    tmp2 = pState->cntFIFO;
    pState->FIFOdTH[tmp2] = tmp1;
    
    if(pParam->cnt1ms > tmp2)
    {
        (pState->cntFIFO)++;
    } 
    else
    {
        pState->cntFIFO = 0u;
    }
    
    /* Accumulate dTH for 1ms. */
    tmp2 = pState->cntFIFO;
    pState->SUMdTH +=  tmp1 - pState->FIFOdTH[tmp2];
    /* Cal. electric angular speed @ rad/s. */
    pState->WeRaw = pState->SUMdTH * CONSTANT_1By1ms;
    /* LPF */
    pState->WeHat = ((pParam->oneMinusWcTs) * (pState->WeHat)) + ((pParam->WcTs) * (pState->WeRaw));

    *pOutput->speed = pState->WeHat;
}

/*******************************************************************************
 Interface Functions  
 *******************************************************************************/

/*! \brief Reduced order Luenberger observer ( ROLO ) initialization
 * 
 * Details.
 * Reduced order Luenberger observer ( ROLO ) initialization
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
tStd_ReturnType_e mcRpoI_RotorPositionCalculationInit( tmcRpo_ConfigParameters_s * const rolParam )
{
    tmcRpo_Parameters_s * pParam;
    
    /* Initialize input ports */
    mcRpo_InputPorts_mas[rolParam->Id] = rolParam->inPort;
    
    /* Initialize output ports */
    mcRpo_OutputPorts_mas[rolParam->Id] = rolParam->outPort;
    
    /* Initialize ROLO parameters */
#if ( ENABLE == DEVELOPER_MODE )
    pParam = &mcRpo_Parameters_mas[rolParam->Id];
    pParam->Rs  =  rolParam->userParam.Rs;
    pParam->Ls  =  rolParam->userParam.Ls;
    pParam->H   = rolParam->userParam.H;
    pParam->Ts  =  rolParam->userParam.Ts;     
    pParam->Wc  =  rolParam->userParam.Wc; 
    pParam->oneMinusH   =  1.0f - pParam->H; 
    pParam->HLsByTs   =  pParam->H * pParam->Ls / pParam->Ts;
    pParam->HLsByTsMinusRs =  pParam->HLsByTs - pParam->Rs;
    pParam->WcTs  =  pParam->Wc * pParam->Ts;
    pParam->oneMinusWcTs   =  1.0f - pParam->WcTs;
    pParam->cnt1ms  = 0.001/ pParam->Ts;  
#else 
    pParam = &mcRpo_Parameters_mas[rolParam->Id];
    pParam->Rs  =  CONFIG_MotorPerPhaseResistanceInOhm;
    pParam->Ls  =  CONFIG_MotorPerPhaseInductanceInHenry;
    pParam->H   = CONFIG_RoloHGain;
    pParam->Ts  =  CONFIG_RoloAlgorithmCycleTime;     
    pParam->Wc  =  CONFIG_RoloSpeedFilterCornerFrequency; 
    pParam->oneMinusH   =  CONSTANT_1MinusHGain; 
    pParam->HLsByTs   =  CONSTANT_HLsByTs;
    pParam->HLsByTsMinusRs =  CONSTANT_HLsByTsMinusRs;
    pParam->WcTs  =  CONSTANT_WcTs;
    pParam->oneMinusWcTs   =  CONSTANT_OneMinusWcTs;
    pParam->cnt1ms  = CONSTANT_NumberOfSamplesIn1ms;  
#endif    

    return returnType_Passed;   
}


/*! \brief Reduced order Luenberger observer ( ROLO ) run
 * 
 * Details.
 * Reduced order Luenberger observer ( ROLO ) run
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationRun( const tmcRpo_InstanceId_e Id )
{
    float ualpha, ubeta;
    tmcRpo_InputPorts_s * pInput;
    tmcRpo_OutputPorts_s * pOutput;
    tmcRpo_StateVariables_s * pState;
    tmcRpo_Parameters_s * pParam;
    
    /* Assign the pointers to local variables for easier readability and faster execution*/
    pInput = &mcRpo_InputPorts_mas[Id];
    pOutput = &mcRpo_OutputPorts_mas[Id]; 
    pState = &mcRpo_StateVariables_mas[Id]; 
    pParam = &mcRpo_Parameters_mas[Id];
      
    /* Determine Za */
    ualpha  = ( *pInput->ualpha ) * ( *pInput->umax );
    ubeta  = ( *pInput->ubeta ) * ( *pInput->umax );
    pState->Za  =  ( pParam->oneMinusH * pState->Za )
                  +  ( pParam->HLsByTsMinusRs * ( pParam->H * (*pInput->ialpha ) - pState->WeHat * pParam->Ts * (*pInput->ibeta)))
                  +  ( pParam->H * ualpha - pState->WeHat * pParam->Ts * ubeta );
      
    /* Determine Zb */
    pState->Zb  =  ( pParam->oneMinusH * pState->Zb )
                  +  ( pParam->HLsByTsMinusRs * ( pParam->H * (*pInput->ibeta) + pState->WeHat * pParam->Ts * (*pInput->ialpha)))
                  +  ( pParam->H * ubeta  + pState->WeHat * pParam->Ts * ualpha );            

    /* Determine alpha axis back EMF */   
    pState->Ea  = pState->Za - pParam->HLsByTs * (*pInput->ialpha) + pState->WeHat * pParam->Ls * (*pInput->ibeta);

    /* Determine beta axis back EMF */
    pState->Eb  = pState->Zb - pParam->HLsByTs * (*pInput->ibeta) - pState->WeHat * pParam->Ls * (*pInput->ialpha);

    /* Phase Estimation  */
    mcRpo_RotorPositionCalculate( pState, pOutput);

    /* Speed Calculation */
    mcRpo_RotorSpeedCalculate( pParam, pState, pOutput );

}

/*! \brief Reduced order Luenberger observer ( ROLO ) reset
 * 
 * Details.
 * Reduced order Luenberger observer ( ROLO ) reset
 * 
 * @param[in]: 
 * @param[in/out]:
 * @param[out]:
 * @return:
 */
void mcRpoI_RotorPositionCalculationReset( const tmcRpo_InstanceId_e Id )
{
    uint8_t index = 0;

    /* Reset ROLO Instance */
    mcRpo_StateVariables_mas[Id].Za   =   0.0f;
    mcRpo_StateVariables_mas[Id].Zb   =   0.0f;
    mcRpo_StateVariables_mas[Id].Ea   =   0.0f;
    mcRpo_StateVariables_mas[Id].Eb   =   0.0f;
    mcRpo_StateVariables_mas[Id].zTH  =  0.0f;
    mcRpo_StateVariables_mas[Id].WeHat   =   0.0f;
    mcRpo_StateVariables_mas[Id].WeRaw   =   0.0f;
    mcRpo_StateVariables_mas[Id].SUMdTH  =   0.0f ;
    mcRpo_StateVariables_mas[Id].cntFIFO   =   0u ;

    for( index = 0; index < CONSTANT_SpeedFifoBufferCount; index++ )
    {
        mcRpo_StateVariables_mas[Id].FIFOdTH[index]  = 0.0f ;
    }
}
