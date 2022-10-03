import Timer from '/timer.js'


const timerDiv = document.querySelector(".timer");
const quoteDiv = document.querySelector(".quote");
const userInput = document.querySelector(".input");
const startButton = document.querySelector(".start");
const nextButton = document.querySelector(".next");
const RANDOM_QUOTE_API_URL = 'http://api.quotable.io/random';
let isTicking = false;
let quote = "";
let userArray = [];
let counter = 0;


const timer = new Timer;

function getRandomQuote(url){
    return fetch(url)
    .then(response => response.json())
    .then(data => data.content)
}

async function getNextQuote(){

    //resetting the program for the next quote
    counter = 0;
    userArray = [];
    userInput.value = "";
    userInput.focus();
    timer.resetTimer(timerDiv);
    const quotesArray = document.querySelectorAll(".span");
    quotesArray.forEach(quoteSpan => quoteSpan.remove());

    quote = await getRandomQuote(RANDOM_QUOTE_API_URL);
    quote.split("").forEach(character => {   //splitting the quote into individual character spans
        const characterSpan = document.createElement("span");
        characterSpan.innerHTML = character;
        characterSpan.id = character;
        characterSpan.style.pointerEvents = 'none';
        characterSpan.style.userSelect = 'none';
        characterSpan.classList.add("span");
        quoteDiv.appendChild(characterSpan);
    })
}
getNextQuote();   //calling function on page load

function matchText(e){

    //starting the timer automatically once user starts typing
    counter++;
    if(counter === 1){
        timer.startTimer(timerDiv);
    }

    const quoteArray = document.querySelectorAll(".span");

    // if(e.inputType == "deleteContentBackward") userArray.pop(); //removing backspace null elements
    userArray.push(e.data); //this ensure that array only has the characters and not any null elements
    if(userArray.join("") == quote) handleWin(timerDiv); //user successfully matched quote
    
    quoteArray.forEach((characterSpan, index) => {
        const character = userArray[index];
        if(character == null){
            characterSpan.classList.remove("correct");
            characterSpan.classList.remove("incorrect");
        }
        else if(characterSpan.innerHTML === character){
            characterSpan.classList.add("correct");
            characterSpan.classList.remove("incorrect");
        }
        else{
            characterSpan.classList.add("incorrect");
            characterSpan.classList.remove("correct");
        }
    })
}

function handleWin(timerDiv){
    const time = timer.resetTimer(timerDiv);
    const words = userArray.join("").split(" ");
    const wpm = Math.round(words.length / (time/60));
    timerDiv.innerHTML = `WPM - ${wpm}`;
}

nextButton.addEventListener("click", getNextQuote);
startButton.addEventListener('click', () => timer.startTimer(timerDiv));
userInput.addEventListener('input', matchText);

