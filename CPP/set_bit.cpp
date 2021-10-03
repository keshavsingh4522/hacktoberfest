#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int a;
	int i;

	std::cout<<"Enter the number ";
	std::cin>>a;

	std::cout<<"Enter the bit number to set ";
	std::cin>>i;
        
	int mask;
	mask= 1<<i;

	int temp;

	temp=a|mask;

	std::cout<<"The number after setting bit "<<i<<" is:"<<temp<<std::endl;

}
