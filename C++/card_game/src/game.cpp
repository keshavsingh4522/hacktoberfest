#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include "messages.h"
#include "card.h"
#include "player.h"
#include "deck.h"
#include "game.h"
#include "color.h"

using namespace std;


string nickname = "";


/*
            -----------------CONSTRUCTOR AND DESTRUCTOR-------------------
            ♦ DeckMaster(): creates a new object of type DeckMaster
            ♦ ~DeckMaster(): destroys object of type DeckMaster
    */
    DeckMaster::DeckMaster(){
        
        
        if(nickname ==""){
            cout<<endl
            <<"\t " <<"\t"
            <<"Enter your nickname: ";
            cin>>nickname;
        }
       
        this->player = new Player(nickname);
        this->computer = new Player("BlackMoon");
        this->deck = new Deck();
        this->roundTail = 0;
    } 

    
    DeckMaster::~DeckMaster(){
        this->player = NULL;
        this->computer = NULL;
        this->deck = NULL;
        this->roundTail = 0;
    }

     /*
        -------------------ACCESSORS-------------------
        
                        GETTERS
            ♦ GetPlayer(): returns human player
            ♦ GetComputer(): returns the machine player
            ♦ GetDeck(): returns the deck
            ♦ GetRoundsTail(): returns the roundstail
    */
    Player* DeckMaster::GetPlayer(){
        return this->player;
    }
    Player* DeckMaster::GetComputer(){
        return this->computer;
    }
    Deck* DeckMaster::GetDeck(){
        return this->deck;
    }
    int DeckMaster::GetRoundsTail(){
        return this->roundTail;
    }

     /*
        ---------------------SETTERS---------------------
        ♦ SetPlayer(): updates the human player
        ♦ SetComputer(): updates the machine player
        ♦ SetDeck(): updates games's deck
        ♦ SetRoundsTail(): updates the roundstail
    */

    void DeckMaster::SetPlayer(Player* player){
        this->player = player;
    }
    void DeckMaster::SetComputer(Player* computer){ 
        this->computer = computer;
    }
    void DeckMaster::SetDeck(Deck* deck){
        this->deck = deck;
    }
    void DeckMaster::SetRoundsTail(int rounds){
        this->roundTail = rounds;
    }


    /*
        ---------------------METHODS---------------------
        ♦ Welcome(): prints welcome message
        ♦ InitGame(): Initializes the by generating the Deck
        ♦ PrintStatistics(): prints games's statistics
        ♦ PlayRound(): Starts a new round
    */

    
    void DeckMaster::InitGame(){
        std::cout<<"\a";
B:
        Player *player = this->player;
        Player *computer = this->computer;
        UtilsFunctions *utils = new UtilsFunctions();
        char isSatisfied;
        stack<Card> playerHand;
        stack<Card> computerHand;

        Deck *deck = this->deck;

        A:
            playerHand = deck->PickHand();
            player->SetHand(playerHand);
            cout<<"......................................";
            cout<<".................................................\n";
            cout<<"\t "<<"\t "
                <<endl<<"YOUR CARDS: " 
              
                <<endl;
            //printing user hand
            cout<<lightCyan;
            utils->PrintHand(playerHand);
            cout<<lightGreen;
        
        cout<<"Press C to change hand or any other key to continue: ";
        cin>>isSatisfied;
        std::cout<<"\a";

        switch(isSatisfied){
            case 'C':
                    //Putting back the cards
                 while(!playerHand.empty()){
                    deck->PutBackCard(playerHand.top());
                    playerHand.pop();
                    }
                    goto A;
                    break;
            case 'c':
                  //Putting back the cards
                 while(!playerHand.empty()){
                    deck->PutBackCard(playerHand.top());
                    playerHand.pop();
                    }
                    goto A;
                    break;
            default:
                break;

        }

        computerHand = deck->PickHand();
        computer->SetHand(computerHand);

            cout<<"......................................";
            cout<<".................................................\n";
            cout<<"\t "<<"\t "<<endl<<"COMPUTER'S CARDS: "<<endl;
            //printing computer's hand
            cout<<red;
            utils->PrintHand(computerHand);
            cout<<lightGreen;
            system("pause");

        this->Play();

    }




    /**
     * @brief Prints all the information about the player
     * 
     */
    void DeckMaster::PrintStatistics(){
        std::cout<<"\a";
        Player *player = this->player;
        Player *computer = this->player;
        int roundTail = this->GetRoundsTail();
        
        cout<<endl <<"\t " <<"\t "<<"\t ";
        cout<<lightMagenta
            <<"Name: "
            <<bold_on<<player->GetPlayerName()
            <<"\t ";

        cout<<green
            <<"Rounds played: "
            <<this->GetRoundsTail()
            <<"\t ";

        cout<<green
            <<"Wins: "
            <<player->GetWins()
            <<"\t ";

        cout<<red
            <<"Loses: "
            <<player->GetLoses()
            <<"\t "
            <<bold_off
            <<lightGreen;


        cout<<endl;
    }




