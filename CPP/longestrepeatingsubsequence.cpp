#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int m, int n)
{
	int t[m + 1][n + 1];
	for (int i = 0; i <= n; i++)
		t[0][i] = 0;
	for (int i = 0; i <= m; i++)
		t[i][0] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1] && i != j)
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	return t[m][n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string x;
		cin >> x;
		cout << lcs(x, x, x.length(), x.length()) << "\n";
	}
	return 0;
}