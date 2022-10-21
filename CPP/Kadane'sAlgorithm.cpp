#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr, int n)
{
    int res = INT_MIN;

    int temp = 0;

    for(int i = 0; i < n; i++)
    {
        temp += arr[i];
        res = max(res, temp);

        if(temp < 0)
        temp = 0;
    }

    return res;
}

int main()
{
    vector<int> arr;

    int n;

    cout << "Enter the size of array" << endl;
    cin >> n;

    cout << endl;
    cout << "Enter the elements of array" << endl;

    int temp;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;

        arr.push_back(temp);
    }

    cout << endl;
    cout << "Largest sum of contiguous subarray possible: " << kadane(arr, n) << endl;

    return 0;
}
