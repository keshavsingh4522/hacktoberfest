
import java.util.Scanner;

public class Main {

	public static void main(String[] args)
	{
	    int i;
	    Scanner sc=new Scanner(System.in);
		System.out.print(" How much elements do you want in array ? ");
		int n=sc.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter values:-");
		for( i=0;i<n;i++)
		{
		    arr[i]=sc.nextInt();
		}
		bubble(arr);
		System.out.print("Sorted array:- ");
		for(int num:arr)
		System.out.print(num+" ");

	}

	static void bubble(int[] a) 
	{
	    int i,j;
//run the steps N-1 times

		for (i = a.length-1; i >=1; i--) 
		{
			for (j = 0; j < i; j++) 
			{
//swap if the items are smaller than previous item
				if (a[j] > a[j+1] ) 
				{
					int temp = a[j];
					a[j] = a[j + 1];
					a[j+1] = temp;
				}
			}
		}
	}
}
