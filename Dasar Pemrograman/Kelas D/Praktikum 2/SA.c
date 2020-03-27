#include <stdio.h>

int main() {
    long long N;
    long long Q;

    scanf("%lld", &N);
    long long  H[N], B[N];
    for (long long i=0; i<N; i++) {
        scanf("%lld", &H[i]);
        B[i] = H[i];
    }
    scanf("%lld", &Q);
    for(long long i=0; i<Q; i++) {
        long long L, R, X;
        scanf("%lld %lld %lld", &L, &R, &X);
        H[L-1] += X;
        H[R] -= X;
    }
    long long a = 0;
    for(long long i=0; i<N; i++) {
        a += H[i];
        H[i] = a;
        a -= B[i];
    }

    for(long long i=0; i<N; i++) {
        printf("%lld", H[i]);
        if(i<N-1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}
