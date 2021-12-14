#pragma once
#include<string>
#include<ostream>
using namespace std;

class Card
{
    /*
        -------------------DATA ATTRIBUTES------------------------
            ♦ name: keep the card's name
            ♦ suite: keep the card's suite
            ♦ worth: keep the value of the card
    */
private:
 string suite;
 int worth;
 string name;

public:
    /*
        -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
            ♦ Card(): creates a new object of type card
            ♦ Card(suite, int): overloaded constructor, creates a new object of type card
            ♦ ~Card(): destroys object of type card
    */
    Card(); 
    Card(string, int);
    ~Card();

     /*
        -------------------ACCESSORS-------------------
        
                        GETTERS
            ♦ GetName(): returns card's name
            ♦ GetWorth(): returns the card's value
            ♦ GetSuite: returns the card's suite
    */
    string GetName();
    int GetWorth();
    string GetSuite();

     /*
        ---------------------SETTERS---------------------
        ♦ SetName(): updates the card's name
        ♦ SetWorth(): updates the card's value
        ♦ SetSuite(): updates card's suite
    */
    void SetName(string _name);
    void SetWorth(int _worth);
    void SetSuite(string _suite);
     /*
        ---------------------METHODS---------------------
        ♦ string GetColor(): returns the color of the card
        ♦ string GetDesign(): returns 
        
    */
    string GetColor(string);
    string GetDesign(string);

   
};