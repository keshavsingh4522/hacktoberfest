// Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.

#include <bits/stdc++.h>
using namespace std;

void inti_code() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

unordered_map<char, int> symbols = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};

bool isValid(string str) {
	stack<char> st;

	for (char ch : str)
	{
		if (symbols[ch] < 0)
			st.push(ch);
		else {
			if (st.empty()) return false;

			char top = st.top();
			st.pop();
			if (symbols[top] + symbols[ch] != 0)
				return false;
		}
	}
	return st.empty();
}

int main()
{
	inti_code();

	string str;

	cin >> str;

	cout << (isValid(str) ? "Valid" : "Invalid");

	return 0;
}
