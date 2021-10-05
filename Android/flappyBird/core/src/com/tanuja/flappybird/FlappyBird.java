package com.tanuja.flappybird;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Graphics;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer;
import com.badlogic.gdx.math.Circle;
import com.badlogic.gdx.math.Intersector;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.utils.ScreenUtils;

import java.util.Random;

public class FlappyBird extends ApplicationAdapter {
	SpriteBatch batch;
	Texture background;	//background
	Texture gameOver;	//game over screen

//	ShapeRenderer shapeRenderer;

	Texture[] birds;	// array have 2 img, bird with open wings and bird with close wings
	int flapstate = 0;	//for tracking the wings (open/close)
	float birdY=0;	//updating position of bird in Y axix (up or down)
	float velocity = 0;	//velocity of the bird
	Circle birdCircle;	//creating a shape for collision detection
	int score = 0;	//for score management
	int scoringTube=0;
	BitmapFont font;

	int gamestate=0;	//active or over
	float gravity = 2;	//exponential growth of speed of the bird (downwards)

	Texture topTube;	//top tube
	Texture bottomTube;	//bottom tube
	float gap = 400;	//gap between the tubes
	float maxTubeOffset;	//limit of the tube according to screen
	Random randomGenerator;	//generate random number 0 to 1
	float tubeVelocity = 4;	//speed acc. to game
	int numberOfTube = 4;
	float[] tubeX = new float[numberOfTube];	//updating position of tube
	float[] tubeOffset = new float[numberOfTube];
	float distanceBetweenTube;	//dist bt set of tubes in x axis
	Rectangle[] topTubeRectangle;	//collision det for tubes
	Rectangle[] bottomTubeRectangle;	//collision det for tubes


	@Override
	public void create () {
		batch = new SpriteBatch();
		background = new Texture("bg.png");	//setting path
		gameOver = new Texture("gameover.png");
		birds = new Texture[2];							//declaration of the array of bird state
		birds[0] = new Texture("bird.png");	//setting path
		birds[1] = new Texture("bird2.png");	//setting path

		topTube = new Texture("toptube.png");	//setting path
		bottomTube = new Texture("bottomtube.png");	//setting path
		maxTubeOffset = Gdx.graphics.getHeight() - gap/2 - 100;
		randomGenerator = new Random();	//declaring random method
		distanceBetweenTube = Gdx.graphics.getWidth()/2;	//setting the width
//		shapeRenderer = new ShapeRenderer();
		birdCircle = new Circle();	//creating a shape for collision detection
		topTubeRectangle = new Rectangle[numberOfTube];	//collision detection of tube
		bottomTubeRectangle = new Rectangle[numberOfTube];	//collision detection of tube
		font = new BitmapFont(); //display of score in the game screen
		font.setColor(Color.WHITE);
		font.getData().setScale(10);

		startGame();	//set the initial position of the bird and the tubes

	}

	public void startGame()
	{
		birdY = Gdx.graphics.getHeight()/2 - birds[0].getHeight()/2;	//assigning tht value if the birds in the array
		for (int i=0;i<numberOfTube;i++)
		{
			tubeOffset[i] = (randomGenerator.nextFloat() - 0.5f)*(Gdx.graphics.getHeight() - gap - 1150);	//(1150 is according to 6.5-inch display)
			tubeX[i] = Gdx.graphics.getWidth()/2 - topTube.getWidth()/2 + Gdx.graphics.getWidth() +i*distanceBetweenTube;	//initial state if the tube
			topTubeRectangle[i] = new Rectangle();
			bottomTubeRectangle[i] = new Rectangle();
		}
	}

