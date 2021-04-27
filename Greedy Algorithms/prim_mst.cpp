/*
    Implementation of minimum spanning tree, using prim's algo.

    Assumption:
        :- graph is undirected
        :- node's keys are in numbers
        :- -1 is not a valid key value
        :- vertex (or node's key) value starts from 0
*/
#include <iostream>
#include <limits> // to use numeric_limits
#include <queue>
#include <utility> // to use pair
#include <vector>
using namespace std;

typedef pair<int, int> Pair;

// prim's algo
void prim_algo(vector<Pair> adj[], int V, int src)
{
    /*
        store distance of each vertex from parent
    */
    vector<int> dis(V, numeric_limits<int>::max());
    
    /*
        store parent of each vertex
    */
    vector<int> parent(V);
    bool visited[V] = {false};

    /*
        min heap , store (weight, vertex) pair
        first weight in pair because first element of pair use in comparison
    */
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    pq.push(make_pair(0, src));
    dis[src] = 0; // shortest path from source 'src'
    parent[src] = -1; 

    while (!pq.empty())
    {
        int min_dist_vrtx = pq.top().second; // vertex with minimum distance
        pq.pop();                            // remove vertex with minimum distance from priority queue

        visited[min_dist_vrtx] = true;

        // all adjacent of min_dist_vrtx
        for (Pair val : adj[min_dist_vrtx])
        {
            int weight = val.first;       // weight
            int v = val.second; // vertex
    
            if (visited[v] == false) {    
                if (dis[v] > weight)
                {
                    dis[v] = weight;
                    parent[v] = min_dist_vrtx;
                    pq.push(make_pair(dis[v], v));
                }
            }
        }
    }

    /*
        printing edge's in mst
        neglected 0th vertex, as it doesn't have parent
    */
    cout << "(vertex_1, vertex_2)\n\n";
    for(int i=1; i<V; i++) {
        cout << "(" << parent[i] << ", " << i << ")" << endl;
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
    adj[v].push_back(make_pair(wt, u));
    adj[u].push_back(make_pair(wt, v));
}

// function to print adjacency list
void printGraph(vector<Pair> adj[], int V)
{
    cout << "\nvertex\t(adjacent, weight)\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t ";
        for (Pair val : adj[i])
            cout << "(" << val.second << ", " << val.first << ")" << ' ';
        cout << '\n';
    }
}

int main()
{
    int V;
    cout << "\nEnter total numbers of vertex: ";
    cin >> V;

    int E;
    cout << "\nEnter total numbers of edge: ";
    cin >> E;

    vector<Pair> adj[V];
    cout << "\nStart entering: vertex_1 vertex_2 weight\n\n";
    for (int i=0; i<E; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        addEdge(adj, v1, v2, wt);
    }

    int src;
    cout << "\nEnter vertex with which to start: ";
    cin >> src;

    cout << "\nAdjacency List : \n";
    printGraph(adj, V);

    cout << "\nEdge's in spanning tree : \n";
    prim_algo(adj, V, src);

    return 0;
}

/*
    INPUT: 
    Enter total numbers of vertex: 9

    Enter total numbers of edge: 13

    Start entering: vertex_1 vertex_2 weight

    0 1 4
    0 7 8 
    1 2 8 
    1 7 11
    2 3 7 
    2 5 4
    2 8 2
    3 4 9
    3 5 14
    4 5 10
    5 6 2
    6 7 1
    6 8 6

    Enter vertex with which to start: 0

    OUTPUT:
    Adjacency List :

    vertex  (adjacent, weight)
    0        (1, 4) (7, 8)
    1        (0, 4) (2, 8) (7, 11)
    2        (1, 8) (3, 7) (5, 4) (8, 2)
    3        (2, 7) (4, 9) (5, 14)
    4        (3, 9) (5, 10)
    5        (2, 4) (3, 14) (4, 10) (6, 2)
    6        (5, 2) (7, 1) (8, 6)
    7        (0, 8) (1, 11) (6, 1)
    8        (2, 2) (6, 6)

    Edge's in spanning tree :
    (vertex_1, vertex_2)

    (0, 1)
    (1, 2)
    (2, 3)
    (3, 4)
    (2, 5)
    (5, 6)
    (6, 7)
    (2, 8)
*/