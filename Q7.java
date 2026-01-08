import java.util.Scanner;
class Q7
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("MENU\n1-Prime Number or not\n2-Automorphic Number or not\nEnter your choice");
        int n=sc.nextInt();
        int a;
        switch(n)
        {
            case 1:
            System.out.println("Enter any number");
            a=sc.nextInt();
            int c=0;
            for(int x=1;x<=a;x++)
            {
                if(a%x==0)
                {
                    c++;
                }
            }
            if(c==2)
            {
                System.out.println("Prime Number");
            }
            else
            {
                System.out.println("NOT a prime number");
            }
            break;
            
            case 2:
            System.out.println("Enter any number");
            a=sc.nextInt();
            int s=a*a;
            int d=1;
            for(int x=a;x!=0;x=x/10)
            d=d*10;
            if(s%d==a)
            {
                System.out.println("Automorphic Number");
            }
            else
            {
                System.out.println("NOT");
            }
            break;
            
            
        }
    }
}
            