/**
 * Euler for directed graph
 */

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    int *in; //counter for in-degree of a vertex
public:
    Graph(int V);
    void addEdge(int u, int v);

    //method to check if graph is Eulerian
    int isEulerianCycle();

    //To check if all non-zero degree vertices are connected
    bool isSC();

    //to start DFS from vertex v
    void DFSUtil(int v, bool visited[]);

    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for(int i=0;i<V;i++)
        in[i]=0;
}

//edge for undirected graph
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    (in[v])++;
}

//returns true if the directed graph has an eulerian cycle
bool Graph::isEulerianCycle()
{
    //check if all non-zero vertices are connected
    if(isSC() == false)
        return false;

    //check if in-degree and out-degree of every vertex is same
    for(int i=0;i<V;i++)
        if(adj[i].size() != in[i])
            return false;

    return true;
}

//DFS starting from vertex v
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator itr;

    for(itr=adj[v].begin(); itr != adj[v].end(); itr++)
        if(!visited[*itr])
            DFSUtil(*i, visited);
}

//return reverse (or Transpose) of this graph
Graph Graph::getTranspose()
{
    Graph g(V);
    for(int v=0;v<V;v++)
    {
        //recur for all vertices adjacent to this vertex
        list<int>::iterator itr;
        for(itr = adj[v].begin();itr != adj[v].end(); itr++)
        {
            g.adj[*i].push_back(v);
            (g.in[v])++;
        }
    }
    return g;
}

//returns true if all non-zero degree vertices of graph are strongly connected
bool Graph::isSc()
{
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

        //Find first vertex with non-zero degree
    int n;
    for(n=0;n<V;n++)
        if(adj[n].size() > 0)
            break;

    // Do DFS traversal starting from first non zero degree vertex.
    DFSUtil(n,visited);

    // If DFS traversal doesn't visit all vertices, then return false.
    for(int i=0;i<V;i++)
        if(adj[i].size() > 0 && visited[i] == false)
            return false;

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i=0;i<V;i++)
        visited[i] = false;

    // Do DFS for reversed graph starting from first vertex.
    // Staring Vertex must be same starting point of first DFS
    gr.DFSUtil(n, visited);

    // If all vertices are not visited in second DFS, then return false
    for(int i=0;i<V;i++)
        if(adj[i].size() > 0 && visited[i] == false)
            return false;

    return true;
}


int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if (g.isEulerianCycle())
       cout << "Given directed graph is eulerian n";
    else
       cout << "Given directed graph is NOT eulerian n";
    return 0;
}
