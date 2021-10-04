const keys = document.querySelectorAll('.key');
const button = document.querySelector('button');
const wh = document.querySelectorAll('.white');
const bl = document.querySelectorAll('.black');

button.addEventListener('click', () => {
    var i;
    let color = '#';
    color1 = color + Math.random().toString(16).slice(2,8);
    color2 = color + Math.random().toString(16).slice(2,8);
    for (i = 0; i < wh.length; i++) {
        wh[i].style.backgroundColor = color1;
    }
    for (i = 0; i < bl.length; i++) {
        bl[i].style.backgroundColor = color2;
    }
})

keys.forEach(key => {
    key.addEventListener('click', () => playnote(key))
})

function playnote(key) {
    const noteAudio = document.getElementById(key.dataset.note)
    noteAudio.currentTime = 0; 
    noteAudio.play()
    key.classList.add('active')
    noteAudio.addEventListener('ended', () => {
        key.classList.remove('active')
    })
}