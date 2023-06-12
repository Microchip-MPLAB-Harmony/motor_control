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

// version: R0-RC1

// ******* Universal constants *******
Nm_ozin = 7.061552e-3;
KRPM_rads = 0.060/2/%pi;
Vbus = ${MCPMSMFOC_VOLTAGE_MAGNITUDE};                  // override value in volts

// ******* Load all motor and board parameter files *******
exec("MotorParameters.sce", -1);
exec("BoardParameters.sce", -1);

// ******* Derived parameters *******
X2C_sampleTime = 1/fPWM;
Vdc_phase = Vbus/sqrt(3);
Ipeakfullscale = 1.65/(abs(Igain)*Rshunt);
startupCurrentNorm = motorStartupCurrent/Ipeakfullscale;
Isat = min(maxCurrentCommand*0.85,motorRatedCurrent);
IsatNorm = Isat/Ipeakfullscale;

// ******* Choose one of the saturation modes *******
SaturationModeBalancedDQ = %F;
SaturationModeQheavy = %T;

if SaturationModeBalancedDQ then
    // voltage saturation scheme:
    // remaining voltage after HFI is shared equally
    // between d axis and q axis controllers
    VmaxAmp = Vdc_phase - hfiUcAmplitude;
    Vsat = sqrt((VmaxAmp^2)/2);
    Vdsat = Vsat;
    Vqsat = Vsat;
    VdsatNorm = Vdsat/Vdc_phase;
    VqsatNorm = Vqsat/Vdc_phase;
end

if SaturationModeQheavy then
    // voltage saturation scheme:
    // 95% of remaining voltage after HFI is shared 1x in
    // d axis controller and 4x in q axis controller
    VmaxAmp = (Vdc_phase - hfiUcAmplitude)*0.95;
    Vsat = sqrt((VmaxAmp^2)/17);
    Vdsat = Vsat;
    Vqsat = 4*Vsat;
    VdsatNorm = Vdsat/Vdc_phase;
    VqsatNorm = Vqsat/Vdc_phase;
end

// rescaled motor parameters
Ls_mH = (1e3)*(Ld+Lq)/2;

// ZS/MT tuning parameters
n_scale = nominalSpeed;
UDCLink_scale = Vbus;
I_scale = Ipeakfullscale;
vdcNormalization = Vbus/sqrt(3);


// ******* Derived constants *******
speed2mechAngle     = (2*%pi*n_scale/60)/%pi;
speed2elAngle       = speed2mechAngle * n_p;

