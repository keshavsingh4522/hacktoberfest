#pragma once
#include<string>
#include<stack>
#include "card.h"

class Player{
    /*
        -------------------DATA ATTRIBUTES------------------------
            ♦ playerName: keep the player's nickname
            ♦ highScore: keep the player's highscore
    */
private:
    string playerName;
    int highScore; 
    int chanceOfChangingHand;
    int wins, loses;
    stack<Card> hand;

public:

    /*
        -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
            ♦ Player(): creates a new object of type player
            ♦ ~Player(): destroys object of type player
    */

    Player(string name);
    ~Player();


    /*
        -------------------ACCESSORS-------------------
        
                        GETTERS
            ♦ getPlayerName(): returns player's name
            ♦ getHighScore(): returns the high score
    */

    string GetPlayerName();
    int GetHighScore();
    int GetchanceOfChangingHand();
    int GetWins();
    int GetLoses();
    stack<Card> GetHand();

    /*
        ---------------------SETTERS---------------------
        ♦ SetPlayerName(): updates the player's name
        ♦ SetHighScore(): updates the player's high score
    */
    void SetPlayerName(string name);
    void SetHighScore(int highscore);
    void SetchanceOfChangingHand(int);
    void SetWins(int);
    void SetLoses(int);
    void SetHand(stack<Card>);


    /*
        ---------------------METHODS---------------------
        ♦ ChangeHand(): updates the player's hand
        ♦ PrintHand(): prints out player's hand
    */

    void ChangeHand();
    void PrintHand();
};