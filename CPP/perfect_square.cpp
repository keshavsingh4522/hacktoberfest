// CPP program to find if x is a
// perfect square.
#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long double x)
{
	// Find floating point value of
	// square root of x.
	if (x >= 0) {

		long long sr = sqrt(x);
		
		// if product of square root
		//is equal, then
		// return T/F
		return (sr * sr == x);
	}
	// else return false if n<0
	return false;
}

int main()
{
	long long x = 2502;
	if (isPerfectSquare(x))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
