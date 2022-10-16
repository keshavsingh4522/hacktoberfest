// CPP program to illustrate
// auto-initializing of pair STL
#include <iostream>
#include <utility>

using namespace std;

int main()
{
	pair<int, double> PAIR1;
	pair<string, char> PAIR2;

	// it is initialised to 0
	cout << PAIR1.first;

	// it is initialised to 0
	cout << PAIR1.second;

	cout << " ";

	// // it prints nothing i.e NULL
	cout << PAIR2.first;
	
	// it prints nothing i.e NULL
	cout << PAIR2.second;

	return 0;
}
