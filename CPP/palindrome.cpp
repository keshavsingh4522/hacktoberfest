#include<stdio.h>
#include<iostream>
using namespace std;
int main()

{ 
	int n;
	int rev=0;
	int rem=0;
	int temp;
	std::cout<<"Enter the number"<<std::endl;
	std::cin>>n;
	temp=n;
	while(n!=0)
	{
	  rem=n%10;
	  rev = rev*10+rem;
	  n=n/10;
	}
        
	if(temp==rev)
	{ 
		std::cout<<"The number is palindrome"<<std::endl;


	}
	else
		{
			std::cout<<"The number is not plaindrome"<<std::endl;
		}

	return 0;



}

