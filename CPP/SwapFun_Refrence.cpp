//through allias

#include<iostream>
using namespace std;
 
void swap(int &x,int &y){
int temp;
temp=x;
x=y;
y=temp;
}

int main()
{
 int a,b;
 cout<<"Program to Swap 2 number using REfrence"<<endl;
 cout<<"Enter 2 numbers : ";
 cin>>a;
 cout<<endl;
 cout<<"2ND Numnber :  ";
 cin>>b;
 cout<<"Initial setting :("<<a<<", "<<b<<")";
 swap(a,b);
 cout<<endl<<"After using Refrence :("<<a<<", "<<b<<")"<<endl;

}