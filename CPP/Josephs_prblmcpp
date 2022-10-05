#include <iostream>
using namespace std;

int jos(int n, int k){
if(n==1) return 0;
else{
 return (jos(n-1,k)+k)%n;
}
}
// LOGIC IS WHEN U MAKE A STACK FN CALL AGAIN IT REPATS TH EVALUE THAT HAS BEEN ALREADY DELETD IN PREVIOUS
//CALL HENCE MAKE A GENERAL CASE AND THEN COMPARE IT HERE +K AND MOD N HAS BEEN DONE THROUGH COMPARING RESULTS


int main(){
int n=5,k=3;
cout<<jos(n,k);


}