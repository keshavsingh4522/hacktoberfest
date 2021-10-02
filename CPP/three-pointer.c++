/*Count triplets with sum smaller than X 

Given an array arr[] of distinct integers of size N and a value sum, 
the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of 
(arr[i] + arr[j] + arr[k]) smaller than the given value sum.*/
// A Simple C++ program to count triplets with sum smaller
// than a given value
#include<bits/stdc++.h>
using namespace std;



long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    long long count=0;
	    long long  i=0,j,k;
	    while(i<n-2)
	    {
	        j=i+1,k=n-1;
	        while(j<k)
	        {
	            if(arr[i]+arr[j]+arr[k]<sum)
	            count=count+k-j,j++;
	            else
	            k--;
	        }
	       i++; 
	    }
	  return count;  
	}
int main()
{
	int arr[] = {5, 1, 3, 4, 7};
	int n = sizeof arr / sizeof arr[0];
	int sum = 12;
	cout << countTriplets(arr, n, sum) << endl;
	return 0;
}
