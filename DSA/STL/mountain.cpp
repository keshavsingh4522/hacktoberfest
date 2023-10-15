#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int largest=0;

    for(int i=1;i<=n-2;)
    {
        //condition for peaks
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
           //backward traversal
           int j=i,cnt=1;
           while(j>=1 and a[j]>a[j-1])
           {
               cnt++;
               j--;
           }

           //forward traversal
           while(a[i]>a[i+1] and i<=n-2)
           {
               cnt++;
               i++;
           }
           largest=max(largest,cnt);
        }
        else
            i++;
    }
    
    cout<<largest;
}
