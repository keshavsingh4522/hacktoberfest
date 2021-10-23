//August Challenge 2021
//OLYRANK 

#include <iostream>
using namespace std;


int main(){
    int t;
    cin>> t;
    int a,b,c,d,e,f;
    while(t--){
       cin>>a>>b>>c>>d>>e>>f;
       
       if((a+b+c)>(d+e+f)){
           cout<<"1"<<endl;
       }
       else
            cout<<"2"<<endl;
    }
    return 0;
}