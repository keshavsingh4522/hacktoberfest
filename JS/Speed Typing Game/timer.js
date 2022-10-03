export default class Timer{
    constructor(){}

    startTimer(timerDiv){
            const then = Math.round(((Date.now()))/1000);
            window.timer = setInterval(() => {
                const now = Math.round(((Date.now()))/1000);
                window.time = now - then;
                const [min, sec] = this.splitTime(window.time);
                this.updateHTML(min, sec, timerDiv);
        }, 1000);
        
    }
    splitTime(time){
        if(time < 60) {
            const min = 0;
            const sec = time;
            return [min, sec];
        }
        const min = Math.trunc(time / 60);
        const sec = time % 60;
        console.log(min, sec);
        return [min, sec]
    }

    updateHTML(min, sec, timerDiv){
        timerDiv.innerHTML = `${min < 10 ? '0' : ''}${min}:${sec < 10 ? '0' : ''}${sec}`;
    }
    
    resetTimer(timerDiv){
        clearInterval(window.timer);
        this.updateHTML(0, 0, timerDiv);
        return window.time;
    }
}

