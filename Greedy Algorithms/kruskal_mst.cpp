/*
    Implementation of minimum spanning tree, using kruskal algo.

    Assumption:
    :- node's keys are in numbers
    :- vertex (or node's key) value starts from 0
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> edge;

class Graph {
    private:
        vector<pair<int, edge> > graph;
        vector<pair<int, edge> > mst; 
        int *parent;
        int V;  // number of vertices
    public:
        Graph(int V);
        void addWeightedEdge(int wt, int v1, int v2);
        int find_set(int v);
        void union_set(int v1, int v2);
        void kruskal_algo();
        void print_mst();
};

Graph::Graph(int V) {
    parent = new int[V];

    /*
        initially parent of i, is i itself
    */
    for (int i=0; i < V; i++) {
        parent[i] = i;
    }

    graph.clear();
    mst.clear();
}

void Graph::addWeightedEdge(int wt, int v1, int v2) {
    graph.push_back(make_pair(wt, edge(v1, v2)));
}

int Graph::find_set(int v) {
    if (v == parent[v]) {
        return v;   // if v is the parent of itself
    } else {
        /* 
            if v is not parent of itself, 
            then v is not the representative of his set, 
            so we recursively call find on its parent 
        */
        return find_set(parent[v]); 
    }
}

void Graph::union_set(int v1, int v2) {
    parent[v1] = parent[v2];
}

void Graph::kruskal_algo() {
    sort(graph.begin(), graph.end());   // sort in increasing weight
    
    for(int i = 0; i < graph.size(); i++) {

        // v1Rep = v1 representative, same for v2Rep
        int v1Rep = find_set(graph[i].second.first);
        int v2Rep = find_set(graph[i].second.second);

        if(v1Rep != v2Rep) {
            mst.push_back(graph[i]);
            union_set(v1Rep, v2Rep);
        }       
    }
}

void Graph::print_mst() {
    
    cout << "\n(vertex_1, vertex_2) weight\n\n";
    for(int i = 0; i < mst.size(); i++) {
        cout << "(" << mst[i].second.first << ", "
             << mst[i].second.second << ") " << mst[i].first << "\n";
    }
}

int main() {

    int V, E;
    cout << "\nEnter number of: vertex edge\n";
    cin >> V >> E;

    Graph g(V);

    cout << "\nStart entering: vertex_1 vertex_2 weight\n\n";
    for(int i = 0; i < E; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        g.addWeightedEdge(wt, v1, v2);
    }

    g.kruskal_algo();
    cout << "\nMinimum Spanning Tree: \n";
    g.print_mst();

    return 0;
}

/*
    INPUT:
    Enter number of: vertex edge
    9 13

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

    OUTPUT:
    Minimum Spanning Tree:

    (vertex_1, vertex_2) weight

    (6, 7) 1
    (2, 8) 2
    (5, 6) 2
    (0, 1) 4
    (2, 5) 4
    (2, 3) 7
    (0, 7) 8
    (3, 4) 9
*/