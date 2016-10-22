/**
 * To find Bridge or Cut vertex
 */
#include <bits/stdc++.h>
using namespace std;

#define NIL -1

class Graph
{
	int V;
	list<int> *adj;
	
public:
	Graph(int V);
	void addEdge(int u, int v);
	void bridge();
	void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

//recursive function to print all bridges using DFS traversal
//u --> vertex to be visited
//visited[] ---> keep set of visted vertex
//disc[] --> stores discovery time of visited vertices
//parent[] --> stores parent vertices in DFS
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
	static int time = 0;
	
	//marking current vertex as visited
	visited[u] = true;
	
	//initialize discovery time and low value
	disc[u] = low[u] = ++time;
	
	//Check for all vertices adjacent to current vertex
	list<int>::iterator itr;
	for(itr=adj[u].begin(); itr != adj[u].end(); itr++)
	{
		int v = *itr;
		
		//if v is not visited recur for it
		if(!visited[v])
		{
			parent[v] = u;
			bridgeUtil(v, visited, disc, low, parent);
			
			//check if subtree rooted with v has a 
			//connection to one of ancestor of u 
			low[u] = min(low[u], low[v]);
			
			//If lowest vertex reachable from subtree
			//under v is below u in DFS tree, then u-v is a bridge
			if(low[v] > disc[u])
				cout<<u<<" "<<v<<endl;
		}
		//update low value of u for parent function call
		else if(v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void Graph::bridge()
{
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	
	//initialize parent and visited array
	for(int i=0;i<V;i++)
	{
		parent[i] = NIL;
		visited[i] = false;
	}
	
	//searching the bridge for all vertex one by one
	for(int i=0;i<V;i++)
		if(visited[i] == false)
			bridgeUtil(i, visited, disc, low, parent);
}

int main()
{
	Graph g(5);
	g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
	
	cout<<"Bridges are "<<endl;
    g.bridge();
}