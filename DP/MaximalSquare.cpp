// In a 2-D Binary matrix filled with 0's and 1's, find the area of the largest square containing only 1's.
#include<bits/stdc++.h>
using namespace std;

int Maximal_Sq(vector <vector<int>> matrix){
  int h = matrix.size();
  int w = matrix[0].size();
  //cout << " h = " << h << "\t";
  //cout << " w = " << w << "\n";
  if (h == 0 || w == 0){
    return -1;
  }
  int ans = 0;
  vector <vector<int>> dp(h, vector<int>(w));
  for (int row = 0; row < h; ++row){
    for (int col = 0; col < w; ++col){
      if(matrix[row][col] == 1){
        //cout << "hi " << col;
        dp[row][col] = 1;    
        if (row > 0 && col > 0){
          //cout << "HII " << dp[row][col];
          dp[row][col] += min({dp[row-1][col], dp[row][col-1], dp[row-1][col-1]});
        }
        ans = max(ans, dp[row][col]);
      }
    }
  }
  return ans * ans;
}

int main(){
  //int n, m;
  //cout << "Enter bo. of rows & col. \n";
  //cin >> n >> m;
  vector <vector<int>> matrix {
    {1,1,1},
    {1,1,1},
    {1,1,1}
  };
  cout << "Area of largest Sq. = " << Maximal_Sq(matrix) << "\n";
  return 0;
}
