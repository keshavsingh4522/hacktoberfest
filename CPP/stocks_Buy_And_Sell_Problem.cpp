#include <bits/stdc++.h>

using namespace std;

int stocksProfit(int arr[],int n){
    int minPrice= INT_MAX;
    int maxProfit = 0;
    for(int i=0 ; i<n ; i++){
        minPrice = min(minPrice , arr[i]);
        maxProfit = max(maxProfit , arr[i] - minPrice);
    }
    return maxProfit;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout<<"Maximum Profit: "<<stocksProfit(arr , n)<<" Rs.";

    return 0;
}
