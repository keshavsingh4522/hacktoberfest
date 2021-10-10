#include <bits/stdc++.h>
using namespace std;
int main() {
   
   string s1,s2;
   cin>>s1;

   for(int i=s1.size()-1;i>=0;i--)
   s2.push_back(s1[i]);

   if(s1==s2)
   cout<<"palindrome";
   else
   cout<<"no";
}
