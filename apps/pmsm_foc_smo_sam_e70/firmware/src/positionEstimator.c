/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    positionEstimator.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.

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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#if 0
#include "mc_app.h"
#endif
#include "positionEstimator.h"


/* global variable definitions */
static tagSMO SMOdata;
static tagEstimatorPara estimatorPara;
static tagStateCtrl estimatorState;
static tagDynFilter dynFilterAlpha1;
static tagDynFilter dynFilterAlpha2;
static tagDynFilter dynFilterBeta1;
static tagDynFilter dynFilterBeta2;
static float WeObs;  /* electric angular speed for BEMF observer */
static float WcFil;  /* cross frequency for BEMF filter */
static float coefX;  /* input coefficient of dynamic filter */
static float coefY;  /* output coefficient of dynamic filter */
/* coefficients of BEMF observer */
static float a1BEMFobs;
static float a2BEMFobs;
static float b1BEMFobs;
static float b2BEMFobs;
#if 0
static uint16_t tmp16_1;
static float tmpF_1;
static uint8_t stateLatch;
#endif


inline static float floatAbs(float x)
{
    float tmp;
    
    if(0.0 < x)
    {
        tmp = x;
    } 
    else
    {
        tmp = -x;
    }
    
    return tmp;
}


/* Chebyshev approximation of sin(x), x is in [-pi/2, pi/2]:
 * 0.999978675*x - 0.1664971*x^3 + 0.00799224*x^5
*/
inline float sinChebyshevF(float x)
{
    float y;
    float tmp1;
    float tmp2;
    
    /* We assume the input x is in [-pi, pi], no guard locates here. */
    /* Map the input angle into [-pi/2, pi/2]. */
    if((float)M_PI_2 < x)
    {
        y = (float)M_PI - x;
    } 
    else if((float)(-M_PI_2) > x)
    {
        y = (float)(-M_PI) - x;
    } 
    else
    {
        y = x;
    }
    
    tmp1 = y * y;
    tmp2 = y * (CHEB_SIN_1 + tmp1 * (CHEB_SIN_3 + (tmp1 * CHEB_SIN_5)));
    
    return tmp2;
}


inline float cosChebyshevF(float x)
{
    float y;
    float tmp1;
    
    /* We assume the input x is in [-pi, pi], no guard locates here. */
    /* Map the input angle into [pi/2, -pi/2]. */    
    if(0.0 > x)
    {
        y = (float)M_PI_2 + x;
    } 
    else
    {
        y = (float)M_PI_2 - x;
    }
    
    tmp1 = sinChebyshevF(y);
    
    return tmp1;
}


inline static void resetSMO(tagSMO *SMOdataP)
{
    SMOdataP->IalphaHat = 0.0;
    SMOdataP->IbetaHat = 0.0;
    SMOdataP->EalphaHat = 0.0;
    SMOdataP->EbetaHat = 0.0;
}


inline static void loadSMO(tagObserverInput * observerInputP, tagSMO *SMOdataP)
{
#if 0
    SMOdataP->Ialpha = ParkParm.Ialpha;
    SMOdataP->Ibeta = ParkParm.Ibeta;
    SMOdataP->Ualpha = ParkParm.MaxPhaseVoltage * ParkParm.Valpha;
    SMOdataP->Ubeta = ParkParm.MaxPhaseVoltage * ParkParm.Vbeta;
#else
    SMOdataP->Ialpha = observerInputP->Ialpha;
    SMOdataP->Ibeta = observerInputP->Ibeta;
    SMOdataP->Ualpha = observerInputP->Ualpha;
    SMOdataP->Ubeta = observerInputP->Ubeta;
#endif
    SMOdataP->We = WeObs;
}

/* description: current observer
 * input:
 *      I -- current feedback
 *      U -- imposed voltage
 *      Ehat -- estimated BEMF
 *      Ihat -- estimated current
 * output:
 *      Ihat -- estimated current
 *      B -- BEMF estimation error */
