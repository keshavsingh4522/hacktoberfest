const calculate=()=>{

    //taking the input value entered
    const inputtemp=document.getElementById('heading2').value;
    // console.log(inputtemp);
    //now taking the type of coverter the user want to with twmperature
    const tempselect=document.getElementById('temp_diff');
    const valuetemp=temp_diff.options[tempselect.selectedIndex].value;
    // console.log(valuetemp);
    //cel to farenhite
    if(valuetemp == 'celcius'){
        let result=Math.round((inputtemp*9/5) + 32);
        document.getElementById('res').innerHTML=`=${result} °farenhite`;
    }
    
    //farhhenite to celcius
    if(valuetemp == 'farhenite'){
        let result=Math.round((inputtemp-32)*5/9);
        document.getElementById('res').innerHTML=`=${result} °celcius`;
    }

}