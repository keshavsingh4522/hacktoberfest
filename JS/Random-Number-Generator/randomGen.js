const generateBtn = document.querySelector('#btn');
var min = document.querySelector(".min-number").value;
var max = document.querySelector(".max-number").value;
let numbers = createArray();

$(".min-number").change(function () {
    if ($(".min-number").val() != min) {
        update();
    }
});

$(".max-number").change(function () {
    if ($(".max-number").val() != max) {
        update();
    }
});


function update() {
    min = document.querySelector(".min-number").value;
    max = document.querySelector(".max-number").value;
    numbers = createArray();
}

/**
 * 
 * @param {Number} min 
 * @param {Number} max 
 * @returns 
 */
function generateRandomNumber() {

    let num = 0
    let positive = true
    const trueMin = Math.min(...[min, max])
    const trueMax = Math.max(...[min, max])

    if (min < 0 || max < 0) positive = Math.random() * 2 < 1 ? true : false

    if (!positive) num = Math.round(Math.random() * trueMin)
    else num = Math.round(Math.random() * trueMax)

    return num
}

function simpleRandom(n) {
    return Math.floor(Math.random() * n + 1);
}

function createArray() {
    let array = [];

    for (let i = 0; i <= 10; i++) {
        array.push(generateRandomNumber());
    }

    return array;
}


generateBtn.addEventListener('click', () => {
    if (numbers.length == 0) {
        numbers = createArray();
    }
    for (let i = 0; i < 10; i++) {
        simpleRandom();
    }
    let randomIndex = simpleRandom(numbers.length);
    let randomNumer = numbers[randomIndex];
    numbers.splice(randomIndex, 1);
    if (typeof randomNumer === 'undefined') {
        numbers = createArray();
        document.getElementById("result").value = generateRandomNumber();
    } else {
        document.getElementById("result").value = randomNumer;
    }
});