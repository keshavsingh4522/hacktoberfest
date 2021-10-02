#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main(void){
    string s="tea",t="eat";

    map<char,int>mp1,mp2;

    for(int i=0;i<=s.length();i++){
        mp1[s[i]]++;
    }
    for(int i=0;i<=t.length();i++){
        mp2[t[i]]++;
    }
    if(mp1==mp2){
        cout<<"true";
    }else
    cout<<"false";



}