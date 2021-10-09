// returns a random number between 0 and maxNumber which defaults to 10
function randomNumber(maxNumber = 10) {
	return Math.floor(Math.random() * maxNumber +1);
}

// returns either 1 or 2
console.log(randomNumber(2));
// returns a number between 1 and 5
console.log(randomNumber(5));
// returns a number betwee 1 and 100
console.log(randomNumber(100));
