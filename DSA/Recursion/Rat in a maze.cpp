/*
                      Statement
Consider a rat placed at (0, 0) in a square matrix of order N * N. 
It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 
at a cell in the matrix represents that rat can be travel through it.

Note: In a path, no cell can be visited more than one time. 
If the source cell is 0, the rat cannot move to any other cell.

// Example :
Input:N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}

Output: DDRDRR DRDDRR
Explanation:The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR 
            and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
*/


// code
#include <bits/stdc++.h>
class Solution{
    private:
        // Checking if the given x and y are possible values of not.
        bool isPossible(int x ,int y, int n, vector<vector<int>> &visited, vector<vector<int>>&m){
            if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (m[x][y]==1)){
                return true;
            }
            return false;
        }
        
        void solve(vector<vector<int>> &m,vector<vector<int>> visited,string temp,int n,int x,int y,vector<string> &res){
            if(x==n-1 && y==n-1){
                res.push_back(temp);
                return;
            }
            
            visited[x][y]=1;
        
            string save=temp;
            
            int newx=x+1;
            int newy=y;
            if(isPossible(newx,newy,n,visited,m)==true){
                temp+="D";
                solve(m,visited,temp,n,newx,newy,res);
                temp=save;
            }
            
            newx=x-1;
            newy=y;
            if(isPossible(newx,newy,n,visited,m)==true){
                temp+="U";
                solve(m,visited,temp,n,newx,newy,res);
                temp=save;
            }
            
            newx=x;
            newy=y+1;
            if(isPossible(newx,newy,n,visited,m)==true){
                temp+="R";
                solve(m,visited,temp,n,newx,newy,res);
                temp=save;
            }
            
            newx=x;
            newy=y-1;
            if(isPossible(newx,newy,n,visited,m)==true){
                temp+="L";
                solve(m,visited,temp,n,newx,newy,res);
                temp=save;
            }
            
            visited[x][y]=0;
        }
  
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
      
        // If the initial point is 0 we can't move forward and will return res.
        if(m[0][0]==0){
            return res;
        }
        
        // Creating a 2-D visited array will be used in backtracking.
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        string temp="";
        int x=0,y=0;
        solve(m,visited,temp,n,x,y,res);
        sort(res.begin(),res.end());
        return res;
    }
};
