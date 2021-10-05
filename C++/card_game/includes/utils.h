#pragma once
#include<string>
#include<sstream>
#include "card.h"
#include <stack>


class UtilsFunctions{

public:
    string getCardName(string suite, int worth);
    void PrintHand(stack<Card> );
    void Welcome();
    bool Menu();
    void Gallery();
    void Settings();
};