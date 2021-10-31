#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> cost){
  int n = cost.size();
  int m = cost[0].size();
  int dp[n+1][m+1];

  dp[0][0] = cost[0][0];

  for(int i = 1; i <= n; i++){
    dp[i][0] = dp[i-1][0] + cost[i][0];
  }
  for(int j = 1; j <= n; j++){
    dp[0][j] = dp[0][j-1] + cost[0][j];
  }
  for(int i = 1; i <= n; ++i){
    for(int j =1; j <= m; ++j){
      dp[i][j] = cost[i][j] + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
    }
  }
  return dp[n][m];
}

int main()
{   
    vector<vector<int>> cost = {  {1, 2, 3},
                                  {4, 8, 2},
                                  {1, 5, 3} };
 
    cout << minCost(cost) << endl;
    return 0;
}
