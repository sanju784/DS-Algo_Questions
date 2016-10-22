/**
* To find Articulation Point or Cut Vertex
*
* Note : AP is for undirected graph
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
	void AP();
	void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

//ad graph is undirected adding edge to both points
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

//recursive function to find AP using DFS traversal
//u --> The vertex to be visited
//visted[] --> array to keep track of visited vertices
//disc[] --> stores discovery times of visited vertices
//parent[] --> stores parent vertices in DFS tree
//ap[] --> Store Articulation Point
void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
	static int time = 0;
	
	//Count of children in DFS tree
	int children = 0;
	
	//marking current vertex as visited
	visited[u] = true;
	
	//initializing discovery time and low value
	disc[u] = low[u] = ++time;
	
	//checking all vertices adjacent to current vertex
	list<int>::iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
		int v = *itr; //v is current adjacent to u
		
		//If v is not visited, then make it child of u in DFS tree and recur for it
		if(!visited[v])
		{
			children++;
			parent[v] = u;
			APUtil(v, visited, disc, low, parent,ap);
			
			//check if the subtree rooted with v has a connection to
			//one of the ancestor of u
			low[u] = min(low[u], low[v]);
			
			//u is an AP in following cases
			
			//(u) is root of DFS tree and has 2 more child
			if(parent[u] == NIL && children > 1)
				ap[u] = true;
			
			//(2) If u is not root and low value of one of its child is more
			//than discovery value of u
			if(parent[u] != NIL && low[v] >= disc[u])
				ap[u] = true;
		}
		
		//update low value of u for parent function calls
		else if(v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void Graph::AP()
{
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V];

	for(int i=0;i<V;i++)
	{
		parent[i] = NIL;
		visited[i] = false;
		ap[i] = false;
	}

	//calling the recursive helper function for every vertex one by one
	//to find AP in DFS tree rooted with vertex i
	for(int i=0;i<V;i++)
		if(visited[i] == false)
			APUtil(i, visited, disc, low, parent, ap);

	//the ap[] now contains the AP
	for(int i=0;i<V;i++)
		if(ap[i] == true)
			cout<<i<<" ";
}

int main()
{
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(0,3);
	g.addEdge(3,4);
	cout<<"The AP are ";
	g.AP();
	return 0;
}