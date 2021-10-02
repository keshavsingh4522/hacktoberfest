#include <iostream>
using namespace std;

int getMinDiff(int a[], int n, int k) {
        sort(a,a+n);
	    int ans=a[n-1]-a[0];
	    for(int i=1;i<n;i++)
	    {
	        int u=min(a[i]-k,a[0]+k);
	        int v=max(a[n-1]-k,a[i-1]+k);
	        ans=min(v-u,ans);
	    }
	    return ans;
}

int main(){

   int k = 2, n = 4;
   int arr[] = {1, 5, 8, 10};
   cout<< getMinDiff(arr,n,k);

    return 0;
}