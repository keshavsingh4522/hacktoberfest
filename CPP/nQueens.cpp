#include<iostream>
using namespace std;
#define N 5

void printBoard(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

}

bool isValid(int board[N][N], int row, int col)
{
    for(int i = 0; i < col; i++) // Check the left columns if they contain a queen on the same row
    {
        if(board[row][i])
        {
            return false;
        }
    }

    for(int i = row, j = col; i>=0 && j>=0; i--, j--) // check the upper left diagonal for other queens
    {
        if(board[i][j])
        {
            return false;
        }
    }

    for(int i = row, j = col; i < N && j >= 0; i++, j--) // check the lower left diagonal for other queens
    {
        if(board[i][j])
        {
            return false;
        }
    }

    return true; // if there is no queen to the left, on the upper or lower left diagonals place the queen on current board[row][col]
}


bool placeQueens(int board[N][N], int col)
{

    if(col >= N)
    {
        return true;
    }

    for(int i = 0; i < N; i++)
    {

        if(isValid(board, i, col))
        {
            board[i][col] = 1;

            printBoard(board);
            cout << "\n\n";

            if(placeQueens(board, col + 1))
            {
                return true;
            }

            cout << "steps failed. Backtracking" << endl;
            board[i][col] = 0;
            printBoard(board);
            cout << "\n\n";

        }

    }
}


int main()
{

    int board[N][N];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
   
    if (placeQueens(board, 0) == false) 
    { 
        printf("Solution does not exist"); 
        return 0; 
    } 
   
    printBoard(board); 

    return 0;
}