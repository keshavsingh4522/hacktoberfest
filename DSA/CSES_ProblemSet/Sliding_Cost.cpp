#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> leftSet, rightSet;
    ll leftSum = 0, rightSum = 0;
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << 0 << " ";
        return 0;
    }

    if (k == 2)
    {
        for (int i = 1; i < n; i++)
            cout << abs(val[i] - val[i - 1]) << " ";
        return 0;
    }

    vector<pair<int, int>> st;
    for (int i = 0; i < k; i++)
        st.push_back({val[i], i});

    sort(st.begin(), st.end());

    for (int i = 0; i < k / 2 + (k % 2); i++)
    {
        leftSet.insert(st[i]);
        leftSum += st[i].first;
    }

    for (int i = k / 2 + (k % 2); i < k; i++)
    {
        rightSet.insert(st[i]);
        rightSum += st[i].first;
    }

    ll median = leftSet.rbegin()->first;

    cout << median * leftSet.size() - leftSum +
                rightSum - median * rightSet.size()
         << " ";

    for (int i = 1; i < n - k + 1; i++)
    {
        if (leftSet.count({val[i - 1], i - 1}))
        {
            leftSum -= val[i - 1];
            leftSet.erase({val[i - 1], i - 1});
        }
        else
        {
            rightSum -= val[i - 1];
            rightSet.erase({val[i - 1], i - 1});
        }

        if ((*leftSet.rbegin()) < make_pair(val[k - 1 + i], k - 1 + i))
        {
            rightSet.insert({val[k - 1 + i], k - 1 + i});
            rightSum += val[k - 1 + i];
        }
        else
        {
            leftSet.insert({val[k - 1 + i], k - 1 + i});
            leftSum += val[k - 1 + i];
        }

        while (leftSet.size() < k / 2 + (k % 2))
        {
            auto rightExtra = *rightSet.begin();
            rightSet.erase(rightExtra);
            rightSum -= rightExtra.first;
            leftSum += rightExtra.first;
            leftSet.insert(rightExtra);
        }

        while (leftSet.size() > k / 2 + (k % 2))
        {
            auto leftExtra = *leftSet.rbegin();
            leftSet.erase(leftExtra);
            leftSum -= leftExtra.first;
            rightSum += leftExtra.first;
            rightSet.insert(leftExtra);
        }

        median = leftSet.rbegin()->first;
        cout << median * leftSet.size() - leftSum +
                    rightSum - median * rightSet.size()
             << " ";
    }
}