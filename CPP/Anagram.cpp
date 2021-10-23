//A code is to check whether two strings are anagram of each other or not.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
//Function
bool isAnagram(string a, string b)
    {
        int t[26] = {0};
        int i = 0;
        int len1 = a.length(), len2 = b.length();
        if (len1 != len2)
            return 0;
        for (i = 0; i < len1; i++)
        {
            t[a[i] - 97]++;
        }
        for (i = 0; i < len1; i++)
        {
            t[b[i] - 97]--;
            if (t[b[i] - 97] == -1)
                return 0;
        }
        return 1;
    }
};
//Driver Code
int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
