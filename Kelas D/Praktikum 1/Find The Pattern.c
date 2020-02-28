#include <stdio.h>

int main() {
    int x, y, bil;
    int juml;
    scanf("%d %d", &x, &y);
    scanf("%d", &bil);

    juml=x;
    for(int j=0; j<bil; j++){
        for(int l=0; l<juml; l++) {
            printf("^");
        }
        juml+=y;
        printf("\n");
    }


}
