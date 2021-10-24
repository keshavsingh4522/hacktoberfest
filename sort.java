import java.util.Scanner;
public class sort
	{
		public static void main (String [] args)
	{
		Scanner sc = new Scanner(System.in);String a [] = new String [10];
		 int i,j;
		String  temp = "";
		System.out.println("enter ten names, here->>");
		for(i = 0 ; i < a.length; i++){a[i] = sc.nextLine();
	}
		for(i = 0 ; i < a.length; i++)
		{
		for(j = i+1; j < a.length; j++)
			{	if(a[i].compareTo(a[j]) > 0)
					{
						temp = a[i];a[i] = a[j];a[j] = temp;
					}
			}
	}
			System.out.println("the order of the names sorted alphabetically is : ");
			for(i = 0 ; i < a.length; i++)
				{
					System.out.println(a[i]);
				}
	}
	}