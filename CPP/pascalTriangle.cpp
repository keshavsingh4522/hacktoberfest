#include<iostream>
using namespace std;

int main()
{
    int n; // last level
    cin >> n;
    int arr[n][n];
    for (int line = 0; line < n; ++line)
    {
        for(int space = 0; space <= n - line; ++space) cout << " ";
        for (int i = 0; i <= line; i++)
        {
            if (line == i || i == 0)
                arr[line][i] = 1;
            else
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];

            cout << arr[line][i] << " ";
        }
        cout << "\n";
    }
}