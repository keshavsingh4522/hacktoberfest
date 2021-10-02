
import java.util.Scanner;

class MstKruskal {                      //mst -> minimum spanning tree
    void kruskal(int cost[][], int n){
        int [] par = new int[n];
        for(int i=0;i<n;i++){
            par[i]= -1;
        }
        int a=0, b=0, u=0, v=0, mincost=0, min, ne =0;
        System.out.println("MST edges are: ");
        while(ne < n-1) {
            min = 999;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(cost[i][j]< min){
                        min = cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
            while(par[u]!= -1)
                 u = par[u];
            if(u!=v) {
                System.out.println("from vertex "+a+" to vertex "+b+" and the cost = "+min);
                System.out.println(a+"----->"+b+" with cost= "+min);
                mincost+=min;
                par[b] = a;
                ne++;
            }
            cost[a][b] = cost[b][a] = 999;
        }
        System.out.println("cost of mst = "+mincost);
    }
}
public class KruskalAlgo {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");
        int n = s.nextInt();
        int c[][] = new int[n][n];
        System.out.println("Enter the cost of matrix: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c[i][j] = s.nextInt();
            }
        }
        System.out.println("Enter the source node: ");
        int source = s.nextInt();
        MstKruskal obj = new MstKruskal();
        obj.kruskal(c, n);
    }   
}
