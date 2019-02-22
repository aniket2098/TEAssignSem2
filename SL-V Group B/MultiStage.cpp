#include<bits/stdc++.h> 
using namespace std; 
  
#define infinity INT_MAX 

class MultiStage {

    int noOfVertices;
    int noOfEdges;
    int **graph;
public:
    void input();
    int shortestDistance();
};

void MultiStage :: input() {

    cin >> noOfVertices;

    graph = new int*[noOfVertices];

    for(int i = 0; i < noOfVertices; i++) {

        graph[i] = new int[noOfVertices];

        for(int j = 0; j < noOfVertices; j++) {
            graph[i][j] = infinity;
        }
    }

    cin >> noOfEdges;

    for(int i = 0; i < noOfEdges; i++) {

        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source][destination] = weight;
    }
}

int MultiStage :: shortestDistance() { 
  
    int distance[noOfVertices]; 
  
    distance[noOfVertices-1] = 0; 
  
    for (int i = noOfVertices-2 ; i >= 0 ; i--) 
    {
        distance[i] = infinity; 
  
        for (int j = i ; j < noOfVertices ; j++) 
        { 
            if (graph[i][j] == infinity) 
                continue; 
  
            distance[i] = min(distance[i], graph[i][j] + distance[j]); 
        } 
    } 
  
    return distance[0]; 
}

int main() 
{ 

    MultiStage multiStage;
    multiStage.input();
    cout << "The length of the shortest path is :: " << multiStage.shortestDistance() << endl; 
    return 0; 
} 