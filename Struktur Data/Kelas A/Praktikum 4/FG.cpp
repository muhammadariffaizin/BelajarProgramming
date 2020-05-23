#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>

#define N 26

int vis[N];
int num[N];

using namespace std;

void bfs(vector< pair<int, int> > adj_l[], int startNode, int n, int h)
{
  queue<int> q;
  bool visited[n];
  int dist[n];
  int height[n];
  int temp_d;

  memset(dist, -1, n * sizeof(dist[0]));
  memset(height, 0, n * sizeof(height[0]));
  q.push(startNode);

  dist[startNode] = 0;
  height[startNode] = 0;
  visited[startNode] = true;

  while (!q.empty())
  {
    int curNode = q.front();
    q.pop();

    if (height[curNode] < h)
    {
      for (size_t i = 0 ; i < adj_l[curNode].size() ; i++)
      {
        int nextNode = adj_l[curNode][i].first;

        height[nextNode] = height[curNode] + 1;
        temp_d = dist[curNode] + adj_l[curNode][i].second;

        if (!visited[nextNode])
        {
          dist[nextNode] = temp_d;
          adj_l[curNode][i].second = dist[nextNode];
          q.push(nextNode);
          visited[nextNode] = true;
        }
        else
        {
          if (temp_d < dist[nextNode])
          {
            dist[nextNode] = temp_d;
            adj_l[curNode][i].second = dist[nextNode];
          }
        }
      }
    }
  }

  int i = 0;
  for (auto s : dist)
  {
    if (s != -1)
      printf("%d %d\n", i++, s);
    else
      printf("%d INFINITY\n", i++);
  }
}

