#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int size;
    int i,j,k;
    int bilangan;

    scanf("%d", &bilangan);
    for(int x=0; x<bilangan; x++){
        scanf("%s", text);
        size=strlen(text);

        for (i=0; i<size; i++) {
            for (j=0; j<size; j++) {
                if(i != j) {
                    if(text[i]==text[j]){
                        for(k=j; k<size; k++) {
                            text[k]=text[k+1];
                        }
                    }
                    //printf("%d %d %d-%d\n", i,j, text[i], text[j]);
                }
            }
        }
        printf("%s\n", text);
    }
}
