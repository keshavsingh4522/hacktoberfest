package search;

public class searchMountainArray {
    public static int search_Mountain(int [] arr, int target){
        int peak = mountain_peak(arr);
        int firstTry = binarySearch(arr, target, 0, peak);
        if (firstTry != -1){
            return firstTry;
        }
        return orderAgnostic_binarySearch(arr,target, peak + 1, arr.length);
    }

    public static int binarySearch(int [] arr, int target, int start, int end){

        while (start <= end){
            int mid = start + (end - start)/2;

            if (target < arr[mid]){
                end = mid - 1;
            }
            else if (target > arr[mid]){
                start = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    public static int orderAgnostic_binarySearch(int [] arr, int target, int start, int end){

        while (start <= end){
            int mid = start + (end - start)/2;

            if (target < arr[mid]){
                start = mid + 1;
            }
            else if (target > arr[mid]){
                end = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    public static int mountain_peak(int [] arr){
        int start = 0;
        int end = arr.length - 1;

        while (start <= end){
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1]){
                end = mid;
            } else if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
        }
        return start;
    }
    public static void main(String[] args) {

    }
}
