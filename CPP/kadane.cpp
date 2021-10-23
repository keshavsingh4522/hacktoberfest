#include<iostream>
using namespace std;

int MaxContigousSum(int A[],int n){
    int M[n]=0,maxSum=0;
    if(A[0]>0)
        M[0]=A[0];
    else M[0]=0;
    for(int i=1;i<n;i++){
        if(M[i-1]+A[i]>0)
            M[i]=M[i-1]+A[i];
        else M[i]=0;
    
    }
    for (int i = 0; i < n; i++)
    {
        if(M[i>maxSum])
            maxSum=M[i];
        /* code */
    }
    return maxSum;
    
}

int main(){

    int k,a[];
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        cin>>a[i];
    }
    
    cin>>MaxContigousSum(a[],k);

    return 0;
}