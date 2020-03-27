#include <stdio.h>
#include <string.h>

int lost, found=-1;
char a[100], b[100], c[100];

void permute(char *a, char *b, int *count, int level)
{
    if (level == strlen(a)){
        b[level] ='\0';
        if(strcmp(b,c) == 0) {
            found = lost;
        }
        if(found>0) {
            found--;
        } else if (found == 0) {
            printf("%s\n", b);
            found=-1;
        }
        return;
    }
    else {
        for (int i=0; i < strlen(a); i++)
        {
            if(count[i]==0) {
                continue;
            } else {
                b[level] = a[i];
                count[i]--;
                permute(a, b, count, level+1);
                count[i]++;
            }
        }
    }
}
int main()
{
    int count[100];
    for (int i=0; i<100; i++) {
        count[i] = 1;
    }
    scanf("%s %s", a, c);
    scanf("%d", &lost);
    permute(a, b, count, 0);
    return 0;
}
