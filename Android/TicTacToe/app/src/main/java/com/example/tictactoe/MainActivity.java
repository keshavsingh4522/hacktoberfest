package com.example.tictactoe;

import androidx.appcompat.app.AppCompatActivity;
import androidx.gridlayout.widget.GridLayout;

import android.media.Image;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    int activeplayer = 0;   //0: yellow, 1: red, 2: empty state...
    boolean gameactive = true;  //for the winning condition
    int[] gamestate = {2,2,2,2,2,2,2,2,2};   // we have 9 state 0,1,2,3,4,5,6,7,8
    int[][] winningstates = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    public void tapped(View view)
    {
        ImageView counts = (ImageView) view;
        int tapat = Integer.parseInt(counts.getTag().toString());   //for backup if the state is empty then only user is allowed to enter the game move
//        Toast.makeText(this, counts.getTag().toString(), Toast.LENGTH_SHORT).show();
        if(gameactive && gamestate[tapat] == 2){

            counts.setTranslationY(-1500);  //creating animation from +ve y axis
            gamestate[tapat]=activeplayer;  //it stores the value and records of the player and the position...
            if(activeplayer==0)
            {
                counts.setImageResource(R.drawable.yellow);
                activeplayer=1; //updated the player
            }
            else
            {
                counts.setImageResource(R.drawable.red);
                activeplayer=0; //updated the player
            }
            counts.animate().translationYBy(1500).rotation(3600).setDuration(300);
            for(int[] winningstate : winningstates)
            {
                if(gamestate[winningstate[0]]==gamestate[winningstate[1]] && gamestate[winningstate[1]]==gamestate[winningstate[2]] && gamestate[winningstate[1]]!=2)
                {
                    String winner="";
                    if(activeplayer == 1)
                    {
                        winner = "yellow "; //because we have updated the state of next played look at the pointer
                    }
                    else
                    {
                        winner ="red ";
                    }
//                    Toast.makeText(this, , Toast.LENGTH_SHORT).show();
                    //we can notice that after ending the game also we can play.... that is not the rule so lets fix it. remember tha gameisactive??
                    gameactive = false;
                    //now lets create some ui and button to replay the game...
                    //when a user won the game then we will highlight the textView..
                    TextView winnertext = (TextView) findViewById(R.id.winner);
                    winnertext.setText(winner + "has won");
                    winnertext.setVisibility(View.VISIBLE);
                    Button playag = (Button) findViewById(R.id.playagainbutton);
                    playag.setVisibility(View.VISIBLE); //now create onclick method.... playagain?
                }
            }
        }
    }
    public  void playagain(View view)
    {
        TextView winnertext = (TextView) findViewById(R.id.winner);
        winnertext.setVisibility(View.INVISIBLE);
        Button playag = (Button) findViewById(R.id.playagainbutton);
        playag.setVisibility(View.INVISIBLE);
        GridLayout grd = (GridLayout) findViewById(R.id.gridLayout);
        for(int i=0;i<grd.getChildCount();i++)   //now we have to erase the imageView from grid view...getChildCount() will return the count of childs
        {
            ImageView counts = (ImageView) grd.getChildAt(i);
            counts.setImageDrawable(null);  //will remove the image of red or yellow circle
        }
        // now we have to update the gamestate...
        activeplayer = 0;   //0: yellow, 1: red, 2: empty state...
        gameactive = true;  //for the winning condition
        for(int i=0;i<gamestate.length;i++)
        {
            gamestate[i]=2;
        }
        //lets play...
//        Thanks for watching
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}