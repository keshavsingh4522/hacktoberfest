#include<stdio.h>
#include<iostream>
int main()
{
	int a;
	int b;

        std::cout<<"Enter the first number"<<std::endl;
	std::cin>>a;

        std::cout<<"Enter the second number to make it first no."<<std::endl;
	std::cin>>b;

	int count=0;

	int temp;
	temp = a^b;
	while(temp!=0)
	{
		temp=temp&(temp-1);
		count++;
	}
	std::cout<<"The number bit change required for converting a to b is"<<std::endl;
	std::cout<<count;
	std::cout<<std::endl;	
	return 0;
}


