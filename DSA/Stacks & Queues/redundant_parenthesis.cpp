#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkRedundant(string str){
	
	stack<char> s;

	for(char ch : str){
		if(ch!=')'){
			s.push(ch); // a,b, + , - , ( ....
		}
		else{
			// ')'
			bool operator_found = false;

			while(!s.empty() and s.top()!='('){
				char top = s.top();
				if(top=='+' or top=='-' or top=='*' or top=='/'){
					operator_found = true;
				}
				s.pop();
			}
			s.pop(); //pop the opening bracked after the loop if over

			if(operator_found == false){
				return true;
			}
		}
	}
	return false;
}


int main() {
    string str = "((a+b)+c) + ((d*e))";
    if(checkRedundant(str)){
        cout<<"Contains Redundant Parenthesis";
    }
    else{
        cout<<"r";
    }
    return 0;
}