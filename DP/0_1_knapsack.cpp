 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
 #include "../debug.h"
 
int t[1002][1002];
 
int MyKnapSack(int W, int wt[], int val[], int n){
    if(W==0 || n==0) 
        return 0;
   
    if(t[n][W] != -1) 
        return t[n][W];
   
    if(wt[n-1]<=W)   
        return t[n][W] = max(val[n-1]+MyKnapSack(W-wt[n-1], wt, val, n-1), MyKnapSack(W, wt, val, n-1));
    else 
        return t[n][W] = MyKnapSack(W, wt, val, n-1);
}

int knapSack(int W, int wt[], int val[], int n) { 
    memset(t, -1, sizeof(t));
    return MyKnapSack(W, wt, val,n);
}
 
int main(){
    // freopen("../input.txt", "r", stdin);  
    freopen("../output.txt", "w", stdout);
    freopen("../Error.txt", "w", stderr);
 
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int n = sizeof(wt)/sizeof(wt[0]);
    int W = 7;

    cout<<knapSack(W, wt, val, n);
 }
