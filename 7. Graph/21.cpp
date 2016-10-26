/**
 * Find Spanning tree
 */

#include <bits/stdc++.h>
using namespace std;

#define V 5

int minKey(bool mstSet[])
{
    for(int v=0;v<V;v++)
        if(mstSet[v] == false)
            return v;
}

void printMST(int parent[], int n, int graph[V][V])
{
    cout<<"Edge\tWeight\n";
    for(int i=1;i<V;i++)
        cout<<parent[i]<< " - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
}

void MST(int graph[V][V])
{
    int parent[V];
    bool mstSet[V];

    for(int i=0; i<V;i++)
        mstSet[i] = false;
    parent[0] = -1;

    for(int count=0;count<V;count++)
    {
        int u = minKey(mstSet);
        mstSet[u] = true;

        for(int v=0;v<V;v++)
            if(graph[u][v] && mstSet[v] == false)
                parent[v]=u;
    }

    printMST(parent, V, graph);
}

int main()
{
    int graph[V][V] = {
                      {0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    MST(graph);
}
