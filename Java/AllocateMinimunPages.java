//Allocate Minimum Pages- maximum number of pages read by a student is minimised
//Constraints - 1. Allocate the books in a continuous fashion 2. Pages of a single book cannot be split


import java.util.*;
public class AllocateMinimumPages{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();           //Number of books
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();      //Filling number of pages in a book
        }
        int m = sc.nextInt();           //Number of students
        System.out.println("Minimum number of pages " + minPages(arr,n,m));
    }
    static int minPages(int arr[],int n, int m){        //Function to find the minimum pages
        long sum =0;
        if(n<m){
            return -1;
        }
        for(int i=0;i<n;i++){                   //Count total number of Pages
            sum += arr[i];
        }
        int min = 0, max = (int)sum;
        int result = Integer.MAX_VALUE;
        while(min<=max){                    //Applying binary search
            int mid = (min+max)/2;
            if(isPossible(arr, n, m, mid)){
                result = mid;
                max = mid - 1;
            }else{
                min = mid + 1;
            }
        }
        return result;
    }
    static boolean isPossible(int arr[], int n, int m, int curr_min)        //Utility method to check if current minimum value is feasible or not.
    {
        int studentsRequired = 1;
        int curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > curr_min)
                return false;
            if (curr_sum + arr[i] > curr_min)
            {
                studentsRequired++;
                curr_sum = arr[i];
                if (studentsRequired > m)
                    return false;
            }
            else
                curr_sum += arr[i];
        }
        return true;
    }
}


//Time Complexity - O(nlogm)
//Space Complexity - O(1)