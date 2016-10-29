/**
 * To find cycle in Directed Graph
 *
 * Algoritm by using white, grey and black set
 * Solution by DFS
 * This is done by using DFS tree and check for the presence of back edge in tree
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
	bool isCycle();
	bool isCycleUtil(int v, bool visited[], bool *rs);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

//for directed graph
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

bool Graph::isCycleUtil(int v, bool visited[], bool *recStack)
{
	if(visited[v] == false)
	{
		//marking current vetex as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;
		
		//recur for vertex adjacent to current vertex
		list<int>::iterator itr;
		for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
		{
			if(!visited[*itr] && isCycleUtil(*itr, visited, recStack))
				return true;
			else if(recStack[*itr])
				return true;
		}
	}
	recStack[v] = false;
	return false;
}

bool Graph::isCycle()
{
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	
	//Marking all vertex as unvisited and all 
	//all recursion as false such that no back edge exists
	for(int i=0;i<V;i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	
	//checking DFS for all vertex
	for(int i=0;i<V;i++)
		if(isCycleUtil(i, visited, recStack))
			return true;
	
	return false;
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	
	g.isCycle()?cout<<"Graph has cycles":cout<<"Graph has no cycles";
}