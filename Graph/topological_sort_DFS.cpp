/*
    topological sorting using DFS traversal of Graph
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// dfs travel
void dfs(vector<int> adj[], int s, stack<int> &stk, bool visited[])
{
    visited[s] = true; // mark s as visited

    // for every adjacent of s
    for (int val : adj[s])
        if (visited[val] == false)
            dfs(adj, val, stk, visited);

    // push s on stack
    stk.push(s);
}

// function performing sorting
void topo_sort(vector<int> adj[], int V)
{
    stack<int> stk; // first created a stack
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            dfs(adj, i, stk, visited);

    // print stack
    while (!stk.empty())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }
}

// function adding edge in adjacency list
void addEdge(vector<int> adj[], int v, int u) // v -> u
{
    adj[v].push_back(u);
}

// function to print adjacency list
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i + 1 << " : ";
        for (int val : adj[i])
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    /*
            Directed Acyclic Graph

            0 --> 1 --> 3 --> 4
                        /\   /\
                         |   /
                          2
    */

    int V = 5; // total number of vertex
    vector<int> adj[V];

    addEdge(adj, 0, 1); // 0 -> 1
    addEdge(adj, 1, 3); // 1 -> 3
    addEdge(adj, 2, 3); // 2 -> 3
    addEdge(adj, 2, 4); // 2 -> 4
    addEdge(adj, 3, 4); // 3 -> 4

    cout << "\nAdjacency List : \n";
    printGraph(adj, V);

    cout << "\nTopological Sort : " ;
    topo_sort(adj, V);

    return 0;
}