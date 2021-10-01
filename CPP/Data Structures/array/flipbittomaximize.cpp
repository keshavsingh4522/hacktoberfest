// You are using GCC
#include <bits/stdc++.h>
using namespace std;

vector<int> tobinary(int n)
{
    vector<int> binary;
    while (n > 0)
    {
        binary.push_back(n % 2);
        n /= 2;
    }
    return binary;
}
int result(int n)
{
    vector<int> binary = tobinary(n);
    vector<int> dummy;
    int count = 0;
    for (int x : binary)
        if (x == 0)
        {
            dummy.push_back(count);
            count = 0;
        }
        else
            count++;
    int out = 0;
    for (int i = 0; i < dummy.size() - 1; i++)
    {
        if (dummy[i] + dummy[i + 1] > out)
        {
            out = dummy[i] + dummy[i + 1];
        }
    }
    return out + 1;
}
int main()
{
    int n;
    cin >> n;
    cout << "output:" << result(n);
}