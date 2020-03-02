#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct dnode_t {
    int data;
    int id;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

typedef struct deque_t {
    DListNode           \
        *_head,
        *_tail;
    unsigned _size;
} Deque;

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value, int id);
void deq_pushBack(Deque *deque, int value, int id);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

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

void deq_pushFront(Deque *deque, int value, int id)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        newNode->id = id;
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

void deq_pushBack(Deque *deque, int value, int id)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        newNode->id = id;
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

int deq_size(Deque *deque) {
    return deque->_size;
}

int deq_backId(Deque *deque) {
    if(!deq_isEmpty(&deque)) {
        return deque->_tail->id;
    }
    return 0;
}

int deq_frontId(Deque *deque) {
    if(!deq_isEmpty(&deque)) {
        return deque->_head->id;
    }
    return 0;
}

int deq_min(Deque *deque) {
    DListNode *temp = deque->_head->next;
    int min = deque->_head->data;

    while(temp!=NULL) {
        if(temp->data < min) {
            min = temp->data;
        }
        temp=temp->next;
    }
    return min;
}

int main(int argc, char const *argv[])
{
    Deque mydeq;
    deq_init(&mydeq);

    int n, t, b;
    int hitung=0;
    int min;

    scanf("%d", &n);
    scanf("%d", &t);

    for(int i=0; i<n; i++) {
        scanf("%d", &b);
        //printf("%d\n", deq_size(&mydeq));
        if(deq_isEmpty(&mydeq)) {
            deq_pushBack(&mydeq, b, i);
        }
        if(deq_frontId(&mydeq) + 1 <= i-t+1 && deq_backId(&mydeq)+1 >= t){
            //printf("(%d)\n", deq_backId(&mydeq));
            deq_popFront(&mydeq);
        }
        if(deq_back(&mydeq)>=b) {
            while(deq_back(&mydeq)>=b && !deq_isEmpty(&mydeq)){
                deq_popBack(&mydeq);
            }
            deq_pushBack(&mydeq, b, i);
        }
        if(deq_back(&mydeq)<b) {
            deq_pushBack(&mydeq, b, i);
        }
        if(i>=t-1){
            printf("%d", deq_front(&mydeq));
        }
        if(i>=t-1 && i<n) {
            printf("\n");
        }
    }
    return 0;
}
