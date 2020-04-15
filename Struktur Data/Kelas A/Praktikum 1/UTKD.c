#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    int max;
    int min;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

int main()
{
	Stack myStack;
	stack_init(&myStack);
	int testcase;
	scanf("%d",&testcase);
	char kata[10];
	int i;
	for(i=0;i<testcase;i++)
	{
		scanf("%s",&kata);
//		getchar();
		if(strcmp(kata,"push") == 0)
		{
			int x;
			scanf("%d",&x);
			stack_push(&myStack,x);
			if(myStack.max < x)
			{
				myStack.max = x;
			}
			else if(myStack.min > x)
			{
				myStack.min = x;
			}
		}
		else if(strcmp(kata,"pop") == 0)
		{
			stack_pop(&myStack);
		}
		else if(strcmp(kata,"top") == 0)
		{
			printf("%d\n",stack_top(&myStack));
		}
		else if(strcmp(kata,"max") == 0)
		{
			printf("%d\n",myStack.max);
		}
		else if(strcmp(kata,"min") == 0)
		{
			printf("%d\n",myStack);
		}
//		getchar();
		// testcase--;
	}
}

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
    stack->max = 0;
    stack->min = 0;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) 
	{
        stack->_size++;
        if (stack_isEmpty(stack)) 
        {
        	stack->max = value;
        	stack->min = value;
        	newNode->next = NULL;
        }
        else newNode->next = stack->_top;
		newNode->data = value;
        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
	{
		if(stack->max == stack->_top->data)
		{
			StackNode *temp = stack->_top->next;
			int maks = temp->data;
			while(temp->next != NULL)
			{
				if(maks < temp->next->data)
				{
					maks = temp->next->data;
				}
				temp = temp->next;
			}
			stack->max = maks;
		}
		if(stack->min == stack->_top->data)
		{
			StackNode *temp = stack->_top->next;
			int minim = temp->data;
			while(temp->next != NULL)
			{
				if(minim > temp->next->data)
				{
					minim = temp->next->data;
				}
				temp = temp->next;
			}
			stack->min = minim;
		}
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

