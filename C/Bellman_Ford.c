#include <stdio.h>  //including standard i/o library
#include <stdlib.h> //to dynamic allocation
#include <limits.h> //to get max values

//structre to store details of each edge of the graph
struct Edge
{
    //directed edges containing source and destination and a weight
    int source, destination, weight;
};

//structure to represent a Weighted Directed Graph
struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct Graph* makeGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));    //Allocating space to structure graph
    //assigning values to structure elements that taken form user.
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof( struct Edge ) );

    return graph;
}

void show(int dist[], int nV, int src)
{
    int i;  //declaring local variables
    printf("\nThe Distance from Source Vertex %d--- \n",src);
    for (i = 0; i < nV; ++i){
        printf("to Vertex %d is %d\n", i, dist[i]);
}
}

void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
    int E = graph->E;

    int dis[V];
    int i,j;

     //We initialize all distance to infinity except source.
    for (i = 0; i < V; i++)
        dis[i] = INT_MAX;   //to achieve the max possible value of 'int' datatype

    // We assign source distance 0, as the distance from source vertex to itself is always 0.
    dis[source] = 0;

    //The shortest path of graph that contain V vertices,will never contain "|V|-1" edges. Thus we do "|V|-1" relaxations here
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;

            if (dis[u] + weight < dis[v])
                    dis[v] = dis[u] + weight;
        }
    }


    //As BellmanFord does not work if a negative edge cycle exists,we try to relax for another time ie. |V|th time
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;

        // If we get a shorter path, then there is a negative edge cycle.
        if (dis[u] + weight < dis[v]){
            printf("\nNegative Edge Cycle Exists -- Not Possible\n");
            return;
        }
    }

    show(dis, V, source);
}

int main()
{
    int nV,nE,src;  //nV = Number of Vertices, nE = Number of Edges, src is source vertex
    int i=0;
    printf("Number of vertices : ");
    scanf("%d",&nV);

    printf("Number of edges : ");
    scanf("%d",&nE);

    printf("Source Vertex :  ");
    scanf("%d",&src);

    struct Graph* graph = makeGraph(nV, nE);    //calling the function to allocate space to these many vertices and edges
    //the initial vertex is 0
    for(;i<nE;i++){
        printf("\nDetails of Edge %d --- \n",i+1);
        printf("\tSource : ");      //the source of the edge
        scanf("%d",&graph->edge[i].source);
        printf("\tDestination : ");     //the destination of the edge
        scanf("%d",&graph->edge[i].destination);
        printf("\tWeight : ",i+1);      //the weight associated with the edge
        scanf("%d",&graph->edge[i].weight);
    }

    BellmanFord(graph, src); //passing created graph and source vertex to BellmanFord Algorithm function

    return 0;
}
//end of program
//Contributed by Dipanjan Dutta
