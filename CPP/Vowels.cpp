#include<iostream>
#include<string>
using namespace std;
 
int main()
{
int count=0;
string s="How many are words";
for (int i=0;s[i]!='\0';i++){
if (s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i'){
    count++;
}
}
cout<<count;
}
