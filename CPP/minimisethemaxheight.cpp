#include<iostream>
using namespace std;

    int maxdiff(int a[],int n,int k){
        int max=a[0];
        int min=a[0];
        for (int i = 0; i < n-1; i++)
        {
            if(a[i]<a[i+1]){
                a[i]+=k;
                a[i+1]-=k;
            }
            else{
                a[i]-=k;
                a[i+1]+=k;

            }
            if(a[i]>max){
                max=a[i];
            }
            if(a[i]<min){
                min=a[i];
            }
            
            if(a[i+1]>max){
                max=a[i+1];
            }
            if(a[i+1]<min){
                min=a[i+1];
            }
        }
        return max-min;
    }

int main(){
    int k,n;
    cin>>k;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];

    }
    
    cout<<maxdiff(a[],n,k);

    return 0;
}