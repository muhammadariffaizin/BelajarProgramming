#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int row=0, col=0;

bool isSafe(int map[10][10], int i, int j, bool visited[10][10]) {
    return (i >= 0 && i<row && j>=0 && j<col && (map[i][j] && !visited[i][j]));
}

void DFS(int map[10][10], int i, int j, bool visited[10][10]) {
    int rowB[] = {-1, 0, 1, 0};
    int colB[] = {0, -1, 0, 1};

    visited[i][j] = true;

    for(int k=0; k<4; k++) {
        if(isSafe(map, i + rowB[k], j + colB[k], visited))
            DFS(map, i + rowB[k], j + colB[k], visited);
    }
}

int countIsland(int map[10][10]) {
    bool visited[10][10] = {};
    int count=0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(map[i][j] && !visited[i][j]) {
                DFS(map, i, j, visited);
                ++count;
                // cout << i << " " << j << " " << count << endl;
            }
        }
    }
    return count;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int temp=0;
    int map[10][10]={};
    char c;
    vector<int> arr;
    while(1) {
        c = getchar();
        if(c == EOF){
            row++;
            temp++;
            col = temp;
            break;
        } else if(c == '\n') {
            row++;
            temp++;
            col = temp;
            temp=0;
        } else if(c == ' ') {
            temp++;
        } else if(c == '1') {
            map[row][temp] = 1;
        }
    }
    // cout << row << " " << col << endl;
    cout << countIsland(map) << endl;
    return 0;
}