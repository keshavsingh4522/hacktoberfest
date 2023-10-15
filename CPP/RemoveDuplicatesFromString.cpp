#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str1[], int n)
{
int index = 0;
	

for (int i=0; i<n; i++) {
		

	int j;
	for (j=0; j<i; j++)
		if (str[i] == str[j])
		break;

	if (j == i)
		str[index++] = str[i];
}
	
return str;
}


int main()
{
string str1;
cin>>str1;
int n = str1.size();
cout << removeDuplicate(str1, n);
return 0;
}
