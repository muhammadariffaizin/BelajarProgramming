#include <stdio.h>
unsigned long long find(unsigned long long x) {
    if (x==1|| x==2) {
        return 1;
    } else if (x>2) {
        return find(x-1) * find(x-2) * 2;
    }
}

int main() {
    int n;

    scanf("%d", &n);
    int cari;

    for(int i=0; i<n; i++) {
        scanf("%d", &cari);
        printf("%llu\n", find(cari+1));
    }
}
