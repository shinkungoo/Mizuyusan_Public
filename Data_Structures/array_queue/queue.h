//
// Created by Shizumu on 2022/2/19.
//

#ifndef ARRAY_QUEUE_QUEUE_H
#define ARRAY_QUEUE_QUEUE_H

#include <stdbool.h>
typedef int ElementType;
typedef int Position;
typedef struct QNode* Queue;
struct QNode{
    ElementType *items;
    Position front, rear;
    int MaxSize;
};
Queue CreateQueue(int MaxSize);
bool IsFull(Queue q);
bool IsEmpty(Queue q);
bool Enqueue(Queue q, ElementType x);
ElementType Dequeue(Queue q);
void PrintQueue(Queue q);
#endif //ARRAY_QUEUE_QUEUE_H
