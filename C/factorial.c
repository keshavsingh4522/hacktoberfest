#include<stdio.h>
int fact(int n)
{
 if(n<=1)
  return 1;
 else if(n==2)
  return n;
 else
  return n*fact(n-1);
}
int main()    
{    
 int i,number;    
 printf("Enter a number: ");    
 scanf("%d",&number);  
 printf("Factorial of %d is: %d",number,fact(number));    
return 0;  
}
