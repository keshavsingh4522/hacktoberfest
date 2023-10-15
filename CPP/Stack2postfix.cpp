//@sidhartha8011
//Cpp code to convert a postfix expression

#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int main()
{
	char ch[100];
	int i,op1,op2;
	stack<int> s;
	cout << "enter the postfix expression : ";
	gets(ch);
	for(i=0;ch[i]!='\0';i++)
		if(isdigit(ch[i]))
			s.push(ch[i]-'0');
		else
		{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			switch (ch[i])
			{
			case '+': s.push(op1+op2);break;
			case '-': s.push(op1-op2);break;
			case '*': s.push(op1*op2);break;
			case '/': s.push(op1/op2);break;
			default:
				break;
			}
		}
	cout << "after evaluating :" << s.top();
	return 0;


}