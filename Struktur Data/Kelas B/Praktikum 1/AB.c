#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct queueNode_t {
    int data;
    int barang;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front,
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value, int barang);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value, int barang)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->barang = barang;
        newNode->next = NULL;

        if (queue_isEmpty(queue)) {
            queue->_front = queue->_rear = newNode;
        } else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

float queue_rata(Queue *queue) {
    QueueNode *temp = queue->_front;
    float rata=0;
    if(!queue_isEmpty(&queue)) {
        while (temp!=NULL) {
            rata += temp->data * temp->barang;
            //printf("%d * %d = %d; rata : %.4f\n", temp->data, temp->barang, temp->data * temp->barang, rata);
            temp=temp->next;
        }
        //printf("%.4f\n", rata / queue->_size);
        return rata / queue->_size;
    } else {return 0;}
}

int queue_jumlah(Queue *queue, int A) {
    QueueNode *temp = queue->_front;
    int jumlah=0;
    int hitung=0;

    while (temp!=NULL && hitung<A) {
        jumlah += temp->data;
        temp=temp->next;
        hitung++;
    }
    return jumlah;
}

int queue_jumlah_barang(Queue *queue, int A) {
    QueueNode *temp = queue->_front;
    int jumlah_barang=0;
    int hitung=0;

    while(temp!=NULL && hitung<A) {
        jumlah_barang+=temp->barang;
        temp=temp->next;
        hitung++;
    }
    return jumlah_barang;
}

int main(int argc, char const *argv[])
{
    int T;

    Queue Antrian;

    queue_init(&Antrian);

    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        int pilihan;
        int X, Y;
        int A;
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                scanf("%d %d", &X, &Y);
                queue_push(&Antrian, X, Y);
                break;
            case 2:
                if(!queue_isEmpty(&Antrian)) {
                    queue_pop(&Antrian);
                } else {
                    printf("Yah habis :(\n");
                }
                break;
            case 3:
                printf("Rata-rata : %.4f\n", queue_rata(&Antrian));
                break;
            case 4:
                scanf("%d", &A);
                printf("Harga Total : %d, Jumlah Total : %d\n", queue_jumlah(&Antrian, A), queue_jumlah_barang(&Antrian, A));
                break;
        }
    }
    return 0;
}
