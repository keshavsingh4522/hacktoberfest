#include<bits/stdc++.h>
using namespace std;
// sieve of eratosthenes
  void sieveOfEratosthenes(int n){
        bool arr[n+1]={};     
          for(int i=2;i*i<=n;i++){
            if(arr[i]==false){
             
            for(int j = i*i ; j<=n;j+=i)
              arr[j] = true;
            }
          }
          
          for(int i=2;i<=n;i++){if(arr[i]==false) cout<<i<<" ";}
  }
int main(){
   int n;
      cout<<"enter n ";
        cin>>n;
        cout<<"all the prime numbers less than or equal to "<<n<<" are: \n";    
        sieveOfEratosthenes(n);
  return 0;
}
