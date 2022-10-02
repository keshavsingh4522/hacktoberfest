import java.util.*;;
class kruskal
{
    int parent[]=new int[10];
    int kru(int ar[][],int n)
    {
        int i,j,k=1,a=0,b=0,u=0,v=0,min,mincost=0;
        while(k<n)
        {
            min=99;
            for( i=1;i<=n;i++)
            {
            for( j=1;j<=n;j++)
            {
                if(ar[i][j]<min)
                {
                    min=ar[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
            }
            while(parent[u]>0)
            u=parent[u];
            while(parent[v]>0)
            v=parent[v];
            if(u!=v)
            {
                System.out.println((k++)+"min cost is ");
                System.out.println(a+" "+ b+"= "+min);
                mincost+=min;
                parent[v]=u;
            }
            ar[a][b]=ar[b][a]=99;
        }
        return mincost;
    }
}
public class kruskal {
    public static void main(String[] args) {
        int ar[][]=new int[10][10];
        int n,s,x;
        System.out.println("Enter the number of nodes: ");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        System.out.println("Enetr the matrix: ");
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        ar[i][j]=sc.nextInt();
        kruskal k=new kruskal();
       x= k.kru(ar, n);
       System.out.println(k);
    }
}
