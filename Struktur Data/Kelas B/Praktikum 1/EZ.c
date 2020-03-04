#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct stackNode_t {
    int data;
    int max;
    int max2;
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
        if (stack_isEmpty(stack)) {
            newNode->next = NULL;
            newNode->max = value;
            newNode->max2 = 0;
        }
        else {
            if(value > stack->_top->max) {
                newNode->max2 = stack->_top->max;
                newNode->max = value;
            } else if(value <= stack->_top->max && value > stack->_top->max2) {
                newNode->max2 = value;
                newNode->max = stack->_top->max;
            } else {
                newNode->max = stack->_top->max;
                newNode->max2 = stack->_top->max2;
            }
            newNode->next = stack->_top;
        }
        //printf("!!%d %d!!\n", newNode->max, newNode->max2);
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

int stack_max(Stack *stack) {
    return stack->_top->max;
}

int stack_max2(Stack *stack) {
    return stack->_top->max2;
}

int main(int argc, char const *argv[])
{
    int N, Q, X, V, L, R;

    scanf("%d %d", &N, &Q);

    Stack myStack[N];

    for(int i=0; i<N; i++) {
        stack_init(&myStack[i]);
    }
    while(Q--) {
        int pilihan;

        scanf("%d", &pilihan);
        if(pilihan==1) {
            scanf("%d %d", &X, &V);
            if(X<=N) {
                stack_push(&myStack[X-1], V);
            }
        } else if(pilihan==2) {
            scanf("%d", &X);
            stack_pop(&myStack[X-1]);
        } else if(pilihan==3) {
            int totalmax=0;
            int totalmax2=0;
            int size = 0;
            scanf("%d %d", &L, &R);
            for(int j=L; j<=R; j++) {
                if(!stack_isEmpty(&myStack[j-1])){
                    int max1 = stack_max(&myStack[j-1]);
                    int max2 = stack_max2(&myStack[j-1]);
                    //printf("--%d %d--\n", max1, max2);
                    if(max1 > totalmax) {
                        totalmax2 = totalmax;
                        totalmax = max1;
                    }else if(max1 <= totalmax && max1 > totalmax2) {
                        totalmax2 = max1;
                    }
                    if(max2 <= totalmax && max2 > totalmax2) {
                        totalmax2 = max2;
                    }
                    //printf("(%d %d)\n", totalmax, totalmax2);
                }
                size += stack_size(&myStack[j-1]);
            }
            if(totalmax2 == 0) {
                totalmax2 = totalmax;
            }
            if(size == 0){
                printf("Tidak Ada!\n");
            } else {
                printf("%d\n", totalmax2);
            }
        }
    }
    return 0;
}
