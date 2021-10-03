#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

int n;
int res=0;
int i;
std::cout<<"Enter the number to check "<<std::endl;
std::cin>>n;
for ( i=5; i<=n;i=i*5)
{
  res= res + n/i;
}

std::cout<<"The trailing zeroes are "<<res<<std::endl;

}

