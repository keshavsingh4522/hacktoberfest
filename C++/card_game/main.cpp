#include <iostream>
#include<string>
#include<ostream>
#include<sstream>
#include "color.h"
#include "card.h"
#include "messages.h"
#include "utils.h"
#include "game.h"

using namespace std;

int main()
{

    int choice;
    
    UtilsFunctions *utils = new UtilsFunctions();
    Messages *messages = new Messages();

    while(true){
        utils->Welcome();
        cout<<messages->Menu();
        cout<<"Press the corresponding key to your choice: ";
         cin>>choice;
         DeckMaster *Game;
         
        switch(choice){
            case 1:
                
                utils->Welcome();
                Game = new DeckMaster();
                Game->PrintStatistics();
                Game->InitGame();
                break;
            case 2:
                cout<<"\t \t---------PURCHASE PREMIUM VERSION----------"
                    <<endl
                    <<"\t \t PRICE : ($49.99)"
                    <<endl
                    <<"\t \t(MOMO 679782255)"
                    <<endl;
                    system("pause");
                break;
            case 3:
                cout<<endl
                    <<"\t \t---------SOUND SETTINGS----------"
                    <<endl
                    <<"\t \t Sound deactivated!"
                    <<endl;
                    system("pause");
                break;      
            case 4:
                cout<<messages->HowToplay();
                system("pause > 0");
                break;
            case 5:
                utils->Gallery();
                system("pause");
                break;
            case 6:
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }

    
    
    system("pause > 0");
    return 0;
}
