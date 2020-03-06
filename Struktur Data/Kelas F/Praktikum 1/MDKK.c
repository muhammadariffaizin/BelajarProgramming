/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
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

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);
void pindah(Stack *awal,Stack *akhir);
void print(Stack *adik,Stack *mas);

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack mumud;
    Stack kakak;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&mumud);
	stack_init(&kakak);
	
	int n,t,a,b;
	scanf("%d",&n);
	int nn=n;
	bool tumpukan_salah=false;
	
	while(n)
	{
		stack_push(&mumud,n);
		n--;
	}
	//printd(&mumud);
	scanf("%d",&t);
	while(t)
	{
		scanf("%d %d",&a,&b);
//		printf("\t\t%d\n",t);
		if(a==1)
		{
			while(b)
			{
				pindah(&mumud, &kakak);
				b--;
			}
		}
		else
		if(a==2)
		{
			while(b)
			{
				pindah(&kakak, &mumud);
				b--;
			}
		}
		else
		if(a!=1 && a!=2)
		{
			tumpukan_salah=true;
		}
		t--;
	}
	if(tumpukan_salah)
	{
		printf("TumpukAnnya saLah! :(\n");
	}
	else
	if(nn<=0 && !tumpukan_salah)
	{
		printf("MudMud SangaT MaraH!\n");

	}
	else
		print(&mumud,&kakak);
    return 0;
}

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        newNode->data = value;
        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void pindah(Stack *awal,Stack *akhir) 
{
	int move;
	if(!stack_isEmpty(awal))
	{
		move = awal->_top->data;
		stack_push(akhir,move);
    	stack_pop(awal);
	}
}

void print(Stack *adik,Stack *mas)
{
	int sizeadik = stack_size(adik);
	int sizemas = stack_size(mas);
	
		/* Output */
	while (!stack_isEmpty(adik) || !stack_isEmpty(mas)) {
		/* size mumud < size kakak */
		if (stack_isEmpty(adik) && sizeadik >= 0){
			printf("MudMud Marah!\t");
			sizeadik = -1;
		}
		else if (!stack_isEmpty(adik)) {
			/* size mumud = 0 */
			if(stack_top(adik) == 0)
				continue;
			else{
				printf("%d\t\t", stack_top(adik));
		   		stack_pop(adik);
			}
		}
		/* rapihkan output ketika mumud sudah habis */
		else if(stack_isEmpty(adik) && sizeadik == -1){
			printf("\t\t");
		}
		if (stack_isEmpty(mas) && sizemas >= 0){
			printf("MudmuD KasihAn!");
			sizemas = -1;
		}
		else if (!stack_isEmpty(mas)) {
			printf("%d", stack_top(mas));
	        stack_pop(mas);
		}
		printf("\n");
	}

}
