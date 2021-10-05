#include "card.h"
#include "utils.h"
#include<string>
#include<sstream>
#include<ostream>
#include "color.h"
using namespace std; 
 /*
        -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
            ♦ Card(): creates a new object of type card
            ♦ Card(name): overloaded constructor, creates a new object of type card
            ♦ ~Card(): destroys object of type card
    */
    Card::Card() : worth(1), suite("Spade") {}

    
    Card::Card(string suite, int worth){
        UtilsFunctions *utils;
       string cardName = utils->getCardName(suite, worth);
       this->name = cardName;
        this->suite = suite;
        this->worth = worth;
    }
    Card::~Card(){
        this->name = "";
        this->suite = "";
        this->worth = 0;
    }

     /*
        -------------------ACCESSORS-------------------
        
                        GETTERS
            ♦ GetName(): returns card's name
            ♦ GetWorth(): returns the card's value
            ♦ GetSuite: returns the card's suite
    */
    string Card::GetName(){
        return this->name;
    }
    int Card::GetWorth(){
        return this->worth;
    }
    string Card::GetSuite(){
        return this->suite;
    }

     /*
        ---------------------SETTERS---------------------
        ♦ SetName(): updates the card's name
        ♦ SetWorth(): updates the card's value
        ♦ SetSuite(): updates card's suite
    */
    void Card::SetName(string _name){
        this->name = _name;
    }

    void Card::SetWorth(int _worth){
        this->worth = _worth;
    }

    void Card::SetSuite(string _suite){
        this->suite = _suite;
    }

     /*
        ---------------------METHODS---------------------
        ♦
        
    */
    string Card::GetColor(string suite){
        if(suite=="DIAMOND" || suite=="HEART"){
            //std::cout<<red;
            return "red";
        }
        else{
            return "black";
        }
    }
