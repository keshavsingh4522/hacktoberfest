int Solution::maxArr(vector<int> &A) {
    int maxPlus=INT_MIN,minPlus=INT_MAX,maxMinus=INT_MIN,minMinus=INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        maxPlus=max(maxPlus,A[i]+i);
        maxMinus=max(maxMinus,A[i]-i);
        minPlus=min(minPlus,A[i]+i);
        minMinus=min(minMinus,A[i]-i);
    }
    return (maxPlus-minPlus)>(maxMinus-minMinus)?(maxPlus-minPlus):(maxMinus-minMinus);
}
