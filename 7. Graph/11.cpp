/**
 * To get total Path from source s to destination d
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
    int getTotalPath(int s, int d);
    int getTotalPathUtil(int s, int d, bool *visited);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

int Graph::getTotalPathUtil(int s, int d, bool *visited)
{
    static int count = 0;
    visited[s] = true;
    if(s==d)
        count++;
    else
    {
        list<int>::iterator i;
        for(i=adj[s].begin(); i!=adj[s].end(); i++)
            if(!visited[*i])
                getTotalPathUtil(*i,d,visited);
    }
    visited[s] = false;
    return count;
}

int Graph::getTotalPath(int s, int d)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    return getTotalPathUtil(s, d, visited);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    int s=2, d=3;
    cout<<"Total Path "<<g.getTotalPath(s,d);
    return 0;
}
