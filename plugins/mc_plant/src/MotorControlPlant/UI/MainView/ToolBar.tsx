import React from "react";
import { Button } from "primereact/button";
import { Toolbar } from "primereact/toolbar";
import icon from "../../../Resources/Images/MICH4C.png";

import "../../../Styles/Headder.css";
import PrimeReact from "primereact/api";
import { LoadImage, HideDiv, ShowDiv } from '../../Common/NodeUtils';
import { ZoomInReact, ZoomOutReact } from '../../Common/SymbolAccess';

let portNumber = (window as any).javaConnector.getPortNumber();

const Headder = () => {
  PrimeReact.ripple = true;

  const leftContents = (
    <React.Fragment>
      {LoadImage(icon)}
      <label style={{ fontSize: "18px", fontWeight: "bolder" }}>
        {" "}
        MOTOR CONTROL PLANT{" "}
      </label>
    </React.Fragment>
  );

  const rightContents = (
    <React.Fragment>
      <Button
        label="HOME"
        tooltip="View MC Plant Home Screen"
        tooltipOptions={{ position: "bottom" }}
        icon="pi pi-home"
        iconPos="left"
        className="p-button p-button-text p-mr-2"
        style={{ fontWeight: "bold", color: "black" }}
        onClick={() => LoadHome()}
      />
      <Button
        label="SUMMARY"
        tooltip="View Summary"
        tooltipOptions={{ position: "bottom" }}
        className="p-button p-button-text  p-mr-2"
        style={{ fontWeight: "bold", color: "black" }}
        onClick={() => LoadSummary()}
      />
      <Button
        label="HELP"
        tooltip="View MC Plant help"
        tooltipOptions={{ position: "bottom" }}
        // icon="pi pi-search"
        className="p-button p-button-text  p-mr-2"
        iconPos="right"
        style={{ fontWeight: "bold", color: "black" }}
        onClick={() => LoadHelp()}
      />
      <Button
        tooltip="Ctrl + Mouse Scroll Up"
        tooltipOptions={{ position: "left" }}
        icon="pi pi-search-plus"
        className="p-button-rounded p-button-text p-button-plain p-button-lg p-mr-1"
        onClick={() => ZoomIn()}
      />
      <Button
        tooltip="Ctrl + Mouse Scroll Down"
        tooltipOptions={{ position: "left" }}
        icon="pi pi-search-minus"
        className="p-button-rounded p-button-text p-button-lg p-button-plain"
        onClick={() => ZoomOut()}
      />
    </React.Fragment>
  );

  const HideAll = () => {
    HideDiv(document.getElementById("motor"));
    HideDiv(document.getElementById("summary"));
  };

  const LoadHome = () => {
    HideAll();
    ShowDiv(document.getElementById("motor"), null);
  };

  const LoadSummary = () => {
    HideAll();
    ShowDiv(document.getElementById("summary"), null);
  };

  const LoadHelp = () => {
    window.open(
      "http://localhost:" + portNumber + "/motor_control/docs/index.html",
      "_blank",
      "toolbar=0,location=0,menubar=0"
    );
  };

  function ZoomIn(){
    ZoomInReact();
  }

  function ZoomOut(){
    ZoomOutReact();
  }

  function openInNewTab(href: any) {
    Object.assign(document.createElement("a"), {
      target: "_blank",
      href: href,
    }).click();
  }

  return (
    <div className="Headder">
      <div>
        <Toolbar
          left={leftContents}
          right={rightContents}
          style={{ background: "white", height: "60px", maxHeight:"60px", border: "white", positon:"sticky", top:"0", overflow:"hidden" }}
        />
      </div>
    </div>
  );
};

export default Headder;
