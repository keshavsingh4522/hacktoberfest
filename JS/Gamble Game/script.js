'use strict';

// Selecting elements
const name0Player = document.querySelector('#name--0');
const name1Player = document.querySelector('#name--1');
const bidBtn = document.querySelector('.bid-btn');
const player0El = document.querySelector('.player--0');
const player1El = document.querySelector('.player--1');
const score0El = document.querySelector('#score--0');
const score1El = document.querySelector('#score--1');
const current0El = document.getElementById('current--0');
const current1El = document.getElementById('current--1');
const diceEl = document.querySelector('.dice');
const btnNew = document.querySelector('.btn--new');
const btnRoll = document.querySelector('.btn--roll');
const btnHold = document.querySelector('.btn--hold');
const overlay = document.querySelector('.overlay');
const modal = document.querySelector('.modal');
const closeModal = document.querySelector('.close-modal');

// Modals Implementation

const modalClose = function () {
  modal.classList.add('hidden');
  overlay.classList.add('hidden');
};

closeModal.addEventListener('click', modalClose);

bidBtn.addEventListener('click', function () {
  name0Player.textContent = document.querySelector('#player-name-0').value;
  name1Player.textContent = document.querySelector('#player-name-1').value;

  modalClose();
});

//Starting conditions
score0El.textContent = 0;
score1El.textContent = 0;
diceEl.classList.add('hidden');

let scores = [0, 0];
let currentScore = 0;
let activePlayer = 0;

const switchPlayer = function () {
  document.getElementById(`current--${activePlayer}`).textContent = 0;
  player0El.classList.toggle('player--active'); //Remove class if it's there otherwise it'll add
  player1El.classList.toggle('player--active');
  activePlayer = activePlayer === 0 ? 1 : 0;
  currentScore = 0;
};

// Rollinf=g dice functionality
btnRoll.addEventListener('click', function () {
  // 1. Generating a random dice roll
  const dice = Math.ceil(Math.random() * 6);

  // 2. Display dice
  diceEl.classList.remove('hidden');
  diceEl.src = `dice-${dice}.png`;

  // 3. Check for rolled 1: if true, switch to next player
  if (dice !== 1) {
    // Add dice to current score
    currentScore += dice;
    document.getElementById(`current--${activePlayer}`).textContent =
      currentScore;
  } else {
    // Switch Player
    switchPlayer();
  }
});

btnHold.addEventListener('click', function () {
  // 1. Add curent score to active player score
  scores[activePlayer] += currentScore;
  document.querySelector(`#score--${activePlayer}`).textContent =
    scores[activePlayer];

  // 2. Player Won
  if (scores[activePlayer] >= 100) {
    document
      .querySelector(`.player--${activePlayer}`)
      .classList.add('player--winner');
    document
      .querySelector(`.player--${activePlayer}`)
      .classList.remove('player--active');
    btnHold.style.visibility = 'hidden';
    btnRoll.classList.add('hidden');
    diceEl.classList.add('hidden');
  } else {
    // 3. Switch Player
    switchPlayer();
  }
});

// We can use playing = true and put btnRoll function inside if and when somebody wins change playing = false
// Then there will be no need to change visibility of buttons

btnNew.addEventListener('click', function () {
  btnHold.style.visibility = 'visible';
  btnRoll.classList.remove('hidden');
  player0El.classList.remove('player--winner');
  player1El.classList.remove('player--winner');
  player0El.classList.add('player--active');
  player1El.classList.remove('player--active');
  score0El.textContent = 0;
  score1El.textContent = 0;
  current0El.textContent = 0;
  current1El.textContent = 0;
  //If you want to implement whichever player won last should start game then
  //just remove activePlayer = 0
  activePlayer = 0;
  currentScore = 0;
  scores = [0, 0];
});
