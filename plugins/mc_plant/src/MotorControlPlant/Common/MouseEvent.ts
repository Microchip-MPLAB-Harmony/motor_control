export function CallMouseMove(
  evt: { target: any },
  svgdoc: any,
  toolTipObject: any
) {
  document.body.style.cursor = "pointer";
  var target = evt.target;
  if (target.correspondingUseElement) target = target.correspondingUseElement;
  showTooltip(evt, target.toolTip, svgdoc, toolTipObject);
}

function hideTooltip(toolTipObject: any) {
  toolTipObject.setAttributeNS(null, "visibility", "hidden");
}

export function CallMouseLeave(evt: { target: any }, toolTipObject: any) {
  document.body.style.cursor = "auto";
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
  toolTipObject.setAttributeNS(null, "x", mouseX + 6 / CTM.a);
  toolTipObject.setAttributeNS(null, "y", mouseY + 20 / CTM.d);
  toolTipObject.setAttributeNS(null, "visibility", "visible");
  var x = (evt.clientX - CTM.e + 6) / CTM.a;
  var y = (evt.clientY - CTM.f + 20) / CTM.d;
  toolTipObject.setAttributeNS(
    null,
    "transform",
    "translate(" + x + " " + y + ")"
  );

  var tooltipText = toolTipObject.getElementsByTagName("text")[0];
  tooltipText.firstChild.data = text;

  var tooltipRects = toolTipObject.getElementsByTagName("rect");
  var length = tooltipText.getComputedTextLength();
  for (var i = 0; i < tooltipRects.length; i++) {
    tooltipRects[i].setAttributeNS(null, "width", length + 8);
  }
}
