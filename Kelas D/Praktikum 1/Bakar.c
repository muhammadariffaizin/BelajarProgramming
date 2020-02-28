#include <stdio.h>
#include <math.h>

int main() {
    int i, j;
    double a, b;
    int bil;
    double hasil, akar;
    scanf("%d", &bil);
    for(i=0; i<bil; i++) {
        scanf("%lf %lf", &a, &b);
        hasil=sqrt((a*a)+(b*b));
        printf("%.3lf\n", 2*hasil);
    }


}
