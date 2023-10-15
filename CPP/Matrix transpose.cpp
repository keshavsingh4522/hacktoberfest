//Matrix Transpose

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<"\n";
    int a[n][n];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"\n";
    
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[j][i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
