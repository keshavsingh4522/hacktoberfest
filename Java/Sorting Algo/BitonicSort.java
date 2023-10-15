// Bitonic Sort
//this program works when size of input is power of 2.   
public class BitonicSort  
{  
static void exchange(int arr[], int i, int j, boolean d)  
{  
    int temp;  
    if (d==(arr[i]>arr[j]))  
    {  
            temp = arr[i];  
        arr[i] = arr[j];  
        arr[j] = temp;  
    }  
}  
/* The sequence to be sorted starts at
index position low (l), the parameter c is the number
of elements to be sorted.*/
static void bitonicMerge(int arr[], int l, int c, boolean d)  
{  
    int k,i;  
    if (c>1)  
    {  
        k = c/2;  
        for (i=l; i<l+k; i++)  
            exchange(arr, i, i+k, d);  
        bitonicMerge(arr, l, k, d);  
        bitonicMerge(arr, l+k, k, d);  
    }  
}  
static void bitonicSort(int arr[],int l, int c, boolean d)  
{  
    int k;  
    if (c>1)  
    {  
        k = c/2;  
        // sort in ascending order since dir here is 1
        bitonicSort(arr, l, k, true);  

        // sort in descending order since dir here is 0
        bitonicSort(arr, l+k, k, false);  

        // Will merge whole sequence in ascending order since dir=1.
        bitonicMerge(arr,l, c, d);  
    }  
}  
  /*Caller of bitonicSort for sorting the entire array
      of length N in ASCENDING order */ 

static void sort(int arr[], int n, boolean order)  
{  
    bitonicSort(arr,0, n, order);  
}  

 /* A utility function to print array of size n */
 static void printArray(int arr[])
 {
     int n = arr.length;
     for (int i=0; i<n; ++i)
         System.out.print(arr[i] + " ");
     System.out.println();
 }

// Driver Code

public static void main(String[] args)  
{ 
    int arr[]= {1, 10, 2, 3, 1, 23, 45, 21};  
    int n = arr.length;  
    int i;  
    boolean order = true;     
    sort(arr, n, order);  
   
    System.out.println("Sorted array: \n");  
    for (i=0; i<n; i++)  
        System.out.println(arr[i]);  
}  
}  
