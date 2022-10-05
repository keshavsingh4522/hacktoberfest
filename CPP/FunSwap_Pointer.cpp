//First we take 2 numbers a and b in main function , then take pointer x and pointer y as parmeters(*x *y)
//we then use refrence(&) sign in main fn. to give address as value for swap fn  
//Pointer x stores the address of a and Pointer y stores address of b , Pointers are meant to point they store
// address values (&a and &b) When we use *x or *b they give the actual value of the thing they point at 
// hence *x= actual value of a and *y= actual value this is created inside the heap , when we start assigning
//the address at which pointers are pointing gets interchanged hence the swap


#include<iostream>
using namespace std;
 
void swap(int *x,int *y){
int temp;
temp=*x;
*x=*y;
*y=temp;
}

int main()
{
 int a,b;
 cout<<"Program to Swap 2 number using Pointer Or Address "<<endl;
 cout<<"Enter 2 numbers : ";
 cin>>a;
 cout<<"2nd Numnber :  ";
 cin>>b;
 cout<<"Initial setting :("<<a<<", "<<b<<")";
 swap(&a,&b);
 cout<<endl<<"After using Refrence :("<<a<<", "<<b<<")"<<endl;

}