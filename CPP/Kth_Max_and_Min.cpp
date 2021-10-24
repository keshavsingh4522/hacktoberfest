// Write a Program to find the Kth Maximum and Minimum element in the array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
  // sorting the array of n elements
    sort(a,a+n);

    int kmin=a[k-1];  // Finding Kth minimum element
    int kmax=a[n-k];  // FInding Kth Maximum element

    cout<<kmax<<" "<<kmin;

}

/*

Sample Input: 

5 3
12 4 6 3 2

Sample Output :  4 4

*/
