#include<stdio.h>
// recursive code to create binary equivalent of a inputed number.

void func(int n){
    if(n==0)
    return;
    func(n/2);
      printf("%d",n%2);
}

int main(){
     int n;
       scanf("%d",&n);
         func(n); 
  return 0;
}
