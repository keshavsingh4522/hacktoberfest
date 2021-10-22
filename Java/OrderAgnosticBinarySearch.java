/* This is Java program to search the element in an array using Binary Search. 
Binary Search only works for sorted array (either assending or in decending order).

Where normal Binary search only works for either assending or decending array, OrderAgnostic Binary
search wroks irrespective of the order of the array, i.e will works both for assending and decending array.*/

import java.util.Scanner;

public class OrderAgnosticBS {
    public static void main(String[] args) // main function. Program will start from this function.
    {
        int arr[] = { 123, 98, 45, 13, 05, 0, -9, -14, -25 };
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the target element : ");
        int target = sc.nextInt(); // taking input from user
        int ans = search(arr, target);
        System.out.println("index" + ans);
    }

    static int search(int arr[], int target) // this function will implement the binary search and find the element.
    {

        boolean isAse = arr[0] < arr[arr.length - 1];
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == arr[mid]) {
                return mid;
            }
            if (isAse) {
                if (target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            else {
                if (target > arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
}

// Output

// Enter the target element : 10
// -1 (not found)

// Enter the target element : 98
// 1 (found at index 1)

// Contributed by Abhishek Bhatt : @AbhishekBhatt072003
