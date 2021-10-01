#include<bits/stdc++.h>
using namespace std;

   int firstocc(vector<int>&nums,int target,int low,int high)
    {
        if(low>high) return -1; 
        int mid=(low+high)/2;
        if(nums[mid]>target)
            return firstocc(nums,target,low,mid-1);
        else if(nums[mid]<target)
            return firstocc(nums,target,mid+1,high);
        else 
            if(mid==0||nums[mid-1]!=nums[mid])
            return mid;
            else 
                return firstocc(nums,target,low,mid-1);
    }
int main()
{ 
    vector<int>a={10,20,20,20,20,33};
    int x=40;
    int low=0, high=5;
    cout<<firstocc(a,x,low,high);

}