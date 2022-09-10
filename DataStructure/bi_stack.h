#ifndef DATASTRUCTURE_BI_STACK_H
#define DATASTRUCTURE_BI_STACK_H
#include <stdio.h>
#include <stdlib.h>
#define N 1010
#define EMPTY (-1)
typedef int ElementType;
typedef struct BSNode *BiStack;
struct BSNode {
    ElementType *item;
    int front, rear;
    int size;
};

int isFull(BiStack s) { return ((s->rear + 1)%s->size == s->front);}
int isEmpty(BiStack s){ return (s->front == s->rear);}

BiStack CreateBiStack(int size)
{
    BiStack s = (BiStack)malloc(sizeof(struct BSNode));
    s->item = (ElementType *)malloc(size * sizeof(ElementType));
    s->front = s->rear = 0;
    s->size = size;
    return s;
}

void push_back(BiStack s, ElementType x)
{
    if (!isFull(s)) {
        s->rear = (s->rear + 1) % s->size;
        s->item[s->rear] = x;
    }
}

void push_front(BiStack s, ElementType x)
{
    if (!isFull(s)) {
        s->front = (s->front - 1 + s->size) % s->size;
        s->item[(s->front + 1) % s->size] = x;
    }
}

ElementType pop_front(BiStack s)
{
    if (!isEmpty(s)) {
        s->front = (s->front + 1) % s->size;
        return s->item[s->front];
    }else{
        return EMPTY;
    }
}

ElementType pop_back(BiStack s)
{
    if(!isEmpty(s)){
        s->rear = (s->rear - 1 + s->size) % s->size;
        return s->item[(s->rear + 1) % s->size];
    }else{
        return EMPTY;
    }
}

ElementType first(BiStack s)
{
    if(!isEmpty(s)){
        return s->item[(s->front + 1) % s->size];
    }else{
        return EMPTY;
    }
}

ElementType last(BiStack s)
{
    if(!isEmpty(s)){
        return s->item[s->rear];
    }else{
        return EMPTY;
    }
}

void printBiStack(BiStack s)
{
    for(int i = (s->front + 1) % s->size; i != (s->rear + 1) % s->size; i = (i + 1) % s->size){
        printf("%d ", s->item[i]);
    }
}

void Test()
{
    BiStack bs = CreateBiStack(100);
    for(int i = 0; i < 10; i ++){
        push_front(bs, i);
    }
    for(int i = 0; i < 10; i ++){
        push_back(bs, i);
    }
    printBiStack(bs), printf("\n");
    pop_back(bs);
    pop_back(bs);
    printBiStack(bs), printf("\n");
    pop_front(bs);
    push_back(bs, 100);
    push_front(bs, 100);
    printBiStack(bs), printf("\n");
}

#endif //DATASTRUCTURE_BI_STACK_H
