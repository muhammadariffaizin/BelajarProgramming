#include <stdio.h>
#include <string.h>

int main(){
    int i, j, k,
        tinggi, lebar, index,
        letakX, letakY, langkah[4],
        min,
        batas = 1;
    char input;
    //input size
    scanf("%d %d", &tinggi, &lebar);
    int maze[lebar + 2][tinggi + 2];
    int history[tinggi * lebar][2];
    int awal[2], akhir[2];

    //input maze
    for(i = 1; i <= tinggi; i++){
        for(j = 1; j <= lebar; j++){
            scanf(" %c", &input);
            if(input == 'S'){
                index = 1;

                awal[0] = j;
                awal[1] = i;
            }
            else if(input == '.') index = 1;
            else if(input == '#') index = -2;
            else if(input == 'F'){
                index = 1;
                history[0][0] = j; //X
                history[0][1] = i; //Y

                akhir[0] = j; //X
                akhir[1] = i; //Y
            }
            maze[j][i] = index;
        }
    }
    for(i = 0; i < batas; i++){
        letakX = history[i][0];
        letakY = history[i][1];
        if(maze[letakX][letakY - 1] == 1){
            maze[letakX][letakY - 1] += maze[letakX][letakY];
            history[batas][0] = letakX;
            history[batas][1] = letakY - 1;
            batas++;
        }

        //kiri
        if(maze[letakX - 1][letakY] == 1){
            maze[letakX - 1][letakY] += maze[letakX][letakY];
            history[batas][0] = letakX - 1;
            history[batas][1] = letakY;
            batas++;
        }

        //bawah
        if(maze[letakX][letakY + 1] == 1){
            maze[letakX][letakY + 1] += maze[letakX][letakY];
            history[batas][0] = letakX;
            history[batas][1] = letakY + 1;
            batas++;
        }

        //kanan
        if(maze[letakX + 1][letakY] == 1){
            maze[letakX + 1][letakY] += maze[letakX][letakY];
            history[batas][0] = letakX + 1;
            history[batas][1] = letakY;
            batas++;
        }

        if(i == 0) maze[letakX][letakY] = 0;
    }

    min = maze[awal[0]][awal[1]] - 1;
    maze[akhir[0]][akhir[1]] = 1;

    int click = 1;
    if(maze[awal[0]][awal[1]] == 1){
        click = 0;
        printf("Tidak ada jalan menuju F.\n");
    }

    if(click == 1){
        //print step
        printf("Langkah minimum: %d\n", min);

        //backtrack
        // printf("processing %d'th queue\n", i);

        letakX = awal[0];
        letakY = awal[1];

        for(i = 0; i < min; i++){

            //atas
            if(maze[letakX][letakY - 1] == maze[letakX][letakY] - 1){
                printf("%c", 'T');
                letakX = letakX;
                letakY = letakY - 1;
            }
            //kiri
            else if(maze[letakX - 1][letakY] == maze[letakX][letakY] - 1){
                printf("%c", 'L');
                letakX = letakX - 1;
                letakY = letakY;
            }
            //bawah
            else if(maze[letakX][letakY + 1] == maze[letakX][letakY] - 1){
                printf("%c", 'B');
                letakX = letakX;
                letakY = letakY + 1;
            }
            //kanan
            else if(maze[letakX + 1][letakY] == maze[letakX][letakY] - 1){
                printf("%c", 'R');
                letakX = letakX + 1;
                letakY = letakY;
            }

            if(i != min - 1) printf(" ");
        }
        printf("\n");
    }

    //test print
//    for(int i=1; i<=tinggi; i++) {
//        for(int j=1; j<=lebar; j++) {
//            printf("%d ", maze[j][i]);
//            if(maze[j][i]>0) {
//                printf(" ");
//            }
//        }
//        printf("\n");
//    }
    return 0;
}
/*
4 4
#.S#
...#
#.#.
...F
*/
