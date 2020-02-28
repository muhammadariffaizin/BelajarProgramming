#include <stdio.h>

int main() {
    int a, b, X;
    int sama;
    int jetA=0, jetB=0;
    int jumlahA=0, jumlahB=0;
    int i, j, k;
    scanf("%d %d %d", &a, &b, &X);
    for(i=a; i<X; i+=a) {
        jetA+=a;
        if(jetA%b == 0) {
            //printf("%d", jetA);
            continue;
        }
        jumlahA+=jetA;
    }
    for(j=b; j<X; j+=b) {
        jetB+=b;
        jumlahB+=jetB;
    }
    printf("%d\n", jumlahA+jumlahB);
}
