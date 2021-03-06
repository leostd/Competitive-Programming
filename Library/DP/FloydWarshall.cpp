/*
	Este algoritmo consigue el camino mas corto para cada par de nodos
	en un grafo.

	Complejidad en tiempo: O(V^3)
	Complejidad en espacio: O(V^2)
*/

#include <bits/stdc++.h>
#define V 4
#define INF 0x3f3f3f
using namespace std;

int graph[V][V] = 	{	{0, 5, INF, 10},
						{INF, 0, 3, INF},
						{INF, INF, 0, 1},
						{INF, INF, INF, 0}
					};

void printSolution(int dist[][V]){
	printf ("Following matrix shows the shortest distances"
	        " between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
	    for (int j = 0; j < V; j++)
	    {
	        if (dist[i][j] == INF)
	            printf("%7s", "INF");
	        else
	            printf ("%7d", dist[i][j]);
	    }
	    printf("\n");
	}
}

void floydWarshall(){
	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++){
		for (i = 0; i < V; i++){
			for (j = 0; j < V; j++){
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist);
}

int main(){
	floydWarshall();
	return 0;
}