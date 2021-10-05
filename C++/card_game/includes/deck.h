#pragma once
#include<string>
#include<vector>
#include "card.h"
#include "utils.h"
#include "player.h"
using namespace std;

class Deck{
     /*
        -------------------DATA ATTRIBUTES------------------------
            ♦ cards: keep the collection of all cards in a vector
    */
private:
    vector<Card> cards;

public:
    /*
        -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
            ♦ Deck(): creates a new object of type Deck
            ♦ ~Deck(): destroys object of type card
    */
    Deck(); 
    ~Deck();

    vector<Card> GetCards();

     /*
        ---------------------METHODS---------------------
        ♦ Shuffle(): shuffle the collection of cards
        ♦ PickCard(): return a card from the cards collection
        
    */
    void Shuffle();
    Card PickCard();
    stack<Card> PickHand();
    void PutBackCard(Card card);

};