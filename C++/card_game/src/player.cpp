 #include<iostream>
 #include<string>
 #include<stack>
 #include "card.h"
 #include "deck.h"
 #include "utils.h"
 using namespace std;



 
 /*
        ---------------CONSTRUCTOR AND DESTRUCTOR-------------------
            ♦ Player(): creates a new object of type player
            ♦ ~Player(): destroys object of type player
    */

    Player::Player(string name){
        Deck *deck = new Deck();
        stack<Card> hand = deck->PickHand();
        this->chanceOfChangingHand = 2;
        this->playerName = name;
        this->wins = 0;
        this->loses = 0;
        this->highScore = 0;
    }
    Player::~Player(){
        this->playerName = "player";
        this->highScore = 0;
    }


    /*
        -------------------ACCESSORS-------------------
                        GETTERS
            ♦ getPlayerName(): returns player's name
            ♦ getHighScore(): returns the high score
    */

    string Player::GetPlayerName(){
        return this->playerName;
    }
    int Player::GetHighScore(){
        return this->highScore;
    }
    int Player::GetchanceOfChangingHand(){
        return this->chanceOfChangingHand;
    }
    int Player::GetWins(){
        return this->wins;
    }
    int Player::GetLoses(){
        return this->loses;
    }
    stack<Card> Player::GetHand(){
        return this->hand;
    }

    /*
                       SETTERS
        ♦ SetUserName(): updates the player's name
        ♦ SetHighScore(): updates the player's high score
    */
    void Player::SetPlayerName(string name){
        this->playerName = name;
    }
    void Player::SetHighScore(int highscore){
        this->highScore = highscore;
    }
    void Player::SetchanceOfChangingHand(int chance){
        this->chanceOfChangingHand = chance;
    }
    void Player::SetWins(int _wins){
        this->wins = _wins;
    }
    void Player::SetLoses(int _loses){
        this->loses = _loses;
    }
    void Player::SetHand(stack<Card> _hand){
        this->hand = _hand;
    }

     /*
        ---------------------METHODS---------------------
        ♦ ChangeHand(): updates the player's hand
    */

    void Player::ChangeHand(){
        Deck *deck = new Deck();
        stack<Card> playerHand = deck->PickHand();
        this->hand = playerHand;
    }
    void Player::PrintHand(){
        stack<Card> Hand = this->hand;
        UtilsFunctions *utils = new UtilsFunctions();
        utils->PrintHand(Hand);
    }