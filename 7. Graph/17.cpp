/**
 * Check Euler in undirected graph
 */

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);

    //method to check if graph is Eulerian
    int isEulerian();

    //To check if all non-zero degree vertices are connected
    bool isConnected();

    //to start DFS from vertex v
    void DFSUtil(int v, bool visited[]);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

//edge for undirected graph
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
        if(!visited[*itr])
            DFSUtil(*itr, visited);
}

//To check if all non-zero degree vertices are connected
bool Graph::isConnected()
{
    bool visited[V];
    int i;
    for(i=0;i<V;i++)
        visited[i]=false;

    //Find a vertex with non-zero degree
    for(i=0;i<V;i++)
        if(adj[i].size() != 0)
            break;

    //If there are no edge in the graph, return true
    if(i==V)
        return true;

    //start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);

    //check if all non-zero degree vertices are visited
    for(int i=0;i<V;i++)
        if(visited[i] == false && adj[i].size() > 0)
            return false;

    return true;
}

//The function return following values
//0 --> If graph is not Eulerian
//1 --> If graph has a Euler Path (Semi-Eulerian)
//2 --> If graph has a Euler circuit (Eulerian)
int Graph::isEulerian()
{
    //Check if all non-zero degree vertices are connected
    if(isConnected() == false)
        return 0;

    //count vertices with odd degree
    int odd=0;
    for(int i=0;i<V;i++)
        if(adj[i].size() & 1)
            odd++;

    //If count is more than 2 then graph is not Eulerian
    if(odd > 2)
        return 0;

    //If odd count is 2, then semi-Eulerian
    //If odd count is 0, then Eulerian
    //Note that odd count can never be 1 for undirected graph
    return odd?1:2;
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    int res = g.isEulerian();
    if(res==0)
        cout<<"Graph is not Eulerian";
    else if(res==1)
        cout<<"Graph has a Euler path";
    else
        cout<<"Graph has a Euler cycle";
    return 0;
}
