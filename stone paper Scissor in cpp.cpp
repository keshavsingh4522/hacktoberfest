#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string gameResult (string s)
        {
            //string str;
                if(s[0]==s[1])
                    return "DRAW";
                else if(s[0]=='R' && s[1]=='S')
                     return "A";
                
                else if(s[0]=='S' && s[1]=='R')
                     return "B";
                
                else if(s[0]=='S' && s[1]=='P')
                    return "A";
               
                else if(s[0]=='P' && s[1]=='S')
                     return "B";
                
                else if(s[0]=='P' && s[1]=='R')
                    return "A";
                
                else if(s[0]=='R' && s[1]=='P')
                     return "B";
                
                
        }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.gameResult (s) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
