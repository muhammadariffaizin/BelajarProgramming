#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t 
{
    int masuk;
    int keluar;
    struct snode_t *next;
} SListNode;

/* Struktur ADT Stack */

typedef struct slist_t 
{
    unsigned _size;
    int _mobil;
    int jam;
    SListNode *_head;
} SinglyList;

/* Function prototype */

void check(SinglyList *, int *, int *);
void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value, int);
void slist_popFront(SinglyList *list);
void slist_remove(SinglyList *list, int value);
void slist_printList (SinglyList *);

int main()
{
	SinglyList myPark; // deklarasi linked list
	slist_init(&myPark); // membuat node baru
	int kapasitas, jumlah;
	scanf ("%d %d", &kapasitas, &jumlah); // input kapasitas parkiran dan jumlah kendaraan
                                          // yang ada
	myPark._size=kapasitas; // membuat kapasitas parkir berdasarkan yang diinput
	int i;
	for (i=0;i<jumlah;i++)
	{
		int melbu, metu;
		scanf ("%d %d", &melbu, &metu); // input jam masuk dan jam keluar parkir
		slist_pushFront(&myPark, melbu, metu); // input masuk ke dalam fungsi push
	}
	scanf ("%d", &myPark.jam); // input jam parkir yang ingin dimasukkan
	int cekKap, cekKar;
	check(&myPark, &cekKap, &cekKar); // cek tempat parkir penuh atau tidak
	if (myPark._size==myPark._mobil) printf ("Coba reschedule!\n"); /* jika penuh,
															cetak "Coba reschedule!" */
	else printf("Semangat wawancaranya!\n"); /* jika masih ada yang kosong,
												cetak "Semangat wawancaranya!" */
}

void check(SinglyList *list, int *cekKap, int *cekKar){
	/* fungsi untuk mengecek apakah di dalam node ada yang kosong atau tidak */
	SListNode *temp=list->_head;
	while (temp!=NULL){
		if (temp->masuk<=list->jam){
		list->_mobil++;
		/* jika yang masuk kurang atau sama dengan jam yang akan Aya masuk,
			maka kendaraan bertambah, sehingga Aya harus reschedule */
		}
		if (temp->keluar<=list->jam)
		{
			list->_mobil--;
		/* jika yang keluar kurang atau sama dengan jam yang akan Aya masuk,
			maka kendaraan berkurang, sehingga Aya bisa tes wawancara */
		}
		temp=temp->next;
	}
}

void slist_printList(SinglyList *list) 
{
	/* fungsi untuk mencetak semua yang ada di dalam node */
    SListNode *np = list->_head;
    while (np != NULL) 
    {
        printf("%d %d\n", np->masuk, np->keluar); // jam masuk dan keluar
        np = np->next;
    }
    return;
}

void slist_init(SinglyList *list) 
{
	/* fungsi untuk membuat node baru */
    list->_head = NULL;
    list->_size = 0;
    list->_mobil=0;
}

bool slist_isEmpty(SinglyList *list) 
{
	/* cek apakah node tersebut kosong atau tidak */
    return (list->_head == NULL);
}

void slist_remove(SinglyList *list, int metu)
{
    /* fungsi untuk menghapus elemen di dalam node,
        fungsi ini juga memanggil fungsi pop untuk
        mengeluarkan elemen di dalam node */
    if (!slist_isEmpty(list)) 
    {
        SListNode *temp, *prev;
        temp = list->_head;
        if (temp->keluar == metu) 
        {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->keluar != metu) 
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushFront(SinglyList *list, int melbu, int metu) 
{
    /* fungsi untuk menambah elemen di dalam node dari depan */
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) 
    {
        newNode->masuk = melbu;
        newNode->keluar =metu;
        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    /* fungsi untuk mengeluarkan elemen dari node */
    if (!slist_isEmpty(list)) 
    {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}
