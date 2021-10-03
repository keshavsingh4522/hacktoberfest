#include<stdio.h>
#include<iostream>
using namespace std;
int  main()
{

int a;
std::cout<<"Enter the Value ";
std::cin>>a;

int n;
std::cout<<"Enter the number of times to shift ";
std::cin>>n;

int choice;
std::cout<<"Enter the operation to perform "<<endl;
std::cout<<"1.Right Shift "<<endl;
std::cout<<"2.Left Shift "<<endl;
std::cin>>choice;

switch(choice)
{
	case 1: 
		a=a>>n;
		std::cout<<"Value of number after "<<n<<" right shifts "<<a;
		std::cout<<endl;
		break;
	case 2: 
		a=a<<n;
		std::cout<<"Value of number after "<<n<<" left shift "<<a;
		std::cout<<endl;
		break;
	default:
		std::cout<<"INVALID INPUT"<<endl;
		break;
}


return 0;
}
