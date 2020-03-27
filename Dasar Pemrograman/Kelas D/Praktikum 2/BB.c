#include <stdio.h>

int main() {
    int T;
    int N, X, Y;
    int A, B, C;
    int tanah[100000]={},temp[100000]={};
    int i, j, k;
    int berhasil;
    int max;

    scanf("%d", &T);
    for (i=0; i<T; i++) {
        max=0;
        berhasil = 0;
        /*for(j=0; j<100000; j++){
            tanah[j] = 0;
            temp[j] = tanah[j];
        }*/
        scanf("%d %d %d", &N, &X, &Y);
        for(j=0; j<N; j++) {
            scanf("%d %d %d", &A, &B, &C);
            tanah[A-1] += C;
            tanah[B] -= C;
            if(B>max) {max=B;}
            //for(k=A-1; k<=B-1; k++) {
                //printf("tanah %d : %d + %d = ", k, tanah[k], C);
                //tanah[k] += C;
                //printf("%d\n", tanah[k]);
            //}
        }
        int a = 0;
        for(j=0; j<max; j++) {
            a+=tanah[j];
            tanah[j] = a;
            a-=temp[j];
            //printf("tanah %d nilainya %d a %d\n", j, tanah[j], a);
        }
        // Check
        for(j=0; j<max; j++) {
            if (tanah[j] == X) {
                if (tanah[j] == tanah[j+1]) {
                    berhasil++;
                }
                if (berhasil==Y) {
                    break;
                }
            }
        }
        //Print
        if(berhasil == Y) {
            printf("Akhirnya makan\n");
        } else {
            printf("Sial kelaparan\n");}
    }
}