#if 0  /* forward difference equivalence */
inline static void currentObserver(float I, float U, float Ehat, float * Ihat, float * B)
{
    float tmp1;
    float tmp2;
    float Bintegral;
    
    tmp1 = I - *Ihat;
    
    if(RL_BOUNDARY_I < tmp1){  /* Itilde is above boundary layer. */
        *B = RL_M;
        Bintegral = RL_MTS;
    } else if(-RL_BOUNDARY_I > tmp1){  /* Itilde is below boundary layer. */
        *B = -RL_M;
        Bintegral = -RL_MTS;
    } else{  /* Itilde is inside boundary layer. */
        *B = tmp1 * RL_MDBI;
        Bintegral = tmp1 * RL_MDBITS;
    }
    
    tmp1 = U - Ehat - ((*Ihat)*RL_RS);
    tmp2 = tmp1 * RL_TSDLS;
    *Ihat = *Ihat + tmp2 + Bintegral;
}
#else  /* ZOH discretization */
inline static void currentObserver(float I, float U, float Ehat, float * Ihat, float * B)
{
    float tmp1;
    
    tmp1 = I - *Ihat;
    
    if(estimatorPara.boundaryI < tmp1)
    {  /* Itilde is above boundary layer. */
        *B = estimatorPara.m;
    } 
    else if(-estimatorPara.boundaryI > tmp1)
    {  /* Itilde is below boundary layer. */
        *B = -estimatorPara.m;
    } 
    else
    {  /* Itilde is inside boundary layer. */
        *B = tmp1 * estimatorPara.mdbi;
    }
    
    *Ihat = (estimatorPara.aIObs * (*Ihat)) + (estimatorPara.b1IObs * Ehat) + (estimatorPara.b2IObs * U) + (estimatorPara.b3IObs * (*B));
}
#endif

/* description: calculate coefficients of BEMF observer
 * input:
 *      We -- electric angular speed
 * global input:
 *      RL_TS
 *      RL_LS
 *      RL_LAMBDA 
 * global output:
 *      a1BEMFobs 
 *      a2BEMFobs 
 *      b1BEMFobs
 *      b2BEMFobs */
inline static void BEMFobsCoeffCal(float We)
{
    float tmp1;
    float tmp2;

    if((RL_EPSILON_F > We) && (-RL_EPSILON_F < We))
    {  /* We is too small to estimate BEMF. */
        return;
    }
   
    tmp1 = We * estimatorPara.ts;   
    a1BEMFobs = cosChebyshevF(tmp1);
    a2BEMFobs = sinChebyshevF(tmp1);
    tmp1 = 1.0 - a1BEMFobs;
    tmp2 = estimatorPara.lambda / We;
    b1BEMFobs = ((tmp2 * a2BEMFobs) + tmp1) * estimatorPara.ls;
    b2BEMFobs = (a2BEMFobs - (tmp2 * tmp1)) * estimatorPara.ls;    
}


/* description: BEMF observer
 * input:
 *      E1hat -- estimated BEMF of the target axis  
 *      E2hat -- estimated BEMF of the other axis
 *      B1 -- BEMF estimation error of the target axis
 *      B2 -- BEMF estimation error of the other axis
 *      We -- electric angular speed
 * output:
 *      E1hat -- estimated BEMF of the target axis 
 * remark:
 *      Pay attention to the sign of B2 and E2hat when calling the function. */
#if 0  /* forward difference equivalence */
inline static void BEMFobserver(float * E1hat, float E2hat, float B1, float B2, float We){
    float tmp1;
    
    tmp1 = ((B1*RL_LAMBDA) + (B2*We)) * RL_LS;  /* It is a '+' for B2. */
    tmp1 = tmp1 + (E2hat*We);  /* It is a '+' for E2hat. */
    tmp1 = tmp1 * RL_TS;
    *E1hat = *E1hat + tmp1;
}
#else  /* ZOH discretization */
inline static void BEMFobserver(float * E1hat, float E2hat, float B1, float B2)
{
     *E1hat =  (a1BEMFobs * (*E1hat)) + (a2BEMFobs * E2hat) + (b1BEMFobs * B1) + (b2BEMFobs * B2);
}
#endif


inline static void exeSMO(tagSMO *SMOdataP)
{
    float zEalphaHat;
    
    currentObserver(SMOdataP->Ialpha, SMOdataP->Ualpha, 
        SMOdataP->EalphaHat, &SMOdataP->IalphaHat, &SMOdataP->Balpha);  /* Estimate Ialpha. */
    currentObserver(SMOdataP->Ibeta, SMOdataP->Ubeta, 
        SMOdataP->EbetaHat, &SMOdataP->IbetaHat, &SMOdataP->Bbeta);  /* Estimate Ibeta. */  
    zEalphaHat = SMOdataP->EalphaHat;  /* Latch last EalphaHat. */
    BEMFobsCoeffCal(SMOdataP->We);
    BEMFobserver(&SMOdataP->EalphaHat, -SMOdataP->EbetaHat, 
        SMOdataP->Balpha, SMOdataP->Bbeta);  /* Estimate Ealpha. */ 
    BEMFobserver(&SMOdataP->EbetaHat, zEalphaHat, 
        SMOdataP->Bbeta, -SMOdataP->Balpha);  /* Estimate Ebeta. */

}


