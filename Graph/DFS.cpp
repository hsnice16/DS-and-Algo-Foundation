/*
    Depth First Search of Graph
        - Recursive in nature
*/

#include <iostream>
#include <vector>
using namespace std;

// function for Depth First Search traversing of Graph
void DFS(vector<int> adj[], int s, bool visited[]) // s - source vertex
{

    visited[s] = true; // marked source as visited
    cout << s << ' ';  // print source vertex

    // recursive call for adjacent vertex of source vertex
    for (int val : adj[s])
    {
        if (visited[val] == false)
        {
            DFS(adj, val, visited);
        }
    }

    return;
}

// function doing prior job to call DFS
void traverse_dfs(vector<int> adj[], int s, int v)
{
    bool visited[v]; // to check vertex is already in queue or not
                     // using so no vertex printed more than one

    // initializing visited
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    DFS(adj, s, visited);
}

// function adding Edge in adjacency list
void addEdge(vector<int> adj[], int v, int u) // v - first vertex, u - second vertex
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

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
             0
            / \
           1   4
           |  / \
           2 5 - 6
           |
           3
    */

    int v = 7; // total number of vertex
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    cout << "\nAdjacency List : \n";
    printGraph(adj, v);

    cout << "\nDepth First Search : ";
    int s = 0;
    traverse_dfs(adj, s, v);

    return 0;
}

/*
    Few Applications of DFS : 
    1) Cycle Detection
    2) Topological Sorting
    3) Strongly Connected components
    4) Solving maze and similar puzzles
    5) Path Finding
*/