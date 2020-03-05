#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

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
        newNode->data = value;
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else {newNode->next = stack->_top;}

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

void stack_print(Stack *stack) {
    StackNode *temp = stack->_top;

    while(temp!=NULL) {
        printf("%d", temp->data);
        if(temp->next != NULL) {
            printf(" ");
        }
        temp=temp->next;
    }
    printf("\n");
}

void stack_pushAll (Stack *stack, Stack *stack2) {
    StackNode *temp = stack->_top;
    while (temp!=NULL) {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            stack2->_size++;
            newNode->data = temp->data;
            if (stack_isEmpty(stack2)) newNode->next = NULL;
            else newNode->next = stack2->_top;

            stack2->_top = newNode;
        }
        temp=temp->next;
    }
}

int main(int argc, char const *argv[])
{
    Stack myStack, myStack2;

    int T, N, B;

    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        stack_init(&myStack);
        stack_init(&myStack2);
        scanf("%d", &N);
        for(int j=0; j<N; j++) {
            scanf("%d", &B);
            while(stack_top(&myStack) < B) {
                if(!stack_isEmpty(&myStack)) {
                    //printf("%d %d\n", stack_top(&myStack), B);
                    stack_pop(&myStack);
                } else {break;}
            }
            stack_push(&myStack, B);
        }
        stack_pushAll(&myStack, &myStack2);
        stack_print(&myStack2);
    }

    return 0;
}
