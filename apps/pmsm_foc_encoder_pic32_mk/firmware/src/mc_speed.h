/* 
 * File:   mc_speed.h
 * Author: I51152
 *
 * Created on July 19, 2019, 3:30 PM
 */

#ifndef MC_SPEED_H
#define	MC_SPEED_H

typedef struct 
{
         float filterParam;
         float pot2SpeedRatio;
         float minSpeed;
}tMCSPE_PARAM_S;


extern uint8_t SpeedLoopActive;
extern void MCSPE_ResetSpeedControl( void );
extern void MCSPE_InitializeSpeedControl( void );
extern void MCSPE_SpeedCommand( void );

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MC_SPEED_H */

