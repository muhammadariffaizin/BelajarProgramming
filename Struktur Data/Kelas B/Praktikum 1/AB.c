#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct stackNode_t {
    char data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char value);
void stack_pop(Stack *stack);
char stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char value)
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

char stack_top(Stack *stack)
{
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}


int main() {
    char input[100];
    int size;
    gets(input);
    size = strlen(input);

    Stack Palindrome;
    stack_init(&Palindrome);

    for(int i=0; i<size; i++) {
        if(size/2<(size+1)/2 && i == size/2) continue;
        if(i<size/2) {
            stack_push(&Palindrome, input[i]);
        } else if (i+1>size/2) {
            if(input[i]==stack_top(&Palindrome)) {
                stack_pop(&Palindrome);
            } else {
                printf("mahal, eh bukan palindrom deh\n");
                return 0;
            }
        }
    }
    printf("palindrom\n");
    return 0;
}
