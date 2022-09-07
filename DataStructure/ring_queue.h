#ifndef DATASTRUCTURE_RING_QUEUE_H
#define DATASTRUCTURE_RING_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#define N 1010
#define EMPTY -1
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
void Test();
#endif //DATASTRUCTURE_RING_QUEUE_H
