// C++ code to demonstrate printing pattern of alphabets
#include <iostream>
using namespace std;

void contalpha(int n)
{
	int i = 1, j = 0;
	int num = 65;
	char alpha = char(num);
	while (i <= n) {
		while (j <= i - 1) {
			cout << alpha << " ";
			alpha++;
			j++;
		}
		j = 0;
		i++;
		cout << endl;
	}
}

int main()
{
	int n = 5;
	contalpha(n);
	return 0;
}