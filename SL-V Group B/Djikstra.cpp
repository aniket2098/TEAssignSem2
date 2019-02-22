#include <bits/stdc++.h>

using namespace std;

#define V 10

typedef struct gnode {
 	string name;
 	int vid;
}gnode;

int insertVertex(gnode vertices[10]) {
	int n;
	cout<<"\nEnter no. of vertices: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter city name: ";
		cin>>vertices[i].name;
		vertices[i].vid=i;
	}
	return n;
}

void insertEdge(int graph[][V],int n) {
	for(int i=0;i<n;i++)
	{
		int n;
		cout<<"\nEnter no. of cities connected to city number "<<i+1<<"(Exclude previously entered cities): ";
		cin>>n;
		cout<<"\nEnter the end points: \n";
		for(int j=0;j<n;j++)
		{
			int temp;
			cout<<j+1<<" edge: ";
			cin>>temp;
			cout<<"\nEnter cost: ";
			cin>>graph[i][temp-1];
			graph[temp-1][i] = graph[i][temp-1];
			cout<<"\n";
		}
	}
}

int minimumDistance(int distance[],bool visited[],int n) {
	int min=INT_MAX;
	int index;
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && distance[i]<min)
		{
			min=distance[i];
			index=i;
		}
	}
	return index;
}

void print(int distance[],int n) {
	cout<<"Vertex\tDistance from src\n";
	for(int i=0;i<n;i++)
	{
		cout<<i<<"\t"<<distance[i]<<"\n";
	}
}

void djikstra(int graph[V][V],int src,int n) {
	bool visited[n];
	int distance[n];

	for(int i=0;i<n;i++)
	{
		visited[i]=0;
		distance[i]=INT_MAX;
	}

	distance[src]=0;

	for(int i=0;i<n-1;i++)
	{
		int unvisitedShort=minimumDistance(distance,visited,n);
		visited[unvisitedShort]=1;

		for(int i=0;i<n;i++)
		{
			if(!visited[i] && graph[unvisitedShort][i] && distance[unvisitedShort]+graph[unvisitedShort][i] < distance[i] && distance[unvisitedShort]!=INT_MAX)
				distance[i]=graph[unvisitedShort][i] + distance[unvisitedShort];
		}
	}
	print(distance,n);
	distance[src]=0;

}

int main() {
	int n;
	gnode vertices[10];
	int graph[V][V]={0};
	n=insertVertex(vertices);
	insertEdge(graph,n);
	djikstra(graph,0,n);
	return 0;
}