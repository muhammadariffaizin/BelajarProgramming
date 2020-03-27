#include <stdio.h>

struct Ksatria {
    char Nama[101];
    long long X;
    int Nyawa;
};

int main() {
    int N;
    long long Y;
    long long Z;
    scanf("%d", &N);
    struct Ksatria Orang[N];
    for (int i=0; i<N; i++) {
        scanf("%s", &Orang[i].Nama);
        scanf("%lld", &Orang[i].X);
        Orang[i].Nyawa = 100;
    }
    /*
    for (int i=0; i<N; i++) {
        printf("%s", Orang[i].Nama);
        printf("%d", Orang[i].X);
    }*/
    scanf("%lld %lld", &Y, &Z);
    for(int i=0; i<N; i++) {
        if(Z==0 && Orang[i].X == 0) {
            if(i==N-1) {
                return 0;
            }
        }
    }

    int tamat=0;
    int index=0;
    while (tamat == 0) {
        Y-=Orang[index].X;
        Orang[index].Nyawa-=Z;
        //printf("%s %d vs %d\n", Orang[index].Nama, Orang[index].Nyawa, Y);

        if(Orang[index].Nyawa > 0 && Y<=0 && index==0) {
            tamat = 1 ;
            printf("Monster mati dibunuh %s\n", Orang[index].Nama);
            printf("Orang yang mati :\n");
            return 0;
        }

        else if(Orang[index].Nyawa<=0) {
            index++;
        }

        //jika dua2nya mati
        if(Y<=0 && index>N-1) {
            tamat = 1;
            printf("Monster mati dibunuh %s\n", Orang[index-1].Nama);
            printf("Orang yang mati :\n");
            for (int i=0; i<index; i++) {
                if(Orang[i].Nyawa <= 0) {
                    printf("%d. %s\n", i+1, Orang[i].Nama);
                }
            }
        }
        //jika semua ksatria mati
        else if(index>N-1) {
            tamat = 1;
            printf("Monster gagal dibunuh\n");
        }
        //jika monster mati
        else if(Y<=0) {
            tamat = 1;
            printf("Monster mati dibunuh %s\n", Orang[index-1].Nama);
            printf("Orang yang mati :\n");
            for (int i=0; i<index; i++) {
                if(Orang[i].Nyawa <= 0) {
                    printf("%d. %s\n", i+1, Orang[i].Nama);
                }
            }
        }
    }
}
