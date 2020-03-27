#include <stdio.h>

char lahan[11][11];
int area=0;

void cari() {
    /*
    if(lahan[x][y]=="#") {
        ketemu=1;
        cari(x+1,y);
        cari(x,y+1);
    }
    */
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(lahan[i][j]=='.') {
                area++;
                cek(i,j);
            }
        }
    }
}

void cek(int x, int y) {
    lahan[x][y]='_';
    //atas
    if(lahan[x-1][y]=='.' && x>=0) {
        cek(x-1, y);
    }
    //kiri
    if(lahan[x][y-1]=='.' && y>=0) {
        cek(x, y-1);
    }
    //bawah
    if(lahan[x+1][y]=='.' && x<10) {
        cek(x+1, y);
    }
    //kanan
    if(lahan[x][y+1]=='.' && y<10) {
        cek(x, y+1);
    }
}

int main() {
    for(int i=0; i<10; i++) {
        //for(int j=0; j<10; j++) {
            scanf("%s", &lahan[i]);
        //}
    }
    cari();

    /*
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            printf("%c", lahan[i][j]);
        }
        printf("\n");
    }
    */

    printf("%d\n", area);
}

/*
..#....#.#
..#.....#.
..#.......
..########
..........
..........
....######
....#.....
....#.....
....#.....

#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
#.#.#.#.#.
.#.#.#.#.#
*/
