// Define variables to store the input and result
let currentInput = '';
let currentResult = '';

// Function to append a digit or operator to the current input
function appendToInput(value) {
    currentInput += value;
}

// Function to clear the input
function clearInput() {
    currentInput = '';
}

// Function to calculate the result
function calculateResult() {
    try {
        currentResult = eval(currentInput);
    } catch (error) {
        currentResult = 'Error';
    }
}
// Function to clear the input
function clearInput() {
    currentInput = '';
}

// Function to calculate the result
function calculateResult() {
    try {
        currentResult = eval(currentInput);
    } catch (error) {
        currentResult = 'Error';
    }
}


// Function to display the result
function displayResult() {
    document.getElementById('output').textContent = currentResult;
}

// Add event listeners to digit and operator buttons
document.getElementById('button1').addEventListener('click', () => appendToInput('1'));

document.getElementById('button2').addEventListener('click', () => appendToInput('2'));

document.getElementById('button3').addEventListener('click', () => appendToInput('3'));

document.getElementById('button4').addEventListener('click', () => appendToInput('4'));

document.getElementById('button5').addEventListener('click', () => appendToInput('5'));

document.getElementById('button6').addEventListener('click', () => appendToInput('6'));

document.getElementById('button7').addEventListener('click', () => appendToInput('7'));

document.getElementById('button8').addEventListener('click', () => appendToInput('8'));

document.getElementById('button9').addEventListener('click', () => appendToInput('9'));

document.getElementById('button0').addEventListener('click', () => appendToInput('0'));

document.getElementById('add').addEventListener('click', () => appendToInput('+'));
document.getElementById('subtract').addEventListener('click', () => appendToInput('-'));
document.getElementById('multiply').addEventListener('click', () => appendToInput('*'));
document.getElementById('divide').addEventListener('click', () => appendToInput('/'));

document.getElementById('clear').addEventListener('click', () => clearInput());
document.getElementById('equals').addEventListener('click', () => {
    calculateResult();
    displayResult();
});

document.getElementById('button1').addEventListener('click', () => appendToInput('1'));

document.getElementById('button2').addEventListener('click', () => appendToInput('2'));

document.getElementById('button3').addEventListener('click', () => appendToInput('3'));

document.getElementById('button4').addEventListener('click', () => appendToInput('4'));

document.getElementById('button5').addEventListener('click', () => appendToInput('5'));

document.getElementById('button6').addEventListener('click', () => appendToInput('6'));

document.getElementById('button7').addEventListener('click', () => appendToInput('7'));

document.getElementById('button8').addEventListener('click', () => appendToInput('8'));

document.getElementById('button9').addEventListener('click', () => appendToInput('9'));

document.getElementById('button0').addEventListener('click', () => appendToInput('0'));

document.getElementById('add').addEventListener('click', () => appendToInput('+'));

document.getElementById('subtract').addEventListener('click', () => appendToInput('-'));

document.getElementById('multiply').addEventListener('click', () => appendToInput('*'));

document.getElementById('divide').addEventListener('click', () => appendToInput('/'));

document.getElementById('clear').addEventListener('click', () => clearInput());
document.getElementById('equals').addEventListener('click', () => {
    calculateResult();
    displayResult();
});
