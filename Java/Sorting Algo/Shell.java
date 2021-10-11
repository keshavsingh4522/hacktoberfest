/*
in this implementation, we choose the gap to be half of that of the total length.
after that the gap is again halved.
the process is done till gap is not 1, which means then it will become insertion sort
*/

public class Shell
{
    void  ShellSort(int arr[], int n)
    {
       for(int gap= n/2 ; gap>0 ; gap/=2)
       {
           for(int i= gap ; i<n ; i++)
           {
               int temp = arr[i];
               int j = i;
               for(j=i ; j>=gap && arr[j - gap]> temp ; j-=gap)
               {
                   arr[j] = arr[j - gap];
               }
              arr[j] = temp;
           }
       }

    }

    static void print(int arr[] , int n)
    {
        for (int i=0 ; i<n ; i++)
            System.out.print(arr[i] + " ");

    }

    public static void main(String[] args) {
        int arr[]= {20, 35, -15, 7, 55, 1, -22 };
        int n= arr.length;
        Shell ob = new Shell();
        ob.ShellSort(arr,n);
        System.out.println("Sorted Array");
        ob.print(arr,n);
    }
}
