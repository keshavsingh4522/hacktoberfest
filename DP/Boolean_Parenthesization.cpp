#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int BooleanParenthesization(string &s, int i, int j, bool isTrue){
	if(i > j)
		return false;
	if(i == j){
		if(isTrue == true)
			return s[i] == 'T';
		else
			return s[i] == 'F';
	}

	int ans = 0;
	for(int k=i+1; k<=j-1; k+=2){
		int lT = BooleanParenthesization(s, i, k-1, true);
		int lF = BooleanParenthesization(s, i, k-1, false);
		int rT = BooleanParenthesization(s, k+1, j, true);
		int rF = BooleanParenthesization(s, k+1, j, false);

		if(s[k] == '&'){
			if(isTrue == true)
				ans += lT*rT;
			else
				ans += (lT*rF + lF*rT + lF*lF);
		}
		else if(s[k] == '|'){
			if(isTrue == true)
				ans += (lT*rT + lT*rF + lF*rT);
			else
				ans += lF*rF;
		}
		else if(s[k] == '^'){
			if(isTrue == true)
				ans += (lT*rF + lF*rT);
			else
				ans += (lT*rT + lF*rF);
		}
	}
	return ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string s = "T^F&T"; // o/p: 3
	// s = "T|T&F^T"; // o/p: 4
	// s = "T|T&F^T"; // o/p: 4
	// s = "T^F|F"; // o/p: 2
	cout<<BooleanParenthesization(s, 0, s.size()-1, true);
}