int way_adj(
    vector<int> adj[],
    int index, int target,
    stack <int> *stac, int puz[]
  )
{
  int i;
  int key = 0;
  int marker = 0;
  int n = adj[index].size();
  int s_way = INT_MAX;
  stack <int> way_st[n];

  // printf("%d ", index);

  if (index == target)
  {
    stac->push(index);
    return 1;
  }
  // printf("lewat\n");
  
  vis[index] = 1;

  for (i = 0; i < adj[index].size(); i++)
  {
    int next = adj[index][i];
    key = 0;

    if (vis[next])
      continue;
    
    if (puz[next])
      if (puz[next] != puz[target])
        continue;

    // printf("---%d %d <- %d\n", puz[target], target, next);
    key = way_adj(adj, next, target, &way_st[i], puz);
    // printf("siz: %lu\n", way_st[i].size());

    way_st[i].push(index);

    if (s_way > way_st[i].size() && key)
    {
      s_way  = way_st[i].size();
      marker = i;
    }
  }

  vis[index] = 0;

  if (s_way != INT_MAX)
  {
    for (i = 0; i < s_way; i++)
    {
      // printf("sok\n");
      stac->push(way_st[marker].top());
      way_st[marker].pop();
    }
    key = 1;
  }

  return key;
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

void pushAdj_list(vector<int> adj_l[], int u, int v) 
{ 
	adj_l[u].push_back(v); 
	// adj_l[v].push_back(u); 
}

int solvePath (
  vector<int> adj[], int puz[],
  int index, int target, int dir,
  queue<int> *path
  )
{
  int i;
  int left = -1;
  int right = -1;
  int top = -1;
  int bottom = -1;
  int way[4];
  int key = 0;
  int dir_dis = (index%5) - (target%5);

  // printf("%d\n", index);

  if (index == target)
  {
    path->push(index);
    return 1;
  }
  
  path->push(index);
  vis[index] = 1;
  
  for (i = 0; i < adj[index].size(); i++)
  {
    if (adj[index][i] == index-1)
      left = adj[index][i];
    if (adj[index][i] == index-5)
      top = adj[index][i];
    if (adj[index][i] == index+1)
      right = adj[index][i];
    if (adj[index][i] == index+5)
      bottom = adj[index][i];
  }

  if (dir_dis > 0 || (dir > 0 && dir_dis == 0))
  {
    way[0] = left;
    way[1] = bottom;
    way[2] = right;
    way[3] = top;
  }
  else if (dir_dis < 0 || (dir < 0 && dir_dis == 0))
  {
    way[0] = right;
    way[1] = bottom;
    way[2] = left;
    way[3] = top;
  }

  for (i = 0; i < 4; i++)
  {
    if (puz[way[i]] == puz[target] && !vis[way[i]])
      key = solvePath(adj, puz, way[i], target, dir, path);
    
    if (key)
    {
      path->push(index);
      return 1;
    }
  }

  for (i = 0; i < 4; i++)
  {
    if (way[i] != -1 && (!puz[way[i]] || puz[way[i]] == puz[target]) && !vis[way[i]])
      key = solvePath(adj, puz, way[i], target, dir, path);
    
    if (key)
    {
      path->push(index);
      return 1;
    }
  }

  return 0;
}

int main() 
{
  int T = 5;
  int n = 5;
  int i;
  int j;
  int k;
  int l;
  int num;
  int key = 0;
  int counter = 0;
  int matrix[25];
  int matrix2[25];
  char input[6];
  int index[6] = {0};
  int place[6][2];
  vector<int> dist[6][6];
  vector<int> prev_ind;
  vector<int> adj[N];
  queue<int> q;
  queue<int> prev_q;
  stack<int> s[6];

  while (counter < 5)
  {
    scanf("%s", input);

    for (i = 0; i < n; i++)
    {
      num = counter*5 + i;
      // printf("%d\n", num);

      if ((num + 1) < 25)
        if (num % 5 != 4)
          pushAdj_list(adj, num, num + 1);
      if ((num - 1) > - 1)
        if (num % 5 != 0)
          pushAdj_list(adj, num, num - 1);
      if ((num + 5) < 25)
        pushAdj_list(adj, num, num + 5);
      if ((num - 5) > - 1)
        pushAdj_list(adj, num, num - 5);

      if (input[i] == 'X')
      {
        matrix[num] = 0;
        matrix2[num] = 0;
      }
      else
      {
        matrix[num] = input[i] - '0';
        matrix2[num] = input[i] - '0';

        index[matrix[num]] += 1;
        place[matrix[num]][index[matrix[num]] - 1] = num;

        if (index[matrix[num]] == 2)
        {
          int div1 = place[matrix[num]][0]/5;
          int div2 = place[matrix[num]][1]/5;
          int div = abs(div1 - div2);
          int mod1 = place[matrix[num]][0]%5;
          int mod2 = place[matrix[num]][1]%5;
          int min1 = mod1 - mod2;
          int min2 = abs(min1);
          // printf("->%d %d\n", matrix[num], min + div);

          dist[div][min2].push_back(matrix[num]);
        }
      }
    }
    counter++;
  }

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if (dist[i][j].size() > 0)
      {
        for (k = 0; k < dist[i][j].size(); k++)
        {
          int ind = dist[i][j][k];
          q.push(ind);
        }
      }
    }
  }

  while (true)
  {
    int marker = 0;

    while (!q.empty())
    {
      int ind = q.front();
      q.pop();

      key = way_adj(adj, place[ind][0], place[ind][1], &s[ind], matrix2);

      if (key)
      {
        // printf("print\n");
        // printf("->%d %lu", s[ind].top(), s[ind].size());
        
        while (!s[ind].empty())
        {
          matrix2[s[ind].top()] = ind;
          s[ind].pop();
        }
        
        // for (l = 0; l < 25; l++)
        // {
        //   printf("%d", matrix2[l]);
        //   if (l%5 == 4)
        //     printf("\n");
        // }
        // printf("\n");
      }
      else
      {
        for (l = 0; l < 25; l++)
          matrix2[l] = matrix[l];
        
        q.push(ind);
        while (!prev_q.empty())
        {
          q.push(prev_q.front());
          prev_q.pop();
        }
      }

      prev_q.push(ind);
    }

    for (i = 0; i < 25; i++)
    {
      if (matrix2[i] == 0)
      {
        for (j = 0; j < adj[i].size(); j++)
        {
          if (matrix2[adj[i][j]])
            break;
        }
        // printf("%d-%d\n", i, matrix2[adj[i][j]]);
        matrix2[i] = matrix2[adj[i][j]];
        marker = 1;
        // while (!prev_q.empty())
        // {
        //   q.push(prev_q.front());
        //   prev_q.pop();
        // }
      }
    }

    if (!marker)
      break;
  }

  for (i = 0; i < 25; i++)
  {
    printf("%d", matrix2[i]);
    if (i%5 == 4)
      printf("\n");
  }

	return 0; 
} 
