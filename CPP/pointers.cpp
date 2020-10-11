#include<iostream>
using namespace std;
int main()
{

	int a,b,*p1,*p2;
	a= 10;
	b= 20;
	p1=&a;
	p2=&b;
	cout<<"the addresses of variables a and b are "<<" "<<p1<<" "<<p2<<endl;
	cout<<"the values stored in a nd b are"<<" "<<a<<" "<<b<<endl;
	*p1=*p2;
	*p2=8;
        cout<<"new values of a and b are"<<" "<<a<<" "<<b<<endl;
return 0;
}
