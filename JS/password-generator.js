const readline = require("readline")
const randomstring = require("randomstring")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('How long do you want your password to be? eg. 10\n', (lengthPass) => {
    const randomPass = randomstring.generate({
        length: lengthPass,
        charset: 'alphanumeric'
    });
    console.log("\nHere is your randomized password:\n" + randomPass)

    rl.close();
});
