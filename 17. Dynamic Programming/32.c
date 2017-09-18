/**
 * Floyd's Warshall Algorithm
 * This algorithm is to find shortest path b/w any pair of nodes
 */
#include <stdio.h>
#include <limits.h>

#define INF 99999
#define V 4

void printSolution(int dist[][V])
{
	printf("Shortest distance Result\n\n");
	int i, j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			if(dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

//here the solution used is
// if(d[i][j] > d[i][k]+d[k][j])
//	   d[i][j] = d[i][k]+d[k][j]
//otherwise d[i][j] = d[i][j]
//here k means that if we are going through node k 
//then we are checking if we go through k then is distance less or more

void floydWarshall(int graph[][V])
{
	//dist is the solution matrix
	int dist[V][V],i,j,k;
	
	//initialize distance matrix same as graph as 
	//when d[i][j] <= d[i][k]+d[k][j] then d[i][j] will be equal to d[i][j]
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			dist[i][j] = graph[i][j];
		
	for(k=0;k<V;k++)
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	printSolution(dist);
}

void main()
{
	int graph[V][V] = { 
			{0,   5,     INF, 10},
			{INF, 0,     3,  INF},
			{INF, INF,   0,    1},
			{INF, INF, INF,    0}
			};
					   
	floydWarshall(graph);
}
