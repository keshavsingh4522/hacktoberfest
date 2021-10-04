/* A C++ program of a  calculator for simple arithmetic operators (+, -,
*, /). The program should take two operands from user and perform the
operation on those two operands depending upon the operator entered by
user. */
#include<iostream>
using namespace std;
int main(){
	cout<<"\nWelcome to Calculator.\n Please enter data in the following format:-\n"; 
	cout<<"(number1)(space)(operator)(space)(number2) \n";
	float number1,number2,number3;
	char op,a;	
	do{
		cin>>number1>>op>>number2;
		switch(op){
			case '+':
				number3=number1+number2;
				break;
			case '-':
				number3=number1-number2;
				break;
			case '*':
				number3=number1*number2;
				break;
			case '/':
				if(number2==0)
				{cout<<"Numbers invalid for operation, please try again.";
				break;}
				else
				{number3=number1/number2;
				break;}
			default:
				cout<<"Operator not recognised. Please try again.";
			}
		cout<<"Answer: \t"<<number3<<endl;
		cout<<"Do you want to try again?(y/n)\n";
		cin>>a;
	}while(a=='y');
	return 0;
}
