/*
    Program to detect cycle in Directed Graph using Kahn's Algorithm
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// function checking cycle exist or not
bool check_cycle(vector<int> adj[], int V, int indegree[])
{
    queue<int> q; // make a queue

    // inserting vertexes with indegree zero
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty()) // while queue is not empty
    {
        int curr = q.front();
        count++; // count how many elements comes out of queue
        q.pop();

        // traverse adjacent vertex of curr vertex
        for (int val : adj[curr])
        {
            if (indegree[val] != 0)
                indegree[val]--;

            if (indegree[val] == 0)
                q.push(val);
        }
    }

    return (count != V);
}

// function adding edge in adjacency list
void addEdge(vector<int> adj[], int v, int u, int indegree[]) // directed edge, v -> u
{
    adj[v].push_back(u);
    indegree[u]++;
}

// print adjacency list
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

        0 ->  1  -> 2
             ^ ^    |
             |   \ \/
             4     3

    */

    int v = 5; // total number of vertex
    vector<int> adj[v];
    int indegree[v] = {0};

    addEdge(adj, 0, 1, indegree); // 0 -> 1
    addEdge(adj, 1, 2, indegree); // 1 -> 2
    addEdge(adj, 2, 3, indegree); // 2 -> 3
    addEdge(adj, 3, 1, indegree); // 3 -> 1
    addEdge(adj, 4, 1, indegree); // 4 -> 1

    cout << "\nAdjacency List : \n";
    printGraph(adj, v);

    cout << "\nCycle exist in Graph or not ? : " << boolalpha << check_cycle(adj, v, indegree);

    return 0;
}