
/*******************************************************************************
  Motor Control Library Interface Header

  Company:
    Microchip Technology Inc. 

  File Name:  
    mc_Lib.h

  Summary:
    Motor Control Library Header File.

  Description:
    This file describes the macros, structures and APIs used by Motor Control Library for SAMD5x 
*******************************************************************************/


// DOM-IGNORE-BEGIN   
/*******************************************************************************
Copyright (c) <2018> released Microchip Technology Inc.  All rights reserved.

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
#include <stdint.h>
#ifndef _MCLIB_H
#define _MCLIB_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Constants
// *****************************************************************************
// *****************************************************************************



#define 	SQRT3_BY2     			(float)0.866025403788  // Defines value for sqrt(3)/2
#define 	ONE_BY_SQRT3     		(float)0.5773502691    // Defines value for 1/sqrt(3)

#define 	ANGLE_2PI              	(2*M_PI)               // Defines value for 2*PI
#define 	TABLE_SIZE      		256                    // Defines the size of sine/cosine look up table
#define 	ANGLE_STEP      		(float)((float)ANGLE_2PI/(float)TABLE_SIZE) //Defines the angle resolution in the sine/cosine look up table
#define     ONE_BY_ANGLE_STEP       (float)(1/ANGLE_STEP)
// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/*  Defines structures which contain input and output parameters for the motor control APIs
*/


//Structure containing variables used in calculating Space Vector PWM Duty cycles
typedef struct 
{
    float   PWMPeriod;  // PWM Period in PWM Timer Counts
    float   Vr1;        // Normalized Phase A voltage obtained using modified Clarke transform
    float   Vr2;        // Normalized Phase B voltage obtained using modified Clarke transform
    float   Vr3;        // Normalized Phase C voltage obtained using modified Clarke transform
    float	T1;         // Length of Vector T1
    float   T2;         // Length of Vector T2
    float   Ta;         // Ta = To/2 + T1 + T2
    float   Tb;         // Tb = To/2 + T2
    float   Tc;         // Tc = To/2
    float 	dPWM_A;      // Phase A Duty Cycle
    float   dPWM_B;      // Phase B Duty Cycle
    float   dPWM_C;      // Phase C Duty Cycle
} mcParam_SVPWM;


//Structure containing variables used as control references for Current PI and Speed PI
typedef struct 
{
    float   VelInput;   // Speed Input. Speed Input passed through a rate limiter gives Speed Reference
    float   VelRef;		// Speed Reference. 
    float   IdRef; 		// D axis Current (Flux) reference value
    float   IdRef_FW_Raw;  // Field Weakening D axis Current Reference (Raw)
    float   IdRef_FW_Filtered; // Field Weakening D axis Current (Flux) reference Filtered
    float   qKfilterIdRef;  // D axis Current Reference Filter Coefficient
    float   IqRef; 		// Q axis Current (Torque) reference value
	float   Diff;		// Difference between Speed Input and Speed Reference
	float 	IqRefmax;	// Maximum Q axis current

} mcParam_ControlRef;

//Structure containing variables used in Field Oriented Control
typedef struct 
{
    float   OpenLoopAngle;      // Rotor Angle in Radians
    float   DCBusVoltage;   // Measured DC Bus voltage in volts
    float   MaxPhaseVoltage;// Maximum Phase to Neutral Voltage
	float	VdqNorm;        // Normalized vector sum of D and Q axis voltage
	float	MaxVoltageCircleSquared;    // Square of Maximum Phase Voltage  
	float   VdSquaredDenorm;            // Square of D axis Voltage in Volts
	float	VqSquaredDenorm;            // Square of Q axis Voltage in Volts
	float	VqRefVoltage;               // Estimated Q axis voltage during Flux Weakening in Volts
    float   Vqs;
    float   Vds;

} mcParam_FOC;

//Structure containing variables used in position and speed calculation
typedef struct
{
  volatile uint16_t elec_rotation_count;
  float rotor_angle_rad_per_sec;
  int16_t prev_position_count;
  int16_t present_position_count;
  uint16_t QDECcnt;
  uint16_t QDECcntZ;
  uint16_t posCnt;
  uint16_t posCompensation;
  uint32_t posCntTmp;
  
}MCAPP_POSITION_CALC;

//Structure containing  component values for 2 Phase Stationary Reference Frame
typedef struct 
{
    float   alpha;     // Alpha axis component in 2 Phase Stationary Frame 
    float   beta;      // Beta axis component  in 2 Phase Stationary Frame

} mcParam_AlphaBeta;

//Structure containing component values for 2 Phase Rotating Reference Frame
typedef struct 
{
    float   d;     // D axis component in 2 Phase Rotating Frame 
    float   q;      // Q axis component  in 2 Phase Rotating Frame

} mcParam_DQ;

