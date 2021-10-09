var res = document.getElementById("res");

function clc(){
    res.innerHTML = "";
}

function insert(num){
    res.innerHTML += num;
}

function eql(){
    let result = res.innerHTML;
    
    operator = result.replace(/[0-9]/g, '');
    result = result.split(new RegExp(/[+\-*/]/));    
    
    let num1 = result[0];
    let num2 = result[1];
    
    num1 = binaryToDecimal(num1);
    num2 = binaryToDecimal(num2);    

    switch(operator){
        case '+':
            value = num1 + num2;
            break;
        case '*':
            value = num1 * num2;
            break;
        case '/':
            value = num1 / num2;
            break;
        case '-':
            value = num1 - num2;
            break;
        default:
            value = ''
            break;
    }
    res.innerHTML = decimalToBinary(value);
}

function decimalToBinary(num){
    let binary = [];
    while(num > 0){
        binary.push(num % 2);
        num = Math.floor(num / 2);
    }
    return binary.reverse().join('');
}

function binaryToDecimal(binary){
    let decimal = 0;
    for(let i = 0; i < binary.length; i++){
        decimal += binary[i] * Math.pow(2, binary.length - i - 1);
    }
    return decimal;
}