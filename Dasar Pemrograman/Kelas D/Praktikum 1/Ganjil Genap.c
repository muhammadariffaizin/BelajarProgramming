#include <stdio.h>

int main() {
    int bil;
    long i;
    long ganjil, genap;
    ganjil = 0;
    genap = 0;
    scanf("%d", &bil);
    for(int x=0; x<bil; x++) {
        scanf("%ld", &i);
        if(i%2==0) {
            genap+=i;
        } else {
            ganjil-=i;
        }
    }
    printf("%ld\n", ganjil+genap);
}
