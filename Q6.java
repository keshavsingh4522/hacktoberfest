import java.util.Scanner;
class Q6
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String name[] =new String[5];
        int a[]=new int[5];
        double dis[]=new double[5];
        double net[]=new double[5];

        for(int x=0;x<=4;x++)
        {
            System.out.println("Enter name "+(x+1));
            name[x]=sc.next();
            System.out.println("Enter amount");
            a[x]=sc.nextInt();
            if(a[x]>=0&&a[x]<=25000)
            {
                dis[x]=2.0;
                net[x]=(double)a[x]-(a[x]*dis[x]/100.0);
            }
            else if(a[x]<=35000)
            {
                dis[x]=10.0;
                net[x]=(double)a[x]-(a[x]*dis[x]/100.0);
            }
            else if(a[x]<=55000)
            {
                dis[x]=12.0;
                net[x]=(double)a[x]-(a[x]*dis[x]/100.0);
            }
            else if(a[x]<=70000)
            {
                dis[x]=16.0;
                net[x]=(double)a[x]-(a[x]*dis[x]/100.0);
            }
            else
            {
                dis[x]=18.0;
                net[x]=(double)a[x]-(a[x]*dis[x]/100.0);
            }
        }
        System.out.println("SL.NO.\tName\tTicket Charges\tDiscount\tNet Amount");
        for(int x=0;x<=4;x++)
        {

            System.out.println((x+1)+"\t"+name[x]+"\t"+a[x]+"\t\t\t"+dis[x]+"\t"+net[x]);
        }
    }
}    