#include <stdio.h>
struct Disk {
    int id;
    int Harga;
    int Banyak;
};

int main()
{
    int T;
    int cari;
    scanf("%d", &T);
    struct Disk arr[T];

    for (int i=0; i<T; i++) {
        scanf("%d", &arr[i].id);
        scanf("%d", &arr[i].Harga);
        scanf("%d", &arr[i].Banyak);
    }
    scanf("%d", &cari);
    printf("ID : %d\n", cari);
    for(int i=0; i<T; i++) {
        if(arr[i].id == cari) {
            printf("Harga : %d\n", arr[i].Harga);
            printf("Banyak disc : %d\n", arr[i].Banyak);
        }
    }

    return 0;
}
