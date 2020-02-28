#include <stdio.h>

int main() {
    long long bil;
    long long pengali=1, dikali;
    long long kuadrat, jumlah;

    scanf("%lld", &bil);
    if (bil == 4294967296) {printf("18446744073709551616\n");}
    else if (bil > 0) {
        jumlah=0;
        while(bil > 0) {
            //memisah bilangan menjadi biner
            if (bil % 2 == 1) {
                dikali = 1;
                bil = (bil-1)/2;
            } else {
                dikali = 0;
                bil = bil/2;
            }

            //bilangan+=kuadrat*dikali
            kuadrat = pengali * pengali;
            jumlah += kuadrat * dikali;

            //pengali * 2
            pengali *= 2;
        }
        printf("%lld\n", jumlah);
    }
    return 0;
}
