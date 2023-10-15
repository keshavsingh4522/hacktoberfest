#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>n;

    int sum=18;
    unordered_set<int>s;

    //fix the first element
    for(int i=0;i<n-2;i++)
    {
         // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        int curr_sum=sum-a[i];
        for(int j=i+1;j<n;j++)
        {
            if(s.find(curr_sum)!=s.end())
            cout<<a[i]<<" "<<a[j]<<" "<<curr_sum-a[j];
             // If we reach here, then no triplet was found
        s.insert(a[j]);
        }
    }
}