//Structure containing component values for 3 Phase Stationary Reference Frame
typedef struct 
{
    float   a;      // A axis component in 3 Phase Stationary Frame 
    float   b;      // B axis component in 3 Phase Stationary Frame 
    float   c;      // C axis component in 3 Phase Stationary Frame 
} mcParam_ABC;

//Structure containing variables used for Sine & Cosine calculation 
typedef struct 
{
    float   Angle; // Angle in radians whose sine/cosine needs to be calculated
    float   Sin;   // Sine(Angle)
    float   Cos;   // Cosine(Angle) 
} mcParam_SinCos;


// Structure containing variables used by PI Compensator
typedef struct 
{
    float   qdSum;  // Integrator Output of the PI Compensator
    float   qKp;    // Proportional Coefficient of the PI Compensator
    float   qKi;    // Integral Coefficient of the PI Compensator
    float   qKc;    // Anti-windup Coefficient of the PI Compensator
    float   qOutMax;// Max output limit of the PI Compensator
    float   qOutMin;// Min output limit of the PI Compensator
    float   qInRef; // Reference input of the PI Compensator
    float   qInMeas;// Feedback input of the PI Compensator
    float   qOut;   // Proportional + Integral Output of the PI Compensator
    float   qErr;   // Error input of the PI Compensator
    float   p_out;
    float   i_out;
} mcParam_PIController;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
/*  This section describes the APIs used for Motor Control Applications in a 32 bit MCU with FPU
*/


// *****************************************************************************
/* Function:
    void mcLib_ParkTransform(mcParam_AlphaBeta *alphabetaParam ,
                             mcParam_SinCos *scParam,  mcParam_DQ *dqParam)

  Summary:
  Park Transform

  Description:
 This function calculates Park Transform.
 
  Precondition: 
    None.
 

  Parameters:
    *alphabetaParam     - Structure pointer pointing to the mcParam_AlphaBeta 
                          type structure containing Alpha-Beta axis
                          components(2 Phase Stationary Frame) 

    *scParam            - Structure pointer pointing to the mcParam_SinCos type 
                          structure containing parameters related to Sine 
                          and Cosine Calculations.
 
    *dqParam            - Structure pointer pointing to the mcParam_DQ type 
                          structure containing D-Q axis 
                          components(2 Phase Rotating Frame). 
    
  Returns:
    None.

  Example:
    <code>
    mcParam_AlphaBeta mcApp_I_AlphaBetaParam;
    mcParam_SinCos mcApp_SincosParam; 
    mcParam_DQ mcApp_I_DQParam; 
 
    // Angle input = 1.571 radians (90 degree)
	mcApp_SincosParam.Angle = (float) 1.571;
    
    //Calculate Sine and Cosine using mcLib_SinCosGen
    mcLib_SinCosGen(&mcApp_SincosParam);
  
      
    // Update Alpha and Beta axis currents
    mcApp_I_AlphaBeta.alpha = 1.2;
    mcApp_I_AlphaBeta.beta = 0.8;  
    

    // Calculate Park transform using mcLib_ParkTransform. The result
    // of the transform is in mcApp_I_DQParam.d and mcApp_I_DQParam.q
     mcLib_ParkTransform(&mcApp_I_AlphaBetaParam,  &mcApp_SincosParam, &mcApp_I_DQParam);
    </code>

  Remarks: 
    None.
*/

void mcLib_ParkTransform(mcParam_AlphaBeta *alphabetaParam ,mcParam_SinCos *scParam,  mcParam_DQ *dqParam);





// *****************************************************************************
/* Function:
    void mcLib_InvParkTransform(mcParam_DQ *dqParam, mcParam_SinCos *scParam, 
                               mcParam_AlphaBeta *alphabetaParam)

  Summary:
 Inverse Park Transform

  Description:
 This function calculates inverse Park Transform

 
  Precondition: 
    None.
 

  Parameters:
    *dqParam           - Structure pointer pointing to the mcParam_DQ type 
                         structure containing D-Q axis components
   
    *scParam           - Structure pointer pointing to the mcParam_SinCos type 
                         structure containing parameters related to Sine 
                         and Cosine Calculations.

 
    *alphabetaParam    - Structure pointer pointing to the mcParam_AlphaBeta 
                         type structure containing Alpha-Beta axis
                         components(2 Phase Stationary Frame).
  Returns:
    None.

  Example:
    <code>
    mcParam_DQ                          mcApp_V_DQParam;
    mcParam_SinCos                      mcApp_SincosParam;
    mcParam_AlphaBeta                   mcApp_V_AlphaBetaParam;
  
 
    // Angle input = 1.571 radians (90 degree))
	mcApp_SincosParam.Angle = (float) 1.571;
    
    //Calculate Sine and Cosine using mcLib_SinCosGen
    mcLib_SinCosGen(&mcApp_SincosParam);
  
 
    
    // Update normalized D axis and Q axis values.
    mcApp_V_DQParam.d = 0;
    mcApp_V_DQParam.q = 0.8;  
    

    // Calculate inverse Park transform using mcLib_InvParkTransform. The result
    // of the transform is in mcApp_V_AlphaBetaParam.alpha and
    // mcApp_V_AlphaBetaParam.beta
    mcLib_InvParkTransform(&mcApp_V_DQParam,&mcApp_SincosParam,
                           &mcApp_V_AlphaBetaParam);
    </code>

  Remarks: 
    None.
*/
void mcLib_InvParkTransform(mcParam_DQ *dqParam, mcParam_SinCos *scParam,
                            mcParam_AlphaBeta *alphabetaParam);

