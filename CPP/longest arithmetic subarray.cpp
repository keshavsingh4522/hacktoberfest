#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void longestarithmeticsubarray(int n,int arr[]){

    int ans=2,j=2,cur=2;
    int pd=arr[j]-arr[j-1];

    while (j < n)
    {
        if (pd == arr[j]-arr[j-1])
        {
            cur++;
        }
        else{
            pd=arr[j]-arr[j-1];
            cur=2;
        }
        ans=max(ans,cur);
        
        j++;
    }

    cout<<ans<<endl;

}

int main(){

    int n;
    cin>>n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    longestarithmeticsubarray(n,arr);

    return 0;
}