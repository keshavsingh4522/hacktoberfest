#include <iostream>
using namespace std;

void nextPermutation(vector<int>& nums){
    int i = nums.size()-2;
    int j;
    //we iterate the array from back and find that element for which arr[i] < arr[]
    for(i;i >=0; i--){
        if(nums[i]>nums[i+1]){
            break;
        }
    }

    //corner case for last element

    if(i<0){
        reverse(nums.begin(), nums.end());
    }

    //finding next element just greater that the first element found = index 2
    //swap for numbers at index i and j 
    //reverse the string after the first indexed element

    else{
        for(j=nums.size()-1; j>i;j--){
            if(nums[j]>nums[i]){
                break;
            }
        }
        swap(nums[j], nums[i]);
        reverse(nums.begin()+i+1, nums.end);
    }
}

int main(){
    
    vector<int> arr = {1,2,3};
    nextPermutation(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}