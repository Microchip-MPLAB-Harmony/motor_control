var myVariable = `
{"0": {
    "doc": "Configuring the Library",
    "title": "Configuring the Library",
    "content": "Different UI configurations are explained below. Control Algorithm Parameters . Allows to select application mode like open loop or speed loop or torque loop. Position feedback determines the feedback loop implementation like PLL estimator sensorless or Encoder based sensored algorithm. This allows to configure startup parameters and control loop PI parameters. Flying Start Parameters . Allows configuration of Flying Start Detection Parameters. By default, the implementation of this mode is part of an archive file lib_mc_flyingstart.a. In order to access the source file, please contact Microchip’s Local Sales Office. | Flying Start Detect mode uses a separate set of current controller PI gains which can be different than current control PI gains used in normal Run mode. It is recommended that in Flying Start Mode, the current controllers should have higher bandwidth than during normal Run mode. | Flying Start Detect Duration - Defines the duration in seconds for which the control algorithm will attempt to ascertain if the motor is freewheeling. | Minimum Flying Start Speed - Defines the minimum speed in RPM below which if the motor is freewheeling, the control algorithm would deem it as “Not Freewheeling” . | Flying Start Current - Defines the starting current in A which would be used during transition from Flying Start Detection -&gt; Closed Loop operation. | Null Vector Braking Duration - Defines the passive braking duration in seconds, implemented by applying null vector pulses to the motor windings. | Regenerative Braking - When enabled, if the motor’s freewheeling speed is above the minimum flying start detect speed and in the opposite direction to that of command direction, the control algorithm would actively brake the motor using regenerative braking until the motor speed falls below minimum flying start detect speed. | Peak Regenerative Braking Current - Defines the maximum regenerative braking current applied in A. | Regenerative Braking Ramp Duration - Defines the duration in seconds during which the regenerative braking current ramps from 0 to Peak Regenerative Braking Current. | . | . PWM Configurations . Select the PWM frequency and PWM channels used to drive Phase U, V and W based on board connections. Selected configurations are passed to the PWM PLIB. PWM PLIB is auto-configured for FOC algorithm. ADC Configurations . Select ADC channels used for Phase U current, Phase V Current, DC Bus voltage and potentiometer based on the board connections. Selected configurations are passed to the ADC PLIB. ADC PLIB is auto-configured for FOC algorithm. Encoder Configurations . Select the number of encoder pulses per revolution of the motor. Selected configurations are passed to the QDEC PLIB. Motor Parameters . Allows to configure motor parameters. Microchip direct motors are selectable and pre-configured. User can select custom motor to configure parameters for other motors. Control Board Parameters . Allows to configure control board parameters. Microchip’s motor control development boards like dsPICDEM MCLV-2 development board are selectable and pre-configured. User can select custom board to configure parameters for other boards. IO Pin Configurations . Configure I/O pins for PWM, ADC, Encoder, UART, input switches and LEDs using the pin manager. Clock Configurations . CPU clock speed is defaulted to maximum recommended clock frequency of the MCU. View or modify the clock speed using clock manager. ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/configurations.html",
    "relUrl": "/algorithms/pmsm_foc/configurations.html"
  },"1": {
    "doc": "Control Algorithm",
    "title": "Control Algorithm",
    "content": "Field Oriented Control (FOC): . Field Oriented Control is the technique used to achieve the decoupled control of torque and flux. This is done by transforming the stator current quantities (phase currents) from stationary reference frame to torque and flux producing currents components in rotating reference frame using mathematical transformations. The Field Oriented Control is done as follows: . | Measure the motor phase currents. | Transform them into the two phase system (a, b) using the Clarke transformation. | Calculate the rotor position angle. There are different ways to get the rotor position angle like using PLL estimator or quadrature encoder sensor. | Transform stator currents into the d,q-coordinate system using the Park transformation. | The stator current’s torque (iq) and flux (id) producing components are controlled separately by the controllers. | The output stator voltage space vector is transformed back from the d,q-coordinate system into the two phase system fixed with the stator by the Inverse Park transformation. | Using the space vector modulation, the three-phase output voltage is generated. | . PLL Estimator . The working principle of the PLL estimator can be found in Application Note AN2520. Its operating principle is based on the fact that the d-component of the Back Electromotive Force (BEMF) must be equal to zero at a steady state functioning mode. The main disadvantage of PLL estimator is its inability to estimate the rotor angle at lower rotor speeds because of very low value of back EMF. Therefore, the FOC algorithm also integrates the ramp-up profile for motor start. The reference speed is incremented linearly using a open loop phase voltage control until the required minimum reference speed for the PLL estimator is reached. Quadrature Encoder . An incremental optical encoder provides two pulse trains which are in quadrature with each other. Some encoders also have an index pulse which helps in finding the precide rotor position spatially. Microcontroller quadrature encoder peripheral is used to capture and decode quadrature encoder siganls. Peripheral gives the rotor position based on the quadrature pulse. And velocity is calculated by measuring encoder pulses in known time interval. PIC32MK QEI peripheral gives the velocity directly. Please refer to the Application Note AN2757 . Field Weakening . The field weakening for PMSM implies imposing a negative value of d-axis current, which has the role of weakening the air gap flux linkage. Field weakening is required to enable the PMSM motor to rotate above its rated speed. An equation based field weakening is implemented. Flying Start . This feature detects if motor shaft is freewheeling due to stored momentum or external force and estimates the rotor angle, speed and direction of the freewheeling motor. If the freewheeling speed is greater than the minimum speed and is rotating in intended direction, this algorithm catches the motor rotation and directly switches to closed loop control. If speed is less then it applies break to halt the motor and starts the control from stationary position. ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/control_algorithm.html",
    "relUrl": "/algorithms/pmsm_foc/control_algorithm.html"
  },"2": {
    "doc": "License",
    "title": "License",
    "content": "IMPORTANT: READ CAREFULLY . MICROCHIP IS WILLING TO LICENSE THIS INTEGRATED SOFTWARE FRAMEWORK SOFTWARE AND ACCOMPANYING DOCUMENTATION OFFERED TO YOU ONLY ON THE CONDITION THAT YOU ACCEPT ALL OF THE FOLLOWING TERMS. TO ACCEPT THE TERMS OF THIS LICENSE, CLICK “I ACCEPT” AND PROCEED WITH THE DOWNLOAD OR INSTALL. IF YOU DO NOT ACCEPT THESE LICENSE TERMS, CLICK “I DO NOT ACCEPT,” AND DO NOT DOWNLOAD OR INSTALL THIS SOFTWARE. NON-EXCLUSIVE SOFTWARE LICENSE AGREEMENT FOR MICROCHIP MPLAB HARMONY INTEGRATED SOFTWARE FRAMEWORK . This Nonexclusive Software License Agreement (“Agreement”) is between you, your heirs, agents, successors and assigns (“Licensee”) and Microchip Technology Incorporated, a Delaware corporation, with a principal place of business at 2355 W. Chandler Blvd., Chandler, AZ 85224-6199, and its subsidiary, Microchip Technology (Barbados) II Incorporated (collectively, “Microchip”) for Microchip’s MPLAB Harmony Integrated Software Framework (“Software”) and accompanying documentation (“Documentation”). The Software and Documentation are licensed under this Agreement and not sold. U.S. copyright laws and international copyright treaties, and other intellectual property laws and treaties protect the Software and Documentation. Microchip reserves all rights not expressly granted to Licensee in this Agreement. | License and Sublicense Grant. (a) Definitions. As used this Agreement, the following terms shall have the meanings defined below: . (i) \\\"Licensee Products\\\" means Licensee products that use or incorporate Microchip Products. (ii) \\\"Microchip Product\\\" means Microchip 16-bit and 32-bit microcontrollers, digital signal controllers or other Microchip semiconductor products with PIC16 and PIC18 prefix and specifically excepting the CX870 and CY920, which are not covered under this Agreement, that use or implement the Software. (iii) \\\"Object Code\\\" means the Software computer programming code provided by Microchip that is in binary form (including related documentation, if any) and error corrections, improvements and updates to such code provided by Microchip in its sole discretion, if any. (iv) \\\"Source Code\\\" means the Software computer programming code provided by Microchip that may be printed out or displayed in human readable form (including related programmer comments and documentation, if any), and error corrections, improvements, updates, modifications and derivatives of such code developed by Microchip, Licensee or Third Party. (v) \\\"Third Party\\\" means Licensee's agents, representatives, consultants, clients, customers, or contract manufacturers. (vi) \\\"Third Party Products\\\" means Third Party products that use or incorporate Microchip Products. (b) Software License Grant. Subject to the terms of this Agreement, Microchip grants strictly to Licensee a personal, worldwide, non-exclusive, non-transferable limited license to use, modify (except as limited by Section 1(f) below), copy and distribute the Software only when the Software is embedded on a Microchip Product that is integrated into Licensee Product or Third Party Product pursuant to Section 2(d) below. Any portion of the Software (including derivatives or modifications thereof) may not be: . (i) embedded on a non-Microchip microcontroller or digital signal controller; (ii) distributed (in Source Code or Object Code), except as described in Section 2(d) below. (c) Documentation License Grant. Subject to all of the terms and conditions of this Agreement, Microchip grants strictly to Licensee a perpetual, worldwide, non-exclusive license to use the Documentation in support of Licensee’s use of the Software. (d) Sublicense Grants. Subject to terms of this Agreement, Licensee may grant a limited sublicense to a Third Party to use the Software as described below only if such Third Party expressly agrees to be bound by terms of confidentiality and limited use that are no broader in scope and duration than the confidentiality and limited use terms of this Agreement: . (i) Third Party may modify Source Code for Licensee, except as limited by Section 1(f) below. (ii) Third Party may program Software into Microchip Products for Licensee. (iii) Third Party may use Software to develop and/or manufacture Licensee Product. (iv) Third Party may use Software to develop and/or manufacture Third Party Products where either: (x) the sublicensed Software contains Source Code modified or otherwise optimized by Licensee for Third Party use; or (y) the sublicensed Software is programmed into Microchip Products by Licensee on behalf of such Third Party. (v) Third Party may use the Documentation in support of Third Party's authorized use of the Software in conformance with this Section 2(d). (e) Audit. Authorized representatives of Microchip shall have the right to reasonably inspect Licensee’s premises and to audit Licensee’s records and inventory of Licensee Products, whether located on Licensee’s premises or elsewhere at any time, announced or unannounced, and in its sole and absolute discretion, in order to ensure Licensee’s adherence to the terms of this Agreement. (f) License and Sublicense Limitation. This Section 1 does not grant Licensee or any Third Party the right to modify any dotstack™ Bluetooth® stack, profile, or iAP protocol included in the Software. | Third Party Requirements. Licensee acknowledges that it is Licensee’s responsibility to comply with any third party license terms or requirements applicable to the use of such third party software, specifications, systems, or tools, including but not limited to SEGGER Microcontroller GmbH &amp; Co. KG’s rights in the emWin software and certain libraries included herein. Microchip is not responsible and will not be held responsible in any manner for Licensee’s failure to comply with such applicable terms or requirements. | Open Source Components. Notwithstanding the license grants contained herein, Licensee acknowledges that certain components of the Software may be covered by so-called “open source” software licenses (“Open Source Components”). Open Source Components means any software licenses approved as open source licenses by the Open Source Initiative or any substantially similar licenses, including any license that, as a condition of distribution, requires Microchip to provide Licensee with certain notices and/or information related to such Open Source Components, or requires that the distributor make the software available in source code format. Microchip will use commercially reasonable efforts to identify such Open Source Components in a text file or “About Box” or in a file or files referenced thereby (and will include any associated license agreement, notices, and other related information therein), or the Open Source Components will contain or be accompanied by its own license agreement. To the extent required by the licenses covering Open Source Components, the terms of such licenses will apply in lieu of the terms of this Agreement, and Microchip hereby represents and warrants that the licenses granted to such Open Source Components will be no less broad than the license granted in Section 1(b). To the extent the terms of the licenses applicable to Open Source Components prohibit any of the restrictions in this Agreement with respect to such Open Source Components, such restrictions will not apply to such Open Source Components. | Licensee’s Obligations. (a) Licensee will ensure Third Party compliance with the terms of this Agreement. (b) Licensee will not: (i) engage in unauthorized use, modification, disclosure or distribution of Software or Documentation, or its derivatives; (ii) use all or any portion of the Software, Documentation, or its derivatives except in conjunction with Microchip Products; or (iii) reverse engineer (by disassembly, decompilation or otherwise) Software or any portion thereof; or (iv) copy or reproduce all or any portion of Software, except as specifically allowed by this Agreement or expressly permitted by applicable law notwithstanding the foregoing limitations. (c) Licensee must include Microchip’s copyright, trademark and other proprietary notices in all copies of the Software, Documentation, and its derivatives. Licensee may not remove or alter any Microchip copyright or other proprietary rights notice posted in any portion of the Software or Documentation. (d) Licensee will defend, indemnify and hold Microchip and its subsidiaries harmless from and against any and all claims, costs, damages, expenses (including reasonable attorney’s fees), liabilities, and losses, including without limitation product liability claims, directly or indirectly arising from or related to: (i) the use, modification, disclosure or distribution of the Software, Documentation or any intellectual property rights related thereto; (ii) the use, sale, and distribution of Licensee Products or Third Party Products, and (iii) breach of this Agreement. THE FOREGOING STATES THE SOLE AND EXCLUSIVE LIABILITY OF THE PARTIES FOR INTELLECTUAL PROPERTY RIGHTS INFRINGEMENT. | Confidentiality. (a) Licensee agrees that the Software (including but not limited to the Source Code, Object Code and library files) and its derivatives, Documentation and underlying inventions, algorithms, know-how and ideas relating to the Software and the Documentation are proprietary information belonging to Microchip and its licensors (“Proprietary Information”). Except as expressly and unambiguously allowed herein, Licensee will hold in confidence and not use or disclose any Proprietary Information and shall similarly bind its employees and Third Party(ies) in writing. Proprietary Information shall not include information that: (i) is in or enters the public domain without breach of this Agreement and through no fault of the receiving party; (ii) the receiving party was legally in possession of prior to receiving it; (iii) the receiving party can demonstrate was developed by it independently and without use of or reference to the disclosing party’s Proprietary Information; or (iv) the receiving party receives from a third party without restriction on disclosure. If Licensee is required to disclose Proprietary Information by law, court order, or government agency, such disclosure shall not be deemed a breach of this Agreement provided that Licensee gives Microchip prompt notice of such requirement in order to allow Microchip to object or limit such disclosure, Licensee cooperates with Microchip to protect Proprietary Information, and Licensee complies with any protective order in place and discloses only the information required by process of law. (b) Licensee agrees that the provisions of this Agreement regarding unauthorized use and nondisclosure of the Software, Documentation and related Proprietary Rights are necessary to protect the legitimate business interests of Microchip and its licensors and that monetary damages alone cannot adequately compensate Microchip or its licensors if such provisions are violated. Licensee, therefore, agrees that if Microchip alleges that Licensee or Third Party has breached or violated such provision then Microchip will have the right to petition for injunctive relief, without the requirement for the posting of a bond, in addition to all other remedies at law or in equity. | Ownership of Proprietary Rights. (a) Microchip and its licensors retain all right, title and interest in and to the Software and Documentation (“Proprietary Rights”) including, but not limited to: (i) patent, copyright, trade secret and other intellectual property rights in the Software, Documentation, and underlying technology; (ii) the Software as implemented in any device or system, all hardware and software implementations of the Software technology (expressly excluding Licensee and Third Party code developed and used in conformance with this Agreement solely to interface with the Software and Licensee Products and/or Third Party Products); and (iii) all modifications and derivative works thereof (by whomever produced). Further, modifications and derivative works shall be considered works made for hire with ownership vesting in Microchip on creation. To the extent such modifications and derivatives do not qualify as a “work for hire,” Licensee hereby irrevocably transfers, assigns and conveys the exclusive copyright thereof to Microchip, free and clear of any and all liens, claims or other encumbrances, to the fullest extent permitted by law. Licensee and Third Party use of such modifications and derivatives is limited to the license rights described in Section 1 above. (b) Licensee shall have no right to sell, assign or otherwise transfer all or any portion of the Software, Documentation or any related intellectual property rights except as expressly set forth in this Agreement. | Termination of Agreement. Without prejudice to any other rights, this Agreement terminates immediately, without notice by Microchip, upon a failure by License or Third Party to comply with any provision of this Agreement. Further, Microchip may also terminate this Agreement upon reasonable belief that Licensee or Third Party have failed to comply with this Agreement. Upon termination, Licensee and Third Party will immediately stop using the Software, Documentation, and derivatives thereof, and immediately destroy all such copies, remove Software from any of Licensee’s tangible media and from systems on which the Software exists, and stop using, disclosing, copying, or reproducing Software (even as may be permitted by this Agreement). Termination of this Agreement will not affect the right of any end user or consumer to use Licensee Products or Third Party Products provided that such products were purchased prior to the termination of this Agreement. | Dangerous Applications. The Software is not fault-tolerant and is not designed, manufactured, or intended for use in hazardous environments requiring failsafe performance (“Dangerous Applications”). Dangerous Applications include the operation of nuclear facilities, aircraft navigation, aircraft communication systems, air traffic control, direct life support machines, weapons systems, or any environment or system in which the failure of the Software could lead directly or indirectly to death, personal injury, or severe physical or environmental damage. Microchip specifically disclaims (a) any express or implied warranty of fitness for use of the Software in Dangerous Applications; and (b) any and all liability for loss, damages and claims resulting from the use of the Software in Dangerous Applications. | Warranties and Disclaimers. THE SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. MICROCHIP AND ITS LICENSORS ASSUME NO RESPONSIBILITY FOR THE ACCURACY, RELIABILITY OR APPLICATION OF THE SOFTWARE OR DOCUMENTATION. MICROCHIP AND ITS LICENSORS DO NOT WARRANT THAT THE SOFTWARE WILL MEET REQUIREMENTS OF LICENSEE OR THIRD PARTY, BE UNINTERRUPTED OR ERROR-FREE. MICROCHIP AND ITS LICENSORS HAVE NO OBLIGATION TO CORRECT ANY DEFECTS IN THE SOFTWARE. LICENSEE AND THIRD PARTY ASSUME THE ENTIRE RISK ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE AND DOCUMENTATION PROVIDED UNDER THIS AGREEMENT. | Limited Liability. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL OR EQUITABLE THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS. The aggregate and cumulative liability of Microchip and its licensors for damages hereunder will in no event exceed $1000 or the amount Licensee paid Microchip for the Software and Documentation, whichever is greater. Licensee acknowledges that the foregoing limitations are reasonable and an essential part of this Agreement. | General. (a) Governing Law, Venue and Waiver of Trial by Jury. THIS AGREEMENT SHALL BE GOVERNED BY AND CONSTRUED UNDER THE LAWS OF THE STATE OF ARIZONA AND THE UNITED STATES WITHOUT REGARD TO CONFLICTS OF LAWS PROVISIONS. Licensee agrees that any disputes arising out of or related to this Agreement, Software or Documentation shall be brought in the courts of State of Arizona. The parties agree to waive their rights to a jury trial in actions relating to this Agreement. (b) Attorneys’ Fees. If either Microchip or Licensee employs attorneys to enforce any rights arising out of or relating to this Agreement, the prevailing party shall be entitled to recover its reasonable attorneys’ fees, costs and other expenses. (c) Entire Agreement. This Agreement shall constitute the entire agreement between the parties with respect to the subject matter hereof. It shall not be modified except by a written agreement signed by an authorized representative of Microchip. (d) Severability. If any provision of this Agreement shall be held by a court of competent jurisdiction to be illegal, invalid or unenforceable, that provision shall be limited or eliminated to the minimum extent necessary so that this Agreement shall otherwise remain in full force and effect and enforceable. (e) Waiver. No waiver of any breach of any provision of this Agreement shall constitute a waiver of any prior, concurrent or subsequent breach of the same or any other provisions hereof, and no waiver shall be effective unless made in writing and signed by an authorized representative of the waiving party. (f) Export Regulation. Licensee agrees to comply with all export laws and restrictions and regulations of the Department of Commerce or other United States or foreign agency or authority. (g) Survival. The indemnities, obligations of confidentiality, and limitations on liability described herein, and any right of action for breach of this Agreement prior to termination shall survive any termination of this Agreement. (h) Assignment. Neither this Agreement nor any rights, licenses or obligations hereunder, may be assigned by Licensee without the prior written approval of Microchip except pursuant to a merger, sale of all assets of Licensee or other corporate reorganization, provided that assignee agrees in writing to be bound by the Agreement. (i) Restricted Rights. Use, duplication or disclosure by the United States Government is subject to restrictions set forth in subparagraphs (a) through (d) of the Commercial Computer-Restricted Rights clause of FAR 52.227-19 when applicable, or in subparagraph (c)(1)(ii) of the Rights in Technical Data and Computer Software clause at DFARS 252.227-7013, and in similar clauses in the NASA FAR Supplement. Contractor/manufacturer is Microchip Technology Inc., 2355 W. Chandler Blvd., Chandler, AZ 85225-6199. | . If Licensee has any questions about this Agreement, please write to Microchip Technology Inc., 2355 W. Chandler Blvd., Chandler, AZ 85224-6199 USA, ATTN: Marketing. Microchip MPLAB Harmony Integrated Software Framework. Copyright © 2015 Microchip Technology Inc. All rights reserved. License Rev. 11/2015 . Copyright © 2015 Qualcomm Atheros, Inc. All Rights Reserved. Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies. THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ",
    "url": "http://localhost:4000/motor_control/mplab_harmony_license.html",
    "relUrl": "/mplab_harmony_license.html"
  },"3": {
    "doc": "PMSM FOC Component",
    "title": "PMSM FOC",
    "content": "PMSM_FOC component provides Field Oriented Control (FOC) algorithm for Permanent Magnet Synchronous Motor (PMSM). This component supports speed control with an inner current control loop to control motor speed and motor current. It also supports current control and open loop mode. Rotor position estimation techniques are configurable in the UI. PMSM_FOC connects to the Peripheral Libraries (PLIBs) from CSP repository and X2CScope component from X2C repository. This component depends on ADC PLIB for phase current measurement, DC bus voltage and potentiometer measurement. PWM PLIB is used to generate three phase signals to control the motor. For quadrature encoder sensor position feedback, PMSM_FOC interacts with QDEC peripheral. ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/readme.html#pmsm-foc",
    "relUrl": "/algorithms/pmsm_foc/readme.html#pmsm-foc"
  },"4": {
    "doc": "PMSM FOC Component",
    "title": "Supported Microcontrollers and Development Boards",
    "content": "| Microcontroller | MCLV2 | MCHV3 | . | SAME70 | Yes | Yes | . | SAME54 | Yes | Yes | . | PIC32MK MCF | Yes | Yes | . | PIC32MK MCM | Yes | Yes | . |   |   |   | . ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/readme.html#supported-microcontrollers-and-development-boards",
    "relUrl": "/algorithms/pmsm_foc/readme.html#supported-microcontrollers-and-development-boards"
  },"5": {
    "doc": "PMSM FOC Component",
    "title": "Supported Features",
    "content": "| Feature | Options | . | Position Feedback | - PLL Estimator - Quadrature Encoder | . | Current Measurement | - Dual shunt | . | Control Loop | - Speed mode - Torque mode - Open loop (For sensorless operation) | . | Field Alignment | - Q-axis alignment - D-axis alignment | . | Advanced Features | - Equation based field weakening - Flying Start | . |   |   | . Software Design . Control Algorithm . Configuring the Library . Using the Library . ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/readme.html#supported-features",
    "relUrl": "/algorithms/pmsm_foc/readme.html#supported-features"
  },"6": {
    "doc": "PMSM FOC Component",
    "title": "PMSM FOC Component",
    "content": " ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/readme.html",
    "relUrl": "/algorithms/pmsm_foc/readme.html"
  },"7": {
    "doc": "Release notes",
    "title": "Microchip MPLAB Harmony 3 Release Notes",
    "content": " ",
    "url": "http://localhost:4000/motor_control/release_notes.html#microchip-mplab-harmony-3-release-notes",
    "relUrl": "/release_notes.html#microchip-mplab-harmony-3-release-notes"
  },"8": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.6.0",
    "content": ". | PMSM_FOC Component . Following features were added to PMSM_FOC component . | SAME5x device support | dsPICDEM MCHV-3 board support | Flying Start support | . | Application Examples . All motor control application examples were moved to product family specific motor control apps repositories. | . Required MPLAB Harmony v3 Modules . | csp v3.8.3 | x2c v1.1.3 | dev_packs v3.8.0 | mhc v3.6.5 | . Known Issues . | ATSAME54 Motor Control Plugin Module based demos may see noise coupling on the ADC channels resulting in motor instability/stall. | This issue can be resolved by ensuring that R1 (0 ohm) resistor is populated. | . | Isolated EDBG Card . | If programming failure occurs with message “java.lang.RuntimeException:RDDI_DAP_OPERATION_FAILED”, then reset the Isolated EDBG Card’s configuration by Go to File -&gt; Project Properties -&gt; EDBG -&gt; Reset . | Programming or debugging PIC32CM, SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | . | pmsm_foc_encoder_ applications running on dsPICDEM MCHV-3 requires increasing bandwidth of the quadrature encoder signal filter to maintain signal integrity of quadrature sensor signals at higher motor speeds. Without these modifications, motor operation may fail at higher speeds. | Reduce the capacitance value of C25, C26 and C27 from 100pF to 10pF 50V NPO 0805 | . | pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in “TORQUE_MODE”. Workaround - Reset the MCU before re-starting the motor in “TORQUE_MODE”. | For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, enable “RAM_EXECUTE” mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory. | . Development Tools . | MPLAB X IDE v5.45 | MPLAB XC32 C/C++ Compiler v2.50 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.6.2. | X2CScope v1.3.0. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v360",
    "relUrl": "/release_notes.html#motor-control-release-v360"
  },"9": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.5.1",
    "content": "New Applications . | The following table provides the list of algorithms added in this release. | . | Algorithm | Description | Control Board | Inverter Board | . | pmsm_foc_rolo_pic32_cm_mc | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | PIC32CM MC 00 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; &lt;li&gt;dsPICDEM™ MCHV-3 Support&lt;/li&gt; | . | acim_vhz_pic32_cm_mc | Open Loop V/F Control of AC Induction Motor | PIC32CM MC 00 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCHV-3 Support&lt;/li&gt; | . | bldc_bc_hall_pic32_cm_mc | Block Commutation based control of BLDC motor using Hall Sensors | PIC32CM MC 00 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; | . Updated Applications . | Application | Description | Control Board | Inverter Board | Revision History | . | pmsm_foc_encoder_lx7720_sam_rh71_ek | Sensored Field Oriented Control of PMSM using SAMRH71 MCU and LX7720 Motor Driver and Position decoder | SAMRH71F20-EK Evaluation Kit | LX7720 Daughter Board | &lt;li&gt; Regenerated demo applications using csp v3.8.1 &lt;/li&gt;&lt;li&gt;Added reverse direction capability&lt;/li&gt;&lt;li&gt; Optimized Speed Controller response &lt;/li&gt; | . Required MPLAB Harmony v3 Modules . | csp v3.8.1 | x2c v1.1.2 | dev_packs v3.8.0 | mhc v3.5.1 | . Known Issues . | Isolated EDBG Card . | This board is not supported in MPLABX v5.40. We recommend using MPLABX v5.45 or above for programming/debugging any PIC32CM_MC, SAM C/D2x, SAM D/E5x and SAM E/V/S7x applications dsPICDEM™ MCHV-3 High Voltage Development Board . | If programming failure occurs with message “java.lang.RuntimeException:RDDI_DAP_OPERATION_FAILED”, then reset the Isolated EDBG Card’s configuration by Go to File -&gt; Project Properties -&gt; EDBG -&gt; Reset . | Programming or debugging PIC32CM, SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | . | pmsm_foc_encoder_ applications running on dsPICDEM MCHV-3 requires increasing bandwidth of the quadrature encoder signal filter to maintain signal integrity of quadrature sensor signals at higher motor speeds. Without these modifications, motor operation may fail at higher speeds. | Reduce the capacitance value of C25, C26 and C27 from 100pF to 10pF 50V NPO 0805 | . | pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in “TORQUE_MODE”. Workaround - Reset the MCU before re-starting the motor in “TORQUE_MODE”. | For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, enable “RAM_EXECUTE” mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory. | . Development Tools . | MPLAB X IDE v5.45 | MPLAB XC32 C/C++ Compiler v2.41 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.6.0. | X2CScope v1.3.0. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v351",
    "relUrl": "/release_notes.html#motor-control-release-v351"
  },"10": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.5.0",
    "content": "New Features . | Feature | Description | Supported Device Family | . | PMSM_FOC Component | An application library for Field Oriented Control (FOC) of Permanent Magnet Synchronous Motors (PMSM). This library can be configured using MPLAB Harmony Configurator (MHC) to auto-generate a fully functional application code which can drive a permanent magnet synchronous motor. | PIC32MK, SAME7x | . New Applications . | The following table provides the list of algorithms added in this release. | . | Algorithm | Description | Control Board | Inverter Board | . | pmsm_foc_encoder_pic32_mk | Sensored Field Oriented Control of PMSM using Quadrature Encoder | PIC32MK MCM Motor Control Plugin Module | dsPICDEM™ MCLV-2 Support | . | pmsm_foc_pll_estimator_pic32_mk | Sensorless Field Oriented Control of PMSM using PLL Estimator | PIC32MK MCM Motor Control Plugin Module | dsPICDEM™ MCLV-2 Support | . | pmsm_foc_encoder_lx7720_sam_rh71_ek | Sensored Field Oriented Control of PMSM using SAMRH71 MCU and LX7720 Motor Driver and Position decoder | SAMRH71F20-EK Evaluation Kit | LX7720 Daughter Board | . Updated Applications . | All demo applications were regenerated using csp v3.7.1 | Following table lists the applications which are updated beyond regeneration using csp v3.7.1. | . | Application | Description | Control Board | Inverter Board | Revision History |   | . | pmsm_foc_encoder_pic32_mk | Sensored Field Oriented Control of PMSM using Quadrature Encoder | PIC32MK Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; | &lt;li&gt; Regenerated low voltage demo (MCLV2) using PMSM_FOC component&lt;/li&gt; |   | . | pmsm_foc_pll_estimator_pic32_mk | Sensorless Field Oriented Control of PMSM using PLL Estimator | PIC32MK Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; | &lt;li&gt; Regenerated low voltage demo (MCLV2) using PMSM_FOC component&lt;/li&gt; | &lt;li&gt; Regenerated low voltage demo (MCLV2) using PMSM_FOC component&lt;/li&gt; | . | pmsm_foc_encoder_sam_e70 | Sensored Field Oriented Control of PMSM using Quadrature Encoder | ATSAME70 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; | &lt;li&gt; Regenerated low voltage demo (MCLV2) using PMSM_FOC component&lt;/li&gt; |   | . | pmsm_foc_pll_estimator_sam_e70 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME70 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; | &lt;li&gt; Regenerated low voltage demo (MCLV2) using PMSM_FOC component&lt;/li&gt; | &lt;li&gt; Regenerated low voltage demo (MCLV2) using PMSM_FOC component&lt;/li&gt; | . | pmsm_foc_rolo_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | ATSAMC21 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; &lt;li&gt;dsPICDEM™ MCHV-3 Support&lt;/li&gt; | &lt;li&gt; Implemented bug fix to use the most recent phase current measurement for current control &lt;/li&gt;&lt;li&gt; Implemented bug fix in integral saturation logic (upper limit) of the PI compensator &lt;/li&gt; |   | . | pmsm_foc_rolo_wm_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | ATSAMC21 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; &lt;li&gt;dsPICDEM™ MCHV-3 Support&lt;/li&gt; | &lt;li&gt; Implemented bug fix to use the most recent phase current measurement for current control &lt;/li&gt;&lt;li&gt; Implemented bug fix in integral saturation logic (upper limit) of the PI compensator &lt;/li&gt; |   | . | pmsm_foc_rolo_fw_mtpa_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Field Weakening and MTPA Capability | ATSAMC21 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; | &lt;li&gt; Implemented bug fix to use the most recent phase current measurement for current control &lt;/li&gt;&lt;li&gt; Implemented bug fix in integral saturation logic (upper limit) of the PI compensator &lt;/li&gt; |   | . | acim_vhz_sam_c21 | Open Loop V/F Control of AC Induction Motor | ATSAMC21 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCHV-3 Support&lt;/li&gt; | &lt;li&gt; Implemented bug fix in integral saturation logic (upper limit) of the PI compensator &lt;/li&gt; |   | . | pmsm_foc_rolo_1shunt | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Single Shunt Current Sense | ATSAMC21 Motor Control Plugin Module | &lt;li&gt;dsPICDEM™ MCLV-2 Support&lt;/li&gt; | &lt;li&gt; Implemented bug fix in integral saturation logic (upper limit) of the PI compensator &lt;/li&gt; |   | . Required MPLAB Harmony v3 Modules . | csp v3.7.1 | x2c v1.0.1 | dev_packs v3.7.0 | mhc v3.5.0 | . Known Issues . | Isolated EDBG Card (board revision #02-10824-R1) is not supported in MPLABX v5.40. We recommend using MPLABX v5.35 for programming/debugging any SAM C/D2x, SAM D/E5x and SAM E/V/S7x applications dsPICDEM™ MCHV-3 High Voltage Development Board | MPLAB X IDE v5.35 fails to program ATSAME70 Motor Control Plugin Module on dsPICDEM™ MCHV-3 High Voltage Development Board. In order to resolve this issue, implement the following change in dap_cortex-m7.py, located at C:\\\\Program Files (x86)\\\\Microchip\\\\MPLABX\\v5.35\\\\packs\\\\Microchip\\SAME70_DFP\\4.2.59\\\\scripts\\\\ . | Goto line # 2, replace “comm_speed=8000000” with “comm_speed=2000000” | . | Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | pmsm_foc_encoder_ applications running on dsPICDEM MCHV-3 requires increasing bandwidth of the quadrature encoder signal filter to maintain signal integrity of quadrature sensor signals at higher motor speeds. Without these modifications, motor operation may fail at higher speeds. | Reduce the capacitance value of C25, C26 and C27 from 100pF to 10pF 50V NPO 0805 | . | pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in “TORQUE_MODE”. Workaround - Reset the MCU before re-starting the motor in “TORQUE_MODE”. | For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, enable “RAM_EXECUTE” mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory. | . Development Tools . | MPLAB X IDE v5.40 | MPLAB XC32 C/C++ Compiler v2.41 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.5.0. | X2CScope v1.3.0. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v350",
    "relUrl": "/release_notes.html#motor-control-release-v350"
  },"11": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.4.1",
    "content": "Updated Applications . | The following table provides the list of applications updated in this release. | . | Application | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | Revision History | . | pmsm_foc_encoder_pic32_mk | Sensored Field Oriented Control of PMSM using Quadrature Encoder | PIC32MK Motor Control Plugin Module | Yes | Yes | &lt;li&gt; PWM to Control Frequency was made 1:1 in Low Voltage Demo (MCLV-2) &lt;/li&gt;&lt;li&gt; Added High Voltage Support (MCHV-3)&lt;/li&gt; | . | pmsm_foc_pll_estimator_pic32_mk | Sensorless Field Oriented Control of PMSM using PLL Estimator | PIC32MK Motor Control Plugin Module | No | Yes | Added High Voltage Support (MCHV-3) | . Required MPLAB Harmony v3 Modules . | csp v3.5.0 | dev_packs v3.5.0 | mhc v3.3.0 | . Known Issues . | Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in “TORQUE_MODE”. Workaround - Reset the MCU before re-starting the motor in “TORQUE_MODE”. | For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, kindly enable “RAM_EXECUTE” mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory | . Development Tools . | MPLAB X IDE v5.25 | MPLAB XC32 C/C++ Compiler v2.30 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.3.0. | X2CScope v1.2.3. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v341",
    "relUrl": "/release_notes.html#motor-control-release-v341"
  },"12": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.4.0",
    "content": "New Algorithms . | The following table provides the list of algorithms added in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | . | pmsm_foc_encoder_pic32_mk | Sensored Field Oriented Control of PMSM using Quadrature Encoder | PIC32MK Motor Control Plugin Module | No | Yes | . | pmsm_foc_pll_estimator_pic32_mk | Sensorless Field Oriented Control of PMSM using PLL Estimator | PIC32MK Motor Control Plugin Module | No | Yes | . | pmsm_foc_smo_sam_e70 | Sensorless Field Oriented Control of PMSM using Sliding Mode Observer | ATSAME70 Motor Control Plugin Module | No | Yes | . | pmsm_foc_rolo_1shunt | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Single Shunt Current Sense | ATSAMC21 Motor Control Plugin Module | No | Yes | . Updated Algorithms . | The following table provides the list of algorithms updated in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | Revision History | . | pmsm_foc_encoder_sam_e70 | Sensored Field Oriented Control of PMSM using PDEC | ATSAME70 Motor Control Plugin Module | Yes | Yes | &lt;li&gt; Added motor start/stop Capability without resetting the MCU&lt;/li&gt; &lt;li&gt; Added Field Weakening support on low voltage application (MCLV-2)&lt;/li&gt;&lt;li&gt; Added MCHV-3 support (without Field Weakening)&lt;/li&gt; | . | pmsm_foc_pll_estimator_sam_e70 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME70 Motor Control Plugin Module | Yes | Yes | &lt;li&gt; Reduced dead-time in High Voltage demo (MCHV-3) to improve open loop to closed loop transition&lt;/li&gt;&lt;li&gt; Resolved bug in Field Weakening operation in reverse direction&lt;/li&gt; | . | pmsm_foc_encoder_sam_e54 | Sensored Field Oriented Control of PMSM using Quadrature Encoder | ATSAME54 Motor Control Plugin Module | Yes | Yes | &lt;li&gt;Added Field Weakening support on low voltage application (MCLV-2) &lt;/li&gt;&lt;li&gt; Added MCHV-3 Support (without field weakening support) &lt;/li&gt; | . | pmsm_foc_encoder_position_sam_e54 | FOC based Position Control of PMSM using Quadrature Encoder | ATSAME54 Motor Control Plugin Module | Yes | Yes | &lt;li&gt; Replaced the PI type Compensator in the position loop with P type Compensator&lt;/li&gt;&lt;li&gt; Added MCHV-3 Support &lt;/li&gt; | . | pmsm_foc_pll_estimator_sam_e54 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME54 Motor Control Plugin Module | Yes | Yes | &lt;li&gt; Unswapped PWMH and PWML output in TCC0 configuration &lt;/li&gt;&lt;li&gt; Update PWM Duty Cycle Update implementation to accomodate for unswapping of the PWMH and PWML&lt;/li&gt;&lt;li&gt;Over-current fault was made recoverable i.e. Motor can be re-started after an over-current fault without resetting the MCU&lt;/li&gt; | . | pmsm_foc_rolo_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | ATSAMC21 Motor Control Plugin Module | Yes | Yes | &lt;li&gt;Over-current fault was made recoverable i.e. Motor can be re-started after an over-current fault without resetting the MCU&lt;/li&gt; | . | pmsm_foc_rolo_wm_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | ATSAMC21 Motor Control Plugin Module | Yes | Yes | &lt;li&gt;Over-current fault was made recoverable i.e. Motor can be re-started after an over-current fault without resetting the MCU&lt;/li&gt;&lt;li&gt; Fixed Speed Filter implementation to make it direction agnostic | . Required MPLAB Harmony v3 Modules . | csp v3.5.0 | dev_packs v3.5.0 | mhc v3.3.0 | . Known Issues . | Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | pmsm_foc_rolo_1shunt may experience false over-current faults during alternate motor start command when operated in “TORQUE_MODE”. Workaround - Reset the MCU before re-starting the motor in “TORQUE_MODE”. | For any demos running on ATSAMC21 Motor Control PIM, if any failures are observed while trying to use X2CScope, these failures may occur due to shortage of CPU computation bandwidth. In such cases, kindly enable “RAM_EXECUTE” mode which speeds up execution by executing certain functions from RAM memory instead of Flash memory | . Development Tools . | MPLAB X IDE v5.25 | MPLAB XC32 C/C++ Compiler v2.30 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.3.0. | X2CScope v1.2.3. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v340",
    "relUrl": "/release_notes.html#motor-control-release-v340"
  },"13": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.3.1",
    "content": "Updated Algorithms . | The following table provides the list of algorithms updated in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | Revision History | . | pmsm_foc_pll_estimator_sam_e54 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME54 Motor Control Plugin Module | Yes | Yes | Added Windmilling (On-the-fly Startup) Support | . | pmsm_foc_rolo_fw_mtpa_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Field Weakening and MTPA Capability | ATSAMC21 Motor Control Plugin Module | No | Yes | Fixed error in MTPA calculation | . | pmsm_foc_pll_estimator_sam_e70 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME70 Motor Control Plugin Module | Yes | Yes | Added Bi-directional Support | . Required MPLAB Harmony v3.3.0 Modules . | csp v3.3.0 | dev_packs v3.3.0 | mhc v3.3.0 | . Known Issues . | Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | . Development Tools . | MPLAB X IDE v5.20 | MPLAB XC32 C/C++ Compiler v2.15 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.3.0. | X2CScope v1.2.3. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v331",
    "relUrl": "/release_notes.html#motor-control-release-v331"
  },"14": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.3.0",
    "content": "New Algorithms . | The following table provides the list of algorithms added in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | . | pmsm_pfc_foc_pll_estimator_sam_e70 | PFC and Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME70 Motor Control Plugin Module | Yes | No | . | pmsm_foc_rolo_fw_mtpa_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Field Weakening and MTPA Capability | ATSAMC21 Motor Control Plugin Module | No | Yes | . | bldc_bc_hall_sam_c21 | Block Commutation based control of BLDC motor using Hall Sensors | ATSAMC21 Motor Control Plugin Module | No | Yes | . | pmsm_foc_pll_estimator_sam_e54 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME54 Motor Control Plugin Module | Yes | Yes | . | pmsm_foc_encoder_sam_e54 | Sensored Field Oriented Control of PMSM using Quadrature Encoder | ATSAME54 Motor Control Plugin Module | No | Yes | . | pmsm_foc_encoder_position_sam_e54 | FOC based Position Control of PMSM using Quadrature Encoder | ATSAME54 Motor Control Plugin Module | No | Yes | . Updated Algorithms . | The following table provides the list of algorithms updated in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | Revision History | . | pmsm_foc_rolo_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | ATSAMC21 Motor Control Plugin Module | Yes | Yes | Regenerated application with csp v3.3.0 | . | pmsm_foc_rolo_wm_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | ATSAMC21 Motor Control Plugin Module | Yes | Yes | Regenerated application with csp v3.3.0 | . | acim_vhz_sam_c21 | Open Loop V/F Control of AC Induction Motor | ATSAMC21 Motor Control Plugin Module | Yes | No | Regenerated application with csp v3.3.0 | . | pmsm_foc_pll_estimator_sam_e70 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME70 Motor Control Plugin Module | Yes | Yes | Regenerated application with csp v3.3.0. Temporarily removed Field Weakening Support, to be added in future release. | . | pmsm_foc_encoder_sam_e70 | Sensored Field Oriented Control of PMSM using PDEC | ATSAME70 Motor Control Plugin Module | No | Yes | Regenerated application with csp v3.3.0 and added ability to spin the motor in both directions. | . Required MPLAB Harmony v3.3.0 Modules . | csp v3.3.0 | dev_packs v3.3.0 | mhc v3.3.0 | . Known Issues . | Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | . Development Tools . | MPLAB X IDE v5.20 | MPLAB XC32 C/C++ Compiler v2.15 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.3.0. | X2CScope v1.2.3. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v330",
    "relUrl": "/release_notes.html#motor-control-release-v330"
  },"15": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.2.0",
    "content": "New Algorithms . | The following table provides the list of algorithms added in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | . | pmsm_foc_rolo_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer | ATSAMC21 Motor Control Plugin Module | Yes | Yes | . | pmsm_foc_rolo_wm_sam_c21 | Sensorless Field Oriented Control of PMSM using Reduced Order Luenberger Observer with Windmilling Capability | ATSAMC21 Motor Control Plugin Module | Yes | Yes | . | acim_vhz_sam_c21 | Open Loop V/F Control of AC Induction Motor | ATSAMC21 Motor Control Plugin Module | Yes | No | . Updated Algorithms . | The following table provides the list of algorithms updated in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | Revision History | . | pmsm_foc_pll_estimator_sam_e70 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME70 Motor Control Plugin Module | Yes | Yes | Regenerated application with csp v3.2.0 | . | pmsm_foc_encoder_sam_e70 | Sensored Field Oriented Control of PMSM using PDEC | ATSAME70 Motor Control Plugin Module | No | Yes | Regenerated application with csp v3.2.0 and added ability to spin the motor in both directions. | . Required MPLAB Harmony v3.2.0 Modules . | csp v3.2.0 | dev_packs v3.2.0 | mhc v3.2.0 | . Known Issues . | MPLAB X IDE v5.15 fails to program ATSAME70 Motor Control Plugin Module on dsPICDEM™ MCHV-3 High Voltage Development Board. In order to resolve this issue, implement the following change in dap_cortex-m7.py, located at C:\\\\Program Files (x86)\\\\Microchip\\\\MPLABX\\v5.15\\\\packs\\\\Microchip\\SAME70_DFP\\3.0.10\\\\scripts\\\\ . | Goto line # 197, replace dap.Connect(True, 8000000L) with dap.Connect(True, 2000000L) | . | Programming or debugging SAM C/D2x or SAM D/E5x MCU, using Isolated EDBG Card (board revision #02-10824-R1) on dsPICDEM™ MCHV-3 High Voltage Development Board may inhibit MCU from executing instructions if the MCU is reset by pressing on board ‘Reset’ switch or power cycling the board. Refer to the Isolated EDBG Debugger Product Change Notice for details of hardware modification needed to resolve this issue. | . Development Tools . | MPLAB X IDE v5.15 | MPLAB XC32 C/C++ Compiler v2.15 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.2.0. | X2CScope v1.2.3. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v320",
    "relUrl": "/release_notes.html#motor-control-release-v320"
  },"16": {
    "doc": "Release notes",
    "title": "Motor Control Release v3.1.0",
    "content": "New Algorithms . | The following table provides the list of algorithms added in this release. | . | Algorithm | Description | Supported Plug In Module | dsPICDEM™ MCHV-3 Support | dsPICDEM™ MCLV-2 Support | . | pmsm_foc_pll_estimator_sam_e70 | Sensorless Field Oriented Control of PMSM using PLL Estimator | ATSAME70 Motor Control Plugin Module | Yes | Yes | . | pmsm_foc_encoder_sam_e70 | Sensored Field Oriented Control of PMSM using PDEC | ATSAME70 Motor Control Plugin Module | No | Yes | . Required MPLAB Harmony v3.1.0 Modules . | csp v3.1.0 | dev_packs v3.1.0 | mhc v3.1.0 | . Known Issues . | None. | . Development Tools . | MPLAB X IDE v5.10 | MPLAB XC32 C/C++ Compiler v2.15 | MPLAB X IDE plug-ins: . | MPLAB Harmony Configurator (MHC) v3.1.0. | X2CScope v1.2.3. | . | . ",
    "url": "http://localhost:4000/motor_control/release_notes.html#motor-control-release-v310",
    "relUrl": "/release_notes.html#motor-control-release-v310"
  },"17": {
    "doc": "Release notes",
    "title": "Release notes",
    "content": ". ",
    "url": "http://localhost:4000/motor_control/release_notes.html",
    "relUrl": "/release_notes.html"
  },"18": {
    "doc": "Using the Library",
    "title": "Using the Library",
    "content": ". | Instantiate PMSM_FOC component | Connect to required PLIBs (ADC, PWM, QDEC) and X2CScope and UART. Configure ADC, PWM and QDEC parameters in PMSM_FOC UI. Please refer to the project graph shown below. Note that PLIB names will be different for different devices | . | Select motor, control board, position feedback method in UI. Configure advanced parameters like field weakening, flying start. | Configure pins in the pin manager | Generate the code | PMSM_FOC is initialized in the SYS_Initialize() function. Function name is PMSM_FOC_Initialize(). | Call PMSM_FOC_Tasks() in the while loop in the main.c | Call X2CScope_Communicate() in the while loop in the main.c | Motor start/stop and direction change is done on the switch event. For MCLV2 board, press S2 to start/stop the motor. And press switch S3 to change the direction of the motor when motor is stopped. For MCHV3, press pushbutton to start/stop the motor | Vary the potentiometer to change the speed of the motor in speed loop . PMSM_FOC_Tasks(); X2CScope_Communicate(); . | . ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/using_the_library.html",
    "relUrl": "/algorithms/pmsm_foc/using_the_library.html"
  },"19": {
    "doc": "Software Design",
    "title": "Software Design",
    "content": "## Software Design - PMSM FOC Control loop is implemented in the ADC result ready interrupt. Refer to the flow chart given below. - ADC channel conversion is triggered by the PWM overflow/zero match event. This trigger point could vary based on the current measurement techniques and MCU PWM IP implementation. - ADC interrupt frequency depends on the PWM frequency. - Slow loop task is executed 10 times slower than ADC interrupt. Polling of switches for user inputs and reference speed calculation is handled in the slow loop task. ### Timing Diagram ![timing_diagram](/motor_control/algorithms/pmsm_foc/images/timing_diagram.png) ### Flow Chart ![flow_chart](/motor_control/algorithms/pmsm_foc/images/flow_chart.png) ### State Machine - **Idle**: In this state, control waits for the switch press. - **Flying Start**: In this state, the control algorithm detects if the motor is freewheeling. If the motor's freewheeling speed is above the minimum Flying Start Detect speed and in the same direction as the command direction, the state machine directly enters in to \\\"Closed Loop\\\" state. However, if the freewheeling speed is less than minimum Flying Start Detect speed, the control algorithm attempts to passive brake the motor by applying pulses of \\\"NUll Vectors\\\". If the freewheeling speed is more than the minimum Flying Start Detect speed but in the opposite direction of the command direction, the control algorithm attempts to active brake the motor by regenerative braking (if enabled). Once the motor speed falls below the minimum Flying Start Detect speed, the control algorithm attempts to passive brake the motor by applying pulses of \\\"NUll Vectors\\\". - **Field Alignement**: Rotor is aligned to known position at D-axis or Q-axis by applying a pre-defined value of the current for a pre-defined length of time. The magnitude of the current and the length of the time for which it is applied depends upon the electrical and mechanical time constant of the PMSM motor drive. Electrical time constant of the motor is a function of R and L values of the motor windings, whereas the mechanical time constant of the motor drive is primarily a function of the static load on the motor shaft. - **Open Loop**: This state is applicable to sensorless position feedback methods. In this state, the speed of the PMSM motor is gradually ramped up using an open loop control. During this mode, the rotor angle is derived from the asserted open loop speed reference. This derived rotor angle would be lagging from the actual rotor angle. The speed is ramped up linearly to a minimum value required for the PLL estimator to estimate the electrical speed of the PMSM motor with sufficient accuracy. Rotor angle information is obtained by integrating the estimated electrical speed of the motor. - **Closing Loop**: In this state, control waits for stabilization time. - **Closed Loop**: Control switched to closed loop and rotor angle is obtained from the configured position feedback method. ### Code Structure ![code_structure](/motor_control/algorithms/pmsm_foc/images/code_structure.png) Configurations: - mc_userparameters.h contains the user configurations. - mc_derivedparameters.h contains the calculated values used in the code. - mc_pmsm_foc_common.h - common data structures and defines PMSM_FOC: - mc_pmsm_foc.c/h - PMSM FOC algorithm interface file Interrupts: - mc_control_loop.c - Control loop is implemented in the ADC result ready ISR. - mc_errorhandler.c - PWM fault ISR to take corrective action on over-current Control library: - mc_lib.c/h - FOC library - mc_picontroller.c/h - PI controller implementation - mc_pwm.c/h - Space Vector modulation (SVM) and updating PWM duty cycles - lib_mc_flyingstart.a - Flying Start Control Library Control Middleware: - mc_speed.c/h - Calculate the reference speed - mc_rotorposition.c/.h - Calculate the position and speed of the rotor - mc_voltagemeasurement.c/h - Get the DC Bus voltage - mc_currentmeasurement.c/h - Get the motor phase currents HAL: - mc_hal.h - Hardware Abstraction Layer to interact with PLIBs ",
    "url": "http://localhost:4000/motor_control/algorithms/pmsm_foc/sw_design.html",
    "relUrl": "/algorithms/pmsm_foc/sw_design.html"
  },"20": {
    "doc": "Software Design",
    "title": "Software Design",
    "content": "## Software Design - PMSM FOC Control loop is implemented in the ADC result ready interrupt. Refer to the flow chart given below. - ADC channel conversion is triggered by the PWM overflow/zero match event. This trigger point could vary based on the current measurement techniques and MCU PWM IP implementation. - ADC interrupt frequency depends on the PWM frequency. - Slow loop task is executed 10 times slower than ADC interrupt. Polling of switches for user inputs and reference speed calculation is handled in the slow loop task. ### Timing Diagram ![timing_diagram](/motor_control/docs/algorithms/pmsm_foc/images/timing_diagram.png) ### Flow Chart ![flow_chart](/motor_control/docs/algorithms/pmsm_foc/images/flow_chart.png) ### State Machine - **Idle**: In this state, control waits for the switch press. - **Flying Start**: In this state, the control algorithm detects if the motor is freewheeling. If the motor's freewheeling speed is above the minimum Flying Start Detect speed and in the same direction as the command direction, the state machine directly enters in to \\\"Closed Loop\\\" state. However, if the freewheeling speed is less than minimum Flying Start Detect speed, the control algorithm attempts to passive brake the motor by applying pulses of \\\"NUll Vectors\\\". If the freewheeling speed is more than the minimum Flying Start Detect speed but in the opposite direction of the command direction, the control algorithm attempts to active brake the motor by regenerative braking (if enabled). Once the motor speed falls below the minimum Flying Start Detect speed, the control algorithm attempts to passive brake the motor by applying pulses of \\\"NUll Vectors\\\". - **Field Alignement**: Rotor is aligned to known position at D-axis or Q-axis by applying a pre-defined value of the current for a pre-defined length of time. The magnitude of the current and the length of the time for which it is applied depends upon the electrical and mechanical time constant of the PMSM motor drive. Electrical time constant of the motor is a function of R and L values of the motor windings, whereas the mechanical time constant of the motor drive is primarily a function of the static load on the motor shaft. - **Open Loop**: This state is applicable to sensorless position feedback methods. In this state, the speed of the PMSM motor is gradually ramped up using an open loop control. During this mode, the rotor angle is derived from the asserted open loop speed reference. This derived rotor angle would be lagging from the actual rotor angle. The speed is ramped up linearly to a minimum value required for the PLL estimator to estimate the electrical speed of the PMSM motor with sufficient accuracy. Rotor angle information is obtained by integrating the estimated electrical speed of the motor. - **Closing Loop**: In this state, control waits for stabilization time. - **Closed Loop**: Control switched to closed loop and rotor angle is obtained from the configured position feedback method. ### Code Structure ![code_structure](/motor_control/docs/algorithms/pmsm_foc/images/code_structure.png) Configurations: - mc_userparameters.h contains the user configurations. - mc_derivedparameters.h contains the calculated values used in the code. - mc_pmsm_foc_common.h - common data structures and defines PMSM_FOC: - mc_pmsm_foc.c/h - PMSM FOC algorithm interface file Interrupts: - mc_control_loop.c - Control loop is implemented in the ADC result ready ISR. - mc_errorhandler.c - PWM fault ISR to take corrective action on over-current Control library: - mc_lib.c/h - FOC library - mc_picontroller.c/h - PI controller implementation - mc_pwm.c/h - Space Vector modulation (SVM) and updating PWM duty cycles - lib_mc_flyingstart.a - Flying Start Control Library Control Middleware: - mc_speed.c/h - Calculate the reference speed - mc_rotorposition.c/.h - Calculate the position and speed of the rotor - mc_voltagemeasurement.c/h - Get the DC Bus voltage - mc_currentmeasurement.c/h - Get the motor phase currents HAL: - mc_hal.h - Hardware Abstraction Layer to interact with PLIBs ",
    "url": "http://localhost:4000/motor_control/docs/algorithms/pmsm_foc/sw_design.html",
    "relUrl": "/docs/algorithms/pmsm_foc/sw_design.html"
  },"21": {
    "doc": "Harmony 3 Motor Control",
    "title": "Harmony 3 Motor Control",
    "content": "# Microchip MPLAB® Harmony 3 Motor Control MPLAB Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC32 microcontroller and microprocessor devices. Refer to the following links for more information. - [Microchip 32-bit MCUs for Motor Control Applications](https://www.microchip.com/design-centers/motor-control-and-drive/control-products/32-bit-solutions) - [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit) - [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus) - [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide) - [Microchip MPLAB Harmony](https://www.microchip.com/mplab/mplab-harmony) - [Microchip MPLAB Harmony Pages](https://microchip-mplab-harmony.github.io/) This repository contains the MPLAB® Harmony 3 Motor Control module. This module contains motor control demonstrations implemented on Microchip's 32-bit SAM and PIC32 microcontrollers. Users can use these demonstrations as a reference for developing their own motor control applications on Microchip's SAM and PIC32 series of microcontrollers using MPLAB Harmony 3. Refer to the following links for release notes and licensing information. - [Release Notes](/motor_control/release_notes.html) - [MPLAB Harmony License](/motor_control/mplab_harmony_license.html) # Contents Summary | Folder | Description |------------|-----------------------------------------------------------| algorithms | Motor Control Algorithm components | doc | Demonstration user guide in .chm format | docs | Demonstration user guide in HTML format | # Motor Control Algorithms | Algorithm | Description |------------ | -------------- | [PMSM FOC Algorithm](/motor_control/algorithms/pmsm_foc/readme.html) | To Control Permanant Magnet Synchronous Motors using Field Oriented Control (FOC) ||| # Motor Control Demo Applications Repositories | Repository Name | Description | Help Document | ----------------- | ------------------- | ---------------- | [mc_apps_pic32cm_mc](https://github.com/Microchip-MPLAB-Harmony/mc_apps_pic32cm_mc) | Motor Control Applications for PIC32CM MC family | [[mc_apps_pic32cm_mc help](https://microchip-mplab-harmony.github.io/mc_apps_pic32cm_mc/) | [mc_apps_pic32mk](https://github.com/Microchip-MPLAB-Harmony/mc_apps_pic32mk) | Motor Control Applications for PIC32MK family | [mc_apps_pic32mk help](https://microchip-mplab-harmony.github.io/mc_apps_pic32mk/) | [mc_apps_sam_c2x](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_c2x) | Motor Control Applications for SAM C2x family | [[mc_apps_sam_c2x help](https://microchip-mplab-harmony.github.io/mc_apps_sam_c2x/) | [mc_apps_sam_d5x_e5x](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_d5x_e5x) | Motor Control Applications for SAM E5x family | [mc_apps_sam_d5x_e5x help](https://microchip-mplab-harmony.github.io/mc_apps_sam_d5x_e5x/) | [mc_apps_sam_e7x_s7x_v7x](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_e7x_s7x_v7x) | Motor Control Applications for SAM E7x family | [mc_apps_sam_e7x_s7x_v7x help](https://microchip-mplab-harmony.github.io/mc_apps_sam_e7x_s7x_v7x/) | [mc_apps_sam_rh71](https://github.com/Microchip-MPLAB-Harmony/mc_apps_sam_rh71) | Motor Control Applications for SAM RH71 family | [mc_apps_sam_rh71 help](https://microchip-mplab-harmony.github.io/mc_apps_sam_rh71/) ||||| ____ [![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/blob/master/mplab_harmony_license.md) [![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/releases/latest) [![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/releases/latest) [![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/mc.svg)](https://github.com/Microchip-MPLAB-Harmony/mc/graphs/commit-activity) [![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/mc.svg)]() ____ [![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology) [![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology) [![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/) [![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech) [![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/mc.svg?style=social)]() [![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/mc.svg?style=social)]() ",
    "url": "http://localhost:4000/motor_control/",
    "relUrl": "/"
  }
}
`;
var data_for_search