inline static void BemfSMO(tagObserverInput * observerInputP)
{
    loadSMO(observerInputP, &SMOdata);

    exeSMO(&SMOdata);

}

/* description: Calculate coefficients of dynamic filter. */
inline static void WcCal(float Wc)
{
    float tmp1;
    tmp1 = Wc * estimatorPara.ts;
    coefX = tmp1 / (2+tmp1);
    coefY = (2-tmp1) / (2+tmp1);
}

inline static void loadFilter1(void)
{
    dynFilterAlpha1.x = SMOdata.EalphaHat;
    dynFilterBeta1.x = SMOdata.EbetaHat;
    #if 0
    dynFilterAlpha1.Wc = floatAbs(CtrlParm.VelRef);
    dynFilterBeta1.Wc = floatAbs(CtrlParm.VelRef);
    #endif
}

inline static void loadFilter2(void)
{
    dynFilterAlpha2.x = dynFilterAlpha1.y;
    dynFilterBeta2.x = dynFilterBeta1.y;
    #if 0
    dynFilterAlpha2.Wc = floatAbs(CtrlParm.VelRef);
    dynFilterBeta2.Wc = floatAbs(CtrlParm.VelRef);
    #endif
}

inline static void dynamicFilter(tagDynFilter * dynFilterDataP)
{
    float tmp1;
    tmp1 = coefX * (dynFilterDataP->x + dynFilterDataP->xLatch);
    dynFilterDataP->y = (coefY * dynFilterDataP->y) + tmp1;
    dynFilterDataP->xLatch = dynFilterDataP->x;
}

inline static void BemfFilter(void)
{
    #if 1
    WcCal(WcFil);
    #endif    
    loadFilter1();
    dynamicFilter(&dynFilterAlpha1);
    dynamicFilter(&dynFilterBeta1);
    loadFilter2();
    dynamicFilter(&dynFilterAlpha2);
    dynamicFilter(&dynFilterBeta2);
}


inline static void resetBemfFil(void)
{
    dynFilterAlpha1.xLatch = 0.0;
    dynFilterAlpha1.y = 0.0;
    dynFilterAlpha2.xLatch = 0.0;
    dynFilterAlpha2.y = 0.0;
    dynFilterBeta1.xLatch = 0.0;
    dynFilterBeta1.y = 0.0;
    dynFilterBeta2.xLatch = 0.0;
    dynFilterBeta2.y = 0.0;
}


/* description: Polynomial approximated atan function with float parameters and return value. */
inline static float polynmApproxAtanf(float tanVal)
{
    float z, zz;
    
    /* z should be inside [-1.0, 1.0]. */
    if(1.0f < tanVal)
    {
        z = 1.0f;
    } 
    else if(-1.0f > tanVal)
    {
        z = -1.0f;
    } 
    else
    {
        z = tanVal;
    }
    
    zz = z * z;
    
    return ((RL_A*zz + RL_B)*zz + RL_C)*z;
}


/* description: Polynomial approximated atan2 function with float parameters and return value. */
inline static float polynmApproxAtan2f(float y, float x)
{
    float tmp1, tmp2, z;

    tmp1 = floatAbs(y);
    tmp2 = floatAbs(x);
    z = (tmp1 > tmp2) ? (tmp1) : (tmp2);  /* Pick the max value from tmp1 and tmp2. */
    
    if(z < RL_EPSILON_F)
    {  /* Both y and x are too small. */
        return 0.0f;
    }
    
    if(tmp2 >= tmp1)
    {  /* abs(x) >= abs(y) */
        z = y / x;
        tmp2 = polynmApproxAtanf(z);
        if(x > 0.0f)
        {  /* -pi/2 ~ pi/2 */
            tmp1 = tmp2;
        } 
        else if(y > 0.0f)
        {
            tmp1 = tmp2 + (float)M_PI;
        } 
        else
        {
            tmp1 = tmp2 - (float)M_PI;
        }
    } 
    else
    {  /* abs(x) < abs(y) */
        z = x / y;
        tmp2 = polynmApproxAtanf(z);
        if(y > 0.0f)
        {
            tmp1 = -tmp2 + (float)M_PI_2;
        } 
        else
        {
            tmp1 = -tmp2 - (float)M_PI_2;
        }
    }
    
    return tmp1;
}


