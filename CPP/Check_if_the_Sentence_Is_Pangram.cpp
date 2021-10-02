/*
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
accumulate(first, last, sum);
first, last : first and last elements of range 
              whose elements are to be added
sum :  initial value of the sum
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<char> v(26,0);
        for(auto x:sentence)
        {
            v[x-'a'] = 1;
        }
        return accumulate(begin(v),end(v),0) == 26;
    }
};

int main(){
    string s="thequickbrownfoxjumpsoverthelazydog";
    cout<<checkIfPangram(s);
}