#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output)
{
	
	if (input.empty()) {
		cout << output << endl;
		return;
	}

	// output is passed with including
	// the Ist characther of
	// Input string
	printSubsequence(input.substr(1), output + input[0]);

	// output is passed without
	// including the Ist character
	// of Input string
	printSubsequence(input.substr(1), output);
}

int main()
{

	string output = "";
	string input = "abcd";

	printSubsequence(input, output);

	return 0;
}
