
import PrimeReact from 'primereact/api';
// import { Toast } from 'primereact/toast';
// import { useRef } from 'react';
import { ReactComponent as MotorControlPlant } from '../../../Resources/Svgs/mc_plant_view.svg';


const MyComponent = () => {
    // // active ripple effect
    PrimeReact.ripple = true;
   
    // const toast = useRef<Toast>(null);
    return (

        <div>
            {/* <Toast ref={toast} position="bottom-right" /> */}
            {/* Logo is an actual React component */}
            {/* <MotorControlPlant id="motor" /> */}
            {/* <Headder/> */}
            <MotorControlPlant id="motor"
                height={(window as any).javaConnector.getScreenHeight()}
                width={(window as any).javaConnector.getScreenWidth()}

            />



            {/* <SvgComponent /> */}


            {/* <SVGComponent id="motora"/> */}

            {/* <img src={LogoName} id="raj" alt="logo"/> */}
            {/* document.querySelector("g").addEventListener("click", () => alert("clicked")); */}
            {/* console.log(Logo.port); */}
        </div>


    );
}

export default MyComponent;

