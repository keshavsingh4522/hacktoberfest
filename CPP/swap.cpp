#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

	int a;
	std::cout<<"Enter the value of a "<<std::endl;
	std::cin>>a;

	int b;
	std::cout<<"Enter the value of b "<<std::endl;
	std::cin>>b;

	std::cout<<"Value of a before swapping "<<a<<std::endl;
	std::cout<<"Value of b before swapping "<<b<<std::endl;
         
/*swapping numbers using xor*/
	a= a^b;
	b= a^b;
	a= a^b;
        cout<<"__________________________________________________"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Value of a after swapping "<<a<<std::endl;
	std::cout<<"Value of b after swapping "<<b<<std::endl;

        return 0;
	
}
