#include <iostream>
using namespace std;

int main() {
int x=0,t,i;
cin>>t;
while(t--){
    cin>>i;
    if(i>0){
      if (x>=0){
         x=x-i;
         cout<<x<<endl;
}
      else{
         x=x+i;
         cout<<x<<endl; }
         
}
    else{
        if(i>0){
      if (x>=0){
         x=x+i;
         cout<<x<<endl;
}
      else{
         x=x-i;
         cout<<x<<endl; }
    }
    
}
}
}
