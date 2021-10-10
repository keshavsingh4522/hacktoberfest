#include <iostream>
using namespace std;
int main() {
   int n;
   cin>>n;

   while(n>0)
   {
       int last_digit=(n&1);
       cout<<last_digit;
       n=n>>1;
   }
}
