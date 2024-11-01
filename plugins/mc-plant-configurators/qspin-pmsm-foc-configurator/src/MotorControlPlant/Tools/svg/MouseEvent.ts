/*
 * Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 */
function CallMouseMove(evt: { target: any }, svgdoc: any, toolTipObject: any) {
  // document.body.style.cursor = 'pointer';
  document.body.className = 'hand';
  var target = evt.target;
  if (target.correspondingUseElement) {
    target = target.correspondingUseElement;
  }
  showTooltip(evt, target.toolTip, svgdoc, toolTipObject);
}

function hideTooltip(toolTipObject: any) {
  toolTipObject.setAttributeNS(null, 'visibility', 'hidden');
}

export function CallMouseLeave(evt: { target: any }, toolTipObject: any) {
  // document.body.style.cursor = 'auto';
  document.body.className = 'normal';
  hideTooltip(toolTipObject);
}

function showTooltip(
  evt: { target?: any; clientX?: any; clientY?: any },
  text: any,
  svgdoc: any,
  toolTipObject: any
) {
  var CTM = svgdoc.getScreenCTM();
  var mouseX = (evt.clientX - CTM.e) / CTM.a;
  var mouseY = (evt.clientY - CTM.f) / CTM.d;
  toolTipObject.setAttributeNS(null, 'x', mouseX + 6 / CTM.a);
  toolTipObject.setAttributeNS(null, 'y', mouseY + 20 / CTM.d);
  toolTipObject.setAttributeNS(null, 'visibility', 'visible');
  var x = (evt.clientX - CTM.e + 6) / CTM.a;
  var y = (evt.clientY - CTM.f + 20) / CTM.d;
  toolTipObject.setAttributeNS(null, 'transform', 'translate(' + x + ' ' + y + ')');

  var tooltipText = toolTipObject.getElementsByTagName('text')[0];
  tooltipText.firstChild.data = text;

  var tooltipRects = toolTipObject.getElementsByTagName('rect');
  var length = tooltipText.getComputedTextLength();
  for (var i = 0; i < tooltipRects.length; i++) {
    tooltipRects[i].setAttributeNS(null, 'width', length + 8);
  }
}
export { CallMouseMove };
