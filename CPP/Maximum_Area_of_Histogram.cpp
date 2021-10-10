#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    stack<pair<int, int>> temp;
    vector<int> right;
    vector<int> left;
    for (int i = 0; i < n; i++)
    {
        if (temp.empty() == true)
        {
            right.push_back(-1);
        }
        else if (temp.top().first < heights[i])
        {
            right.push_back(temp.top().second);
        }
        else if (temp.top().first >= heights[i])
        {
            while (temp.empty() == false && temp.top().first >= heights[i])
            {
                temp.pop();
            }
            if (temp.empty() == true)
            {
                right.push_back(-1);
            }
            else
            {
                right.push_back(temp.top().second);
            }
        }
        temp.push({heights[i], i});
    }
    while (temp.empty() == false)
        temp.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        if (temp.empty() == true)
        {
            left.push_back(n);
        }
        else if (temp.top().first < heights[i])
        {
            left.push_back(temp.top().second);
        }
        else if (temp.top().first >= heights[i])
        {
            while (temp.empty() == false && temp.top().first >= heights[i])
            {
                temp.pop();
            }
            if (temp.empty() == true)
            {
                left.push_back(n);
            }
            else
            {
                left.push_back(temp.top().second);
            }
        }
        temp.push({heights[i], i});
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        right[i] = (left[n - i - 1] - right[i] - 1) * heights[i];
        res = max(res, right[i]);
    }
    return 0;
}
