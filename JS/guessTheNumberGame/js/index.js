'use strict';

// getting DOM elements ------------------------------------------>
const generateBtn = document.querySelector('#generate');
const startMessage = document.querySelector('.NumberGenerate');
const checkBtn = document.querySelector('#check');
const userInput = document.querySelector('#userGuess');
const attemptCounter = document.querySelector('.counter');
const highScoreCounter = document.querySelector('.highScoreValue');
const message = document.querySelector('#message');
const storeUserGuess = document.querySelector(".userGuessValues");


// variables --------------------------------------->
let secrateNumber;
let attemptLeft = 10;
let highScore = 0
let storeInput = []


// function area ----------------------------------->
function enable(enableItems){
    for(let items = 0; items < enableItems.length ; items++){
        enableItems[items].disabled = false;
    }
}


function disable(disableItems){
    for(let items = 0; items < disableItems.length ; items++){
        disableItems[items].disabled = true;
    }
}


function returnMessage(textMessgae){
    message.textContent = textMessgae;
}


function valueEnteredShow(valueEntered){
    storeInput.push(`${valueEntered} `);
    storeUserGuess.value = storeInput;
    userInput.value = ''
}

function resetGame(){
    enable([checkBtn , userInput])
    disable([generateBtn])
    attemptLeft = 10;
    attemptCounter.textContent = attemptLeft;
    storeInput = [];
    storeUserGuess.value ='';
    userInput.value = '';
    message.textContent ='';
    message.style.color = 'black';;
}



// click events ------------------------------------------------------------>
generateBtn.addEventListener('click' , function (){
    secrateNumber = Math.floor(Math.random()*100)+1;
    startMessage.textContent = `A Number is generated between 1 and 100`;
    resetGame();
})

checkBtn.addEventListener('click' , function(){
    startMessage.textContent = '';
    const userInputValue = Number(userInput.value);
    if (!userInputValue){
        returnMessage('No Number Entered');
    }
    else{
        if (userInputValue > 100){
            returnMessage('Your Number is Greater than 100')
        }
        else if (userInputValue < 0){
            returnMessage("Your Number can't be negative")
        }
        else{
            if(attemptLeft === 0){
                returnMessage("You Loose the game!")
                message.style.color = 'red'
                enable([generateBtn])
                generateBtn.textContent = 'Restart'
                disable([userInput , checkBtn])

            }
            else{
                if (userInputValue === secrateNumber){
                    returnMessage("Yeeee! you have wone the game.")
                    valueEnteredShow(userInputValue);
                    message.style.color = 'green';
                    disable([userInput , checkBtn])
                    enable([generateBtn])
                    if (attemptLeft > highScore){
                        highScore = attemptLeft;
                        highScoreCounter.textContent = highScore; 
                    }
                    else{
                        highScore = highScore;  
                        highScoreCounter.textContent = highScore;  
                    }
                    generateBtn.textContent = 'Restart'
                }
                else if (userInputValue < secrateNumber){
                    returnMessage('Your Number is too low. Try with a higher number')
                    valueEnteredShow(userInputValue);
                    attemptLeft--
                }
    
                else if (userInputValue > secrateNumber){
                    returnMessage('Your Number is too hight. Try with a low number')
                    valueEnteredShow(userInputValue);
                    attemptLeft--
                }
                attemptCounter.textContent = attemptLeft;
            }
        }
    }
})