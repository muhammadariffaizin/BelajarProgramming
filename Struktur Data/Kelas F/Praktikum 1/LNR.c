/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
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

typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

int n=0;
/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);
void print(PriorityQueue *pqueue);

int main()
{
    // Buat objek PriorityQueue
    PriorityQueue mypque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&mypque);

    int i,x;
//    scanf("%d",&n);
    do
    {
    	scanf("%d",&x);
    	if(x != (-1))
    		pqueue_push(&mypque,x);
//    	printf("%d \n",pqueue_top(&mypque));
	}
	while(x != (-1));
	
	print(&mypque);
//	while(!pqueue_isEmpty(&mypque))
//	{
//		if(n>0)
//		{
//			printf("%d ",pqueue_top(&mypque));
//		}
//		else
//			printf("%d!",pqueue_top(&mypque));
//		pqueue_pop(&mypque);
//	}
	printf("\n");
    return 0;
}

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data <= value)
            {
            	temp = temp->next;
//            	if(temp->data == value)
//            	{
//            		break;
//				}
			}
            
        if(temp->data != value)
        {
        	newNode->next = temp->next;
        	temp->next = newNode;
		}
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

void print(PriorityQueue *pqueue)
{
	PQueueNode *temp = pqueue->_top;
	while(!pqueue_isEmpty(&temp))
	{
		if(temp->next != NULL)
		{
			printf("%d ",pqueue_top(&temp));
		}
		else
			printf("%d",pqueue_top(&temp));
		pqueue_pop(&temp);
	}
}