// *****************************************************************************
/* Function:
    void mcLib_ClarkeTransform(mcParam_ABC *abcParam, mcParam_AlphaBeta *alphabetaParam)

  Summary:
 Clarke Transform

  Description:
 This function calculates Clarke Transform

  Precondition: 
    None.
 

  Parameters:
    *abcParam           - Structure pointer pointing to the mcParam_ABC type 
                          structure containing A,B,C axis
                          components (3 Phase Stationary Frame)
    
    *alphabetaParam     - Structure pointer pointing to the mcParam_AlphaBeta 
                          type structure containing Alpha-Beta axis
   
      Returns:
        None.

  Example:
    <code>
    mcParam_ABC mcApp_I_ABCParam;
    mcParam_AlphaBeta mcApp_I_AlphaBetaParam;
    
    //Update Ia and Ib current values 
    mcApp_I_ABCParam.a = 1.2; // Phase A current in Amperes
    mcApp_I_ABCParam.b = 0.8; // Phase B current in Amperes
    

    // Calculate Clarke transform using mcLib_ClarkeTransform. The result
    // of the transform is in mcApp_I_AlphaBetaParam.alpha and mcApp_I_AlphaBetaParam.beta
   mcLib_ClarkeTransform(&mcApp_I_ABCParam, &mcApp_I_AlphaBetaParam);
    </code>

  Remarks: 
    None.
*/
void mcLib_ClarkeTransform(mcParam_ABC *abcParam, mcParam_AlphaBeta *alphabetaParam);




// *****************************************************************************
/* Function:
   void mcLib_SVPWMGen( mcParam_AlphaBeta *alphabetaParam, mcParam_SVPWM *svParam )

  Summary:
  Space Vector PWM Generation

  Description:
  This function calculates Duty cycles for Space Vector PWM Signals

  Precondition:
  None.
 

  Parameters:
    *alphabetaParam     - Structure pointer pointing to the mcParam_AlphaBeta 
                          type structure containing alpha-beta axis normalized 
                          stator voltage values 
  
    *svParam            - Structure pointer pointing to the mcParam_SVPWM 
                          type structure containing SVPWM parameters.

   
  Returns:
    None.

  Example:
    <code>
    mcParam_AlphaBeta                   mcApp_V_AlphaBetaParam; 
    mcParam_SVPWM 						mcApp_SVGenParam;
   
    
    //Update normalized Valpha and Vbeta values 
    mcApp_V_AlphaBetaParam.alpha = 0.1; // Normalized Alpha axis voltage
    mcApp_V_AlphaBetaParam.beta = 0.8; // Normalized Beta axis voltage
    
    //Set PWM Period in PWM Timer counts
    mcApp_SVGenParam.PWMPeriod = 3000; // PWM Period in PWM Timer Counts
    

    // Calculate duty cycles for SVPWM using mcLib_SVPWMGen. The result
    // of the transform is in mcApp_SVGenParam.dPWM_A, mcApp_SVGenParam.dPWM_B
    // and mcApp_SVGenParam.dPWM_C
     mcLib_SVPWMGen(&mcApp_focParam, &mcApp_SVGenParam);
    </code>

  Remarks: 
    None.
*/
void mcLib_SVPWMGen( mcParam_AlphaBeta *alphabetaParam, mcParam_SVPWM *svParam );

