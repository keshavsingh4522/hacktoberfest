#include <bits/stdc++.h>

using namespace std;

bool isMatch(string str, string pattern)
{
  int m = str.length(), n = pattern.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++)
  {
    if (pattern[i - 1] == '*')
    {
      dp[i][0] = dp[i - 2][0];
    }
    else
    {
      dp[i][0] = false;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (pattern[i - 1] == '*')
      {
        if (dp[i - 2][j] == true)
        {
          dp[i][j] = true;
        }
        else
        {
          if (pattern[i - 2] == str[j - 1] || pattern[i - 2] == '.')
          {
            dp[i][j] = dp[i][j - 1];
          }
          else
          {
            dp[i][j] = false;
          }
        }
      }
      else if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '.')
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = false;
      }
    }
  }
  return dp[n][m];
}

int main()
{
  string str, pattern;
  cin >> str >> pattern;

  if (isMatch(str, pattern))
  {
    cout << "The pattern matches the given string" << endl;
  }
  else
  {
    cout << "The pattern doesn't match." << endl;
  }
}