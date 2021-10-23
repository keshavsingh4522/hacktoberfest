//program that arranges words in an array alphabetically 
//(like that of a dictionary)

package quicksort;

import java.util.Scanner;


class Arr{
    
    private String[] arr;
    private int pivot;

    Arr(String[] arr){
     
        this.arr=arr;
    }
    //recursively calls qSort() for each partition created
    void qSort(int l,int r){
        
        if(l<r){
        partition(l,r);
        qSort(l,pivot-1);
        qSort(pivot+1,r);
        }
    }
    /*finds and returns the pivot's position to qSort(),
      thereby partitioning the array as left-of-pivot and right-of-pivot*/    
    void partition(int l,int r){
        
        int i=l,j=r+1;
        while(i<j){
            
            do {
                i++;
            }while(arr[i].compareToIgnoreCase(arr[l])<=0&&i<r);
            
            
            do{
                j--;
            }while(arr[j].compareToIgnoreCase(arr[l])>0 && j>=l);
            
            if(i<j)
            swap(i,j);
            
        }
        swap(l,j);
        pivot=j;
        
    }
    void swap(int l,int r){
        
        String temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
    }
    
}


public class QuickSort {

    public static void main(String[] args) {

        String arr[];
        Scanner in = new Scanner(System.in);
        System.out.print("Enter input size : ");
        int n=in.nextInt();
        arr=new String[n];
        in.nextLine();
        System.out.println("Enter names : ");
        for(int i=0;i<n;i++){
            arr[i]=in.nextLine();
        }

        Arr a=new Arr(arr);
        a.qSort(0, n-1);
        
        System.out.println("\nNames in Lexicographical order : ");
        for(int i=0;i<n;i++)
            System.out.println(arr[i]);
        
    }
    
}
