//given mxn maze find and count all possible paths that helps in escaping the rat
//it can move only forwards and downwards

#include <iostream>
using namespace std;

//i,j-> coordinates of current cell
//m,n-> coordinates of last cell
bool solve( char maze[10][10],int sol[10][10],int i,int j,int m,int n)
{
    if(m==i && n==j)
    {
        sol[m][n]=1;

        //printing the path
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }   
        cout<<endl;
        return true;
    }
    if(i>m || j>n)
    return false;

    //cell is blocked
    if(maze[i][j]=='X')
    return false;

    //Assuming this condition
    sol[i][j]=1;
    bool down=solve(maze,sol,i+1,j,m,n);
    bool forward=solve(maze,sol,i,j+1,m,n);

    //backtracking
    sol[i][j]=0;


    if(down || forward)
    return true;
    // else
    return false;
}

int main() {
    char maze[10][10]={"0000","0x00","00x0","000x"};
    int sol[10][10]={0};
    int m,n;

    solve(maze,sol,0,0,m-1,n-1);
    return 0;
}
#include <iostream>
using namespace std;

//i,j-> coordinates of current cell
//m,n-> coordinates of last cell
bool solve( char maze[10][10],int sol[10][10],int i,int j,int m,int n)
{
    if(m==i && n==j)
    {
        sol[m][n]=1;
        //printing the path
        int k1,k2;

        for(k1=0;k1<m;k1++)
        {
            for(k2=0;k2<n;k2++)
            {
                cout<<sol[k1][k2]<<" ";
            }
            cout<<endl;
        }   
        cout<<endl;
        return true;
    }
    if(i>m || j>n )
    return false;

    //cell is blocked
    if(maze[i][j]=='X')
    return false;

    //Assuming this condition
    sol[i][j]=1;
    bool down=solve(maze,sol,i+1,j,m,n);
    bool forward=solve(maze,sol,i,j+1,m,n);

    //backtracking
    sol[i][j]=0;


    if(down || forward)
    return true;
    // else
    return false;
}

int main() {
    char maze[10][10];
    // ={{'0','0','0','0'},
    // {'0','x','0','0'},
    // {'0','0','x','0'},
    // {'0','0','0','x'}};
    int m,n;
    cin>>m>>n;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    int sol[10][10]={0};
    // int m,n;

    solve(maze,sol,0,0,m,n);
    return 0;
}
