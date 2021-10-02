alert("Welcome to The Simon Game! The rule to play the game is simple!  The computer flashes a button.  You have to click the button along with all the previous buttons in the correct sequence! Best of Luck!👍");
var name = prompt("Please Enter Your Name🐱‍👤:");


var buttonColours = ["red", "blue", "green", "yellow"];

var gamePattern = [];

var started = false;
var level = 0;
var userClickedPattern = [];



$(document).keydown(function() {
  if (!started) {
    $("#level-title").html("Level " + level);
    nextSequence();
    started = true;
  }
});


$(".btn").on("click", function(event) {
  var userChosenColour = event.target.id;
  userClickedPattern.push(userChosenColour);
  playSound(userChosenColour);
  animatePress(userChosenColour);
  checkAnswer(userClickedPattern.length - 1);
});



function nextSequence() {
  userClickedPattern = [];
  level++;
  $("#level-title").html("Level " + level);
  var randomNumber = Math.floor(Math.random() * 4);
  var randomChosenColour = buttonColours[randomNumber];
  var selectedButton = $("#" + randomChosenColour);

  gamePattern.push(randomChosenColour);

  selectedButton.fadeIn(100).fadeOut(100).fadeIn(100);
  playSound(randomChosenColour);

}


function playSound(color) {

  switch (color) {
    case "red":
      var red = new Audio("sounds/red.mp3");
      red.play();
      break;

    case "blue":
      var blue = new Audio("sounds/blue.mp3");
      blue.play();
      break;

    case "green":
      var green = new Audio("sounds/green.mp3");
      green.play();
      break;

    case "yellow":
      var yellow = new Audio("sounds/yellow.mp3");
      yellow.play();
      break;

    case "wrong":
      var wrong = new Audio("sounds/wrong.mp3");
      wrong.play();
      break;

  }



}



function animatePress(currentColor) {
  $("#" + currentColor).addClass("pressed");
  setTimeout(function() {
    $("#" + currentColor).removeClass("pressed");
  }, 100);
}


function checkAnswer(currentLevel) {
  if (gamePattern[currentLevel] === userClickedPattern[currentLevel]) {
    if (gamePattern.length === userClickedPattern.length) {
      setTimeout(function() {
        nextSequence();
      }, 1000);
    }
  } else {
    playSound("wrong");
    $("body").addClass("game-over");
    $("#level-title").text("Game Over, Press Any Key to Restart");

    setTimeout(function() {
      $("body").removeClass("game-over");
    }, 200);
      message(level);
    startOver();

  }
}


function startOver() {
  level = 0;
  gamePattern = [];
  started = false;
}

function message(num) {
  if (num <= 10) {
    alert(name + ", your could complete only " + num + " levels, try to be better next time!");
  } else {
    alert("Well Played " + name + ", you completed " + num  + " levels!😉");
  }
}
