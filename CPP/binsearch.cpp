
//Program finds only the integer part of square root of a number

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int squarerootofnum(int n)
{
    int lo=1,hi=(n/2);
    int target,val;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(mid*mid<=n)
        {
            val = mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return val;
}
int main() {
	
	int n;
    cout<<"Enter the number: ";
	cin>>n;
    cout<<"\nThe integer part of square root of a number is: "<<squarerootofnum(n)<<endl;
    
	return 0;
}
