#include <iostream>
#include <vector>
#include <set>
#include <queue> 
#include <algorithm>
#include <limits.h>

using namespace std;

int W, H;

struct cell 
{ 
    int x, y; 
    int distance; 
    cell(int x, int y, int distance) : 
        x(x), y(y), distance(distance) {} 
}; 
  
bool operator<(const cell& a, const cell& b) 
{ 
    if (a.distance == b.distance) 
    { 
        if (a.x != b.x) 
            return (a.x < b.x); 
        else
            return (a.y < b.y); 
    } 
    return (a.distance < b.distance); 
} 
  
bool isInsideGrid(int i, int j) 
{ 
    return (i >= 0 && i < W && j >= 0 && j < H); 
} 

int main() {
    int N, M, startX, startY;
    char X, S;
    cin >> N >> W >> H;
    int arr[26];
    int peta[H][W];
    while(N--) {
        cin >> X >> M;
        arr[X-'A'] = M;
    }
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> S;
            if(S == 'Y') {
                startX = j;
                startY = i;
                peta[startY][startX] = 0;
            } else {
                peta[i][j] = arr[S-'A'];
            }
        }
    }

    int dis[H][W]; 
    int minim = INT_MAX;
  
    for (int i = 0; i < H; i++) 
        for (int j = 0; j < W; j++) 
            dis[i][j] = INT_MAX; 
  
    int dx[] = {-1, 0, 1, 0}; 
    int dy[] = {0, 1, 0, -1}; 
  
    set<cell> st; 
  
    st.insert(cell(startX, startY, 0)); 
  
    dis[startY][startX] = peta[startY][startX]; 
  
    while (!st.empty()) 
    { 
        cell k = *st.begin(); 
        st.erase(st.begin()); 
  
        for (int i = 0; i < 4; i++) 
        { 
            int x = k.x + dx[i]; 
            int y = k.y + dy[i]; 

            if (!isInsideGrid(x, y)) 
                continue; 

            if (dis[y][x] > dis[k.y][k.x] + peta[y][x]) 
            { 
                if (dis[y][x] != INT_MAX) 
                    st.erase(st.find(cell(x, y, dis[y][x]))); 
                dis[y][x] = dis[k.y][k.x] + peta[y][x]; 
                st.insert(cell(x, y, dis[y][x])); 
            } 
            if(x==0 || x == W-1 || y == 0 || y == H-1) {
                if(dis[y][x] < minim) {
                    minim = dis[y][x];
                }
            }
        } 
    } 
    cout << minim << endl;
    return 0;
}