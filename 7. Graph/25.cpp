/**
 * Find depth of DAG
 * For undirected graph all graph is same
 * except that a visited set must also be maintained
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
    int getDepth(int);
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

int Graph::getDepth(int root)
{
    queue<int> q;
    q.push(root);
    q.push(-1);
    int count = 1;
    list<int>::iterator itr;
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        if(tp == -1)
        {
            count++;
            if(!q.empty())
                q.push(-1);
        } else {
            for(itr = adj[tp].begin(); itr != adj[tp].end(); itr++)
            {
                    q.push(*itr);
            }
        }
    }
    return count;
}

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    cout<<"Depth of Graph is "<<g.getDepth(1);
    return 0;
}
