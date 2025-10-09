#include<bits/stdc++.h>
using namespace std;

// PROBLEM LINK:  https://leetcode.com/problems/unique-paths/

 int uniquePaths(int m, int n) {
        vector< vector<int>>dp(m,vector<int>(n));
        for(int i = 0;i<m;i++){
            dp[i][n-1] = 1;
        }
        for(int j = 0;j<n;j++){
            dp[m-1][j] = 1;
        }
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[i][j]= dp[i+1][j] + dp[i][j+1];
            }
        }
        
        
        return dp[0][0];
 }

int main(){
    
 int n;
 int m;
 n = 3;
 n = 2;
 //unique paths hsould be 3
 //From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 //1. Right -> Down -> Down
 //2. Down -> Down -> Right
 //3. Down -> Right -> Down
 
 cout<<uniquePaths(n,m);
 
    
 /*
 Input: m = 7, n = 3
Output: 28


Input: m = 3, n = 3
Output: 6
 
 Input: m = 3, n = 7
Output: 28
 */
    
}
