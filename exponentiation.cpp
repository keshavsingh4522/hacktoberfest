/* Iterative Function to calculate (x^y)%p in O(log y) */
#include <iostream>
using namespace std;

int power(int x, int y, int p)
{

	// Initialize answer
	int res = 1;

	// Check till the number becomes zero
	while (y > 0) {

		// If y is odd, multiply x with result
		if (y % 2 == 1)
			res = (res * x);

		// y = y/2
		y = y >> 1;

		// Change x to x^2
		x = (x * x);
	}
	return res % p;
}

int main()
{
	int x = 2;
	int y = 5;
	int p = 13;
	cout << "Power is " << power(x, y, p);
	return 0;
}

// This code is contributed by yaswanth0412
