// Implementation of Kosaraju's algorithm to print all Strongly Connected Components

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
public class Kosaraju
{
    Graph graph;
    Kosaraju(Graph graph){
        this.graph = graph;
    }
	// A recursive function to print DFS starting from v
	void DFS(Graph g, int v,boolean visited[])
	{
		visited[v] = true;
		System.out.print(v + " ");

		int n;
        
		Iterator<Integer> i = g.adjacencyList[v].iterator();
		while (i.hasNext())
		{
			n = i.next();
			if (!visited[n])
				DFS(g, n,visited);
		}
	}

	// Function that returns reverse of this graph
	Graph reverse()
	{
		Graph rev_graph = new Graph(graph.size);
		for (int v = 0; v < graph.size; v++)
		{
			Iterator<Integer> i = graph.adjacencyList[v].listIterator();
			while(i.hasNext())
				rev_graph.adjacencyList[i.next()].add(v);
		}
		return rev_graph;
	}

	void fillOrder(int v, boolean visited[], Stack stack)
	{
		visited[v] = true;

		Iterator<Integer> i = graph.adjacencyList[v].iterator();
		while (i.hasNext())
		{
			int n = i.next();
			if(!visited[n])
				fillOrder(n, visited, stack);
		}

		stack.push(v);
	}

	void printSCCs()
	{
		Stack stack = new Stack();

		boolean visited[] = new boolean[graph.size];
		for(int i = 0; i < graph.size; i++)
			visited[i] = false;

		for (int i = 0; i < graph.size; i++)
			if (visited[i] == false)
				fillOrder( i, visited, stack);

		Graph rev_graph = reverse();

		for (int i = 0; i < graph.size; i++)
			visited[i] = false;

		while (stack.empty() == false)
		{
			int v = (int)stack.pop();
			if (visited[v] == false)
			{
				DFS(rev_graph, v, visited);
				System.out.println();
			}
		}
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

		System.out.println("Strongly connected components are:\n");
		Kosaraju scc = new Kosaraju(graph);
        scc.printSCCs();
	}
}
