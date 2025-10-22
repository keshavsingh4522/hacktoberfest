//a<<b=a*2^b
//a>>b=a/2^b

#include <iostream>
using namespace std;

bool isOdd(int n)
{
	//AND operator
    return(n&1);
}

//find nth bit
int findBit(int n,int i)
{
    int mask=(1<<i);
    int bit;
    if((n&mask)>0)
    bit=1;
    else
    bit=0;
    return bit;
}

//clearing ith bit
void clearBit(int n, int i)
{
	int mask= ~(1<<i);
	n=n&mask;
}


int main() {
    //last bit digit of 5 is 1 so it is odd
    int n=5,i;
    cin>>i;
    if(isOdd)
    cout<<"odd";
    else
    cout<<"even";
    cout<<endl;
    cout<<findBit(n,i);
    cout<<endl;
    clearBit(n,i);
    cout<<n;
}

