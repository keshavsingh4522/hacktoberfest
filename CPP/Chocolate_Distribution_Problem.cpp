// Chocolate Distribution Problem

#include <bits/stdc++.h>
using namespace std;

void inti_code() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

long long findMinDiff(vector<long long> a, long long n, long long m) {
	sort(a.begin(), a.end());

	int min_diff = INT_MAX;

	for (int i = 0; i <= n - m; ++i) {
		int diff = a[i + m - 1] - a[i];
		min_diff = min(min_diff, diff);
	}

	return min_diff;
}

int main() {
	inti_code();

	int n; cin >> n;

	int m; cin >> m;

	vector<long long> v;

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		v.push_back(x);
	}

	cout << findMinDiff(v, n, m);

	return 0;
}
