import java.util.*;
public class BinarySearch { 
    
 public static int binarySearch(int[] arr, int target) {
    	//Your code goes here
        int start = 0;
        int end  = arr.length-1;

        if(arr[0]<arr[arr.length-1]){ // if array is sorted in ascending order
        while(start <= end){
            int mid = start + (end-start)/2; 
            if(arr[mid] < target){
                start = (mid+1);
            }
            else if(arr[mid] > target){
                end = (mid-1);
            }
            else {
                return mid;
            }
        }
        return -1;
    }

     else{ // if array is sorted in descending order
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] < target){
                end = (mid-1);
            }
            else if(arr[mid] > target){
                start = (mid+1);
            }
            else {
                return mid;
            }
        }
        return -1;
    }
}
}

