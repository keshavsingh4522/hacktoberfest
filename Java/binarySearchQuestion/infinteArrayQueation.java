package com.binarySearchQuestion;
//https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
public class infinteArrayQueation {
    public static void main(String[] args) {
int [] arr ={1,2,3,4,5,6,7,8,9};
int target = 6;
        System.out.println(ans(arr,target));
    }
   static int ans (int[] arr,int target){
        int s = 0;
        int e = 1;
        while(target>arr[e]){
         int  news = e+1;
         e = e + (e-s + 1)*2;
         s = news;
        }
     return search(arr,target,s,e);
    }
    static int search(int[] arr,int traget,int s,int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (traget < arr[mid]) {
                e = mid - 1;
            } else if (traget > arr[mid]) {
                s = mid + 1;
            } else if (traget == arr[mid]) {
                return mid;
            }
        }
        return -1;
    }
}