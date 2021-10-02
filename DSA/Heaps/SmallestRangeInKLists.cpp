// Problem : Smallest range in K lists
//
// Problem Link: https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1#
//
// Input:
// N = 5, K = 3
// KSortedArray[][] = {{1 3 5 7 9},
//                     {0 2 4 6 8},
//                     {2 3 5 7 11}}
// Output: 1 2
// Explanation: K = 3
// A:[1 3 5 7 9]
// B:[0 2 4 6 8]
// C:[2 3 5 7 11]
// Smallest range is formed by number 1
// present in first list and 2 is present
// in both 2nd and 3rd list.

// Solution:
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int maxi=INT_MIN, minrange=INT_MAX, start;
        for(int i=0;i<k;i++) 
        {
           pq.push({arr[i][0],i});
           maxi=max(maxi,arr[i][0]);
        }
        int a[k]={0};
        while(true)
        {
           pair<int,int> p=pq.top();
           pq.pop();
           int mini=p.first;
           int range=maxi-mini;
           if(range<minrange) 
           {
               start=mini;
               minrange=range;
           }
           a[p.second]++;
           if(a[p.second]==n)
               break;
           pq.push({arr[p.second][a[p.second]],p.second});
           maxi=max(maxi,arr[p.second][a[p.second]]);
        }
        return {start, minrange+start};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends

