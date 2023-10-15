import java.util.*;

public class Prim_Algorithm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertex = sc.nextInt();
        int edge = sc.nextInt();
        int mat[][] = new int[vertex][vertex];
        for (int i = 0; i < edge; i++) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            int weight = sc.nextInt();
            mat[src][dest] = weight;
            mat[dest][src] = weight;
        }

        // for (int i = 0; i < vertex; i++) {
        // for (int j = 0; j < vertex; j++) {
        // System.out.print(mat[i][j]);
        // }
        // System.out.println();
        // }

        /*
         * 5 7 0 1 4 0 2 8 1 2 2 1 3 6 3 2 3 2 4 9 3 4 5
         */

        sc.close();

        int[] parent = new int[vertex];
        int[] weight = new int[vertex];
        Arrays.fill(weight, Integer.MAX_VALUE);
        weight[0] = 0;

        boolean[] visited = new boolean[vertex];

        for (int i = 0; i < vertex; i++) {
            if (visited[i])
                continue;
            prims(mat, vertex, parent, weight, visited);
        }

        for (int i = 0; i < vertex; i++) {
            System.out.println(i + " " + parent[i] + " " + weight[i]);
        }

    }

    static void prims(int mat[][], int vertex, int[] parent, int[] weight, boolean[] visited) {
        int min = -1;
        int temp = Integer.MAX_VALUE;

        for (int i = 0; i < vertex; i++) {
            if (temp > weight[i] && !visited[i]) {
                temp = weight[i];
                min = i;
            }
        }

        if (min == -1)
            return;

        visited[min] = true;

        for (int i = 0; i < vertex; i++) {
            if (mat[min][i] == 0)
                continue;
            if (weight[i] > mat[min][i] && !visited[i]) {
                weight[i] = mat[min][i];
                parent[i] = min;
            }
        }

    }

}
