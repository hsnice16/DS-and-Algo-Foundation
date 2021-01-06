/*
    Breadth First Search in Graph

    First Version :
        Given an undirected graph and a source vertex 's'
        print BFS from the given source.

    Second Version :
        No source is given and graph may be disconnected (relate to web crawling)

    Idea is :
        first print source vertex and then its adjacent, 
        and then their adjacent which are not printed yet , so on.

    Time Complexity of Idea :
        O(V + E), where E can be 2*E(for undirected)
                  and we are adding V for corner case when ther is no edge
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
// for first version
void BFS(vector<int> adj[], int s, int v) // v - total vertex, s - source vertex
{
    bool visited[v]; // to check vertex is already in queue or not
                     // using so no vertex printed more than one

    // initializing visited
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

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
*/

// second version
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
void BFSDis(vector<int> adj[], int v)
{
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
            BFS(adj, i, visited);
    }
}

// add edge in adjacency list
void addEdge(vector<int> adj[], int u, int v)
{
    // one edge fills two cell
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// print adjacency list
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int val : adj[i])
        {
            cout << val << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    /*
    // for first version
    /*
           1 ---- 3
         /     /    
        0  |  /   |
         \   /
           2 ---- 4
    
    int v = 5;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
*/
    // for second version
    /*
            0                4
           /  \            /   \
          1    2          5 --- 6
           \  /
             3


    */
    int v = 7;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    cout << "\nPrint Graph : \n";
    printGraph(adj, v);

    cout << "\nBreadth First Search : \n";
    int s = 0;
    BFSDis(adj, v);

    return 0;
}

/*
    Few Applications of BFS

    1-> Shortest Path in an unweighted Graph
    2-> Crawlers in Search Engines
    3-> Peer to Peer Networks
    4-> Social Networking Search
    5-> In Garbage Collection (Cheney's Algorithm)
    6-> Cycle Detection
    7-> Ford Fulkerson Algorithm (gives better time complexity)
    8-> Broadcasting
*/