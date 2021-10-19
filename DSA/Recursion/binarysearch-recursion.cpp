


#include <iostrem.h>
 

int binarySearch(int nums[], int low, int high, int target)
{
    
    if (low > high) {
        return -1;
    }
 
   
 
    int mid = (low + high)/2;    // overflow can happen
   
 
   
    if (target == nums[mid]) {
        return mid;
    }
 
    
    else if (target < nums[mid]) {
        return binarySearch(nums, low, mid - 1, target);
    }
 
    
    else {
        return binarySearch(nums, mid + 1, high, target);
    }
}
 
int main(void)
{
    int nums[] = { 2, 5, 6, 8, 9, 10 };
    int target = 5;
 
    int n = sizeof(nums)/sizeof(nums[0]);
 
    int low = 0, high = n - 1;
    int index = binarySearch(nums, low, high, target);
 
    if (index != -1) {
        cout<<"Element found at index "<< index;
    }
    else {
        cout<<"Element not found in the array";
    }
 
    return 0;
}
