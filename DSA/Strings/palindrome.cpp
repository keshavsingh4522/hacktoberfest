/*
   Function to check if a string is palindrom or not
   Time Complexity - O(N)
   Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string s="abacdffghgffdcaba";  //check on sample string.
    
    for(int i=0; i<s.length()/2; i++) 
    {
        if(s[i] != s[s.length()-i-1]) 
        {
            cout << "not a palindrome";
            return 0;
        }
    }
    cout << "palindrome";
    
    return 0;

}
