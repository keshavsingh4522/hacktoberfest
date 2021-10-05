import java.util.*;
class Graph_dfs
{
    private int V;
    private LinkedList <Integer> adj[];
    Graph_dfs(int v)
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

    void dfs_util(int v,boolean visited[])
    {
        visited[v]=true;
        System.out.println(v);
        Iterator <Integer> i=adj[v].listIterator();
        int n;
        while(i.hasNext())
        {
            n=i.next();
            if(!visited[n])
                dfs_util(n,visited);
        }
    }

    void dfs(int v)
    {
        boolean visited[]=new boolean[V];
        int z=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                dfs_util(i,visited);
                z++;
            }
        }

    }

    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        int x,s;
        x=d.nextInt();
        s=d.nextInt();
        Graph_dfs g=new Graph_dfs(x);
        g.addEdge(1,2);
        g.addEdge(1,3);
        g.dfs(s);
    }
}
