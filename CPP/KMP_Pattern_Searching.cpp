/* This program prints the number of times given pattern occurs in a string in O(n) using KMP */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(int i = 0; i < x; i++)
#define For(x,y) for(int i = x; i <= y; i++)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define pb push_back
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
const int mx = 1e6;
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    string p,s;
    cin>>p>>s;
    int n = s.length(), m = p.length(), ans = 0;
    int lps[m] = {0};   // An array of longest prefix count for each index
    for(int i = 1; i < m; i++)   // Calculating longest proper prefix which is also a suffix
    {
        int j = lps[i-1];
        while(j > 0 && p[i] != p[j])
        j = lps[j-1];
        if(p[i] == p[j])
        ++j;
        lps[i] = j;
    }
    int j = 0;
    for(int i = 0; i <= (n-m); i++)
    {
        int q = i;
        for(; j < m; j++)
        {
            if(p[j] == s[i])
            ++i;
            else
            break;
        }
        if(j == m) // Pattern Matches
        {
            ++ans;
            i = q;
        }
        else
        {
            if(j == 0) // If first character itself don't match
            continue;
            --i;      // Start matching again at mismatch character
        }
        j = lps[j-1];
    }
    cout<<ans<<endl;
}