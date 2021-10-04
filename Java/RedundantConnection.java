import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class ReduntantEdge {
    public static void main(String[] args){
        int[][] conn = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
        System.out.println(Arrays.toString(new ReduntantEdge().findRedundantConnection(conn)));
    }
    int findParent(Map<Integer, Integer> parentMap, Integer child){
        if(parentMap.get(child).equals(child)) return child;
        parentMap.put(child, findParent(parentMap, parentMap.get(child)));
        return parentMap.get(child);
    }
    public int[] findRedundantConnection(int[][] edges) {
        Map<Integer, Integer> parentMap = new HashMap<>();
        for(int[] edge : edges) {
            parentMap.put(edge[0], edge[0]);
            parentMap.put(edge[1], edge[1]);
        }
        for(int[] edge: edges){
            Integer p1 = findParent(parentMap, edge[0]);
            Integer p2 = findParent(parentMap, edge[1]);
            if(p1.equals(p2)) {
                return new int[]{edge[0], edge[1]};
            }
            else parentMap.put(p1, p2);
        }
        return new int[]{};
    }

    public int findParent(int[] par, int i) {
        if(par[i] == i) return i;
        return par[i] = findParent(par, par[i]);
    }
    public int[] findRedundantConnectionUF(int[][] connections) {
        int[] parent = new int[connections.length+1];
        for(int i = 1; i <= connections.length; i++) parent[i] = i;
        for(int[] connection : connections) {
            int p1 = findParent(parent, connection[0]);
            int p2 = findParent(parent, connection[1]);
            if(p1 == p2){
                return new int[]{connection[0], connection[1]};
            }
            else parent[p1] = p2;
        }
        return new int[]{};
    }
}
