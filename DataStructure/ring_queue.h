#ifndef DATASTRUCTURE_RING_QUEUE_H
#define DATASTRUCTURE_RING_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#define N 1010
#define EMPTY (-1)
typedef int ElementType;
typedef struct QNode *Queue;
struct QNode {
    ElementType *item;
    int front, rear;
    int size;
};

int isFull(Queue q) { return ((q->rear+1)%q->size == q->front);}
int isEmpty(Queue q){ return (q->front == q->rear);}

Queue CreateQueue(int size)
{
    Queue q = (Queue)malloc(sizeof(struct QNode));
    q->item = (ElementType *)malloc(size * sizeof(ElementType));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(Queue q, ElementType x)
{
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % q->size;
        q->item[q->rear] = x;
    }
}

ElementType dequeue(Queue q)
{
    if (!isEmpty(q)) {
        q->front = (q->front + 1) % q->size;
        return q->item[q->front];
    }else{
        return EMPTY;
    }
}

ElementType first(Queue q)
{
    if(!isEmpty(q)){
        return q->item[(q->front + 1) % q->size];
    }else{
        return EMPTY;
    }
}

ElementType last(Queue q)
{
    if(!isEmpty(q)){
        return q->item[q->rear];
    }else{
        return EMPTY;
    }
}

int Find(Queue q, ElementType x)
{
    int ret = -1;
    for(int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size){
        if(q->item[i] == x){
            ret = i;
            break;
        }
    }
    return ret;
}

void printQueue(Queue q)
{
    for(int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size){
        printf("%d ", q->item[i]);
    }
}

void cutInLine(Queue q, ElementType x)
{
    int idx = -1;
    for(int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size){
        if(q->item[i] == x){
            idx = i;
            break;
        }
    }
    if(idx != (q->front + 1) % q->size && idx != -1 && !isFull(q)){
        q->item[q->front] = x;
        q->front = (q->front - 1 + q->size) % q->size;
        q->rear = (q->rear - 1 + q->size) % q->size;
        for(int i = idx; i != (q->rear + 1) % q->size; i = (i + 1) % q->size){
            q->item[i] = q->item[(i + 1) % q->size];
        }
    }
}

void addInLine(Queue q, ElementType x)
{
    q->item[q->front] = x;
    q->front = (q->front - 1 + q->size) % q->size;
}

void freeQueue(Queue q){
    free(q->item);
    q->item = NULL;
}

void Test()
{
    Queue q = CreateQueue(100);
    for(int i = 0; i < 20; i ++){
        enqueue(q, i);
    }
    for(int i = 0; i < 5; i ++){
        dequeue(q);
    }
    for(int i = 0; i < 10; i ++){
        enqueue(q, i);
    }
    printQueue(q), printf("\n");
    cutInLine(q, 0);
    cutInLine(q, 17);
    cutInLine(q, 9);
    cutInLine(q, 9);
    printQueue(q), printf("\n");
    addInLine(q, 100);
    addInLine(q, 1000);
    addInLine(q, 1001);
    addInLine(q, 1002);
    printQueue(q), printf("\n");
}
#endif //DATASTRUCTURE_RING_QUEUE_H
