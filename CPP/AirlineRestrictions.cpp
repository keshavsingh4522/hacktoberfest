#include<iostream>

using namespace std;


int main(){

   int T,A,B,C,D,E;
  //cout<<"enter no of test cases"<<endl;
   cin>>T;

   while(T){
      // cout<<"enter the wieghts"<<endl;
       cin>>A>>B>>C>>D>>E;
       if((A+B)<=D && C<=E){
           cout<<"YES"<<endl;
       }
       else if((A+C)<=D && B<=E){
           cout<<"YES"<<endl;
       }
       else if((B+C)<=D && A<=E){
           cout<<"YES"<<endl;
       }
       else{
           cout<<"NO"<<endl;
       }
       T--;
   } 
   return 0;
}
