#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include <stdlib.h>
#include<time.h>
#include "deck.h"
#include "card.h"
using namespace std;

 /*
        -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
            ♦ Deck(): creates a new object of type Deck
            ♦ ~Deck(): destroys object of type card
    */
    Deck::Deck(){
        for(int i = 1; i<= 13; i++){
            Card card_diamond("DIAMOND", i);
            Card card_spade("SPADE", i);
            Card card_club("CLUB", i);
            Card card_heart("HEART", i);

            this->cards.push_back(card_diamond);
            this->cards.push_back(card_spade);
            this->cards.push_back(card_club);
            this->cards.push_back(card_heart);
        }
    } 
    Deck::~Deck(){
         this->cards.clear();
    }

    vector<Card> Deck::GetCards(){
        return this->cards;
    }

     /*
        ---------------------METHODS---------------------
        ♦ Shuffle(): shuffle the collection of cards
        ♦ PickCard(): return a card from the cards collection
        ♦ PickHand(): return a stack of 5 cards picked from the deck collection
        ♦ PutBackCard(): put back a card in the deck
        
    */
    void Deck::Shuffle(){
        std::random_shuffle(cards.begin(), cards.end());
    }


    Card Deck::PickCard(){
        int index = rand() % cards.size();
        Card pickedCard = cards.at(index);
        cards.erase(cards.begin() + index);
        return pickedCard;
    }


    void Deck::PutBackCard(Card card){
        this->cards.push_back(card);
        this->Shuffle();
    }


    stack<Card> Deck::PickHand(){
        stack<Card> hand;
        this->Shuffle();
        for(int i = 1; i<=5; i++){
            hand.push(this->PickCard());
        }
        return hand;
    }
