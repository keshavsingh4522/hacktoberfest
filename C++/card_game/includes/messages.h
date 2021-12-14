#pragma once
#include<string>
#include<sstream>
#include<ostream>
using namespace std;


/**
 * @brief 
    THE CLASS MESSAGES CONTAINS ALL DIFFERENT MESSAGES USED IN THE PROGRAM :
        ♦ DeckMaster
        ♦ Menu
        ♦ How to play etc...
 * 
 */

class Messages{



/**
 * @brief 
    ------------------------------METHODS----------------------------
         ♦ string DeckMaster(): returns the string message 'BLACK MOON'
         ♦ string  Menu(): returns the string message of the game MENU
         ♦ string  Youwin(): returns the string message 'EUREKA! YOU WON...'
         ♦ string  GameOver(): returns the string message 'GAME OVER'
         ♦ string  NoWinner(): returns the string message 'NO WINNER'
         ♦ string  Lost(): returns the string message 'YOU LOST'
         ♦ string  Victory(): returns the string message 'VICTORY'
         ♦ string  Deck(): returns the string message 'DECK'
 * 
 */

public:
    string DeckMaster();
    string Menu();
    string HowToplay();
    string Youwin();
    string YouLose();
    string GameOver();
    string NoWinner();
    string Lost();
    string Victory();
    string Deck();
};