#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int search(Stack *stack, int value);

int main()
{
	int testcase;
	Stack myHead; // deklarasi stack
	scanf("%d",&testcase); // membuat testcase
	while(testcase)
	{
		int tumpukan;
		stack_init(&myHead); // membuat node baru
		scanf("%d",&tumpukan); // mengisi berapa isi tumpukan yang diinginkan
		while(tumpukan)
		{
			int angka;
			scanf("%d",&angka); // mengisi tumpukan dengan angka 
			stack_push(&myHead,angka); // angka masuk ke stack
			tumpukan--;
		}
		int cari;
		scanf("%d",&cari); // mencari angka yang dicari
		int hasil = search(&myHead,cari);
		printf("%d\n",hasil); /* menampilkan hasil angka yang dicari, jika ketemu, 
							     print angka tsb, jika tidak, maka print -1 */
		testcase--;
	}
}

void stack_init(Stack *stack) 
{
	/* fungsi untuk membuat node baru */
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) 
{
	/* fungsi untuk mendeteksi isi stack kosong atau tidak */
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
	/* fungsi untuk mengisi stack dari atas */
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) 
	{
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
	/* fungsi untuk menghapus data dari tumpukan paling atas */
    if (!stack_isEmpty(stack)) 
	{
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
	/* fungsi untuk mendapatkan data pada tumpukan paling atas */
    if (!stack_isEmpty(stack))
	{ 
        return stack->_top->data;
        /* mengembalikan nilai yang ditunjuk oleh pointer */
    }
    return 0;
}

unsigned stack_size(Stack *stack) 
{
	/* menentukan ukuran dari stack */
    return stack->_size;
}

int search(Stack *stack, int value)
{
	/* fungsi untuk mencari element pada stack */
	int njir = 0;
	while(!stack_isEmpty(stack))
	{
		if(stack->_top->data == value)
		{
			return njir;
			/* jika pointer menunjuk angka yang sama dengan yang dicari,
			 maka nilainya dikembalikan */
		}
		else
		{
			stack_pop(stack);
			njir++;
			/* jika tidak sama, maka angka yang ditunjuk dipop, lalu berpindah ke 
				angka setelahnya sampai bertemu nilai yang sama */
		}
	}
	return -1;
}
