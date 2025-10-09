#include<bits/stdc++.h>
using namespace std;

int mindiffsubset(int set[], int n, int sum)
{
	bool subset[n + 1][sum + 1];
	for (int i = 0; i <= sum; i++)
		subset[0][i] = false;
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (set[i - 1] > j)
				subset[i][j] = subset[i - 1][j];
			else
				subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
		}
	}
	vector<int> v;
	for (int i = n; i <= n; i++)
	{
		for (int j = 0; j <= sum / 2; j++)
		{
			if (subset[i][j] == true)
				v.push_back(j);
		}
	}
	int mn = INT_MAX;
	for (int i = 0; i < v.size(); i++)
	{
		mn = min(mn, sum - 2 * v[i]);
	}
	return mn;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int set[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> set[i];
		sum = sum + set[i];
	}
	cout << mindiffsubset(set, n, sum);
	return 0;
}