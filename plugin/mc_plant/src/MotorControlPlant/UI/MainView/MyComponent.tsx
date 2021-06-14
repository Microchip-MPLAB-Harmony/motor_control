
import  {ReactComponent as MotorControlPlant}  from '../../../Resources/Svgs/mc_plant_view.svg';

const MyComponent = () => {
    
   
    return(
       
        <div>
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

export default MyComponent ;