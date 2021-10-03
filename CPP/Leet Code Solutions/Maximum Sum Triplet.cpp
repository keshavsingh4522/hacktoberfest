void calculateR(vector<int> &arrR,vector<int> &arr){
    set<int> right;
    int n=arr.size();
    for(int i=n-1;i>=0;i--)
        {
            right.insert(arr[i]);
            if(arr[i]==*right.rbegin())
                arrR[i]=0;
            else
            arrR[i]=*right.rbegin();
        }
}

void calculateL(vector<int> &arrL,vector<int> &arr){
    set<int> left;
    left.insert(0);
    int n=arr.size();
    for(int i=0;i<arr.size();i++)
        {
            left.insert(arr[i]);
            arrL[i]=*(--(left.lower_bound(arr[i])));
        }
}
    

int Solution::solve(vector<int> &arr) {
    int max=INT_MIN;
    int n=arr.size();
    vector<int> arrL(n);
    vector<int> arrR(n);
    calculateL(arrL,arr);
    calculateR(arrR,arr);
    for(int i=0;i<n;i++)
        {
            int temp=arrL[i]+arrR[i]+arr[i];
            if(max<temp && arrR[i]!=0 && arrL[i]!=0)
                max=temp;
        }
    return max;
}
