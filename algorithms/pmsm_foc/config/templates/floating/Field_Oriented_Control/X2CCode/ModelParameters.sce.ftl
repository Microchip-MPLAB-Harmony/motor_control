// (c) 2020 Microchip Technology Inc. and its subsidiaries
// Subject to your compliance with these terms, you may use Microchip software and any derivatives exclusively 
// with Microchip products. You’re responsible for complying with 3rd party license terms applicable to your use 
// of 3rd party software (including open source software) that may accompany Microchip software. 
// SOFTWARE IS “AS IS.” NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
// IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP 
// BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
// KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR 
// THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP’S TOTAL LIABILITY ON ALL CLAIMS RELATED 
// TO THE SOFTWARE WILL NOT EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

// System parameters 
SYSTEM_PwmFrequencyInHz = 20000  
X2C_sampleTime = 1/ SYSTEM_PwmFrequencyInHz

// Define the conversion factors
sqrt2 = sqrt(2);
krpm_to_rad_per_s = 100 * %pi / 3;

// Function to convert ke from Vrms/Krpm to Vpeak/rad/s
function ke_vpeak_rpm = convert_ke(ke_vrms_krpm)
    // Convert Vrms/Krpm to Vpeak/Krpm
    ke_vpeak_krpm = ke_vrms_krpm * sqrt2;
    
    // Convert Vpeak/Krpm to Vpeak/rad/s
    ke_vpeak_rpm = ke_vpeak_krpm / 1000;
endfunction

// Load all motor and board parameter files
exec("MotorParameters.sce", -1);
exec("BoardParameters.sce", -1);


// Fundamental base values 
PER_UNIT_Ubase = BOARD_UmaxMeasurable;
PER_UNIT_Ibase = BOARD_ImaxMeasurable;
PER_UNIT_Nbase = MOTOR_MaximumRpm;

// Derived base values
PER_UNIT_Zbase = PER_UNIT_Ubase/PER_UNIT_Ibase
PER_UNIT_Nbase_rad_per_s = PER_UNIT_Nbase * 2 * %pi / 60;
PER_UNIT_Lbase = PER_UNIT_Zbase / PER_UNIT_Nbase_rad_per_s;
PER_UNIT_OneOverKeBase = PER_UNIT_Ubase / PER_UNIT_Nbase;

// BEMF Estimator
BemfEstimator_Rs = MOTOR_PhaseRsInOhm / PER_UNIT_Zbase;
BemfEstimator_Ls = 500 * ( MOTOR_PhaseLdInHenry + MOTOR_PhaseLqInHenry ) / PER_UNIT_Lbase;
BemfEstimator_oneOverKe = PER_UNIT_Ubase * convert_ke( MOTOR_BemfConstInVrmsPerKrpm )/ PER_UNIT_Nbase;
BemfEstimator_SpeedToAngle = ( 2 * PER_UNIT_Nbase * MOTOR_Polepairs / 60.0 )

// Open loop startup parameters
OpenloopStartup_CurrentInAmps = 0.7 *  MOTOR_RatedCurrentInAmps/ PER_UNIT_Ibase
OpenloopStartup_SpeedToAngle = ( 2 * PER_UNIT_Nbase * MOTOR_Polepairs / 60.0 )
OpenloopStartup_FinalSpeedPlus = ${MCPMSMFOC_OPEN_LOOP_END_SPEED} / PER_UNIT_Nbase;
OpenloopStartup_FinalSpeedMinus = -OpenloopStartup_FinalSpeedPlus

OpenloopStartup_PrechargeTimeInSec = 0.1;
OpenloopStartup_AlignmentTimeInSec = ${MCPMSMFOC_STARTUP_TIME};
OpenloopStartup_SpeedRampTimeInSec = ${MCPMSMFOC_OPEN_LOOP_RAMP_TIME};
OpenloopStartup_SpeedStabTimeInSec = ${MCPMSMFOC_OPEN_LOOP_STAB_TIME};
OpenloopStartup_TransitionTimeInSec = 1.0 
OpenloopStartup_AccelerationInRpmPerSec  = 1 // ToDO: Calculate from final speed and ramp time 

OpenloopStartup_PrechargeStamp = OpenloopStartup_PrechargeTimeInSec;
OpenloopStartup_AlignmentTimeStamp = OpenloopStartup_PrechargeTimeInSec + OpenloopStartup_AlignmentTimeInSec;
OpenloopStartup_SpeedRampTimeStamp = OpenloopStartup_AlignmentTimeStamp + OpenloopStartup_SpeedRampTimeInSec;
OpenloopStartup_SpeedStabTimeStamp = OpenloopStartup_SpeedRampTimeStamp + OpenloopStartup_SpeedStabTimeInSec;
OpenloopStartup_TransitionTimeStamp = OpenloopStartup_SpeedStabTimeStamp + OpenloopStartup_TransitionTimeInSec;


//

OpenloopStartup_PrechargeStampSe = 0.1;
OpenloopStartup_AlignmentTimeStampSe = 0.8;
OpenloopStartup_SpeedRampTimeStampSe = 0.8;
OpenloopStartup_SpeedStabTimeStampSe = 0.8;
OpenloopStartup_TransitionTimeStampSe = 0.8;

// Sensorless
//  Default PI controller parameters
// Speed PI 
SpeedKp = 1;
SpeedKi = 5;
SpeedDemandRate = 0.075;
SPEED_CONTROL_MaximumReference=0.8;
SPEED_CONTROL_MinimumReference = 0.005;


// Flux control PI
PIFluxKp =  0.8;
PIFluxKi = 0.5;

// Torque control PI
PITorqueKp = 0.8;
PITorqueKi =0.5;

// PLL
PLL_INT = 640;

// Sensored
//  Default PI controller parameters
// Speed PI 
SpeedKpSe = 1;
SpeedKiSe = 5;
SpeedDemandRateSe = 2.5;
SPEED_CONTROL_MaximumReferenceSe=0.8;
SPEED_CONTROL_MinimumReferenceSe = 0.005;


// Flux control PI
PIFluxKpSe =  0.255;
PIFluxKiSe = 0.8;

// Torque control PI
PITorqueKpSe = 0.255;
PITorqueKiSe =0.8;

