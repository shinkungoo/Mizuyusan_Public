//
// Created by Shizumu on 2022/2/19.
//
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"

Queue CreateQueue(int MaxSize)
{
    Queue temp;
    temp = (Queue) malloc(sizeof(struct QNode));
    temp->MaxSize = MaxSize;
    temp->items = (ElementType *) malloc(sizeof (ElementType) * temp->MaxSize);
    temp->front = temp->rear = 0;

    return temp;
}

bool IsFull(Queue q)
{
    return (((q->rear + 1) % q->MaxSize) == q->front % q->MaxSize);
}

bool IsEmpty(Queue q)
{
    return (q->rear == q->front);
}

bool Enqueue(Queue q, ElementType x)
{
    bool ret;
    if(IsFull(q)){
        ret = false;
    }else{
        q->rear = (q->rear + 1) % q->MaxSize;
        q->items[q->rear] = x;
        ret = true;
    }

    return ret;
}

ElementType Dequeue(Queue q)
{
    ElementType ret;
    if(IsEmpty(q)){
        ret = false;
    }else{
        q->front = (q->front + 1) % q->MaxSize;
        ret = q->items[q->front];
    }

    return ret;
}

void PrintQueue(Queue q)
{
    if(IsEmpty(q)){
        printf("|Empty|\n");
    }else{
        printf("%d--->", q->front);
        for(int i = q->front + 1; ; i = (i + 1) % q->MaxSize){
            printf("|%d", q->items[i]);
            if(i == q->rear){
                break;
            }
        }
        printf("|<---%d\n", q->rear);
    }
}