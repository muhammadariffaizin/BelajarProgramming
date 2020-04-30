#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int unit;

unit arr[100100] = {};

unit md = 1000000000 + 7;

int main(){
    unit n = 0;
    scanf("%llu",&n);
    getchar();
    unit i = 0;
    for (;i < n;i++){
        unit x = 0;
        while (1){
            char c = getchar();
            if (c == '\n') break;

            unit a = 1;
            unit b = (c - '0');

            x |= a << b;
        }
        arr[i] = x;
    }
    unit val = 0;
    for (i = 0;i < n;i++){
        unit j = i + 1;
        for (;j < n;j++){
            unit temp = arr[i] & arr[j];
            if (temp != 0){
                val = ((val % md) + (1 % md)) % md;
            }
        }
    }
    printf("%llu\n",val);
    // system("pause");
}
