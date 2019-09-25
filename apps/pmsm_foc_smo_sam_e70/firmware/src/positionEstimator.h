#ifndef _POSITION_ESTIMATOR_H
#define _POSITION_ESTIMATOR_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "definitions.h"                // SYS function prototypes
#include "mc_app.h"
#include "X2CScope.h"
#include "X2CScopeCommunication.h"


/* User input Macro */
#define APPROX_ATAN_ENABLE 1u  /* Is approximated atan2 function enabled (for faster execution time)? */
#define BEMF_FIL_ENABLE 1u  /* Is dynamic BEMF filter enabled? */
/* Constant Macro */
#define RL_2PI (float)(2.0*M_PI)
#define RL_1D1MS ((float)1000.0)
#define RL_EPSILON_F ((float)0.00000001)  /* small float value for zero-check */
#define RL_A ((float)0.0776509570923569)
#define RL_B ((float)-0.287434475393028)
#define RL_C (float)(M_PI_4 - RL_A - RL_B)
#define CHEB_SIN_1 (float)0.999978675
#define CHEB_SIN_3 (float)-0.1664971
#define CHEB_SIN_5 (float)0.00799224

#define SPEED_FIFO_COUNT   (41U)


/* Type definitions */
typedef struct {
    /* input information */
    float Ialpha;
    float Ibeta;
    float Ualpha;
    float Ubeta;
    float We;  /* electric angular speed */
    /* ouput estamation */
    float IalphaHat;
    float IbetaHat;
    float EalphaHat;
    float EbetaHat;
    /* intermediate variables */
    float Balpha;  /* Ealpha tilde*/
    float Bbeta;  /* Ebeta tilde*/
} tagSMO;

typedef struct{
    /* input */
    float x;  /* raw signal */
    float Wc;  /* cross frequency */
    /* output */
    float y;  /* filtered signal */
    /* intermediate variables */
    float xLatch;
} tagDynFilter;

typedef struct{
    float TH;  /* estimated electric rotor angle */
    float THI;  /* rotor angle for 3-2 transform */
    float THO;  /* rotor angle for 2-3 transform */
    float zTH;  /* last TH */
    float dTH;  /* difference of TH */
} tagPosition;

typedef struct{
    float WeHat;  /* estimated electric rotor angular speed */
    float WmHat;  /* estimated mechanical rotor angular speed */
    float WeRaw;  /* un-filtered estimated We */
    float SUMdTH;
    uint16_t cntFIFO;
    /* The max supported loop time is 25us --> 40u for 1ms. */
    float FIFOdTH[SPEED_FIFO_COUNT];  /* FIFO for dTH */    
} tagSpeed;

typedef struct{
    uint8_t state;
    uint8_t isStateChanging;
    uint16_t cnt1;
} tagStateCtrl;

typedef struct{
    float boundaryI;  /* boundary layer of current observer */
    float m;  /* gain of current observer */
    float lambda;  /* desired eigenvalue of BEMF observer */
    float wcSpeedFil;  /* cross frequency of speed filter */
    float pwmFreq;  /* sampling frequency */
    float rs;  /* Resistance in Ohms */
    float ls;  /* Inductance in Henrys */
    float P;  /* # of pole pairs */
    float speedRefTime;  /* The time period where BEMF observer uses speed reference. */
    float expRsLsTs;  /* exp(-Rs/Ls*Ts) */
} tagInputPara;

typedef struct{
    float boundaryI;  /* boundary layer of current observer */
    float m;  /* gain of current observer */
    float lambda;  /* desired eigenvalue of BEMF observer */
    float ls;  /* Inductance in Henrys */
    float speedRefCnt;
    float cnt1ms;
    float mdbi;
    float ts;
    float wcTs;
    float oneMinusWcTs;
    float eleRadPsToMecRPM;
    float aIObs;
    float b1IObs;
    float b2IObs;
    float b3IObs;
} tagEstimatorPara;

typedef struct{
    float Ialpha;
    float Ibeta;
    float Ualpha;
    float Ubeta;
    float WeRef;  /* electric angular speed reference */
    uint16_t startObs;  /* (flag) start observer: 0u -- no start; 0xFFFFu -- start. */
    tagPosition * positionDataP;
    tagSpeed * speedDataP;
    tagInputPara * para;
} tagObserverInput;

/* global variable declaration */
extern tagPosition positionData;
extern tagSpeed speedData;
extern tagObserverInput observerInput;

/* function declaration */
void motionEstimator(tagObserverInput * observerInputP);
void resetEstimator(tagObserverInput * observerInputP);


#endif  /* _POSITION_ESTIMATOR_H */

