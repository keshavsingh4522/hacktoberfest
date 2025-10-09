import React from 'react';
import Bmicalc from './Components/Bmicalc';


function App() {
  return (
    <div className="flex flex-col justify-center text-left items-center h-screen item-center text-blue-800 text-3xl">
      <h1 className="mb-16 font-bold text-5xl">BMI Calculator</h1>
      <Bmicalc />
    </div>
  );
}

export default App;
