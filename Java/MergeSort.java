import java.util.Arrays;
import java.util.Scanner;

public class MergeSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        mergeSort(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }

    public static void mergeSort(int[] arr, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merging(arr, start, mid, end);
        }
    }

    public static void merging(int[] arr, int start, int mid, int end) {
        int n1 = mid - start + 1;
        int n2 = end - mid;
        int[] left = new int[n1];
        int[] right = new int[n2];
        for(int i=0;i<n1;i++){
            left[i]=arr[start+i];
        }
        for(int i=0;i<n2;i++){
            right[i]=arr[mid+1+i];
        }

        int i = 0;
        int j = 0;
        int index = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[index] = left[i++];
            } else {
                arr[index] = right[j++];
            }
            index++;
        }
        while (i < n1) {
            arr[index++] = left[i++];
        }
        while (j < n2) {
            arr[index++] = right[j++];
        }
    }
}
