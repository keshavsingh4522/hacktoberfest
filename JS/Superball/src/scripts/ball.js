class Ball {
    constructor() {
        this.posX = this.randomX();
        this.posY = 0;
        this.el = $(document.createElement('div')).addClass('ball')
                                                .css('position', 'absolute')
                                                .css('top', this.posY + 'px')
                                                .css('left', this.posX + 'px')
                                                .css('width', '150px')
                                                .css('height', '150px')
                                                .css('border-radius', '50%')
                                                .css('background-image', 'url(src/res/image/football.png)')
                                                .css('background-size', 'cover');
        $("#droparea").append(this.el);
    }

    moveDown() {
        this.posY += 80;
        if (this.posY > window.innerHeight) {
            this.kill();
        } else {
            $(this.el).css('top', this.posY + 'px');
        }
    }

    randomX() {
        let rndX = Math.floor(Math.random() * window.innerWidth);
        if (rndX > window.innerWidth - 150) rndX = window.innerWidth - 150;
        return rndX;
    }

    reset() {
        this.posY = 0;
        this.posX = this.randomX();
        $(this.el).css('display', 'block');
    }

    kill() {
        $(this.el).css('display', 'none');
    }
}