var repo_name = "motor_control";
var doc_folder_name = "docs";
var localhost_path = "http://localhost:4000/";
var home_index_string = "Microchip MPLAB® Harmony 3 Motor Control";

(function (jtd, undefined) {

// Event handling

jtd.addEvent = function(el, type, handler) {
  if (el.attachEvent) el.attachEvent('on'+type, handler); else el.addEventListener(type, handler);
}
jtd.removeEvent = function(el, type, handler) {
  if (el.detachEvent) el.detachEvent('on'+type, handler); else el.removeEventListener(type, handler);
}
jtd.onReady = function(ready) {
  // in case the document is already rendered
  if (document.readyState!='loading') ready();
  // modern browsers
  else if (document.addEventListener) document.addEventListener('DOMContentLoaded', ready);
  // IE <= 8
  else document.attachEvent('onreadystatechange', function(){
      if (document.readyState=='complete') ready();
  });
}

// Show/hide mobile menu

function initNav() {
  jtd.addEvent(document, 'click', function(e){
    var target = e.target;
    while (target && !(target.classList && target.classList.contains('nav-list-expander'))) {
      target = target.parentNode;
    }
    if (target) {
      e.preventDefault();
      target.parentNode.classList.toggle('active');
    }
  });

  const siteNav = document.getElementById('site-nav');
  const mainHeader = document.getElementById('main-header');
  const menuButton = document.getElementById('menu-button');

  jtd.addEvent(menuButton, 'click', function(e){
    e.preventDefault();

    if (menuButton.classList.toggle('nav-open')) {
      siteNav.classList.add('nav-open');
      mainHeader.classList.add('nav-open');
    } else {
      siteNav.classList.remove('nav-open');
      mainHeader.classList.remove('nav-open');
    }
  });
}
// Site search

function initSearch() {

    data_for_search = JSON.parse(myVariable);
    lunr.tokenizer.separator = /[\s/]+/

    var index = lunr(function () {
        this.ref('id');
        this.field('title', { boost: 200 });
        this.field('content', { boost: 2 });
        this.field('url');
        this.metadataWhitelist = ['position']

        var location = document.location.pathname;
        var path = location.substring(0, location.lastIndexOf("/"));
        var directoryName = path.substring(path.lastIndexOf("/")+1);

        var cur_path_from_repo = path.substring(path.lastIndexOf(repo_name));

        // Decrement depth by 2 as HTML files are placed in repo_name/doc_folder_name
        var cur_depth_from_doc_folder = (cur_path_from_repo.split("/").length - 2);

        var rel_path_to_doc_folder = "";

        if (cur_depth_from_doc_folder == 0) {
            rel_path_to_doc_folder = "./"
        }
        else {
            for (var i = 0; i < cur_depth_from_doc_folder; i++)
            {
                rel_path_to_doc_folder = rel_path_to_doc_folder + "../"
            }
        }

        for (var i in data_for_search) {

            data_for_search[i].url = data_for_search[i].url.replace(localhost_path + repo_name, rel_path_to_doc_folder);

            if (data_for_search[i].title == home_index_string)
            {
                data_for_search[i].url = data_for_search[i].url + "index.html"
            }

            this.add({
                id: i,
                title: data_for_search[i].title,
                content: data_for_search[i].content,
                url: data_for_search[i].url
            });
        }
    });

    searchLoaded(index, data_for_search);
}function searchLoaded(index, docs) {
  var index = index;
  var docs = docs;
  var searchInput = document.getElementById('search-input');
  var searchResults = document.getElementById('search-results');
  var mainHeader = document.getElementById('main-header');
  var currentInput;
  var currentSearchIndex = 0;

  function showSearch() {
    document.documentElement.classList.add('search-active');
  }

  function hideSearch() {
    document.documentElement.classList.remove('search-active');
  }

  function update() {
    currentSearchIndex++;

    var input = searchInput.value;
    if (input === '') {
      hideSearch();
    } else {
      showSearch();
      // scroll search input into view, workaround for iOS Safari
      window.scroll(0, -1);
      setTimeout(function(){ window.scroll(0, 0); }, 0);
    }
    if (input === currentInput) {
      return;
    }
    currentInput = input;
    searchResults.innerHTML = '';
    if (input === '') {
      return;
    }

    var results = index.query(function (query) {
      var tokens = lunr.tokenizer(input)
      query.term(tokens, {
        boost: 10
      });
      query.term(tokens, {
        wildcard: lunr.Query.wildcard.TRAILING
      });
    });

    if ((results.length == 0) && (input.length > 2)) {
      var tokens = lunr.tokenizer(input).filter(function(token, i) {
        return token.str.length < 20;
      })
      if (tokens.length > 0) {
        results = index.query(function (query) {
          query.term(tokens, {
            editDistance: Math.round(Math.sqrt(input.length / 2 - 1))
          });
        });
      }
    }

    if (results.length == 0) {
      var noResultsDiv = document.createElement('div');
      noResultsDiv.classList.add('search-no-result');
      noResultsDiv.innerText = 'No results found';
      searchResults.appendChild(noResultsDiv);

    } else {
      var resultsList = document.createElement('ul');
      resultsList.classList.add('search-results-list');
      searchResults.appendChild(resultsList);

      addResults(resultsList, results, 0, 10, 100, currentSearchIndex);
    }

    function addResults(resultsList, results, start, batchSize, batchMillis, searchIndex) {
      if (searchIndex != currentSearchIndex) {
        return;
      }
      for (var i = start; i < (start + batchSize); i++) {
        if (i == results.length) {
          return;
        }
        addResult(resultsList, results[i]);
      }
      setTimeout(function() {
        addResults(resultsList, results, start + batchSize, batchSize, batchMillis, searchIndex);
      }, batchMillis);
    }

    function addResult(resultsList, result) {
      var doc = docs[result.ref];

      var resultsListItem = document.createElement('li');
      resultsListItem.classList.add('search-results-list-item');
      resultsList.appendChild(resultsListItem);

      var resultLink = document.createElement('a');
      resultLink.classList.add('search-result');
      resultLink.setAttribute('href', doc.url);
      resultsListItem.appendChild(resultLink);

      var resultTitle = document.createElement('div');
      resultTitle.classList.add('search-result-title');
      resultLink.appendChild(resultTitle);

      var resultDoc = document.createElement('div');
      resultDoc.classList.add('search-result-doc');
      resultDoc.innerHTML = '<svg viewBox="0 0 24 24" class="search-result-icon"><use xlink:href="#svg-doc"></use></svg>';
      resultTitle.appendChild(resultDoc);

      var resultDocTitle = document.createElement('div');
      resultDocTitle.classList.add('search-result-doc-title');
      resultDocTitle.innerHTML = doc.doc;
      resultDoc.appendChild(resultDocTitle);
      var resultDocOrSection = resultDocTitle;

      if (doc.doc != doc.title) {
        resultDoc.classList.add('search-result-doc-parent');
        var resultSection = document.createElement('div');
        resultSection.classList.add('search-result-section');
        resultSection.innerHTML = doc.title;
        resultTitle.appendChild(resultSection);
        resultDocOrSection = resultSection;
      }

      var metadata = result.matchData.metadata;
      var titlePositions = [];
      var contentPositions = [];
      for (var j in metadata) {
        var meta = metadata[j];
        if (meta.title) {
          var positions = meta.title.position;
          for (var k in positions) {
            titlePositions.push(positions[k]);
          }
        }
        if (meta.content) {
          var positions = meta.content.position;
          for (var k in positions) {
            var position = positions[k];
            var previewStart = position[0];
            var previewEnd = position[0] + position[1];
            var ellipsesBefore = true;
            var ellipsesAfter = true;
            for (var k = 0; k < 5; k++) {
              var nextSpace = doc.content.lastIndexOf(' ', previewStart - 2);
              var nextDot = doc.content.lastIndexOf('. ', previewStart - 2);
              if ((nextDot >= 0) && (nextDot > nextSpace)) {
                previewStart = nextDot + 1;
                ellipsesBefore = false;
                break;
              }
              if (nextSpace < 0) {
                previewStart = 0;
                ellipsesBefore = false;
                break;
              }
              previewStart = nextSpace + 1;
            }
            for (var k = 0; k < 10; k++) {
              var nextSpace = doc.content.indexOf(' ', previewEnd + 1);
              var nextDot = doc.content.indexOf('. ', previewEnd + 1);
              if ((nextDot >= 0) && (nextDot < nextSpace)) {
                previewEnd = nextDot;
                ellipsesAfter = false;
                break;
              }
              if (nextSpace < 0) {
                previewEnd = doc.content.length;
                ellipsesAfter = false;
                break;
              }
              previewEnd = nextSpace;
            }
            contentPositions.push({
              highlight: position,
              previewStart: previewStart, previewEnd: previewEnd,
              ellipsesBefore: ellipsesBefore, ellipsesAfter: ellipsesAfter
            });
          }
        }
      }

      if (titlePositions.length > 0) {
        titlePositions.sort(function(p1, p2){ return p1[0] - p2[0] });
        resultDocOrSection.innerHTML = '';
        addHighlightedText(resultDocOrSection, doc.title, 0, doc.title.length, titlePositions);
      }

      if (contentPositions.length > 0) {
        contentPositions.sort(function(p1, p2){ return p1.highlight[0] - p2.highlight[0] });
        var contentPosition = contentPositions[0];
        var previewPosition = {
          highlight: [contentPosition.highlight],
          previewStart: contentPosition.previewStart, previewEnd: contentPosition.previewEnd,
          ellipsesBefore: contentPosition.ellipsesBefore, ellipsesAfter: contentPosition.ellipsesAfter
        };
        var previewPositions = [previewPosition];
        for (var j = 1; j < contentPositions.length; j++) {
          contentPosition = contentPositions[j];
          if (previewPosition.previewEnd < contentPosition.previewStart) {
            previewPosition = {
              highlight: [contentPosition.highlight],
              previewStart: contentPosition.previewStart, previewEnd: contentPosition.previewEnd,
              ellipsesBefore: contentPosition.ellipsesBefore, ellipsesAfter: contentPosition.ellipsesAfter
            }
            previewPositions.push(previewPosition);
          } else {
            previewPosition.highlight.push(contentPosition.highlight);
            previewPosition.previewEnd = contentPosition.previewEnd;
            previewPosition.ellipsesAfter = contentPosition.ellipsesAfter;
          }
        }

        var resultPreviews = document.createElement('div');
        resultPreviews.classList.add('search-result-previews');
        resultLink.appendChild(resultPreviews);

        var content = doc.content;
        for (var j = 0; j < Math.min(previewPositions.length, 3); j++) {
          var position = previewPositions[j];

          var resultPreview = document.createElement('div');
          resultPreview.classList.add('search-result-preview');
          resultPreviews.appendChild(resultPreview);

          if (position.ellipsesBefore) {
            resultPreview.appendChild(document.createTextNode('... '));
          }
          addHighlightedText(resultPreview, content, position.previewStart, position.previewEnd, position.highlight);
          if (position.ellipsesAfter) {
            resultPreview.appendChild(document.createTextNode(' ...'));
          }
        }
      }
      var resultRelUrl = document.createElement('span');
      resultRelUrl.classList.add('search-result-rel-url');
      resultRelUrl.innerText = doc.relUrl;
      resultTitle.appendChild(resultRelUrl);
    }

    function addHighlightedText(parent, text, start, end, positions) {
      var index = start;
      for (var i in positions) {
        var position = positions[i];
        var span = document.createElement('span');
        span.innerHTML = text.substring(index, position[0]);
        parent.appendChild(span);
        index = position[0] + position[1];
        var highlight = document.createElement('span');
        highlight.classList.add('search-result-highlight');
        highlight.innerHTML = text.substring(position[0], index);
        parent.appendChild(highlight);
      }
      var span = document.createElement('span');
      span.innerHTML = text.substring(index, end);
      parent.appendChild(span);
    }
  }

  jtd.addEvent(searchInput, 'focus', function(){
    setTimeout(update, 0);
  });

  jtd.addEvent(searchInput, 'keyup', function(e){
    switch (e.keyCode) {
      case 27: // When esc key is pressed, hide the results and clear the field
        searchInput.value = '';
        break;
      case 38: // arrow up
      case 40: // arrow down
      case 13: // enter
        e.preventDefault();
        return;
    }
    update();
  });

  jtd.addEvent(searchInput, 'keydown', function(e){
    switch (e.keyCode) {
      case 38: // arrow up
        e.preventDefault();
        var active = document.querySelector('.search-result.active');
        if (active) {
          active.classList.remove('active');
          if (active.parentElement.previousSibling) {
            var previous = active.parentElement.previousSibling.querySelector('.search-result');
            previous.classList.add('active');
          }
        }
        return;
      case 40: // arrow down
        e.preventDefault();
        var active = document.querySelector('.search-result.active');
        if (active) {
          if (active.parentElement.nextSibling) {
            var next = active.parentElement.nextSibling.querySelector('.search-result');
            active.classList.remove('active');
            next.classList.add('active');
          }
        } else {
          var next = document.querySelector('.search-result');
          if (next) {
            next.classList.add('active');
          }
        }
        return;
      case 13: // enter
        e.preventDefault();
        var active = document.querySelector('.search-result.active');
        if (active) {
          active.click();
        } else {
          var first = document.querySelector('.search-result');
          if (first) {
            first.click();
          }
        }
        return;
    }
  });

  jtd.addEvent(document, 'click', function(e){
    if (e.target != searchInput) {
      hideSearch();
    }
  });
}

// Switch theme

jtd.getTheme = function() {
  var cssFileHref = document.querySelector('[rel="stylesheet"]').getAttribute('href');
  return cssFileHref.substring(cssFileHref.lastIndexOf('-') + 1, cssFileHref.length - 4);
}

jtd.setTheme = function(theme) {
  var cssFile = document.querySelector('[rel="stylesheet"]');
  cssFile.setAttribute('href', 'http://localhost:4000/motor_control/assets/css/just-the-docs-' + theme + '.css');
}

// Document ready

jtd.onReady(function(){
  initNav();
  initSearch();
});

})(window.jtd = window.jtd || {});


