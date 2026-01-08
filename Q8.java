import java.util.Scanner;
class Q8
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int p[]=new int[6];
        int q[]=new int[4];
        int r[]=new int[10];
        for(int x=0;x<p.length;x++)
        {
            System.out.println("P[]");
            System.out.println("Enter number at index "+x);
            p[x]=sc.nextInt();
        }
        for(int x=0;x<q.length;x++)
        {
            System.out.println("Q[]");
            System.out.println("Enter number at index "+x);
            q[x]=sc.nextInt();
        }
        int i=0;
        for(int x=0;x<p.length;x++)
        {
            r[i]=p[x];
            i++;
        }
        for(int x=0;x<q.length;x++)
        {
            r[i]=q[x];
            i++;
        }
        System.out.println("R[]");
        for(int x=0;x<r.length;x++)
        {
            System.out.println(r[x]);
        }
    }
}