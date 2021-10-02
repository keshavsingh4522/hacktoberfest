void fillSuffix(vector<int> &A,vector<int> &arr){
    int n=A.size();
    arr[n]=0;
    for(int i=n-1;i>=0;i--){
        arr[i]=arr[i+1]+A[i];
    }
}

void fillPrefix(vector<int> &A,vector<int> &arr){
    arr[0]=0;
    for(int i=1;i<arr.size();i++){
        arr[i]=arr[i-1]+A[i-1];
    }
}

int Solution::solve(vector<int> &A, int B) {
    int sum=INT_MIN;
    int count=B;
    int n=A.size();
    vector<int> prefixSum(A.size()+1);
    vector<int> suffixSum(A.size()+1);
    fillPrefix(A,prefixSum);
    fillSuffix(A,suffixSum);
    for(int i=0;i<=B;i++){
        int temp=prefixSum[i]+suffixSum[n-B+i];
        if(temp>sum)
            sum=temp;
    }
    return sum;
}
