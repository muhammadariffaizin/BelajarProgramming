#include <stdio.h>

int main() {
    int i, j;
    int a, b;
    int temp;
    int digit;
    int bilangan[200];

    digit=0;
    scanf("%d %d", &a, &b);
    bilangan[0]=1;
    if(a==0||b==0) {
        printf("0");
    } else {
        for(i=a; i>a-b; i--) {
            temp = 0;
             for(j=0; j<=digit; j++) {
                temp=(bilangan[j]*i)+temp;
                bilangan[j] = temp%10;
                temp = temp/10;
            }
            while(temp>0) {
                bilangan[++digit]=temp%10;
                temp=temp/10;
            }
        }
        for(i=digit; i>=0; i--) {
            printf("%d", bilangan[i]);
        }
    }
    printf("\n");
    return 0;
}
