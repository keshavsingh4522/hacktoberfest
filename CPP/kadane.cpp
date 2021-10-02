#include<bits/stdc++.h>

using namespace std;

int kadane(vector <int> a) {
    int max_current = a[0];
    int max_global = a[0];
    for (int i = 1; i < a.size(); i++) {
        max_current = max(a[i], max_current + a[i]);
        if(max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}

int main() {
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << kadane(a);
    return 0;
}
