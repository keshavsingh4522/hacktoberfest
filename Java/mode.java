import java.util.*;
public class mode
{
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        int i,n,max,v,j,max1;
        n=d.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++)
            a[i]=d.nextInt();
        max=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>max)
                max=a[i];
        }
        int count[]=new int[max+1];
        for(i=0;i<n;i++)
        {
            if(count[a[i]]==0)
            {
                for(j=0;j<n;j++)
                {
                    if(a[i]==a[j])
                        count[a[i]]++;
                }
            }
        }
        max1=0;
        v=0;
        for(i=0;i<max+1;i++)
        {
            if(count[i]>max1)
            {
                max1=count[i];
                v=i;
            }
        }
        System.out.println(v);
    }
}
