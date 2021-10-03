// Print the following pattern for the given N number of rows.
// Pattern for N = 4
// 1
// 22
// 333
// 4444
#include<iostream>
using namespace std;


int main(){

   int n;
   cin>>n;
   int i,j;
   
   
   
  for(i=1;i<=n;i++){
      for(j=1;j<=i;j++){
          cout<<i;
      }
      cout<<endl;
  }
}
