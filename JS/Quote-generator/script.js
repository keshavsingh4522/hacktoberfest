const quotes = ['Originality is the fine art of remebering what you hear but forgetting where you heard it.', 
'Never let the fear of striking out keep you from playing the game.', 
'When you cease to dream you cease to live.', 
'Live as if you were to die tomorrow, but a reality to be experienced.', 
'The best way to predict your future is to create it.',
'Happiness is like a butterfly; the more you chase it, the more it will elude you, but if you turn your attention to other things, it will come and sit softly on your shoulder', 
"When it is obvious that goals can't be reached, don't adjust the goals, but adjust the action steps."];

function newQuote() {
   var randomNumber = Math.floor(Math.random() * (quotes.length));
   document.getElementById('Display').innerHTML = quotes[randomNumber];
}