inline static void positionCal(tagPosition * positionDataP, float alpha, float beta, tagObserverInput * observerInputP)
{
    float tmp1;
    
    /* TH cal. */
#if APPROX_ATAN_ENABLE
    tmp1 = polynmApproxAtan2f(beta, alpha);  /* polynomial-approximated atan2f function */
#else
    tmp1 = atan2f(beta, alpha);  /* Standard-library atan2f function */   
#endif    
    
    /* Return value of atan2f locates in [-pi, pi]. */
#if BEMF_FIL_ENABLE
    if(0.0 > tmp1)
    {
        positionDataP->TH = tmp1 + RL_2PI;
    } 
    else
    {
        positionDataP->TH = tmp1;
    }
#else
    if( 0.0 < observerInputP->WeRef)
    {
        tmp1 = tmp1 - (float)M_PI_2;
    } 
    else
    {
        tmp1 = tmp1 + (float)M_PI_2;
    }
    
    if(0.0 > tmp1)
    {
        positionDataP->TH = tmp1 + RL_2PI;
    } 
    else if(RL_2PI < tmp1)
    {
        positionDataP->TH = tmp1 - RL_2PI;
    } 
    else
    {
        positionDataP->TH = tmp1;
    }    
#endif
    
    /* dTH cal. */
    tmp1 = (positionDataP->TH) - (positionDataP->zTH);   
    if(-M_PI > tmp1)
    {
        positionDataP->dTH = tmp1 + RL_2PI;
    } 
    else if(M_PI < tmp1)
    {
        positionDataP->dTH = tmp1 - RL_2PI;
    } else
    {
        positionDataP->dTH = tmp1;
    }
    
    /* THI cal. */
    positionDataP->THI = positionDataP->TH;
    
    /* THO cal. */
    tmp1 = positionDataP->THI + positionDataP->dTH;
    if(0.0 > tmp1)
    {
        positionDataP->THO = tmp1 + RL_2PI;
    }
    else if(RL_2PI < tmp1)
    {
        positionDataP->THO = tmp1 - RL_2PI;
    } 
    else
    {
        positionDataP->THO = tmp1;
    }
    
    /* Latch TH */
    positionDataP->zTH = positionDataP->TH;
}


inline static void speedCal(tagPosition * positionDataP, tagSpeed * speedDataP)
{
    float tmp1;
    uint16_t tmp2;
    
    /* Update FIFO. */
    tmp1 = positionDataP->dTH;
    tmp2 = speedDataP->cntFIFO;
    speedDataP->FIFOdTH[tmp2] = tmp1;
    
    if(estimatorPara.cnt1ms > tmp2)
    {
        (speedDataP->cntFIFO)++;
    } 
    else
    {
        speedDataP->cntFIFO = 0u;
    }
    
    /* Accumulate dTH for 1ms. */
    tmp2 = speedDataP->cntFIFO;
    speedDataP->SUMdTH +=  tmp1 - speedDataP->FIFOdTH[tmp2];
    /* Cal. electric angular speed @ rad/s. */
    speedDataP->WeRaw = speedDataP->SUMdTH * RL_1D1MS;
    /* LPF */
    speedDataP->WeHat = ((estimatorPara.oneMinusWcTs) * (speedDataP->WeHat)) + ((estimatorPara.wcTs) * (speedDataP->WeRaw));
#if 0
    /* Cal. mechanical angular speed @ RPM. */
    speedDataP->WmHat = speedDataP->WeHat * (estimatorPara.eleRadPsToMecRPM);
#endif
}


static void resetSpeedCal(tagSpeed * speedDataP)
{
    uint16_t tmp;
    
    speedDataP->cntFIFO = 0u;
    
    for(tmp=0u; estimatorPara.cnt1ms >= tmp; tmp++)
    {
        speedDataP->FIFOdTH[tmp] = 0.0;
    }
}


