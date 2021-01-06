/*
    Topological sorting using Kahn's BFS based algorithm
    for Acyclic Directed Graph

    In Topological sorting:
        - nodes( or vertex) are considered as job
        - edge are considered as dependency

    for ex : if there is a directed edge , v1 -> v2
            then v2 depend on v1, it can execute its job only
            after v1 finised .
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// function implementation topological sorting
void sort(vector<int> adj[], int V, int indegree[])
{
    queue<int> q; // make a queue

    // inserting vertexes with indegree zero
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) // while queue is not empty
    {
        int curr = q.front();
        q.pop();
        cout << curr << ' ';

        // traverse adjacent vertex of curr vertex
        for (int val : adj[curr])
        {
            if (indegree[val] != 0)
                indegree[val]--;

            if (indegree[val] == 0)
                q.push(val);
        }
    }
}

// function to add edge in adjacency list
void addEdge(vector<int> adj[], int u, int v, int indegree[])
{
    adj[u].push_back(v);
    indegree[v]++; // update the indegree
}

// function to print adjacency list
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "vertex " << i << " : ";
        for (int val : adj[i])
            cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    /*
        directed graph : 

          2 <-- 0 --> 3 <-- 1 --> 4
           \         /\  
            \________| 
    */

    int V = 5; // total number of vertexex

    vector<int> adj[V];
    int indegree[V] = {0};

    addEdge(adj, 0, 2, indegree); // 0 -> 2
    addEdge(adj, 0, 3, indegree); // 0 -> 3
    addEdge(adj, 2, 3, indegree); // 2 -> 3
    addEdge(adj, 1, 3, indegree); // 1 -> 3
    addEdge(adj, 1, 4, indegree); // 1 -> 4

    cout << "\nAdjacency List : \n";
    printGraph(adj, V);

    cout << "\nTopological sort : ";
    sort(adj, V, indegree);

    return 0;
}