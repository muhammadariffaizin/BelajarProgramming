#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 
#include <stdio.h>
#include <string.h>

#define N 34

bool vis[N];

using namespace std;

void bfs(vector< pair<int, int> > adj_l[], int startNode, int n, int h)
{
  queue<int> q;
  bool visited[n];
  pair<int, pair<int, int> > dist[n];
  int height[n];
  int temp_d;
  int i;
  int j;
  int counter = 0;
  vector< pair<int, pair<int, int>> > l_way[n];

  for (i = 0; i < n; i++)
  {
    dist[i].first = INT_MAX;
    dist[i].second.second = 0; 
    dist[i].second.first = 
    height[i] = -1;
  }

  memset(height, -1, n * sizeof(height[0]));
  q.push(startNode);
  l_way[startNode].push_back(make_pair(0, make_pair(0, 0)));

  dist[startNode].first = 0;
  height[startNode] = 0;
  visited[startNode] = true;

  while (!q.empty())
  {
    int curNode = q.front();
    q.pop();

    // printf("%d..\n", curNode);

    for (size_t i = 0 ; i < adj_l[curNode].size() ; i++)
    {
      int nextNode = adj_l[curNode][i].first;

      if (nextNode == dist[curNode].second.first)
        continue;
      
      if (dist[curNode].first == INT_MAX)
        temp_d = INT_MAX;
      else
        temp_d = dist[curNode].first + adj_l[curNode][i].second;

      // printf("%d-%d-%d ", curNode, nextNode, temp_d);
      
      // if (counter > 50)
        // { printf(">>> %lu\n", q.size()); return;}
      // counter++;

      if (height[nextNode] != -1)
      {
        if (height[nextNode] > (height[curNode] + 1))
          height[nextNode] = height[curNode] + 1;
      }
      else
        height[nextNode] = height[curNode] + 1;
      // printf("%d %d, ", nextNode, dist[nextNode].second.second);

      if (!visited[nextNode])
      {
        dist[nextNode].second.first = curNode;
        dist[nextNode].second.second = dist[curNode].second.second + 1;

        if (dist[nextNode].second.second > h)
          dist[nextNode].first = INT_MAX;
        else
          dist[nextNode].first = temp_d;

        q.push(nextNode);

        visited[nextNode] = true;
      }
      else
      {
        if (temp_d < dist[nextNode].first)
        {
          dist[nextNode].second.first = curNode;
          dist[nextNode].second.second = dist[curNode].second.second + 1;

          if (dist[nextNode].second.second > h)
            dist[nextNode].first = INT_MAX;
          else
            dist[nextNode].first = temp_d;

          q.push(nextNode);
          // printf("{ %d } ", nextNode);
        }
        else
        {
          if (dist[nextNode].second.first == curNode)
          {
            // printf("masuk\n");
            dist[nextNode].second.second = dist[curNode].second.second + 1;
            
            if (dist[nextNode].second.second > h)
              dist[nextNode].first = INT_MAX;
            else
              dist[nextNode].first = temp_d;

            if (adj_l[nextNode].size() > 1)
              q.push(nextNode);
          }

          if ((dist[nextNode].first + adj_l[curNode][i].second) < dist[curNode].first)
          {
            if ((dist[nextNode].second.second + 1) <= h)
            {
              dist[curNode].first = dist[nextNode].first + adj_l[curNode][i].second;
              dist[curNode].second.second = dist[nextNode].second.second + 1;
              dist[curNode].second.first = nextNode;

              q.push(curNode);
            }
          }
        }
      }
      // printf("%d -> ", dist[nextNode].second.second);
      l_way[nextNode].push_back(make_pair(temp_d, make_pair(curNode, dist[curNode].second.second + 1)));
    }
    // printf("\n");
  }

  // cout << "\n";
  for (i = 0; i < n; i++)
  {
    if (dist[i].first != INT_MAX)
      printf("%d %d\n", i, dist[i].first);
    else
      printf("%d INFINITY\n", i);
  }

  // cout << endl;
  // for (i = 0; i < n; i++)
  // {
  //   printf("%d: ", i);
  //   for (j = 0; j < l_way[i].size(); j++)
  //     printf("%d-%d-%d ", l_way[i][j].first, l_way[i][j].second.first, l_way[i][j].second.second);
  //   printf("\n");
  // }

  // cout << endl;
  // for (i = 0; i < n; i++)
  // {
  //   int c_way = INT_MAX;
  //   printf("%d ", i);
  //   for (j = 0; j < l_way[i].size(); j++)
  //   {
  //     if (l_way[i][j].second.second <= h)
  //     {
  //       if (c_way > l_way[i][j].first)
  //         c_way = l_way[i][j].first;
  //     }
  //     // printf("%d-%d-%d ", l_way[i][j].first, l_way[i][j].second.first, l_way[i][j].second.second);
  //   }
  //   if (c_way != INT_MAX)
  //     printf("%d\n", c_way);
  //   else
  //     printf("INFINITY\n");
  // }
}

void way_adj(
    vector< pair<int, int> > adj[],
    int index, int w, int p, int h,
    int way[]
  )
{
  int i;

  if (h == -1)
  {
    
    return;
  }

  if (!vis[index])
  {
    if (way[index] > (way[p] + w))
      way[index] = way[p] + w;

    vis[index] = true;
  }
  else if (vis[index])
  {
    if (way[index] > (way[p] + w))
      way[index] = way[p] + w;

    vis[index] = false;
    return;
  }

  for (size_t i = 0 ; i < adj[index].size() ; i++)
  {
    way_adj(
      adj, adj[index][i].first,
      adj[index][i].second,
      index, h - 1, way
    );
  }

  vis[index] = false;
}

void printGraph(vector< pair<int, int> > adj[], int V) 
{ 
	for (int v = 0; v < V; ++v) 
	{ 
		cout << "\n Adjacency list of vertex "
			<< v << "\n head "; 
		for (auto x : adj[v]) 
		  cout << "-> " << x.first << ": " << x.second << " "; 
		printf("\n"); 
	} 
} 

void pushAdj_list(vector< pair<int, int> > adj_l[], int u, int v, int w) 
{ 
	adj_l[u].push_back(make_pair(v, w)); 
	adj_l[v].push_back(make_pair(u, w)); 
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
      if (arr[j] > arr[j+1]) 
        swap(&arr[j], &arr[j+1]); 
}

int main() 
{
  int T;
  int n = 0;
  int input[3];
  int i = 0;
  int k;
  int marker;
  int nver;
  int X;
  int L;
  int way[N];

  scanf("%d %d", &nver, &T);

  for (i = 0; i < nver; i++)
    way[i] = INT_MAX;

  int ver[nver];
  vector< pair<int, int> > adj[N];

  while (T--)
  {
    scanf("%d %d %d", &input[0], &input[1], &input[2]);

    pushAdj_list(adj, input[0], input[1], input[2]);
  }

  scanf("%d %d", &X, &L);

  way[X] = 0;
  // printGraph(adj, nver);
  // way_adj(adj, X, 0, X, L, way);
  bfs(adj, X, nver, L);

  // for (i = 0; i < nver; i++)
  // {
  //   if (way[i] != INT_MAX)
  //     printf("%d %d\n", i, way[i]);
  //   else
  //     printf("%d INFINITY\n", i);
  // }

	return 0; 
} 
