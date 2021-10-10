#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar + n);
    ll mid = ar[n / 2];

    ll tot = 0;
    for (int i = 0; i < n; i++)
        tot += abs(ar[i] - mid);

    cout << 1LL * tot << endl;
}