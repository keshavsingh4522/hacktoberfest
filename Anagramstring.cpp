#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool isAnagram(string a, string b){
        int h1[26] = {0},h2[26] = {0};
        for(char it : a)
          h1[it - 'a']++;
        for(char it : b)
          h2[it - 'a']++;

        for(int i=0; i<26; i++)
            if(h1[i] != h2[i])
                return false;

        return true; 
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        string c, d;
        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
