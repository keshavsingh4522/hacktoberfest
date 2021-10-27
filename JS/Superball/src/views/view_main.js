var viewMain = `
	<div id="body">
		<div id="droparea"></div>
		<div id="zeit">Time 0.00</div>
		<div id="bestzeit">Record 0.00</div>
		<div id="controls">
			Controls: A (left), D (right)
		</div>
		<div id="player"></div>
		<div id="gameOverScreen">
			<h1>Game Over<h1>
			<button onclick="app.controller.playAgain()">Play again</button>
		</div>
	</div>
`;