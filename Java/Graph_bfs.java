import java.util.*;
class Graph_bfs{
    static private int V;
    static private LinkedList <Integer> adj[];
    Graph_bfs(int v)
    {

        V=v;
        adj=new LinkedList[v];
        for(int i=0;i<V;i++)
            adj[i]=new LinkedList();

    }

    void addEdge(int v,int w)
    {
        adj[v].add(w);
    }

    static int[] bfs(int s,int len)
    {
        boolean visited[]=new boolean[V];
        LinkedList <Integer> q=new LinkedList<>();
        visited[s]=true;
        q.add(s);
        int c=0;
        int dist[]=new int[len];
        for(int i=0;i<len;i++)
            dist[i]=-1;
        int z=0;
        dist[s]=0;
        while(q.size()!=0)
        {
            s=q.poll();
            Iterator <Integer> i=adj[s].listIterator();
            //c++;
            while(i.hasNext())
            {
                int n=i.next();
                if(!visited[n])
                {
                    visited[n]=true;
                    q.add(n);
                    dist[n]=dist[s]+1;
                    System.out.println(n);
                }
            }
        }
        return dist;
    }

    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        int n,m,i,j;
        int t=d.nextInt();
        while(t-->0)
        {
            n=d.nextInt();
            m=d.nextInt();
            int a[]=new int[n+1];
            for(i=1;i<=n;i++)
                a[i]=d.nextInt();
            int b[]=new int[m];
            for(i=0;i<m;i++)
                b[i]=d.nextInt();
            Graph_bfs g=new Graph_bfs(n+1);
            for(i=0;i<=n;i++)
            {
                if(a[i]!=0)
                    g.addEdge(0,i);
            }
            for(i=1;i<=n;i++)
            {
                if(a[i]==1 && i!=n)
                {
                    while(i!=n)
                    {
                        g.addEdge(i,i+1);
                        i++;
                    }
                }
            }
            for(i=n;i>=1;i--)
            {
                if(a[i]==2 && i!=1)
                {
                    while(i!=1)
                    {
                        g.addEdge(i,i-1);
                        i--;
                    }
                }
            }
            int dist1[]=new int[n+1];
            dist1=bfs(0,n+1);
            for(i=0;i<m;i++)
            {
                if(dist1[b[i]]!=-1)
                    dist1[b[i]]--;
                System.out.print(dist1[b[i]]+" ");
            }
            System.out.println();
        }
    }
}
