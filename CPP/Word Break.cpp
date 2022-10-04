#include<bits/stdc++.h>
using namespace std;

unordered_set<string> words; //global for syntax
int dp[302]; //global for syntax

    bool backtrack(string &s, int start) {
        if(dp[start] != -1) return dp[start];
        if(start >= size(s)) return true;
        string temp = "";
        for(int ind = start; ind < size(s); ind++) {
            temp.push_back(s[ind]);
            if(words.find(temp) == words.end()) continue; // if not found
            if(backtrack(s, ind+1)) return dp[start] = true;
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word : wordDict) words.insert(word);
        memset(dp, -1, sizeof(dp));
        return backtrack(s, 0);
    }

int main(){
    string s ; cin>>s ; 
    vector<string> wordDict  ; 
    int n ; cin>>n; 
    for(int i = 0; i < n ; i++){
        string g ; cin>>g ; 
        wordDict[i] = g ; 
    }
    if(wordBreak(s , wordDict))[
        cout<<"true"<<endl ; 
    ]else{
         cout<<"false"<<endl ; 
    }
    return 0 ; 
}