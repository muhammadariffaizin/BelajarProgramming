#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// a structure to represent the weight of edge in graph
class Edge
{
    public:
    int src, dest, weight;
};

// a structure to represent a connected, undirected
class Graph
{
    public:
    int V, E;

    // graph is represented as an array of edges.
    Edge* edge;
};

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

// A structure to represent a subset for union-find
class subset
{
    public:
    int parent;
    int rank;
};

// A function to find set of an element i
int find(subset S[], int i)
{
    // find root and make root as parent of i
    if (S[i].parent != i)
        S[i].parent = find(S, S[i].parent);

    return S[i].parent;
}

// A function that does union of two sets of x and y
void Union(subset S[], int x, int y)
{
    int xroot = find(S, x);
    int yroot = find(S, y);

    // Attach smaller rank tree under root of high
    if (S[xroot].rank < S[yroot].rank)
        S[xroot].parent = yroot;
    else if (S[xroot].rank > S[yroot].rank)
        S[yroot].parent = xroot;

    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        S[yroot].parent = xroot;
        S[xroot].rank++;
    }
}

// Compare two edges according to their weights.
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

/// The main function to MST using Kruskal's algorithm
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V]; // Tnis will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges to non-decreasing
    // order of their weight. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    // Allocate memory for creating V sS
    subset *S = new subset[( V * sizeof(subset) )];

    // Create V S with single elements
    for (int v = 0; v < V; ++v)
    {
        S[v].parent = v;
        S[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E)
    {
        // Step 2: Pick the smallest edge
        Edge next_edge = graph->edge[i++];

        int x = find(S, next_edge.src);
        int y = find(S, next_edge.dest);

        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(S, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the
    // built MST
    int sum = 0;
    for (i = 0; i < e; ++i)
    {
        sum = sum + 10000*result[i].weight;
    }

    cout<< sum << endl;
    return;
}

int main()
{
    int T, V, E;

    cin>> T;
    int a = 1;
    while(T)
    {
        scanf("%d", &V); // Number of vertices in graph
        scanf("%d", &E);; // Number of edges in graph
        Graph* graph = createGraph(V, E);

        int i=0;
        while(E)
        {
            scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
            E--;
            i++;
        }
        cout<<"Kasus #" << a << ": ";
        KruskalMST(graph); //process func

        a++;
        T--;
    }

    return 0;
}

