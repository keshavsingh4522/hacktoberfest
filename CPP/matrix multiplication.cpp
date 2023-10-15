//matrix multiplication(2-D array)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2,n3;
    cin>>n1 >>n2>> n3;
    
    int arr1[n1][n2];
    int arr2[n2][n3];
    int prod[n1][n3];
    
    cout<<"\n";
    
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
         cin>>arr1[i][j];   
        }
    }
    
    cout<<"\n";

    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n3;j++)
        {
         cin>>arr2[i][j];   
        }
    }
    
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
         prod[i][j]=0;   
        }
    }
    
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
            for(int k=0;k<n2;k++)
            {
                prod[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    
    cout<<"\n";
    
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n3;j++)
        {
         cout<<prod[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
