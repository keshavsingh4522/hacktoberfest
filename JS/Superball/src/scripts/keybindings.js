document.onkeydown = function(e) {
    // Player movement
    if (!app.gameOver) {
        if (e.keyCode == 65) {      // a
            app.movePlayerLeft = true;
        }
        if (e.keyCode == 68) {      // d
            app.movePlayerRight = true;
        }
    }
};

document.onkeyup = function(e) {
    if (e.keyCode == 65) {      // a
        app.movePlayerLeft = false;
    }
    if (e.keyCode == 68) {      // d
        app.movePlayerRight = false;
    }
};