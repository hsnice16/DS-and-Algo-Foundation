/*
    connected component : a graph where every node reachable

    for example :
    I/P :
             0      3      5
           /  \     |     / \
          1 -- 2    4    6   7
                             |
                             8
    O/P : 3 
            there are 3 connected components
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<int> adj[], int s, bool visited[]) // s - source vertex
{
    queue<int> q;      // make a queue
    q.push(s);         // push source vertex in queue
    visited[s] = true; // marked source as visited

    while (!q.empty()) // while queue is not empty
    {
        int curr = q.front(); // get front vertex in queue
        q.pop();              // pop front vertex in queue
        cout << curr << ' ';  // print curr vertex, popped from queue

        // push adjacent vertex of curr vertex
        for (int val : adj[curr])
        {
            if (visited[val] == false)
            {
                visited[val] = true;
                q.push(val);
            }
        }
    }
}

// may or may not disconnected
int BFSDis(vector<int> adj[], int v)
{
    int count = 0;   // to count component
    bool visited[v]; // to check vertex is already in queue or not
                     // using so no vertex printed more than one

    // initializing visited
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, i, visited);
            count++;
        }
    }

    return count;
}

// function adding Edge in adjacency list
void add_edge(vector<int> adj[], int v, int u) // v - first vertex , u - second vertex
{
    // one edge fills two cell in undirected graph
    adj[v].push_back(u);
    adj[u].push_back(v);
}

// function to print graph
void print_graph(vector<int> adj[], int v)
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
    int v = 9; // total number of vertexes
    vector<int> adj[v];

    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 2);

    add_edge(adj, 3, 4);

    add_edge(adj, 5, 6);
    add_edge(adj, 5, 7);
    add_edge(adj, 7, 8);

    cout << "\nAdjacency List : \n";
    print_graph(adj, v);

    cout << "\nBreadth First Search of Graph : ";
    int count = BFSDis(adj, v);

    cout << "\nNumber of Connected Component : " << count << endl;

    return 0;
}
