#include<iostream>
using namespace std;
bool isSafe(int board[][10], int row, int col, int n)	//This function is to check whether queen can be placed safely or not
{
	for(int i=0;i<col;i++)
	{
		if(board[row][i] == 1)
		{
			return false;
		}
	}
	for(int i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j] ==1)
		{
			return false;
		}
	}
	for(int i=row,j=col;i<n && j>=0;i++,j--)
	{
		if(board[i][j] ==1)
		{
			return false;
		}
	}
	return true;
}
bool nQueen(int board[][10], int col, int n)
{
	if(col>=n)
	{
		for(int i=0;i<n;i++)	//Simple printing of the board 
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	for(int i=0;i<n;i++)
	{
		if(isSafe(board,i,col,n))
		{
			board[i][col]=1;
			if(nQueen(board,col+1,n))	//Recursively calling the function to keep another queen
			{
				return true;
			}
			board[i][col]=0; 	//Backtracking
		}
	}
	return false;	//if control reaches over here that means there is no way to place queen on such a board
}
int main()
{
	int n;
	int board[10][10]={0};	//Initially no queen on board
	cin>>n;
	bool check = nQueen(board,0,n);	//function calling
	if(check == false)
	cout<<-1;
	return 0;
}
