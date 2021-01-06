/*
    program to detect cycle in directed graph using DFS of Graph ;
*/

#include <iostream>
#include <vector>
using namespace std;

// dfs
bool dfs(vector<int> adj[], int i, bool visited[], bool rec_st[])
{
    visited[i] = true; // mark i as visited
    rec_st[i] = true;  // mark entry of i in stack true

    for (int val : adj[i])
    {
        if (visited[val] == false && dfs(adj, val, visited, rec_st))
            return true;
        else if (rec_st[val] == true) // if val is already visited and its entry stack is true
            return true;              // cycle exist
    }
    rec_st[i] = false; // vertex 'i' call is over, mark its entry in stack as false
    return false;
}

// traverse dfs
bool traverse_dfs(vector<int> adj[], int v)
{
    bool visited[v] = {false}; // to check vertex is already visited or not
    bool rec_st[v] = {false};  // recursion stack, to check vertex is already in stack or not

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            if (dfs(adj, i, visited, rec_st) == true)
                return true;
    }
    return false;
}

// function adding Edge in adjacency list
void addEdge(vector<int> adj[], int v, int u) // v - first vertex, u - second vertex
                                              // edge from v -> u
{
    adj[v].push_back(u);
}

// function to print adjacency list
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Vertex : " << i << " : ";
        for (int val : adj[i])
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    /*
        0 -> 1 <- 2 -> 3 -> 4
                        ^   |
                         \  \/
                           5

    */
    int v = 6; // total number of vertex
    vector<int> adj[v];

    addEdge(adj, 0, 1); // 0 -> 1
    addEdge(adj, 2, 1); // 2 -> 1
    addEdge(adj, 2, 3); // 2 -> 3
    addEdge(adj, 3, 4); // 3 -> 4
    addEdge(adj, 4, 5); // 4 -> 5
    addEdge(adj, 5, 3); // 5 -> 3

    cout << "\nAdjacency List : \n";
    printGraph(adj, v);

    cout << "\nIs Cycle exist in Graph ? : " << boolalpha << traverse_dfs(adj, v);

    return 0;
}