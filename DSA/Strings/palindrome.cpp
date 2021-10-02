#include <bits/stdc++.h>
using namespace std;
int main() {
   string s="aba";
   string str;

   for(int i=s.size()-1;i>=0;i--)
   str.push_back(s[i]);

  if(str==s)
  cout<<"palindrome";
  else
  cout<<"not a palindrome";

}
