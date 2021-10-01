/*
Given a n x m grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


*/
#include<bits/stdc++.h>
using namespace std;
int dp[202][202];
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    dp[i][j]=grid[i][j];
                }else if(i==n-1){
                    dp[i][j]=grid[i][j]+dp[i][j+1];
                }
                else if(j==m-1){
                    dp[i][j]=grid[i][j]+dp[i+1][j];
                }
                else{
                    dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        
  }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
            int rows,cols;
            cin>>rows>>cols;
            vector<vector<int>> grid( rows , vector<int> (cols));
            for(int i=0;i<rows;i++){
               for(int j=0;j<cols;j++){
                       cin>> grid[i][j];
                }
          }
          cout << minPathSum(grid) << "\n";
    }
return 0;
}





