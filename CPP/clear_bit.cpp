#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
 int a;
 std::cout<<"Enter the number"<<std::endl;
 std::cin>>a;

 int i;
 std::cout<<"Enter the bit number to be cleared"<<std::endl;
 std::cin>>i;

 int mask;
 mask=1<<i;
 mask=~mask;

 int temp;
 temp=a&mask;

 std::cout<<"Number obtained after clearing bit at given position "<<i<<" of "<<a<<" is "<<temp<<std::endl;
}


