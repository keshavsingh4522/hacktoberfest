package com.saikat;

import java.util.Scanner;

class MountainArray {
    public static void main(String[] args) {
        int[] arr = {1,5,10,2,1};
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int end = arr.length-1;
        int peak=peakIndexInMountainArray(arr);
        //System.out.println(peak);
        int answer1 = binarySearch(arr, t,0,peak);
        int answer2 = binarySearch(arr,t, peak+1, end );
        if(answer1 == -1 && answer2 == -1)
            System.out.println("Not found");
        else if(answer2==-1)
            System.out.println(answer1);
        else
            System.out.println(answer2);
    }
    static int peakIndexInMountainArray(int[] arr) {
        int start = 0;
        int end = arr.length-1;
        while(start<end)
        {//not doing start<=end because we want to break the loop even when start=end;
            // this will ensure that the start and the end pointer are pointing at the
            // same position when the loop terminates. That position will be the greatest element in the array.
            int mid = start+(end-start)/2;
            if(arr[mid]>arr[mid+1])
                end=mid;//this may be the answer hence I'm not doing `end = mid-1`;
            else 
                start = mid+1;
            //In this case I am in the ascending part of the array, and I know that mid+1 > mid element,
            // so I am ignoring the middle element.
        }
        return end;
    }
    static int binarySearch(int[] arr, int target, int start, int end)
    {
        if(arr[start]<arr[end]) {
            while (start <= end) {
                int mid = (start + end) / 2;
                if (arr[mid] == target) {
                    return mid;
                } else if (arr[mid] > target) {
                    end = mid - 1;
                } else
                    start = mid + 1;
            }
        }
        else if(arr[start]>=arr[end])
        {
            while (start <= end) {
                int mid = (start + end) / 2;
                if (arr[mid] == target) {
                    return mid;
                } else if (arr[mid] > target) {
                    start = mid + 1;
                } else
                    end = mid - 1;
            }
        }
      return -1;
    }
}