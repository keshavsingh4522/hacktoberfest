const play = document.getElementById('play');
const iconContainer = document.getElementById('iconContainer');
const spinner = document.getElementById('spinner');
const playDiv = document.getElementById('playDiv');
const loadingSpan = document.getElementById('loading');

const audio = new Audio('game.m4a');

play.addEventListener('click', () => {
    playDiv.style.display = 'none';
    spinner.style.display = 'block';
    audio.play();

    let proceesing = setInterval(() => {
                        output();
                    }, 120);

    let index = 3;
    loadingSpan.innerHTML = index;
    index--;
    let loading = setInterval(() => {
        loadingSpan.innerHTML = index;
                        index--;
                    }, 1000);

    setTimeout(() => {
        clearInterval(proceesing);
        clearInterval(loading);
        output();
        
        spinner.style.display = 'none';
        playDiv.style.display = 'block';
    }, 3000);
});

const output = () => {
    let randomNo = Math.ceil(Math.random()*3);

    switch(randomNo) {
        case 1:
            iconContainer.innerHTML = `<i class="fas fa-hand-rock"></i>`;
            break;
            
        case 2:
            iconContainer.innerHTML = `<i class="fas fa-hand-paper"></i>`;
            break;

        case 3:
            iconContainer.innerHTML = `<i class="fas fa-hand-scissors"></i>`;
            break;
    }
}
