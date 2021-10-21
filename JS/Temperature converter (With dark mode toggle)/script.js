const submitButton = document.getElementById('submit-button');
let inputBox = document.getElementById('inp-box');
const inputUnit = document.getElementById('inputUnit');
const convertTo = document.getElementById('convertTo');
const errorDiv = document.getElementById('errordiv');

let darkModeState = false;

submitButton.addEventListener('click', (e) => {
  e.preventDefault();
  var result = 0;
  let intInputBox = parseInt(inputBox.value);
  if(inputBox.value.length == 0) {
    errorDiv.innerHTML = `<span style='color: red;'>Input a valid value</span>`;
    setTimeout(() => {
      errorDiv.innerHTML = '';
    }, 2000);
    return 0;
  } else if (/\D+/.test(inputBox.value) == true) {
    errorDiv.innerHTML = `<span style='color: red;'>${inputBox.value} is not a number</span>`;
    setTimeout(() => {
      errorDiv.innerHTML = '';
    }, 2000);
    return 0;
  } else {
    if(inputUnit.value == 'cel' && convertTo.value == 'far') {
      result = eval((9/5 * intInputBox) + 32) + '&deg' + 'F';
    } else if(inputUnit.value == 'cel' && convertTo.value == 'kel') {
      result = eval(intInputBox + 273) + 'K';
    } else if(inputUnit.value == 'far' && convertTo.value == 'cel') {
      result = eval(5/9 * (intInputBox - 32)) + '&deg' + 'C';
    } else if(inputUnit.value == 'far' && convertTo.value == 'kel') {
      result = eval((5/9 * (intInputBox - 32)) + 273) + 'K';
    } else if(inputUnit.value == 'kel' && convertTo.value == 'cel') {
      result = eval(intInputBox - 273) + '&deg' + 'C';
    } else if(inputUnit.value == 'kel' && convertTo.value == 'far') {
      result = eval((9/5 * (intInputBox - 273)) + 32) + '&deg' + 'F';
    } else {
      result = "You can't convert temperature unit";
    }
    document.getElementById('result').innerHTML = result;
  }
});

function toggleDarkMode() {
  darkModeState = !darkModeState
  if(darkModeState) {
    document.body.style.backgroundColor = 'black';
    document.querySelector('.dark-mode').style.backgroundColor = 'black';
    document.querySelector('.dark-mode').style.color = 'white!important';
    document.body.style.color = 'white';
    document.querySelector('.converter-body').style.boxShadow = '0 4px 8px 0 rgba(255,255,255,0.9)';
  } else {
    document.body.style.backgroundColor = 'white';
    document.querySelector('.dark-mode').style.backgroundColor = 'white';
    document.body.style.color = 'black';
    document.querySelector('.converter-body').style.boxShadow = '0 4px 8px 0 rgba(0,0,0,0.2)';
  }
}
