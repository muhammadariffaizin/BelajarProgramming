#include<bits/stdc++.h> 
#include <map>
using namespace std; 
# define INF 0x3f3f3f3f 
  
typedef pair<long long, long long> iPair; 
  
void addEdge(vector <pair<long long, long long> > adj[], long long u, long long v, long long wt)
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt));
} 

void bridgeUtil(vector<pair<long long,long long> > adj[], vector<pair<long long,long long> > bridge[],
				long long u, bool visited[], long long disc[], long long low[], long long parent[]) 
{ 
    static int time = 0; 
    visited[u] = true; 
    disc[u] = low[u] = ++time; 
  
    vector<pair<long long, long long> >::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = i->first;
		int weight = i->second; 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(adj, bridge, v, visited, disc, low, parent); 

            low[u]  = min(low[u], low[v]); 
  
            if (low[v] > disc[u]) 
            {
				bridge[u].push_back(make_pair(v,weight));
				bridge[v].push_back(make_pair(u,weight));
//            	cout << "bridge : " << u << " " << v << endl; 
			}
        } 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
   
void abridge(vector<pair<long long,long long> > adj[], vector<pair<long long,long long> > bridge[], long long n) 
{ 
    bool *visited = new bool[n+1]; 
    long long *disc = new long long[n+1]; 
    long long *low = new long long[n+1]; 
    long long *parent = new long long[n+1]; 
  
    for (int i = 1; i <= n; i++) 
    { 
        parent[i] = -1; 
        visited[i] = false; 
    } 
    for (int i = 1; i <= n; i++) 
        if (visited[i] == false) 
            bridgeUtil(adj, bridge, i, visited, disc, low, parent); 
} 

void shortestPath(vector<pair<long long,long long> > adj[], vector<pair<long long,long long> > bridge[], 
				long long V, long long src, map<long long, long long*> *mapku)
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    
    long long *dist = (long long*) malloc ((V+1)* sizeof(long long));
    memset (dist, INF, (V+1)*sizeof(long long));
    vector<pair<long long,long long> > :: iterator x;	
    dist[src] = 0;
    pq.push(make_pair(dist[src], src)); 
    while (!pq.empty()){
        long long u = pq.top().second; 
        pq.pop(); 
        
		for (int x = 0; x < adj[u].size(); ++x)
		{ 
            long long v = adj[u][x].first; 		
            long long weight = adj[u][x].second;
            if (dist[v] > dist[u] + weight)
			{
				pair<long long,long long> z = make_pair(v, weight);
				if(find(bridge[u].begin(), bridge[u].end(), z) != bridge[u].end())
					dist[v] = dist[u] + weight;
				else dist[v] = dist[u];
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    }
	(*mapku)[src] = dist;
} 

int main() 
{ 
	map<long long, long long*> apa;
	long long n, m;
	scanf("%lld %lld", &n, &m);
	vector<iPair> bridge[n+1];
	vector<iPair> adj[n+1];
	for (int i = 0; i < m; i++)
	{
		long long v1, v2, wt;
		scanf("%lld %lld %lld", &v1, &v2, &wt);
		addEdge(adj, v1, v2, wt);
	}
	abridge(adj, bridge, n);
	for(int i = 1; i <= n; i++)
	{
		apa.insert({i, NULL});
		shortestPath(adj, bridge, n, i, &apa);
	}
	long long tc;
	scanf("%lld", &tc);
	while (tc--)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		
		cout << apa[a][b] << endl;
	}

	return 0;
} 
