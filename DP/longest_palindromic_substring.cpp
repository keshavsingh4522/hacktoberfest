/*
Given a string s, return the longest palindromic substring in s.

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

*/

#include <bits/stdc++.h>
using namespace std;

 string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];
        int end=0;
        int start=0;
        string res="";
        for(int g=0;g<n;g++){
            int i=0;
            int j=g;
            while(j<n){
                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                if(dp[i][j] && j-i > end-start){
                    end=j;
                    start=i;
                }
                i++;
                j++;
            }
        }
        return s.substr(start,end-start+1);
    }
int main()
{
    int t;
    cin>>t;
    while(t--){
      string S;
      cin>>S;
      cout << longestPalindrome(S) << endl;
    }
}


