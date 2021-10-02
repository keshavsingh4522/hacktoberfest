#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum=0;

	while(n!=0)
	{
		int rem=n%10;
		sum+=rem;
		n%=10;
	}
	return 0;
}