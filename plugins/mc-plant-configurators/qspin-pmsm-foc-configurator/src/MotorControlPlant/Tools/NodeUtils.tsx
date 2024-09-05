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
import { DialogCommonInitilizeCode } from '../UI/CustomPopUp/CustomPopUp';
import MultipleUIComponentsWithLabel from './MultipleUIComponentsWithLabel';
const LoadImage = (props: { file: any }) => {
  return (
    <div>
      <img
        src={props.file}
        alt='icon'
      />
    </div>
  );
};

const AddImageAndParameters = (props: {
  Image: any;
  Headding: any;
  component_id: string;
  SymbolsArray: string[];
}) => {
  return (
    <div className='p-fluid'>
      <div>
        {props.Image !== null && LoadImage(props.Image)}
        <br></br>
        <span style={{ fontWeight: 'bold' }}> {props.Headding} </span> <br></br>
        <br></br>
        <MultipleUIComponentsWithLabel
          componentId={props.component_id}
          symbolsArray={props.SymbolsArray}
        />
      </div>
    </div>
  );
};

const AddTitileOnly = (props: { Headding: any }) => {
  return (
    <div className='p-fluid'>
      <div>
        <span style={{ fontWeight: 'bold' }}> {props.Headding} </span>
      </div>
    </div>
  );
};

const AddTitleAndParameters = (props: {
  Headding: any;
  SymbolsArray: any;
  component_id: string;
}) => {
  return (
    <div className='p-fluid'>
      <div>
        <span style={{ fontWeight: 'bold' }}> {props.Headding} </span> <br></br>
        <br></br>
        <MultipleUIComponentsWithLabel
          componentId={props.component_id}
          symbolsArray={props.SymbolsArray}
        />
      </div>
    </div>
  );
};

function ShowDiv(elements: any, specifiedDisplay: any) {
  elements = elements.length ? elements : [elements];
  for (var index = 0; index < elements.length; index++) {
    elements[index].style.display = specifiedDisplay || 'block';
  }
}

function HideDiv(elements: any) {
  elements = elements.length ? elements : [elements];
  for (var index = 0; index < elements.length; index++) {
    elements[index].style.display = 'none';
  }
}

const GetHeadder = (props: { headder: string }) => {
  return (
    <div>
      <span style={{ fontWeight: 'bold' }}> {props.headder} </span> <br></br>
      <br></br>
    </div>
  );
};

const ShowConfigProps = (props: {
  title: string;
  componentId: string;
  symbolsArray: string[];
  showToast: (arg0: any) => void;
}) => {
  DialogCommonInitilizeCode(props.showToast, props.componentId, props.symbolsArray);
  return (
    <div>
      <AddTitleAndParameters
        Headding={props.title}
        component_id={props.componentId}
        SymbolsArray={props.symbolsArray}
      />
    </div>
  );
};

export {
  LoadImage,
  AddImageAndParameters,
  AddTitileOnly,
  AddTitleAndParameters,
  ShowDiv,
  HideDiv,
  GetHeadder,
  ShowConfigProps
};
