#include<stdio.h>
#include<iostream>
int main()
{       
 int n;
 std::cout<<"enter the number"<<std::endl;
 std::cin>>n;
 int fact=1;
 for(int i=1;i<=n;i++)
 {
         fact= fact*i;
 }       
 

 std::cout<<"Factorial of number "<<n<<" is "<<fact<<std::endl;
 return 0; 
}
