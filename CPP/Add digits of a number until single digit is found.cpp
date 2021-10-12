#include <iostream>
using namespace std;
int singledigit(int);
int main(){
	int n;
	cin>>n;
	int result= singledigit(n);
	cout<<result;
	
	return 0;
}
int singledigit(int n){
	int b,sum=0;
		while(n>0){
			
	b=n%10;
	n=n/10;
	sum=sum+b;
	}
	if(sum%10==sum){
		return sum;
	}
	else{
		singledigit(sum);
	}
	}
