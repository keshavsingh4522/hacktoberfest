#include <bits/stdc++.h>
using namespace std;
int main() {
   string s="avengers";
   string str="vers";

    //using 2 pointer method
    int i=s.length()-1;
    int j=str.length()-1;

    while(i<=0 and j<=0)
    {
        if(s[i]==s[j])
        {
            i--;
            j--;
        }
        else
        i--;
    }

    if(j==-1)
    cout<<"yes";
    else
    cout<<"no";
}
