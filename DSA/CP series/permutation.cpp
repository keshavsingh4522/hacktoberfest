#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define unique(v) v.erase(std::unique(v.begin(), v.end()), v.end());
// #define INP/OUT freopen(
// , 
// , stdin); freopen(
// , 
// , stdout);

long long   gcd(long long  a, long long  b)
{
if (b == 0)
return a;
return gcd(b, a % b);
}
long long   lcm(long long  a, long long  b)
{
return (a / gcd(a, b)) * b;
}






int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    ll num  = (n*(n+1))/2;
     if(n==1){
        cout<<1<<endl;
    }
    else if(num%n == 0){
        cout<<-1<<endl;
    }
    else{
        int i = n-1;
        cout<<n<<" ";
        while(i>1){
            
            cout<<i<<" "<<n-i+1<<" ";
            
            i-=2;
        }
        cout<<1<<endl;

        // cout<<endl;

    }
}
 return 0;
}
