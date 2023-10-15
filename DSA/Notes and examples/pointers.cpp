#include<iostream>
using namespace std;
int main()
{
	int a=5;
	int *ptr;
	ptr=&a;
	cout<<"address of variable="<<ptr;
	cout<<"\nvalue="<<*ptr;
	cout<<"\naddress of pointer="<<&ptr;
	return 0;
}