	@Override
	public void render () {	//// this method keeps rendering itself in a infinite loop to stay update the game state

		batch.begin();
		batch.draw(background, 0, 0, Gdx.graphics.getWidth(), Gdx.graphics.getHeight());
		if (gamestate == 1 && birdY < Gdx.graphics.getHeight()) {	//when game started

			if(tubeX[scoringTube] < Gdx.graphics.getWidth()/2)
			{
				score++;
				Gdx.app.log("Score",String.valueOf(score));
				if(scoringTube < numberOfTube - 1)
				{
					scoringTube++;
				}
				else
				{
					scoringTube = 0;
				}
			}

			if (Gdx.input.justTouched()) {
				velocity = -25;	//gain in y axis (that push feel while tapping)
			}

			for (int i=0;i<numberOfTube;i++) {

				if(tubeX[i] < -topTube.getWidth()){
					tubeX[i] += numberOfTube * distanceBetweenTube;
					tubeOffset[i] = (randomGenerator.nextFloat() - 0.5f)*(Gdx.graphics.getHeight() - gap - 1150);	//for randomising
				}else {
					tubeX[i] -= tubeVelocity;    //speed of the tube
				}
				batch.draw(topTube, tubeX[i], Gdx.graphics.getHeight() / 2 + gap / 2 + tubeOffset[i]);    //top tube
				batch.draw(bottomTube, tubeX[i], Gdx.graphics.getHeight() / 2 - gap / 2 - bottomTube.getHeight() + tubeOffset[i]);    //bottom tube
				topTubeRectangle[i] = new Rectangle(tubeX[i],Gdx.graphics.getHeight() / 2 + gap / 2 + tubeOffset[i],topTube.getWidth(),topTube.getHeight());
				bottomTubeRectangle[i] = new Rectangle(tubeX[i],Gdx.graphics.getHeight() / 2 - gap / 2 - bottomTube.getHeight() + tubeOffset[i],bottomTube.getWidth(),bottomTube.getHeight());
			}


			if(birdY > 0)	//if bird above the screen
			{	//velocity 2 + 1
				velocity = velocity + gravity;
				birdY -= velocity;
			}
			else	//if bird touches the bottom of the screen
			{
				gamestate = 2;	//gameover state
			}
		}
		else if(gamestate == 0) {	//when game is not started
			if (Gdx.input.justTouched()) {
 				gamestate=1;	//starting of the game
			}
		} else if(gamestate == 2 || birdY >= Gdx.graphics.getHeight()){	//when game over

			batch.draw(gameOver, Gdx.graphics.getWidth()/20000,Gdx.graphics.getHeight()/2 - gameOver.getHeight()/2,Gdx.graphics.getWidth(),Gdx.graphics.getHeight()/10);

			if (Gdx.input.justTouched()) {	//as user touches the screen, the game start
				gamestate=1;	//starting of the game
				startGame(); //resatart
				score=0;
				scoringTube = 0;
				velocity=0;
			}
		}
		if (flapstate == 1)	//tracking the wings f the birds
			flapstate = 0;
		else
			flapstate = 1;


		batch.draw(birds[flapstate], Gdx.graphics.getWidth() / 2 - birds[flapstate].getWidth() / 2, birdY);

		font.draw(batch,String.valueOf(score),120,200);	//display of score in game screen

		birdCircle.set(Gdx.graphics.getWidth()/2, birdY + birds[flapstate].getHeight()/2,birds[flapstate].getWidth()/2);
//		shapeRenderer.begin(ShapeRenderer.ShapeType.Filled);
//		shapeRenderer.setColor(Color.RED);
//		shapeRenderer.circle(birdCircle.x,birdCircle.y,birdCircle.radius);

		for (int i=0;i<numberOfTube;i++){
			//shapeRenderer.rect(tubeX[i],Gdx.graphics.getHeight() / 2 + gap / 2 + tubeOffset[i],topTube.getWidth(),topTube.getHeight());
			//shapeRenderer.rect(tubeX[i],Gdx.graphics.getHeight() / 2 - gap / 2 - bottomTube.getHeight() + tubeOffset[i],bottomTube.getWidth(),bottomTube.getHeight());

			if(Intersector.overlaps(birdCircle,topTubeRectangle[i]) || Intersector.overlaps(birdCircle,bottomTubeRectangle[i])){
				gamestate = 2;	//gameover state
			}
		}
		batch.end();

//		shapeRenderer.end();
	}
	
	@Override
	public void dispose () {
		batch.dispose();
		background.dispose();
	}
}
