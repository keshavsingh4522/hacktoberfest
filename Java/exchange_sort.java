import java.util.*;
 
public class Example {
 
   public static void main(String[] args) {
 
      int[] arr = {99, 77, 55, 33, 11, 88, 66, 44, 22};
      System.out.println("Unsorted: " + Arrays.toString(arr));
 
      exchangeSort(arr);
      System.out.println("Sorted  : " + Arrays.toString(arr));
   }
 
   public static void exchangeSort(int[] arr) {
 
      for (int i = 0; i < arr.length - 1; i++) {
         for (int j = i + 1; j < arr.length; j++) {
            if (arr[i] > arr[j]) {
               int temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
         }
      }
   }
 
}
