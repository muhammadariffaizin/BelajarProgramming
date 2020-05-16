#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int **path, *visited;

void DLS(int index, int limit, int weight, int V){
 
	visited[index] = weight;
 
	if(limit < 1)
		return;
 
	for(int i=0; i<V; i++){
		if(i == index)
			continue;
 
		if(path[i][index] == 0)
			continue;
 
		int curWeight = path[i][index] + weight;
 
		if(curWeight < visited[i]){
			// cout << "Index " << index << " ke " << i << " dengan weight: " << curWeight << " pada limit " << limit << endl;
			DLS(i, limit-1, curWeight, V);
		}
 
	}
}
 
int main(){
	int V;
    cin >> V;
    
    path = new int*[V];
    for(int i=0; i<V; i++) {
        path[i] = new int[V];
    }
	// path = (int*)malloc(V * V * sizeof(int));
    // cout << "Y" << endl;
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			path[i][j] = 0;
 
	int E;
    cin >> E;
 
	for(int e=0; e<E; e++){
		int A, B, C;
        cin >> A >> B >> C;

		path[B][A] = C;
		// path[B][A] = C;
		// *(path + B + A*V) = C;
	}
    
    visited = new int[V];
 
	for(int i=0; i<V; i++)
		visited[i] = 1073741824;
 
	int X, L;
    cin >> X >> L;
 
	DLS(X, L, 0, V);
 
	for(int i=0; i<V; i++){
		cout << i << " ";
		if(visited[i] == 1073741824)
			cout << "INFINITY";
		else
			cout << visited[i];
 
		cout << endl;
	}
}