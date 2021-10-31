import java.util.*;

public class InsertionSortJava{
    public static void main(String[] args){
      System.out.println("Enter the number of array elements: ");
      Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      System.out.println("Enter the array elements: ");
      int arr[]=new int[n];
      for(int i=0;i<n;i++){
        arr[i]=sc.nextInt();
      }
      insertion(arr);
      System.out.println("The elements in sorted order using Insertion Sort :");
      System.out.println(Arrays.toString(arr));
    sc.close();
  }

  static void insertion(int arr[]){
    for(int i=0;i<arr.length-1;i++){
      for(int j=i+1;j>0;j--){
        if(arr[j]<arr[j-1]){
          swap(arr,j,j-1);
        }
        else{
          break;
        }
      }
    }
}

  static void swap(int arr[],int first,int second){
      int temp=arr[first];
      arr[first]=arr[second];
      arr[second]=temp;
    }
}