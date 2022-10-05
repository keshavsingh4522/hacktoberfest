#include <iostream>
using namespace std;

void sumsubset( string  s, string curr=" ", int i=0){
    if(i==s.length()){
        cout<<curr<<endl;
        return;
    }
    sumsubset(s,curr,i+1);
    sumsubset(s,curr+s[i],i+1);
}


int main(){
string s="abc";
int n=3;
sumsubset(s);
}