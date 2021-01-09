/*
    Problem : Given a graph and a source vertex src in graph, find shortest paths
                from src to all vertices in the given graph. The graph may contain
                negative weight edges.

    Time Complexity : O(VE), where V is number of vertex and E is number of edges

    Bellman-Ford algorithm does not work if graph has a negative weight cycle. If
    there is a negative weight cycle, you can go on relaxing its nodes indefinitely.
*/

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#define infinite numeric_limits<int>::max()

struct Edge
{
    int src, dest, weight; // src -> source, dest -> destination, weight of an edge
};

struct Graph
{
    int V, E;          // V -> number of vertices, E -> number of edges
    struct Edge *edge; // graph is represented as an array of edges.
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// bellman ford algorithm
void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;

    vector<int> dist(V, infinite); // initializing all distance to infinite
    dist[src] = 0;                 // distance of source from source

    // traverse all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most
    // |V| - 1 edges
    for (int i = 1; i <= (V - 1); i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int wt = graph->edge[j].weight;
            if (dist[u] != infinite && dist[v] > dist[u] + wt)
                dist[v] = dist[u] + wt;
        }
    }

    // this step reports if there is a negative weight cycle in graph.
    // If we iterate through all edges one more time and got a shorter path
    // for any vertex, then there is a negative weight cycle.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int wt = graph->edge[i].weight;
        if (dist[u] != infinite && dist[v] > dist[u] + wt)
        {
            cout << "\nGraph contains negative weight cycle\n";
            return;
        }
    }

    // print shortes path
    cout << "\nVertex Distance from source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main()
{
    /*
        try to understand to fig.
                         B
                 /\      / /\ \    \ 2
            -1   /      /   \  \    \
                /      /     \  \    \/
            A       3 /     1 \  \2      E
              \      /         \  \      /
            4  \    /           \  \    / -3
               \/  \/            \ \/  \/ 
               C  <---------------- D
                            5
    */

    /*
        A -> 0, B -> 1, C -> 2, D -> 3, E -> 4 (INDEX)
    */

    int V = 5; // total number of vertex
    int E = 8; // total number of edges
    struct Graph *graph = createGraph(V, E);

    graph->edge[0].src = 0;     // A
    graph->edge[0].dest = 1;    // B
    graph->edge[0].weight = -1; // wt of edge

    graph->edge[1].src = 0;    // A
    graph->edge[1].dest = 2;   // C
    graph->edge[1].weight = 4; // wt

    graph->edge[2].src = 1;    // B
    graph->edge[2].dest = 2;   // C
    graph->edge[2].weight = 3; // wt

    graph->edge[3].src = 1;    // B
    graph->edge[3].dest = 3;   // D
    graph->edge[3].weight = 2; // wt

    graph->edge[4].src = 1;    // B
    graph->edge[4].dest = 4;   // E
    graph->edge[4].weight = 2; // wt

    graph->edge[5].src = 3;    // D
    graph->edge[5].dest = 2;   // C
    graph->edge[5].weight = 5; // wt

    graph->edge[6].src = 3;    // D
    graph->edge[6].dest = 1;   // B
    graph->edge[6].weight = 1; // wt

    graph->edge[7].src = 4;    // E
    graph->edge[7].dest = 3;   // D
    graph->edge[7].weight = -3; // wt

    int src = 0;
    cout << "\nBellman ford algorithm : \n";
    BellmanFord(graph, src);

    return 0;
}