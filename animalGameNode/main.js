const readlineSync = require('readline-sync');

function appreciation() {
    let words = ["Yay i got it", "Yeah, I am still the better one", "We are living in the matrix", "Yes Yes!! The future is machines"];
    let randomInd = Math.floor(Math.random() * words.length);
    return words[randomInd];
}
var fs = require("fs");


var treeMain = fs.readFileSync('tree.json');
var root = JSON.parse(treeMain)

let newRoundStart = readlineSync.question("Do you want to play\n");
if (newRoundStart.toLowerCase() == 'yes') {
    console.log("Think of an animal");
    doRound(root);
}
else{
    return roundExit();
}

function roundExit() {
    t = false;
    console.log("Thanks for playing, good-bye");
}

function doRound(node) {
    if (node.question) {
        let answer = readlineSync.question(node.question + "\n");
        if (answer.toLowerCase() == 'yes') {
            doRound(node.yes);
        }
        else {
            doRound(node.no);
        }

    }
    else {
        let answer = readlineSync.question(`Is it a ${node.animalName}?` + "\n")
        if (answer.toLowerCase() == 'yes') {
            console.log(appreciation())
        }
        else {
            console.log("Oops - looks like I need to improve.")
            let newAnimal = readlineSync.question("What was the animal?\n");
            let newQuestion = readlineSync.question("What is the distinguishing question between " + node.animalName + " and " + newAnimal + "?\n");
            node.question = newQuestion;
            node.no = {};
            node.yes = {};
            let newAnimalTof = readlineSync.question("For " + newAnimal + " is the answer yes?\n");
            if (newAnimalTof.toLowerCase() == 'yes') {
                node.yes.animalName = newAnimal;
                node.no.animalName = node.animalName
            }
            else {
                node.no.animalName = newAnimal;
                node.yes.animalName = node.animalName;
            }
            delete node.animalName;
            console.log("Thanks for helping me improve!!");

        }
    }
    var treeMain = JSON.stringify(root, null, 2);
    fs.writeFileSync('tree.json', treeMain)
}
let isContinueTrue = true
while (isContinueTrue) {
    isContinueTrue = readlineSync.question('Want to play again?(y/n)')
    if (isContinueTrue == 'y') {
        isContinueTrue = true;
        console.log('Think of an animal')
         doRound(root)}
    else {
        return roundExit();
    }
}
