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

boardName = '${MCPMSMFOC_BOARD_SEL}'

if isdef(['Vbus'])==%T then
    if Vbus == 0 then
        Vbus = ${MCPMSMFOC_VOLTAGE_MAGNITUDE};
    end
end

BOARD_PwmFrequencyInHz = ${MCPMSMFOC_PWM_FREQUENCY};

BOARD_RshuntInOhm = ${MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT};
BOARD_CSAGain = ${MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN};
BOARD_CSABias = ${MCPMSMFOC_ANALOG_FRONT_END_IA_OFFSET};

// Calculate maximum measurable current
if ( BOARD_RshuntInOhm <> 0 & BOARD_CSAGain <> 0 ) then
    BOARD_ImaxMeasurable = 1.65/ ( BOARD_RshuntInOhm * BOARD_CSAGain )
else
    BOARD_ImaxMeasurable = 0
end

BOARD_BusVoltageDividerRatio = ${MCPMSMFOC_DC_BUS_RATIO}
// Calculate maximum measurable voltage 
if ( BOARD_BusVoltageDividerRatio <> 0 ) then
    BOARD_UmaxMeasurable = 3.3 / BOARD_BusVoltageDividerRatio
else
    BOARD_UmaxMeasurable = 0
end


