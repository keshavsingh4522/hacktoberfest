package com.binarySearchQuestion;

import java.util.Arrays;
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
public class firstAndLast {
    public static void main(String[] args) {
        int [] nums ={1,22,22,44,55,55,55};
        int target = 55;
        int [] arr = searchRange(nums,target);
        System.out.println(Arrays.toString(arr));
    }
    static public int[] searchRange(int[] nums, int target) {
        int [] ans ={-1,-1};
        int start = search(nums,target,true);
        int end = search (nums,target,false);
        ans[0] = start;
        ans[1] = end;
        return ans;

    }
    static int search(int[] nums,int target,boolean first){
        int ans = -1;
        int s = 0;
        int e = nums.length-1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(target<nums[mid]){
                e = mid-1;
            }if(target>nums[mid]){
                s = mid+1;
            }else if(target==nums[mid]){
                ans = mid;
                if(first){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }

        }
        return ans;
    }
}


