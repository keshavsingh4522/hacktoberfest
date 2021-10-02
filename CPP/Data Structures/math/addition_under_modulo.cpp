//https://practice.geeksforgeeks.org/problems/addition-under-modulo/1/?track=ppc-mathematics&batchId=221

#include<bits/stdc++.h>
using namespace std;
long long sumUnderModulo(long long a,long long b)
{
    // code here
    long long m=10e9+7;
    return  (( a % m ) + ( b % m )) % m;
    
}

// { Driver Code Starts.
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    cout<<sumUnderModulo(a,b)<<endl;
	}
	return 0;
}  // } Driver Code Ends