inline static void motionCal(tagObserverInput * observerInputP)
{
#if BEMF_FIL_ENABLE
    positionCal(observerInputP->positionDataP, dynFilterAlpha2.y, dynFilterBeta2.y, observerInputP);
#else
    positionCal(observerInputP->positionDataP, SMOdata.EalphaHat, SMOdata.EbetaHat, observerInputP);    
#endif
    speedCal(observerInputP->positionDataP, observerInputP->speedDataP);
}


inline static void paraCal(tagInputPara * inputParaP, tagEstimatorPara * estParaP)
{
    float tmp1;

    estParaP->boundaryI = inputParaP->boundaryI;
    estParaP->m = inputParaP->m;
    estParaP->lambda = inputParaP->lambda;
    estParaP->ls = inputParaP->ls;
    estParaP->speedRefCnt = (uint16_t)(inputParaP->pwmFreq * inputParaP->speedRefTime);
    estParaP->cnt1ms = (uint16_t)(inputParaP->pwmFreq * 0.001);
    estParaP->mdbi = (float)(inputParaP->m / inputParaP->boundaryI);
    estParaP->ts = (float)(1.0 / inputParaP->pwmFreq);
    estParaP->wcTs = (float)(inputParaP->wcSpeedFil * estParaP->ts);
    estParaP->oneMinusWcTs = (float)(1.0 - estParaP->wcTs);
    tmp1 = (float)(1.0 / inputParaP->P);  /* 1 / #_of_pole_pairs */
    estParaP->eleRadPsToMecRPM = (float)(tmp1 * 60.0 / RL_2PI);
    tmp1 = inputParaP->expRsLsTs;
    estParaP->aIObs = tmp1;
    estParaP->b1IObs = (tmp1 - 1.0) / inputParaP->rs;
    estParaP->b2IObs = -estParaP->b1IObs;
    estParaP->b3IObs = inputParaP->ls * estParaP->b2IObs;   
}


void resetEstimator(tagObserverInput * observerInputP)
{
    estimatorState.state = 0u;
    resetSMO(&SMOdata);
    resetBemfFil();
    resetSpeedCal(observerInputP->speedDataP);
    paraCal(observerInputP->para, &estimatorPara);
    estimatorState.cnt1 = 0u;    
}

inline void motionEstimator(tagObserverInput * observerInputP)
{
    float tmp;
    
    if(1u == observerInputP->startObs)
    {  /* BEMF observer reset instruction is received. */ 
        observerInputP->startObs = 0u;
        estimatorState.state = 0u;
    }
    
    switch(estimatorState.state)
    {
        case 0u:  /* initialization */
            resetSMO(&SMOdata);
            resetBemfFil();
            resetSpeedCal(observerInputP->speedDataP);
            paraCal(observerInputP->para, &estimatorPara);
            estimatorState.cnt1 = 0u;
            estimatorState.state = 1u;
            break;
        case 1u:  /* wait for BEMF observer trigger */
            #if 0
                if(0u == MC_APP_MC_CONTROL.bit.OpenLoop){  /* be in close-loop mode */
            #endif
            if(2u == observerInputP->startObs)
            {  /* BEMF observer start instruction is received. */      
                estimatorState.cnt1++;
            }
            if(1u <= estimatorState.cnt1)
            {
                estimatorState.cnt1 = 0u;
                observerInputP->startObs = 0u;
                estimatorState.state = 2u;
            }
            break;
        case 2u:  /* BEMF observer uses speed reference. */
            tmp = observerInputP->WeRef;
            WeObs = tmp;
            BemfSMO(observerInputP);
            #if BEMF_FIL_ENABLE
                WcFil = floatAbs(tmp);
                BemfFilter();
            #endif
            motionCal(observerInputP);
            /**/
            estimatorState.cnt1++;
            if(estimatorPara.speedRefCnt <= estimatorState.cnt1)
            {
                estimatorState.cnt1 = 0u;
                estimatorState.state = 3u;
            }
            break;
        case 3u:  /* BEMF observer uses estimated speed. */
            WeObs = observerInputP->speedDataP->WeHat; 
            BemfSMO(observerInputP);
            #if BEMF_FIL_ENABLE            
                #if 0
                    /* It is not stable for BEMF filter to use estimated speed as cross frequency;
                    * But a strong filter onto estimated speed can be stable. */
                    WcFil = floatAbs(observerInputP->speedDataP->WeHat);
                #else
                    WcFil = floatAbs(observerInputP->WeRef);
                #endif
                BemfFilter();
            #endif
            motionCal(observerInputP);
            break;
        default:
            break;
    }
}


/* End of file */