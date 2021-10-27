var controllerMain = {
  init : function() {
    let player = document.getElementById("player");
    app.playerLeft = player.offsetLeft;
    app.playerTop = player.offsetTop;
    app.updateID = setInterval(app.controller.update, 40);
  },

  update : function() {
    app.controller.count();
    app.controller.movePlayer();
    app.controller.checkCollision();
    app.controller.checkGameOver();
    app.controller.moveBalls();

    app.frame += 1;
    if (app.frame == 2) {
      app.controller.createBall();
      app.frame = 0;
    }
  },

  movePlayerLeft : function() {
    app.playerLeft -= app.moveFactor;
    if(app.playerLeft < 0) app.playerLeft = 0;
    $("#player").css('left', app.playerLeft.toString() + 'px');
  },

  movePlayerRight : function() {
    app.playerLeft += app.moveFactor;
    if (app.playerLeft > window.innerWidth - 150) app.playerLeft = window.innerWidth - 150;
    $("#player").css('left', app.playerLeft.toString() + 'px');
  },

  createBall : function() {
    var rnd = Math.floor(Math.random() * 20);
    let ball = null;
    if (rnd == 9) {
      if (app.ballsDead.length == 0) {
        // create new
        ball = new Ball();
        app.balls.push(ball);
      } else {
        // respawn dead one on top
        ball = app.ballsDead.shift();
        ball.reset();
        app.balls.push(ball);
      }
    }
  },

  moveBalls : function() {
    for (let i=0; i<app.balls.length; i++) {
      app.balls[i].moveDown();
    }
  },

  count() {
    app.count += 0.04;
    $("#zeit").html("Time " + String(app.count.toFixed(2)));
  },

  checkCollision : function() {
    for (let i=0; i<app.balls.length; i++) {
      let ball = app.balls[i];
      if ( ((ball.posX >= app.playerLeft && ball.posX <= app.playerLeft + 150) || (ball.posX + 150 >= app.playerLeft && ball.posX + 150 <= app.playerLeft + 150))
        && ((ball.posY >= app.playerTop && ball.posY <= app.playerTop + 150) || (ball.posY + 150 >= app.playerTop && ball.posY + 150 <= app.playerTop + 150)) ) 
      {
        app.gameOver = true;
      }
    }
  },

  checkGameOver : function() {
    if (app.gameOver) {
      clearInterval(app.updateID);
      if (app.count > app.rekord) {
        app.rekord = app.count;
        $("#bestzeit").html("Record " + String(app.rekord.toFixed(2)));
      }
      $("#gameOverScreen").css('display', 'block');
    }
  },

  playAgain : function() {
    $("#gameOverScreen").css('display', 'none');
    while(app.balls.length > 0) {
      let ball = app.balls.shift();
      $(ball.el).remove();
    }
    app.ballsDead = [];
    app.count = 0.00;
    app.gameOver = false;
    app.updateID = app.updateID = setInterval(app.controller.update, 40);
  },

  movePlayer : function() {
    if (app.movePlayerLeft) {
      this.movePlayerLeft();
    } else if(app.movePlayerRight) {
      this.movePlayerRight();
    }
  }
};