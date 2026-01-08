import './App.css';
import Navbar from './components/navbar/Navbar';
import Card from './components/card/Card';
import {data} from './data';
function App() {
  return (
    <div className="App">
    <div className='wrapper'>
      <Navbar/>
      <div className='card-container'>
      {data.map((el,index)=>{
        return (
          <Card data={el} key={index}/>
        )
      })}
      </div>
    </div>
    </div>
  );
}

export default App;