/**
 * @brief Announces final winner based on the number of wins 
            Draw match is announced if the three rounds has no winner
 * 
 * @param playerWins number of wins of the player
 * @param playerLoses number of loses of the player
 */


   void DeckMaster::AnnounceFinalWinner(int playerWins, int playerLoses){
       std::cout<<"\a";
       Messages *messages = new Messages();
       if(playerWins > playerLoses){

        cout<<messages->Victory(); 
        system("pause");
        
       }
       else if (playerWins == playerLoses ) {
           cout <<endl<<"******************DRAW MATCH!******************";
       }
       else {
           cout<<messages->Lost();
           system("pause");   
              
           }
   }



    /**
     * @brief 
        ♦ Compares each pair of cards (PLAYER'S CARD, COMPUTER'S CARD)
        ♦ Compares sum of player's hand to computer's hand
        ♦ Announce the winner of the round
     * 
     * @return true if the player has chosen to continue playing
     * @return false otherwise
     */
    bool DeckMaster::Play(){
        std::cout<<"\a";

            Player *player  = this->player;
            stack<Card> playerHand = player->GetHand();
            Player *computer = this->computer;
            stack<Card> computerHand = computer->GetHand();
            Messages *messages = new Messages();

            int lastRound = this->roundTail;

            Card _computerHand[5];
            Card _playerHand[5];
            int index = 0;
            while(!playerHand.empty()){
                _playerHand[index] = playerHand.top();
                playerHand.pop();
                index++;
                
            }
            index = 0;
            while(!computerHand.empty()){
                _computerHand[index] = computerHand.top();
                computerHand.pop();
                index++;
                
            }
            cout<<"\t \t"
                <<"-------------------------"
                <<"PLAYING ROUND " + std::to_string(roundTail + 1)
                <<"-----------------------"
                <<endl <<endl;
            for(int i =0; i<5; i++){

                cout<<_playerHand[i].GetName()
                    <<" ( " << _playerHand[i].GetWorth() <<" ) "
                    <<"  -------------"
                    <<" VS "
                    <<" -------------- "
                    <<_computerHand[i].GetName()
                    <<" ( " << _computerHand[i].GetWorth() <<" ) ";
                    

                    if(_computerHand[i].GetWorth() > _playerHand[i].GetWorth()){
                        cout<<" ==> "
                            <<_computerHand[i].GetName()
                            <<" WINS!"
                            <<endl
                            <<endl;
                            
                    }
                    else if(_computerHand[i].GetWorth() == _playerHand[i].GetWorth()){
                            cout<<"NO WINNER" <<endl<<endl;
                    }
                    else{
                        cout<<" ==> "
                            <<_playerHand[i].GetName()
                            <<" WINS! (YOU WON)"
                            <<endl
                            <<endl;
                            
                            
                      }
            }

            this->AnnounceWinner(_computerHand, _playerHand);
            this->SetRoundsTail(lastRound + 1);

            cout<<endl<<"\t \t \t YOUR STATISTICS..."<<endl;
            this->PrintStatistics();

            char isGamecontinuing;
            if(this->roundTail <=2){
                cout<<endl<<"Press C to continue or any other letter to exit: ";
                std::cout<<"\a";
                cin>>isGamecontinuing;
                if(isGamecontinuing == 'C' || isGamecontinuing == 'c'){
                    if( (this->roundTail == 2) && (player->GetWins() == 0)  ){
                        cout<<messages->GameOver();
                         cout<<"\t \t YOUR STATISTICS..."<<endl;
                         
                        /* AnnounceFinalWinner(player->GetWins(), player->GetLoses());
                         this->PrintStatistics();
                         system("pause");*/
                         

                    }
                else{
                    
                    this->InitGame();
                    cout<<"\t \t \t-------------- FINAL STATISTICS------------------"<<endl;
                    AnnounceFinalWinner(player->GetWins(), player->GetLoses());
                    this->PrintStatistics();
                   
                
                }
                  
            }
                }
                else{
                    cout<<"\t \t \t-------------- FINAL STATISTICS------------------"<<endl;
                    AnnounceFinalWinner(player->GetWins(), player->GetLoses());
                    this->PrintStatistics();
                    
            }
            }
    //}




    /**
     * @brief Compares computer's hand value and player's hand value, then announce the winner of the round
     * 
     * @param computerHand cards of teh computer
     * @param playerHand cards of th player
     */
    void DeckMaster::AnnounceWinner(Card computerHand[], Card playerHand[]){
        std::cout<<"\a";
        int computerHandWorth = 0;
        int playerHandWorth = 0;
        Messages *messages = new Messages();
        for(int i = 0; i<5; i++){
            computerHandWorth += computerHand[i].GetWorth();
            playerHandWorth += playerHand[i].GetWorth();
        }

            cout<<endl<<"\t \t \t" 
                <<"YOU ( " << playerHandWorth<<" POINTS) "
                <<"  -------------"
                <<" VS "
                <<" -------------- "
                <<" COMPUTER( " << computerHandWorth<<" POINTS) ";

        if(playerHandWorth > computerHandWorth){
            Player *player = this->player;
            player->SetWins(player->GetWins() + 1);
            
            cout<<green
                <<messages->Youwin();
            cout<<def;
        }
        else if(playerHandWorth == computerHandWorth){
            cout<<messages->NoWinner();
        }
        else{
            cout<<red
                <<messages->YouLose();
            cout<<def;
            player->SetLoses(player->GetLoses() + 1);
            
        }
    }


    /**
     * @brief Prints game over message
        Game over occurs if the player loses the first and second round
     * 
     */
    void DeckMaster::GameOver(){
        std::cout<<"\a";
        Messages *messages = new Messages();
        cout<<messages->GameOver();
        this->PrintStatistics();
        exit(0);
    }