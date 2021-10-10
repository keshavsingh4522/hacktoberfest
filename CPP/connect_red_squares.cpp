#include "bits/stdc++.h"
#define int          long long int
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     9;
int n, m; vector<string> a;
set<vector<string>> s;
int ans;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ok(int x, int y) {
	return x > - 1 and y > - 1 and x < n and y < n;
}
void f(int m) {
	if (s.count(a)) {
		return;
	}
	s.insert(a);
	if (m == 0) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '.') {
				int has_red_surroundings = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					if (ok(x, y) and a[x][y] == '@')
						has_red_surroundings = 1;
				}
				if (has_red_surroundings) {
					a[i][j] = '@';
					f(m - 1);
					a[i][j] = '.';
				}
			}
		}
	}
}
void solve() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '.') {
				a[i][j] = '@';
				f(m - 1);
				a[i][j] = '.';
			}
		}
	}
	cout << ans;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}