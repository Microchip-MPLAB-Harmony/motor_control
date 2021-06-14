import React from "react";
import { Button } from "primereact/button";
import { Toolbar } from "primereact/toolbar";

const Headder = () => {

    const leftContents = (
        <React.Fragment>
           
           
            <Button label="Hardware" style={{background : '#f99', color:'black'}} tooltip="click here to view Hardware block elements only" tooltipOptions={{position: 'bottom'}}  />
            {/* <i className="pi pi-arrow-right" style={{'fontSize': '2em'}}/> */}
            <span className="p-mr-4">    </span>
            <Button label="Control" style={{background : '#0050ef', color:'white'}} tooltip="click here to view Control block elements only" className="p-button-success" tooltipOptions={{position: 'bottom'}} />
            {/* <span className="p-mr-4">    </span> */}
            {/* <i className="pi pi-arrow-right" style={{'fontSize': '2em'}}/> */}
            
            <span className="p-mr-4">    </span><Button label="Peripheral" style={{background : '#ffdb73', color:'black'}}  tooltip="click here to view Peripheral block elements only" tooltipOptions={{position: 'bottom'}} className="p-button-success" />
            
            <span className="p-mr-4">    </span>{/* <i className="pi pi-arrow-right" style={{'fontSize': '2em'}}/> */}
            <Button label="MCU Config" style={{background : '#a8e8a6', color:'black'}} tooltip="click here to view MCU Config block elements only" tooltipOptions={{position: 'bottom'}} className="p-button-success" />
        </React.Fragment>
    );

    const rightContents = (
        <React.Fragment>
            <Button label="Summary"  tooltip="click here to view Summary" className="p-mr-2" tooltipOptions={{position: 'bottom'}} />
            <Button label="Help" tooltip="click here to view MC Plant help" tooltipOptions={{position: 'bottom'}} icon="pi pi-search" className="p-mr-2" iconPos="right"/>
        </React.Fragment>
    );
    
    return(
        <div>    
            <Toolbar left={leftContents} right={rightContents}  style={{background : 'light-blue'}}/>
        </div>
    );
}

export default Headder ;