#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter the number till which you want to find the prime number";
    cin>>n;
    int prime[100];
    for(int i=0;i<=n;i++)
    {
        prime[i]=1;
    }
    prime[0]=0;
    prime[1]=0;
        for(int i=2;i<sqrt(n);i++)
        {
            if(prime[i]==1)
            {
                for(int j=2;i*j<=n;j++)
                {
                    prime[i*j]=0;
                }
            }
        }
    for(int i=0;i<=n;i++)  
    {
        if(prime[i]==1)
        cout<<i<<" is prime"<<endl;
        else
        cout<<i<<" is not a prime number"<<endl;
    }
}
 