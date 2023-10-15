#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j=0;
    for (int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
    }
    while(j<nums.size()){
        nums[j++]=0;
    }
}

int main(){
    vector <int> nums={0,1,0,3,12};
    moveZeroes(nums);
    for(auto x:nums){
        cout<<x<<"\t";
    }
    return 0;
}