// *****************************************************************************
/* Function:
    void mcLib_CalcTimes( mcParam_SVPWM *svParam  );

  Summary:
  Space Vector to Duty Cycle Translation

  Description:
  This function translates the space vector durations to normalized duty cycle 
  values for SVPWM

  Precondition:
  None.
 

  Parameters:
    *svParam            - Structure pointer pointing to the mcParam_SVPWM type 
                          structure containing SVPWM parameters

      Input: 
     *Following members of the mcParam_SVPWM type structure are input to this 
     * function
        float   PWMPeriod;        // PWM Period in PWM Timer Counts
        float   T1;               // Normalized Duration of T1 vector 
        float   T2;               // Normalized Duration of T2 vector 
   
      Output:
     * Following members of the mcParam_SVPWM type structure contain the output 
     * of this function
        float   Ta;         // Ta = To/2 + T1 + T2
        float   Tb;         // Tb = To/2 + T2
        float   Tc;         // Tc = To/2
                                                                                
  Returns:
    None.

  Example:
    <code>
    
    mcParam_SVPWM 						mcApp_SVGenParam;
    
        
    //Set PWM Period in PWM Timer counts
    mcApp_SVGenParam.PWMPeriod = 3000; // PWM Period in PWM Timer Counts
    
    //Set the normalized lengths of Vector T1 and T2
    mcApp_SVGenParam.T1 = 0.8; // Normalized length of vector T1
    mcApp_SVGenParam.T2 = 0.2; // Normalized length of vector T2

    // Calculate normalized duty cycles for SVPWM using mcLib_CalcTimes. The 
    // result of the transform is in mcApp_SVGenParam.Ta, mcApp_SVGenParam.Tb
    // and mcApp_SVGenParam.Tc
     mcLib_CalcTimes(&mcApp_SVGenParam);
    </code>

  Remarks: 
    None.
*/
void mcLib_CalcTimes( mcParam_SVPWM *svParam );

// *****************************************************************************
/* Function:
    void mcLib_InitPI( mcParam_PIController *pParm)

  Summary:
  Initialize PI Controller

  Description:
  This function initializes the PI Controller i.e. clears the integral sum and PI output.

  Precondition:
  None.
 

  Parameters:
    *pParam            - Structure pointer pointing to the mcParam_PIController type structure containing PI Compensator Parameters
  
  Returns:
    None.

  Example:
    <code>
    
    mcParam_PIController mcApp_PIParam;
    
        
    // Initialize PI Compensator output using mcLib_InitPI. 
     mcLib_InitPI(&mcApp_PIParam);
    </code>

  Remarks: 
    None.
*/
void mcLib_InitPI( mcParam_PIController *pParam);

// *****************************************************************************
/* Function:
    void mcLib_CalcPI( mcParam_PIController *pParm)

  Summary:
  Calculates PI Compensator Output

  Description:
  This function calculates the PI Compensator Output.

  Precondition:
  None.
 

  Parameters:
    *pParam            - Structure pointer pointing to the mcParam_PIController type structure containing PI Compensator Parameters.
     
  Returns:
    None.

  Example:
    <code>
    
    mcParam_PIController mcApp_PIParam;
    
        
    //Set the PI Compensator Coefficients
    mcApp_PIParam.qKp = 0.5;  // Proportional Coefficient of the PI Compensator      
    mcApp_PIParam.qKi = 0.2;  // Integral Coefficient of the PI Compensator            
    mcApp_PIParam.qKc = 0.3;  // Anti-windup Coefficient of the PI Compensator     
    
    // Set the PI Compensator Saturation Limits
    mcApp_PIParam.qOutMax = 1;// Max output limit of the PI Compensator
    mcApp_PIParam.qOutMin = -1;// Min output limit of the PI Compensator
    
    // Update the reference and feedback value inputs to PI Compensator 
    mcApp_PIParam.qInRef = <Reference Value>;
    mcApp_PIParam.qInMeas = <Feedback Value>;
        

    // Calculate PI Compensator output using mcLib_CalcPI. The output of the 
    // PI Compensator is in mcApp_PIParam.qOut
     mcLib_CalcPI(&mcApp_PIParam);
    </code>

  Remarks: 
    None.
*/
void mcLib_CalcPI( mcParam_PIController *pParam);



// *****************************************************************************
/* Function:
    void mcLib_SinCosGen(mcParam_SinCos *scParam)

  Summary:
  Calculates Sine and Cosine values 

  Description:
  This function calculates Sine and Cosine values of a given angle (specified in radians)

  Precondition:
  None.
 

  Parameters:
    *scParam            - Structure pointer pointing to the mcParam_SinCos type structure containing parameters
                          related to Sine and Cosine Calculations.
  
  Returns:
    None.

  Example:
    <code>
    
     mcParam_SinCos mcApp_SincosParam;
 
    // Angle input = 1.571 radians (90 degree)
	mcApp_SincosParam.Angle = (float) 1.571;
    
    //Calculate Sine and Cosine using mcLib_SinCosGen. The calculated Sine and Cosine 
    // values are in mcApp_SincosParam.Sin and mcApp_SincosParam.Cos respectively.
    mcLib_SinCosGen(&mcApp_SincosParam);
        
    </code>

  Remarks: 
    None.
*/
void mcLib_SinCosGen(mcParam_SinCos *scParam);


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // #ifndef _MC_LIB_H
/*******************************************************************************
 End of File
*/
