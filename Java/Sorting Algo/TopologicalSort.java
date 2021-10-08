// Implementation of Topological Sort
import java.util.*; 

class Graph
{
// Adjacency List representation of Graph
    int size; 
	LinkedList<Integer> adjacencyList[];

	Graph(int n)
	{
		size = n;
		adjacencyList = new LinkedList[n];
		for (int i=0; i<n; ++i)
			adjacencyList[i] = new LinkedList();
	}

	void addEdge(int v, int w) 
    { 
        adjacencyList[v].add(w); 
    }
}

public class TopologicalSort 
{
    Graph graph;
    TopologicalSort(Graph graph){
        this.graph = graph;
    }
    
    void topologicalSortUtil(int v, boolean visited[], Stack stack) 
    { 
        visited[v] = true; 
        Integer i;

        Iterator<Integer> it = graph.adjacencyList[v].iterator(); 
        while (it.hasNext()) 
        { 
            i = it.next(); 
            if (!visited[i]) 
                topologicalSortUtil(i, visited, stack); 
        } 

        stack.push(v); 
    }

    void topologicalSort() 
    { 
        Stack stack = new Stack(); 
  
        boolean visited[] = new boolean[graph.size]; 
        for (int i = 0; i < graph.size; i++) 
            visited[i] = false; 
  
        for (int i = 0; i < graph.size; i++) 
            if (visited[i] == false) 
                topologicalSortUtil(i, visited, stack); 
  
        while (stack.empty()==false) 
            System.out.print(stack.pop() + " "); 
    } 
  
    public static void main(String args[]) 
    { 

        Graph graph = new Graph(9);
		graph.addEdge(0, 3);
		graph.addEdge(1, 7);
		graph.addEdge(2, 5);
		graph.addEdge(3, 6);
		graph.addEdge(4, 1);
        graph.addEdge(5, 8);
        graph.addEdge(6, 0);
        graph.addEdge(7, 4);
        graph.addEdge(7, 5);
        graph.addEdge(8, 6);
        graph.addEdge(8, 2);
  
        System.out.println("Topological sort of the given graph:"); 
        TopologicalSort obj = new TopologicalSort(graph);
        obj.topologicalSort(); 
    } 
} 