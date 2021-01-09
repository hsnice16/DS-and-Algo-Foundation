/*
    Implementation of Dijkstra's Algorithm

    Given a graph and a source vertex in the 
    graph, find the shortest paths from source 
    to all vertices in the given graph.

    a SPT (shortest path tree) is generated with
    given source as root

    Dijkstra's Algorithm not works for negative weight

*/

#include <iostream>
#include <limits> // to use numeric_limits
#include <queue>
#include <utility> // to use pair
#include <vector>
using namespace std;

typedef pair<int, int> Pair;

// function performing dijkstra's algo
void shortest_path(vector<Pair> adj[], int V, int src)
{
    vector<int> res(V, numeric_limits<int>::max()); // to store shortest path
                                                    // initialized with V size , value in all INF_MAX

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq; // min heap , store (weight, vertex) pair
    // first weight in pair because first element of pair use in comparison

    pq.push(make_pair(0, src));
    res[src] = 0; // shortest path from source 'src'

    while (!pq.empty())
    {
        int min_dist_vrtx = pq.top().second; // vertex with minimum distance
        pq.pop();                            // remove vertex with minimum distance from priority queue

        // all adjacent of min_dist_vrtx
        for (Pair val : adj[min_dist_vrtx])
        {
            int v = val.first;       // vertex
            int weight = val.second; // weight

            if (res[v] > res[min_dist_vrtx] + weight) // if only distance of vertex v in rex vector
            {
                res[v] = res[min_dist_vrtx] + weight;
                pq.push(make_pair(res[v], v));
            }
        }
    }

    // print shortest path
    cout << "\nVertex\tShortest distance from source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t " << res[i] << '\n';
    }
}

/**
    function to add edge in adjacency list
    
    parameter :
        vector<pair<int, int> > adj[] -> vector presenting adjacency list
        v -> first vertex
        u -> second vertex
        wt -> weigth b/w vertexex
*/
void addEdge(vector<Pair> adj[], int v, int u, int wt)
{
    // one edge fills two cells in undirected graph
    adj[v].push_back(make_pair(u, wt));
    adj[u].push_back(make_pair(v, wt));
}

// function to print adjacency list
void printGraph(vector<Pair> adj[], int V)
{
    cout << "\nvertex\t(adjacent, weight)\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t ";
        for (Pair val : adj[i])
            cout << "(" << val.first << ", " << val.second << ")" << ' ';
        cout << '\n';
    }
}

int main()
{
    /*
                          8          7
                     (1) ----- (2) ------ (3)
                   /    |      |  \        |\
        4(weight) /     |      |2  \       | \9
                 /      |      |    \      |  \
                (0)     |11  (8)     \4  14|   (4)
                 \      |   /  |      \    |  /
                8 \     |  / 7 |6      \   | /10
                   \    | /    |        \  |/
                      (7) --- (6) ------ (5)
                            1       2
    */

    int V = 9; // total vertexes
    vector<Pair> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 7, 6, 1);
    addEdge(adj, 6, 5, 2);
    addEdge(adj, 5, 4, 10);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 8, 6, 6);
    addEdge(adj, 8, 7, 7);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 5, 14);

    cout << "\nAdjacency List : \n";
    printGraph(adj, V);

    cout << "\nShortes Path : \n";
    int src = 0; // source
    shortest_path(adj, V, src);
    return 0;
}