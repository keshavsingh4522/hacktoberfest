const colors = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "A", "B", "C", "D", "E", "F"];
const btn = document.querySelector(".btn");
const div = document.querySelector(".container");

btn.addEventListener("click", function () {
    let hexValue = "#"
    for (let i = 0; i < 6 ; i++) {
        let x = Math.floor(Math.random()*colors.length);
        hexValue += colors[x];
    }

    div.style.backgroundColor = hexValue;
    let text = document.querySelector(".color-value");
    text.textContent = hexValue;
});
