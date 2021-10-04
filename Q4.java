import java.util.Scanner;
class Q4
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int ar[]={5,7,9,11,15,20,30,45,89,97};
        System.out.println("Enter the number to be searched");
        int n=sc.nextInt();
        boolean found=false;
        int min=0,max=ar.length,mid;
        while(min<=max)
        {
            mid=(min+max)/2;
            if(n==ar[mid])
            {
                System.out.println(n+" found at index "+mid);
                found = true;
                break;
            }
            else if(n<ar[mid])
            {
                max = mid-1;
            }
            else
            {
                min=mid+1;
            }
        }
        if(found == false)
        {
            System.out.println("Search element not found");
        }
    }
}