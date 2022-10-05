#include<iostream>
#include <string>
using namespace std;

void replacestring(string s){
if(s.length()==0) return;

if(s[0]=='p' && s[1]=='i'){
    cout<<"3.14";
    replacestring(s.substr(2));
}
else{
    cout<<s[0];
    replacestring(s.substr(1));
}
}


int main(){
replacestring("pipppppipippppi");
}