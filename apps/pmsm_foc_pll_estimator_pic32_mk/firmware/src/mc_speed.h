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
    uint8_t s_ControlStatus_e;
    float   n_openLoopSpeed_f32;
}tMCSPE_INPUT_SIGNAL_S;


typedef struct 
{
    float potFiltered;
}tMCSPE_STATE_SIGNAL_S;

typedef struct 
{
    float potReading;
    float commandRpm;
    float commandSpeed;
}tMCSPE_OUTPUT_SIGNAL_S;
typedef struct 
{
    float filterParam;
    float pot2SpeedRatio;
    float minSpeed;
}tMCSPE_PARAMETERS_S;


/******************************************************************************/
/*                       INTERFACE VARIABLES                                  */
/******************************************************************************/
extern tMCSPE_OUTPUT_SIGNAL_S gMCSPE_OutputSignals;


/******************************************************************************/
/*                       INTERFACE FUNCTIONS                                  */
/******************************************************************************/

/******************************************************************************/
/* Function name: MCSPE_InitializeSpeedControl                                */
/* Function parameters: None                                                  */
/* Function return: uint8_t                                                   */
/* Description: Reset speed control state variables                           */
/******************************************************************************/
extern void  MCSPE_InitializeSpeedControl(void);


/******************************************************************************/
/* Function name: MCSPE_SpeedCommand                                          */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Determines the speed command from external source             */
/*                      or potentiometer                                      */
/******************************************************************************/
extern void MCSPE_SpeedCommand( void );


/******************************************************************************/
/* Function name: MCSPE_ResetSpeedControl                                     */
/* Function parameters: None                                                  */
/* Function return: uint8_t                                                   */
/* Description: Reset speed control state variables                           */
/******************************************************************************/
extern void  MCSPE_ResetSpeedControl(void);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MC_SPEED_H */

