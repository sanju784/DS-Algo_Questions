/**
 * Detect Cycle in an undirected graph
 * 
 * (1) Can be done by DFS           O(E+V) time
 * (2) Can be done by Disjoint sets O(ELogV) time
 *
 * Here using DFS method
 * (Here for any vertex v, if there is an adjacent u
 * such that u is already visited and u is not parent v
 * then the graph has a cycle)
 */
 
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	
public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isCyclic();
	bool isCyclicUtil(int v, bool visited[], int parent);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

//for undirected graph
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

//function that uses visited[] and parent to detect cycle 
//in subgraph that is reachable from vertex v 
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	//marking current vertex as visited
	visited[v] = true;
	
	//checking for adjacent vertex of v 
	list<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		//If an adjacent is not visited recur for that adjacent
		if(!visited[*itr])
		{
			if(isCyclicUtil(*itr, visited, v))
				return true;
		}
		//If adjacent is visited and not parent of current vertex then there is a cycle
		else if(*itr != parent)
			return true;
	}
	return false;
}

bool Graph::isCyclic()
{
	//initailize all vertex as not visited
	bool* visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;
	
	//Calling recursive function for every unvisited vertex
	for(int u=0;u<V;u++)
		if(!visited[u])
			if(isCyclicUtil(u, visited, -1))
				return true;
			
	return false;
}

int main()
{
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(2,0);
	g.addEdge(0,3);
	g.addEdge(3,4);
	g.isCyclic()?cout<<"Graph has cycles":
				 cout<<"Graph does not have cycles";
}