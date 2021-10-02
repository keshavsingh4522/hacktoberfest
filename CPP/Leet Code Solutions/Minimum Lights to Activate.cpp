int Solution::solve(vector<int> &A, int B) {
    int count=0;
    for(int i=0;i<A.size();i++){
        int j=i+B-1,k=i-B+1;
        if(k<0) k=0;
        if(j>A.size()-1) j=A.size()-1;
        while(j>=k && A[j]==0)
            j--;
        if(j<k) return -1;
        count++;
        i=j+B;
    }
    return count;
}
