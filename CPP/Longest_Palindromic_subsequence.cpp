
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

// Returns the length of the longest palindromic subsequence in seq
int lps(string seq, int i, int j)
{

    if (i == j)
        return 1;

    if (seq[i] == seq[j] && i + 1 == j)
        return 2;

    if (seq[i] == seq[j])
        return lps(seq, i + 1, j - 1) + 2;

    return max(lps(seq, i, j - 1), lps(seq, i + 1, j));
}

int main()
{
    string str;
    cout << "Enter the string : ";
    cin >> str;
    int n = str.size();
    cout << "The length of the Longest Palindromic Subsequence is " << lps(str, 0, n - 1);
    return 0;
}
