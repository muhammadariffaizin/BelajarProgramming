#include <stdio.h>

void ganti(int *a, int *b){
	int s;
	s = *a;
	*a = *b;
	*b = s;
}

typedef struct{
	char nama [10];
}alamat_awal;

int main(){
	int n, q, a, b, c, id [20000], ids [20000];

	scanf ("%d", &n);
	alamat_awal array [20000];
	for (a = 0; a < n; a++){
		scanf ("%d%s", &id [a], &array [a].nama);
		ids [a] = a;
	}

	scanf ("%d", &q);
	int selip [q], no [q];
	for (a = n; a < n + q; a++){
		scanf ("%d%d%s", &selip [a - n], &id [a], &array [a].nama);
		no [a - n] = a;
		ids [a] = a;
	}

//	for (a = 0; a < n + q; a++)
//	printf ("%d ", ids [a]);

	//Perhitungan
	for (a = 0; a < q; a++){
		for (b = 0; b < n + q; b++){
			if (selip [a] == id [b]){
				ganti (&id [b + 1], &id [no [a]]);
				ganti (&ids [b + 1], &ids [no [a]]);
				c = no [a];
				while (c > b + 2){
					ganti (&ids [c], &ids [c - 1]);
					ganti (&id [c], &id [c - 1]);
					c--;
				}
			}
		}
	}

	for (a = 0; a < n + q; a++){
//		printf ("%d. %d\n", a + 1, ids [a] + 1);
		printf ("%s", array [ids [a]].nama);
		if (a != n + q - 1)
		printf (" ");
	}
	printf ("\n");

	return 0;
}
