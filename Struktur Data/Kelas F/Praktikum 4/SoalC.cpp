/*
Soal C - "Robot Muterin Kotak"
AC di Revisi Praktikum 

Interpretasi maksud soal:
Ada robot, ada arena
- Arena berbentuk segi empat, dinomori sesuai pattern 1U 1T 2S 2B 3U 3T...NU NT (N+1)S (N+1)B
- Robot bisa jalan satu langkah, dua langkah, ..., n langkah ke depan

Robot di titik P harus bisa sampai di Titik Q
Output program adalah bagaimana robot berjalan ke titik Q disertai arah jalannya (U, S, B, T)


Penjelasan Algo:
(i)     cari N (angka di depan pattern NU NT (N+1)S (N+1)B)
(ii)    cari nomor petak awal ke-N di pattern beserta pattern (ke utara kah, ke barat, etc)
(iii)   cari jawabannya :) 

more below
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int form(int n) {
    //fungsi untuk mencari nomor petak awal ke-N (ii)
    return (n*n) + n;
}
int getN(int P) {
    //fungsi untuk mencari N (i)
    return floor((-1+sqrt(1+4*P))/2);
}

//prototyping fungsi untuk mencari bagaimana robot berjalan ke Q
void printU(int asli, int n, int akhir);
void printT(int asli, int n, int akhir);
void printS(int asli, int n, int akhir);
void printB(int asli, int n, int akhir);


void dir(int P, int Q) {
    // mencari jawaban :) (iii)
    int n = getN(P), resN = form(n), \
     diff = P - resN, val = n + 1;

    // variabel int n menyimpan n, resN menyimpan awal nomor petak di pattern N
    // variable diff menyimpan jarak letak awal robot dengan petak awal nomor pattern
    // val adalah banyaknya petak untuk pattern ke-N

    /*
    0 termasuk ke pattern 1U, dari 0 ke 1 arahnya utara dengan beda 1 angka
    sementara itu, 1U sendiri meng-cover 2 bilangan, yakni 0 dan 1, karena itu val = n + 1
       ^ 1 2
       | 0 3
           4
    */

    //berdasarkan n dan val, diperoleh arah awal robot
    //fungsi yang sesuai dipanggil untuk memulai jalan robot
    if (n % 2 == 0) {
        if (diff >= val) {
            //mulai T
            printT(diff-val, val, Q-P);
            
        }
        else {
            //mulai U
            printU(diff, val, Q-P);
        }
    }
    else {
        if (diff >= val) {
            //mulai B
            printB(diff-val, val, Q-P);
        }
        else {
            //mulai S
            printS(diff, val, Q-P);
        }
    }
}

int main() {
    //input
    int T, P, Q;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &P, &Q);
        dir(P, Q);
    }
  
}

//setiap fungsi print dibawah ini pada dasarnya sama aja
//keempat fungsi akan dijalankan sesuai urutan U->T->S->B sampai di tujuan
//fungsi menerima sejauh mana robot bisa berjalan untuk pattern ke-n tersebut sebelum belok, 
//nilai n, dan seberapa jauh lagi harus jalan

void printU(int asli, int n, int akhir) {
    int hasil = 0, tempA = akhir;

    if (n <= akhir) {
        tempA = akhir - n + asli;
        hasil = n - asli;
    }
    else if (n > akhir) {
        for (tempA; tempA - 1 >= 0; tempA--) hasil++;
    }
    cout << hasil << "U";

    if (tempA <= 0) cout << endl;
    else {
        cout << " -> ";
        printT(0, n, tempA);
    }
}

void printT(int asli, int n, int akhir) {
    int hasil = 0, tempA = akhir;

    if (n <= akhir) {
        tempA = akhir - n + asli;
        hasil = n - asli;
    }
    else if (n > akhir) {
        for (tempA; tempA - 1 >= 0; tempA--) hasil++;
    }
    cout << hasil << "T";

    if (tempA <= 0) cout << endl;
    else {
        cout << " -> ";
        n++;
        printS(0, n, tempA);
    }
}

void printS(int asli, int n, int akhir) {
    int hasil = 0, tempA = akhir;

    if (n <= akhir) {
        tempA = akhir - n + asli;
        hasil = n - asli;
    }
    else if (n > akhir) {
        for (tempA; tempA - 1 >= 0; tempA--) hasil++;
    }

    cout << hasil << "S";

    if (tempA <= 0) cout << endl;
    else {
        cout << " -> ";
        printB(0, n, tempA);
    }
}

void printB(int asli, int n, int akhir) {
    int hasil = 0, tempA = akhir;

    if (n <= akhir) {
        tempA = akhir - n + asli;
        hasil = n - asli;
    }
    else if (n > akhir) {
        for (tempA; tempA - 1 >= 0; tempA--) hasil++;
    }
    cout << hasil << "B";

    if (tempA <= 0) cout << endl;
    else {
        cout << " -> ";
        n++;
        printU(0, n, tempA);
    }
}