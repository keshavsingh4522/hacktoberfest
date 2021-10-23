//SHUFFLIN
#include <bits/stdc++.h>
using namespace std;

void AlternateRearrange(int arr[], int n)
{
    int arr_ev[100000];
    int arr_od[100000];
    int x=0,y=0;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2 == 0)
            arr_ev[x++]=arr[i];
        else
            arr_od[y++]=arr[i];
    }
    int index = 0, i = 0, j = 0;
 
    bool flag = true;
    
    
int e=x, o=y;
    while(e>0 && o>0)
    {
        arr[index++]=arr_ev[i++];e--;
        arr[index++]=arr_od[j++];o--;
    }
    while(e>0)
    {
        arr[index++]=arr_ev[i++];e--;
    }
    while(o>0)
    {
        arr[index++]=arr_od[j++];o--;
    }
}

int main() {
    int t;
    cin>>t;
	while(t--){
	    int n, arr[100000];
        cin>>n;
    
        for(int i=0; i<n; ++i){
            cin>>arr[i];
        }
        
        AlternateRearrange(arr, n);
        
        int arr2[100000],sum=0;
        for(int i=0; i<n; ++i){
            int x=(arr[i]+(i+1));
            arr2[i]=x%2;
            sum+=arr2[i];
        }
        cout<<sum<<endl;
        
	}
	return 0;
}
