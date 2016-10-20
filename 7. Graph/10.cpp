/**
 * Program to check if there is a path from Source s to Destination d
 */

#include <bits/stdc++.h>
using namespace std;

//directed graph using adjacency list
class Graph
{
    int V; //No. of vertex
    list<int> *adj; //list of pointer for adjacency list

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isReachable(int s, int d);
};

//constructor to initialize total vertex and adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V]; //array of list to save adjacent node
}

//add edge to the graph
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

//A BSG based function to check for path from s to d
bool Graph::isReachable(int s, int d)
{
    if(s==d)
        return true;

    //initially all vertex unvisited
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    //queue to perform BFS operation(list can work both as stack and queue)
    list<int> q;

    //marking source node as visited and adding it to queue
    visited[s] = true;
    q.push_back(s);

    //iterator to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!q.empty())
    {
        //getting vertex from queue
        s = q.front();
        q.pop_front();

        //getting all adjacent vertices of the dequeued vertex
        //if adjacent vertex is not visited then marking it as visited and adding it to queue
        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            //checking if adjacent node is the destination node
            if(*i == d)
                return true;

            //adding unvisited adjacent node to the queue and marking as visited
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    int s=1, d=3;
    if(g.isReachable(s, d))
        cout<<"\nThere is Path from "<<s<<" to "<<d;
    else
        cout<<"\nNo Path exits from "<<s<<" to "<<d;

    s=3, d=1;
    if(g.isReachable(s, d))
        cout<<"\nThere is Path from "<<s<<" to "<<d;
    else
        cout<<"\nNo Path exits from "<<s<<" to "<<d;

    return 0;
}
