// Implementation of adjacency list using vector

#include <iostream>
#include <vector>

using namespace std;

// function to add edge in a undirected graph
void addEdge(vector<int> adj[], int v, int u)
{
    // one edge fills two cell
    adj[v].push_back(u);
    adj[u].push_back(v);
}

// function to print graph
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int val : adj[i])
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    /*
           0  ----  1 ----- 3
            \      /
             \    /
               2
    */

    int v = 4;
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    printGraph(adj, v);
    return 0;
}