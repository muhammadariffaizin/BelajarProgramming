#include<bits/stdc++.h>
using namespace std; 
#define NIL -1 
#define INF INT_MAX

// int V,E;
 
typedef pair <int, int> pii;
 
class Graph 
{ 
    int V; 
    vector< pii > *adj; 
    void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[], vector< pii > bdg[]); 
public: 
    Graph(int V); // Constructor 
    void addEdge(int u, int v, long long w); 
    void bridge(vector< pii > bdg[]); 
    void shortestPath(int src, vector< pii > bdg[], long long dist[]); 
}; 
 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new vector< pii >[V]; 
} 
 
void Graph::addEdge(int u, int v, long long w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w));
} 
 
void Graph::bridgeUtil(int u, bool visited[], int disc[], 
    int low[], int parent[], vector< pii > bdg[]) 
{ 
    static int time = 0; 
 
    visited[u] = true; 
 
    disc[u] = low[u] = ++time; 
 
    vector< pii >::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = i->first;
        long long w = i->second;
 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent, bdg); 
 
            low[u] = min(low[u], low[v]); 
 
            if (low[v] > disc[u]) 
            {
                bdg[u].push_back(make_pair(v,w));
                bdg[v].push_back(make_pair(u,w));
            }
        } 
 
        else if (v != parent[u]) 
            low[u] = min(low[u], disc[v]); 
    } 
} 
 
void Graph::bridge(vector< pii > bdg[]) 
{ 
    bool visited[V];
    int disc[V];
    int low[V];
    int parent[V];
 
    for (int i=0;i<V;i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
 
    for (int i=0;i<V;i++) 
        if (!visited[i]) 
            bridgeUtil(i, visited, disc, low, parent, bdg); 
} 
 
void Graph::shortestPath(int src, vector< pii > bdg[], long long dist[]) 
{ 
     priority_queue< int, vector <int> , greater<int> > pq; 
 
    for (int i = 0 ; i < V ; i++)
        dist[i] = -1 ;
 
    pq.push(src); 
    dist[src] = 0; 
    // u = v.sekarang, v = v.tetangga;
    while (!pq.empty()) 
    { 
        int u = pq.top(); 
        pq.pop(); 
 
        vector<pii>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        {  
            int v = (*i).first; 
            long long weight = (*i).second; 
 
            if (dist[v] > dist[u] + weight ||  dist[v] == -1) 
            { 
                pii target = make_pair(v, weight);
                if (find(bdg[u].begin(), bdg[u].end(), target) == bdg[u].end())
                    dist[v] = dist[u];
                else  
                    dist[v] = dist[u] + weight; 
                pq.push(v); 
            } 
        } 
    } 
}
// void fastscan(int &number) 
// { 
//     bool negative = false; 
//     register int c; 
  
//     number = 0; 

//     c = getchar_unlocked(); 
//     if (c=='-') 
//     { 
//         negative = true; 
//         c = getchar_unlocked(); 
//     } 
//     for (; (c>47 && c<58); c=getchar_unlocked()) 
//         number = number *10 + c - 48; 
  
//     if (negative) 
//         number *= -1; 
// } 
int main() 
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cin.tie(NULL);
    int V,E;
    // scanf("%d%d", &V, &E);
    cin >> V >> E;
    // fastscan(V);
    // fastscan(E);
    Graph g(V);
    vector< pii > bdg[V];
    while(E--)
    {
        int from, to;
        long long weight;
        // scanf("%d%d%d", &from, &to, &weight);
        cin >> from >> to >> weight;
        // fastscan(from);
        // fastscan(to);
        // fastscan(weight);
        g.addEdge(from-1, to-1, weight);
    }
    g.bridge(bdg);
    long long dist[V][V];
    for(int i=0;i<V;i++)
    {
        g.shortestPath(i, bdg, dist[i]);
    }
    int testcase;
    // scanf("%d", &testcase);
    cin >> testcase;
    // fastscan(testcase);
    for(int i=0;i<testcase;i++)
    {
        int from1, to1;
        // scanf("%d%d", &from1, &to1);
        cin >> from1 >> to1;
        // fastscan(from1);
        // fastscan(to1);
        // if(dist[from1-1].size() == 0)
            
        // printf("%lld\n", dist[from1-1][to1-1]);
        cout << dist[from1-1][to1-1] << "\n";
    }
    return 0; 
}
