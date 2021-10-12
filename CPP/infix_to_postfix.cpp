#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
 if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
 {
 return true;
 }
 else
 {
 return false;
 }
}
 
int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
string InfixtoPostfix(stack <char> stack, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		
		if((infix[i] >= 'a' && infix[i] <= 'z')
 		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix += infix[i];
		}
		else if(infix[i] == '(')
		{
			stack.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((stack.top()!='(') && (!stack.empty()))
			{
				char temp=stack.top();
				postfix += temp;
				stack.pop();
			}
			if(stack.top() == '(')
			{
				stack.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			if(stack.empty())
			{
				stack.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(stack.top()))
 				{
 					stack.push(infix[i]);
 				} 
 				else if((precedence(infix[i])==precedence(stack.top())) && (infix[i]=='^'))
 				{
 					stack.push(infix[i]);
				}
 				else
 				{
 					while((!stack.empty()) && (precedence(infix[i])<=precedence(stack.top())))
 					{
 						char temp = stack.top();
						postfix+= temp;
 						stack.pop();
 					}
 					stack.push(infix[i]);
 				}	
			}
		}
	}
	while(!stack.empty())
 	{
 		postfix+=stack.top();
 		stack.pop();
 	}
 
 return postfix;
}

int main()
{
	string infix_exp,postfix_exp;
	cout<<"\n Enter a Infix Expression : ";
	cin>>infix_exp;
	stack <char> stack;
	postfix_exp= InfixtoPostfix(stack,infix_exp);
	cout<<"\n Postfix Expression is : "<<postfix_exp;
	return 0;
	
}
