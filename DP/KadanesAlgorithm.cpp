/*
Kadane's Algorithm 
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number)
which has the maximum sum and return its sum.
Example 1:
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
Example 2:
Input:
N = 4
Arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1 
of element (-1)
 */
#include<iostream>
using namespace std;

int maxSum(int a[], int n){
    int ma = INT_MIN;
    int max_th = 0;
    for(int i=0; i<n; i++){
        max_th = max_th+ a[i];
        if(max_th>ma)
            ma = max_th;
        if(max_th<0)
            max_th = 0;
    }
    return ma;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int sum= maxSum(a, n);
    cout<<"Sum: "<<sum;
}