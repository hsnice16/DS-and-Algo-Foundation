// program to check cycle is present or not in an undirected graph

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (int val : adj[s])
    {
        if (visited[val] == false)
            if (dfs(adj, val, visited, s) == true)
                return true;
            else if (val != parent)
                return true;
    }
    return false;
}

bool traverse_dfs(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            if (dfs(adj, i, visited, -1) == true)
                return true;
    }
    return false;
}

// function of adding Edge in adjacency list
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// function to print graph
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Vertex " << i << " : ";
        for (int val : adj[i])
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    /*
        0 -- 1 -- 2 -- 4 -- 5
              \  /
               3
    */

    int v = 6; // total number of vertex
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);

    cout << "\nAdjacency List : \n";
    printGraph(adj, v);

    cout << "\nCycle present in Graph or not ? " << boolalpha << traverse_dfs(adj, v) << endl;

    return 0;
}