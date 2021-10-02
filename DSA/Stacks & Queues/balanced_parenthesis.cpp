#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool isBalanced(string input){

	stack<char> s;
	for(auto ch : input){

		switch(ch){
			case '(':
			case '[':
			case '{': s.push(ch);
						break;

			case ')': if(!s.empty() and s.top()=='('){
						s.pop();
					  }
					  else{
					  	return false;
					  }
					  break;

			case ']': if(!s.empty() and s.top()=='['){
						s.pop();
					  }
					  else{
					  	return false;
					  }
					  break;

			case '}': if(!s.empty() and s.top()=='{'){
						s.pop();
					  }
					  else{
					  	return false;
					  }
					  break;
			default : continue;	  
		}
	}

	if(s.empty()==true){
		return true;
	}
	return false;
}



int main(){
	string s = "{ a + (b+c) + ([d+e]*f)) } + k`";//{ a + (b+c) + ([d+e]*f)) } + k";

	if(isBalanced(s)){
		cout<<"Balanced!"<<endl;
	}
	else{
		cout<<"Not Balanced "<<endl;

	}
return 0;
}