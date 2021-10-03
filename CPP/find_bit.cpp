#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int a;
    std::cout<<"Enter the number ";
    std::cin>>a;
    int i;
    std::cout<<"Enter the bit no. to check ";
    std::cin>>i;
    int mask =1<<i;
    int temp=0;
    temp= a&mask;
    if(temp!=0)
    {
	    std:: cout<<"The bit at position "<<i<<" is: ";
	    std::cout<<"1";
    }
    else
    {
	    std::cout<<"The bit at position "<<i<<" is: ";
	    std::cout<<"0";
    }
}

