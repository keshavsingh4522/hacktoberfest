class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m-1;
        int j = n-1;
        int x = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[x] = nums1[i];
                i--;x--;
            }else{
                nums1[x] = nums2[j];
                j--;x--;
            }
        }
        while(j>=0){
            nums1[x] = nums2[j];
            j--;x--;
        }
    }
}
