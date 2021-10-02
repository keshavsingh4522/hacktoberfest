#include<iostream>
#include<vector>
using namespace std;

// Calculating the minimum path sum from top to bottom
// Leetcode: https://leetcode.com/problems/triangle/

int main(){

    int n,x;

    cout<<"Enter the number of rows in the triangle: ";
    cin>>n;

    vector<vector<int>> triangle(n);

    for(int i=1;i<=n;i++){
        cout<<"Enter "<<i<<" elements in the "<<i<<" row: ";
        for(int j=0;j<i;j++){
            cin>>x;
            triangle[i-1].push_back(x);
        }
    }

    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=triangle[n-1][i];
    }
    // Bottom up

    for(int i=triangle.size()-2;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
        }
    }

    cout<< dp[0]<<"\n";
}
