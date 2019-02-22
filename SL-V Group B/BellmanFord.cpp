#include <bits/stdc++.h> 

#define MAX INT_MAX  

using namespace std;
     
class Path {
    
    struct noOfEdgesdge 
    { 
        int source, destination, weight; 
    }; 
        
    typedef struct Graph 
    { 
        int noOfVertices, noOfEdges;
        struct noOfEdgesdge* edge; 
    }Graph;
    Graph* graph;
    int* distance;
public:
    Path(int,int);
    void display();
    void BellmanFord(int);
};
 
Path :: Path(int noOfVertices, int noOfEdges)
{ 
    graph = new Graph; 
    graph->noOfVertices = noOfVertices; 
    graph->noOfEdges = noOfEdges;

    graph->edge = new noOfEdgesdge[noOfEdges]; 

    for(int i = 0; i < noOfEdges; i++) {

        cin >> graph->edge[i].source >> graph->edge[i].destination >> graph->edge[i].weight;
    }

    distance = new int[noOfVertices];
}

void Path :: display() 
{ 
    printf("Vertex     Distance\n"); 
    for (int i = 0; i < graph->noOfVertices; ++i) 
        printf("%d \t|\t %d\n", i, distance[i]); 
} 
  
void Path :: BellmanFord(int source) 
{ 
    int noOfVertices = graph->noOfVertices; 
    int noOfEdges = graph->noOfEdges;
  
    for (int i = 0; i < noOfVertices; i++) 
        distance[i]   = MAX; 
    distance[source] = 0; 
  
    for (int i = 1; i <= noOfVertices-1; i++) 
    { 
        for (int j = 0; j < noOfEdges; j++) 
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (distance[u] != MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }
  
    for (int i = 0; i < noOfEdges; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (distance[u] != MAX && distance[u] + weight < distance[v])
            printf("Negative weight cycle present!\n");
    }
  
    display();
  
    return; 
} 
  
int main() 
{ 
    int noOfVertices, noOfEdges, source;
    cin >> noOfVertices >> noOfEdges >> source;
    Path path(noOfVertices, noOfEdges);
    path.BellmanFord(source); 
  
    return 0; 
} 