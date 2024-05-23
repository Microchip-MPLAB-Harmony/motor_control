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

if isdef(['boardName'])==%F then
    mprintf("[Warning] - No boardName defined, defining this now.");
    boardName = '${MCPMSMFOC_BOARD_SEL}';
else
    if boardName == '${MCPMSMFOC_BOARD_SEL}'

        fPWM = ${MCPMSMFOC_PWM_FREQUENCY};

        Rshunt = ${MCPMSMFOC_ANALOG_FRONT_END_IA_SHUNT};
        Igain = ${MCPMSMFOC_ANALOG_FRONT_END_IA_GAIN};

        maxCurrentCommand = 2.9;

    end
end

