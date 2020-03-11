#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ULL unsigned long long int

typedef struct dynamicarr_t {
    ULL *_arr;
    unsigned _size, _capacity;
} DynamicArray;

typedef struct dnode_t {
    ULL data;
    struct dnode_t      
        *next,
        *prev;
} DListNode;

typedef struct deque_t {
    DListNode           
        *_head, 
        *_tail;
    unsigned _size;
}Deque;

DListNode* __dlist_createNode(ULL value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, ULL value);
void deq_pushBack(Deque *deque, ULL value);
ULL  deq_front(Deque *deque);
ULL  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);
void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, ULL value);
ULL dArray_getAt(DynamicArray *darray, unsigned index);
ULL total_max(DynamicArray *arr,ULL n,ULL k);

int main(){
    DynamicArray myarr;
    dArray_init(&myarr);
    ULL n,k,i,sem;
    scanf("%llu %llu",&n,&k);
    for(i=0;i<n;i++){
        scanf("%llu",&sem);
        dArray_pushBack(&myarr,sem);
    }
    printf("%llu\n",total_max(&myarr,n,k));
    
    return 0;
}

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2;
    darray->_size = 0;
    darray->_arr = (ULL*) malloc(sizeof(ULL) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, ULL value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        ULL *newArr = (ULL*) malloc(sizeof(ULL) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        ULL *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

ULL dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

DListNode* __dlist_createNode(ULL value){
    DListNode *newNode = (DListNode*) malloc (sizeof(DListNode));
    
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
    return (deque->_head == NULL && deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, ULL value)
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

void deq_pushBack(Deque *deque, ULL value)
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

ULL deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

ULL deq_back(Deque *deque) {
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

ULL total_max(DynamicArray *arr,ULL n,ULL k){
    
    Deque deq;
    deq_init(&deq);
    ULL i,total=0; 

	for (i = 0; i < k; ++i) { 
		while (!deq_isEmpty(&deq) && dArray_getAt(arr,i) >= dArray_getAt(arr,deq_back(&deq))) 
			deq_popBack(&deq);
		deq_pushBack(&deq,i);
	} 

	for (; i < n; ++i) { 
		total += dArray_getAt(arr,deq_front(&deq));

		while (!deq_isEmpty(&deq) && deq_front(&deq) <= i - k) 
			deq_popFront(&deq);
        
        while (!deq_isEmpty(&deq) && dArray_getAt(arr,i) >= dArray_getAt(arr,deq_back(&deq))) 
			deq_popBack(&deq); 
		
        deq_pushBack(&deq,i); 
	} 

	total += dArray_getAt(arr,deq_front(&deq));
    return total;
}
