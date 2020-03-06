/**
 * Implementasi ADT Deque (Double-ended Queue)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

int main(int argc, char const *argv[])
{
//    deq_init(&data1);

    int i,j,n,jumlah,count1,count2,max;
    scanf("%d",&n);
    bool stop;
    int na,nb,batas,x;
    while(n)
    {
    	Deque data1;
    	deq_init(&data1);
    	
    	stop=false;
    	jumlah=0;
    	max=0;
    	count1=0;
    	count2=0;
    	scanf("%d %d %d",&na,&nb,&batas);
    	while(na)
    	{
//    		printf("a")-;
    		scanf("%d",&x);
    		if(jumlah+x > batas)
    		{
    			stop=true;
			}
    		if(jumlah+x <= batas && !stop)
    		{
    			deq_pushBack(&data1,x);
    			jumlah+=x;
    			count1++;
			}
//			printf("%d\n",jumlah);
    		na--;
		}
		max=count1;
//		printf("max: %d\n",max);
//		stop=false;
		while(nb)
		{
//			printf("b");
			scanf("%d",&x);
			jumlah+=x;
			count2++;
//			printf("%d!\n",jumlah);
			while(jumlah>batas && !deq_isEmpty(&data1))
			{
				jumlah -= deq_back(&data1);
				count1--;
				deq_popBack(&data1);
				
			}
//			printf("%d\n",jumlah);
//			printf("%d\n",jumlah);
			if(max < count1+count2 && jumlah<=batas)
			{
				max=count1+count2;
			}
//			if(stop)
//				break;
//			printf("%d %d max: %d\n",count1,count2,max);
			nb--;
		}
		printf("%d\n",max);
		n--;
	}
    
    return 0;
}

/* Definisi Fungsi */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}
