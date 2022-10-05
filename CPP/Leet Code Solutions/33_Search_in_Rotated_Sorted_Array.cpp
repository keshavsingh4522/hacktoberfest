class Solution {
public:
    int pivote(vector<int> arr, int n){
        int s = 0, e = n-1;
        int mid = s+(e-s)/2;
        while(s<e){
            if(arr[mid]>=arr[0]){
                s= mid+1;
            }
            else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
    
    int binarysearch(vector<int> arr, int s, int e, int target){
        int mid = s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s = 0, n = nums.size(), pivto = pivote(nums,n);
        if(target>=nums[pivto] && target<=nums[n-1]){
            return binarysearch(nums, pivto, n, target);
        }
        else{
            return binarysearch(nums, s, pivto-1, target);
        }
    }
};
