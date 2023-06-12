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

if isdef(['motorName'])==%F then
    mprintf("[Warning] - No motorName defined, defining this now.");
    motorName = '${MCPMSMFOC_MOTOR_SEL}';
else
    if motorName == '${MCPMSMFOC_MOTOR_SEL}'
        if isdef(['Vbus'])==%T then
            if Vbus == 0 then
                Vbus = ${MCPMSMFOC_VOLTAGE_MAGNITUDE};
            end
        end

        <#--  Per phase resistance  -->
        Rs = ${MCPMSMFOC_R};
        Ld = ${MCPMSMFOC_LD};
        Lq = ${MCPMSMFOC_LQ};
        Kell = ${MCPMSMFOC_BEMF_CONST};

        n_p = ${MCPMSMFOC_POLE_PAIRS};

        nominalSpeed = ${MCPMSMFOC_RATED_SPEED};

        J_nmradss = 0.912e-6 * 10; // inertia Nm/rad/s/s

        motorRatedCurrent = ${MCPMSMFOC_MAX_MOTOR_CURRENT};
        motorStartupCurrent = ${MCPMSMFOC_STARTUP_CURRENT};

        boardName == '${MCPMSMFOC_BOARD_SEL}'
        kpCurrent = ${MCPMSMFOC_ID_PID_KP};
        kiCurrent = ${MCPMSMFOC_ID_PID_KI};
        kpVelocity = ${MCPMSMFOC_SPEED_PID_KP};
        kiVelocity = ${MCPMSMFOC_SPEED_PID_KI};
    end
end
