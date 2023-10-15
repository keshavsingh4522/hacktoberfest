#include <bits/stdc++.h>
using namespace std;

char generateComputerMove()
{
    int max = 2;
    int min = 0;
    int randNum = rand() % (max - min + 1) + min;

    switch (randNum)
    {
    case 0:
        return 'r';
    case 1:
        return 'p';
    case 2:
        return 's';
    default:
        return 'r';
    }
}

char determineWinner(char playerMove, char computerMove)
{
    if (playerMove == computerMove)
    {
        return 't';
    }
    else if (playerMove == 'r' && computerMove == 's')
    {
        return 'p';
    }
    else if (playerMove == 'p' && computerMove == 'r')
    {
        return 'p';
    }
    else if (playerMove == 's' && computerMove == 'p')
    {
        return 'p';
    }
    else
    {
        return 'c';
    }
}

int main()
{
    bool cont = true;
    char play;

    while (cont)
    {
        cout << "Welcome to Rock Paper Scissors!" << endl;
        cout << "Enter your move (r, p, or s): ";

        char playerMove;
        cin >> playerMove;

        char computerMove = generateComputerMove();

        char winner = determineWinner(playerMove, computerMove);

        if (winner == 'p')
        {
            cout << "You win!" << endl;
        }
        else if (winner == 'c')
        {
            cout << "The computer wins!" << endl;
        }
        else
        {
            cout << "Tie!" << endl;
        }

        cout << "Do you wish to play again (Y/N): ";
        cin >> play;

        if (play == 'Y' || play == 'y')
        {
            continue;
        }
        else if (play == 'N' || play == 'n')
        {
            cout << "Thank you for playing" << endl;
            break;
        }
        else
        {
            cout << "Invalid Input. Try again." << endl;
            cout << "Do you wish to play again (Y/N): ";
            cin >> play;
        }
    }

    return 0;
}