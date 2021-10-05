#include "messages.h"
#include<string>
#include<ostream>
#include<sstream>
using namespace std;

/**
 * @brief 
    CONSTEXPR: constexpr is a keyword introduced in C++ 11
    It is somehow like the 'const' keyword but it can also be applied on functions
    The main idea is to help programs to do computations in compilation time rather than run time

    AUTO: The auto keyword specifies that the type of the variable that is 
    being declared will be automatically deducted from its initializer.
 * 
 * @return string 
 */


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


    string Messages::DeckMaster(){
        constexpr auto blackmoon = R"(
             _______   ___            __       ______   __   ___  ___      ___     ______      ______    _____  ___   
            |   _  "\ |"  |          /""\     /" _  "\ |/"| /  ")|"  \    /"  |   /    " \    /    " \  (\"   \|"  \  
            (. |_)  :)||  |         /    \   (: ( \___)(: |/   /  \   \  //   |  // ____  \  // ____  \ |.\\   \    | 
            |:     \/ |:  |        /' /\  \   \/ \     |    __/   /\\  \/.    | /  /    ) :)/  /    ) :)|: \.   \\  | 
            (|  _  \\  \  |___    //  __'  \  //  \ _  (// _  \  |: \.        |(: (____/ //(: (____/ // |.  \    \. | 
            |: |_)  :)( \_|:  \  /   /  \\  \(:   _) \ |: | \  \ |.  \    /:  | \        /  \        /  |    \    \ | 
            (_______/  \_______)(___/    \___)\_______)(__|  \__)|___|\__/|___|  \"_____/    \"_____/    \___|\____\) 

                                        (THE BEST EVER CARD GAME... YOU UNDERTSTAND?)                                                                

        )";
        std::ostringstream _blackmoon; //declaring a new output stream variable
        _blackmoon << blackmoon; //writing the raw string in the output stream
        system("cls");
        system("cls");
        return _blackmoon.str(); //returning the string content of the output stream
    }


    string Messages::Youwin(){
        constexpr auto youwin = R"(
                
                                _____ _   _______ _____ _   __ ___  _  __   _______ _   _   _    _ _____ _   _       
                                |  ___| | | | ___ \  ___| | / // _ \| | \ \ / /  _  | | | | | |  | |  _  | \ | |      
                                | |__ | | | | |_/ / |__ | |/ // /_\ \ |  \ V /| | | | | | | | |  | | | | |  \| |      
                                |  __|| | | |    /|  __||    \|  _  | |   \ / | | | | | | | | |/\| | | | | . ` |      
                                | |___| |_| | |\ \| |___| |\  \ | | |_|   | | \ \_/ / |_| | \  /\  | \_/ / |\  |_ _ _ 
                                \____/ \___/\_| \_\____/\_| \_|_| |_(_)   \_/  \___/ \___/   \/  \/ \___/\_| \_(_|_|_)
                                                                                                                
                                                                                      

        )";
         std::ostringstream _youwin;
        _youwin << youwin; 
        return _youwin.str();
    }
    string Messages::YouLose(){
            constexpr auto youlose = R"(    
                                            ______  _____ ______  _____   ___   _____  _ 
                                            |  _  \|  ___||  ___||  ___| / _ \ |_   _|| |
                                            | | | || |__  | |_   | |__  / /_\ \  | |  | |
                                            | | | ||  __| |  _|  |  __| |  _  |  | |  | |
                                            | |/ / | |___ | |    | |___ | | | |  | |  |_|
                                            |___/  \____/ \_|    \____/ \_| |_/  \_/  (_)
            )";

        std::ostringstream _youlose;
        _youlose << youlose; 
        return _youlose.str();
    }

    string Messages::GameOver(){
        constexpr auto gameOver = R"(
            
                                        _____  ___ ___  ________   _____ _   _ ___________ 
                                        |  __ \/ _ \|  \/  |  ___| |  _  | | | |  ___| ___ \
                                        | |  \/ /_\ \ .  . | |__   | | | | | | | |__ | |_/ /
                                        | | __|  _  | |\/| |  __|  | | | | | | |  __||    / 
                                        | |_\ \ | | | |  | | |___  \ \_/ | \_/ / |___| |\ \ 
                                        \____|_| |_|_|  |_|____/   \___/ \___/\____/\_| \_|
                                                                                        
                                                    

        )";
     std::ostringstream _gameOver;
        _gameOver << gameOver; 
        return _gameOver.str();
    }
    

    string Messages::HowToplay(){
        constexpr auto howtoPlay = R"(
            
                        .-"-._,-'_`-._,-'_`-._,-'_`-._,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,.
                        (  ,-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-~-} ;.
                        \ \.'_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-._~--. \ .
                        /\ \/ ,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._`./ \ \ .
                        ( (`/ /                                                               \ / \ \ .
                        \ \') )           __           ___ ____     __        __              \ / \ \ .   
                        ( (`/ /     |__| |  | | | |     |  |  |    |__] |    |__|  \_/        \ / \ \ .
                        ( (`/ /     |  | |__| |_|_|     |  |__|    |    |___ |  |   |         \ / \ \ .
                        ( (`/ /                                                               \ / \ \ .
                        / / \ /                                                               \ / \ \ .
                        \ \') )                                                               ( (,\ \ . 
                        / \ / /  1. The goal in Blackmoon cards is to beat the computer's     \ / \ \ . 
                        ( (`/ /     hand with a hand of greater worth                         / /.) ) . 
                        / ('/ /     (sum of cards in the hand)                                / /.) ) .
                        \ \ / \                                                               / / \ / . 
                        \ \') )  2. Gallery provides you with deck, color and value of cards  ( (,\ \ . 
                        / \ / /                                                               \ / \ \ .
                        ( ( / /  3. Pressing C asks for another hand of cards. Pressing other / /.) ) .
                        \ \ / \     keys holds your total(hand) and end your turn.            / / \ / . 
                        \ \') )                                                               ( (,\ \ . 
                        / \ / /  4. Your name is required before the start of the game.       \ / \ \ .
                        ( ( / /                                                               / /.) ) . 
                        \ \ / \  5. A lower hand worth means you lose the game                / / \ / .
                        \ \') )                                                               ( (,\ \ . 
                        / \ / /                                                               \ / \ \ .
                        ( ( / /                                                               / /.) ) .
                        \ \ / \       _       _ (Press any key to continue) _       _         / / \ /.
                        \ `.\ `-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._-'_`-._,-'_/ ,/.\ \ . 
                        ( `. `,~-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-=,' ,\ \ .
                        `. `'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,"-' ; .
                            `-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-.-' .
    
        )";

        
        std::ostringstream _howtoPlay;
        _howtoPlay << howtoPlay; 
        return _howtoPlay.str();
    }

    string Messages::NoWinner(){
        constexpr auto noWinner = R"(
            
                                    _   _ _____   _    _ _____ _   _ _   _ ___________ 
                                    | \ | |  _  | | |  | |_   _| \ | | \ | |  ___| ___ \
                                    |  \| | | | | | |  | | | | |  \| |  \| | |__ | |_/ /
                                    | . ` | | | | | |/\| | | | | . ` | . ` |  __||    / 
                                    | |\  \ \_/ / \  /\  /_| |_| |\  | |\  | |___| |\ \ 
                                    \_| \_/\___/   \/  \/ \___/\_| \_|_| \_|____/\_| \_|
                                                                                
                                                    

        )";
     std::ostringstream _noWinner;
        _noWinner << noWinner; 
        return _noWinner.str();
    }

    string Messages::Menu(){
        constexpr auto menu = R"(
                                        ................................. 
                                        |         1-Start a new Game    | 
                                        |         2-Use Joystick        |
                                        |         3-Deactivate sound    |
                                        |         4-How to Play?        |   
                                        |         5-Gallery             |
                                        |         6-Exit                |                
                                        .................................
        )";
     std::ostringstream _menu;
        _menu << menu; 
        return _menu.str();
    }

    string Messages::Victory(){
        constexpr auto victory = R"(
            
                                    (                      )   (        )  
                                    )\ )   (     *   )  ( /(   )\ )  ( /(  
                                    (   (  (()/(   )\  ` )  /(  )\()) (()/(  )\()) 
                                    )\  )\  /(_))(((_)  ( )(_))((_)\   /(_))((_)\  
                                    ((_)((_)(_))  )\___ (_(_())   ((_) (_)) __ ((_) 
                                    \ \ / / |_ _|((/ __||_   _|  / _ \ | _ \\ \ / / 
                                     \ V /   | |  | (__   | |   | (_) ||   / \ V /  
                                      \_/   |___|  \___|  |_|    \___/ |_|_\  |_|   
                                                                

        )";
     std::ostringstream _victory;
        _victory << victory; 
        return _victory.str();
    }

    string Messages::Lost(){
        constexpr auto lost = R"(
            
                                        .   .__..  .  .   .__. __..___.  | 
                                        \./ |  ||  |  |   |  |(__   |    | 
                                         |  |__||__|  |___|__|.__)  |    * 
                                                                        

        )";
     std::ostringstream _lost;
        _lost << lost; 
        return _lost.str();
    }

     string Messages::Deck(){
        constexpr auto  deck = R"(
                
                                                ______ _____ _____  _   __
                                                |  _  \  ___/  __ \| | / /
                                                | | | | |__ | /  \/| |/ / 
                                                | | | |  __|| |    |    \ 
                                                | |/ /| |___| \__/\| |\  \
                                                |___/ \____/ \____/\_| \_/
                          
                          

        )";
     std::ostringstream _deck;
        _deck << deck; 
        return _deck.str();
    }