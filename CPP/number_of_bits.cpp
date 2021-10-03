#include<stdio.h>
#include<iostream>

int main()
{
	unsigned int a;
	std::cout<<"Enter the Value ";
	std::cin>>a;
	unsigned int temp=a;

	int count=0;
	while(a!=0)
	{
		a=a&(a-1);
		count++;
	}
	
	std::cout<<"The number "<<temp<<" contains "<<count<<" bits!";
	std::cout<<std::endl;
	
	return 0;
}
