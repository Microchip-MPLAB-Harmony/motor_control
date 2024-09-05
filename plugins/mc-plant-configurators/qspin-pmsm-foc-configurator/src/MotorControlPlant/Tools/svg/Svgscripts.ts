import { CallMouseLeave, CallMouseMove } from './MouseEvent';

export function resetColors(svgdoc: any) {
  let myNodelist = svgdoc.querySelectorAll('*');
  let i;
  for (i = 0; i < myNodelist.length; i++) {
    if (myNodelist[i].style) {
      myNodelist[i].style.fill = myNodelist[i].myParm2;
    } else if (myNodelist[i].getAttribute('fill')) {
      myNodelist[i].setAttribute('fill', myNodelist[i].myParm2);
    }
  }
}

export function changeColor(group: any) {
  for (let i = 0; i < group.childNodes.length; i++) {
    let element = group.childNodes[i];
    if (element.nodeType !== 3) {
      if (element.childNodes.length !== 0) {
        changeColor(element);
      } else if (
        (element.tagName === 'rect' ||
          element.tagName === 'path' ||
          element.tagName === 'circle') &&
        element.id !== ''
      ) {
        if (element && element.getAttribute('fill')) {
          element.setAttribute('fill', '#757575');
        } else if (element && element.getAttribute('style')) {
          element.style.fill = '#757575';
        }
      }
    }
  }
}

export function storeComponentColors(svgdoc: any) {
  let myNodelist = svgdoc.querySelectorAll('*');
  let i;
  for (i = 0; i < myNodelist.length; i++) {
    if (myNodelist[i].style) {
      myNodelist[i].myParm2 = myNodelist[i].style.fill;
    } else if (myNodelist[i].getAttribute('fill')) {
      myNodelist[i].myParm2 = myNodelist[i].getAttribute('fill');
    }
  }
}

export function addEventListeners(
  svg: any,
  groupid: any,
  dialogHeading: string,
  popupType: boolean,
  sendClickAction: (arg: any) => void,
  childAndParent: Map<any, any>,
  svgAndToolTipObject: Map<any, any>
) {
  let group = svg.getElementById(groupid);
  IterateSVGelements(
    svg,
    group,
    groupid,
    dialogHeading,
    popupType,
    sendClickAction,
    childAndParent,
    mouseMove,
    mouseLeave
  );

  function mouseMove(evt: { target: any }) {
    CallMouseMove(
      evt,
      childAndParent.get(evt.target),
      svgAndToolTipObject.get(childAndParent.get(evt.target))
    );
  }

  function mouseLeave(evt: { target: any }) {
    CallMouseLeave(evt, svgAndToolTipObject.get(childAndParent.get(evt.target)));
  }
}
function IterateSVGelements(
  svg: any,
  group: any,
  groupid: any,
  dialogHeading: string,
  popupType: boolean,
  sendClickAction: (arg: any) => void,
  childAndParent: Map<any, any>,
  mouseMove: (arg: any) => void,
  mouseLeave: (arg: any) => void
) {
  try {
    for (let i = 0; i < group.childNodes.length; i++) {
      let childElement = group.childNodes[i];
      childElement.addEventListener('click', sendClickAction, false);
      childElement.addEventListener('mousemove', mouseMove);
      childElement.addEventListener('mouseleave', mouseLeave);
      childAndParent.set(childElement, svg);
      if (popupType) {
        childElement.value = groupid;
      }
      childElement.toolTip = dialogHeading;
      if (childElement.childNodes.length > 0) {
        IterateSVGelements(
          svg,
          childElement,
          groupid,
          dialogHeading,
          popupType,
          sendClickAction,
          childAndParent,
          mouseMove,
          mouseLeave
        );
      }
    }
  } catch {}
}
