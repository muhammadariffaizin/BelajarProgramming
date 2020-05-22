/*
Soal F - "Soal Wibu 2"
AC di Revisi Praktikum

Interpretasi Maksud Soal:
Ada pulau, ada jembatan
- ada sebanyak N pulau dan sebanyak P jembatan
- diberikan pulau-pulau yang terhubung oleh P jembatan
- 1 bridge 2 islands :)

Dicari berapa banyak jembatan lagi yang harus dibangun agar
semua pulau terhubung

Penjelasan Algo:
Problem disjoint set
(i.)    buat sebanyak N pulau di disjoint set (awalnya dianggap parentnya diri sendiri)
(ii.)   setiap jembatan yang menghubungi dua pulau "is treated as calling the union function to both islands"
(iii.)  union-kan sampai ga bisa lagi (sudah 1 parent)

more below
*/

#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <climits>

using namespace std;

/*
disjoint set yang sudah di modifikasi
1. menggunakan vector, penggunaan array menghasilkan segmentation error :(
2. menggunakan class constructor, jadi tidak perlu ada fungsi init :)
*/
class DisjointSet {
    vector <int> parent;
    int size;

    public:
    DisjointSet(int num) {
        this->size = num;
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return find(parent[x]);
    }

    void unions(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        parent[rootX] = rootY;
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }

    /*
    jawaban diperoleh disini
    (i)     unionkan semua "pulau" yang ada
    (ii)    setiap union tambahkan counter bridge
    (iii)   return bridge 
    */
    int buildBridges() {
        int bridge = 0;
    
        for (int i = 0; i < size-1; i++) {
            if (!check(i, i+1)) {
                unions(i, i+1);
                bridge++;
            }
        }
        return bridge;
    }
};

int main() {
    int islands, numBridges;
    int a, b;

    scanf("%d%d", &islands, &numBridges);

    DisjointSet disjointSet(islands);

    for (int i = 0; i < numBridges; i++) {
         scanf("%d%d", &a, &b);
         disjointSet.unions(a, b);
    }
  cout << disjointSet.buildBridges() << endl;

}